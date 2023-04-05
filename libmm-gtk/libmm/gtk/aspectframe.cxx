// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/aspectframe.hxx>
#include <libmm/gtk/aspectframe_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  auto
  AspectFrame::unset_child () -> void
  {
    gtk_aspect_frame_set_child (gobj (), nullptr);
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkAspectFrame* object, bool take_copy) -> gtk::AspectFrame*
  {
    return dynamic_cast<gtk::AspectFrame*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  AspectFrame_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &AspectFrame_Class::class_init_function;

      register_derived_type (gtk_aspect_frame_get_type ());
    }

    return *this;
  }

  auto
  AspectFrame_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  AspectFrame_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new AspectFrame ((GtkAspectFrame*) (o)));
  }

  AspectFrame::AspectFrame (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  AspectFrame::AspectFrame (GtkAspectFrame* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  AspectFrame::AspectFrame (AspectFrame&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  AspectFrame::operator= (AspectFrame&& src) noexcept -> AspectFrame&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  AspectFrame::~AspectFrame () noexcept
  {
    destroy_ ();
  }

  AspectFrame::CppClassType AspectFrame::aspectframe_class_;

  auto
  AspectFrame::get_type () -> GType
  {
    return aspectframe_class_.init ().get_type ();
  }

  auto
  AspectFrame::get_base_type () -> GType
  {
    return gtk_aspect_frame_get_type ();
  }

  AspectFrame::AspectFrame (Align xalign,
                            Align yalign,
                            float ratio,
                            bool obey_child)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (aspectframe_class_.init (),
                                          "xalign",
                                          _gtkmm_align_float_from_enum (xalign),
                                          "yalign",
                                          _gtkmm_align_float_from_enum (yalign),
                                          "ratio",
                                          ratio,
                                          "obey_child",
                                          static_cast<int> (obey_child),
                                          nullptr))
  {
  }

  AspectFrame::AspectFrame (float xalign,
                            float yalign,
                            float ratio,
                            bool obey_child)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (aspectframe_class_.init (),
                                          "xalign",
                                          xalign,
                                          "yalign",
                                          yalign,
                                          "ratio",
                                          ratio,
                                          "obey_child",
                                          static_cast<int> (obey_child),
                                          nullptr))
  {
  }

  auto
  AspectFrame::set_xalign (Align xalign) -> void
  {
    gtk_aspect_frame_set_xalign (gobj (),
                                 _gtkmm_align_float_from_enum (xalign));
  }

  auto
  AspectFrame::set_xalign (float xalign) -> void
  {
    gtk_aspect_frame_set_xalign (gobj (), xalign);
  }

  auto
  AspectFrame::get_xalign () const -> float
  {
    return gtk_aspect_frame_get_xalign (const_cast<GtkAspectFrame*> (gobj ()));
  }

  auto
  AspectFrame::set_yalign (Align yalign) -> void
  {
    gtk_aspect_frame_set_yalign (gobj (),
                                 _gtkmm_align_float_from_enum (yalign));
  }

  auto
  AspectFrame::set_yalign (float yalign) -> void
  {
    gtk_aspect_frame_set_yalign (gobj (), yalign);
  }

  auto
  AspectFrame::get_yalign () const -> float
  {
    return gtk_aspect_frame_get_yalign (const_cast<GtkAspectFrame*> (gobj ()));
  }

  auto
  AspectFrame::set_ratio (float ratio) -> void
  {
    gtk_aspect_frame_set_ratio (gobj (), ratio);
  }

  auto
  AspectFrame::get_ratio () const -> float
  {
    return gtk_aspect_frame_get_ratio (const_cast<GtkAspectFrame*> (gobj ()));
  }

  auto
  AspectFrame::set_obey_child (bool obey_child) -> void
  {
    gtk_aspect_frame_set_obey_child (gobj (), static_cast<int> (obey_child));
  }

  auto
  AspectFrame::get_obey_child () const -> bool
  {
    return gtk_aspect_frame_get_obey_child (
        const_cast<GtkAspectFrame*> (gobj ()));
  }

  auto
  AspectFrame::set_child (Widget& child) -> void
  {
    gtk_aspect_frame_set_child (gobj (), (child).gobj ());
  }

  auto
  AspectFrame::get_child () -> Widget*
  {
    return glib::wrap (gtk_aspect_frame_get_child (gobj ()));
  }

  auto
  AspectFrame::get_child () const -> const Widget*
  {
    return const_cast<AspectFrame*> (this)->get_child ();
  }

  auto
  AspectFrame::property_xalign () -> glib::PropertyProxy<float>
  {
    return glib::PropertyProxy<float> (this, "xalign");
  }

  auto
  AspectFrame::property_xalign () const -> glib::PropertyProxy_ReadOnly<float>
  {
    return glib::PropertyProxy_ReadOnly<float> (this, "xalign");
  }

  auto
  AspectFrame::property_yalign () -> glib::PropertyProxy<float>
  {
    return glib::PropertyProxy<float> (this, "yalign");
  }

  auto
  AspectFrame::property_yalign () const -> glib::PropertyProxy_ReadOnly<float>
  {
    return glib::PropertyProxy_ReadOnly<float> (this, "yalign");
  }

  auto
  AspectFrame::property_ratio () -> glib::PropertyProxy<float>
  {
    return glib::PropertyProxy<float> (this, "ratio");
  }

  auto
  AspectFrame::property_ratio () const -> glib::PropertyProxy_ReadOnly<float>
  {
    return glib::PropertyProxy_ReadOnly<float> (this, "ratio");
  }

  auto
  AspectFrame::property_obey_child () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "obey-child");
  }

  auto
  AspectFrame::property_obey_child () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "obey-child");
  }

  auto
  AspectFrame::property_child () -> glib::PropertyProxy<Widget*>
  {
    return glib::PropertyProxy<Widget*> (this, "child");
  }

  auto
  AspectFrame::property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "child");
  }

} // namespace gtk
