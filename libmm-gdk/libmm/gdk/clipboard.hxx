// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_CLIPBOARD_H
#define _GDKMM_CLIPBOARD_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/contentformats.hxx>
#include <libmm/gdk/contentprovider.hxx>
#include <libmm/gdk/display.hxx>
#include <libmm/gdk/texture.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkClipboard = struct _GdkClipboard;
using GdkClipboardClass = struct _GdkClipboardClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gdk
{
  class LIBMM_GDK_SYMEXPORT Clipboard_Class;
}
#endif

namespace gio
{
  class LIBMM_GDK_SYMEXPORT Cancellable;
  class LIBMM_GDK_SYMEXPORT InputStream;
} // namespace gio

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT Clipboard : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Clipboard;
    using CppClassType = Clipboard_Class;
    using BaseObjectType = GdkClipboard;
    using BaseClassType = GdkClipboardClass;

    Clipboard (const Clipboard&) = delete;
    auto
    operator= (const Clipboard&) -> Clipboard& = delete;

  private:
    friend class Clipboard_Class;
    static CppClassType clipboard_class_;

  protected:
    explicit Clipboard (const glib::ConstructParams& construct_params);
    explicit Clipboard (GdkClipboard* castitem);

#endif

  public:
    Clipboard (Clipboard&& src) noexcept;
    auto
    operator= (Clipboard&& src) noexcept -> Clipboard&;

    ~Clipboard () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkClipboard*
    {
      return reinterpret_cast<GdkClipboard*> (gobject_);
    }

    auto
    gobj () const -> const GdkClipboard*
    {
      return reinterpret_cast<GdkClipboard*> (gobject_);
    }

    auto
    gobj_copy () -> GdkClipboard*;

  private:
  public:
    auto
    get_display () -> glib::RefPtr<Display>;

    auto
    get_display () const -> glib::RefPtr<const Display>;

    auto
    get_formats () -> glib::RefPtr<ContentFormats>;

    auto
    get_formats () const -> glib::RefPtr<const ContentFormats>;

    auto
    is_local () const -> bool;

    auto
    get_content () -> glib::RefPtr<ContentProvider>;

    auto
    get_content () const -> glib::RefPtr<const ContentProvider>;

    auto
    read_async (const std::vector<glib::ustring>& mime_types,
                int io_priority,
                const gio::SlotAsyncReady& slot,
                const glib::RefPtr<gio::Cancellable>& cancellable) -> void;

    auto
    read_async (const std::vector<glib::ustring>& mime_types,
                int io_priority,
                const gio::SlotAsyncReady& slot) -> void;

    auto
    read_finish (const glib::RefPtr<gio::AsyncResult>& result,
                 glib::ustring& out_mime_type)
        -> glib::RefPtr<gio::InputStream>;

    auto
    read_texture_async (const gio::SlotAsyncReady& slot,
                        const glib::RefPtr<gio::Cancellable>& cancellable)
        -> void;

    auto
    read_texture_async (const gio::SlotAsyncReady& slot) -> void;

    auto
    read_texture_finish (const glib::RefPtr<gio::AsyncResult>& result)
        -> glib::RefPtr<Texture>;

    auto
    read_text_async (const gio::SlotAsyncReady& slot,
                     const glib::RefPtr<gio::Cancellable>& cancellable) -> void;

    auto
    read_text_async (const gio::SlotAsyncReady& slot) -> void;

    auto
    read_text_finish (const glib::RefPtr<gio::AsyncResult>& result)
        -> glib::ustring;

    auto
    set_content (const glib::RefPtr<const ContentProvider>& provider) -> bool;

    auto
    unset_content () -> bool;

    auto
    set_text (const glib::ustring& text) -> void;

    auto
    set_texture (const glib::RefPtr<const Texture>& texture) -> void;

    auto
    property_display () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>>;

    auto
    property_formats () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ContentFormats>>;

    auto
    property_local () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_content () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ContentProvider>>;

    auto
    signal_changed () -> glib::SignalProxy<void ()>;

  public:
  public:
  protected:
  };

} // namespace gdk

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkClipboard* object, bool take_copy = false) -> glib::RefPtr<gdk::Clipboard>;
} // namespace glib

#endif
