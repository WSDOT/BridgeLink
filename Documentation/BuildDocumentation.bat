cd \ARP\BridgeLink\Documentation

doxygen Doxygen.dox

\ARP\BridgeLink\RegFreeCOM\x64\Release\MakeDocMap BridgeLink
rmdir /S /Q \ARP\BridgeLink\Docs\BridgeLink\%1\
mkdir \ARP\BridgeLink\Docs\BridgeLink\%1\
copy \ARP\BridgeLink\Documentation\doc\html\* \ARP\BridgeLink\Docs\BridgeLink\%1\
copy \ARP\BridgeLink\Documentation\BridgeLink.dm \ARP\BridgeLink\Docs\BridgeLink\%1\
