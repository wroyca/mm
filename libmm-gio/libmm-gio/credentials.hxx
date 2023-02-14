
#ifndef _GIOMM_CREDENTIALS_H
#define _GIOMM_CREDENTIALS_H

#include <libmm-gio/gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GCredentials = struct _GCredentials;
using GCredentialsClass = struct _GCredentialsClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API Credentials_Class;
}
#endif

namespace Gio
{

  class GIOMM_API Credentials : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Credentials;
    using CppClassType = Credentials_Class;
    using BaseObjectType = GCredentials;
    using BaseClassType = GCredentialsClass;

    Credentials (const Credentials&) = delete;
    auto
    operator= (const Credentials&) -> Credentials& = delete;

  private:
    friend class Credentials_Class;
    static CppClassType credentials_class_;

  protected:
    explicit Credentials (const Glib::ConstructParams& construct_params);
    explicit Credentials (GCredentials* castitem);

#endif

  public:
    Credentials (Credentials&& src) noexcept;
    auto
    operator= (Credentials&& src) noexcept -> Credentials&;

    ~Credentials () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GCredentials*
    {
      return reinterpret_cast<GCredentials*> (gobject_);
    }

    auto
    gobj () const -> const GCredentials*
    {
      return reinterpret_cast<GCredentials*> (gobject_);
    }

    auto
    gobj_copy () -> GCredentials*;

  private:
  protected:
    Credentials ();

  public:
    enum class Type
    {
      INVALID,
      LINUX_UCRED,
      FREEBSD_CMSGCRED,
      OPENBSD_SOCKPEERCRED,
      SOLARIS_UCRED,
      NETBSD_UNPCBID,
      APPLE_XUCRED,
      WIN32_PID
    };

    static auto
    create () -> Glib::RefPtr<Credentials>;

    auto
    to_string () const -> Glib::ustring;

    auto
    get_native (Type native_type) -> gpointer;

    void
    set_native (Type native_type, gpointer native);

    auto
    is_same_user (const Glib::RefPtr<const Credentials>& other_credentials)
        -> bool;

#ifdef G_OS_UNIX

    auto
    get_unix_user () -> uid_t;
#endif

#ifdef G_OS_UNIX

    auto
    set_unix_user (uid_t uid) -> bool;
#endif

#ifdef G_OS_UNIX

    auto
    get_unix_pid () const -> pid_t;
#endif

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GCredentials* object, bool take_copy = false) -> Glib::RefPtr<Gio::Credentials>;
} // namespace Glib

#endif
