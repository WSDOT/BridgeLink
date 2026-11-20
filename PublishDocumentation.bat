REM - Script to build and publish documentation sets to the WSDOT http server

SET DOC_TARGET=\\wsdot\Resources\Topics\Publish\Web\ProdCF\EESC\Bridge\software\Documentation

REM - use only the major and minor build number
REM - this assumes documentation for version 1.1.0 is the same as for version 1.1.1
REM - which will generally be true. This way we don't have to publish new documentation
REM - for every bug-fix release. Just use 1.1 for the version number

SET BRIDGELINK_DOCUMENTATION_VERSION=9.1
SET BETOOLBOX_DOCUMENTATION_VERSION=%BRIDGELINK_DOCUMENTATION_VERSION%
SET PGSUPER_DOCUMENTATION_VERSION=%BRIDGELINK_DOCUMENTATION_VERSION%
SET PGSPLICE_DOCUMENTATION_VERSION=%BRIDGELINK_DOCUMENTATION_VERSION%
SET PGSLIBRARY_VERISON=%BRIDGELINK_DOCUMENTATION_VERSION%
SET XBRATE_DOCUMENTATION_VERSION=%BRIDGELINK_DOCUMENTATION_VERSION%
SET BARLIST_DOCUMENTATION_VERSION=%BRIDGELINK_DOCUMENTATION_VERSION%

REM - Build the documentation sets
REM - Each script builds its set from scratch (Doxygen into an emptied doc folder), then makes
REM - %ARPDIR%\BridgeLink\Docs\<set>\<version> the same as the build, copying only files whose
REM - content changed (SyncFolder.ps1), so unchanged files keep their timestamps
call %ARPDIR%\BridgeLink\Documentation\BuildDocumentation.bat          %BRIDGELINK_DOCUMENTATION_VERSION%
call %ARPDIR%\BEToolbox\Documentation\BuildDocumentation.bat           %BETOOLBOX_DOCUMENTATION_VERSION%
call %ARPDIR%\PGSuper\Documentation\BuildDocumentation.bat             %PGSUPER_DOCUMENTATION_VERSION%
call %ARPDIR%\PGSuper\TxDOTAgent\Documentation\BuildDocumentation.bat  %PGSUPER_DOCUMENTATION_VERSION%
call %ARPDIR%\PGSuper\KDOTExport\Documentation\BuildDocumentation.bat  %PGSUPER_DOCUMENTATION_VERSION%
call %ARPDIR%\XBeamRate\Documentation\BuildDocumentation.bat           %XBRATE_DOCUMENTATION_VERSION%
call %ARPDIR%\Barlist\Documentation\BuildDocumentation.bat           %BARLIST_DOCUMENTATION_VERSION%
call %ARPDIR%\Barlist\Barlist\Documentation\BuildDocumentation.bat           %BARLIST_DOCUMENTATION_VERSION%

cd %ARPDIR%\BridgeLink

REM the /b option is for build only, no publish
if "%1" == "/b" goto END

REM - Make the server copy of each documentation set the same as %ARPDIR%\BridgeLink\Docs
REM - (robocopy /MIR copies new and changed files and deletes files the local copy doesn't have;
REM - the document map, <name>.dm locally, is <name>.dm.html on the server)
SET PUBLISH_FAILED=0
call :publish BridgeLink\%BRIDGELINK_DOCUMENTATION_VERSION%     BridgeLink.dm   BridgeLink.dm.html
call :publish BEToolbox\%BETOOLBOX_DOCUMENTATION_VERSION%       BEToolbox.dm    BEToolbox.dm.html
call :publish PGSuper\%PGSUPER_DOCUMENTATION_VERSION%           PGSuper.dm      PGSuper.dm.html
call :publish PGSplice\%PGSPLICE_DOCUMENTATION_VERSION%         PGSplice.dm     PGSplice.dm.html
call :publish PGSLibrary\%PGSLIBRARY_VERISON%                   PGSLibrary.dm   PGSLibrary.dm.html
call :publish TOGA\%PGSUPER_DOCUMENTATION_VERSION%              Toga.dm         Toga.dm.html
call :publish TxCADExport\%PGSUPER_DOCUMENTATION_VERSION%       TxCADExport.dm  TxCADExport.dm.html
call :publish KDOT\%PGSUPER_DOCUMENTATION_VERSION%              KDOT.dm         KDOT.dm.html
call :publish XBRate\%XBRATE_DOCUMENTATION_VERSION%             XBRate.dm       XBRate.dm.html
call :publish Barlist\%BARLIST_DOCUMENTATION_VERSION%           Barlist.dm      Barlist.dm.html
call :publish Barlist\Barlist\%BARLIST_DOCUMENTATION_VERSION%   BarlistDocs.dm  BarlistDocs.dm.html
if "%PUBLISH_FAILED%" == "1" echo *** One or more documentation sets failed to publish, see the messages above ***

:END

cd %ARPDIR%\BridgeLink
goto :eof

REM - :publish <set folder> <local document map> <server document map>
REM - robocopy compares size and time stamp; /FFT allows for the server's 2 second time resolution.
REM - The document maps are excluded from the mirror (/XF also keeps robocopy from deleting the server's
REM - .dm.html) and copied on their own when their content changed.
REM - robocopy exit codes 0-7 are success, 8 and up are failures.
:publish
robocopy "%ARPDIR%\BridgeLink\Docs\%1" "%DOC_TARGET%\%1" /MIR /FFT /XF *.dm *.dm.html /R:2 /W:5 /NP /NFL /NDL
if errorlevel 8 (echo *** Failed to publish %1 *** & SET PUBLISH_FAILED=1 & exit /B 1)
powershell -NoProfile -ExecutionPolicy Bypass -File %ARPDIR%\BridgeLink\SyncFolder.ps1 -Source "%ARPDIR%\BridgeLink\Docs\%1\%2" -Target "%DOC_TARGET%\%1\%3"
if errorlevel 1 (echo *** Failed to publish %1\%3 *** & SET PUBLISH_FAILED=1 & exit /B 1)
exit /B 0
