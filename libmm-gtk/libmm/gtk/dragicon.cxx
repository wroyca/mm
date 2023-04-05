// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/dragicon.hxx>
#include <libmm/gtk/dragicon_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  auto
  DragIcon::unset_child () -> void
  {
    gtk_drag_icon_set_child (gobj (), nullptr);
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkDragIcon* object, bool take_copy) -> gtk::DragIcon*
  {
    return dynamic_cast<gtk::DragIcon*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  DragIcon_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &DragIcon_Class::class_init_function;

      gtype_ = gtk_drag_icon_get_type ();
    }

    return *this;
  }

  auto
  DragIcon_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  DragIcon_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new DragIcon ((GtkDragIcon*) (o)));
  }

  DragIcon::DragIcon (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  DragIcon::DragIcon (GtkDragIcon* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  DragIcon::DragIcon (DragIcon&& src) noexcept
    : gtk::Widget (std::move (src)),
      Native (std::move (src)),
      Root (std::move (src))
  {
  }

  auto
  DragIcon::operator= (DragIcon&& src) noexcept -> DragIcon&
  {
    gtk::Widget::operator= (std::move (src));
    Native::operator= (std::move (src));
    Root::operator= (std::move (src));
    return *this;
  }

  DragIcon::~DragIcon () noexcept
  {
    destroy_ ();
  }

  DragIcon::CppClassType DragIcon::dragicon_class_;

  auto
  DragIcon::get_type () -> GType
  {
    return dragicon_class_.init ().get_type ();
  }

  auto
  DragIcon::get_base_type () -> GType
  {
    return gtk_drag_icon_get_type ();
  }

  auto
  DragIcon::get_for_drag (const glib::RefPtr<gdk::Drag>& drag) -> DragIcon*
  {
    return glib::wrap (
        (GtkDragIcon*) (gtk_drag_icon_get_for_drag (glib::unwrap (drag))));
  }

  auto
  DragIcon::set_child (Widget& child) -> void
  {
    gtk_drag_icon_set_child (gobj (), (child).gobj ());
  }

  auto
  DragIcon::get_child () -> Widget*
  {
    return glib::wrap (gtk_drag_icon_get_child (gobj ()));
  }

  auto
  DragIcon::get_child () const -> const Widget*
  {
    return const_cast<DragIcon*> (this)->get_child ();
  }

  auto
  DragIcon::set_from_paintable (const glib::RefPtr<gdk::Drag>& drag,
                                const glib::RefPtr<gdk::Paintable>& paintable,
                                int hot_x,
                                int hot_y) -> void
  {
    gtk_drag_icon_set_from_paintable (glib::unwrap (drag),
                                      glib::unwrap (paintable),
                                      hot_x,
                                      hot_y);
  }

  auto
  DragIcon::create_widget_for_value (const glib::ValueBase& value) -> Widget*
  {
    return glib::wrap (gtk_drag_icon_create_widget_for_value ((value).gobj ()));
  }

  auto
  DragIcon::property_child () -> glib::PropertyProxy<Widget*>
  {
    return glib::PropertyProxy<Widget*> (this, "child");
  }

  auto
  DragIcon::property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "child");
  }

} // namespace gtk
