// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/pixbufanimation.hxx>
#include <libmm/gdk/pixbufanimation_p.hxx>

#include <gdk/gdk.h>
#include <libmm/gio/slot_async.hxx>

namespace gdk
{

  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  PixbufAnimation::get_iter (gint64 start_time) -> glib::RefPtr<PixbufAnimationIter>
  {
    GTimeVal tv;
    tv.tv_sec = start_time / 1000000;
    tv.tv_usec = start_time % 1000000;
    return glib::wrap (gdk_pixbuf_animation_get_iter (gobj (), &tv));
  }

  G_GNUC_END_IGNORE_DEPRECATIONS

} // namespace gdk

namespace
{
}

namespace glib
{

  auto
  wrap (GdkPixbufAnimation* object, bool take_copy) -> glib::RefPtr<gdk::PixbufAnimation>
  {
    return glib::make_refptr_for_instance<gdk::PixbufAnimation> (
        dynamic_cast<gdk::PixbufAnimation*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gdk
{

  auto
  PixbufAnimation_Class::init () -> const glib::Class&
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
  PixbufAnimation_Class::wrap_new (GObject* object) -> glib::ObjectBase*
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
      const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  PixbufAnimation::PixbufAnimation (GdkPixbufAnimation* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  PixbufAnimation::PixbufAnimation (PixbufAnimation&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  PixbufAnimation::operator= (PixbufAnimation&& src) noexcept -> PixbufAnimation&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  PixbufAnimation::~PixbufAnimation () noexcept {}

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
  PixbufAnimation::create_from_file (const std::string& filename) -> glib::RefPtr<PixbufAnimation>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (
        gdk_pixbuf_animation_new_from_file (filename.c_str (), &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  PixbufAnimation::create_from_stream (
      const glib::RefPtr<gio::InputStream>& stream,
      const glib::RefPtr<gio::Cancellable>& cancellable) -> glib::RefPtr<PixbufAnimation>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (gdk_pixbuf_animation_new_from_stream (
        const_cast<GInputStream*> (glib::unwrap (stream)),
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  PixbufAnimation::create_from_stream_async (
      const glib::RefPtr<gio::InputStream>& stream,
      const gio::SlotAsyncReady& slot,
      const glib::RefPtr<gio::Cancellable>& cancellable) -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gdk_pixbuf_animation_new_from_stream_async (
        const_cast<GInputStream*> (glib::unwrap (stream)),
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  PixbufAnimation::create_from_stream_finish (
      const glib::RefPtr<gio::AsyncResult>& result) -> glib::RefPtr<PixbufAnimation>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (
        gdk_pixbuf_animation_new_from_stream_finish (glib::unwrap (result),
                                                     &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  PixbufAnimation::create_from_resource (const std::string& resource_path) -> glib::RefPtr<PixbufAnimation>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (
        gdk_pixbuf_animation_new_from_resource (resource_path.c_str (),
                                                &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
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
  PixbufAnimation::get_static_image () -> glib::RefPtr<Pixbuf>
  {
    auto retvalue =
        glib::wrap (gdk_pixbuf_animation_get_static_image (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

} // namespace gdk
