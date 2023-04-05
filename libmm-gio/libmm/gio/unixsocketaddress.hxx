// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_UNIXSOCKETADDRESS_H
#define _GIOMM_UNIXSOCKETADDRESS_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/socketaddress.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GUnixSocketAddress = struct _GUnixSocketAddress;
using GUnixSocketAddressClass = struct _GUnixSocketAddressClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT UnixSocketAddress_Class;
}
#endif

namespace glib
{
  class LIBMM_GLIB_SYMEXPORT ByteArray;
}

namespace gio
{

  class LIBMM_GIO_SYMEXPORT UnixSocketAddress : public SocketAddress
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
    explicit UnixSocketAddress (const glib::ConstructParams& construct_params);
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
    create (const std::string& path) -> glib::RefPtr<UnixSocketAddress>;

    static auto
    create (const std::string& path, Type type, int path_len = -1)
        -> glib::RefPtr<UnixSocketAddress>;

    auto
    get_address_type () const -> Type;

    auto
    get_path () const -> std::string;

    static auto
    abstract_names_supported () -> bool;

    auto
    property_address_type () const -> glib::PropertyProxy_ReadOnly<Type>;

    auto
    property_path () const -> glib::PropertyProxy_ReadOnly<std::string>;

    auto
    property_path_as_array () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::ByteArray>>;

  public:
  public:
  protected:
  };

} // namespace gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::UnixSocketAddress::Type>
    : public glib::Value_Enum<gio::UnixSocketAddress::Type>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GUnixSocketAddress* object, bool take_copy = false) -> glib::RefPtr<gio::UnixSocketAddress>;
} // namespace glib

#endif
