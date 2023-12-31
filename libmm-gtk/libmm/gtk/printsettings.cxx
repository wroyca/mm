// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/printsettings.hxx>
#include <libmm/gtk/printsettings_p.hxx>

#include <libmm/glib/vectorutils.hxx>

#include <glib.h>
#include <gtk/gtk.h>

namespace
{

  static auto
  proxy_foreach_callback (const char* key, const char* value, void* data) -> void
  {
    typedef gtk::PrintSettings::SlotForeach SlotType;
    auto& slot = *static_cast<SlotType*> (data);

    try
    {
      slot (glib::convert_const_gchar_ptr_to_ustring (key),
            glib::convert_const_gchar_ptr_to_ustring (value));
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
    }
  }

} // namespace

namespace gtk
{

  const glib::ustring PrintSettings::Keys::PRINTER = GTK_PRINT_SETTINGS_PRINTER;
  const glib::ustring PrintSettings::Keys::ORIENTATION =
      GTK_PRINT_SETTINGS_ORIENTATION;
  const glib::ustring PrintSettings::Keys::PAPER_FORMAT =
      GTK_PRINT_SETTINGS_PAPER_FORMAT;
  const glib::ustring PrintSettings::Keys::PAPER_WIDTH =
      GTK_PRINT_SETTINGS_PAPER_WIDTH;
  const glib::ustring PrintSettings::Keys::PAPER_HEIGHT =
      GTK_PRINT_SETTINGS_PAPER_HEIGHT;
  const glib::ustring PrintSettings::Keys::NUM_COPIES =
      GTK_PRINT_SETTINGS_N_COPIES;
  const glib::ustring PrintSettings::Keys::DEFAULT_SOURCE =
      GTK_PRINT_SETTINGS_DEFAULT_SOURCE;
  const glib::ustring PrintSettings::Keys::QUALITY = GTK_PRINT_SETTINGS_QUALITY;
  const glib::ustring PrintSettings::Keys::RESOLUTION =
      GTK_PRINT_SETTINGS_RESOLUTION;
  const glib::ustring PrintSettings::Keys::USE_COLOR =
      GTK_PRINT_SETTINGS_USE_COLOR;
  const glib::ustring PrintSettings::Keys::DUPLEX = GTK_PRINT_SETTINGS_DUPLEX;
  const glib::ustring PrintSettings::Keys::COLLATE = GTK_PRINT_SETTINGS_COLLATE;
  const glib::ustring PrintSettings::Keys::REVERSE = GTK_PRINT_SETTINGS_REVERSE;
  const glib::ustring PrintSettings::Keys::MEDIA_TYPE =
      GTK_PRINT_SETTINGS_MEDIA_TYPE;
  const glib::ustring PrintSettings::Keys::DITHER = GTK_PRINT_SETTINGS_DITHER;
  const glib::ustring PrintSettings::Keys::SCALE = GTK_PRINT_SETTINGS_SCALE;
  const glib::ustring PrintSettings::Keys::PRINT_PAGES =
      GTK_PRINT_SETTINGS_PRINT_PAGES;
  const glib::ustring PrintSettings::Keys::PAGE_RANGES =
      GTK_PRINT_SETTINGS_PAGE_RANGES;
  const glib::ustring PrintSettings::Keys::PAGE_SET =
      GTK_PRINT_SETTINGS_PAGE_SET;
  const glib::ustring PrintSettings::Keys::FINISHINGS =
      GTK_PRINT_SETTINGS_FINISHINGS;
  const glib::ustring PrintSettings::Keys::NUMBER_UP =
      GTK_PRINT_SETTINGS_NUMBER_UP;
  const glib::ustring PrintSettings::Keys::OUTPUT_BIN =
      GTK_PRINT_SETTINGS_OUTPUT_BIN;

