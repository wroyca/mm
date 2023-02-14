
#ifndef _GIOMM_RESOURCE_H
#define _GIOMM_RESOURCE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/inputstream.hxx>
#include <libmm-glib/bytes.hxx>
#include <libmm-glib/error.hxx>
#include <libmm-glib/refptr.hxx>
#include <string>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GResource GResource;
#endif

namespace Gio
{

  class ResourceError : public Glib::Error
  {
  public:
    enum Code
    {
      NOT_FOUND,
      INTERNAL
    };

    GIOMM_API
    ResourceError (Code error_code, const Glib::ustring& error_message);
    GIOMM_API explicit ResourceError (GError* gobject);
    GIOMM_API auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    GIOMM_API static void
    throw_func (GError* gobject);

    friend GIOMM_API void
    wrap_init ();

#endif
  };

  class GIOMM_API Resource final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Resource;
    using BaseObjectType = GResource;
#endif

    void
    reference () const;

    void
    unreference () const;

    auto
    gobj () -> GResource*;

    auto
    gobj () const -> const GResource*;

    auto
    gobj_copy () const -> GResource*;

    Resource () = delete;

    Resource (const Resource&) = delete;
    auto
    operator= (const Resource&) -> Resource& = delete;

  protected:
    void
    operator delete (void*, std::size_t);

  private:
  public:
    enum class Flags
    {
      NONE = 0x0,
      COMPRESSED = (1 << 0)
    };

    enum class LookupFlags
    {
      NONE = 0x0
    };

    static auto
    create_from_data (const Glib::RefPtr<const Glib::Bytes>& data)
        -> Glib::RefPtr<Resource>;

    static auto
    create_from_file (const std::string& filename) -> Glib::RefPtr<Resource>;

    auto
    open_stream (const std::string& path,
                 LookupFlags lookup_flags = LookupFlags::NONE) const
        -> Glib::RefPtr<InputStream>;

    auto
    lookup_data (const std::string& path,
                 LookupFlags lookup_flags = LookupFlags::NONE) const
        -> Glib::RefPtr<const Glib::Bytes>;

    auto
    enumerate_children (const std::string& path,
                        LookupFlags lookup_flags = LookupFlags::NONE) const
        -> std::vector<std::string>;

    void
    get_info (const std::string& path,
              gsize& size,
              Flags& flags,
              LookupFlags lookup_flags = LookupFlags::NONE) const;

    void
    get_file_exists (const std::string& path,
                     LookupFlags lookup_flags = LookupFlags::NONE) const;

    auto
    get_file_exists_nothrow (const std::string& path,
                             LookupFlags lookup_flags = LookupFlags::NONE) const
        -> bool;

    void
    register_global ();

    void
    unregister_global ();

    static auto
    open_stream_global (const std::string& path,
                        LookupFlags lookup_flags = LookupFlags::NONE)
        -> Glib::RefPtr<InputStream>;

    static auto
    lookup_data_global (const std::string& path,
                        LookupFlags lookup_flags = LookupFlags::NONE)
        -> Glib::RefPtr<const Glib::Bytes>;

    static auto
    enumerate_children_global (const std::string& path,
                               LookupFlags lookup_flags = LookupFlags::NONE)
        -> std::vector<std::string>;

    static void
    get_info_global (const std::string& path,
                     gsize& size,
                     Flags& flags,
                     LookupFlags lookup_flags = LookupFlags::NONE);

    static void
    get_file_exists_global (const std::string& path,
                            LookupFlags lookup_flags = LookupFlags::NONE);

    static auto
    get_file_exists_global_nothrow (
        const std::string& path,
        LookupFlags lookup_flags = LookupFlags::NONE) -> bool;
  };

} // namespace Gio

namespace Gio
{

  inline auto
  operator| (Resource::Flags lhs, Resource::Flags rhs) -> Resource::Flags
  {
    return static_cast<Resource::Flags> (static_cast<unsigned> (lhs) |
                                         static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (Resource::Flags lhs, Resource::Flags rhs) -> Resource::Flags
  {
    return static_cast<Resource::Flags> (static_cast<unsigned> (lhs) &
                                         static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (Resource::Flags lhs, Resource::Flags rhs) -> Resource::Flags
  {
    return static_cast<Resource::Flags> (static_cast<unsigned> (lhs) ^
                                         static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(Resource::Flags flags) -> Resource::Flags
  {
    return static_cast<Resource::Flags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (Resource::Flags& lhs, Resource::Flags rhs) -> Resource::Flags&
  {
    return (lhs = static_cast<Resource::Flags> (static_cast<unsigned> (lhs) |
                                                static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (Resource::Flags& lhs, Resource::Flags rhs) -> Resource::Flags&
  {
    return (lhs = static_cast<Resource::Flags> (static_cast<unsigned> (lhs) &
                                                static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (Resource::Flags& lhs, Resource::Flags rhs) -> Resource::Flags&
  {
    return (lhs = static_cast<Resource::Flags> (static_cast<unsigned> (lhs) ^
                                                static_cast<unsigned> (rhs)));
  }
} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GIOMM_API Value<Gio::Resource::Flags>
    : public Glib::Value_Flags<Gio::Resource::Flags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gio
{

  inline auto
  operator| (Resource::LookupFlags lhs, Resource::LookupFlags rhs) -> Resource::LookupFlags
  {
    return static_cast<Resource::LookupFlags> (static_cast<unsigned> (lhs) |
                                               static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (Resource::LookupFlags lhs, Resource::LookupFlags rhs) -> Resource::LookupFlags
  {
    return static_cast<Resource::LookupFlags> (static_cast<unsigned> (lhs) &
                                               static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (Resource::LookupFlags lhs, Resource::LookupFlags rhs) -> Resource::LookupFlags
  {
    return static_cast<Resource::LookupFlags> (static_cast<unsigned> (lhs) ^
                                               static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(Resource::LookupFlags flags) -> Resource::LookupFlags
  {
    return static_cast<Resource::LookupFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (Resource::LookupFlags& lhs, Resource::LookupFlags rhs) -> Resource::LookupFlags&
  {
    return (lhs = static_cast<Resource::LookupFlags> (
                static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (Resource::LookupFlags& lhs, Resource::LookupFlags rhs) -> Resource::LookupFlags&
  {
    return (lhs = static_cast<Resource::LookupFlags> (
                static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (Resource::LookupFlags& lhs, Resource::LookupFlags rhs) -> Resource::LookupFlags&
  {
    return (lhs = static_cast<Resource::LookupFlags> (
                static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs)));
  }
} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GIOMM_API Value<Gio::Resource::LookupFlags>
    : public Glib::Value_Flags<Gio::Resource::LookupFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{

  GIOMM_API
  auto
  wrap (GResource* object, bool take_copy = false) -> Glib::RefPtr<Gio::Resource>;

} // namespace Glib

#endif
