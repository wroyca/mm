// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSAUTHOBSERVER_H
#define _GIOMM_DBUSAUTHOBSERVER_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/credentials.hxx>
#include <libmm/gio/iostream.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusAuthObserver = struct _GDBusAuthObserver;
using GDBusAuthObserverClass = struct _GDBusAuthObserverClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio::DBus
{
  class LIBMM_GIO_SYMEXPORT AuthObserver_Class;
}
#endif

namespace gio::DBus
{

  class LIBMM_GIO_SYMEXPORT AuthObserver : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = AuthObserver;
    using CppClassType = AuthObserver_Class;
    using BaseObjectType = GDBusAuthObserver;
    using BaseClassType = GDBusAuthObserverClass;

    AuthObserver (const AuthObserver&) = delete;
    auto
    operator= (const AuthObserver&) -> AuthObserver& = delete;

  private:
    friend class AuthObserver_Class;
    static CppClassType authobserver_class_;

  protected:
    explicit AuthObserver (const glib::ConstructParams& construct_params);
    explicit AuthObserver (GDBusAuthObserver* castitem);

#endif

  public:
    AuthObserver (AuthObserver&& src) noexcept;
    auto
    operator= (AuthObserver&& src) noexcept -> AuthObserver&;

    ~AuthObserver () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GDBusAuthObserver*
    {
      return reinterpret_cast<GDBusAuthObserver*> (gobject_);
    }

    auto
    gobj () const -> const GDBusAuthObserver*
    {
      return reinterpret_cast<GDBusAuthObserver*> (gobject_);
    }

    auto
    gobj_copy () -> GDBusAuthObserver*;

  private:
  protected:
    AuthObserver ();

  public:
    static auto
    create () -> glib::RefPtr<AuthObserver>;

    auto
    authorize_authenticated_peer (
        const glib::RefPtr<const IOStream>& stream,
        const glib::RefPtr<const Credentials>& credentials) -> bool;

    auto
    allow_mechanism (const std::string& mechanism) -> bool;

    auto
    signal_authorize_authenticated_peer ()
        -> glib::SignalProxy<bool (const glib::RefPtr<const IOStream>&,
                                   const glib::RefPtr<const Credentials>&)>;

    auto
    signal_allow_mechanism () -> glib::SignalProxy<bool (const std::string&)>;

  public:
  public:
  protected:
  };

} // namespace gio::DBus

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDBusAuthObserver* object, bool take_copy = false) -> glib::RefPtr<gio::DBus::AuthObserver>;
} // namespace glib

#endif
