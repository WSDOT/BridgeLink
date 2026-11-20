<#
.SYNOPSIS
   Makes Target the same as Source, copying only files whose content changed.

.DESCRIPTION
   Used by the documentation scripts (each BuildDocumentation.bat and PublishDocumentation.bat).

   Folder mode (Source is a folder): every file in Source is copied to Target unless Target already has a file
   with the same size and SHA-256 hash; files and folders in Target that aren't in Source are deleted, except
   files whose names match a -Keep pattern. Unchanged files keep their timestamps, so a later
   "robocopy /MIR" of Target (e.g. to the documentation server) copies only what really changed, even though
   Doxygen rewrites every file on each build.

   File mode (Source is a file): Source is copied to the Target path unless Target has the same content.

.EXAMPLE
   powershell -NoProfile -ExecutionPolicy Bypass -File SyncFolder.ps1 -Source doc\html -Target %ARPDIR%\BridgeLink\Docs\PGSuper\10.0 -Keep PGSuper.dm
#>
param(
   [Parameter(Mandatory = $true)][string]$Source,
   [Parameter(Mandatory = $true)][string]$Target,
   [string[]]$Keep = @()
)

$ErrorActionPreference = 'Stop'

function Test-SameContent([string]$a, [string]$b)
{
   if (-not (Test-Path -LiteralPath $b -PathType Leaf)) { return $false }
   if ((Get-Item -LiteralPath $a).Length -ne (Get-Item -LiteralPath $b).Length) { return $false }
   return (Get-FileHash -LiteralPath $a -Algorithm SHA256).Hash -eq (Get-FileHash -LiteralPath $b -Algorithm SHA256).Hash
}

try
{
   if (Test-Path -LiteralPath $Source -PathType Leaf)
   {
      $dir = Split-Path -Parent $Target
      if ($dir -and -not (Test-Path -LiteralPath $dir)) { New-Item -ItemType Directory -Path $dir | Out-Null }
      if (Test-SameContent $Source $Target) { Write-Host "Unchanged: $Target" }
      else { Copy-Item -LiteralPath $Source -Destination $Target -Force; Write-Host "Copied: $Target" }
      exit 0
   }

   if (-not (Test-Path -LiteralPath $Source -PathType Container)) { throw "Source not found: $Source" }
   $src = (Resolve-Path -LiteralPath $Source).ProviderPath.TrimEnd('\')
   if (-not (Test-Path -LiteralPath $Target)) { New-Item -ItemType Directory -Path $Target | Out-Null }
   $dst = (Resolve-Path -LiteralPath $Target).ProviderPath.TrimEnd('\')

   $copied = 0; $unchanged = 0; $deleted = 0
   $wanted = @{}

   # copy new and changed files
   foreach ($file in Get-ChildItem -LiteralPath $src -Recurse -File -Force)
   {
      $rel = $file.FullName.Substring($src.Length + 1)
      $wanted[$rel.ToLowerInvariant()] = $true
      $to = Join-Path $dst $rel
      if (Test-SameContent $file.FullName $to) { $unchanged++; continue }
      $toDir = Split-Path -Parent $to
      if (-not (Test-Path -LiteralPath $toDir)) { New-Item -ItemType Directory -Path $toDir | Out-Null }
      Copy-Item -LiteralPath $file.FullName -Destination $to -Force
      $copied++
   }

   # mark the folders that hold wanted files
   $wantedDirs = @{}
   foreach ($rel in $wanted.Keys)
   {
      $d = Split-Path -Parent $rel
      while ($d) { $wantedDirs[$d] = $true; $d = Split-Path -Parent $d }
   }

   # delete files that aren't in the source (except kept ones)
   foreach ($file in Get-ChildItem -LiteralPath $dst -Recurse -File -Force)
   {
      $rel = $file.FullName.Substring($dst.Length + 1).ToLowerInvariant()
      if ($wanted.ContainsKey($rel)) { continue }
      $kept = $false
      foreach ($pattern in $Keep) { if ($file.Name -like $pattern) { $kept = $true; break } }
      if ($kept) { $d = Split-Path -Parent $rel; while ($d) { $wantedDirs[$d] = $true; $d = Split-Path -Parent $d }; continue }
      Remove-Item -LiteralPath $file.FullName -Force
      $deleted++
   }

   # delete folders that aren't in the source, deepest first
   foreach ($dir in (Get-ChildItem -LiteralPath $dst -Recurse -Directory -Force | Sort-Object { $_.FullName.Length } -Descending))
   {
      $rel = $dir.FullName.Substring($dst.Length + 1).ToLowerInvariant()
      if (-not $wantedDirs.ContainsKey($rel)) { Remove-Item -LiteralPath $dir.FullName -Recurse -Force }
   }

   Write-Host ("{0}: {1} copied, {2} unchanged, {3} deleted" -f $dst, $copied, $unchanged, $deleted)
   exit 0
}
catch
{
   Write-Host "SyncFolder.ps1 failed: $_"
   exit 1
}
