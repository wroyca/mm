// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/drop.hxx>
#include <libmm/gdk/drop_p.hxx>

#include <gdk/gdk.h>
#include <libmm/gdk/contentformats.hxx>
#include <libmm/gdk/device.hxx>
#include <libmm/gdk/display.hxx>
#include <libmm/gdk/drag.hxx>
#include <libmm/gdk/surface.hxx>
#include <libmm/gio/cancellable.hxx>
#include <libmm/gio/inputstream.hxx>
#include <libmm/gio/slot_async.hxx>

namespace gdk
{

  auto
  Drop::refuse () -> void
  {
    gdk_drop_status (gobj (),
                     static_cast<GdkDragAction> (0),
                     static_cast<GdkDragAction> (0));
  }

  auto
  Drop::failed () -> void
  {
    gdk_drop_finish (gobj (), (static_cast<GdkDragAction> (0)));
  }

  auto
  Drop::read_value_finish (const glib::RefPtr<gio::AsyncResult>& result) -> glib::ValueBase
  {
    GError* gerror = nullptr;
    const GValue* gvalue =
        gdk_drop_read_value_finish (gobj (), glib::unwrap (result), &gerror);
    if (gerror)
      ::glib::Error::throw_exception (gerror);

    glib::ValueBase retvalue;
    retvalue.init (gvalue);
    return retvalue;
  }

} // namespace gdk

namespace
{
}

namespace glib
{

  auto
  wrap (GdkDrop* object, bool take_copy) -> glib::RefPtr<gdk::Drop>
  {
    return glib::make_refptr_for_instance<gdk::Drop> (dynamic_cast<gdk::Drop*> (
        glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gdk
{

  auto
  Drop_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Drop_Class::class_init_function;

      register_derived_type (gdk_drop_get_type ());
    }

    return *this;
  }

  auto
  Drop_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Drop_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Drop ((GdkDrop*) object);
  }

  auto
  Drop::gobj_copy () -> GdkDrop*
  {
    reference ();
    return gobj ();
  }

  Drop::Drop (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  Drop::Drop (GdkDrop* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  Drop::Drop (Drop&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  Drop::operator= (Drop&& src) noexcept -> Drop&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  Drop::~Drop () noexcept {}

  Drop::CppClassType Drop::drop_class_;

  auto
  Drop::get_type () -> GType
  {
    return drop_class_.init ().get_type ();
  }

  auto
  Drop::get_base_type () -> GType
  {
    return gdk_drop_get_type ();
  }

  auto
  Drop::get_display () -> glib::RefPtr<Display>
  {
    auto retvalue = glib::wrap (gdk_drop_get_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Drop::get_display () const -> glib::RefPtr<const Display>
  {
    return const_cast<Drop*> (this)->get_display ();
  }

  auto
  Drop::get_device () -> glib::RefPtr<Device>
  {
    auto retvalue = glib::wrap (gdk_drop_get_device (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Drop::get_device () const -> glib::RefPtr<const Device>
  {
    return const_cast<Drop*> (this)->get_device ();
  }

  auto
  Drop::get_surface () -> glib::RefPtr<Surface>
  {
    auto retvalue = glib::wrap (gdk_drop_get_surface (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Drop::get_surface () const -> glib::RefPtr<const Surface>
  {
    return const_cast<Drop*> (this)->get_surface ();
  }

  auto
  Drop::get_formats () -> glib::RefPtr<ContentFormats>
  {
    auto retvalue = glib::wrap (gdk_drop_get_formats (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Drop::get_formats () const -> glib::RefPtr<const ContentFormats>
  {
    return const_cast<Drop*> (this)->get_formats ();
  }

  auto
  Drop::get_actions () const -> DragAction
  {
    return static_cast<DragAction> (
        gdk_drop_get_actions (const_cast<GdkDrop*> (gobj ())));
  }

  auto
  Drop::get_drag () -> glib::RefPtr<Drag>
  {
    auto retvalue = glib::wrap (gdk_drop_get_drag (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Drop::get_drag () const -> glib::RefPtr<const Drag>
  {
    return const_cast<Drop*> (this)->get_drag ();
  }

  auto
  Drop::status (DragAction actions, DragAction preferred) -> void
  {
    gdk_drop_status (gobj (),
                     static_cast<GdkDragAction> (actions),
                     static_cast<GdkDragAction> (preferred));
  }

  auto
  Drop::finish (DragAction action) -> void
  {
    gdk_drop_finish (gobj (), static_cast<GdkDragAction> (action));
  }

  auto
  Drop::read_async (const std::vector<glib::ustring>& mime_types,
                    int io_priority,
                    const gio::SlotAsyncReady& slot,
                    const glib::RefPtr<gio::Cancellable>& cancellable) -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gdk_drop_read_async (
        gobj (),
        glib::ArrayHandler<glib::ustring>::vector_to_array (mime_types).data (),
        io_priority,
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  Drop::read_async (const std::vector<glib::ustring>& mime_types,
                    int io_priority,
                    const gio::SlotAsyncReady& slot) -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gdk_drop_read_async (
        gobj (),
        glib::ArrayHandler<glib::ustring>::vector_to_array (mime_types).data (),
        io_priority,
        nullptr,
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  Drop::read_finish (const glib::RefPtr<gio::AsyncResult>& result,
                     glib::ustring& out_mime_type) -> glib::RefPtr<gio::InputStream>
  {
    GError* gerror = nullptr;
    const char* g_out_mime_type = nullptr;
    auto retvalue = glib::wrap (gdk_drop_read_finish (gobj (),
                                                      glib::unwrap (result),
                                                      &g_out_mime_type,
                                                      &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    out_mime_type = glib::convert_const_gchar_ptr_to_ustring (g_out_mime_type);
    return retvalue;
  }

  auto
  Drop::read_value_async (GType type,
                          int io_priority,
                          const gio::SlotAsyncReady& slot,
                          const glib::RefPtr<gio::Cancellable>& cancellable) -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gdk_drop_read_value_async (
        gobj (),
        type,
        io_priority,
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  Drop::read_value_async (GType type,
                          int io_priority,
                          const gio::SlotAsyncReady& slot) -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gdk_drop_read_value_async (gobj (),
                               type,
                               io_priority,
                               nullptr,
                               &gio::SignalProxy_async_callback,
                               slot_copy);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<DragAction>::value,
      "Type DragAction cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Drop::property_actions () const -> glib::PropertyProxy_ReadOnly<DragAction>
  {
    return glib::PropertyProxy_ReadOnly<DragAction> (this, "actions");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Device>>::value,
      "Type glib::RefPtr<Device> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Drop::property_device () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Device>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Device>> (this, "device");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Display>>::value,
      "Type glib::RefPtr<Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Drop::property_display () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>> (this,
                                                                "display");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<glib::RefPtr<Drag>>::value,
      "Type glib::RefPtr<Drag> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Drop::property_drag () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Drag>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Drag>> (this, "drag");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<ContentFormats>>::value,
      "Type glib::RefPtr<ContentFormats> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Drop::property_formats () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ContentFormats>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<ContentFormats>> (
        this,
        "formats");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Surface>>::value,
      "Type glib::RefPtr<Surface> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Drop::property_surface () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Surface>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Surface>> (this,
                                                                "surface");
  }

} // namespace gdk
