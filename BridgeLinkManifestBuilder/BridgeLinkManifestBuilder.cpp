///////////////////////////////////////////////////////////////////////
// BridgeLinkManifestBuilder
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

/// @brief This application creates manifest files for BridgeLink and
/// all of its Plug-in Applications, Extensions, etc. Manifests are
/// created for everything that is part of the BridgeLink standard install.
/// 
/// Technically, the manifest files could be written by hand, but it is much
/// easier to do it programmatically. Hand-coding requires dealing with GUIDs
/// and json file format.

#include "afx.h"

#include <iostream>
#include <tchar.h>

#include <WBFLTypes.h>
#include <EAF/ComponentManager.h>

#include <initguid.h>
#include "../include/BridgeLinkCATID.h"

#include "../../Barlist/ExcelExporter/CLSID.h"
#include "../../Barlist/BXF/CLSID.h"
#include "../../Barlist/SDK/Include/BarlistPlugin.h"
#include "../../Barlist/Include/BarlistCATID.h"


#include "../../PGSuper/psgLib/CLSID.h"
#include "../../Barlist/Barlist/CLSID.h"
#include "../../XBeamRate/CLSID.h"
#include "../../PGSuper/TxDOTAgent/CLSID.h"
#include "../../BEToolbox/BEToolboxCLSID.h"

#include "../BridgeLinkTestPlugin/CLSID.h"

//#include "../../BEToolboxExtensions/CLSID.h"
#include "../../BEToolbox/BEToolboxToolExample/CLSID.h"

#include "../../PGSuper/Include/Plugins/PGSuperIEPlugin.h"

#include "../../PGSuper/WSDOTAgent\CLSID.h"
#include "../../PGSuper/PGSuperAppPlugin\CLSID.h"
#include "../../PGSuper/Include\PGSuperCatCom.h"
#include "../../PGSuper/Include\PGSpliceCatCom.h"
#include "../../PGSuper/Include\Plugins\BeamFamilyCLSID.h"
#include "../../PGSuper/ExtensionAgentExample\CLSID.h"
#include "../../PGSuper/AnalysisAgent\CLSID.h"
#include "../../PGSuper/BridgeAgent\CLSID.h"
#include "../../PGSuper/EngAgent\CLSID.h"
#include "../../PGSuper/ProjectAgent\CLSID.h"
#include "../../PGSuper/SpecAgent\CLSID.h"
#include "../../PGSuper/GraphingAgent\CLSID.h"
#include "../../PGSuper/ReportAgent\CLSID.h"
#include "../../PGSuper/TestAgent\CLSID.h"
#include "../../PGSuper/Include/Plugins/BeamFactoryCATID.h"
#include "../../PGSuper/Include/Plugins/Beams.h"

#include "../../PGSuper/KDOTExport/KDOTExport.h"

#include "../../PGSuper/LibraryMgrPluginExample/CLSID.h"
#include "../../PGSuper/Include/PGSuperLibraryMgrCATID.h"
#include "../../PGSuper/IEPluginExample/IEPluginExample.h"

//#include "../../PGSuperIfcExtensions/IfcExtensions.h"
//#include "../../PGSuperScriptingExtension/CLSID.h"


#include "../../XBeamRate/Include/XBeamRateCatCom.h"
#include "../../XBeamRate/AnalysisAgent/AnalysisAgentCLSID.h"
#include "../../XBeamRate/EngAgent/EngAgentCLSID.h"
#include "../../XBeamRate/GraphingAgent/GraphingAgentCLSID.h"
#include "../../XBeamRate/PierAgent/PierAgentCLSID.h"
#include "../../XBeamRate/ProjectAgent/ProjectAgentCLSID.h"
#include "../../XBeamRate/ReportAgent/ReportAgentCLSID.h"
#include "../../XBeamRate/TestAgent/TestAgentCLSID.h"

#include "../../PGSuper/TxDOTAgent/TogaCatCom.h"

