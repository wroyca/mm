// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/drawingarea.hxx>
#include <libmm/gtk/drawingarea_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gdk/cairoutils.hxx>

namespace
{

  auto
  SignalProxy_Draw_gtk_callback (GtkDrawingArea*,
                                 cairo_t* cr,
                                 int width,
                                 int height,
                                 void* user_data) -> void
  {
    auto the_slot = static_cast<gtk::DrawingArea::SlotDraw*> (user_data);
    auto cr2 = gdk::cairo::wrap (cr, false);

    try
    {
      (*the_slot) (cr2, width, height);
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
    }
  }

} // namespace

namespace gtk
{
  auto
  DrawingArea::set_draw_func (const SlotDraw& slot) -> void
  {
    auto slot_copy = new SlotDraw (slot);

    gtk_drawing_area_set_draw_func (gobj (),
                                    &SignalProxy_Draw_gtk_callback,
                                    slot_copy,
                                    &glib::destroy_notify_delete<SlotDraw>);
  }

} // namespace gtk

namespace
{

  static auto
  DrawingArea_signal_resize_callback (GtkDrawingArea* self,
                                      gint p0,
                                      gint p1,
                                      void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (int, int)>;

    auto obj = dynamic_cast<DrawingArea*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0, p1);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo DrawingArea_signal_resize_info = {
      "resize",
      (GCallback) &DrawingArea_signal_resize_callback,
      (GCallback) &DrawingArea_signal_resize_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkDrawingArea* object, bool take_copy) -> gtk::DrawingArea*
  {
    return dynamic_cast<gtk::DrawingArea*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  DrawingArea_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &DrawingArea_Class::class_init_function;

      register_derived_type (gtk_drawing_area_get_type ());
    }

    return *this;
  }

  auto
  DrawingArea_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->resize = &resize_callback;
  }

  auto
  DrawingArea_Class::resize_callback (GtkDrawingArea* self, gint p0, gint p1) -> void
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
          obj->on_resize (p0, p1);
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->resize)
      (*base->resize) (self, p0, p1);
  }

  auto
  DrawingArea_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new DrawingArea ((GtkDrawingArea*) (o)));
  }

  DrawingArea::DrawingArea (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  DrawingArea::DrawingArea (GtkDrawingArea* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  DrawingArea::DrawingArea (DrawingArea&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  DrawingArea::operator= (DrawingArea&& src) noexcept -> DrawingArea&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  DrawingArea::~DrawingArea () noexcept
  {
    destroy_ ();
  }

  DrawingArea::CppClassType DrawingArea::drawingarea_class_;

  auto
  DrawingArea::get_type () -> GType
  {
    return drawingarea_class_.init ().get_type ();
  }

  auto
  DrawingArea::get_base_type () -> GType
  {
    return gtk_drawing_area_get_type ();
  }

  DrawingArea::DrawingArea ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (drawingarea_class_.init ()))
  {
  }

  auto
  DrawingArea::set_content_width (int width) -> void
  {
    gtk_drawing_area_set_content_width (gobj (), width);
  }

  auto
  DrawingArea::get_content_width () const -> int
  {
    return gtk_drawing_area_get_content_width (
        const_cast<GtkDrawingArea*> (gobj ()));
  }

  auto
  DrawingArea::set_content_height (int width) -> void
  {
    gtk_drawing_area_set_content_height (gobj (), width);
  }

  auto
  DrawingArea::get_content_height () const -> int
  {
    return gtk_drawing_area_get_content_height (
        const_cast<GtkDrawingArea*> (gobj ()));
  }

  auto
  DrawingArea::signal_resize () -> glib::SignalProxy<void (int, int)>
  {
    return glib::SignalProxy<void (int, int)> (this,
                                               &DrawingArea_signal_resize_info);
  }

  auto
  DrawingArea::property_content_width () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "content-width");
  }

  auto
  DrawingArea::property_content_width () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "content-width");
  }

  auto
  DrawingArea::property_content_height () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "content-height");
  }

  auto
  DrawingArea::property_content_height () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "content-height");
  }

  auto
  gtk::DrawingArea::on_resize (int width, int height) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->resize)
      (*base->resize) (gobj (), width, height);
  }

} // namespace gtk
