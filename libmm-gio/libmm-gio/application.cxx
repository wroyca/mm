


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/application.hpp>
#include <libmm-gio/application_p.hpp>


/* Copyright (C) 2007 The gtkmm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gio/gio.h>
#include <libmm-gio/file.hpp>
#include <libmm-gio/actiongroup.hpp>
#include <libmm-gio/init.hpp>
#include <cstring> // std::memset()
#include <map>
#include <mutex>
#include <vector>

using Flags = Gio::Application::Flags;

namespace // anonymous
{

auto Application_signal_open_callback (
  GApplication *self, GFile **files, const gint n_files, const gchar *hint, void *data) -> void
{
  using SlotType = sigc::slot<void(const Gio::Application::type_vec_files&, const Glib::ustring&)>;

  Gio::Application::type_vec_files vec_files(n_files);
  for (int i = 0; i < n_files; ++i)
  {
    vec_files[i] = Glib::wrap(files[i], true);
  }

  const auto hint_str = hint ? hint : Glib::ustring();

  // Do not try to call a signal on a disassociated wrapper.
  if (Glib::ObjectBase::_get_current_wrapper((GObject*)self))
  {
    try
    {
      if (const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
      {
        (*static_cast<SlotType*>(slot))(vec_files, hint_str);
        return;
      }
    }
    catch (...)
    {
      Glib::exception_handlers_invoke();
    }
  }

  return;
}

auto Application_signal_open_notify_callback (
  GApplication *self, GFile **files, const gint n_files, const gchar *hint, void *data) -> void
{
  using namespace Gio;
  using SlotType = sigc::slot<void(const Application::type_vec_files&, const Glib::ustring&)>;

  Application::type_vec_files vec_files(n_files);
  for (int i = 0; i < n_files; i++)
  {
    vec_files[i] = Glib::wrap(files[i], true);
  }

  const auto hint_str = hint ? hint : Glib::ustring();

  // Do not try to call a signal on a disassociated wrapper.
  if (Glib::ObjectBase::_get_current_wrapper((GObject*)self))
  {
    try
    {
      if (const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
      {
        (*static_cast<SlotType*>(slot))(vec_files, hint_str);
        return;
      }
    }
    catch (...)
    {
      Glib::exception_handlers_invoke();
    }
  }

  return;
}

const Glib::SignalProxyInfo Application_signal_open_info = { "open",
  (GCallback)&Application_signal_open_callback,
  (GCallback)&Application_signal_open_notify_callback };

// The add_main_option_entry*() methods that take a slot parameter are handled
// similarly to the corresponding Glib::OptionGroup::add_entry*() methods.
// There is an important difference: In add_main_option_entry*() we can't pass
// an Application pointer to the used GOptionGroup.
// g_application_add_main_option_entries() creates a GOptionGroup with user_data == nullptr.
// Therefore Application_option_arg_callback() is called with data == nullptr.
// Application_option_arg_callback() does not know which Application instance
// the command-line option belongs to. All Application instances (usually only one)
// share a map, mapping the long command option name to an OptionArgCallbackData.
class OptionArgCallbackData
{
public:
  explicit OptionArgCallbackData(const Gio::Application* application,
    const Glib::ustring& long_name, const gchar short_name,
    const Glib::ustring& description, const Glib::ustring& arg_description,
    const Glib::OptionGroup::SlotOptionArgString& slot)
  :
    application_(application),
    long_name_(g_strdup(long_name.c_str())), // must not be nullptr
    short_name_(short_name),
    description_(g_strdup(c_str_or_nullptr(description))),
    arg_description_(g_strdup(c_str_or_nullptr(arg_description))),
    slot_string_(new Glib::OptionGroup::SlotOptionArgString(slot)),
    slot_filename_(nullptr)
  {
  }

  explicit OptionArgCallbackData(const Gio::Application* application,
    const Glib::ustring& long_name, const gchar short_name,
    const Glib::ustring& description, const Glib::ustring& arg_description,
    const Glib::OptionGroup::SlotOptionArgFilename& slot)
  :
    application_(application),
    long_name_(g_strdup(long_name.c_str())), // must not be nullptr
    short_name_(short_name),
    description_(g_strdup(c_str_or_nullptr(description))),
    arg_description_(g_strdup(c_str_or_nullptr(arg_description))),
    slot_string_(nullptr),
    slot_filename_(new Glib::OptionGroup::SlotOptionArgFilename(slot))
  {
  }

  auto get_application() const -> const Gio::Application* { return application_; }
  auto get_long_name() const -> const gchar* { return long_name_; }
  auto get_short_name() const -> gchar { return short_name_; }
  auto get_description() const -> const gchar* { return description_; }
  auto get_arg_description() const -> const gchar* { return arg_description_; }
  auto is_filename_option() const -> bool { return slot_filename_ != nullptr; }

  auto get_slot_string() const -> const Glib::OptionGroup::SlotOptionArgString* { return slot_string_; }

  auto get_slot_filename() const -> const Glib::OptionGroup::SlotOptionArgFilename*
  {
    return slot_filename_;
  }

  ~OptionArgCallbackData()
  {
    g_free(long_name_);
    g_free(description_);
    g_free(arg_description_);
    delete slot_string_;
    delete slot_filename_;
    // Don't delete application_. It's not owned by this class.
  }

private:
  const Gio::Application* application_;
  gchar* long_name_;
  gchar short_name_;
  gchar* description_;
  gchar* arg_description_;
  // One of these slot pointers is nullptr and the other one points to a slot.
  Glib::OptionGroup::SlotOptionArgString* slot_string_;
  Glib::OptionGroup::SlotOptionArgFilename* slot_filename_;

  // Not copyable
  OptionArgCallbackData(const OptionArgCallbackData&) = delete;
  auto operator=(const OptionArgCallbackData&) -> OptionArgCallbackData& = delete;

}; // end class OptionArgCallbackData

using OptionArgCallbackDataMap = std::map<Glib::ustring, OptionArgCallbackData*>;
OptionArgCallbackDataMap option_arg_callback_data;

// Gio::Application instances may be used in different threads.
// Accesses to option_arg_callback_data must be thread-safe.
std::mutex option_arg_callback_data_mutex;

auto
Application_option_arg_callback(
  const gchar* option_name, const gchar* value, gpointer /* data */, GError** error) -> gboolean
{
  const Glib::ustring cpp_option_name(option_name);

  // option_name is either a single dash followed by a single letter (for a
  // short name) or two dashes followed by a long option name.
  std::unique_lock<std::mutex> lock(option_arg_callback_data_mutex);
  OptionArgCallbackDataMap::const_iterator iterFind = option_arg_callback_data.end();
  if (option_name[1] == '-')
  {
    // Long option name.
    const auto long_option_name = Glib::ustring(option_name + 2);
    iterFind = option_arg_callback_data.find(long_option_name);
  }
  else
  {
    // Short option name.
    const auto short_option_name = option_name[1];
    for (iterFind = option_arg_callback_data.begin(); iterFind != option_arg_callback_data.end();
         ++iterFind)
    {
      if (iterFind->second->get_short_name() == short_option_name)
        break;
    }
  }

  if (iterFind == option_arg_callback_data.end())
  {
    Glib::OptionError(Glib::OptionError::UNKNOWN_OPTION, "Application_option_arg_callback(): "
                                                         "Unknown option " +
                                                           cpp_option_name)
      .propagate(error);
    return false;
  }

  const bool has_value = value != nullptr;
  const OptionArgCallbackData* const option_arg = iterFind->second;
  try
  {
    if (option_arg->is_filename_option())
    {
      const auto the_slot = option_arg->get_slot_filename();
      lock.unlock();
      const std::string cpp_value(value ? value : "");
      return (*the_slot)(cpp_option_name, cpp_value, has_value);
    }
    else
    {
      const auto the_slot = option_arg->get_slot_string();
      lock.unlock();
      const Glib::ustring cpp_value(value ? value : "");
      return (*the_slot)(cpp_option_name, cpp_value, has_value);
    }
  }
  catch (Glib::Error& err)
  {
    err.propagate(error);
  }
  catch (...)
  {
    Glib::exception_handlers_invoke();
  }
  return false;
}

} // anonymous namespace

