REM - Script to prepare for Release


REM - The version number comes from WBFL_VERSION_STRING in WBFL\Include\WBFLVersion.h
call %ARPDIR%\BridgeLink\GetVersion.bat
if errorlevel 1 exit /B 1
SET VERSION=%ARP_VERSION%

REM - Step 1. Update the documentation

cd %ARPDIR%\BridgeLink

call PublishDocumentation.bat



REM - Step 2. Update the binary files

cd %ARPDIR%\BridgeLink

call UpdateBinFiles.bat



REM - Step 3. Copy binaries to the release file tree

cd \ARP_RELEASE


mkdir Barlist\%VERSION%\bin

xcopy /E /I /Y %ARPDIR%\Barlist\bin\* Barlist\%VERSION%\bin



mkdir BEToolbox\%VERSION%\bin

xcopy /E /I /Y %ARPDIR%\BEToolbox\bin\* BEToolbox\%VERSION%\bin



mkdir BridgeLink\%VERSION%\bin

xcopy /E /I /Y  %ARPDIR%\BridgeLink\bin\* BridgeLink\%VERSION%\bin



mkdir PGSuper\%VERSION%\bin

xcopy /E /I /Y  %ARPDIR%\PGSuper\bin\* PGSuper\%VERSION%\bin
xcopy /E /I /Y  %ARPDIR%\PGSuperIfcExtensions\bin\* PGSuper\%VERSION%\bin



mkdir XBeamRate\%VERSION%\bin

xcopy /E /I /Y  %ARPDIR%\XBeamRate\bin\* XBeamRate\%VERSION%\bin



mkdir WBFL\%VERSION%\bin

xcopy /E /I /Y  %ARPDIR%\WBFL\bin\* WBFL\%VERSION%\bin



REM - Step 4. Check that our binaries in the release file tree have the version number in WBFLVersion.h
REM -         (warnings only: the tree can hold old files the installers don't use; the installer build checks its package)

powershell -NoProfile -ExecutionPolicy Bypass -File %ARPDIR%\BridgeLink\CheckVersions.ps1 -WarnOnly -Path "\ARP_RELEASE\Barlist\%VERSION%\bin;\ARP_RELEASE\BEToolbox\%VERSION%\bin;\ARP_RELEASE\BridgeLink\%VERSION%\bin;\ARP_RELEASE\PGSuper\%VERSION%\bin;\ARP_RELEASE\XBeamRate\%VERSION%\bin;\ARP_RELEASE\WBFL\%VERSION%\bin"



cd %ARPDIR%\BridgeLink