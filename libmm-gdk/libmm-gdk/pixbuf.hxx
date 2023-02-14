
#ifndef _GDKMM_PIXBUF_H
#define _GDKMM_PIXBUF_H

#include <libmm-gdk/mm-gdkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <vector>

#include <libmm-cairo/surface.hxx>
#include <libmm-gdk/pixbufformat.hxx>
#include <libmm-gio/icon.hxx>
#include <libmm-gio/inputstream.hxx>
#include <libmm-gio/loadableicon.hxx>
#include <libmm-glib/error.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkPixbuf = struct _GdkPixbuf;
using GdkPixbufClass = struct _GdkPixbufClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{
  class GDKMM_API Pixbuf_Class;
}
#endif

namespace Gdk
{

  enum class Colorspace
  {
    RGB
  };

} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GDKMM_API Value<Gdk::Colorspace>
    : public Glib::Value_Enum<Gdk::Colorspace>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gdk
{

  enum class InterpType
  {
    NEAREST,
    TILES,
    BILINEAR,
    HYPER
  };

} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GDKMM_API Value<Gdk::InterpType>
    : public Glib::Value_Enum<Gdk::InterpType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gdk
{

  class PixbufError : public Glib::Error
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

    GDKMM_API
    PixbufError (Code error_code, const Glib::ustring& error_message);
    GDKMM_API explicit PixbufError (GError* gobject);
    GDKMM_API auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    GDKMM_API static void
    throw_func (GError* gobject);

    friend GDKMM_API void
    wrap_init ();

#endif
  };

} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GDKMM_API Value<Gdk::PixbufError::Code>
    : public Glib::Value_Enum<Gdk::PixbufError::Code>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gdk
{

  class GDKMM_API Pixbuf : public Glib::Object,
                           public Gio::Icon,
                           public Gio::LoadableIcon
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
    explicit Pixbuf (const Glib::ConstructParams& construct_params);
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
    Pixbuf (const ::Cairo::RefPtr<::Cairo::Surface>& src,
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
    create (const ::Cairo::RefPtr<::Cairo::Surface>& src,
            int src_x,
            int src_y,
            int width,
            int height) -> Glib::RefPtr<Pixbuf>;

    auto
    copy () const -> Glib::RefPtr<Pixbuf>;

    static auto
    create (Colorspace colorspace,
            bool has_alpha,
            int bits_per_sample,
            int width,
            int height) -> Glib::RefPtr<Pixbuf>;

    static auto
    create_subpixbuf (const Glib::RefPtr<Pixbuf>& src_pixbuf,
                      int src_x,
                      int src_y,
                      int width,
                      int height) -> Glib::RefPtr<Pixbuf>;

    static auto
    create_from_file (const std::string& filename) -> Glib::RefPtr<Pixbuf>;

    static auto
    create_from_file (const std::string& filename,
                      int width,
                      int height,
                      bool preserve_aspect_ratio = true)
        -> Glib::RefPtr<Pixbuf>;

    static auto
    create_from_resource (const std::string& resource_path)
        -> Glib::RefPtr<Pixbuf>;

    static auto
    create_from_resource (const std::string& resource_path,
                          int width,
                          int height,
                          bool preserve_aspect_ratio = true)
        -> Glib::RefPtr<Pixbuf>;

    static auto
    create_from_data (const guint8* data,
                      Colorspace colorspace,
                      bool has_alpha,
                      int bits_per_sample,
                      int width,
                      int height,
                      int rowstride) -> Glib::RefPtr<Pixbuf>;

    static auto
    create_from_data (const guint8* data,
                      Colorspace colorspace,
                      bool has_alpha,
                      int bits_per_sample,
                      int width,
                      int height,
                      int rowstride,
                      const SlotDestroyData& destroy_slot)
        -> Glib::RefPtr<Pixbuf>;

    static auto
    create_from_xpm_data (const char* const* data) -> Glib::RefPtr<Pixbuf>;

    static auto
    create_from_stream (const Glib::RefPtr<Gio::InputStream>& stream,
                        const Glib::RefPtr<Gio::Cancellable>& cancellable)
        -> Glib::RefPtr<Pixbuf>;
    static auto
    create_from_stream (const Glib::RefPtr<Gio::InputStream>& stream)
        -> Glib::RefPtr<Pixbuf>;

    static auto
    create_from_stream_at_scale (
        const Glib::RefPtr<Gio::InputStream>& stream,
        int width,
        int height,
        bool preserve_aspect_ratio,
        const Glib::RefPtr<Gio::Cancellable>& cancellable)
        -> Glib::RefPtr<Pixbuf>;
    static auto
    create_from_stream_at_scale (const Glib::RefPtr<Gio::InputStream>& stream,
                                 int width,
                                 int height,
                                 bool preserve_aspect_ratio)
        -> Glib::RefPtr<Pixbuf>;

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

    void
    fill (guint32 pixel);

    void
    save (const std::string& filename, const Glib::ustring& type) const;

    void
    save (const std::string& filename,
          const Glib::ustring& type,
          const std::vector<Glib::ustring>& option_keys,
          const std::vector<Glib::ustring>& option_values) const;

#if 0 
  typedef sigc::slot<const char*(gsize)> SlotSave;

  
  void save(const SlotSave& slot, const std::string& type);


  
  typepdef std::map<Glib::ustring, Glib::ustring> SaveValuesMap;

  void save(const SlotSave& slot, const std::string& type, const SaveValuesMap& options);
#endif

    void
    save_to_buffer (gchar*& buffer,
                    gsize& buffer_size,
                    const Glib::ustring& type = "png") const;

    void
    save_to_buffer (gchar*& buffer,
                    gsize& buffer_size,
                    const Glib::ustring& type,
                    const std::vector<Glib::ustring>& option_keys,
                    const std::vector<Glib::ustring>& option_values) const;

    auto
    add_alpha (bool substitute_color, guint8 r, guint8 g, guint8 b) const
        -> Glib::RefPtr<Gdk::Pixbuf>;

    void
    copy_area (int src_x,
               int src_y,
               int width,
               int height,
               const Glib::RefPtr<Gdk::Pixbuf>& dest_pixbuf,
               int dest_x,
               int dest_y) const;

    void
    saturate_and_pixelate (const Glib::RefPtr<Gdk::Pixbuf>& dest,
                           float saturation,
                           bool pixelate) const;

    void
    scale (const Glib::RefPtr<Gdk::Pixbuf>& dest,
           int dest_x,
           int dest_y,
           int dest_width,
           int dest_height,
           double offset_x,
           double offset_y,
           double scale_x,
           double scale_y,
           InterpType interp_type) const;

    void
    composite (const Glib::RefPtr<Gdk::Pixbuf>& dest,
               int dest_x,
               int dest_y,
               int dest_width,
               int dest_height,
               double offset_x,
               double offset_y,
               double scale_x,
               double scale_y,
               InterpType interp_type,
               int overall_alpha) const;

    void
    composite_color (const Glib::RefPtr<Gdk::Pixbuf>& dest,
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
                     guint32 color2) const;

    auto
    scale_simple (int dest_width, int dest_height, InterpType interp_type) const
        -> Glib::RefPtr<Gdk::Pixbuf>;

    auto
    composite_color_simple (int dest_width,
                            int dest_height,
                            InterpType interp_type,
                            int overall_alpha,
                            int check_size,
                            guint32 color1,
                            guint32 color2) const -> Glib::RefPtr<Gdk::Pixbuf>;

    auto
    rotate_simple (Rotation angle) const -> Glib::RefPtr<Gdk::Pixbuf>;

    auto
    flip (bool horizontal = true) const -> Glib::RefPtr<Gdk::Pixbuf>;

    auto
    get_option (const Glib::ustring& key) const -> Glib::ustring;

    auto
    set_option (const Glib::ustring& key, const Glib::ustring& value) -> bool;

    auto
    remove_option (const Glib::ustring& key) -> bool;

    auto
    copy_options (const Glib::RefPtr<Pixbuf>& dest_pixbuf) const -> bool;

    auto
    apply_embedded_orientation () -> Glib::RefPtr<Pixbuf>;

    static auto
    get_formats () -> std::vector<PixbufFormat>;

    auto
    property_colorspace () const -> Glib::PropertyProxy_ReadOnly<Colorspace>;

    auto
    property_n_channels () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_has_alpha () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_bits_per_sample () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_width () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_height () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_rowstride () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_pixels () const -> Glib::PropertyProxy_ReadOnly<void*>;

  public:
  public:
  protected:
  };

} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GDKMM_API Value<Gdk::Pixbuf::Rotation>
    : public Glib::Value_Enum<Gdk::Pixbuf::Rotation>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{

  GDKMM_API
  auto
  wrap (GdkPixbuf* object, bool take_copy = false) -> Glib::RefPtr<Gdk::Pixbuf>;
} // namespace Glib

#endif