namespace Gio
{

auto
Application::custom_class_init() -> const Glib::Class&
{
  Glib::init();
  init();
  return application_class_.init();
}

Application::Application(const Glib::ustring& application_id, const Flags flags)
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  // GApplication complains about "" but allows nullptr, so we avoid passing "".
ObjectBase(nullptr),
Object(Glib::ConstructParams(custom_class_init(),
                             "application_id", c_str_or_nullptr(application_id),
                             "flags", flags, nullptr))
{
}

Application::~Application() noexcept
{
  // Delete all OptionArgCallbackData instances that belong to this application.
  std::lock_guard<std::mutex> lock(option_arg_callback_data_mutex);
  OptionArgCallbackDataMap::iterator iter = option_arg_callback_data.begin();
  while (iter != option_arg_callback_data.end())
  {
    const OptionArgCallbackDataMap::iterator saved_iter = iter;
    ++iter;
    if (saved_iter->second->get_application() == this)
    {
      delete saved_iter->second;
      option_arg_callback_data.erase(saved_iter);
    }
  }
}

// static
auto Application::unset_default () -> void
{
  g_application_set_default(nullptr);
}

auto Application_Class::open_callback (
  GApplication *self, GFile **files, const gint n_files, const gchar *hint) -> void
{
  const auto obj_base =
    Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:

  if (obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if (obj) // This can be nullptr during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        Application::type_vec_files vec_files(n_files);
        for (int i = 0; i < n_files; i++)
        {
          vec_files[i] = Glib::wrap(files[i], true);
        }

        const auto hint_str = hint ? hint : Glib::ustring();

        obj->on_open(vec_files, hint_str);
        return;
      }
      catch (...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(g_type_class_peek_parent(G_OBJECT_GET_CLASS(
    self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if (base && base->open)
    (*base->open)(self, files, n_files, hint);
}

auto
Application::signal_open() -> Glib::SignalProxy<void(const type_vec_files &, const Glib::ustring&)>
{
  return {this, &Application_signal_open_info};
}

auto Application::on_open (
  const type_vec_files &files, const Glib::ustring &hint) -> void
{
  const auto base = static_cast<BaseClassType*>(g_type_class_peek_parent(G_OBJECT_GET_CLASS(
    gobject_)) // Get the parent class of the object class (The original underlying C class).
    );

  if (base && base->open)
  {
    (*base->open)(gobj(),
      Glib::ArrayHandler<type_vec_files::value_type>::vector_to_array(files).data(), files.size(),
      hint.c_str());
  }
}

auto Application::open (const type_vec_files &files, const Glib::ustring &hint) -> void
{
  g_application_open(gobj(),
    Glib::ArrayHandler<type_vec_files::value_type>::vector_to_array(files).data(), files.size(),
    hint.c_str());
}

auto Application::open (const Glib::RefPtr <File> &file, const Glib::ustring &hint) -> void
{
  type_vec_files files(1);
  files[0] = file;
  open(files, hint);
}

auto Application::add_main_option_entry (
  OptionType arg_type, const Glib::ustring &long_name, const gchar short_name, const Glib::ustring &description, const Glib::ustring &arg_description,
  Glib::OptionEntry::Flags flags) -> void
{
  // g_application_add_main_option() saves copies of the strings.
  // No need to keep copies in Gio::Application.
  g_application_add_main_option(gobj(), long_name.c_str(), short_name,
    static_cast<GOptionFlags>(flags), static_cast<GOptionArg>(arg_type),
    description.c_str(), c_str_or_nullptr(arg_description));
}

auto Application::add_main_option_entry (
  const Glib::OptionGroup::SlotOptionArgString &slot,
  const Glib::ustring &long_name, const gchar short_name, const Glib::ustring &description,
  const Glib::ustring &arg_description, const Glib::OptionEntry::Flags flags) -> void
{
  OptionArgCallbackData* callback_data = nullptr;
  {
    std::lock_guard<std::mutex> lock(option_arg_callback_data_mutex);
    const OptionArgCallbackDataMap::iterator iterFind = option_arg_callback_data.find(long_name);
    if (iterFind != option_arg_callback_data.end())
      return; // Ignore duplicates

    callback_data = new OptionArgCallbackData(
      this, long_name, short_name, description, arg_description, slot);
    option_arg_callback_data[long_name] = callback_data;
  } // option_arg_callback_data_mutex.unlock()

  add_main_option_entry_private(callback_data->get_long_name(), short_name,
    callback_data->get_description(), callback_data->get_arg_description(),
    flags & ~Glib::OptionEntry::Flags::FILENAME);
}

auto Application::add_main_option_entry_filename (
  const Glib::OptionGroup::SlotOptionArgFilename &slot,
  const Glib::ustring &long_name, const gchar short_name, const Glib::ustring &description,
  const Glib::ustring &arg_description, const Glib::OptionEntry::Flags flags) -> void
{
  OptionArgCallbackData* callback_data = nullptr;
  {
    std::lock_guard<std::mutex> lock(option_arg_callback_data_mutex);
    const OptionArgCallbackDataMap::iterator iterFind = option_arg_callback_data.find(long_name);
    if (iterFind != option_arg_callback_data.end())
      return; // Ignore duplicates

    callback_data = new OptionArgCallbackData(
      this, long_name, short_name, description, arg_description, slot);
    option_arg_callback_data[long_name] = callback_data;
  } // option_arg_callback_data_mutex.unlock()

  add_main_option_entry_private(callback_data->get_long_name(), short_name,
    callback_data->get_description(), callback_data->get_arg_description(),
    flags | Glib::OptionEntry::Flags::FILENAME);
}

auto Application::add_main_option_entry_private (
  const gchar *long_name, const gchar short_name, const gchar *description,
  const gchar *arg_description, Glib::OptionEntry::Flags flags) -> void
{
  // g_application_add_main_option() can't be used for options with
  // a callback slot, because GOptionEntry.arg_data must be non-null.

  // Create a temporary array, just so we can give the correct thing to
  // g_application_add_main_option_entries():
  GOptionEntry array[2];
  std::memset(array, 0, 2 * sizeof(GOptionEntry)); // null-termination

  // g_application_add_main_option_entries() does not take its own copy
  // of the strings. We must keep them alive, and keep pointers to them,
  // so we can delete them when the Application instance is deleted.
  // This is handled in OptionArgCallbackData.

  // Fill in array[0].
  array[0].arg = G_OPTION_ARG_CALLBACK;
  array[0].long_name = long_name;
  array[0].short_name = short_name;
  array[0].description = description;
  array[0].arg_description = arg_description;
  array[0].flags = static_cast<int>(flags);

  // GoptionEntry.arg_data is a function pointer, cast to void*.
  // See Glib::OptionGroup::CppOptionEntry::allocate_c_arg() for a discussion
  // of this hack.
  union {
    void* dp;
    GOptionArgFunc fp;
  } u;
  u.fp = &Application_option_arg_callback;
  array[0].arg_data = u.dp;

  g_application_add_main_option_entries(gobj(), array);
}

auto Application::unset_resource_base_path () -> void
{
  g_application_set_resource_base_path(gobj(), nullptr /* see the C docs. */);
}

} // namespace Gio

namespace
{


const Glib::SignalProxyInfo Application_signal_startup_info =
{
  "startup",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


const Glib::SignalProxyInfo Application_signal_shutdown_info =
{
  "shutdown",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


const Glib::SignalProxyInfo Application_signal_activate_info =
{
  "activate",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


auto Application_signal_command_line_callback(GApplication* self, GApplicationCommandLine* p0,void* data) -> gint
{
  using namespace Gio;
  using SlotType = sigc::slot<int(const Glib::RefPtr<ApplicationCommandLine>&)>;

  const auto obj = dynamic_cast<Application*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

  using RType = gint;
  return RType();
}

auto Application_signal_command_line_notify_callback(GApplication* self, GApplicationCommandLine* p0, void* data) -> gint
{
  using namespace Gio;
  using SlotType = sigc::slot<void(const Glib::RefPtr<ApplicationCommandLine>&)>;

  const auto obj = dynamic_cast<Application*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

  using RType = gint;
  return RType();
}

const Glib::SignalProxyInfo Application_signal_command_line_info =
{
  "command-line",
  (GCallback) &Application_signal_command_line_callback,
  (GCallback) &Application_signal_command_line_notify_callback
};


auto Application_signal_handle_local_options_callback(GApplication* self, GVariantDict* p0,void* data) -> gint
{
  using namespace Gio;
  using SlotType = sigc::slot<int(const Glib::RefPtr<Glib::VariantDict>&)>;

  const auto obj = dynamic_cast<Application*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

  using RType = gint;
  return RType();
}

auto Application_signal_handle_local_options_notify_callback(GApplication* self, GVariantDict* p0, void* data) -> gint
{
  using namespace Gio;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Glib::VariantDict>&)>;

  const auto obj = dynamic_cast<Application*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

  using RType = gint;
  return RType();
}

const Glib::SignalProxyInfo Application_signal_handle_local_options_info =
{
  "handle-local-options",
  (GCallback) &Application_signal_handle_local_options_callback,
  (GCallback) &Application_signal_handle_local_options_notify_callback
};


auto Application_signal_name_lost_callback(GApplication* self, void* data) -> gboolean
{
  using namespace Gio;
  using SlotType = sigc::slot<bool()>;

  const auto obj = dynamic_cast<Application*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        return (*static_cast<SlotType*>(slot))();
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }

  using RType = gboolean;
  return RType();
}

auto Application_signal_name_lost_notify_callback(GApplication* self,  void* data) -> gboolean
{
  using namespace Gio;
  using SlotType = sigc::slot<void()>;

  const auto obj = dynamic_cast<Application*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

  using RType = gboolean;
  return RType();
}

const Glib::SignalProxyInfo Application_signal_name_lost_info =
{
  "name-lost",
  (GCallback) &Application_signal_name_lost_callback,
  (GCallback) &Application_signal_name_lost_notify_callback
};


} // anonymous namespace

// static
auto Glib::Value<Gio::Application::Flags>::value_type() -> GType
{
  return g_application_flags_get_type();
}


namespace Glib
{

auto wrap(GApplication* object, const bool take_copy) -> RefPtr<Gio::Application>
{
  return Glib::make_refptr_for_instance<Gio::Application>( dynamic_cast<Gio::Application*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto Application_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Application_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_application_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  ActionGroup::add_interface(get_type());
  ActionMap::add_interface(get_type());

  }

  return *this;
}


auto Application_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

  klass->local_command_line = &local_command_line_vfunc_callback;
  klass->before_emit = &before_emit_vfunc_callback;
  klass->after_emit = &after_emit_vfunc_callback;
  klass->quit_mainloop = &quit_mainloop_vfunc_callback;
  klass->run_mainloop = &run_mainloop_vfunc_callback;
  klass->dbus_register = &dbus_register_vfunc_callback;
  klass->dbus_unregister = &dbus_unregister_vfunc_callback;

  klass->startup = &startup_callback;
  klass->shutdown = &shutdown_callback;
  klass->activate = &activate_callback;
  klass->command_line = &command_line_callback;
  klass->handle_local_options = &handle_local_options_callback;
  klass->name_lost = &name_lost_callback;
  klass->open = &open_callback;
  }

auto Application_Class::local_command_line_vfunc_callback(GApplication* self, gchar*** arguments, int* exit_status) -> gboolean
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
        return obj->local_command_line_vfunc(*arguments
                                             , *exit_status
        );
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->local_command_line)
    return (*base->local_command_line)(self, arguments, exit_status);

  using RType = gboolean;
  return RType();
}
auto Application_Class::before_emit_vfunc_callback (
  GApplication *self, GVariant *platform_data) -> void
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
        obj->before_emit_vfunc(Glib::wrap(platform_data,true)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->before_emit)
    (*base->before_emit)(self, platform_data);
}
auto Application_Class::after_emit_vfunc_callback (
  GApplication *self, GVariant *platform_data) -> void
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
        obj->after_emit_vfunc(Glib::wrap(platform_data,true)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->after_emit)
    (*base->after_emit)(self, platform_data);
}
auto Application_Class::quit_mainloop_vfunc_callback (GApplication *self) -> void
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
        obj->quit_mainloop_vfunc();
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->quit_mainloop)
    (*base->quit_mainloop)(self);
}
auto Application_Class::run_mainloop_vfunc_callback (GApplication *self) -> void
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
        obj->run_mainloop_vfunc();
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->run_mainloop)
    (*base->run_mainloop)(self);
}
auto Application_Class::dbus_register_vfunc_callback(GApplication* self, GDBusConnection* connection, const gchar* object_path, GError** error) -> gboolean
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
        return obj->dbus_register_vfunc(Glib::wrap(connection, true)
                                        , Glib::convert_const_gchar_ptr_to_ustring(object_path)
        );
      }
      catch(Glib::Error& errormm)
      {
        errormm.propagate(error);
        using RType = gboolean;
        return RType();
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->dbus_register)
    return (*base->dbus_register)(self, connection, object_path, error);

  using RType = gboolean;
  return RType();
}
auto Application_Class::dbus_unregister_vfunc_callback (
  GApplication *self, GDBusConnection *connection, const gchar *object_path) -> void
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
        obj->dbus_unregister_vfunc(Glib::wrap(connection, true)
, Glib::convert_const_gchar_ptr_to_ustring(object_path)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->dbus_unregister)
    (*base->dbus_unregister)(self, connection, object_path);
}

