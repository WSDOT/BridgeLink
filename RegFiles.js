////////////////////////////////////////////////////////////////////////
// Performs self-registration for all COM DLLs
// Run this script before running a release or debug build
// If the wrong type (debug/release) DLLs are registered when
// launching from the IDE, the application can crash.
//
// To setup registration commands in Visual Studio
// 1) Select Tools > External Tools
// 2) Press [Add]
// 3) Enter the following
//
// For x64 Debug builds
// Title: Register (x64 Debug)
// Command: cscript.exe
// Arguments: F:\ARP\BridgeLink\RegFreeCOM\RegFiles.js .\x64\Debug
// Initial Directory: F:\ARP\BridgeLink\RegFreeCOM\
// Use Output Window [x]
//
// For x64 Release builds
// Title: Register (x64 Release)
// Command: cscript.exe
// Arguments: F:\ARP\BridgeLink\RegFreeCOM\RegFiles.js
// Initial Directory: F:\ARP\BridgeLink\RegFreeCOM\
// Use Output Window [x]
//
// For Unregistering x64 Debug builds
// Title: Unregister (x64 Debug)
// Command: cscript.exe
// Arguments: F:\ARP\BridgeLink\RegFreeCOM\RegFiles.js
// Initial Directory: F:\ARP\BridgeLink\RegFreeCOM\ .\x64\Debug /u
// Use Output Window [x]
//
// For Unregistering x64 Release builds
// Title: Unregister (x64 Release)
// Command: cscript.exe
// Arguments: F:\ARP\BridgeLink\RegFreeCOM\RegFiles.js
// Initial Directory: F:\ARP\BridgeLink\RegFreeCOM\ .\x64\Release /u
// Use Output Window [x]
//
// NOTE: The External Tools feature doesn't seem to be able to interpret the $(ARPDIR) environment variable. You will need to change "F:\ARP" to whereever your ARPDIR.

var wsShell = new ActiveXObject("WScript.Shell");
var objArgs = WScript.Arguments;
var directory;
if ( objArgs.Count() == 0 )
   directory = ".\\x64\\Release";
else
    directory = objArgs(0);

var options;
if (objArgs.Count() == 2)
    options = objArgs(1) + " ";
else
    options = "";

var FSO = new ActiveXObject("Scripting.FileSystemObject");
var folder = FSO.GetFolder(directory);
var fc = new Enumerator(folder.Files);
for ( fc.moveFirst(); !fc.atEnd(); fc.moveNext() )
{
   var fileName = new String(fc.item());

   idx = fileName.indexOf(".dll");
   if ( idx != -1 )
   {
      // we have a DLL

      idx = fileName.lastIndexOf('\\');
      // make sure it isn't a WBFL dll - these don't get registered because we are using RegFreeCOM
      if (fileName.substring(idx+1,idx+5) != "WBFL")
      {
         var cmd = "%SYSTEMROOT%\\System32\\regsvr32.exe /s " + options + fileName;
         var result = wsShell.Run(cmd,1,"TRUE");

         var msg = cmd;
         if (result == 0)
             msg += " - SUCCEEDED";
         else if (result == 4)
             msg += " - dll does not have DllRegisterServer " + result;
         else
             msg += " ***ERROR*** " + result;
         WScript.Echo(msg);
      }
   }
}

WScript.Echo("Done");