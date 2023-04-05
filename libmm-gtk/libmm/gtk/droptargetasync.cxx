// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/droptargetasync.hxx>
#include <libmm/gtk/droptargetasync_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gio/slot_async.hxx>

namespace gtk
{
  auto
  DropTargetAsync::create (
      const glib::RefPtr<const gdk::ContentFormats>& formats,
      gdk::DragAction actions) -> glib::RefPtr<DropTargetAsync>
  {
    if (formats)
      formats->reference ();
    return glib::wrap (gtk_drop_target_async_new (
        const_cast<GdkContentFormats*> (glib::unwrap (formats)),
        static_cast<GdkDragAction> (actions)));
  }

  auto
  DropTargetAsync::create (gdk::DragAction actions) -> glib::RefPtr<DropTargetAsync>
  {
    return glib::wrap (
        gtk_drop_target_async_new (nullptr,
                                   static_cast<GdkDragAction> (actions)));
  }
} // namespace gtk

namespace
{

  static auto
  DropTargetAsync_signal_accept_callback (GtkDropTargetAsync* self,
                                          GdkDrop* p0,
                                          void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<bool (const glib::RefPtr<gdk::Drop>&)>;

    auto obj = dynamic_cast<DropTargetAsync*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> (
              (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true)));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static auto
  DropTargetAsync_signal_accept_notify_callback (GtkDropTargetAsync* self,
                                                 GdkDrop* p0,
                                                 void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const glib::RefPtr<gdk::Drop>&)>;

    auto obj = dynamic_cast<DropTargetAsync*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const glib::SignalProxyInfo DropTargetAsync_signal_accept_info = {
      "accept",
      (GCallback) &DropTargetAsync_signal_accept_callback,
      (GCallback) &DropTargetAsync_signal_accept_notify_callback};

