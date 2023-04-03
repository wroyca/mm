// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/listview.hxx>
#include <libmm/gtk/listview_p.hxx>

#include <gtk/gtk.h>

namespace
{

  static auto
  ListView_signal_activate_callback (GtkListView* self, guint p0, void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (guint)>;

    auto obj = dynamic_cast<ListView*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo ListView_signal_activate_info = {
      "activate",
      (GCallback) &ListView_signal_activate_callback,
      (GCallback) &ListView_signal_activate_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkListView* object, bool take_copy) -> Gtk::ListView*
  {
    return dynamic_cast<Gtk::ListView*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ListView_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ListView_Class::class_init_function;

      register_derived_type (gtk_list_view_get_type ());
    }

    return *this;
  }

  auto
  ListView_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ListView_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new ListView ((GtkListView*) (o)));
  }

  ListView::ListView (const Glib::ConstructParams& construct_params)
    : ListBase (construct_params)
  {
  }

  ListView::ListView (GtkListView* castitem)
    : ListBase ((GtkListBase*) (castitem))
  {
  }

  ListView::ListView (ListView&& src) noexcept
    : ListBase (std::move (src))
  {
  }

  auto
  ListView::operator= (ListView&& src) noexcept -> ListView&
  {
    ListBase::operator= (std::move (src));
    return *this;
  }

  ListView::~ListView () noexcept
  {
    destroy_ ();
  }

  ListView::CppClassType ListView::listview_class_;

  auto
  ListView::get_type () -> GType
  {
    return listview_class_.init ().get_type ();
  }

  auto
  ListView::get_base_type () -> GType
  {
    return gtk_list_view_get_type ();
  }

  ListView::ListView (const Glib::RefPtr<SelectionModel>& model,
                      const Glib::RefPtr<ListItemFactory>& factory)
    : Glib::ObjectBase (nullptr),
      ListBase (Glib::ConstructParams (listview_class_.init (),
                                       "model",
                                       Glib::unwrap (model),
                                       "factory",
                                       Glib::unwrap (factory),
                                       nullptr))
  {
  }

  auto
  ListView::get_model () -> Glib::RefPtr<SelectionModel>
  {
    auto retvalue = Glib::wrap (gtk_list_view_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ListView::get_model () const -> Glib::RefPtr<const SelectionModel>
  {
    return const_cast<ListView*> (this)->get_model ();
  }

  auto
  ListView::set_model (const Glib::RefPtr<SelectionModel>& model) -> void
  {
    gtk_list_view_set_model (gobj (), Glib::unwrap (model));
  }

  auto
  ListView::set_factory (const Glib::RefPtr<ListItemFactory>& factory) -> void
  {
    gtk_list_view_set_factory (gobj (), Glib::unwrap (factory));
  }

  auto
  ListView::get_factory () -> Glib::RefPtr<ListItemFactory>
  {
    auto retvalue = Glib::wrap (gtk_list_view_get_factory (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ListView::get_factory () const -> Glib::RefPtr<const ListItemFactory>
  {
    return const_cast<ListView*> (this)->get_factory ();
  }

  auto
  ListView::set_show_separators (bool show_separators) -> void
  {
    gtk_list_view_set_show_separators (gobj (),
                                       static_cast<int> (show_separators));
  }

  auto
  ListView::get_show_separators () const -> bool
  {
    return gtk_list_view_get_show_separators (
        const_cast<GtkListView*> (gobj ()));
  }

  auto
  ListView::set_single_click_activate (bool single_click_activate) -> void
  {
    gtk_list_view_set_single_click_activate (
        gobj (),
        static_cast<int> (single_click_activate));
  }

  auto
  ListView::get_single_click_activate () const -> bool
  {
    return gtk_list_view_get_single_click_activate (
        const_cast<GtkListView*> (gobj ()));
  }

  auto
  ListView::set_enable_rubberband (bool enable_rubberband) -> void
  {
    gtk_list_view_set_enable_rubberband (gobj (),
                                         static_cast<int> (enable_rubberband));
  }

  auto
  ListView::get_enable_rubberband () const -> bool
  {
    return gtk_list_view_get_enable_rubberband (
        const_cast<GtkListView*> (gobj ()));
  }

  auto
  ListView::signal_activate () -> Glib::SignalProxy<void (guint)>
  {
    return Glib::SignalProxy<void (guint)> (this,
                                            &ListView_signal_activate_info);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<ListItemFactory>>::value,
      "Type Glib::RefPtr<ListItemFactory> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ListView::property_factory () -> Glib::PropertyProxy<Glib::RefPtr<ListItemFactory>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<ListItemFactory>> (this, "factory");
  }

  auto
  ListView::property_factory () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ListItemFactory>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ListItemFactory>> (
        this,
        "factory");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<SelectionModel>>::value,
      "Type Glib::RefPtr<SelectionModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ListView::property_model () -> Glib::PropertyProxy<Glib::RefPtr<SelectionModel>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<SelectionModel>> (this, "model");
  }

  auto
  ListView::property_model () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<SelectionModel>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<SelectionModel>> (this,
                                                                       "model");
  }

  auto
  ListView::property_show_separators () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "show-separators");
  }

  auto
  ListView::property_show_separators () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "show-separators");
  }

  auto
  ListView::property_single_click_activate () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "single-click-activate");
  }

  auto
  ListView::property_single_click_activate () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "single-click-activate");
  }

  auto
  ListView::property_enable_rubberband () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "enable-rubberband");
  }

  auto
  ListView::property_enable_rubberband () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "enable-rubberband");
  }

} // namespace Gtk