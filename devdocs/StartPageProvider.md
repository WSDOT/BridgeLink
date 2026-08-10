Start Page Provider
====================

BridgeLink has no built-in start page. Its main frame class, `CMainFrame`, is built on top of the
WBFL::EAF library's start page mechanism (`CEAFMainFrame::CreateStartPage`), but rather than
hard-coding start page content into `BridgeLink.exe`, `CMainFrame::CreateStartPage()` delegates to a
provider component that's selected at runtime. This is how a third party can supply BridgeLink's
start page without modifying or rebuilding `BridgeLink.exe` itself.

## How BridgeLink resolves a provider

`CMainFrame::CreateStartPage()` (`MainFrm.cpp`) does the following each time it's called:

1. Reads the string value `StartPageProvider` from the registry key
   `HKEY_CURRENT_USER\SOFTWARE\Washington State Department of Transportation\BridgeLink\Settings`.
   This value holds a CLSID.
2. Converts the string to a `CLSID` and asks the component manager to create an instance of it as an
   `IStartPageWndProvider`:
   ```
   auto start_page_wnd_provider =
      WBFL::EAF::ComponentManager::GetInstance().CreateComponent<IStartPageWndProvider>(clsid);
   ```
3. Forwards to that component's `CreateStartPage()` and returns whatever it returns.

If the registry value is missing, the CLSID string is invalid, or no component is registered under
that CLSID, `CreateStartPage()` falls through to `nullptr` - the same as any other EAF application
with no start page. There's no error dialog; a missing or misconfigured provider just means no start
page is shown.

## The `IStartPageWndProvider` interface

This is the interface a third party implements to become a start page provider
(`Include\StartPageWndProvider.h`):
```
class IStartPageWndProvider
{
public:
   virtual std::shared_ptr<CEAFStartPageWnd> CreateStartPage() = 0;
};
```

Its `CreateStartPage()` follows the same contract as the underlying EAF hook it's standing in for:
construct and return a `CEAFStartPageWnd`-derived window, but don't call `Create()` on it yourself -
BridgeLink's main frame does that once the window comes back from the provider.

## Registering a provider

To make BridgeLink use your provider:

1. Implement `IStartPageWndProvider` on a class that also derives from `WBFL::EAF::ComponentObject`,
   returning your `CEAFStartPageWnd`-derived window from `CreateStartPage()`.
2. Register that class as a Component Object under a CLSID of your choosing, the same way any other
   EAF component is registered (see the Component Object Model documentation in the WBFL::EAF
   developer docs for the manifest file and Object Entry Map mechanism).
3. Set the `StartPageProvider` value under
   `HKEY_CURRENT_USER\SOFTWARE\Washington State Department of Transportation\BridgeLink\Settings` to
   your provider's CLSID string, so `CMainFrame::CreateStartPage()` picks it up.
