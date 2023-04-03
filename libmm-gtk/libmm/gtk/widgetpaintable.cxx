// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/widgetpaintable.hxx>
#include <libmm/gtk/widgetpaintable_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  auto
  WidgetPaintable::unset_widget () -> void
  {
    gtk_widget_paintable_set_widget (gobj (), nullptr);
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkWidgetPaintable* object, bool take_copy) -> Glib::RefPtr<Gtk::WidgetPaintable>
  {
    return Glib::make_refptr_for_instance<Gtk::WidgetPaintable> (
        dynamic_cast<Gtk::WidgetPaintable*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  WidgetPaintable_Class::init () -> const Glib::Class&
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
  WidgetPaintable_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
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
      const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  WidgetPaintable::WidgetPaintable (GtkWidgetPaintable* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  WidgetPaintable::WidgetPaintable (WidgetPaintable&& src) noexcept
    : Glib::Object (std::move (src)),
      Gdk::Paintable (std::move (src))
  {
  }

  auto
  WidgetPaintable::operator= (WidgetPaintable&& src) noexcept -> WidgetPaintable&
  {
    Glib::Object::operator= (std::move (src));
    Gdk::Paintable::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (widgetpaintable_class_.init ()))
  {
  }

  WidgetPaintable::WidgetPaintable (Widget& widget)
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (widgetpaintable_class_.init (),
                                           "widget",
                                           (widget).gobj (),
                                           nullptr))
  {
  }

  auto
  WidgetPaintable::create () -> Glib::RefPtr<WidgetPaintable>
  {
    return Glib::make_refptr_for_instance<WidgetPaintable> (
        new WidgetPaintable ());
  }

  auto
  WidgetPaintable::create (Widget& widget) -> Glib::RefPtr<WidgetPaintable>
  {
    return Glib::make_refptr_for_instance<WidgetPaintable> (
        new WidgetPaintable (widget));
  }

  auto
  WidgetPaintable::get_widget () -> Widget*
  {
    return Glib::wrap (gtk_widget_paintable_get_widget (gobj ()));
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
  WidgetPaintable::property_widget () -> Glib::PropertyProxy<Widget*>
  {
    return Glib::PropertyProxy<Widget*> (this, "widget");
  }

  auto
  WidgetPaintable::property_widget () const -> Glib::PropertyProxy_ReadOnly<Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Widget*> (this, "widget");
  }

} // namespace Gtk