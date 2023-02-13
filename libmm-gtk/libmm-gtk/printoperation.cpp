


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/printoperation.hpp>
#include <libmm-gtk/printoperation_p.hpp>


/* Copyright (C) 2006 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <gtk/gtk.h>

using Result = Gtk::PrintOperation::Result;

// This Signal Proxy allows the C++ coder to specify a sigc::slot instead of a static function.

static auto SignalProxy_PrintSetupDone_gtk_callback (
  GtkPageSetup *page_setup, const gpointer data) -> void
{
  const auto the_slot = static_cast<Gtk::SlotPrintSetupDone*>(data);

  try
  {
    const auto ps = Glib::wrap(page_setup);
    (*the_slot)(ps);
  }
  catch (...)
  {
    Glib::exception_handlers_invoke();
  }

  delete the_slot;
}

namespace Gtk
{

auto
PrintOperation::run(Action action) -> Result
{
  GError* gerror = nullptr;
  const Result res =
    (Result)gtk_print_operation_run(this->gobj(), (GtkPrintOperationAction)action, nullptr, &gerror);

  if (res == Result::ERROR)
  {
    gtk_print_operation_get_error(this->gobj(), &gerror);
    Glib::Error::throw_exception(gerror);
  }

  return res;
}

auto
run_page_setup_dialog(Window& parent,
                      const Glib::RefPtr<const PageSetup>& page_setup,
                      const Glib::RefPtr<const PrintSettings>& print_settings) -> Glib::RefPtr<PageSetup>
{
  // Specify the exact type with template specialization, to avoid possible
  // ambiguities between the const and non-const versions of unwrap() reported
  // by Sun's compiler (specifying unwrap<const Object> was reported
  // not to work):
  return Glib::wrap(
    gtk_print_run_page_setup_dialog(
      parent.gobj(),
      const_cast<GtkPageSetup*>(Glib::unwrap<PageSetup>(page_setup)),
      const_cast<GtkPrintSettings*>(Glib::unwrap<PrintSettings>(print_settings))));

}

auto
run_page_setup_dialog(Window& parent,
                      const Glib::RefPtr<const PrintSettings>& print_settings) -> Glib::RefPtr<PageSetup>
{
  // Specify the exact type with template specialization, to avoid possible
  // ambiguities between the const and non-const versions of unwrap() reported
  // by Sun's compiler (specifying unwrap<const Object> was reported
  // not to work):
  return Glib::wrap(
    gtk_print_run_page_setup_dialog(
      parent.gobj(),
      nullptr,
      const_cast<GtkPrintSettings*>(Glib::unwrap<PrintSettings>(print_settings))));

}

auto run_page_setup_dialog_async (
  Window &parent,
  const Glib::RefPtr <const PageSetup> &page_setup,
  const Glib::RefPtr <const PrintSettings> &print_settings,
  const SlotPrintSetupDone &slot) -> void
{
  const auto slot_copy = new SlotPrintSetupDone(slot);

  // Specify the exact type with template specialization, to avoid possible
  // ambiguities between the const and non-const versions of unwrap() reported
  // by Sun's compiler (specifying unwrap<const Object> was reported
  // not to work):
  gtk_print_run_page_setup_dialog_async(
    parent.gobj(),
    const_cast<GtkPageSetup*>(Glib::unwrap<PageSetup>(page_setup)),
    const_cast<GtkPrintSettings*>(Glib::unwrap<PrintSettings>(print_settings)),
    &SignalProxy_PrintSetupDone_gtk_callback,
    slot_copy);
}

auto run_page_setup_dialog_async (
  Window &parent,
  const Glib::RefPtr <const PrintSettings> &print_settings,
  const SlotPrintSetupDone &slot) -> void
{
  const auto slot_copy = new SlotPrintSetupDone(slot);

  // Specify the exact type with template specialization, to avoid possible
  // ambiguities between the const and non-const versions of unwrap() reported
  // by Sun's compiler (specifying unwrap<const Object> was reported
  // not to work):
  gtk_print_run_page_setup_dialog_async(
    parent.gobj(),
    nullptr,
    const_cast<GtkPrintSettings*>(Glib::unwrap<PrintSettings>(print_settings)),
    &SignalProxy_PrintSetupDone_gtk_callback,
    slot_copy);
}

} // namespace Gtk

namespace
{


auto PrintOperation_signal_done_callback (
  GtkPrintOperation *self, GtkPrintOperationResult p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(Result)>;

  const auto obj = dynamic_cast<PrintOperation*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(static_cast<Result>(p0)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo PrintOperation_signal_done_info =
{
  "done",
  (GCallback) &PrintOperation_signal_done_callback,
  (GCallback) &PrintOperation_signal_done_callback
};


auto PrintOperation_signal_begin_print_callback (
  GtkPrintOperation *self, GtkPrintContext *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<PrintContext>&)>;

  const auto obj = dynamic_cast<PrintOperation*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo PrintOperation_signal_begin_print_info =
{
  "begin_print",
  (GCallback) &PrintOperation_signal_begin_print_callback,
  (GCallback) &PrintOperation_signal_begin_print_callback
};


auto PrintOperation_signal_paginate_callback(GtkPrintOperation* self, GtkPrintContext* p0,void* data) -> gboolean
{
  using namespace Gtk;
  using SlotType = sigc::slot<bool(const Glib::RefPtr<PrintContext>&)>;

  const auto obj = dynamic_cast<PrintOperation*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        return (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
        );
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }

  using RType = gboolean;
  return RType();
}

auto PrintOperation_signal_paginate_notify_callback(GtkPrintOperation* self, GtkPrintContext* p0, void* data) -> gboolean
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<PrintContext>&)>;

  const auto obj = dynamic_cast<PrintOperation*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }

  using RType = gboolean;
  return RType();
}

const Glib::SignalProxyInfo PrintOperation_signal_paginate_info =
{
  "paginate",
  (GCallback) &PrintOperation_signal_paginate_callback,
  (GCallback) &PrintOperation_signal_paginate_notify_callback
};


auto PrintOperation_signal_request_page_setup_callback (
  GtkPrintOperation *self, GtkPrintContext *p0, const gint p1, GtkPageSetup *p2, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<PrintContext>&, int, const Glib::RefPtr<PageSetup>&)>;

  const auto obj = dynamic_cast<PrintOperation*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
, p1
, Glib::wrap(p2, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo PrintOperation_signal_request_page_setup_info =
{
  "request_page_setup",
  (GCallback) &PrintOperation_signal_request_page_setup_callback,
  (GCallback) &PrintOperation_signal_request_page_setup_callback
};


auto PrintOperation_signal_draw_page_callback (
  GtkPrintOperation *self, GtkPrintContext *p0, const gint p1, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<PrintContext>&, int)>;

  const auto obj = dynamic_cast<PrintOperation*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
, p1
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo PrintOperation_signal_draw_page_info =
{
  "draw_page",
  (GCallback) &PrintOperation_signal_draw_page_callback,
  (GCallback) &PrintOperation_signal_draw_page_callback
};


auto PrintOperation_signal_end_print_callback (
  GtkPrintOperation *self, GtkPrintContext *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<PrintContext>&)>;

  const auto obj = dynamic_cast<PrintOperation*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo PrintOperation_signal_end_print_info =
{
  "end_print",
  (GCallback) &PrintOperation_signal_end_print_callback,
  (GCallback) &PrintOperation_signal_end_print_callback
};


const Glib::SignalProxyInfo PrintOperation_signal_status_changed_info =
{
  "status_changed",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


auto PrintOperation_signal_create_custom_widget_callback(GtkPrintOperation* self, void* data) -> GtkWidget*
{
  using namespace Gtk;
  using SlotType = sigc::slot<Widget*()>;

  const auto obj = dynamic_cast<PrintOperation*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        return Glib::unwrap((*static_cast<SlotType*>(slot))());
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }

  using RType = GtkWidget*;
  return RType();
}

auto PrintOperation_signal_create_custom_widget_notify_callback(GtkPrintOperation* self,  void* data) -> GtkWidget*
{
  using namespace Gtk;
  using SlotType = sigc::slot<void()>;

  const auto obj = dynamic_cast<PrintOperation*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))();
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }

  using RType = GtkWidget*;
  return RType();
}

const Glib::SignalProxyInfo PrintOperation_signal_create_custom_widget_info =
{
  "create_custom_widget",
  (GCallback) &PrintOperation_signal_create_custom_widget_callback,
  (GCallback) &PrintOperation_signal_create_custom_widget_notify_callback
};


auto PrintOperation_signal_custom_widget_apply_callback (
  GtkPrintOperation *self, GtkWidget *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(Widget*)>;

  const auto obj = dynamic_cast<PrintOperation*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo PrintOperation_signal_custom_widget_apply_info =
{
  "custom_widget_apply",
  (GCallback) &PrintOperation_signal_custom_widget_apply_callback,
  (GCallback) &PrintOperation_signal_custom_widget_apply_callback
};


auto PrintOperation_signal_preview_callback(GtkPrintOperation* self, GtkPrintOperationPreview* p0,GtkPrintContext* p1,GtkWindow* p2,void* data) -> gboolean
{
  using namespace Gtk;
  using SlotType = sigc::slot<bool(const Glib::RefPtr<PrintOperationPreview>&, const Glib::RefPtr<PrintContext>&, Window*)>;

  const auto obj = dynamic_cast<PrintOperation*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        return (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
                                               , Glib::wrap(p1, true)
                                               , Glib::wrap(p2)
        );
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }

  using RType = gboolean;
  return RType();
}

auto PrintOperation_signal_preview_notify_callback(GtkPrintOperation* self, GtkPrintOperationPreview* p0,GtkPrintContext* p1,GtkWindow* p2, void* data) -> gboolean
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<PrintOperationPreview>&, const Glib::RefPtr<PrintContext>&, Window*)>;

  const auto obj = dynamic_cast<PrintOperation*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
, Glib::wrap(p1, true)
, Glib::wrap(p2)
);
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }

  using RType = gboolean;
  return RType();
}

const Glib::SignalProxyInfo PrintOperation_signal_preview_info =
{
  "preview",
  (GCallback) &PrintOperation_signal_preview_callback,
  (GCallback) &PrintOperation_signal_preview_notify_callback
};


auto PrintOperation_signal_update_custom_widget_callback (
  GtkPrintOperation *self, GtkWidget *p0, GtkPageSetup *p1, GtkPrintSettings *p2,
  void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(Widget*, const Glib::RefPtr<PageSetup>&, const Glib::RefPtr<PrintSettings>&)>;

  const auto obj = dynamic_cast<PrintOperation*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0)
, Glib::wrap(p1, true)
, Glib::wrap(p2, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo PrintOperation_signal_update_custom_widget_info =
{
  "update_custom_widget",
  (GCallback) &PrintOperation_signal_update_custom_widget_callback,
  (GCallback) &PrintOperation_signal_update_custom_widget_callback
};


} // anonymous namespace

// static
auto Glib::Value<Gtk::PrintStatus>::value_type() -> GType
{
  return gtk_print_status_get_type();
}


Gtk::PrintError::PrintError(const Code error_code, const Glib::ustring& error_message)
: Error(GTK_PRINT_ERROR, error_code, error_message)
{}

Gtk::PrintError::PrintError(GError* gobject)
: Error(gobject)
{}

auto Gtk::PrintError::code() const -> Code
{
  return static_cast<Code>(Error::code());
}

auto Gtk::PrintError::throw_func (GError *gobject) -> void
{
  throw PrintError(gobject);
}

// static
auto Glib::Value<Gtk::PrintError::Code>::value_type() -> GType
{
  return gtk_print_error_get_type();
}

// static
auto Glib::Value<Gtk::PrintOperation::Result>::value_type() -> GType
{
  return gtk_print_operation_result_get_type();
}

// static
auto Glib::Value<Gtk::PrintOperation::Action>::value_type() -> GType
{
  return gtk_print_operation_action_get_type();
}


namespace Glib
{

auto wrap(GtkPrintOperation* object, const bool take_copy) -> RefPtr<Gtk::PrintOperation>
{
  return Glib::make_refptr_for_instance<Gtk::PrintOperation>( dynamic_cast<Gtk::PrintOperation*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto PrintOperation_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &PrintOperation_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_print_operation_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  PrintOperationPreview::add_interface(get_type());

  }

  return *this;
}


auto PrintOperation_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


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


auto PrintOperation_Class::done_callback (
  GtkPrintOperation *self, GtkPrintOperationResult p0) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_done(static_cast<Result>(p0)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->done)
    (*base->done)(self, p0);
}
auto PrintOperation_Class::begin_print_callback (
  GtkPrintOperation *self, GtkPrintContext *p0) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_begin_print(Glib::wrap(p0, true)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->begin_print)
    (*base->begin_print)(self, p0);
}
auto PrintOperation_Class::paginate_callback(GtkPrintOperation* self, GtkPrintContext* p0) -> gboolean
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return obj->on_paginate(Glib::wrap(p0, true)
        );
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->paginate)
    return (*base->paginate)(self, p0);

  using RType = gboolean;
  return RType();
}
auto PrintOperation_Class::request_page_setup_callback (
  GtkPrintOperation *self, GtkPrintContext *p0, const gint p1, GtkPageSetup *p2) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_request_page_setup(Glib::wrap(p0, true)
, p1
, Glib::wrap(p2, true)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->request_page_setup)
    (*base->request_page_setup)(self, p0, p1, p2);
}
auto PrintOperation_Class::draw_page_callback (
  GtkPrintOperation *self, GtkPrintContext *p0, const gint p1) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_draw_page(Glib::wrap(p0, true)
, p1
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->draw_page)
    (*base->draw_page)(self, p0, p1);
}
auto PrintOperation_Class::end_print_callback (GtkPrintOperation *self, GtkPrintContext *p0) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_end_print(Glib::wrap(p0, true)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->end_print)
    (*base->end_print)(self, p0);
}
auto PrintOperation_Class::status_changed_callback (GtkPrintOperation *self) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_status_changed();
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->status_changed)
    (*base->status_changed)(self);
}
auto PrintOperation_Class::create_custom_widget_callback(GtkPrintOperation* self) -> GtkWidget*
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return Glib::unwrap(obj->on_create_custom_widget());
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->create_custom_widget)
    return (*base->create_custom_widget)(self);

  using RType = GtkWidget*;
  return RType();
}
auto PrintOperation_Class::custom_widget_apply_callback (
  GtkPrintOperation *self, GtkWidget *p0) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_custom_widget_apply(Glib::wrap(p0)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->custom_widget_apply)
    (*base->custom_widget_apply)(self, p0);
}
auto PrintOperation_Class::preview_callback(GtkPrintOperation* self, GtkPrintOperationPreview* p0, GtkPrintContext* p1, GtkWindow* p2) -> gboolean
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return obj->on_preview(Glib::wrap(p0, true)
                               , Glib::wrap(p1, true)
                               , Glib::wrap(p2)
        );
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->preview)
    return (*base->preview)(self, p0, p1, p2);

  using RType = gboolean;
  return RType();
}
auto PrintOperation_Class::update_custom_widget_callback (
  GtkPrintOperation *self, GtkWidget *p0, GtkPageSetup *p1, GtkPrintSettings *p2) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_update_custom_widget(Glib::wrap(p0)
, Glib::wrap(p1, true)
, Glib::wrap(p2, true)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->update_custom_widget)
    (*base->update_custom_widget)(self, p0, p1, p2);
}


auto PrintOperation_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new PrintOperation((GtkPrintOperation*)object);
}


/* The implementation: */

