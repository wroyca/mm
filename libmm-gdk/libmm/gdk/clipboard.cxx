// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/clipboard.hxx>
#include <libmm/gdk/clipboard_p.hxx>

#include <libmm/gio/cancellable.hxx>
#include <libmm/gio/inputstream.hxx>
#include <libmm/gio/slot_async.hxx>

namespace gdk
{
  auto
  Clipboard::unset_content () -> bool
  {
    return gdk_clipboard_set_content (gobj (), nullptr);
  }
} // namespace gdk

namespace
{

  static const glib::SignalProxyInfo Clipboard_signal_changed_info = {
      "changed",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

}

namespace glib
{

  auto
  wrap (GdkClipboard* object, bool take_copy) -> glib::RefPtr<gdk::Clipboard>
  {
    return glib::make_refptr_for_instance<gdk::Clipboard> (
        dynamic_cast<gdk::Clipboard*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gdk
{

  auto
  Clipboard_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Clipboard_Class::class_init_function;

      register_derived_type (gdk_clipboard_get_type ());
    }

    return *this;
  }

  auto
  Clipboard_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Clipboard_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Clipboard ((GdkClipboard*) object);
  }

  auto
  Clipboard::gobj_copy () -> GdkClipboard*
  {
    reference ();
    return gobj ();
  }

  Clipboard::Clipboard (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  Clipboard::Clipboard (GdkClipboard* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  Clipboard::Clipboard (Clipboard&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  Clipboard::operator= (Clipboard&& src) noexcept -> Clipboard&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  Clipboard::~Clipboard () noexcept {}

  Clipboard::CppClassType Clipboard::clipboard_class_;

  auto
  Clipboard::get_type () -> GType
  {
    return clipboard_class_.init ().get_type ();
  }

  auto
  Clipboard::get_base_type () -> GType
  {
    return gdk_clipboard_get_type ();
  }

  auto
  Clipboard::get_display () -> glib::RefPtr<Display>
  {
    auto retvalue = glib::wrap (gdk_clipboard_get_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Clipboard::get_display () const -> glib::RefPtr<const Display>
  {
    return const_cast<Clipboard*> (this)->get_display ();
  }

  auto
  Clipboard::get_formats () -> glib::RefPtr<ContentFormats>
  {
    auto retvalue = glib::wrap (gdk_clipboard_get_formats (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Clipboard::get_formats () const -> glib::RefPtr<const ContentFormats>
  {
    return const_cast<Clipboard*> (this)->get_formats ();
  }

  auto
  Clipboard::is_local () const -> bool
  {
    return gdk_clipboard_is_local (const_cast<GdkClipboard*> (gobj ()));
  }

  auto
  Clipboard::get_content () -> glib::RefPtr<ContentProvider>
  {
    auto retvalue = glib::wrap (gdk_clipboard_get_content (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Clipboard::get_content () const -> glib::RefPtr<const ContentProvider>
  {
    return const_cast<Clipboard*> (this)->get_content ();
  }

  auto
  Clipboard::read_async (const std::vector<glib::ustring>& mime_types,
                         int io_priority,
                         const gio::SlotAsyncReady& slot,
                         const glib::RefPtr<gio::Cancellable>& cancellable) -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gdk_clipboard_read_async (
        gobj (),
        glib::ArrayHandler<glib::ustring>::vector_to_array (mime_types).data (),
        io_priority,
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  Clipboard::read_async (const std::vector<glib::ustring>& mime_types,
                         int io_priority,
                         const gio::SlotAsyncReady& slot) -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gdk_clipboard_read_async (
        gobj (),
        glib::ArrayHandler<glib::ustring>::vector_to_array (mime_types).data (),
        io_priority,
        nullptr,
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  Clipboard::read_finish (const glib::RefPtr<gio::AsyncResult>& result,
                          glib::ustring& out_mime_type) -> glib::RefPtr<gio::InputStream>
  {
    GError* gerror = nullptr;
    const char* g_out_mime_type = nullptr;
    auto retvalue =
        glib::wrap (gdk_clipboard_read_finish (gobj (),
                                               glib::unwrap (result),
                                               &g_out_mime_type,
                                               &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    out_mime_type = glib::convert_const_gchar_ptr_to_ustring (g_out_mime_type);
    return retvalue;
  }

  auto
  Clipboard::read_texture_async (
      const gio::SlotAsyncReady& slot,
      const glib::RefPtr<gio::Cancellable>& cancellable) -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gdk_clipboard_read_texture_async (
        gobj (),
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  Clipboard::read_texture_async (const gio::SlotAsyncReady& slot) -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gdk_clipboard_read_texture_async (gobj (),
                                      nullptr,
                                      &gio::SignalProxy_async_callback,
                                      slot_copy);
  }

  auto
  Clipboard::read_texture_finish (const glib::RefPtr<gio::AsyncResult>& result) -> glib::RefPtr<Texture>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::wrap (gdk_clipboard_read_texture_finish (gobj (),
                                                       glib::unwrap (result),
                                                       &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Clipboard::read_text_async (const gio::SlotAsyncReady& slot,
                              const glib::RefPtr<gio::Cancellable>& cancellable) -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gdk_clipboard_read_text_async (
        gobj (),
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  Clipboard::read_text_async (const gio::SlotAsyncReady& slot) -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gdk_clipboard_read_text_async (gobj (),
                                   nullptr,
                                   &gio::SignalProxy_async_callback,
                                   slot_copy);
  }

  auto
  Clipboard::read_text_finish (const glib::RefPtr<gio::AsyncResult>& result) -> glib::ustring
  {
    GError* gerror = nullptr;
    auto retvalue = glib::convert_return_gchar_ptr_to_ustring (
        gdk_clipboard_read_text_finish (gobj (),
                                        glib::unwrap (result),
                                        &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Clipboard::set_content (const glib::RefPtr<const ContentProvider>& provider) -> bool
  {
    return gdk_clipboard_set_content (
        gobj (),
        const_cast<GdkContentProvider*> (glib::unwrap (provider)));
  }

  auto
  Clipboard::set_text (const glib::ustring& text) -> void
  {
    gdk_clipboard_set_text (gobj (), text.c_str ());
  }

  auto
  Clipboard::set_texture (const glib::RefPtr<const Texture>& texture) -> void
  {
    gdk_clipboard_set_texture (
        gobj (),
        const_cast<GdkTexture*> (glib::unwrap (texture)));
  }

  auto
  Clipboard::signal_changed () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &Clipboard_signal_changed_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Display>>::value,
      "Type glib::RefPtr<Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Clipboard::property_display () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>> (this,
                                                                "display");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<ContentFormats>>::value,
      "Type glib::RefPtr<ContentFormats> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Clipboard::property_formats () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ContentFormats>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<ContentFormats>> (
        this,
        "formats");
  }

  auto
  Clipboard::property_local () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "local");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<ContentProvider>>::value,
      "Type glib::RefPtr<ContentProvider> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Clipboard::property_content () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ContentProvider>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<ContentProvider>> (
        this,
        "content");
  }

} // namespace gdk
