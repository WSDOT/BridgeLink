// JScript source code
var FSO = new ActiveXObject("Scripting.FileSystemObject");
var ImagesFolder = FSO.GetFolder("\\ARP_RELEASE\\XBeamRate\\8.0.9.0\\bin\\images");
var XBRateDocsFolder = FSO.GetFolder("\\ARP\\BridgeLink\\Docs\\XBRate\\8.0");
var XBRateDocsSearchFolder = FSO.GetFolder("\\ARP\\BridgeLink\\Docs\\XBRate\\8.0\\search");

WScript.Echo("<?xml version='1.0'?>");
WScript.Echo("<!-- This file genereted by BuildXBeamRateImagesFragment.js script-->");
WScript.Echo("<Wix xmlns='http://schemas.microsoft.com/wix/2006/wi'>");

WScript.Echo("<!-- Include project wide variables -->");
WScript.Echo("<?include Variables.wxi?>");

// Report Images Files
WScript.Echo("<Fragment Id='XBRImages'>");

WScript.Echo("<DirectoryRef Id=\"APPLICATIONFOLDER\" FileSource =\"$(var.XBeamRateSourceRoot)\AutomationDlls\$(var.PlatformFolder)\" >");
WScript.Echo("<Directory Id=\"XBRImages\" Name=\"Images\" /> <!-- Create the Images directory -->");
WScript.Echo("</DirectoryRef>");

WScript.Echo("<DirectoryRef Id='XBRImages' FileSource='$(var.XBeamRateSourceRoot)\Images'>");
WScript.Echo("<Component Id='XBRImages' Guid='{E57F7374-4468-452e-ABEF-5BF78C13EED0}' Win64='$(var.IsWin64)'>");
var i = 0;
var fc = new Enumerator(ImagesFolder.Files);
for (; !fc.atEnd(); fc.moveNext()) {
   var s = new String(fc.item());
   var lastIdx = s.lastIndexOf("\\");
   var fileName = new String;
   fileName = s.substring(lastIdx + 1);

   var fileExt = new String;
   fileExt = fileName.substring(fileName.lastIndexOf("."));

   var fileTag = new String;
   if (fileExt == ".dm")
       fileTag = "<File Id='XBRImage" + (i++) + "' Name='" + fileName + "' KeyPath='yes' />";
   else
      fileTag = "<File Id='XBRImage" + (i++) + "' Name='" + fileName + "' />";

   WScript.Echo(fileTag);
}
WScript.Echo("</Component>");
WScript.Echo("</DirectoryRef>");
WScript.Echo("</Fragment>");

WScript.Echo("<Fragment Id='XBRateDocs'>");

WScript.Echo("<DirectoryRef Id=\"Documentation\" FileSource =\"$(var.XBRateDocumentationSourceRoot)\">");
WScript.Echo("<Directory Id=\"XBRateDocsRoot\" Name=\"$(var.XBRateDocumentationTarget)\"> <!-- Create the documentation directory -->");
WScript.Echo("<Directory Id=\"XBRateDocs\" Name=\"$(var.XBRateDocumentationVersion)\"> <!-- Create the documentation directory -->");
WScript.Echo("<Directory Id=\"XBRateSearchDocs\" Name=\"search\"> <!-- Create the search directory -->");
WScript.Echo("</Directory>");
WScript.Echo("</Directory>");
WScript.Echo("</Directory>");
WScript.Echo("</DirectoryRef>");

WScript.Echo("<DirectoryRef Id='XBRateDocs' FileSource=\"$(var.XBRateDocumentationSourceRoot)\">");
WScript.Echo("<Component Id='XBRateDocs' Guid='{2B06B8FF-CB08-4726-8481-C109725C9691}' Win64='$(var.IsWin64)'>");
var fcDocs = new Enumerator(XBRateDocsFolder.Files);
var i = 0;
for (; !fcDocs.atEnd(); fcDocs.moveNext()) {
    var s = new String(fcDocs.item());
    var lastIdx = s.lastIndexOf("\\");
    var fileName = new String;
    fileName = s.substring(lastIdx + 1);

    var fileTag = new String;
    if (fileName == "index.html")
        fileTag = "<File Id='XBRateDocs" + (i++) + "' Name='" + fileName + "' KeyPath='yes' />";
    else
        fileTag = "<File Id='XBRateDocs" + (i++) + "' Name='" + fileName + "' />";

    WScript.Echo(fileTag);
}
WScript.Echo("</Component>");
WScript.Echo("</DirectoryRef>");

WScript.Echo("<DirectoryRef Id='XBRateSearchDocs' FileSource=\"$(var.XBRateDocumentationSourceRoot)\\search\">");
WScript.Echo("<Component Id='XBRateSearchDocs' Guid='' Win64='$(var.IsWin64)'>");
var fcSearchDocs = new Enumerator(XBRateDocsSearchFolder.Files);
var i = 0;
for (; !fcSearchDocs.atEnd(); fcSearchDocs.moveNext()) {
   var s = new String(fcSearchDocs.item());
   var lastIdx = s.lastIndexOf("\\");
   var fileName = new String;
   fileName = s.substring(lastIdx + 1);

   var fileExt = new String;
   fileExt = fileName.substring(fileName.lastIndexOf("."));

   var fileTag = new String;
   fileTag = "<File Id='XBRateSearchDocs" + (i++) + "' Name='" + fileName + "' />";

   WScript.Echo(fileTag);
}
WScript.Echo("</Component>");
WScript.Echo("</DirectoryRef>");

WScript.Echo("</Fragment>");

WScript.Echo("</Wix>");

WScript.Quit(0);
