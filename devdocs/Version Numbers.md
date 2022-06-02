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