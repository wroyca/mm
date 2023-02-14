
#ifndef _GLIBMM_SPAWN_H
#define _GLIBMM_SPAWN_H

#include <libmm-glib/error.hxx>
#include <libmm-glib/mm-glibconfig.hxx>
#include <sigc++/sigc++.h>
#include <string>
#include <vector>

namespace Glib
{

  using Pid = GPid;

  enum class SpawnFlags
  {
    DEFAULT = 0x0,
    LEAVE_DESCRIPTORS_OPEN = 1 << 0,
    DO_NOT_REAP_CHILD = 1 << 1,
    SEARCH_PATH = 1 << 2,
    STDOUT_TO_DEV_NULL = 1 << 3,
    STDERR_TO_DEV_NULL = 1 << 4,
    CHILD_INHERITS_STDIN = 1 << 5,
    FILE_AND_ARGV_ZERO = 1 << 6,
    SEARCH_PATH_FROM_ENVP = 1 << 7,
    CLOEXEC_PIPES = 1 << 8,
    CHILD_INHERITS_STDOUT = 1 << 9,
    CHILD_INHERITS_STDERR = 1 << 10,
    STDIN_FROM_DEV_NULL = 1 << 11
  };

  inline auto
  operator| (SpawnFlags lhs, SpawnFlags rhs) -> SpawnFlags
  {
    return static_cast<SpawnFlags> (static_cast<unsigned> (lhs) |
                                    static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (SpawnFlags lhs, SpawnFlags rhs) -> SpawnFlags
  {
    return static_cast<SpawnFlags> (static_cast<unsigned> (lhs) &
                                    static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (SpawnFlags lhs, SpawnFlags rhs) -> SpawnFlags
  {
    return static_cast<SpawnFlags> (static_cast<unsigned> (lhs) ^
                                    static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(SpawnFlags flags) -> SpawnFlags
  {
    return static_cast<SpawnFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (SpawnFlags& lhs, SpawnFlags rhs) -> SpawnFlags&
  {
    return (lhs = static_cast<SpawnFlags> (static_cast<unsigned> (lhs) |
                                           static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (SpawnFlags& lhs, SpawnFlags rhs) -> SpawnFlags&
  {
    return (lhs = static_cast<SpawnFlags> (static_cast<unsigned> (lhs) &
                                           static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (SpawnFlags& lhs, SpawnFlags rhs) -> SpawnFlags&
  {
    return (lhs = static_cast<SpawnFlags> (static_cast<unsigned> (lhs) ^
                                           static_cast<unsigned> (rhs)));
  }

  class SpawnError : public Glib::Error
  {
  public:
    enum Code
    {
      FORK,
      READ,
      CHDIR,
      ACCES,
      PERM,
      TOO_BIG,
      TOOBIG = TOO_BIG,
      NOEXEC,
      NAMETOOLONG,
      NOENT,
      NOMEM,
      NOTDIR,
      LOOP,
      TXTBUSY,
      IO,
      NFILE,
      MFILE,
      INVAL,
      ISDIR,
      LIBBAD,
      FAILED
    };

    GLIBMM_API
    SpawnError (Code error_code, const Glib::ustring& error_message);
    GLIBMM_API explicit SpawnError (GError* gobject);
    GLIBMM_API auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    GLIBMM_API static void
    throw_func (GError* gobject);

    friend GLIBMM_API void
    wrap_init ();

#endif
  };

  using SlotSpawnChildSetup = sigc::slot<void ()>;

  GLIBMM_API
  void
  spawn_async_with_pipes (const std::string& working_directory,
                          const std::vector<std::string>& argv,
                          const std::vector<std::string>& envp,
                          SpawnFlags flags = SpawnFlags::DEFAULT,
                          const SlotSpawnChildSetup& child_setup = {},
                          Pid* child_pid = nullptr,
                          int* standard_input = nullptr,
                          int* standard_output = nullptr,
                          int* standard_error = nullptr);

  GLIBMM_API
  void
  spawn_async_with_pipes (const std::string& working_directory,
                          const std::vector<std::string>& argv,
                          SpawnFlags flags = SpawnFlags::DEFAULT,
                          const SlotSpawnChildSetup& child_setup = {},
                          Pid* child_pid = nullptr,
                          int* standard_input = nullptr,
                          int* standard_output = nullptr,
                          int* standard_error = nullptr);

  GLIBMM_API
  void
  spawn_async (const std::string& working_directory,
               const std::vector<std::string>& argv,
               const std::vector<std::string>& envp,
               SpawnFlags flags = SpawnFlags::DEFAULT,
               const SlotSpawnChildSetup& child_setup = {},
               Pid* child_pid = nullptr);

  GLIBMM_API
  void
  spawn_async (const std::string& working_directory,
               const std::vector<std::string>& argv,
               SpawnFlags flags = SpawnFlags::DEFAULT,
               const SlotSpawnChildSetup& child_setup = {},
               Pid* child_pid = nullptr);

  GLIBMM_API
  void
  spawn_sync (const std::string& working_directory,
              const std::vector<std::string>& argv,
              const std::vector<std::string>& envp,
              SpawnFlags flags = SpawnFlags::DEFAULT,
              const SlotSpawnChildSetup& child_setup = {},
              std::string* standard_output = nullptr,
              std::string* standard_error = nullptr,
              int* wait_status = nullptr);

  GLIBMM_API
  void
  spawn_sync (const std::string& working_directory,
              const std::vector<std::string>& argv,
              SpawnFlags flags = SpawnFlags::DEFAULT,
              const SlotSpawnChildSetup& child_setup = {},
              std::string* standard_output = nullptr,
              std::string* standard_error = nullptr,
              int* wait_status = nullptr);

  GLIBMM_API
  void
  spawn_command_line_async (const std::string& command_line);

  GLIBMM_API
  void
  spawn_command_line_sync (const std::string& command_line,
                           std::string* standard_output = nullptr,
                           std::string* standard_error = nullptr,
                           int* wait_status = nullptr);

  GLIBMM_API
  void
  spawn_close_pid (Pid pid);

} // namespace Glib

#endif