auto Application_Class::startup_callback (GApplication *self) -> void
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
        obj->on_startup();
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
  if(base && base->startup)
    (*base->startup)(self);
}
auto Application_Class::shutdown_callback (GApplication *self) -> void
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
        obj->on_shutdown();
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
  if(base && base->shutdown)
    (*base->shutdown)(self);
}
auto Application_Class::activate_callback (GApplication *self) -> void
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
        obj->on_activate();
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
  if(base && base->activate)
    (*base->activate)(self);
}
auto Application_Class::command_line_callback(GApplication* self, GApplicationCommandLine* p0) -> gint
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
        return obj->on_command_line(Glib::wrap(p0, true)
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
  if(base && base->command_line)
    return (*base->command_line)(self, p0);

  using RType = gint;
  return RType();
}
auto Application_Class::handle_local_options_callback(GApplication* self, GVariantDict* p0) -> gint
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
        return obj->on_handle_local_options(Glib::wrap(p0, true)
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
  if(base && base->handle_local_options)
    return (*base->handle_local_options)(self, p0);

  using RType = gint;
  return RType();
}
auto Application_Class::name_lost_callback(GApplication* self) -> gboolean
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
        return obj->on_name_lost();
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
  if(base && base->name_lost)
    return (*base->name_lost)(self);

  using RType = gboolean;
  return RType();
}


