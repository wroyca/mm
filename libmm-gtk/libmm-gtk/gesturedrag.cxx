

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/gesturedrag.hxx>
#include <libmm-gtk/gesturedrag_p.hxx>

#include <gtk/gtk.h>

namespace
{

  auto
  GestureDrag_signal_drag_begin_callback (GtkGestureDrag* self,
                                          const gdouble p0,
                                          const gdouble p1,
                                          void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (double, double)>;

    const auto obj = dynamic_cast<GestureDrag*> (
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

  const Glib::SignalProxyInfo GestureDrag_signal_drag_begin_info = {
      "drag-begin",
      (GCallback) &GestureDrag_signal_drag_begin_callback,
      (GCallback) &GestureDrag_signal_drag_begin_callback};

  auto
  GestureDrag_signal_drag_update_callback (GtkGestureDrag* self,
                                           const gdouble p0,
                                           const gdouble p1,
                                           void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (double, double)>;

    const auto obj = dynamic_cast<GestureDrag*> (
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

  const Glib::SignalProxyInfo GestureDrag_signal_drag_update_info = {
      "drag-update",
      (GCallback) &GestureDrag_signal_drag_update_callback,
      (GCallback) &GestureDrag_signal_drag_update_callback};

  auto
  GestureDrag_signal_drag_end_callback (GtkGestureDrag* self,
                                        const gdouble p0,
                                        const gdouble p1,
                                        void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (double, double)>;

    const auto obj = dynamic_cast<GestureDrag*> (
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

  const Glib::SignalProxyInfo GestureDrag_signal_drag_end_info = {
      "drag-end",
      (GCallback) &GestureDrag_signal_drag_end_callback,
      (GCallback) &GestureDrag_signal_drag_end_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkGestureDrag* object, const bool take_copy) -> RefPtr<Gtk::GestureDrag>
  {
    return Glib::make_refptr_for_instance<Gtk::GestureDrag> (
        dynamic_cast<Gtk::GestureDrag*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  GestureDrag_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &GestureDrag_Class::class_init_function;

      register_derived_type (gtk_gesture_drag_get_type ());
    }

    return *this;
  }

  auto
  GestureDrag_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  GestureDrag_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new GestureDrag ((GtkGestureDrag*) object);
  }

  auto
  GestureDrag::gobj_copy () -> GtkGestureDrag*
  {
    reference ();
    return gobj ();
  }

  GestureDrag::GestureDrag (const Glib::ConstructParams& construct_params)
    : GestureSingle (construct_params)
  {
  }

  GestureDrag::GestureDrag (GtkGestureDrag* castitem)
    : GestureSingle ((GtkGestureSingle*) castitem)
  {
  }

  GestureDrag::GestureDrag (GestureDrag&& src) noexcept
    : GestureSingle (std::move (src))
  {
  }

  auto
  GestureDrag::operator= (GestureDrag&& src) noexcept -> GestureDrag&
  {
    GestureSingle::operator= (std::move (src));
    return *this;
  }

  GestureDrag::~GestureDrag () noexcept = default;

  GestureDrag::CppClassType GestureDrag::gesturedrag_class_;

  auto
  GestureDrag::get_type () -> GType
  {
    return gesturedrag_class_.init ().get_type ();
  }

  auto
  GestureDrag::get_base_type () -> GType
  {
    return gtk_gesture_drag_get_type ();
  }

  GestureDrag::GestureDrag ()
    : ObjectBase (nullptr),
      GestureSingle (Glib::ConstructParams (gesturedrag_class_.init ()))
  {
  }

  auto
  GestureDrag::create () -> Glib::RefPtr<GestureDrag>
  {
    return Glib::make_refptr_for_instance<GestureDrag> (new GestureDrag ());
  }

  auto
  GestureDrag::get_start_point (double& x, double& y) const -> bool
  {
    return gtk_gesture_drag_get_start_point (
        const_cast<GtkGestureDrag*> (gobj ()),
        &x,
        &y);
  }

  auto
  GestureDrag::get_offset (double& x, double& y) const -> bool
  {
    return gtk_gesture_drag_get_offset (const_cast<GtkGestureDrag*> (gobj ()),
                                        &x,
                                        &y);
  }

  auto
  GestureDrag::signal_drag_begin () -> Glib::SignalProxy<void (double, double)>
  {
    return {this, &GestureDrag_signal_drag_begin_info};
  }

  auto
  GestureDrag::signal_drag_update () -> Glib::SignalProxy<void (double, double)>
  {
    return {this, &GestureDrag_signal_drag_update_info};
  }

  auto
  GestureDrag::signal_drag_end () -> Glib::SignalProxy<void (double, double)>
  {
    return {this, &GestureDrag_signal_drag_end_info};
  }

} // namespace Gtk
