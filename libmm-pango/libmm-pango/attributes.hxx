// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_ATTRIBUTES_H
#define _PANGOMM_ATTRIBUTES_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-pango/color.hxx>
#include <libmm-pango/fontdescription.hxx>
#include <libmm-pango/language.hxx>
#include <libmm-pango/rectangle.hxx>
#include <pango/pango.h>

namespace Pango
{

  enum class AttrType
  {
    INVALID,
    LANGUAGE,
    FAMILY,
    STYLE,
    WEIGHT,
    VARIANT,
    STRETCH,
    SIZE,
    FONT_DESC,
    FOREGROUND,
    BACKGROUND,
    UNDERLINE,
    STRIKETHROUGH,
    RISE,
    SHAPE,
    SCALE_FACTOR,
    FALLBACK,
    LETTER_SPACING,
    UNDERLINE_COLOR,
    STRIKETHROUGH_COLOR,
    ABSOLUTE_SIZE,
    GRAVITY,
    GRAVITY_HINT,
    FONT_FEATURES,
    FOREGROUND_ALPHA,
    BACKGROUND_ALPHA,
    ALLOW_BREAKS,
    SHOW,
    INSERT_HYPHENS,
    OVERLINE,
    OVERLINE_COLOR,
    LINE_HEIGHT,
    ABSOLUTE_LINE_HEIGHT,
    TEXT_TRANSFORM,
    WORD,
    SENTENCE,
    BASELINE_SHIFT,
    FONT_SCALE
  };

} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_PANGO_SYMEXPORT Value<Pango::AttrType>
    : public Glib::Value_Enum<Pango::AttrType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Pango
{

  enum class Underline
  {
    NONE,
    SINGLE,
    DOUBLE,
    LOW,
    ERROR,
    SINGLE_LINE,
    DOUBLE_LINE,
    ERROR_LINE
  };

} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_PANGO_SYMEXPORT Value<Pango::Underline>
    : public Glib::Value_Enum<Pango::Underline>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Pango
{

  enum class Overline
  {
    NONE,
    SINGLE
  };

} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_PANGO_SYMEXPORT Value<Pango::Overline>
    : public Glib::Value_Enum<Pango::Overline>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Pango
{

  enum class ShowFlags
  {
    NONE = 0x0,
    SPACES = 1 << 0,
    LINE_BREAKS = 1 << 1,
    IGNORABLES = 1 << 2
  };

  inline auto
  operator| (ShowFlags lhs, ShowFlags rhs) -> ShowFlags
  {
    return static_cast<ShowFlags> (static_cast<unsigned> (lhs) |
                                   static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (ShowFlags lhs, ShowFlags rhs) -> ShowFlags
  {
    return static_cast<ShowFlags> (static_cast<unsigned> (lhs) &
                                   static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (ShowFlags lhs, ShowFlags rhs) -> ShowFlags
  {
    return static_cast<ShowFlags> (static_cast<unsigned> (lhs) ^
                                   static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(ShowFlags flags) -> ShowFlags
  {
    return static_cast<ShowFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (ShowFlags& lhs, ShowFlags rhs) -> ShowFlags&
  {
    return (lhs = static_cast<ShowFlags> (static_cast<unsigned> (lhs) |
                                          static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (ShowFlags& lhs, ShowFlags rhs) -> ShowFlags&
  {
    return (lhs = static_cast<ShowFlags> (static_cast<unsigned> (lhs) &
                                          static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (ShowFlags& lhs, ShowFlags rhs) -> ShowFlags&
  {
    return (lhs = static_cast<ShowFlags> (static_cast<unsigned> (lhs) ^
                                          static_cast<unsigned> (rhs)));
  }

} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_PANGO_SYMEXPORT Value<Pango::ShowFlags>
    : public Glib::Value_Flags<Pango::ShowFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Pango
{

  enum class TextTransform
  {
    NONE,
    LOWERCASE,
    UPPERCASE,
    CAPITALIZE
  };

} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_PANGO_SYMEXPORT Value<Pango::TextTransform>
    : public Glib::Value_Enum<Pango::TextTransform>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Pango
{

  class BaselineShift_Wrapper final
  {
  public:
    enum BaselineShift
    {
      NONE,
      SUPERSCRIPT,
      SUBSCRIPT
    };
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    BaselineShift_Wrapper () = delete;
#endif
  };

  using BaselineShift = BaselineShift_Wrapper::BaselineShift;

} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_PANGO_SYMEXPORT Value<Pango::BaselineShift>
    : public Glib::Value_Enum<Pango::BaselineShift>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Pango
{

  enum class FontScale
  {
    NONE,
    SUPERSCRIPT,
    SUBSCRIPT,
    SMALL_CAPS
  };

} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_PANGO_SYMEXPORT Value<Pango::FontScale>
    : public Glib::Value_Enum<Pango::FontScale>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Pango
{

  typedef PangoLogAttr LogAttr;

  class LIBMM_PANGO_SYMEXPORT AttrString;
  class LIBMM_PANGO_SYMEXPORT AttrLanguage;
  class LIBMM_PANGO_SYMEXPORT AttrColor;
  class LIBMM_PANGO_SYMEXPORT AttrInt;
  class LIBMM_PANGO_SYMEXPORT AttrFloat;
  class LIBMM_PANGO_SYMEXPORT AttrFontDesc;
  class LIBMM_PANGO_SYMEXPORT AttrShape;

  enum class LIBMM_PANGO_SYMEXPORT GravityHint;

  class LIBMM_PANGO_SYMEXPORT Attribute
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Attribute;
    using BaseObjectType = PangoAttribute;
#endif

  private:
  public:
    Attribute ();

    Attribute (const Attribute& src);
    explicit Attribute (PangoAttribute* castitem, bool take_copy = true);
    ~Attribute ();

    auto
    operator= (const Attribute& src) -> Attribute&;

    auto
    get_type () const -> AttrType;

    static auto
    register_type (const Glib::ustring& name) -> AttrType;

    static auto
    get_type_name (AttrType type) -> Glib::ustring;

    auto
    get_start_index () const -> unsigned int;

    auto
    get_end_index () const -> unsigned int;

    auto
    set_start_index (const unsigned int& value) -> void;

    auto
    set_end_index (const unsigned int& value) -> void;

    auto
    equal (const Attribute& attr2) const -> bool;

    auto
    gobj () -> PangoAttribute*
    {
      return gobject_;
    }

    auto
    gobj () const -> const PangoAttribute*
    {
      return gobject_;
    }

    static auto
    create_attr_family (const Glib::ustring& family) -> AttrString;

    static auto
    create_attr_language (const Language& language) -> AttrLanguage;

    static auto
    create_attr_foreground (guint16 red, guint16 green, guint16 blue)
        -> AttrColor;

    static auto
    create_attr_background (guint16 red, guint16 green, guint16 blue)
        -> AttrColor;

    static auto
    create_attr_foreground_alpha (guint16 alpha) -> AttrInt;

    static auto
    create_attr_background_alpha (guint16 alpha) -> AttrInt;

    static auto
    create_attr_size (int size) -> AttrInt;

    static auto
    create_attr_size_absolute (int size) -> AttrInt;

    static auto
    create_attr_style (Style style) -> AttrInt;

    static auto
    create_attr_weight (Weight weight) -> AttrInt;

    static auto
    create_attr_variant (Variant variant) -> AttrInt;

    static auto
    create_attr_stretch (Stretch stretch) -> AttrInt;

    static auto
    create_attr_font_desc (const FontDescription& desc) -> AttrFontDesc;

    static auto
    create_attr_underline (Underline underline) -> AttrInt;

    static auto
    create_attr_underline_color (guint16 red, guint16 green, guint16 blue)
        -> AttrColor;

    static auto
    create_attr_overline (Overline overline) -> AttrInt;

    static auto
    create_attr_overline_color (guint16 red, guint16 green, guint16 blue)
        -> AttrColor;

    static auto
    create_attr_strikethrough (bool strikethrough) -> AttrInt;

    static auto
    create_attr_strikethrough_color (guint16 red, guint16 green, guint16 blue)
        -> AttrColor;

    static auto
    create_attr_rise (int rise) -> AttrInt;

    static auto
    create_attr_baseline_shift (int shift) -> AttrInt;

    static auto
    create_attr_font_scale (FontScale scale) -> AttrInt;

    static auto
    create_attr_scale (double scale_factor) -> AttrFloat;

    static auto
    create_attr_fallback (bool enable_fallback) -> AttrInt;

    static auto
    create_attr_letter_spacing (int letter_spacing) -> AttrInt;

    static auto
    create_attr_shape (const Rectangle& ink_rect, const Rectangle& logical_rect)
        -> AttrShape;

    static auto
    create_attr_gravity (Gravity gravity) -> AttrInt;

    static auto
    create_attr_gravity_hint (GravityHint hint) -> AttrInt;

    static auto
    create_attr_font_features (const Glib::ustring& features) -> AttrString;

    static auto
    create_attr_allow_breaks (bool allow_breaks) -> AttrInt;

    static auto
    create_attr_word () -> AttrInt;

    static auto
    create_attr_sentence () -> AttrInt;

    static auto
    create_attr_insert_hyphens (bool insert_hyphens) -> AttrInt;

    static auto
    create_attr_show (ShowFlags show) -> AttrInt;

    static auto
    create_attr_line_height (double factor) -> AttrFloat;

    static auto
    create_attr_line_height_absolute (int height) -> AttrInt;

    static auto
    create_attr_text_transform (TextTransform transform) -> AttrInt;

  protected:
    PangoAttribute* gobject_;
  };

  inline auto
  operator== (const Attribute& lhs, const Attribute& rhs) -> bool
  {
    return lhs.equal (rhs);
  }

  inline auto
  operator!= (const Attribute& lhs, const Attribute& rhs) -> bool
  {
    return !lhs.equal (rhs);
  }

  class LIBMM_PANGO_SYMEXPORT AttrString : public Attribute
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = AttrString;
    using BaseObjectType = PangoAttrString;
#endif

  private:
  protected:
    AttrString ();

  public:
    AttrString (const AttrString& src);
    explicit AttrString (PangoAttrString* castitem, bool take_copy = true);

    auto
    operator= (const AttrString& src) -> AttrString&;

    auto
    get_string () const -> Glib::ustring;

    auto
    set_string (const Glib::ustring& string) -> void;

    auto
    gobj () -> PangoAttrString*
    {
      return reinterpret_cast<PangoAttrString*> (gobject_);
    }

    auto
    gobj () const -> const PangoAttrString*
    {
      return reinterpret_cast<const PangoAttrString*> (gobject_);
    }
  };

  class LIBMM_PANGO_SYMEXPORT AttrLanguage : public Attribute
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = AttrLanguage;
    using BaseObjectType = PangoAttrLanguage;
#endif

  private:
  protected:
    AttrLanguage ();

  public:
    AttrLanguage (const AttrLanguage& src);
    explicit AttrLanguage (PangoAttrLanguage* castitem, bool take_copy = true);

    auto
    operator= (const AttrLanguage& src) -> AttrLanguage&;

    auto
    get_language () const -> Language;

    auto
    set_language (const Language& value) -> void;

    auto
    gobj () -> PangoAttrLanguage*
    {
      return reinterpret_cast<PangoAttrLanguage*> (gobject_);
    }

    auto
    gobj () const -> const PangoAttrLanguage*
    {
      return reinterpret_cast<const PangoAttrLanguage*> (gobject_);
    }
  };

  class LIBMM_PANGO_SYMEXPORT AttrColor : public Attribute
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = AttrColor;
    using BaseObjectType = PangoAttrColor;
#endif

  private:
  protected:
    AttrColor ();

  public:
    AttrColor (const AttrColor& src);
    explicit AttrColor (PangoAttrColor* castitem, bool take_copy = true);

    auto
    operator= (const AttrColor& src) -> AttrColor&;

    auto
    get_color () const -> Color;

    auto
    set_color (const Color& value) -> void;

    auto
    gobj () -> PangoAttrColor*
    {
      return reinterpret_cast<PangoAttrColor*> (gobject_);
    }

    auto
    gobj () const -> const PangoAttrColor*
    {
      return reinterpret_cast<const PangoAttrColor*> (gobject_);
    }
  };

  class LIBMM_PANGO_SYMEXPORT AttrInt : public Attribute
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = AttrInt;
    using BaseObjectType = PangoAttrInt;
#endif

  private:
  protected:
    AttrInt ();

  public:
    AttrInt (const AttrInt& src);
    explicit AttrInt (PangoAttrInt* castitem, bool take_copy = true);

    auto
    operator= (const AttrInt& src) -> AttrInt&;

    auto
    get_value () const -> int;

    auto
    set_value (const int& value) -> void;

    auto
    gobj () -> PangoAttrInt*
    {
      return reinterpret_cast<PangoAttrInt*> (gobject_);
    }

    auto
    gobj () const -> const PangoAttrInt*
    {
      return reinterpret_cast<const PangoAttrInt*> (gobject_);
    }
  };

  class LIBMM_PANGO_SYMEXPORT AttrFloat : public Attribute
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = AttrFloat;
    using BaseObjectType = PangoAttrFloat;
#endif

  private:
  protected:
    AttrFloat ();

  public:
    AttrFloat (const AttrFloat& src);
    explicit AttrFloat (PangoAttrFloat* castitem, bool take_copy = true);

    auto
    operator= (const AttrFloat& src) -> AttrFloat&;

    auto
    get_value () const -> double;

    auto
    set_value (const double& value) -> void;

    auto
    gobj () -> PangoAttrFloat*
    {
      return reinterpret_cast<PangoAttrFloat*> (gobject_);
    }

    auto
    gobj () const -> const PangoAttrFloat*
    {
      return reinterpret_cast<const PangoAttrFloat*> (gobject_);
    }
  };

  class LIBMM_PANGO_SYMEXPORT AttrFontDesc : public Attribute
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = AttrFontDesc;
    using BaseObjectType = PangoAttrFontDesc;
#endif

  private:
  protected:
    AttrFontDesc ();

  public:
    AttrFontDesc (const AttrFontDesc& src);
    explicit AttrFontDesc (PangoAttrFontDesc* castitem, bool take_copy = true);

    auto
    operator= (const AttrFontDesc& src) -> AttrFontDesc&;

    auto
    get_desc () const -> FontDescription;

    auto
    set_desc (const FontDescription& desc) -> void;

    auto
    gobj () -> PangoAttrFontDesc*
    {
      return reinterpret_cast<PangoAttrFontDesc*> (gobject_);
    }

    auto
    gobj () const -> const PangoAttrFontDesc*
    {
      return reinterpret_cast<const PangoAttrFontDesc*> (gobject_);
    }
  };

  class LIBMM_PANGO_SYMEXPORT AttrShape : public Attribute
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = AttrShape;
    using BaseObjectType = PangoAttrShape;
#endif

  private:
  protected:
    AttrShape ();

  public:
    AttrShape (const AttrShape& src);
    explicit AttrShape (PangoAttrShape* castitem, bool take_copy = true);

    auto
    operator= (const AttrShape& src) -> AttrShape&;

    auto
    get_ink_rect () const -> Rectangle;

    auto
    get_logical_rect () const -> Rectangle;

    auto
    set_ink_rect (const Rectangle& value) -> void;

    auto
    set_logical_rect (const Rectangle& value) -> void;

    auto
    gobj () -> PangoAttrShape*
    {
      return reinterpret_cast<PangoAttrShape*> (gobject_);
    }

    auto
    gobj () const -> const PangoAttrShape*
    {
      return reinterpret_cast<const PangoAttrShape*> (gobject_);
    }
  };

  struct AttributeTraits
  {
    typedef Pango::Attribute CppType;
    typedef const PangoAttribute* CType;
    typedef PangoAttribute* CTypeNonConst;

    static auto
    to_c_type (const CppType& obj) -> CType
    {
      return obj.gobj ();
    }

    static auto
    to_c_type (CType ptr) -> CType
    {
      return ptr;
    }

    static auto
    to_cpp_type (CType ptr) -> CppType
    {
      return CppType (const_cast<CTypeNonConst> (ptr), true);
    }

    static auto
    release_c_type (CType ptr) -> void
    {
      pango_attribute_destroy (const_cast<CTypeNonConst> (ptr));
    }
  };

} // namespace Pango

namespace Glib
{

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (PangoAttribute* object, bool take_copy = false) -> Pango::Attribute;

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (PangoAttrString* object, bool take_copy = false) -> Pango::AttrString;

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (PangoAttrLanguage* object, bool take_copy = false) -> Pango::AttrLanguage;

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (PangoAttrColor* object, bool take_copy = false) -> Pango::AttrColor;

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (PangoAttrInt* object, bool take_copy = false) -> Pango::AttrInt;

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (PangoAttrFloat* object, bool take_copy = false) -> Pango::AttrFloat;

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (PangoAttrFontDesc* object, bool take_copy = false) -> Pango::AttrFontDesc;

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (PangoAttrShape* object, bool take_copy = false) -> Pango::AttrShape;

} // namespace Glib

#endif
