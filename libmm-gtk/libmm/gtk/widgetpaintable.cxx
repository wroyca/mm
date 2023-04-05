// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/widgetpaintable.hxx>
#include <libmm/gtk/widgetpaintable_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  auto
  WidgetPaintable::unset_widget () -> void
  {
    gtk_widget_paintable_set_widget (gobj (), nullptr);
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkWidgetPaintable* object, bool take_copy) -> glib::RefPtr<gtk::WidgetPaintable>
  {
    return glib::make_refptr_for_instance<gtk::WidgetPaintable> (
        dynamic_cast<gtk::WidgetPaintable*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  WidgetPaintable_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &WidgetPaintable_Class::class_init_function;

      gtype_ = gtk_widget_paintable_get_type ();
    }

    return *this;
  }

  auto
  WidgetPaintable_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  WidgetPaintable_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new WidgetPaintable ((GtkWidgetPaintable*) object);
  }

  auto
  WidgetPaintable::gobj_copy () -> GtkWidgetPaintable*
  {
    reference ();
    return gobj ();
  }

  WidgetPaintable::WidgetPaintable (
      const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  WidgetPaintable::WidgetPaintable (GtkWidgetPaintable* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  WidgetPaintable::WidgetPaintable (WidgetPaintable&& src) noexcept
    : glib::Object (std::move (src)),
      gdk::Paintable (std::move (src))
  {
  }

  auto
  WidgetPaintable::operator= (WidgetPaintable&& src) noexcept -> WidgetPaintable&
  {
    glib::Object::operator= (std::move (src));
    gdk::Paintable::operator= (std::move (src));
    return *this;
  }

  WidgetPaintable::~WidgetPaintable () noexcept {}

  WidgetPaintable::CppClassType WidgetPaintable::widgetpaintable_class_;

  auto
  WidgetPaintable::get_type () -> GType
  {
    return widgetpaintable_class_.init ().get_type ();
  }

  auto
  WidgetPaintable::get_base_type () -> GType
  {
    return gtk_widget_paintable_get_type ();
  }

  WidgetPaintable::WidgetPaintable ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (widgetpaintable_class_.init ()))
  {
  }

  WidgetPaintable::WidgetPaintable (Widget& widget)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (widgetpaintable_class_.init (),
                                           "widget",
                                           (widget).gobj (),
                                           nullptr))
  {
  }

  auto
  WidgetPaintable::create () -> glib::RefPtr<WidgetPaintable>
  {
    return glib::make_refptr_for_instance<WidgetPaintable> (
        new WidgetPaintable ());
  }

  auto
  WidgetPaintable::create (Widget& widget) -> glib::RefPtr<WidgetPaintable>
  {
    return glib::make_refptr_for_instance<WidgetPaintable> (
        new WidgetPaintable (widget));
  }

  auto
  WidgetPaintable::get_widget () -> Widget*
  {
    return glib::wrap (gtk_widget_paintable_get_widget (gobj ()));
  }

  auto
  WidgetPaintable::get_widget () const -> const Widget*
  {
    return const_cast<WidgetPaintable*> (this)->get_widget ();
  }

  auto
  WidgetPaintable::set_widget (Widget& widget) -> void
  {
    gtk_widget_paintable_set_widget (gobj (), (widget).gobj ());
  }

  auto
  WidgetPaintable::property_widget () -> glib::PropertyProxy<Widget*>
  {
    return glib::PropertyProxy<Widget*> (this, "widget");
  }

  auto
  WidgetPaintable::property_widget () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "widget");
  }

} // namespace gtk
