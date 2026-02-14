# webviewer
A minimalistic browser intended for web applications

## Quickstart
### Launching
```webviewer https://chat.openai.com```

### Integrating in your system through Home Manager
to your Home Manager configuration add the following:
```
xdg = {
  enable = true;
  desktopEntries = {
    chatgpt = {
      name = "chatGPT";
      exec = "${pkgs.webviewer}/bin/webviewer https://chat.openai.com"
      terminal = false;
      categories = ["Network"];
      type = "Application";
    };
  };
};
```
make sure you added webviewer to your nixpkgs overlay that this works. 

### Building
```nix build```

## Why?
Modern websites are often more applications than websites. A general browser
IMHO often isn't the right tool for these kinds of applications.

- Browsers use by default a shared state between different webapps (e.g. shared
  cookie store, shared cache, shared settings, etc.) or it need some
  configuriation (e.g. containers on firefox), but that's IMHO too complicated.
  This implementation us a separate store for each domain.
- Browsers bring in lots of annoying ui, that can't be disabled. I want to
  launch a web application just like a native application, from my systems
  launcher. I don't want tabs there, or favourites or plugins or whatever. I
  just want to use that web application.

## Technical Stuff
### Browsing part
This project uses QtWebEngine. QtWebEngine is a sane version of chromium, where
google surveillance and vendored libs were patched out. Instead it uses systems
native libs and no surveillance. It's a browser engine that's both sane and
working for all websites (which is rather seldom these days).

### Building part
This project uses nix + CMake as its build system. You should really try
[nix](https://nixos.org/explore) if you don't know it yet.

### MCP (Model Context Protocol) Integration
This repository includes MCP configuration (`.mcp.json`) for AI assistants to access:
- **GitHub MCP Server**: Access repository code, issues, PRs, workflows, and more
- **NixOS MCP Server**: Query NixOS packages, options, Home Manager, and nix-darwin configurations

Compatible with AI tools supporting MCP like Claude Desktop, VS Code, Cursor, and others.
For more information, see:
- [GitHub MCP Server](https://github.com/github/github-mcp-server)
- [NixOS MCP Server](https://mcp-nixos.io/)

### ToDo (in no particular order)
- One Process Multiple Sessions
- Ad-Blocking
- Support for UserScripts
- IPC for controlling through external tools
- NixOS module
