// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gtkmm/box.h>
#include <gtkmm/private/box_p.h>


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
#include <glibmm/wrap.h>


namespace Gtk
{
void Box::insert_child_at_start(Widget& child)
{
  gtk_box_insert_child_after(gobj(), child.gobj(), nullptr);
}

void Box::reorder_child_at_start(Widget& child)
{
  gtk_box_reorder_child_after(gobj(), child.gobj(), nullptr);
}

} //namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

Gtk::Box* wrap(GtkBox* object, bool take_copy)
{
  return dynamic_cast<Gtk::Box *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& Box_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Box_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_box_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Orientable::add_interface(get_type());

  }

  return *this;
}


void Box_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* Box_Class::wrap_new(GObject* o)
{
  return manage(new Box((GtkBox*)(o)));

}


/* The implementation: */

Box::Box(const Glib::ConstructParams& construct_params)
:
  Gtk::Widget(construct_params)
{
  }

Box::Box(GtkBox* castitem)
:
  Gtk::Widget((GtkWidget*)(castitem))
{
  }


Box::Box(Box&& src) noexcept
: Gtk::Widget(std::move(src))
  , Orientable(std::move(src))
{}

Box& Box::operator=(Box&& src) noexcept
{
  Gtk::Widget::operator=(std::move(src));
  Orientable::operator=(std::move(src));
  return *this;
}

Box::~Box() noexcept
{
  destroy_();
}

Box::CppClassType Box::box_class_; // initialize static member

GType Box::get_type()
{
  return box_class_.init().get_type();
}


GType Box::get_base_type()
{
  return gtk_box_get_type();
}


Box::Box(Orientation orientation, int spacing)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::Widget(Glib::ConstructParams(box_class_.init(), "orientation", static_cast<GtkOrientation>(orientation), "spacing", spacing, nullptr))
{
  

}

void Box::set_homogeneous(bool homogeneous)
{
  gtk_box_set_homogeneous(gobj(), static_cast<int>(homogeneous));
}

bool Box::get_homogeneous() const
{
  return gtk_box_get_homogeneous(const_cast<GtkBox*>(gobj()));
}

void Box::set_spacing(int spacing)
{
  gtk_box_set_spacing(gobj(), spacing);
}

int Box::get_spacing() const
{
  return gtk_box_get_spacing(const_cast<GtkBox*>(gobj()));
}

void Box::set_baseline_position(BaselinePosition position)
{
  gtk_box_set_baseline_position(gobj(), static_cast<GtkBaselinePosition>(position));
}

BaselinePosition Box::get_baseline_position() const
{
  return static_cast<BaselinePosition>(gtk_box_get_baseline_position(const_cast<GtkBox*>(gobj())));
}

void Box::append(Gtk::Widget& child)
{
  gtk_box_append(gobj(), (child).gobj());
}

void Box::prepend(Gtk::Widget& child)
{
  gtk_box_prepend(gobj(), (child).gobj());
}

void Box::remove(Gtk::Widget& child)
{
  gtk_box_remove(gobj(), (child).gobj());
}

void Box::insert_child_after(Widget& child, const Widget& sibling)
{
  gtk_box_insert_child_after(gobj(), (child).gobj(), const_cast<GtkWidget*>((sibling).gobj()));
}

void Box::reorder_child_after(Widget& child, const Widget& sibling)
{
  gtk_box_reorder_child_after(gobj(), (child).gobj(), const_cast<GtkWidget*>((sibling).gobj()));
}


Glib::PropertyProxy< int > Box::property_spacing() 
{
  return Glib::PropertyProxy< int >(this, "spacing");
}

Glib::PropertyProxy_ReadOnly< int > Box::property_spacing() const
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "spacing");
}

Glib::PropertyProxy< bool > Box::property_homogeneous() 
{
  return Glib::PropertyProxy< bool >(this, "homogeneous");
}

Glib::PropertyProxy_ReadOnly< bool > Box::property_homogeneous() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "homogeneous");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<BaselinePosition>::value,
  "Type BaselinePosition cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

Glib::PropertyProxy< BaselinePosition > Box::property_baseline_position() 
{
  return Glib::PropertyProxy< BaselinePosition >(this, "baseline-position");
}

Glib::PropertyProxy_ReadOnly< BaselinePosition > Box::property_baseline_position() const
{
  return Glib::PropertyProxy_ReadOnly< BaselinePosition >(this, "baseline-position");
}


} // namespace Gtk


