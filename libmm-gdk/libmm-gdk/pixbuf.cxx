// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/pixbuf.hxx>
#include <libmm-gdk/pixbuf_p.hxx>

#include <gdk-pixbuf/gdk-pixbuf.h>

#include <libmm-glib/vectorutils.hxx>

#include <gdk-pixbuf/gdk-pixbuf.h>
#include <gdk/gdk.h>

namespace
{

  auto
  pixbuf_destroy_data_callback (guint8* pixels, void* user_data) -> void
  {
    const auto slot = static_cast<Gdk::Pixbuf::SlotDestroyData*> (user_data);
    g_return_if_fail (slot != nullptr);

    try
    {
      (*slot) (pixels);
    }
    catch (...)
    {
      Glib::exception_handlers_invoke ();
    }

    delete slot;
  }

} // namespace

namespace Gdk
{

  Pixbuf::Pixbuf (const Cairo::RefPtr<Cairo::Surface>& src,
                  const int src_x,
                  const int src_y,
                  const int width,
                  const int height)
    : Object ((GObject*) gdk_pixbuf_get_from_surface (src->cobj (),
                                                      src_x,
                                                      src_y,
                                                      width,
                                                      height))
  {
    if (!gobj ())
      throw PixbufError (PixbufError::FAILED,
                         "Could not construct Pixbuf from Cairo::Surface");
  }

  auto
  Pixbuf::create_from_data (const guint8* data,
                            Colorspace colorspace,
                            const bool has_alpha,
                            const int bits_per_sample,
                            const int width,
                            const int height,
                            const int rowstride) -> Glib::RefPtr<Pixbuf>
  {
    const auto pixbuf = gdk_pixbuf_new_from_data (data,
                                                  (GdkColorspace) colorspace,
                                                  has_alpha,
                                                  bits_per_sample,
                                                  width,
                                                  height,
                                                  rowstride,
                                                  nullptr,
                                                  nullptr);

    return Glib::wrap (pixbuf);
  }

  auto
  Pixbuf::create_from_data (const guint8* data,
                            Colorspace colorspace,
                            const bool has_alpha,
                            const int bits_per_sample,
                            const int width,
                            const int height,
                            const int rowstride,
                            const SlotDestroyData& destroy_slot) -> Glib::RefPtr<Pixbuf>
  {
    const auto pixbuf = gdk_pixbuf_new_from_data (
        data,
        (GdkColorspace) colorspace,
        has_alpha,
        bits_per_sample,
        width,
        height,
        rowstride,
        &pixbuf_destroy_data_callback,
        new SlotDestroyData (destroy_slot));

    return Glib::wrap (pixbuf);
  }

