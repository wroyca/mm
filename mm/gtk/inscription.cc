// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.h>

#include <mm/gtk/inscription.h>
#include <mm/gtk/private/inscription_p.h>


/* Copyright 2022 The gtkmm Development Team
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

using Overflow = Gtk::Inscription::Overflow;

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Gtk::Inscription::Overflow>::value_type() -> GType
{
  return gtk_inscription_overflow_get_type();
}


namespace Glib
{

auto wrap(GtkInscription* object, bool take_copy) -> Gtk::Inscription*
{
  return dynamic_cast<Gtk::Inscription *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto Inscription_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_inscription_get_type();

  }

  return *this;
}


auto Inscription_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new Inscription((GtkInscription*)(o)));

}


/* The implementation: */

Inscription::Inscription(const Glib::ConstructParams& construct_params)
:
  Gtk::Widget(construct_params)
{
  }

Inscription::Inscription(GtkInscription* castitem)
:
  Gtk::Widget((GtkWidget*)(castitem))
{
  }


Inscription::Inscription(Inscription&& src) noexcept
: Gtk::Widget(std::move(src))
{}

auto Inscription::operator=(Inscription&& src) noexcept -> Inscription&
{
  Gtk::Widget::operator=(std::move(src));
  return *this;
}

Inscription::~Inscription() noexcept
{
  destroy_();
}

Inscription::CppClassType Inscription::inscription_class_; // initialize static member

auto Inscription::get_type() -> GType
{
  return inscription_class_.init().get_type();
}


auto Inscription::get_base_type() -> GType
{
  return gtk_inscription_get_type();
}


Inscription::Inscription()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::Widget(Glib::ConstructParams(inscription_class_.init()))
{


}

Inscription::Inscription(const Glib::ustring& text)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::Widget(Glib::ConstructParams(inscription_class_.init(), "text", text.c_str(), nullptr))
{


}

auto Inscription::get_text() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_inscription_get_text(const_cast<GtkInscription*>(gobj())));
}

void Inscription::set_text(const Glib::ustring& text)
{
  gtk_inscription_set_text(gobj(), text.empty() ? nullptr : text.c_str());
}

auto Inscription::get_attributes() const -> Pango::AttrList
{
  return Pango::AttrList((gtk_inscription_get_attributes(const_cast<GtkInscription*>(gobj()))));
}

void Inscription::set_attributes(Pango::AttrList& attrs)
{
  gtk_inscription_set_attributes(gobj(), (attrs).gobj());
}

void Inscription::set_markup(const Glib::ustring& markup)
{
  gtk_inscription_set_markup(gobj(), markup.empty() ? nullptr : markup.c_str());
}

auto Inscription::get_text_overflow() const -> Inscription::Overflow
{
  return static_cast<Inscription::Overflow>(gtk_inscription_get_text_overflow(const_cast<GtkInscription*>(gobj())));
}

void Inscription::set_text_overflow(Overflow overflow)
{
  gtk_inscription_set_text_overflow(gobj(), static_cast<GtkInscriptionOverflow>(overflow));
}

auto Inscription::get_wrap_mode() const -> Pango::WrapMode
{
  return static_cast<Pango::WrapMode>(gtk_inscription_get_wrap_mode(const_cast<GtkInscription*>(gobj())));
}

void Inscription::set_wrap_mode(Pango::WrapMode wrap_mode)
{
  gtk_inscription_set_wrap_mode(gobj(), static_cast<PangoWrapMode>(wrap_mode));
}

auto Inscription::get_min_chars() const -> unsigned int
{
  return gtk_inscription_get_min_chars(const_cast<GtkInscription*>(gobj()));
}

void Inscription::set_min_chars(unsigned int min_chars)
{
  gtk_inscription_set_min_chars(gobj(), min_chars);
}

auto Inscription::get_nat_chars() const -> unsigned int
{
  return gtk_inscription_get_nat_chars(const_cast<GtkInscription*>(gobj()));
}

void Inscription::set_nat_chars(unsigned int nat_chars)
{
  gtk_inscription_set_nat_chars(gobj(), nat_chars);
}

auto Inscription::get_min_lines() const -> unsigned int
{
  return gtk_inscription_get_min_lines(const_cast<GtkInscription*>(gobj()));
}

void Inscription::set_min_lines(unsigned int min_lines)
{
  gtk_inscription_set_min_lines(gobj(), min_lines);
}

auto Inscription::get_nat_lines() const -> unsigned int
{
  return gtk_inscription_get_nat_lines(const_cast<GtkInscription*>(gobj()));
}

void Inscription::set_nat_lines(unsigned int nat_lines)
{
  gtk_inscription_set_nat_lines(gobj(), nat_lines);
}

