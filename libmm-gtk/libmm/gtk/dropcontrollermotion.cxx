// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/dropcontrollermotion.hxx>
#include <libmm/gtk/dropcontrollermotion_p.hxx>

#include <gtk/gtk.h>

namespace
{

  static auto
  DropControllerMotion_signal_enter_callback (GtkDropControllerMotion* self,
                                              gdouble p0,
                                              gdouble p1,
                                              void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (double, double)>;

    auto obj = dynamic_cast<DropControllerMotion*> (
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

  static const glib::SignalProxyInfo DropControllerMotion_signal_enter_info = {
      "enter",
      (GCallback) &DropControllerMotion_signal_enter_callback,
      (GCallback) &DropControllerMotion_signal_enter_callback};

  static const glib::SignalProxyInfo DropControllerMotion_signal_leave_info = {
      "leave",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static auto
  DropControllerMotion_signal_motion_callback (GtkDropControllerMotion* self,
                                               gdouble p0,
                                               gdouble p1,
                                               void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (double, double)>;

    auto obj = dynamic_cast<DropControllerMotion*> (
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

  static const glib::SignalProxyInfo DropControllerMotion_signal_motion_info = {
      "motion",
      (GCallback) &DropControllerMotion_signal_motion_callback,
      (GCallback) &DropControllerMotion_signal_motion_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkDropControllerMotion* object, bool take_copy) -> glib::RefPtr<gtk::DropControllerMotion>
  {
    return glib::make_refptr_for_instance<gtk::DropControllerMotion> (
        dynamic_cast<gtk::DropControllerMotion*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  DropControllerMotion_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &DropControllerMotion_Class::class_init_function;

      register_derived_type (gtk_drop_controller_motion_get_type ());
    }

    return *this;
  }

  auto
  DropControllerMotion_Class::class_init_function (void* g_class,
                                                   void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  DropControllerMotion_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new DropControllerMotion ((GtkDropControllerMotion*) object);
  }

  auto
  DropControllerMotion::gobj_copy () -> GtkDropControllerMotion*
  {
    reference ();
    return gobj ();
  }

  DropControllerMotion::DropControllerMotion (
      const glib::ConstructParams& construct_params)
    : EventController (construct_params)
  {
  }

  DropControllerMotion::DropControllerMotion (GtkDropControllerMotion* castitem)
    : EventController ((GtkEventController*) (castitem))
  {
  }

  DropControllerMotion::DropControllerMotion (
      DropControllerMotion&& src) noexcept
    : EventController (std::move (src))
  {
  }

  auto
  DropControllerMotion::operator= (DropControllerMotion&& src) noexcept -> DropControllerMotion&
  {
    EventController::operator= (std::move (src));
    return *this;
  }

  DropControllerMotion::~DropControllerMotion () noexcept {}

  DropControllerMotion::CppClassType
      DropControllerMotion::dropcontrollermotion_class_;

  auto
  DropControllerMotion::get_type () -> GType
  {
    return dropcontrollermotion_class_.init ().get_type ();
  }

  auto
  DropControllerMotion::get_base_type () -> GType
  {
    return gtk_drop_controller_motion_get_type ();
  }

  DropControllerMotion::DropControllerMotion ()
    : glib::ObjectBase (nullptr),
      EventController (
          glib::ConstructParams (dropcontrollermotion_class_.init ()))
  {
  }

  auto
  DropControllerMotion::create () -> glib::RefPtr<DropControllerMotion>
  {
    return glib::make_refptr_for_instance<DropControllerMotion> (
        new DropControllerMotion ());
  }

  auto
  DropControllerMotion::contains_pointer () const -> bool
  {
    return gtk_drop_controller_motion_contains_pointer (
        const_cast<GtkDropControllerMotion*> (gobj ()));
  }

  auto
  DropControllerMotion::is_pointer () const -> bool
  {
    return gtk_drop_controller_motion_is_pointer (
        const_cast<GtkDropControllerMotion*> (gobj ()));
  }

  auto
  DropControllerMotion::get_drop () -> glib::RefPtr<gdk::Drop>
  {
    auto retvalue = glib::wrap (gtk_drop_controller_motion_get_drop (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DropControllerMotion::get_drop () const -> glib::RefPtr<const gdk::Drop>
  {
    return const_cast<DropControllerMotion*> (this)->get_drop ();
  }

  auto
  DropControllerMotion::signal_enter () -> glib::SignalProxy<void (double, double)>
  {
    return glib::SignalProxy<void (double, double)> (
        this,
        &DropControllerMotion_signal_enter_info);
  }

  auto
  DropControllerMotion::signal_leave () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this,
                                       &DropControllerMotion_signal_leave_info);
  }

  auto
  DropControllerMotion::signal_motion () -> glib::SignalProxy<void (double, double)>
  {
    return glib::SignalProxy<void (double, double)> (
        this,
        &DropControllerMotion_signal_motion_info);
  }

  auto
  DropControllerMotion::property_contains_pointer () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "contains-pointer");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gdk::Drop>>::value,
      "Type glib::RefPtr<gdk::Drop> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  DropControllerMotion::property_drop () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Drop>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Drop>> (this, "drop");
  }

  auto
  DropControllerMotion::property_is_pointer () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "is-pointer");
  }

} // namespace gtk
