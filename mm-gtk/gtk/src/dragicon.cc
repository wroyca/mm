// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gtkmm/dragicon.h>
#include <gtkmm/private/dragicon_p.h>


/* Copyright (C) 2020 The gtkmm Development Team
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

void DragIcon::unset_child()
{
  gtk_drag_icon_set_child(gobj(), nullptr);
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

Gtk::DragIcon* wrap(GtkDragIcon* object, bool take_copy)
{
  return dynamic_cast<Gtk::DragIcon *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& DragIcon_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &DragIcon_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_drag_icon_get_type();

  }

  return *this;
}


void DragIcon_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* DragIcon_Class::wrap_new(GObject* o)
{
  return manage(new DragIcon((GtkDragIcon*)(o)));

}


/* The implementation: */

DragIcon::DragIcon(const Glib::ConstructParams& construct_params)
:
  Gtk::Widget(construct_params)
{
  }

DragIcon::DragIcon(GtkDragIcon* castitem)
:
  Gtk::Widget((GtkWidget*)(castitem))
{
  }


DragIcon::DragIcon(DragIcon&& src) noexcept
: Gtk::Widget(std::move(src))
  , Native(std::move(src))
  , Root(std::move(src))
{}

DragIcon& DragIcon::operator=(DragIcon&& src) noexcept
{
  Gtk::Widget::operator=(std::move(src));
  Native::operator=(std::move(src));
  Root::operator=(std::move(src));
  return *this;
}

DragIcon::~DragIcon() noexcept
{
  destroy_();
}

DragIcon::CppClassType DragIcon::dragicon_class_; // initialize static member

GType DragIcon::get_type()
{
  return dragicon_class_.init().get_type();
}


GType DragIcon::get_base_type()
{
  return gtk_drag_icon_get_type();
}


DragIcon* DragIcon::get_for_drag(const Glib::RefPtr<Gdk::Drag>& drag)
{
  return Glib::wrap((GtkDragIcon*)(gtk_drag_icon_get_for_drag(Glib::unwrap(drag))));
}

void DragIcon::set_child(Widget& child)
{
  gtk_drag_icon_set_child(gobj(), (child).gobj());
}

Widget* DragIcon::get_child()
{
  return Glib::wrap(gtk_drag_icon_get_child(gobj()));
}

const Widget* DragIcon::get_child() const
{
  return const_cast<DragIcon*>(this)->get_child();
}

void DragIcon::set_from_paintable(const Glib::RefPtr<Gdk::Drag>& drag, const Glib::RefPtr<Gdk::Paintable>& paintable, int hot_x, int hot_y)
{
  gtk_drag_icon_set_from_paintable(Glib::unwrap(drag), Glib::unwrap(paintable), hot_x, hot_y);
}

Widget* DragIcon::create_widget_for_value(const Glib::ValueBase& value)
{
  return Glib::wrap(gtk_drag_icon_create_widget_for_value((value).gobj()));
}


Glib::PropertyProxy< Widget* > DragIcon::property_child() 
{
  return Glib::PropertyProxy< Widget* >(this, "child");
}

Glib::PropertyProxy_ReadOnly< Widget* > DragIcon::property_child() const
{
  return Glib::PropertyProxy_ReadOnly< Widget* >(this, "child");
}


} // namespace Gtk


