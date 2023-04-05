// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#include <libmm/gtk/mm-gtkconfig.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/cellview.hxx>
  #include <libmm/gtk/cellview_p.hxx>

  #include <gtk/gtk.h>
  #include <libmm/gtk/cellrendererpixbuf.hxx>
  #include <libmm/gtk/cellrenderertext.hxx>

namespace gtk
{

  CellView::CellView (const glib::ustring& text, bool use_markup)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (cellview_class_.init ()))
  {
    auto cell = gtk::manage (new gtk::CellRendererText ());

    if (use_markup)
    {
      cell->property_markup () = text;
    }
    else
    {
      cell->property_text () = text;
    }

    pack_start (*cell);
  }

  CellView::CellView (const glib::RefPtr<gdk::Texture>& texture)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (cellview_class_.init ()))
  {
    auto cell = gtk::manage (new gtk::CellRendererPixbuf ());

    cell->property_texture () = texture;

    pack_start (*cell);
  }

  auto
  CellView::unset_model () -> void
  {
    gtk_cell_view_set_model (gobj (), nullptr);
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkCellView* object, bool take_copy) -> gtk::CellView*
  {
    return dynamic_cast<gtk::CellView*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  CellView_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &CellView_Class::class_init_function;

      register_derived_type (gtk_cell_view_get_type ());

      CellLayout::add_interface (get_type ());
      Orientable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  CellView_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  CellView_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new CellView ((GtkCellView*) (o)));
  }

  CellView::CellView (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  CellView::CellView (GtkCellView* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  CellView::CellView (CellView&& src) noexcept
    : gtk::Widget (std::move (src)),
      CellLayout (std::move (src)),
      Orientable (std::move (src))
  {
  }

  auto
  CellView::operator= (CellView&& src) noexcept -> CellView&
  {
    gtk::Widget::operator= (std::move (src));
    CellLayout::operator= (std::move (src));
    Orientable::operator= (std::move (src));
    return *this;
  }

  CellView::~CellView () noexcept
  {
    destroy_ ();
  }

  CellView::CppClassType CellView::cellview_class_;

  auto
  CellView::get_type () -> GType
  {
    return cellview_class_.init ().get_type ();
  }

  auto
  CellView::get_base_type () -> GType
  {
    return gtk_cell_view_get_type ();
  }

  CellView::CellView ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (cellview_class_.init ()))
  {
  }

  auto
  CellView::set_model (const glib::RefPtr<TreeModel>& model) -> void
  {
    gtk_cell_view_set_model (gobj (), glib::unwrap (model));
  }

  auto
  CellView::get_model () -> glib::RefPtr<TreeModel>
  {
    auto retvalue = glib::wrap (gtk_cell_view_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  CellView::get_model () const -> glib::RefPtr<const TreeModel>
  {
    return const_cast<CellView*> (this)->get_model ();
  }

  auto
  CellView::set_displayed_row (const TreeModel::Path& path) -> void
  {
    gtk_cell_view_set_displayed_row (gobj (),
                                     const_cast<GtkTreePath*> ((path).gobj ()));
  }

  auto
  CellView::get_displayed_row () const -> TreeModel::Path
  {
    return gtk::TreePath (
        gtk_cell_view_get_displayed_row (const_cast<GtkCellView*> (gobj ())),
        false);
  }

  auto
  CellView::get_draw_sensitive () const -> bool
  {
    return gtk_cell_view_get_draw_sensitive (
        const_cast<GtkCellView*> (gobj ()));
  }

  auto
  CellView::set_draw_sensitive (bool draw_sensitive) -> void
  {
    gtk_cell_view_set_draw_sensitive (gobj (),
                                      static_cast<int> (draw_sensitive));
  }

  auto
  CellView::get_fit_model () const -> bool
  {
    return gtk_cell_view_get_fit_model (const_cast<GtkCellView*> (gobj ()));
  }

  auto
  CellView::set_fit_model (bool fit_model) -> void
  {
    gtk_cell_view_set_fit_model (gobj (), static_cast<int> (fit_model));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<TreeModel>>::value,
      "Type glib::RefPtr<TreeModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CellView::property_model () -> glib::PropertyProxy<glib::RefPtr<TreeModel>>
  {
    return glib::PropertyProxy<glib::RefPtr<TreeModel>> (this, "model");
  }

  auto
  CellView::property_model () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<TreeModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<TreeModel>> (this,
                                                                  "model");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<CellArea>>::value,
      "Type glib::RefPtr<CellArea> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CellView::property_cell_area () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<CellArea>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<CellArea>> (this,
                                                                 "cell-area");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<CellAreaContext>>::value,
      "Type glib::RefPtr<CellAreaContext> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CellView::property_cell_area_context () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<CellAreaContext>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<CellAreaContext>> (
        this,
        "cell-area-context");
  }

  auto
  CellView::property_draw_sensitive () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "draw-sensitive");
  }

  auto
  CellView::property_draw_sensitive () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "draw-sensitive");
  }

  auto
  CellView::property_fit_model () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "fit-model");
  }

  auto
  CellView::property_fit_model () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "fit-model");
  }

} // namespace gtk

#endif
