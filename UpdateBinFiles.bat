REM - Script to prepare for Release

REM - Update WBFL Files
cd \ARP\WBFL
call UpdateBinFiles.bat

REM - Update PGSuper/PGSplice Files
cd \ARP\PGSuper
call UpdateBinFiles.bat

REM - Update BEToolbox Files
cd \ARP\BEToolbox
call UpdateBinFiles.bat


REM - Update XBeam Rate Files
cd \ARP\XBeamRate
call UpdateBinFiles.bat

REM - Update Bridge Link Files

cd \ARP\BridgeLink
SET BINTARGET=bin


REM - Application files
xcopy /Y /d RegFreeCOM\x64\Release\BridgeLink.exe 	%BINTARGET%\App\x64\
xcopy /Y /d BridgeLink.tip				%BINTARGET%\App\
xcopy /Y /d License.txt					%BINTARGET%\App\
xcopy /Y /d res\BridgeLink.ico                          %BINTARGET%\App\
