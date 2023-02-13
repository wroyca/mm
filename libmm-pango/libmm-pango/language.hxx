
#ifndef _PANGOMM_LANGUAGE_H
#define _PANGOMM_LANGUAGE_H

#include <libmm-pango/mm-pangoconfig.hxx>


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2002 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


#include <libmm-glib/value.hxx>
#include <pango/pango.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _PangoLanguage PangoLanguage; }
#endif

namespace Pango
{

/** @addtogroup pangommEnums pangomm Enums and Flags */

/**
 *  @var Script INVALID_CODE
 * A value never returned from pango_script_for_unichar().
 *
 *  @var Script COMMON
 * A character used by multiple different scripts.
 *
 *  @var Script INHERITED
 * A mark glyph that takes its script from the
 * base glyph to which it is attached.
 *
 *  @var Script ARABIC
 * Arabic.
 *
 *  @var Script ARMENIAN
 * Armenian.
 *
 *  @var Script BENGALI
 * Bengali.
 *
 *  @var Script BOPOMOFO
 * Bopomofo.
 *
 *  @var Script CHEROKEE
 * Cherokee.
 *
 *  @var Script COPTIC
 * Coptic.
 *
 *  @var Script CYRILLIC
 * Cyrillic.
 *
 *  @var Script DESERET
 * Deseret.
 *
 *  @var Script DEVANAGARI
 * Devanagari.
 *
 *  @var Script ETHIOPIC
 * Ethiopic.
 *
 *  @var Script GEORGIAN
 * Georgian.
 *
 *  @var Script GOTHIC
 * Gothic.
 *
 *  @var Script GREEK
 * Greek.
 *
 *  @var Script GUJARATI
 * Gujarati.
 *
 *  @var Script GURMUKHI
 * Gurmukhi.
 *
 *  @var Script HAN
 * Han.
 *
 *  @var Script HANGUL
 * Hangul.
 *
 *  @var Script HEBREW
 * Hebrew.
 *
 *  @var Script HIRAGANA
 * Hiragana.
 *
 *  @var Script KANNADA
 * Kannada.
 *
 *  @var Script KATAKANA
 * Katakana.
 *
 *  @var Script KHMER
 * Khmer.
 *
 *  @var Script LAO
 * Lao.
 *
 *  @var Script LATIN
 * Latin.
 *
 *  @var Script MALAYALAM
 * Malayalam.
 *
 *  @var Script MONGOLIAN
 * Mongolian.
 *
 *  @var Script MYANMAR
 * Myanmar.
 *
 *  @var Script OGHAM
 * Ogham.
 *
 *  @var Script OLD_ITALIC
 * Old Italic.
 *
 *  @var Script ORIYA
 * Oriya.
 *
 *  @var Script RUNIC
 * Runic.
 *
 *  @var Script SINHALA
 * Sinhala.
 *
 *  @var Script SYRIAC
 * Syriac.
 *
 *  @var Script TAMIL
 * Tamil.
 *
 *  @var Script TELUGU
 * Telugu.
 *
 *  @var Script THAANA
 * Thaana.
 *
 *  @var Script THAI
 * Thai.
 *
 *  @var Script TIBETAN
 * Tibetan.
 *
 *  @var Script CANADIAN_ABORIGINAL
 * Canadian Aboriginal.
 *
 *  @var Script YI
 * Yi.
 *
 *  @var Script TAGALOG
 * Tagalog.
 *
 *  @var Script HANUNOO
 * Hanunoo.
 *
 *  @var Script BUHID
 * Buhid.
 *
 *  @var Script TAGBANWA
 * Tagbanwa.
 *
 *  @var Script BRAILLE
 * Braille.
 *
 *  @var Script CYPRIOT
 * Cypriot.
 *
 *  @var Script LIMBU
 * Limbu.
 *
 *  @var Script OSMANYA
 * Osmanya.
 *
 *  @var Script SHAVIAN
 * Shavian.
 *
 *  @var Script LINEAR_B
 * Linear B.
 *
 *  @var Script TAI_LE
 * Tai Le.
 *
 *  @var Script UGARITIC
 * Ugaritic.
 *
 *  @var Script NEW_TAI_LUE
 * New Tai Lue. @newin{1,10}
 *
 *  @var Script BUGINESE
 * Buginese. @newin{1,10}
 *
 *  @var Script GLAGOLITIC
 * Glagolitic. @newin{1,10}
 *
 *  @var Script TIFINAGH
 * Tifinagh. @newin{1,10}
 *
 *  @var Script SYLOTI_NAGRI
 * Syloti Nagri. @newin{1,10}
 *
 *  @var Script OLD_PERSIAN
 * Old Persian. @newin{1,10}
 *
 *  @var Script KHAROSHTHI
 * Kharoshthi. @newin{1,10}
 *
 *  @var Script UNKNOWN
 * An unassigned code point. @newin{1,14}
 *
 *  @var Script BALINESE
 * Balinese. @newin{1,14}
 *
 *  @var Script CUNEIFORM
 * Cuneiform. @newin{1,14}
 *
 *  @var Script PHOENICIAN
 * Phoenician. @newin{1,14}
 *
 *  @var Script PHAGS_PA
 * Phags-pa. @newin{1,14}
 *
 *  @var Script NKO
 * N'Ko. @newin{1,14}
 *
 *  @var Script KAYAH_LI
 * Kayah Li. @newin{1,20,1}
 *
 *  @var Script LEPCHA
 * Lepcha. @newin{1,20,1}
 *
 *  @var Script REJANG
 * Rejang. @newin{1,20,1}
 *
 *  @var Script SUNDANESE
 * Sundanese. @newin{1,20,1}
 *
 *  @var Script SAURASHTRA
 * Saurashtra. @newin{1,20,1}
 *
 *  @var Script CHAM
 * Cham. @newin{1,20,1}
 *
 *  @var Script OL_CHIKI
 * Ol Chiki. @newin{1,20,1}
 *
 *  @var Script VAI
 * Vai. @newin{1,20,1}
 *
 *  @var Script CARIAN
 * Carian. @newin{1,20,1}
 *
 *  @var Script LYCIAN
 * Lycian. @newin{1,20,1}
 *
 *  @var Script LYDIAN
 * Lydian. @newin{1,20,1}
 *
 *  @var Script BATAK
 * Batak. @newin{1,32}
 *
 *  @var Script BRAHMI
 * Brahmi. @newin{1,32}
 *
 *  @var Script MANDAIC
 * Mandaic. @newin{1,32}
 *
 *  @var Script CHAKMA
 * Chakma. @newin{1,32}
 *
 *  @var Script MEROITIC_CURSIVE
 * Meroitic Cursive. @newin{1,32}
 *
 *  @var Script MEROITIC_HIEROGLYPHS
 * Meroitic Hieroglyphs. @newin{1,32}
 *
 *  @var Script MIAO
 * Miao. @newin{1,32}
 *
 *  @var Script SHARADA
 * Sharada. @newin{1,32}
 *
 *  @var Script SORA_SOMPENG
 * Sora Sompeng. @newin{1,32}
 *
 *  @var Script TAKRI
 * Takri. @newin{1,32}
 *
 *  @var Script BASSA_VAH
 * Bassa. @newin{1,40}
 *
 *  @var Script CAUCASIAN_ALBANIAN
 * Caucasian Albanian. @newin{1,40}
 *
 *  @var Script DUPLOYAN
 * Duployan. @newin{1,40}
 *
 *  @var Script ELBASAN
 * Elbasan. @newin{1,40}
 *
 *  @var Script GRANTHA
 * Grantha. @newin{1,40}
 *
 *  @var Script KHOJKI
 * Kjohki. @newin{1,40}
 *
 *  @var Script KHUDAWADI
 * Khudawadi, Sindhi. @newin{1,40}
 *
 *  @var Script LINEAR_A
 * Linear A. @newin{1,40}
 *
 *  @var Script MAHAJANI
 * Mahajani. @newin{1,40}
 *
 *  @var Script MANICHAEAN
 * Manichaean. @newin{1,40}
 *
 *  @var Script MENDE_KIKAKUI
 * Mende Kikakui. @newin{1,40}
 *
 *  @var Script MODI
 * Modi. @newin{1,40}
 *
 *  @var Script MRO
 * Mro. @newin{1,40}
 *
 *  @var Script NABATAEAN
 * Nabataean. @newin{1,40}
 *
 *  @var Script OLD_NORTH_ARABIAN
 * Old North Arabian. @newin{1,40}
 *
 *  @var Script OLD_PERMIC
 * Old Permic. @newin{1,40}
 *
 *  @var Script PAHAWH_HMONG
 * Pahawh Hmong. @newin{1,40}
 *
 *  @var Script PALMYRENE
 * Palmyrene. @newin{1,40}
 *
 *  @var Script PAU_CIN_HAU
 * Pau Cin Hau. @newin{1,40}
 *
 *  @var Script PSALTER_PAHLAVI
 * Psalter Pahlavi. @newin{1,40}
 *
 *  @var Script SIDDHAM
 * Siddham. @newin{1,40}
 *
 *  @var Script TIRHUTA
 * Tirhuta. @newin{1,40}
 *
 *  @var Script WARANG_CITI
 * Warang Citi. @newin{1,40}
 *
 *  @var Script AHOM
 * Ahom. @newin{1,40}
 *
 *  @var Script ANATOLIAN_HIEROGLYPHS
 * Anatolian Hieroglyphs. @newin{1,40}
 *
 *  @var Script HATRAN
 * Hatran. @newin{1,40}
 *
 *  @var Script MULTANI
 * Multani. @newin{1,40}
 *
 *  @var Script OLD_HUNGARIAN
 * Old Hungarian. @newin{1,40}
 *
 *  @var Script SIGNWRITING
 * Signwriting. @newin{1,40}
 *
 *  @enum Script
 *
 * The `Pango::Script` enumeration identifies different writing
 * systems.
 *
 * The values correspond to the names as defined in the Unicode standard. See
 * [Unicode Standard Annex 24: Script names](http://www.unicode.org/reports/tr24/)
 *
 * Note that this enumeration is deprecated and will not be updated
 * to include values in newer versions of the Unicode standard.
 * Applications should use the `UnicodeScript` enumeration instead,
 * whose values are interchangeable with `Pango::Script`.
 *
 * @ingroup pangommEnums
 */
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
class PANGOMM_API Value<Pango::Script> : public Glib::Value_Enum<Pango::Script>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Pango
{


/** A Pango::Language is used to represent a language.
 */
class PANGOMM_API Language
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = Language;
  using BaseObjectType = PangoLanguage;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType G_GNUC_CONST;


