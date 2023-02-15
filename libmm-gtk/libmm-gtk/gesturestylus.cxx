// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/gesturestylus.hxx>
#include <libmm-gtk/gesturestylus_p.hxx>

#include <gtk/gtk.h>
#include <libmm-gdk/devicetool.hxx>
#include <memory>

namespace Gtk
{

  auto
  GestureStylus::get_axis (Gdk::AxisUse axis) const -> std::optional<double>
  {
    double g_value = double ();
    auto retvalue = gtk_gesture_stylus_get_axis (
        const_cast<GtkGestureStylus*> (gobj ()),
        static_cast<GdkAxisUse> (axis),
        &g_value);

    if (retvalue)
      return g_value;
    else
      return {};
  }

  auto
  GestureStylus::get_axes (const std::vector<Gdk::AxisUse>& axes) const -> std::vector<double>
  {
    auto g_axes = std::make_unique<GdkAxisUse[]> (axes.size () + 1);
    for (std::size_t i = 0; i < axes.size (); ++i)
      g_axes[i] = static_cast<GdkAxisUse> (axes[i]);
    g_axes[axes.size ()] = GDK_AXIS_IGNORE;

    double* g_values = nullptr;
    const bool result = gtk_gesture_stylus_get_axes (
        const_cast<GtkGestureStylus*> (gobj ()),
        g_axes.get (),
        &g_values);

    if (result)
      return Glib::ArrayHandler<double>::array_to_vector (g_values,
                                                          axes.size (),
                                                          Glib::OWNERSHIP_DEEP);
    else
      return {};
  }

  auto
  GestureStylus::get_backlog () const -> std::vector<Gdk::TimeCoord>
  {
    GdkTimeCoord* g_backlog = nullptr;
    guint n_elems = 0;
    const bool result = gtk_gesture_stylus_get_backlog (
        const_cast<GtkGestureStylus*> (gobj ()),
        &g_backlog,
        &n_elems);

    if (result)
      return Glib::ArrayHandler<Gdk::TimeCoord, Gdk::TimeCoordTraits>::
          array_to_vector (g_backlog, n_elems, Glib::OWNERSHIP_DEEP);
    else
      return {};
  }

} // namespace Gtk

namespace
{

