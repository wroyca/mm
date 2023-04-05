// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_PIXBUF_H
#define _GDKMM_PIXBUF_H

#include <libmm/gdk/mm-gdkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <vector>

#include <libmm/cairo/surface.hxx>
#include <libmm/gdk/pixbufformat.hxx>
#include <libmm/gio/icon.hxx>
#include <libmm/gio/inputstream.hxx>
#include <libmm/gio/loadableicon.hxx>
#include <libmm/glib/error.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkPixbuf = struct _GdkPixbuf;
using GdkPixbufClass = struct _GdkPixbufClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gdk
{
  class LIBMM_GDK_SYMEXPORT Pixbuf_Class;
}
#endif

namespace gdk
{

  enum class Colorspace
  {
    RGB
  };

} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::Colorspace>
    : public glib::Value_Enum<gdk::Colorspace>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gdk
{

  enum class InterpType
  {
    NEAREST,
    TILES,
    BILINEAR,
    HYPER
  };

} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::InterpType>
    : public glib::Value_Enum<gdk::InterpType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gdk
{

  class PixbufError : public glib::Error
  {
  public:
    enum Code
    {
      CORRUPT_IMAGE,
      INSUFFICIENT_MEMORY,
      BAD_OPTION,
      UNKNOWN_TYPE,
      UNSUPPORTED_OPERATION,
      FAILED,
      INCOMPLETE_ANIMATION
    };

    LIBMM_GDK_SYMEXPORT
    PixbufError (Code error_code, const glib::ustring& error_message);
    LIBMM_GDK_SYMEXPORT explicit PixbufError (GError* gobject);
    LIBMM_GDK_SYMEXPORT auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    LIBMM_GDK_SYMEXPORT static auto
    throw_func (GError* gobject) -> void;

    friend LIBMM_GDK_SYMEXPORT auto
    wrap_init () -> void;

#endif
  };

} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::PixbufError::Code>
    : public glib::Value_Enum<gdk::PixbufError::Code>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT Pixbuf : public glib::Object,
                           public gio::Icon,
                           public gio::LoadableIcon
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Pixbuf;
    using CppClassType = Pixbuf_Class;
    using BaseObjectType = GdkPixbuf;
    using BaseClassType = GdkPixbufClass;

    Pixbuf (const Pixbuf&) = delete;
    auto
    operator= (const Pixbuf&) -> Pixbuf& = delete;

  private:
    friend class Pixbuf_Class;
    static CppClassType pixbuf_class_;

  protected:
    explicit Pixbuf (const glib::ConstructParams& construct_params);
    explicit Pixbuf (GdkPixbuf* castitem);

#endif

  public:
    Pixbuf (Pixbuf&& src) noexcept;
    auto
    operator= (Pixbuf&& src) noexcept -> Pixbuf&;

    ~Pixbuf () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkPixbuf*
    {
      return reinterpret_cast<GdkPixbuf*> (gobject_);
    }

    auto
    gobj () const -> const GdkPixbuf*
    {
      return reinterpret_cast<GdkPixbuf*> (gobject_);
    }

    auto
    gobj_copy () -> GdkPixbuf*;

  private:
  protected:
    Pixbuf (const ::cairo::RefPtr<::cairo::Surface>& src,
            int src_x,
            int src_y,
            int width,
            int height);

  public:
    enum class Rotation
    {
      NONE = 0,
      COUNTERCLOCKWISE = 90,
      UPSIDEDOWN = 180,
      CLOCKWISE = 270
    };

    using SlotDestroyData = sigc::slot<void (const guint8*)>;

    static auto
    create (const ::cairo::RefPtr<::cairo::Surface>& src,
            int src_x,
            int src_y,
            int width,
            int height) -> glib::RefPtr<Pixbuf>;

    auto
    copy () const -> glib::RefPtr<Pixbuf>;

    static auto
    create (Colorspace colorspace,
            bool has_alpha,
            int bits_per_sample,
            int width,
            int height) -> glib::RefPtr<Pixbuf>;

    static auto
    create_subpixbuf (const glib::RefPtr<Pixbuf>& src_pixbuf,
                      int src_x,
                      int src_y,
                      int width,
                      int height) -> glib::RefPtr<Pixbuf>;

    static auto
    create_from_file (const std::string& filename) -> glib::RefPtr<Pixbuf>;

    static auto
    create_from_file (const std::string& filename,
                      int width,
                      int height,
                      bool preserve_aspect_ratio = true)
        -> glib::RefPtr<Pixbuf>;

    static auto
    create_from_resource (const std::string& resource_path)
        -> glib::RefPtr<Pixbuf>;

    static auto
    create_from_resource (const std::string& resource_path,
                          int width,
                          int height,
                          bool preserve_aspect_ratio = true)
        -> glib::RefPtr<Pixbuf>;

    static auto
    create_from_data (const guint8* data,
                      Colorspace colorspace,
                      bool has_alpha,
                      int bits_per_sample,
                      int width,
                      int height,
                      int rowstride) -> glib::RefPtr<Pixbuf>;

    static auto
    create_from_data (const guint8* data,
                      Colorspace colorspace,
                      bool has_alpha,
                      int bits_per_sample,
                      int width,
                      int height,
                      int rowstride,
                      const SlotDestroyData& destroy_slot)
        -> glib::RefPtr<Pixbuf>;

    static auto
    create_from_xpm_data (const char* const* data) -> glib::RefPtr<Pixbuf>;

    static auto
    create_from_stream (const glib::RefPtr<gio::InputStream>& stream,
                        const glib::RefPtr<gio::Cancellable>& cancellable)
        -> glib::RefPtr<Pixbuf>;
    static auto
    create_from_stream (const glib::RefPtr<gio::InputStream>& stream)
        -> glib::RefPtr<Pixbuf>;

    static auto
    create_from_stream_at_scale (
        const glib::RefPtr<gio::InputStream>& stream,
        int width,
        int height,
        bool preserve_aspect_ratio,
        const glib::RefPtr<gio::Cancellable>& cancellable)
        -> glib::RefPtr<Pixbuf>;
    static auto
    create_from_stream_at_scale (const glib::RefPtr<gio::InputStream>& stream,
                                 int width,
                                 int height,
                                 bool preserve_aspect_ratio)
        -> glib::RefPtr<Pixbuf>;

    auto
    get_colorspace () const -> Colorspace;

    auto
    get_n_channels () const -> int;

    auto
    get_has_alpha () const -> bool;

    auto
    get_bits_per_sample () const -> int;

    auto
    get_pixels () -> guint8*;

    auto
    get_pixels () const -> const guint8*;

    auto
    get_pixels (guint& length) -> guint8*;

    auto
    get_pixels (guint& length) const -> const guint8*;

    auto
    get_width () const -> int;

    auto
    get_height () const -> int;

    auto
    get_rowstride () const -> int;

    auto
    get_byte_length () const -> gsize;

    auto
    fill (guint32 pixel) -> void;

    auto
    save (const std::string& filename, const glib::ustring& type) const -> void;

    auto
    save (const std::string& filename,
          const glib::ustring& type,
          const std::vector<glib::ustring>& option_keys,
          const std::vector<glib::ustring>& option_values) const -> void;

