// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/contentprovider.hxx>
#include <libmm/gdk/contentprovider_p.hxx>

#include <gdk/gdk.h>

#include <libmm/gio/outputstream.hxx>
#include <libmm/gio/slot_async.hxx>

namespace gdk
{

  auto
  ContentProvider::create (
      const std::vector<glib::RefPtr<ContentProvider>>& providers) -> glib::RefPtr<ContentProvider>
  {
    for (auto provider : providers)
      provider->reference ();

    return glib::wrap (gdk_content_provider_new_union (
        glib::ArrayHandler<glib::RefPtr<ContentProvider>>::vector_to_array (
            providers)
            .data (),
        providers.size ()));
  }

} // namespace gdk

namespace
{

  static const glib::SignalProxyInfo
      ContentProvider_signal_content_changed_info = {
          "content-changed",
          (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
          (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

}

namespace glib
{

  auto
  wrap (GdkContentProvider* object, bool take_copy) -> glib::RefPtr<gdk::ContentProvider>
  {
    return glib::make_refptr_for_instance<gdk::ContentProvider> (
        dynamic_cast<gdk::ContentProvider*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gdk
{

  auto
  ContentProvider_Class::init () -> const glib::Class&
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
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

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
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->content_changed)
      (*base->content_changed) (self);
  }

  auto
  ContentProvider_Class::wrap_new (GObject* object) -> glib::ObjectBase*
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
      const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  ContentProvider::ContentProvider (GdkContentProvider* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  ContentProvider::ContentProvider (ContentProvider&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  ContentProvider::operator= (ContentProvider&& src) noexcept -> ContentProvider&
  {
    glib::Object::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (contentprovider_class_.init ()))
  {
  }

  auto
  ContentProvider::create (const glib::ValueBase& value) -> glib::RefPtr<ContentProvider>
  {
    return glib::wrap (gdk_content_provider_new_for_value ((value).gobj ()));
  }

  auto
  ContentProvider::create (const glib::ustring& mime_type,
                           const glib::RefPtr<const glib::Bytes>& bytes) -> glib::RefPtr<ContentProvider>
  {
    return glib::wrap (gdk_content_provider_new_for_bytes (
        mime_type.c_str (),
        const_cast<GBytes*> (glib::unwrap<glib::Bytes> (bytes))));
  }

  auto
  ContentProvider::ref_formats () const -> glib::RefPtr<ContentFormats>
  {
    return glib::wrap (gdk_content_provider_ref_formats (
        const_cast<GdkContentProvider*> (gobj ())));
  }

  auto
  ContentProvider::ref_storable_formats () const -> glib::RefPtr<ContentFormats>
  {
    return glib::wrap (gdk_content_provider_ref_storable_formats (
        const_cast<GdkContentProvider*> (gobj ())));
  }

  auto
  ContentProvider::content_changed () -> void
  {
    gdk_content_provider_content_changed (gobj ());
  }

  auto
  ContentProvider::write_mime_type_async (
      const glib::ustring& mime_type,
      const glib::RefPtr<gio::OutputStream>& stream,
      int io_priority,
      const gio::SlotAsyncReady& slot,
      const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gdk_content_provider_write_mime_type_async (
        const_cast<GdkContentProvider*> (gobj ()),
        mime_type.c_str (),
        glib::unwrap (stream),
        io_priority,
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  ContentProvider::write_mime_type_async (
      const glib::ustring& mime_type,
      const glib::RefPtr<gio::OutputStream>& stream,
      int io_priority,
      const gio::SlotAsyncReady& slot) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gdk_content_provider_write_mime_type_async (
        const_cast<GdkContentProvider*> (gobj ()),
        mime_type.c_str (),
        glib::unwrap (stream),
        io_priority,
        nullptr,
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  ContentProvider::write_mime_type_finish (
      const glib::RefPtr<gio::AsyncResult>& result) const -> void
  {
    GError* gerror = nullptr;
    gdk_content_provider_write_mime_type_finish (
        const_cast<GdkContentProvider*> (gobj ()),
        glib::unwrap (result),
        &(gerror));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
  }

  auto
  ContentProvider::get_value (glib::ValueBase& value) const -> void
  {
    GError* gerror = nullptr;
    gdk_content_provider_get_value (const_cast<GdkContentProvider*> (gobj ()),
                                    (value).gobj (),
                                    &(gerror));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
  }

  auto
  ContentProvider::signal_content_changed () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (
        this,
        &ContentProvider_signal_content_changed_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<ContentFormats>>::value,
      "Type glib::RefPtr<ContentFormats> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ContentProvider::property_formats () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ContentFormats>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<ContentFormats>> (
        this,
        "formats");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<ContentFormats>>::value,
      "Type glib::RefPtr<ContentFormats> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ContentProvider::property_storable_formats () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ContentFormats>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<ContentFormats>> (
        this,
        "storable-formats");
  }

  auto
  gdk::ContentProvider::on_content_changed () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->content_changed)
      (*base->content_changed) (gobj ());
  }

} // namespace gdk
