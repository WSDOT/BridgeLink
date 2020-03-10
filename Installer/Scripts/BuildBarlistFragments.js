// JScript source code
var FSO = new ActiveXObject("Scripting.FileSystemObject");
var BarlistDocsFolder = FSO.GetFolder("\\ARP\\BridgeLink\\Docs\\Barlist\\5.3");
var fc = new Enumerator(BarlistDocsFolder.Files);

WScript.Echo("<?xml version='1.0'?>");
WScript.Echo("<!-- This file genereted by BuildBarlistFragment.js script-->");
WScript.Echo("<Wix xmlns='http://schemas.microsoft.com/wix/2006/wi'>");

WScript.Echo("<!-- Include project wide variables -->");
WScript.Echo("<?include Variables.wxi?>");

WScript.Echo("<!-- Documentation Files -->");
WScript.Echo("<Fragment Id='BarlistDocs'>");

WScript.Echo("<DirectoryRef Id=\"Documentation\" FileSource =\"$(var.BarlistDocumentationSourceRoot)\">");
WScript.Echo("<Directory Id=\"BarlistDocsRoot\" Name=\"$(var.BarlistDocumentationTarget)\"> <!-- Create the documentation directory -->");
WScript.Echo("<Directory Id=\"BarlistDocs\" Name=\"$(var.BarlistDocumentationVersion)\"/> <!-- Create the documentation directory -->");
WScript.Echo("</Directory>");
WScript.Echo("</DirectoryRef>");


WScript.Echo("<DirectoryRef Id='BarlistDocs' FileSource=\"$(var.BarlistDocumentationSourceRoot)\">");
WScript.Echo("<Component Id='BarlistDocs' Guid='{EA697C8B-8863-420d-BCB7-411C653DC2EE}' Win64='$(var.IsWin64)'>");
var fcDocs = new Enumerator(BarlistDocsFolder.Files);
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
        fileTag = "<File Id='BarlistDocs" + (i++) + "' Name='" + fileName + "' KeyPath='yes' />";
    else
        fileTag = "<File Id='BarlistDocs" + (i++) + "' Name='" + fileName + "' />";

    WScript.Echo(fileTag);
}
WScript.Echo("</Component>");
WScript.Echo("</DirectoryRef>");
WScript.Echo("</Fragment>");

WScript.Echo("</Wix>");

WScript.Quit(0);
