cd %ARPDIR%\BridgeLink\Documentation

rmdir /S /Q doc
doxygen Doxygen.dox

%ARPDIR%\BridgeLink\RegFreeCOM\x64\Release\MakeDocMap BridgeLink
rmdir /S /Q %ARPDIR%\BridgeLink\Docs\BridgeLink\%1\
mkdir %ARPDIR%\BridgeLink\Docs\BridgeLink\%1\
copy %ARPDIR%\BridgeLink\Documentation\doc\html\* %ARPDIR%\BridgeLink\Docs\BridgeLink\%1\
copy %ARPDIR%\BridgeLink\Documentation\BridgeLink.dm %ARPDIR%\BridgeLink\Docs\BridgeLink\%1\
