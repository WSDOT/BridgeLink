// JScript source code
var FSO = new ActiveXObject("Scripting.FileSystemObject");
var ImagesFolder = FSO.GetFolder("\\ARP_RELEASE\\PGSuper\\4.0.6.0\\bin\\images");
var PGSuperDocsFolder = FSO.GetFolder("\\ARP\\BridgeLink\\Docs\\PGSuper\\4.0");
var PGSpliceDocsFolder = FSO.GetFolder("\\ARP\\BridgeLink\\Docs\\PGSplice\\4.0");
var PGSLibraryDocsFolder = FSO.GetFolder("\\ARP\\BridgeLink\\Docs\\PGSLibrary\\4.0");
var TOGADocsFolder = FSO.GetFolder("\\ARP\\BridgeLink\\Docs\\TOGA\\4.0");
var KDOTDocsFolder = FSO.GetFolder("\\ARP\\BridgeLink\\Docs\\KDOT\\4.0");

var fc = new Enumerator(ImagesFolder.Files);

WScript.Echo("<?xml version='1.0'?>");
WScript.Echo("<!-- This file genereted by BuildPGSuperImagesFragment.js script-->");
WScript.Echo("<Wix xmlns='http://schemas.microsoft.com/wix/2006/wi'>");

WScript.Echo("<!-- Include project wide variables -->");
WScript.Echo("<?include Variables.wxi?>");

// Report Images Files
WScript.Echo("<Fragment Id='Images'>");

WScript.Echo("<DirectoryRef Id=\"APPLICATIONFOLDER\" FileSource =\"$(var.PGSuperSourceRoot)\AutomationDlls\$(var.PlatformFolder)\" >");
WScript.Echo("<Directory Id=\"Images\" Name=\"Images\" /> <!-- Create the Images directory -->");
WScript.Echo("</DirectoryRef>");

WScript.Echo("<DirectoryRef Id='Images' FileSource='$(var.PGSuperSourceRoot)\Images'>");
WScript.Echo("<Component Id='Images' Guid='{1F1083F4-5C49-46b7-880E-A34DCB3D79C9}' Win64='$(var.IsWin64)'>");
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
       fileTag = "<File Id='Image" + (i++) + "' Name='" + fileName + "' KeyPath='yes' />";
   else
      fileTag = "<File Id='Image" + (i++) + "' Name='" + fileName + "' />";

   WScript.Echo(fileTag);
}
WScript.Echo("</Component>");
WScript.Echo("</DirectoryRef>");
WScript.Echo("</Fragment>");

// Documentation Files
WScript.Echo("<Fragment Id='PGSuperDocs'>");

WScript.Echo("<DirectoryRef Id=\"Documentation\" FileSource =\"$(var.PGSuperDocumentationSourceRoot)\">");
WScript.Echo("<Directory Id=\"PGSuperDocsRoot\" Name=\"$(var.PGSuperDocumentationTarget)\"> <!-- Create the documentation directory -->");
WScript.Echo("<Directory Id=\"PGSuperDocs\" Name=\"$(var.PGSuperDocumentationVersion)\"/> <!-- Create the documentation directory -->");
WScript.Echo("</Directory>");
WScript.Echo("</DirectoryRef>");

WScript.Echo("<DirectoryRef Id='PGSuperDocs' FileSource=\"$(var.PGSuperDocumentationSourceRoot)\">");
WScript.Echo("<Component Id='PGSuperDocs' Guid='{CF5F4A84-93E9-47e7-B405-B8DE747B98A9}' Win64='$(var.IsWin64)'>");
var fcDocs = new Enumerator(PGSuperDocsFolder.Files);
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
        fileTag = "<File Id='PGSuperDocs" + (i++) + "' Name='" + fileName + "' KeyPath='yes' />";
    else
        fileTag = "<File Id='PGSuperDocs" + (i++) + "' Name='" + fileName + "' />";

    WScript.Echo(fileTag);
}
WScript.Echo("</Component>");
WScript.Echo("</DirectoryRef>");
WScript.Echo("</Fragment>");

/////////////////////////////////////////////////////
WScript.Echo("<Fragment Id='PGSpliceDocs'>");

WScript.Echo("<DirectoryRef Id=\"Documentation\" FileSource =\"$(var.PGSpliceDocumentationSourceRoot)\">");
WScript.Echo("<Directory Id=\"PGSpliceDocsRoot\" Name=\"$(var.PGSpliceDocumentationTarget)\"> <!-- Create the documentation directory -->");
WScript.Echo("<Directory Id=\"PGSpliceDocs\" Name=\"$(var.PGSpliceDocumentationVersion)\"/> <!-- Create the documentation directory -->");
WScript.Echo("</Directory>");
WScript.Echo("</DirectoryRef>");

WScript.Echo("<DirectoryRef Id='PGSpliceDocs' FileSource=\"$(var.PGSpliceDocumentationSourceRoot)\">");
WScript.Echo("<Component Id='PGSpliceDocs' Guid='{AA5CB22A-488A-44ee-885F-6AA269F9663A}' Win64='$(var.IsWin64)'>");
var fcDocs = new Enumerator(PGSpliceDocsFolder.Files);
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
        fileTag = "<File Id='PGSpliceDocs" + (i++) + "' Name='" + fileName + "' KeyPath='yes' />";
    else
        fileTag = "<File Id='PGSpliceDocs" + (i++) + "' Name='" + fileName + "' />";

    WScript.Echo(fileTag);
}
WScript.Echo("</Component>");
WScript.Echo("</DirectoryRef>");
WScript.Echo("</Fragment>");


