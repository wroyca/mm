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
 * #include <mm/gtk.h>
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

#include <mm/glib/mm-glib.hpp>
#include <mm/gio/gio.hpp>

#include <mm/gdk/mm-gdk.hpp>

#include <mm/gtk/object.hpp>
#include <mm/gtk/aboutdialog.hpp>
#include <mm/gtk/accelerator.hpp>
#include <mm/gtk/accelkey.hpp>
#include <mm/gtk/actionable.hpp>
#include <mm/gtk/actionbar.hpp>
#include <mm/gtk/adjustment.hpp>
#include <mm/gtk/appchooserbutton.hpp>
#include <mm/gtk/appchooserdialog.hpp>
#include <mm/gtk/appchooserwidget.hpp>
#include <mm/gtk/application.hpp>
#include <mm/gtk/applicationwindow.hpp>
#include <mm/gtk/aspectframe.hpp>
#include <mm/gtk/assistant.hpp>
#include <mm/gtk/binlayout.hpp>
#include <mm/gtk/boolfilter.hpp>
#include <mm/gtk/border.hpp>
#include <mm/gtk/box.hpp>
#include <mm/gtk/boxlayout.hpp>
#include <mm/gtk/builder.hpp>
#include <mm/gtk/button.hpp>
#include <mm/gtk/cellarea.hpp>
#include <mm/gtk/cellareabox.hpp>
#include <mm/gtk/cellareacontext.hpp>
#include <mm/gtk/cellview.hpp>
#include <mm/gtk/checkbutton.hpp>
#include <mm/gtk/cellrenderer.hpp>
#include <mm/gtk/cellrendereraccel.hpp>
#include <mm/gtk/cellrenderercombo.hpp>
#include <mm/gtk/cellrendererpixbuf.hpp>
#include <mm/gtk/cellrendererprogress.hpp>
#include <mm/gtk/cellrendererspin.hpp>
#include <mm/gtk/cellrendererspinner.hpp>
#include <mm/gtk/cellrenderertext.hpp>
#include <mm/gtk/cellrenderertoggle.hpp>
#include <mm/gtk/centerbox.hpp>
#include <mm/gtk/centerlayout.hpp>
#include <mm/gtk/colorbutton.hpp>
#include <mm/gtk/colorchooser.hpp>
#include <mm/gtk/colorchooserdialog.hpp>
#include <mm/gtk/columnview.hpp>
#include <mm/gtk/combobox.hpp>
#include <mm/gtk/comboboxtext.hpp>
#include <mm/gtk/constraintlayout.hpp>
#include <mm/gtk/cssprovider.hpp>
#include <mm/gtk/csssection.hpp>
#include <mm/gtk/dialog.hpp>
#include <mm/gtk/directorylist.hpp>
#include <mm/gtk/dragicon.hpp>
#include <mm/gtk/dragsource.hpp>
#include <mm/gtk/drawingarea.hpp>
#include <mm/gtk/dropcontrollermotion.hpp>
#include <mm/gtk/dropdown.hpp>
#include <mm/gtk/droptarget.hpp>
#include <mm/gtk/droptargetasync.hpp>
#include <mm/gtk/editablelabel.hpp>
#include <mm/gtk/emojichooser.hpp>
#include <mm/gtk/entry.hpp>
#include <mm/gtk/expander.hpp>
#include <mm/gtk/enums.hpp>
#include <mm/gtk/eventcontroller.hpp>
#include <mm/gtk/eventcontrollerfocus.hpp>
#include <mm/gtk/eventcontrollerkey.hpp>
#include <mm/gtk/eventcontrollermotion.hpp>
#include <mm/gtk/eventcontrollerscroll.hpp>
#include <mm/gtk/filechooser.hpp>
#include <mm/gtk/filechooserdialog.hpp>
#include <mm/gtk/filechoosernative.hpp>
#include <mm/gtk/filechooserwidget.hpp>
#include <mm/gtk/filefilter.hpp>
#include <mm/gtk/filterlistmodel.hpp>
#include <mm/gtk/fixed.hpp>
#include <mm/gtk/flattenlistmodel.hpp>
#include <mm/gtk/flowbox.hpp>
#include <mm/gtk/flowboxchild.hpp>
#include <mm/gtk/fontbutton.hpp>
#include <mm/gtk/fontchooser.hpp>
#include <mm/gtk/fontchooserdialog.hpp>
#include <mm/gtk/fontchooserwidget.hpp>
#include <mm/gtk/frame.hpp>
#include <mm/gtk/gesture.hpp>
#include <mm/gtk/gestureclick.hpp>
#include <mm/gtk/gesturedrag.hpp>
#include <mm/gtk/gesturelongpress.hpp>
#include <mm/gtk/gesturepan.hpp>
#include <mm/gtk/gesturerotate.hpp>
#include <mm/gtk/gesturesingle.hpp>
#include <mm/gtk/gesturestylus.hpp>
#include <mm/gtk/gestureswipe.hpp>
#include <mm/gtk/gesturezoom.hpp>
#include <mm/gtk/glarea.hpp>
#include <mm/gtk/grid.hpp>
#include <mm/gtk/gridlayout.hpp>
#include <mm/gtk/gridlayoutchild.hpp>
#include <mm/gtk/gridview.hpp>
#include <mm/gtk/headerbar.hpp>
#include <mm/gtk/icontheme.hpp>
#include <mm/gtk/iconview.hpp>
#include <mm/gtk/image.hpp>
#include <mm/gtk/infobar.hpp>
#include <mm/gtk/inscription.hpp>
#include <mm/gtk/calendar.hpp>
#include <mm/gtk/label.hpp>
#include <mm/gtk/layoutchild.hpp>
#include <mm/gtk/layoutmanager.hpp>
#include <mm/gtk/levelbar.hpp>
#include <mm/gtk/listbox.hpp>
#include <mm/gtk/listboxrow.hpp>
#include <mm/gtk/liststore.hpp>
#include <mm/gtk/listview.hpp>
#include <mm/gtk/listviewtext.hpp>
#include <mm/gtk/linkbutton.hpp>
#include <mm/gtk/mediacontrols.hpp>
#include <mm/gtk/mediafile.hpp>
#include <mm/gtk/menubutton.hpp>
#include <mm/gtk/messagedialog.hpp>
#include <mm/gtk/multifilter.hpp>
#include <mm/gtk/multiselection.hpp>
#include <mm/gtk/multisorter.hpp>
#include <mm/gtk/noselection.hpp>
#include <mm/gtk/notebook.hpp>
#include <mm/gtk/numericsorter.hpp>
#include <mm/gtk/object.hpp>
#include <mm/gtk/overlay.hpp>
#include <mm/gtk/padcontroller.hpp>
#include <mm/gtk/paned.hpp>
#include <mm/gtk/pagesetup.hpp>
#ifndef G_OS_WIN32
#include <mm/gtk/pagesetupunixdialog.hpp>
#endif
#include <mm/gtk/papersize.hpp>
#include <mm/gtk/passwordentry.hpp>
#include <mm/gtk/picture.hpp>
#include <mm/gtk/popover.hpp>
#include <mm/gtk/popovermenu.hpp>
#include <mm/gtk/popovermenubar.hpp>
#include <mm/gtk/printcontext.hpp>
#ifndef G_OS_WIN32
#include <mm/gtk/printer.hpp>
#include <mm/gtk/printjob.hpp>
#endif
#include <mm/gtk/printoperation.hpp>
#include <mm/gtk/printoperationpreview.hpp>
#include <mm/gtk/printsettings.hpp>
#ifndef G_OS_WIN32
#include <mm/gtk/printunixdialog.hpp>
#endif
#include <mm/gtk/progressbar.hpp>
#include <mm/gtk/range.hpp>
#include <mm/gtk/recentinfo.hpp>
#include <mm/gtk/recentmanager.hpp>
#include <mm/gtk/revealer.hpp>
#include <mm/gtk/scale.hpp>
#include <mm/gtk/scalebutton.hpp>
#include <mm/gtk/scrollbar.hpp>
#include <mm/gtk/scrolledwindow.hpp>
#include <mm/gtk/searchbar.hpp>
#include <mm/gtk/searchentry.hpp>
#include <mm/gtk/separator.hpp>
#include <mm/gtk/selectionfiltermodel.hpp>
#include <mm/gtk/selectionlistmodelimpl.hpp>
#include <mm/gtk/settings.hpp>
#include <mm/gtk/shortcutcontroller.hpp>
#include <mm/gtk/shortcutlabel.hpp>
#include <mm/gtk/shortcutsgroup.hpp>
#include <mm/gtk/shortcutssection.hpp>
#include <mm/gtk/shortcutsshortcut.hpp>
#include <mm/gtk/shortcutswindow.hpp>
#include <mm/gtk/signallistitemfactory.hpp>
#include <mm/gtk/singleselection.hpp>
#include <mm/gtk/sizegroup.hpp>
#include <mm/gtk/slicelistmodel.hpp>
#include <mm/gtk/snapshot.hpp>
#include <mm/gtk/sortlistmodel.hpp>
#include <mm/gtk/spinbutton.hpp>
#include <mm/gtk/spinner.hpp>
#include <mm/gtk/stack.hpp>
#include <mm/gtk/stacksidebar.hpp>
#include <mm/gtk/stackswitcher.hpp>
#include <mm/gtk/statusbar.hpp>
#include <mm/gtk/stringfilter.hpp>
#include <mm/gtk/stringlist.hpp>
#include <mm/gtk/stringobject.hpp>
#include <mm/gtk/stringsorter.hpp>
#include <mm/gtk/stylecontext.hpp>
#include <mm/gtk/switch.hpp>
#include <mm/gtk/text.hpp>
#include <mm/gtk/textbuffer.hpp>
#include <mm/gtk/textchildanchor.hpp>
#include <mm/gtk/textiter.hpp>
#include <mm/gtk/textmark.hpp>
#include <mm/gtk/texttag.hpp>
#include <mm/gtk/texttagtable.hpp>
#include <mm/gtk/textview.hpp>
#include <mm/gtk/togglebutton.hpp>
#include <mm/gtk/tooltip.hpp>
#include <mm/gtk/treeexpander.hpp>
#include <mm/gtk/treelistmodel.hpp>
#include <mm/gtk/treemodel.hpp>
#include <mm/gtk/treemodelfilter.hpp>
#include <mm/gtk/treemodelsort.hpp>
#include <mm/gtk/treepath.hpp>
#include <mm/gtk/treerowreference.hpp>
#include <mm/gtk/treeselection.hpp>
#include <mm/gtk/treestore.hpp>
#include <mm/gtk/treeview.hpp>
#include <mm/gtk/treeviewcolumn.hpp>
#include <mm/gtk/version.hpp>
#include <mm/gtk/video.hpp>
#include <mm/gtk/viewport.hpp>
#include <mm/gtk/volumebutton.hpp>
#include <mm/gtk/widget.hpp>
#include <mm/gtk/widgetpaintable.hpp>
#include <mm/gtk/windowcontrols.hpp>
#include <mm/gtk/window.hpp>
#include <mm/gtk/windowhandle.hpp>

#endif /* #ifndef GTKMM_H */
