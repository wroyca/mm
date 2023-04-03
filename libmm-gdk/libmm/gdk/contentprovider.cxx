// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/contentprovider.hxx>
#include <libmm/gdk/contentprovider_p.hxx>

#include <gdk/gdk.h>

#include <libmm/gio/outputstream.hxx>
#include <libmm/gio/slot_async.hxx>

namespace Gdk
{

  auto
  ContentProvider::create (
      const std::vector<Glib::RefPtr<ContentProvider>>& providers) -> Glib::RefPtr<ContentProvider>
  {
    for (auto provider : providers)
      provider->reference ();

    return Glib::wrap (gdk_content_provider_new_union (
        Glib::ArrayHandler<Glib::RefPtr<ContentProvider>>::vector_to_array (
            providers)
            .data (),
        providers.size ()));
  }

} // namespace Gdk

namespace
{

  static const Glib::SignalProxyInfo
      ContentProvider_signal_content_changed_info = {
          "content-changed",
          (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
          (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

}

namespace Glib
{

  auto
  wrap (GdkContentProvider* object, bool take_copy) -> Glib::RefPtr<Gdk::ContentProvider>
  {
    return Glib::make_refptr_for_instance<Gdk::ContentProvider> (
        dynamic_cast<Gdk::ContentProvider*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gdk
{

  auto
  ContentProvider_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ContentProvider_Class::class_init_function;

      register_derived_type (gdk_content_provider_get_type ());
    }

    return *this;
  }

  auto
  ContentProvider_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->content_changed = &content_changed_callback;
  }

  auto
  ContentProvider_Class::content_changed_callback (GdkContentProvider* self) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_content_changed ();
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->content_changed)
      (*base->content_changed) (self);
  }

  auto
  ContentProvider_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new ContentProvider ((GdkContentProvider*) object);
  }

  auto
  ContentProvider::gobj_copy () -> GdkContentProvider*
  {
    reference ();
    return gobj ();
  }

  ContentProvider::ContentProvider (
      const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  ContentProvider::ContentProvider (GdkContentProvider* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  ContentProvider::ContentProvider (ContentProvider&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  ContentProvider::operator= (ContentProvider&& src) noexcept -> ContentProvider&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  ContentProvider::~ContentProvider () noexcept {}

  ContentProvider::CppClassType ContentProvider::contentprovider_class_;

  auto
  ContentProvider::get_type () -> GType
  {
    return contentprovider_class_.init ().get_type ();
  }

  auto
  ContentProvider::get_base_type () -> GType
  {
    return gdk_content_provider_get_type ();
  }

  ContentProvider::ContentProvider ()
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (contentprovider_class_.init ()))
  {
  }

  auto
  ContentProvider::create (const Glib::ValueBase& value) -> Glib::RefPtr<ContentProvider>
  {
    return Glib::wrap (gdk_content_provider_new_for_value ((value).gobj ()));
  }

  auto
  ContentProvider::create (const Glib::ustring& mime_type,
                           const Glib::RefPtr<const Glib::Bytes>& bytes) -> Glib::RefPtr<ContentProvider>
  {
    return Glib::wrap (gdk_content_provider_new_for_bytes (
        mime_type.c_str (),
        const_cast<GBytes*> (Glib::unwrap<Glib::Bytes> (bytes))));
  }

  auto
  ContentProvider::ref_formats () const -> Glib::RefPtr<ContentFormats>
  {
    return Glib::wrap (gdk_content_provider_ref_formats (
        const_cast<GdkContentProvider*> (gobj ())));
  }

  auto
  ContentProvider::ref_storable_formats () const -> Glib::RefPtr<ContentFormats>
  {
    return Glib::wrap (gdk_content_provider_ref_storable_formats (
        const_cast<GdkContentProvider*> (gobj ())));
  }

  auto
  ContentProvider::content_changed () -> void
  {
    gdk_content_provider_content_changed (gobj ());
  }

  auto
  ContentProvider::write_mime_type_async (
      const Glib::ustring& mime_type,
      const Glib::RefPtr<Gio::OutputStream>& stream,
      int io_priority,
      const Gio::SlotAsyncReady& slot,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gdk_content_provider_write_mime_type_async (
        const_cast<GdkContentProvider*> (gobj ()),
        mime_type.c_str (),
        Glib::unwrap (stream),
        io_priority,
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  ContentProvider::write_mime_type_async (
      const Glib::ustring& mime_type,
      const Glib::RefPtr<Gio::OutputStream>& stream,
      int io_priority,
      const Gio::SlotAsyncReady& slot) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gdk_content_provider_write_mime_type_async (
        const_cast<GdkContentProvider*> (gobj ()),
        mime_type.c_str (),
        Glib::unwrap (stream),
        io_priority,
        nullptr,
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  ContentProvider::write_mime_type_finish (
      const Glib::RefPtr<Gio::AsyncResult>& result) const -> void
  {
    GError* gerror = nullptr;
    gdk_content_provider_write_mime_type_finish (
        const_cast<GdkContentProvider*> (gobj ()),
        Glib::unwrap (result),
        &(gerror));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
  }

  auto
  ContentProvider::get_value (Glib::ValueBase& value) const -> void
  {
    GError* gerror = nullptr;
    gdk_content_provider_get_value (const_cast<GdkContentProvider*> (gobj ()),
                                    (value).gobj (),
                                    &(gerror));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
  }

  auto
  ContentProvider::signal_content_changed () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (
        this,
        &ContentProvider_signal_content_changed_info);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<ContentFormats>>::value,
      "Type Glib::RefPtr<ContentFormats> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ContentProvider::property_formats () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ContentFormats>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ContentFormats>> (
        this,
        "formats");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<ContentFormats>>::value,
      "Type Glib::RefPtr<ContentFormats> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ContentProvider::property_storable_formats () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ContentFormats>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ContentFormats>> (
        this,
        "storable-formats");
  }

  auto
  Gdk::ContentProvider::on_content_changed () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->content_changed)
      (*base->content_changed) (gobj ());
  }

} // namespace Gdk
