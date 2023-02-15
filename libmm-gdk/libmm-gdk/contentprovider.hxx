// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_CONTENTPROVIDER_H
#define _GDKMM_CONTENTPROVIDER_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/contentformats.hxx>
#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/cancellable.hxx>
#include <libmm-glib/bytes.hxx>
#include <libmm-glib/object.hxx>
#include <libmm-glib/refptr.hxx>
#include <memory>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkContentProvider = struct _GdkContentProvider;
using GdkContentProviderClass = struct _GdkContentProviderClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{
  class LIBMM_GDK_SYMEXPORT ContentProvider_Class;
}
#endif

namespace Gio
{
  class LIBMM_GDK_SYMEXPORT OutputStream;
}

namespace Gdk
{

  class LIBMM_GDK_SYMEXPORT ContentProvider : public Glib::Object
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
    explicit ContentProvider (const Glib::ConstructParams& construct_params);
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
    create (const Glib::ValueBase& value) -> Glib::RefPtr<ContentProvider>;

    static auto
    create (const std::vector<Glib::RefPtr<ContentProvider>>& providers)
        -> Glib::RefPtr<ContentProvider>;

    static auto
    create (const Glib::ustring& mime_type,
            const Glib::RefPtr<const Glib::Bytes>& bytes)
        -> Glib::RefPtr<ContentProvider>;

    auto
    ref_formats () const -> Glib::RefPtr<ContentFormats>;

    auto
    ref_storable_formats () const -> Glib::RefPtr<ContentFormats>;

    auto
    content_changed () -> void;

    auto
    write_mime_type_async (
        const Glib::ustring& mime_type,
        const Glib::RefPtr<Gio::OutputStream>& stream,
        int io_priority,
        const Gio::SlotAsyncReady& slot,
        const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void;

    auto
    write_mime_type_async (const Glib::ustring& mime_type,
                           const Glib::RefPtr<Gio::OutputStream>& stream,
                           int io_priority,
                           const Gio::SlotAsyncReady& slot) const -> void;

    auto
    write_mime_type_finish (const Glib::RefPtr<Gio::AsyncResult>& result) const
        -> void;

    auto
    get_value (Glib::ValueBase& value) const -> void;

    auto
    property_formats () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ContentFormats>>;

    auto
    property_storable_formats () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ContentFormats>>;

    auto
    signal_content_changed () -> Glib::SignalProxy<void ()>;

  public:
  public:
  protected:
    virtual auto
    on_content_changed () -> void;
  };

} // namespace Gdk

namespace Glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkContentProvider* object, bool take_copy = false) -> Glib::RefPtr<Gdk::ContentProvider>;
} // namespace Glib

#endif
