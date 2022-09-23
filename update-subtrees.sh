#!/bin/sh

# Provide an easy way to automatically merge changes from upstream.
# If you don't have a POSIX-compatible shell on your system, feel free to use
# this as a reference. 
# 
# Adapted from LukeUsher.

# Switch to the directory containing this script, or exit with a failure to 
# prevent the git subtree from spreading to another repository.
cd "$(dirname "$0")" || exit 1

# Merge changes from upstream repositories.
# Ideally, this should not be necessary, as we want to move the development here. 
git subtree pull --prefix mm-cairo git@gitlab.gnome.org:wroy/cairomm.git master --squash
git subtree pull --prefix mm-common git@gitlab.gnome.org:wroy/mm-common.git master --squash
git subtree pull --prefix mm-glib git@gitlab.gnome.org:wroy/glibmm.git master --squash
git subtree pull --prefix mm-pango git@gitlab.gnome.org:wroy/pangomm.git master --squash
git subtree pull --prefix mm-gtk git@gitlab.gnome.org:wroy/gtkmm.git master --squash