// This program creates a series of manifest files for BridgeLink and its applications (BEToolbox, PGSuper, XBRate, etc)

void BridgeLinkApplications()
{
   // Creates manifest for the main BridgeLink application.
   auto& cm = WBFL::EAF::ComponentManager::GetInstance();
   cm.Reset();

   // BridgeLink Plugin Applications
   cm.RegisterComponent(_T("PGSLibrary Editor"), CLSID_LibraryAppPlugin, _T("PGSuperLibrary.dll"), CATID_BridgeLinkAppPlugin);
   cm.RegisterComponent(_T("Barlist"), CLSID_BarlistPluginApp, _T("Barlist.dll"), { CATID_BridgeLinkAppPlugin, CATID_BarlistAppPlugin });
   cm.RegisterComponent(_T("TxDOT Optional Girder Analysis (TOGA)"), CLSID_TOGAPluginApp, _T("TxDOTAgent.dll"), CATID_BridgeLinkAppPlugin);
   cm.RegisterComponent(_T("BEToolbox"), CLSID_BEToolboxPluginApp, _T("BEToolbox.dll"), CATID_BridgeLinkAppPlugin);
   cm.RegisterComponent(_T("PGSuper"), CLSID_PGSuperPluginApp, _T("PGSuper.dll"), CATID_BridgeLinkAppPlugin);
   cm.RegisterComponent(_T("PGSplice"), CLSID_PGSplicePluginApp, _T("PGSuper.dll"), CATID_BridgeLinkAppPlugin);
   cm.RegisterComponent(_T("PGSuper Project Importer"), CLSID_PGSuperProjectImporterPluginApp, _T("PGSuper.dll"), CATID_BridgeLinkAppPlugin);
   cm.RegisterComponent(_T("PGSplice Project Importer"), CLSID_PGSpliceProjectImporterPluginApp, _T("PGSuper.dll"), CATID_BridgeLinkAppPlugin);
   cm.RegisterComponent(_T("XBeam Rate"), CLSID_XBeamRatePluginApp, _T("XBeamRate.dll"), CATID_BridgeLinkAppPlugin);

   // BridgeLink Plugin Application Component Information Objects
   cm.RegisterComponent(_T("BridgeLink Example Component Information"), CLSID_BridgeLinkExampleComponentInfo, _T("BridgeLinkTestPlugin.dll"), CATID_BridgeLinkComponentInfo);
   cm.RegisterComponent(_T("Barlist Component Information"), CLSID_BarlistComponentInfo, _T("Barlist.dll"), { CATID_BridgeLinkComponentInfo,CATID_BarlistComponentInfo });
   cm.RegisterComponent(_T("TOGA Component Information"), CLSID_TOGAPluginAppComponentInfo, _T("TxDOTAgent.dll"), CATID_BridgeLinkComponentInfo);
   cm.RegisterComponent(_T("BEToolbox Component Information"), CLSID_BEToolboxComponentInfo, _T("BEToolbox.dll"), CATID_BridgeLinkComponentInfo);
   cm.RegisterComponent(_T("XBeam Rate Component Information"), CLSID_XBeamRateComponentInfo,  _T("XBeamRate.dll"), CATID_BridgeLinkComponentInfo);
   cm.RegisterComponent(_T("PGSuper Component Information"), CLSID_PGSuperComponentInfo, _T("PGSuper.dll"), CATID_BridgeLinkComponentInfo);
   cm.RegisterComponent(_T("PGSplice Component Information"), CLSID_PGSpliceComponentInfo, _T("PGSuper.dll"), CATID_BridgeLinkComponentInfo);

   cm.Save(_T("Application.Manifest.BridgeLink"));
}

