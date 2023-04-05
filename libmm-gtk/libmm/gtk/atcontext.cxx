// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/atcontext.hxx>
#include <libmm/gtk/atcontext_p.hxx>

#include <gtk/gtk.h>

namespace
{

  static const glib::SignalProxyInfo ATContext_signal_state_change_info = {
      "state-change",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

}

namespace glib
{

  auto
  wrap (GtkATContext* object, bool take_copy) -> glib::RefPtr<gtk::ATContext>
  {
    return glib::make_refptr_for_instance<gtk::ATContext> (
        dynamic_cast<gtk::ATContext*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  ATContext_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = gtk_at_context_get_type ();
    }

    return *this;
  }

  auto
  ATContext_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new ATContext ((GtkATContext*) object);
  }

  auto
  ATContext::gobj_copy () -> GtkATContext*
  {
    reference ();
    return gobj ();
  }

  ATContext::ATContext (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  ATContext::ATContext (GtkATContext* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  ATContext::ATContext (ATContext&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  ATContext::operator= (ATContext&& src) noexcept -> ATContext&
  {
    glib::Object::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (atcontext_class_.init ()))
  {
  }

  auto
  ATContext::create (Accessible::Role accessible_role,
                     const glib::RefPtr<Accessible>& accessible,
                     const glib::RefPtr<gdk::Display>& display) -> glib::RefPtr<ATContext>
  {
    return glib::wrap (
        gtk_at_context_create (static_cast<GtkAccessibleRole> (accessible_role),
                               glib::unwrap (accessible),
                               glib::unwrap (display)));
  }

  auto
  ATContext::get_accessible () -> glib::RefPtr<Accessible>
  {
    auto retvalue = glib::wrap (gtk_at_context_get_accessible (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ATContext::get_accessible () const -> glib::RefPtr<const Accessible>
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
  ATContext::signal_state_change () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this,
                                       &ATContext_signal_state_change_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Accessible::Role>::value,
      "Type Accessible::Role cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ATContext::property_accessible_role () -> glib::PropertyProxy<Accessible::Role>
  {
    return glib::PropertyProxy<Accessible::Role> (this, "accessible-role");
  }

  auto
  ATContext::property_accessible_role () const -> glib::PropertyProxy_ReadOnly<Accessible::Role>
  {
    return glib::PropertyProxy_ReadOnly<Accessible::Role> (this,
                                                           "accessible-role");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Accessible>>::value,
      "Type glib::RefPtr<Accessible> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ATContext::property_accessible () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Accessible>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Accessible>> (
        this,
        "accessible");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gdk::Display>>::value,
      "Type glib::RefPtr<gdk::Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ATContext::property_display () -> glib::PropertyProxy<glib::RefPtr<gdk::Display>>
  {
    return glib::PropertyProxy<glib::RefPtr<gdk::Display>> (this, "display");
  }

  auto
  ATContext::property_display () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Display>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Display>> (this,
                                                                     "display");
  }

} // namespace gtk
