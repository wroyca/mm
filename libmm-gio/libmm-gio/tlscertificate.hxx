
#ifndef _GIOMM_TLSCERTIFICATE_H
#define _GIOMM_TLSCERTIFICATE_H

#include <libmm-gio/gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/enums.hxx>
#include <libmm-glib/datetime.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GTlsCertificate = struct _GTlsCertificate;
using GTlsCertificateClass = struct _GTlsCertificateClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API TlsCertificate_Class;
}
#endif

namespace Glib
{

  class GLIBMM_API ByteArray;

}

namespace Gio
{

  class GIOMM_API SocketConnectable;

  class GIOMM_API TlsCertificate : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = TlsCertificate;
    using CppClassType = TlsCertificate_Class;
    using BaseObjectType = GTlsCertificate;
    using BaseClassType = GTlsCertificateClass;

    TlsCertificate (const TlsCertificate&) = delete;
    auto
    operator= (const TlsCertificate&) -> TlsCertificate& = delete;

  private:
    friend class TlsCertificate_Class;
    static CppClassType tlscertificate_class_;

  protected:
    explicit TlsCertificate (const Glib::ConstructParams& construct_params);
    explicit TlsCertificate (GTlsCertificate* castitem);

#endif

  public:
    TlsCertificate (TlsCertificate&& src) noexcept;
    auto
    operator= (TlsCertificate&& src) noexcept -> TlsCertificate&;

    ~TlsCertificate () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GTlsCertificate*
    {
      return reinterpret_cast<GTlsCertificate*> (gobject_);
    }

    auto
    gobj () const -> const GTlsCertificate*
    {
      return reinterpret_cast<GTlsCertificate*> (gobject_);
    }

    auto
    gobj_copy () -> GTlsCertificate*;

  private:
  protected:
    explicit TlsCertificate (const std::string& data, gssize length);

    explicit TlsCertificate (const std::string& file);

    explicit TlsCertificate (const std::string& cert_file,
                             const std::string& key_file);

  public:
    static auto
    create_from_pem (const std::string& data, gssize length = -1)
        -> Glib::RefPtr<TlsCertificate>;

    static auto
    create (const std::string& file) -> Glib::RefPtr<TlsCertificate>;

    static auto
    create (const std::string& cert_file, const std::string& key_file)
        -> Glib::RefPtr<TlsCertificate>;

    static auto
    create_list_from_file (const std::string& file)
        -> std::vector<Glib::RefPtr<TlsCertificate>>;

    auto
    get_issuer () -> Glib::RefPtr<TlsCertificate>;

    auto
    get_issuer () const -> Glib::RefPtr<const TlsCertificate>;

    auto
    verify (const Glib::RefPtr<const SocketConnectable>& identity,
            const Glib::RefPtr<const TlsCertificate>& trusted_ca) const
        -> TlsCertificateFlags;

    auto
    verify (const Glib::RefPtr<const SocketConnectable>& identity) const
        -> TlsCertificateFlags;

    auto
    verify (const Glib::RefPtr<const TlsCertificate>& trusted_ca) const
        -> TlsCertificateFlags;

    auto
    verify () const -> TlsCertificateFlags;

    auto
    is_same (const Glib::RefPtr<const TlsCertificate>& cert_two) const -> bool;

    auto
    get_not_valid_before () const -> Glib::DateTime;

    auto
    get_not_valid_after () const -> Glib::DateTime;

    auto
    get_subject_name () const -> Glib::ustring;

    auto
    get_issuer_name () const -> Glib::ustring;

    auto
    property_certificate () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Glib::ByteArray>>;

    auto
    property_certificate_pem () const
        -> Glib::PropertyProxy_ReadOnly<std::string>;

    auto
    property_private_key () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Glib::ByteArray>>;

    auto
    property_private_key_pem () const
        -> Glib::PropertyProxy_ReadOnly<std::string>;

    auto
    property_issuer () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<TlsCertificate>>;

    auto
    property_pkcs11_uri () const -> Glib::PropertyProxy_ReadOnly<std::string>;

    auto
    property_private_key_pkcs11_uri () const
        -> Glib::PropertyProxy_ReadOnly<std::string>;

    auto
    property_not_valid_before () const
        -> Glib::PropertyProxy_ReadOnly<Glib::DateTime>;

    auto
    property_not_valid_after () const
        -> Glib::PropertyProxy_ReadOnly<Glib::DateTime>;

    auto
    property_subject_name () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_issuer_name () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  protected:
    virtual auto
    verify_vfunc (const Glib::RefPtr<const SocketConnectable>& identity,
                  const Glib::RefPtr<const TlsCertificate>& trusted_ca) const
        -> TlsCertificateFlags;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GTlsCertificate* object, bool take_copy = false) -> Glib::RefPtr<Gio::TlsCertificate>;
} // namespace Glib

#endif
