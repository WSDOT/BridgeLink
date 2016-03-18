REM - Script to build and publish documentation sets to the WSDOT http server

REM - Build the documentation sets
call \ARP\BridgeLink\Documentation\BuildDocumentation.bat
call \ARP\BridgeLinkBEToolbox\Documentation\BuildDocumentation.bat
call \ARP\PGSuper\Documentation\BuildDocumentation.bat
call \ARP\XBeamRate\Documentation\BuildDocumentation.bat

cd \ARP\BridgeLink
