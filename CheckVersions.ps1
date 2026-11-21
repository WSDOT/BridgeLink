<#
.SYNOPSIS
   Checks that our binaries carry the version number in WBFLVersion.h.

.DESCRIPTION
   Every .dll and .exe in the given folders, or in the given installer packages (.msi, extracted to a temporary
   folder), is checked when its CompanyName matches -Company or its file name matches -Name. Its file version and
   product version (the strings and the numbers; a "+<commit>" suffix on the product version, which .NET builds add,
   is ignored) must be WBFL_VERSION_STRING from WBFLVersion.h; a binary
   without a version resource is reported too. -Exclude lists binaries that keep their own version, and the unit
   test DLLs (*UnitTests.dll), which are for the test framework and never deployed.

   Used by BuildRelease.bat (the release file tree) and BridgeLinkInstaller.wixproj (the built package).
   Problems are written as MSBuild-style warnings ("CheckVersions : warning BLV001: ..."); the exit code is 1
   when there are problems, unless -WarnOnly is given.

.EXAMPLE
   powershell -NoProfile -ExecutionPolicy Bypass -File CheckVersions.ps1 -Path bin\x64\Release\BridgeLink.msi
#>
param(
   [Parameter(Mandatory = $true)][string[]]$Path,
   [string[]]$Company = @('Washington State Department of Transportation', 'Kansas Department of Transportation'),
   [string[]]$Name = @('WBFL*.dll', 'PGSuper*.dll', 'PGSuper*.exe', 'BridgeLink*.dll', 'BridgeLink*.exe', 'BEToolbox*.dll',
                       'XBeamRate*.dll', 'Barlist*.dll', 'Barlist*.exe', 'BXF.dll', 'MakePgz.exe'),
   [string[]]$Exclude = @('Convert.dll', '*UnitTests.dll'),
   [string]$Header = "$env:ARPDIR\WBFL\Include\WBFLVersion.h",
   [switch]$WarnOnly
)

$ErrorActionPreference = 'Stop'

# powershell -File passes a list as one string: accept "a;b;c" too
$Path = @($Path | ForEach-Object { $_ -split ';' } | Where-Object { $_ })

$m =[regex]::Match([IO.File]::ReadAllText($Header), '(?m)^[ \t]*#[ \t]*define[ \t]+WBFL_VERSION_STRING[ \t]+"(\d+\.\d+\.\d+\.\d+)"')
if (-not $m.Success) { Write-Host "CheckVersions : error BLV000: WBFL_VERSION_STRING not found in $Header"; exit 1 }
$want = $m.Groups[1].Value

function Test-Ours([IO.FileInfo]$file)
{
   foreach ($x in $Exclude) { if ($file.Name -like $x) { return $false } }
   $c = $file.VersionInfo.CompanyName
   foreach ($x in $Company) { if ($c -and $c -like $x) { return $true } }
   foreach ($x in $Name) { if ($file.Name -like $x) { return $true } }
   return $false
}

$problems = 0; $checked = 0; $temp = @()
try
{
   foreach ($p in $Path)
   {
      if (-not (Test-Path -LiteralPath $p)) { Write-Host "CheckVersions : warning BLV002: $p not found"; $problems++; continue }
      $root = $p
      if ($p -like '*.msi')
      {
         $root = Join-Path ([IO.Path]::GetTempPath()) ("CheckVersions_" + [guid]::NewGuid().ToString('N'))
         $temp += $root
         $msi = (Resolve-Path -LiteralPath $p).ProviderPath
         Start-Process msiexec.exe -ArgumentList @('/a', "`"$msi`"", '/qn', "TARGETDIR=`"$root`"") -Wait -NoNewWindow
         if (-not (Test-Path $root)) { Write-Host "CheckVersions : error BLV003: couldn't extract $p"; $problems++; continue }
      }
      foreach ($file in Get-ChildItem -LiteralPath $root -Recurse -File -Include *.dll, *.exe)
      {
         if (-not (Test-Ours $file)) { continue }
         $checked++
         $v = $file.VersionInfo
         $numbers = "{0}.{1}.{2}.{3}" -f $v.FileMajorPart, $v.FileMinorPart, $v.FileBuildPart, $v.FilePrivatePart
         $product = "{0}.{1}.{2}.{3}" -f $v.ProductMajorPart, $v.ProductMinorPart, $v.ProductBuildPart, $v.ProductPrivatePart
         $where = if ($p -like '*.msi') { "$($file.Name) in $p" } else { $file.FullName }
         # .NET builds add the commit to the product version ("10.0.0.1+<hash>", SemVer build metadata): it's ignored
         $productString = if ($v.ProductVersion) { ($v.ProductVersion.Trim() -split '\+')[0] } else { $null }
         if (-not $v.FileVersion)
         {
            Write-Host "CheckVersions : warning BLV004: $where has no version resource (expected $want)"; $problems++
         }
         elseif ($v.FileVersion.Trim() -ne $want -or ($productString -and $productString -ne $want) -or $numbers -ne $want -or $product -ne $want)
         {
            Write-Host "CheckVersions : warning BLV001: $where is version $($v.FileVersion.Trim()) (product $($v.ProductVersion)), expected $want"; $problems++
         }
      }
   }
}
finally
{
   foreach ($t in $temp) { Remove-Item -LiteralPath $t -Recurse -Force -ErrorAction SilentlyContinue }
}

if ($problems) { Write-Host "CheckVersions: $problems of $checked binaries don't have version $want (WBFL_VERSION_STRING in $Header)" }
else { Write-Host "CheckVersions: all $checked binaries have version $want" }
if ($problems -and -not $WarnOnly) { exit 1 }
exit 0
