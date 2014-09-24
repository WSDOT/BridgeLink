REM - Script to prepare for Release

REM - Update OpenBridgeML Files
cd \ARP\OpenBridgeML
call UpdateBinFiles.bat

REM - Update WBFL Files
cd \ARP\WBFL
call UpdateBinFiles.bat

REM - Update PGSuper/PGSplice Files
cd \ARP\PGSuper
call UpdateBinFiles.bat

REM - Update BEToolbox Files
cd \ARP\BridgeLinkBEToolbox
call UpdateBinFiles.bat

REM - Update Bridge Link Files

cd \ARP\BridgeLink
SET BINTARGET=bin


REM - Application files
copy /Y RegFreeCOM\Win32\Release\BridgeLink.exe  	%BINTARGET%\App\Win32\
copy /Y RegFreeCOM\x64\Release\BridgeLink.exe  		%BINTARGET%\App\x64\
copy /Y BridgeLink.tip					%BINTARGET%\App\
copy /Y License.txt					%BINTARGET%\App\
copy /Y BridgeLink.chm					%BINTARGET%\App\
