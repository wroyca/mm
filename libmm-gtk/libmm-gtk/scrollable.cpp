


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/scrollable.hpp>
#include <mm/gtk/private/scrollable_p.hpp>


/* Copyright 2010 The gtkmm Development Team
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

using Policy = Gtk::Scrollable::Policy;

namespace Gtk
{

// This vfunc callback is custom implemented because we want the output
// argument of the C++ vfunc to be Gtk::Border& (not GtkBorder* or GtkBorder&),
// and when a GtkBorder is wrapped in a Gtk::Border, the Gtk::Border takes
// ownership of the GtkBorder or a copy of it. The wrapped copy must be assigned
// to the original GtkBorder after the call to the C++ vfunc.
auto Scrollable_Class::get_border_vfunc_callback(GtkScrollable* self, GtkBorder* border) -> gboolean
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        Border border_copy(border, true);
        const auto result = obj->get_border_vfunc(border_copy);
        if (border)
          *border = *border_copy.gobj();
        return result;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->get_border)
    return (*base->get_border)(self, border);

  using RType = gboolean;
  return RType();
}

auto Scrollable::unset_hadjustment () -> void
{
  gtk_scrollable_set_hadjustment(gobj(), nullptr);
}

auto Scrollable::unset_vadjustment () -> void
{
  gtk_scrollable_set_vadjustment(gobj(), nullptr);
}

} //namespace Gtk

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Gtk::Scrollable::Policy>::value_type() -> GType
{
  return gtk_scrollable_policy_get_type();
}


namespace Glib
{

auto wrap(GtkScrollable* object, const bool take_copy) -> RefPtr<Gtk::Scrollable>
{
  return Glib::make_refptr_for_instance<Gtk::Scrollable>( Glib::wrap_auto_interface<Gtk::Scrollable> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gtk
{


/* The *_Class implementation: */

auto Scrollable_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &Scrollable_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = gtk_scrollable_get_type();
  }

  return *this;
}

auto Scrollable_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);

  klass->get_border = &get_border_vfunc_callback;

}


auto Scrollable_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Scrollable((GtkScrollable*)object);
}


/* The implementation: */

Scrollable::Scrollable()
: Interface(scrollable_class_.init())
{}

Scrollable::Scrollable(GtkScrollable* castitem)
: Interface((GObject*)castitem)
{}

Scrollable::Scrollable(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

Scrollable::Scrollable(Scrollable&& src) noexcept
: Interface(std::move(src))
{}

auto Scrollable::operator=(Scrollable&& src) noexcept -> Scrollable&
{
  Interface::operator=(std::move(src));
  return *this;
}

Scrollable::~Scrollable() noexcept = default;

// static
auto Scrollable::add_interface (
  const GType gtype_implementer) -> void
{
  scrollable_class_.init().add_interface(gtype_implementer);
}

Scrollable::CppClassType Scrollable::scrollable_class_; // initialize static member

auto Scrollable::get_type() -> GType
{
  return scrollable_class_.init().get_type();
}


auto Scrollable::get_base_type() -> GType
{
  return gtk_scrollable_get_type();
}


auto Scrollable::get_hadjustment() -> Glib::RefPtr<Adjustment>
{
  auto retvalue = Glib::wrap(gtk_scrollable_get_hadjustment(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Scrollable::get_hadjustment() const -> Glib::RefPtr<const Adjustment>
{
  return const_cast<Scrollable*>(this)->get_hadjustment();
}

auto Scrollable::set_hadjustment (const Glib::RefPtr <Adjustment> &hadjustment) -> void
{
  gtk_scrollable_set_hadjustment(gobj(), Glib::unwrap(hadjustment));
}

auto Scrollable::get_vadjustment() -> Glib::RefPtr<Adjustment>
{
  auto retvalue = Glib::wrap(gtk_scrollable_get_vadjustment(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Scrollable::get_vadjustment() const -> Glib::RefPtr<const Adjustment>
{
  auto retvalue = Glib::wrap(gtk_scrollable_get_vadjustment(const_cast<GtkScrollable*>(gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Scrollable::set_vadjustment (const Glib::RefPtr <Adjustment> &vadjustment) -> void
{
  gtk_scrollable_set_vadjustment(gobj(), Glib::unwrap(vadjustment));
}

auto Scrollable::get_hscroll_policy() const -> Policy
{
  return static_cast<Policy>(gtk_scrollable_get_hscroll_policy(const_cast<GtkScrollable*>(gobj())));
}

auto Scrollable::set_hscroll_policy (Policy policy) -> void
{
  gtk_scrollable_set_hscroll_policy(gobj(), static_cast<GtkScrollablePolicy>(policy));
}

auto Scrollable::get_vscroll_policy() const -> Policy
{
  return static_cast<Policy>(gtk_scrollable_get_vscroll_policy(const_cast<GtkScrollable*>(gobj())));
}

auto Scrollable::set_vscroll_policy (Policy policy) -> void
{
  gtk_scrollable_set_vscroll_policy(gobj(), static_cast<GtkScrollablePolicy>(policy));
}

auto Scrollable::get_border(Border& border) const -> bool
{
  return gtk_scrollable_get_border(const_cast<GtkScrollable*>(gobj()), border.gobj());
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Adjustment>>::value,
  "Type Glib::RefPtr<Adjustment> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Scrollable::property_hadjustment() -> Glib::PropertyProxy< Glib::RefPtr<Adjustment> >
{
  return {this, "hadjustment"};
}

auto Scrollable::property_hadjustment() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Adjustment> >
{
  return {this, "hadjustment"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Adjustment>>::value,
  "Type Glib::RefPtr<Adjustment> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Scrollable::property_vadjustment() -> Glib::PropertyProxy< Glib::RefPtr<Adjustment> >
{
  return {this, "vadjustment"};
}

auto Scrollable::property_vadjustment() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Adjustment> >
{
  return {this, "vadjustment"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Policy>::value,
  "Type Policy cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Scrollable::property_hscroll_policy() -> Glib::PropertyProxy< Policy >
{
  return {this, "hscroll-policy"};
}

auto Scrollable::property_hscroll_policy() const -> Glib::PropertyProxy_ReadOnly< Policy >
{
  return {this, "hscroll-policy"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Policy>::value,
  "Type Policy cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Scrollable::property_vscroll_policy() -> Glib::PropertyProxy< Policy >
{
  return {this, "vscroll-policy"};
}

auto Scrollable::property_vscroll_policy() const -> Glib::PropertyProxy_ReadOnly< Policy >
{
  return {this, "vscroll-policy"};
}


auto Scrollable::get_border_vfunc(Border& border) const -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->get_border)
  {
    const bool retval((*base->get_border)(const_cast<GtkScrollable*>(gobj()),border.gobj()));
    return retval;
  }

  using RType = bool;
  return RType();
}


} // namespace Gtk