auto Application_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Application((GApplication*)object);
}


/* The implementation: */

auto Application::gobj_copy() -> GApplication*
{
  reference();
  return gobj();
}

Application::Application(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

Application::Application(GApplication* castitem)
: Object((GObject*)castitem)
{}


Application::Application(Application&& src) noexcept
: Object(std::move(src))
  , ActionGroup(std::move(src))
  , ActionMap(std::move(src))
{}

auto Application::operator=(Application&& src) noexcept -> Application&
{
  Object::operator=(std::move(src));
  ActionGroup::operator=(std::move(src));
  ActionMap::operator=(std::move(src));
  return *this;
}


Application::CppClassType Application::application_class_; // initialize static member

auto Application::get_type() -> GType
{
  return application_class_.init().get_type();
}


auto Application::get_base_type() -> GType
{
  return g_application_get_type();
}


auto Application::create(const Glib::ustring& application_id, const Flags flags) -> Glib::RefPtr<Application>
{
  return Glib::make_refptr_for_instance<Application>( new Application(application_id, flags) );
}

auto Application::id_is_valid(const Glib::ustring& application_id) -> bool
{
  return g_application_id_is_valid(application_id.c_str());
}

auto Application::get_id() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_application_get_application_id(const_cast<GApplication*>(gobj())));
}

