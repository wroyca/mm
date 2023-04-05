// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/passwordentry.hxx>
#include <libmm/gtk/passwordentry_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkPasswordEntry* object, bool take_copy) -> gtk::PasswordEntry*
  {
    return dynamic_cast<gtk::PasswordEntry*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  PasswordEntry_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &PasswordEntry_Class::class_init_function;

      register_derived_type (gtk_password_entry_get_type ());

      Editable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  PasswordEntry_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  PasswordEntry_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new PasswordEntry ((GtkPasswordEntry*) (o)));
  }

  PasswordEntry::PasswordEntry (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  PasswordEntry::PasswordEntry (GtkPasswordEntry* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  PasswordEntry::PasswordEntry (PasswordEntry&& src) noexcept
    : gtk::Widget (std::move (src)),
      Editable (std::move (src))
  {
  }

  auto
  PasswordEntry::operator= (PasswordEntry&& src) noexcept -> PasswordEntry&
  {
    gtk::Widget::operator= (std::move (src));
    Editable::operator= (std::move (src));
    return *this;
  }

  PasswordEntry::~PasswordEntry () noexcept
  {
    destroy_ ();
  }

  PasswordEntry::CppClassType PasswordEntry::passwordentry_class_;

  auto
  PasswordEntry::get_type () -> GType
  {
    return passwordentry_class_.init ().get_type ();
  }

  auto
  PasswordEntry::get_base_type () -> GType
  {
    return gtk_password_entry_get_type ();
  }

  PasswordEntry::PasswordEntry ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (passwordentry_class_.init ()))
  {
  }

  auto
  PasswordEntry::set_show_peek_icon (bool show_peek_icon) -> void
  {
    gtk_password_entry_set_show_peek_icon (gobj (),
                                           static_cast<int> (show_peek_icon));
  }

  auto
  PasswordEntry::get_show_peek_icon () const -> bool
  {
    return gtk_password_entry_get_show_peek_icon (
        const_cast<GtkPasswordEntry*> (gobj ()));
  }

  auto
  PasswordEntry::set_extra_menu (const glib::RefPtr<gio::MenuModel>& model) -> void
  {
    gtk_password_entry_set_extra_menu (gobj (), glib::unwrap (model));
  }

  auto
  PasswordEntry::get_extra_menu () -> glib::RefPtr<gio::MenuModel>
  {
    auto retvalue = glib::wrap (gtk_password_entry_get_extra_menu (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PasswordEntry::get_extra_menu () const -> glib::RefPtr<const gio::MenuModel>
  {
    return const_cast<PasswordEntry*> (this)->get_extra_menu ();
  }

  auto
  PasswordEntry::property_placeholder_text () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "placeholder-text");
  }

  auto
  PasswordEntry::property_placeholder_text () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this,
                                                        "placeholder-text");
  }

  auto
  PasswordEntry::property_activates_default () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "activates-default");
  }

  auto
  PasswordEntry::property_activates_default () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "activates-default");
  }

  auto
  PasswordEntry::property_show_peek_icon () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "show-peek-icon");
  }

  auto
  PasswordEntry::property_show_peek_icon () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "show-peek-icon");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::MenuModel>>::value,
      "Type glib::RefPtr<gio::MenuModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  PasswordEntry::property_extra_menu () -> glib::PropertyProxy<glib::RefPtr<gio::MenuModel>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::MenuModel>> (this,
                                                              "extra-menu");
  }

  auto
  PasswordEntry::property_extra_menu () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>> (
        this,
        "extra-menu");
  }

} // namespace gtk
