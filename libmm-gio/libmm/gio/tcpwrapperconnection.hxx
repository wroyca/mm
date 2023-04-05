// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_TCPWRAPPERCONNECTION_H
#define _GIOMM_TCPWRAPPERCONNECTION_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/tcpconnection.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GTcpWrapperConnection = struct _GTcpWrapperConnection;
using GTcpWrapperConnectionClass = struct _GTcpWrapperConnectionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT TcpWrapperConnection_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT TcpWrapperConnection : public gio::TcpConnection
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = TcpWrapperConnection;
    using CppClassType = TcpWrapperConnection_Class;
    using BaseObjectType = GTcpWrapperConnection;
    using BaseClassType = GTcpWrapperConnectionClass;

    TcpWrapperConnection (const TcpWrapperConnection&) = delete;
    auto
    operator= (const TcpWrapperConnection&) -> TcpWrapperConnection& = delete;

  private:
    friend class TcpWrapperConnection_Class;
    static CppClassType tcpwrapperconnection_class_;

  protected:
    explicit TcpWrapperConnection (
        const glib::ConstructParams& construct_params);
    explicit TcpWrapperConnection (GTcpWrapperConnection* castitem);

#endif

  public:
    TcpWrapperConnection (TcpWrapperConnection&& src) noexcept;
    auto
    operator= (TcpWrapperConnection&& src) noexcept -> TcpWrapperConnection&;

    ~TcpWrapperConnection () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GTcpWrapperConnection*
    {
      return reinterpret_cast<GTcpWrapperConnection*> (gobject_);
    }

    auto
    gobj () const -> const GTcpWrapperConnection*
    {
      return reinterpret_cast<GTcpWrapperConnection*> (gobject_);
    }

    auto
    gobj_copy () -> GTcpWrapperConnection*;

  private:
  public:
    explicit TcpWrapperConnection (const glib::RefPtr<IOStream>& base_io_stream,
                                   const glib::RefPtr<Socket>& socket);

    auto
    get_base_io_stream () -> glib::RefPtr<IOStream>;

    auto
    get_base_io_stream () const -> glib::RefPtr<const IOStream>;

    auto
    property_base_io_stream () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<IOStream>>;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GTcpWrapperConnection* object, bool take_copy = false) -> glib::RefPtr<gio::TcpWrapperConnection>;
} // namespace glib

#endif
