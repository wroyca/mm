


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/printsettings.hpp>
#include <libmm-gtk/printsettings_p.hpp>


/* Copyright (C) 2006 The gtkmm Development Team
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

#include <libmm-glib/vectorutils.hpp>

#include <gtk/gtk.h>
#include <glib.h>

namespace // anonymous
{

auto proxy_foreach_callback (const char *key, const char *value, void *data) -> void
{
  typedef Gtk::PrintSettings::SlotForeach SlotType;
  const auto& slot = *static_cast<SlotType*>(data);

  try
  {
    slot(Glib::convert_const_gchar_ptr_to_ustring(key), Glib::convert_const_gchar_ptr_to_ustring(value));
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }
}

} // anonymous namespace

namespace Gtk
{

//Initialize static members:
const Glib::ustring PrintSettings::Keys::PRINTER = GTK_PRINT_SETTINGS_PRINTER;
const Glib::ustring PrintSettings::Keys::ORIENTATION = GTK_PRINT_SETTINGS_ORIENTATION;
const Glib::ustring PrintSettings::Keys::PAPER_FORMAT = GTK_PRINT_SETTINGS_PAPER_FORMAT;
const Glib::ustring PrintSettings::Keys::PAPER_WIDTH = GTK_PRINT_SETTINGS_PAPER_WIDTH;
const Glib::ustring PrintSettings::Keys::PAPER_HEIGHT = GTK_PRINT_SETTINGS_PAPER_HEIGHT;
const Glib::ustring PrintSettings::Keys::NUM_COPIES = GTK_PRINT_SETTINGS_N_COPIES;
const Glib::ustring PrintSettings::Keys::DEFAULT_SOURCE = GTK_PRINT_SETTINGS_DEFAULT_SOURCE;
const Glib::ustring PrintSettings::Keys::QUALITY = GTK_PRINT_SETTINGS_QUALITY;
const Glib::ustring PrintSettings::Keys::RESOLUTION = GTK_PRINT_SETTINGS_RESOLUTION;
const Glib::ustring PrintSettings::Keys::USE_COLOR = GTK_PRINT_SETTINGS_USE_COLOR;
const Glib::ustring PrintSettings::Keys::DUPLEX = GTK_PRINT_SETTINGS_DUPLEX;
const Glib::ustring PrintSettings::Keys::COLLATE = GTK_PRINT_SETTINGS_COLLATE;
const Glib::ustring PrintSettings::Keys::REVERSE = GTK_PRINT_SETTINGS_REVERSE;
const Glib::ustring PrintSettings::Keys::MEDIA_TYPE = GTK_PRINT_SETTINGS_MEDIA_TYPE;
const Glib::ustring PrintSettings::Keys::DITHER = GTK_PRINT_SETTINGS_DITHER;
const Glib::ustring PrintSettings::Keys::SCALE = GTK_PRINT_SETTINGS_SCALE;
const Glib::ustring PrintSettings::Keys::PRINT_PAGES = GTK_PRINT_SETTINGS_PRINT_PAGES;
const Glib::ustring PrintSettings::Keys::PAGE_RANGES = GTK_PRINT_SETTINGS_PAGE_RANGES;
const Glib::ustring PrintSettings::Keys::PAGE_SET = GTK_PRINT_SETTINGS_PAGE_SET;
const Glib::ustring PrintSettings::Keys::FINISHINGS = GTK_PRINT_SETTINGS_FINISHINGS;
const Glib::ustring PrintSettings::Keys::NUMBER_UP = GTK_PRINT_SETTINGS_NUMBER_UP;
const Glib::ustring PrintSettings::Keys::OUTPUT_BIN = GTK_PRINT_SETTINGS_OUTPUT_BIN;

const Glib::ustring PrintSettings::Keys::OUTPUT_FILE_FORMAT = GTK_PRINT_SETTINGS_OUTPUT_FILE_FORMAT;
const Glib::ustring PrintSettings::Keys::OUTPUT_URI = GTK_PRINT_SETTINGS_OUTPUT_URI;

const Glib::ustring PrintSettings::Keys::WIN32_DRIVER_VERSION = GTK_PRINT_SETTINGS_WIN32_DRIVER_VERSION;
const Glib::ustring PrintSettings::Keys::WIN32_DRIVER_EXTRA = GTK_PRINT_SETTINGS_WIN32_DRIVER_EXTRA;

auto PrintSettings::create_from_key_file(const Glib::RefPtr<const Glib::KeyFile>& key_file) -> Glib::RefPtr<PrintSettings>
{
  auto result = create();

  result->load_from_key_file(key_file);

  return result;
}

auto PrintSettings::create_from_key_file(const Glib::RefPtr<const Glib::KeyFile>& key_file, const Glib::ustring& group_name) -> Glib::RefPtr<PrintSettings>
{
  auto result = create();

  result->load_from_key_file(key_file, group_name);

  return result;
}

auto PrintSettings::create_from_file(const std::string& file_name) -> Glib::RefPtr<PrintSettings>
{
  auto result = create();

  result->load_from_file(file_name);

  return result;
}

auto PrintSettings::setting_foreach (const SlotForeach &slot) -> void
{
  SlotForeach slot_copy(slot);
  gtk_print_settings_foreach(gobj(), &proxy_foreach_callback, &slot_copy);
}

PageRange::PageRange()
:
  start(0),
  end(0)
{}

PageRange::PageRange(const int start_, const int end_)
:
  start(start_),
  end(end_)
{}

auto PrintSettings::get_page_ranges() const -> std::vector<PageRange>
{
  int num_ranges (0);
  const GtkPageRange* page_ranges =
    gtk_print_settings_get_page_ranges(const_cast<GtkPrintSettings*>(gobj()), &num_ranges);

  // We get a copy of page_ranges. Logically our ownership is deep, but
  // since page_ranges contains elements instead of pointers to elements,
  // ArrayHandler shall delete only the container. Thus OWNERSHIP_SHALLOW.
  return Glib::ArrayHandler<PageRange, PageRangeTraits>::array_to_vector(
    page_ranges, num_ranges, Glib::OWNERSHIP_SHALLOW);
}

auto PrintSettings::set_page_ranges (const std::vector <PageRange> &page_ranges) -> void
{
  gtk_print_settings_set_page_ranges(gobj(),
    Glib::ArrayHandler<PageRange, PageRangeTraits>::vector_to_array(page_ranges).data(),
    page_ranges.size());
}

auto PrintSettings::load_from_key_file(const Glib::RefPtr<const Glib::KeyFile>& key_file) -> bool
{
  GError* gerror = nullptr;
  const bool retvalue = gtk_print_settings_load_key_file(gobj(), const_cast<GKeyFile*>(unwrap(key_file)), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);

  return retvalue;
}

auto PrintSettings::save_to_key_file (const Glib::RefPtr <Glib::KeyFile> &key_file) const -> void
{
  gtk_print_settings_to_key_file(const_cast<GtkPrintSettings*>(gobj()), unwrap(key_file), nullptr);
}

} // namespace Gtk

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Gtk::PrintDuplex>::value_type() -> GType
{
  return gtk_print_duplex_get_type();
}

// static
auto Glib::Value<Gtk::PrintQuality>::value_type() -> GType
{
  return gtk_print_quality_get_type();
}

// static
auto Glib::Value<Gtk::PrintPages>::value_type() -> GType
{
  return gtk_print_pages_get_type();
}

// static
auto Glib::Value<Gtk::PageSet>::value_type() -> GType
{
  return gtk_page_set_get_type();
}

// static
auto Glib::Value<Gtk::NumberUpLayout>::value_type() -> GType
{
  return gtk_number_up_layout_get_type();
}


namespace Glib
{

auto wrap(GtkPrintSettings* object, const bool take_copy) -> RefPtr<Gtk::PrintSettings>
{
  return Glib::make_refptr_for_instance<Gtk::PrintSettings>( dynamic_cast<Gtk::PrintSettings*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto PrintSettings_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &PrintSettings_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_print_settings_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto PrintSettings_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto PrintSettings_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new PrintSettings((GtkPrintSettings*)object);
}


/* The implementation: */

