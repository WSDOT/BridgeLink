///////////////////////////////////////////////////////////////////////
// BridgeLink - BridgeLink Extensible Application Framework
// Copyright © 1999-2018  Washington State Department of Transportation
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

// StartPageWndProvider.h
//

#pragma once

#include <EAF\EAFStartPageWnd.h>

// {271E5B9C-A3C9-486f-9E89-FD0EBD2B6E58}
DEFINE_GUID(IID_IStartPageWndProvider, 
0x271e5b9c, 0xa3c9, 0x486f, 0x9e, 0x89, 0xfd, 0xe, 0xbd, 0x2b, 0x6e, 0x58);
struct __declspec(uuid("271E5B9C-A3C9-486f-9E89-FD0EBD2B6E58")) IStartPageWndProvider;
interface IStartPageWndProvider : public IUnknown
{
   virtual CEAFStartPageWnd* CreateStartPage() = 0;
};
