// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-gtk/cellrenderer_generation.hxx>

namespace Gtk::CellRenderer_Generation
{

  template <>
  auto
  generate_cellrenderer<Glib::RefPtr<Gdk::Pixbuf>> (bool) -> CellRenderer*
  {
    return new CellRendererPixbuf ();
  }

  template <>
  auto
  generate_cellrenderer<bool> (const bool editable) -> CellRenderer*
  {
    CellRendererToggle* pCellRenderer = new CellRendererToggle ();

    pCellRenderer->property_activatable () = editable;

    return pCellRenderer;
  }

  template <>
  auto
  generate_cellrenderer<AccelKey> (const bool editable) -> CellRenderer*
  {
    CellRendererAccel* pCellRenderer = new CellRendererAccel ();

    pCellRenderer->property_editable () = editable;

    return pCellRenderer;
  }

} // namespace Gtk::CellRenderer_Generation
