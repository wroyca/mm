// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!

// So we can use deprecated functions in our deprecated methods.
//#undef GDK_PIXBUF_DISABLE_DEPRECATED


#include <mm/glib/mm-glib.hpp>

#include <mm/gdk/pixbuf.hpp>
#include <mm/gdk/private/pixbuf_p.hpp>

#include <gdk-pixbuf/gdk-pixbuf.h>

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

#include <mm/glib/vectorutils.hpp>

#include <gdk/gdk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

namespace
{

void pixbuf_destroy_data_callback(guint8* pixels, void* user_data)
{
  const auto slot = static_cast<Gdk::Pixbuf::SlotDestroyData*>(user_data);
  g_return_if_fail(slot != nullptr);

  try
  {
    (*slot)(pixels); // invoke callback
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }

  delete slot;
}

} // anonymous namespace


namespace Gdk
{

Pixbuf::Pixbuf(const ::Cairo::RefPtr< ::Cairo::Surface>& src,
         int src_x, int src_y, int width, int height)
:
  Object((GObject*) gdk_pixbuf_get_from_surface(
    src->cobj(), src_x, src_y, width, height))
{
  if (!gobj())
    throw PixbufError(PixbufError::FAILED, "Could not construct Pixbuf from Cairo::Surface");
}

auto Pixbuf::create_from_data(const guint8* data, Colorspace colorspace,
                                              bool has_alpha, int bits_per_sample,
                                              int width, int height, int rowstride) -> Glib::RefPtr<Pixbuf>
{
  const auto pixbuf = gdk_pixbuf_new_from_data(
      data, (GdkColorspace) colorspace, has_alpha, bits_per_sample, width, height, rowstride,
      nullptr, nullptr);

  return Glib::wrap(pixbuf);
}

auto Pixbuf::create_from_data(const guint8* data, Colorspace colorspace,
                                              bool has_alpha, int bits_per_sample,
                                              int width, int height, int rowstride,
                                              const Pixbuf::SlotDestroyData& destroy_slot) -> Glib::RefPtr<Pixbuf>
{
  const auto pixbuf = gdk_pixbuf_new_from_data(
      data, (GdkColorspace) colorspace, has_alpha, bits_per_sample, width, height, rowstride,
      &pixbuf_destroy_data_callback, new SlotDestroyData(destroy_slot));

  return Glib::wrap(pixbuf);
}

auto Pixbuf::create_from_stream(const Glib::RefPtr<Gio::InputStream>& stream) -> Glib::RefPtr<Pixbuf>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(gdk_pixbuf_new_from_stream(const_cast<GInputStream*>(Glib::unwrap(stream)), nullptr, &(gerror)));

  if(gerror)
    ::Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto Pixbuf::create_from_stream_at_scale(const Glib::RefPtr<Gio::InputStream>& stream, int width, int height, bool preserve_aspect_ratio) -> Glib::RefPtr<Pixbuf>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(gdk_pixbuf_new_from_stream_at_scale(const_cast<GInputStream*>(Glib::unwrap(stream)), width, height, static_cast<int>(preserve_aspect_ratio), nullptr, &(gerror)));

  if(gerror)
    ::Glib::Error::throw_exception(gerror);

  return retvalue;
}

void Pixbuf::save(const std::string& filename, const Glib::ustring& type) const
{
  GError* gerror = nullptr;
  gdk_pixbuf_savev(const_cast<GdkPixbuf*>(gobj()),
                   filename.c_str(), type.c_str(), nullptr, nullptr, &gerror);

  if(gerror)
    ::Glib::Error::throw_exception(gerror);
}

void Pixbuf::save(const std::string& filename, const Glib::ustring& type,
                  const std::vector<Glib::ustring>& option_keys,
                  const std::vector<Glib::ustring>& option_values) const
{
  GError* gerror = nullptr;

  gdk_pixbuf_savev(
      const_cast<GdkPixbuf*>(gobj()), filename.c_str(), type.c_str(),
      const_cast<char**>(Glib::ArrayHandler<Glib::ustring>::vector_to_array(option_keys).data ()),
      const_cast<char**>(Glib::ArrayHandler<Glib::ustring>::vector_to_array(option_values).data ()),
      &gerror);

  if(gerror)
    ::Glib::Error::throw_exception(gerror);
}

