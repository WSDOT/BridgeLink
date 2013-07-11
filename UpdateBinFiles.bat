REM - Script to prepare for Release

SET BINTARGET=bin


REM - Application files
copy /Y RegFreeCOM\Win32\Release\BridgeLink.exe  	%BINTARGET%\App\Win32\
copy /Y RegFreeCOM\x64\Release\BridgeLink.exe  		%BINTARGET%\App\x64\
copy /Y BridgeLink.tip					%BINTARGET%\App\
copy /Y License.txt					%BINTARGET%\App\
copy /Y BridgeLink.chm					%BINTARGET%\App\