void BridgeLinkApplicationPluginExample()
{
   // Creates teh manifiest for the BridgeLink Example Application Plugin
   // DO NOT DISTRIBUTE THIS MANIFEST
   auto& cm = WBFL::EAF::ComponentManager::GetInstance();
   cm.Reset();
   cm.RegisterComponent(_T("BridgeLink Plugin Example"), CLSID_BridgeLinkExamplePluginApp, _T("BridgeLinkTestPlugin.dll"), CATID_BridgeLinkAppPlugin);
   cm.Save(_T("PluginExample.Manifest.BridgeLink"));
}

void Barlist()
{
   // Creates the manifest for the Barlist application. The plugins are key parts of the application
   WBFL::EAF::ComponentManager::GetInstance().Reset();
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("BXF Exporter"), CLSID_BXFAddin, _T("BXF.dll"), CATID_BarlistPlugin);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Excel Exporter"), CLSID_ExcelExporterAddin, _T("BarlistExcelExporter.dll"), CATID_BarlistPlugin);
   WBFL::EAF::ComponentManager::GetInstance().Save(_T("Application.Manifest.Barlist"));
}

void BEToolboxTools()
{
   // Creates the mainfiest for BEToolbox's tools
   WBFL::EAF::ComponentManager::GetInstance().Reset();
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("BoxGdr Tool"), CLSID_BoxGdrTool, _T("BEToolbox.dll"), CATID_BEToolboxTool);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("GenComp Tool"), CLSID_GenCompTool, _T("BEToolbox.dll"), CATID_BEToolboxTool);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("GirComp Tool"), CLSID_GirCompTool, _T("BEToolbox.dll"), CATID_BEToolboxTool);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("UltCol Tool"), CLSID_UltColTool, _T("BEToolbox.dll"), CATID_BEToolboxTool);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Curvel Tool"), CLSID_CurvelTool, _T("BEToolbox.dll"), CATID_BEToolboxTool);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("PGStable Tool"), CLSID_PGStableTool, _T("BEToolbox.dll"), CATID_BEToolboxTool);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Spectra Tool"), CLSID_SpectraTool, _T("BEToolbox.dll"), CATID_BEToolboxTool);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Bearing Tool"), CLSID_BearingTool, _T("BEToolbox.dll"), CATID_BEToolboxTool);
   WBFL::EAF::ComponentManager::GetInstance().Save(_T("Application.Manifest.BEToolbox"));
}

void BEToolboxExampleTool()
{
   // Creates the manifest for the BEToolbox Example Tool
   // DO NOT DISTRIBUTE THIS MANIFEST
   WBFL::EAF::ComponentManager::GetInstance().Reset();
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Example Tool"), CLSID_ExampleTool, _T("BEToolboxToolExample.dll"), CATID_BEToolboxTool);
   WBFL::EAF::ComponentManager::GetInstance().Save(_T("ExampleTool.Manifest.BEToolbox"));
}

void BEToolboxExperimentalTools()
{
   // Creates the manifest for BEToolbox experimental tools
   // DO NOT DISTRIBUTE THIS MANIFEST
   //WBFL::EAF::ComponentManager::GetInstance().Reset();
   //WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("RCCapacity Tool"), CLSID_RCCapacityTool, _T("BEToolboxToolExtensions.dll"), CATID_BEToolboxTool);
   //WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("SVT Tool"), CLSID_SVTTool, _T("BEToolboxToolExtensions.dll"), CATID_BEToolboxTool);
   //WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("M3C Tool"), CLSID_M3CTool, _T("BEToolboxToolExtensions.dll"), CATID_BEToolboxTool);
   //WBFL::EAF::ComponentManager::GetInstance().Save(_T("Experimental.Manifest.BEToolbox"));
}

