// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/droptarget.hxx>
#include <libmm/gtk/droptarget_p.hxx>

#include <gtk/gtk.h>
#include <libmm/glib/vectorutils.hxx>

namespace gtk
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
    return glib::ArrayHandler<GType>::array_to_vector (gtype_array,
                                                       n_gtypes,
                                                       glib::OWNERSHIP_NONE);
  }

  auto
  DropTarget::get_value () const -> glib::ValueBase
  {
    const GValue* gvalue =
        gtk_drop_target_get_value (const_cast<GtkDropTarget*> (gobj ()));

    glib::ValueBase retvalue;
    if (gvalue)
      retvalue.init (gvalue);
    return retvalue;
  }

} // namespace gtk

namespace
{

  static auto
  DropTarget_signal_accept_callback (GtkDropTarget* self,
                                     GdkDrop* p0,
                                     void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<bool (const glib::RefPtr<gdk::Drop>&)>;

    auto obj = dynamic_cast<DropTarget*> (
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
  DropTarget_signal_accept_notify_callback (GtkDropTarget* self,
                                            GdkDrop* p0,
                                            void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const glib::RefPtr<gdk::Drop>&)>;

    auto obj = dynamic_cast<DropTarget*> (
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

  static const glib::SignalProxyInfo DropTarget_signal_accept_info = {
      "accept",
      (GCallback) &DropTarget_signal_accept_callback,
      (GCallback) &DropTarget_signal_accept_notify_callback};

  static auto
  DropTarget_signal_enter_callback (GtkDropTarget* self,
                                    gdouble p0,
                                    gdouble p1,
                                    void* data) -> GdkDragAction
  {
    using namespace gtk;
    using SlotType = sigc::slot<gdk::DragAction (double, double)>;

    auto obj = dynamic_cast<DropTarget*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<GdkDragAction> (
              (*static_cast<SlotType*> (slot)) (p0, p1));
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
  DropTarget_signal_enter_notify_callback (GtkDropTarget* self,
                                           gdouble p0,
                                           gdouble p1,
                                           void* data) -> GdkDragAction
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (double, double)>;

    auto obj = dynamic_cast<DropTarget*> (
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

    using RType = GdkDragAction;
    return RType ();
  }

  static const glib::SignalProxyInfo DropTarget_signal_enter_info = {
      "enter",
      (GCallback) &DropTarget_signal_enter_callback,
      (GCallback) &DropTarget_signal_enter_notify_callback};

  static auto
  DropTarget_signal_motion_callback (GtkDropTarget* self,
                                     gdouble p0,
                                     gdouble p1,
                                     void* data) -> GdkDragAction
  {
    using namespace gtk;
    using SlotType = sigc::slot<gdk::DragAction (double, double)>;

    auto obj = dynamic_cast<DropTarget*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<GdkDragAction> (
              (*static_cast<SlotType*> (slot)) (p0, p1));
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
  DropTarget_signal_motion_notify_callback (GtkDropTarget* self,
                                            gdouble p0,
                                            gdouble p1,
                                            void* data) -> GdkDragAction
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (double, double)>;

    auto obj = dynamic_cast<DropTarget*> (
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

    using RType = GdkDragAction;
    return RType ();
  }

  static const glib::SignalProxyInfo DropTarget_signal_motion_info = {
      "motion",
      (GCallback) &DropTarget_signal_motion_callback,
      (GCallback) &DropTarget_signal_motion_notify_callback};

  static const glib::SignalProxyInfo DropTarget_signal_leave_info = {
      "leave",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static auto
  DropTarget_signal_drop_callback (GtkDropTarget* self,
                                   const GValue* p0,
                                   gdouble p1,
                                   gdouble p2,
                                   void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<bool (const glib::ValueBase&, double, double)>;

    auto obj = dynamic_cast<DropTarget*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> ((*static_cast<SlotType*> (
              slot)) (*reinterpret_cast<const glib::ValueBase*> (p0), p1, p2));
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
  DropTarget_signal_drop_notify_callback (GtkDropTarget* self,
                                          const GValue* p0,
                                          gdouble p1,
                                          gdouble p2,
                                          void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const glib::ValueBase&, double, double)>;

    auto obj = dynamic_cast<DropTarget*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (
              slot)) (*reinterpret_cast<const glib::ValueBase*> (p0), p1, p2);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const glib::SignalProxyInfo DropTarget_signal_drop_info = {
      "drop",
      (GCallback) &DropTarget_signal_drop_callback,
      (GCallback) &DropTarget_signal_drop_notify_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkDropTarget* object, bool take_copy) -> glib::RefPtr<gtk::DropTarget>
  {
    return glib::make_refptr_for_instance<gtk::DropTarget> (
        dynamic_cast<gtk::DropTarget*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  DropTarget_Class::init () -> const glib::Class&
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
  DropTarget_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new DropTarget ((GtkDropTarget*) object);
  }

  auto
  DropTarget::gobj_copy () -> GtkDropTarget*
  {
    reference ();
    return gobj ();
  }

  DropTarget::DropTarget (const glib::ConstructParams& construct_params)
    : EventController (construct_params)
  {
  }

  DropTarget::DropTarget (GtkDropTarget* castitem)
    : EventController ((GtkEventController*) (castitem))
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

  DropTarget::~DropTarget () noexcept {}

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
  DropTarget::create (GType type, gdk::DragAction actions) -> glib::RefPtr<DropTarget>
  {
    return glib::wrap (
        gtk_drop_target_new (type, static_cast<GdkDragAction> (actions)));
  }

  auto
  DropTarget::get_formats () -> glib::RefPtr<gdk::ContentFormats>
  {
    auto retvalue = glib::wrap (gtk_drop_target_get_formats (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DropTarget::get_formats () const -> glib::RefPtr<const gdk::ContentFormats>
  {
    return const_cast<DropTarget*> (this)->get_formats ();
  }

  auto
  DropTarget::set_actions (gdk::DragAction actions) -> void
  {
    gtk_drop_target_set_actions (gobj (), static_cast<GdkDragAction> (actions));
  }

  auto
  DropTarget::get_actions () const -> gdk::DragAction
  {
    return static_cast<gdk::DragAction> (
        gtk_drop_target_get_actions (const_cast<GtkDropTarget*> (gobj ())));
  }

  auto
  DropTarget::set_preload (bool preload) -> void
  {
    gtk_drop_target_set_preload (gobj (), static_cast<int> (preload));
  }

  auto
  DropTarget::get_preload () const -> bool
  {
    return gtk_drop_target_get_preload (const_cast<GtkDropTarget*> (gobj ()));
  }

#ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  DropTarget::get_drop () -> glib::RefPtr<gdk::Drop>
  {
    auto retvalue = glib::wrap (gtk_drop_target_get_drop (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

#ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  DropTarget::get_drop () const -> glib::RefPtr<const gdk::Drop>
  {
    return const_cast<DropTarget*> (this)->get_drop ();
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

  auto
  DropTarget::get_current_drop () -> glib::RefPtr<gdk::Drop>
  {
    auto retvalue = glib::wrap (gtk_drop_target_get_current_drop (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DropTarget::get_current_drop () const -> glib::RefPtr<const gdk::Drop>
  {
    return const_cast<DropTarget*> (this)->get_current_drop ();
  }

  auto
  DropTarget::reject () -> void
  {
    gtk_drop_target_reject (gobj ());
  }

  auto
  DropTarget::signal_accept () -> glib::SignalProxy<bool (const glib::RefPtr<gdk::Drop>&)>
  {
    return glib::SignalProxy<bool (const glib::RefPtr<gdk::Drop>&)> (
        this,
        &DropTarget_signal_accept_info);
  }

  auto
  DropTarget::signal_enter () -> glib::SignalProxy<gdk::DragAction (double, double)>
  {
    return glib::SignalProxy<gdk::DragAction (double, double)> (
        this,
        &DropTarget_signal_enter_info);
  }

  auto
  DropTarget::signal_motion () -> glib::SignalProxy<gdk::DragAction (double, double)>
  {
    return glib::SignalProxy<gdk::DragAction (double, double)> (
        this,
        &DropTarget_signal_motion_info);
  }

  auto
  DropTarget::signal_leave () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &DropTarget_signal_leave_info);
  }

  auto
  DropTarget::signal_drop () -> glib::SignalProxy<bool (const glib::ValueBase&, double, double)>
  {
    return glib::SignalProxy<bool (const glib::ValueBase&, double, double)> (
        this,
        &DropTarget_signal_drop_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<gdk::DragAction>::value,
      "Type gdk::DragAction cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  DropTarget::property_actions () -> glib::PropertyProxy<gdk::DragAction>
  {
    return glib::PropertyProxy<gdk::DragAction> (this, "actions");
  }

  auto
  DropTarget::property_actions () const -> glib::PropertyProxy_ReadOnly<gdk::DragAction>
  {
    return glib::PropertyProxy_ReadOnly<gdk::DragAction> (this, "actions");
  }

#ifndef GTKMM_DISABLE_DEPRECATED

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gdk::Drop>>::value,
      "Type glib::RefPtr<gdk::Drop> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  DropTarget::property_drop () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Drop>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Drop>> (this, "drop");
  }
#endif

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gdk::Drop>>::value,
      "Type glib::RefPtr<gdk::Drop> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  DropTarget::property_current_drop () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Drop>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Drop>> (
        this,
        "current-drop");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gdk::ContentFormats>>::value,
      "Type glib::RefPtr<gdk::ContentFormats> cannot be used in "
      "_WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  DropTarget::property_formats () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::ContentFormats>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::ContentFormats>> (
        this,
        "formats");
  }

  auto
  DropTarget::property_preload () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "preload");
  }

  auto
  DropTarget::property_preload () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "preload");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<GValue*>::value,
      "Type GValue* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  DropTarget::property_value () const -> glib::PropertyProxy_ReadOnly<GValue*>
  {
    return glib::PropertyProxy_ReadOnly<GValue*> (this, "value");
  }

} // namespace gtk
