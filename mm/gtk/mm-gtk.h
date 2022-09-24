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

#include <mm/glib/mm-glib.h>
#include <mm/gio/gio.h>

#include <mm/gdk/mm-gdk.h>

#include <mm/gtk/object.h>
#include <mm/gtk/aboutdialog.h>
#include <mm/gtk/accelerator.h>
#include <mm/gtk/accelkey.h>
#include <mm/gtk/actionable.h>
#include <mm/gtk/actionbar.h>
#include <mm/gtk/adjustment.h>
#include <mm/gtk/appchooserbutton.h>
#include <mm/gtk/appchooserdialog.h>
#include <mm/gtk/appchooserwidget.h>
#include <mm/gtk/application.h>
#include <mm/gtk/applicationwindow.h>
#include <mm/gtk/aspectframe.h>
#include <mm/gtk/assistant.h>
#include <mm/gtk/binlayout.h>
#include <mm/gtk/boolfilter.h>
#include <mm/gtk/border.h>
#include <mm/gtk/box.h>
#include <mm/gtk/boxlayout.h>
#include <mm/gtk/builder.h>
#include <mm/gtk/button.h>
#include <mm/gtk/cellarea.h>
#include <mm/gtk/cellareabox.h>
#include <mm/gtk/cellareacontext.h>
#include <mm/gtk/cellview.h>
#include <mm/gtk/checkbutton.h>
#include <mm/gtk/cellrenderer.h>
#include <mm/gtk/cellrendereraccel.h>
#include <mm/gtk/cellrenderercombo.h>
#include <mm/gtk/cellrendererpixbuf.h>
#include <mm/gtk/cellrendererprogress.h>
#include <mm/gtk/cellrendererspin.h>
#include <mm/gtk/cellrendererspinner.h>
#include <mm/gtk/cellrenderertext.h>
#include <mm/gtk/cellrenderertoggle.h>
#include <mm/gtk/centerbox.h>
#include <mm/gtk/centerlayout.h>
#include <mm/gtk/colorbutton.h>
#include <mm/gtk/colorchooser.h>
#include <mm/gtk/colorchooserdialog.h>
#include <mm/gtk/columnview.h>
#include <mm/gtk/combobox.h>
#include <mm/gtk/comboboxtext.h>
#include <mm/gtk/constraintlayout.h>
#include <mm/gtk/cssprovider.h>
#include <mm/gtk/csssection.h>
#include <mm/gtk/dialog.h>
#include <mm/gtk/directorylist.h>
#include <mm/gtk/dragicon.h>
#include <mm/gtk/dragsource.h>
#include <mm/gtk/drawingarea.h>
#include <mm/gtk/dropcontrollermotion.h>
#include <mm/gtk/dropdown.h>
#include <mm/gtk/droptarget.h>
#include <mm/gtk/droptargetasync.h>
#include <mm/gtk/editablelabel.h>
#include <mm/gtk/emojichooser.h>
#include <mm/gtk/entry.h>
#include <mm/gtk/expander.h>
#include <mm/gtk/enums.h>
#include <mm/gtk/eventcontroller.h>
#include <mm/gtk/eventcontrollerfocus.h>
#include <mm/gtk/eventcontrollerkey.h>
#include <mm/gtk/eventcontrollermotion.h>
#include <mm/gtk/eventcontrollerscroll.h>
#include <mm/gtk/filechooser.h>
#include <mm/gtk/filechooserdialog.h>
#include <mm/gtk/filechoosernative.h>
#include <mm/gtk/filechooserwidget.h>
#include <mm/gtk/filefilter.h>
#include <mm/gtk/filterlistmodel.h>
#include <mm/gtk/fixed.h>
#include <mm/gtk/flattenlistmodel.h>
#include <mm/gtk/flowbox.h>
#include <mm/gtk/flowboxchild.h>
#include <mm/gtk/fontbutton.h>
#include <mm/gtk/fontchooser.h>
#include <mm/gtk/fontchooserdialog.h>
#include <mm/gtk/fontchooserwidget.h>
#include <mm/gtk/frame.h>
#include <mm/gtk/gesture.h>
#include <mm/gtk/gestureclick.h>
#include <mm/gtk/gesturedrag.h>
#include <mm/gtk/gesturelongpress.h>
#include <mm/gtk/gesturepan.h>
#include <mm/gtk/gesturerotate.h>
#include <mm/gtk/gesturesingle.h>
#include <mm/gtk/gesturestylus.h>
#include <mm/gtk/gestureswipe.h>
#include <mm/gtk/gesturezoom.h>
#include <mm/gtk/glarea.h>
#include <mm/gtk/grid.h>
#include <mm/gtk/gridlayout.h>
#include <mm/gtk/gridlayoutchild.h>
#include <mm/gtk/gridview.h>
#include <mm/gtk/headerbar.h>
#include <mm/gtk/icontheme.h>
#include <mm/gtk/iconview.h>
#include <mm/gtk/image.h>
#include <mm/gtk/infobar.h>
#include <mm/gtk/inscription.h>
#include <mm/gtk/calendar.h>
#include <mm/gtk/label.h>
#include <mm/gtk/layoutchild.h>
#include <mm/gtk/layoutmanager.h>
#include <mm/gtk/levelbar.h>
#include <mm/gtk/listbox.h>
#include <mm/gtk/listboxrow.h>
#include <mm/gtk/liststore.h>
#include <mm/gtk/listview.h>
#include <mm/gtk/listviewtext.h>
#include <mm/gtk/linkbutton.h>
#include <mm/gtk/mediacontrols.h>
#include <mm/gtk/mediafile.h>
#include <mm/gtk/menubutton.h>
#include <mm/gtk/messagedialog.h>
#include <mm/gtk/multifilter.h>
#include <mm/gtk/multiselection.h>
#include <mm/gtk/multisorter.h>
#include <mm/gtk/noselection.h>
#include <mm/gtk/notebook.h>
#include <mm/gtk/numericsorter.h>
#include <mm/gtk/object.h>
#include <mm/gtk/overlay.h>
#include <mm/gtk/padcontroller.h>
#include <mm/gtk/paned.h>
#include <mm/gtk/pagesetup.h>
#ifndef G_OS_WIN32
# include <mm/gtk/pagesetupunixdialog.h>
#endif
#include <mm/gtk/papersize.h>
#include <mm/gtk/passwordentry.h>
#include <mm/gtk/picture.h>
#include <mm/gtk/popover.h>
#include <mm/gtk/popovermenu.h>
#include <mm/gtk/popovermenubar.h>
#include <mm/gtk/printcontext.h>
#ifndef G_OS_WIN32
# include <mm/gtk/printer.h>
# include <mm/gtk/printjob.h>
#endif
#include <mm/gtk/printoperation.h>
#include <mm/gtk/printoperationpreview.h>
#include <mm/gtk/printsettings.h>
#ifndef G_OS_WIN32
# include <mm/gtk/printunixdialog.h>
#endif
#include <mm/gtk/progressbar.h>
#include <mm/gtk/range.h>
#include <mm/gtk/recentinfo.h>
#include <mm/gtk/recentmanager.h>
#include <mm/gtk/revealer.h>
#include <mm/gtk/scale.h>
#include <mm/gtk/scalebutton.h>
#include <mm/gtk/scrollbar.h>
#include <mm/gtk/scrolledwindow.h>
#include <mm/gtk/searchbar.h>
#include <mm/gtk/searchentry.h>
#include <mm/gtk/separator.h>
#include <mm/gtk/selectionfiltermodel.h>
#include <mm/gtk/selectionlistmodelimpl.h>
#include <mm/gtk/settings.h>
#include <mm/gtk/shortcutcontroller.h>
#include <mm/gtk/shortcutlabel.h>
#include <mm/gtk/shortcutsgroup.h>
#include <mm/gtk/shortcutssection.h>
#include <mm/gtk/shortcutsshortcut.h>
#include <mm/gtk/shortcutswindow.h>
#include <mm/gtk/signallistitemfactory.h>
#include <mm/gtk/singleselection.h>
#include <mm/gtk/sizegroup.h>
#include <mm/gtk/slicelistmodel.h>
#include <mm/gtk/snapshot.h>
#include <mm/gtk/sortlistmodel.h>
#include <mm/gtk/spinbutton.h>
#include <mm/gtk/spinner.h>
#include <mm/gtk/stack.h>
#include <mm/gtk/stacksidebar.h>
#include <mm/gtk/stackswitcher.h>
#include <mm/gtk/statusbar.h>
#include <mm/gtk/stringfilter.h>
#include <mm/gtk/stringlist.h>
#include <mm/gtk/stringobject.h>
#include <mm/gtk/stringsorter.h>
#include <mm/gtk/stylecontext.h>
#include <mm/gtk/switch.h>
#include <mm/gtk/text.h>
#include <mm/gtk/textbuffer.h>
#include <mm/gtk/textchildanchor.h>
#include <mm/gtk/textiter.h>
#include <mm/gtk/textmark.h>
#include <mm/gtk/texttag.h>
#include <mm/gtk/texttagtable.h>
#include <mm/gtk/textview.h>
#include <mm/gtk/togglebutton.h>
#include <mm/gtk/tooltip.h>
#include <mm/gtk/treeexpander.h>
#include <mm/gtk/treelistmodel.h>
#include <mm/gtk/treemodel.h>
#include <mm/gtk/treemodelfilter.h>
#include <mm/gtk/treemodelsort.h>
#include <mm/gtk/treepath.h>
#include <mm/gtk/treerowreference.h>
#include <mm/gtk/treeselection.h>
#include <mm/gtk/treestore.h>
#include <mm/gtk/treeview.h>
#include <mm/gtk/treeviewcolumn.h>
#include <mm/gtk/version.h>
#include <mm/gtk/video.h>
#include <mm/gtk/viewport.h>
#include <mm/gtk/volumebutton.h>
#include <mm/gtk/widget.h>
#include <mm/gtk/widgetpaintable.h>
#include <mm/gtk/windowcontrols.h>
#include <mm/gtk/window.h>
#include <mm/gtk/windowhandle.h>

#endif /* #ifndef GTKMM_H */
