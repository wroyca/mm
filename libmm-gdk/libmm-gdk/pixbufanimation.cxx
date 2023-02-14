// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/pixbufanimation.hxx>
#include <libmm-gdk/pixbufanimation_p.hxx>

#include <gdk/gdk.h>
#include <libmm-gio/slot_async.hxx>

namespace Gdk
{

  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  PixbufAnimation::get_iter (const gint64 start_time) -> Glib::RefPtr<PixbufAnimationIter>
  {
    GTimeVal tv;
    tv.tv_sec = start_time / 1000000;
    tv.tv_usec = start_time % 1000000;
    return Glib::wrap (gdk_pixbuf_animation_get_iter (gobj (), &tv));
  }

  G_GNUC_END_IGNORE_DEPRECATIONS

} // namespace Gdk

namespace
{
}

namespace Glib
{

  auto
  wrap (GdkPixbufAnimation* object, const bool take_copy) -> RefPtr<Gdk::PixbufAnimation>
  {
    return Glib::make_refptr_for_instance<Gdk::PixbufAnimation> (
        dynamic_cast<Gdk::PixbufAnimation*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gdk
{

  auto
  PixbufAnimation_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &PixbufAnimation_Class::class_init_function;

      register_derived_type (gdk_pixbuf_animation_get_type ());
    }

    return *this;
  }

  auto
  PixbufAnimation_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  PixbufAnimation_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new PixbufAnimation ((GdkPixbufAnimation*) object);
  }

  auto
  PixbufAnimation::gobj_copy () -> GdkPixbufAnimation*
  {
    reference ();
    return gobj ();
  }

  PixbufAnimation::PixbufAnimation (
      const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  PixbufAnimation::PixbufAnimation (GdkPixbufAnimation* castitem)
    : Object ((GObject*) castitem)
  {
  }

  PixbufAnimation::PixbufAnimation (PixbufAnimation&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  PixbufAnimation::operator= (PixbufAnimation&& src) noexcept -> PixbufAnimation&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  PixbufAnimation::~PixbufAnimation () noexcept = default;

  PixbufAnimation::CppClassType PixbufAnimation::pixbufanimation_class_;

  auto
  PixbufAnimation::get_type () -> GType
  {
    return pixbufanimation_class_.init ().get_type ();
  }

  auto
  PixbufAnimation::get_base_type () -> GType
  {
    return gdk_pixbuf_animation_get_type ();
  }

  auto
  PixbufAnimation::create_from_file (const std::string& filename) -> Glib::RefPtr<PixbufAnimation>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        gdk_pixbuf_animation_new_from_file (filename.c_str (), &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  PixbufAnimation::create_from_stream (
      const Glib::RefPtr<Gio::InputStream>& stream,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) -> Glib::RefPtr<PixbufAnimation>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        gdk_pixbuf_animation_new_from_stream (Glib::unwrap (stream),
                                              Glib::unwrap (cancellable),
                                              &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  PixbufAnimation::create_from_stream_async (
      const Glib::RefPtr<Gio::InputStream>& stream,
      const Gio::SlotAsyncReady& slot,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new Gio::SlotAsyncReady (slot);

    gdk_pixbuf_animation_new_from_stream_async (
        Glib::unwrap (stream),
        Glib::unwrap (cancellable),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  PixbufAnimation::create_from_stream_finish (
      const Glib::RefPtr<Gio::AsyncResult>& result) -> Glib::RefPtr<PixbufAnimation>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        gdk_pixbuf_animation_new_from_stream_finish (Glib::unwrap (result),
                                                     &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  PixbufAnimation::create_from_resource (const std::string& resource_path) -> Glib::RefPtr<PixbufAnimation>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        gdk_pixbuf_animation_new_from_resource (resource_path.c_str (),
                                                &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  PixbufAnimation::get_width () const -> int
  {
    return gdk_pixbuf_animation_get_width (
        const_cast<GdkPixbufAnimation*> (gobj ()));
  }

  auto
  PixbufAnimation::get_height () const -> int
  {
    return gdk_pixbuf_animation_get_height (
        const_cast<GdkPixbufAnimation*> (gobj ()));
  }

  auto
  PixbufAnimation::is_static_image () const -> bool
  {
    return gdk_pixbuf_animation_is_static_image (
        const_cast<GdkPixbufAnimation*> (gobj ()));
  }

  auto
  PixbufAnimation::get_static_image () -> Glib::RefPtr<Pixbuf>
  {
    auto retvalue =
        Glib::wrap (gdk_pixbuf_animation_get_static_image (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

} // namespace Gdk
