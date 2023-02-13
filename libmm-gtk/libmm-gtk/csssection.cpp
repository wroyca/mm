


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/csssection.hpp>
#include <libmm-gtk/csssection_p.hpp>


/* Copyright (C) 2014 The gtkmm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>

namespace
{
} // anonymous namespace


/* Why reinterpret_cast<CssSection*>(gobject) is needed:
 *
 * A CssSection instance is in fact always a GtkCssSection instance.
 * Unfortunately, GtkCssSection cannot be a member of CssSection,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because CssSection does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

auto wrap(GtkCssSection* object, const bool take_copy) -> RefPtr<Gtk::CssSection>
{
  if(take_copy && object)
    gtk_css_section_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<Gtk::CssSection>(reinterpret_cast<Gtk::CssSection*>(object));
}

} // namespace Glib


namespace Gtk
{

auto CssSection::reference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  gtk_css_section_ref(reinterpret_cast<GtkCssSection*>(const_cast<CssSection*>(this)));
}

auto CssSection::unreference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  gtk_css_section_unref(reinterpret_cast<GtkCssSection*>(const_cast<CssSection*>(this)));
}

auto CssSection::gobj() -> GtkCssSection*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GtkCssSection*>(this);
}

auto CssSection::gobj() const -> const GtkCssSection*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GtkCssSection*>(this);
}

auto CssSection::gobj_copy() const -> GtkCssSection*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GtkCssSection*>(const_cast<CssSection*>(this));
  gtk_css_section_ref(gobject);
  return gobject;
}


auto CssSection::create(const Glib::RefPtr<Gio::File>& file, const CssLocation& start, const CssLocation& end) -> Glib::RefPtr<CssSection>
{
  return Glib::wrap(gtk_css_section_new(Glib::unwrap<Gio::File>(file), start.gobj(), end.gobj()));
}

auto CssSection::to_string() const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(gtk_css_section_to_string(gobj()));
}

auto CssSection::get_parent() -> Glib::RefPtr<CssSection>
{
  auto retvalue = Glib::wrap(gtk_css_section_get_parent(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto CssSection::get_parent() const -> Glib::RefPtr<const CssSection>
{
  return const_cast<CssSection*>(this)->get_parent();
}

auto CssSection::get_file() -> Glib::RefPtr<Gio::File>
{
  auto retvalue = Glib::wrap(gtk_css_section_get_file(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto CssSection::get_file() const -> Glib::RefPtr<const Gio::File>
{
  return const_cast<CssSection*>(this)->get_file();
}

auto CssSection::get_start_location() const -> CssLocation
{
  return Glib::wrap(gtk_css_section_get_start_location(gobj()));
}

auto CssSection::get_end_location() const -> CssLocation
{
  return Glib::wrap(gtk_css_section_get_end_location(gobj()));
}


} // namespace Gtk


