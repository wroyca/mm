


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/assistantpage.hxx>
#include <libmm-gtk/assistantpage_p.hxx>


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

#include <libmm-gtk/widget.hxx>
#include <gtk/gtk.h>

using Type = Gtk::AssistantPage::Type;

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Gtk::AssistantPage::Type>::value_type() -> GType
{
  return gtk_assistant_page_type_get_type();
}


namespace Glib
{

auto wrap(GtkAssistantPage* object, const bool take_copy) -> RefPtr<Gtk::AssistantPage>
{
  return Glib::make_refptr_for_instance<Gtk::AssistantPage>( dynamic_cast<Gtk::AssistantPage*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto AssistantPage_Class::init() -> const Class&
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


auto AssistantPage_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto AssistantPage_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new AssistantPage((GtkAssistantPage*)object);
}


/* The implementation: */

auto AssistantPage::gobj_copy() -> GtkAssistantPage*
{
  reference();
  return gobj();
}

AssistantPage::AssistantPage(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

AssistantPage::AssistantPage(GtkAssistantPage* castitem)
: Object((GObject*)castitem)
{}


AssistantPage::AssistantPage(AssistantPage&& src) noexcept
: Object(std::move(src))
{}

auto AssistantPage::operator=(AssistantPage&& src) noexcept -> AssistantPage&
{
  Object::operator=(std::move(src));
  return *this;
}


AssistantPage::~AssistantPage() noexcept = default;

AssistantPage::CppClassType AssistantPage::assistantpage_class_; // initialize static member

auto AssistantPage::get_type() -> GType
{
  return assistantpage_class_.init().get_type();
}


auto AssistantPage::get_base_type() -> GType
{
  return gtk_assistant_page_get_type();
}


auto AssistantPage::get_child() -> Widget*
{
  return Glib::wrap(gtk_assistant_page_get_child(gobj()));
}

auto AssistantPage::get_child() const -> const Widget*
{
  return const_cast<AssistantPage*>(this)->get_child();
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Type>::value,
  "Type Type cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto AssistantPage::property_page_type() -> Glib::PropertyProxy< Type >
{
  return {this, "page-type"};
}

auto AssistantPage::property_page_type() const -> Glib::PropertyProxy_ReadOnly< Type >
{
  return {this, "page-type"};
}

auto AssistantPage::property_title() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "title"};
}

auto AssistantPage::property_title() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "title"};
}

auto AssistantPage::property_complete() -> Glib::PropertyProxy< bool >
{
  return {this, "complete"};
}

auto AssistantPage::property_complete() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "complete"};
}

auto AssistantPage::property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >
{
  return {this, "child"};
}


} // namespace Gtk

