// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/atcontext.hxx>
#include <libmm/gtk/atcontext_p.hxx>

#include <gtk/gtk.h>

namespace
{

  static const Glib::SignalProxyInfo ATContext_signal_state_change_info = {
      "state-change",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

}

namespace Glib
{

  auto
  wrap (GtkATContext* object, bool take_copy) -> Glib::RefPtr<Gtk::ATContext>
  {
    return Glib::make_refptr_for_instance<Gtk::ATContext> (
        dynamic_cast<Gtk::ATContext*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ATContext_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = gtk_at_context_get_type ();
    }

    return *this;
  }

  auto
  ATContext_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new ATContext ((GtkATContext*) object);
  }

  auto
  ATContext::gobj_copy () -> GtkATContext*
  {
    reference ();
    return gobj ();
  }

  ATContext::ATContext (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  ATContext::ATContext (GtkATContext* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  ATContext::ATContext (ATContext&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  ATContext::operator= (ATContext&& src) noexcept -> ATContext&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  ATContext::~ATContext () noexcept {}

  ATContext::CppClassType ATContext::atcontext_class_;

  auto
  ATContext::get_type () -> GType
  {
    return atcontext_class_.init ().get_type ();
  }

  auto
  ATContext::get_base_type () -> GType
  {
    return gtk_at_context_get_type ();
  }

  ATContext::ATContext ()
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (atcontext_class_.init ()))
  {
  }

  auto
  ATContext::create (Accessible::Role accessible_role,
                     const Glib::RefPtr<Accessible>& accessible,
                     const Glib::RefPtr<Gdk::Display>& display) -> Glib::RefPtr<ATContext>
  {
    return Glib::wrap (
        gtk_at_context_create (static_cast<GtkAccessibleRole> (accessible_role),
                               Glib::unwrap (accessible),
                               Glib::unwrap (display)));
  }

  auto
  ATContext::get_accessible () -> Glib::RefPtr<Accessible>
  {
    auto retvalue = Glib::wrap (gtk_at_context_get_accessible (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ATContext::get_accessible () const -> Glib::RefPtr<const Accessible>
  {
    return const_cast<ATContext*> (this)->get_accessible ();
  }

  auto
  ATContext::get_accessible_role () const -> Accessible::Role
  {
    return static_cast<Accessible::Role> (gtk_at_context_get_accessible_role (
        const_cast<GtkATContext*> (gobj ())));
  }

  auto
  ATContext::signal_state_change () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this,
                                       &ATContext_signal_state_change_info);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Accessible::Role>::value,
      "Type Accessible::Role cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ATContext::property_accessible_role () -> Glib::PropertyProxy<Accessible::Role>
  {
    return Glib::PropertyProxy<Accessible::Role> (this, "accessible-role");
  }

  auto
  ATContext::property_accessible_role () const -> Glib::PropertyProxy_ReadOnly<Accessible::Role>
  {
    return Glib::PropertyProxy_ReadOnly<Accessible::Role> (this,
                                                           "accessible-role");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Accessible>>::value,
      "Type Glib::RefPtr<Accessible> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ATContext::property_accessible () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Accessible>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Accessible>> (
        this,
        "accessible");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gdk::Display>>::value,
      "Type Glib::RefPtr<Gdk::Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ATContext::property_display () -> Glib::PropertyProxy<Glib::RefPtr<Gdk::Display>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gdk::Display>> (this, "display");
  }

  auto
  ATContext::property_display () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Display>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Display>> (this,
                                                                     "display");
  }

} // namespace Gtk
