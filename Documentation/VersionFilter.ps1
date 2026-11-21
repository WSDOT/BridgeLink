# Doxygen input filter for src\index.md (FILTER_PATTERNS in Doxygen.dox): replaces $(ARP_DOCUMENTATION_VERSION) in the links to
# the other documentation sets with the documentation version (x.y). BuildDocumentation.bat sets the variable
# (GetVersion.bat, from WBFL_VERSION_STRING in WBFL\Include\WBFLVersion.h).
param([Parameter(Mandatory = $true)][string]$File)
if (-not $env:ARP_DOCUMENTATION_VERSION) { [Console]::Error.WriteLine('VersionFilter.ps1: ARP_DOCUMENTATION_VERSION is not set (run BuildDocumentation.bat)'); exit 1 }
$text = [IO.File]::ReadAllText($File)
$out = New-Object IO.StreamWriter([Console]::OpenStandardOutput(), (New-Object Text.UTF8Encoding($false)))
$out.Write($text.Replace('$(ARP_DOCUMENTATION_VERSION)', $env:ARP_DOCUMENTATION_VERSION))
$out.Flush()