  auto
  Pixbuf::create_from_stream (const Glib::RefPtr<Gio::InputStream>& stream) -> Glib::RefPtr<Pixbuf>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        gdk_pixbuf_new_from_stream (Glib::unwrap (stream), nullptr, &gerror));

    if (gerror)
      Glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  Pixbuf::create_from_stream_at_scale (
      const Glib::RefPtr<Gio::InputStream>& stream,
      const int width,
      const int height,
      const bool preserve_aspect_ratio) -> Glib::RefPtr<Pixbuf>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::wrap (gdk_pixbuf_new_from_stream_at_scale (Glib::unwrap (stream),
                                                         width,
                                                         height,
                                                         preserve_aspect_ratio,
                                                         nullptr,
                                                         &gerror));

    if (gerror)
      Glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  Pixbuf::save (const std::string& filename, const Glib::ustring& type) const -> void
  {
    GError* gerror = nullptr;
    gdk_pixbuf_savev (const_cast<GdkPixbuf*> (gobj ()),
                      filename.c_str (),
                      type.c_str (),
                      nullptr,
                      nullptr,
                      &gerror);

    if (gerror)
      Glib::Error::throw_exception (gerror);
  }

  auto
  Pixbuf::save (const std::string& filename,
                const Glib::ustring& type,
                const std::vector<Glib::ustring>& option_keys,
                const std::vector<Glib::ustring>& option_values) const -> void
  {
    GError* gerror = nullptr;

    gdk_pixbuf_savev (
        const_cast<GdkPixbuf*> (gobj ()),
        filename.c_str (),
        type.c_str (),
        const_cast<char**> (
            Glib::ArrayHandler<Glib::ustring>::vector_to_array (option_keys)
                .data ()),
        const_cast<char**> (
            Glib::ArrayHandler<Glib::ustring>::vector_to_array (option_values)
                .data ()),
        &gerror);

    if (gerror)
      Glib::Error::throw_exception (gerror);
  }

  auto
  Pixbuf::save_to_buffer (gchar*& buffer,
                          gsize& buffer_size,
                          const Glib::ustring& type) const -> void
  {
    GError* gerror = nullptr;

    gdk_pixbuf_save_to_buffer (const_cast<GdkPixbuf*> (gobj ()),
                               &buffer,
                               &buffer_size,
                               type.c_str (),
                               &gerror,
                               nullptr);

    if (gerror)
      Glib::Error::throw_exception (gerror);
  }

  auto
  Pixbuf::save_to_buffer (gchar*& buffer,
                          gsize& buffer_size,
                          const Glib::ustring& type,
                          const std::vector<Glib::ustring>& option_keys,
                          const std::vector<Glib::ustring>& option_values) const -> void
  {
    GError* gerror = nullptr;

    gdk_pixbuf_save_to_bufferv (
        const_cast<GdkPixbuf*> (gobj ()),
        &buffer,
        &buffer_size,
        type.c_str (),
        const_cast<char**> (
            Glib::ArrayHandler<Glib::ustring>::vector_to_array (option_keys)
                .data ()),
        const_cast<char**> (
            Glib::ArrayHandler<Glib::ustring>::vector_to_array (option_values)
                .data ()),
        &gerror);

    if (gerror)
      Glib::Error::throw_exception (gerror);
  }

  auto
  Pixbuf::get_formats () -> std::vector<PixbufFormat>
  {
    return Glib::SListHandler<PixbufFormat, PixbufFormatTraits>::
        slist_to_vector (gdk_pixbuf_get_formats (), Glib::OWNERSHIP_SHALLOW);
  }

  auto
  Pixbuf::get_pixels (guint& length) const -> const guint8*
  {
    length = get_byte_length ();
    return gdk_pixbuf_read_pixels (gobj ());
  }

} // namespace Gdk

namespace
{
}

auto
Glib::Value<Gdk::Colorspace>::value_type () -> GType
{
  return gdk_colorspace_get_type ();
}

auto
Glib::Value<Gdk::InterpType>::value_type () -> GType
{
  return gdk_interp_type_get_type ();
}

Gdk::PixbufError::PixbufError (const Code error_code,
                               const Glib::ustring& error_message)
  : Error (GDK_PIXBUF_ERROR, error_code, error_message)
{
}

Gdk::PixbufError::PixbufError (GError* gobject)
  : Error (gobject)
{
}

auto
Gdk::PixbufError::code () const -> Code
{
  return static_cast<Code> (Error::code ());
}

auto
Gdk::PixbufError::throw_func (GError* gobject) -> void
{
  throw PixbufError (gobject);
}

auto
Glib::Value<Gdk::PixbufError::Code>::value_type () -> GType
{
  return gdk_pixbuf_error_get_type ();
}

auto
Glib::Value<Gdk::Pixbuf::Rotation>::value_type () -> GType
{
  return gdk_pixbuf_rotation_get_type ();
}

namespace Glib
{

