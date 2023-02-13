


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/frame.hxx>
#include <libmm-gtk/frame_p.hxx>


/* Copyright 1998-2002 The gtkmm Development Team
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

auto Frame::unset_label () -> void
{
  gtk_frame_set_label(gobj(), nullptr);
}

auto Frame::unset_child () -> void
{
  gtk_frame_set_child(gobj(), nullptr);
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkFrame* object, const bool take_copy) -> Gtk::Frame*
{
  return dynamic_cast<Gtk::Frame *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto Frame_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Frame_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_frame_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto Frame_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

  klass->compute_child_allocation = &compute_child_allocation_vfunc_callback;

}

auto Frame_Class::compute_child_allocation_vfunc_callback (
  GtkFrame *self, GtkAllocation *allocation) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->compute_child_allocation_vfunc(Glib::wrap(allocation)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->compute_child_allocation)
    (*base->compute_child_allocation)(self, allocation);
}


auto Frame_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new Frame((GtkFrame*)o));

}


/* The implementation: */

Frame::Frame(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

Frame::Frame(GtkFrame* castitem)
: Widget((GtkWidget*)castitem)
{
  }


Frame::Frame(Frame&& src) noexcept
: Widget(std::move(src))
{}

auto Frame::operator=(Frame&& src) noexcept -> Frame&
{
  Widget::operator=(std::move(src));
  return *this;
}

Frame::~Frame() noexcept
{
  destroy_();
}

Frame::CppClassType Frame::frame_class_; // initialize static member

auto Frame::get_type() -> GType
{
  return frame_class_.init().get_type();
}


auto Frame::get_base_type() -> GType
{
  return gtk_frame_get_type();
}


Frame::Frame()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(frame_class_.init()))
{


}

Frame::Frame(const Glib::ustring& label)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(frame_class_.init(), "label", label.c_str(), nullptr))
{


}

auto Frame::set_label (const Glib::ustring &label) -> void
{
  gtk_frame_set_label(gobj(), label.c_str());
}

auto Frame::get_label() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_frame_get_label(const_cast<GtkFrame*>(gobj())));
}

auto Frame::set_label_widget (Widget &label_widget) -> void
{
  gtk_frame_set_label_widget(gobj(), label_widget.gobj());
}

auto Frame::get_label_widget() -> Widget*
{
  return Glib::wrap(gtk_frame_get_label_widget(gobj()));
}

auto Frame::get_label_widget() const -> const Widget*
{
  return const_cast<Frame*>(this)->get_label_widget();
}

auto Frame::set_label_align (
  const float xalign) -> void
{
  gtk_frame_set_label_align(gobj(), xalign);
}

auto Frame::set_label_align (
  const Align xalign) -> void
{
  gtk_frame_set_label_align(gobj(), _gtkmm_align_float_from_enum(xalign));
}

auto Frame::get_label_align() const -> float
{
  return gtk_frame_get_label_align(const_cast<GtkFrame*>(gobj()));
}

auto Frame::set_child (Widget &child) -> void
{
  gtk_frame_set_child(gobj(), child.gobj());
}

auto Frame::get_child() -> Widget*
{
  return Glib::wrap(gtk_frame_get_child(gobj()));
}

auto Frame::get_child() const -> const Widget*
{
  return const_cast<Frame*>(this)->get_child();
}


auto Frame::property_label() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "label"};
}

auto Frame::property_label() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "label"};
}

auto Frame::property_label_xalign() -> Glib::PropertyProxy< double >
{
  return {this, "label-xalign"};
}

auto Frame::property_label_xalign() const -> Glib::PropertyProxy_ReadOnly< double >
{
  return {this, "label-xalign"};
}

auto Frame::property_label_widget() -> Glib::PropertyProxy< Widget* >
{
  return {this, "label-widget"};
}

auto Frame::property_label_widget() const -> Glib::PropertyProxy_ReadOnly< Widget* >
{
  return {this, "label-widget"};
}

auto Frame::property_child() -> Glib::PropertyProxy< Widget* >
{
  return {this, "child"};
}

auto Frame::property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >
{
  return {this, "child"};
}


auto Frame::compute_child_allocation_vfunc (Allocation &allocation) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->compute_child_allocation)
  {
    (*base->compute_child_allocation)(gobj(),allocation.gobj());
  }
}


} // namespace Gtk


