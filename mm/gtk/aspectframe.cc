// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.h>

#include <mm/gtk/aspectframe.h>
#include <mm/gtk/private/aspectframe_p.h>


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

void AspectFrame::unset_child()
{
  gtk_aspect_frame_set_child(gobj(), nullptr);
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkAspectFrame* object, bool take_copy) -> Gtk::AspectFrame*
{
  return dynamic_cast<Gtk::AspectFrame *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto AspectFrame_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &AspectFrame_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_aspect_frame_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void AspectFrame_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto AspectFrame_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new AspectFrame((GtkAspectFrame*)(o)));

}


/* The implementation: */

AspectFrame::AspectFrame(const Glib::ConstructParams& construct_params)
:
  Gtk::Widget(construct_params)
{
  }

AspectFrame::AspectFrame(GtkAspectFrame* castitem)
:
  Gtk::Widget((GtkWidget*)(castitem))
{
  }


AspectFrame::AspectFrame(AspectFrame&& src) noexcept
: Gtk::Widget(std::move(src))
{}

auto AspectFrame::operator=(AspectFrame&& src) noexcept -> AspectFrame&
{
  Gtk::Widget::operator=(std::move(src));
  return *this;
}

AspectFrame::~AspectFrame() noexcept
{
  destroy_();
}

AspectFrame::CppClassType AspectFrame::aspectframe_class_; // initialize static member

auto AspectFrame::get_type() -> GType
{
  return aspectframe_class_.init().get_type();
}


auto AspectFrame::get_base_type() -> GType
{
  return gtk_aspect_frame_get_type();
}


AspectFrame::AspectFrame(Align xalign, Align yalign, float ratio, bool obey_child)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::Widget(Glib::ConstructParams(aspectframe_class_.init(), "xalign", _gtkmm_align_float_from_enum(xalign), "yalign", _gtkmm_align_float_from_enum(yalign), "ratio", ratio, "obey_child", static_cast<int>(obey_child), nullptr))
{


}

AspectFrame::AspectFrame(float xalign, float yalign, float ratio, bool obey_child)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::Widget(Glib::ConstructParams(aspectframe_class_.init(), "xalign", xalign, "yalign", yalign, "ratio", ratio, "obey_child", static_cast<int>(obey_child), nullptr))
{


}

void AspectFrame::set_xalign(Align xalign)
{
  gtk_aspect_frame_set_xalign(gobj(), _gtkmm_align_float_from_enum(xalign));
}

void AspectFrame::set_xalign(float xalign)
{
  gtk_aspect_frame_set_xalign(gobj(), xalign);
}

auto AspectFrame::get_xalign() const -> float
{
  return gtk_aspect_frame_get_xalign(const_cast<GtkAspectFrame*>(gobj()));
}

void AspectFrame::set_yalign(Align yalign)
{
  gtk_aspect_frame_set_yalign(gobj(), _gtkmm_align_float_from_enum(yalign));
}

void AspectFrame::set_yalign(float yalign)
{
  gtk_aspect_frame_set_yalign(gobj(), yalign);
}

auto AspectFrame::get_yalign() const -> float
{
  return gtk_aspect_frame_get_yalign(const_cast<GtkAspectFrame*>(gobj()));
}

void AspectFrame::set_ratio(float ratio)
{
  gtk_aspect_frame_set_ratio(gobj(), ratio);
}

auto AspectFrame::get_ratio() const -> float
{
  return gtk_aspect_frame_get_ratio(const_cast<GtkAspectFrame*>(gobj()));
}

void AspectFrame::set_obey_child(bool obey_child)
{
  gtk_aspect_frame_set_obey_child(gobj(), static_cast<int>(obey_child));
}

auto AspectFrame::get_obey_child() const -> bool
{
  return gtk_aspect_frame_get_obey_child(const_cast<GtkAspectFrame*>(gobj()));
}

void AspectFrame::set_child(Widget& child)
{
  gtk_aspect_frame_set_child(gobj(), (child).gobj());
}

auto AspectFrame::get_child() -> Widget*
{
  return Glib::wrap(gtk_aspect_frame_get_child(gobj()));
}

auto AspectFrame::get_child() const -> const Widget*
{
  return const_cast<AspectFrame*>(this)->get_child();
}


auto AspectFrame::property_xalign() -> Glib::PropertyProxy< float >
{
  return Glib::PropertyProxy< float >(this, "xalign");
}

auto AspectFrame::property_xalign() const -> Glib::PropertyProxy_ReadOnly< float >
{
  return Glib::PropertyProxy_ReadOnly< float >(this, "xalign");
}

auto AspectFrame::property_yalign() -> Glib::PropertyProxy< float >
{
  return Glib::PropertyProxy< float >(this, "yalign");
}

auto AspectFrame::property_yalign() const -> Glib::PropertyProxy_ReadOnly< float >
{
  return Glib::PropertyProxy_ReadOnly< float >(this, "yalign");
}

auto AspectFrame::property_ratio() -> Glib::PropertyProxy< float >
{
  return Glib::PropertyProxy< float >(this, "ratio");
}

auto AspectFrame::property_ratio() const -> Glib::PropertyProxy_ReadOnly< float >
{
  return Glib::PropertyProxy_ReadOnly< float >(this, "ratio");
}

auto AspectFrame::property_obey_child() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "obey-child");
}

auto AspectFrame::property_obey_child() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "obey-child");
}

auto AspectFrame::property_child() -> Glib::PropertyProxy< Widget* >
{
  return Glib::PropertyProxy< Widget* >(this, "child");
}

auto AspectFrame::property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >
{
  return Glib::PropertyProxy_ReadOnly< Widget* >(this, "child");
}


} // namespace Gtk