  const glib::ustring PrintSettings::Keys::OUTPUT_FILE_FORMAT =
      GTK_PRINT_SETTINGS_OUTPUT_FILE_FORMAT;
  const glib::ustring PrintSettings::Keys::OUTPUT_URI =
      GTK_PRINT_SETTINGS_OUTPUT_URI;

  const glib::ustring PrintSettings::Keys::WIN32_DRIVER_VERSION =
      GTK_PRINT_SETTINGS_WIN32_DRIVER_VERSION;
  const glib::ustring PrintSettings::Keys::WIN32_DRIVER_EXTRA =
      GTK_PRINT_SETTINGS_WIN32_DRIVER_EXTRA;

  auto
  PrintSettings::create_from_key_file (
      const glib::RefPtr<const glib::KeyFile>& key_file) -> glib::RefPtr<PrintSettings>
  {
    auto result = PrintSettings::create ();

    result->load_from_key_file (key_file);

    return result;
  }

  auto
  PrintSettings::create_from_key_file (
      const glib::RefPtr<const glib::KeyFile>& key_file,
      const glib::ustring& group_name) -> glib::RefPtr<PrintSettings>
  {
    auto result = PrintSettings::create ();

    result->load_from_key_file (key_file, group_name);

    return result;
  }

  auto
  PrintSettings::create_from_file (const std::string& file_name) -> glib::RefPtr<PrintSettings>
  {
    auto result = PrintSettings::create ();

    result->load_from_file (file_name);

    return result;
  }

  auto
  PrintSettings::setting_foreach (const SlotForeach& slot) -> void
  {
    SlotForeach slot_copy (slot);
    gtk_print_settings_foreach (const_cast<GtkPrintSettings*> (gobj ()),
                                &proxy_foreach_callback,
                                &slot_copy);
  }

  PageRange::PageRange ()
    : start (0),
      end (0)
  {
  }

  PageRange::PageRange (int start_, int end_)
    : start (start_),
      end (end_)
  {
  }

