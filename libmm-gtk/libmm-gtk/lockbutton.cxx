


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/lockbutton.hxx>
#include <libmm-gtk/lockbutton_p.hxx>


/*
 * Copyright 2014 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <gtk/gtk.h>


namespace Gtk
{

auto LockButton::unset_permission () -> void
{
  gtk_lock_button_set_permission(gobj(), nullptr);
}

} // namespace Gtk


namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkLockButton* object, const bool take_copy) -> Gtk::LockButton*
{
  return dynamic_cast<Gtk::LockButton *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto LockButton_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &LockButton_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_lock_button_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto LockButton_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto LockButton_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new LockButton((GtkLockButton*)o));

}


/* The implementation: */

LockButton::LockButton(const Glib::ConstructParams& construct_params)
: Button(construct_params)
{
  }

LockButton::LockButton(GtkLockButton* castitem)
: Button((GtkButton*)castitem)
{
  }


LockButton::LockButton(LockButton&& src) noexcept
: Button(std::move(src))
{}

auto LockButton::operator=(LockButton&& src) noexcept -> LockButton&
{
  Button::operator=(std::move(src));
  return *this;
}

LockButton::~LockButton() noexcept
{
  destroy_();
}

LockButton::CppClassType LockButton::lockbutton_class_; // initialize static member

auto LockButton::get_type() -> GType
{
  return lockbutton_class_.init().get_type();
}


auto LockButton::get_base_type() -> GType
{
  return gtk_lock_button_get_type();
}


LockButton::LockButton()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Button(Glib::ConstructParams(lockbutton_class_.init()))
{


}

LockButton::LockButton(const Glib::RefPtr<const Gio::Permission>& permission)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Button(Glib::ConstructParams(lockbutton_class_.init(), "permission", Glib::unwrap<Gio::Permission>(permission), nullptr))
{


}

auto LockButton::get_permission() -> Glib::RefPtr<Gio::Permission>
{
  auto retvalue = Glib::wrap(gtk_lock_button_get_permission(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto LockButton::get_permission() const -> Glib::RefPtr<const Gio::Permission>
{
  return const_cast<LockButton*>(this)->get_permission();
}

auto LockButton::set_permission (const Glib::RefPtr <const Gio::Permission> &permission) -> void
{
  gtk_lock_button_set_permission(gobj(), const_cast<GPermission*>(Glib::unwrap<Gio::Permission>(permission)));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::Permission>>::value,
  "Type Glib::RefPtr<Gio::Permission> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto LockButton::property_permission() -> Glib::PropertyProxy< Glib::RefPtr<Gio::Permission> >
{
  return {this, "permission"};
}

auto LockButton::property_permission() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::Permission> >
{
  return {this, "permission"};
}

auto LockButton::property_text_lock() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "text-lock"};
}

auto LockButton::property_text_lock() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "text-lock"};
}

auto LockButton::property_text_unlock() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "text-unlock"};
}

auto LockButton::property_text_unlock() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "text-unlock"};
}

auto LockButton::property_tooltip_lock() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "tooltip-lock"};
}

auto LockButton::property_tooltip_lock() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "tooltip-lock"};
}

auto LockButton::property_tooltip_unlock() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "tooltip-unlock"};
}

auto LockButton::property_tooltip_unlock() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "tooltip-unlock"};
}

auto LockButton::property_tooltip_not_authorized() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "tooltip-not-authorized"};
}

auto LockButton::property_tooltip_not_authorized() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "tooltip-not-authorized"};
}


} // namespace Gtk


