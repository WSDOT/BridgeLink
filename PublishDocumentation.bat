REM - Script to build and publish documentation sets to the WSDOT http server

SET DOC_TARGET=\\wsdot\Resources\Topics\Publish\Web\ProdCF\EESC\Bridge\software\Documentation

REM - use only the major and minor build number
REM - this assumes documentation for version 1.1.0 is the same as for version 1.1.1
REM - which will generally be true. This way we don't have to publish new documentation
REM - for every bug-fix release. Just use 1.1 for the version number

SET BRIDGELINK_DOCUMENTATION_VERSION=4.1
SET BETOOLBOX_DOCUMENTATION_VERSION=%BRIDGELINK_DOCUMENTATION_VERSION%
SET PGSUPER_DOCUMENTATION_VERSION=%BRIDGELINK_DOCUMENTATION_VERSION%
SET PGSPLICE_DOCUMENTATION_VERSION=%BRIDGELINK_DOCUMENTATION_VERSION%
SET PGSLIBRARY_VERISON=%BRIDGELINK_DOCUMENTATION_VERSION%
SET XBRATE_DOCUMENTATION_VERSION=%BRIDGELINK_DOCUMENTATION_VERSION%
SET BARLIST_DOCUMENTATION_VERSION=5.1

REM - Build the documentation sets
call \ARP\BridgeLink\Documentation\BuildDocumentation.bat          %BRIDGELINK_DOCUMENTATION_VERSION%
call \ARP\BEToolbox\Documentation\BuildDocumentation.bat           %BETOOLBOX_DOCUMENTATION_VERSION%
call \ARP\PGSuper\Documentation\BuildDocumentation.bat             %PGSUPER_DOCUMENTATION_VERSION%
call \ARP\PGSuper\TxDOTAgent\Documentation\BuildDocumentation.bat  %PGSUPER_DOCUMENTATION_VERSION%
call \ARP\PGSuper\KDOTExport\Documentation\BuildDocumentation.bat  %PGSUPER_DOCUMENTATION_VERSION%
call \ARP\XBeamRate\Documentation\BuildDocumentation.bat           %XBRATE_DOCUMENTATION_VERSION%
call \ARP\Barlist\Documentation\BuildDocumentation.bat           %BARLIST_DOCUMENTATION_VERSION%
call \ARP\Barlist\Barlist\Documentation\BuildDocumentation.bat           %BARLIST_DOCUMENTATION_VERSION%

cd \ARP\BridgeLink

REM the /b option is for build only, no publish
if "%1" == "/b" goto END

REM - Copy the documentation sets to the WSDOT server
rmdir /S /Q %DOC_TARGET%\BridgeLink\%BRIDGELINK_DOCUMENTATION_VERSION%\
mkdir %DOC_TARGET%\BridgeLink\%BRIDGELINK_DOCUMENTATION_VERSION%\
copy \ARP\BridgeLink\Documentation\BridgeLink.dm %DOC_TARGET%\BridgeLink\%BRIDGELINK_DOCUMENTATION_VERSION%\BridgeLink.dm.html
copy \ARP\BridgeLink\Documentation\doc\html\* %DOC_TARGET%\BridgeLink\%BRIDGELINK_DOCUMENTATION_VERSION%\

rmdir /S /Q %DOC_TARGET%\BEToolbox\%BETOOLBOX_DOCUMENTATION_VERSION%\
mkdir %DOC_TARGET%\BEToolbox\%BETOOLBOX_DOCUMENTATION_VERSION%\
copy \ARP\BEToolbox\Documentation\BEToolbox.dm %DOC_TARGET%\BEToolbox\%BETOOLBOX_DOCUMENTATION_VERSION%\BEToolbox.dm.html
copy \ARP\BEToolbox\Documentation\doc\html\* %DOC_TARGET%\BEToolbox\%BETOOLBOX_DOCUMENTATION_VERSION%\

rmdir /S /Q %DOC_TARGET%\PGSuper\%PGSUPER_DOCUMENTATION_VERSION%\
mkdir %DOC_TARGET%\PGSuper\%PGSUPER_DOCUMENTATION_VERSION%\
copy \ARP\PGSuper\Documentation\PGSuper.dm %DOC_TARGET%\PGSuper\%PGSUPER_DOCUMENTATION_VERSION%\PGSuper.dm.html
copy \ARP\PGSuper\Documentation\PGSuper\doc\html\* %DOC_TARGET%\PGSuper\%PGSUPER_DOCUMENTATION_VERSION%\

