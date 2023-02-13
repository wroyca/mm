


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/papersize.hxx>
#include <libmm-gtk/papersize_p.hxx>


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

#include <libmm-glib/vectorutils.hxx>

#include <gtk/gtk.h>

namespace Gtk
{
// Initialize external constants.
const Glib::ustring PAPER_NAME_A3 = GTK_PAPER_NAME_A3;
const Glib::ustring PAPER_NAME_A4 = GTK_PAPER_NAME_A4;
const Glib::ustring PAPER_NAME_A5 = GTK_PAPER_NAME_A5;
const Glib::ustring PAPER_NAME_B5 = GTK_PAPER_NAME_B5;
const Glib::ustring PAPER_NAME_LETTER = GTK_PAPER_NAME_LETTER;
const Glib::ustring PAPER_NAME_EXECUTIVE = GTK_PAPER_NAME_EXECUTIVE;
const Glib::ustring PAPER_NAME_LEGAL = GTK_PAPER_NAME_LEGAL;

//PaperSize::PaperSize()
//:
//  gobject_(gtk_paper_size_new(gtk_paper_size_get_default()))
//{}

PaperSize::PaperSize(const Glib::ustring& name)
:
  gobject_(gtk_paper_size_new(name.c_str()))
{}

PaperSize::PaperSize(const Glib::ustring& ppd_name, const Glib::ustring& ppd_display_name, const double width, const double height)
:
  gobject_(gtk_paper_size_new_from_ppd(ppd_name.c_str(),
                                       ppd_display_name.c_str(),
                                       width,
                                       height))
{}

PaperSize::PaperSize(const Glib::ustring& name, const Glib::ustring& display_name, const double width, const double height, Unit unit)
:
  gobject_(gtk_paper_size_new_custom(name.c_str(),
                                     display_name.c_str(),
                                     width,
                                     height,
                                     GtkUnit(unit)))
{}

PaperSize::PaperSize(const Glib::RefPtr<const Glib::KeyFile>& key_file, const Glib::ustring& group_name)
{
  GError* gerror = nullptr;
  gobject_ = gtk_paper_size_new_from_key_file(const_cast<GKeyFile*>(unwrap(key_file)), c_str_or_nullptr(group_name), &gerror);

  if (gerror)
    Glib::Error::throw_exception(gerror);
}

auto PaperSize::equal(const PaperSize& other) const -> bool
{
  return static_cast<bool>(gtk_paper_size_is_equal(const_cast<GtkPaperSize*>(this->gobj()),
                                                   const_cast<GtkPaperSize*>(other.gobj())));
}

PaperSize::operator bool() const
{
  return gobj();
}

auto PaperSize::save_to_key_file (const Glib::RefPtr <Glib::KeyFile> &key_file) -> void
{
  gtk_paper_size_to_key_file( gobj(), unwrap(key_file), nullptr);
}

// static
auto PaperSizeTraits::release_c_type (
  const CType ptr) -> void
{
  gtk_paper_size_free(const_cast<CTypeNonConst>(ptr));
}

} // namespace Gtk

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Gtk::Unit>::value_type() -> GType
{
  return gtk_unit_get_type();
}


namespace Glib
{

auto wrap(GtkPaperSize* object, const bool take_copy) -> Gtk::PaperSize
{
  return Gtk::PaperSize(object, take_copy);
}

} // namespace Glib


