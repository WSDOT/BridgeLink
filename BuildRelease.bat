REM - Script to prepare for Release


SET VERSION=8.0.7.1

REM - Step 1. Update the documentation

cd %ARPDIR%\BridgeLink

call PublishDocumentation.bat



REM - Step 2. Update the binary files

cd %ARPDIR%\BridgeLink

call UpdateBinFiles.bat



REM - Step 3. Copy binaries to the release file tree

cd %ARPDIR%\BridgeLink

call PublishRelease.bat %VERSION%
