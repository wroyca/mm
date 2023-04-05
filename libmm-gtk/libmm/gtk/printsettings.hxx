// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_PRINTSETTINGS_H
#define _GTKMM_PRINTSETTINGS_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <vector>

#include <libmm/glib/object.hxx>
#include <libmm/gtk/enums.hxx>
#include <libmm/gtk/papersize.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPrintSettings = struct _GtkPrintSettings;
using GtkPrintSettingsClass = struct _GtkPrintSettingsClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT PrintSettings_Class;
}
#endif

namespace gtk
{

  enum class PrintDuplex
  {
    SIMPLEX,
    HORIZONTAL,
    VERTICAL
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::PrintDuplex>
    : public glib::Value_Enum<gtk::PrintDuplex>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  enum class PrintQuality
  {
    LOW,
    NORMAL,
    HIGH,
    DRAFT
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::PrintQuality>
    : public glib::Value_Enum<gtk::PrintQuality>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  enum class PrintPages
  {
    ALL,
    CURRENT,
    RANGES,
    SELECTION
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::PrintPages>
    : public glib::Value_Enum<gtk::PrintPages>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  enum class PageSet
  {
    ALL,
    EVEN,
    ODD
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::PageSet> : public glib::Value_Enum<gtk::PageSet>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  enum class NumberUpLayout
  {
    LEFT_TO_RIGHT_TOP_TO_BOTTOM,
    LEFT_TO_RIGHT_BOTTOM_TO_TOP,
    RIGHT_TO_LEFT_TOP_TO_BOTTOM,
    RIGHT_TO_LEFT_BOTTOM_TO_TOP,
    TOP_TO_BOTTOM_LEFT_TO_RIGHT,
    TOP_TO_BOTTOM_RIGHT_TO_LEFT,
    BOTTOM_TO_TOP_LEFT_TO_RIGHT,
    BOTTOM_TO_TOP_RIGHT_TO_LEFT
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::NumberUpLayout>
    : public glib::Value_Enum<gtk::NumberUpLayout>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT PageRange
  {
  public:
    PageRange ();
    PageRange (int start, int end);

    int start;
    int end;
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  struct PageRangeTraits
  {
    using CppType = PageRange;
    using CType = GtkPageRange;
    using CTypeNonConst = GtkPageRange;

    static auto
    to_c_type (CType c_obj) -> CType
    {
      return c_obj;
    }

    static auto
    release_c_type (CType) -> void
    {
    }

    static auto
    to_c_type (const CppType& cpp_obj) -> CType
    {
      CTypeNonConst c_obj = {cpp_obj.start, cpp_obj.end};
      return c_obj;
    }

    static auto
    to_cpp_type (CType c_obj) -> CppType
    {
      return CppType (c_obj.start, c_obj.end);
    }
  };
#endif

  class LIBMM_GTK_SYMEXPORT PrintSettings : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = PrintSettings;
    using CppClassType = PrintSettings_Class;
    using BaseObjectType = GtkPrintSettings;
    using BaseClassType = GtkPrintSettingsClass;

    PrintSettings (const PrintSettings&) = delete;
    auto
    operator= (const PrintSettings&) -> PrintSettings& = delete;

  private:
    friend class PrintSettings_Class;
    static CppClassType printsettings_class_;

  protected:
    explicit PrintSettings (const glib::ConstructParams& construct_params);
    explicit PrintSettings (GtkPrintSettings* castitem);

#endif

  public:
    PrintSettings (PrintSettings&& src) noexcept;
    auto
    operator= (PrintSettings&& src) noexcept -> PrintSettings&;

    ~PrintSettings () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkPrintSettings*
    {
      return reinterpret_cast<GtkPrintSettings*> (gobject_);
    }

    auto
    gobj () const -> const GtkPrintSettings*
    {
      return reinterpret_cast<GtkPrintSettings*> (gobject_);
    }

    auto
    gobj_copy () -> GtkPrintSettings*;

  private:
  protected:
    PrintSettings ();

  public:
    static auto
    create () -> glib::RefPtr<PrintSettings>;

    static auto
    create_from_key_file (const glib::RefPtr<const glib::KeyFile>& key_file)
        -> glib::RefPtr<PrintSettings>;

    static auto
    create_from_key_file (const glib::RefPtr<const glib::KeyFile>& key_file,
                          const glib::ustring& group_name)
        -> glib::RefPtr<PrintSettings>;

    static auto
    create_from_file (const std::string& file_name)
        -> glib::RefPtr<PrintSettings>;

    class Keys
    {
    public:
      static const glib::ustring PRINTER;
      static const glib::ustring ORIENTATION;
      static const glib::ustring PAPER_FORMAT;
      static const glib::ustring PAPER_WIDTH;
      static const glib::ustring PAPER_HEIGHT;
      static const glib::ustring NUM_COPIES;
      static const glib::ustring DEFAULT_SOURCE;
      static const glib::ustring QUALITY;
      static const glib::ustring RESOLUTION;
      static const glib::ustring USE_COLOR;
      static const glib::ustring DUPLEX;
      static const glib::ustring COLLATE;
      static const glib::ustring REVERSE;
      static const glib::ustring MEDIA_TYPE;
      static const glib::ustring DITHER;
      static const glib::ustring SCALE;
      static const glib::ustring PRINT_PAGES;
      static const glib::ustring PAGE_RANGES;
      static const glib::ustring PAGE_SET;
      static const glib::ustring FINISHINGS;
      static const glib::ustring NUMBER_UP;
      static const glib::ustring NUMBER_UP_LAYOUT;
      static const glib::ustring OUTPUT_BIN;

      static const glib::ustring OUTPUT_FILE_FORMAT;
      static const glib::ustring OUTPUT_URI;

      static const glib::ustring WIN32_DRIVER_VERSION;
      static const glib::ustring WIN32_DRIVER_EXTRA;
    };

    auto
    copy () const -> glib::RefPtr<PrintSettings>;

    auto
    load_from_file (const std::string& file_name) -> bool;

    auto
    load_from_key_file (const glib::RefPtr<const glib::KeyFile>& key_file,
                        const glib::ustring& group_name) -> bool;

    auto
    load_from_key_file (const glib::RefPtr<const glib::KeyFile>& key_file)
        -> bool;

    auto
    save_to_file (const std::string& file_name) const -> bool;

    auto
    save_to_key_file (const glib::RefPtr<glib::KeyFile>& key_file,
                      const glib::ustring& group_name) const -> void;

    auto
    save_to_key_file (const glib::RefPtr<glib::KeyFile>& key_file) const
        -> void;

    auto
    has_key (const glib::ustring& key) const -> bool;

    auto
    get (const glib::ustring& key) const -> glib::ustring;

    auto
    set (const glib::ustring& key, const glib::ustring& value) -> void;

    auto
    unset (const glib::ustring& key) -> void;

    typedef sigc::slot<void (const glib::ustring&, const glib::ustring&)>
        SlotForeach;

    auto
    setting_foreach (const SlotForeach& slot) -> void;

    auto
    get_bool (const glib::ustring& key) const -> bool;

    auto
    set_bool (const glib::ustring& key, bool value = true) -> void;

    auto
    get_double (const glib::ustring& key) const -> double;

    auto
    get_double_with_default (const glib::ustring& key, double def) const
        -> double;

    auto
    set_double (const glib::ustring& key, double value) -> void;

    auto
    get_length (const glib::ustring& key, Unit unit) const -> double;

    auto
    set_length (const glib::ustring& key, double value, Unit unit) -> void;

    auto
    get_int (const glib::ustring& key) const -> int;

    auto
    get_int_with_default (const glib::ustring& key, int def) const -> int;

    auto
    set_int (const glib::ustring& key, int value) -> void;

    auto
    get_printer () const -> glib::ustring;

    auto
    set_printer (const glib::ustring& printer) -> void;

    auto
    get_orientation () const -> PageOrientation;

    auto
    set_orientation (PageOrientation orientation) -> void;

    auto
    get_paper_size () -> PaperSize;

    auto
    get_paper_size () const -> const PaperSize;

    auto
    set_paper_size (const PaperSize& paper_size) -> void;

    auto
    get_paper_width (Unit unit) const -> double;

    auto
    set_paper_width (double width, Unit unit) -> void;

    auto
    get_paper_height (Unit unit) const -> double;

    auto
    set_paper_height (double height, Unit unit) -> void;

    auto
    get_use_color () const -> bool;

    auto
    set_use_color (bool use_color = true) -> void;

    auto
    get_collate () const -> bool;

    auto
    set_collate (bool collate = true) -> void;

    auto
    get_reverse () const -> bool;

    auto
    set_reverse (bool reverse = true) -> void;

    auto
    get_duplex () const -> PrintDuplex;

    auto
    set_duplex (PrintDuplex duplex) -> void;

    auto
    get_quality () const -> PrintQuality;

    auto
    set_quality (PrintQuality quality) -> void;

    auto
    get_n_copies () const -> int;

    auto
    set_n_copies (int num_copies) -> void;

    auto
    get_number_up () const -> int;

    auto
    set_number_up (int number_up) -> void;

    auto
    get_number_up_layout () const -> NumberUpLayout;

    auto
    set_number_up (NumberUpLayout number_up_layout) -> void;

    auto
    get_resolution () const -> int;

    auto
    set_resolution (int resolution) -> void;

    auto
    get_resolution_x () const -> int;

    auto
    get_resolution_y () const -> int;

    auto
    set_resolution_xy (int resolution_x, int resolution_y) -> void;

    auto
    get_printer_lpi () const -> double;

    auto
    set_printer_lpi (double lpi) -> void;

    auto
    get_scale () const -> double;

    auto
    set_scale (double scale) -> void;

    auto
    get_print_pages () const -> PrintPages;

    auto
    set_print_pages (PrintPages pages) -> void;

    auto
    get_page_ranges () const -> std::vector<PageRange>;
    auto
    set_page_ranges (const std::vector<PageRange>& page_ranges) -> void;

    auto
    get_page_set () const -> PageSet;

    auto
    set_page_set (PageSet page_set) -> void;

    auto
    get_default_source () const -> glib::ustring;

    auto
    set_default_source (const glib::ustring& default_source) -> void;

    auto
    get_media_type () const -> glib::ustring;

    auto
    set_media_type (const glib::ustring& media_type) -> void;

    auto
    get_dither () const -> glib::ustring;

    auto
    set_dither (const glib::ustring& dither) -> void;

    auto
    get_finishings () const -> glib::ustring;

    auto
    set_finishings (const glib::ustring& finishings) -> void;

    auto
    get_output_bin () const -> glib::ustring;

    auto
    set_output_bin (const glib::ustring& output_bin) -> void;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkPrintSettings* object, bool take_copy = false) -> glib::RefPtr<gtk::PrintSettings>;
} // namespace glib

#endif