/////////////////////////////////////////////////////
WScript.Echo("<Fragment Id='PGSLibraryDocs'>");

WScript.Echo("<DirectoryRef Id=\"Documentation\" FileSource =\"$(var.PGSLibraryDocumentationSourceRoot)\">");
WScript.Echo("<Directory Id=\"PGSLibraryDocsRoot\" Name=\"$(var.PGSLibraryDocumentationTarget)\"> <!-- Create the documentation directory -->");
WScript.Echo("<Directory Id=\"PGSLibraryDocs\" Name=\"$(var.PGSLibraryDocumentationVersion)\"/> <!-- Create the documentation directory -->");
WScript.Echo("</Directory>");
WScript.Echo("</DirectoryRef>");

WScript.Echo("<DirectoryRef Id='PGSLibraryDocs' FileSource=\"$(var.PGSLibraryDocumentationSourceRoot)\">");
WScript.Echo("<Component Id='PGSLibraryDocs' Guid='{6665BED1-FF38-4358-B980-5CCBBCD49C8B}' Win64='$(var.IsWin64)'>");
var fcDocs = new Enumerator(PGSLibraryDocsFolder.Files);
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
        fileTag = "<File Id='PGSLibraryDocs" + (i++) + "' Name='" + fileName + "' KeyPath='yes' />";
    else
        fileTag = "<File Id='PGSLibraryDocs" + (i++) + "' Name='" + fileName + "' />";

    WScript.Echo(fileTag);
}
WScript.Echo("</Component>");
WScript.Echo("</DirectoryRef>");
WScript.Echo("</Fragment>");


/////////////////////////////////////////////////////
WScript.Echo("<Fragment Id='TOGADocs'>");

WScript.Echo("<DirectoryRef Id=\"Documentation\" FileSource =\"$(var.TOGADocumentationSourceRoot)\">");
WScript.Echo("<Directory Id=\"TOGADocsRoot\" Name=\"$(var.TOGADocumentationTarget)\"> <!-- Create the documentation directory -->");
WScript.Echo("<Directory Id=\"TOGADocs\" Name=\"$(var.TOGADocumentationVersion)\"/> <!-- Create the documentation directory -->");
WScript.Echo("</Directory>");
WScript.Echo("</DirectoryRef>");

WScript.Echo("<DirectoryRef Id='TOGADocs' FileSource=\"$(var.TOGADocumentationSourceRoot)\">");
WScript.Echo("<Component Id='TOGADocs' Guid='{AC181102-FE63-4fa0-8BB2-CC5F9695E4B3}' Win64='$(var.IsWin64)'>");
var fcDocs = new Enumerator(TOGADocsFolder.Files);
var i = 0;
for (; !fcDocs.atEnd(); fcDocs.moveNext()) {
    var s = new String(fcDocs.item());
    var lastIdx = s.lastIndexOf("\\");
    var fileName = new String;
    fileName = s.substring(lastIdx + 1);

    var fileTag = new String;
    if (fileName == "index.html")
        fileTag = "<File Id='TOGADocs" + (i++) + "' Name='" + fileName + "' KeyPath='yes' />";
    else
        fileTag = "<File Id='TOGADocs" + (i++) + "' Name='" + fileName + "' />";

    WScript.Echo(fileTag);
}
WScript.Echo("</Component>");
WScript.Echo("</DirectoryRef>");
WScript.Echo("</Fragment>");


/////////////////////////////////////////////////////
WScript.Echo("<Fragment Id='KDOTDocs'>");

WScript.Echo("<DirectoryRef Id=\"Documentation\" FileSource =\"$(var.KDOTDocumentationSourceRoot)\">");
WScript.Echo("<Directory Id=\"KDOTDocsRoot\" Name=\"$(var.KDOTDocumentationTarget)\"> <!-- Create the documentation directory -->");
WScript.Echo("<Directory Id=\"KDOTDocs\" Name=\"$(var.KDOTDocumentationVersion)\"/> <!-- Create the documentation directory -->");
WScript.Echo("</Directory>");
WScript.Echo("</DirectoryRef>");

WScript.Echo("<DirectoryRef Id='KDOTDocs' FileSource=\"$(var.KDOTDocumentationSourceRoot)\">");
WScript.Echo("<Component Id='KDOTDocs' Guid='{38CE2D02-E0CF-4bc1-B194-7EFAED0A10D0}' Win64='$(var.IsWin64)'>");
var fcDocs = new Enumerator(KDOTDocsFolder.Files);
var i = 0;
for (; !fcDocs.atEnd(); fcDocs.moveNext()) {
    var s = new String(fcDocs.item());
    var lastIdx = s.lastIndexOf("\\");
    var fileName = new String;
    fileName = s.substring(lastIdx + 1);

    var fileTag = new String;
    if (fileName == "index.html")
        fileTag = "<File Id='KDOTDocs" + (i++) + "' Name='" + fileName + "' KeyPath='yes' />";
    else
        fileTag = "<File Id='KDOTDocs" + (i++) + "' Name='" + fileName + "' />";

    WScript.Echo(fileTag);
}
WScript.Echo("</Component>");
WScript.Echo("</DirectoryRef>");
WScript.Echo("</Fragment>");

WScript.Echo("</Wix>");

WScript.Quit(0);
