
#ifndef _GTKMM_INSCRIPTION_H
#define _GTKMM_INSCRIPTION_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/widget.hxx>
#include <libmm-pango/attrlist.hxx>
#include <libmm-pango/layout.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Inscription_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Inscription : public Widget
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
    friend GTKMM_API class Inscription_Class;
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

    void
    set_text (const Glib::ustring& text);

    auto
    get_attributes () const -> Pango::AttrList;

    void
    set_attributes (Pango::AttrList& attrs);

    void
    set_markup (const Glib::ustring& markup);

    auto
    get_text_overflow () const -> Inscription::Overflow;

    void
    set_text_overflow (Overflow overflow);

    auto
    get_wrap_mode () const -> Pango::WrapMode;

    void
    set_wrap_mode (Pango::WrapMode wrap_mode);

    auto
    get_min_chars () const -> unsigned int;

    void
    set_min_chars (unsigned int min_chars);

    auto
    get_nat_chars () const -> unsigned int;

    void
    set_nat_chars (unsigned int nat_chars);

    auto
    get_min_lines () const -> unsigned int;

    void
    set_min_lines (unsigned int min_lines);

    auto
    get_nat_lines () const -> unsigned int;

    void
    set_nat_lines (unsigned int nat_lines);

    auto
    get_xalign () const -> float;

    void
    set_xalign (float xalign);

    auto
    get_yalign () const -> float;

    void
    set_yalign (float yalign);

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
  class GTKMM_API Value<Gtk::Inscription::Overflow>
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

  GTKMM_API
  auto
  wrap (GtkInscription* object, bool take_copy = false) -> Gtk::Inscription*;
} // namespace Glib

#endif
