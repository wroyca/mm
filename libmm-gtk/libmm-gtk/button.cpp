


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/button.hpp>
#include <libmm-gtk/button_p.hpp>


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
#include <libmm-gtk/image.hpp>

namespace Gtk
{

Button::Button(const Glib::ustring& label, const bool mnemonic)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(button_class_.init(), "label",label.c_str(),"use_underline",gboolean(mnemonic), nullptr))
{}

auto Button::set_image_from_icon_name (
  const Glib::ustring &icon_name, const IconSize size, const bool use_fallback) -> void
{
  // It would be possible to create a Gtk::Image and add it with Container::add()
  // instead of calling set_icon_name(), but only set_icon_name() sets style classes
  // appropriately for a button with an icon.

  set_icon_name(icon_name);
  if (size == IconSize::INHERIT && !use_fallback)
    return;

  const auto image = dynamic_cast<Image*>(get_child());
  if (image)
  {
    image->set_from_icon_name(icon_name);
    image->set_icon_size(size);
    image->property_use_fallback() = use_fallback;
  }
}

auto Button::unset_child () -> void
{
  gtk_button_set_child(gobj(), nullptr);
}

} // namespace Gtk

namespace
{


const Glib::SignalProxyInfo Button_signal_clicked_info =
{
  "clicked",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkButton* object, const bool take_copy) -> Gtk::Button*
{
  return dynamic_cast<Gtk::Button *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto Button_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Button_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_button_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Actionable::add_interface(get_type());

  }

  return *this;
}


auto Button_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


  klass->clicked = &clicked_callback;
}


auto Button_Class::clicked_callback (GtkButton *self) -> void
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
        obj->on_clicked();
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
  if(base && base->clicked)
    (*base->clicked)(self);
}


auto Button_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new Button((GtkButton*)o));

}


/* The implementation: */

Button::Button(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

Button::Button(GtkButton* castitem)
: Widget((GtkWidget*)castitem)
{
  }


Button::Button(Button&& src) noexcept
: Widget(std::move(src))
  , Actionable(std::move(src))
{}

auto Button::operator=(Button&& src) noexcept -> Button&
{
  Widget::operator=(std::move(src));
  Actionable::operator=(std::move(src));
  return *this;
}

Button::~Button() noexcept
{
  destroy_();
}

Button::CppClassType Button::button_class_; // initialize static member

auto Button::get_type() -> GType
{
  return button_class_.init().get_type();
}


auto Button::get_base_type() -> GType
{
  return gtk_button_get_type();
}


Button::Button()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(button_class_.init()))
{


}

auto Button::set_has_frame (
  const bool has_frame) -> void
{
  gtk_button_set_has_frame(gobj(), has_frame);
}

auto Button::get_has_frame() const -> bool
{
  return gtk_button_get_has_frame(const_cast<GtkButton*>(gobj()));
}

auto Button::set_label (const Glib::ustring &label) -> void
{
  gtk_button_set_label(gobj(), label.c_str());
}

auto Button::get_label() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_button_get_label(const_cast<GtkButton*>(gobj())));
}

auto Button::set_use_underline (
  const bool use_underline) -> void
{
  gtk_button_set_use_underline(gobj(), use_underline);
}

auto Button::get_use_underline() const -> bool
{
  return gtk_button_get_use_underline(const_cast<GtkButton*>(gobj()));
}

auto Button::set_icon_name (const Glib::ustring &icon_name) -> void
{
  gtk_button_set_icon_name(gobj(), icon_name.c_str());
}

auto Button::get_icon_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_button_get_icon_name(const_cast<GtkButton*>(gobj())));
}

auto Button::set_child (Widget &child) -> void
{
  gtk_button_set_child(gobj(), child.gobj());
}

auto Button::get_child() -> Widget*
{
  return Glib::wrap(gtk_button_get_child(gobj()));
}

auto Button::get_child() const -> const Widget*
{
  return const_cast<Button*>(this)->get_child();
}


auto Button::signal_clicked() -> Glib::SignalProxy<void()>
{
  return {this, &Button_signal_clicked_info};
}


auto Button::property_label() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "label"};
}

auto Button::property_label() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "label"};
}

auto Button::property_has_frame() -> Glib::PropertyProxy< bool >
{
  return {this, "has-frame"};
}

auto Button::property_has_frame() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "has-frame"};
}

auto Button::property_use_underline() -> Glib::PropertyProxy< bool >
{
  return {this, "use-underline"};
}

auto Button::property_use_underline() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "use-underline"};
}

auto Button::property_icon_name() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "icon-name"};
}

auto Button::property_icon_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "icon-name"};
}

auto Button::property_child() -> Glib::PropertyProxy< Widget* >
{
  return {this, "child"};
}

auto Button::property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >
{
  return {this, "child"};
}


auto Button::on_clicked () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->clicked)
    (*base->clicked)(gobj());
}


} // namespace Gtk


