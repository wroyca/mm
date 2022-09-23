// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gtkmm/widgetpaintable.h>
#include <gtkmm/private/widgetpaintable_p.h>


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

Glib::RefPtr<Gtk::WidgetPaintable> wrap(GtkWidgetPaintable* object, bool take_copy)
{
  return Glib::make_refptr_for_instance<Gtk::WidgetPaintable>( dynamic_cast<Gtk::WidgetPaintable*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& WidgetPaintable_Class::init()
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


Glib::ObjectBase* WidgetPaintable_Class::wrap_new(GObject* object)
{
  return new WidgetPaintable((GtkWidgetPaintable*)object);
}


/* The implementation: */

GtkWidgetPaintable* WidgetPaintable::gobj_copy()
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

WidgetPaintable& WidgetPaintable::operator=(WidgetPaintable&& src) noexcept
{
  Glib::Object::operator=(std::move(src));
  Gdk::Paintable::operator=(std::move(src));
  return *this;
}


WidgetPaintable::~WidgetPaintable() noexcept
{}


WidgetPaintable::CppClassType WidgetPaintable::widgetpaintable_class_; // initialize static member

GType WidgetPaintable::get_type()
{
  return widgetpaintable_class_.init().get_type();
}


GType WidgetPaintable::get_base_type()
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

Glib::RefPtr<WidgetPaintable> WidgetPaintable::create()
{
  return Glib::make_refptr_for_instance<WidgetPaintable>( new WidgetPaintable() );
}

Glib::RefPtr<WidgetPaintable> WidgetPaintable::create(Widget& widget)
{
  return Glib::make_refptr_for_instance<WidgetPaintable>( new WidgetPaintable(widget) );
}

Widget* WidgetPaintable::get_widget()
{
  return Glib::wrap(gtk_widget_paintable_get_widget(gobj()));
}

const Widget* WidgetPaintable::get_widget() const
{
  return const_cast<WidgetPaintable*>(this)->get_widget();
}

void WidgetPaintable::set_widget(Widget& widget)
{
  gtk_widget_paintable_set_widget(gobj(), (widget).gobj());
}


Glib::PropertyProxy< Widget* > WidgetPaintable::property_widget() 
{
  return Glib::PropertyProxy< Widget* >(this, "widget");
}

Glib::PropertyProxy_ReadOnly< Widget* > WidgetPaintable::property_widget() const
{
  return Glib::PropertyProxy_ReadOnly< Widget* >(this, "widget");
}


} // namespace Gtk


