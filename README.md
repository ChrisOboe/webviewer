# webviewer
A minimalistic browser intended for web applications

## Quickstart
### Launching
```webviewer https://chat.openai.com```

### Building
```nix build```

## Why?
Modern websites are often more applications than websites. A general browser IMHO often isn't the right tool for these kinds of applications.

- Browsers use by default a shared state between different webapps (e.g. shared cookie store, shared cache, shared settings, etc.) or it need some configuriation (e.g. containers on firefox), but that's IMHO too complicated. This implementation us a separate store for each domain.
- Browsers bring in lots of annoying ui, that can't be disabled. I want to launch a web application just like a native application, from my systems launcher. I don't want tabs there, or favourites or plugins or whatever. I just want to use that web application.

## Technical Stuff
### Browsing part
This project uses QtWebEngine. QtWebEngine is a sane version of chromium, where google surveillance and vendored libs were patched out. Instead it uses systems native libs and no surveillance. It's a browser engine that's both sane and working for all websites (which is rather seldom these days). 

### Building part
This project uses nix + CMake as it's build system. You should really try [nix](https://nixos.org/explore) if you don't know it yet. 

### ToDo (in no particular order)
- Multiple Windows
- One Process Multiple Sessions
- Ad-Blocking
- Support for UserScripts
- IPC for controlling through external tools
- NixOS integration module (for automatically creating 'shortcuts' to web applications in your favourite launcher)
