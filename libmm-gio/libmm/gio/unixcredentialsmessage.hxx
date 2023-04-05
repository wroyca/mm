// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_UNIXCREDENTIALSMESSAGE_H
#define _GIOMM_UNIXCREDENTIALSMESSAGE_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/socketcontrolmessage.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GUnixCredentialsMessage = struct _GUnixCredentialsMessage;
using GUnixCredentialsMessageClass = struct _GUnixCredentialsMessageClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT UnixCredentialsMessage_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT Credentials;

  class LIBMM_GIO_SYMEXPORT UnixCredentialsMessage : public SocketControlMessage
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = UnixCredentialsMessage;
    using CppClassType = UnixCredentialsMessage_Class;
    using BaseObjectType = GUnixCredentialsMessage;
    using BaseClassType = GUnixCredentialsMessageClass;

    UnixCredentialsMessage (const UnixCredentialsMessage&) = delete;
    auto
    operator= (const UnixCredentialsMessage&)
        -> UnixCredentialsMessage& = delete;

  private:
    friend class UnixCredentialsMessage_Class;
    static CppClassType unixcredentialsmessage_class_;

  protected:
    explicit UnixCredentialsMessage (
        const glib::ConstructParams& construct_params);
    explicit UnixCredentialsMessage (GUnixCredentialsMessage* castitem);

#endif

  public:
    UnixCredentialsMessage (UnixCredentialsMessage&& src) noexcept;
    auto
    operator= (UnixCredentialsMessage&& src) noexcept
        -> UnixCredentialsMessage&;

    ~UnixCredentialsMessage () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GUnixCredentialsMessage*
    {
      return reinterpret_cast<GUnixCredentialsMessage*> (gobject_);
    }

    auto
    gobj () const -> const GUnixCredentialsMessage*
    {
      return reinterpret_cast<GUnixCredentialsMessage*> (gobject_);
    }

    auto
    gobj_copy () -> GUnixCredentialsMessage*;

  private:
  protected:
    UnixCredentialsMessage ();
    explicit UnixCredentialsMessage (
        const glib::RefPtr<Credentials>& credentials);

  public:
    static auto
    create () -> glib::RefPtr<UnixCredentialsMessage>;

    static auto
    create (const glib::RefPtr<Credentials>& credentials)
        -> glib::RefPtr<UnixCredentialsMessage>;

    auto
    get_credentials () -> glib::RefPtr<Credentials>;

    auto
    get_credentials () const -> glib::RefPtr<const Credentials>;

    static auto
    is_supported () -> bool;

    auto
    property_credentials () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Credentials>>;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GUnixCredentialsMessage* object, bool take_copy = false) -> glib::RefPtr<gio::UnixCredentialsMessage>;
} // namespace glib

#endif