void BEToolboxPGSImportersExporters()
{
   // Creates the manifest for PGSuper/PGSplice importers/exporters implemented by BEToolbox tools
   WBFL::EAF::ComponentManager::GetInstance().Reset();
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Curvel Exporter"), CLSID_CurvelExporter, _T("BEToolbox.dll"), { CATID_PGSuperDataExporter,CATID_PGSpliceDataExporter });
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Curvel Importer"), CLSID_CurvelImporter, _T("BEToolbox.dll"), { CATID_PGSuperDataImporter,CATID_PGSpliceDataImporter });
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("GenComp Exporter"), CLSID_GenCompExporter, _T("BEToolbox.dll"), { CATID_PGSuperDataExporter,CATID_PGSpliceDataExporter });
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("PGStable Exporter"), CLSID_PGStableExporter, _T("BEToolbox.dll"), { CATID_PGSuperDataExporter,CATID_PGSpliceDataExporter });
   WBFL::EAF::ComponentManager::GetInstance().Save(_T("BEToolboxExtensions.Manifest.PGSuper"));
}

void PGSuper()
{
   // Creates the manifest for PGSuper/PGSplice
   WBFL::EAF::ComponentManager::GetInstance().Reset();

   // PGSuper/PGSplice Agents
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Analysis Agent"), CLSID_AnalysisAgent, _T("PGSuperAnalysisAgent.dll"), { CATID_PGSuperAgent, CATID_PGSpliceAgent });
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Bridge Agent"), CLSID_BridgeAgent, _T("PGSuperBridgeAgent.dll"), { CATID_PGSuperAgent, CATID_PGSpliceAgent });
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Eng Agent"), CLSID_EngAgent, _T("PGSuperEngAgent.dll"), { CATID_PGSuperAgent, CATID_PGSpliceAgent });
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Graphing Agent"), CLSID_PGSuperGraphingAgent, _T("PGSuperGraphingAgent.dll"), { CATID_PGSuperAgent, CATID_PGSpliceAgent });
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Project Agent"), CLSID_ProjectAgent, _T("PGSuperProjectAgent.dll"), { CATID_PGSuperAgent, CATID_PGSpliceAgent });
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Report Agent"), CLSID_PGSuperReportAgent, _T("PGSuperReportAgent.dll"), { CATID_PGSuperAgent, CATID_PGSpliceAgent });
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Spec Agent"), CLSID_SpecAgent, _T("PGSuperSpecAgent.dll"), { CATID_PGSuperAgent, CATID_PGSpliceAgent });
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Test Agent"), CLSID_TestAgent, _T("PGSuperTestAgent.dll"), { CATID_PGSuperAgent, CATID_PGSpliceAgent });

   // PGSuper Beam Families
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("I-Beam"), CLSID_WFBeamFamily, _T("PGSuperBeams.dll"), CATID_PGSuperBeamFamily);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("U-Beam"), CLSID_UBeamFamily, _T("PGSuperBeams.dll"), CATID_PGSuperBeamFamily);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Box Beam"), CLSID_BoxBeamFamily, _T("PGSuperBeams.dll"), CATID_PGSuperBeamFamily);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Deck Bulb Tee"), CLSID_DeckBulbTeeBeamFamily, _T("PGSuperBeams.dll"), CATID_PGSuperBeamFamily);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Double Tee"), CLSID_DoubleTeeBeamFamily, _T("PGSuperBeams.dll"), CATID_PGSuperBeamFamily);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Ribbed Girder"), CLSID_RibbedBeamFamily, _T("PGSuperBeams.dll"), CATID_PGSuperBeamFamily);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Voided Slab"), CLSID_SlabBeamFamily, _T("PGSuperBeams.dll"), CATID_PGSuperBeamFamily);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Decked Slab Beam"), CLSID_DeckedSlabBeamFamily, _T("PGSuperBeams.dll"), CATID_PGSuperBeamFamily);

   // PGSuper Beam Factories
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Precast I-Beam"), CLSID_WFBeamFactory, _T("PGSuperBeams.dll"), CATID_WFBeamFactory);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Nebraska NU Girder"), CLSID_NUBeamFactory, _T("PGSuperBeams.dll"), CATID_WFBeamFactory);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Tapered I-Beam"), CLSID_TaperedIBeamFactory, _T("PGSuperBeams.dll"), CATID_WFBeamFactory);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Precast U-Beam (WSDOT)"), CLSID_UBeamFactory, _T("PGSuperBeams.dll"), CATID_UBeamFactory);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Precast U-Beam (TXDOT)"), CLSID_UBeam2Factory, _T("PGSuperBeams.dll"), CATID_UBeamFactory);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Deck Bulb Tee"), CLSID_BulbTeeFactory, _T("PGSuperBeams.dll"), CATID_DeckBulbTeeBeamFactory);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("NU Decked Bulb Tee Girder"), CLSID_NUDeckedBulbTeeFactory, _T("PGSuperBeams.dll"), CATID_DeckBulbTeeBeamFactory);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("PCI Decked Bulb Tee Girder"), CLSID_PCIDeckedBulbTeeFactory, _T("PGSuperBeams.dll"), CATID_DeckBulbTeeBeamFactory);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Double Tee"), CLSID_DoubleTeeFactory, _T("PGSuperBeams.dll"), CATID_DoubleTeeBeamFactory);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Double Tee (TxDOT)"), CLSID_TxDotDoubleTFactory, _T("PGSuperBeams.dll"), CATID_DoubleTeeBeamFactory);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Double Tee (WSDOT)"), CLSID_MultiWeb2Factory, _T("PGSuperBeams.dll"), CATID_DoubleTeeBeamFactory);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Ribbed Girder"), CLSID_MultiWebFactory, _T("PGSuperBeams.dll"), CATID_RibbedBeamFactory);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Voided Slab"), CLSID_VoidedSlabFactory, _T("PGSuperBeams.dll"), CATID_SlabBeamFactory);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Voided Slab (WSDOT)"), CLSID_VoidedSlab2Factory, _T("PGSuperBeams.dll"), CATID_SlabBeamFactory);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Box Beam"), CLSID_BoxBeamFactory, _T("PGSuperBeams.dll"), CATID_BoxBeamFactory);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Box Beam (TxDOT)"), CLSID_BoxBeam2Factory, _T("PGSuperBeams.dll"), CATID_BoxBeamFactory);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Decked Slab Beam"), CLSID_DeckedSlabBeamFactory, _T("PGSuperBeams.dll"), CATID_DeckedSlabBeamFactory);

   // PGSplice Beam Families
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Spliced I-Beam"), CLSID_SplicedIBeamFamily, _T("PGSuperBeams.dll"), CATID_PGSpliceBeamFamily);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Spliced U-Beam"), CLSID_SplicedUBeamFamily, _T("PGSuperBeams.dll"), CATID_PGSpliceBeamFamily);

   // PGSplice Beam Factories
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Spliced I-Beam"), CLSID_SplicedIBeamFactory, _T("PGSuperBeams.dll"), CATID_SplicedIBeamFactory);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Spliced NU-Beam"), CLSID_SplicedNUBeamFactory, _T("PGSuperBeams.dll"), CATID_SplicedIBeamFactory);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Spliced U-Beam"), CLSID_SplicedUBeamFactory, _T("PGSuperBeams.dll"), CATID_SplicedUBeamFactory);

   WBFL::EAF::ComponentManager::GetInstance().Save(_T("Application.Manifest.PGSuper"));
}

