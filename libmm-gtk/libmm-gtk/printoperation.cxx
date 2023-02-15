// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/printoperation.hxx>
#include <libmm-gtk/printoperation_p.hxx>

#include <gtk/gtk.h>

using Result = Gtk::PrintOperation::Result;

static auto
SignalProxy_PrintSetupDone_gtk_callback (GtkPageSetup* page_setup,
                                         gpointer data) -> void
{
  const auto the_slot = static_cast<Gtk::SlotPrintSetupDone*> (data);

  try
  {
    auto ps = Glib::wrap (page_setup);
    (*the_slot) (ps);
  }
  catch (...)
  {
    Glib::exception_handlers_invoke ();
  }

  delete the_slot;
}

namespace Gtk
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
      ::Glib::Error::throw_exception (gerror);
    }

    return res;
  }

  auto
  run_page_setup_dialog (
      Window& parent,
      const Glib::RefPtr<const PageSetup>& page_setup,
      const Glib::RefPtr<const PrintSettings>& print_settings) -> Glib::RefPtr<PageSetup>
  {
    return Glib::wrap (gtk_print_run_page_setup_dialog (
        parent.gobj (),
        const_cast<GtkPageSetup*> (Glib::unwrap<PageSetup> (page_setup)),
        const_cast<GtkPrintSettings*> (
            Glib::unwrap<PrintSettings> (print_settings))));
  }

  auto
  run_page_setup_dialog (
      Window& parent,
      const Glib::RefPtr<const PrintSettings>& print_settings) -> Glib::RefPtr<PageSetup>
  {
    return Glib::wrap (gtk_print_run_page_setup_dialog (
        parent.gobj (),
        nullptr,
        const_cast<GtkPrintSettings*> (
            Glib::unwrap<PrintSettings> (print_settings))));
  }

  auto
  run_page_setup_dialog_async (
      Window& parent,
      const Glib::RefPtr<const PageSetup>& page_setup,
      const Glib::RefPtr<const PrintSettings>& print_settings,
      const SlotPrintSetupDone& slot) -> void
  {
    auto slot_copy = new SlotPrintSetupDone (slot);

    gtk_print_run_page_setup_dialog_async (
        parent.gobj (),
        const_cast<GtkPageSetup*> (Glib::unwrap<PageSetup> (page_setup)),
        const_cast<GtkPrintSettings*> (
            Glib::unwrap<PrintSettings> (print_settings)),
        &SignalProxy_PrintSetupDone_gtk_callback,
        slot_copy);
  }

  auto
  run_page_setup_dialog_async (
      Window& parent,
      const Glib::RefPtr<const PrintSettings>& print_settings,
      const SlotPrintSetupDone& slot) -> void
  {
    auto slot_copy = new SlotPrintSetupDone (slot);

    gtk_print_run_page_setup_dialog_async (
        parent.gobj (),
        nullptr,
        const_cast<GtkPrintSettings*> (
            Glib::unwrap<PrintSettings> (print_settings)),
        &SignalProxy_PrintSetupDone_gtk_callback,
        slot_copy);
  }

} // namespace Gtk

namespace
{

