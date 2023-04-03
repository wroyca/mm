// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef __CAIROMM_SURFACE_H
#define __CAIROMM_SURFACE_H

#include <string>
#include <vector>

#include <sigc++/slot.h>

#include <libmm/cairo/device.hxx>
#include <libmm/cairo/enums.hxx>
#include <libmm/cairo/exception.hxx>
#include <libmm/cairo/fontoptions.hxx>
#include <libmm/cairo/refptr.hxx>

#ifdef CAIRO_HAS_PDF_SURFACE
  #include <cairo-pdf.h>
#endif
#ifdef CAIRO_HAS_PS_SURFACE
  #include <cairo-ps.h>
#endif
#ifdef CAIRO_HAS_SVG_SURFACE
  #include <cairo-svg.h>
#endif

#ifdef CAIRO_HAS_GLITZ_SURFACE
  #include <cairo-glitz.h>
#endif

namespace Cairo
{

  class LIBMM_CAIRO_SYMEXPORT Surface
  {
  public:
    enum class Type
    {
      IMAGE = CAIRO_SURFACE_TYPE_IMAGE,

      PDF = CAIRO_SURFACE_TYPE_PDF,

      PS = CAIRO_SURFACE_TYPE_PS,

      XLIB = CAIRO_SURFACE_TYPE_XLIB,

      XCB = CAIRO_SURFACE_TYPE_XCB,

      GLITZ = CAIRO_SURFACE_TYPE_GLITZ,

      QUARTZ = CAIRO_SURFACE_TYPE_QUARTZ,

#if !defined(WIN32) && !defined(CAIROMM_DISABLE_DEPRECATED)

      WIN32 = CAIRO_SURFACE_TYPE_WIN32,
#endif

      WIN32_SURFACE = CAIRO_SURFACE_TYPE_WIN32,

      BEOS = CAIRO_SURFACE_TYPE_BEOS,

      DIRECTFB = CAIRO_SURFACE_TYPE_DIRECTFB,

      SVG = CAIRO_SURFACE_TYPE_SVG,

      OS2 = CAIRO_SURFACE_TYPE_OS2,

      WIN32_PRINTING = CAIRO_SURFACE_TYPE_WIN32_PRINTING,

      QUARTZ_IMAGE = CAIRO_SURFACE_TYPE_QUARTZ_IMAGE,

      SCRIPT = CAIRO_SURFACE_TYPE_SCRIPT,

      QT = CAIRO_SURFACE_TYPE_QT,

      RECORDING = CAIRO_SURFACE_TYPE_RECORDING,

      VG = CAIRO_SURFACE_TYPE_VG,

      GL = CAIRO_SURFACE_TYPE_GL,

      DRM = CAIRO_SURFACE_TYPE_DRM,

      TEE = CAIRO_SURFACE_TYPE_TEE,

      XML = CAIRO_SURFACE_TYPE_XML,

      SKIA = CAIRO_SURFACE_TYPE_SKIA,

      SUBSURFACE = CAIRO_SURFACE_TYPE_SUBSURFACE
    };

    enum class Format
    {
      ARGB32 = CAIRO_FORMAT_ARGB32,

      RGB24 = CAIRO_FORMAT_RGB24,

      A8 = CAIRO_FORMAT_A8,

      A1 = CAIRO_FORMAT_A1,

      RGB16_565 = CAIRO_FORMAT_RGB16_565
    };

    typedef sigc::slot<ErrorStatus (const unsigned char*, unsigned int)>
        SlotWriteFunc;

    typedef sigc::slot<ErrorStatus (unsigned char*, unsigned int)> SlotReadFunc;

    explicit Surface (cairo_surface_t* cobject, bool has_reference = false);

    Surface (const Surface&) = delete;
    auto
    operator= (const Surface&) -> Surface& = delete;

    virtual ~Surface ();

    auto
    get_mime_data (const std::string& mime_type, unsigned long& length) -> const
        unsigned char*;

    typedef sigc::slot<void ()> SlotDestroy;

