


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/fontchooserwidget.hxx>
#include <libmm-gtk/fontchooserwidget_p.hxx>


/* Copyright 2011 The gtkmm Development Team
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

} //namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkFontChooserWidget* object, const bool take_copy) -> Gtk::FontChooserWidget*
{
  return dynamic_cast<Gtk::FontChooserWidget *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto FontChooserWidget_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &FontChooserWidget_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_font_chooser_widget_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  FontChooser::add_interface(get_type());

  }

  return *this;
}


auto FontChooserWidget_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto FontChooserWidget_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new FontChooserWidget((GtkFontChooserWidget*)o));

}


/* The implementation: */

FontChooserWidget::FontChooserWidget(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

FontChooserWidget::FontChooserWidget(GtkFontChooserWidget* castitem)
: Widget((GtkWidget*)castitem)
{
  }


FontChooserWidget::FontChooserWidget(FontChooserWidget&& src) noexcept
: Widget(std::move(src))
  , FontChooser(std::move(src))
{}

auto FontChooserWidget::operator=(FontChooserWidget&& src) noexcept -> FontChooserWidget&
{
  Widget::operator=(std::move(src));
  FontChooser::operator=(std::move(src));
  return *this;
}

FontChooserWidget::~FontChooserWidget() noexcept
{
  destroy_();
}

FontChooserWidget::CppClassType FontChooserWidget::fontchooserwidget_class_; // initialize static member

auto FontChooserWidget::get_type() -> GType
{
  return fontchooserwidget_class_.init().get_type();
}


auto FontChooserWidget::get_base_type() -> GType
{
  return gtk_font_chooser_widget_get_type();
}


FontChooserWidget::FontChooserWidget()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(fontchooserwidget_class_.init()))
{


}


} // namespace Gtk


