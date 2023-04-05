// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/inscription.hxx>
#include <libmm/gtk/inscription_p.hxx>

#include <gtk/gtk.h>

using Overflow = gtk::Inscription::Overflow;

namespace
{
}

auto
glib::Value<gtk::Inscription::Overflow>::value_type () -> GType
{
  return gtk_inscription_overflow_get_type ();
}

namespace glib
{

  auto
  wrap (GtkInscription* object, bool take_copy) -> gtk::Inscription*
  {
    return dynamic_cast<gtk::Inscription*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  Inscription_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = gtk_inscription_get_type ();
    }

    return *this;
  }

  auto
  Inscription_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Inscription ((GtkInscription*) (o)));
  }

  Inscription::Inscription (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Inscription::Inscription (GtkInscription* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Inscription::Inscription (Inscription&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  Inscription::operator= (Inscription&& src) noexcept -> Inscription&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  Inscription::~Inscription () noexcept
  {
    destroy_ ();
  }

  Inscription::CppClassType Inscription::inscription_class_;

  auto
  Inscription::get_type () -> GType
  {
    return inscription_class_.init ().get_type ();
  }

  auto
  Inscription::get_base_type () -> GType
  {
    return gtk_inscription_get_type ();
  }

  Inscription::Inscription ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (inscription_class_.init ()))
  {
  }

  Inscription::Inscription (const glib::ustring& text)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (inscription_class_.init (),
                                          "text",
                                          text.c_str (),
                                          nullptr))
  {
  }

  auto
  Inscription::get_text () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_inscription_get_text (const_cast<GtkInscription*> (gobj ())));
  }

  auto
  Inscription::set_text (const glib::ustring& text) -> void
  {
    gtk_inscription_set_text (gobj (), text.empty () ? nullptr : text.c_str ());
  }

  auto
  Inscription::get_attributes () const -> pango::AttrList
  {
    return pango::AttrList ((gtk_inscription_get_attributes (
        const_cast<GtkInscription*> (gobj ()))));
  }

  auto
  Inscription::set_attributes (pango::AttrList& attrs) -> void
  {
    gtk_inscription_set_attributes (gobj (), (attrs).gobj ());
  }

  auto
  Inscription::set_markup (const glib::ustring& markup) -> void
  {
    gtk_inscription_set_markup (gobj (),
                                markup.empty () ? nullptr : markup.c_str ());
  }

  auto
  Inscription::get_text_overflow () const -> Inscription::Overflow
  {
    return static_cast<Inscription::Overflow> (
        gtk_inscription_get_text_overflow (
            const_cast<GtkInscription*> (gobj ())));
  }

  auto
  Inscription::set_text_overflow (Overflow overflow) -> void
  {
    gtk_inscription_set_text_overflow (
        gobj (),
        static_cast<GtkInscriptionOverflow> (overflow));
  }

  auto
  Inscription::get_wrap_mode () const -> pango::WrapMode
  {
    return static_cast<pango::WrapMode> (
        gtk_inscription_get_wrap_mode (const_cast<GtkInscription*> (gobj ())));
  }

  auto
  Inscription::set_wrap_mode (pango::WrapMode wrap_mode) -> void
  {
    gtk_inscription_set_wrap_mode (gobj (),
                                   static_cast<PangoWrapMode> (wrap_mode));
  }

  auto
  Inscription::get_min_chars () const -> unsigned int
  {
    return gtk_inscription_get_min_chars (
        const_cast<GtkInscription*> (gobj ()));
  }

  auto
  Inscription::set_min_chars (unsigned int min_chars) -> void
  {
    gtk_inscription_set_min_chars (gobj (), min_chars);
  }

  auto
  Inscription::get_nat_chars () const -> unsigned int
  {
    return gtk_inscription_get_nat_chars (
        const_cast<GtkInscription*> (gobj ()));
  }

  auto
  Inscription::set_nat_chars (unsigned int nat_chars) -> void
  {
    gtk_inscription_set_nat_chars (gobj (), nat_chars);
  }

  auto
  Inscription::get_min_lines () const -> unsigned int
  {
    return gtk_inscription_get_min_lines (
        const_cast<GtkInscription*> (gobj ()));
  }

  auto
  Inscription::set_min_lines (unsigned int min_lines) -> void
  {
    gtk_inscription_set_min_lines (gobj (), min_lines);
  }

  auto
  Inscription::get_nat_lines () const -> unsigned int
  {
    return gtk_inscription_get_nat_lines (
        const_cast<GtkInscription*> (gobj ()));
  }

  auto
  Inscription::set_nat_lines (unsigned int nat_lines) -> void
  {
    gtk_inscription_set_nat_lines (gobj (), nat_lines);
  }

  auto
  Inscription::get_xalign () const -> float
  {
    return gtk_inscription_get_xalign (const_cast<GtkInscription*> (gobj ()));
  }

  auto
  Inscription::set_xalign (float xalign) -> void
  {
    gtk_inscription_set_xalign (gobj (), xalign);
  }

  auto
  Inscription::get_yalign () const -> float
  {
    return gtk_inscription_get_yalign (const_cast<GtkInscription*> (gobj ()));
  }

  auto
  Inscription::set_yalign (float yalign) -> void
  {
    gtk_inscription_set_yalign (gobj (), yalign);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<pango::AttrList>::value,
      "Type pango::AttrList cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Inscription::property_attributes () -> glib::PropertyProxy<pango::AttrList>
  {
    return glib::PropertyProxy<pango::AttrList> (this, "attributes");
  }

  auto
  Inscription::property_attributes () const -> glib::PropertyProxy_ReadOnly<pango::AttrList>
  {
    return glib::PropertyProxy_ReadOnly<pango::AttrList> (this, "attributes");
  }

  auto
  Inscription::property_markup () -> glib::PropertyProxy_WriteOnly<glib::ustring>
  {
    return glib::PropertyProxy_WriteOnly<glib::ustring> (this, "markup");
  }

  auto
  Inscription::property_min_chars () -> glib::PropertyProxy<unsigned int>
  {
    return glib::PropertyProxy<unsigned int> (this, "min-chars");
  }

  auto
  Inscription::property_min_chars () const -> glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return glib::PropertyProxy_ReadOnly<unsigned int> (this, "min-chars");
  }

  auto
  Inscription::property_min_lines () -> glib::PropertyProxy<unsigned int>
  {
    return glib::PropertyProxy<unsigned int> (this, "min-lines");
  }

  auto
  Inscription::property_min_lines () const -> glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return glib::PropertyProxy_ReadOnly<unsigned int> (this, "min-lines");
  }

  auto
  Inscription::property_nat_chars () -> glib::PropertyProxy<unsigned int>
  {
    return glib::PropertyProxy<unsigned int> (this, "nat-chars");
  }

  auto
  Inscription::property_nat_chars () const -> glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return glib::PropertyProxy_ReadOnly<unsigned int> (this, "nat-chars");
  }

  auto
  Inscription::property_nat_lines () -> glib::PropertyProxy<unsigned int>
  {
    return glib::PropertyProxy<unsigned int> (this, "nat-lines");
  }

  auto
  Inscription::property_nat_lines () const -> glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return glib::PropertyProxy_ReadOnly<unsigned int> (this, "nat-lines");
  }

  auto
  Inscription::property_text () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "text");
  }

  auto
  Inscription::property_text () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "text");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          Inscription::Overflow>::value,
      "Type Inscription::Overflow cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Inscription::property_text_overflow () -> glib::PropertyProxy<Inscription::Overflow>
  {
    return glib::PropertyProxy<Inscription::Overflow> (this, "text-overflow");
  }

  auto
  Inscription::property_text_overflow () const -> glib::PropertyProxy_ReadOnly<Inscription::Overflow>
  {
    return glib::PropertyProxy_ReadOnly<Inscription::Overflow> (
        this,
        "text-overflow");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<pango::WrapMode>::value,
      "Type pango::WrapMode cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Inscription::property_wrap_mode () -> glib::PropertyProxy<pango::WrapMode>
  {
    return glib::PropertyProxy<pango::WrapMode> (this, "wrap-mode");
  }

  auto
  Inscription::property_wrap_mode () const -> glib::PropertyProxy_ReadOnly<pango::WrapMode>
  {
    return glib::PropertyProxy_ReadOnly<pango::WrapMode> (this, "wrap-mode");
  }

  auto
  Inscription::property_xalign () -> glib::PropertyProxy<float>
  {
    return glib::PropertyProxy<float> (this, "xalign");
  }

  auto
  Inscription::property_xalign () const -> glib::PropertyProxy_ReadOnly<float>
  {
    return glib::PropertyProxy_ReadOnly<float> (this, "xalign");
  }

  auto
  Inscription::property_yalign () -> glib::PropertyProxy<float>
  {
    return glib::PropertyProxy<float> (this, "yalign");
  }

  auto
  Inscription::property_yalign () const -> glib::PropertyProxy_ReadOnly<float>
  {
    return glib::PropertyProxy_ReadOnly<float> (this, "yalign");
  }

} // namespace gtk
