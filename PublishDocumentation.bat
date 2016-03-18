REM - Script to build and publish documentation sets to the WSDOT http server

SET DOC_TARGET=\\wsdot\Resources\Topics\Publish\Web\ProdCF\EESC\Bridge\software\Documentation

REM - use only the major and minor build number
REM - this assumes documentation for version 1.1.0 is the same as for version 1.1.1
REM - which will generally be true. This way we don't have to publish new documentation
REM - for every bug-fix release

SET BRIDGELINK_VERSION=1.0
SET BETOOLBOX_VERSION=3.0
SET PGSUPER_VERSION=3.0
SET PGSPLICE_VERSION=%PGSUPER_VERSION%
SET PGSLIBRARY_VERISON=%PGSUPER_VERSION%
SET XBRATE_VERSION=1.0

REM - Build the documentation sets
call \ARP\BridgeLink\Documentation\BuildDocumentation.bat
call \ARP\BridgeLinkBEToolbox\Documentation\BuildDocumentation.bat
call \ARP\PGSuper\Documentation\BuildDocumentation.bat
call \ARP\XBeamRate\Documentation\BuildDocumentation.bat

REM - Copy the documentation sets to the WSDOT server
xcopy /y/d \ARP\BridgeLink\Documentation\BridgeLink.dm %DOC_TARGET%\BridgeLink\%BRIDGELINK_VERSION%\BridgeLink.dm.html
xcopy /y/d \ARP\BridgeLink\Documentation\doc\html\* %DOC_TARGET%\BridgeLink\%BRIDGELINK_VERSION%\

xcopy /y/d \ARP\BridgeLinkBEToolbox\Documentation\BEToolbox.dm %DOC_TARGET%\BEToolbox\%BETOOLBOX_VERSION%\BEToolbox.dm.html
xcopy /y/d \ARP\BridgeLinkBEToolbox\Documentation\doc\html\* %DOC_TARGET%\BEToolbox\%BETOOLBOX_VERSION%\

xcopy /y/d \ARP\PGSuper\Documentation\PGSuper.dm %DOC_TARGET%\PGSuper\%PGSUPER_VERSION%\PGSuper.dm.html
xcopy /y/d \ARP\PGSuper\Documentation\PGSuper\doc\html\* %DOC_TARGET%\PGSuper\%PGSUPER_VERSION%\

xcopy /y/d \ARP\PGSuper\Documentation\PGSplice.dm %DOC_TARGET%\PGSplice\%PGSPLICE_VERSION%\PGSplice.dm.html
xcopy /y/d \ARP\PGSuper\Documentation\PGSplice\doc\html\* %DOC_TARGET%\PGSplice\%PGSPLICE_VERSION%\

xcopy /y/d \ARP\PGSuper\Documentation\PGSLibrary.dm %DOC_TARGET%\PGSLibrary\%PGSLIBRARY_VERISON%\PGSLibrary.dm.html
xcopy /y/d \ARP\PGSuper\Documentation\PGSLibrary\doc\html\* %DOC_TARGET%\PGSLibrary\%PGSLIBRARY_VERISON%\

xcopy /y/d \ARP\PGSuper\TxDOTAgent\Documentation\Toga.dm %DOC_TARGET%\Toga\%PGSUPER_VERSION%\Toga.dm.html
xcopy /y/d \ARP\PGSuper\TxDOTAgent\Documentation\doc\html\* %DOC_TARGET%\Toga\%PGSUPER_VERSION%\

xcopy /y/d \ARP\PGSuper\KDOTExport\Documentation\KDOT.dm %DOC_TARGET%\KDOT\%PGSUPER_VERSION%\KDOT.dm.html
xcopy /y/d \ARP\PGSuper\KDOTExport\Documentation\doc\html\* %DOC_TARGET%\KDOT\%PGSUPER_VERSION%\

xcopy /y/d \ARP\XBeamRate\Documentation\XBRate.dm %DOC_TARGET%\XBRate\%XBRATE_VERSION%\XBRate.dm.html
xcopy /y/d \ARP\XBeamRate\Documentation\doc\html\* %DOC_TARGET%\XBRate\%XBRATE_VERSION%\

cd \ARP\BridgeLink
