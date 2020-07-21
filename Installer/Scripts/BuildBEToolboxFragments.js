// JScript source code
var FSO = new ActiveXObject("Scripting.FileSystemObject");
var ImagesFolder = FSO.GetFolder("\\ARP_RELEASE\\BEToolbox\\6.0.0.0\\bin\\images");
var BEToolboxDocsFolder = FSO.GetFolder("\\ARP\\BridgeLink\\Docs\\BEToolbox\\6.0");
var fc = new Enumerator(ImagesFolder.Files);

WScript.Echo("<?xml version='1.0'?>");
WScript.Echo("<!-- This file genereted by BuildBEToolboxFragments.js script-->");
WScript.Echo("<Wix xmlns='http://schemas.microsoft.com/wix/2006/wi'>");


WScript.Echo("<!-- Include project wide variables -->");
WScript.Echo("<?include Variables.wxi?>");

// Report Images Files
WScript.Echo("<Fragment Id='BETImages'>");

WScript.Echo("<DirectoryRef Id=\"APPLICATIONFOLDER\" FileSource =\"$(var.BEToolboxSourceRoot)\AutomationDlls\$(var.PlatformFolder)\" >");
WScript.Echo("<Directory Id=\"BETImages\" Name=\"Images\" /> <!-- Create the Images directory -->");
WScript.Echo("</DirectoryRef>");

WScript.Echo("<DirectoryRef Id='BETImages' FileSource='$(var.BEToolboxSourceRoot)\Images'>");
WScript.Echo("<Component Id='BEToolboxImages' Guid='{857D64B5-DF3B-4b40-84C6-253EF430077E}' Win64='$(var.IsWin64)'>");
var i = 0;
for (; !fc.atEnd(); fc.moveNext()) {
    var s = new String(fc.item());
    var lastIdx = s.lastIndexOf("\\");
    var fileName = new String;
    fileName = s.substring(lastIdx + 1);

    var fileExt = new String;
    fileExt = fileName.substring(fileName.lastIndexOf("."));

    var fileTag = new String;
    if (fileExt == ".dm")
        fileTag = "<File Id='BETImage" + (i++) + "' Name='" + fileName + "' KeyPath='yes' />";
    else
        fileTag = "<File Id='BETImage" + (i++) + "' Name='" + fileName + "' />";

    WScript.Echo(fileTag);
}
WScript.Echo("</Component>");
WScript.Echo("</DirectoryRef>");
WScript.Echo("</Fragment>");

WScript.Echo("<!-- Documentation Files -->");
WScript.Echo("<Fragment Id='BEToolboxDocs'>");

WScript.Echo("<DirectoryRef Id=\"Documentation\" FileSource =\"$(var.BEToolboxDocumentationSourceRoot)\">");
WScript.Echo("<Directory Id=\"BEToolboxDocsRoot\" Name=\"$(var.BEToolboxDocumentationTarget)\"> <!-- Create the documentation directory -->");
WScript.Echo("<Directory Id=\"BEToolboxDocs\" Name=\"$(var.BEToolboxDocumentationVersion)\"/> <!-- Create the documentation directory -->");
WScript.Echo("</Directory>");
WScript.Echo("</DirectoryRef>");

WScript.Echo("<DirectoryRef Id='BEToolboxDocs' FileSource=\"$(var.BEToolboxDocumentationSourceRoot)\">");
WScript.Echo("<Component Id='BEToolboxDocs' Guid='{F975C9D5-A6E5-4c37-80EE-6E915A4BEDF3}' Win64='$(var.IsWin64)'>");
var fcDocs = new Enumerator(BEToolboxDocsFolder.Files);
var i = 0;
for (; !fcDocs.atEnd(); fcDocs.moveNext()) {
    var s = new String(fcDocs.item());
    var lastIdx = s.lastIndexOf("\\");
    var fileName = new String;
    fileName = s.substring(lastIdx + 1);

    var fileExt = new String;
    fileExt = fileName.substring(fileName.lastIndexOf("."));

    var fileTag = new String;
    if (fileExt == ".dm")
        fileTag = "<File Id='BEToolboxDocs" + (i++) + "' Name='" + fileName + "' KeyPath='yes' />";
    else
        fileTag = "<File Id='BEToolboxDocs" + (i++) + "' Name='" + fileName + "' />";

    WScript.Echo(fileTag);
}
WScript.Echo("</Component>");
WScript.Echo("</DirectoryRef>");
WScript.Echo("</Fragment>");

WScript.Echo("</Wix>");

WScript.Quit(0);
