// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/gtk/cellrenderer_generation.hxx>

namespace gtk
{

  namespace CellRenderer_Generation
  {

    template <>
    auto
    generate_cellrenderer<glib::RefPtr<gdk::Pixbuf>> (bool) -> CellRenderer*
    {
      return new CellRendererPixbuf ();
    }

    template <>
    auto
    generate_cellrenderer<bool> (bool editable) -> CellRenderer*
    {
      CellRendererToggle* pCellRenderer = new CellRendererToggle ();

      pCellRenderer->property_activatable () = editable;

      return pCellRenderer;
    }

    template <>
    auto
    generate_cellrenderer<AccelKey> (bool editable) -> CellRenderer*
    {
      CellRendererAccel* pCellRenderer = new CellRendererAccel ();

      pCellRenderer->property_editable () = editable;

      return pCellRenderer;
    }

  } // namespace CellRenderer_Generation

} // namespace gtk

#endif
