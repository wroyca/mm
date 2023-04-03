// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CELLRENDERER_GENERATION_H
#define _GTKMM_CELLRENDERER_GENERATION_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/gtk/cellrendereraccel.hxx>
  #include <libmm/gtk/cellrendererpixbuf.hxx>
  #include <libmm/gtk/cellrenderertext.hxx>
  #include <libmm/gtk/cellrenderertoggle.hxx>

namespace Gtk
{

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
  namespace CellRenderer_Generation
  {

    template <class T_ModelColumnType>
    auto
    generate_cellrenderer (bool editable = false) -> CellRenderer*
    {
      auto cell_renderer = new CellRendererText ();

      cell_renderer->property_editable () = editable;

      return cell_renderer;
    }

    #if !defined(__GNUC__) || __GNUC__ > 2

    template <>
    LIBMM_GTK_SYMEXPORT auto
    generate_cellrenderer<bool> (bool editable) -> CellRenderer*;

    template <>
    LIBMM_GTK_SYMEXPORT auto
    generate_cellrenderer<Glib::RefPtr<Gdk::Pixbuf>> (bool editable)
        -> CellRenderer*;

    template <>
    LIBMM_GTK_SYMEXPORT auto
    generate_cellrenderer<AccelKey> (bool editable) -> CellRenderer*;

    #endif

  } // namespace CellRenderer_Generation
  #endif

} // namespace Gtk

#endif

#endif