namespace Gtk
{


// static
auto PaperSize::get_type() -> GType
{
  return gtk_paper_size_get_type();
}

PaperSize::PaperSize()
:
  gobject_ (nullptr) // Allows creation of invalid wrapper, e.g. for output arguments to methods.
{}

PaperSize::PaperSize(const PaperSize& other)
:
  gobject_ (other.gobject_ ? gtk_paper_size_copy(other.gobject_) : nullptr)
{}

PaperSize::PaperSize(PaperSize&& other) noexcept
:
  gobject_(other.gobject_)
{
  other.gobject_ = nullptr;
}

auto PaperSize::operator=(PaperSize&& other) noexcept -> PaperSize&
{
  PaperSize temp (std::move(other));
  swap(temp);
  return *this;
}

PaperSize::PaperSize(GtkPaperSize* gobject, const bool make_a_copy)
:
  // For BoxedType wrappers, make_a_copy is true by default.  The static
  // BoxedType wrappers must always take a copy, thus make_a_copy = true
  // ensures identical behaviour if the default argument is used.
  gobject_ (make_a_copy && gobject ? gtk_paper_size_copy(gobject) : gobject)
{}

auto PaperSize::operator=(const PaperSize& other) -> PaperSize&
{
  PaperSize temp (other);
  swap(temp);
  return *this;
}

PaperSize::~PaperSize() noexcept
{
  if(gobject_)
    gtk_paper_size_free(gobject_);
}

auto PaperSize::swap (PaperSize &other) noexcept -> void
{
  std::swap(gobject_, other.gobject_);
}

auto PaperSize::gobj_copy() const -> GtkPaperSize*
{
  return gtk_paper_size_copy(gobject_);
}


auto PaperSize::get_paper_sizes(
  const bool include_custom) -> std::vector<PaperSize>
{
  return Glib::ListHandler<PaperSize, PaperSizeTraits>::list_to_vector(gtk_paper_size_get_paper_sizes(include_custom), Glib::OWNERSHIP_DEEP);
}

auto PaperSize::get_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_paper_size_get_name(const_cast<GtkPaperSize*>(gobj())));
}

auto PaperSize::get_display_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_paper_size_get_display_name(const_cast<GtkPaperSize*>(gobj())));
}

auto PaperSize::get_ppd_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_paper_size_get_ppd_name(const_cast<GtkPaperSize*>(gobj())));
}

auto PaperSize::get_width(Unit unit) const -> double
{
  return gtk_paper_size_get_width(const_cast<GtkPaperSize*>(gobj()), static_cast<GtkUnit>(unit));
}

auto PaperSize::get_height(Unit unit) const -> double
{
  return gtk_paper_size_get_height(const_cast<GtkPaperSize*>(gobj()), static_cast<GtkUnit>(unit));
}

auto PaperSize::is_custom() const -> bool
{
  return gtk_paper_size_is_custom(const_cast<GtkPaperSize*>(gobj()));
}

auto PaperSize::is_ipp() const -> bool
{
  return gtk_paper_size_is_ipp(const_cast<GtkPaperSize*>(gobj()));
}

auto PaperSize::set_size (
  const double width, const double height, Unit unit) -> void
{
  gtk_paper_size_set_size(gobj(), width, height, static_cast<GtkUnit>(unit));
}

auto PaperSize::get_default_top_margin(Unit unit) const -> double
{
  return gtk_paper_size_get_default_top_margin(const_cast<GtkPaperSize*>(gobj()), static_cast<GtkUnit>(unit));
}

auto PaperSize::get_default_bottom_margin(Unit unit) const -> double
{
  return gtk_paper_size_get_default_bottom_margin(const_cast<GtkPaperSize*>(gobj()), static_cast<GtkUnit>(unit));
}

auto PaperSize::get_default_left_margin(Unit unit) const -> double
{
  return gtk_paper_size_get_default_left_margin(const_cast<GtkPaperSize*>(gobj()), static_cast<GtkUnit>(unit));
}

auto PaperSize::get_default_right_margin(Unit unit) const -> double
{
  return gtk_paper_size_get_default_right_margin(const_cast<GtkPaperSize*>(gobj()), static_cast<GtkUnit>(unit));
}

auto PaperSize::get_default() -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_paper_size_get_default());
}

auto PaperSize::save_to_key_file (
  const Glib::RefPtr <Glib::KeyFile> &key_file, const Glib::ustring &group_name) -> void
{
  gtk_paper_size_to_key_file(gobj(), unwrap(key_file), group_name.c_str());
}


} // namespace Gtk