#if 0
  typedef sigc::slot<const char*(gsize)> SlotSave;


  void save(const SlotSave& slot, const std::string& type);



  typepdef std::map<glib::ustring, glib::ustring> SaveValuesMap;

  void save(const SlotSave& slot, const std::string& type, const SaveValuesMap& options);
#endif

    auto
    save_to_buffer (gchar*& buffer,
                    gsize& buffer_size,
                    const glib::ustring& type = "png") const -> void;

    auto
    save_to_buffer (gchar*& buffer,
                    gsize& buffer_size,
                    const glib::ustring& type,
                    const std::vector<glib::ustring>& option_keys,
                    const std::vector<glib::ustring>& option_values) const
        -> void;

    auto
    add_alpha (bool substitute_color, guint8 r, guint8 g, guint8 b) const
        -> glib::RefPtr<gdk::Pixbuf>;

    auto
    copy_area (int src_x,
               int src_y,
               int width,
               int height,
               const glib::RefPtr<gdk::Pixbuf>& dest_pixbuf,
               int dest_x,
               int dest_y) const -> void;

    auto
    saturate_and_pixelate (const glib::RefPtr<gdk::Pixbuf>& dest,
                           float saturation,
                           bool pixelate) const -> void;

    auto
    scale (const glib::RefPtr<gdk::Pixbuf>& dest,
           int dest_x,
           int dest_y,
           int dest_width,
           int dest_height,
           double offset_x,
           double offset_y,
           double scale_x,
           double scale_y,
           InterpType interp_type) const -> void;

    auto
    composite (const glib::RefPtr<gdk::Pixbuf>& dest,
               int dest_x,
               int dest_y,
               int dest_width,
               int dest_height,
               double offset_x,
               double offset_y,
               double scale_x,
               double scale_y,
               InterpType interp_type,
               int overall_alpha) const -> void;

    auto
    composite_color (const glib::RefPtr<gdk::Pixbuf>& dest,
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
                     guint32 color2) const -> void;

    auto
    scale_simple (int dest_width, int dest_height, InterpType interp_type) const
        -> glib::RefPtr<gdk::Pixbuf>;

    auto
    composite_color_simple (int dest_width,
                            int dest_height,
                            InterpType interp_type,
                            int overall_alpha,
                            int check_size,
                            guint32 color1,
                            guint32 color2) const -> glib::RefPtr<gdk::Pixbuf>;

    auto
    rotate_simple (Rotation angle) const -> glib::RefPtr<gdk::Pixbuf>;

    auto
    flip (bool horizontal = true) const -> glib::RefPtr<gdk::Pixbuf>;

    auto
    get_option (const glib::ustring& key) const -> glib::ustring;

    auto
    set_option (const glib::ustring& key, const glib::ustring& value) -> bool;

    auto
    remove_option (const glib::ustring& key) -> bool;

    auto
    copy_options (const glib::RefPtr<Pixbuf>& dest_pixbuf) const -> bool;

    auto
    apply_embedded_orientation () -> glib::RefPtr<Pixbuf>;

    static auto
    get_formats () -> std::vector<PixbufFormat>;

    auto
    property_colorspace () const -> glib::PropertyProxy_ReadOnly<Colorspace>;

    auto
    property_n_channels () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_has_alpha () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_bits_per_sample () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_width () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_height () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_rowstride () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_pixels () const -> glib::PropertyProxy_ReadOnly<void*>;

  public:
  public:
  protected:
  };

} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::Pixbuf::Rotation>
    : public glib::Value_Enum<gdk::Pixbuf::Rotation>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkPixbuf* object, bool take_copy = false) -> glib::RefPtr<gdk::Pixbuf>;
} // namespace glib

#endif