auto Application::set_id (const Glib::ustring &application_id) -> void
{
  g_application_set_application_id(gobj(), application_id.c_str());
}

auto Application::get_dbus_connection() -> Glib::RefPtr<DBus::Connection>
{
  auto retvalue = Glib::wrap(g_application_get_dbus_connection(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Application::get_dbus_connection() const -> Glib::RefPtr<const DBus::Connection>
{
  return const_cast<Application*>(this)->get_dbus_connection();
}

auto Application::get_dbus_object_path() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_application_get_dbus_object_path(const_cast<GApplication*>(gobj())));
}

auto Application::get_inactivity_timeout() const -> guint
{
  return g_application_get_inactivity_timeout(const_cast<GApplication*>(gobj()));
}

auto Application::set_inactivity_timeout (
  const guint inactivity_timeout) -> void
{
  g_application_set_inactivity_timeout(gobj(), inactivity_timeout);
}

auto Application::get_flags() const -> Flags
{
  return static_cast<Flags>(g_application_get_flags(const_cast<GApplication*>(gobj())));
}

auto Application::set_flags (Flags flags) -> void
{
  g_application_set_flags(gobj(), static_cast<GApplicationFlags>(flags));
}

auto Application::get_resource_base_path() const -> std::string
{
  return Glib::convert_const_gchar_ptr_to_stdstring(g_application_get_resource_base_path(const_cast<GApplication*>(gobj())));
}

auto Application::set_resource_base_path (const std::string &resource_path) -> void
{
  g_application_set_resource_base_path(gobj(), resource_path.c_str());
}

auto Application::add_option_group (Glib::OptionGroup &group) -> void
{
  g_application_add_option_group(gobj(), group.gobj_copy());
}

auto Application::set_option_context_parameter_string (
  const Glib::ustring &parameter_string) -> void
{
  g_application_set_option_context_parameter_string(gobj(), parameter_string.empty() ? nullptr : parameter_string.c_str());
}

auto Application::set_option_context_summary (const Glib::ustring &summary) -> void
{
  g_application_set_option_context_summary(gobj(), summary.empty() ? nullptr : summary.c_str());
}

auto Application::set_option_context_description (const Glib::ustring &description) -> void
{
  g_application_set_option_context_description(gobj(), description.empty() ? nullptr : description.c_str());
}

auto Application::is_registered() const -> bool
{
  return g_application_get_is_registered(const_cast<GApplication*>(gobj()));
}

auto Application::is_remote() const -> bool
{
  return g_application_get_is_remote(const_cast<GApplication*>(gobj()));
}

auto Application::register_application(const Glib::RefPtr<Cancellable>& cancellable) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_application_register(gobj(), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Application::register_application() -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_application_register(gobj(), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Application::hold () -> void
{
  g_application_hold(gobj());
}

auto Application::release () -> void
{
  g_application_release(gobj());
}

auto Application::activate () -> void
{
  g_application_activate(gobj());
}

auto Application::run(
  const int argc, char** argv) -> int
{
  return g_application_run(gobj(), argc, argv);
}

auto Application::quit () -> void
{
  g_application_quit(gobj());
}

auto Application::set_default (const Glib::RefPtr <Application> &application) -> void
{
  g_application_set_default(Glib::unwrap(application));
}

auto Application::get_default() -> Glib::RefPtr<Application>
{

  auto retvalue = Glib::wrap(g_application_get_default());
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us
  return retvalue;
}

auto Application::mark_busy () -> void
{
  g_application_mark_busy(gobj());
}

auto Application::unmark_busy () -> void
{
  g_application_unmark_busy(gobj());
}

auto Application::get_is_busy() const -> bool
{
  return g_application_get_is_busy(const_cast<GApplication*>(gobj()));
}

auto Application::send_notification (
  const Glib::ustring &id, const Glib::RefPtr <Notification> &notification) -> void
{
  g_application_send_notification(gobj(), id.empty() ? nullptr : id.c_str(), Glib::unwrap(notification));
}

auto Application::send_notification (const Glib::RefPtr <Notification> &notification) -> void
{
  g_application_send_notification(gobj(), nullptr, Glib::unwrap(notification));
}

auto Application::withdraw_notification (const Glib::ustring &id) -> void
{
  g_application_withdraw_notification(gobj(), id.c_str());
}


auto Application::signal_startup() -> Glib::SignalProxy<void()>
{
  return {this, &Application_signal_startup_info};
}


auto Application::signal_shutdown() -> Glib::SignalProxy<void()>
{
  return {this, &Application_signal_shutdown_info};
}


auto Application::signal_activate() -> Glib::SignalProxy<void()>
{
  return {this, &Application_signal_activate_info};
}


auto Application::signal_command_line() -> Glib::SignalProxy<int(const Glib::RefPtr<ApplicationCommandLine>&)>
{
  return {this, &Application_signal_command_line_info};
}


auto Application::signal_handle_local_options() -> Glib::SignalProxy<int(const Glib::RefPtr<Glib::VariantDict>&)>
{
  return {this, &Application_signal_handle_local_options_info};
}


auto Application::signal_name_lost() -> Glib::SignalProxy<bool()>
{
  return {this, &Application_signal_name_lost_info};
}


auto Application::property_application_id() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "application-id"};
}

auto Application::property_application_id() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "application-id"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Flags>::value,
  "Type Flags cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Application::property_flags() -> Glib::PropertyProxy< Flags >
{
  return {this, "flags"};
}

auto Application::property_flags() const -> Glib::PropertyProxy_ReadOnly< Flags >
{
  return {this, "flags"};
}

auto Application::property_inactivity_timeout() -> Glib::PropertyProxy< guint >
{
  return {this, "inactivity-timeout"};
}

auto Application::property_inactivity_timeout() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "inactivity-timeout"};
}