void WSDOT_PGSuper()
{
   // Creates the manifest for the WSDOT extension to PGSuper
   WBFL::EAF::ComponentManager::GetInstance().Reset();

   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("WSDOT Component Information"), CLSID_WSDOTPGSuperComponentInfo, _T("WSDOTAgent.dll"), CATID_PGSuperComponentInfo);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("WSDOT Component Information"), CLSID_WSDOTPGSpliceComponentInfo, _T("WSDOTAgent.dll"), CATID_PGSpliceComponentInfo);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("WSDOT Extension Agent"), CLSID_WSDOTAgent, _T("WSDOTAgent.dll"), { CATID_PGSuperExtensionAgent, CATID_PGSpliceExtensionAgent });

   WBFL::EAF::ComponentManager::GetInstance().Save(_T("WSDOT.Manifest.PGSuper"));
}

void TxDOT_PGSuper()
{
   // Creates the manifest for the TxDOT extension to PGSuper
   WBFL::EAF::ComponentManager::GetInstance().Reset();

   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("TxDOT Component Information"), CLSID_TxDOTPGSuperComponentInfo, _T("TxDOTAgent.dll"), CATID_PGSuperComponentInfo);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("TxDOT Extension Agent"), CLSID_TxDOTAgent, _T("TxDOTAgent.dll"), { CATID_PGSuperExtensionAgent, CATID_PGSpliceExtensionAgent });
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("TxDOT CAD Exporter"), CLSID_TxDOTCadExporter, _T("TxDOTAgent.dll"), CATID_PGSuperDataExporter);

   WBFL::EAF::ComponentManager::GetInstance().Save(_T("TxDOT.Manifest.PGSuper"));
}

