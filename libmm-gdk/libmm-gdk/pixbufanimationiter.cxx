


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/pixbufanimationiter.hxx>
#include <libmm-gdk/pixbufanimationiter_p.hxx>


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

namespace Gdk
{

G_GNUC_BEGIN_IGNORE_DEPRECATIONS
auto PixbufAnimationIter::advance(
  const gint64 current_time) -> bool
{
  // GTimeVal is deprecated, but gdk-pixbuf has no replacement for
  // gdk_pixbuf_animation_iter_advance() without GTimeVal.
  GTimeVal tv;
  tv.tv_sec = current_time / 1000000;
  tv.tv_usec = current_time % 1000000;
  return gdk_pixbuf_animation_iter_advance(gobj(), &tv);
}
G_GNUC_END_IGNORE_DEPRECATIONS

} //namespace Gdk


namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GdkPixbufAnimationIter* object, const bool take_copy) -> RefPtr<Gdk::PixbufAnimationIter>
{
  return Glib::make_refptr_for_instance<Gdk::PixbufAnimationIter>( dynamic_cast<Gdk::PixbufAnimationIter*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gdk
{


/* The *_Class implementation: */

auto PixbufAnimationIter_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &PixbufAnimationIter_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gdk_pixbuf_animation_iter_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto PixbufAnimationIter_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto PixbufAnimationIter_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new PixbufAnimationIter((GdkPixbufAnimationIter*)object);
}


/* The implementation: */

auto PixbufAnimationIter::gobj_copy() -> GdkPixbufAnimationIter*
{
  reference();
  return gobj();
}

PixbufAnimationIter::PixbufAnimationIter(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

PixbufAnimationIter::PixbufAnimationIter(GdkPixbufAnimationIter* castitem)
: Object((GObject*)castitem)
{}


PixbufAnimationIter::PixbufAnimationIter(PixbufAnimationIter&& src) noexcept
: Object(std::move(src))
{}

auto PixbufAnimationIter::operator=(PixbufAnimationIter&& src) noexcept -> PixbufAnimationIter&
{
  Object::operator=(std::move(src));
  return *this;
}


PixbufAnimationIter::~PixbufAnimationIter() noexcept = default;

PixbufAnimationIter::CppClassType PixbufAnimationIter::pixbufanimationiter_class_; // initialize static member

auto PixbufAnimationIter::get_type() -> GType
{
  return pixbufanimationiter_class_.init().get_type();
}


auto PixbufAnimationIter::get_base_type() -> GType
{
  return gdk_pixbuf_animation_iter_get_type();
}


auto PixbufAnimationIter::get_delay_time() const -> int
{
  return gdk_pixbuf_animation_iter_get_delay_time(const_cast<GdkPixbufAnimationIter*>(gobj()));
}

auto PixbufAnimationIter::get_pixbuf() -> Glib::RefPtr<Pixbuf>
{
  auto retvalue = Glib::wrap(gdk_pixbuf_animation_iter_get_pixbuf(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto PixbufAnimationIter::get_pixbuf() const -> Glib::RefPtr<const Pixbuf>
{
  return const_cast<PixbufAnimationIter*>(this)->get_pixbuf();
}

auto PixbufAnimationIter::on_currently_loading_frame() const -> bool
{
  return gdk_pixbuf_animation_iter_on_currently_loading_frame(const_cast<GdkPixbufAnimationIter*>(gobj()));
}


} // namespace Gdk


