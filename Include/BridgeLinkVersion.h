///////////////////////////////////////////////////////////////////////
// BridgeLink - BridgeLink Extensible Application Framework
// Copyright © 1999-2025  Washington State Department of Transportation
//                        Bridge and Structures Office
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the Alternate Route Open Source License as 
// published by the Washington State Department of Transportation, 
// Bridge and Structures Office.
//
// This program is distributed in the hope that it will be useful, but 
// distribution is AS IS, WITHOUT ANY WARRANTY; without even the implied 
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See 
// the Alternate Route Open Source License for more details.
//
// You should have received a copy of the Alternate Route Open Source 
// License along with this program; if not, write to the Washington 
// State Department of Transportation, Bridge and Structures Office, 
// P.O. Box  47340, Olympia, WA 98503, USA or e-mail 
// Bridge_Support@wsdot.wa.gov
///////////////////////////////////////////////////////////////////////

#pragma once

// Version Number Scheme... major.minor.fix.build
// major = major version number (increment for major, significant new features, releases) 
// minor = minor version number (increment for minor, bug fix releases)
// fix = increment for hot fixes (don't increment major.minor for hot fixes)
// build = the build or release candidate number
//
// hot fixes - sometimes there are bugs that need to be fixed and deployed now. That is a hot fix.

#define _BETA_VERSION          // When defined, building beta versions

// includes WBFL Version macro and
// macros that define the minimum version of Windows and IE
#include <WBFLVersion.h>

#ifndef _BRIDGELINK_VERSION
#define _BRIDGELINK_VERSION _WBFL_VERSION
#endif

