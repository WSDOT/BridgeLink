Release Procedures
==================
This whitepaper documents the procedures for releasing the BridgeLink application suite.

**Building source for release**

Before BridgeLink can be released, the source files must be updated with version information and built.

***Unit and Regression Tests***

Before publishing a release, run the WBFL unit tests and the regression tests for all of the BridgeLink applications. Verify all tests pass and all issues are resolved.

***Update Copyright Notice***

Once a year, the copyright notice must be updated to the current year. Every source file contains the copyright notice and must be updated. Additionally, the DLL and EXE resources must have their copyright data updated as well (`LegalCopyright` in each `res\<name>.rc2` file, and copyright text in About dialogs). The easiest way to update the copyright date is to search and replace "Copyright © 1999-2026" with the correct ending year (of course, the ending year range will change so you actually need to search for the year range 1999-yyyy). Do this in both the WBFL and BridgeLinkComplete solutions. Don't change the files in `WBFL\Depreciated`, third-party code, or the license texts.

Keep each file's encoding when replacing. Most source files, and all `.rc` and `.rc2` files, are ANSI (code page 1252), where © is the byte A9; an editor that saves such a file as UTF-8 turns © into the replacement character, which then shows up as `ï¿½` (in 2026, about 270 files had it, including several version resources).

Commit the copyright update to GIT.

***Version Numbers***

Before releasing, the version number must be incremented (see `Version Numbers.md` for the x.y.z.b scheme). It is set in one place, `\ARP\WBFL\Include\WBFLVersion.h`. Change the four numbers and the string together:

    #define WBFL_VERSION_MAJOR   10
    #define WBFL_VERSION_MINOR   0
    #define WBFL_VERSION_HOTFIX  0
    #define WBFL_VERSION_BUILD   1
    #define WBFL_VERSION_STRING  "10.0.0.1"

The compile stops (a `static_assert` in the header) when the string doesn't match the numbers. As an example, when releasing the third beta of version 7.1.0, change `WBFL_VERSION_BUILD` to 3 and `WBFL_VERSION_STRING` to "7.1.0.3". Nothing else needs to be changed; everything gets the version from this header:

* **C++ code:** `_WBFL_VERSION` (major.minor.hotfix as one number, e.g. 1000 for 10.0.0) is computed from the numbers.
* **Version resources:** each project's `VS_VERSION_INFO` is in its `res\<name>.rc2` file and uses the macros (`FILEVERSION WBFL_VERSION_MAJOR,...` and `VALUE "FileVersion", WBFL_VERSION_STRING`). The resource editor doesn't open `.rc2` files, so it can't replace the macros with numbers. Edit a version resource in its `.rc2` file, in a text editor. A new project gets its version resource the same way (see `WBFL\FEA2D\FEA2D.rc` for a project with only a version resource).
* **Scripts:** `BuildRelease.bat`, `PublishDocumentation.bat`, `Tag.bat`, `PGSuper\Configurations\PublishConfigurations.bat`, and each documentation set's `BuildDocumentation.bat` call `\ARP\BridgeLink\GetVersion.bat`, which reads `WBFL_VERSION_STRING` and sets `ARP_VERSION` (x.y.z.b), `ARP_RELEASE_VERSION` (x.y.z), and `ARP_DOCUMENTATION_VERSION` (x.y).
* **Installer:** `Installer\BridgeLinkInstaller.wixproj` imports `Installer\Version.props`, which reads the header and `_BETA_VERSION` (see Beta/Production Releases) and defines the versions for the package name, the MSI product version (x.y.z), the release file tree folders (x.y.z.b), and the documentation folders (x.y). The installer's fragment scripts (`Installer\Scripts\Build*Fragments.js`) read the header too. Other installers built on BridgeLink can import `Version.props` the same way (its header lists what it defines).
* **Documentation:** each Doxygen configuration has `PROJECT_NUMBER = $(ARP_DOCUMENTATION_VERSION)` (Doxygen reads it from the environment, which `BuildDocumentation.bat` sets), and the links in `Documentation\src\index.md` to the other documentation sets have the placeholder `$(ARP_DOCUMENTATION_VERSION)`, which `Documentation\VersionFilter.ps1` replaces (a Doxygen input filter). Run `BuildDocumentation.bat` to build a documentation set; Doxygen run on its own leaves the version out.

`BuildRelease.bat` lists the binaries in the release file tree that don't have the version in `WBFLVersion.h` (`\ARP\BridgeLink\CheckVersions.ps1`; the tree can also hold old files that no installer uses), and the installer build does the same for the package it built (warnings in the build output). A binary that keeps its own version on purpose is listed in the script's `-Exclude` parameter (`Convert.dll`).

****Versioning the Installer Package****

The installer package name comes from `WBFLVersion.h` and `_BETA_VERSION` in `BridgeLinkVersion.h` (see Beta/Production Releases): `BridgeLink_x.y.z_Beta_b_<platform>_<configuration>.msi` for beta releases and `BridgeLink_x.y.z_<platform>_<configuration>.msi` for official releases. Nothing needs to be changed in the installer project.

Don't change the output name on the project's Installer property page: Visual Studio saves `$(...)` typed there as `%24%28...%29`, and the packages are then named `BridgeLink_..._$(Platform)_$(Configuration).msi`.