  explicit Language(PangoLanguage* gobject, bool make_a_copy = true);

  Language(const Language& other);
  auto operator=(const Language& other) -> Language&;

  Language(Language&& other) noexcept;
  auto operator=(Language&& other) noexcept -> Language&;

  ~Language() noexcept;

  void swap(Language& other) noexcept;

  ///Provides access to the underlying C instance.
  auto       gobj() -> PangoLanguage*       { return gobject_; }

  ///Provides access to the underlying C instance.
  auto gobj() const -> const PangoLanguage* { return gobject_; }

  ///Provides access to the underlying C instance. The caller is responsible for freeing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> PangoLanguage*;

protected:
  PangoLanguage* gobject_;

private:

   //This function is a bad hack for internal use by renderers and Pango (from pango/pango-utils.c)
   //This is defined as a macro


public:
  /** Constructs an empty language tag.
   */
  Language();

  /** Constructs a Pango::Language object from a RFC-3066 format language tag.
   * This function first canonicalizes the string by converting it to lowercase,
   * mapping '_' to '-', and stripping all characters other than letters and '-'.
   */
  Language(const Glib::ustring& language);

  /** Gets a RFC-3066 format string representing the given language tag.
   * @return A string representing the language tag. An empty string is returned if the language tag is empty.
   */
  auto get_string() const -> Glib::ustring;