auto PrintSettings::gobj_copy() -> GtkPrintSettings*
{
  reference();
  return gobj();
}

PrintSettings::PrintSettings(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

PrintSettings::PrintSettings(GtkPrintSettings* castitem)
: Object((GObject*)castitem)
{}


PrintSettings::PrintSettings(PrintSettings&& src) noexcept
: Object(std::move(src))
{}

auto PrintSettings::operator=(PrintSettings&& src) noexcept -> PrintSettings&
{
  Object::operator=(std::move(src));
  return *this;
}


PrintSettings::~PrintSettings() noexcept = default;

PrintSettings::CppClassType PrintSettings::printsettings_class_; // initialize static member

auto PrintSettings::get_type() -> GType
{
  return printsettings_class_.init().get_type();
}


auto PrintSettings::get_base_type() -> GType
{
  return gtk_print_settings_get_type();
}


PrintSettings::PrintSettings()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(printsettings_class_.init()))
{


}

auto PrintSettings::create() -> Glib::RefPtr<PrintSettings>
{
  return Glib::make_refptr_for_instance<PrintSettings>( new PrintSettings() );
}

auto PrintSettings::copy() const -> Glib::RefPtr<PrintSettings>
{
  return Glib::wrap(gtk_print_settings_copy(const_cast<GtkPrintSettings*>(gobj())));
}

