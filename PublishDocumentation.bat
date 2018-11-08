REM - Script to build and publish documentation sets to the WSDOT http server

SET DOC_TARGET=\\wsdot\Resources\Topics\Publish\Web\ProdCF\EESC\Bridge\software\Documentation

REM - use only the major and minor build number
REM - this assumes documentation for version 1.1.0 is the same as for version 1.1.1
REM - which will generally be true. This way we don't have to publish new documentation
REM - for every bug-fix release. Just use 1.1 for the version number

SET BRIDGELINK_VERSION=4.0
SET BETOOLBOX_VERSION=%BRIDGELINK_VERSION%
SET PGSUPER_VERSION=%BRIDGELINK_VERSION%
SET PGSPLICE_VERSION=%BRIDGELINK_VERSION%
SET PGSLIBRARY_VERISON=%BRIDGELINK_VERSION%
SET XBRATE_VERSION=%BRIDGELINK_VERSION%

REM - Build the documentation sets
call \ARP\BridgeLink\Documentation\BuildDocumentation.bat          %BRIDGELINK_VERSION%
call \ARP\BEToolbox\Documentation\BuildDocumentation.bat           %BETOOLBOX_VERSION%
call \ARP\PGSuper\Documentation\BuildDocumentation.bat             %PGSUPER_VERSION%
call \ARP\PGSuper\TxDOTAgent\Documentation\BuildDocumentation.bat  %PGSUPER_VERSION%
call \ARP\PGSuper\KDOTExport\Documentation\BuildDocumentation.bat  %PGSUPER_VERSION%
call \ARP\XBeamRate\Documentation\BuildDocumentation.bat           %XBRATE_VERSION%

cd \ARP\BridgeLink

REM the /b option is for build only, no publish
if "%1" == "/b" goto END

REM - Copy the documentation sets to the WSDOT server
rmdir /S /Q %DOC_TARGET%\BridgeLink\%BRIDGELINK_VERSION%\
mkdir %DOC_TARGET%\BridgeLink\%BRIDGELINK_VERSION%\
copy \ARP\BridgeLink\Documentation\BridgeLink.dm %DOC_TARGET%\BridgeLink\%BRIDGELINK_VERSION%\BridgeLink.dm.html
copy \ARP\BridgeLink\Documentation\doc\html\* %DOC_TARGET%\BridgeLink\%BRIDGELINK_VERSION%\

rmdir /S /Q %DOC_TARGET%\BEToolbox\%BETOOLBOX_VERSION%\
mkdir %DOC_TARGET%\BEToolbox\%BETOOLBOX_VERSION%\
copy \ARP\BEToolbox\Documentation\BEToolbox.dm %DOC_TARGET%\BEToolbox\%BETOOLBOX_VERSION%\BEToolbox.dm.html
copy \ARP\BEToolbox\Documentation\doc\html\* %DOC_TARGET%\BEToolbox\%BETOOLBOX_VERSION%\

rmdir /S /Q %DOC_TARGET%\PGSuper\%PGSUPER_VERSION%\
mkdir %DOC_TARGET%\PGSuper\%PGSUPER_VERSION%\
copy \ARP\PGSuper\Documentation\PGSuper.dm %DOC_TARGET%\PGSuper\%PGSUPER_VERSION%\PGSuper.dm.html
copy \ARP\PGSuper\Documentation\PGSuper\doc\html\* %DOC_TARGET%\PGSuper\%PGSUPER_VERSION%\

rmdir /S /Q %DOC_TARGET%\PGSplice\%PGSPLICE_VERSION%\
mkdir %DOC_TARGET%\PGSplice\%PGSPLICE_VERSION%\
copy \ARP\PGSuper\Documentation\PGSplice.dm %DOC_TARGET%\PGSplice\%PGSPLICE_VERSION%\PGSplice.dm.html
copy \ARP\PGSuper\Documentation\PGSplice\doc\html\* %DOC_TARGET%\PGSplice\%PGSPLICE_VERSION%\

rmdir /S /Q %DOC_TARGET%\PGSLibrary\%PGSLIBRARY_VERISON%\
mkdir %DOC_TARGET%\PGSLibrary\%PGSLIBRARY_VERISON%\
copy \ARP\PGSuper\Documentation\PGSLibrary.dm %DOC_TARGET%\PGSLibrary\%PGSLIBRARY_VERISON%\PGSLibrary.dm.html
copy \ARP\PGSuper\Documentation\PGSLibrary\doc\html\* %DOC_TARGET%\PGSLibrary\%PGSLIBRARY_VERISON%\

rmdir /S /Q %DOC_TARGET%\TOGA\%PGSUPER_VERSION%\
mkdir %DOC_TARGET%\TOGA\%PGSUPER_VERSION%\
copy \ARP\PGSuper\TxDOTAgent\Documentation\Toga.dm %DOC_TARGET%\TOGA\%PGSUPER_VERSION%\Toga.dm.html
copy \ARP\PGSuper\TxDOTAgent\Documentation\doc\html\* %DOC_TARGET%\TOGA\%PGSUPER_VERSION%\

rmdir /S /Q %DOC_TARGET%\KDOT\%PGSUPER_VERSION%\
mkdir %DOC_TARGET%\KDOT\%PGSUPER_VERSION%\
copy \ARP\PGSuper\KDOTExport\Documentation\KDOT.dm %DOC_TARGET%\KDOT\%PGSUPER_VERSION%\KDOT.dm.html
copy \ARP\PGSuper\KDOTExport\Documentation\doc\html\* %DOC_TARGET%\KDOT\%PGSUPER_VERSION%\

rmdir /S /Q %DOC_TARGET%\XBRate\%XBRATE_VERSION%\
mkdir %DOC_TARGET%\XBRate\%XBRATE_VERSION%\
copy \ARP\XBeamRate\Documentation\XBRate.dm %DOC_TARGET%\XBRate\%XBRATE_VERSION%\XBRate.dm.html
copy \ARP\XBeamRate\Documentation\doc\html\* %DOC_TARGET%\XBRate\%XBRATE_VERSION%\

:END

cd \ARP\BridgeLink
