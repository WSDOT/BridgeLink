// JScript source code
var FSO = new ActiveXObject("Scripting.FileSystemObject");
var ImagesFolder = FSO.GetFolder("\\ARP_RELEASE\\PGSuper\\8.0.5.0\\bin\\images");
var PGSuperDocsFolder = FSO.GetFolder("\\ARP\\BridgeLink\\Docs\\PGSuper\\8.0");
var PGSuperDocsSearchFolder = FSO.GetFolder("\\ARP\\BridgeLink\\Docs\\PGSuper\\8.0\\search");
var PGSpliceDocsFolder = FSO.GetFolder("\\ARP\\BridgeLink\\Docs\\PGSplice\\8.0");
var PGSpliceDocsSearchFolder = FSO.GetFolder("\\ARP\\BridgeLink\\Docs\\PGSplice\\8.0\\search");
var PGSLibraryDocsFolder = FSO.GetFolder("\\ARP\\BridgeLink\\Docs\\PGSLibrary\\8.0");
var PGSLibraryDocsSearchFolder = FSO.GetFolder("\\ARP\\BridgeLink\\Docs\\PGSLibrary\\8.0\\search");
var TOGADocsFolder = FSO.GetFolder("\\ARP\\BridgeLink\\Docs\\TOGA\\8.0");
var TOGADocsSearchFolder = FSO.GetFolder("\\ARP\\BridgeLink\\Docs\\TOGA\\8.0\\search");
var TxCADExportDocsFolder = FSO.GetFolder("\\ARP\\BridgeLink\\Docs\\TxCADExport\\8.0");
var TxCADExportDocsSearchFolder = FSO.GetFolder("\\ARP\\BridgeLink\\Docs\\TxCADExport\\8.0\\search");
var KDOTDocsFolder = FSO.GetFolder("\\ARP\\BridgeLink\\Docs\\KDOT\\8.0");
var KDOTDocsSearchFolder = FSO.GetFolder("\\ARP\\BridgeLink\\Docs\\KDOT\\8.0\\search");

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
WScript.Echo("<Directory Id=\"PGSuperDocs\" Name=\"$(var.PGSuperDocumentationVersion)\"> <!-- Create the documentation version number directory -->");
WScript.Echo("<Directory Id=\"PGSuperSearchDocs\" Name=\"search\"> <!-- Create the documentation search directory -->");
WScript.Echo("</Directory>");
WScript.Echo("</Directory>");
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

WScript.Echo("<DirectoryRef Id='PGSuperSearchDocs' FileSource=\"$(var.PGSuperDocumentationSourceRoot)\\search\">");
WScript.Echo("<Component Id='PGSuperSearchDocs' Guid='{813EA28D-F49B-441F-95CE-069869669A02}' Win64='$(var.IsWin64)'>");
var fcSearchDocs = new Enumerator(PGSuperDocsSearchFolder.Files);
var i = 0;
for (; !fcSearchDocs.atEnd(); fcSearchDocs.moveNext()) {
   var s = new String(fcSearchDocs.item());
   var lastIdx = s.lastIndexOf("\\");
   var fileName = new String;
   fileName = s.substring(lastIdx + 1);

   var fileExt = new String;
   fileExt = fileName.substring(fileName.lastIndexOf("."));

   var fileTag = new String;
   fileTag = "<File Id='PGSuperSearchDocs" + (i++) + "' Name='" + fileName + "' />";

   WScript.Echo(fileTag);
}
WScript.Echo("</Component>");
WScript.Echo("</DirectoryRef>");

WScript.Echo("</Fragment>");

/////////////////////////////////////////////////////
WScript.Echo("<Fragment Id='PGSpliceDocs'>");

WScript.Echo("<DirectoryRef Id=\"Documentation\" FileSource =\"$(var.PGSpliceDocumentationSourceRoot)\">");
WScript.Echo("<Directory Id=\"PGSpliceDocsRoot\" Name=\"$(var.PGSpliceDocumentationTarget)\"> <!-- Create the documentation directory -->");
WScript.Echo("<Directory Id=\"PGSpliceDocs\" Name=\"$(var.PGSpliceDocumentationVersion)\"> <!-- Create the documentation directory -->");
WScript.Echo("<Directory Id=\"PGSpliceSearchDocs\" Name=\"search\"> <!-- Create the documentation search directory -->");
WScript.Echo("</Directory>");
WScript.Echo("</Directory>");
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

