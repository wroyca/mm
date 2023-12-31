// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/glib/spawn.hxx>
#include <libmm/glib/spawn_p.hxx>

#include <glib.h>
#include <libmm/glib/exceptionhandler.hxx>
#include <libmm/glib/utility.hxx>

namespace
{

  extern "C"
  {
    static auto
    child_setup_callback (void* user_data) -> void
    {
      try
      {
        (*reinterpret_cast<glib::SlotSpawnChildSetup*> (user_data)) ();
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    static auto
    copy_output_buf (std::string* dest, const char* buf) -> void
    {
      if (dest)
      {
        if (buf)
          *dest = buf;
        else
          dest->erase ();
      }
    }
  }

} // namespace

namespace glib
{

  auto
  spawn_async_with_pipes (const std::string& working_directory,
                          const std::vector<std::string>& argv,
                          const std::vector<std::string>& envp,
                          SpawnFlags flags,
                          const SlotSpawnChildSetup& child_setup,
                          Pid* child_pid,
                          int* standard_input,
                          int* standard_output,
                          int* standard_error) -> void
  {
    const bool setup_slot = !child_setup.empty ();
    auto child_setup_ = child_setup;
    GError* gerror = nullptr;

    g_spawn_async_with_pipes (
        c_str_or_nullptr (working_directory),
        const_cast<char**> (
            ArrayHandler<std::string>::vector_to_array (argv).data ()),
        const_cast<char**> (
            ArrayHandler<std::string>::vector_to_array (envp).data ()),
        static_cast<GSpawnFlags> (unsigned (flags)),
        setup_slot ? &child_setup_callback : nullptr,
        setup_slot ? &child_setup_ : nullptr,
        child_pid,
        standard_input,
        standard_output,
        standard_error,
        &gerror);

    if (gerror)
      Error::throw_exception (gerror);
  }

  auto
  spawn_async_with_pipes (const std::string& working_directory,
                          const std::vector<std::string>& argv,
                          SpawnFlags flags,
                          const SlotSpawnChildSetup& child_setup,
                          Pid* child_pid,
                          int* standard_input,
                          int* standard_output,
                          int* standard_error) -> void
  {
    const bool setup_slot = !child_setup.empty ();
    auto child_setup_ = child_setup;
    GError* gerror = nullptr;

    g_spawn_async_with_pipes (
        c_str_or_nullptr (working_directory),
        const_cast<char**> (
            ArrayHandler<std::string>::vector_to_array (argv).data ()),
        nullptr,
        static_cast<GSpawnFlags> (unsigned (flags)),
        setup_slot ? &child_setup_callback : nullptr,
        setup_slot ? &child_setup_ : nullptr,
        child_pid,
        standard_input,
        standard_output,
        standard_error,
        &gerror);

    if (gerror)
      Error::throw_exception (gerror);
  }

  auto
  spawn_async (const std::string& working_directory,
               const std::vector<std::string>& argv,
               const std::vector<std::string>& envp,
               SpawnFlags flags,
               const SlotSpawnChildSetup& child_setup,
               Pid* child_pid) -> void
  {
    const bool setup_slot = !child_setup.empty ();
    auto child_setup_ = child_setup;
    GError* gerror = nullptr;

    g_spawn_async (
        c_str_or_nullptr (working_directory),
        const_cast<char**> (
            ArrayHandler<std::string>::vector_to_array (argv).data ()),
        const_cast<char**> (
            ArrayHandler<std::string>::vector_to_array (envp).data ()),
        static_cast<GSpawnFlags> (unsigned (flags)),
        setup_slot ? &child_setup_callback : nullptr,
        setup_slot ? &child_setup_ : nullptr,
        child_pid,
        &gerror);

    if (gerror)
      Error::throw_exception (gerror);
  }

  auto
  spawn_async (const std::string& working_directory,
               const std::vector<std::string>& argv,
               SpawnFlags flags,
               const SlotSpawnChildSetup& child_setup,
               Pid* child_pid) -> void
  {
    const bool setup_slot = !child_setup.empty ();
    auto child_setup_ = child_setup;
    GError* gerror = nullptr;

    g_spawn_async (
        c_str_or_nullptr (working_directory),
        const_cast<char**> (
            ArrayHandler<std::string>::vector_to_array (argv).data ()),
        nullptr,
        static_cast<GSpawnFlags> (unsigned (flags)),
        setup_slot ? &child_setup_callback : nullptr,
        setup_slot ? &child_setup_ : nullptr,
        child_pid,
        &gerror);

    if (gerror)
      Error::throw_exception (gerror);
  }

  auto
  spawn_sync (const std::string& working_directory,
              const std::vector<std::string>& argv,
              const std::vector<std::string>& envp,
              SpawnFlags flags,
              const SlotSpawnChildSetup& child_setup,
              std::string* standard_output,
              std::string* standard_error,
              int* wait_status) -> void
  {
    const bool setup_slot = !child_setup.empty ();
    auto child_setup_ = child_setup;

    GError* gerror = nullptr;
    char* pch_buf_standard_output = nullptr;
    char* pch_buf_standard_error = nullptr;
    g_spawn_sync (
        c_str_or_nullptr (working_directory),
        const_cast<char**> (
            ArrayHandler<std::string>::vector_to_array (argv).data ()),
        const_cast<char**> (
            ArrayHandler<std::string>::vector_to_array (envp).data ()),
        static_cast<GSpawnFlags> (unsigned (flags)),
        setup_slot ? &child_setup_callback : nullptr,
        setup_slot ? &child_setup_ : nullptr,
        standard_output ? &pch_buf_standard_output : nullptr,
        standard_error ? &pch_buf_standard_error : nullptr,
        wait_status,
        &gerror);
    const auto buf_standard_output =
        make_unique_ptr_gfree (pch_buf_standard_output);
    const auto buf_standard_error =
        make_unique_ptr_gfree (pch_buf_standard_error);

    if (gerror)
      Error::throw_exception (gerror);

    copy_output_buf (standard_output, buf_standard_output.get ());
    copy_output_buf (standard_error, buf_standard_error.get ());
  }

  auto
  spawn_sync (const std::string& working_directory,
              const std::vector<std::string>& argv,
              SpawnFlags flags,
              const SlotSpawnChildSetup& child_setup,
              std::string* standard_output,
              std::string* standard_error,
              int* wait_status) -> void
  {
    const bool setup_slot = !child_setup.empty ();
    auto child_setup_ = child_setup;

    char* pch_buf_standard_output = nullptr;
    char* pch_buf_standard_error = nullptr;
    GError* gerror = nullptr;

    g_spawn_sync (
        c_str_or_nullptr (working_directory),
        const_cast<char**> (
            ArrayHandler<std::string>::vector_to_array (argv).data ()),
        nullptr,
        static_cast<GSpawnFlags> (unsigned (flags)),
        setup_slot ? &child_setup_callback : nullptr,
        setup_slot ? &child_setup_ : nullptr,
        standard_output ? &pch_buf_standard_output : nullptr,
        standard_error ? &pch_buf_standard_error : nullptr,
        wait_status,
        &gerror);
    const auto buf_standard_output =
        make_unique_ptr_gfree (pch_buf_standard_output);
    const auto buf_standard_error =
        make_unique_ptr_gfree (pch_buf_standard_error);

    if (gerror)
      Error::throw_exception (gerror);

    copy_output_buf (standard_output, buf_standard_output.get ());
    copy_output_buf (standard_error, buf_standard_error.get ());
  }

  auto
  spawn_command_line_async (const std::string& command_line) -> void
  {
    GError* gerror = nullptr;
    g_spawn_command_line_async (command_line.c_str (), &gerror);

    if (gerror)
      Error::throw_exception (gerror);
  }

  auto
  spawn_command_line_sync (const std::string& command_line,
                           std::string* standard_output,
                           std::string* standard_error,
                           int* wait_status) -> void
  {
    char* pch_buf_standard_output = nullptr;
    char* pch_buf_standard_error = nullptr;
    GError* gerror = nullptr;

    g_spawn_command_line_sync (
        command_line.c_str (),
        standard_output ? &pch_buf_standard_output : nullptr,
        standard_error ? &pch_buf_standard_error : nullptr,
        wait_status,
        &gerror);
    const auto buf_standard_output =
        make_unique_ptr_gfree (pch_buf_standard_output);
    const auto buf_standard_error =
        make_unique_ptr_gfree (pch_buf_standard_error);

    if (gerror)
      Error::throw_exception (gerror);

    copy_output_buf (standard_output, buf_standard_output.get ());
    copy_output_buf (standard_error, buf_standard_error.get ());
  }

  auto
  spawn_close_pid (const Pid pid) -> void
  {
    g_spawn_close_pid (pid);
  }

} // namespace glib

namespace
{
}

glib::SpawnError::SpawnError (const Code error_code,
                              const ustring& error_message)
  : Error (G_SPAWN_ERROR, error_code, error_message)
{
}

glib::SpawnError::SpawnError (GError* gobject)
  : Error (gobject)
{
}

auto
glib::SpawnError::code () const -> Code
{
  return static_cast<Code> (Error::code ());
}

auto
glib::SpawnError::throw_func (GError* gobject) -> void
{
  throw SpawnError (gobject);
}
