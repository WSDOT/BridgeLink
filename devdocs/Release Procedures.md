Release Procedures
==================
This whitepaper documents the procedures for releasing the BridgeLink application suite.

**Building source for release**

Before BridgeLink can be released, the source files must be updated with version information and built.

***Unit and Regression Tests***

Before publishing a release, run the WBFL unit tests and the regression tests for all of the BridgeLink applications. Verify all tests pass and all issues are resolved.

***Update Copyright Notice***

Once a year, the copyright notice must be updated to the current year. Every source file contains the copyright notice and must be updated. Additionally, the DLL and EXE resources must have their copyright data updated as well. The easiest way to update the copyright date is to search and replace "Copyright © 1999-2021" with the correct ending year (of course, the ending year range will change so you actually need to search for the year range 1999-yyyy). Do this in both the WBFL and BridgeLinkComplete solutions.

Commit the copyright update to GIT.

***Version Numbers***

Before releasing, the version number must be incremented. The easiest way to do this is search and replace the version number. The version number is represented in two forms in the RC files. The forms are x.y.z.b and x,y,z,b and both forms must be replaced. Do this search and replace in the WBFL, BridgeLinkComplete, and BridgeLinkInstaller (located in \ARP\BridgeLink\Installers) solutions.

As an example, when release the third beta of version 7.1.0 do a search and replace of 7.1.0.2 with 7.1.0.3 and 7,1,0,2 with 7,1,0,3.

****Versioning the Installer Package****

In the BridgeLinkInstaller solution, update the version number incorporated into the installer package name.

* Right click on the BridgeLinkInstaller project and select Properties
* Click the Installer option
* Update the output name with the version number

****Documentation versioning****

The documentation sets contains version numbers and links to versioned sub-documents. The version number is defined in all of the doxygen files. The documentation version numbers use only the major and minor version numbers, so updating the version number only needs to occur for the first release (beta or otherwise) after incrementing the major or minor version number.

Also, `\ARP\BridgeLink\Documentation\src\index.md` contains links to the various BridgeLink applications. The version number is encoded into these links. In addition to updating version numbers in the doxygen files, update the version number in this file.

****Update built scripts****

There are several script files (bat files) used to prepare the installer build environment. The version number must be updated in these files as well. Update the version number in the following files:

* BuildRelease.bat
* PublishDocumentation.bat
* PublishConfigurations.bat
* Tag.bat

Updating the version number in Tag.bat is a little cumbersome. Review the comments at the top of the file for additional information.

****Additional versioning steps for official releases****

When making an official release (not a beta release), the version constant must be updated as well. Since the version number is syncronized acrossed all BridgeLink applications and components, this only needs to be changed in one place. Update the `_WBFL_VERSION` macro in the `WBFLVersion.h` file found in the WBFLTypes project. The macro is the primary version number without the digit seperator (.).

`#define _WBFL_VERSION 710 // version 7.1.0`

***Beta/Production Releases***

If this is a production (final) release, comment out the `_BETA_VERSION` macro in `BridgeLinkVersion.h`.

This macro causes certain debugging features to be compiled into Beta releases. We do not want these features in the final production release of the software.

***Compile***

Once the version numbers are update, do a complete build of the WBFL and BridgeLinkComplete solutions.

Commit to GIT with a commit message stating "Updated version numbers for 7.1 Beta 3", or something similar. Of course, you'll substitute the actual version number in the commit message.

**Preparing the installer build environment**

Before the installer can be built, the build envinroment must be prepared. This is made easy through script files. The BuildRelease.bat file copies all the files for the release into predefined locations for the BridgeLinkInstaller project. This batch script also builds and publishes the complete BridgeLink end user documentation set. The batch script does not published PGSuper or PGSplice configurations.

* Using a command prompt or PowerShell (as adminstrator), nagivate to `\ARP\BridgeLink` and run `BuildRelease.bat`

**Building the installer (MSI) package**

After the installer build environment is prepared, the BridgeLinkInstaller solution is used to build the MSI installer packages. This solution creates installer packages for WSDOT and TxDOT. The TxDOT package differs from the WSDOT package in that it has defaults set for the TxDOT engineering environment.

In Visual Studio, select Build > Batch Build, select the Release and TxDOT x64 Solution Configurations and build. The resulting MSI files are located in:

* WSDOT - `\ARP\BridgeLink\installer\bin\x64\Release`
* TxDOT - `\ARP\BridgeLink\installer\bin\x64\TxDOT`

Occasionally, the Visual Studio macros well get messed up in the BridgeLinkInstaller.wixproj project file. If the resulting MSI files contain $(Project) and $(Configuration) in the filename, open the .wixproj file in a text editor, find the following line

    <OutputName>BridgeLink_7.0.0_Beta_5_%24%28Platform%29_%24%28Configuration%29</OutputName>

and replace %24%28 with $( and replace %29 with )

    <OutputName>BridgeLink_7.0.0_Beta_5_$(Platform)_$(Configuration)</OutputName>

**Retain official copy of the installer**

Copy the resulting installer packages to `\ARP_INSTALLERS`.

**Test the installer**

Test the installer packages before deploying them. A good way to test them is to start Windows Sandbox (a virtual machine) and install the software and try it out.

**Tag and commit**

The various repositories need to be tagged at the point of release. Edit the `Tag.bat` file and change the tag and commit message as described in the file header.

Run the `Tag.bat` file to tag and commit the release.

**Release Notes**

Update the release notes in `\ARP_INSTALLER\Release Notes`. Whereever possible append the Mantis issue number to the note with "(Mnnnn)" where nnnn is the issue number.

**Deploying the WSDOT installer**

BridgeLink must be deployed to WSDOT engineers (internal) and to the public via the WSDOT web site (external).

***Internal deployment***

Copy the installer package to `J:\installs\BridgeLink`. Rename the installer package to BridgeLink_x.y.z.msi. Submit a help desk ticket and request office-wide deployment.

***External deployment***

Copy the installer package to `\\wsdot\Resources\Topics\Publish\Web\ProdCF\EESC\Bridge\software\Downloads\BridgeLink_x.y` (where x.y is the version number). Rename the installer package to BridgeLink_x.y.z.msi.

Using the Admin interface of the Bridge Office Software Download site, add the new release, change the previous release to archival status, and update the release history with the release notes.