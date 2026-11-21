Version Numbers
===============

The BridgeLink suite uses a simple and common scheme for managing version numbers.

Versions numbers are major.minor.hotfix.build (x.y.z.b) format where:
* major: incremented for releases that contain significant new features and capabilities.
* minor: incremented for releases that contain changes to the existing features of the software that results in files that are not compatible with previous releases.
* hotfix: incremented when a bug fix release is made. Files must be compatibible with previous releases.
* build: incremented for each final build of the same version. Typically incremented only for beta releases.

Examples:

* 7.0.0.4 - 4th release of version 7.0. This could be either the production version of 7.0 or the 4th beta release. 
* 7.1.0.0 - 1st release of version 7.1
* 7.1.2.1 - 2nd hot fix release to version 7.1. The hot fix had one beta release (7.1.2.0) for customer testing prior to the production release (7.1.2.1).

Where the version number is set
-------------------------------

The version number is set in one place: `WBFL_VERSION_MAJOR`, `WBFL_VERSION_MINOR`, `WBFL_VERSION_HOTFIX`, `WBFL_VERSION_BUILD`, and `WBFL_VERSION_STRING` in `\ARP\WBFL\Include\WBFLVersion.h`. The compile stops when the string and the numbers don't match. Everything else gets the version from there: the C++ code (`_WBFL_VERSION`), the version resources of every DLL and EXE (in each project's `res\<name>.rc2`), the release and documentation scripts (through `\ARP\BridgeLink\GetVersion.bat`), the documentation, and the installers (through `\ARP\BridgeLink\Installer\Version.props`). See `Release Procedures.md`.

The forms used are derived from it: x.y.z.b (e.g. 10.0.0.1) for the binaries, the release file tree, and the tags (`version_x.y.z.b`); x.y.z (10.0.0) for the MSI product version and the configuration folders; x.y (10.0) for the documentation.

Every release has all four numbers, beta or official. Whether a release is a beta release is set separately, by `_BETA_VERSION` in `\ARP\BridgeLink\Include\BridgeLinkVersion.h` (comment it out for an official release): it turns on debugging features and names the installer package (`BridgeLink_x.y.z_Beta_b_...` for a beta release, `BridgeLink_x.y.z_...` for an official release).
