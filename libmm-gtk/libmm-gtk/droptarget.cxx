// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/droptarget.hxx>
#include <libmm-gtk/droptarget_p.hxx>

#include <gtk/gtk.h>
#include <libmm-glib/vectorutils.hxx>

namespace Gtk
{
  auto
  DropTarget::set_gtypes (const std::vector<GType>& types) -> void
  {
    gtk_drop_target_set_gtypes (gobj (),
                                const_cast<GType*> (types.data ()),
                                types.size ());
  }

  auto
  DropTarget::get_gtypes () const -> std::vector<GType>
  {
    gsize n_gtypes = 0;
    const GType* gtype_array = gtk_drop_target_get_gtypes (
        const_cast<GtkDropTarget*> (gobj ()),
        &n_gtypes);
    return Glib::ArrayHandler<GType>::array_to_vector (gtype_array,
                                                       n_gtypes,
                                                       Glib::OWNERSHIP_NONE);
  }

  auto
  DropTarget::get_value () const -> Glib::ValueBase
  {
    const GValue* gvalue =
        gtk_drop_target_get_value (const_cast<GtkDropTarget*> (gobj ()));

    Glib::ValueBase retvalue;
    if (gvalue)
      retvalue.init (gvalue);
    return retvalue;
  }

} // namespace Gtk

namespace
{

