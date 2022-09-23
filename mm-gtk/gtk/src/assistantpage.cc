// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gtkmm/assistantpage.h>
#include <gtkmm/private/assistantpage_p.h>


/* Copyright (C) 2019 The gtkmm Development Team
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

#include <gtkmm/widget.h>
#include <gtk/gtk.h>

using Type = Gtk::AssistantPage::Type;

namespace
{
} // anonymous namespace

// static
GType Glib::Value<Gtk::AssistantPage::Type>::value_type()
{
  return gtk_assistant_page_type_get_type();
}


namespace Glib
{

Glib::RefPtr<Gtk::AssistantPage> wrap(GtkAssistantPage* object, bool take_copy)
{
  return Glib::make_refptr_for_instance<Gtk::AssistantPage>( dynamic_cast<Gtk::AssistantPage*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& AssistantPage_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &AssistantPage_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_assistant_page_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void AssistantPage_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* AssistantPage_Class::wrap_new(GObject* object)
{
  return new AssistantPage((GtkAssistantPage*)object);
}


/* The implementation: */

GtkAssistantPage* AssistantPage::gobj_copy()
{
  reference();
  return gobj();
}

AssistantPage::AssistantPage(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

AssistantPage::AssistantPage(GtkAssistantPage* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


AssistantPage::AssistantPage(AssistantPage&& src) noexcept
: Glib::Object(std::move(src))
{}

AssistantPage& AssistantPage::operator=(AssistantPage&& src) noexcept
{
  Glib::Object::operator=(std::move(src));
  return *this;
}


AssistantPage::~AssistantPage() noexcept
{}


AssistantPage::CppClassType AssistantPage::assistantpage_class_; // initialize static member

GType AssistantPage::get_type()
{
  return assistantpage_class_.init().get_type();
}


GType AssistantPage::get_base_type()
{
  return gtk_assistant_page_get_type();
}


Widget* AssistantPage::get_child()
{
  return Glib::wrap(gtk_assistant_page_get_child(gobj()));
}

const Widget* AssistantPage::get_child() const
{
  return const_cast<AssistantPage*>(this)->get_child();
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Type>::value,
  "Type Type cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

Glib::PropertyProxy< Type > AssistantPage::property_page_type() 
{
  return Glib::PropertyProxy< Type >(this, "page-type");
}

Glib::PropertyProxy_ReadOnly< Type > AssistantPage::property_page_type() const
{
  return Glib::PropertyProxy_ReadOnly< Type >(this, "page-type");
}

Glib::PropertyProxy< Glib::ustring > AssistantPage::property_title() 
{
  return Glib::PropertyProxy< Glib::ustring >(this, "title");
}

Glib::PropertyProxy_ReadOnly< Glib::ustring > AssistantPage::property_title() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "title");
}

Glib::PropertyProxy< bool > AssistantPage::property_complete() 
{
  return Glib::PropertyProxy< bool >(this, "complete");
}

Glib::PropertyProxy_ReadOnly< bool > AssistantPage::property_complete() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "complete");
}

Glib::PropertyProxy_ReadOnly< Widget* > AssistantPage::property_child() const
{
  return Glib::PropertyProxy_ReadOnly< Widget* >(this, "child");
}


} // namespace Gtk