WScript.Echo("<DirectoryRef Id='PGSpliceSearchDocs' FileSource=\"$(var.PGSpliceDocumentationSourceRoot)\\search\">");
WScript.Echo("<Component Id='PGSpliceSearchDocs' Guid='{784F6C83-0ED7-4D48-A7DF-77A9BB8DFDAD}' Win64='$(var.IsWin64)'>");
var fcSearchDocs = new Enumerator(PGSpliceDocsSearchFolder.Files);
var i = 0;
for (; !fcSearchDocs.atEnd(); fcSearchDocs.moveNext()) {
   var s = new String(fcSearchDocs.item());
   var lastIdx = s.lastIndexOf("\\");
   var fileName = new String;
   fileName = s.substring(lastIdx + 1);

   var fileExt = new String;
   fileExt = fileName.substring(fileName.lastIndexOf("."));

   var fileTag = new String;
   fileTag = "<File Id='PGSpliceSearchDocs" + (i++) + "' Name='" + fileName + "' />";

   WScript.Echo(fileTag);
}
WScript.Echo("</Component>");
WScript.Echo("</DirectoryRef>");

WScript.Echo("</Fragment>");


/////////////////////////////////////////////////////
WScript.Echo("<Fragment Id='PGSLibraryDocs'>");

WScript.Echo("<DirectoryRef Id=\"Documentation\" FileSource =\"$(var.PGSLibraryDocumentationSourceRoot)\">");
WScript.Echo("<Directory Id=\"PGSLibraryDocsRoot\" Name=\"$(var.PGSLibraryDocumentationTarget)\"> <!-- Create the documentation directory -->");
WScript.Echo("<Directory Id=\"PGSLibraryDocs\" Name=\"$(var.PGSLibraryDocumentationVersion)\"> <!-- Create the documentation directory -->");
WScript.Echo("<Directory Id=\"PGSLibrarySearchDocs\" Name=\"search\"> <!-- Create the documentation search directory -->");
WScript.Echo("</Directory>");
WScript.Echo("</Directory>");
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

WScript.Echo("<DirectoryRef Id='PGSLibrarySearchDocs' FileSource=\"$(var.PGSLibraryDocumentationSourceRoot)\\search\">");
WScript.Echo("<Component Id='PGSLibrarySearchDocs' Guid='{C34F23C5-1E48-4397-93F7-71B1FC848E57}' Win64='$(var.IsWin64)'>");
var fcSearchDocs = new Enumerator(PGSLibraryDocsSearchFolder.Files);
var i = 0;
for (; !fcSearchDocs.atEnd(); fcSearchDocs.moveNext()) {
   var s = new String(fcSearchDocs.item());
   var lastIdx = s.lastIndexOf("\\");
   var fileName = new String;
   fileName = s.substring(lastIdx + 1);

   var fileExt = new String;
   fileExt = fileName.substring(fileName.lastIndexOf("."));

   var fileTag = new String;
   fileTag = "<File Id='PGSLibrarySearchDocs" + (i++) + "' Name='" + fileName + "' />";

   WScript.Echo(fileTag);
}
WScript.Echo("</Component>");
WScript.Echo("</DirectoryRef>");

WScript.Echo("</Fragment>");


/////////////////////////////////////////////////////
WScript.Echo("<Fragment Id='TOGADocs'>");

WScript.Echo("<DirectoryRef Id=\"Documentation\" FileSource =\"$(var.TOGADocumentationSourceRoot)\">");
WScript.Echo("<Directory Id=\"TOGADocsRoot\" Name=\"$(var.TOGADocumentationTarget)\"> <!-- Create the documentation directory -->");
WScript.Echo("<Directory Id=\"TOGADocs\" Name=\"$(var.TOGADocumentationVersion)\"> <!-- Create the documentation directory -->");
WScript.Echo("<Directory Id=\"TOGASearchDocs\" Name=\"search\"> <!-- Create the documentation search directory -->");
WScript.Echo("</Directory>");
WScript.Echo("</Directory>");
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

WScript.Echo("<DirectoryRef Id='TOGASearchDocs' FileSource=\"$(var.TOGADocumentationSourceRoot)\\search\">");
WScript.Echo("<Component Id='TOGASearchDocs' Guid='{E129BE13-E134-4E46-96B3-56CF7D4C4A2C}' Win64='$(var.IsWin64)'>");
var fcSearchDocs = new Enumerator(TOGADocsSearchFolder.Files);
var i = 0;
for (; !fcSearchDocs.atEnd(); fcSearchDocs.moveNext()) {
   var s = new String(fcSearchDocs.item());
   var lastIdx = s.lastIndexOf("\\");
   var fileName = new String;
   fileName = s.substring(lastIdx + 1);

   var fileExt = new String;
   fileExt = fileName.substring(fileName.lastIndexOf("."));

   var fileTag = new String;
   fileTag = "<File Id='TOGASearchDocs" + (i++) + "' Name='" + fileName + "' />";

   WScript.Echo(fileTag);
}
WScript.Echo("</Component>");
WScript.Echo("</DirectoryRef>");
WScript.Echo("</Fragment>");


/////////////////////////////////////////////////////
WScript.Echo("<Fragment Id='TxCADExportDocs'>");

