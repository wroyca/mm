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

namespace Gdk
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
  Drop::read_value_finish (const Glib::RefPtr<Gio::AsyncResult>& result) -> Glib::ValueBase
  {
    GError* gerror = nullptr;
    const GValue* gvalue =
        gdk_drop_read_value_finish (gobj (), Glib::unwrap (result), &gerror);
    if (gerror)
      ::Glib::Error::throw_exception (gerror);

    Glib::ValueBase retvalue;
    retvalue.init (gvalue);
    return retvalue;
  }

} // namespace Gdk

namespace
{
}

namespace Glib
{

  auto
  wrap (GdkDrop* object, bool take_copy) -> Glib::RefPtr<Gdk::Drop>
  {
    return Glib::make_refptr_for_instance<Gdk::Drop> (dynamic_cast<Gdk::Drop*> (
        Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gdk
{

  auto
  Drop_Class::init () -> const Glib::Class&
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
  Drop_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Drop ((GdkDrop*) object);
  }

  auto
  Drop::gobj_copy () -> GdkDrop*
  {
    reference ();
    return gobj ();
  }

  Drop::Drop (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  Drop::Drop (GdkDrop* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  Drop::Drop (Drop&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  Drop::operator= (Drop&& src) noexcept -> Drop&
  {
    Glib::Object::operator= (std::move (src));
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
  Drop::get_display () -> Glib::RefPtr<Display>
  {
    auto retvalue = Glib::wrap (gdk_drop_get_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Drop::get_display () const -> Glib::RefPtr<const Display>
  {
    return const_cast<Drop*> (this)->get_display ();
  }

  auto
  Drop::get_device () -> Glib::RefPtr<Device>
  {
    auto retvalue = Glib::wrap (gdk_drop_get_device (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Drop::get_device () const -> Glib::RefPtr<const Device>
  {
    return const_cast<Drop*> (this)->get_device ();
  }

  auto
  Drop::get_surface () -> Glib::RefPtr<Surface>
  {
    auto retvalue = Glib::wrap (gdk_drop_get_surface (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Drop::get_surface () const -> Glib::RefPtr<const Surface>
  {
    return const_cast<Drop*> (this)->get_surface ();
  }

  auto
  Drop::get_formats () -> Glib::RefPtr<ContentFormats>
  {
    auto retvalue = Glib::wrap (gdk_drop_get_formats (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Drop::get_formats () const -> Glib::RefPtr<const ContentFormats>
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
  Drop::get_drag () -> Glib::RefPtr<Drag>
  {
    auto retvalue = Glib::wrap (gdk_drop_get_drag (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Drop::get_drag () const -> Glib::RefPtr<const Drag>
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
  Drop::read_async (const std::vector<Glib::ustring>& mime_types,
                    int io_priority,
                    const Gio::SlotAsyncReady& slot,
                    const Glib::RefPtr<Gio::Cancellable>& cancellable) -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gdk_drop_read_async (
        gobj (),
        Glib::ArrayHandler<Glib::ustring>::vector_to_array (mime_types).data (),
        io_priority,
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  Drop::read_async (const std::vector<Glib::ustring>& mime_types,
                    int io_priority,
                    const Gio::SlotAsyncReady& slot) -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gdk_drop_read_async (
        gobj (),
        Glib::ArrayHandler<Glib::ustring>::vector_to_array (mime_types).data (),
        io_priority,
        nullptr,
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  Drop::read_finish (const Glib::RefPtr<Gio::AsyncResult>& result,
                     Glib::ustring& out_mime_type) -> Glib::RefPtr<Gio::InputStream>
  {
    GError* gerror = nullptr;
    const char* g_out_mime_type = nullptr;
    auto retvalue = Glib::wrap (gdk_drop_read_finish (gobj (),
                                                      Glib::unwrap (result),
                                                      &g_out_mime_type,
                                                      &(gerror)));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    out_mime_type = Glib::convert_const_gchar_ptr_to_ustring (g_out_mime_type);
    return retvalue;
  }

  auto
  Drop::read_value_async (GType type,
                          int io_priority,
                          const Gio::SlotAsyncReady& slot,
                          const Glib::RefPtr<Gio::Cancellable>& cancellable) -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gdk_drop_read_value_async (
        gobj (),
        type,
        io_priority,
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  Drop::read_value_async (GType type,
                          int io_priority,
                          const Gio::SlotAsyncReady& slot) -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gdk_drop_read_value_async (gobj (),
                               type,
                               io_priority,
                               nullptr,
                               &Gio::SignalProxy_async_callback,
                               slot_copy);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<DragAction>::value,
      "Type DragAction cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Drop::property_actions () const -> Glib::PropertyProxy_ReadOnly<DragAction>
  {
    return Glib::PropertyProxy_ReadOnly<DragAction> (this, "actions");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Device>>::value,
      "Type Glib::RefPtr<Device> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Drop::property_device () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Device>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Device>> (this, "device");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Display>>::value,
      "Type Glib::RefPtr<Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Drop::property_display () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Display>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Display>> (this,
                                                                "display");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Drag>>::value,
      "Type Glib::RefPtr<Drag> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Drop::property_drag () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Drag>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Drag>> (this, "drag");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<ContentFormats>>::value,
      "Type Glib::RefPtr<ContentFormats> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Drop::property_formats () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ContentFormats>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ContentFormats>> (
        this,
        "formats");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Surface>>::value,
      "Type Glib::RefPtr<Surface> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Drop::property_surface () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Surface>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Surface>> (this,
                                                                "surface");
  }

} // namespace Gdk
