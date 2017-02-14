var wsShell = new ActiveXObject("WScript.Shell");
var objArgs = WScript.Arguments;
var directory;
if ( objArgs.Count() == 0 )
   directory = ".\\x64\\Release";
else
   directory = objArgs(0);

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
         var cmd = "%SYSTEMROOT%\\System32\\regsvr32.exe /s " + fileName;
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