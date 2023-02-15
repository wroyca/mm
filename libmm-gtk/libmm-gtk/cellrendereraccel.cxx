// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/mm-glib.hxx>

  #include <libmm-gtk/cellrendereraccel.hxx>
  #include <libmm-gtk/cellrendereraccel_p.hxx>

  #include <gtk/gtk.h>

using Mode = Gtk::CellRendererAccel::Mode;

namespace Gtk
{

  auto
  CellRendererAccel::_property_renderable () -> Glib::PropertyProxy_Base
  {
    return property_accel_key ();
  }

} // namespace Gtk

namespace
{

  static auto
  CellRendererAccel_signal_accel_edited_callback (GtkCellRendererAccel* self,
                                                  const gchar* p0,
                                                  guint p1,
                                                  GdkModifierType p2,
                                                  guint p3,
                                                  void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<
        void (const Glib::ustring&, guint, Gdk::ModifierType, guint)>;

    auto obj = dynamic_cast<CellRendererAccel*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              Glib::convert_const_gchar_ptr_to_ustring (p0),
              p1,
              static_cast<Gdk::ModifierType> (p2),
              p3);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo
      CellRendererAccel_signal_accel_edited_info = {
          "accel_edited",
          (GCallback) &CellRendererAccel_signal_accel_edited_callback,
          (GCallback) &CellRendererAccel_signal_accel_edited_callback};

  static auto
  CellRendererAccel_signal_accel_cleared_callback (GtkCellRendererAccel* self,
                                                   const gchar* p0,
                                                   void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (const Glib::ustring&)>;

    auto obj = dynamic_cast<CellRendererAccel*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              Glib::convert_const_gchar_ptr_to_ustring (p0));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo
      CellRendererAccel_signal_accel_cleared_info = {
          "accel_cleared",
          (GCallback) &CellRendererAccel_signal_accel_cleared_callback,
          (GCallback) &CellRendererAccel_signal_accel_cleared_callback};

} // namespace

auto
Glib::Value<Gtk::CellRendererAccel::Mode>::value_type () -> GType
{
  return gtk_cell_renderer_accel_mode_get_type ();
}

namespace Glib
{

  auto
  wrap (GtkCellRendererAccel* object, bool take_copy) -> Gtk::CellRendererAccel*
  {
    return dynamic_cast<Gtk::CellRendererAccel*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  CellRendererAccel_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &CellRendererAccel_Class::class_init_function;

      register_derived_type (gtk_cell_renderer_accel_get_type ());
    }

    return *this;
  }

  auto
  CellRendererAccel_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  CellRendererAccel_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new CellRendererAccel ((GtkCellRendererAccel*) (o)));
  }

  CellRendererAccel::CellRendererAccel (
      const Glib::ConstructParams& construct_params)
    : Gtk::CellRendererText (construct_params)
  {
  }

  CellRendererAccel::CellRendererAccel (GtkCellRendererAccel* castitem)
    : Gtk::CellRendererText ((GtkCellRendererText*) (castitem))
  {
  }

  CellRendererAccel::CellRendererAccel (CellRendererAccel&& src) noexcept
    : Gtk::CellRendererText (std::move (src))
  {
  }

  auto
  CellRendererAccel::operator= (CellRendererAccel&& src) noexcept -> CellRendererAccel&
  {
    Gtk::CellRendererText::operator= (std::move (src));
    return *this;
  }

  CellRendererAccel::~CellRendererAccel () noexcept
  {
    destroy_ ();
  }

  CellRendererAccel::CppClassType CellRendererAccel::cellrendereraccel_class_;

  auto
  CellRendererAccel::get_type () -> GType
  {
    return cellrendereraccel_class_.init ().get_type ();
  }

  auto
  CellRendererAccel::get_base_type () -> GType
  {
    return gtk_cell_renderer_accel_get_type ();
  }

  CellRendererAccel::CellRendererAccel ()
    : Glib::ObjectBase (nullptr),
      Gtk::CellRendererText (
          Glib::ConstructParams (cellrendereraccel_class_.init ()))
  {
  }

  auto
  CellRendererAccel::signal_accel_edited () -> Glib::SignalProxy<
      void (const Glib::ustring&, guint, Gdk::ModifierType, guint)>
  {
    return Glib::SignalProxy<
        void (const Glib::ustring&, guint, Gdk::ModifierType, guint)> (
        this,
        &CellRendererAccel_signal_accel_edited_info);
  }

  auto
  CellRendererAccel::signal_accel_cleared () -> Glib::SignalProxy<void (const Glib::ustring&)>
  {
    return Glib::SignalProxy<void (const Glib::ustring&)> (
        this,
        &CellRendererAccel_signal_accel_cleared_info);
  }

  auto
  CellRendererAccel::property_accel_key () -> Glib::PropertyProxy<guint>
  {
    return Glib::PropertyProxy<guint> (this, "accel-key");
  }

  auto
  CellRendererAccel::property_accel_key () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "accel-key");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Gdk::ModifierType>::value,
      "Type Gdk::ModifierType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  CellRendererAccel::property_accel_mods () -> Glib::PropertyProxy<Gdk::ModifierType>
  {
    return Glib::PropertyProxy<Gdk::ModifierType> (this, "accel-mods");
  }

  auto
  CellRendererAccel::property_accel_mods () const -> Glib::PropertyProxy_ReadOnly<Gdk::ModifierType>
  {
    return Glib::PropertyProxy_ReadOnly<Gdk::ModifierType> (this, "accel-mods");
  }

  auto
  CellRendererAccel::property_keycode () -> Glib::PropertyProxy<guint>
  {
    return Glib::PropertyProxy<guint> (this, "keycode");
  }

  auto
  CellRendererAccel::property_keycode () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "keycode");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Mode>::value,
      "Type Mode cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  CellRendererAccel::property_accel_mode () -> Glib::PropertyProxy<Mode>
  {
    return Glib::PropertyProxy<Mode> (this, "accel-mode");
  }

  auto
  CellRendererAccel::property_accel_mode () const -> Glib::PropertyProxy_ReadOnly<Mode>
  {
    return Glib::PropertyProxy_ReadOnly<Mode> (this, "accel-mode");
  }

} // namespace Gtk

#endif
