


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/notebookpage.hxx>
#include <libmm-gtk/notebookpage_p.hxx>


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

auto wrap(GtkNotebookPage* object, const bool take_copy) -> RefPtr<Gtk::NotebookPage>
{
  return Glib::make_refptr_for_instance<Gtk::NotebookPage>( dynamic_cast<Gtk::NotebookPage*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto NotebookPage_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &NotebookPage_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_notebook_page_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto NotebookPage_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto NotebookPage_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new NotebookPage((GtkNotebookPage*)object);
}


/* The implementation: */

auto NotebookPage::gobj_copy() -> GtkNotebookPage*
{
  reference();
  return gobj();
}

NotebookPage::NotebookPage(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

NotebookPage::NotebookPage(GtkNotebookPage* castitem)
: Object((GObject*)castitem)
{}


NotebookPage::NotebookPage(NotebookPage&& src) noexcept
: Object(std::move(src))
{}

auto NotebookPage::operator=(NotebookPage&& src) noexcept -> NotebookPage&
{
  Object::operator=(std::move(src));
  return *this;
}


NotebookPage::~NotebookPage() noexcept = default;

NotebookPage::CppClassType NotebookPage::notebookpage_class_; // initialize static member

auto NotebookPage::get_type() -> GType
{
  return notebookpage_class_.init().get_type();
}


auto NotebookPage::get_base_type() -> GType
{
  return gtk_notebook_page_get_type();
}


auto NotebookPage::get_child() -> Widget*
{
  return Glib::wrap(gtk_notebook_page_get_child(gobj()));
}

auto NotebookPage::get_child() const -> const Widget*
{
  return const_cast<NotebookPage*>(this)->get_child();
}


auto NotebookPage::property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >
{
  return {this, "child"};
}

auto NotebookPage::property_tab() const -> Glib::PropertyProxy_ReadOnly< Widget* >
{
  return {this, "tab"};
}

auto NotebookPage::property_menu() const -> Glib::PropertyProxy_ReadOnly< Widget* >
{
  return {this, "menu"};
}

auto NotebookPage::property_tab_label() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "tab-label"};
}

auto NotebookPage::property_tab_label() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "tab-label"};
}

auto NotebookPage::property_menu_label() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "menu-label"};
}

auto NotebookPage::property_menu_label() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "menu-label"};
}

auto NotebookPage::property_position() -> Glib::PropertyProxy< int >
{
  return {this, "position"};
}

auto NotebookPage::property_position() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "position"};
}

auto NotebookPage::property_tab_expand() -> Glib::PropertyProxy< bool >
{
  return {this, "tab-expand"};
}

auto NotebookPage::property_tab_expand() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "tab-expand"};
}

auto NotebookPage::property_tab_fill() -> Glib::PropertyProxy< bool >
{
  return {this, "tab-fill"};
}

auto NotebookPage::property_tab_fill() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "tab-fill"};
}

auto NotebookPage::property_reorderable() -> Glib::PropertyProxy< bool >
{
  return {this, "reorderable"};
}

auto NotebookPage::property_reorderable() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "reorderable"};
}

auto NotebookPage::property_detachable() -> Glib::PropertyProxy< bool >
{
  return {this, "detachable"};
}

auto NotebookPage::property_detachable() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "detachable"};
}


} // namespace Gtk


