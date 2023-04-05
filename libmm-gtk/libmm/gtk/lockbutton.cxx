// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/lockbutton.hxx>
  #include <libmm/gtk/lockbutton_p.hxx>

  #include <gtk/gtk.h>

namespace gtk
{

  auto
  LockButton::unset_permission () -> void
  {
    gtk_lock_button_set_permission (gobj (), nullptr);
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkLockButton* object, bool take_copy) -> gtk::LockButton*
  {
    return dynamic_cast<gtk::LockButton*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  LockButton_Class::init () -> const glib::Class&
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
  LockButton_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new LockButton ((GtkLockButton*) (o)));
  }

  LockButton::LockButton (const glib::ConstructParams& construct_params)
    : gtk::Button (construct_params)
  {
  }

  LockButton::LockButton (GtkLockButton* castitem)
    : gtk::Button ((GtkButton*) (castitem))
  {
  }

  LockButton::LockButton (LockButton&& src) noexcept
    : gtk::Button (std::move (src))
  {
  }

  auto
  LockButton::operator= (LockButton&& src) noexcept -> LockButton&
  {
    gtk::Button::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::Button (glib::ConstructParams (lockbutton_class_.init ()))
  {
  }

  LockButton::LockButton (const glib::RefPtr<const gio::Permission>& permission)
    : glib::ObjectBase (nullptr),
      gtk::Button (glib::ConstructParams (
          lockbutton_class_.init (),
          "permission",
          const_cast<GPermission*> (glib::unwrap<gio::Permission> (permission)),
          nullptr))
  {
  }

  auto
  LockButton::get_permission () -> glib::RefPtr<gio::Permission>
  {
    auto retvalue = glib::wrap (gtk_lock_button_get_permission (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  LockButton::get_permission () const -> glib::RefPtr<const gio::Permission>
  {
    return const_cast<LockButton*> (this)->get_permission ();
  }

  auto
  LockButton::set_permission (
      const glib::RefPtr<const gio::Permission>& permission) -> void
  {
    gtk_lock_button_set_permission (
        gobj (),
        const_cast<GPermission*> (glib::unwrap<gio::Permission> (permission)));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::Permission>>::value,
      "Type glib::RefPtr<gio::Permission> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  LockButton::property_permission () -> glib::PropertyProxy<glib::RefPtr<gio::Permission>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::Permission>> (this,
                                                               "permission");
  }

  auto
  LockButton::property_permission () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::Permission>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::Permission>> (
        this,
        "permission");
  }

  auto
  LockButton::property_text_lock () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "text-lock");
  }

  auto
  LockButton::property_text_lock () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "text-lock");
  }

  auto
  LockButton::property_text_unlock () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "text-unlock");
  }

  auto
  LockButton::property_text_unlock () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "text-unlock");
  }

  auto
  LockButton::property_tooltip_lock () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "tooltip-lock");
  }

  auto
  LockButton::property_tooltip_lock () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "tooltip-lock");
  }

  auto
  LockButton::property_tooltip_unlock () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "tooltip-unlock");
  }

  auto
  LockButton::property_tooltip_unlock () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "tooltip-unlock");
  }

  auto
  LockButton::property_tooltip_not_authorized () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "tooltip-not-authorized");
  }

  auto
  LockButton::property_tooltip_not_authorized () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (
        this,
        "tooltip-not-authorized");
  }

} // namespace gtk

#endif
