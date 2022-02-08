REM - Script to prepare for Release

REM - Update WBFL Files
cd %ARPDIR%\WBFL
call UpdateBinFiles.bat

REM - Update PGSuper/PGSplice Files
cd %ARPDIR%\PGSuper
call UpdateBinFiles.bat

cd %ARPDIR%\PGSuperExperimental
call UpdateBinFiles.bat

REM - Update BEToolbox Files
cd %ARPDIR%\BEToolbox
call UpdateBinFiles.bat


REM - Update XBeam Rate Files
cd %ARPDIR%\XBeamRate
call UpdateBinFiles.bat


REM - Update Barlist Files
cd %ARPDIR%\Barlist
call UpdateBinFiles.bat

REM - Update Bridge Link Files

cd %ARPDIR%\BridgeLink
SET BINTARGET=bin


REM - Application files
xcopy /Y /d RegFreeCOM\x64\Release\BridgeLink.exe 	%BINTARGET%\App\x64\
xcopy /Y /d BridgeLink.tip				%BINTARGET%\App\
xcopy /Y /d License.txt					%BINTARGET%\App\
xcopy /Y /d res\BridgeLink.ico                          %BINTARGET%\App\
