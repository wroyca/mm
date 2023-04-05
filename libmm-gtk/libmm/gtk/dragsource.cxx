// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/dragsource.hxx>
#include <libmm/gtk/dragsource_p.hxx>

#include <gtk/gtk.h>

namespace
{

  static auto
  DragSource_signal_prepare_callback (GtkDragSource* self,
                                      gdouble p0,
                                      gdouble p1,
                                      void* data) -> GdkContentProvider*
  {
    using namespace gtk;
    using SlotType =
        sigc::slot<glib::RefPtr<gdk::ContentProvider> (double, double)>;

    auto obj = dynamic_cast<DragSource*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return glib::unwrap_copy ((*static_cast<SlotType*> (slot)) (p0, p1));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = GdkContentProvider*;
    return RType ();
  }

  static auto
  DragSource_signal_prepare_notify_callback (GtkDragSource* self,
                                             gdouble p0,
                                             gdouble p1,
                                             void* data) -> GdkContentProvider*
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (double, double)>;

    auto obj = dynamic_cast<DragSource*> (
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

    using RType = GdkContentProvider*;
    return RType ();
  }

  static const glib::SignalProxyInfo DragSource_signal_prepare_info = {
      "prepare",
      (GCallback) &DragSource_signal_prepare_callback,
      (GCallback) &DragSource_signal_prepare_notify_callback};

  static auto
  DragSource_signal_drag_begin_callback (GtkDragSource* self,
                                         GdkDrag* p0,
                                         void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const glib::RefPtr<gdk::Drag>&)>;

