// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_INSCRIPTION_H
#define _GTKMM_INSCRIPTION_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/widget.hxx>
#include <libmm/pango/attrlist.hxx>
#include <libmm/pango/layout.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT Inscription_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT Inscription : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Inscription CppObjectType;
    typedef Inscription_Class CppClassType;
    typedef GtkInscription BaseObjectType;
    typedef GtkInscriptionClass BaseClassType;
#endif

    Inscription (Inscription&& src) noexcept;
    auto
    operator= (Inscription&& src) noexcept -> Inscription&;

    Inscription (const Inscription&) = delete;
    auto
    operator= (const Inscription&) -> Inscription& = delete;

    ~Inscription () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class Inscription_Class;
    static CppClassType inscription_class_;

  protected:
    explicit Inscription (const Glib::ConstructParams& construct_params);
    explicit Inscription (GtkInscription* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkInscription*
    {
      return reinterpret_cast<GtkInscription*> (gobject_);
    }

    auto
    gobj () const -> const GtkInscription*
    {
      return reinterpret_cast<GtkInscription*> (gobject_);
    }

  private:
  public:
    enum class Overflow
    {
      CLIP,
      ELLIPSIZE_START,
      ELLIPSIZE_MIDDLE,
      ELLIPSIZE_END
    };

    Inscription ();

    explicit Inscription (const Glib::ustring& text);

    auto
    get_text () const -> Glib::ustring;

    auto
    set_text (const Glib::ustring& text) -> void;

    auto
    get_attributes () const -> Pango::AttrList;

    auto
    set_attributes (Pango::AttrList& attrs) -> void;

    auto
    set_markup (const Glib::ustring& markup) -> void;

    auto
    get_text_overflow () const -> Inscription::Overflow;

    auto
    set_text_overflow (Overflow overflow) -> void;

    auto
    get_wrap_mode () const -> Pango::WrapMode;

    auto
    set_wrap_mode (Pango::WrapMode wrap_mode) -> void;

    auto
    get_min_chars () const -> unsigned int;

    auto
    set_min_chars (unsigned int min_chars) -> void;

    auto
    get_nat_chars () const -> unsigned int;

    auto
    set_nat_chars (unsigned int nat_chars) -> void;

    auto
    get_min_lines () const -> unsigned int;

    auto
    set_min_lines (unsigned int min_lines) -> void;

    auto
    get_nat_lines () const -> unsigned int;

    auto
    set_nat_lines (unsigned int nat_lines) -> void;

    auto
    get_xalign () const -> float;

    auto
    set_xalign (float xalign) -> void;

    auto
    get_yalign () const -> float;

    auto
    set_yalign (float yalign) -> void;

    auto
    property_attributes () -> Glib::PropertyProxy<Pango::AttrList>;

    auto
    property_attributes () const
        -> Glib::PropertyProxy_ReadOnly<Pango::AttrList>;

    auto
    property_markup () -> Glib::PropertyProxy_WriteOnly<Glib::ustring>;

    auto
    property_min_chars () -> Glib::PropertyProxy<unsigned int>;

    auto
    property_min_chars () const -> Glib::PropertyProxy_ReadOnly<unsigned int>;

    auto
    property_min_lines () -> Glib::PropertyProxy<unsigned int>;

    auto
    property_min_lines () const -> Glib::PropertyProxy_ReadOnly<unsigned int>;

    auto
    property_nat_chars () -> Glib::PropertyProxy<unsigned int>;

    auto
    property_nat_chars () const -> Glib::PropertyProxy_ReadOnly<unsigned int>;

    auto
    property_nat_lines () -> Glib::PropertyProxy<unsigned int>;

    auto
    property_nat_lines () const -> Glib::PropertyProxy_ReadOnly<unsigned int>;

    auto
    property_text () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_text () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_text_overflow () -> Glib::PropertyProxy<Inscription::Overflow>;

    auto
    property_text_overflow () const
        -> Glib::PropertyProxy_ReadOnly<Inscription::Overflow>;

    auto
    property_wrap_mode () -> Glib::PropertyProxy<Pango::WrapMode>;

    auto
    property_wrap_mode () const
        -> Glib::PropertyProxy_ReadOnly<Pango::WrapMode>;

    auto
    property_xalign () -> Glib::PropertyProxy<float>;

    auto
    property_xalign () const -> Glib::PropertyProxy_ReadOnly<float>;

    auto
    property_yalign () -> Glib::PropertyProxy<float>;

    auto
    property_yalign () const -> Glib::PropertyProxy_ReadOnly<float>;

  public:
  public:
  protected:
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<Gtk::Inscription::Overflow>
    : public Glib::Value_Enum<Gtk::Inscription::Overflow>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkInscription* object, bool take_copy = false) -> Gtk::Inscription*;
} // namespace Glib

#endif