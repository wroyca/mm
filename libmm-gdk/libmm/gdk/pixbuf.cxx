// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/pixbuf.hxx>
#include <libmm/gdk/pixbuf_p.hxx>

#include <libmm/glib/vectorutils.hxx>

#include <gdk-pixbuf/gdk-pixbuf.h>
#include <gdk/gdk.h>

namespace
{

  static auto
  pixbuf_destroy_data_callback (guint8* pixels, void* user_data) -> void
  {
    const auto slot = static_cast<gdk::Pixbuf::SlotDestroyData*> (user_data);
    g_return_if_fail (slot != nullptr);

    try
    {
      (*slot) (pixels);
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
    }

    delete slot;
  }

} // namespace

namespace gdk
{

  Pixbuf::Pixbuf (const ::cairo::RefPtr<::cairo::Surface>& src,
                  int src_x,
                  int src_y,
                  int width,
                  int height)
    : Object ((GObject*) gdk_pixbuf_get_from_surface (src->cobj (),
                                                      src_x,
                                                      src_y,
                                                      width,
                                                      height))
  {
    if (!gobj ())
      throw PixbufError (PixbufError::FAILED,
                         "Could not construct Pixbuf from cairo::Surface");
  }

  auto
  Pixbuf::create_from_data (const guint8* data,
                            Colorspace colorspace,
                            bool has_alpha,
                            int bits_per_sample,
                            int width,
                            int height,
                            int rowstride) -> glib::RefPtr<Pixbuf>
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

    return glib::wrap (pixbuf);
  }

  auto
  Pixbuf::create_from_data (const guint8* data,
                            Colorspace colorspace,
                            bool has_alpha,
                            int bits_per_sample,
                            int width,
                            int height,
                            int rowstride,
                            const Pixbuf::SlotDestroyData& destroy_slot) -> glib::RefPtr<Pixbuf>
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

    return glib::wrap (pixbuf);
  }

  auto
  Pixbuf::create_from_stream (const glib::RefPtr<gio::InputStream>& stream) -> glib::RefPtr<Pixbuf>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (gdk_pixbuf_new_from_stream (
        const_cast<GInputStream*> (glib::unwrap (stream)),
        nullptr,
        &(gerror)));

    if (gerror)
      ::glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  Pixbuf::create_from_stream_at_scale (
      const glib::RefPtr<gio::InputStream>& stream,
      int width,
      int height,
      bool preserve_aspect_ratio) -> glib::RefPtr<Pixbuf>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (gdk_pixbuf_new_from_stream_at_scale (
        const_cast<GInputStream*> (glib::unwrap (stream)),
        width,
        height,
        static_cast<int> (preserve_aspect_ratio),
        nullptr,
        &(gerror)));

    if (gerror)
      ::glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  Pixbuf::save (const std::string& filename, const glib::ustring& type) const -> void
  {
    GError* gerror = nullptr;
    gdk_pixbuf_savev (const_cast<GdkPixbuf*> (gobj ()),
                      filename.c_str (),
                      type.c_str (),
                      nullptr,
                      nullptr,
                      &gerror);

    if (gerror)
      ::glib::Error::throw_exception (gerror);
  }

  auto
  Pixbuf::save (const std::string& filename,
                const glib::ustring& type,
                const std::vector<glib::ustring>& option_keys,
                const std::vector<glib::ustring>& option_values) const -> void
  {
    GError* gerror = nullptr;

    gdk_pixbuf_savev (
        const_cast<GdkPixbuf*> (gobj ()),
        filename.c_str (),
        type.c_str (),
        const_cast<char**> (
            glib::ArrayHandler<glib::ustring>::vector_to_array (option_keys)
                .data ()),
        const_cast<char**> (
            glib::ArrayHandler<glib::ustring>::vector_to_array (option_values)
                .data ()),
        &gerror);

    if (gerror)
      ::glib::Error::throw_exception (gerror);
  }

  auto
  Pixbuf::save_to_buffer (gchar*& buffer,
                          gsize& buffer_size,
                          const glib::ustring& type) const -> void
  {
    GError* gerror = nullptr;

    gdk_pixbuf_save_to_buffer (const_cast<GdkPixbuf*> (gobj ()),
                               &buffer,
                               &buffer_size,
                               type.c_str (),
                               &gerror,
                               nullptr);

    if (gerror)
      ::glib::Error::throw_exception (gerror);
  }

  auto
  Pixbuf::save_to_buffer (gchar*& buffer,
                          gsize& buffer_size,
                          const glib::ustring& type,
                          const std::vector<glib::ustring>& option_keys,
                          const std::vector<glib::ustring>& option_values) const -> void
  {
    GError* gerror = nullptr;

    gdk_pixbuf_save_to_bufferv (
        const_cast<GdkPixbuf*> (gobj ()),
        &buffer,
        &buffer_size,
        type.c_str (),
        const_cast<char**> (
            glib::ArrayHandler<glib::ustring>::vector_to_array (option_keys)
                .data ()),
        const_cast<char**> (
            glib::ArrayHandler<glib::ustring>::vector_to_array (option_values)
                .data ()),
        &gerror);

    if (gerror)
      ::glib::Error::throw_exception (gerror);
  }

  auto
  Pixbuf::get_formats () -> std::vector<PixbufFormat>
  {
    return glib::SListHandler<PixbufFormat, PixbufFormatTraits>::
        slist_to_vector (gdk_pixbuf_get_formats (), glib::OWNERSHIP_SHALLOW);
  }

  auto
  Pixbuf::get_pixels (guint& length) const -> const guint8*
  {
    length = get_byte_length ();
    return gdk_pixbuf_read_pixels (const_cast<GdkPixbuf*> (gobj ()));
  }

} // namespace gdk

