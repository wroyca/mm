// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/frame.hxx>
#include <libmm/gtk/frame_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  auto
  Frame::unset_label () -> void
  {
    gtk_frame_set_label (gobj (), nullptr);
  }

  auto
  Frame::unset_child () -> void
  {
    gtk_frame_set_child (gobj (), nullptr);
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkFrame* object, bool take_copy) -> gtk::Frame*
  {
    return dynamic_cast<gtk::Frame*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  Frame_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Frame_Class::class_init_function;

      register_derived_type (gtk_frame_get_type ());
    }

    return *this;
  }

  auto
  Frame_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->compute_child_allocation = &compute_child_allocation_vfunc_callback;
  }

  auto
  Frame_Class::compute_child_allocation_vfunc_callback (
      GtkFrame* self,
      GtkAllocation* allocation) -> void
  {
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->compute_child_allocation_vfunc (
              (Allocation&) (glib::wrap (allocation)));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->compute_child_allocation)
      (*base->compute_child_allocation) (self, allocation);
  }

  auto
  Frame_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Frame ((GtkFrame*) (o)));
  }

  Frame::Frame (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Frame::Frame (GtkFrame* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Frame::Frame (Frame&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  Frame::operator= (Frame&& src) noexcept -> Frame&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  Frame::~Frame () noexcept
  {
    destroy_ ();
  }

  Frame::CppClassType Frame::frame_class_;

  auto
  Frame::get_type () -> GType
  {
    return frame_class_.init ().get_type ();
  }

  auto
  Frame::get_base_type () -> GType
  {
    return gtk_frame_get_type ();
  }

  Frame::Frame ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (frame_class_.init ()))
  {
  }

  Frame::Frame (const glib::ustring& label)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (frame_class_.init (),
                                          "label",
                                          label.c_str (),
                                          nullptr))
  {
  }

  auto
  Frame::set_label (const glib::ustring& label) -> void
  {
    gtk_frame_set_label (gobj (), label.c_str ());
  }

  auto
  Frame::get_label () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_frame_get_label (const_cast<GtkFrame*> (gobj ())));
  }

  auto
  Frame::set_label_widget (Widget& label_widget) -> void
  {
    gtk_frame_set_label_widget (gobj (), (label_widget).gobj ());
  }

  auto
  Frame::get_label_widget () -> Widget*
  {
    return glib::wrap (gtk_frame_get_label_widget (gobj ()));
  }

  auto
  Frame::get_label_widget () const -> const Widget*
  {
    return const_cast<Frame*> (this)->get_label_widget ();
  }

  auto
  Frame::set_label_align (float xalign) -> void
  {
    gtk_frame_set_label_align (gobj (), xalign);
  }

  auto
  Frame::set_label_align (Align xalign) -> void
  {
    gtk_frame_set_label_align (gobj (), _gtkmm_align_float_from_enum (xalign));
  }

  auto
  Frame::get_label_align () const -> float
  {
    return gtk_frame_get_label_align (const_cast<GtkFrame*> (gobj ()));
  }

  auto
  Frame::set_child (Widget& child) -> void
  {
    gtk_frame_set_child (gobj (), (child).gobj ());
  }

  auto
  Frame::get_child () -> Widget*
  {
    return glib::wrap (gtk_frame_get_child (gobj ()));
  }

  auto
  Frame::get_child () const -> const Widget*
  {
    return const_cast<Frame*> (this)->get_child ();
  }

  auto
  Frame::property_label () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "label");
  }

  auto
  Frame::property_label () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "label");
  }

  auto
  Frame::property_label_xalign () -> glib::PropertyProxy<double>
  {
    return glib::PropertyProxy<double> (this, "label-xalign");
  }

  auto
  Frame::property_label_xalign () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return glib::PropertyProxy_ReadOnly<double> (this, "label-xalign");
  }

  auto
  Frame::property_label_widget () -> glib::PropertyProxy<Widget*>
  {
    return glib::PropertyProxy<Widget*> (this, "label-widget");
  }

  auto
  Frame::property_label_widget () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "label-widget");
  }

  auto
  Frame::property_child () -> glib::PropertyProxy<Widget*>
  {
    return glib::PropertyProxy<Widget*> (this, "child");
  }

  auto
  Frame::property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "child");
  }

  auto
  gtk::Frame::compute_child_allocation_vfunc (Allocation& allocation) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->compute_child_allocation)
    {
      (*base->compute_child_allocation) (gobj (),
                                         (GtkAllocation*) (allocation.gobj ()));
    }
  }

} // namespace gtk
