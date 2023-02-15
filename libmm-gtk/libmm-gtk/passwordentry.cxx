// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/passwordentry.hxx>
#include <libmm-gtk/passwordentry_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkPasswordEntry* object, bool take_copy) -> Gtk::PasswordEntry*
  {
    return dynamic_cast<Gtk::PasswordEntry*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  PasswordEntry_Class::init () -> const Glib::Class&
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
  PasswordEntry_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new PasswordEntry ((GtkPasswordEntry*) (o)));
  }

  PasswordEntry::PasswordEntry (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  PasswordEntry::PasswordEntry (GtkPasswordEntry* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  PasswordEntry::PasswordEntry (PasswordEntry&& src) noexcept
    : Gtk::Widget (std::move (src)),
      Editable (std::move (src))
  {
  }

  auto
  PasswordEntry::operator= (PasswordEntry&& src) noexcept -> PasswordEntry&
  {
    Gtk::Widget::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (passwordentry_class_.init ()))
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
  PasswordEntry::set_extra_menu (const Glib::RefPtr<Gio::MenuModel>& model) -> void
  {
    gtk_password_entry_set_extra_menu (gobj (), Glib::unwrap (model));
  }

  auto
  PasswordEntry::get_extra_menu () -> Glib::RefPtr<Gio::MenuModel>
  {
    auto retvalue = Glib::wrap (gtk_password_entry_get_extra_menu (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PasswordEntry::get_extra_menu () const -> Glib::RefPtr<const Gio::MenuModel>
  {
    return const_cast<PasswordEntry*> (this)->get_extra_menu ();
  }

  auto
  PasswordEntry::property_placeholder_text () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "placeholder-text");
  }

  auto
  PasswordEntry::property_placeholder_text () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this,
                                                        "placeholder-text");
  }

  auto
  PasswordEntry::property_activates_default () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "activates-default");
  }

  auto
  PasswordEntry::property_activates_default () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "activates-default");
  }

  auto
  PasswordEntry::property_show_peek_icon () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "show-peek-icon");
  }

  auto
  PasswordEntry::property_show_peek_icon () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "show-peek-icon");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::MenuModel>>::value,
      "Type Glib::RefPtr<Gio::MenuModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  PasswordEntry::property_extra_menu () -> Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>> (this,
                                                              "extra-menu");
  }

  auto
  PasswordEntry::property_extra_menu () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>> (
        this,
        "extra-menu");
  }

} // namespace Gtk
