// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gtkmm/checkbutton.h>
#include <gtkmm/private/checkbutton_p.h>


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

CheckButton::CheckButton(const Glib::ustring& label, bool mnemonic)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::Widget(Glib::ConstructParams(checkbutton_class_.init(), "label",label.c_str(),"use_underline",gboolean(mnemonic), nullptr))
{}

void CheckButton::unset_child()
{
  gtk_check_button_set_child(gobj(), nullptr);
}

void CheckButton::unset_group()
{
  gtk_check_button_set_group(gobj(), nullptr);
}

} // namespace Gtk

namespace
{


static const Glib::SignalProxyInfo CheckButton_signal_toggled_info =
{
  "toggled",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

Gtk::CheckButton* wrap(GtkCheckButton* object, bool take_copy)
{
  return dynamic_cast<Gtk::CheckButton *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& CheckButton_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &CheckButton_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_check_button_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Actionable::add_interface(get_type());

  }

  return *this;
}


void CheckButton_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


  klass->toggled = &toggled_callback;
}


void CheckButton_Class::toggled_callback(GtkCheckButton* self)
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

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


Glib::ObjectBase* CheckButton_Class::wrap_new(GObject* o)
{
  return manage(new CheckButton((GtkCheckButton*)(o)));

}


/* The implementation: */

CheckButton::CheckButton(const Glib::ConstructParams& construct_params)
:
  Gtk::Widget(construct_params)
{
  }

CheckButton::CheckButton(GtkCheckButton* castitem)
:
  Gtk::Widget((GtkWidget*)(castitem))
{
  }


CheckButton::CheckButton(CheckButton&& src) noexcept
: Gtk::Widget(std::move(src))
  , Actionable(std::move(src))
{}

CheckButton& CheckButton::operator=(CheckButton&& src) noexcept
{
  Gtk::Widget::operator=(std::move(src));
  Actionable::operator=(std::move(src));
  return *this;
}

CheckButton::~CheckButton() noexcept
{
  destroy_();
}

CheckButton::CppClassType CheckButton::checkbutton_class_; // initialize static member

GType CheckButton::get_type()
{
  return checkbutton_class_.init().get_type();
}


GType CheckButton::get_base_type()
{
  return gtk_check_button_get_type();
}


CheckButton::CheckButton()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::Widget(Glib::ConstructParams(checkbutton_class_.init()))
{
  

}

void CheckButton::set_inconsistent(bool inconsistent)
{
  gtk_check_button_set_inconsistent(gobj(), static_cast<int>(inconsistent));
}

bool CheckButton::get_inconsistent() const
{
  return gtk_check_button_get_inconsistent(const_cast<GtkCheckButton*>(gobj()));
}

void CheckButton::set_active(bool setting)
{
  gtk_check_button_set_active(gobj(), static_cast<int>(setting));
}

bool CheckButton::get_active() const
{
  return gtk_check_button_get_active(const_cast<GtkCheckButton*>(gobj()));
}

void CheckButton::set_label(const Glib::ustring& label)
{
  gtk_check_button_set_label(gobj(), label.c_str());
}

Glib::ustring CheckButton::get_label() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_check_button_get_label(const_cast<GtkCheckButton*>(gobj())));
}

void CheckButton::set_use_underline(bool setting)
{
  gtk_check_button_set_use_underline(gobj(), static_cast<int>(setting));
}

bool CheckButton::get_use_underline() const
{
  return gtk_check_button_get_use_underline(const_cast<GtkCheckButton*>(gobj()));
}

void CheckButton::set_child(Widget& child)
{
  gtk_check_button_set_child(gobj(), (child).gobj());
}

Widget* CheckButton::get_child()
{
  return Glib::wrap(gtk_check_button_get_child(gobj()));
}

const Widget* CheckButton::get_child() const
{
  return const_cast<CheckButton*>(this)->get_child();
}

void CheckButton::set_group(CheckButton& group)
{
  gtk_check_button_set_group(gobj(), (group).gobj());
}


Glib::SignalProxy<void()> CheckButton::signal_toggled()
{
  return Glib::SignalProxy<void() >(this, &CheckButton_signal_toggled_info);
}


Glib::PropertyProxy< bool > CheckButton::property_active() 
{
  return Glib::PropertyProxy< bool >(this, "active");
}

Glib::PropertyProxy_ReadOnly< bool > CheckButton::property_active() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "active");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<CheckButton*>::value,
  "Type CheckButton* cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

Glib::PropertyProxy_WriteOnly< CheckButton* > CheckButton::property_group() 
{
  return Glib::PropertyProxy_WriteOnly< CheckButton* >(this, "group");
}

Glib::PropertyProxy< Glib::ustring > CheckButton::property_label() 
{
  return Glib::PropertyProxy< Glib::ustring >(this, "label");
}

Glib::PropertyProxy_ReadOnly< Glib::ustring > CheckButton::property_label() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "label");
}

Glib::PropertyProxy< bool > CheckButton::property_inconsistent() 
{
  return Glib::PropertyProxy< bool >(this, "inconsistent");
}

Glib::PropertyProxy_ReadOnly< bool > CheckButton::property_inconsistent() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "inconsistent");
}

Glib::PropertyProxy< bool > CheckButton::property_use_underline() 
{
  return Glib::PropertyProxy< bool >(this, "use-underline");
}

Glib::PropertyProxy_ReadOnly< bool > CheckButton::property_use_underline() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "use-underline");
}

Glib::PropertyProxy< Widget* > CheckButton::property_child() 
{
  return Glib::PropertyProxy< Widget* >(this, "child");
}

Glib::PropertyProxy_ReadOnly< Widget* > CheckButton::property_child() const
{
  return Glib::PropertyProxy_ReadOnly< Widget* >(this, "child");
}


void Gtk::CheckButton::on_toggled()
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->toggled)
    (*base->toggled)(gobj());
}


} // namespace Gtk


