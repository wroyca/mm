


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gdk/pixbufanimation.hpp>
#include <libmm-gdk/pixbufanimation_p.hpp>


/*
 * Copyright 1998-2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <libmm-gio/slot_async.hpp>
#include <gdk/gdk.h>

namespace Gdk
{

G_GNUC_BEGIN_IGNORE_DEPRECATIONS
auto PixbufAnimation::get_iter(
  const gint64 start_time) -> Glib::RefPtr<PixbufAnimationIter>
{
  // GTimeVal is deprecated, but gdk-pixbuf has no replacement for
  // gdk_pixbuf_animation_get_iter() without GTimeVal.
  GTimeVal tv;
  tv.tv_sec = start_time / 1000000;
  tv.tv_usec = start_time % 1000000;
  return Glib::wrap(gdk_pixbuf_animation_get_iter(gobj(), &tv));
}
G_GNUC_END_IGNORE_DEPRECATIONS

} //namespace Gdk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GdkPixbufAnimation* object, const bool take_copy) -> RefPtr<Gdk::PixbufAnimation>
{
  return Glib::make_refptr_for_instance<Gdk::PixbufAnimation>( dynamic_cast<Gdk::PixbufAnimation*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gdk
{


/* The *_Class implementation: */

auto PixbufAnimation_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &PixbufAnimation_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gdk_pixbuf_animation_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto PixbufAnimation_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto PixbufAnimation_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new PixbufAnimation((GdkPixbufAnimation*)object);
}


/* The implementation: */

auto PixbufAnimation::gobj_copy() -> GdkPixbufAnimation*
{
  reference();
  return gobj();
}

PixbufAnimation::PixbufAnimation(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

PixbufAnimation::PixbufAnimation(GdkPixbufAnimation* castitem)
: Object((GObject*)castitem)
{}


PixbufAnimation::PixbufAnimation(PixbufAnimation&& src) noexcept
: Object(std::move(src))
{}

auto PixbufAnimation::operator=(PixbufAnimation&& src) noexcept -> PixbufAnimation&
{
  Object::operator=(std::move(src));
  return *this;
}


PixbufAnimation::~PixbufAnimation() noexcept = default;

PixbufAnimation::CppClassType PixbufAnimation::pixbufanimation_class_; // initialize static member

auto PixbufAnimation::get_type() -> GType
{
  return pixbufanimation_class_.init().get_type();
}


auto PixbufAnimation::get_base_type() -> GType
{
  return gdk_pixbuf_animation_get_type();
}


auto PixbufAnimation::create_from_file(const std::string& filename) -> Glib::RefPtr<PixbufAnimation>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(gdk_pixbuf_animation_new_from_file(filename.c_str(), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto PixbufAnimation::create_from_stream(const Glib::RefPtr<Gio::InputStream>& stream, const Glib::RefPtr<Gio::Cancellable>& cancellable) -> Glib::RefPtr<PixbufAnimation>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(gdk_pixbuf_animation_new_from_stream(Glib::unwrap(stream), Glib::unwrap(cancellable), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto PixbufAnimation::create_from_stream_async (
  const Glib::RefPtr <Gio::InputStream> &stream, const Gio::SlotAsyncReady &slot,
  const Glib::RefPtr <Gio::Cancellable> &cancellable) -> void
{
  // Create a copy of the slot.
  const auto slot_copy = new Gio::SlotAsyncReady(slot);

  gdk_pixbuf_animation_new_from_stream_async(Glib::unwrap(stream), Glib::unwrap(cancellable), &Gio::SignalProxy_async_callback, slot_copy);
}

auto PixbufAnimation::create_from_stream_finish(const Glib::RefPtr<Gio::AsyncResult>& result) -> Glib::RefPtr<PixbufAnimation>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(gdk_pixbuf_animation_new_from_stream_finish(Glib::unwrap(result), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto PixbufAnimation::create_from_resource(const std::string& resource_path) -> Glib::RefPtr<PixbufAnimation>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(gdk_pixbuf_animation_new_from_resource(resource_path.c_str(), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto PixbufAnimation::get_width() const -> int
{
  return gdk_pixbuf_animation_get_width(const_cast<GdkPixbufAnimation*>(gobj()));
}

auto PixbufAnimation::get_height() const -> int
{
  return gdk_pixbuf_animation_get_height(const_cast<GdkPixbufAnimation*>(gobj()));
}

auto PixbufAnimation::is_static_image() const -> bool
{
  return gdk_pixbuf_animation_is_static_image(const_cast<GdkPixbufAnimation*>(gobj()));
}

auto PixbufAnimation::get_static_image() -> Glib::RefPtr<Pixbuf>
{
  auto retvalue = Glib::wrap(gdk_pixbuf_animation_get_static_image(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}


} // namespace Gdk


