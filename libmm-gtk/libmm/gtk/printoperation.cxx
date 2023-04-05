// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/printoperation.hxx>
#include <libmm/gtk/printoperation_p.hxx>

#include <gtk/gtk.h>

using Result = gtk::PrintOperation::Result;

static auto
SignalProxy_PrintSetupDone_gtk_callback (GtkPageSetup* page_setup,
                                         gpointer data) -> void
{
  const auto the_slot = static_cast<gtk::SlotPrintSetupDone*> (data);

  try
  {
    auto ps = glib::wrap (page_setup);
    (*the_slot) (ps);
  }
  catch (...)
  {
    glib::exception_handlers_invoke ();
  }

  delete the_slot;
}

namespace gtk
{

  auto
  PrintOperation::run (Action action) -> PrintOperation::Result
  {
    GError* gerror = nullptr;
    Result res = (Result) gtk_print_operation_run (
        this->gobj (),
        (GtkPrintOperationAction) action,
        nullptr,
        &gerror);

    if (res == PrintOperation::Result::ERROR)
    {
      gtk_print_operation_get_error (this->gobj (), &gerror);
      ::glib::Error::throw_exception (gerror);
    }

    return res;
  }

  auto
  run_page_setup_dialog (
      Window& parent,
      const glib::RefPtr<const PageSetup>& page_setup,
      const glib::RefPtr<const PrintSettings>& print_settings) -> glib::RefPtr<PageSetup>
  {
    return glib::wrap (gtk_print_run_page_setup_dialog (
        parent.gobj (),
        const_cast<GtkPageSetup*> (glib::unwrap<PageSetup> (page_setup)),
        const_cast<GtkPrintSettings*> (
            glib::unwrap<PrintSettings> (print_settings))));
  }

  auto
  run_page_setup_dialog (
      Window& parent,
      const glib::RefPtr<const PrintSettings>& print_settings) -> glib::RefPtr<PageSetup>
  {
    return glib::wrap (gtk_print_run_page_setup_dialog (
        parent.gobj (),
        nullptr,
        const_cast<GtkPrintSettings*> (
            glib::unwrap<PrintSettings> (print_settings))));
  }

  auto
  run_page_setup_dialog_async (
      Window& parent,
      const glib::RefPtr<const PageSetup>& page_setup,
      const glib::RefPtr<const PrintSettings>& print_settings,
      const SlotPrintSetupDone& slot) -> void
  {
    auto slot_copy = new SlotPrintSetupDone (slot);

    gtk_print_run_page_setup_dialog_async (
        parent.gobj (),
        const_cast<GtkPageSetup*> (glib::unwrap<PageSetup> (page_setup)),
        const_cast<GtkPrintSettings*> (
            glib::unwrap<PrintSettings> (print_settings)),
        &SignalProxy_PrintSetupDone_gtk_callback,
        slot_copy);
  }

  auto
  run_page_setup_dialog_async (
      Window& parent,
      const glib::RefPtr<const PrintSettings>& print_settings,
      const SlotPrintSetupDone& slot) -> void
  {
    auto slot_copy = new SlotPrintSetupDone (slot);

    gtk_print_run_page_setup_dialog_async (
        parent.gobj (),
        nullptr,
        const_cast<GtkPrintSettings*> (
            glib::unwrap<PrintSettings> (print_settings)),
        &SignalProxy_PrintSetupDone_gtk_callback,
        slot_copy);
  }

} // namespace gtk

namespace
{

