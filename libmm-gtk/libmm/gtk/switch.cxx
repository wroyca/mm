// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/switch.hxx>
#include <libmm/gtk/switch_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

}

namespace
{

  static auto
  Switch_signal_state_set_callback (GtkSwitch* self, gboolean p0, void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<bool (bool)>;

    auto obj = dynamic_cast<Switch*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> ((*static_cast<SlotType*> (slot)) (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
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
    using namespace gtk;
    using SlotType = sigc::slot<void (bool)>;

    auto obj = dynamic_cast<Switch*> (
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

    using RType = gboolean;
    return RType ();
  }

  static const glib::SignalProxyInfo Switch_signal_state_set_info = {
      "state-set",
      (GCallback) &Switch_signal_state_set_callback,
      (GCallback) &Switch_signal_state_set_notify_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkSwitch* object, bool take_copy) -> gtk::Switch*
  {
    return dynamic_cast<gtk::Switch*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  Switch_Class::init () -> const glib::Class&
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
  Switch_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Switch ((GtkSwitch*) (o)));
  }

  Switch::Switch (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Switch::Switch (GtkSwitch* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Switch::Switch (Switch&& src) noexcept
    : gtk::Widget (std::move (src)),
      Actionable (std::move (src))
  {
  }

  auto
  Switch::operator= (Switch&& src) noexcept -> Switch&
  {
    gtk::Widget::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (switch_class_.init ()))
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
  Switch::signal_state_set () -> glib::SignalProxy<bool (bool)>
  {
    return glib::SignalProxy<bool (bool)> (this, &Switch_signal_state_set_info);
  }

  auto
  Switch::property_active () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "active");
  }

  auto
  Switch::property_active () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "active");
  }

  auto
  Switch::property_state () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "state");
  }

  auto
  Switch::property_state () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "state");
  }

} // namespace gtk