void KDOT_PGSuper()
{
   // Creates the manifest for the KDOT extension to PGSuper
   WBFL::EAF::ComponentManager::GetInstance().Reset();

   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("KDOT Component Information"), CLSID_KDOTPGSuperComponentInfo, _T("KDOTExport.dll"), CATID_PGSuperComponentInfo);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("KDOT CAD Exporter"), CLSID_KDOTDataExporter, _T("KDOTExport.dll"), CATID_PGSuperDataExporter);

   WBFL::EAF::ComponentManager::GetInstance().Save(_T("KDOT.Manifest.PGSuper"));
}

void PGSuper_Experimental()
{
   //// Creates the manifest for experimental extensions to PGSuper/PGSplice
   //WBFL::EAF::ComponentManager::GetInstance().Reset();

   //WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("IFC Exporter"), CLSID_PGSuperIfcExporter, _T("PGSuperIfcExtensions.dll"), { CATID_PGSuperDataExporter, CATID_PGSpliceDataExporter });
   //WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("IFC Importer"), CLSID_PGSuperIfcImporter, _T("PGSuperIfcExtensions.dll"), { CATID_PGSuperDataImporter, CATID_PGSpliceDataImporter });

   //WBFL::EAF::ComponentManager::GetInstance().Save(_T("Experimental.Manifest.PGSuper"));

   //WBFL::EAF::ComponentManager::GetInstance().Reset();

   //WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("IFC Exporter"), CLSID_PGSuperScriptingAgent, _T("PGSuperScriptingExtension.dll"), CATID_PGSuperExtensionAgent);

   //WBFL::EAF::ComponentManager::GetInstance().Save(_T("Scripting.Manifest.PGSuper"));
}

void PGSuper_Examples()
{
   // Creates the manifest for example plug-ins and extensions for PGSuper/PGSplice
   // DO NOT DISTRIBUTE THIS MANIFEST
   WBFL::EAF::ComponentManager::GetInstance().Reset();

   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Example Extension Agent"), CLSID_ExampleExtensionAgent, _T("ExtensionAgentExample.dll"), { CATID_PGSuperExtensionAgent, CATID_PGSpliceExtensionAgent });
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Library Manager Plugin Example"), CLSID_LibMgrDocPlugin, _T("LibraryMgrPluginExample.dll"), CATID_PGSuperLibraryManagerPlugin);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("PGSuper Example Data Importer"), CLSID_PGSuperDataImporter, _T("IEPluginExample.dll"), CATID_PGSuperDataImporter);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("PGSuper Example Data Exporter"), CLSID_PGSuperDataExporter, _T("IEPluginExample.dll"), CATID_PGSuperDataExporter);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Example PGSuper Project Importer"), CLSID_PGSuperProjectImporter, _T("IEPluginExample.dll"), CATID_PGSuperProjectImporter);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("Example PGSplice Project Importer"), CLSID_PGSpliceProjectImporter, _T("IEPluginExample.dll"), CATID_PGSpliceProjectImporter);

   WBFL::EAF::ComponentManager::GetInstance().Save(_T("Examples.Manifest.PGSuper"));
}

