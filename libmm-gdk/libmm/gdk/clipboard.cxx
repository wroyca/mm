// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/clipboard.hxx>
#include <libmm/gdk/clipboard_p.hxx>

#include <libmm/gio/cancellable.hxx>
#include <libmm/gio/inputstream.hxx>
#include <libmm/gio/slot_async.hxx>

namespace Gdk
{
  auto
  Clipboard::unset_content () -> bool
  {
    return gdk_clipboard_set_content (gobj (), nullptr);
  }
} // namespace Gdk

namespace
{

  static const Glib::SignalProxyInfo Clipboard_signal_changed_info = {
      "changed",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

}

namespace Glib
{

  auto
  wrap (GdkClipboard* object, bool take_copy) -> Glib::RefPtr<Gdk::Clipboard>
  {
    return Glib::make_refptr_for_instance<Gdk::Clipboard> (
        dynamic_cast<Gdk::Clipboard*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gdk
{

  auto
  Clipboard_Class::init () -> const Glib::Class&
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
  Clipboard_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Clipboard ((GdkClipboard*) object);
  }

  auto
  Clipboard::gobj_copy () -> GdkClipboard*
  {
    reference ();
    return gobj ();
  }

  Clipboard::Clipboard (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  Clipboard::Clipboard (GdkClipboard* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  Clipboard::Clipboard (Clipboard&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  Clipboard::operator= (Clipboard&& src) noexcept -> Clipboard&
  {
    Glib::Object::operator= (std::move (src));
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
  Clipboard::get_display () -> Glib::RefPtr<Display>
  {
    auto retvalue = Glib::wrap (gdk_clipboard_get_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Clipboard::get_display () const -> Glib::RefPtr<const Display>
  {
    return const_cast<Clipboard*> (this)->get_display ();
  }

  auto
  Clipboard::get_formats () -> Glib::RefPtr<ContentFormats>
  {
    auto retvalue = Glib::wrap (gdk_clipboard_get_formats (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Clipboard::get_formats () const -> Glib::RefPtr<const ContentFormats>
  {
    return const_cast<Clipboard*> (this)->get_formats ();
  }

  auto
  Clipboard::is_local () const -> bool
  {
    return gdk_clipboard_is_local (const_cast<GdkClipboard*> (gobj ()));
  }

  auto
  Clipboard::get_content () -> Glib::RefPtr<ContentProvider>
  {
    auto retvalue = Glib::wrap (gdk_clipboard_get_content (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Clipboard::get_content () const -> Glib::RefPtr<const ContentProvider>
  {
    return const_cast<Clipboard*> (this)->get_content ();
  }

  auto
  Clipboard::read_async (const std::vector<Glib::ustring>& mime_types,
                         int io_priority,
                         const Gio::SlotAsyncReady& slot,
                         const Glib::RefPtr<Gio::Cancellable>& cancellable) -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gdk_clipboard_read_async (
        gobj (),
        Glib::ArrayHandler<Glib::ustring>::vector_to_array (mime_types).data (),
        io_priority,
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  Clipboard::read_async (const std::vector<Glib::ustring>& mime_types,
                         int io_priority,
                         const Gio::SlotAsyncReady& slot) -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gdk_clipboard_read_async (
        gobj (),
        Glib::ArrayHandler<Glib::ustring>::vector_to_array (mime_types).data (),
        io_priority,
        nullptr,
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  Clipboard::read_finish (const Glib::RefPtr<Gio::AsyncResult>& result,
                          Glib::ustring& out_mime_type) -> Glib::RefPtr<Gio::InputStream>
  {
    GError* gerror = nullptr;
    const char* g_out_mime_type = nullptr;
    auto retvalue =
        Glib::wrap (gdk_clipboard_read_finish (gobj (),
                                               Glib::unwrap (result),
                                               &g_out_mime_type,
                                               &(gerror)));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    out_mime_type = Glib::convert_const_gchar_ptr_to_ustring (g_out_mime_type);
    return retvalue;
  }

  auto
  Clipboard::read_texture_async (
      const Gio::SlotAsyncReady& slot,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gdk_clipboard_read_texture_async (
        gobj (),
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  Clipboard::read_texture_async (const Gio::SlotAsyncReady& slot) -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gdk_clipboard_read_texture_async (gobj (),
                                      nullptr,
                                      &Gio::SignalProxy_async_callback,
                                      slot_copy);
  }

  auto
  Clipboard::read_texture_finish (const Glib::RefPtr<Gio::AsyncResult>& result) -> Glib::RefPtr<Texture>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::wrap (gdk_clipboard_read_texture_finish (gobj (),
                                                       Glib::unwrap (result),
                                                       &(gerror)));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Clipboard::read_text_async (const Gio::SlotAsyncReady& slot,
                              const Glib::RefPtr<Gio::Cancellable>& cancellable) -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gdk_clipboard_read_text_async (
        gobj (),
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  Clipboard::read_text_async (const Gio::SlotAsyncReady& slot) -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gdk_clipboard_read_text_async (gobj (),
                                   nullptr,
                                   &Gio::SignalProxy_async_callback,
                                   slot_copy);
  }

  auto
  Clipboard::read_text_finish (const Glib::RefPtr<Gio::AsyncResult>& result) -> Glib::ustring
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::convert_return_gchar_ptr_to_ustring (
        gdk_clipboard_read_text_finish (gobj (),
                                        Glib::unwrap (result),
                                        &(gerror)));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Clipboard::set_content (const Glib::RefPtr<const ContentProvider>& provider) -> bool
  {
    return gdk_clipboard_set_content (
        gobj (),
        const_cast<GdkContentProvider*> (Glib::unwrap (provider)));
  }

  auto
  Clipboard::set_text (const Glib::ustring& text) -> void
  {
    gdk_clipboard_set_text (gobj (), text.c_str ());
  }

  auto
  Clipboard::set_texture (const Glib::RefPtr<const Texture>& texture) -> void
  {
    gdk_clipboard_set_texture (
        gobj (),
        const_cast<GdkTexture*> (Glib::unwrap (texture)));
  }

  auto
  Clipboard::signal_changed () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this, &Clipboard_signal_changed_info);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Display>>::value,
      "Type Glib::RefPtr<Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Clipboard::property_display () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Display>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Display>> (this,
                                                                "display");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<ContentFormats>>::value,
      "Type Glib::RefPtr<ContentFormats> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Clipboard::property_formats () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ContentFormats>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ContentFormats>> (
        this,
        "formats");
  }

  auto
  Clipboard::property_local () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "local");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<ContentProvider>>::value,
      "Type Glib::RefPtr<ContentProvider> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Clipboard::property_content () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ContentProvider>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ContentProvider>> (
        this,
        "content");
  }

} // namespace Gdk