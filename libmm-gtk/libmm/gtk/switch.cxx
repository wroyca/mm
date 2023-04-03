// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/switch.hxx>
#include <libmm/gtk/switch_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

}

namespace
{

  static auto
  Switch_signal_state_set_callback (GtkSwitch* self, gboolean p0, void* data) -> gboolean
  {
    using namespace Gtk;
    using SlotType = sigc::slot<bool (bool)>;

    auto obj = dynamic_cast<Switch*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> ((*static_cast<SlotType*> (slot)) (p0));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static auto
  Switch_signal_state_set_notify_callback (GtkSwitch* self,
                                           gboolean p0,
                                           void* data) -> gboolean
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (bool)>;

    auto obj = dynamic_cast<Switch*> (
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

    using RType = gboolean;
    return RType ();
  }

  static const Glib::SignalProxyInfo Switch_signal_state_set_info = {
      "state-set",
      (GCallback) &Switch_signal_state_set_callback,
      (GCallback) &Switch_signal_state_set_notify_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkSwitch* object, bool take_copy) -> Gtk::Switch*
  {
    return dynamic_cast<Gtk::Switch*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Switch_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Switch_Class::class_init_function;

      register_derived_type (gtk_switch_get_type ());

      Actionable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  Switch_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Switch_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new Switch ((GtkSwitch*) (o)));
  }

  Switch::Switch (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  Switch::Switch (GtkSwitch* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Switch::Switch (Switch&& src) noexcept
    : Gtk::Widget (std::move (src)),
      Actionable (std::move (src))
  {
  }

  auto
  Switch::operator= (Switch&& src) noexcept -> Switch&
  {
    Gtk::Widget::operator= (std::move (src));
    Actionable::operator= (std::move (src));
    return *this;
  }

  Switch::~Switch () noexcept
  {
    destroy_ ();
  }

  Switch::CppClassType Switch::switch_class_;

  auto
  Switch::get_type () -> GType
  {
    return switch_class_.init ().get_type ();
  }

  auto
  Switch::get_base_type () -> GType
  {
    return gtk_switch_get_type ();
  }

  Switch::Switch ()
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (switch_class_.init ()))
  {
  }

  auto
  Switch::set_active (bool is_active) -> void
  {
    gtk_switch_set_active (gobj (), static_cast<int> (is_active));
  }

  auto
  Switch::get_active () const -> bool
  {
    return gtk_switch_get_active (const_cast<GtkSwitch*> (gobj ()));
  }

  auto
  Switch::set_state (bool state) -> void
  {
    gtk_switch_set_state (gobj (), static_cast<int> (state));
  }

  auto
  Switch::get_state () const -> bool
  {
    return gtk_switch_get_state (const_cast<GtkSwitch*> (gobj ()));
  }

  auto
  Switch::signal_state_set () -> Glib::SignalProxy<bool (bool)>
  {
    return Glib::SignalProxy<bool (bool)> (this, &Switch_signal_state_set_info);
  }

  auto
  Switch::property_active () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "active");
  }

  auto
  Switch::property_active () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "active");
  }

  auto
  Switch::property_state () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "state");
  }

  auto
  Switch::property_state () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "state");
  }

} // namespace Gtk