  static auto
  DropTargetAsync_signal_drag_enter_callback (GtkDropTargetAsync* self,
                                              GdkDrop* p0,
                                              gdouble p1,
                                              gdouble p2,
                                              void* data) -> GdkDragAction
  {
    using namespace gtk;
    using SlotType = sigc::slot<
        gdk::DragAction (const glib::RefPtr<gdk::Drop>&, double, double)>;

    auto obj = dynamic_cast<DropTargetAsync*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<GdkDragAction> (
              (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true), p1, p2));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = GdkDragAction;
    return RType ();
  }

  static auto
  DropTargetAsync_signal_drag_enter_notify_callback (GtkDropTargetAsync* self,
                                                     GdkDrop* p0,
                                                     gdouble p1,
                                                     gdouble p2,
                                                     void* data) -> GdkDragAction
  {
    using namespace gtk;
    using SlotType =
        sigc::slot<void (const glib::RefPtr<gdk::Drop>&, double, double)>;

    auto obj = dynamic_cast<DropTargetAsync*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true), p1, p2);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = GdkDragAction;
    return RType ();
  }

  static const glib::SignalProxyInfo DropTargetAsync_signal_drag_enter_info = {
      "drag-enter",
      (GCallback) &DropTargetAsync_signal_drag_enter_callback,
      (GCallback) &DropTargetAsync_signal_drag_enter_notify_callback};

  static auto
  DropTargetAsync_signal_drag_motion_callback (GtkDropTargetAsync* self,
                                               GdkDrop* p0,
                                               gdouble p1,
                                               gdouble p2,
                                               void* data) -> GdkDragAction
  {
    using namespace gtk;
    using SlotType = sigc::slot<
        gdk::DragAction (const glib::RefPtr<gdk::Drop>&, double, double)>;

    auto obj = dynamic_cast<DropTargetAsync*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<GdkDragAction> (
              (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true), p1, p2));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = GdkDragAction;
    return RType ();
  }

  static auto
  DropTargetAsync_signal_drag_motion_notify_callback (GtkDropTargetAsync* self,
                                                      GdkDrop* p0,
                                                      gdouble p1,
                                                      gdouble p2,
                                                      void* data) -> GdkDragAction
  {
    using namespace gtk;
    using SlotType =
        sigc::slot<void (const glib::RefPtr<gdk::Drop>&, double, double)>;

    auto obj = dynamic_cast<DropTargetAsync*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true), p1, p2);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = GdkDragAction;
    return RType ();
  }

  static const glib::SignalProxyInfo DropTargetAsync_signal_drag_motion_info = {
      "drag-motion",
      (GCallback) &DropTargetAsync_signal_drag_motion_callback,
      (GCallback) &DropTargetAsync_signal_drag_motion_notify_callback};

  static auto
  DropTargetAsync_signal_drag_leave_callback (GtkDropTargetAsync* self,
                                              GdkDrop* p0,
                                              void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const glib::RefPtr<gdk::Drop>&)>;

    auto obj = dynamic_cast<DropTargetAsync*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo DropTargetAsync_signal_drag_leave_info = {
      "drag-leave",
      (GCallback) &DropTargetAsync_signal_drag_leave_callback,
      (GCallback) &DropTargetAsync_signal_drag_leave_callback};

  static auto
  DropTargetAsync_signal_drop_callback (GtkDropTargetAsync* self,
                                        GdkDrop* p0,
                                        gdouble p1,
                                        gdouble p2,
                                        void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType =
        sigc::slot<bool (const glib::RefPtr<gdk::Drop>&, double, double)>;

    auto obj = dynamic_cast<DropTargetAsync*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> (
              (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true), p1, p2));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static auto
  DropTargetAsync_signal_drop_notify_callback (GtkDropTargetAsync* self,
                                               GdkDrop* p0,
                                               gdouble p1,
                                               gdouble p2,
                                               void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType =
        sigc::slot<void (const glib::RefPtr<gdk::Drop>&, double, double)>;

    auto obj = dynamic_cast<DropTargetAsync*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true), p1, p2);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const glib::SignalProxyInfo DropTargetAsync_signal_drop_info = {
      "drop",
      (GCallback) &DropTargetAsync_signal_drop_callback,
      (GCallback) &DropTargetAsync_signal_drop_notify_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkDropTargetAsync* object, bool take_copy) -> glib::RefPtr<gtk::DropTargetAsync>
  {
    return glib::make_refptr_for_instance<gtk::DropTargetAsync> (
        dynamic_cast<gtk::DropTargetAsync*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  DropTargetAsync_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &DropTargetAsync_Class::class_init_function;

      register_derived_type (gtk_drop_target_async_get_type ());
    }

    return *this;
  }

  auto
  DropTargetAsync_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  DropTargetAsync_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new DropTargetAsync ((GtkDropTargetAsync*) object);
  }

  auto
  DropTargetAsync::gobj_copy () -> GtkDropTargetAsync*
  {
    reference ();
    return gobj ();
  }

  DropTargetAsync::DropTargetAsync (
      const glib::ConstructParams& construct_params)
    : EventController (construct_params)
  {
  }

  DropTargetAsync::DropTargetAsync (GtkDropTargetAsync* castitem)
    : EventController ((GtkEventController*) (castitem))
  {
  }

  DropTargetAsync::DropTargetAsync (DropTargetAsync&& src) noexcept
    : EventController (std::move (src))
  {
  }

  auto
  DropTargetAsync::operator= (DropTargetAsync&& src) noexcept -> DropTargetAsync&
  {
    EventController::operator= (std::move (src));
    return *this;
  }

  DropTargetAsync::~DropTargetAsync () noexcept {}

  DropTargetAsync::CppClassType DropTargetAsync::droptargetasync_class_;

  auto
  DropTargetAsync::get_type () -> GType
  {
    return droptargetasync_class_.init ().get_type ();
  }

  auto
  DropTargetAsync::get_base_type () -> GType
  {
    return gtk_drop_target_async_get_type ();
  }

  auto
  DropTargetAsync::set_formats (
      const glib::RefPtr<const gdk::ContentFormats>& formats) -> void
  {
    gtk_drop_target_async_set_formats (
        gobj (),
        const_cast<GdkContentFormats*> (glib::unwrap (formats)));
  }

  auto
  DropTargetAsync::get_formats () -> glib::RefPtr<gdk::ContentFormats>
  {
    auto retvalue = glib::wrap (gtk_drop_target_async_get_formats (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DropTargetAsync::get_formats () const -> glib::RefPtr<const gdk::ContentFormats>
  {
    return const_cast<DropTargetAsync*> (this)->get_formats ();
  }

  auto
  DropTargetAsync::set_actions (gdk::DragAction actions) -> void
  {
    gtk_drop_target_async_set_actions (gobj (),
                                       static_cast<GdkDragAction> (actions));
  }

  auto
  DropTargetAsync::get_actions () const -> gdk::DragAction
  {
    return static_cast<gdk::DragAction> (gtk_drop_target_async_get_actions (
        const_cast<GtkDropTargetAsync*> (gobj ())));
  }

  auto
  DropTargetAsync::reject_drop (const glib::RefPtr<gdk::Drop>& drop) -> void
  {
    gtk_drop_target_async_reject_drop (gobj (), glib::unwrap (drop));
  }

  auto
  DropTargetAsync::signal_accept () -> glib::SignalProxy<bool (const glib::RefPtr<gdk::Drop>&)>
  {
    return glib::SignalProxy<bool (const glib::RefPtr<gdk::Drop>&)> (
        this,
        &DropTargetAsync_signal_accept_info);
  }

  auto
  DropTargetAsync::signal_drag_enter () -> glib::SignalProxy<
      gdk::DragAction (const glib::RefPtr<gdk::Drop>&, double, double)>
  {
    return glib::SignalProxy<
        gdk::DragAction (const glib::RefPtr<gdk::Drop>&, double, double)> (
        this,
        &DropTargetAsync_signal_drag_enter_info);
  }

  auto
  DropTargetAsync::signal_drag_motion () -> glib::SignalProxy<
      gdk::DragAction (const glib::RefPtr<gdk::Drop>&, double, double)>
  {
    return glib::SignalProxy<
        gdk::DragAction (const glib::RefPtr<gdk::Drop>&, double, double)> (
        this,
        &DropTargetAsync_signal_drag_motion_info);
  }

  auto
  DropTargetAsync::signal_drag_leave () -> glib::SignalProxy<void (const glib::RefPtr<gdk::Drop>&)>
  {
    return glib::SignalProxy<void (const glib::RefPtr<gdk::Drop>&)> (
        this,
        &DropTargetAsync_signal_drag_leave_info);
  }

  auto
  DropTargetAsync::signal_drop () -> glib::SignalProxy<
      bool (const glib::RefPtr<gdk::Drop>&, double, double)>
  {
    return glib::SignalProxy<
        bool (const glib::RefPtr<gdk::Drop>&, double, double)> (
        this,
        &DropTargetAsync_signal_drop_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<gdk::DragAction>::value,
      "Type gdk::DragAction cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  DropTargetAsync::property_actions () -> glib::PropertyProxy<gdk::DragAction>
  {
    return glib::PropertyProxy<gdk::DragAction> (this, "actions");
  }

  auto
  DropTargetAsync::property_actions () const -> glib::PropertyProxy_ReadOnly<gdk::DragAction>
  {
    return glib::PropertyProxy_ReadOnly<gdk::DragAction> (this, "actions");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gdk::ContentFormats>>::value,
      "Type glib::RefPtr<gdk::ContentFormats> cannot be used in "
      "_WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  DropTargetAsync::property_formats () -> glib::PropertyProxy<glib::RefPtr<gdk::ContentFormats>>
  {
    return glib::PropertyProxy<glib::RefPtr<gdk::ContentFormats>> (this,
                                                                   "formats");
  }

  auto
  DropTargetAsync::property_formats () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::ContentFormats>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::ContentFormats>> (
        this,
        "formats");
  }

} // namespace gtk
