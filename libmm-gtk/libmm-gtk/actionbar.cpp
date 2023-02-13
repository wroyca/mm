


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/actionbar.hpp>
#include <libmm-gtk/actionbar_p.hpp>


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

auto ActionBar::unset_center_widget () -> void
{
  gtk_action_bar_set_center_widget(gobj(), nullptr);
}

} // namespace Gtk


namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkActionBar* object, const bool take_copy) -> Gtk::ActionBar*
{
  return dynamic_cast<Gtk::ActionBar *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto ActionBar_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ActionBar_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_action_bar_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto ActionBar_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ActionBar_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new ActionBar((GtkActionBar*)o));

}


/* The implementation: */

ActionBar::ActionBar(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

ActionBar::ActionBar(GtkActionBar* castitem)
: Widget((GtkWidget*)castitem)
{
  }


ActionBar::ActionBar(ActionBar&& src) noexcept
: Widget(std::move(src))
{}

auto ActionBar::operator=(ActionBar&& src) noexcept -> ActionBar&
{
  Widget::operator=(std::move(src));
  return *this;
}

ActionBar::~ActionBar() noexcept
{
  destroy_();
}

ActionBar::CppClassType ActionBar::actionbar_class_; // initialize static member

auto ActionBar::get_type() -> GType
{
  return actionbar_class_.init().get_type();
}


auto ActionBar::get_base_type() -> GType
{
  return gtk_action_bar_get_type();
}


ActionBar::ActionBar()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(actionbar_class_.init()))
{


}

auto ActionBar::pack_start (
  Widget &child) -> void
{
  gtk_action_bar_pack_start(gobj(), child.gobj());
}

auto ActionBar::pack_end (
  Widget &child) -> void
{
  gtk_action_bar_pack_end(gobj(), child.gobj());
}

auto ActionBar::remove (
  Widget &child) -> void
{
  gtk_action_bar_remove(gobj(), child.gobj());
}

auto ActionBar::get_center_widget() -> Widget*
{
  return Glib::wrap(gtk_action_bar_get_center_widget(gobj()));
}

auto ActionBar::get_center_widget() const -> const Widget*
{
  return const_cast<ActionBar*>(this)->get_center_widget();
}

auto ActionBar::set_center_widget (Widget &center_widget) -> void
{
  gtk_action_bar_set_center_widget(gobj(), center_widget.gobj());
}

auto ActionBar::set_revealed (
  const bool revealed) -> void
{
  gtk_action_bar_set_revealed(gobj(), revealed);
}

auto ActionBar::get_revealed() const -> bool
{
  return gtk_action_bar_get_revealed(const_cast<GtkActionBar*>(gobj()));
}


auto ActionBar::property_revealed() -> Glib::PropertyProxy< bool >
{
  return {this, "revealed"};
}

auto ActionBar::property_revealed() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "revealed"};
}


} // namespace Gtk


