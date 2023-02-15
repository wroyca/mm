// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/pixbufanimationiter.hxx>
#include <libmm-gdk/pixbufanimationiter_p.hxx>

namespace Gdk
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

} // namespace Gdk

namespace
{
}

namespace Glib
{

  auto
  wrap (GdkPixbufAnimationIter* object, bool take_copy) -> Glib::RefPtr<Gdk::PixbufAnimationIter>
  {
    return Glib::make_refptr_for_instance<Gdk::PixbufAnimationIter> (
        dynamic_cast<Gdk::PixbufAnimationIter*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gdk
{

  auto
  PixbufAnimationIter_Class::init () -> const Glib::Class&
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
  PixbufAnimationIter_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
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
      const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  PixbufAnimationIter::PixbufAnimationIter (GdkPixbufAnimationIter* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  PixbufAnimationIter::PixbufAnimationIter (PixbufAnimationIter&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  PixbufAnimationIter::operator= (PixbufAnimationIter&& src) noexcept -> PixbufAnimationIter&
  {
    Glib::Object::operator= (std::move (src));
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
  PixbufAnimationIter::get_pixbuf () -> Glib::RefPtr<Gdk::Pixbuf>
  {
    auto retvalue = Glib::wrap (gdk_pixbuf_animation_iter_get_pixbuf (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PixbufAnimationIter::get_pixbuf () const -> Glib::RefPtr<const Gdk::Pixbuf>
  {
    return const_cast<PixbufAnimationIter*> (this)->get_pixbuf ();
  }

  auto
  PixbufAnimationIter::on_currently_loading_frame () const -> bool
  {
    return gdk_pixbuf_animation_iter_on_currently_loading_frame (
        const_cast<GdkPixbufAnimationIter*> (gobj ()));
  }

} // namespace Gdk
