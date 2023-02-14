
#ifndef _GTKMM_CELLVIEW_H
#define _GTKMM_CELLVIEW_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/texture.hxx>
#include <libmm-gtk/cellarea.hxx>
#include <libmm-gtk/cellareacontext.hxx>
#include <libmm-gtk/celllayout.hxx>
#include <libmm-gtk/cellrenderer.hxx>
#include <libmm-gtk/orientable.hxx>
#include <libmm-gtk/treemodel.hxx>
#include <libmm-gtk/treepath.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellView = struct _GtkCellView;
using GtkCellViewClass = struct _GtkCellViewClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API CellView_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API CellView : public Widget,
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
    friend GTKMM_API class CellView_Class;
    static CppClassType cellview_class_;

  protected:
    explicit CellView (const Glib::ConstructParams& construct_params);
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

    explicit CellView (const Glib::ustring& text, bool use_markup = false);

    explicit CellView (const Glib::RefPtr<Gdk::Texture>& texture);

    void
    set_model (const Glib::RefPtr<TreeModel>& model);

    void
    unset_model ();

    auto
    get_model () -> Glib::RefPtr<TreeModel>;

    auto
    get_model () const -> Glib::RefPtr<const TreeModel>;

    void
    set_displayed_row (const TreeModel::Path& path);

    auto
    get_displayed_row () const -> TreeModel::Path;

    auto
    get_draw_sensitive () const -> bool;

    void
    set_draw_sensitive (bool draw_sensitive = true);

    auto
    get_fit_model () const -> bool;

    void
    set_fit_model (bool fit_model = true);

    auto
    property_model () -> Glib::PropertyProxy<Glib::RefPtr<TreeModel>>;

    auto
    property_model () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<TreeModel>>;

    auto
    property_cell_area () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<CellArea>>;

    auto
    property_cell_area_context () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<CellAreaContext>>;

    auto
    property_draw_sensitive () -> Glib::PropertyProxy<bool>;

    auto
    property_draw_sensitive () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_fit_model () -> Glib::PropertyProxy<bool>;

    auto
    property_fit_model () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkCellView* object, bool take_copy = false) -> Gtk::CellView*;
} // namespace Glib

#endif
