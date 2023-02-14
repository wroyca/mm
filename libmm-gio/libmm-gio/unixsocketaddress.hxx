
#ifndef _GIOMM_UNIXSOCKETADDRESS_H
#define _GIOMM_UNIXSOCKETADDRESS_H

#include <libmm-gio/gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/socketaddress.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GUnixSocketAddress = struct _GUnixSocketAddress;
using GUnixSocketAddressClass = struct _GUnixSocketAddressClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API UnixSocketAddress_Class;
}
#endif

namespace Glib
{
  class GLIBMM_API ByteArray;
}

namespace Gio
{

  class GIOMM_API UnixSocketAddress : public SocketAddress
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = UnixSocketAddress;
    using CppClassType = UnixSocketAddress_Class;
    using BaseObjectType = GUnixSocketAddress;
    using BaseClassType = GUnixSocketAddressClass;

    UnixSocketAddress (const UnixSocketAddress&) = delete;
    auto
    operator= (const UnixSocketAddress&) -> UnixSocketAddress& = delete;

  private:
    friend class UnixSocketAddress_Class;
    static CppClassType unixsocketaddress_class_;

  protected:
    explicit UnixSocketAddress (const Glib::ConstructParams& construct_params);
    explicit UnixSocketAddress (GUnixSocketAddress* castitem);

#endif

  public:
    UnixSocketAddress (UnixSocketAddress&& src) noexcept;
    auto
    operator= (UnixSocketAddress&& src) noexcept -> UnixSocketAddress&;

    ~UnixSocketAddress () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GUnixSocketAddress*
    {
      return reinterpret_cast<GUnixSocketAddress*> (gobject_);
    }

    auto
    gobj () const -> const GUnixSocketAddress*
    {
      return reinterpret_cast<GUnixSocketAddress*> (gobject_);
    }

    auto
    gobj_copy () -> GUnixSocketAddress*;

  private:
  public:
    enum class Type
    {
      INVALID,
      ANONYMOUS,
      PATH,
      ABSTRACT,
      ABSTRACT_PADDED
    };

  protected:
    explicit UnixSocketAddress (const std::string& path);

  public:
    static auto
    create (const std::string& path) -> Glib::RefPtr<UnixSocketAddress>;

    static auto
    create (const std::string& path, Type type, int path_len = -1)
        -> Glib::RefPtr<UnixSocketAddress>;

    auto
    get_address_type () const -> Type;

    auto
    get_path () const -> std::string;

    static auto
    abstract_names_supported () -> bool;

    auto
    property_address_type () const -> Glib::PropertyProxy_ReadOnly<Type>;

    auto
    property_path () const -> Glib::PropertyProxy_ReadOnly<std::string>;

    auto
    property_path_as_array () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Glib::ByteArray>>;

  public:
  public:
  protected:
  };

} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GIOMM_API Value<Gio::UnixSocketAddress::Type>
    : public Glib::Value_Enum<Gio::UnixSocketAddress::Type>
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
  wrap (GUnixSocketAddress* object, bool take_copy = false) -> Glib::RefPtr<Gio::UnixSocketAddress>;
} // namespace Glib

#endif
