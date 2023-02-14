# C++ binding libraries for the GNOME ecosystem

C++ binding libraries for the GNOME ecosystem, maintained and packaged for easy consumption in [build2](https://build2.org) projects.

> **Warning**
>
> The libraries has been tailored to meet our personal needs, and includes some unique modifications that you won't find in their upstream counter-part. Please use this repository at your own risk and make sure to thoroughly test any modifications before incorporating them into your own projects.

![mm](mm.png)

## Releases

This repository uses [Semantic Versioning](https://semver.org/) for its releases. You can find the latest release, as well as all previous releases, on the [Releases page](https://github.com/wroyca/mm/release) page.

## Building

To build the packages, simply run the following command:

* `bdep init -C @build cc && b`

You can choose a different compiler using the config.cxx option:

* `bdep init -C @build cc config.cxx=cl && b`

To build with debugging symbols, add the appropriate flags:

* `bdep init -C @build cc config.cxx=cl config.cc.coptions="/Od /MDd /Zi" config.cc.loptions=/DEBUG && b`

###### For instructions on installing the build2 toolchain and setting up your environment, please refer to the build2 documentation.

## Installing

To install the packages, use the following command:

`b install`

This will install the packages to the default prefix of the build2 build system (usually /usr/local). You can specify a different prefix using the config.install.root or !config.install.root option:

`b install config.install.root=/mm/`

## Documentation

We made the difficult decision to strip all comments from our source files. Why, you ask? Well, it turns out that our beloved Doxygen was tripping over these comments and refusing to generate proper documentation. We know, we know - this is not an ideal solution by any stretch of the imagination. But trust us, going through and manually fixing each and every one would have taken longer than it does to get through a season of Game of Thrones. In the end, we made the tough call to sacrifice our comments to ensure that we could all sleep soundly at night.

Now, we can hear you groaning already - "But what about all of our precious comments?!" Fear not, dear reader, for we have a plan. We still have access to the comments from an older commit, and we will be selectively adding back the most important ones. And, in case you were worried, we promise that we will eventually provide proper documentation for every function. We know that documentation is crucial to the success of any project, and we take it seriously—sort of.

We understand that this was a very aggressive cleanup, and it may not seem like it's making our lives easier in the short term. But this is going to be a huge help in the long run. And who knows, maybe we'll look back on this in a few months and have a good laugh about how we had to strip out all of our comments just to get our documentation to work. Hey, a little humor goes a long way in the world of software development!

## License

The repository acts as a packaging and distribution platform for the GNOME C++ binding libraries. The libraries themselves are subject to their own individual licenses, and any modifications made to the libraries in this repository are still bound by the terms of their original licenses. This repository simply provides a convenient way to distribute and manage the libraries within build2 projects, while still respecting the licenses of the individual libraries.

* [libmm-adw](libmm-cairo/LICENSE.md)
* [libmm-cairo](libmm-cairo/LICENSE.md)
* [libmm-gdk](libmm-gdk/LICENSE.md)
* [libmm-gio](libmm-gio/LICENSE.md)
* [libmm-glib](libmm-glib/LICENSE.md)
* [libmm-gtk](libmm-gtk/LICENSE.md)
* [libmm-pango](libmm-pango/LICENSE.md)
