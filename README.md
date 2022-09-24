# MM

Monolithic C++ interface for GTK and GNOME, forked from GTKMM.

## Build on Linux

### Meson

###### See [the project configuration](meson.build) for required dependencies.

Building is done by specifying a target directory to Meson:

```bash
meson setup builddir
meson compile -C builddir
```

## Documentation
The [documentation]() is generated from the repository source codes directly. It contains all necessary resources including source code snippets, details on execution of the programs, diagrammatic representation of program flow, and links to external resources.

## Legal
MM Libraries are licensed under the terms of their original authors.

* [mm-cairo](mm/cairo/LICENSE)
* [mm-gdk](mm/gdk/LICENSE)
* [mm-gio](mm/gio/LICENSE)
* [mm-glib](mm/glib/LICENSE)
* [mm-gtk](mm/gtk/LICENSE)
* [mm-pango](mm/pango/LICENSE)
