


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/viewport.hpp>
#include <mm/gtk/private/viewport_p.hpp>


/*
 * Copyright 2002 The gtkmm Development Team
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

#include <mm/gtk/viewport.hpp>
#include <mm/gtk/adjustment.hpp>
#include <gtk/gtk.h>

namespace Gtk
{

auto Viewport::unset_child () -> void
{
  gtk_viewport_set_child(gobj(), nullptr);
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkViewport* object, const bool take_copy) -> Gtk::Viewport*
{
  return dynamic_cast<Gtk::Viewport *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto Viewport_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Viewport_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_viewport_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Scrollable::add_interface(get_type());

  }

  return *this;
}


auto Viewport_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Viewport_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new Viewport((GtkViewport*)o));

}


/* The implementation: */

Viewport::Viewport(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

Viewport::Viewport(GtkViewport* castitem)
: Widget((GtkWidget*)castitem)
{
  }


Viewport::Viewport(Viewport&& src) noexcept
: Widget(std::move(src))
  , Scrollable(std::move(src))
{}

auto Viewport::operator=(Viewport&& src) noexcept -> Viewport&
{
  Widget::operator=(std::move(src));
  Scrollable::operator=(std::move(src));
  return *this;
}

Viewport::~Viewport() noexcept
{
  destroy_();
}

Viewport::CppClassType Viewport::viewport_class_; // initialize static member

auto Viewport::get_type() -> GType
{
  return viewport_class_.init().get_type();
}


auto Viewport::get_base_type() -> GType
{
  return gtk_viewport_get_type();
}


Viewport::Viewport(const Glib::RefPtr<Adjustment>& hadjustment, const Glib::RefPtr<Adjustment>& vadjustment)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(viewport_class_.init(), "hadjustment", Glib::unwrap(hadjustment), "vadjustment", Glib::unwrap(vadjustment), nullptr))
{


}

auto Viewport::set_scroll_to_focus (
  const bool scroll_to_focus) -> void
{
  gtk_viewport_set_scroll_to_focus(gobj(), scroll_to_focus);
}

auto Viewport::get_scroll_to_focus() const -> bool
{
  return gtk_viewport_get_scroll_to_focus(const_cast<GtkViewport*>(gobj()));
}

auto Viewport::set_child (Widget &child) -> void
{
  gtk_viewport_set_child(gobj(), child.gobj());
}

auto Viewport::get_child() -> Widget*
{
  return Glib::wrap(gtk_viewport_get_child(gobj()));
}

auto Viewport::get_child() const -> const Widget*
{
  return const_cast<Viewport*>(this)->get_child();
}


auto Viewport::property_scroll_to_focus() -> Glib::PropertyProxy< bool >
{
  return {this, "scroll-to-focus"};
}

auto Viewport::property_scroll_to_focus() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "scroll-to-focus"};
}

auto Viewport::property_child() -> Glib::PropertyProxy< Widget* >
{
  return {this, "child"};
}

auto Viewport::property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >
{
  return {this, "child"};
}


} // namespace Gtk