****Documentation versioning****

The documentation version numbers use only the major and minor version numbers (x.y): the documentation for version 10.0.0 is the same as for 10.0.1, so it only changes with the major or minor version number. The documentation sets are built into `\ARP\BridgeLink\Docs\<set>\<x.y>`, the installer's fragment scripts install them from there, and `PublishDocumentation.bat` publishes them to the WSDOT server. All of it follows `WBFLVersion.h`; nothing needs to be changed by hand.

***Beta/Production Releases***

If this is a production (final) release, comment out the `_BETA_VERSION` macro in `BridgeLinkVersion.h`.

This macro causes certain debugging features to be compiled into Beta releases. We do not want these features in the final production release of the software. It also names the installer package (`_Beta_b` in the name for a beta release).

***Compile***

Once the version numbers are updated, do a complete build of the WBFL and BridgeLinkComplete solutions (Release, x64).

**Preparing the installer build environment**

Before the installer can be built, the build environment must be prepared. This is made easy through script files. `BuildRelease.bat` builds and publishes the complete BridgeLink end user documentation set (`PublishDocumentation.bat`), copies all the files for the release into predefined locations for the BridgeLinkInstaller project (each repository's `UpdateBinFiles.bat` stages its files in its `bin` folder, and `BuildRelease.bat` copies them to `\ARP_RELEASE\<application>\<x.y.z.b>\bin`), and checks the version numbers of the binaries there. The batch script does not publish PGSuper or PGSplice configurations (`PGSuper\Configurations\PublishConfigurations.bat`).

* Using a command prompt or PowerShell (as administrator), navigate to `\ARP\BridgeLink` and run `BuildRelease.bat`

The documentation is built from scratch each time, and only the files whose content changed are copied: `\ARP\BridgeLink\Docs` is updated with `\ARP\BridgeLink\SyncFolder.ps1`, and the WSDOT server is made the same as `\ARP\BridgeLink\Docs` with `robocopy /MIR` (it copies new and changed files and deletes the files the local copy doesn't have). Run `PublishDocumentation.bat /b` to build the documentation without publishing it.

When a release adds a run-time file (a DLL, a manifest, a data file), add it to the repository's `UpdateBinFiles.bat` and to the installer's `.wxs` file together. For example, the IFC import and export (the optional Experimental Features, `Installer\ExperimentalExtensions.wxs`) needs IfcOpenShell, PROJ and its EPSG database (`proj\proj.db`), and the mapping tables, staged by `PGSuperIfcExtensions\UpdateBinFiles.bat`.

**Building the installer (MSI) package**

After the installer build environment is prepared, the BridgeLinkInstaller solution is used to build the MSI installer packages. This solution creates installer packages for WSDOT and TxDOT. The TxDOT package differs from the WSDOT package in that it has defaults set for the TxDOT engineering environment.

In Visual Studio, select Build > Batch Build, select the Release and TxDOT x64 Solution Configurations and build. The resulting MSI files are located in:

* WSDOT - `\ARP\BridgeLink\installer\bin\x64\Release`
* TxDOT - `\ARP\BridgeLink\installer\bin\x64\TxDOT`

The build output lists, as warnings, the binaries in the package that don't have the version in `WBFLVersion.h` (see Version Numbers).

The Visual C++ run time is installed with merge modules (`Installer\MergeModules.wxs`). They must match the platform toolset the binaries are built with (v145, Visual Studio 2026); the file names the folder they're in, which depends on the Visual Studio edition (Professional, Community, Enterprise), so change it there for another edition.

If the resulting MSI files contain `$(Platform)` and `$(Configuration)` in the filename, the output name was changed on the Installer property page (see "Versioning the Installer Package"). Open the .wixproj file in a text editor and restore the line

    <OutputName>BridgeLink_$(ArpPackageVersion)_$(Platform)_$(Configuration)</OutputName>

**Retain official copy of the installer**

Copy the resulting installer packages to `\ARP_INSTALLERS`.

**Test the installer**

Test the installer packages before deploying them. A good way to test them is to start Windows Sandbox (a virtual machine) and install the software and try it out.

**Tag and commit**

The various repositories need to be tagged at the point of release. `Tag.bat` commits, tags (`version_x.y.z.b`, from `WBFLVersion.h`), and pushes every repository; it needs no changes.

Run the `Tag.bat` file to tag and commit the release.

**Release Notes**

Update the release notes in `\ARP_INSTALLER\Release Notes`. Wherever possible append the Mantis issue number to the note with "(Mnnnn)" where nnnn is the issue number.

**Deploying the WSDOT installer**

BridgeLink must be deployed to WSDOT engineers (internal) and to the public via the WSDOT web site (external).

***Internal deployment***

Copy the installer package to `J:\installs\BridgeLink`. Rename the installer package to BridgeLink_x.y.z.msi. Submit a help desk ticket and request office-wide deployment.

***External deployment***

Copy the WSDOT installer package to `\\wsdot\Resources\Topics\Publish\Web\ProdCF\EESC\Bridge\software\Downloads\BridgeLink_x.y` (where x.y is the version number). Rename the installer package to BridgeLink_x.y.z.msi.

Using the Admin interface of the Bridge Office Software Download site, add the new release, change the previous release to archival status, and update the release history with the release notes.
