// JScript source code
var FSO = new ActiveXObject("Scripting.FileSystemObject");
var BridgeLinkDocsFolder = FSO.GetFolder("\\ARP_RELEASE\\BridgeLink\\1.0.0.32\\bin\\App\\Docs");
var fc = new Enumerator(BridgeLinkDocsFolder.Files);

WScript.Echo("<?xml version='1.0'?>");
WScript.Echo("<!-- This file genereted by BuildBridgeLinkFragment.js script-->");
WScript.Echo("<Wix xmlns='http://schemas.microsoft.com/wix/2006/wi'>");

WScript.Echo("<!-- Include project wide variables -->");
WScript.Echo("<?include Variables.wxi?>");

WScript.Echo("<!-- Documentation Files -->");
WScript.Echo("<Fragment Id='BridgeLinkDocs'>");

WScript.Echo("<DirectoryRef Id=\"Documentation\" FileSource =\"$(var.BridgeLinkSourceRoot)App\\Docs\">");
WScript.Echo("<Directory Id=\"BridgeLinkDocs\" Name=\"BridgeLink\"/> <!-- Create the documentation directory -->");
WScript.Echo("</DirectoryRef>");


WScript.Echo("<DirectoryRef Id='BridgeLinkDocs' FileSource=\"$(var.BridgeLinkSourceRoot)App\\Docs\">");
WScript.Echo("<Component Id='BridgeLinkDocs' Guid='{EA697C8B-8863-420d-BCB7-411C653DC2EE}' Win64='$(var.IsWin64)'>");
var fcDocs = new Enumerator(BridgeLinkDocsFolder.Files);
var i = 0;
for (; !fcDocs.atEnd(); fcDocs.moveNext()) {
    var s = new String(fcDocs.item());
    var lastIdx = s.lastIndexOf("\\");
    var fileName = new String;
    fileName = s.substring(lastIdx + 1);

    var fileTag = new String;
    if (fileName == "index.html")
        fileTag = "<File Id='BridgeLinkDocs" + (i++) + "' Name='" + fileName + "' KeyPath='yes' />";
    else
        fileTag = "<File Id='BridgeLinkDocs" + (i++) + "' Name='" + fileName + "' />";

    WScript.Echo(fileTag);
}
WScript.Echo("</Component>");
WScript.Echo("</DirectoryRef>");
WScript.Echo("</Fragment>");

WScript.Echo("</Wix>");

WScript.Quit(0);
