


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/filechooserwidget.hpp>
#include <libmm-gtk/filechooserwidget_p.hpp>


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


} // namespace Gtk


namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkFileChooserWidget* object, const bool take_copy) -> Gtk::FileChooserWidget*
{
  return dynamic_cast<Gtk::FileChooserWidget *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto FileChooserWidget_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &FileChooserWidget_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_file_chooser_widget_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  FileChooser::add_interface(get_type());

  }

  return *this;
}


auto FileChooserWidget_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto FileChooserWidget_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new FileChooserWidget((GtkFileChooserWidget*)o));

}


/* The implementation: */

FileChooserWidget::FileChooserWidget(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

FileChooserWidget::FileChooserWidget(GtkFileChooserWidget* castitem)
: Widget((GtkWidget*)castitem)
{
  }


FileChooserWidget::FileChooserWidget(FileChooserWidget&& src) noexcept
: Widget(std::move(src))
  , FileChooser(std::move(src))
{}

auto FileChooserWidget::operator=(FileChooserWidget&& src) noexcept -> FileChooserWidget&
{
  Widget::operator=(std::move(src));
  FileChooser::operator=(std::move(src));
  return *this;
}

FileChooserWidget::~FileChooserWidget() noexcept
{
  destroy_();
}

FileChooserWidget::CppClassType FileChooserWidget::filechooserwidget_class_; // initialize static member

auto FileChooserWidget::get_type() -> GType
{
  return filechooserwidget_class_.init().get_type();
}


auto FileChooserWidget::get_base_type() -> GType
{
  return gtk_file_chooser_widget_get_type();
}


FileChooserWidget::FileChooserWidget()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(filechooserwidget_class_.init()))
{


}

FileChooserWidget::FileChooserWidget(const Action action)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(filechooserwidget_class_.init(), "action", action, nullptr))
{


}


} // namespace Gtk


