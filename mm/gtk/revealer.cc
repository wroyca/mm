// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.h>

#include <mm/gtk/revealer.h>
#include <mm/gtk/private/revealer_p.h>


/*
 * Copyright 2013 The gtkmm Development Team
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

void Revealer::unset_child()
{
  gtk_revealer_set_child(gobj(), nullptr);
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkRevealer* object, bool take_copy) -> Gtk::Revealer*
{
  return dynamic_cast<Gtk::Revealer *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto Revealer_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Revealer_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_revealer_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void Revealer_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Revealer_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new Revealer((GtkRevealer*)(o)));

}


/* The implementation: */

Revealer::Revealer(const Glib::ConstructParams& construct_params)
:
  Gtk::Widget(construct_params)
{
  }

Revealer::Revealer(GtkRevealer* castitem)
:
  Gtk::Widget((GtkWidget*)(castitem))
{
  }


Revealer::Revealer(Revealer&& src) noexcept
: Gtk::Widget(std::move(src))
{}

auto Revealer::operator=(Revealer&& src) noexcept -> Revealer&
{
  Gtk::Widget::operator=(std::move(src));
  return *this;
}

Revealer::~Revealer() noexcept
{
  destroy_();
}

Revealer::CppClassType Revealer::revealer_class_; // initialize static member

auto Revealer::get_type() -> GType
{
  return revealer_class_.init().get_type();
}


auto Revealer::get_base_type() -> GType
{
  return gtk_revealer_get_type();
}


Revealer::Revealer()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::Widget(Glib::ConstructParams(revealer_class_.init()))
{


}

auto Revealer::get_reveal_child() const -> bool
{
  return gtk_revealer_get_reveal_child(const_cast<GtkRevealer*>(gobj()));
}

void Revealer::set_reveal_child(bool reveal_child)
{
  gtk_revealer_set_reveal_child(gobj(), static_cast<int>(reveal_child));
}

auto Revealer::get_child_revealed() const -> bool
{
  return gtk_revealer_get_child_revealed(const_cast<GtkRevealer*>(gobj()));
}

auto Revealer::get_transition_duration() const -> guint
{
  return gtk_revealer_get_transition_duration(const_cast<GtkRevealer*>(gobj()));
}

void Revealer::set_transition_duration(guint duration)
{
  gtk_revealer_set_transition_duration(gobj(), duration);
}

auto Revealer::get_transition_type() const -> RevealerTransitionType
{
  return static_cast<RevealerTransitionType>(gtk_revealer_get_transition_type(const_cast<GtkRevealer*>(gobj())));
}

void Revealer::set_transition_type(RevealerTransitionType transition)
{
  gtk_revealer_set_transition_type(gobj(), static_cast<GtkRevealerTransitionType>(transition));
}

void Revealer::set_child(Widget& child)
{
  gtk_revealer_set_child(gobj(), (child).gobj());
}

auto Revealer::get_child() -> Widget*
{
  return Glib::wrap(gtk_revealer_get_child(gobj()));
}

auto Revealer::get_child() const -> const Widget*
{
  return const_cast<Revealer*>(this)->get_child();
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<RevealerTransitionType>::value,
  "Type RevealerTransitionType cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Revealer::property_transition_type() -> Glib::PropertyProxy< RevealerTransitionType >
{
  return Glib::PropertyProxy< RevealerTransitionType >(this, "transition-type");
}

auto Revealer::property_transition_type() const -> Glib::PropertyProxy_ReadOnly< RevealerTransitionType >
{
  return Glib::PropertyProxy_ReadOnly< RevealerTransitionType >(this, "transition-type");
}

auto Revealer::property_transition_duration() -> Glib::PropertyProxy< guint >
{
  return Glib::PropertyProxy< guint >(this, "transition-duration");
}

auto Revealer::property_transition_duration() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return Glib::PropertyProxy_ReadOnly< guint >(this, "transition-duration");
}

auto Revealer::property_reveal_child() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "reveal-child");
}

auto Revealer::property_reveal_child() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "reveal-child");
}

auto Revealer::property_child_revealed() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "child-revealed");
}

auto Revealer::property_child() -> Glib::PropertyProxy< Widget* >
{
  return Glib::PropertyProxy< Widget* >(this, "child");
}

auto Revealer::property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >
{
  return Glib::PropertyProxy_ReadOnly< Widget* >(this, "child");
}


} // namespace Gtk


