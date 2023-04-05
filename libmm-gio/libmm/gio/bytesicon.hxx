#ifndef _GIOMM_BYTESICON_H
#define _GIOMM_BYTESICON_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/icon.hxx>
#include <libmm/gio/loadableicon.hxx>
#include <libmm/glib/bytes.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GBytesIcon = struct _GBytesIcon;
using GBytesIconClass = struct _GBytesIconClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT BytesIcon_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT BytesIcon : public glib::Object,
                              public Icon,
                              public LoadableIcon
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = BytesIcon;
    using CppClassType = BytesIcon_Class;
    using BaseObjectType = GBytesIcon;
    using BaseClassType = GBytesIconClass;

    BytesIcon (const BytesIcon&) = delete;
    BytesIcon&
    operator= (const BytesIcon&) = delete;

  private:
    friend class BytesIcon_Class;
    static CppClassType bytesicon_class_;

  protected:
    explicit BytesIcon (const glib::ConstructParams& construct_params);
    explicit BytesIcon (GBytesIcon* castitem);

#endif

  public:
    BytesIcon (BytesIcon&& src) noexcept;
    BytesIcon&
    operator= (BytesIcon&& src) noexcept;

    ~BytesIcon () noexcept override;

    static GType
    get_type () G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static GType
    get_base_type () G_GNUC_CONST;
#endif

    GBytesIcon*
    gobj ()
    {
      return reinterpret_cast<GBytesIcon*> (gobject_);
    }

    const GBytesIcon*
    gobj () const
    {
      return reinterpret_cast<GBytesIcon*> (gobject_);
    }

    GBytesIcon*
    gobj_copy ();

  private:
  protected:
    explicit BytesIcon (const glib::RefPtr<const glib::Bytes>& bytes);

  public:
    static glib::RefPtr<BytesIcon>
    create (const glib::RefPtr<const glib::Bytes>& bytes);

    glib::RefPtr<const glib::Bytes>
    get_bytes () const;

    glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::Bytes>>
    property_bytes () const;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{
  LIBMM_GIO_SYMEXPORT
  glib::RefPtr<gio::BytesIcon>
  wrap (GBytesIcon* object, bool take_copy = false);
} // namespace glib

#endif
