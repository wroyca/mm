// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/gesturedrag.hxx>
#include <libmm/gtk/gesturedrag_p.hxx>

#include <gtk/gtk.h>

namespace
{

  static auto
  GestureDrag_signal_drag_begin_callback (GtkGestureDrag* self,
                                          gdouble p0,
                                          gdouble p1,
                                          void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (double, double)>;

    auto obj = dynamic_cast<GestureDrag*> (
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

  static const glib::SignalProxyInfo GestureDrag_signal_drag_begin_info = {
      "drag-begin",
      (GCallback) &GestureDrag_signal_drag_begin_callback,
      (GCallback) &GestureDrag_signal_drag_begin_callback};

  static auto
  GestureDrag_signal_drag_update_callback (GtkGestureDrag* self,
                                           gdouble p0,
                                           gdouble p1,
                                           void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (double, double)>;

    auto obj = dynamic_cast<GestureDrag*> (
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

  static const glib::SignalProxyInfo GestureDrag_signal_drag_update_info = {
      "drag-update",
      (GCallback) &GestureDrag_signal_drag_update_callback,
      (GCallback) &GestureDrag_signal_drag_update_callback};

  static auto
  GestureDrag_signal_drag_end_callback (GtkGestureDrag* self,
                                        gdouble p0,
                                        gdouble p1,
                                        void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (double, double)>;

    auto obj = dynamic_cast<GestureDrag*> (
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

  static const glib::SignalProxyInfo GestureDrag_signal_drag_end_info = {
      "drag-end",
      (GCallback) &GestureDrag_signal_drag_end_callback,
      (GCallback) &GestureDrag_signal_drag_end_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkGestureDrag* object, bool take_copy) -> glib::RefPtr<gtk::GestureDrag>
  {
    return glib::make_refptr_for_instance<gtk::GestureDrag> (
        dynamic_cast<gtk::GestureDrag*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  GestureDrag_Class::init () -> const glib::Class&
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
  GestureDrag_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new GestureDrag ((GtkGestureDrag*) object);
  }

  auto
  GestureDrag::gobj_copy () -> GtkGestureDrag*
  {
    reference ();
    return gobj ();
  }

  GestureDrag::GestureDrag (const glib::ConstructParams& construct_params)
    : GestureSingle (construct_params)
  {
  }

  GestureDrag::GestureDrag (GtkGestureDrag* castitem)
    : GestureSingle ((GtkGestureSingle*) (castitem))
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

  GestureDrag::~GestureDrag () noexcept {}

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
    : glib::ObjectBase (nullptr),
      GestureSingle (glib::ConstructParams (gesturedrag_class_.init ()))
  {
  }

  auto
  GestureDrag::create () -> glib::RefPtr<GestureDrag>
  {
    return glib::make_refptr_for_instance<GestureDrag> (new GestureDrag ());
  }

  auto
  GestureDrag::get_start_point (double& x, double& y) const -> bool
  {
    return gtk_gesture_drag_get_start_point (
        const_cast<GtkGestureDrag*> (gobj ()),
        &(x),
        &(y));
  }

  auto
  GestureDrag::get_offset (double& x, double& y) const -> bool
  {
    return gtk_gesture_drag_get_offset (const_cast<GtkGestureDrag*> (gobj ()),
                                        &(x),
                                        &(y));
  }

  auto
  GestureDrag::signal_drag_begin () -> glib::SignalProxy<void (double, double)>
  {
    return glib::SignalProxy<void (double, double)> (
        this,
        &GestureDrag_signal_drag_begin_info);
  }

  auto
  GestureDrag::signal_drag_update () -> glib::SignalProxy<void (double, double)>
  {
    return glib::SignalProxy<void (double, double)> (
        this,
        &GestureDrag_signal_drag_update_info);
  }

  auto
  GestureDrag::signal_drag_end () -> glib::SignalProxy<void (double, double)>
  {
    return glib::SignalProxy<void (double, double)> (
        this,
        &GestureDrag_signal_drag_end_info);
  }

} // namespace gtk
