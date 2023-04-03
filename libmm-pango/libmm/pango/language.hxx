// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_LANGUAGE_H
#define _PANGOMM_LANGUAGE_H

#include <libmm/pango/mm-pangoconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/value.hxx>
#include <pango/pango.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _PangoLanguage PangoLanguage;
}
#endif

namespace Pango
{

  enum class Script
  {
    INVALID_CODE = -1,
    COMMON,
    INHERITED,
    ARABIC,
    ARMENIAN,
    BENGALI,
    BOPOMOFO,
    CHEROKEE,
    COPTIC,
    CYRILLIC,
    DESERET,
    DEVANAGARI,
    ETHIOPIC,
    GEORGIAN,
    GOTHIC,
    GREEK,
    GUJARATI,
    GURMUKHI,
    HAN,
    HANGUL,
    HEBREW,
    HIRAGANA,
    KANNADA,
    KATAKANA,
    KHMER,
    LAO,
    LATIN,
    MALAYALAM,
    MONGOLIAN,
    MYANMAR,
    OGHAM,
    OLD_ITALIC,
    ORIYA,
    RUNIC,
    SINHALA,
    SYRIAC,
    TAMIL,
    TELUGU,
    THAANA,
    THAI,
    TIBETAN,
    CANADIAN_ABORIGINAL,
    YI,
    TAGALOG,
    HANUNOO,
    BUHID,
    TAGBANWA,
    BRAILLE,
    CYPRIOT,
    LIMBU,
    OSMANYA,
    SHAVIAN,
    LINEAR_B,
    TAI_LE,
    UGARITIC,
    NEW_TAI_LUE,
    BUGINESE,
    GLAGOLITIC,
    TIFINAGH,
    SYLOTI_NAGRI,
    OLD_PERSIAN,
    KHAROSHTHI,
    UNKNOWN,
    BALINESE,
    CUNEIFORM,
    PHOENICIAN,
    PHAGS_PA,
    NKO,
    KAYAH_LI,
    LEPCHA,
    REJANG,
    SUNDANESE,
    SAURASHTRA,
    CHAM,
    OL_CHIKI,
    VAI,
    CARIAN,
    LYCIAN,
    LYDIAN,
    BATAK,
    BRAHMI,
    MANDAIC,
    CHAKMA,
    MEROITIC_CURSIVE,
    MEROITIC_HIEROGLYPHS,
    MIAO,
    SHARADA,
    SORA_SOMPENG,
    TAKRI,
    BASSA_VAH,
    CAUCASIAN_ALBANIAN,
    DUPLOYAN,
    ELBASAN,
    GRANTHA,
    KHOJKI,
    KHUDAWADI,
    LINEAR_A,
    MAHAJANI,
    MANICHAEAN,
    MENDE_KIKAKUI,
    MODI,
    MRO,
    NABATAEAN,
    OLD_NORTH_ARABIAN,
    OLD_PERMIC,
    PAHAWH_HMONG,
    PALMYRENE,
    PAU_CIN_HAU,
    PSALTER_PAHLAVI,
    SIDDHAM,
    TIRHUTA,
    WARANG_CITI,
    AHOM,
    ANATOLIAN_HIEROGLYPHS,
    HATRAN,
    MULTANI,
    OLD_HUNGARIAN,
    SIGNWRITING
  };

} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_PANGO_SYMEXPORT Value<Pango::Script>
    : public Glib::Value_Enum<Pango::Script>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Pango
{

  class LIBMM_PANGO_SYMEXPORT Language
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Language;
    using BaseObjectType = PangoLanguage;
#endif

    static auto
    get_type () -> GType G_GNUC_CONST;

    explicit Language (PangoLanguage* gobject, bool make_a_copy = true);

    Language (const Language& other);
    auto
    operator= (const Language& other) -> Language&;

    Language (Language&& other) noexcept;
    auto
    operator= (Language&& other) noexcept -> Language&;

    ~Language () noexcept;

    auto
    swap (Language& other) noexcept -> void;

    auto
    gobj () -> PangoLanguage*
    {
      return gobject_;
    }

    auto
    gobj () const -> const PangoLanguage*
    {
      return gobject_;
    }

    auto
    gobj_copy () const -> PangoLanguage*;

  protected:
    PangoLanguage* gobject_;

  private:
  public:
    Language ();

    Language (const Glib::ustring& language);

    auto
    get_string () const -> Glib::ustring;

    auto
    matches (const Glib::ustring& range_list) const -> bool;

    auto
    includes_script (Script script) const -> bool;

    auto
    get_scripts () const -> std::vector<Script>;
  };

} // namespace Pango

namespace Pango
{

  inline auto
  swap (Language& lhs, Language& rhs) noexcept -> void
  {
    lhs.swap (rhs);
  }

} // namespace Pango

namespace Glib
{

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (PangoLanguage* object, bool take_copy = false) -> Pango::Language;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class LIBMM_PANGO_SYMEXPORT Value<Pango::Language>
    : public Glib::Value_Boxed<Pango::Language>
  {
  };
#endif

} // namespace Glib

#endif
