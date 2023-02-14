
#ifndef _GIOMM_UNIXCREDENTIALSMESSAGE_H
#define _GIOMM_UNIXCREDENTIALSMESSAGE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/socketcontrolmessage.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GUnixCredentialsMessage = struct _GUnixCredentialsMessage;
using GUnixCredentialsMessageClass = struct _GUnixCredentialsMessageClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API UnixCredentialsMessage_Class;
}
#endif

namespace Gio
{

  class GIOMM_API Credentials;

  class GIOMM_API UnixCredentialsMessage : public SocketControlMessage
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
        const Glib::ConstructParams& construct_params);
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
        const Glib::RefPtr<Credentials>& credentials);

  public:
    static auto
    create () -> Glib::RefPtr<UnixCredentialsMessage>;

    static auto
    create (const Glib::RefPtr<Credentials>& credentials)
        -> Glib::RefPtr<UnixCredentialsMessage>;

    auto
    get_credentials () -> Glib::RefPtr<Credentials>;

    auto
    get_credentials () const -> Glib::RefPtr<const Credentials>;

    static auto
    is_supported () -> bool;

    auto
    property_credentials () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Credentials>>;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GUnixCredentialsMessage* object, bool take_copy = false) -> Glib::RefPtr<Gio::UnixCredentialsMessage>;
} // namespace Glib

#endif