    auto obj = dynamic_cast<DragSource*> (
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

  static const glib::SignalProxyInfo DragSource_signal_drag_begin_info = {
      "drag-begin",
      (GCallback) &DragSource_signal_drag_begin_callback,
      (GCallback) &DragSource_signal_drag_begin_callback};

  static auto
  DragSource_signal_drag_end_callback (GtkDragSource* self,
                                       GdkDrag* p0,
                                       gboolean p1,
                                       void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const glib::RefPtr<gdk::Drag>&, bool)>;

    auto obj = dynamic_cast<DragSource*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true), p1);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo DragSource_signal_drag_end_info = {
      "drag-end",
      (GCallback) &DragSource_signal_drag_end_callback,
      (GCallback) &DragSource_signal_drag_end_callback};

  static auto
  DragSource_signal_drag_cancel_callback (GtkDragSource* self,
                                          GdkDrag* p0,
                                          GdkDragCancelReason p1,
                                          void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<bool (const glib::RefPtr<gdk::Drag>&,
                                      gdk::DragCancelReason)>;

    auto obj = dynamic_cast<DragSource*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> ((*static_cast<SlotType*> (slot)) (
              glib::wrap (p0, true),
              static_cast<gdk::DragCancelReason> (p1)));
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
  DragSource_signal_drag_cancel_notify_callback (GtkDragSource* self,
                                                 GdkDrag* p0,
                                                 GdkDragCancelReason p1,
                                                 void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const glib::RefPtr<gdk::Drag>&,
                                      gdk::DragCancelReason)>;

    auto obj = dynamic_cast<DragSource*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::wrap (p0, true),
              static_cast<gdk::DragCancelReason> (p1));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const glib::SignalProxyInfo DragSource_signal_drag_cancel_info = {
      "drag-cancel",
      (GCallback) &DragSource_signal_drag_cancel_callback,
      (GCallback) &DragSource_signal_drag_cancel_notify_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkDragSource* object, bool take_copy) -> glib::RefPtr<gtk::DragSource>
  {
    return glib::make_refptr_for_instance<gtk::DragSource> (
        dynamic_cast<gtk::DragSource*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  DragSource_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &DragSource_Class::class_init_function;

      register_derived_type (gtk_drag_source_get_type ());
    }

    return *this;
  }

  auto
  DragSource_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  DragSource_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new DragSource ((GtkDragSource*) object);
  }

  auto
  DragSource::gobj_copy () -> GtkDragSource*
  {
    reference ();
    return gobj ();
  }

  DragSource::DragSource (const glib::ConstructParams& construct_params)
    : GestureSingle (construct_params)
  {
  }

  DragSource::DragSource (GtkDragSource* castitem)
    : GestureSingle ((GtkGestureSingle*) (castitem))
  {
  }

  DragSource::DragSource (DragSource&& src) noexcept
    : GestureSingle (std::move (src))
  {
  }

  auto
  DragSource::operator= (DragSource&& src) noexcept -> DragSource&
  {
    GestureSingle::operator= (std::move (src));
    return *this;
  }

  DragSource::~DragSource () noexcept {}

  DragSource::CppClassType DragSource::dragsource_class_;

  auto
  DragSource::get_type () -> GType
  {
    return dragsource_class_.init ().get_type ();
  }

  auto
  DragSource::get_base_type () -> GType
  {
    return gtk_drag_source_get_type ();
  }

  DragSource::DragSource ()
    : glib::ObjectBase (nullptr),
      GestureSingle (glib::ConstructParams (dragsource_class_.init ()))
  {
  }

  auto
  DragSource::create () -> glib::RefPtr<DragSource>
  {
    return glib::make_refptr_for_instance<DragSource> (new DragSource ());
  }

  auto
  DragSource::set_content (const glib::RefPtr<gdk::ContentProvider>& content) -> void
  {
    gtk_drag_source_set_content (gobj (), glib::unwrap (content));
  }

  auto
  DragSource::get_content () -> glib::RefPtr<gdk::ContentProvider>
  {
    auto retvalue = glib::wrap (gtk_drag_source_get_content (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DragSource::get_content () const -> glib::RefPtr<const gdk::ContentProvider>
  {
    return const_cast<DragSource*> (this)->get_content ();
  }

  auto
  DragSource::set_actions (gdk::DragAction actions) -> void
  {
    gtk_drag_source_set_actions (gobj (), static_cast<GdkDragAction> (actions));
  }

  auto
  DragSource::get_actions () const -> gdk::DragAction
  {
    return static_cast<gdk::DragAction> (
        gtk_drag_source_get_actions (const_cast<GtkDragSource*> (gobj ())));
  }

  auto
  DragSource::set_icon (const glib::RefPtr<const gdk::Paintable>& paintable,
                        int hot_x,
                        int hot_y) -> void
  {
    gtk_drag_source_set_icon (
        gobj (),
        const_cast<GdkPaintable*> (glib::unwrap (paintable)),
        hot_x,
        hot_y);
  }

  auto
  DragSource::drag_cancel () -> void
  {
    gtk_drag_source_drag_cancel (gobj ());
  }

  auto
  DragSource::get_drag () -> glib::RefPtr<gdk::Drag>
  {
    auto retvalue = glib::wrap (gtk_drag_source_get_drag (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DragSource::get_drag () const -> glib::RefPtr<const gdk::Drag>
  {
    return const_cast<DragSource*> (this)->get_drag ();
  }

  auto
  DragSource::signal_prepare () -> glib::SignalProxy<glib::RefPtr<gdk::ContentProvider> (double, double)>
  {
    return glib::SignalProxy<glib::RefPtr<gdk::ContentProvider> (double,
                                                                 double)> (
        this,
        &DragSource_signal_prepare_info);
  }

  auto
  DragSource::signal_drag_begin () -> glib::SignalProxy<void (const glib::RefPtr<gdk::Drag>&)>
  {
    return glib::SignalProxy<void (const glib::RefPtr<gdk::Drag>&)> (
        this,
        &DragSource_signal_drag_begin_info);
  }

  auto
  DragSource::signal_drag_end () -> glib::SignalProxy<void (const glib::RefPtr<gdk::Drag>&, bool)>
  {
    return glib::SignalProxy<void (const glib::RefPtr<gdk::Drag>&, bool)> (
        this,
        &DragSource_signal_drag_end_info);
  }

  auto
  DragSource::signal_drag_cancel () -> glib::SignalProxy<bool (const glib::RefPtr<gdk::Drag>&,
                                 gdk::DragCancelReason)>
  {
    return glib::SignalProxy<bool (const glib::RefPtr<gdk::Drag>&,
                                   gdk::DragCancelReason)> (
        this,
        &DragSource_signal_drag_cancel_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gdk::ContentProvider>>::value,
      "Type glib::RefPtr<gdk::ContentProvider> cannot be used in "
      "_WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  DragSource::property_content () -> glib::PropertyProxy<glib::RefPtr<gdk::ContentProvider>>
  {
    return glib::PropertyProxy<glib::RefPtr<gdk::ContentProvider>> (this,
                                                                    "content");
  }

  auto
  DragSource::property_content () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::ContentProvider>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::ContentProvider>> (
        this,
        "content");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<gdk::DragAction>::value,
      "Type gdk::DragAction cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  DragSource::property_actions () -> glib::PropertyProxy<gdk::DragAction>
  {
    return glib::PropertyProxy<gdk::DragAction> (this, "actions");
  }

  auto
  DragSource::property_actions () const -> glib::PropertyProxy_ReadOnly<gdk::DragAction>
  {
    return glib::PropertyProxy_ReadOnly<gdk::DragAction> (this, "actions");
  }

} // namespace gtk