    auto
    set_mime_data (const std::string& mime_type,
                   unsigned char* data,
                   unsigned long length,
                   const SlotDestroy& slot_destroy) -> void;

    auto
    unset_mime_data (const std::string& mime_type) -> void;

    auto
    get_font_options (FontOptions& options) const -> void;

    auto
    finish () -> void;

    auto
    flush () -> void;

    auto
    mark_dirty () -> void;

    auto
    mark_dirty (int x, int y, int width, int height) -> void;

    auto
    set_device_offset (double x_offset, double y_offset) -> void;

    auto
    get_device_offset (double& x_offset, double& y_offset) const -> void;

    auto
    set_device_scale (double x_scale, double y_scale) -> void;

    inline auto
    set_device_scale (double scale) -> void
    {
      set_device_scale (scale, scale);
    }

    auto
    get_device_scale (double& x_scale, double& y_scale) const -> void;

    auto
    get_device_scale () const -> double;

    auto
    set_fallback_resolution (double x_pixels_per_inch, double y_pixels_per_inch)
        -> void;

    auto
    get_fallback_resolution (double& x_pixels_per_inch,
                             double& y_pixels_per_inch) const -> void;

    auto
    get_type () const -> Type;

    auto
    get_content () const -> Content;

    auto
    copy_page () -> void;

    auto
    show_page () -> void;

    auto
    has_show_text_glyphs () const -> bool;

#ifdef CAIRO_HAS_PNG_FUNCTIONS

    auto
    write_to_png (const std::string& filename) -> void;

    auto
    write_to_png_stream (const SlotWriteFunc& write_func) -> void;

#endif

    auto
    get_device () -> RefPtr<Device>;

    typedef cairo_surface_t cobject;

    inline auto
    cobj () -> cobject*
    {
      return m_cobject;
    }

    inline auto
    cobj () const -> const cobject*
    {
      return m_cobject;
    }

#ifndef DOXYGEN_IGNORE_THIS

    inline auto
    get_status () const -> ErrorStatus
    {
      return cairo_surface_status (const_cast<cairo_surface_t*> (cobj ()));
    }

    auto
    reference () const -> void;
    auto
    unreference () const -> void;
#endif

    static auto
    create (const RefPtr<Surface> other, Content content, int width, int height)
        -> RefPtr<Surface>;

    static auto
    create (const RefPtr<Surface>& target,
            double x,
            double y,
            double width,
            double height) -> RefPtr<Surface>;

  protected:
    cobject* m_cobject;
  };

  class LIBMM_CAIRO_SYMEXPORT ImageSurface : public Surface
  {
  protected:
  public:
    explicit ImageSurface (cairo_surface_t* cobject,
                           bool has_reference = false);

    ~ImageSurface () override;

    auto
    get_width () const -> int;

    auto
    get_height () const -> int;

    auto
    get_data () -> unsigned char*;
    auto
    get_data () const -> const unsigned char*;

    auto
    get_format () const -> Format;

    auto
    get_stride () const -> int;

    static auto
    format_stride_for_width (Format format, int width) -> int;

    static auto
    create (Format format, int width, int height) -> RefPtr<ImageSurface>;

    static auto
    create (unsigned char* data,
            Format format,
            int width,
            int height,
            int stride) -> RefPtr<ImageSurface>;

#ifdef CAIRO_HAS_PNG_FUNCTIONS

    static auto
    create_from_png (std::string filename) -> RefPtr<ImageSurface>;

    static auto
    create_from_png_stream (const SlotReadFunc& read_func)
        -> RefPtr<ImageSurface>;

#endif
  };

  class LIBMM_CAIRO_SYMEXPORT RecordingSurface : public Surface
  {
  public:
    explicit RecordingSurface (cairo_surface_t* cobject,
                               bool has_reference = false);

    ~RecordingSurface () override;

    auto
    ink_extents () const -> Rectangle;

    auto
    get_extents (Rectangle& extents) const -> bool;

    static auto
    create (Content content = Content::CONTENT_COLOR_ALPHA)
        -> RefPtr<RecordingSurface>;