  /** Checks if a language tag matches one of the elements in a list of
   * language ranges.
   *
   * A language tag is considered to match a range in the list if the
   * range is '*', the range is exactly the tag, or the range is a prefix
   * of the tag, and the character after it in the tag is '-'.
   *
   * @param range_list A list of language ranges, separated by ';', ':',
   * ',', or space characters.
   * Each element must either be '*', or a RFC 3066 language range
   * canonicalized as by from_string().
   * @return <tt>true</tt> if a match was found.
   */
  auto matches(const Glib::ustring & range_list) const -> bool;

  /** Determines if @a script is one of the scripts used to
   * write @a language.
   *
   * The returned value is conservative; if nothing is known about
   * the language tag @a language, <tt>true</tt> will be returned, since, as
   * far as Pango knows, @a script might be used to write @a language.
   *
   * This routine is used in Pango's itemization process when
   * determining if a supplied language tag is relevant to
   * a particular section of text. It probably is not useful
   * for applications in most circumstances.
   *
   * This function uses get_scripts() internally.
   *
   * @newin{1,4}
   *
   * @param script A `Pango::Script`.
   * @return <tt>true</tt> if @a script is one of the scripts used
   * to write @a language or if nothing is known about @a language
   * (including the case that @a language is <tt>nullptr</tt>), <tt>false</tt> otherwise.
   */
  auto includes_script(Script script) const -> bool;


 /** Determines the scripts used to to write this language.
   * If nothing is known about the language tag then an empty container is returned.
   * The list of scripts returned starts with the script that the
   * language uses most and continues to the one it uses least.
   *
   * Most languages use only one script for writing, but there are
   * some that use two (Latin and Cyrillic for example), and a few
   * use three (Japanese for example).  Applications should not make
   * any assumptions on the maximum number of scripts returned
   * though, except that it is a small number.
   *
   * @result A container of Script values.
   *
   * @newin{2,14}
   */
  auto get_scripts() const -> std::vector<Script>;


};

} /* namespace Pango */


namespace Pango
{

/** @relates Pango::Language
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 */
inline void swap(Language& lhs, Language& rhs) noexcept
  { lhs.swap(rhs); }

} // namespace Pango

namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Pango::Language
 */
PANGOMM_API
auto wrap(PangoLanguage* object, bool take_copy = false) -> Pango::Language;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class PANGOMM_API Value<Pango::Language> : public Glib::Value_Boxed<Pango::Language>
{};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif /* _PANGOMM_LANGUAGE_H */