auto Inscription::get_xalign() const -> float
{
  return gtk_inscription_get_xalign(const_cast<GtkInscription*>(gobj()));
}

void Inscription::set_xalign(float xalign)
{
  gtk_inscription_set_xalign(gobj(), xalign);
}

auto Inscription::get_yalign() const -> float
{
  return gtk_inscription_get_yalign(const_cast<GtkInscription*>(gobj()));
}

void Inscription::set_yalign(float yalign)
{
  gtk_inscription_set_yalign(gobj(), yalign);
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Pango::AttrList>::value,
  "Type Pango::AttrList cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Inscription::property_attributes() -> Glib::PropertyProxy< Pango::AttrList >
{
  return Glib::PropertyProxy< Pango::AttrList >(this, "attributes");
}

auto Inscription::property_attributes() const -> Glib::PropertyProxy_ReadOnly< Pango::AttrList >
{
  return Glib::PropertyProxy_ReadOnly< Pango::AttrList >(this, "attributes");
}

auto Inscription::property_markup() -> Glib::PropertyProxy_WriteOnly< Glib::ustring >
{
  return Glib::PropertyProxy_WriteOnly< Glib::ustring >(this, "markup");
}

auto Inscription::property_min_chars() -> Glib::PropertyProxy< unsigned int >
{
  return Glib::PropertyProxy< unsigned int >(this, "min-chars");
}

auto Inscription::property_min_chars() const -> Glib::PropertyProxy_ReadOnly< unsigned int >
{
  return Glib::PropertyProxy_ReadOnly< unsigned int >(this, "min-chars");
}

auto Inscription::property_min_lines() -> Glib::PropertyProxy< unsigned int >
{
  return Glib::PropertyProxy< unsigned int >(this, "min-lines");
}

auto Inscription::property_min_lines() const -> Glib::PropertyProxy_ReadOnly< unsigned int >
{
  return Glib::PropertyProxy_ReadOnly< unsigned int >(this, "min-lines");
}

auto Inscription::property_nat_chars() -> Glib::PropertyProxy< unsigned int >
{
  return Glib::PropertyProxy< unsigned int >(this, "nat-chars");
}

auto Inscription::property_nat_chars() const -> Glib::PropertyProxy_ReadOnly< unsigned int >
{
  return Glib::PropertyProxy_ReadOnly< unsigned int >(this, "nat-chars");
}

auto Inscription::property_nat_lines() -> Glib::PropertyProxy< unsigned int >
{
  return Glib::PropertyProxy< unsigned int >(this, "nat-lines");
}

auto Inscription::property_nat_lines() const -> Glib::PropertyProxy_ReadOnly< unsigned int >
{
  return Glib::PropertyProxy_ReadOnly< unsigned int >(this, "nat-lines");
}

auto Inscription::property_text() -> Glib::PropertyProxy< Glib::ustring >
{
  return Glib::PropertyProxy< Glib::ustring >(this, "text");
}

auto Inscription::property_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "text");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Inscription::Overflow>::value,
  "Type Inscription::Overflow cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Inscription::property_text_overflow() -> Glib::PropertyProxy< Inscription::Overflow >
{
  return Glib::PropertyProxy< Inscription::Overflow >(this, "text-overflow");
}

auto Inscription::property_text_overflow() const -> Glib::PropertyProxy_ReadOnly< Inscription::Overflow >
{
  return Glib::PropertyProxy_ReadOnly< Inscription::Overflow >(this, "text-overflow");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Pango::WrapMode>::value,
  "Type Pango::WrapMode cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Inscription::property_wrap_mode() -> Glib::PropertyProxy< Pango::WrapMode >
{
  return Glib::PropertyProxy< Pango::WrapMode >(this, "wrap-mode");
}

auto Inscription::property_wrap_mode() const -> Glib::PropertyProxy_ReadOnly< Pango::WrapMode >
{
  return Glib::PropertyProxy_ReadOnly< Pango::WrapMode >(this, "wrap-mode");
}

auto Inscription::property_xalign() -> Glib::PropertyProxy< float >
{
  return Glib::PropertyProxy< float >(this, "xalign");
}

auto Inscription::property_xalign() const -> Glib::PropertyProxy_ReadOnly< float >
{
  return Glib::PropertyProxy_ReadOnly< float >(this, "xalign");
}

auto Inscription::property_yalign() -> Glib::PropertyProxy< float >
{
  return Glib::PropertyProxy< float >(this, "yalign");
}

auto Inscription::property_yalign() const -> Glib::PropertyProxy_ReadOnly< float >
{
  return Glib::PropertyProxy_ReadOnly< float >(this, "yalign");
}


} // namespace Gtk