    static auto
    create (const Rectangle& extents,
            Content content = Content::CONTENT_COLOR_ALPHA)
        -> RefPtr<RecordingSurface>;
  };

#ifdef CAIRO_HAS_PDF_SURFACE

  typedef enum
  {
    PDF_VERSION_1_4 = CAIRO_PDF_VERSION_1_4,
    PDF_VERSION_1_5 = CAIRO_PDF_VERSION_1_5
  } PdfVersion;

  class LIBMM_CAIRO_SYMEXPORT PdfSurface : public Surface
  {
  public:
    explicit PdfSurface (cairo_surface_t* cobject, bool has_reference = false);
    ~PdfSurface () override;

    static auto
    create (std::string filename,
            double width_in_points,
            double height_in_points) -> RefPtr<PdfSurface>;

    static auto
    create_for_stream (const SlotWriteFunc& write_func,
                       double width_in_points,
                       double height_in_points) -> RefPtr<PdfSurface>;

    auto
    set_size (double width_in_points, double height_in_points) -> void;

    auto
    restrict_to_version (PdfVersion version) -> void;

    static auto
    get_versions () -> const std::vector<PdfVersion>;

    static auto
    version_to_string (PdfVersion version) -> std::string;
  };

#endif

#ifdef CAIRO_HAS_PS_SURFACE

  typedef enum
  {
    PS_LEVEL_2 = CAIRO_PS_LEVEL_2,
    PS_LEVEL_3 = CAIRO_PS_LEVEL_3
  } PsLevel;

  class LIBMM_CAIRO_SYMEXPORT PsSurface : public Surface
  {
  public:
    explicit PsSurface (cairo_surface_t* cobject, bool has_reference = false);
    ~PsSurface () override;

    static auto
    create (std::string filename,
            double width_in_points,
            double height_in_points) -> RefPtr<PsSurface>;

    static auto
    create_for_stream (const SlotWriteFunc& write_func,
                       double width_in_points,
                       double height_in_points) -> RefPtr<PsSurface>;

    auto
    set_size (double width_in_points, double height_in_points) -> void;

    auto
    dsc_comment (std::string comment) -> void;

    auto
    dsc_begin_setup () -> void;

    auto
    dsc_begin_page_setup () -> void;

    auto
    set_eps (bool eps) -> void;

    auto
    get_eps () const -> bool;

    auto
    restrict_to_level (PsLevel level) -> void;

    static auto
    get_levels () -> const std::vector<PsLevel>;

    static auto
    level_to_string (PsLevel level) -> std::string;
  };

#endif

#ifdef CAIRO_HAS_SVG_SURFACE

  typedef enum
  {
    SVG_VERSION_1_1 = CAIRO_SVG_VERSION_1_1,
    SVG_VERSION_1_2 = CAIRO_SVG_VERSION_1_2
  } SvgVersion;

  class LIBMM_CAIRO_SYMEXPORT SvgSurface : public Surface
  {
  public:
    explicit SvgSurface (cairo_surface_t* cobject, bool has_reference = false);
    ~SvgSurface () override;

    static auto
    create (std::string filename,
            double width_in_points,
            double height_in_points) -> RefPtr<SvgSurface>;

    static auto
    create_for_stream (const SlotWriteFunc& write_func,
                       double width_in_points,
                       double height_in_points) -> RefPtr<SvgSurface>;

    auto
    restrict_to_version (SvgVersion version) -> void;

    static auto
    get_versions () -> const std::vector<SvgVersion>;

    static auto
    version_to_string (SvgVersion version) -> std::string;
  };

#endif

#ifdef CAIRO_HAS_GLITZ_SURFACE

  class LIBMM_CAIRO_SYMEXPORT GlitzSurface : public Surface
  {
  public:
    explicit GlitzSurface (cairo_surface_t* cobject,
                           bool has_reference = false);

    ~GlitzSurface () override;

    static RefPtr<GlitzSurface>
    create (glitz_surface_t* surface);
  };

#endif

} // namespace Cairo

#endif