  auto
  wrap (GdkPixbuf* object, const bool take_copy) -> RefPtr<Gdk::Pixbuf>
  {
    return Glib::make_refptr_for_instance<Gdk::Pixbuf> (
        dynamic_cast<Gdk::Pixbuf*> (wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gdk
{

  auto
  Pixbuf_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Pixbuf_Class::class_init_function;

      register_derived_type (gdk_pixbuf_get_type ());

      Gio::Icon::add_interface (get_type ());
      Gio::LoadableIcon::add_interface (get_type ());
    }

    return *this;
  }

  auto
  Pixbuf_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Pixbuf_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Pixbuf ((GdkPixbuf*) object);
  }

  auto
  Pixbuf::gobj_copy () -> GdkPixbuf*
  {
    reference ();
    return gobj ();
  }

  Pixbuf::Pixbuf (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  Pixbuf::Pixbuf (GdkPixbuf* castitem)
    : Object ((GObject*) castitem)
  {
  }

  Pixbuf::Pixbuf (Pixbuf&& src) noexcept
    : Object (std::move (src)),
      Icon (std::move (src)),
      LoadableIcon (std::move (src))
  {
  }

  auto
  Pixbuf::operator= (Pixbuf&& src) noexcept -> Pixbuf&
  {
    Object::operator= (std::move (src));
    Icon::operator= (std::move (src));
    LoadableIcon::operator= (std::move (src));
    return *this;
  }

  Pixbuf::~Pixbuf () noexcept = default;

  Pixbuf::CppClassType Pixbuf::pixbuf_class_;

  auto
  Pixbuf::get_type () -> GType
  {
    return pixbuf_class_.init ().get_type ();
  }

  auto
  Pixbuf::get_base_type () -> GType
  {
    return gdk_pixbuf_get_type ();
  }

  auto
  Pixbuf::create (const Cairo::RefPtr<Cairo::Surface>& src,
                  const int src_x,
                  const int src_y,
                  const int width,
                  const int height) -> Glib::RefPtr<Pixbuf>
  {
    return Glib::make_refptr_for_instance<Pixbuf> (
        new Pixbuf (src, src_x, src_y, width, height));
  }

  auto
  Pixbuf::copy () const -> Glib::RefPtr<Pixbuf>
  {
    return Glib::wrap (gdk_pixbuf_copy (gobj ()));
  }

  auto
  Pixbuf::create (Colorspace colorspace,
                  const bool has_alpha,
                  const int bits_per_sample,
                  const int width,
                  const int height) -> Glib::RefPtr<Pixbuf>
  {
    return Glib::wrap (gdk_pixbuf_new (static_cast<GdkColorspace> (colorspace),
                                       has_alpha,
                                       bits_per_sample,
                                       width,
                                       height));
  }

  auto
  Pixbuf::create_subpixbuf (const Glib::RefPtr<Pixbuf>& src_pixbuf,
                            const int src_x,
                            const int src_y,
                            const int width,
                            const int height) -> Glib::RefPtr<Pixbuf>
  {
    return Glib::wrap (gdk_pixbuf_new_subpixbuf (Glib::unwrap (src_pixbuf),
                                                 src_x,
                                                 src_y,
                                                 width,
                                                 height));
  }

  auto
  Pixbuf::create_from_file (const std::string& filename) -> Glib::RefPtr<Pixbuf>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::wrap (gdk_pixbuf_new_from_file (filename.c_str (), &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Pixbuf::create_from_file (const std::string& filename,
                            const int width,
                            const int height,
                            const bool preserve_aspect_ratio) -> Glib::RefPtr<Pixbuf>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::wrap (gdk_pixbuf_new_from_file_at_scale (filename.c_str (),
                                                       width,
                                                       height,
                                                       preserve_aspect_ratio,
                                                       &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Pixbuf::create_from_resource (const std::string& resource_path) -> Glib::RefPtr<Pixbuf>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        gdk_pixbuf_new_from_resource (resource_path.c_str (), &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Pixbuf::create_from_resource (const std::string& resource_path,
                                const int width,
                                const int height,
                                const bool preserve_aspect_ratio) -> Glib::RefPtr<Pixbuf>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        gdk_pixbuf_new_from_resource_at_scale (resource_path.c_str (),
                                               width,
                                               height,
                                               preserve_aspect_ratio,
                                               &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Pixbuf::create_from_xpm_data (const char* const* data) -> Glib::RefPtr<Pixbuf>
  {
    return Glib::wrap (
        gdk_pixbuf_new_from_xpm_data (const_cast<const char**> (data)));
  }

  auto
  Pixbuf::create_from_stream (const Glib::RefPtr<Gio::InputStream>& stream,
                              const Glib::RefPtr<Gio::Cancellable>& cancellable) -> Glib::RefPtr<Pixbuf>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::wrap (gdk_pixbuf_new_from_stream (Glib::unwrap (stream),
                                                Glib::unwrap (cancellable),
                                                &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Pixbuf::create_from_stream_at_scale (
      const Glib::RefPtr<Gio::InputStream>& stream,
      const int width,
      const int height,
      const bool preserve_aspect_ratio,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) -> Glib::RefPtr<Pixbuf>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        gdk_pixbuf_new_from_stream_at_scale (Glib::unwrap (stream),
                                             width,
                                             height,
                                             preserve_aspect_ratio,
                                             Glib::unwrap (cancellable),
                                             &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Pixbuf::get_colorspace () const -> Colorspace
  {
    return static_cast<Colorspace> (gdk_pixbuf_get_colorspace (gobj ()));
  }

  auto
  Pixbuf::get_n_channels () const -> int
  {
    return gdk_pixbuf_get_n_channels (gobj ());
  }

  auto
  Pixbuf::get_has_alpha () const -> bool
  {
    return gdk_pixbuf_get_has_alpha (gobj ());
  }

  auto
  Pixbuf::get_bits_per_sample () const -> int
  {
    return gdk_pixbuf_get_bits_per_sample (gobj ());
  }

  auto
  Pixbuf::get_pixels () -> guint8*
  {
    return gdk_pixbuf_get_pixels (gobj ());
  }

  auto
  Pixbuf::get_pixels () const -> const guint8*
  {
    return gdk_pixbuf_read_pixels (gobj ());
  }

  auto
  Pixbuf::get_pixels (guint& length) -> guint8*
  {
    return gdk_pixbuf_get_pixels_with_length (gobj (), &length);
  }

  auto
  Pixbuf::get_width () const -> int
  {
    return gdk_pixbuf_get_width (gobj ());
  }

  auto
  Pixbuf::get_height () const -> int
  {
    return gdk_pixbuf_get_height (gobj ());
  }

  auto
  Pixbuf::get_rowstride () const -> int
  {
    return gdk_pixbuf_get_rowstride (gobj ());
  }

  auto
  Pixbuf::get_byte_length () const -> gsize
  {
    return gdk_pixbuf_get_byte_length (gobj ());
  }

  auto
  Pixbuf::fill (const guint32 pixel) -> void
  {
    gdk_pixbuf_fill (gobj (), pixel);
  }

  auto
  Pixbuf::add_alpha (const bool substitute_color,
                     const guint8 r,
                     const guint8 g,
                     const guint8 b) const -> Glib::RefPtr<Pixbuf>
  {
    return Glib::wrap (
        gdk_pixbuf_add_alpha (gobj (), substitute_color, r, g, b));
  }

  auto
  Pixbuf::copy_area (const int src_x,
                     const int src_y,
                     const int width,
                     const int height,
                     const Glib::RefPtr<Pixbuf>& dest_pixbuf,
                     const int dest_x,
                     const int dest_y) const -> void
  {
    gdk_pixbuf_copy_area (gobj (),
                          src_x,
                          src_y,
                          width,
                          height,
                          Glib::unwrap (dest_pixbuf),
                          dest_x,
                          dest_y);
  }

  auto
  Pixbuf::saturate_and_pixelate (const Glib::RefPtr<Pixbuf>& dest,
                                 const float saturation,
                                 const bool pixelate) const -> void
  {
    gdk_pixbuf_saturate_and_pixelate (gobj (),
                                      Glib::unwrap (dest),
                                      saturation,
                                      pixelate);
  }

  auto
  Pixbuf::scale (const Glib::RefPtr<Pixbuf>& dest,
                 const int dest_x,
                 const int dest_y,
                 const int dest_width,
                 const int dest_height,
                 const double offset_x,
                 const double offset_y,
                 const double scale_x,
                 const double scale_y,
                 InterpType interp_type) const -> void
  {
    gdk_pixbuf_scale (gobj (),
                      Glib::unwrap (dest),
                      dest_x,
                      dest_y,
                      dest_width,
                      dest_height,
                      offset_x,
                      offset_y,
                      scale_x,
                      scale_y,
                      static_cast<GdkInterpType> (interp_type));
  }

  auto
  Pixbuf::composite (const Glib::RefPtr<Pixbuf>& dest,
                     const int dest_x,
                     const int dest_y,
                     const int dest_width,
                     const int dest_height,
                     const double offset_x,
                     const double offset_y,
                     const double scale_x,
                     const double scale_y,
                     InterpType interp_type,
                     const int overall_alpha) const -> void
  {
    gdk_pixbuf_composite (gobj (),
                          Glib::unwrap (dest),
                          dest_x,
                          dest_y,
                          dest_width,
                          dest_height,
                          offset_x,
                          offset_y,
                          scale_x,
                          scale_y,
                          static_cast<GdkInterpType> (interp_type),
                          overall_alpha);
  }

  auto
  Pixbuf::composite_color (const Glib::RefPtr<Pixbuf>& dest,
                           const int dest_x,
                           const int dest_y,
                           const int dest_width,
                           const int dest_height,
                           const double offset_x,
                           const double offset_y,
                           const double scale_x,
                           const double scale_y,
                           InterpType interp_type,
                           const int overall_alpha,
                           const int check_x,
                           const int check_y,
                           const int check_size,
                           const guint32 color1,
                           const guint32 color2) const -> void
  {
    gdk_pixbuf_composite_color (gobj (),
                                Glib::unwrap (dest),
                                dest_x,
                                dest_y,
                                dest_width,
                                dest_height,
                                offset_x,
                                offset_y,
                                scale_x,
                                scale_y,
                                static_cast<GdkInterpType> (interp_type),
                                overall_alpha,
                                check_x,
                                check_y,
                                check_size,
                                color1,
                                color2);
  }

  auto
  Pixbuf::scale_simple (const int dest_width,
                        const int dest_height,
                        InterpType interp_type) const -> Glib::RefPtr<Pixbuf>
  {
    return Glib::wrap (
        gdk_pixbuf_scale_simple (gobj (),
                                 dest_width,
                                 dest_height,
                                 static_cast<GdkInterpType> (interp_type)));
  }

  auto
  Pixbuf::composite_color_simple (const int dest_width,
                                  const int dest_height,
                                  InterpType interp_type,
                                  const int overall_alpha,
                                  const int check_size,
                                  const guint32 color1,
                                  const guint32 color2) const -> Glib::RefPtr<Pixbuf>
  {
    return Glib::wrap (gdk_pixbuf_composite_color_simple (
        gobj (),
        dest_width,
        dest_height,
        static_cast<GdkInterpType> (interp_type),
        overall_alpha,
        check_size,
        color1,
        color2));
  }

  auto
  Pixbuf::rotate_simple (Rotation angle) const -> Glib::RefPtr<Pixbuf>
  {
    return Glib::wrap (
        gdk_pixbuf_rotate_simple (gobj (),
                                  static_cast<GdkPixbufRotation> (angle)));
  }

  auto
  Pixbuf::flip (const bool horizontal) const -> Glib::RefPtr<Pixbuf>
  {
    return Glib::wrap (gdk_pixbuf_flip (gobj (), horizontal));
  }

  auto
  Pixbuf::get_option (const Glib::ustring& key) const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gdk_pixbuf_get_option (const_cast<GdkPixbuf*> (gobj ()), key.c_str ()));
  }

  auto
  Pixbuf::set_option (const Glib::ustring& key, const Glib::ustring& value) -> bool
  {
    return gdk_pixbuf_set_option (gobj (), key.c_str (), value.c_str ());
  }

  auto
  Pixbuf::remove_option (const Glib::ustring& key) -> bool
  {
    return gdk_pixbuf_remove_option (gobj (), key.c_str ());
  }

  auto
  Pixbuf::copy_options (const Glib::RefPtr<Pixbuf>& dest_pixbuf) const -> bool
  {
    return gdk_pixbuf_copy_options (const_cast<GdkPixbuf*> (gobj ()),
                                    Glib::unwrap (dest_pixbuf));
  }

  auto
  Pixbuf::apply_embedded_orientation () -> Glib::RefPtr<Pixbuf>
  {
    return Glib::wrap (gdk_pixbuf_apply_embedded_orientation (gobj ()));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Colorspace>::value,
      "Type Colorspace cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Pixbuf::property_colorspace () const -> Glib::PropertyProxy_ReadOnly<Colorspace>
  {
    return {this, "colorspace"};
  }

  auto
  Pixbuf::property_n_channels () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "n-channels"};
  }

  auto
  Pixbuf::property_has_alpha () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "has-alpha"};
  }

  auto
  Pixbuf::property_bits_per_sample () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "bits-per-sample"};
  }

  auto
  Pixbuf::property_width () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "width"};
  }

  auto
  Pixbuf::property_height () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "height"};
  }

  auto
  Pixbuf::property_rowstride () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "rowstride"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<void*>::value,
      "Type void* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Pixbuf::property_pixels () const -> Glib::PropertyProxy_ReadOnly<void*>
  {
    return {this, "pixels"};
  }

} // namespace Gdk
