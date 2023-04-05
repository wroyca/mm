// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/cellrendereraccel.hxx>
  #include <libmm/gtk/cellrendereraccel_p.hxx>

  #include <gtk/gtk.h>

using Mode = gtk::CellRendererAccel::Mode;

namespace gtk
{

  auto
  CellRendererAccel::_property_renderable () -> glib::PropertyProxy_Base
  {
    return property_accel_key ();
  }

} // namespace gtk

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
    using namespace gtk;
    using SlotType = sigc::slot<
        void (const glib::ustring&, guint, gdk::ModifierType, guint)>;

    auto obj = dynamic_cast<CellRendererAccel*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::convert_const_gchar_ptr_to_ustring (p0),
              p1,
              static_cast<gdk::ModifierType> (p2),
              p3);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo
      CellRendererAccel_signal_accel_edited_info = {
          "accel_edited",
          (GCallback) &CellRendererAccel_signal_accel_edited_callback,
          (GCallback) &CellRendererAccel_signal_accel_edited_callback};

  static auto
  CellRendererAccel_signal_accel_cleared_callback (GtkCellRendererAccel* self,
                                                   const gchar* p0,
                                                   void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const glib::ustring&)>;

    auto obj = dynamic_cast<CellRendererAccel*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::convert_const_gchar_ptr_to_ustring (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo
      CellRendererAccel_signal_accel_cleared_info = {
          "accel_cleared",
          (GCallback) &CellRendererAccel_signal_accel_cleared_callback,
          (GCallback) &CellRendererAccel_signal_accel_cleared_callback};

} // namespace

auto
glib::Value<gtk::CellRendererAccel::Mode>::value_type () -> GType
{
  return gtk_cell_renderer_accel_mode_get_type ();
}

namespace glib
{

  auto
  wrap (GtkCellRendererAccel* object, bool take_copy) -> gtk::CellRendererAccel*
  {
    return dynamic_cast<gtk::CellRendererAccel*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  CellRendererAccel_Class::init () -> const glib::Class&
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
  CellRendererAccel_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new CellRendererAccel ((GtkCellRendererAccel*) (o)));
  }

  CellRendererAccel::CellRendererAccel (
      const glib::ConstructParams& construct_params)
    : gtk::CellRendererText (construct_params)
  {
  }

  CellRendererAccel::CellRendererAccel (GtkCellRendererAccel* castitem)
    : gtk::CellRendererText ((GtkCellRendererText*) (castitem))
  {
  }

  CellRendererAccel::CellRendererAccel (CellRendererAccel&& src) noexcept
    : gtk::CellRendererText (std::move (src))
  {
  }

  auto
  CellRendererAccel::operator= (CellRendererAccel&& src) noexcept -> CellRendererAccel&
  {
    gtk::CellRendererText::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::CellRendererText (
          glib::ConstructParams (cellrendereraccel_class_.init ()))
  {
  }

  auto
  CellRendererAccel::signal_accel_edited () -> glib::SignalProxy<
      void (const glib::ustring&, guint, gdk::ModifierType, guint)>
  {
    return glib::SignalProxy<
        void (const glib::ustring&, guint, gdk::ModifierType, guint)> (
        this,
        &CellRendererAccel_signal_accel_edited_info);
  }

  auto
  CellRendererAccel::signal_accel_cleared () -> glib::SignalProxy<void (const glib::ustring&)>
  {
    return glib::SignalProxy<void (const glib::ustring&)> (
        this,
        &CellRendererAccel_signal_accel_cleared_info);
  }

  auto
  CellRendererAccel::property_accel_key () -> glib::PropertyProxy<guint>
  {
    return glib::PropertyProxy<guint> (this, "accel-key");
  }

  auto
  CellRendererAccel::property_accel_key () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "accel-key");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<gdk::ModifierType>::value,
      "Type gdk::ModifierType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CellRendererAccel::property_accel_mods () -> glib::PropertyProxy<gdk::ModifierType>
  {
    return glib::PropertyProxy<gdk::ModifierType> (this, "accel-mods");
  }

  auto
  CellRendererAccel::property_accel_mods () const -> glib::PropertyProxy_ReadOnly<gdk::ModifierType>
  {
    return glib::PropertyProxy_ReadOnly<gdk::ModifierType> (this, "accel-mods");
  }

  auto
  CellRendererAccel::property_keycode () -> glib::PropertyProxy<guint>
  {
    return glib::PropertyProxy<guint> (this, "keycode");
  }

  auto
  CellRendererAccel::property_keycode () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "keycode");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Mode>::value,
      "Type Mode cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CellRendererAccel::property_accel_mode () -> glib::PropertyProxy<Mode>
  {
    return glib::PropertyProxy<Mode> (this, "accel-mode");
  }

  auto
  CellRendererAccel::property_accel_mode () const -> glib::PropertyProxy_ReadOnly<Mode>
  {
    return glib::PropertyProxy_ReadOnly<Mode> (this, "accel-mode");
  }

} // namespace gtk

#endif
