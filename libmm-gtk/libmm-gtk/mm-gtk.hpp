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

#include <libmm-glib/mm-glib.hxx>
#include <libmm-gio/gio.hxx>

#include <libmm-gdk/mm-gdk.hxx>

#include <libmm-gtk/object.hxx>
#include <libmm-gtk/aboutdialog.hxx>
#include <libmm-gtk/accelerator.hxx>
#include <libmm-gtk/accelkey.hxx>
#include <libmm-gtk/actionable.hxx>
#include <libmm-gtk/actionbar.hxx>
#include <libmm-gtk/adjustment.hxx>
#include <libmm-gtk/appchooserbutton.hxx>
#include <libmm-gtk/appchooserdialog.hxx>
#include <libmm-gtk/appchooserwidget.hxx>
#include <libmm-gtk/application.hxx>
#include <libmm-gtk/applicationwindow.hxx>
#include <libmm-gtk/aspectframe.hxx>
#include <libmm-gtk/assistant.hxx>
#include <libmm-gtk/binlayout.hxx>
#include <libmm-gtk/boolfilter.hxx>
#include <libmm-gtk/border.hxx>
#include <libmm-gtk/box.hxx>
#include <libmm-gtk/boxlayout.hxx>
#include <libmm-gtk/builder.hxx>
#include <libmm-gtk/button.hxx>
#include <libmm-gtk/cellarea.hxx>
#include <libmm-gtk/cellareabox.hxx>
#include <libmm-gtk/cellareacontext.hxx>
#include <libmm-gtk/cellview.hxx>
#include <libmm-gtk/checkbutton.hxx>
#include <libmm-gtk/cellrenderer.hxx>
#include <libmm-gtk/cellrendereraccel.hxx>
#include <libmm-gtk/cellrenderercombo.hxx>
#include <libmm-gtk/cellrendererpixbuf.hxx>
#include <libmm-gtk/cellrendererprogress.hxx>
#include <libmm-gtk/cellrendererspin.hxx>
#include <libmm-gtk/cellrendererspinner.hxx>
#include <libmm-gtk/cellrenderertext.hxx>
#include <libmm-gtk/cellrenderertoggle.hxx>
#include <libmm-gtk/centerbox.hxx>
#include <libmm-gtk/centerlayout.hxx>
#include <libmm-gtk/colorbutton.hxx>
#include <libmm-gtk/colorchooser.hxx>
#include <libmm-gtk/colorchooserdialog.hxx>
#include <libmm-gtk/columnview.hxx>
#include <libmm-gtk/combobox.hxx>
#include <libmm-gtk/comboboxtext.hxx>
#include <libmm-gtk/constraintlayout.hxx>
#include <libmm-gtk/cssprovider.hxx>
#include <libmm-gtk/csssection.hxx>
#include <libmm-gtk/dialog.hxx>
#include <libmm-gtk/directorylist.hxx>
#include <libmm-gtk/dragicon.hxx>
#include <libmm-gtk/dragsource.hxx>
#include <libmm-gtk/drawingarea.hxx>
#include <libmm-gtk/dropcontrollermotion.hxx>
#include <libmm-gtk/dropdown.hxx>
#include <libmm-gtk/droptarget.hxx>
#include <libmm-gtk/droptargetasync.hxx>
#include <libmm-gtk/editablelabel.hxx>
#include <libmm-gtk/emojichooser.hxx>
#include <libmm-gtk/entry.hxx>
#include <libmm-gtk/expander.hxx>
#include <libmm-gtk/enums.hxx>
#include <libmm-gtk/eventcontroller.hxx>
#include <libmm-gtk/eventcontrollerfocus.hxx>
#include <libmm-gtk/eventcontrollerkey.hxx>
#include <libmm-gtk/eventcontrollermotion.hxx>
#include <libmm-gtk/eventcontrollerscroll.hxx>
#include <libmm-gtk/filechooser.hxx>
#include <libmm-gtk/filechooserdialog.hxx>
#include <libmm-gtk/filechoosernative.hxx>
#include <libmm-gtk/filechooserwidget.hxx>
#include <libmm-gtk/filefilter.hxx>
#include <libmm-gtk/filterlistmodel.hxx>
#include <libmm-gtk/fixed.hxx>
#include <libmm-gtk/flattenlistmodel.hxx>
#include <libmm-gtk/flowbox.hxx>
#include <libmm-gtk/flowboxchild.hxx>
#include <libmm-gtk/fontbutton.hxx>
#include <libmm-gtk/fontchooser.hxx>
#include <libmm-gtk/fontchooserdialog.hxx>
#include <libmm-gtk/fontchooserwidget.hxx>
#include <libmm-gtk/frame.hxx>
#include <libmm-gtk/gesture.hxx>
#include <libmm-gtk/gestureclick.hxx>
#include <libmm-gtk/gesturedrag.hxx>
#include <libmm-gtk/gesturelongpress.hxx>
#include <libmm-gtk/gesturepan.hxx>
#include <libmm-gtk/gesturerotate.hxx>
#include <libmm-gtk/gesturesingle.hxx>
#include <libmm-gtk/gesturestylus.hxx>
#include <libmm-gtk/gestureswipe.hxx>
#include <libmm-gtk/gesturezoom.hxx>
#include <libmm-gtk/glarea.hxx>
#include <libmm-gtk/grid.hxx>
#include <libmm-gtk/gridlayout.hxx>
#include <libmm-gtk/gridlayoutchild.hxx>
#include <libmm-gtk/gridview.hxx>
#include <libmm-gtk/headerbar.hxx>
#include <libmm-gtk/icontheme.hxx>
#include <libmm-gtk/iconview.hxx>
#include <libmm-gtk/image.hxx>
#include <libmm-gtk/infobar.hxx>
#include <libmm-gtk/inscription.hxx>
#include <libmm-gtk/calendar.hxx>
#include <libmm-gtk/label.hxx>
#include <libmm-gtk/layoutchild.hxx>
#include <libmm-gtk/layoutmanager.hxx>
#include <libmm-gtk/levelbar.hxx>
#include <libmm-gtk/listbox.hxx>
#include <libmm-gtk/listboxrow.hxx>
#include <libmm-gtk/liststore.hxx>
#include <libmm-gtk/listview.hxx>
#include <libmm-gtk/listviewtext.hxx>
#include <libmm-gtk/linkbutton.hxx>
#include <libmm-gtk/mediacontrols.hxx>
#include <libmm-gtk/mediafile.hxx>
#include <libmm-gtk/menubutton.hxx>
#include <libmm-gtk/messagedialog.hxx>
#include <libmm-gtk/multifilter.hxx>
#include <libmm-gtk/multiselection.hxx>
#include <libmm-gtk/multisorter.hxx>
#include <libmm-gtk/noselection.hxx>
#include <libmm-gtk/notebook.hxx>
#include <libmm-gtk/numericsorter.hxx>
#include <libmm-gtk/object.hxx>
#include <libmm-gtk/overlay.hxx>
#include <libmm-gtk/padcontroller.hxx>
#include <libmm-gtk/paned.hxx>
#include <libmm-gtk/pagesetup.hxx>
#ifndef G_OS_WIN32
#include <libmm-gtk/pagesetupunixdialog.hxx>
#endif
#include <libmm-gtk/papersize.hxx>
#include <libmm-gtk/passwordentry.hxx>
#include <libmm-gtk/picture.hxx>
#include <libmm-gtk/popover.hxx>
#include <libmm-gtk/popovermenu.hxx>
#include <libmm-gtk/popovermenubar.hxx>
#include <libmm-gtk/printcontext.hxx>
#ifndef G_OS_WIN32
#include <libmm-gtk/printer.hxx>
#include <libmm-gtk/printjob.hxx>
#endif
#include <libmm-gtk/printoperation.hxx>
#include <libmm-gtk/printoperationpreview.hxx>
#include <libmm-gtk/printsettings.hxx>
#ifndef G_OS_WIN32
#include <libmm-gtk/printunixdialog.hxx>
#endif
#include <libmm-gtk/progressbar.hxx>
#include <libmm-gtk/range.hxx>
#include <libmm-gtk/recentinfo.hxx>
#include <libmm-gtk/recentmanager.hxx>
#include <libmm-gtk/revealer.hxx>
#include <libmm-gtk/scale.hxx>
#include <libmm-gtk/scalebutton.hxx>
#include <libmm-gtk/scrollbar.hxx>
#include <libmm-gtk/scrolledwindow.hxx>
#include <libmm-gtk/searchbar.hxx>
#include <libmm-gtk/searchentry.hxx>
#include <libmm-gtk/separator.hxx>
#include <libmm-gtk/selectionfiltermodel.hxx>
#include <libmm-gtk/selectionlistmodelimpl.hxx>
#include <libmm-gtk/settings.hxx>
#include <libmm-gtk/shortcutcontroller.hxx>
#include <libmm-gtk/shortcutlabel.hxx>
#include <libmm-gtk/shortcutsgroup.hxx>
#include <libmm-gtk/shortcutssection.hxx>
#include <libmm-gtk/shortcutsshortcut.hxx>
#include <libmm-gtk/shortcutswindow.hxx>
#include <libmm-gtk/signallistitemfactory.hxx>
#include <libmm-gtk/singleselection.hxx>
#include <libmm-gtk/sizegroup.hxx>
#include <libmm-gtk/slicelistmodel.hxx>
#include <libmm-gtk/snapshot.hxx>
#include <libmm-gtk/sortlistmodel.hxx>
#include <libmm-gtk/spinbutton.hxx>
#include <libmm-gtk/spinner.hxx>
#include <libmm-gtk/stack.hxx>
#include <libmm-gtk/stacksidebar.hxx>
#include <libmm-gtk/stackswitcher.hxx>
#include <libmm-gtk/statusbar.hxx>
#include <libmm-gtk/stringfilter.hxx>
#include <libmm-gtk/stringlist.hxx>
#include <libmm-gtk/stringobject.hxx>
#include <libmm-gtk/stringsorter.hxx>
#include <libmm-gtk/stylecontext.hxx>
#include <libmm-gtk/switch.hxx>
#include <libmm-gtk/text.hxx>
#include <libmm-gtk/textbuffer.hxx>
#include <libmm-gtk/textchildanchor.hxx>
#include <libmm-gtk/textiter.hxx>
#include <libmm-gtk/textmark.hxx>
#include <libmm-gtk/texttag.hxx>
#include <libmm-gtk/texttagtable.hxx>
#include <libmm-gtk/textview.hxx>
#include <libmm-gtk/togglebutton.hxx>
#include <libmm-gtk/tooltip.hxx>
#include <libmm-gtk/treeexpander.hxx>
#include <libmm-gtk/treelistmodel.hxx>
#include <libmm-gtk/treemodel.hxx>
#include <libmm-gtk/treemodelfilter.hxx>
#include <libmm-gtk/treemodelsort.hxx>
#include <libmm-gtk/treepath.hxx>
#include <libmm-gtk/treerowreference.hxx>
#include <libmm-gtk/treeselection.hxx>
#include <libmm-gtk/treestore.hxx>
#include <libmm-gtk/treeview.hxx>
#include <libmm-gtk/treeviewcolumn.hxx>
#include <libmm-gtk/version.hxx>
#include <libmm-gtk/video.hxx>
#include <libmm-gtk/viewport.hxx>
#include <libmm-gtk/volumebutton.hxx>
#include <libmm-gtk/widget.hxx>
#include <libmm-gtk/widgetpaintable.hxx>
#include <libmm-gtk/windowcontrols.hxx>
#include <libmm-gtk/window.hxx>
#include <libmm-gtk/windowhandle.hxx>

#endif /* #ifndef GTKMM_H */