auto PrintOperation::gobj_copy() -> GtkPrintOperation*
{
  reference();
  return gobj();
}

PrintOperation::PrintOperation(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

PrintOperation::PrintOperation(GtkPrintOperation* castitem)
: Object((GObject*)castitem)
{}


PrintOperation::PrintOperation(PrintOperation&& src) noexcept
: Object(std::move(src))
  , PrintOperationPreview(std::move(src))
{}

auto PrintOperation::operator=(PrintOperation&& src) noexcept -> PrintOperation&
{
  Object::operator=(std::move(src));
  PrintOperationPreview::operator=(std::move(src));
  return *this;
}


PrintOperation::~PrintOperation() noexcept = default;

PrintOperation::CppClassType PrintOperation::printoperation_class_; // initialize static member

auto PrintOperation::get_type() -> GType
{
  return printoperation_class_.init().get_type();
}


auto PrintOperation::get_base_type() -> GType
{
  return gtk_print_operation_get_type();
}


PrintOperation::PrintOperation()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(printoperation_class_.init()))
{


}

auto PrintOperation::create() -> Glib::RefPtr<PrintOperation>
{
  return Glib::make_refptr_for_instance<PrintOperation>( new PrintOperation() );
}

auto PrintOperation::set_default_page_setup (
  const Glib::RefPtr <PageSetup> &default_page_setup) -> void
{
  gtk_print_operation_set_default_page_setup(gobj(), Glib::unwrap(default_page_setup));
}