  static auto
  PrintOperation_signal_done_callback (GtkPrintOperation* self,
                                       GtkPrintOperationResult p0,
                                       void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (Result)>;

    auto obj = dynamic_cast<PrintOperation*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (static_cast<Result> (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo PrintOperation_signal_done_info = {
      "done",
      (GCallback) &PrintOperation_signal_done_callback,
      (GCallback) &PrintOperation_signal_done_callback};

  static auto
  PrintOperation_signal_begin_print_callback (GtkPrintOperation* self,
                                              GtkPrintContext* p0,
                                              void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const glib::RefPtr<PrintContext>&)>;

    auto obj = dynamic_cast<PrintOperation*> (
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

  static const glib::SignalProxyInfo PrintOperation_signal_begin_print_info = {
      "begin_print",
      (GCallback) &PrintOperation_signal_begin_print_callback,
      (GCallback) &PrintOperation_signal_begin_print_callback};

  static auto
  PrintOperation_signal_paginate_callback (GtkPrintOperation* self,
                                           GtkPrintContext* p0,
                                           void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<bool (const glib::RefPtr<PrintContext>&)>;

    auto obj = dynamic_cast<PrintOperation*> (
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
  PrintOperation_signal_paginate_notify_callback (GtkPrintOperation* self,
                                                  GtkPrintContext* p0,
                                                  void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const glib::RefPtr<PrintContext>&)>;

    auto obj = dynamic_cast<PrintOperation*> (
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

  static const glib::SignalProxyInfo PrintOperation_signal_paginate_info = {
      "paginate",
      (GCallback) &PrintOperation_signal_paginate_callback,
      (GCallback) &PrintOperation_signal_paginate_notify_callback};

  static auto
  PrintOperation_signal_request_page_setup_callback (GtkPrintOperation* self,
                                                     GtkPrintContext* p0,
                                                     gint p1,
                                                     GtkPageSetup* p2,
                                                     void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const glib::RefPtr<PrintContext>&,
                                      int,
                                      const glib::RefPtr<PageSetup>&)>;

    auto obj = dynamic_cast<PrintOperation*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (
              slot)) (glib::wrap (p0, true), p1, glib::wrap (p2, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo
      PrintOperation_signal_request_page_setup_info = {
          "request_page_setup",
          (GCallback) &PrintOperation_signal_request_page_setup_callback,
          (GCallback) &PrintOperation_signal_request_page_setup_callback};

  static auto
  PrintOperation_signal_draw_page_callback (GtkPrintOperation* self,
                                            GtkPrintContext* p0,
                                            gint p1,
                                            void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const glib::RefPtr<PrintContext>&, int)>;

    auto obj = dynamic_cast<PrintOperation*> (
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

  static const glib::SignalProxyInfo PrintOperation_signal_draw_page_info = {
      "draw_page",
      (GCallback) &PrintOperation_signal_draw_page_callback,
      (GCallback) &PrintOperation_signal_draw_page_callback};

  static auto
  PrintOperation_signal_end_print_callback (GtkPrintOperation* self,
                                            GtkPrintContext* p0,
                                            void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const glib::RefPtr<PrintContext>&)>;

    auto obj = dynamic_cast<PrintOperation*> (
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

  static const glib::SignalProxyInfo PrintOperation_signal_end_print_info = {
      "end_print",
      (GCallback) &PrintOperation_signal_end_print_callback,
      (GCallback) &PrintOperation_signal_end_print_callback};

  static const glib::SignalProxyInfo PrintOperation_signal_status_changed_info =
      {"status_changed",
       (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
       (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static auto
  PrintOperation_signal_create_custom_widget_callback (GtkPrintOperation* self,
                                                       void* data) -> GtkWidget*
  {
    using namespace gtk;
    using SlotType = sigc::slot<Widget*()>;

    auto obj = dynamic_cast<PrintOperation*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return (GtkWidget*) glib::unwrap (
              (*static_cast<SlotType*> (slot)) ());
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = GtkWidget*;
    return RType ();
  }

  static auto
  PrintOperation_signal_create_custom_widget_notify_callback (
      GtkPrintOperation* self,
      void* data) -> GtkWidget*
  {
    using namespace gtk;
    using SlotType = sigc::slot<void ()>;

    auto obj = dynamic_cast<PrintOperation*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) ();
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = GtkWidget*;
    return RType ();
  }

  static const glib::SignalProxyInfo
      PrintOperation_signal_create_custom_widget_info = {
          "create_custom_widget",
          (GCallback) &PrintOperation_signal_create_custom_widget_callback,
          (GCallback) &PrintOperation_signal_create_custom_widget_notify_callback};

  static auto
  PrintOperation_signal_custom_widget_apply_callback (GtkPrintOperation* self,
                                                      GtkWidget* p0,
                                                      void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (Widget*)>;

    auto obj = dynamic_cast<PrintOperation*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo
      PrintOperation_signal_custom_widget_apply_info = {
          "custom_widget_apply",
          (GCallback) &PrintOperation_signal_custom_widget_apply_callback,
          (GCallback) &PrintOperation_signal_custom_widget_apply_callback};

  static auto
  PrintOperation_signal_preview_callback (GtkPrintOperation* self,
                                          GtkPrintOperationPreview* p0,
                                          GtkPrintContext* p1,
                                          GtkWindow* p2,
                                          void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType =
        sigc::slot<bool (const glib::RefPtr<PrintOperationPreview>&,
                         const glib::RefPtr<PrintContext>&,
                         Window*)>;

    auto obj = dynamic_cast<PrintOperation*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> (
              (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true),
                                                glib::wrap (p1, true),
                                                glib::wrap (p2)));
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
  PrintOperation_signal_preview_notify_callback (GtkPrintOperation* self,
                                                 GtkPrintOperationPreview* p0,
                                                 GtkPrintContext* p1,
                                                 GtkWindow* p2,
                                                 void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType =
        sigc::slot<void (const glib::RefPtr<PrintOperationPreview>&,
                         const glib::RefPtr<PrintContext>&,
                         Window*)>;

    auto obj = dynamic_cast<PrintOperation*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true),
                                            glib::wrap (p1, true),
                                            glib::wrap (p2));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const glib::SignalProxyInfo PrintOperation_signal_preview_info = {
      "preview",
      (GCallback) &PrintOperation_signal_preview_callback,
      (GCallback) &PrintOperation_signal_preview_notify_callback};

  static auto
  PrintOperation_signal_update_custom_widget_callback (GtkPrintOperation* self,
                                                       GtkWidget* p0,
                                                       GtkPageSetup* p1,
                                                       GtkPrintSettings* p2,
                                                       void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (Widget*,
                                      const glib::RefPtr<PageSetup>&,
                                      const glib::RefPtr<PrintSettings>&)>;

    auto obj = dynamic_cast<PrintOperation*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0),
                                            glib::wrap (p1, true),
                                            glib::wrap (p2, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo
      PrintOperation_signal_update_custom_widget_info = {
          "update_custom_widget",
          (GCallback) &PrintOperation_signal_update_custom_widget_callback,
          (GCallback) &PrintOperation_signal_update_custom_widget_callback};

} // namespace

auto
glib::Value<gtk::PrintStatus>::value_type () -> GType
{
  return gtk_print_status_get_type ();
}

gtk::PrintError::PrintError (gtk::PrintError::Code error_code,
                             const glib::ustring& error_message)
  : glib::Error (GTK_PRINT_ERROR, error_code, error_message)
{
}

gtk::PrintError::PrintError (GError* gobject)
  : glib::Error (gobject)
{
}

auto
gtk::PrintError::code () const -> gtk::PrintError::Code
{
  return static_cast<Code> (glib::Error::code ());
}

auto
gtk::PrintError::throw_func (GError* gobject) -> void
{
  throw gtk::PrintError (gobject);
}

auto
glib::Value<gtk::PrintError::Code>::value_type () -> GType
{
  return gtk_print_error_get_type ();
}

auto
glib::Value<gtk::PrintOperation::Result>::value_type () -> GType
{
  return gtk_print_operation_result_get_type ();
}

auto
glib::Value<gtk::PrintOperation::Action>::value_type () -> GType
{
  return gtk_print_operation_action_get_type ();
}

namespace glib
{

  auto
  wrap (GtkPrintOperation* object, bool take_copy) -> glib::RefPtr<gtk::PrintOperation>
  {
    return glib::make_refptr_for_instance<gtk::PrintOperation> (
        dynamic_cast<gtk::PrintOperation*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  PrintOperation_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &PrintOperation_Class::class_init_function;

      register_derived_type (gtk_print_operation_get_type ());

      PrintOperationPreview::add_interface (get_type ());
    }

    return *this;
  }

  auto
  PrintOperation_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->done = &done_callback;
    klass->begin_print = &begin_print_callback;
    klass->paginate = &paginate_callback;
    klass->request_page_setup = &request_page_setup_callback;
    klass->draw_page = &draw_page_callback;
    klass->end_print = &end_print_callback;
    klass->status_changed = &status_changed_callback;
    klass->create_custom_widget = &create_custom_widget_callback;
    klass->custom_widget_apply = &custom_widget_apply_callback;
    klass->preview = &preview_callback;
    klass->update_custom_widget = &update_custom_widget_callback;
  }

  auto
  PrintOperation_Class::done_callback (GtkPrintOperation* self,
                                       GtkPrintOperationResult p0) -> void
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
          obj->on_done (static_cast<Result> (p0));
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

    if (base && base->done)
      (*base->done) (self, p0);
  }

  auto
  PrintOperation_Class::begin_print_callback (GtkPrintOperation* self,
                                              GtkPrintContext* p0) -> void
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
          obj->on_begin_print (glib::wrap (p0, true));
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

    if (base && base->begin_print)
      (*base->begin_print) (self, p0);
  }

  auto
  PrintOperation_Class::paginate_callback (GtkPrintOperation* self,
                                           GtkPrintContext* p0) -> gboolean
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
          return static_cast<int> (obj->on_paginate (glib::wrap (p0, true)));
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->paginate)
      return (*base->paginate) (self, p0);

    using RType = gboolean;
    return RType ();
  }

  auto
  PrintOperation_Class::request_page_setup_callback (GtkPrintOperation* self,
                                                     GtkPrintContext* p0,
                                                     gint p1,
                                                     GtkPageSetup* p2) -> void
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
          obj->on_request_page_setup (glib::wrap (p0, true),
                                      p1,
                                      glib::wrap (p2, true));
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

    if (base && base->request_page_setup)
      (*base->request_page_setup) (self, p0, p1, p2);
  }

  auto
  PrintOperation_Class::draw_page_callback (GtkPrintOperation* self,
                                            GtkPrintContext* p0,
                                            gint p1) -> void
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
          obj->on_draw_page (glib::wrap (p0, true), p1);
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

    if (base && base->draw_page)
      (*base->draw_page) (self, p0, p1);
  }

  auto
  PrintOperation_Class::end_print_callback (GtkPrintOperation* self,
                                            GtkPrintContext* p0) -> void
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
          obj->on_end_print (glib::wrap (p0, true));
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

    if (base && base->end_print)
      (*base->end_print) (self, p0);
  }

  auto
  PrintOperation_Class::status_changed_callback (GtkPrintOperation* self) -> void
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
          obj->on_status_changed ();
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

    if (base && base->status_changed)
      (*base->status_changed) (self);
  }

  auto
  PrintOperation_Class::create_custom_widget_callback (GtkPrintOperation* self) -> GtkWidget*
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
          return (GtkWidget*) glib::unwrap (obj->on_create_custom_widget ());
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->create_custom_widget)
      return (*base->create_custom_widget) (self);

    using RType = GtkWidget*;
    return RType ();
  }

  auto
  PrintOperation_Class::custom_widget_apply_callback (GtkPrintOperation* self,
                                                      GtkWidget* p0) -> void
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
          obj->on_custom_widget_apply (glib::wrap (p0));
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

    if (base && base->custom_widget_apply)
      (*base->custom_widget_apply) (self, p0);
  }

  auto
  PrintOperation_Class::preview_callback (GtkPrintOperation* self,
                                          GtkPrintOperationPreview* p0,
                                          GtkPrintContext* p1,
                                          GtkWindow* p2) -> gboolean
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
          return static_cast<int> (obj->on_preview (glib::wrap (p0, true),
                                                    glib::wrap (p1, true),
                                                    glib::wrap (p2)));
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->preview)
      return (*base->preview) (self, p0, p1, p2);