void XBeamRate_PGSuper()
{
   // Creates the manifest for XBeamRate extensions to PGSuper/PGSplice
   WBFL::EAF::ComponentManager::GetInstance().Reset();

   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("XBRate Extension Agent"), CLSID_XBeamRateAgent, _T("XBeamRate.dll"), { CATID_PGSuperExtensionAgent, CATID_PGSpliceExtensionAgent });
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("XBRate Component Information"), CLSID_XBRatePGSuperComponentInfo, _T("XBeamRate.dll"), CATID_PGSuperComponentInfo);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("XBRate Component Information"), CLSID_XBRatePGSpliceComponentInfo, _T("XBeamRate.dll"), CATID_PGSpliceComponentInfo);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("XBRate Pier Exporter"), CLSID_XBeamRateDataExporter, _T("XBeamRate.dll"), CATID_PGSuperDataExporter);

   WBFL::EAF::ComponentManager::GetInstance().Save(_T("XBeamRateExtensions.Manifest.PGSuper"));
}

void XBeamRate()
{
   // Creates the manifest for teh XBeamRate application
   WBFL::EAF::ComponentManager::GetInstance().Reset();

   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("XBR Analysis Agent"), CLSID_XBeamRateAnalysisAgent, _T("XBeamRateAnalysisAgent.dll"), CATID_XBeamRateAgent);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("XBR Eng Agent"), CLSID_XBeamRateEngAgent, _T("XBeamRateEngAgent.dll"), CATID_XBeamRateAgent);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("XBR Graph Agent"), CLSID_XBeamRateGraphingAgent, _T("XBeamRateGraphingAgent.dll"), CATID_XBeamRateAgent);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("XBR Pier Agent"), CLSID_XBeamRatePierAgent, _T("XBeamRatePierAgent.dll"), CATID_XBeamRateAgent);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("XBR Project Agent"), CLSID_XBeamRateProjectAgent, _T("XBeamRateProjectAgent.dll"), CATID_XBeamRateAgent);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("XBR Report Agent"), CLSID_XBeamRateReportAgent, _T("XBeamRateReportAgent.dll"), CATID_XBeamRateAgent);
   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("XBR Test Agent"), CLSID_XBeamRateTestAgent, _T("XBeamRateTestAgent.dll"), CATID_XBeamRateAgent);

   WBFL::EAF::ComponentManager::GetInstance().Save(_T("Application.Manifest.XBeamRate"));
}

void TOGA()
{
   // Creates the manifest for TOGA extensions
   // The TxDOT extension agent is a TOGA extension. Otherwise, TOGA uses the PGSuper manifest
   WBFL::EAF::ComponentManager::GetInstance().Reset();

   WBFL::EAF::ComponentManager::GetInstance().RegisterComponent(_T("TOGA TxDOT Extension Agent"), CLSID_TxDOTAgent, _T("TxDOTAgent.dll"), CATID_TogaExtensionAgent);

   WBFL::EAF::ComponentManager::GetInstance().Save(_T("Extensions.Manifest.TOGA"));
}

int main()
{
   BridgeLinkApplications();
   BridgeLinkApplicationPluginExample();

   Barlist();

   BEToolboxTools();
   BEToolboxExampleTool();
   BEToolboxExperimentalTools();
   BEToolboxPGSImportersExporters();

   PGSuper();
   WSDOT_PGSuper();
   TxDOT_PGSuper();
   KDOT_PGSuper();
   XBeamRate_PGSuper();
   PGSuper_Examples();
   PGSuper_Experimental();

   XBeamRate();

   TOGA();
}
