


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/volumebutton.hpp>
#include <mm/gtk/private/volumebutton_p.hpp>


/*
 * Copyright 2007 The gtkmm Development Team
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


} // namespace Gtk


namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkVolumeButton* object, const bool take_copy) -> Gtk::VolumeButton*
{
  return dynamic_cast<Gtk::VolumeButton *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto VolumeButton_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &VolumeButton_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_volume_button_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto VolumeButton_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto VolumeButton_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new VolumeButton((GtkVolumeButton*)o));

}


/* The implementation: */

VolumeButton::VolumeButton(const Glib::ConstructParams& construct_params)
: ScaleButton(construct_params)
{
  }

VolumeButton::VolumeButton(GtkVolumeButton* castitem)
: ScaleButton((GtkScaleButton*)castitem)
{
  }


VolumeButton::VolumeButton(VolumeButton&& src) noexcept
: ScaleButton(std::move(src))
{}

auto VolumeButton::operator=(VolumeButton&& src) noexcept -> VolumeButton&
{
  ScaleButton::operator=(std::move(src));
  return *this;
}

VolumeButton::~VolumeButton() noexcept
{
  destroy_();
}

VolumeButton::CppClassType VolumeButton::volumebutton_class_; // initialize static member

auto VolumeButton::get_type() -> GType
{
  return volumebutton_class_.init().get_type();
}


auto VolumeButton::get_base_type() -> GType
{
  return gtk_volume_button_get_type();
}


VolumeButton::VolumeButton()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
ScaleButton(Glib::ConstructParams(volumebutton_class_.init()))
{


}


auto VolumeButton::property_use_symbolic() -> Glib::PropertyProxy< bool >
{
  return {this, "use-symbolic"};
}

auto VolumeButton::property_use_symbolic() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "use-symbolic"};
}


} // namespace Gtk


