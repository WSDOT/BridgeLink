# BridgeLink

BridgeLink is a bridge engineering application framework. BridgeLink provides a single entry point into a suite of bridge engineering applications such as [BEToolbox](https://github.com/WSDOT/BEToolbox), [PGSuper](https://github.com/WSDOT/PGSuper), and [XBeamRate](https://github.com/WSDOT/XBeamRate). BridgeLink applications are runtime discovered and automatically integrated in the application framework.

## Getting Started
This repository holds the source code fo the BridgeLink application. 

### Installing BridgeLink with pre-built MSI installer package
If you are looking to download the MSI installer package for the BridgeLink bridge engineering suite, you can do so from [WSDOT](http://www.wsdot.wa.gov) at [http://www.wsdot.wa.gov/eesc/bridge/software](http://www.wsdot.wa.gov/eesc/bridge/software).

### Building BridgeLink from source
If you are looking to build BridgeLink from source you will need to start with the [Washington Bridge Foundation Libraries (WBFL)](https://github.com/WSDOT/WBFL) and then the BridgeLink plug-in applications (such as [PGSuper](https://github.com/WSDOT/PGSuper)). 

In theory, you can build the main BridgeLink application without any of the plug-in applications and you'll have a running program. It won't do anything because it will be just an empty shell. The BridgeLink suite is most useful when there are BridgeLink plug-in applications available.

The standard BridgeLink plug-in applications are:
* [Barlist](https://github.com/WSDOT/Barlist)
* [BEToolbox](https://github.com/WSDOT/BEToolbox)
* [PGSuper/PGSplice](https://github.com/WSDOT/PGSuper)
* [XBeamRate](https://github.com/WSDOT/XBeamRate)

Once you've cloned the repositories for the BridgeLink plug-in applications you want to use:
1. Satisfy the prerequisites and build WBFL
2. Satisfy the prerequisites and build one or more BridgeLink plug-in applications using the VS Solution File (*.sln) in the app's repository
3. Build BridgeLink using the BridgeLink.sln solution

The prefered method to build the entire BridgeLink suite is to:
1. Satisfy the prerequisites and build WBFL
2. Satisfy the prerequisites for all the standard BridgeLink plug-in applications
3. Build the BridgeLink suite using the BridgeLinkComplete.sln solution.

#### Prerequisites
The general prerequisites are:

1. Download and install the following projects before you can build the WBFL
* [Boost libraries](http://www.boost.org)
* [Code Synthesis XSD 3.3](https://codesynthesis.com/products/xsd/)

2. Define BOOSTDIR and XSDDIR environment variables for the location where the boost and code synthesis libraries are installed.

3. Clone the repository into **drive letter**:/ARP/ and create an environment variable ARPDIR to this folder.

4. Obtain and install the Stingray ObjectiveGrid product from Perforce (https://www.perforce.com/products/stingray). Several of the BridgeLink plug-in applications use this grid control product in the UI since a suitable open source grid control has not been identified. Define a GRID_PROPS environment variable that specifies the ObjectiveGrid properties files. A common setting is "C:\Program Files\Perforce\Stingray Studio 2022.1\Src\SS-X64-PropSheet16.props". A do-nothing proxy for the  ObjectiveGrid control is available WBFL. This proxy enables full BridgeLink suite builds without the ObjectiveGrid control. The proxy does not simulate grid functionality, it simply provides dummy classes and methods to enable builds. Accessing windows and dialogs that utilize the ObjectiveGrid control will not function properly and may crash. See WBFL for details on building the BridgeLink suite without ObjectiveGrid.

## Registering BridgeLink Plug-in Applications
All BridgeLink applications are plug-ins to the BridgeLink-environment. BridgeLink discovers the plug-in applications at runtime using COM Component Categories.

When running BridgeLink from the Visual Studio development environment, you must register the BridgeLink plug-in applications with RegSvr32.exe. Additionally, some BridgeLink plug-in applications themselves have runtime discoverable components. One example is PGSuper. These components must be registered as well.

To make life easy, there is a script file in the BridgeLink source code called RegFiles.js. The header of this file provides step-by-step instructions for setting up the Visual Studio **Tools > External Tools** feature to register all these components automatically.

Before starting a debugging session, use the script file to register all of the Debug or Release build components (depending on if you are starting the debugger or just launching the application, respectively). 

If anyone has a better way of automatically registering these components, please implement and send a pull request.

## Authors
This project is jointly developed by the Washington State and Texas Departments of Transportation

* **Richard Brice, PE** - [WSDOT](https://github.com/RickBrice)
* **Richard Pickings, PE** - [BridgeSight Inc](http://www.bridgesight.com) for TxDOT

## License

This project is licensed under the [Alternate Route Open Source License](http://www.wsdot.wa.gov/eesc/bridge/alternateroute/arosl.htm)