  static auto
  PrintOperation_signal_done_callback (GtkPrintOperation* self,
                                       GtkPrintOperationResult p0,
                                       void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (Result)>;

    auto obj = dynamic_cast<PrintOperation*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (static_cast<Result> (p0));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo PrintOperation_signal_done_info = {
      "done",
      (GCallback) &PrintOperation_signal_done_callback,
      (GCallback) &PrintOperation_signal_done_callback};

  static auto
  PrintOperation_signal_begin_print_callback (GtkPrintOperation* self,
                                              GtkPrintContext* p0,
                                              void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (const Glib::RefPtr<PrintContext>&)>;

    auto obj = dynamic_cast<PrintOperation*> (
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
  }

  static const Glib::SignalProxyInfo PrintOperation_signal_begin_print_info = {
      "begin_print",
      (GCallback) &PrintOperation_signal_begin_print_callback,
      (GCallback) &PrintOperation_signal_begin_print_callback};

  static auto
  PrintOperation_signal_paginate_callback (GtkPrintOperation* self,
                                           GtkPrintContext* p0,
                                           void* data) -> gboolean
  {
    using namespace Gtk;
    using SlotType = sigc::slot<bool (const Glib::RefPtr<PrintContext>&)>;

    auto obj = dynamic_cast<PrintOperation*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> (
              (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true)));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
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
    using namespace Gtk;
    using SlotType = sigc::slot<void (const Glib::RefPtr<PrintContext>&)>;

    auto obj = dynamic_cast<PrintOperation*> (
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

  static const Glib::SignalProxyInfo PrintOperation_signal_paginate_info = {
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
    using namespace Gtk;
    using SlotType = sigc::slot<void (const Glib::RefPtr<PrintContext>&,
                                      int,
                                      const Glib::RefPtr<PageSetup>&)>;

    auto obj = dynamic_cast<PrintOperation*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (
              slot)) (Glib::wrap (p0, true), p1, Glib::wrap (p2, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo
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
    using namespace Gtk;
    using SlotType = sigc::slot<void (const Glib::RefPtr<PrintContext>&, int)>;

    auto obj = dynamic_cast<PrintOperation*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true), p1);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo PrintOperation_signal_draw_page_info = {
      "draw_page",
      (GCallback) &PrintOperation_signal_draw_page_callback,
      (GCallback) &PrintOperation_signal_draw_page_callback};

  static auto
  PrintOperation_signal_end_print_callback (GtkPrintOperation* self,
                                            GtkPrintContext* p0,
                                            void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (const Glib::RefPtr<PrintContext>&)>;

    auto obj = dynamic_cast<PrintOperation*> (
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
  }

  static const Glib::SignalProxyInfo PrintOperation_signal_end_print_info = {
      "end_print",
      (GCallback) &PrintOperation_signal_end_print_callback,
      (GCallback) &PrintOperation_signal_end_print_callback};

  static const Glib::SignalProxyInfo PrintOperation_signal_status_changed_info =
      {"status_changed",
       (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
       (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  static auto
  PrintOperation_signal_create_custom_widget_callback (GtkPrintOperation* self,
                                                       void* data) -> GtkWidget*
  {
    using namespace Gtk;
    using SlotType = sigc::slot<Widget*()>;

    auto obj = dynamic_cast<PrintOperation*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          return (GtkWidget*) Glib::unwrap (
              (*static_cast<SlotType*> (slot)) ());
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
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
    using namespace Gtk;
    using SlotType = sigc::slot<void ()>;

    auto obj = dynamic_cast<PrintOperation*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) ();
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = GtkWidget*;
    return RType ();
  }

  static const Glib::SignalProxyInfo
      PrintOperation_signal_create_custom_widget_info = {
          "create_custom_widget",
          (GCallback) &PrintOperation_signal_create_custom_widget_callback,
          (GCallback) &PrintOperation_signal_create_custom_widget_notify_callback};

  static auto
  PrintOperation_signal_custom_widget_apply_callback (GtkPrintOperation* self,
                                                      GtkWidget* p0,
                                                      void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (Widget*)>;

    auto obj = dynamic_cast<PrintOperation*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo
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
    using namespace Gtk;
    using SlotType =
        sigc::slot<bool (const Glib::RefPtr<PrintOperationPreview>&,
                         const Glib::RefPtr<PrintContext>&,
                         Window*)>;

    auto obj = dynamic_cast<PrintOperation*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> (
              (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true),
                                                Glib::wrap (p1, true),
                                                Glib::wrap (p2)));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
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
    using namespace Gtk;
    using SlotType =
        sigc::slot<void (const Glib::RefPtr<PrintOperationPreview>&,
                         const Glib::RefPtr<PrintContext>&,
                         Window*)>;

    auto obj = dynamic_cast<PrintOperation*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true),
                                            Glib::wrap (p1, true),
                                            Glib::wrap (p2));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const Glib::SignalProxyInfo PrintOperation_signal_preview_info = {
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
    using namespace Gtk;
    using SlotType = sigc::slot<void (Widget*,
                                      const Glib::RefPtr<PageSetup>&,
                                      const Glib::RefPtr<PrintSettings>&)>;

    auto obj = dynamic_cast<PrintOperation*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0),
                                            Glib::wrap (p1, true),
                                            Glib::wrap (p2, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo
      PrintOperation_signal_update_custom_widget_info = {
          "update_custom_widget",
          (GCallback) &PrintOperation_signal_update_custom_widget_callback,
          (GCallback) &PrintOperation_signal_update_custom_widget_callback};

} // namespace

auto
Glib::Value<Gtk::PrintStatus>::value_type () -> GType
{
  return gtk_print_status_get_type ();
}

Gtk::PrintError::PrintError (Gtk::PrintError::Code error_code,
                             const Glib::ustring& error_message)
  : Glib::Error (GTK_PRINT_ERROR, error_code, error_message)
{
}

Gtk::PrintError::PrintError (GError* gobject)
  : Glib::Error (gobject)
{
}

auto
Gtk::PrintError::code () const -> Gtk::PrintError::Code
{
  return static_cast<Code> (Glib::Error::code ());
}

auto
Gtk::PrintError::throw_func (GError* gobject) -> void
{
  throw Gtk::PrintError (gobject);
}

auto
Glib::Value<Gtk::PrintError::Code>::value_type () -> GType
{
  return gtk_print_error_get_type ();
}

auto
Glib::Value<Gtk::PrintOperation::Result>::value_type () -> GType
{
  return gtk_print_operation_result_get_type ();
}

auto
Glib::Value<Gtk::PrintOperation::Action>::value_type () -> GType
{
  return gtk_print_operation_action_get_type ();
}

namespace Glib
{

  auto
  wrap (GtkPrintOperation* object, bool take_copy) -> Glib::RefPtr<Gtk::PrintOperation>
  {
    return Glib::make_refptr_for_instance<Gtk::PrintOperation> (
        dynamic_cast<Gtk::PrintOperation*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  PrintOperation_Class::init () -> const Glib::Class&
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
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

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
          Glib::exception_handlers_invoke ();
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
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_begin_print (Glib::wrap (p0, true));
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

    if (base && base->begin_print)
      (*base->begin_print) (self, p0);
  }

  auto
  PrintOperation_Class::paginate_callback (GtkPrintOperation* self,
                                           GtkPrintContext* p0) -> gboolean
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return static_cast<int> (obj->on_paginate (Glib::wrap (p0, true)));
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
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
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_request_page_setup (Glib::wrap (p0, true),
                                      p1,
                                      Glib::wrap (p2, true));
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

    if (base && base->request_page_setup)
      (*base->request_page_setup) (self, p0, p1, p2);
  }

  auto
  PrintOperation_Class::draw_page_callback (GtkPrintOperation* self,
                                            GtkPrintContext* p0,
                                            gint p1) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_draw_page (Glib::wrap (p0, true), p1);
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

    if (base && base->draw_page)
      (*base->draw_page) (self, p0, p1);
  }

  auto
  PrintOperation_Class::end_print_callback (GtkPrintOperation* self,
                                            GtkPrintContext* p0) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_end_print (Glib::wrap (p0, true));
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

    if (base && base->end_print)
      (*base->end_print) (self, p0);
  }

  auto
  PrintOperation_Class::status_changed_callback (GtkPrintOperation* self) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

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
          Glib::exception_handlers_invoke ();
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
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return (GtkWidget*) Glib::unwrap (obj->on_create_custom_widget ());
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
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
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_custom_widget_apply (Glib::wrap (p0));
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

    if (base && base->custom_widget_apply)
      (*base->custom_widget_apply) (self, p0);
  }

  auto
  PrintOperation_Class::preview_callback (GtkPrintOperation* self,
                                          GtkPrintOperationPreview* p0,
                                          GtkPrintContext* p1,
                                          GtkWindow* p2) -> gboolean
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return static_cast<int> (obj->on_preview (Glib::wrap (p0, true),
                                                    Glib::wrap (p1, true),
                                                    Glib::wrap (p2)));
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
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
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_update_custom_widget (Glib::wrap (p0),
                                        Glib::wrap (p1, true),
                                        Glib::wrap (p2, true));
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

    if (base && base->update_custom_widget)
      (*base->update_custom_widget) (self, p0, p1, p2);
  }

  auto
  PrintOperation_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new PrintOperation ((GtkPrintOperation*) object);
  }

