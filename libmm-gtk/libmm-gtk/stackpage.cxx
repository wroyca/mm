


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/stackpage.hxx>
#include <libmm-gtk/stackpage_p.hxx>


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

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkStackPage* object, const bool take_copy) -> RefPtr<Gtk::StackPage>
{
  return Glib::make_refptr_for_instance<Gtk::StackPage>( dynamic_cast<Gtk::StackPage*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto StackPage_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &StackPage_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_stack_page_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Accessible::add_interface(get_type());

  }

  return *this;
}


auto StackPage_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto StackPage_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new StackPage((GtkStackPage*)object);
}


/* The implementation: */

auto StackPage::gobj_copy() -> GtkStackPage*
{
  reference();
  return gobj();
}

StackPage::StackPage(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

StackPage::StackPage(GtkStackPage* castitem)
: Object((GObject*)castitem)
{}


StackPage::StackPage(StackPage&& src) noexcept
: Object(std::move(src))
  , Accessible(std::move(src))
{}

auto StackPage::operator=(StackPage&& src) noexcept -> StackPage&
{
  Object::operator=(std::move(src));
  Accessible::operator=(std::move(src));
  return *this;
}


StackPage::~StackPage() noexcept = default;

StackPage::CppClassType StackPage::stackpage_class_; // initialize static member

auto StackPage::get_type() -> GType
{
  return stackpage_class_.init().get_type();
}


auto StackPage::get_base_type() -> GType
{
  return gtk_stack_page_get_type();
}


auto StackPage::get_child() -> Widget*
{
  return Glib::wrap(gtk_stack_page_get_child(gobj()));
}

auto StackPage::get_child() const -> const Widget*
{
  return const_cast<StackPage*>(this)->get_child();
}

auto StackPage::get_visible() const -> bool
{
  return gtk_stack_page_get_visible(const_cast<GtkStackPage*>(gobj()));
}

auto StackPage::set_visible (
  const bool visible) -> void
{
  gtk_stack_page_set_visible(gobj(), visible);
}

auto StackPage::get_needs_attention() const -> bool
{
  return gtk_stack_page_get_needs_attention(const_cast<GtkStackPage*>(gobj()));
}

auto StackPage::set_needs_attention (
  const bool setting) -> void
{
  gtk_stack_page_set_needs_attention(gobj(), setting);
}

auto StackPage::get_use_underline() const -> bool
{
  return gtk_stack_page_get_use_underline(const_cast<GtkStackPage*>(gobj()));
}

auto StackPage::set_use_underline (
  const bool setting) -> void
{
  gtk_stack_page_set_use_underline(gobj(), setting);
}

auto StackPage::get_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_stack_page_get_name(const_cast<GtkStackPage*>(gobj())));
}

auto StackPage::set_name (const Glib::ustring &setting) -> void
{
  gtk_stack_page_set_name(gobj(), setting.c_str());
}

auto StackPage::get_title() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_stack_page_get_title(const_cast<GtkStackPage*>(gobj())));
}

auto StackPage::set_title (const Glib::ustring &setting) -> void
{
  gtk_stack_page_set_title(gobj(), setting.c_str());
}

auto StackPage::get_icon_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_stack_page_get_icon_name(const_cast<GtkStackPage*>(gobj())));
}

auto StackPage::set_icon_name (const Glib::ustring &setting) -> void
{
  gtk_stack_page_set_icon_name(gobj(), setting.c_str());
}


auto StackPage::property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >
{
  return {this, "child"};
}

auto StackPage::property_name() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "name"};
}

auto StackPage::property_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "name"};
}

auto StackPage::property_title() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "title"};
}

auto StackPage::property_title() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "title"};
}

auto StackPage::property_icon_name() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "icon-name"};
}

auto StackPage::property_icon_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "icon-name"};
}

auto StackPage::property_needs_attention() -> Glib::PropertyProxy< bool >
{
  return {this, "needs-attention"};
}

auto StackPage::property_needs_attention() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "needs-attention"};
}

auto StackPage::property_visible() -> Glib::PropertyProxy< bool >
{
  return {this, "visible"};
}

auto StackPage::property_visible() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "visible"};
}

auto StackPage::property_use_underline() -> Glib::PropertyProxy< bool >
{
  return {this, "use-underline"};
}

auto StackPage::property_use_underline() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "use-underline"};
}


} // namespace Gtk


