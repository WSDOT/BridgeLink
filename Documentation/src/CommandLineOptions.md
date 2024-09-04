Command Line Options {#command_line_options}
=======================
The typical method for running a Windows program is through an interactive user interface and BridgeLink is no different. Additionally, BridgeLink can be run from the command line so you can perform customized batch processing. Here we will discuss the general method of running BridgeLink from the command line.

The notation \<options\> will mean any command line option supported by BridgeLink. 

The notation \<app options\> will mean any command line option supported by a BridgeLink Application such as PGSuper or PGSplice.

Command line options are of the format:
              /command \<arg\>

Where the option always begins with the '/' character followed by a command. Commands can be a single character such as /a or a word such as /Help.

Commands can have optional arguments as identified by \<arg\>. An example of a command with an argument is /open mainwindow

Executing BridgeLink from the command line
-----------------------------------------------
To execute BridgeLink from the command line enter the following at a command prompt:

        BridgeLink.exe <options>

BridgeLink Command Line Options
----------------------------------
BridgeLink command line options are described in the table below

Option | Description
-------|---------------
(blank), no options given | BridgeLink starts in interactive mode when no command line options are given. In interactive mode, you use the graphical user interface to operate the program
\<_filename_\> | BrideLink starts in interactive mode and opens the supplied file with its associated BridgeLink application.
\<options\> | BridgeLink starts in command mode when options are given. In command mode, BridgeLink starts, executes the command options, and terminates.
/? | Displays the command line options window
/Help | Same as /?
\<app options\> \<_filename_\> | BridgeLink opens the file with its associated BridgeLink Application. For example, if a file with a pgs extension is given on the command line, BridgeLink opens the file with PGSuper. The application specific options, \<app options\> are then processed by the BridgeLink Application. If the file name is omitted, the application specific options \<app options\> are passed to all BridgeLink Applications until an application is found that can process them. If no application can be found the command line options window is displayed. <br> Example: <br> BridgeLink.exe /Configuration=WSDOT:WSDOT <br> Finds the first BridgeLink Application that knows how to process the /Configuration option.
/App=\<appname\> \<app options\> \<_filename_\> | BridgeLink Applications are not guaranteed to have unique command line options.  Use this instead of \<app options\> alone to pass application specific command line options to a specific BridgeLink Application. Identify the specific BridgeLink Application with /App=<appname\>. <br> Example: <br> BridgeLink.exe /App=PGSuper /Configuration=WSDOT:WSDOT <br> Passes the /Configuration option to the PGSuper Application

> NOTE: Command line options for specific BridgeLink Applications are found in the documentation for those applications.

