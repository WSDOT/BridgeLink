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

#include <guiddef.h>

// CATID for plug-ins that extend BridgeLink itself
// {885F1426-44D9-4df3-A53D-CCF557DD2227}
DEFINE_GUID(CATID_BridgeLinkPlugin, 
0x885f1426, 0x44d9, 0x4df3, 0xa5, 0x3d, 0xcc, 0xf5, 0x57, 0xdd, 0x22, 0x27);

// CATID for plug-ins that provide BridgeLink applications
// {1D069A0E-7436-4275-A129-C84ADC22DE68}
DEFINE_GUID(CATID_BridgeLinkAppPlugin, 
0x1d069a0e, 0x7436, 0x4275, 0xa1, 0x29, 0xc8, 0x4a, 0xdc, 0x22, 0xde, 0x68);

// {AF28A0E7-E9AD-4839-9901-5F004209498B}
DEFINE_GUID(CATID_BridgeLinkComponentInfo, 
0xaf28a0e7, 0xe9ad, 0x4839, 0x99, 0x1, 0x5f, 0x0, 0x42, 0x9, 0x49, 0x8b);
