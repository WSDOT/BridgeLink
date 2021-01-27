Introduction {#mainpage}
=====================
BridgeLink is an open source bridge engineering application framework from the Washington State Department of Transportation (WSDOT). BridgeLink provides a single cohesive environment that links together bridge engineering software applications.

BridgeLink offers a wide variety of bridge engineering software applications including general engineering tools, conventional and spliced precast girder design, and cross beam load rating analysis.


BridgeLink Applications
=======================

BridgeLink Applications are software programs that extend the BridgeLink framework. See @ref more_about_bridgelink for additional information.

The distribution provided by WSDOT has several standard BridgeLink Applications. An overview of the standard applications is presented below.

## Standard BridgeLink Applications
The standard BridgeLink Applications provided by WSDOT are:
* [Barlist](../../Barlist/Barlist/6.1/index.html)
* [BEToolbox](../../BEToolbox/6.1/index.html)
* [PGSuper](../../PGSuper/6.1/index.html) with WSDOT, TxDOT, and [KDOT](../../KDOT/3.0/index.html) Extensions
* [PGSplice](../../PGSplice/6.1/index.html) with WSDOT Extensions
* [PGS Library Editor](../../PGSLibrary/6.1/index.html)
* [TOGA](../../TOGA/6.1/index.html)
* [XBRate](../../XBRate/6.1/index.html)

These applications are briefly described in the sections that follow. You can get detailed information about each application from its manual.

> Think of BridgeLink like you think of Microsoft Office. It is a suite of applications. Think of the various BridgeLink Applications like Microsoft Word, Excel, and PowerPoint. They are applications that belong to the suite.

## Barlist
The Barlist application computes reinforcing steel quantity estimates. Barlist features an Explorer-style interface for managing reinforcement groups and bar records, an interactive bend guide for selecting bend diagraphs, and support for third party add-in components.

## BEToolbox
The Bridge Engineers Toolbox (BEToolbox) application is a collection of useful bridge engineering utility programs. These programs have their origins in the earliest days of computer applications at the WSDOT Bridge Design Office. These applications have endured through decades of change in computing and bridge engineer technology because of their simplicity and usefulness. 

Tool    | Description
--------|---------------------
BoxGdr  | BoxGdr computes the geometric section properties of a box girder including cross sectional area, moment of inertia, and centroid. 
Curvel  | Curvel computes roadway elevations, grade, and crown slope with respect to a given vertical curve and superelevation transition. Alignment information can be transferred between Curvel, PGSuper and PGSplice.
GenComp | GenComp computes the geometric section properties of a generalized composite cross section. Girder cross sections can be exported from PGSuper and PGSplice and subsequently imported into GenComp for further analysis and verification.
GirComp | GirComp computes the geometric section properties of a built-up or rolled steel section with a composite concrete slab.
UltCol  | UltCol computes axial/bending interaction for a circular reinforced concrete column.

## PGSuper
PGSuper is a BridgeLink Application for design, analysis, and load rating of precast-prestressed girder bridges in accordance with AASHTO LRFD Bridge Design Specifications and AASHTO Manual for Bridge Evaluation. PGSuper can model a wide variety of bridge configurations including I-beams, U-beams (tub girders), voided slabs, box beams, double tees, and deck bulb tee for simple span and multi-span continuous structures.

Features | Description
--------|---------------------
Modeling | PGSuper can model a wide variety of bridge configurations. Modeling consists of both defining the roadway alignment and the bridge framing. The roadway alignment model includes horizontal curves with entry and exit spirals, symmetrical and unsymmetrical vertical curves, and superelevation transitions. Bridge modeling includes skewed piers, single and multi-span structures, non-parallel (splayed) girders, different number and type of girders in each span, and varying width bridge decks. 
Girder Types | PGSuper supports eleven parametric girder types including I-Beams, Bulb Tees, U-Beams, Voided Slabs, and Box Beams. Additional girder types can be included through third party extensions.
Stress Analysis | Stress analysis can be performed using gross or transformed section properties.
Prestress Losses | Prestress losses can be computed using the AASHTO LRFD simplified method, TxDOT simplified method, AASHTO LRFD refined method, or a general lump sum method. 
Design | Use the design tool to quickly design your precast girders. The designer will determine required release and final concrete strength, prestressing configuration, lifting configuration, hauling configuration, stirrup configuration, and required haunch depth. Up to three different design strategies can be used to optimize designs for your local fabricators.
Load Rating | Load and Resistance Factor Ratings (LRFR) are performed in accordance with the Section 6A for the AASHTO Manual for Bridge Evaluation. Level 1, 2, and 3 load ratings are performed. Load posting analysis is automatically performed as needed.
Lifting and Hauling Analysis | Girders can be analyzed and designed for stresses and stability during lifting and hauling.
User Interface | PGSuper offers a rich, bridge-centric, user interface that keeps your attention on designing bridges. Information is presented in customary engineering drawing formats include plan, section, and elevation views. Interact directly with a graphical representation of your bridge and its components instead of wading through obscure menu commands and hierarchical data structures.
Analysis Results | Analysis results are presented in graphical and textual format. Quickly understand the behavior of your bridge by reviewing moment, shear, and deflection diagrams. Limit state demands are plotted with allowable stresses and section resistance for easy verification of LRFD code requirements. Reports can contain as little or as much information as you like. Sometimes a summary of controlling stress is all you need. Other times, you want to really dig in and understand how the software computed a particular value. Engineering software should never be a black box. The details of every calculation are available through reports.
Customization | PGSuper is unique in that it doesn't have any default values. New projects are created from templates and the templates establish default values. PGSuper also has a library system where frequently used sets of complex information are stored. The library system includes definitions of common materials, girders, barriers, vehicles, project criteria, and load rating criteria. Together, the templates and libraries form a PGSuper Configuration.  You can create your own PGSuper Configuration and tailor it to your specific needs. PGSuper can be customized by changing its configuration.
Extensions | PGSuper can be extended with PGSuper Application Extensions. WSDOT and TxDOT have created extensions that provide agency-specific features. The WSDOT Girder Schedule report is one example. This report brings together all of the information a designer needs to include in the girder schedule for a WSDOT PS&E package.

## PGSplice
PGSplice is a BridgeLink Application for design, analysis, and load rating of spliced precast-prestressed girder bridges in accordance with AASHTO Specifications. PGSplice can model a wide variety of spliced girder bridge configurations including multi-span structures with cantilever pier segments, drop in field segments, erection towers, strong back hangers and multi-stage post-tensioning. PGSplice analyzes spliced girder structures with a non-linear time step method.

PGSplice is very similar to PGSuper in terms of its bridge modeling, analysis capabilities, and analysis results features. The biggest difference is that PGSplice can model multi-span continuous post-tensioned spliced girders. Most of the items discussed above for PGSuper are applicable to PGSplice.

Spliced girders are analyzed with a non-linear time step method. Time-dependent concrete properties, creep and shrinkage of concrete, and relaxation of prestressing steel can be modeled with the AASHTO LRFD, ACI209, and CEB-FIP Model Code.

## PGSuper/PGSplice Library Editor
The PGSuper/PGSplice Library Editor is a utility application for creating and managing libraries for PGSuper and PGSplice. The library editor is used by application administrators to create shared libraries. These libraries, when combined with project templates, form PGSuper and PGSplice Configurations. These configurations can be placed on a local area network for sharing within an organization or in the cloud for sharing around the world.

## Texas Optional Girder Analysis (TOGA)
The TOGA application is a utility program used by TxDOT engineers to evaluate contractor submitted optional designs. TOGA is generally not used outside of TxDOT.

## XBRate
The XBRate is a cross beam load rating application. XBRate is both an extension for PGSuper and PGSplice as well as a stand-alone BridgeLink application. XBRate adds a pier view, load rating reports, analysis results graphs, editing, and reinforced concrete cross beam load rating capabilities to PGSuper and PGSplice. Cross beam geometry, dead loads, and live loads are extracted from PGSuper/PGSplice. When used as a stand-alone BridgeLink application, XBRate models a generalized pier and cross beam. Superstructure reactions for dead and live loads are input from an external source and load rating computations are performed. Load rating calculations include Level 1, 2, and 3 ratings and load posting analysis as needed.

