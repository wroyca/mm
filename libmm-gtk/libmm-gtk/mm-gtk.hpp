/* gtkmm - a C++ wrapper for the Gtk toolkit
 *
 * Copyright 1999-2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _GTKMM_H
#define _GTKMM_H

/** @mainpage gtkmm Reference Manual
 *
 * @section description Description
 *
 * gtkmm is the official C++ interface for the popular GUI library GTK.
 * Highlights include typesafe callbacks, and a comprehensive set of widgets
 * that are easily extensible via inheritance.
 *
 * For instance, see @ref Widgets, @ref Dialogs, @ref TreeView "TreeView" and
 * @ref TextView "TextView".
 *
 * See also the
 * <a href="https://gnome.pages.gitlab.gnome.org/gtkmm-documentation/">Programming
 * with gtkmm</a> book.
 *
 * @section features Features
 *
 * - GTK’s mature, capable set of @ref Widgets "widgets". See
 *   <a href="https://www.gtk.org/">the GTK website</a> for more information.
 * - Use inheritance to derive custom widgets.
 * - Type-safe signal handlers (slots), in standard C++, using
 *   <a href="https://libsigcplusplus.github.io/libsigcplusplus/">libsigc++</a>.
 * - Polymorphism.
 * - Use of the Standard C++ Library, including strings, containers and
 *   iterators.
 * - Full internationalisation with UTF8.
 * - Complete C++ memory management.
 *   - Member instances or dynamic new and delete.
 *   - Optional automatic deletion of child widgets.
 *   - No manual reference-counting.
 * - Full use of C++ namespaces.
 * - No macros.
 *
 * @section basics Basic Usage
 *
 * Include the gtkmm header:
 * @code
 * #include <libmm-gtk.h>
 * @endcode
 * (You may include individual headers, such as @c gtkmm/button.h instead.)
 *
 * If your source file is @c program.cc, you can compile it with:
 * @code
 * g++ program.cc -o program  `pkg-config --cflags --libs gtkmm-4.0`
 * @endcode
 * If your version of g++ is not C++17-compliant by default,
 * add the @c -std=c++17 option.
 *
 * If you use <a href="https://mesonbuild.com/">Meson</a>, include the following
 * in @c meson.build:
 * @code
 * gtkmm_dep = dependency('gtkmm-4.0')
 * program_name = 'program'
 * cpp_sources = [ 'program.cc' ]
 * executable(program_name,
 *   cpp_sources,
 *   dependencies: gtkmm_dep
 * )
 * @endcode
 *
 * Alternatively, if using autoconf, use the following in @c configure.ac:
 * @code
 * PKG_CHECK_MODULES([GTKMM], [gtkmm-4.0])
 * @endcode
 * Then use the generated @c GTKMM_CFLAGS and @c GTKMM_LIBS variables in the
 * project @c Makefile.am files. For example:
 * @code
 * program_CPPFLAGS = $(GTKMM_CFLAGS)
 * program_LDADD = $(GTKMM_LIBS)
 * @endcode
 */

/* Gtkmm version.  */
extern const int gtkmm_major_version;
extern const int gtkmm_minor_version;
extern const int gtkmm_micro_version;

#include <libmm-glib/mm-glib.hpp>
#include <libmm-gio/gio.hpp>

#include <libmm-gdk/mm-gdk.hpp>