auto PrintOperation::get_default_page_setup() -> Glib::RefPtr<PageSetup>
{
  auto retvalue = Glib::wrap(gtk_print_operation_get_default_page_setup(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto PrintOperation::get_default_page_setup() const -> Glib::RefPtr<const PageSetup>
{
  return const_cast<PrintOperation*>(this)->get_default_page_setup();
}

auto PrintOperation::set_print_settings (const Glib::RefPtr <PrintSettings> &print_settings) -> void
{
  gtk_print_operation_set_print_settings(gobj(), Glib::unwrap(print_settings));
}

auto PrintOperation::get_print_settings() -> Glib::RefPtr<PrintSettings>
{
  auto retvalue = Glib::wrap(gtk_print_operation_get_print_settings(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto PrintOperation::get_print_settings() const -> Glib::RefPtr<const PrintSettings>
{
  return const_cast<PrintOperation*>(this)->get_print_settings();
}

auto PrintOperation::set_job_name (const Glib::ustring &job_name) -> void
{
  gtk_print_operation_set_job_name(gobj(), job_name.c_str());
}

auto PrintOperation::set_n_pages (
  const int n_pages) -> void
{
  gtk_print_operation_set_n_pages(gobj(), n_pages);
}

auto PrintOperation::set_current_page (
  const int current_page) -> void
{
  gtk_print_operation_set_current_page(gobj(), current_page);
}

auto PrintOperation::set_use_full_page (
  const bool use_full_page) -> void
{
  gtk_print_operation_set_use_full_page(gobj(), use_full_page);
}

auto PrintOperation::set_unit (Unit unit) -> void
{
  gtk_print_operation_set_unit(gobj(), static_cast<GtkUnit>(unit));
}

auto PrintOperation::set_export_filename (const std::string &filename) -> void
{
  gtk_print_operation_set_export_filename(gobj(), filename.c_str());
}

auto PrintOperation::set_track_print_status (
  const bool track_status) -> void
{
  gtk_print_operation_set_track_print_status(gobj(), track_status);
}

auto PrintOperation::set_show_progress (
  const bool show_progress) -> void
{
  gtk_print_operation_set_show_progress(gobj(), show_progress);
}

auto PrintOperation::set_allow_async (
  const bool allow_async) -> void
{
  gtk_print_operation_set_allow_async(gobj(), allow_async);
}

auto PrintOperation::set_custom_tab_label (const Glib::ustring &label) -> void
{
  gtk_print_operation_set_custom_tab_label(gobj(), label.c_str());
}

auto PrintOperation::run(Action action, Window& parent) -> Result
{
  GError* gerror = nullptr;
  const auto retvalue = static_cast<Result>(gtk_print_operation_run(gobj(), static_cast<GtkPrintOperationAction>(action), parent.gobj(), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto PrintOperation::get_status() const -> PrintStatus
{
  return static_cast<PrintStatus>(gtk_print_operation_get_status(const_cast<GtkPrintOperation*>(gobj())));
}

auto PrintOperation::get_status_string() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_print_operation_get_status_string(const_cast<GtkPrintOperation*>(gobj())));
}

auto PrintOperation::cancel () -> void
{
  gtk_print_operation_cancel(gobj());
}

auto PrintOperation::is_finished() const -> bool
{
  return gtk_print_operation_is_finished(const_cast<GtkPrintOperation*>(gobj()));
}

auto PrintOperation::draw_page_finish () -> void
{
  gtk_print_operation_draw_page_finish(gobj());
}

auto PrintOperation::set_defer_drawing () -> void
{
  gtk_print_operation_set_defer_drawing(gobj());
}

auto PrintOperation::set_support_selection (
  const bool support_selection) -> void
{
  gtk_print_operation_set_support_selection(gobj(), support_selection);
}

auto PrintOperation::get_support_selection() const -> bool
{
  return gtk_print_operation_get_support_selection(const_cast<GtkPrintOperation*>(gobj()));
}

auto PrintOperation::set_has_selection (
  const bool has_selection) -> void
{
  gtk_print_operation_set_has_selection(gobj(), has_selection);
}

auto PrintOperation::get_has_selection() const -> bool
{
  return gtk_print_operation_get_has_selection(const_cast<GtkPrintOperation*>(gobj()));
}

auto PrintOperation::set_embed_page_setup (
  const bool embed) -> void
{
  gtk_print_operation_set_embed_page_setup(gobj(), embed);
}

auto PrintOperation::get_embed_page_setup() const -> bool
{
  return gtk_print_operation_get_embed_page_setup(const_cast<GtkPrintOperation*>(gobj()));
}

auto PrintOperation::get_n_pages_to_print() const -> int
{
  return gtk_print_operation_get_n_pages_to_print(const_cast<GtkPrintOperation*>(gobj()));
}


auto PrintOperation::signal_done() -> Glib::SignalProxy<void(Result)>
{
  return {this, &PrintOperation_signal_done_info};
}


auto PrintOperation::signal_begin_print() -> Glib::SignalProxy<void(const Glib::RefPtr<PrintContext>&)>
{
  return {this, &PrintOperation_signal_begin_print_info};
}


auto PrintOperation::signal_paginate() -> Glib::SignalProxy<bool(const Glib::RefPtr<PrintContext>&)>
{
  return {this, &PrintOperation_signal_paginate_info};
}


auto PrintOperation::signal_request_page_setup() -> Glib::SignalProxy<void(const Glib::RefPtr<PrintContext>&, int, const Glib::RefPtr<PageSetup>&)>
{
  return {this, &PrintOperation_signal_request_page_setup_info};
}


auto PrintOperation::signal_draw_page() -> Glib::SignalProxy<void(const Glib::RefPtr<PrintContext>&, int)>
{
  return {this, &PrintOperation_signal_draw_page_info};
}


auto PrintOperation::signal_end_print() -> Glib::SignalProxy<void(const Glib::RefPtr<PrintContext>&)>
{
  return {this, &PrintOperation_signal_end_print_info};
}


auto PrintOperation::signal_status_changed() -> Glib::SignalProxy<void()>
{
  return {this, &PrintOperation_signal_status_changed_info};
}


auto PrintOperation::signal_create_custom_widget() -> Glib::SignalProxy<Widget*()>
{
  return {this, &PrintOperation_signal_create_custom_widget_info};
}


auto PrintOperation::signal_custom_widget_apply() -> Glib::SignalProxy<void(Widget*)>
{
  return {this, &PrintOperation_signal_custom_widget_apply_info};
}


auto PrintOperation::signal_preview() -> Glib::SignalProxy<bool(const Glib::RefPtr<PrintOperationPreview>&, const Glib::RefPtr<PrintContext>&, Window*)>
{
  return {this, &PrintOperation_signal_preview_info};
}


auto PrintOperation::signal_update_custom_widget() -> Glib::SignalProxy<void(Widget*, const Glib::RefPtr<PageSetup>&, const Glib::RefPtr<PrintSettings>&)>
{
  return {this, &PrintOperation_signal_update_custom_widget_info};
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<PageSetup>>::value,
  "Type Glib::RefPtr<PageSetup> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto PrintOperation::property_default_page_setup() -> Glib::PropertyProxy< Glib::RefPtr<PageSetup> >
{
  return {this, "default-page-setup"};
}

auto PrintOperation::property_default_page_setup() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<PageSetup> >
{
  return {this, "default-page-setup"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<PrintSettings>>::value,
  "Type Glib::RefPtr<PrintSettings> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto PrintOperation::property_print_settings() -> Glib::PropertyProxy< Glib::RefPtr<PrintSettings> >
{
  return {this, "print-settings"};
}

auto PrintOperation::property_print_settings() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<PrintSettings> >
{
  return {this, "print-settings"};
}

auto PrintOperation::property_job_name() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "job-name"};
}

auto PrintOperation::property_job_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "job-name"};
}

auto PrintOperation::property_n_pages() -> Glib::PropertyProxy< int >
{
  return {this, "n-pages"};
}

auto PrintOperation::property_n_pages() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "n-pages"};
}

auto PrintOperation::property_current_page() -> Glib::PropertyProxy< int >
{
  return {this, "current-page"};
}

auto PrintOperation::property_current_page() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "current-page"};
}

auto PrintOperation::property_use_full_page() -> Glib::PropertyProxy< bool >
{
  return {this, "use-full-page"};
}

auto PrintOperation::property_use_full_page() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "use-full-page"};
}

