#ifndef _GTKMM_CELLRENDERER_GENERATION_H
#define _GTKMM_CELLRENDERER_GENERATION_H

#include <libmm-gtk/cellrendereraccel.hxx>
#include <libmm-gtk/cellrendererpixbuf.hxx>
#include <libmm-gtk/cellrenderertext.hxx>
#include <libmm-gtk/cellrenderertoggle.hxx>

namespace Gtk::CellRenderer_Generation
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
  GTKMM_API auto
  generate_cellrenderer<bool> (bool editable) -> CellRenderer*;

  template <>
  GTKMM_API auto
  generate_cellrenderer<Glib::RefPtr<Gdk::Pixbuf>> (bool editable) -> CellRenderer*;

  template <>
  GTKMM_API auto
  generate_cellrenderer<AccelKey> (bool editable) -> CellRenderer*;

#endif

} // namespace Gtk::CellRenderer_Generation

#endif
