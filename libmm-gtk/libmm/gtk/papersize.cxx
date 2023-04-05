// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/papersize.hxx>
#include <libmm/gtk/papersize_p.hxx>

#include <libmm/glib/vectorutils.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  const glib::ustring PAPER_NAME_A3 = GTK_PAPER_NAME_A3;
  const glib::ustring PAPER_NAME_A4 = GTK_PAPER_NAME_A4;
  const glib::ustring PAPER_NAME_A5 = GTK_PAPER_NAME_A5;
  const glib::ustring PAPER_NAME_B5 = GTK_PAPER_NAME_B5;
  const glib::ustring PAPER_NAME_LETTER = GTK_PAPER_NAME_LETTER;
  const glib::ustring PAPER_NAME_EXECUTIVE = GTK_PAPER_NAME_EXECUTIVE;
  const glib::ustring PAPER_NAME_LEGAL = GTK_PAPER_NAME_LEGAL;

  PaperSize::PaperSize (const glib::ustring& name)
    : gobject_ (gtk_paper_size_new (name.c_str ()))
  {
  }

  PaperSize::PaperSize (const glib::ustring& ppd_name,
                        const glib::ustring& ppd_display_name,
                        double width,
                        double height)
    : gobject_ (gtk_paper_size_new_from_ppd (ppd_name.c_str (),
                                             ppd_display_name.c_str (),
                                             width,
                                             height))
  {
  }

  PaperSize::PaperSize (const glib::ustring& name,
                        const glib::ustring& display_name,
                        double width,
                        double height,
                        Unit unit)
    : gobject_ (gtk_paper_size_new_custom (name.c_str (),
                                           display_name.c_str (),
                                           width,
                                           height,
                                           GtkUnit (unit)))
  {
  }

  PaperSize::PaperSize (const glib::RefPtr<const glib::KeyFile>& key_file,
                        const glib::ustring& group_name)
  {
    GError* gerror = nullptr;
    gobject_ = gtk_paper_size_new_from_key_file (
        const_cast<GKeyFile*> (glib::unwrap (key_file)),
        glib::c_str_or_nullptr (group_name),
        &gerror);

    if (gerror)
      glib::Error::throw_exception (gerror);
  }

  auto
  PaperSize::equal (const PaperSize& other) const -> bool
  {
    return (static_cast<bool> (
        gtk_paper_size_is_equal (const_cast<GtkPaperSize*> (this->gobj ()),
                                 const_cast<GtkPaperSize*> (other.gobj ()))));
  }

  PaperSize::operator bool () const
  {
    return gobj ();
  }

  auto
  PaperSize::save_to_key_file (const glib::RefPtr<glib::KeyFile>& key_file) -> void
  {
    gtk_paper_size_to_key_file (gobj (), glib::unwrap (key_file), nullptr);
  }

  auto
  PaperSizeTraits::release_c_type (CType ptr) -> void
  {
    gtk_paper_size_free (const_cast<CTypeNonConst> (ptr));
  }

} // namespace gtk

namespace
{
}

auto
glib::Value<gtk::Unit>::value_type () -> GType
{
  return gtk_unit_get_type ();
}

namespace glib
{

  auto
  wrap (GtkPaperSize* object, bool take_copy) -> gtk::PaperSize
  {
    return gtk::PaperSize (object, take_copy);
  }

} // namespace glib

namespace gtk
{

  auto
  PaperSize::get_type () -> GType
  {
    return gtk_paper_size_get_type ();
  }

  PaperSize::PaperSize ()
    : gobject_ (nullptr)
  {
  }

  PaperSize::PaperSize (const PaperSize& other)
    : gobject_ ((other.gobject_) ? gtk_paper_size_copy (other.gobject_) :
                                   nullptr)
  {
  }

  PaperSize::PaperSize (PaperSize&& other) noexcept
    : gobject_ (other.gobject_)
  {
    other.gobject_ = nullptr;
  }

  auto
  PaperSize::operator= (PaperSize&& other) noexcept -> PaperSize&
  {
    PaperSize temp (std::move (other));
    swap (temp);
    return *this;
  }

