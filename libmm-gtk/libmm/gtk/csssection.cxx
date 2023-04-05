// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/csssection.hxx>
#include <libmm/gtk/csssection_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkCssSection* object, bool take_copy) -> glib::RefPtr<gtk::CssSection>
  {
    if (take_copy && object)
      gtk_css_section_ref (object);

    return glib::make_refptr_for_instance<gtk::CssSection> (
        reinterpret_cast<gtk::CssSection*> (object));
  }

} // namespace glib

namespace gtk
{

  auto
  CssSection::reference () const -> void
  {
    gtk_css_section_ref (
        reinterpret_cast<GtkCssSection*> (const_cast<CssSection*> (this)));
  }

  auto
  CssSection::unreference () const -> void
  {
    gtk_css_section_unref (
        reinterpret_cast<GtkCssSection*> (const_cast<CssSection*> (this)));
  }

  auto
  CssSection::gobj () -> GtkCssSection*
  {
    return reinterpret_cast<GtkCssSection*> (this);
  }

  auto
  CssSection::gobj () const -> const GtkCssSection*
  {
    return reinterpret_cast<const GtkCssSection*> (this);
  }

  auto
  CssSection::gobj_copy () const -> GtkCssSection*
  {
    const auto gobject =
        reinterpret_cast<GtkCssSection*> (const_cast<CssSection*> (this));
    gtk_css_section_ref (gobject);
    return gobject;
  }

  auto
  CssSection::create (const glib::RefPtr<gio::File>& file,
                      const CssLocation& start,
                      const CssLocation& end) -> glib::RefPtr<CssSection>
  {
    return glib::wrap (gtk_css_section_new (
        const_cast<GFile*> (glib::unwrap<gio::File> (file)),
        (start).gobj (),
        (end).gobj ()));
  }

  auto
  CssSection::to_string () const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        gtk_css_section_to_string (const_cast<GtkCssSection*> (gobj ())));
  }

  auto
  CssSection::get_parent () -> glib::RefPtr<CssSection>
  {
    auto retvalue = glib::wrap (gtk_css_section_get_parent (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  CssSection::get_parent () const -> glib::RefPtr<const CssSection>
  {
    return const_cast<CssSection*> (this)->get_parent ();
  }

  auto
  CssSection::get_file () -> glib::RefPtr<gio::File>
  {
    auto retvalue = glib::wrap (gtk_css_section_get_file (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  CssSection::get_file () const -> glib::RefPtr<const gio::File>
  {
    return const_cast<CssSection*> (this)->get_file ();
  }

  auto
  CssSection::get_start_location () const -> CssLocation
  {
    return glib::wrap (gtk_css_section_get_start_location (
        const_cast<GtkCssSection*> (gobj ())));
  }

  auto
  CssSection::get_end_location () const -> CssLocation
  {
    return glib::wrap (gtk_css_section_get_end_location (
        const_cast<GtkCssSection*> (gobj ())));
  }

} // namespace gtk
