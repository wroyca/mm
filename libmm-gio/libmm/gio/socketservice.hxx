// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SOCKETSERVICE_H
#define _GIOMM_SOCKETSERVICE_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/socketlistener.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSocketService = struct _GSocketService;
using GSocketServiceClass = struct _GSocketServiceClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT SocketService_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT SocketService : public gio::SocketListener
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = SocketService;
    using CppClassType = SocketService_Class;
    using BaseObjectType = GSocketService;
    using BaseClassType = GSocketServiceClass;

    SocketService (const SocketService&) = delete;
    auto
    operator= (const SocketService&) -> SocketService& = delete;

  private:
    friend class SocketService_Class;
    static CppClassType socketservice_class_;

  protected:
    explicit SocketService (const glib::ConstructParams& construct_params);
    explicit SocketService (GSocketService* castitem);

#endif

  public:
    SocketService (SocketService&& src) noexcept;
    auto
    operator= (SocketService&& src) noexcept -> SocketService&;

    ~SocketService () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GSocketService*
    {
      return reinterpret_cast<GSocketService*> (gobject_);
    }

    auto
    gobj () const -> const GSocketService*
    {
      return reinterpret_cast<GSocketService*> (gobject_);
    }

    auto
    gobj_copy () -> GSocketService*;

  private:
  protected:
    SocketService ();

  public:
    static auto
    create () -> glib::RefPtr<SocketService>;

    auto
    start () -> void;

    auto
    stop () -> void;

    auto
    is_active () -> bool;

    auto
    signal_incoming ()
        -> glib::SignalProxy<bool (const glib::RefPtr<SocketConnection>&,
                                   const glib::RefPtr<glib::Object>&)>;

    auto
    property_active () -> glib::PropertyProxy<bool>;

    auto
    property_active () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
    virtual auto
    on_incoming (const glib::RefPtr<SocketConnection>& connection,
                 const glib::RefPtr<glib::Object>& source_object) -> bool;
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GSocketService* object, bool take_copy = false) -> glib::RefPtr<gio::SocketService>;
} // namespace glib

#endif
