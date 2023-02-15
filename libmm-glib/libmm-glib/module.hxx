// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_MODULE_H
#define _GLIBMM_MODULE_H

#include <libmm-glib/mm-glibconfig.hxx>
#include <string>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GModule GModule;
}
#endif

namespace Glib
{

  class LIBMM_GLIB_SYMEXPORT Module
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Module;
    using BaseObjectType = GModule;
#endif

  private:
  public:
    enum class Flags
    {
      LAZY = 1 << 0,
      LOCAL = 1 << 1,
      MASK = 0x03
    };

    explicit Module (const std::string& file_name, Flags flags = Flags (0));

    Module (const Module&) = delete;
    auto
    operator= (const Module&) -> Module& = delete;

    Module (Module&& other) noexcept;
    auto
    operator= (Module&& other) noexcept -> Module&;

    virtual ~Module ();

    explicit operator bool () const;

    static auto
    get_supported () -> bool;

    auto
    make_resident () -> void;

    static auto
    get_last_error () -> std::string;

    auto
    get_symbol (const std::string& symbol_name, void*& symbol) const -> bool;

    auto
    get_name () const -> std::string;

    static auto
    build_path (const std::string& directory, const std::string& module_name)
        -> std::string;

    auto
    gobj () -> GModule*
    {
      return gobject_;
    }

    auto
    gobj () const -> const GModule*
    {
      return gobject_;
    }

  protected:
    GModule* gobject_;
  };

} // namespace Glib

namespace Glib
{

  inline auto
  operator| (Module::Flags lhs, Module::Flags rhs) -> Module::Flags
  {
    return static_cast<Module::Flags> (static_cast<unsigned> (lhs) |
                                       static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (Module::Flags lhs, Module::Flags rhs) -> Module::Flags
  {
    return static_cast<Module::Flags> (static_cast<unsigned> (lhs) &
                                       static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (Module::Flags lhs, Module::Flags rhs) -> Module::Flags
  {
    return static_cast<Module::Flags> (static_cast<unsigned> (lhs) ^
                                       static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(Module::Flags flags) -> Module::Flags
  {
    return static_cast<Module::Flags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (Module::Flags& lhs, Module::Flags rhs) -> Module::Flags&
  {
    return (lhs = static_cast<Module::Flags> (static_cast<unsigned> (lhs) |
                                              static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (Module::Flags& lhs, Module::Flags rhs) -> Module::Flags&
  {
    return (lhs = static_cast<Module::Flags> (static_cast<unsigned> (lhs) &
                                              static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (Module::Flags& lhs, Module::Flags rhs) -> Module::Flags&
  {
    return (lhs = static_cast<Module::Flags> (static_cast<unsigned> (lhs) ^
                                              static_cast<unsigned> (rhs)));
  }
} // namespace Glib

#endif
