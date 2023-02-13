


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/passwordentry.hxx>
#include <libmm-gtk/passwordentry_p.hxx>


/* Copyright (C) 2019 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkPasswordEntry* object, const bool take_copy) -> Gtk::PasswordEntry*
{
  return dynamic_cast<Gtk::PasswordEntry *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto PasswordEntry_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &PasswordEntry_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_password_entry_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Editable::add_interface(get_type());

  }

  return *this;
}


auto PasswordEntry_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto PasswordEntry_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new PasswordEntry((GtkPasswordEntry*)o));

}


/* The implementation: */

PasswordEntry::PasswordEntry(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

PasswordEntry::PasswordEntry(GtkPasswordEntry* castitem)
: Widget((GtkWidget*)castitem)
{
  }


PasswordEntry::PasswordEntry(PasswordEntry&& src) noexcept
: Widget(std::move(src))
  , Editable(std::move(src))
{}

auto PasswordEntry::operator=(PasswordEntry&& src) noexcept -> PasswordEntry&
{
  Widget::operator=(std::move(src));
  Editable::operator=(std::move(src));
  return *this;
}

PasswordEntry::~PasswordEntry() noexcept
{
  destroy_();
}

PasswordEntry::CppClassType PasswordEntry::passwordentry_class_; // initialize static member

auto PasswordEntry::get_type() -> GType
{
  return passwordentry_class_.init().get_type();
}


auto PasswordEntry::get_base_type() -> GType
{
  return gtk_password_entry_get_type();
}


PasswordEntry::PasswordEntry()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(passwordentry_class_.init()))
{


}

auto PasswordEntry::set_show_peek_icon (
  const bool show_peek_icon) -> void
{
  gtk_password_entry_set_show_peek_icon(gobj(), show_peek_icon);
}

auto PasswordEntry::get_show_peek_icon() const -> bool
{
  return gtk_password_entry_get_show_peek_icon(const_cast<GtkPasswordEntry*>(gobj()));
}

auto PasswordEntry::set_extra_menu (const Glib::RefPtr <Gio::MenuModel> &model) -> void
{
  gtk_password_entry_set_extra_menu(gobj(), Glib::unwrap(model));
}

auto PasswordEntry::get_extra_menu() -> Glib::RefPtr<Gio::MenuModel>
{
  auto retvalue = Glib::wrap(gtk_password_entry_get_extra_menu(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto PasswordEntry::get_extra_menu() const -> Glib::RefPtr<const Gio::MenuModel>
{
  return const_cast<PasswordEntry*>(this)->get_extra_menu();
}


auto PasswordEntry::property_placeholder_text() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "placeholder-text"};
}

auto PasswordEntry::property_placeholder_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "placeholder-text"};
}

auto PasswordEntry::property_activates_default() -> Glib::PropertyProxy< bool >
{
  return {this, "activates-default"};
}

auto PasswordEntry::property_activates_default() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "activates-default"};
}

auto PasswordEntry::property_show_peek_icon() -> Glib::PropertyProxy< bool >
{
  return {this, "show-peek-icon"};
}

auto PasswordEntry::property_show_peek_icon() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "show-peek-icon"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::MenuModel>>::value,
  "Type Glib::RefPtr<Gio::MenuModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto PasswordEntry::property_extra_menu() -> Glib::PropertyProxy< Glib::RefPtr<Gio::MenuModel> >
{
  return {this, "extra-menu"};
}

auto PasswordEntry::property_extra_menu() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::MenuModel> >
{
  return {this, "extra-menu"};
}


} // namespace Gtk