void Pixbuf::save_to_buffer(gchar*& buffer, gsize& buffer_size,
                            const Glib::ustring& type) const
{
  GError* gerror = nullptr;

  gdk_pixbuf_save_to_buffer(
      const_cast<GdkPixbuf*>(gobj()), &buffer, &buffer_size,
      type.c_str(),
      &gerror, nullptr);

  if(gerror)
    ::Glib::Error::throw_exception(gerror);
}

void Pixbuf::save_to_buffer(gchar*& buffer, gsize& buffer_size,
                            const Glib::ustring& type,
                            const std::vector<Glib::ustring>& option_keys,
                            const std::vector<Glib::ustring>& option_values) const
{
  GError* gerror = nullptr;

  gdk_pixbuf_save_to_bufferv(
      const_cast<GdkPixbuf*>(gobj()),
      &buffer, &buffer_size,
      type.c_str(),
      const_cast<char**>(Glib::ArrayHandler<Glib::ustring>::vector_to_array(option_keys).data ()),
      const_cast<char**>(Glib::ArrayHandler<Glib::ustring>::vector_to_array(option_values).data ()),
      &gerror);

  if(gerror)
    ::Glib::Error::throw_exception(gerror);
}

auto Pixbuf::get_formats() -> std::vector<PixbufFormat>
{
  return Glib::SListHandler<PixbufFormat, PixbufFormatTraits>::slist_to_vector(gdk_pixbuf_get_formats(), Glib::OWNERSHIP_SHALLOW);
}

auto Pixbuf::get_pixels(guint& length) const -> const guint8* {
  length = get_byte_length();
  return gdk_pixbuf_read_pixels(const_cast<GdkPixbuf*>(gobj()));
}

} // namespace Gdk

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Gdk::Colorspace>::value_type() -> GType
{
  return gdk_colorspace_get_type();
}

// static
auto Glib::Value<Gdk::InterpType>::value_type() -> GType
{
  return gdk_interp_type_get_type();
}


Gdk::PixbufError::PixbufError(Gdk::PixbufError::Code error_code, const Glib::ustring& error_message)
:
  Glib::Error (GDK_PIXBUF_ERROR, error_code, error_message)
{}

Gdk::PixbufError::PixbufError(GError* gobject)
:
  Glib::Error (gobject)
{}

auto Gdk::PixbufError::code() const -> Gdk::PixbufError::Code
{
  return static_cast<Code>(Glib::Error::code());
}

void Gdk::PixbufError::throw_func(GError* gobject)
{
  throw Gdk::PixbufError(gobject);
}

// static
auto Glib::Value<Gdk::PixbufError::Code>::value_type() -> GType
{
  return gdk_pixbuf_error_get_type();
}

// static
auto Glib::Value<Gdk::Pixbuf::Rotation>::value_type() -> GType
{
  return gdk_pixbuf_rotation_get_type();
}


