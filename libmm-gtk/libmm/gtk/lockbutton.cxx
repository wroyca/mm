// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/lockbutton.hxx>
  #include <libmm/gtk/lockbutton_p.hxx>

  #include <gtk/gtk.h>

namespace Gtk
{

  auto
  LockButton::unset_permission () -> void
  {
    gtk_lock_button_set_permission (gobj (), nullptr);
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkLockButton* object, bool take_copy) -> Gtk::LockButton*
  {
    return dynamic_cast<Gtk::LockButton*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  LockButton_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &LockButton_Class::class_init_function;

      register_derived_type (gtk_lock_button_get_type ());
    }

    return *this;
  }

  auto
  LockButton_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  LockButton_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new LockButton ((GtkLockButton*) (o)));
  }

  LockButton::LockButton (const Glib::ConstructParams& construct_params)
    : Gtk::Button (construct_params)
  {
  }

  LockButton::LockButton (GtkLockButton* castitem)
    : Gtk::Button ((GtkButton*) (castitem))
  {
  }

  LockButton::LockButton (LockButton&& src) noexcept
    : Gtk::Button (std::move (src))
  {
  }

  auto
  LockButton::operator= (LockButton&& src) noexcept -> LockButton&
  {
    Gtk::Button::operator= (std::move (src));
    return *this;
  }

  LockButton::~LockButton () noexcept
  {
    destroy_ ();
  }

  LockButton::CppClassType LockButton::lockbutton_class_;

  auto
  LockButton::get_type () -> GType
  {
    return lockbutton_class_.init ().get_type ();
  }

  auto
  LockButton::get_base_type () -> GType
  {
    return gtk_lock_button_get_type ();
  }

  LockButton::LockButton ()
    : Glib::ObjectBase (nullptr),
      Gtk::Button (Glib::ConstructParams (lockbutton_class_.init ()))
  {
  }

  LockButton::LockButton (const Glib::RefPtr<const Gio::Permission>& permission)
    : Glib::ObjectBase (nullptr),
      Gtk::Button (Glib::ConstructParams (
          lockbutton_class_.init (),
          "permission",
          const_cast<GPermission*> (Glib::unwrap<Gio::Permission> (permission)),
          nullptr))
  {
  }

  auto
  LockButton::get_permission () -> Glib::RefPtr<Gio::Permission>
  {
    auto retvalue = Glib::wrap (gtk_lock_button_get_permission (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  LockButton::get_permission () const -> Glib::RefPtr<const Gio::Permission>
  {
    return const_cast<LockButton*> (this)->get_permission ();
  }

  auto
  LockButton::set_permission (
      const Glib::RefPtr<const Gio::Permission>& permission) -> void
  {
    gtk_lock_button_set_permission (
        gobj (),
        const_cast<GPermission*> (Glib::unwrap<Gio::Permission> (permission)));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::Permission>>::value,
      "Type Glib::RefPtr<Gio::Permission> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  LockButton::property_permission () -> Glib::PropertyProxy<Glib::RefPtr<Gio::Permission>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::Permission>> (this,
                                                               "permission");
  }

  auto
  LockButton::property_permission () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::Permission>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::Permission>> (
        this,
        "permission");
  }

  auto
  LockButton::property_text_lock () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "text-lock");
  }

  auto
  LockButton::property_text_lock () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "text-lock");
  }

  auto
  LockButton::property_text_unlock () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "text-unlock");
  }

  auto
  LockButton::property_text_unlock () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "text-unlock");
  }

  auto
  LockButton::property_tooltip_lock () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "tooltip-lock");
  }

  auto
  LockButton::property_tooltip_lock () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "tooltip-lock");
  }

  auto
  LockButton::property_tooltip_unlock () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "tooltip-unlock");
  }

  auto
  LockButton::property_tooltip_unlock () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "tooltip-unlock");
  }

  auto
  LockButton::property_tooltip_not_authorized () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "tooltip-not-authorized");
  }

  auto
  LockButton::property_tooltip_not_authorized () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (
        this,
        "tooltip-not-authorized");
  }

} // namespace Gtk

#endif