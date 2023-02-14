

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/drawingarea.hxx>
#include <libmm-gtk/drawingarea_p.hxx>

#include <gtk/gtk.h>
#include <libmm-gdk/cairoutils.hxx>

namespace
{

  auto
  SignalProxy_Draw_gtk_callback (GtkDrawingArea*,
                                 cairo_t* cr,
                                 const int width,
                                 const int height,
                                 void* user_data) -> void
  {
    const auto the_slot = static_cast<Gtk::DrawingArea::SlotDraw*> (user_data);
    const auto cr2 = Gdk::Cairo::wrap (cr, false);

    try
    {
      (*the_slot) (cr2, width, height);
    }
    catch (...)
    {
      Glib::exception_handlers_invoke ();
    }
  }

} // namespace

namespace Gtk
{
  auto
  DrawingArea::set_draw_func (const SlotDraw& slot) -> void
  {
    const auto slot_copy = new SlotDraw (slot);

    gtk_drawing_area_set_draw_func (gobj (),
                                    &SignalProxy_Draw_gtk_callback,
                                    slot_copy,
                                    &Glib::destroy_notify_delete<SlotDraw>);
  }

} // namespace Gtk

namespace
{

  auto
  DrawingArea_signal_resize_callback (GtkDrawingArea* self,
                                      const gint p0,
                                      const gint p1,
                                      void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (int, int)>;

    const auto obj = dynamic_cast<DrawingArea*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0, p1);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  const Glib::SignalProxyInfo DrawingArea_signal_resize_info = {
      "resize",
      (GCallback) &DrawingArea_signal_resize_callback,
      (GCallback) &DrawingArea_signal_resize_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkDrawingArea* object, const bool take_copy) -> Gtk::DrawingArea*
  {
    return dynamic_cast<Gtk::DrawingArea*> (
        wrap_auto ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  DrawingArea_Class::init () -> const Class&
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
  DrawingArea_Class::resize_callback (GtkDrawingArea* self,
                                      const gint p0,
                                      const gint p1) -> void
  {
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

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
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->resize)
      (*base->resize) (self, p0, p1);
  }

  auto
  DrawingArea_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new DrawingArea ((GtkDrawingArea*) o));
  }

  DrawingArea::DrawingArea (const Glib::ConstructParams& construct_params)
    : Widget (construct_params)
  {
  }

  DrawingArea::DrawingArea (GtkDrawingArea* castitem)
    : Widget ((GtkWidget*) castitem)
  {
  }

  DrawingArea::DrawingArea (DrawingArea&& src) noexcept
    : Widget (std::move (src))
  {
  }

  auto
  DrawingArea::operator= (DrawingArea&& src) noexcept -> DrawingArea&
  {
    Widget::operator= (std::move (src));
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
    : ObjectBase (nullptr),
      Widget (Glib::ConstructParams (drawingarea_class_.init ()))
  {
  }

  auto
  DrawingArea::set_content_width (const int width) -> void
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
  DrawingArea::set_content_height (const int width) -> void
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
  DrawingArea::signal_resize () -> Glib::SignalProxy<void (int, int)>
  {
    return {this, &DrawingArea_signal_resize_info};
  }

  auto
  DrawingArea::property_content_width () -> Glib::PropertyProxy<int>
  {
    return {this, "content-width"};
  }

  auto
  DrawingArea::property_content_width () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "content-width"};
  }

  auto
  DrawingArea::property_content_height () -> Glib::PropertyProxy<int>
  {
    return {this, "content-height"};
  }

  auto
  DrawingArea::property_content_height () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "content-height"};
  }

  auto
  DrawingArea::on_resize (const int width, const int height) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->resize)
      (*base->resize) (gobj (), width, height);
  }

} // namespace Gtk
