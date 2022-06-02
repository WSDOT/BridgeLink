REM - Script to build and publish documentation sets to the WSDOT http server

SET DOC_TARGET=\\wsdot\Resources\Topics\Publish\Web\ProdCF\EESC\Bridge\software\Documentation

REM - use only the major and minor build number
REM - this assumes documentation for version 1.1.0 is the same as for version 1.1.1
REM - which will generally be true. This way we don't have to publish new documentation
REM - for every bug-fix release. Just use 1.1 for the version number

SET BRIDGELINK_DOCUMENTATION_VERSION=7.0
SET BETOOLBOX_DOCUMENTATION_VERSION=%BRIDGELINK_DOCUMENTATION_VERSION%
SET PGSUPER_DOCUMENTATION_VERSION=%BRIDGELINK_DOCUMENTATION_VERSION%
SET PGSPLICE_DOCUMENTATION_VERSION=%BRIDGELINK_DOCUMENTATION_VERSION%
SET PGSLIBRARY_VERISON=%BRIDGELINK_DOCUMENTATION_VERSION%
SET XBRATE_DOCUMENTATION_VERSION=%BRIDGELINK_DOCUMENTATION_VERSION%
SET BARLIST_DOCUMENTATION_VERSION=%BRIDGELINK_DOCUMENTATION_VERSION%

REM - Build the documentation sets
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

REM - Copy the documentation sets to the WSDOT server
rmdir /S /Q %DOC_TARGET%\BridgeLink\%BRIDGELINK_DOCUMENTATION_VERSION%\
mkdir %DOC_TARGET%\BridgeLink\%BRIDGELINK_DOCUMENTATION_VERSION%\
copy %ARPDIR%\BridgeLink\Documentation\BridgeLink.dm %DOC_TARGET%\BridgeLink\%BRIDGELINK_DOCUMENTATION_VERSION%\BridgeLink.dm.html
copy %ARPDIR%\BridgeLink\Documentation\doc\html\* %DOC_TARGET%\BridgeLink\%BRIDGELINK_DOCUMENTATION_VERSION%\

rmdir /S /Q %DOC_TARGET%\BEToolbox\%BETOOLBOX_DOCUMENTATION_VERSION%\
mkdir %DOC_TARGET%\BEToolbox\%BETOOLBOX_DOCUMENTATION_VERSION%\
copy %ARPDIR%\BEToolbox\Documentation\BEToolbox.dm %DOC_TARGET%\BEToolbox\%BETOOLBOX_DOCUMENTATION_VERSION%\BEToolbox.dm.html
copy %ARPDIR%\BEToolbox\Documentation\doc\html\* %DOC_TARGET%\BEToolbox\%BETOOLBOX_DOCUMENTATION_VERSION%\

rmdir /S /Q %DOC_TARGET%\PGSuper\%PGSUPER_DOCUMENTATION_VERSION%\
mkdir %DOC_TARGET%\PGSuper\%PGSUPER_DOCUMENTATION_VERSION%\
copy %ARPDIR%\PGSuper\Documentation\PGSuper.dm %DOC_TARGET%\PGSuper\%PGSUPER_DOCUMENTATION_VERSION%\PGSuper.dm.html
copy %ARPDIR%\PGSuper\Documentation\PGSuper\doc\html\* %DOC_TARGET%\PGSuper\%PGSUPER_DOCUMENTATION_VERSION%\

rmdir /S /Q %DOC_TARGET%\PGSplice\%PGSPLICE_DOCUMENTATION_VERSION%\
mkdir %DOC_TARGET%\PGSplice\%PGSPLICE_DOCUMENTATION_VERSION%\
copy %ARPDIR%\PGSuper\Documentation\PGSplice.dm %DOC_TARGET%\PGSplice\%PGSPLICE_DOCUMENTATION_VERSION%\PGSplice.dm.html
copy %ARPDIR%\PGSuper\Documentation\PGSplice\doc\html\* %DOC_TARGET%\PGSplice\%PGSPLICE_DOCUMENTATION_VERSION%\

