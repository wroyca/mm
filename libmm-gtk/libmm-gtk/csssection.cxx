// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/csssection.hxx>
#include <libmm-gtk/csssection_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkCssSection* object, const bool take_copy) -> RefPtr<Gtk::CssSection>
  {
    if (take_copy && object)
      gtk_css_section_ref (object);

    return Glib::make_refptr_for_instance<Gtk::CssSection> (
        reinterpret_cast<Gtk::CssSection*> (object));
  }

} // namespace Glib

namespace Gtk
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
  CssSection::create (const Glib::RefPtr<Gio::File>& file,
                      const CssLocation& start,
                      const CssLocation& end) -> Glib::RefPtr<CssSection>
  {
    return Glib::wrap (gtk_css_section_new (Glib::unwrap<Gio::File> (file),
                                            start.gobj (),
                                            end.gobj ()));
  }

  auto
  CssSection::to_string () const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        gtk_css_section_to_string (gobj ()));
  }

  auto
  CssSection::get_parent () -> Glib::RefPtr<CssSection>
  {
    auto retvalue = Glib::wrap (gtk_css_section_get_parent (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  CssSection::get_parent () const -> Glib::RefPtr<const CssSection>
  {
    return const_cast<CssSection*> (this)->get_parent ();
  }

  auto
  CssSection::get_file () -> Glib::RefPtr<Gio::File>
  {
    auto retvalue = Glib::wrap (gtk_css_section_get_file (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  CssSection::get_file () const -> Glib::RefPtr<const Gio::File>
  {
    return const_cast<CssSection*> (this)->get_file ();
  }

  auto
  CssSection::get_start_location () const -> CssLocation
  {
    return Glib::wrap (gtk_css_section_get_start_location (gobj ()));
  }

  auto
  CssSection::get_end_location () const -> CssLocation
  {
    return Glib::wrap (gtk_css_section_get_end_location (gobj ()));
  }

} // namespace Gtk