    using RType = gboolean;
    return RType ();
  }

  auto
  PrintOperation_Class::update_custom_widget_callback (GtkPrintOperation* self,
                                                       GtkWidget* p0,
                                                       GtkPageSetup* p1,
                                                       GtkPrintSettings* p2) -> void
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
          obj->on_update_custom_widget (glib::wrap (p0),
                                        glib::wrap (p1, true),
                                        glib::wrap (p2, true));
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

    if (base && base->update_custom_widget)
      (*base->update_custom_widget) (self, p0, p1, p2);
  }

  auto
  PrintOperation_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new PrintOperation ((GtkPrintOperation*) object);
  }

  auto
  PrintOperation::gobj_copy () -> GtkPrintOperation*
  {
    reference ();
    return gobj ();
  }

  PrintOperation::PrintOperation (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  PrintOperation::PrintOperation (GtkPrintOperation* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  PrintOperation::PrintOperation (PrintOperation&& src) noexcept
    : glib::Object (std::move (src)),
      PrintOperationPreview (std::move (src))
  {
  }

  auto
  PrintOperation::operator= (PrintOperation&& src) noexcept -> PrintOperation&
  {
    glib::Object::operator= (std::move (src));
    PrintOperationPreview::operator= (std::move (src));
    return *this;
  }

  PrintOperation::~PrintOperation () noexcept {}

  PrintOperation::CppClassType PrintOperation::printoperation_class_;

  auto
  PrintOperation::get_type () -> GType
  {
    return printoperation_class_.init ().get_type ();
  }

  auto
  PrintOperation::get_base_type () -> GType
  {
    return gtk_print_operation_get_type ();
  }

  PrintOperation::PrintOperation ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (printoperation_class_.init ()))
  {
  }

  auto
  PrintOperation::create () -> glib::RefPtr<PrintOperation>
  {
    return glib::make_refptr_for_instance<PrintOperation> (
        new PrintOperation ());
  }

  auto
  PrintOperation::set_default_page_setup (
      const glib::RefPtr<PageSetup>& default_page_setup) -> void
  {
    gtk_print_operation_set_default_page_setup (
        gobj (),
        glib::unwrap (default_page_setup));
  }

  auto
  PrintOperation::get_default_page_setup () -> glib::RefPtr<PageSetup>
  {
    auto retvalue =
        glib::wrap (gtk_print_operation_get_default_page_setup (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PrintOperation::get_default_page_setup () const -> glib::RefPtr<const PageSetup>
  {
    return const_cast<PrintOperation*> (this)->get_default_page_setup ();
  }

  auto
  PrintOperation::set_print_settings (
      const glib::RefPtr<PrintSettings>& print_settings) -> void
  {
    gtk_print_operation_set_print_settings (gobj (),
                                            glib::unwrap (print_settings));
  }

  auto
  PrintOperation::get_print_settings () -> glib::RefPtr<PrintSettings>
  {
    auto retvalue =
        glib::wrap (gtk_print_operation_get_print_settings (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PrintOperation::get_print_settings () const -> glib::RefPtr<const PrintSettings>
  {
    return const_cast<PrintOperation*> (this)->get_print_settings ();
  }

  auto
  PrintOperation::set_job_name (const glib::ustring& job_name) -> void
  {
    gtk_print_operation_set_job_name (gobj (), job_name.c_str ());
  }

  auto
  PrintOperation::set_n_pages (int n_pages) -> void
  {
    gtk_print_operation_set_n_pages (gobj (), n_pages);
  }

  auto
  PrintOperation::set_current_page (int current_page) -> void
  {
    gtk_print_operation_set_current_page (gobj (), current_page);
  }

  auto
  PrintOperation::set_use_full_page (bool use_full_page) -> void
  {
    gtk_print_operation_set_use_full_page (gobj (),
                                           static_cast<int> (use_full_page));
  }

  auto
  PrintOperation::set_unit (Unit unit) -> void
  {
    gtk_print_operation_set_unit (gobj (), static_cast<GtkUnit> (unit));
  }

  auto
  PrintOperation::set_export_filename (const std::string& filename) -> void
  {
    gtk_print_operation_set_export_filename (gobj (), filename.c_str ());
  }

  auto
  PrintOperation::set_track_print_status (bool track_status) -> void
  {
    gtk_print_operation_set_track_print_status (
        gobj (),
        static_cast<int> (track_status));
  }

  auto
  PrintOperation::set_show_progress (bool show_progress) -> void
  {
    gtk_print_operation_set_show_progress (gobj (),
                                           static_cast<int> (show_progress));
  }

  auto
  PrintOperation::set_allow_async (bool allow_async) -> void
  {
    gtk_print_operation_set_allow_async (gobj (),
                                         static_cast<int> (allow_async));
  }

  auto
  PrintOperation::set_custom_tab_label (const glib::ustring& label) -> void
  {
    gtk_print_operation_set_custom_tab_label (gobj (), label.c_str ());
  }

  auto
  PrintOperation::run (Action action, Window& parent) -> Result
  {
    GError* gerror = nullptr;
    auto retvalue = static_cast<Result> (
        gtk_print_operation_run (gobj (),
                                 static_cast<GtkPrintOperationAction> (action),
                                 (parent).gobj (),
                                 &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  PrintOperation::get_status () const -> PrintStatus
  {
    return static_cast<PrintStatus> (gtk_print_operation_get_status (
        const_cast<GtkPrintOperation*> (gobj ())));
  }

  auto
  PrintOperation::get_status_string () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_print_operation_get_status_string (
            const_cast<GtkPrintOperation*> (gobj ())));
  }

  auto
  PrintOperation::cancel () -> void
  {
    gtk_print_operation_cancel (gobj ());
  }

  auto
  PrintOperation::is_finished () const -> bool
  {
    return gtk_print_operation_is_finished (
        const_cast<GtkPrintOperation*> (gobj ()));
  }

  auto
  PrintOperation::draw_page_finish () -> void
  {
    gtk_print_operation_draw_page_finish (gobj ());
  }

  auto
  PrintOperation::set_defer_drawing () -> void
  {
    gtk_print_operation_set_defer_drawing (gobj ());
  }

  auto
  PrintOperation::set_support_selection (bool support_selection) -> void
  {
    gtk_print_operation_set_support_selection (
        gobj (),
        static_cast<int> (support_selection));
  }

  auto
  PrintOperation::get_support_selection () const -> bool
  {
    return gtk_print_operation_get_support_selection (
        const_cast<GtkPrintOperation*> (gobj ()));
  }

  auto
  PrintOperation::set_has_selection (bool has_selection) -> void
  {
    gtk_print_operation_set_has_selection (gobj (),
                                           static_cast<int> (has_selection));
  }

  auto
  PrintOperation::get_has_selection () const -> bool
  {
    return gtk_print_operation_get_has_selection (
        const_cast<GtkPrintOperation*> (gobj ()));
  }

  auto
  PrintOperation::set_embed_page_setup (bool embed) -> void
  {
    gtk_print_operation_set_embed_page_setup (gobj (),
                                              static_cast<int> (embed));
  }

  auto
  PrintOperation::get_embed_page_setup () const -> bool
  {
    return gtk_print_operation_get_embed_page_setup (
        const_cast<GtkPrintOperation*> (gobj ()));
  }

  auto
  PrintOperation::get_n_pages_to_print () const -> int
  {
    return gtk_print_operation_get_n_pages_to_print (
        const_cast<GtkPrintOperation*> (gobj ()));
  }

  auto
  PrintOperation::signal_done () -> glib::SignalProxy<void (Result)>
  {
    return glib::SignalProxy<void (Result)> (this,
                                             &PrintOperation_signal_done_info);
  }

  auto
  PrintOperation::signal_begin_print () -> glib::SignalProxy<void (const glib::RefPtr<PrintContext>&)>
  {
    return glib::SignalProxy<void (const glib::RefPtr<PrintContext>&)> (
        this,
        &PrintOperation_signal_begin_print_info);
  }

  auto
  PrintOperation::signal_paginate () -> glib::SignalProxy<bool (const glib::RefPtr<PrintContext>&)>
  {
    return glib::SignalProxy<bool (const glib::RefPtr<PrintContext>&)> (
        this,
        &PrintOperation_signal_paginate_info);
  }

  auto
  PrintOperation::signal_request_page_setup () -> glib::SignalProxy<void (const glib::RefPtr<PrintContext>&,
                                 int,
                                 const glib::RefPtr<PageSetup>&)>
  {
    return glib::SignalProxy<void (const glib::RefPtr<PrintContext>&,
                                   int,
                                   const glib::RefPtr<PageSetup>&)> (
        this,
        &PrintOperation_signal_request_page_setup_info);
  }

  auto
  PrintOperation::signal_draw_page () -> glib::SignalProxy<void (const glib::RefPtr<PrintContext>&, int)>
  {
    return glib::SignalProxy<void (const glib::RefPtr<PrintContext>&, int)> (
        this,
        &PrintOperation_signal_draw_page_info);
  }

  auto
  PrintOperation::signal_end_print () -> glib::SignalProxy<void (const glib::RefPtr<PrintContext>&)>
  {
    return glib::SignalProxy<void (const glib::RefPtr<PrintContext>&)> (
        this,
        &PrintOperation_signal_end_print_info);
  }

  auto
  PrintOperation::signal_status_changed () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (
        this,
        &PrintOperation_signal_status_changed_info);
  }

  auto
  PrintOperation::signal_create_custom_widget () -> glib::SignalProxy<Widget*()>
  {
    return glib::SignalProxy<Widget*()> (
        this,
        &PrintOperation_signal_create_custom_widget_info);
  }

  auto
  PrintOperation::signal_custom_widget_apply () -> glib::SignalProxy<void (Widget*)>
  {
    return glib::SignalProxy<void (Widget*)> (
        this,
        &PrintOperation_signal_custom_widget_apply_info);
  }

  auto
  PrintOperation::signal_preview () -> glib::SignalProxy<bool (const glib::RefPtr<PrintOperationPreview>&,
                                 const glib::RefPtr<PrintContext>&,
                                 Window*)>
  {
    return glib::SignalProxy<bool (const glib::RefPtr<PrintOperationPreview>&,
                                   const glib::RefPtr<PrintContext>&,
                                   Window*)> (
        this,
        &PrintOperation_signal_preview_info);
  }

  auto
  PrintOperation::signal_update_custom_widget () -> glib::SignalProxy<void (Widget*,
                                 const glib::RefPtr<PageSetup>&,
                                 const glib::RefPtr<PrintSettings>&)>
  {
    return glib::SignalProxy<void (Widget*,
                                   const glib::RefPtr<PageSetup>&,
                                   const glib::RefPtr<PrintSettings>&)> (
        this,
        &PrintOperation_signal_update_custom_widget_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<PageSetup>>::value,
      "Type glib::RefPtr<PageSetup> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  PrintOperation::property_default_page_setup () -> glib::PropertyProxy<glib::RefPtr<PageSetup>>
  {
    return glib::PropertyProxy<glib::RefPtr<PageSetup>> (this,
                                                         "default-page-setup");
  }

  auto
  PrintOperation::property_default_page_setup () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<PageSetup>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<PageSetup>> (
        this,
        "default-page-setup");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<PrintSettings>>::value,
      "Type glib::RefPtr<PrintSettings> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  PrintOperation::property_print_settings () -> glib::PropertyProxy<glib::RefPtr<PrintSettings>>
  {
    return glib::PropertyProxy<glib::RefPtr<PrintSettings>> (this,
                                                             "print-settings");
  }

  auto
  PrintOperation::property_print_settings () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<PrintSettings>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<PrintSettings>> (
        this,
        "print-settings");
  }

  auto
  PrintOperation::property_job_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "job-name");
  }

  auto
  PrintOperation::property_job_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "job-name");
  }

  auto
  PrintOperation::property_n_pages () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "n-pages");
  }

  auto
  PrintOperation::property_n_pages () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "n-pages");
  }

  auto
  PrintOperation::property_current_page () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "current-page");
  }

  auto
  PrintOperation::property_current_page () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "current-page");
  }

  auto
  PrintOperation::property_use_full_page () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "use-full-page");
  }

  auto
  PrintOperation::property_use_full_page () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "use-full-page");
  }

  auto
  PrintOperation::property_track_print_status () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "track-print-status");
  }

  auto
  PrintOperation::property_track_print_status () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "track-print-status");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Unit>::value,
      "Type Unit cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  PrintOperation::property_unit () -> glib::PropertyProxy<Unit>
  {
    return glib::PropertyProxy<Unit> (this, "unit");
  }

  auto
  PrintOperation::property_unit () const -> glib::PropertyProxy_ReadOnly<Unit>
  {
    return glib::PropertyProxy_ReadOnly<Unit> (this, "unit");
  }

  auto
  PrintOperation::property_show_progress () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "show-progress");
  }

  auto
  PrintOperation::property_show_progress () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "show-progress");
  }

  auto
  PrintOperation::property_allow_async () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "allow-async");
  }

  auto
  PrintOperation::property_allow_async () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "allow-async");
  }

  auto
  PrintOperation::property_export_filename () -> glib::PropertyProxy<std::string>
  {
    return glib::PropertyProxy<std::string> (this, "export-filename");
  }

  auto
  PrintOperation::property_export_filename () const -> glib::PropertyProxy_ReadOnly<std::string>
  {
    return glib::PropertyProxy_ReadOnly<std::string> (this, "export-filename");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<PrintStatus>::value,
      "Type PrintStatus cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  PrintOperation::property_status () const -> glib::PropertyProxy_ReadOnly<PrintStatus>
  {
    return glib::PropertyProxy_ReadOnly<PrintStatus> (this, "status");
  }

  auto
  PrintOperation::property_status_string () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "status-string");
  }

  auto
  PrintOperation::property_custom_tab_label () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "custom-tab-label");
  }

  auto
  PrintOperation::property_custom_tab_label () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this,
                                                        "custom-tab-label");
  }

  auto
  PrintOperation::property_support_selection () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "support-selection");
  }

  auto
  PrintOperation::property_support_selection () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "support-selection");
  }

  auto
  PrintOperation::property_has_selection () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "has-selection");
  }

  auto
  PrintOperation::property_has_selection () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "has-selection");
  }

  auto
  PrintOperation::property_embed_page_setup () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "embed-page-setup");
  }

  auto
  PrintOperation::property_embed_page_setup () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "embed-page-setup");
  }

  auto
  PrintOperation::property_n_pages_to_print () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "n-pages-to-print");
  }

  auto
  gtk::PrintOperation::on_done (Result result) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->done)
      (*base->done) (gobj (), static_cast<GtkPrintOperationResult> (result));
  }

  auto
  gtk::PrintOperation::on_begin_print (
      const glib::RefPtr<PrintContext>& context) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->begin_print)
      (*base->begin_print) (gobj (), glib::unwrap (context));
  }

  auto
  gtk::PrintOperation::on_paginate (const glib::RefPtr<PrintContext>& context) -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->paginate)
      return (*base->paginate) (gobj (), glib::unwrap (context));

    using RType = bool;
    return RType ();
  }

  auto
  gtk::PrintOperation::on_request_page_setup (
      const glib::RefPtr<PrintContext>& context,
      int page_no,
      const glib::RefPtr<PageSetup>& setup) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->request_page_setup)
      (*base->request_page_setup) (gobj (),
                                   glib::unwrap (context),
                                   page_no,
                                   glib::unwrap (setup));
  }

  auto
  gtk::PrintOperation::on_draw_page (const glib::RefPtr<PrintContext>& context,
                                     int page_nr) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->draw_page)
      (*base->draw_page) (gobj (), glib::unwrap (context), page_nr);
  }

  auto
  gtk::PrintOperation::on_end_print (const glib::RefPtr<PrintContext>& context) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->end_print)
      (*base->end_print) (gobj (), glib::unwrap (context));
  }

  auto
  gtk::PrintOperation::on_status_changed () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->status_changed)
      (*base->status_changed) (gobj ());
  }

  auto
  gtk::PrintOperation::on_create_custom_widget () -> Widget*
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->create_custom_widget)
      return glib::wrap ((*base->create_custom_widget) (gobj ()));

    using RType = Widget*;
    return RType ();
  }

  auto
  gtk::PrintOperation::on_custom_widget_apply (Widget* widget) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->custom_widget_apply)
      (*base->custom_widget_apply) (gobj (),
                                    (GtkWidget*) glib::unwrap (widget));
  }

  auto
  gtk::PrintOperation::on_preview (
      const glib::RefPtr<PrintOperationPreview>& preview,
      const glib::RefPtr<PrintContext>& context,
      Window* parent) -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->preview)
      return (*base->preview) (gobj (),
                               (glib::unwrap (preview)),
                               glib::unwrap (context),
                               glib::unwrap (parent));

    using RType = bool;
    return RType ();
  }

  auto
  gtk::PrintOperation::on_update_custom_widget (
      Widget* widget,
      const glib::RefPtr<PageSetup>& setup,
      const glib::RefPtr<PrintSettings>& settings) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->update_custom_widget)
      (*base->update_custom_widget) (gobj (),
                                     (GtkWidget*) glib::unwrap (widget),
                                     glib::unwrap (setup),
                                     glib::unwrap (settings));
  }

} // namespace gtk
