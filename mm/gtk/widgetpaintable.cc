// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.h>

#include <mm/gtk/widgetpaintable.h>
#include <mm/gtk/private/widgetpaintable_p.h>


/* Copyright (C) 2018 The gtkmm Development Team
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

#include <gtk/gtk.h>

namespace Gtk
{

void WidgetPaintable::unset_widget()
{
  gtk_widget_paintable_set_widget(gobj(), nullptr);
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkWidgetPaintable* object, bool take_copy) -> Glib::RefPtr<Gtk::WidgetPaintable>
{
  return Glib::make_refptr_for_instance<Gtk::WidgetPaintable>( dynamic_cast<Gtk::WidgetPaintable*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto WidgetPaintable_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &WidgetPaintable_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_widget_paintable_get_type();

  }

  return *this;
}


void WidgetPaintable_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto WidgetPaintable_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new WidgetPaintable((GtkWidgetPaintable*)object);
}


/* The implementation: */

auto WidgetPaintable::gobj_copy() -> GtkWidgetPaintable*
{
  reference();
  return gobj();
}

WidgetPaintable::WidgetPaintable(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

WidgetPaintable::WidgetPaintable(GtkWidgetPaintable* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


WidgetPaintable::WidgetPaintable(WidgetPaintable&& src) noexcept
: Glib::Object(std::move(src))
  , Gdk::Paintable(std::move(src))
{}

auto WidgetPaintable::operator=(WidgetPaintable&& src) noexcept -> WidgetPaintable&
{
  Glib::Object::operator=(std::move(src));
  Gdk::Paintable::operator=(std::move(src));
  return *this;
}


WidgetPaintable::~WidgetPaintable() noexcept
{}


WidgetPaintable::CppClassType WidgetPaintable::widgetpaintable_class_; // initialize static member

auto WidgetPaintable::get_type() -> GType
{
  return widgetpaintable_class_.init().get_type();
}


auto WidgetPaintable::get_base_type() -> GType
{
  return gtk_widget_paintable_get_type();
}


WidgetPaintable::WidgetPaintable()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Glib::Object(Glib::ConstructParams(widgetpaintable_class_.init()))
{


}

WidgetPaintable::WidgetPaintable(Widget& widget)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Glib::Object(Glib::ConstructParams(widgetpaintable_class_.init(), "widget", (widget).gobj(), nullptr))
{


}

auto WidgetPaintable::create() -> Glib::RefPtr<WidgetPaintable>
{
  return Glib::make_refptr_for_instance<WidgetPaintable>( new WidgetPaintable() );
}

auto WidgetPaintable::create(Widget& widget) -> Glib::RefPtr<WidgetPaintable>
{
  return Glib::make_refptr_for_instance<WidgetPaintable>( new WidgetPaintable(widget) );
}

auto WidgetPaintable::get_widget() -> Widget*
{
  return Glib::wrap(gtk_widget_paintable_get_widget(gobj()));
}

auto WidgetPaintable::get_widget() const -> const Widget*
{
  return const_cast<WidgetPaintable*>(this)->get_widget();
}

void WidgetPaintable::set_widget(Widget& widget)
{
  gtk_widget_paintable_set_widget(gobj(), (widget).gobj());
}


auto WidgetPaintable::property_widget() -> Glib::PropertyProxy< Widget* >
{
  return Glib::PropertyProxy< Widget* >(this, "widget");
}

auto WidgetPaintable::property_widget() const -> Glib::PropertyProxy_ReadOnly< Widget* >
{
  return Glib::PropertyProxy_ReadOnly< Widget* >(this, "widget");
}


} // namespace Gtk


