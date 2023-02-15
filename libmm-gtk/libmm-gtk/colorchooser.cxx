// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/mm-glib.hxx>

  #include <libmm-gtk/colorchooser.hxx>
  #include <libmm-gtk/colorchooser_p.hxx>

  #include <gtk/gtk.h>

namespace Gtk
{

  auto
  ColorChooser::get_rgba () const -> Gdk::RGBA
  {
    GdkRGBA crgba;
    gtk_color_chooser_get_rgba (const_cast<GtkColorChooser*> (gobj ()), &crgba);
    return Glib::wrap (&crgba, true);
  }

  auto
  ColorChooser::add_palette (Orientation orientation,
                             int colors_per_line,
                             const std::vector<Gdk::RGBA>& colors) -> void
  {
    gtk_color_chooser_add_palette (
        gobj (),
        (GtkOrientation) orientation,
        colors_per_line,
        colors.size (),
        Glib::ArrayHandler<Gdk::RGBA, Gdk::RGBATraits>::vector_to_array (colors)
            .data ());
  }

} // namespace Gtk

namespace
{

  static auto
  ColorChooser_signal_color_activated_callback (GtkColorChooser* self,
                                                const GdkRGBA* p0,
                                                void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (const Gdk::RGBA&)>;

    auto obj = dynamic_cast<ColorChooser*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              Glib::wrap (const_cast<GdkRGBA*> (p0), true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo ColorChooser_signal_color_activated_info =
      {"color-activated",
       (GCallback) &ColorChooser_signal_color_activated_callback,
       (GCallback) &ColorChooser_signal_color_activated_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkColorChooser* object, bool take_copy) -> Glib::RefPtr<Gtk::ColorChooser>
  {
    return Glib::make_refptr_for_instance<Gtk::ColorChooser> (
        dynamic_cast<Gtk::ColorChooser*> (
            Glib::wrap_auto_interface<Gtk::ColorChooser> ((GObject*) (object),
                                                          take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ColorChooser_Class::init () -> const Glib::Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ColorChooser_Class::iface_init_function;

      gtype_ = gtk_color_chooser_get_type ();
    }

    return *this;
  }

  auto
  ColorChooser_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->color_activated = &color_activated_callback;
  }

  auto
  ColorChooser_Class::color_activated_callback (GtkColorChooser* self,
                                                const GdkRGBA* p0) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_color_activated (
              Glib::wrap (const_cast<GdkRGBA*> (p0), true));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->color_activated)
      (*base->color_activated) (self, p0);
  }

  auto
  ColorChooser_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new ColorChooser ((GtkColorChooser*) (object));
  }

  ColorChooser::ColorChooser ()
    : Glib::Interface (colorchooser_class_.init ())
  {
  }

  ColorChooser::ColorChooser (GtkColorChooser* castitem)
    : Glib::Interface ((GObject*) (castitem))
  {
  }

  ColorChooser::ColorChooser (const Glib::Interface_Class& interface_class)
    : Glib::Interface (interface_class)
  {
  }

  ColorChooser::ColorChooser (ColorChooser&& src) noexcept
    : Glib::Interface (std::move (src))
  {
  }

  auto
  ColorChooser::operator= (ColorChooser&& src) noexcept -> ColorChooser&
  {
    Glib::Interface::operator= (std::move (src));
    return *this;
  }

  ColorChooser::~ColorChooser () noexcept {}

  auto
  ColorChooser::add_interface (GType gtype_implementer) -> void
  {
    colorchooser_class_.init ().add_interface (gtype_implementer);
  }

  ColorChooser::CppClassType ColorChooser::colorchooser_class_;

  auto
  ColorChooser::get_type () -> GType
  {
    return colorchooser_class_.init ().get_type ();
  }

  auto
  ColorChooser::get_base_type () -> GType
  {
    return gtk_color_chooser_get_type ();
  }

  auto
  ColorChooser::set_rgba (const Gdk::RGBA& color) -> void
  {
    gtk_color_chooser_set_rgba (gobj (), (color).gobj ());
  }

  auto
  ColorChooser::get_use_alpha () const -> bool
  {
    return gtk_color_chooser_get_use_alpha (
        const_cast<GtkColorChooser*> (gobj ()));
  }

  auto
  ColorChooser::set_use_alpha (bool use_alpha) -> void
  {
    gtk_color_chooser_set_use_alpha (gobj (), static_cast<int> (use_alpha));
  }

  auto
  ColorChooser::signal_color_activated () -> Glib::SignalProxy<void (const Gdk::RGBA&)>
  {
    return Glib::SignalProxy<void (const Gdk::RGBA&)> (
        this,
        &ColorChooser_signal_color_activated_info);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Gdk::RGBA>::value,
      "Type Gdk::RGBA cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ColorChooser::property_rgba () -> Glib::PropertyProxy<Gdk::RGBA>
  {
    return Glib::PropertyProxy<Gdk::RGBA> (this, "rgba");
  }

  auto
  ColorChooser::property_rgba () const -> Glib::PropertyProxy_ReadOnly<Gdk::RGBA>
  {
    return Glib::PropertyProxy_ReadOnly<Gdk::RGBA> (this, "rgba");
  }

  auto
  ColorChooser::property_use_alpha () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "use-alpha");
  }

  auto
  ColorChooser::property_use_alpha () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "use-alpha");
  }

  auto
  Gtk::ColorChooser::on_color_activated (const Gdk::RGBA& color) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->color_activated)
      (*base->color_activated) (gobj (), (color).gobj ());
  }

} // namespace Gtk

#endif
