REM - Script to publish binary files to ARP_Release

SET VERSION=%1

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