auto Application::property_is_registered() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "is-registered"};
}

auto Application::property_is_remote() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "is-remote"};
}

auto Application::property_resource_base_path() -> Glib::PropertyProxy< std::string >
{
  return {this, "resource-base-path"};
}

auto Application::property_resource_base_path() const -> Glib::PropertyProxy_ReadOnly< std::string >
{
  return {this, "resource-base-path"};
}

auto Application::property_is_busy() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "is-busy"};
}


auto Application::on_startup () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->startup)
    (*base->startup)(gobj());
}
auto Application::on_shutdown () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->shutdown)
    (*base->shutdown)(gobj());
}
auto Application::on_activate () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->activate)
    (*base->activate)(gobj());
}
auto Application::on_command_line(const Glib::RefPtr<ApplicationCommandLine>& command_line) -> int
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->command_line)
    return (*base->command_line)(gobj(),Glib::unwrap(command_line));

  using RType = int;
  return RType();
}
auto Application::on_handle_local_options(const Glib::RefPtr<Glib::VariantDict>& options) -> int
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->handle_local_options)
    return (*base->handle_local_options)(gobj(), unwrap(options));

  using RType = int;
  return RType();
}
auto Application::on_name_lost() -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->name_lost)
    return (*base->name_lost)(gobj());

  using RType = bool;
  return RType();
}

