// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_CONTENTPROVIDER_H
#define _GDKMM_CONTENTPROVIDER_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/contentformats.hxx>
#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/cancellable.hxx>
#include <libmm/glib/bytes.hxx>
#include <libmm/glib/object.hxx>
#include <libmm/glib/refptr.hxx>
#include <memory>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkContentProvider = struct _GdkContentProvider;
using GdkContentProviderClass = struct _GdkContentProviderClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gdk
{
  class LIBMM_GDK_SYMEXPORT ContentProvider_Class;
}
#endif

namespace gio
{
  class LIBMM_GDK_SYMEXPORT OutputStream;
}

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT ContentProvider : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ContentProvider;
    using CppClassType = ContentProvider_Class;
    using BaseObjectType = GdkContentProvider;
    using BaseClassType = GdkContentProviderClass;

    ContentProvider (const ContentProvider&) = delete;
    auto
    operator= (const ContentProvider&) -> ContentProvider& = delete;

  private:
    friend class ContentProvider_Class;
    static CppClassType contentprovider_class_;

  protected:
    explicit ContentProvider (const glib::ConstructParams& construct_params);
    explicit ContentProvider (GdkContentProvider* castitem);

#endif

  public:
    ContentProvider (ContentProvider&& src) noexcept;
    auto
    operator= (ContentProvider&& src) noexcept -> ContentProvider&;

    ~ContentProvider () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkContentProvider*
    {
      return reinterpret_cast<GdkContentProvider*> (gobject_);
    }

    auto
    gobj () const -> const GdkContentProvider*
    {
      return reinterpret_cast<GdkContentProvider*> (gobject_);
    }

    auto
    gobj_copy () -> GdkContentProvider*;

  private:
  protected:
    ContentProvider ();

  public:
    static auto
    create (const glib::ValueBase& value) -> glib::RefPtr<ContentProvider>;

    static auto
    create (const std::vector<glib::RefPtr<ContentProvider>>& providers)
        -> glib::RefPtr<ContentProvider>;

    static auto
    create (const glib::ustring& mime_type,
            const glib::RefPtr<const glib::Bytes>& bytes)
        -> glib::RefPtr<ContentProvider>;

    auto
    ref_formats () const -> glib::RefPtr<ContentFormats>;

    auto
    ref_storable_formats () const -> glib::RefPtr<ContentFormats>;

    auto
    content_changed () -> void;

    auto
    write_mime_type_async (
        const glib::ustring& mime_type,
        const glib::RefPtr<gio::OutputStream>& stream,
        int io_priority,
        const gio::SlotAsyncReady& slot,
        const glib::RefPtr<gio::Cancellable>& cancellable) const -> void;

    auto
    write_mime_type_async (const glib::ustring& mime_type,
                           const glib::RefPtr<gio::OutputStream>& stream,
                           int io_priority,
                           const gio::SlotAsyncReady& slot) const -> void;

    auto
    write_mime_type_finish (const glib::RefPtr<gio::AsyncResult>& result) const
        -> void;

    auto
    get_value (glib::ValueBase& value) const -> void;

    auto
    property_formats () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ContentFormats>>;

    auto
    property_storable_formats () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ContentFormats>>;

    auto
    signal_content_changed () -> glib::SignalProxy<void ()>;

  public:
  public:
  protected:
    virtual auto
    on_content_changed () -> void;
  };

} // namespace gdk

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkContentProvider* object, bool take_copy = false) -> glib::RefPtr<gdk::ContentProvider>;
} // namespace glib

#endif