  auto
  PrintSettings::get_page_ranges () const -> std::vector<PageRange>
  {
    int num_ranges (0);
    GtkPageRange* page_ranges = gtk_print_settings_get_page_ranges (
        const_cast<GtkPrintSettings*> (gobj ()),
        &num_ranges);

    return glib::ArrayHandler<PageRange, PageRangeTraits>::array_to_vector (
        page_ranges,
        num_ranges,
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  PrintSettings::set_page_ranges (const std::vector<PageRange>& page_ranges) -> void
  {
    gtk_print_settings_set_page_ranges (
        gobj (),
        glib::ArrayHandler<PageRange, PageRangeTraits>::vector_to_array (
            page_ranges)
            .data (),
        page_ranges.size ());
  }

  auto
  PrintSettings::load_from_key_file (
      const glib::RefPtr<const glib::KeyFile>& key_file) -> bool
  {
    GError* gerror = nullptr;
    bool retvalue = gtk_print_settings_load_key_file (
        gobj (),
        const_cast<GKeyFile*> (glib::unwrap (key_file)),
        nullptr,
        &(gerror));
    if (gerror)
      ::glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  PrintSettings::save_to_key_file (
      const glib::RefPtr<glib::KeyFile>& key_file) const -> void
  {
    gtk_print_settings_to_key_file (const_cast<GtkPrintSettings*> (gobj ()),
                                    glib::unwrap (key_file),
                                    nullptr);
  }

} // namespace gtk

namespace
{
}

auto
glib::Value<gtk::PrintDuplex>::value_type () -> GType
{
  return gtk_print_duplex_get_type ();
}

auto
glib::Value<gtk::PrintQuality>::value_type () -> GType
{
  return gtk_print_quality_get_type ();
}

auto
glib::Value<gtk::PrintPages>::value_type () -> GType
{
  return gtk_print_pages_get_type ();
}

auto
glib::Value<gtk::PageSet>::value_type () -> GType
{
  return gtk_page_set_get_type ();
}

auto
glib::Value<gtk::NumberUpLayout>::value_type () -> GType
{
  return gtk_number_up_layout_get_type ();
}

namespace glib
{

  auto
  wrap (GtkPrintSettings* object, bool take_copy) -> glib::RefPtr<gtk::PrintSettings>
  {
    return glib::make_refptr_for_instance<gtk::PrintSettings> (
        dynamic_cast<gtk::PrintSettings*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  PrintSettings_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &PrintSettings_Class::class_init_function;

      register_derived_type (gtk_print_settings_get_type ());
    }

    return *this;
  }

  auto
  PrintSettings_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  PrintSettings_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new PrintSettings ((GtkPrintSettings*) object);
  }

  auto
  PrintSettings::gobj_copy () -> GtkPrintSettings*
  {
    reference ();
    return gobj ();
  }

  PrintSettings::PrintSettings (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  PrintSettings::PrintSettings (GtkPrintSettings* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  PrintSettings::PrintSettings (PrintSettings&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  PrintSettings::operator= (PrintSettings&& src) noexcept -> PrintSettings&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  PrintSettings::~PrintSettings () noexcept {}

  PrintSettings::CppClassType PrintSettings::printsettings_class_;

  auto
  PrintSettings::get_type () -> GType
  {
    return printsettings_class_.init ().get_type ();
  }

  auto
  PrintSettings::get_base_type () -> GType
  {
    return gtk_print_settings_get_type ();
  }

  PrintSettings::PrintSettings ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (printsettings_class_.init ()))
  {
  }

  auto
  PrintSettings::create () -> glib::RefPtr<PrintSettings>
  {
    return glib::make_refptr_for_instance<PrintSettings> (new PrintSettings ());
  }

  auto
  PrintSettings::copy () const -> glib::RefPtr<PrintSettings>
  {
    return glib::wrap (
        gtk_print_settings_copy (const_cast<GtkPrintSettings*> (gobj ())));
  }

  auto
  PrintSettings::load_from_file (const std::string& file_name) -> bool
  {
    GError* gerror = nullptr;
    auto retvalue =
        gtk_print_settings_load_file (gobj (), file_name.c_str (), &(gerror));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  PrintSettings::load_from_key_file (
      const glib::RefPtr<const glib::KeyFile>& key_file,
      const glib::ustring& group_name) -> bool
  {
    GError* gerror = nullptr;
    auto retvalue = gtk_print_settings_load_key_file (
        gobj (),
        const_cast<GKeyFile*> (glib::unwrap (key_file)),
        group_name.c_str (),
        &(gerror));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  PrintSettings::save_to_file (const std::string& file_name) const -> bool
  {
    GError* gerror = nullptr;
    auto retvalue = gtk_print_settings_to_file (
        const_cast<GtkPrintSettings*> (gobj ()),
        file_name.c_str (),
        &(gerror));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  PrintSettings::save_to_key_file (const glib::RefPtr<glib::KeyFile>& key_file,
                                   const glib::ustring& group_name) const -> void
  {
    gtk_print_settings_to_key_file (const_cast<GtkPrintSettings*> (gobj ()),
                                    glib::unwrap (key_file),
                                    group_name.c_str ());
  }

  auto
  PrintSettings::has_key (const glib::ustring& key) const -> bool
  {
    return gtk_print_settings_has_key (const_cast<GtkPrintSettings*> (gobj ()),
                                       key.c_str ());
  }

  auto
  PrintSettings::get (const glib::ustring& key) const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_print_settings_get (const_cast<GtkPrintSettings*> (gobj ()),
                                key.c_str ()));
  }

  auto
  PrintSettings::set (const glib::ustring& key, const glib::ustring& value) -> void
  {
    gtk_print_settings_set (gobj (), key.c_str (), value.c_str ());
  }

  auto
  PrintSettings::unset (const glib::ustring& key) -> void
  {
    gtk_print_settings_unset (gobj (), key.c_str ());
  }

  auto
  PrintSettings::get_bool (const glib::ustring& key) const -> bool
  {
    return gtk_print_settings_get_bool (const_cast<GtkPrintSettings*> (gobj ()),
                                        key.c_str ());
  }

  auto
  PrintSettings::set_bool (const glib::ustring& key, bool value) -> void
  {
    gtk_print_settings_set_bool (gobj (),
                                 key.c_str (),
                                 static_cast<int> (value));
  }

  auto
  PrintSettings::get_double (const glib::ustring& key) const -> double
  {
    return gtk_print_settings_get_double (
        const_cast<GtkPrintSettings*> (gobj ()),
        key.c_str ());
  }

  auto
  PrintSettings::get_double_with_default (const glib::ustring& key,
                                          double def) const -> double
  {
    return gtk_print_settings_get_double_with_default (
        const_cast<GtkPrintSettings*> (gobj ()),
        key.c_str (),
        def);
  }

  auto
  PrintSettings::set_double (const glib::ustring& key, double value) -> void
  {
    gtk_print_settings_set_double (gobj (), key.c_str (), value);
  }

  auto
  PrintSettings::get_length (const glib::ustring& key, Unit unit) const -> double
  {
    return gtk_print_settings_get_length (
        const_cast<GtkPrintSettings*> (gobj ()),
        key.c_str (),
        static_cast<GtkUnit> (unit));
  }

  auto
  PrintSettings::set_length (const glib::ustring& key, double value, Unit unit) -> void
  {
    gtk_print_settings_set_length (gobj (),
                                   key.c_str (),
                                   value,
                                   static_cast<GtkUnit> (unit));
  }

  auto
  PrintSettings::get_int (const glib::ustring& key) const -> int
  {
    return gtk_print_settings_get_int (const_cast<GtkPrintSettings*> (gobj ()),
                                       key.c_str ());
  }

  auto
  PrintSettings::get_int_with_default (const glib::ustring& key, int def) const -> int
  {
    return gtk_print_settings_get_int_with_default (
        const_cast<GtkPrintSettings*> (gobj ()),
        key.c_str (),
        def);
  }

  auto
  PrintSettings::set_int (const glib::ustring& key, int value) -> void
  {
    gtk_print_settings_set_int (gobj (), key.c_str (), value);
  }

  auto
  PrintSettings::get_printer () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_print_settings_get_printer (
            const_cast<GtkPrintSettings*> (gobj ())));
  }

  auto
  PrintSettings::set_printer (const glib::ustring& printer) -> void
  {
    gtk_print_settings_set_printer (gobj (), printer.c_str ());
  }

  auto
  PrintSettings::get_orientation () const -> PageOrientation
  {
    return static_cast<PageOrientation> (gtk_print_settings_get_orientation (
        const_cast<GtkPrintSettings*> (gobj ())));
  }

  auto
  PrintSettings::set_orientation (PageOrientation orientation) -> void
  {
    gtk_print_settings_set_orientation (
        gobj (),
        static_cast<GtkPageOrientation> (orientation));
  }

  auto
  PrintSettings::get_paper_size () -> PaperSize
  {
    return glib::wrap (gtk_print_settings_get_paper_size (gobj ()), true);
  }

  auto
  PrintSettings::get_paper_size () const -> const PaperSize
  {
    return const_cast<PrintSettings*> (this)->get_paper_size ();
  }

  auto
  PrintSettings::set_paper_size (const PaperSize& paper_size) -> void
  {
    gtk_print_settings_set_paper_size (
        gobj (),
        const_cast<GtkPaperSize*> ((paper_size).gobj ()));
  }

  auto
  PrintSettings::get_paper_width (Unit unit) const -> double
  {
    return gtk_print_settings_get_paper_width (
        const_cast<GtkPrintSettings*> (gobj ()),
        static_cast<GtkUnit> (unit));
  }

  auto
  PrintSettings::set_paper_width (double width, Unit unit) -> void
  {
    gtk_print_settings_set_paper_width (gobj (),
                                        width,
                                        static_cast<GtkUnit> (unit));
  }

  auto
  PrintSettings::get_paper_height (Unit unit) const -> double
  {
    return gtk_print_settings_get_paper_height (
        const_cast<GtkPrintSettings*> (gobj ()),
        static_cast<GtkUnit> (unit));
  }

  auto
  PrintSettings::set_paper_height (double height, Unit unit) -> void
  {
    gtk_print_settings_set_paper_height (gobj (),
                                         height,
                                         static_cast<GtkUnit> (unit));
  }

  auto
  PrintSettings::get_use_color () const -> bool
  {
    return gtk_print_settings_get_use_color (
        const_cast<GtkPrintSettings*> (gobj ()));
  }

  auto
  PrintSettings::set_use_color (bool use_color) -> void
  {
    gtk_print_settings_set_use_color (gobj (), static_cast<int> (use_color));
  }

  auto
  PrintSettings::get_collate () const -> bool
  {
    return gtk_print_settings_get_collate (
        const_cast<GtkPrintSettings*> (gobj ()));
  }

  auto
  PrintSettings::set_collate (bool collate) -> void
  {
    gtk_print_settings_set_collate (gobj (), static_cast<int> (collate));
  }

  auto
  PrintSettings::get_reverse () const -> bool
  {
    return gtk_print_settings_get_reverse (
        const_cast<GtkPrintSettings*> (gobj ()));
  }

  auto
  PrintSettings::set_reverse (bool reverse) -> void
  {
    gtk_print_settings_set_reverse (gobj (), static_cast<int> (reverse));
  }

  auto
  PrintSettings::get_duplex () const -> PrintDuplex
  {
    return static_cast<PrintDuplex> (gtk_print_settings_get_duplex (
        const_cast<GtkPrintSettings*> (gobj ())));
  }

  auto
  PrintSettings::set_duplex (PrintDuplex duplex) -> void
  {
    gtk_print_settings_set_duplex (gobj (),
                                   static_cast<GtkPrintDuplex> (duplex));
  }

  auto
  PrintSettings::get_quality () const -> PrintQuality
  {
    return static_cast<PrintQuality> (gtk_print_settings_get_quality (
        const_cast<GtkPrintSettings*> (gobj ())));
  }

  auto
  PrintSettings::set_quality (PrintQuality quality) -> void
  {
    gtk_print_settings_set_quality (gobj (),
                                    static_cast<GtkPrintQuality> (quality));
  }

  auto
  PrintSettings::get_n_copies () const -> int
  {
    return gtk_print_settings_get_n_copies (
        const_cast<GtkPrintSettings*> (gobj ()));
  }

  auto
  PrintSettings::set_n_copies (int num_copies) -> void
  {
    gtk_print_settings_set_n_copies (gobj (), num_copies);
  }

  auto
  PrintSettings::get_number_up () const -> int
  {
    return gtk_print_settings_get_number_up (
        const_cast<GtkPrintSettings*> (gobj ()));
  }

  auto
  PrintSettings::set_number_up (int number_up) -> void
  {
    gtk_print_settings_set_number_up (gobj (), number_up);
  }

  auto
  PrintSettings::get_number_up_layout () const -> NumberUpLayout
  {
    return static_cast<NumberUpLayout> (
        gtk_print_settings_get_number_up_layout (
            const_cast<GtkPrintSettings*> (gobj ())));
  }

  auto
  PrintSettings::set_number_up (NumberUpLayout number_up_layout) -> void
  {
    gtk_print_settings_set_number_up_layout (
        gobj (),
        static_cast<GtkNumberUpLayout> (number_up_layout));
  }

  auto
  PrintSettings::get_resolution () const -> int
  {
    return gtk_print_settings_get_resolution (
        const_cast<GtkPrintSettings*> (gobj ()));
  }

  auto
  PrintSettings::set_resolution (int resolution) -> void
  {
    gtk_print_settings_set_resolution (gobj (), resolution);
  }

  auto
  PrintSettings::get_resolution_x () const -> int
  {
    return gtk_print_settings_get_resolution_x (
        const_cast<GtkPrintSettings*> (gobj ()));
  }

  auto
  PrintSettings::get_resolution_y () const -> int
  {
    return gtk_print_settings_get_resolution_y (
        const_cast<GtkPrintSettings*> (gobj ()));
  }

  auto
  PrintSettings::set_resolution_xy (int resolution_x, int resolution_y) -> void
  {
    gtk_print_settings_set_resolution_xy (gobj (), resolution_x, resolution_y);
  }

  auto
  PrintSettings::get_printer_lpi () const -> double
  {
    return gtk_print_settings_get_printer_lpi (
        const_cast<GtkPrintSettings*> (gobj ()));
  }

  auto
  PrintSettings::set_printer_lpi (double lpi) -> void
  {
    gtk_print_settings_set_printer_lpi (gobj (), lpi);
  }

  auto
  PrintSettings::get_scale () const -> double
  {
    return gtk_print_settings_get_scale (
        const_cast<GtkPrintSettings*> (gobj ()));
  }

  auto
  PrintSettings::set_scale (double scale) -> void
  {
    gtk_print_settings_set_scale (gobj (), scale);
  }

  auto
  PrintSettings::get_print_pages () const -> PrintPages
  {
    return static_cast<PrintPages> (gtk_print_settings_get_print_pages (
        const_cast<GtkPrintSettings*> (gobj ())));
  }

  auto
  PrintSettings::set_print_pages (PrintPages pages) -> void
  {
    gtk_print_settings_set_print_pages (gobj (),
                                        static_cast<GtkPrintPages> (pages));
  }

  auto
  PrintSettings::get_page_set () const -> PageSet
  {
    return static_cast<PageSet> (gtk_print_settings_get_page_set (
        const_cast<GtkPrintSettings*> (gobj ())));
  }

  auto
  PrintSettings::set_page_set (PageSet page_set) -> void
  {
    gtk_print_settings_set_page_set (gobj (),
                                     static_cast<GtkPageSet> (page_set));
  }

  auto
  PrintSettings::get_default_source () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_print_settings_get_default_source (
            const_cast<GtkPrintSettings*> (gobj ())));
  }

  auto
  PrintSettings::set_default_source (const glib::ustring& default_source) -> void
  {
    gtk_print_settings_set_default_source (gobj (), default_source.c_str ());
  }

  auto
  PrintSettings::get_media_type () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_print_settings_get_media_type (
            const_cast<GtkPrintSettings*> (gobj ())));
  }

  auto
  PrintSettings::set_media_type (const glib::ustring& media_type) -> void
  {
    gtk_print_settings_set_media_type (gobj (), media_type.c_str ());
  }

  auto
  PrintSettings::get_dither () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_print_settings_get_dither (
            const_cast<GtkPrintSettings*> (gobj ())));
  }

  auto
  PrintSettings::set_dither (const glib::ustring& dither) -> void
  {
    gtk_print_settings_set_dither (gobj (), dither.c_str ());
  }

  auto
  PrintSettings::get_finishings () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_print_settings_get_finishings (
            const_cast<GtkPrintSettings*> (gobj ())));
  }

  auto
  PrintSettings::set_finishings (const glib::ustring& finishings) -> void
  {
    gtk_print_settings_set_finishings (gobj (), finishings.c_str ());
  }

  auto
  PrintSettings::get_output_bin () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_print_settings_get_output_bin (
            const_cast<GtkPrintSettings*> (gobj ())));
  }

  auto
  PrintSettings::set_output_bin (const glib::ustring& output_bin) -> void
  {
    gtk_print_settings_set_output_bin (gobj (), output_bin.c_str ());
  }

} // namespace gtk