WScript.Echo("<DirectoryRef Id=\"Documentation\" FileSource =\"$(var.TxCADExportDocumentationSourceRoot)\">");
WScript.Echo("<Directory Id=\"TxCADExportDocsRoot\" Name=\"$(var.TxCADExportDocumentationTarget)\"> <!-- Create the documentation directory -->");
WScript.Echo("<Directory Id=\"TxCADExportDocs\" Name=\"$(var.TxCADExportDocumentationVersion)\"> <!-- Create the documentation directory -->");
WScript.Echo("<Directory Id=\"TxCADExportSearchDocs\" Name=\"search\"> <!-- Create the documentation search directory -->");
WScript.Echo("</Directory>");
WScript.Echo("</Directory>");
WScript.Echo("</Directory>");
WScript.Echo("</DirectoryRef>");

WScript.Echo("<DirectoryRef Id='TxCADExportDocs' FileSource=\"$(var.TxCADExportDocumentationSourceRoot)\">");
WScript.Echo("<Component Id='TxCADExportDocs' Guid='{38B4998F-CD5C-407F-9E38-B4E65F7BF577}' Win64='$(var.IsWin64)'>");
var fcDocs = new Enumerator(TxCADExportDocsFolder.Files);
var i = 0;
for (; !fcDocs.atEnd() ; fcDocs.moveNext()) {
    var s = new String(fcDocs.item());
    var lastIdx = s.lastIndexOf("\\");
    var fileName = new String;
    fileName = s.substring(lastIdx + 1);

    var fileTag = new String;
    if (fileName == "index.html")
        fileTag = "<File Id='TxCADExportDocs" + (i++) + "' Name='" + fileName + "' KeyPath='yes' />";
    else
        fileTag = "<File Id='TxCADExportDocs" + (i++) + "' Name='" + fileName + "' />";

    WScript.Echo(fileTag);
}
WScript.Echo("</Component>");
WScript.Echo("</DirectoryRef>");

WScript.Echo("<DirectoryRef Id='TxCADExportSearchDocs' FileSource=\"$(var.TxCADExportDocumentationSourceRoot)\\search\">");
WScript.Echo("<Component Id='TxCADExportSearchDocs' Guid='{6FD417DE-AAA9-4BA8-B3B8-06F2B4B87879}' Win64='$(var.IsWin64)'>");
var fcSearchDocs = new Enumerator(TxCADExportDocsSearchFolder.Files);
var i = 0;
for (; !fcSearchDocs.atEnd(); fcSearchDocs.moveNext()) {
   var s = new String(fcSearchDocs.item());
   var lastIdx = s.lastIndexOf("\\");
   var fileName = new String;
   fileName = s.substring(lastIdx + 1);

   var fileExt = new String;
   fileExt = fileName.substring(fileName.lastIndexOf("."));

   var fileTag = new String;
   fileTag = "<File Id='TxCADExportSearchDocs" + (i++) + "' Name='" + fileName + "' />";

   WScript.Echo(fileTag);
}
WScript.Echo("</Component>");
WScript.Echo("</DirectoryRef>");
WScript.Echo("</Fragment>");

/////////////////////////////////////////////////////
WScript.Echo("<Fragment Id='KDOTDocs'>");

WScript.Echo("<DirectoryRef Id=\"Documentation\" FileSource =\"$(var.KDOTDocumentationSourceRoot)\">");
WScript.Echo("<Directory Id=\"KDOTDocsRoot\" Name=\"$(var.KDOTDocumentationTarget)\"> <!-- Create the documentation directory -->");
WScript.Echo("<Directory Id=\"KDOTDocs\" Name=\"$(var.KDOTDocumentationVersion)\"> <!-- Create the documentation directory -->");
WScript.Echo("<Directory Id=\"KDOTSearchDocs\" Name=\"search\"> <!-- Create the documentation search directory -->");
WScript.Echo("</Directory>");
WScript.Echo("</Directory>");
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

WScript.Echo("<DirectoryRef Id='KDOTSearchDocs' FileSource=\"$(var.KDOTDocumentationSourceRoot)\\search\">");
WScript.Echo("<Component Id='KDOTSearchDocs' Guid='{F7F877C7-9D70-4CB2-9090-DFF9218C9E19}' Win64='$(var.IsWin64)'>");
var fcSearchDocs = new Enumerator(KDOTDocsSearchFolder.Files);
var i = 0;
for (; !fcSearchDocs.atEnd(); fcSearchDocs.moveNext()) {
   var s = new String(fcSearchDocs.item());
   var lastIdx = s.lastIndexOf("\\");
   var fileName = new String;
   fileName = s.substring(lastIdx + 1);

   var fileExt = new String;
   fileExt = fileName.substring(fileName.lastIndexOf("."));

   var fileTag = new String;
   fileTag = "<File Id='KDOTSearchDocs" + (i++) + "' Name='" + fileName + "' />";

   WScript.Echo(fileTag);
}
WScript.Echo("</Component>");
WScript.Echo("</DirectoryRef>");
WScript.Echo("</Fragment>");

WScript.Echo("</Wix>");

WScript.Quit(0);