namespace
{
}

auto
glib::Value<gdk::Colorspace>::value_type () -> GType
{
  return gdk_colorspace_get_type ();
}

auto
glib::Value<gdk::InterpType>::value_type () -> GType
{
  return gdk_interp_type_get_type ();
}

gdk::PixbufError::PixbufError (gdk::PixbufError::Code error_code,
                               const glib::ustring& error_message)
  : glib::Error (GDK_PIXBUF_ERROR, error_code, error_message)
{
}

gdk::PixbufError::PixbufError (GError* gobject)
  : glib::Error (gobject)
{
}

auto
gdk::PixbufError::code () const -> gdk::PixbufError::Code
{
  return static_cast<Code> (glib::Error::code ());
}

auto
gdk::PixbufError::throw_func (GError* gobject) -> void
{
  throw gdk::PixbufError (gobject);
}

auto
glib::Value<gdk::PixbufError::Code>::value_type () -> GType
{
  return gdk_pixbuf_error_get_type ();
}

auto
glib::Value<gdk::Pixbuf::Rotation>::value_type () -> GType
{
  return gdk_pixbuf_rotation_get_type ();
}

namespace glib
{

  auto
  wrap (GdkPixbuf* object, bool take_copy) -> glib::RefPtr<gdk::Pixbuf>
  {
    return glib::make_refptr_for_instance<gdk::Pixbuf> (
        dynamic_cast<gdk::Pixbuf*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gdk
{

  auto
  Pixbuf_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Pixbuf_Class::class_init_function;

      register_derived_type (gdk_pixbuf_get_type ());

      gio::Icon::add_interface (get_type ());
      gio::LoadableIcon::add_interface (get_type ());
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
  Pixbuf_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Pixbuf ((GdkPixbuf*) object);
  }

  auto
  Pixbuf::gobj_copy () -> GdkPixbuf*
  {
    reference ();
    return gobj ();
  }

  Pixbuf::Pixbuf (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  Pixbuf::Pixbuf (GdkPixbuf* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  Pixbuf::Pixbuf (Pixbuf&& src) noexcept
    : glib::Object (std::move (src)),
      gio::Icon (std::move (src)),
      gio::LoadableIcon (std::move (src))
  {
  }

  auto
  Pixbuf::operator= (Pixbuf&& src) noexcept -> Pixbuf&
  {
    glib::Object::operator= (std::move (src));
    gio::Icon::operator= (std::move (src));
    gio::LoadableIcon::operator= (std::move (src));
    return *this;
  }

  Pixbuf::~Pixbuf () noexcept {}

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
  Pixbuf::create (const ::cairo::RefPtr<::cairo::Surface>& src,
                  int src_x,
                  int src_y,
                  int width,
                  int height) -> glib::RefPtr<Pixbuf>
  {
    return glib::make_refptr_for_instance<Pixbuf> (
        new Pixbuf (src, src_x, src_y, width, height));
  }

  auto
  Pixbuf::copy () const -> glib::RefPtr<Pixbuf>
  {
    return glib::wrap (gdk_pixbuf_copy (const_cast<GdkPixbuf*> (gobj ())));
  }

  auto
  Pixbuf::create (Colorspace colorspace,
                  bool has_alpha,
                  int bits_per_sample,
                  int width,
                  int height) -> glib::RefPtr<Pixbuf>
  {
    return glib::wrap (gdk_pixbuf_new (static_cast<GdkColorspace> (colorspace),
                                       static_cast<int> (has_alpha),
                                       bits_per_sample,
                                       width,
                                       height));
  }

  auto
  Pixbuf::create_subpixbuf (const glib::RefPtr<Pixbuf>& src_pixbuf,
                            int src_x,
                            int src_y,
                            int width,
                            int height) -> glib::RefPtr<Pixbuf>
  {
    return glib::wrap (gdk_pixbuf_new_subpixbuf (glib::unwrap (src_pixbuf),
                                                 src_x,
                                                 src_y,
                                                 width,
                                                 height));
  }

  auto
  Pixbuf::create_from_file (const std::string& filename) -> glib::RefPtr<Pixbuf>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::wrap (gdk_pixbuf_new_from_file (filename.c_str (), &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Pixbuf::create_from_file (const std::string& filename,
                            int width,
                            int height,
                            bool preserve_aspect_ratio) -> glib::RefPtr<Pixbuf>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (gdk_pixbuf_new_from_file_at_scale (
        filename.c_str (),
        width,
        height,
        static_cast<int> (preserve_aspect_ratio),
        &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Pixbuf::create_from_resource (const std::string& resource_path) -> glib::RefPtr<Pixbuf>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (
        gdk_pixbuf_new_from_resource (resource_path.c_str (), &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Pixbuf::create_from_resource (const std::string& resource_path,
                                int width,
                                int height,
                                bool preserve_aspect_ratio) -> glib::RefPtr<Pixbuf>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (gdk_pixbuf_new_from_resource_at_scale (
        resource_path.c_str (),
        width,
        height,
        static_cast<int> (preserve_aspect_ratio),
        &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Pixbuf::create_from_xpm_data (const char* const* data) -> glib::RefPtr<Pixbuf>
  {
    return glib::wrap (
        gdk_pixbuf_new_from_xpm_data (const_cast<const char**> (data)));
  }

  auto
  Pixbuf::create_from_stream (const glib::RefPtr<gio::InputStream>& stream,
                              const glib::RefPtr<gio::Cancellable>& cancellable) -> glib::RefPtr<Pixbuf>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (gdk_pixbuf_new_from_stream (
        const_cast<GInputStream*> (glib::unwrap (stream)),
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Pixbuf::create_from_stream_at_scale (
      const glib::RefPtr<gio::InputStream>& stream,
      int width,
      int height,
      bool preserve_aspect_ratio,
      const glib::RefPtr<gio::Cancellable>& cancellable) -> glib::RefPtr<Pixbuf>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (gdk_pixbuf_new_from_stream_at_scale (
        const_cast<GInputStream*> (glib::unwrap (stream)),
        width,
        height,
        static_cast<int> (preserve_aspect_ratio),
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Pixbuf::get_colorspace () const -> Colorspace
  {
    return static_cast<Colorspace> (
        gdk_pixbuf_get_colorspace (const_cast<GdkPixbuf*> (gobj ())));
  }

  auto
  Pixbuf::get_n_channels () const -> int
  {
    return gdk_pixbuf_get_n_channels (const_cast<GdkPixbuf*> (gobj ()));
  }

  auto
  Pixbuf::get_has_alpha () const -> bool
  {
    return gdk_pixbuf_get_has_alpha (const_cast<GdkPixbuf*> (gobj ()));
  }

  auto
  Pixbuf::get_bits_per_sample () const -> int
  {
    return gdk_pixbuf_get_bits_per_sample (const_cast<GdkPixbuf*> (gobj ()));
  }

  auto
  Pixbuf::get_pixels () -> guint8*
  {
    return gdk_pixbuf_get_pixels (gobj ());
  }

  auto
  Pixbuf::get_pixels () const -> const guint8*
  {
    return gdk_pixbuf_read_pixels (const_cast<GdkPixbuf*> (gobj ()));
  }

  auto
  Pixbuf::get_pixels (guint& length) -> guint8*
  {
    return gdk_pixbuf_get_pixels_with_length (gobj (), &(length));
  }

  auto
  Pixbuf::get_width () const -> int
  {
    return gdk_pixbuf_get_width (const_cast<GdkPixbuf*> (gobj ()));
  }

  auto
  Pixbuf::get_height () const -> int
  {
    return gdk_pixbuf_get_height (const_cast<GdkPixbuf*> (gobj ()));
  }

  auto
  Pixbuf::get_rowstride () const -> int
  {
    return gdk_pixbuf_get_rowstride (const_cast<GdkPixbuf*> (gobj ()));
  }

  auto
  Pixbuf::get_byte_length () const -> gsize
  {
    return gdk_pixbuf_get_byte_length (const_cast<GdkPixbuf*> (gobj ()));
  }

  auto
  Pixbuf::fill (guint32 pixel) -> void
  {
    gdk_pixbuf_fill (gobj (), pixel);
  }

  auto
  Pixbuf::add_alpha (bool substitute_color, guint8 r, guint8 g, guint8 b) const -> glib::RefPtr<gdk::Pixbuf>
  {
    return glib::wrap (
        gdk_pixbuf_add_alpha (const_cast<GdkPixbuf*> (gobj ()),
                              static_cast<int> (substitute_color),
                              r,
                              g,
                              b));
  }

  auto
  Pixbuf::copy_area (int src_x,
                     int src_y,
                     int width,
                     int height,
                     const glib::RefPtr<gdk::Pixbuf>& dest_pixbuf,
                     int dest_x,
                     int dest_y) const -> void
  {
    gdk_pixbuf_copy_area (const_cast<GdkPixbuf*> (gobj ()),
                          src_x,
                          src_y,
                          width,
                          height,
                          glib::unwrap (dest_pixbuf),
                          dest_x,
                          dest_y);
  }

  auto
  Pixbuf::saturate_and_pixelate (const glib::RefPtr<gdk::Pixbuf>& dest,
                                 float saturation,
                                 bool pixelate) const -> void
  {
    gdk_pixbuf_saturate_and_pixelate (const_cast<GdkPixbuf*> (gobj ()),
                                      glib::unwrap (dest),
                                      saturation,
                                      static_cast<int> (pixelate));
  }

  auto
  Pixbuf::scale (const glib::RefPtr<gdk::Pixbuf>& dest,
                 int dest_x,
                 int dest_y,
                 int dest_width,
                 int dest_height,
                 double offset_x,
                 double offset_y,
                 double scale_x,
                 double scale_y,
                 InterpType interp_type) const -> void
  {
    gdk_pixbuf_scale (const_cast<GdkPixbuf*> (gobj ()),
                      glib::unwrap (dest),
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
  Pixbuf::composite (const glib::RefPtr<gdk::Pixbuf>& dest,
                     int dest_x,
                     int dest_y,
                     int dest_width,
                     int dest_height,
                     double offset_x,
                     double offset_y,
                     double scale_x,
                     double scale_y,
                     InterpType interp_type,
                     int overall_alpha) const -> void
  {
    gdk_pixbuf_composite (const_cast<GdkPixbuf*> (gobj ()),
                          glib::unwrap (dest),
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
  Pixbuf::composite_color (const glib::RefPtr<gdk::Pixbuf>& dest,
                           int dest_x,
                           int dest_y,
                           int dest_width,
                           int dest_height,
                           double offset_x,
                           double offset_y,
                           double scale_x,
                           double scale_y,
                           InterpType interp_type,
                           int overall_alpha,
                           int check_x,
                           int check_y,
                           int check_size,
                           guint32 color1,
                           guint32 color2) const -> void
  {
    gdk_pixbuf_composite_color (const_cast<GdkPixbuf*> (gobj ()),
                                glib::unwrap (dest),
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
  Pixbuf::scale_simple (int dest_width,
                        int dest_height,
                        InterpType interp_type) const -> glib::RefPtr<gdk::Pixbuf>
  {
    return glib::wrap (
        gdk_pixbuf_scale_simple (const_cast<GdkPixbuf*> (gobj ()),
                                 dest_width,
                                 dest_height,
                                 static_cast<GdkInterpType> (interp_type)));
  }

  auto
  Pixbuf::composite_color_simple (int dest_width,
                                  int dest_height,
                                  InterpType interp_type,
                                  int overall_alpha,
                                  int check_size,
                                  guint32 color1,
                                  guint32 color2) const -> glib::RefPtr<gdk::Pixbuf>
  {
    return glib::wrap (gdk_pixbuf_composite_color_simple (
        const_cast<GdkPixbuf*> (gobj ()),
        dest_width,
        dest_height,
        static_cast<GdkInterpType> (interp_type),
        overall_alpha,
        check_size,
        color1,
        color2));
  }

  auto
  Pixbuf::rotate_simple (Rotation angle) const -> glib::RefPtr<gdk::Pixbuf>
  {
    return glib::wrap (
        gdk_pixbuf_rotate_simple (const_cast<GdkPixbuf*> (gobj ()),
                                  static_cast<GdkPixbufRotation> (angle)));
  }

  auto
  Pixbuf::flip (bool horizontal) const -> glib::RefPtr<gdk::Pixbuf>
  {
    return glib::wrap (gdk_pixbuf_flip (const_cast<GdkPixbuf*> (gobj ()),
                                        static_cast<int> (horizontal)));
  }

  auto
  Pixbuf::get_option (const glib::ustring& key) const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gdk_pixbuf_get_option (const_cast<GdkPixbuf*> (gobj ()), key.c_str ()));
  }

  auto
  Pixbuf::set_option (const glib::ustring& key, const glib::ustring& value) -> bool
  {
    return gdk_pixbuf_set_option (gobj (), key.c_str (), value.c_str ());
  }

  auto
  Pixbuf::remove_option (const glib::ustring& key) -> bool
  {
    return gdk_pixbuf_remove_option (gobj (), key.c_str ());
  }

  auto
  Pixbuf::copy_options (const glib::RefPtr<Pixbuf>& dest_pixbuf) const -> bool
  {
    return gdk_pixbuf_copy_options (const_cast<GdkPixbuf*> (gobj ()),
                                    glib::unwrap (dest_pixbuf));
  }

  auto
  Pixbuf::apply_embedded_orientation () -> glib::RefPtr<Pixbuf>
  {
    return glib::wrap (gdk_pixbuf_apply_embedded_orientation (gobj ()));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Colorspace>::value,
      "Type Colorspace cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Pixbuf::property_colorspace () const -> glib::PropertyProxy_ReadOnly<Colorspace>
  {
    return glib::PropertyProxy_ReadOnly<Colorspace> (this, "colorspace");
  }

  auto
  Pixbuf::property_n_channels () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "n-channels");
  }

  auto
  Pixbuf::property_has_alpha () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "has-alpha");
  }

  auto
  Pixbuf::property_bits_per_sample () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "bits-per-sample");
  }

  auto
  Pixbuf::property_width () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "width");
  }

  auto
  Pixbuf::property_height () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "height");
  }

  auto
  Pixbuf::property_rowstride () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "rowstride");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<void*>::value,
      "Type void* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Pixbuf::property_pixels () const -> glib::PropertyProxy_ReadOnly<void*>
  {
    return glib::PropertyProxy_ReadOnly<void*> (this, "pixels");
  }

} // namespace gdk
