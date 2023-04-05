// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_TLSCERTIFICATE_H
#define _GIOMM_TLSCERTIFICATE_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/enums.hxx>
#include <libmm/glib/datetime.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GTlsCertificate = struct _GTlsCertificate;
using GTlsCertificateClass = struct _GTlsCertificateClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT TlsCertificate_Class;
}
#endif

namespace glib
{

  class LIBMM_GLIB_SYMEXPORT ByteArray;

}

namespace gio
{

  class LIBMM_GIO_SYMEXPORT SocketConnectable;

  class LIBMM_GIO_SYMEXPORT TlsCertificate : public glib::Object
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
    explicit TlsCertificate (const glib::ConstructParams& construct_params);
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
        -> glib::RefPtr<TlsCertificate>;

    static auto
    create (const std::string& file) -> glib::RefPtr<TlsCertificate>;

    static auto
    create (const std::string& cert_file, const std::string& key_file)
        -> glib::RefPtr<TlsCertificate>;

    static auto
    create_list_from_file (const std::string& file)
        -> std::vector<glib::RefPtr<TlsCertificate>>;

    auto
    get_issuer () -> glib::RefPtr<TlsCertificate>;

    auto
    get_issuer () const -> glib::RefPtr<const TlsCertificate>;

    auto
    verify (const glib::RefPtr<const SocketConnectable>& identity,
            const glib::RefPtr<const TlsCertificate>& trusted_ca) const
        -> TlsCertificateFlags;

    auto
    verify (const glib::RefPtr<const SocketConnectable>& identity) const
        -> TlsCertificateFlags;

    auto
    verify (const glib::RefPtr<const TlsCertificate>& trusted_ca) const
        -> TlsCertificateFlags;

    auto
    verify () const -> TlsCertificateFlags;

    auto
    is_same (const glib::RefPtr<const TlsCertificate>& cert_two) const -> bool;

    auto
    get_not_valid_before () const -> glib::DateTime;

    auto
    get_not_valid_after () const -> glib::DateTime;

    auto
    get_subject_name () const -> glib::ustring;

    auto
    get_issuer_name () const -> glib::ustring;

    auto
    property_certificate () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::ByteArray>>;

    auto
    property_certificate_pem () const
        -> glib::PropertyProxy_ReadOnly<std::string>;

    auto
    property_private_key () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::ByteArray>>;

    auto
    property_private_key_pem () const
        -> glib::PropertyProxy_ReadOnly<std::string>;

    auto
    property_issuer () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<TlsCertificate>>;

    auto
    property_pkcs11_uri () const -> glib::PropertyProxy_ReadOnly<std::string>;

    auto
    property_private_key_pkcs11_uri () const
        -> glib::PropertyProxy_ReadOnly<std::string>;

    auto
    property_not_valid_before () const
        -> glib::PropertyProxy_ReadOnly<glib::DateTime>;

    auto
    property_not_valid_after () const
        -> glib::PropertyProxy_ReadOnly<glib::DateTime>;

    auto
    property_subject_name () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_issuer_name () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

  protected:
    virtual auto
    verify_vfunc (const glib::RefPtr<const SocketConnectable>& identity,
                  const glib::RefPtr<const TlsCertificate>& trusted_ca) const
        -> TlsCertificateFlags;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GTlsCertificate* object, bool take_copy = false) -> glib::RefPtr<gio::TlsCertificate>;
} // namespace glib

#endif