  static auto
  GestureStylus_signal_proximity_callback (GtkGestureStylus* self,
                                           gdouble p0,
                                           gdouble p1,
                                           void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (double, double)>;

    auto obj = dynamic_cast<GestureStylus*> (
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

  static const Glib::SignalProxyInfo GestureStylus_signal_proximity_info = {
      "proximity",
      (GCallback) &GestureStylus_signal_proximity_callback,
      (GCallback) &GestureStylus_signal_proximity_callback};

  static auto
  GestureStylus_signal_down_callback (GtkGestureStylus* self,
                                      gdouble p0,
                                      gdouble p1,
                                      void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (double, double)>;

    auto obj = dynamic_cast<GestureStylus*> (
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

  static const Glib::SignalProxyInfo GestureStylus_signal_down_info = {
      "down",
      (GCallback) &GestureStylus_signal_down_callback,
      (GCallback) &GestureStylus_signal_down_callback};

  static auto
  GestureStylus_signal_motion_callback (GtkGestureStylus* self,
                                        gdouble p0,
                                        gdouble p1,
                                        void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (double, double)>;

    auto obj = dynamic_cast<GestureStylus*> (
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

  static const Glib::SignalProxyInfo GestureStylus_signal_motion_info = {
      "motion",
      (GCallback) &GestureStylus_signal_motion_callback,
      (GCallback) &GestureStylus_signal_motion_callback};

  static auto
  GestureStylus_signal_up_callback (GtkGestureStylus* self,
                                    gdouble p0,
                                    gdouble p1,
                                    void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (double, double)>;

    auto obj = dynamic_cast<GestureStylus*> (
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

  static const Glib::SignalProxyInfo GestureStylus_signal_up_info = {
      "up",
      (GCallback) &GestureStylus_signal_up_callback,
      (GCallback) &GestureStylus_signal_up_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkGestureStylus* object, bool take_copy) -> Glib::RefPtr<Gtk::GestureStylus>
  {
    return Glib::make_refptr_for_instance<Gtk::GestureStylus> (
        dynamic_cast<Gtk::GestureStylus*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  GestureStylus_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &GestureStylus_Class::class_init_function;

      register_derived_type (gtk_gesture_stylus_get_type ());
    }

    return *this;
  }

  auto
  GestureStylus_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  GestureStylus_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new GestureStylus ((GtkGestureStylus*) object);
  }

  auto
  GestureStylus::gobj_copy () -> GtkGestureStylus*
  {
    reference ();
    return gobj ();
  }

  GestureStylus::GestureStylus (const Glib::ConstructParams& construct_params)
    : GestureSingle (construct_params)
  {
  }

  GestureStylus::GestureStylus (GtkGestureStylus* castitem)
    : GestureSingle ((GtkGestureSingle*) (castitem))
  {
  }

  GestureStylus::GestureStylus (GestureStylus&& src) noexcept
    : GestureSingle (std::move (src))
  {
  }

  auto
  GestureStylus::operator= (GestureStylus&& src) noexcept -> GestureStylus&
  {
    GestureSingle::operator= (std::move (src));
    return *this;
  }

  GestureStylus::~GestureStylus () noexcept {}

  GestureStylus::CppClassType GestureStylus::gesturestylus_class_;

  auto
  GestureStylus::get_type () -> GType
  {
    return gesturestylus_class_.init ().get_type ();
  }

  auto
  GestureStylus::get_base_type () -> GType
  {
    return gtk_gesture_stylus_get_type ();
  }

  GestureStylus::GestureStylus ()
    : Glib::ObjectBase (nullptr),
      GestureSingle (Glib::ConstructParams (gesturestylus_class_.init ()))
  {
  }

  auto
  GestureStylus::create () -> Glib::RefPtr<GestureStylus>
  {
    return Glib::make_refptr_for_instance<GestureStylus> (new GestureStylus ());
  }

  auto
  GestureStylus::get_stylus_only () const -> bool
  {
    return gtk_gesture_stylus_get_stylus_only (
        const_cast<GtkGestureStylus*> (gobj ()));
  }

  auto
  GestureStylus::set_stylus_only (bool stylus_only) -> void
  {
    gtk_gesture_stylus_set_stylus_only (gobj (),
                                        static_cast<int> (stylus_only));
  }

  auto
  GestureStylus::get_device_tool () -> Glib::RefPtr<Gdk::DeviceTool>
  {
    auto retvalue = Glib::wrap (gtk_gesture_stylus_get_device_tool (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  GestureStylus::get_device_tool () const -> Glib::RefPtr<const Gdk::DeviceTool>
  {
    return const_cast<GestureStylus*> (this)->get_device_tool ();
  }

  auto
  GestureStylus::signal_proximity () -> Glib::SignalProxy<void (double, double)>
  {
    return Glib::SignalProxy<void (double, double)> (
        this,
        &GestureStylus_signal_proximity_info);
  }

  auto
  GestureStylus::signal_down () -> Glib::SignalProxy<void (double, double)>
  {
    return Glib::SignalProxy<void (double, double)> (
        this,
        &GestureStylus_signal_down_info);
  }

  auto
  GestureStylus::signal_motion () -> Glib::SignalProxy<void (double, double)>
  {
    return Glib::SignalProxy<void (double, double)> (
        this,
        &GestureStylus_signal_motion_info);
  }

  auto
  GestureStylus::signal_up () -> Glib::SignalProxy<void (double, double)>
  {
    return Glib::SignalProxy<void (double, double)> (
        this,
        &GestureStylus_signal_up_info);
  }

  auto
  GestureStylus::property_stylus_only () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "stylus-only");
  }

  auto
  GestureStylus::property_stylus_only () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "stylus-only");
  }

} // namespace Gtk