auto PrintSettings::load_from_file(const std::string& file_name) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = gtk_print_settings_load_file(gobj(), file_name.c_str(), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto PrintSettings::load_from_key_file(const Glib::RefPtr<const Glib::KeyFile>& key_file, const Glib::ustring& group_name) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = gtk_print_settings_load_key_file(gobj(), const_cast<GKeyFile*>(unwrap(key_file)), group_name.c_str(), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto PrintSettings::save_to_file(const std::string& file_name) const -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = gtk_print_settings_to_file(const_cast<GtkPrintSettings*>(gobj()), file_name.c_str(), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto PrintSettings::save_to_key_file (
  const Glib::RefPtr <Glib::KeyFile> &key_file, const Glib::ustring &group_name) const -> void
{
  gtk_print_settings_to_key_file(const_cast<GtkPrintSettings*>(gobj()), unwrap(key_file), group_name.c_str());
}

auto PrintSettings::has_key(const Glib::ustring& key) const -> bool
{
  return gtk_print_settings_has_key(const_cast<GtkPrintSettings*>(gobj()), key.c_str());
}

auto PrintSettings::get(const Glib::ustring& key) const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_print_settings_get(const_cast<GtkPrintSettings*>(gobj()), key.c_str()));
}

auto PrintSettings::set (const Glib::ustring &key, const Glib::ustring &value) -> void
{
  gtk_print_settings_set(gobj(), key.c_str(), value.c_str());
}

auto PrintSettings::unset (const Glib::ustring &key) -> void
{
  gtk_print_settings_unset(gobj(), key.c_str());
}

auto PrintSettings::get_bool(const Glib::ustring& key) const -> bool
{
  return gtk_print_settings_get_bool(const_cast<GtkPrintSettings*>(gobj()), key.c_str());
}

auto PrintSettings::set_bool (const Glib::ustring &key, const bool value) -> void
{
  gtk_print_settings_set_bool(gobj(), key.c_str(), value);
}

auto PrintSettings::get_double(const Glib::ustring& key) const -> double
{
  return gtk_print_settings_get_double(const_cast<GtkPrintSettings*>(gobj()), key.c_str());
}

auto PrintSettings::get_double_with_default(const Glib::ustring& key, const double def) const -> double
{
  return gtk_print_settings_get_double_with_default(const_cast<GtkPrintSettings*>(gobj()), key.c_str(), def);
}

auto PrintSettings::set_double (const Glib::ustring &key, const double value) -> void
{
  gtk_print_settings_set_double(gobj(), key.c_str(), value);
}

auto PrintSettings::get_length(const Glib::ustring& key, Unit unit) const -> double
{
  return gtk_print_settings_get_length(const_cast<GtkPrintSettings*>(gobj()), key.c_str(), static_cast<GtkUnit>(unit));
}

auto PrintSettings::set_length (const Glib::ustring &key, const double value, Unit unit) -> void
{
  gtk_print_settings_set_length(gobj(), key.c_str(), value, static_cast<GtkUnit>(unit));
}

auto PrintSettings::get_int(const Glib::ustring& key) const -> int
{
  return gtk_print_settings_get_int(const_cast<GtkPrintSettings*>(gobj()), key.c_str());
}

auto PrintSettings::get_int_with_default(const Glib::ustring& key, const int def) const -> int
{
  return gtk_print_settings_get_int_with_default(const_cast<GtkPrintSettings*>(gobj()), key.c_str(), def);
}

auto PrintSettings::set_int (const Glib::ustring &key, const int value) -> void
{
  gtk_print_settings_set_int(gobj(), key.c_str(), value);
}

auto PrintSettings::get_printer() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_print_settings_get_printer(const_cast<GtkPrintSettings*>(gobj())));
}