rmdir /S /Q %DOC_TARGET%\PGSLibrary\%PGSLIBRARY_VERISON%\
mkdir %DOC_TARGET%\PGSLibrary\%PGSLIBRARY_VERISON%\
copy %ARPDIR%\PGSuper\Documentation\PGSLibrary.dm %DOC_TARGET%\PGSLibrary\%PGSLIBRARY_VERISON%\PGSLibrary.dm.html
copy %ARPDIR%\PGSuper\Documentation\PGSLibrary\doc\html\* %DOC_TARGET%\PGSLibrary\%PGSLIBRARY_VERISON%\

rmdir /S /Q %DOC_TARGET%\TOGA\%PGSUPER_DOCUMENTATION_VERSION%\
mkdir %DOC_TARGET%\TOGA\%PGSUPER_DOCUMENTATION_VERSION%\
copy %ARPDIR%\PGSuper\TxDOTAgent\Documentation\TOGA\Toga.dm %DOC_TARGET%\TOGA\%PGSUPER_DOCUMENTATION_VERSION%\Toga.dm.html
copy %ARPDIR%\PGSuper\TxDOTAgent\Documentation\TOGA\doc\html\* %DOC_TARGET%\TOGA\%PGSUPER_DOCUMENTATION_VERSION%\


rmdir /S /Q %DOC_TARGET%\TxCADExport\%PGSUPER_DOCUMENTATION_VERSION%\
mkdir %DOC_TARGET%\TxCADExport\%PGSUPER_DOCUMENTATION_VERSION%\
copy %ARPDIR%\PGSuper\TxDOTAgent\Documentation\TxCADExport\TxCADExport.dm %DOC_TARGET%\TxCADExport\%PGSUPER_DOCUMENTATION_VERSION%\TxCADExport.dm.html
copy %ARPDIR%\PGSuper\TxDOTAgent\Documentation\TxCADExport\doc\html\* %DOC_TARGET%\TxCADExport\%PGSUPER_DOCUMENTATION_VERSION%\


rmdir /S /Q %DOC_TARGET%\KDOT\%PGSUPER_DOCUMENTATION_VERSION%\
mkdir %DOC_TARGET%\KDOT\%PGSUPER_DOCUMENTATION_VERSION%\
copy %ARPDIR%\PGSuper\KDOTExport\Documentation\KDOT.dm %DOC_TARGET%\KDOT\%PGSUPER_DOCUMENTATION_VERSION%\KDOT.dm.html
copy %ARPDIR%\PGSuper\KDOTExport\Documentation\doc\html\* %DOC_TARGET%\KDOT\%PGSUPER_DOCUMENTATION_VERSION%\

rmdir /S /Q %DOC_TARGET%\XBRate\%XBRATE_DOCUMENTATION_VERSION%\
mkdir %DOC_TARGET%\XBRate\%XBRATE_DOCUMENTATION_VERSION%\
copy %ARPDIR%\XBeamRate\Documentation\XBRate.dm %DOC_TARGET%\XBRate\%XBRATE_DOCUMENTATION_VERSION%\XBRate.dm.html
copy %ARPDIR%\XBeamRate\Documentation\doc\html\* %DOC_TARGET%\XBRate\%XBRATE_DOCUMENTATION_VERSION%\

rmdir /S /Q %DOC_TARGET%\Barlist\%BARLIST_DOCUMENTATION_VERSION%\
mkdir %DOC_TARGET%\Barlist\%BARLIST_DOCUMENTATION_VERSION%\
copy %ARPDIR%\Barlist\Documentation\Barlist.dm %DOC_TARGET%\Barlist\%BARLIST_DOCUMENTATION_VERSION%\Barlist.dm.html
copy %ARPDIR%\Barlist\Documentation\doc\html\* %DOC_TARGET%\Barlist\%BARLIST_DOCUMENTATION_VERSION%\


rmdir /S /Q %DOC_TARGET%\Barlist\Barlist\%BARLIST_DOCUMENTATION_VERSION%\
mkdir %DOC_TARGET%\Barlist\Barlist\%BARLIST_DOCUMENTATION_VERSION%\
copy %ARPDIR%\Barlist\Barlist\Documentation\Barlist.dm %DOC_TARGET%\Barlist\Barlist\%BARLIST_DOCUMENTATION_VERSION%\BarlistDocs.dm.html
copy %ARPDIR%\Barlist\Barlist\Documentation\doc\html\* %DOC_TARGET%\Barlist\Barlist\%BARLIST_DOCUMENTATION_VERSION%\

:END

cd %ARPDIR%\BridgeLink
