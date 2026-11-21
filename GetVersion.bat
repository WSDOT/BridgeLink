@REM - Sets the BridgeLink version numbers from WBFL_VERSION_STRING in %ARPDIR%\WBFL\Include\WBFLVersion.h (x.y.z.b):
@REM -   ARP_VERSION                x.y.z.b (e.g. 10.0.0.1)
@REM -   ARP_RELEASE_VERSION        x.y.z   (e.g. 10.0.0)
@REM -   ARP_DOCUMENTATION_VERSION  x.y     (e.g. 10.0)
@SET ARP_VERSION=
@SET ARP_RELEASE_VERSION=
@SET ARP_DOCUMENTATION_VERSION=
@SET ARP_VERSION_HEADER=%ARPDIR%\WBFL\Include\WBFLVersion.h
@for /f "tokens=2,3" %%a in ('findstr /r /c:"^ *# *define  *WBFL_VERSION_STRING" "%ARP_VERSION_HEADER%"') do @if "%%a" == "WBFL_VERSION_STRING" if not defined ARP_VERSION SET "ARP_VERSION=%%~b"
@for /f "tokens=1-4 delims=." %%a in ("%ARP_VERSION%") do @if not "%%d" == "" (SET "ARP_RELEASE_VERSION=%%a.%%b.%%c" & SET "ARP_DOCUMENTATION_VERSION=%%a.%%b")
@if not defined ARP_RELEASE_VERSION (echo *** WBFL_VERSION_STRING in %ARP_VERSION_HEADER% must be the version number x.y.z.b *** & exit /B 1)
@echo BridgeLink version %ARP_VERSION% (release %ARP_RELEASE_VERSION%, documentation %ARP_DOCUMENTATION_VERSION%)
@exit /B 0