  auto
  PrintOperation::gobj_copy () -> GtkPrintOperation*
  {
    reference ();
    return gobj ();
  }

  PrintOperation::PrintOperation (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  PrintOperation::PrintOperation (GtkPrintOperation* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  PrintOperation::PrintOperation (PrintOperation&& src) noexcept
    : Glib::Object (std::move (src)),
      PrintOperationPreview (std::move (src))
  {
  }

  auto
  PrintOperation::operator= (PrintOperation&& src) noexcept -> PrintOperation&
  {
    Glib::Object::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (printoperation_class_.init ()))
  {
  }

  auto
  PrintOperation::create () -> Glib::RefPtr<PrintOperation>
  {
    return Glib::make_refptr_for_instance<PrintOperation> (
        new PrintOperation ());
  }

  auto
  PrintOperation::set_default_page_setup (
      const Glib::RefPtr<PageSetup>& default_page_setup) -> void
  {
    gtk_print_operation_set_default_page_setup (
        gobj (),
        Glib::unwrap (default_page_setup));
  }

  auto
  PrintOperation::get_default_page_setup () -> Glib::RefPtr<PageSetup>
  {
    auto retvalue =
        Glib::wrap (gtk_print_operation_get_default_page_setup (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PrintOperation::get_default_page_setup () const -> Glib::RefPtr<const PageSetup>
  {
    return const_cast<PrintOperation*> (this)->get_default_page_setup ();
  }

  auto
  PrintOperation::set_print_settings (
      const Glib::RefPtr<PrintSettings>& print_settings) -> void
  {
    gtk_print_operation_set_print_settings (gobj (),
                                            Glib::unwrap (print_settings));
  }

  auto
  PrintOperation::get_print_settings () -> Glib::RefPtr<PrintSettings>
  {
    auto retvalue =
        Glib::wrap (gtk_print_operation_get_print_settings (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PrintOperation::get_print_settings () const -> Glib::RefPtr<const PrintSettings>
  {
    return const_cast<PrintOperation*> (this)->get_print_settings ();
  }

  auto
  PrintOperation::set_job_name (const Glib::ustring& job_name) -> void
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
  PrintOperation::set_custom_tab_label (const Glib::ustring& label) -> void
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
      ::Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  PrintOperation::get_status () const -> PrintStatus
  {
    return static_cast<PrintStatus> (gtk_print_operation_get_status (
        const_cast<GtkPrintOperation*> (gobj ())));
  }

  auto
  PrintOperation::get_status_string () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
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
  PrintOperation::signal_done () -> Glib::SignalProxy<void (Result)>
  {
    return Glib::SignalProxy<void (Result)> (this,
                                             &PrintOperation_signal_done_info);
  }

  auto
  PrintOperation::signal_begin_print () -> Glib::SignalProxy<void (const Glib::RefPtr<PrintContext>&)>
  {
    return Glib::SignalProxy<void (const Glib::RefPtr<PrintContext>&)> (
        this,
        &PrintOperation_signal_begin_print_info);
  }

  auto
  PrintOperation::signal_paginate () -> Glib::SignalProxy<bool (const Glib::RefPtr<PrintContext>&)>
  {
    return Glib::SignalProxy<bool (const Glib::RefPtr<PrintContext>&)> (
        this,
        &PrintOperation_signal_paginate_info);
  }

  auto
  PrintOperation::signal_request_page_setup () -> Glib::SignalProxy<void (const Glib::RefPtr<PrintContext>&,
                                 int,
                                 const Glib::RefPtr<PageSetup>&)>
  {
    return Glib::SignalProxy<void (const Glib::RefPtr<PrintContext>&,
                                   int,
                                   const Glib::RefPtr<PageSetup>&)> (
        this,
        &PrintOperation_signal_request_page_setup_info);
  }

  auto
  PrintOperation::signal_draw_page () -> Glib::SignalProxy<void (const Glib::RefPtr<PrintContext>&, int)>
  {
    return Glib::SignalProxy<void (const Glib::RefPtr<PrintContext>&, int)> (
        this,
        &PrintOperation_signal_draw_page_info);
  }

  auto
  PrintOperation::signal_end_print () -> Glib::SignalProxy<void (const Glib::RefPtr<PrintContext>&)>
  {
    return Glib::SignalProxy<void (const Glib::RefPtr<PrintContext>&)> (
        this,
        &PrintOperation_signal_end_print_info);
  }

  auto
  PrintOperation::signal_status_changed () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (
        this,
        &PrintOperation_signal_status_changed_info);
  }

  auto
  PrintOperation::signal_create_custom_widget () -> Glib::SignalProxy<Widget*()>
  {
    return Glib::SignalProxy<Widget*()> (
        this,
        &PrintOperation_signal_create_custom_widget_info);
  }

  auto
  PrintOperation::signal_custom_widget_apply () -> Glib::SignalProxy<void (Widget*)>
  {
    return Glib::SignalProxy<void (Widget*)> (
        this,
        &PrintOperation_signal_custom_widget_apply_info);
  }

  auto
  PrintOperation::signal_preview () -> Glib::SignalProxy<bool (const Glib::RefPtr<PrintOperationPreview>&,
                                 const Glib::RefPtr<PrintContext>&,
                                 Window*)>
  {
    return Glib::SignalProxy<bool (const Glib::RefPtr<PrintOperationPreview>&,
                                   const Glib::RefPtr<PrintContext>&,
                                   Window*)> (
        this,
        &PrintOperation_signal_preview_info);
  }

  auto
  PrintOperation::signal_update_custom_widget () -> Glib::SignalProxy<void (Widget*,
                                 const Glib::RefPtr<PageSetup>&,
                                 const Glib::RefPtr<PrintSettings>&)>
  {
    return Glib::SignalProxy<void (Widget*,
                                   const Glib::RefPtr<PageSetup>&,
                                   const Glib::RefPtr<PrintSettings>&)> (
        this,
        &PrintOperation_signal_update_custom_widget_info);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<PageSetup>>::value,
      "Type Glib::RefPtr<PageSetup> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  PrintOperation::property_default_page_setup () -> Glib::PropertyProxy<Glib::RefPtr<PageSetup>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<PageSetup>> (this,
                                                         "default-page-setup");
  }

  auto
  PrintOperation::property_default_page_setup () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<PageSetup>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<PageSetup>> (
        this,
        "default-page-setup");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<PrintSettings>>::value,
      "Type Glib::RefPtr<PrintSettings> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  PrintOperation::property_print_settings () -> Glib::PropertyProxy<Glib::RefPtr<PrintSettings>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<PrintSettings>> (this,
                                                             "print-settings");
  }

  auto
  PrintOperation::property_print_settings () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<PrintSettings>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<PrintSettings>> (
        this,
        "print-settings");
  }

  auto
  PrintOperation::property_job_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "job-name");
  }

  auto
  PrintOperation::property_job_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "job-name");
  }

  auto
  PrintOperation::property_n_pages () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "n-pages");
  }

  auto
  PrintOperation::property_n_pages () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "n-pages");
  }

  auto
  PrintOperation::property_current_page () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "current-page");
  }

  auto
  PrintOperation::property_current_page () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "current-page");
  }

  auto
  PrintOperation::property_use_full_page () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "use-full-page");
  }

  auto
  PrintOperation::property_use_full_page () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "use-full-page");
  }

  auto
  PrintOperation::property_track_print_status () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "track-print-status");
  }

  auto
  PrintOperation::property_track_print_status () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "track-print-status");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Unit>::value,
      "Type Unit cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  PrintOperation::property_unit () -> Glib::PropertyProxy<Unit>
  {
    return Glib::PropertyProxy<Unit> (this, "unit");
  }

  auto
  PrintOperation::property_unit () const -> Glib::PropertyProxy_ReadOnly<Unit>
  {
    return Glib::PropertyProxy_ReadOnly<Unit> (this, "unit");
  }

  auto
  PrintOperation::property_show_progress () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "show-progress");
  }

  auto
  PrintOperation::property_show_progress () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "show-progress");
  }

  auto
  PrintOperation::property_allow_async () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "allow-async");
  }

  auto
  PrintOperation::property_allow_async () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "allow-async");
  }

  auto
  PrintOperation::property_export_filename () -> Glib::PropertyProxy<std::string>
  {
    return Glib::PropertyProxy<std::string> (this, "export-filename");
  }

  auto
  PrintOperation::property_export_filename () const -> Glib::PropertyProxy_ReadOnly<std::string>
  {
    return Glib::PropertyProxy_ReadOnly<std::string> (this, "export-filename");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<PrintStatus>::value,
      "Type PrintStatus cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  PrintOperation::property_status () const -> Glib::PropertyProxy_ReadOnly<PrintStatus>
  {
    return Glib::PropertyProxy_ReadOnly<PrintStatus> (this, "status");
  }

  auto
  PrintOperation::property_status_string () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "status-string");
  }

  auto
  PrintOperation::property_custom_tab_label () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "custom-tab-label");
  }

  auto
  PrintOperation::property_custom_tab_label () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this,
                                                        "custom-tab-label");
  }

  auto
  PrintOperation::property_support_selection () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "support-selection");
  }

  auto
  PrintOperation::property_support_selection () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "support-selection");
  }

  auto
  PrintOperation::property_has_selection () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "has-selection");
  }

  auto
  PrintOperation::property_has_selection () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "has-selection");
  }

  auto
  PrintOperation::property_embed_page_setup () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "embed-page-setup");
  }

  auto
  PrintOperation::property_embed_page_setup () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "embed-page-setup");
  }

  auto
  PrintOperation::property_n_pages_to_print () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "n-pages-to-print");
  }

  auto
  Gtk::PrintOperation::on_done (Result result) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->done)
      (*base->done) (gobj (), static_cast<GtkPrintOperationResult> (result));
  }

  auto
  Gtk::PrintOperation::on_begin_print (
      const Glib::RefPtr<PrintContext>& context) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->begin_print)
      (*base->begin_print) (gobj (), Glib::unwrap (context));
  }

  auto
  Gtk::PrintOperation::on_paginate (const Glib::RefPtr<PrintContext>& context) -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->paginate)
      return (*base->paginate) (gobj (), Glib::unwrap (context));

    using RType = bool;
    return RType ();
  }

  auto
  Gtk::PrintOperation::on_request_page_setup (
      const Glib::RefPtr<PrintContext>& context,
      int page_no,
      const Glib::RefPtr<PageSetup>& setup) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->request_page_setup)
      (*base->request_page_setup) (gobj (),
                                   Glib::unwrap (context),
                                   page_no,
                                   Glib::unwrap (setup));
  }

  auto
  Gtk::PrintOperation::on_draw_page (const Glib::RefPtr<PrintContext>& context,
                                     int page_nr) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->draw_page)
      (*base->draw_page) (gobj (), Glib::unwrap (context), page_nr);
  }

  auto
  Gtk::PrintOperation::on_end_print (const Glib::RefPtr<PrintContext>& context) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->end_print)
      (*base->end_print) (gobj (), Glib::unwrap (context));
  }

  auto
  Gtk::PrintOperation::on_status_changed () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->status_changed)
      (*base->status_changed) (gobj ());
  }

  auto
  Gtk::PrintOperation::on_create_custom_widget () -> Widget*
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->create_custom_widget)
      return Glib::wrap ((*base->create_custom_widget) (gobj ()));

    using RType = Widget*;
    return RType ();
  }

  auto
  Gtk::PrintOperation::on_custom_widget_apply (Widget* widget) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->custom_widget_apply)
      (*base->custom_widget_apply) (gobj (),
                                    (GtkWidget*) Glib::unwrap (widget));
  }

  auto
  Gtk::PrintOperation::on_preview (
      const Glib::RefPtr<PrintOperationPreview>& preview,
      const Glib::RefPtr<PrintContext>& context,
      Window* parent) -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->preview)
      return (*base->preview) (gobj (),
                               (Glib::unwrap (preview)),
                               Glib::unwrap (context),
                               Glib::unwrap (parent));

    using RType = bool;
    return RType ();
  }

  auto
  Gtk::PrintOperation::on_update_custom_widget (
      Widget* widget,
      const Glib::RefPtr<PageSetup>& setup,
      const Glib::RefPtr<PrintSettings>& settings) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->update_custom_widget)
      (*base->update_custom_widget) (gobj (),
                                     (GtkWidget*) Glib::unwrap (widget),
                                     Glib::unwrap (setup),
                                     Glib::unwrap (settings));
  }

} // namespace Gtk
