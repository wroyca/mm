# Libmm

Libmm is a robust and versatile library that empowers developers to create
sophisticated graphical user interfaces for their applications with ease.
Building upon GNOME C++ bindings solid foundation, we have made extensive
modifications to the original codebase and packaged it with build2 to offer an
even more powerful development experience. 

> **Note**
> Libmm is currently in an alpha stage of development, which means that there may still be some issues and breakage. Nonetheless, we welcome developers to join us on this exciting journey to improve and refine the library, and contribute to its ongoing development

<img src="https://developer.gnome.org/hig/_images/hig.svg" alt="Hig" height="300">

## Getting Started 

If you're ready to start using libmm, we recommend referring to  the [build2](https://build2.org/build2-toolchain/doc/build2-toolchain-intro.xhtml#preface) documentation. This documentation provides comprehensive instructions for installing and using build2, which offers a powerful and flexible development experience that integrates seamlessly with libmm. If you're already familiar with build2, you can build, test, install, uninstall and upgrade libmm with:

### Windows
```bash
# Create the build configuration:
> bpkg create -d libmm-msvc cc                ^
  config.cxx=cl                               ^
  config.cc.coptions=/O2                      ^
  config.cc.loptions="/LIBPATH:C:/gnome/lib/" ^
  config.install.root=C:/libmm/
> cd libmm-msvc

# To build:
> bpkg build libmm@https://github.com/wroyca/mm.git#main

# To test:
> bpkg test libmm

# To install:
> bpkg install libmm

# To uninstall:
> bpkg uninstall libmm

# To upgrade:
> bpkg fetch
> bpkg status libmm
> bpkg uninstall libmm
> bpkg build --upgrade --recursive libmm
> bpkg install libmm
```

### Linux
```bash
# Create the build configuration:
$ bpkg create -d libmm-gcc cc     \
  config.cxx=g++                  \
  config.cc.coptions=-O3          \
  config.bin.rpath=/usr/local/lib \
  config.install.root=/usr/local  \
  config.install.sudo=sudo
$ cd libmm-gcc

# To build:
$ bpkg build libmm@https://github.com/wroyca/mm.git#main

# To test:
$ bpkg test libmm

# To install:
$ bpkg install libmm

# To uninstall:
$ bpkg uninstall libmm

# To upgrade:
$ bpkg fetch
$ bpkg status libmm
$ bpkg uninstall libmm
$ bpkg build --upgrade --recursive libmm
$ bpkg install libmm
```

###### See [Package Consumption](https://build2.org/build2-toolchain/doc/build2-toolchain-intro.xhtml#guide-consume-pkg) for more information on these bpkg commands.  

## Credits
We would like to extend our appreciation to all the contributors who have helped make the entire collection of GNOME C++ binding libraries a robust and powerful GUI programming tool for C++, including Kjell Ahlstedt, Roger Ferrer Ibáñez, Murray Cumming, Daniel Elstner, Karl Nelson, Tero Pulkkinen, Elliot Lee, Phil Dawes, Erik Andersen, Bibek Sahu, Mirko Streckenbach, Havoc Pennington, Guillaume Laurent, Todd Dukes, Peter Lerner, Herbert Valerio Riedel, and many others.

We would also like to acknowledge any contributors to this repository and those who may contribute in the future. Their hard work and dedication have been essential to the development of this project. Additionally, we extend our appreciation to the GNOME community for their ongoing support and development of the original C++ bindings upon which this repository is based. Without their efforts, this project would not have been possible.

## License
Libmm comprises a collection of C++ binding libraries that were originally derived from the GNOME C++ binding libraries. The libraries themselves are subject to their own individual licenses, and any modifications made to the libraries in this repository are still bound by the terms of their original licenses.

* [libmm-adw](libmm-cairo/LICENSE.md)
* [libmm-cairo](libmm-cairo/LICENSE.md)
* [libmm-gdk](libmm-gdk/LICENSE.md)
* [libmm-gio](libmm-gio/LICENSE.md)
* [libmm-glib](libmm-glib/LICENSE.md)
* [libmm-gtk](libmm-gtk/LICENSE.md)
* [libmm-pango](libmm-pango/LICENSE.md)