rmdir /S /Q %DOC_TARGET%\PGSplice\%PGSPLICE_DOCUMENTATION_VERSION%\
mkdir %DOC_TARGET%\PGSplice\%PGSPLICE_DOCUMENTATION_VERSION%\
copy \ARP\PGSuper\Documentation\PGSplice.dm %DOC_TARGET%\PGSplice\%PGSPLICE_DOCUMENTATION_VERSION%\PGSplice.dm.html
copy \ARP\PGSuper\Documentation\PGSplice\doc\html\* %DOC_TARGET%\PGSplice\%PGSPLICE_DOCUMENTATION_VERSION%\

rmdir /S /Q %DOC_TARGET%\PGSLibrary\%PGSLIBRARY_VERISON%\
mkdir %DOC_TARGET%\PGSLibrary\%PGSLIBRARY_VERISON%\
copy \ARP\PGSuper\Documentation\PGSLibrary.dm %DOC_TARGET%\PGSLibrary\%PGSLIBRARY_VERISON%\PGSLibrary.dm.html
copy \ARP\PGSuper\Documentation\PGSLibrary\doc\html\* %DOC_TARGET%\PGSLibrary\%PGSLIBRARY_VERISON%\

rmdir /S /Q %DOC_TARGET%\TOGA\%PGSUPER_DOCUMENTATION_VERSION%\
mkdir %DOC_TARGET%\TOGA\%PGSUPER_DOCUMENTATION_VERSION%\
copy \ARP\PGSuper\TxDOTAgent\Documentation\Toga.dm %DOC_TARGET%\TOGA\%PGSUPER_DOCUMENTATION_VERSION%\Toga.dm.html
copy \ARP\PGSuper\TxDOTAgent\Documentation\doc\html\* %DOC_TARGET%\TOGA\%PGSUPER_DOCUMENTATION_VERSION%\

rmdir /S /Q %DOC_TARGET%\KDOT\%PGSUPER_DOCUMENTATION_VERSION%\
mkdir %DOC_TARGET%\KDOT\%PGSUPER_DOCUMENTATION_VERSION%\
copy \ARP\PGSuper\KDOTExport\Documentation\KDOT.dm %DOC_TARGET%\KDOT\%PGSUPER_DOCUMENTATION_VERSION%\KDOT.dm.html
copy \ARP\PGSuper\KDOTExport\Documentation\doc\html\* %DOC_TARGET%\KDOT\%PGSUPER_DOCUMENTATION_VERSION%\

rmdir /S /Q %DOC_TARGET%\XBRate\%XBRATE_DOCUMENTATION_VERSION%\
mkdir %DOC_TARGET%\XBRate\%XBRATE_DOCUMENTATION_VERSION%\
copy \ARP\XBeamRate\Documentation\XBRate.dm %DOC_TARGET%\XBRate\%XBRATE_DOCUMENTATION_VERSION%\XBRate.dm.html
copy \ARP\XBeamRate\Documentation\doc\html\* %DOC_TARGET%\XBRate\%XBRATE_DOCUMENTATION_VERSION%\

rmdir /S /Q %DOC_TARGET%\Barlist\%BARLIST_DOCUMENTATION_VERSION%\
mkdir %DOC_TARGET%\Barlist\%BARLIST_DOCUMENTATION_VERSION%\
copy \ARP\Barlist\Documentation\Barlist.dm %DOC_TARGET%\Barlist\%BARLIST_DOCUMENTATION_VERSION%\Barlist.dm.html
copy \ARP\Barlist\Documentation\doc\html\* %DOC_TARGET%\Barlist\%BARLIST_DOCUMENTATION_VERSION%\


rmdir /S /Q %DOC_TARGET%\Barlist\Barlist\%BARLIST_DOCUMENTATION_VERSION%\
mkdir %DOC_TARGET%\Barlist\Barlist\%BARLIST_DOCUMENTATION_VERSION%\
copy \ARP\Barlist\Barlist\Documentation\Barlist.dm %DOC_TARGET%\Barlist\Barlist\%BARLIST_DOCUMENTATION_VERSION%\Barlist.dm.html
copy \ARP\Barlist\Barlist\Documentation\doc\html\* %DOC_TARGET%\Barlist\Barlist\%BARLIST_DOCUMENTATION_VERSION%\

:END

cd \ARP\BridgeLink