auto PrintSettings::set_printer (const Glib::ustring &printer) -> void
{
  gtk_print_settings_set_printer(gobj(), printer.c_str());
}

auto PrintSettings::get_orientation() const -> PageOrientation
{
  return static_cast<PageOrientation>(gtk_print_settings_get_orientation(const_cast<GtkPrintSettings*>(gobj())));
}

auto PrintSettings::set_orientation (PageOrientation orientation) -> void
{
  gtk_print_settings_set_orientation(gobj(), static_cast<GtkPageOrientation>(orientation));
}

auto PrintSettings::get_paper_size() -> PaperSize
{
  return Glib::wrap(gtk_print_settings_get_paper_size(gobj()), true);
}

auto PrintSettings::get_paper_size() const -> const PaperSize
{
  return const_cast<PrintSettings*>(this)->get_paper_size();
}

auto PrintSettings::set_paper_size (const PaperSize &paper_size) -> void
{
  gtk_print_settings_set_paper_size(gobj(), const_cast<GtkPaperSize*>(paper_size.gobj()));
}

auto PrintSettings::get_paper_width(Unit unit) const -> double
{
  return gtk_print_settings_get_paper_width(const_cast<GtkPrintSettings*>(gobj()), static_cast<GtkUnit>(unit));
}

auto PrintSettings::set_paper_width (
  const double width, Unit unit) -> void
{
  gtk_print_settings_set_paper_width(gobj(), width, static_cast<GtkUnit>(unit));
}

auto PrintSettings::get_paper_height(Unit unit) const -> double
{
  return gtk_print_settings_get_paper_height(const_cast<GtkPrintSettings*>(gobj()), static_cast<GtkUnit>(unit));
}

auto PrintSettings::set_paper_height (
  const double height, Unit unit) -> void
{
  gtk_print_settings_set_paper_height(gobj(), height, static_cast<GtkUnit>(unit));
}

auto PrintSettings::get_use_color() const -> bool
{
  return gtk_print_settings_get_use_color(const_cast<GtkPrintSettings*>(gobj()));
}

auto PrintSettings::set_use_color (
  const bool use_color) -> void
{
  gtk_print_settings_set_use_color(gobj(), use_color);
}

auto PrintSettings::get_collate() const -> bool
{
  return gtk_print_settings_get_collate(const_cast<GtkPrintSettings*>(gobj()));
}

auto PrintSettings::set_collate (
  const bool collate) -> void
{
  gtk_print_settings_set_collate(gobj(), collate);
}

auto PrintSettings::get_reverse() const -> bool
{
  return gtk_print_settings_get_reverse(const_cast<GtkPrintSettings*>(gobj()));
}

auto PrintSettings::set_reverse (
  const bool reverse) -> void
{
  gtk_print_settings_set_reverse(gobj(), reverse);
}

auto PrintSettings::get_duplex() const -> PrintDuplex
{
  return static_cast<PrintDuplex>(gtk_print_settings_get_duplex(const_cast<GtkPrintSettings*>(gobj())));
}

auto PrintSettings::set_duplex (PrintDuplex duplex) -> void
{
  gtk_print_settings_set_duplex(gobj(), static_cast<GtkPrintDuplex>(duplex));
}

auto PrintSettings::get_quality() const -> PrintQuality
{
  return static_cast<PrintQuality>(gtk_print_settings_get_quality(const_cast<GtkPrintSettings*>(gobj())));
}

auto PrintSettings::set_quality (PrintQuality quality) -> void
{
  gtk_print_settings_set_quality(gobj(), static_cast<GtkPrintQuality>(quality));
}

auto PrintSettings::get_n_copies() const -> int
{
  return gtk_print_settings_get_n_copies(const_cast<GtkPrintSettings*>(gobj()));
}

auto PrintSettings::set_n_copies (
  const int num_copies) -> void
{
  gtk_print_settings_set_n_copies(gobj(), num_copies);
}

auto PrintSettings::get_number_up() const -> int
{
  return gtk_print_settings_get_number_up(const_cast<GtkPrintSettings*>(gobj()));
}

