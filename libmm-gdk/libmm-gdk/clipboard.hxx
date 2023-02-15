// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_CLIPBOARD_H
#define _GDKMM_CLIPBOARD_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/contentformats.hxx>
#include <libmm-gdk/contentprovider.hxx>
#include <libmm-gdk/display.hxx>
#include <libmm-gdk/texture.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkClipboard = struct _GdkClipboard;
using GdkClipboardClass = struct _GdkClipboardClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{
  class GDKMM_API Clipboard_Class;
}
#endif

namespace Gio
{
  class GDKMM_API Cancellable;
  class GDKMM_API InputStream;
} // namespace Gio

namespace Gdk
{

  class GDKMM_API Clipboard : public Glib::Object
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
    explicit Clipboard (const Glib::ConstructParams& construct_params);
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
    get_display () -> Glib::RefPtr<Display>;

    auto
    get_display () const -> Glib::RefPtr<const Display>;

    auto
    get_formats () -> Glib::RefPtr<ContentFormats>;

    auto
    get_formats () const -> Glib::RefPtr<const ContentFormats>;

    auto
    is_local () const -> bool;

    auto
    get_content () -> Glib::RefPtr<ContentProvider>;

    auto
    get_content () const -> Glib::RefPtr<const ContentProvider>;

    auto
    read_async (const std::vector<Glib::ustring>& mime_types,
                int io_priority,
                const Gio::SlotAsyncReady& slot,
                const Glib::RefPtr<Gio::Cancellable>& cancellable) -> void;

    auto
    read_async (const std::vector<Glib::ustring>& mime_types,
                int io_priority,
                const Gio::SlotAsyncReady& slot) -> void;

    auto
    read_finish (const Glib::RefPtr<Gio::AsyncResult>& result,
                 Glib::ustring& out_mime_type)
        -> Glib::RefPtr<Gio::InputStream>;

    auto
    read_texture_async (const Gio::SlotAsyncReady& slot,
                        const Glib::RefPtr<Gio::Cancellable>& cancellable)
        -> void;

    auto
    read_texture_async (const Gio::SlotAsyncReady& slot) -> void;

    auto
    read_texture_finish (const Glib::RefPtr<Gio::AsyncResult>& result)
        -> Glib::RefPtr<Texture>;

    auto
    read_text_async (const Gio::SlotAsyncReady& slot,
                     const Glib::RefPtr<Gio::Cancellable>& cancellable) -> void;

    auto
    read_text_async (const Gio::SlotAsyncReady& slot) -> void;

    auto
    read_text_finish (const Glib::RefPtr<Gio::AsyncResult>& result)
        -> Glib::ustring;

    auto
    set_content (const Glib::RefPtr<const ContentProvider>& provider) -> bool;

    auto
    unset_content () -> bool;

    auto
    set_text (const Glib::ustring& text) -> void;

    auto
    set_texture (const Glib::RefPtr<const Texture>& texture) -> void;

    auto
    property_display () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Display>>;

    auto
    property_formats () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ContentFormats>>;

    auto
    property_local () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_content () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ContentProvider>>;

    auto
    signal_changed () -> Glib::SignalProxy<void ()>;

  public:
  public:
  protected:
  };

} // namespace Gdk

namespace Glib
{
  GDKMM_API auto
  wrap (GdkClipboard* object, bool take_copy = false) -> Glib::RefPtr<Gdk::Clipboard>;
} // namespace Glib

#endif
