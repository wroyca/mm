// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_PRINTSETTINGS_H
#define _GTKMM_PRINTSETTINGS_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <vector>

#include <libmm-glib/object.hxx>
#include <libmm-gtk/enums.hxx>
#include <libmm-gtk/papersize.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPrintSettings = struct _GtkPrintSettings;
using GtkPrintSettingsClass = struct _GtkPrintSettingsClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API PrintSettings_Class;
}
#endif

namespace Gtk
{

  enum class PrintDuplex
  {
    SIMPLEX,
    HORIZONTAL,
    VERTICAL
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::PrintDuplex>
    : public Glib::Value_Enum<Gtk::PrintDuplex>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

  enum class PrintQuality
  {
    LOW,
    NORMAL,
    HIGH,
    DRAFT
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::PrintQuality>
    : public Glib::Value_Enum<Gtk::PrintQuality>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

  enum class PrintPages
  {
    ALL,
    CURRENT,
    RANGES,
    SELECTION
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::PrintPages>
    : public Glib::Value_Enum<Gtk::PrintPages>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

  enum class PageSet
  {
    ALL,
    EVEN,
    ODD
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::PageSet> : public Glib::Value_Enum<Gtk::PageSet>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
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

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::NumberUpLayout>
    : public Glib::Value_Enum<Gtk::NumberUpLayout>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

  class GTKMM_API PageRange
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

  class GTKMM_API PrintSettings : public Glib::Object
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
    explicit PrintSettings (const Glib::ConstructParams& construct_params);
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
    create () -> Glib::RefPtr<PrintSettings>;

    static auto
    create_from_key_file (const Glib::RefPtr<const Glib::KeyFile>& key_file)
        -> Glib::RefPtr<PrintSettings>;

    static auto
    create_from_key_file (const Glib::RefPtr<const Glib::KeyFile>& key_file,
                          const Glib::ustring& group_name)
        -> Glib::RefPtr<PrintSettings>;

    static auto
    create_from_file (const std::string& file_name)
        -> Glib::RefPtr<PrintSettings>;

    class Keys
    {
    public:
      static const Glib::ustring PRINTER;
      static const Glib::ustring ORIENTATION;
      static const Glib::ustring PAPER_FORMAT;
      static const Glib::ustring PAPER_WIDTH;
      static const Glib::ustring PAPER_HEIGHT;
      static const Glib::ustring NUM_COPIES;
      static const Glib::ustring DEFAULT_SOURCE;
      static const Glib::ustring QUALITY;
      static const Glib::ustring RESOLUTION;
      static const Glib::ustring USE_COLOR;
      static const Glib::ustring DUPLEX;
      static const Glib::ustring COLLATE;
      static const Glib::ustring REVERSE;
      static const Glib::ustring MEDIA_TYPE;
      static const Glib::ustring DITHER;
      static const Glib::ustring SCALE;
      static const Glib::ustring PRINT_PAGES;
      static const Glib::ustring PAGE_RANGES;
      static const Glib::ustring PAGE_SET;
      static const Glib::ustring FINISHINGS;
      static const Glib::ustring NUMBER_UP;
      static const Glib::ustring NUMBER_UP_LAYOUT;
      static const Glib::ustring OUTPUT_BIN;

      static const Glib::ustring OUTPUT_FILE_FORMAT;
      static const Glib::ustring OUTPUT_URI;

      static const Glib::ustring WIN32_DRIVER_VERSION;
      static const Glib::ustring WIN32_DRIVER_EXTRA;
    };

    auto
    copy () const -> Glib::RefPtr<PrintSettings>;

    auto
    load_from_file (const std::string& file_name) -> bool;

    auto
    load_from_key_file (const Glib::RefPtr<const Glib::KeyFile>& key_file,
                        const Glib::ustring& group_name) -> bool;

    auto
    load_from_key_file (const Glib::RefPtr<const Glib::KeyFile>& key_file)
        -> bool;

    auto
    save_to_file (const std::string& file_name) const -> bool;

    auto
    save_to_key_file (const Glib::RefPtr<Glib::KeyFile>& key_file,
                      const Glib::ustring& group_name) const -> void;

    auto
    save_to_key_file (const Glib::RefPtr<Glib::KeyFile>& key_file) const
        -> void;

    auto
    has_key (const Glib::ustring& key) const -> bool;

    auto
    get (const Glib::ustring& key) const -> Glib::ustring;

    auto
    set (const Glib::ustring& key, const Glib::ustring& value) -> void;

    auto
    unset (const Glib::ustring& key) -> void;

    typedef sigc::slot<void (const Glib::ustring&, const Glib::ustring&)>
        SlotForeach;

    auto
    setting_foreach (const SlotForeach& slot) -> void;

    auto
    get_bool (const Glib::ustring& key) const -> bool;

    auto
    set_bool (const Glib::ustring& key, bool value = true) -> void;

    auto
    get_double (const Glib::ustring& key) const -> double;

    auto
    get_double_with_default (const Glib::ustring& key, double def) const
        -> double;

    auto
    set_double (const Glib::ustring& key, double value) -> void;

    auto
    get_length (const Glib::ustring& key, Unit unit) const -> double;

    auto
    set_length (const Glib::ustring& key, double value, Unit unit) -> void;

    auto
    get_int (const Glib::ustring& key) const -> int;

    auto
    get_int_with_default (const Glib::ustring& key, int def) const -> int;

    auto
    set_int (const Glib::ustring& key, int value) -> void;

    auto
    get_printer () const -> Glib::ustring;

    auto
    set_printer (const Glib::ustring& printer) -> void;

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
    get_default_source () const -> Glib::ustring;

    auto
    set_default_source (const Glib::ustring& default_source) -> void;

    auto
    get_media_type () const -> Glib::ustring;

    auto
    set_media_type (const Glib::ustring& media_type) -> void;

    auto
    get_dither () const -> Glib::ustring;

    auto
    set_dither (const Glib::ustring& dither) -> void;

    auto
    get_finishings () const -> Glib::ustring;

    auto
    set_finishings (const Glib::ustring& finishings) -> void;

    auto
    get_output_bin () const -> Glib::ustring;

    auto
    set_output_bin (const Glib::ustring& output_bin) -> void;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  GTKMM_API auto
  wrap (GtkPrintSettings* object, bool take_copy = false) -> Glib::RefPtr<Gtk::PrintSettings>;
} // namespace Glib

#endif
