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
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Inscription_Class;
}
#endif

namespace gtk
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
    explicit Inscription (const glib::ConstructParams& construct_params);
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

    explicit Inscription (const glib::ustring& text);

    auto
    get_text () const -> glib::ustring;

    auto
    set_text (const glib::ustring& text) -> void;

    auto
    get_attributes () const -> pango::AttrList;

    auto
    set_attributes (pango::AttrList& attrs) -> void;

    auto
    set_markup (const glib::ustring& markup) -> void;

    auto
    get_text_overflow () const -> Inscription::Overflow;

    auto
    set_text_overflow (Overflow overflow) -> void;

    auto
    get_wrap_mode () const -> pango::WrapMode;

    auto
    set_wrap_mode (pango::WrapMode wrap_mode) -> void;

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
    property_attributes () -> glib::PropertyProxy<pango::AttrList>;

    auto
    property_attributes () const
        -> glib::PropertyProxy_ReadOnly<pango::AttrList>;

    auto
    property_markup () -> glib::PropertyProxy_WriteOnly<glib::ustring>;

    auto
    property_min_chars () -> glib::PropertyProxy<unsigned int>;

    auto
    property_min_chars () const -> glib::PropertyProxy_ReadOnly<unsigned int>;

    auto
    property_min_lines () -> glib::PropertyProxy<unsigned int>;

    auto
    property_min_lines () const -> glib::PropertyProxy_ReadOnly<unsigned int>;

    auto
    property_nat_chars () -> glib::PropertyProxy<unsigned int>;

    auto
    property_nat_chars () const -> glib::PropertyProxy_ReadOnly<unsigned int>;

    auto
    property_nat_lines () -> glib::PropertyProxy<unsigned int>;

    auto
    property_nat_lines () const -> glib::PropertyProxy_ReadOnly<unsigned int>;

    auto
    property_text () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_text () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_text_overflow () -> glib::PropertyProxy<Inscription::Overflow>;

    auto
    property_text_overflow () const
        -> glib::PropertyProxy_ReadOnly<Inscription::Overflow>;

    auto
    property_wrap_mode () -> glib::PropertyProxy<pango::WrapMode>;

    auto
    property_wrap_mode () const
        -> glib::PropertyProxy_ReadOnly<pango::WrapMode>;

    auto
    property_xalign () -> glib::PropertyProxy<float>;

    auto
    property_xalign () const -> glib::PropertyProxy_ReadOnly<float>;

    auto
    property_yalign () -> glib::PropertyProxy<float>;

    auto
    property_yalign () const -> glib::PropertyProxy_ReadOnly<float>;

  public:
  public:
  protected:
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::Inscription::Overflow>
    : public glib::Value_Enum<gtk::Inscription::Overflow>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkInscription* object, bool take_copy = false) -> gtk::Inscription*;
} // namespace glib

#endif
