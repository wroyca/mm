// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/pixbufanimationiter.hxx>
#include <libmm/gdk/pixbufanimationiter_p.hxx>

namespace gdk
{

  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  PixbufAnimationIter::advance (gint64 current_time) -> bool
  {
    GTimeVal tv;
    tv.tv_sec = current_time / 1000000;
    tv.tv_usec = current_time % 1000000;
    return gdk_pixbuf_animation_iter_advance (gobj (), &tv);
  }

  G_GNUC_END_IGNORE_DEPRECATIONS

} // namespace gdk

namespace
{
}

namespace glib
{

  auto
  wrap (GdkPixbufAnimationIter* object, bool take_copy) -> glib::RefPtr<gdk::PixbufAnimationIter>
  {
    return glib::make_refptr_for_instance<gdk::PixbufAnimationIter> (
        dynamic_cast<gdk::PixbufAnimationIter*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gdk
{

  auto
  PixbufAnimationIter_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &PixbufAnimationIter_Class::class_init_function;

      register_derived_type (gdk_pixbuf_animation_iter_get_type ());
    }

    return *this;
  }

  auto
  PixbufAnimationIter_Class::class_init_function (void* g_class,
                                                  void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  PixbufAnimationIter_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new PixbufAnimationIter ((GdkPixbufAnimationIter*) object);
  }

  auto
  PixbufAnimationIter::gobj_copy () -> GdkPixbufAnimationIter*
  {
    reference ();
    return gobj ();
  }

  PixbufAnimationIter::PixbufAnimationIter (
      const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  PixbufAnimationIter::PixbufAnimationIter (GdkPixbufAnimationIter* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  PixbufAnimationIter::PixbufAnimationIter (PixbufAnimationIter&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  PixbufAnimationIter::operator= (PixbufAnimationIter&& src) noexcept -> PixbufAnimationIter&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  PixbufAnimationIter::~PixbufAnimationIter () noexcept {}

  PixbufAnimationIter::CppClassType
      PixbufAnimationIter::pixbufanimationiter_class_;

  auto
  PixbufAnimationIter::get_type () -> GType
  {
    return pixbufanimationiter_class_.init ().get_type ();
  }

  auto
  PixbufAnimationIter::get_base_type () -> GType
  {
    return gdk_pixbuf_animation_iter_get_type ();
  }

  auto
  PixbufAnimationIter::get_delay_time () const -> int
  {
    return gdk_pixbuf_animation_iter_get_delay_time (
        const_cast<GdkPixbufAnimationIter*> (gobj ()));
  }

  auto
  PixbufAnimationIter::get_pixbuf () -> glib::RefPtr<gdk::Pixbuf>
  {
    auto retvalue = glib::wrap (gdk_pixbuf_animation_iter_get_pixbuf (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PixbufAnimationIter::get_pixbuf () const -> glib::RefPtr<const gdk::Pixbuf>
  {
    return const_cast<PixbufAnimationIter*> (this)->get_pixbuf ();
  }

  auto
  PixbufAnimationIter::on_currently_loading_frame () const -> bool
  {
    return gdk_pixbuf_animation_iter_on_currently_loading_frame (
        const_cast<GdkPixbufAnimationIter*> (gobj ()));
  }

} // namespace gdk