auto PrintSettings::set_number_up (
  const int number_up) -> void
{
  gtk_print_settings_set_number_up(gobj(), number_up);
}

auto PrintSettings::get_number_up_layout() const -> NumberUpLayout
{
  return static_cast<NumberUpLayout>(gtk_print_settings_get_number_up_layout(const_cast<GtkPrintSettings*>(gobj())));
}

auto PrintSettings::set_number_up (NumberUpLayout number_up_layout) -> void
{
  gtk_print_settings_set_number_up_layout(gobj(), static_cast<GtkNumberUpLayout>(number_up_layout));
}

auto PrintSettings::get_resolution() const -> int
{
  return gtk_print_settings_get_resolution(const_cast<GtkPrintSettings*>(gobj()));
}

auto PrintSettings::set_resolution (
  const int resolution) -> void
{
  gtk_print_settings_set_resolution(gobj(), resolution);
}

auto PrintSettings::get_resolution_x() const -> int
{
  return gtk_print_settings_get_resolution_x(const_cast<GtkPrintSettings*>(gobj()));
}

auto PrintSettings::get_resolution_y() const -> int
{
  return gtk_print_settings_get_resolution_y(const_cast<GtkPrintSettings*>(gobj()));
}

auto PrintSettings::set_resolution_xy (
  const int resolution_x, const int resolution_y) -> void
{
  gtk_print_settings_set_resolution_xy(gobj(), resolution_x, resolution_y);
}

auto PrintSettings::get_printer_lpi() const -> double
{
  return gtk_print_settings_get_printer_lpi(const_cast<GtkPrintSettings*>(gobj()));
}

auto PrintSettings::set_printer_lpi (
  const double lpi) -> void
{
  gtk_print_settings_set_printer_lpi(gobj(), lpi);
}

auto PrintSettings::get_scale() const -> double
{
  return gtk_print_settings_get_scale(const_cast<GtkPrintSettings*>(gobj()));
}

auto PrintSettings::set_scale (
  const double scale) -> void
{
  gtk_print_settings_set_scale(gobj(), scale);
}

auto PrintSettings::get_print_pages() const -> PrintPages
{
  return static_cast<PrintPages>(gtk_print_settings_get_print_pages(const_cast<GtkPrintSettings*>(gobj())));
}

auto PrintSettings::set_print_pages (PrintPages pages) -> void
{
  gtk_print_settings_set_print_pages(gobj(), static_cast<GtkPrintPages>(pages));
}

auto PrintSettings::get_page_set() const -> PageSet
{
  return static_cast<PageSet>(gtk_print_settings_get_page_set(const_cast<GtkPrintSettings*>(gobj())));
}

auto PrintSettings::set_page_set (PageSet page_set) -> void
{
  gtk_print_settings_set_page_set(gobj(), static_cast<GtkPageSet>(page_set));
}

auto PrintSettings::get_default_source() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_print_settings_get_default_source(const_cast<GtkPrintSettings*>(gobj())));
}

auto PrintSettings::set_default_source (const Glib::ustring &default_source) -> void
{
  gtk_print_settings_set_default_source(gobj(), default_source.c_str());
}

auto PrintSettings::get_media_type() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_print_settings_get_media_type(const_cast<GtkPrintSettings*>(gobj())));
}

auto PrintSettings::set_media_type (const Glib::ustring &media_type) -> void
{
  gtk_print_settings_set_media_type(gobj(), media_type.c_str());
}

auto PrintSettings::get_dither() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_print_settings_get_dither(const_cast<GtkPrintSettings*>(gobj())));
}

auto PrintSettings::set_dither (const Glib::ustring &dither) -> void
{
  gtk_print_settings_set_dither(gobj(), dither.c_str());
}

auto PrintSettings::get_finishings() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_print_settings_get_finishings(const_cast<GtkPrintSettings*>(gobj())));
}

auto PrintSettings::set_finishings (const Glib::ustring &finishings) -> void
{
  gtk_print_settings_set_finishings(gobj(), finishings.c_str());
}

auto PrintSettings::get_output_bin() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_print_settings_get_output_bin(const_cast<GtkPrintSettings*>(gobj())));
}

auto PrintSettings::set_output_bin (const Glib::ustring &output_bin) -> void
{
  gtk_print_settings_set_output_bin(gobj(), output_bin.c_str());
}


} // namespace Gtk


