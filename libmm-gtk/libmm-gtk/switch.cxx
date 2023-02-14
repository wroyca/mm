

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/switch.hxx>
#include <libmm-gtk/switch_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

}

namespace
{

  auto
  Switch_signal_state_set_callback (GtkSwitch* self,
                                    const gboolean p0,
                                    void* data) -> gboolean
  {
    using namespace Gtk;
    using SlotType = sigc::slot<bool (bool)>;

    const auto obj = dynamic_cast<Switch*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          return (*static_cast<SlotType*> (slot)) (p0);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  auto
  Switch_signal_state_set_notify_callback (GtkSwitch* self,
                                           const gboolean p0,
                                           void* data) -> gboolean
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (bool)>;

    const auto obj = dynamic_cast<Switch*> (
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

  const Glib::SignalProxyInfo Switch_signal_state_set_info = {
      "state-set",
      (GCallback) &Switch_signal_state_set_callback,
      (GCallback) &Switch_signal_state_set_notify_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkSwitch* object, const bool take_copy) -> Gtk::Switch*
  {
    return dynamic_cast<Gtk::Switch*> (
        wrap_auto ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Switch_Class::init () -> const Class&
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
    return manage (new Switch ((GtkSwitch*) o));
  }

  Switch::Switch (const Glib::ConstructParams& construct_params)
    : Widget (construct_params)
  {
  }

  Switch::Switch (GtkSwitch* castitem)
    : Widget ((GtkWidget*) castitem)
  {
  }

  Switch::Switch (Switch&& src) noexcept
    : Widget (std::move (src)),
      Actionable (std::move (src))
  {
  }

  auto
  Switch::operator= (Switch&& src) noexcept -> Switch&
  {
    Widget::operator= (std::move (src));
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
    : ObjectBase (nullptr),
      Widget (Glib::ConstructParams (switch_class_.init ()))
  {
  }

  auto
  Switch::set_active (const bool is_active) -> void
  {
    gtk_switch_set_active (gobj (), is_active);
  }

  auto
  Switch::get_active () const -> bool
  {
    return gtk_switch_get_active (const_cast<GtkSwitch*> (gobj ()));
  }

  auto
  Switch::set_state (const bool state) -> void
  {
    gtk_switch_set_state (gobj (), state);
  }

  auto
  Switch::get_state () const -> bool
  {
    return gtk_switch_get_state (const_cast<GtkSwitch*> (gobj ()));
  }

  auto
  Switch::signal_state_set () -> Glib::SignalProxy<bool (bool)>
  {
    return {this, &Switch_signal_state_set_info};
  }

  auto
  Switch::property_active () -> Glib::PropertyProxy<bool>
  {
    return {this, "active"};
  }

  auto
  Switch::property_active () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "active"};
  }

  auto
  Switch::property_state () -> Glib::PropertyProxy<bool>
  {
    return {this, "state"};
  }

  auto
  Switch::property_state () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "state"};
  }

} // namespace Gtk
