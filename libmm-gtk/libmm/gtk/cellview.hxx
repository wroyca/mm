// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CELLVIEW_H
#define _GTKMM_CELLVIEW_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gdk/texture.hxx>
  #include <libmm/gtk/cellarea.hxx>
  #include <libmm/gtk/cellareacontext.hxx>
  #include <libmm/gtk/celllayout.hxx>
  #include <libmm/gtk/cellrenderer.hxx>
  #include <libmm/gtk/orientable.hxx>
  #include <libmm/gtk/treemodel.hxx>
  #include <libmm/gtk/treepath.hxx>
  #include <libmm/gtk/widget.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellView = struct _GtkCellView;
using GtkCellViewClass = struct _GtkCellViewClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT CellView_Class;
}
  #endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT CellView : public Widget,
                             public CellLayout,
                             public Orientable
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef CellView CppObjectType;
    typedef CellView_Class CppClassType;
    typedef GtkCellView BaseObjectType;
    typedef GtkCellViewClass BaseClassType;
  #endif

    CellView (CellView&& src) noexcept;
    auto
    operator= (CellView&& src) noexcept -> CellView&;

    CellView (const CellView&) = delete;
    auto
    operator= (const CellView&) -> CellView& = delete;

    ~CellView () noexcept override;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class CellView_Class;
    static CppClassType cellview_class_;

  protected:
    explicit CellView (const glib::ConstructParams& construct_params);
    explicit CellView (GtkCellView* castitem);

  #endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkCellView*
    {
      return reinterpret_cast<GtkCellView*> (gobject_);
    }

    auto
    gobj () const -> const GtkCellView*
    {
      return reinterpret_cast<GtkCellView*> (gobject_);
    }

  private:
  public:
    CellView ();

    explicit CellView (const glib::ustring& text, bool use_markup = false);

    explicit CellView (const glib::RefPtr<gdk::Texture>& texture);

    auto
    set_model (const glib::RefPtr<TreeModel>& model) -> void;

    auto
    unset_model () -> void;

    auto
    get_model () -> glib::RefPtr<TreeModel>;

    auto
    get_model () const -> glib::RefPtr<const TreeModel>;

    auto
    set_displayed_row (const TreeModel::Path& path) -> void;

    auto
    get_displayed_row () const -> TreeModel::Path;

    auto
    get_draw_sensitive () const -> bool;

    auto
    set_draw_sensitive (bool draw_sensitive = true) -> void;

    auto
    get_fit_model () const -> bool;

    auto
    set_fit_model (bool fit_model = true) -> void;

    auto
    property_model () -> glib::PropertyProxy<glib::RefPtr<TreeModel>>;

    auto
    property_model () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<TreeModel>>;

    auto
    property_cell_area () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<CellArea>>;

    auto
    property_cell_area_context () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<CellAreaContext>>;

    auto
    property_draw_sensitive () -> glib::PropertyProxy<bool>;

    auto
    property_draw_sensitive () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_fit_model () -> glib::PropertyProxy<bool>;

    auto
    property_fit_model () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkCellView* object, bool take_copy = false) -> gtk::CellView*;
} // namespace glib

#endif

#endif
