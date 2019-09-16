REM - Script to prepare for Release


SET VERSION=5.0.0.3

REM - after Barlist normalizes with the rest of the system, eliminate this and just use VERSION

SET BARLIST_VERSION=5.2.0.3


REM - Step 1. Update the documentation

cd \ARP\BridgeLink

call PublishDocumentation.bat



REM - Step 2. Update the binary files

cd \ARP\BridgeLink

call UpdateBinFiles.bat



REM - Step 3. Copy binaries to the release file tree

cd \ARP_RELEASE


mkdir Barlist\%BARLIST_VERSION%\bin

xcopy /E /I /Y \ARP\Barlist\bin\* Barlist\%BARLIST_VERSION%\bin



mkdir BEToolbox\%VERSION%\bin

xcopy /E /I /Y \ARP\BEToolbox\bin\* BEToolbox\%VERSION%\bin



mkdir BridgeLink\%VERSION%\bin

xcopy /E /I /Y  \ARP\BridgeLink\bin\* BridgeLink\%VERSION%\bin



mkdir PGSuper\%VERSION%\bin

xcopy /E /I /Y  \ARP\PGSuper\bin\* PGSuper\%VERSION%\bin



mkdir XBeamRate\%VERSION%\bin

xcopy /E /I /Y  \ARP\XBeamRate\bin\* XBeamRate\%VERSION%\bin



mkdir WBFL\%VERSION%\bin

xcopy /E /I /Y  \ARP\WBFL\bin\* WBFL\%VERSION%\bin



cd \ARP\BridgeLink