#include <libmm-gtk/object.hpp>
#include <libmm-gtk/aboutdialog.hpp>
#include <libmm-gtk/accelerator.hpp>
#include <libmm-gtk/accelkey.hpp>
#include <libmm-gtk/actionable.hpp>
#include <libmm-gtk/actionbar.hpp>
#include <libmm-gtk/adjustment.hpp>
#include <libmm-gtk/appchooserbutton.hpp>
#include <libmm-gtk/appchooserdialog.hpp>
#include <libmm-gtk/appchooserwidget.hpp>
#include <libmm-gtk/application.hpp>
#include <libmm-gtk/applicationwindow.hpp>
#include <libmm-gtk/aspectframe.hpp>
#include <libmm-gtk/assistant.hpp>
#include <libmm-gtk/binlayout.hpp>
#include <libmm-gtk/boolfilter.hpp>
#include <libmm-gtk/border.hpp>
#include <libmm-gtk/box.hpp>
#include <libmm-gtk/boxlayout.hpp>
#include <libmm-gtk/builder.hpp>
#include <libmm-gtk/button.hpp>
#include <libmm-gtk/cellarea.hpp>
#include <libmm-gtk/cellareabox.hpp>
#include <libmm-gtk/cellareacontext.hpp>
#include <libmm-gtk/cellview.hpp>
#include <libmm-gtk/checkbutton.hpp>
#include <libmm-gtk/cellrenderer.hpp>
#include <libmm-gtk/cellrendereraccel.hpp>
#include <libmm-gtk/cellrenderercombo.hpp>
#include <libmm-gtk/cellrendererpixbuf.hpp>
#include <libmm-gtk/cellrendererprogress.hpp>
#include <libmm-gtk/cellrendererspin.hpp>
#include <libmm-gtk/cellrendererspinner.hpp>
#include <libmm-gtk/cellrenderertext.hpp>
#include <libmm-gtk/cellrenderertoggle.hpp>
#include <libmm-gtk/centerbox.hpp>
#include <libmm-gtk/centerlayout.hpp>
#include <libmm-gtk/colorbutton.hpp>
#include <libmm-gtk/colorchooser.hpp>
#include <libmm-gtk/colorchooserdialog.hpp>
#include <libmm-gtk/columnview.hpp>
#include <libmm-gtk/combobox.hpp>
#include <libmm-gtk/comboboxtext.hpp>
#include <libmm-gtk/constraintlayout.hpp>
#include <libmm-gtk/cssprovider.hpp>
#include <libmm-gtk/csssection.hpp>
#include <libmm-gtk/dialog.hpp>
#include <libmm-gtk/directorylist.hpp>
#include <libmm-gtk/dragicon.hpp>
#include <libmm-gtk/dragsource.hpp>
#include <libmm-gtk/drawingarea.hpp>
#include <libmm-gtk/dropcontrollermotion.hpp>
#include <libmm-gtk/dropdown.hpp>
#include <libmm-gtk/droptarget.hpp>
#include <libmm-gtk/droptargetasync.hpp>
#include <libmm-gtk/editablelabel.hpp>
#include <libmm-gtk/emojichooser.hpp>
#include <libmm-gtk/entry.hpp>
#include <libmm-gtk/expander.hpp>
#include <libmm-gtk/enums.hpp>
#include <libmm-gtk/eventcontroller.hpp>
#include <libmm-gtk/eventcontrollerfocus.hpp>
#include <libmm-gtk/eventcontrollerkey.hpp>
#include <libmm-gtk/eventcontrollermotion.hpp>
#include <libmm-gtk/eventcontrollerscroll.hpp>
#include <libmm-gtk/filechooser.hpp>
#include <libmm-gtk/filechooserdialog.hpp>
#include <libmm-gtk/filechoosernative.hpp>
#include <libmm-gtk/filechooserwidget.hpp>
#include <libmm-gtk/filefilter.hpp>
#include <libmm-gtk/filterlistmodel.hpp>
#include <libmm-gtk/fixed.hpp>
#include <libmm-gtk/flattenlistmodel.hpp>
#include <libmm-gtk/flowbox.hpp>
#include <libmm-gtk/flowboxchild.hpp>
#include <libmm-gtk/fontbutton.hpp>
#include <libmm-gtk/fontchooser.hpp>
#include <libmm-gtk/fontchooserdialog.hpp>
#include <libmm-gtk/fontchooserwidget.hpp>
#include <libmm-gtk/frame.hpp>
#include <libmm-gtk/gesture.hpp>
#include <libmm-gtk/gestureclick.hpp>
#include <libmm-gtk/gesturedrag.hpp>
#include <libmm-gtk/gesturelongpress.hpp>
#include <libmm-gtk/gesturepan.hpp>
#include <libmm-gtk/gesturerotate.hpp>
#include <libmm-gtk/gesturesingle.hpp>
#include <libmm-gtk/gesturestylus.hpp>
#include <libmm-gtk/gestureswipe.hpp>
#include <libmm-gtk/gesturezoom.hpp>
#include <libmm-gtk/glarea.hpp>
#include <libmm-gtk/grid.hpp>
#include <libmm-gtk/gridlayout.hpp>
#include <libmm-gtk/gridlayoutchild.hpp>
#include <libmm-gtk/gridview.hpp>
#include <libmm-gtk/headerbar.hpp>
#include <libmm-gtk/icontheme.hpp>
#include <libmm-gtk/iconview.hpp>
#include <libmm-gtk/image.hpp>
#include <libmm-gtk/infobar.hpp>
#include <libmm-gtk/inscription.hpp>
#include <libmm-gtk/calendar.hpp>
#include <libmm-gtk/label.hpp>
#include <libmm-gtk/layoutchild.hpp>
#include <libmm-gtk/layoutmanager.hpp>
#include <libmm-gtk/levelbar.hpp>
#include <libmm-gtk/listbox.hpp>
#include <libmm-gtk/listboxrow.hpp>
#include <libmm-gtk/liststore.hpp>
#include <libmm-gtk/listview.hpp>
#include <libmm-gtk/listviewtext.hpp>
#include <libmm-gtk/linkbutton.hpp>
#include <libmm-gtk/mediacontrols.hpp>
#include <libmm-gtk/mediafile.hpp>
#include <libmm-gtk/menubutton.hpp>
#include <libmm-gtk/messagedialog.hpp>
#include <libmm-gtk/multifilter.hpp>
#include <libmm-gtk/multiselection.hpp>
#include <libmm-gtk/multisorter.hpp>
#include <libmm-gtk/noselection.hpp>
#include <libmm-gtk/notebook.hpp>
#include <libmm-gtk/numericsorter.hpp>
#include <libmm-gtk/object.hpp>
#include <libmm-gtk/overlay.hpp>
#include <libmm-gtk/padcontroller.hpp>
#include <libmm-gtk/paned.hpp>
#include <libmm-gtk/pagesetup.hpp>
#ifndef G_OS_WIN32
#include <libmm-gtk/pagesetupunixdialog.hpp>
#endif
#include <libmm-gtk/papersize.hpp>
#include <libmm-gtk/passwordentry.hpp>
#include <libmm-gtk/picture.hpp>
#include <libmm-gtk/popover.hpp>
#include <libmm-gtk/popovermenu.hpp>
#include <libmm-gtk/popovermenubar.hpp>
#include <libmm-gtk/printcontext.hpp>
#ifndef G_OS_WIN32
#include <libmm-gtk/printer.hpp>
#include <libmm-gtk/printjob.hpp>
#endif
#include <libmm-gtk/printoperation.hpp>
#include <libmm-gtk/printoperationpreview.hpp>
#include <libmm-gtk/printsettings.hpp>
#ifndef G_OS_WIN32
#include <libmm-gtk/printunixdialog.hpp>
#endif
#include <libmm-gtk/progressbar.hpp>
#include <libmm-gtk/range.hpp>
#include <libmm-gtk/recentinfo.hpp>
#include <libmm-gtk/recentmanager.hpp>
#include <libmm-gtk/revealer.hpp>
#include <libmm-gtk/scale.hpp>
#include <libmm-gtk/scalebutton.hpp>
#include <libmm-gtk/scrollbar.hpp>
#include <libmm-gtk/scrolledwindow.hpp>
#include <libmm-gtk/searchbar.hpp>
#include <libmm-gtk/searchentry.hpp>
#include <libmm-gtk/separator.hpp>
#include <libmm-gtk/selectionfiltermodel.hpp>
#include <libmm-gtk/selectionlistmodelimpl.hpp>
#include <libmm-gtk/settings.hpp>
#include <libmm-gtk/shortcutcontroller.hpp>
#include <libmm-gtk/shortcutlabel.hpp>
#include <libmm-gtk/shortcutsgroup.hpp>
#include <libmm-gtk/shortcutssection.hpp>
#include <libmm-gtk/shortcutsshortcut.hpp>
#include <libmm-gtk/shortcutswindow.hpp>
#include <libmm-gtk/signallistitemfactory.hpp>
#include <libmm-gtk/singleselection.hpp>
#include <libmm-gtk/sizegroup.hpp>
#include <libmm-gtk/slicelistmodel.hpp>
#include <libmm-gtk/snapshot.hpp>
#include <libmm-gtk/sortlistmodel.hpp>
#include <libmm-gtk/spinbutton.hpp>
#include <libmm-gtk/spinner.hpp>
#include <libmm-gtk/stack.hpp>
#include <libmm-gtk/stacksidebar.hpp>
#include <libmm-gtk/stackswitcher.hpp>
#include <libmm-gtk/statusbar.hpp>
#include <libmm-gtk/stringfilter.hpp>
#include <libmm-gtk/stringlist.hpp>
#include <libmm-gtk/stringobject.hpp>
#include <libmm-gtk/stringsorter.hpp>
#include <libmm-gtk/stylecontext.hpp>
#include <libmm-gtk/switch.hpp>
#include <libmm-gtk/text.hpp>
#include <libmm-gtk/textbuffer.hpp>
#include <libmm-gtk/textchildanchor.hpp>
#include <libmm-gtk/textiter.hpp>
#include <libmm-gtk/textmark.hpp>
#include <libmm-gtk/texttag.hpp>
#include <libmm-gtk/texttagtable.hpp>
#include <libmm-gtk/textview.hpp>
#include <libmm-gtk/togglebutton.hpp>
#include <libmm-gtk/tooltip.hpp>
#include <libmm-gtk/treeexpander.hpp>
#include <libmm-gtk/treelistmodel.hpp>
#include <libmm-gtk/treemodel.hpp>
#include <libmm-gtk/treemodelfilter.hpp>
#include <libmm-gtk/treemodelsort.hpp>
#include <libmm-gtk/treepath.hpp>
#include <libmm-gtk/treerowreference.hpp>
#include <libmm-gtk/treeselection.hpp>
#include <libmm-gtk/treestore.hpp>
#include <libmm-gtk/treeview.hpp>
#include <libmm-gtk/treeviewcolumn.hpp>
#include <libmm-gtk/version.hpp>
#include <libmm-gtk/video.hpp>
#include <libmm-gtk/viewport.hpp>
#include <libmm-gtk/volumebutton.hpp>
#include <libmm-gtk/widget.hpp>
#include <libmm-gtk/widgetpaintable.hpp>
#include <libmm-gtk/windowcontrols.hpp>
#include <libmm-gtk/window.hpp>
#include <libmm-gtk/windowhandle.hpp>

#endif /* #ifndef GTKMM_H */