auto PrintOperation::property_track_print_status() -> Glib::PropertyProxy< bool >
{
  return {this, "track-print-status"};
}

auto PrintOperation::property_track_print_status() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "track-print-status"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Unit>::value,
  "Type Unit cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto PrintOperation::property_unit() -> Glib::PropertyProxy< Unit >
{
  return {this, "unit"};
}

auto PrintOperation::property_unit() const -> Glib::PropertyProxy_ReadOnly< Unit >
{
  return {this, "unit"};
}

auto PrintOperation::property_show_progress() -> Glib::PropertyProxy< bool >
{
  return {this, "show-progress"};
}

auto PrintOperation::property_show_progress() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "show-progress"};
}

auto PrintOperation::property_allow_async() -> Glib::PropertyProxy< bool >
{
  return {this, "allow-async"};
}

auto PrintOperation::property_allow_async() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "allow-async"};
}

auto PrintOperation::property_export_filename() -> Glib::PropertyProxy< std::string >
{
  return {this, "export-filename"};
}

auto PrintOperation::property_export_filename() const -> Glib::PropertyProxy_ReadOnly< std::string >
{
  return {this, "export-filename"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<PrintStatus>::value,
  "Type PrintStatus cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto PrintOperation::property_status() const -> Glib::PropertyProxy_ReadOnly< PrintStatus >
{
  return {this, "status"};
}

auto PrintOperation::property_status_string() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "status-string"};
}