  auto
  DropTarget_signal_accept_callback (GtkDropTarget* self,
                                     GdkDrop* p0,
                                     void* data) -> gboolean
  {
    using namespace Gtk;
    using SlotType = sigc::slot<bool (const Glib::RefPtr<Gdk::Drop>&)>;

    const auto obj = dynamic_cast<DropTarget*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          return (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  auto
  DropTarget_signal_accept_notify_callback (GtkDropTarget* self,
                                            GdkDrop* p0,
                                            void* data) -> gboolean
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (const Glib::RefPtr<Gdk::Drop>&)>;

    const auto obj = dynamic_cast<DropTarget*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  const Glib::SignalProxyInfo DropTarget_signal_accept_info = {
      "accept",
      (GCallback) &DropTarget_signal_accept_callback,
      (GCallback) &DropTarget_signal_accept_notify_callback};

  auto
  DropTarget_signal_enter_callback (GtkDropTarget* self,
                                    const gdouble p0,
                                    const gdouble p1,
                                    void* data) -> GdkDragAction
  {
    using namespace Gtk;
    using SlotType = sigc::slot<Gdk::DragAction (double, double)>;

    const auto obj = dynamic_cast<DropTarget*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<GdkDragAction> (
              (*static_cast<SlotType*> (slot)) (p0, p1));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = GdkDragAction;
    return RType ();
  }

  auto
  DropTarget_signal_enter_notify_callback (GtkDropTarget* self,
                                           const gdouble p0,
                                           const gdouble p1,
                                           void* data) -> GdkDragAction
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (double, double)>;

    const auto obj = dynamic_cast<DropTarget*> (
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

    using RType = GdkDragAction;
    return RType ();
  }

  const Glib::SignalProxyInfo DropTarget_signal_enter_info = {
      "enter",
      (GCallback) &DropTarget_signal_enter_callback,
      (GCallback) &DropTarget_signal_enter_notify_callback};

  auto
  DropTarget_signal_motion_callback (GtkDropTarget* self,
                                     const gdouble p0,
                                     const gdouble p1,
                                     void* data) -> GdkDragAction
  {
    using namespace Gtk;
    using SlotType = sigc::slot<Gdk::DragAction (double, double)>;

    const auto obj = dynamic_cast<DropTarget*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<GdkDragAction> (
              (*static_cast<SlotType*> (slot)) (p0, p1));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = GdkDragAction;
    return RType ();
  }

  auto
  DropTarget_signal_motion_notify_callback (GtkDropTarget* self,
                                            const gdouble p0,
                                            const gdouble p1,
                                            void* data) -> GdkDragAction
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (double, double)>;

    const auto obj = dynamic_cast<DropTarget*> (
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

    using RType = GdkDragAction;
    return RType ();
  }

  const Glib::SignalProxyInfo DropTarget_signal_motion_info = {
      "motion",
      (GCallback) &DropTarget_signal_motion_callback,
      (GCallback) &DropTarget_signal_motion_notify_callback};

  const Glib::SignalProxyInfo DropTarget_signal_leave_info = {
      "leave",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  auto
  DropTarget_signal_drop_callback (GtkDropTarget* self,
                                   const GValue* p0,
                                   const gdouble p1,
                                   const gdouble p2,
                                   void* data) -> gboolean
  {
    using namespace Gtk;
    using SlotType = sigc::slot<bool (const Glib::ValueBase&, double, double)>;

    const auto obj = dynamic_cast<DropTarget*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          return (*static_cast<SlotType*> (
              slot)) (*reinterpret_cast<const Glib::ValueBase*> (p0), p1, p2);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  auto
  DropTarget_signal_drop_notify_callback (GtkDropTarget* self,
                                          const GValue* p0,
                                          const gdouble p1,
                                          const gdouble p2,
                                          void* data) -> gboolean
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (const Glib::ValueBase&, double, double)>;

    const auto obj = dynamic_cast<DropTarget*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (
              slot)) (*reinterpret_cast<const Glib::ValueBase*> (p0), p1, p2);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  const Glib::SignalProxyInfo DropTarget_signal_drop_info = {
      "drop",
      (GCallback) &DropTarget_signal_drop_callback,
      (GCallback) &DropTarget_signal_drop_notify_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkDropTarget* object, const bool take_copy) -> RefPtr<Gtk::DropTarget>
  {
    return Glib::make_refptr_for_instance<Gtk::DropTarget> (
        dynamic_cast<Gtk::DropTarget*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  DropTarget_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &DropTarget_Class::class_init_function;

      register_derived_type (gtk_drop_target_get_type ());
    }

    return *this;
  }

  auto
  DropTarget_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  DropTarget_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new DropTarget ((GtkDropTarget*) object);
  }

  auto
  DropTarget::gobj_copy () -> GtkDropTarget*
  {
    reference ();
    return gobj ();
  }

  DropTarget::DropTarget (const Glib::ConstructParams& construct_params)
    : EventController (construct_params)
  {
  }

  DropTarget::DropTarget (GtkDropTarget* castitem)
    : EventController ((GtkEventController*) castitem)
  {
  }

  DropTarget::DropTarget (DropTarget&& src) noexcept
    : EventController (std::move (src))
  {
  }

  auto
  DropTarget::operator= (DropTarget&& src) noexcept -> DropTarget&
  {
    EventController::operator= (std::move (src));
    return *this;
  }

  DropTarget::~DropTarget () noexcept = default;

  DropTarget::CppClassType DropTarget::droptarget_class_;

  auto
  DropTarget::get_type () -> GType
  {
    return droptarget_class_.init ().get_type ();
  }

  auto
  DropTarget::get_base_type () -> GType
  {
    return gtk_drop_target_get_type ();
  }

  auto
  DropTarget::create (const GType type, Gdk::DragAction actions) -> Glib::RefPtr<DropTarget>
  {
    return Glib::wrap (
        gtk_drop_target_new (type, static_cast<GdkDragAction> (actions)));
  }

  auto
  DropTarget::get_formats () -> Glib::RefPtr<Gdk::ContentFormats>
  {
    auto retvalue = Glib::wrap (gtk_drop_target_get_formats (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DropTarget::get_formats () const -> Glib::RefPtr<const Gdk::ContentFormats>
  {
    return const_cast<DropTarget*> (this)->get_formats ();
  }

  auto
  DropTarget::set_actions (Gdk::DragAction actions) -> void
  {
    gtk_drop_target_set_actions (gobj (), static_cast<GdkDragAction> (actions));
  }

  auto
  DropTarget::get_actions () const -> Gdk::DragAction
  {
    return static_cast<Gdk::DragAction> (
        gtk_drop_target_get_actions (const_cast<GtkDropTarget*> (gobj ())));
  }

  auto
  DropTarget::set_preload (const bool preload) -> void
  {
    gtk_drop_target_set_preload (gobj (), preload);
  }

  auto
  DropTarget::get_preload () const -> bool
  {
    return gtk_drop_target_get_preload (const_cast<GtkDropTarget*> (gobj ()));
  }

#ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  DropTarget::get_drop () -> Glib::RefPtr<Gdk::Drop>
  {
    auto retvalue = Glib::wrap (gtk_drop_target_get_drop (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

#ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  DropTarget::get_drop () const -> Glib::RefPtr<const Gdk::Drop>
  {
    return const_cast<DropTarget*> (this)->get_drop ();
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

  auto
  DropTarget::get_current_drop () -> Glib::RefPtr<Gdk::Drop>
  {
    auto retvalue = Glib::wrap (gtk_drop_target_get_current_drop (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DropTarget::get_current_drop () const -> Glib::RefPtr<const Gdk::Drop>
  {
    return const_cast<DropTarget*> (this)->get_current_drop ();
  }

  auto
  DropTarget::reject () -> void
  {
    gtk_drop_target_reject (gobj ());
  }

  auto
  DropTarget::signal_accept () -> Glib::SignalProxy<bool (const Glib::RefPtr<Gdk::Drop>&)>
  {
    return {this, &DropTarget_signal_accept_info};
  }

  auto
  DropTarget::signal_enter () -> Glib::SignalProxy<Gdk::DragAction (double, double)>
  {
    return {this, &DropTarget_signal_enter_info};
  }

  auto
  DropTarget::signal_motion () -> Glib::SignalProxy<Gdk::DragAction (double, double)>
  {
    return {this, &DropTarget_signal_motion_info};
  }

  auto
  DropTarget::signal_leave () -> Glib::SignalProxy<void ()>
  {
    return {this, &DropTarget_signal_leave_info};
  }

  auto
  DropTarget::signal_drop () -> Glib::SignalProxy<bool (const Glib::ValueBase&, double, double)>
  {
    return {this, &DropTarget_signal_drop_info};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Gdk::DragAction>::value,
      "Type Gdk::DragAction cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  DropTarget::property_actions () -> Glib::PropertyProxy<Gdk::DragAction>
  {
    return {this, "actions"};
  }

  auto
  DropTarget::property_actions () const -> Glib::PropertyProxy_ReadOnly<Gdk::DragAction>
  {
    return {this, "actions"};
  }

#ifndef GTKMM_DISABLE_DEPRECATED

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gdk::Drop>>::value,
      "Type Glib::RefPtr<Gdk::Drop> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  DropTarget::property_drop () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Drop>>
  {
    return {this, "drop"};
  }
#endif

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gdk::Drop>>::value,
      "Type Glib::RefPtr<Gdk::Drop> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  DropTarget::property_current_drop () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Drop>>
  {
    return {this, "current-drop"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gdk::ContentFormats>>::value,
      "Type Glib::RefPtr<Gdk::ContentFormats> cannot be used in "
      "_WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  DropTarget::property_formats () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::ContentFormats>>
  {
    return {this, "formats"};
  }

  auto
  DropTarget::property_preload () -> Glib::PropertyProxy<bool>
  {
    return {this, "preload"};
  }

  auto
  DropTarget::property_preload () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "preload"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<GValue*>::value,
      "Type GValue* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  DropTarget::property_value () const -> Glib::PropertyProxy_ReadOnly<GValue*>
  {
    return {this, "value"};
  }

} // namespace Gtk
