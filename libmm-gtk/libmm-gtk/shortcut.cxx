


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/shortcut.hxx>
#include <libmm-gtk/shortcut_p.hxx>


/* Copyright (C) 2020 The gtkmm Development Team
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

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkShortcut* object, const bool take_copy) -> RefPtr<Gtk::Shortcut>
{
  return Glib::make_refptr_for_instance<Gtk::Shortcut>( dynamic_cast<Gtk::Shortcut*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto Shortcut_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Shortcut_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_shortcut_get_type();

  }

  return *this;
}


auto Shortcut_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Shortcut_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Shortcut((GtkShortcut*)object);
}


/* The implementation: */

auto Shortcut::gobj_copy() -> GtkShortcut*
{
  reference();
  return gobj();
}

Shortcut::Shortcut(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

Shortcut::Shortcut(GtkShortcut* castitem)
: Object((GObject*)castitem)
{}


Shortcut::Shortcut(Shortcut&& src) noexcept
: Object(std::move(src))
{}

auto Shortcut::operator=(Shortcut&& src) noexcept -> Shortcut&
{
  Object::operator=(std::move(src));
  return *this;
}


Shortcut::~Shortcut() noexcept = default;

Shortcut::CppClassType Shortcut::shortcut_class_; // initialize static member

auto Shortcut::get_type() -> GType
{
  return shortcut_class_.init().get_type();
}


auto Shortcut::get_base_type() -> GType
{
  return gtk_shortcut_get_type();
}


Shortcut::Shortcut(const Glib::RefPtr<const ShortcutTrigger>& trigger, const Glib::RefPtr<const ShortcutAction>& action)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(shortcut_class_.init(), "trigger", Glib::unwrap(trigger), "action", Glib::unwrap(action), nullptr))
{


}

auto Shortcut::create(const Glib::RefPtr<const ShortcutTrigger>& trigger, const Glib::RefPtr<const ShortcutAction>& action) -> Glib::RefPtr<Shortcut>
{
  return Glib::make_refptr_for_instance<Shortcut>( new Shortcut(trigger, action) );
}

auto Shortcut::get_trigger() const -> Glib::RefPtr<ShortcutTrigger>
{
  auto retvalue = Glib::wrap(gtk_shortcut_get_trigger(const_cast<GtkShortcut*>(gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Shortcut::set_trigger (const Glib::RefPtr <const ShortcutTrigger> &trigger) -> void
{
  gtk_shortcut_set_trigger(gobj(), unwrap_copy(std::const_pointer_cast<ShortcutTrigger>(trigger)));
}

auto Shortcut::get_action() const -> Glib::RefPtr<ShortcutAction>
{
  auto retvalue = Glib::wrap(gtk_shortcut_get_action(const_cast<GtkShortcut*>(gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Shortcut::set_trigger (const Glib::RefPtr <const ShortcutAction> &action) -> void
{
  gtk_shortcut_set_action(gobj(), unwrap_copy(std::const_pointer_cast<ShortcutAction>(action)));
}

auto Shortcut::get_arguments() const -> Glib::VariantBase
{
  return Glib::wrap(gtk_shortcut_get_arguments(const_cast<GtkShortcut*>(gobj())), true);
}

auto Shortcut::set_arguments (const Glib::VariantBase &args) const -> void
{
  gtk_shortcut_set_arguments(const_cast<GtkShortcut*>(gobj()), const_cast<GVariant*>(args.gobj()));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<ShortcutTrigger>>::value,
  "Type Glib::RefPtr<ShortcutTrigger> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Shortcut::property_trigger() -> Glib::PropertyProxy< Glib::RefPtr<ShortcutTrigger> >
{
  return {this, "trigger"};
}

auto Shortcut::property_trigger() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ShortcutTrigger> >
{
  return {this, "trigger"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<ShortcutAction>>::value,
  "Type Glib::RefPtr<ShortcutAction> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Shortcut::property_action() -> Glib::PropertyProxy< Glib::RefPtr<ShortcutAction> >
{
  return {this, "action"};
}

auto Shortcut::property_action() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ShortcutAction> >
{
  return {this, "action"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::VariantBase>::value,
  "Type Glib::VariantBase cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Shortcut::property_arguments() -> Glib::PropertyProxy< Glib::VariantBase >
{
  return {this, "arguments"};
}

auto Shortcut::property_arguments() const -> Glib::PropertyProxy_ReadOnly< Glib::VariantBase >
{
  return {this, "arguments"};
}


} // namespace Gtk