auto Application::local_command_line_vfunc(char**& arguments, int& exit_status) -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->local_command_line)
  {
    const bool retval((*base->local_command_line)(gobj(),&arguments,&exit_status));
    return retval;
  }

  using RType = bool;
  return RType();
}
auto Application::before_emit_vfunc (const Glib::VariantBase &platform_data) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->before_emit)
  {
    (*base->before_emit)(gobj(),const_cast<GVariant*>(platform_data.gobj()));
  }
}
auto Application::after_emit_vfunc (const Glib::VariantBase &platform_data) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->after_emit)
  {
    (*base->after_emit)(gobj(),const_cast<GVariant*>(platform_data.gobj()));
  }
}
auto Application::quit_mainloop_vfunc () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->quit_mainloop)
  {
    (*base->quit_mainloop)(gobj());
  }
}
auto Application::run_mainloop_vfunc () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->run_mainloop)
  {
    (*base->run_mainloop)(gobj());
  }
}
auto Application::dbus_register_vfunc(const Glib::RefPtr<DBus::Connection>& connection, const Glib::ustring& object_path) -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->dbus_register)
  {
    GError* gerror = nullptr;
    const bool retval((*base->dbus_register)(gobj(),Glib::unwrap(connection),object_path.c_str(),&gerror));
    if(gerror)
      Glib::Error::throw_exception(gerror);
    return retval;
  }

  using RType = bool;
  return RType();
}
auto Application::dbus_unregister_vfunc (
  const Glib::RefPtr <DBus::Connection> &connection, const Glib::ustring &object_path) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->dbus_unregister)
  {
    (*base->dbus_unregister)(gobj(),Glib::unwrap(connection),object_path.c_str());
  }
}


} // namespace Gio


