

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/aspectframe.hxx>
#include <libmm-gtk/aspectframe_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  auto
  AspectFrame::unset_child () -> void
  {
    gtk_aspect_frame_set_child (gobj (), nullptr);
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkAspectFrame* object, const bool take_copy) -> Gtk::AspectFrame*
  {
    return dynamic_cast<Gtk::AspectFrame*> (
        wrap_auto ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  AspectFrame_Class::init () -> const Class&
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
  AspectFrame_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new AspectFrame ((GtkAspectFrame*) o));
  }

  AspectFrame::AspectFrame (const Glib::ConstructParams& construct_params)
    : Widget (construct_params)
  {
  }

  AspectFrame::AspectFrame (GtkAspectFrame* castitem)
    : Widget ((GtkWidget*) castitem)
  {
  }

  AspectFrame::AspectFrame (AspectFrame&& src) noexcept
    : Widget (std::move (src))
  {
  }

  auto
  AspectFrame::operator= (AspectFrame&& src) noexcept -> AspectFrame&
  {
    Widget::operator= (std::move (src));
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

  AspectFrame::AspectFrame (const Align xalign,
                            const Align yalign,
                            const float ratio,
                            const bool obey_child)
    : ObjectBase (nullptr),
      Widget (Glib::ConstructParams (aspectframe_class_.init (),
                                     "xalign",
                                     _gtkmm_align_float_from_enum (xalign),
                                     "yalign",
                                     _gtkmm_align_float_from_enum (yalign),
                                     "ratio",
                                     ratio,
                                     "obey_child",
                                     obey_child,
                                     nullptr))
  {
  }

  AspectFrame::AspectFrame (const float xalign,
                            const float yalign,
                            const float ratio,
                            const bool obey_child)
    : ObjectBase (nullptr),
      Widget (Glib::ConstructParams (aspectframe_class_.init (),
                                     "xalign",
                                     xalign,
                                     "yalign",
                                     yalign,
                                     "ratio",
                                     ratio,
                                     "obey_child",
                                     obey_child,
                                     nullptr))
  {
  }

  auto
  AspectFrame::set_xalign (const Align xalign) -> void
  {
    gtk_aspect_frame_set_xalign (gobj (),
                                 _gtkmm_align_float_from_enum (xalign));
  }

  auto
  AspectFrame::set_xalign (const float xalign) -> void
  {
    gtk_aspect_frame_set_xalign (gobj (), xalign);
  }

  auto
  AspectFrame::get_xalign () const -> float
  {
    return gtk_aspect_frame_get_xalign (const_cast<GtkAspectFrame*> (gobj ()));
  }

  auto
  AspectFrame::set_yalign (const Align yalign) -> void
  {
    gtk_aspect_frame_set_yalign (gobj (),
                                 _gtkmm_align_float_from_enum (yalign));
  }

  auto
  AspectFrame::set_yalign (const float yalign) -> void
  {
    gtk_aspect_frame_set_yalign (gobj (), yalign);
  }

  auto
  AspectFrame::get_yalign () const -> float
  {
    return gtk_aspect_frame_get_yalign (const_cast<GtkAspectFrame*> (gobj ()));
  }

  auto
  AspectFrame::set_ratio (const float ratio) -> void
  {
    gtk_aspect_frame_set_ratio (gobj (), ratio);
  }

  auto
  AspectFrame::get_ratio () const -> float
  {
    return gtk_aspect_frame_get_ratio (const_cast<GtkAspectFrame*> (gobj ()));
  }

  auto
  AspectFrame::set_obey_child (const bool obey_child) -> void
  {
    gtk_aspect_frame_set_obey_child (gobj (), obey_child);
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
    gtk_aspect_frame_set_child (gobj (), child.gobj ());
  }

  auto
  AspectFrame::get_child () -> Widget*
  {
    return Glib::wrap (gtk_aspect_frame_get_child (gobj ()));
  }

  auto
  AspectFrame::get_child () const -> const Widget*
  {
    return const_cast<AspectFrame*> (this)->get_child ();
  }

  auto
  AspectFrame::property_xalign () -> Glib::PropertyProxy<float>
  {
    return {this, "xalign"};
  }

  auto
  AspectFrame::property_xalign () const -> Glib::PropertyProxy_ReadOnly<float>
  {
    return {this, "xalign"};
  }

  auto
  AspectFrame::property_yalign () -> Glib::PropertyProxy<float>
  {
    return {this, "yalign"};
  }

  auto
  AspectFrame::property_yalign () const -> Glib::PropertyProxy_ReadOnly<float>
  {
    return {this, "yalign"};
  }

  auto
  AspectFrame::property_ratio () -> Glib::PropertyProxy<float>
  {
    return {this, "ratio"};
  }

  auto
  AspectFrame::property_ratio () const -> Glib::PropertyProxy_ReadOnly<float>
  {
    return {this, "ratio"};
  }

  auto
  AspectFrame::property_obey_child () -> Glib::PropertyProxy<bool>
  {
    return {this, "obey-child"};
  }

  auto
  AspectFrame::property_obey_child () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "obey-child"};
  }

  auto
  AspectFrame::property_child () -> Glib::PropertyProxy<Widget*>
  {
    return {this, "child"};
  }

  auto
  AspectFrame::property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>
  {
    return {this, "child"};
  }

} // namespace Gtk