  PaperSize::PaperSize (GtkPaperSize* gobject, bool make_a_copy)
    : gobject_ ((make_a_copy && gobject) ? gtk_paper_size_copy (gobject) :
                                           gobject)
  {
  }

  auto
  PaperSize::operator= (const PaperSize& other) -> PaperSize&
  {
    PaperSize temp (other);
    swap (temp);
    return *this;
  }

  PaperSize::~PaperSize () noexcept
  {
    if (gobject_)
      gtk_paper_size_free (gobject_);
  }

  auto
  PaperSize::swap (PaperSize& other) noexcept -> void
  {
    std::swap (gobject_, other.gobject_);
  }

  auto
  PaperSize::gobj_copy () const -> GtkPaperSize*
  {
    return gtk_paper_size_copy (gobject_);
  }

  auto
  PaperSize::get_paper_sizes (bool include_custom) -> std::vector<PaperSize>
  {
    return glib::ListHandler<PaperSize, PaperSizeTraits>::list_to_vector (
        gtk_paper_size_get_paper_sizes (static_cast<int> (include_custom)),
        glib::OWNERSHIP_DEEP);
  }

  auto
  PaperSize::get_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_paper_size_get_name (const_cast<GtkPaperSize*> (gobj ())));
  }

  auto
  PaperSize::get_display_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_paper_size_get_display_name (const_cast<GtkPaperSize*> (gobj ())));
  }

  auto
  PaperSize::get_ppd_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_paper_size_get_ppd_name (const_cast<GtkPaperSize*> (gobj ())));
  }

  auto
  PaperSize::get_width (Unit unit) const -> double
  {
    return gtk_paper_size_get_width (const_cast<GtkPaperSize*> (gobj ()),
                                     static_cast<GtkUnit> (unit));
  }

  auto
  PaperSize::get_height (Unit unit) const -> double
  {
    return gtk_paper_size_get_height (const_cast<GtkPaperSize*> (gobj ()),
                                      static_cast<GtkUnit> (unit));
  }

  auto
  PaperSize::is_custom () const -> bool
  {
    return gtk_paper_size_is_custom (const_cast<GtkPaperSize*> (gobj ()));
  }

  auto
  PaperSize::is_ipp () const -> bool
  {
    return gtk_paper_size_is_ipp (const_cast<GtkPaperSize*> (gobj ()));
  }

  auto
  PaperSize::set_size (double width, double height, Unit unit) -> void
  {
    gtk_paper_size_set_size (gobj (),
                             width,
                             height,
                             static_cast<GtkUnit> (unit));
  }

  auto
  PaperSize::get_default_top_margin (Unit unit) const -> double
  {
    return gtk_paper_size_get_default_top_margin (
        const_cast<GtkPaperSize*> (gobj ()),
        static_cast<GtkUnit> (unit));
  }

  auto
  PaperSize::get_default_bottom_margin (Unit unit) const -> double
  {
    return gtk_paper_size_get_default_bottom_margin (
        const_cast<GtkPaperSize*> (gobj ()),
        static_cast<GtkUnit> (unit));
  }

  auto
  PaperSize::get_default_left_margin (Unit unit) const -> double
  {
    return gtk_paper_size_get_default_left_margin (
        const_cast<GtkPaperSize*> (gobj ()),
        static_cast<GtkUnit> (unit));
  }

  auto
  PaperSize::get_default_right_margin (Unit unit) const -> double
  {
    return gtk_paper_size_get_default_right_margin (
        const_cast<GtkPaperSize*> (gobj ()),
        static_cast<GtkUnit> (unit));
  }

  auto
  PaperSize::get_default () -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_paper_size_get_default ());
  }

  auto
  PaperSize::save_to_key_file (const glib::RefPtr<glib::KeyFile>& key_file,
                               const glib::ustring& group_name) -> void
  {
    gtk_paper_size_to_key_file (gobj (),
                                glib::unwrap (key_file),
                                group_name.c_str ());
  }

} // namespace gtk
