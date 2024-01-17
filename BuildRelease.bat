REM - Script to prepare for Release


SET VERSION=8.0.2.0

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



cd %ARPDIR%\BridgeLink