namespace Glib
{

auto wrap(GdkPixbuf* object, bool take_copy) -> Glib::RefPtr<Gdk::Pixbuf>
{
  return Glib::make_refptr_for_instance<Gdk::Pixbuf>( dynamic_cast<Gdk::Pixbuf*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gdk
{


/* The *_Class implementation: */

auto Pixbuf_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Pixbuf_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gdk_pixbuf_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Gio::Icon::add_interface(get_type());
  Gio::LoadableIcon::add_interface(get_type());

  }

  return *this;
}


void Pixbuf_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Pixbuf_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Pixbuf((GdkPixbuf*)object);
}


/* The implementation: */

auto Pixbuf::gobj_copy() -> GdkPixbuf*
{
  reference();
  return gobj();
}

Pixbuf::Pixbuf(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

Pixbuf::Pixbuf(GdkPixbuf* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


Pixbuf::Pixbuf(Pixbuf&& src) noexcept
: Glib::Object(std::move(src))
  , Gio::Icon(std::move(src))
  , Gio::LoadableIcon(std::move(src))
{}

auto Pixbuf::operator=(Pixbuf&& src) noexcept -> Pixbuf&
{
  Glib::Object::operator=(std::move(src));
  Gio::Icon::operator=(std::move(src));
  Gio::LoadableIcon::operator=(std::move(src));
  return *this;
}


Pixbuf::~Pixbuf() noexcept
{}


Pixbuf::CppClassType Pixbuf::pixbuf_class_; // initialize static member

auto Pixbuf::get_type() -> GType
{
  return pixbuf_class_.init().get_type();
}


auto Pixbuf::get_base_type() -> GType
{
  return gdk_pixbuf_get_type();
}


auto Pixbuf::create(const ::Cairo::RefPtr< ::Cairo::Surface>& src, int src_x, int src_y, int width, int height) -> Glib::RefPtr<Pixbuf>
{
  return Glib::make_refptr_for_instance<Pixbuf>( new Pixbuf(src, src_x, src_y, width, height) );
}

auto Pixbuf::copy() const -> Glib::RefPtr<Pixbuf>
{
  return Glib::wrap(gdk_pixbuf_copy(const_cast<GdkPixbuf*>(gobj())));
}

auto Pixbuf::create(Colorspace colorspace, bool has_alpha, int bits_per_sample, int width, int height) -> Glib::RefPtr<Pixbuf>
{
  return Glib::wrap(gdk_pixbuf_new(static_cast<GdkColorspace>(colorspace), static_cast<int>(has_alpha), bits_per_sample, width, height));
}

auto Pixbuf::create_subpixbuf(const Glib::RefPtr<Pixbuf>& src_pixbuf, int src_x, int src_y, int width, int height) -> Glib::RefPtr<Pixbuf>
{
  return Glib::wrap(gdk_pixbuf_new_subpixbuf(Glib::unwrap(src_pixbuf), src_x, src_y, width, height));
}

auto Pixbuf::create_from_file(const std::string& filename) -> Glib::RefPtr<Pixbuf>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(gdk_pixbuf_new_from_file(filename.c_str(), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Pixbuf::create_from_file(const std::string& filename, int width, int height, bool preserve_aspect_ratio) -> Glib::RefPtr<Pixbuf>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(gdk_pixbuf_new_from_file_at_scale(filename.c_str(), width, height, static_cast<int>(preserve_aspect_ratio), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Pixbuf::create_from_resource(const std::string& resource_path) -> Glib::RefPtr<Pixbuf>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(gdk_pixbuf_new_from_resource(resource_path.c_str(), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Pixbuf::create_from_resource(const std::string& resource_path, int width, int height, bool preserve_aspect_ratio) -> Glib::RefPtr<Pixbuf>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(gdk_pixbuf_new_from_resource_at_scale(resource_path.c_str(), width, height, static_cast<int>(preserve_aspect_ratio), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Pixbuf::create_from_xpm_data(const char *const * data) -> Glib::RefPtr<Pixbuf>
{
  return Glib::wrap(gdk_pixbuf_new_from_xpm_data(const_cast<const char**>(data)));
}

auto Pixbuf::create_from_stream(const Glib::RefPtr<Gio::InputStream>& stream, const Glib::RefPtr<Gio::Cancellable>& cancellable) -> Glib::RefPtr<Pixbuf>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(gdk_pixbuf_new_from_stream(const_cast<GInputStream*>(Glib::unwrap(stream)), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Pixbuf::create_from_stream_at_scale(const Glib::RefPtr<Gio::InputStream>& stream, int width, int height, bool preserve_aspect_ratio, const Glib::RefPtr<Gio::Cancellable>& cancellable) -> Glib::RefPtr<Pixbuf>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(gdk_pixbuf_new_from_stream_at_scale(const_cast<GInputStream*>(Glib::unwrap(stream)), width, height, static_cast<int>(preserve_aspect_ratio), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Pixbuf::get_colorspace() const -> Colorspace
{
  return static_cast<Colorspace>(gdk_pixbuf_get_colorspace(const_cast<GdkPixbuf*>(gobj())));
}

auto Pixbuf::get_n_channels() const -> int
{
  return gdk_pixbuf_get_n_channels(const_cast<GdkPixbuf*>(gobj()));
}

auto Pixbuf::get_has_alpha() const -> bool
{
  return gdk_pixbuf_get_has_alpha(const_cast<GdkPixbuf*>(gobj()));
}

auto Pixbuf::get_bits_per_sample() const -> int
{
  return gdk_pixbuf_get_bits_per_sample(const_cast<GdkPixbuf*>(gobj()));
}

auto Pixbuf::get_pixels() -> guint8*
{
  return gdk_pixbuf_get_pixels(gobj());
}

auto Pixbuf::get_pixels() const -> const guint8*
{
  return gdk_pixbuf_read_pixels(const_cast<GdkPixbuf*>(gobj()));
}

auto Pixbuf::get_pixels(guint& length) -> guint8*
{
  return gdk_pixbuf_get_pixels_with_length(gobj(), &(length));
}

auto Pixbuf::get_width() const -> int
{
  return gdk_pixbuf_get_width(const_cast<GdkPixbuf*>(gobj()));
}

auto Pixbuf::get_height() const -> int
{
  return gdk_pixbuf_get_height(const_cast<GdkPixbuf*>(gobj()));
}

auto Pixbuf::get_rowstride() const -> int
{
  return gdk_pixbuf_get_rowstride(const_cast<GdkPixbuf*>(gobj()));
}

auto Pixbuf::get_byte_length() const -> gsize
{
  return gdk_pixbuf_get_byte_length(const_cast<GdkPixbuf*>(gobj()));
}

void Pixbuf::fill(guint32 pixel)
{
  gdk_pixbuf_fill(gobj(), pixel);
}

auto Pixbuf::add_alpha(bool substitute_color, guint8 r, guint8 g, guint8 b) const -> Glib::RefPtr<Gdk::Pixbuf>
{
  return Glib::wrap(gdk_pixbuf_add_alpha(const_cast<GdkPixbuf*>(gobj()), static_cast<int>(substitute_color), r, g, b));
}

void Pixbuf::copy_area(int src_x, int src_y, int width, int height, const Glib::RefPtr<Gdk::Pixbuf>& dest_pixbuf, int dest_x, int dest_y) const
{
  gdk_pixbuf_copy_area(const_cast<GdkPixbuf*>(gobj()), src_x, src_y, width, height, Glib::unwrap(dest_pixbuf), dest_x, dest_y);
}

void Pixbuf::saturate_and_pixelate(const Glib::RefPtr<Gdk::Pixbuf>& dest, float saturation, bool pixelate) const
{
  gdk_pixbuf_saturate_and_pixelate(const_cast<GdkPixbuf*>(gobj()), Glib::unwrap(dest), saturation, static_cast<int>(pixelate));
}

void Pixbuf::scale(const Glib::RefPtr<Gdk::Pixbuf>& dest, int dest_x, int dest_y, int dest_width, int dest_height, double offset_x, double offset_y, double scale_x, double scale_y, InterpType interp_type) const
{
  gdk_pixbuf_scale(const_cast<GdkPixbuf*>(gobj()), Glib::unwrap(dest), dest_x, dest_y, dest_width, dest_height, offset_x, offset_y, scale_x, scale_y, static_cast<GdkInterpType>(interp_type));
}

void Pixbuf::composite(const Glib::RefPtr<Gdk::Pixbuf>& dest, int dest_x, int dest_y, int dest_width, int dest_height, double offset_x, double offset_y, double scale_x, double scale_y, InterpType interp_type, int overall_alpha) const
{
  gdk_pixbuf_composite(const_cast<GdkPixbuf*>(gobj()), Glib::unwrap(dest), dest_x, dest_y, dest_width, dest_height, offset_x, offset_y, scale_x, scale_y, static_cast<GdkInterpType>(interp_type), overall_alpha);
}

void Pixbuf::composite_color(const Glib::RefPtr<Gdk::Pixbuf>& dest, int dest_x, int dest_y, int dest_width, int dest_height, double offset_x, double offset_y, double scale_x, double scale_y, InterpType interp_type, int overall_alpha, int check_x, int check_y, int check_size, guint32 color1, guint32 color2) const
{
  gdk_pixbuf_composite_color(const_cast<GdkPixbuf*>(gobj()), Glib::unwrap(dest), dest_x, dest_y, dest_width, dest_height, offset_x, offset_y, scale_x, scale_y, static_cast<GdkInterpType>(interp_type), overall_alpha, check_x, check_y, check_size, color1, color2);
}

auto Pixbuf::scale_simple(int dest_width, int dest_height, InterpType interp_type) const -> Glib::RefPtr<Gdk::Pixbuf>
{
  return Glib::wrap(gdk_pixbuf_scale_simple(const_cast<GdkPixbuf*>(gobj()), dest_width, dest_height, static_cast<GdkInterpType>(interp_type)));
}

auto Pixbuf::composite_color_simple(int dest_width, int dest_height, InterpType interp_type, int overall_alpha, int check_size, guint32 color1, guint32 color2) const -> Glib::RefPtr<Gdk::Pixbuf>
{
  return Glib::wrap(gdk_pixbuf_composite_color_simple(const_cast<GdkPixbuf*>(gobj()), dest_width, dest_height, static_cast<GdkInterpType>(interp_type), overall_alpha, check_size, color1, color2));
}

auto Pixbuf::rotate_simple(Rotation angle) const -> Glib::RefPtr<Gdk::Pixbuf>
{
  return Glib::wrap(gdk_pixbuf_rotate_simple(const_cast<GdkPixbuf*>(gobj()), static_cast<GdkPixbufRotation>(angle)));
}

auto Pixbuf::flip(bool horizontal) const -> Glib::RefPtr<Gdk::Pixbuf>
{
  return Glib::wrap(gdk_pixbuf_flip(const_cast<GdkPixbuf*>(gobj()), static_cast<int>(horizontal)));
}

auto Pixbuf::get_option(const Glib::ustring& key) const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gdk_pixbuf_get_option(const_cast<GdkPixbuf*>(gobj()), key.c_str()));
}

auto Pixbuf::set_option(const Glib::ustring& key, const Glib::ustring& value) -> bool
{
  return gdk_pixbuf_set_option(gobj(), key.c_str(), value.c_str());
}

auto Pixbuf::remove_option(const Glib::ustring& key) -> bool
{
  return gdk_pixbuf_remove_option(gobj(), key.c_str());
}

auto Pixbuf::copy_options(const Glib::RefPtr<Pixbuf>& dest_pixbuf) const -> bool
{
  return gdk_pixbuf_copy_options(const_cast<GdkPixbuf*>(gobj()), Glib::unwrap(dest_pixbuf));
}

auto Pixbuf::apply_embedded_orientation() -> Glib::RefPtr<Pixbuf>
{
  return Glib::wrap(gdk_pixbuf_apply_embedded_orientation(gobj()));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Colorspace>::value,
  "Type Colorspace cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Pixbuf::property_colorspace() const -> Glib::PropertyProxy_ReadOnly< Colorspace >
{
  return Glib::PropertyProxy_ReadOnly< Colorspace >(this, "colorspace");
}

auto Pixbuf::property_n_channels() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "n-channels");
}

auto Pixbuf::property_has_alpha() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "has-alpha");
}

auto Pixbuf::property_bits_per_sample() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "bits-per-sample");
}

auto Pixbuf::property_width() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "width");
}

auto Pixbuf::property_height() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "height");
}

auto Pixbuf::property_rowstride() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "rowstride");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<void*>::value,
  "Type void* cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Pixbuf::property_pixels() const -> Glib::PropertyProxy_ReadOnly< void* >
{
  return Glib::PropertyProxy_ReadOnly< void* >(this, "pixels");
}


} // namespace Gdk

