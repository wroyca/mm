// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#include <libmm-gtk/mm-gtkconfig.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/mm-glib.hxx>

  #include <libmm-gtk/cellview.hxx>
  #include <libmm-gtk/cellview_p.hxx>

  #include <gtk/gtk.h>
  #include <libmm-gtk/cellrendererpixbuf.hxx>
  #include <libmm-gtk/cellrenderertext.hxx>

namespace Gtk
{

  CellView::CellView (const Glib::ustring& text, bool use_markup)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (cellview_class_.init ()))
  {
    auto cell = Gtk::manage (new Gtk::CellRendererText ());

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

  CellView::CellView (const Glib::RefPtr<Gdk::Texture>& texture)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (cellview_class_.init ()))
  {
    auto cell = Gtk::manage (new Gtk::CellRendererPixbuf ());

    cell->property_texture () = texture;

    pack_start (*cell);
  }

  auto
  CellView::unset_model () -> void
  {
    gtk_cell_view_set_model (gobj (), nullptr);
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkCellView* object, bool take_copy) -> Gtk::CellView*
  {
    return dynamic_cast<Gtk::CellView*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  CellView_Class::init () -> const Glib::Class&
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
  CellView_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new CellView ((GtkCellView*) (o)));
  }

  CellView::CellView (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  CellView::CellView (GtkCellView* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  CellView::CellView (CellView&& src) noexcept
    : Gtk::Widget (std::move (src)),
      CellLayout (std::move (src)),
      Orientable (std::move (src))
  {
  }

  auto
  CellView::operator= (CellView&& src) noexcept -> CellView&
  {
    Gtk::Widget::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (cellview_class_.init ()))
  {
  }

  auto
  CellView::set_model (const Glib::RefPtr<TreeModel>& model) -> void
  {
    gtk_cell_view_set_model (gobj (), Glib::unwrap (model));
  }

  auto
  CellView::get_model () -> Glib::RefPtr<TreeModel>
  {
    auto retvalue = Glib::wrap (gtk_cell_view_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  CellView::get_model () const -> Glib::RefPtr<const TreeModel>
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
    return Gtk::TreePath (
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
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<TreeModel>>::value,
      "Type Glib::RefPtr<TreeModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  CellView::property_model () -> Glib::PropertyProxy<Glib::RefPtr<TreeModel>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<TreeModel>> (this, "model");
  }

  auto
  CellView::property_model () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<TreeModel>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<TreeModel>> (this,
                                                                  "model");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<CellArea>>::value,
      "Type Glib::RefPtr<CellArea> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  CellView::property_cell_area () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<CellArea>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<CellArea>> (this,
                                                                 "cell-area");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<CellAreaContext>>::value,
      "Type Glib::RefPtr<CellAreaContext> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  CellView::property_cell_area_context () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<CellAreaContext>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<CellAreaContext>> (
        this,
        "cell-area-context");
  }

  auto
  CellView::property_draw_sensitive () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "draw-sensitive");
  }

  auto
  CellView::property_draw_sensitive () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "draw-sensitive");
  }

  auto
  CellView::property_fit_model () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "fit-model");
  }

  auto
  CellView::property_fit_model () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "fit-model");
  }

} // namespace Gtk

#endif
