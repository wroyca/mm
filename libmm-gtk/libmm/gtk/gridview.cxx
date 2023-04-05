// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/gridview.hxx>
#include <libmm/gtk/gridview_p.hxx>

#include <gtk/gtk.h>

namespace
{

  static auto
  GridView_signal_activate_callback (GtkGridView* self, guint p0, void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (guint)>;

    auto obj = dynamic_cast<GridView*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo GridView_signal_activate_info = {
      "activate",
      (GCallback) &GridView_signal_activate_callback,
      (GCallback) &GridView_signal_activate_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkGridView* object, bool take_copy) -> gtk::GridView*
  {
    return dynamic_cast<gtk::GridView*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  GridView_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &GridView_Class::class_init_function;

      register_derived_type (gtk_grid_view_get_type ());
    }

    return *this;
  }

  auto
  GridView_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  GridView_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new GridView ((GtkGridView*) (o)));
  }

  GridView::GridView (const glib::ConstructParams& construct_params)
    : ListBase (construct_params)
  {
  }

  GridView::GridView (GtkGridView* castitem)
    : ListBase ((GtkListBase*) (castitem))
  {
  }

  GridView::GridView (GridView&& src) noexcept
    : ListBase (std::move (src))
  {
  }

  auto
  GridView::operator= (GridView&& src) noexcept -> GridView&
  {
    ListBase::operator= (std::move (src));
    return *this;
  }

  GridView::~GridView () noexcept
  {
    destroy_ ();
  }

  GridView::CppClassType GridView::gridview_class_;

  auto
  GridView::get_type () -> GType
  {
    return gridview_class_.init ().get_type ();
  }

  auto
  GridView::get_base_type () -> GType
  {
    return gtk_grid_view_get_type ();
  }

  GridView::GridView (const glib::RefPtr<SelectionModel>& model,
                      const glib::RefPtr<ListItemFactory>& factory)
    : glib::ObjectBase (nullptr),
      ListBase (glib::ConstructParams (gridview_class_.init (),
                                       "model",
                                       glib::unwrap (model),
                                       "factory",
                                       glib::unwrap (factory),
                                       nullptr))
  {
  }

  auto
  GridView::get_model () -> glib::RefPtr<SelectionModel>
  {
    auto retvalue = glib::wrap (gtk_grid_view_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  GridView::get_model () const -> glib::RefPtr<const SelectionModel>
  {
    return const_cast<GridView*> (this)->get_model ();
  }

  auto
  GridView::set_model (const glib::RefPtr<SelectionModel>& model) -> void
  {
    gtk_grid_view_set_model (gobj (), glib::unwrap (model));
  }

  auto
  GridView::set_factory (const glib::RefPtr<ListItemFactory>& factory) -> void
  {
    gtk_grid_view_set_factory (gobj (), glib::unwrap (factory));
  }

  auto
  GridView::get_factory () -> glib::RefPtr<ListItemFactory>
  {
    auto retvalue = glib::wrap (gtk_grid_view_get_factory (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  GridView::get_factory () const -> glib::RefPtr<const ListItemFactory>
  {
    return const_cast<GridView*> (this)->get_factory ();
  }

  auto
  GridView::get_min_columns () const -> guint
  {
    return gtk_grid_view_get_min_columns (const_cast<GtkGridView*> (gobj ()));
  }

  auto
  GridView::set_min_columns (guint min_columns) -> void
  {
    gtk_grid_view_set_min_columns (gobj (), min_columns);
  }

  auto
  GridView::get_max_columns () const -> guint
  {
    return gtk_grid_view_get_max_columns (const_cast<GtkGridView*> (gobj ()));
  }

  auto
  GridView::set_max_columns (guint max_columns) -> void
  {
    gtk_grid_view_set_max_columns (gobj (), max_columns);
  }

  auto
  GridView::set_enable_rubberband (bool enable_rubberband) -> void
  {
    gtk_grid_view_set_enable_rubberband (gobj (),
                                         static_cast<int> (enable_rubberband));
  }

  auto
  GridView::get_enable_rubberband () const -> bool
  {
    return gtk_grid_view_get_enable_rubberband (
        const_cast<GtkGridView*> (gobj ()));
  }

  auto
  GridView::set_single_click_activate (bool single_click_activate) -> void
  {
    gtk_grid_view_set_single_click_activate (
        gobj (),
        static_cast<int> (single_click_activate));
  }

  auto
  GridView::get_single_click_activate () const -> bool
  {
    return gtk_grid_view_get_single_click_activate (
        const_cast<GtkGridView*> (gobj ()));
  }

  auto
  GridView::signal_activate () -> glib::SignalProxy<void (guint)>
  {
    return glib::SignalProxy<void (guint)> (this,
                                            &GridView_signal_activate_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<ListItemFactory>>::value,
      "Type glib::RefPtr<ListItemFactory> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  GridView::property_factory () -> glib::PropertyProxy<glib::RefPtr<ListItemFactory>>
  {
    return glib::PropertyProxy<glib::RefPtr<ListItemFactory>> (this, "factory");
  }

  auto
  GridView::property_factory () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ListItemFactory>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<ListItemFactory>> (
        this,
        "factory");
  }

  auto
  GridView::property_max_columns () -> glib::PropertyProxy<guint>
  {
    return glib::PropertyProxy<guint> (this, "max-columns");
  }

  auto
  GridView::property_max_columns () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "max-columns");
  }

  auto
  GridView::property_min_columns () -> glib::PropertyProxy<guint>
  {
    return glib::PropertyProxy<guint> (this, "min-columns");
  }

  auto
  GridView::property_min_columns () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "min-columns");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<SelectionModel>>::value,
      "Type glib::RefPtr<SelectionModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  GridView::property_model () -> glib::PropertyProxy<glib::RefPtr<SelectionModel>>
  {
    return glib::PropertyProxy<glib::RefPtr<SelectionModel>> (this, "model");
  }

  auto
  GridView::property_model () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<SelectionModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<SelectionModel>> (this,
                                                                       "model");
  }

  auto
  GridView::property_single_click_activate () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "single-click-activate");
  }

  auto
  GridView::property_single_click_activate () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "single-click-activate");
  }

  auto
  GridView::property_enable_rubberband () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "enable-rubberband");
  }

  auto
  GridView::property_enable_rubberband () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "enable-rubberband");
  }

} // namespace gtk