auto PrintOperation::property_custom_tab_label() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "custom-tab-label"};
}

auto PrintOperation::property_custom_tab_label() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "custom-tab-label"};
}

auto PrintOperation::property_support_selection() -> Glib::PropertyProxy< bool >
{
  return {this, "support-selection"};
}

auto PrintOperation::property_support_selection() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "support-selection"};
}

auto PrintOperation::property_has_selection() -> Glib::PropertyProxy< bool >
{
  return {this, "has-selection"};
}

auto PrintOperation::property_has_selection() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "has-selection"};
}

auto PrintOperation::property_embed_page_setup() -> Glib::PropertyProxy< bool >
{
  return {this, "embed-page-setup"};
}

auto PrintOperation::property_embed_page_setup() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "embed-page-setup"};
}

auto PrintOperation::property_n_pages_to_print() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "n-pages-to-print"};
}


auto PrintOperation::on_done (Result result) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->done)
    (*base->done)(gobj(),static_cast<GtkPrintOperationResult>(result));
}
auto PrintOperation::on_begin_print (const Glib::RefPtr <PrintContext> &context) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->begin_print)
    (*base->begin_print)(gobj(),Glib::unwrap(context));
}
auto PrintOperation::on_paginate(const Glib::RefPtr<PrintContext>& context) -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->paginate)
    return (*base->paginate)(gobj(),Glib::unwrap(context));

  using RType = bool;
  return RType();
}
auto PrintOperation::on_request_page_setup (
  const Glib::RefPtr <PrintContext> &context, const int page_no,
  const Glib::RefPtr <PageSetup> &setup) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->request_page_setup)
    (*base->request_page_setup)(gobj(),Glib::unwrap(context),page_no,Glib::unwrap(setup));
}
auto PrintOperation::on_draw_page (
  const Glib::RefPtr <PrintContext> &context, const int page_nr) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->draw_page)
    (*base->draw_page)(gobj(),Glib::unwrap(context),page_nr);
}
auto PrintOperation::on_end_print (const Glib::RefPtr <PrintContext> &context) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->end_print)
    (*base->end_print)(gobj(),Glib::unwrap(context));
}
auto PrintOperation::on_status_changed () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->status_changed)
    (*base->status_changed)(gobj());
}
auto PrintOperation::on_create_custom_widget() -> Widget*
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->create_custom_widget)
    return Glib::wrap((*base->create_custom_widget)(gobj()));

  using RType = Widget*;
  return RType();
}
auto PrintOperation::on_custom_widget_apply (Widget *widget) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->custom_widget_apply)
    (*base->custom_widget_apply)(gobj(),Glib::unwrap(widget));
}
auto PrintOperation::on_preview(const Glib::RefPtr<PrintOperationPreview>& preview, const Glib::RefPtr<PrintContext>& context, Window* parent) -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->preview)
    return (*base->preview)(gobj(),Glib::unwrap(preview),Glib::unwrap(context),Glib::unwrap(parent));

  using RType = bool;
  return RType();
}
auto PrintOperation::on_update_custom_widget (
  Widget *widget, const Glib::RefPtr <PageSetup> &setup,
  const Glib::RefPtr <PrintSettings> &settings) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->update_custom_widget)
    (*base->update_custom_widget)(gobj(),Glib::unwrap(widget),Glib::unwrap(setup),Glib::unwrap(settings));
}


} // namespace Gtk


