


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/togglebutton.hxx>
#include <libmm-gtk/togglebutton_p.hxx>


/*
 * Copyright 1998-2002 The gtkmm Development Team
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

ToggleButton::ToggleButton(const Glib::ustring& label, const bool mnemonic)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Button(Glib::ConstructParams(togglebutton_class_.init(), "label",label.c_str(),"use_underline",gboolean(mnemonic), nullptr))
{}

auto ToggleButton::unset_group () -> void
{
  gtk_toggle_button_set_group(gobj(), nullptr);
}

} // namespace Gtk

namespace
{


const Glib::SignalProxyInfo ToggleButton_signal_toggled_info =
{
  "toggled",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkToggleButton* object, const bool take_copy) -> Gtk::ToggleButton*
{
  return dynamic_cast<Gtk::ToggleButton *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto ToggleButton_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ToggleButton_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_toggle_button_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto ToggleButton_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


  klass->toggled = &toggled_callback;
}


auto ToggleButton_Class::toggled_callback (GtkToggleButton *self) -> void
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
        obj->on_toggled();
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->toggled)
    (*base->toggled)(self);
}


auto ToggleButton_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new ToggleButton((GtkToggleButton*)o));

}


/* The implementation: */

ToggleButton::ToggleButton(const Glib::ConstructParams& construct_params)
: Button(construct_params)
{
  }

ToggleButton::ToggleButton(GtkToggleButton* castitem)
: Button((GtkButton*)castitem)
{
  }


ToggleButton::ToggleButton(ToggleButton&& src) noexcept
: Button(std::move(src))
{}

auto ToggleButton::operator=(ToggleButton&& src) noexcept -> ToggleButton&
{
  Button::operator=(std::move(src));
  return *this;
}

ToggleButton::~ToggleButton() noexcept
{
  destroy_();
}

ToggleButton::CppClassType ToggleButton::togglebutton_class_; // initialize static member

auto ToggleButton::get_type() -> GType
{
  return togglebutton_class_.init().get_type();
}


auto ToggleButton::get_base_type() -> GType
{
  return gtk_toggle_button_get_type();
}


ToggleButton::ToggleButton()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Button(Glib::ConstructParams(togglebutton_class_.init()))
{


}

auto ToggleButton::set_active (
  const bool is_active) -> void
{
  gtk_toggle_button_set_active(gobj(), is_active);
}

auto ToggleButton::get_active() const -> bool
{
  return gtk_toggle_button_get_active(const_cast<GtkToggleButton*>(gobj()));
}

auto ToggleButton::toggled () -> void
{
  gtk_toggle_button_toggled(gobj());
}

auto ToggleButton::set_group (ToggleButton &group) -> void
{
  gtk_toggle_button_set_group(gobj(), group.gobj());
}


auto ToggleButton::signal_toggled() -> Glib::SignalProxy<void()>
{
  return {this, &ToggleButton_signal_toggled_info};
}


auto ToggleButton::property_active() -> Glib::PropertyProxy< bool >
{
  return {this, "active"};
}

auto ToggleButton::property_active() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "active"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<ToggleButton*>::value,
  "Type ToggleButton* cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto ToggleButton::property_group() -> Glib::PropertyProxy_WriteOnly< ToggleButton* >
{
  return {this, "group"};
}


auto ToggleButton::on_toggled () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->toggled)
    (*base->toggled)(gobj());
}


} // namespace Gtk

