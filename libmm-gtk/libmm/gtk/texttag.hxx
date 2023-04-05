// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TEXTTAG_H
#define _GTKMM_TEXTTAG_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/rgba.hxx>
#include <libmm/glib/object.hxx>
#include <libmm/gtk/enums.hxx>
#include <libmm/pango/attributes.hxx>
#include <libmm/pango/fontdescription.hxx>
#include <libmm/pango/tabarray.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTextTag = struct _GtkTextTag;
using GtkTextTagClass = struct _GtkTextTagClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT TextTag_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT TextTag : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = TextTag;
    using CppClassType = TextTag_Class;
    using BaseObjectType = GtkTextTag;
    using BaseClassType = GtkTextTagClass;

    TextTag (const TextTag&) = delete;
    auto
    operator= (const TextTag&) -> TextTag& = delete;

  private:
    friend class TextTag_Class;
    static CppClassType texttag_class_;

  protected:
    explicit TextTag (const glib::ConstructParams& construct_params);
    explicit TextTag (GtkTextTag* castitem);

#endif

  public:
    TextTag (TextTag&& src) noexcept;
    auto
    operator= (TextTag&& src) noexcept -> TextTag&;

    ~TextTag () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkTextTag*
    {
      return reinterpret_cast<GtkTextTag*> (gobject_);
    }

    auto
    gobj () const -> const GtkTextTag*
    {
      return reinterpret_cast<GtkTextTag*> (gobject_);
    }

    auto
    gobj_copy () -> GtkTextTag*;

  private:
  protected:
    TextTag ();
    explicit TextTag (const glib::ustring& name);

  public:
    static auto
    create () -> glib::RefPtr<TextTag>;

    static auto
    create (const glib::ustring& name) -> glib::RefPtr<TextTag>;

    auto
    get_priority () const -> int;

    auto
    set_priority (int priority) -> void;

    auto
    tag_changed (bool size_changed) -> void;

    auto
    property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_background () -> glib::PropertyProxy_WriteOnly<glib::ustring>;

    auto
    property_foreground () -> glib::PropertyProxy_WriteOnly<glib::ustring>;

    auto
    property_background_rgba () -> glib::PropertyProxy<gdk::RGBA>;

    auto
    property_background_rgba () const
        -> glib::PropertyProxy_ReadOnly<gdk::RGBA>;

    auto
    property_foreground_rgba () -> glib::PropertyProxy<gdk::RGBA>;

    auto
    property_foreground_rgba () const
        -> glib::PropertyProxy_ReadOnly<gdk::RGBA>;

    auto
    property_font () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_font () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_font_desc () -> glib::PropertyProxy<pango::FontDescription>;

    auto
    property_font_desc () const
        -> glib::PropertyProxy_ReadOnly<pango::FontDescription>;

    auto
    property_family () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_family () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_style () -> glib::PropertyProxy<pango::Style>;

    auto
    property_style () const -> glib::PropertyProxy_ReadOnly<pango::Style>;

    auto
    property_variant () -> glib::PropertyProxy<pango::Variant>;

    auto
    property_variant () const -> glib::PropertyProxy_ReadOnly<pango::Variant>;

    auto
    property_weight () -> glib::PropertyProxy<int>;

    auto
    property_weight () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_stretch () -> glib::PropertyProxy<pango::Stretch>;

    auto
    property_stretch () const -> glib::PropertyProxy_ReadOnly<pango::Stretch>;

    auto
    property_size () -> glib::PropertyProxy<int>;

    auto
    property_size () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_size_points () -> glib::PropertyProxy<double>;

    auto
    property_size_points () const -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_scale () -> glib::PropertyProxy<double>;

    auto
    property_scale () const -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_pixels_above_lines () -> glib::PropertyProxy<int>;

    auto
    property_pixels_above_lines () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_pixels_below_lines () -> glib::PropertyProxy<int>;

    auto
    property_pixels_below_lines () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_pixels_inside_wrap () -> glib::PropertyProxy<int>;

    auto
    property_pixels_inside_wrap () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_editable () -> glib::PropertyProxy<bool>;

    auto
    property_editable () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_wrap_mode () -> glib::PropertyProxy<WrapMode>;

    auto
    property_wrap_mode () const -> glib::PropertyProxy_ReadOnly<WrapMode>;

    auto
    property_justification () -> glib::PropertyProxy<Justification>;

    auto
    property_justification () const
        -> glib::PropertyProxy_ReadOnly<Justification>;

    auto
    property_direction () -> glib::PropertyProxy<TextDirection>;

    auto
    property_direction () const -> glib::PropertyProxy_ReadOnly<TextDirection>;

    auto
    property_left_margin () -> glib::PropertyProxy<int>;

    auto
    property_left_margin () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_indent () -> glib::PropertyProxy<int>;

    auto
    property_indent () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_line_height () -> glib::PropertyProxy<float>;

    auto
    property_line_height () const -> glib::PropertyProxy_ReadOnly<float>;

    auto
    property_strikethrough () -> glib::PropertyProxy<bool>;

    auto
    property_strikethrough () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_strikethrough_rgba () -> glib::PropertyProxy<gdk::RGBA>;

    auto
    property_strikethrough_rgba () const
        -> glib::PropertyProxy_ReadOnly<gdk::RGBA>;

    auto
    property_right_margin () -> glib::PropertyProxy<int>;

    auto
    property_right_margin () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_underline () -> glib::PropertyProxy<pango::Underline>;

    auto
    property_underline () const
        -> glib::PropertyProxy_ReadOnly<pango::Underline>;

    auto
    property_underline_rgba () -> glib::PropertyProxy<gdk::RGBA>;

    auto
    property_underline_rgba () const -> glib::PropertyProxy_ReadOnly<gdk::RGBA>;

    auto
    property_overline () -> glib::PropertyProxy<pango::Overline>;

    auto
    property_overline () const -> glib::PropertyProxy_ReadOnly<pango::Overline>;

    auto
    property_overline_rgba () -> glib::PropertyProxy<gdk::RGBA>;

    auto
    property_overline_rgba () const -> glib::PropertyProxy_ReadOnly<gdk::RGBA>;

    auto
    property_rise () -> glib::PropertyProxy<int>;

    auto
    property_rise () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_background_full_height () -> glib::PropertyProxy<bool>;

    auto
    property_background_full_height () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_language () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_language () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_tabs () -> glib::PropertyProxy<pango::TabArray>;

    auto
    property_tabs () const -> glib::PropertyProxy_ReadOnly<pango::TabArray>;

    auto
    property_invisible () -> glib::PropertyProxy<bool>;

    auto
    property_invisible () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_paragraph_background ()
        -> glib::PropertyProxy_WriteOnly<glib::ustring>;

    auto
    property_paragraph_background_rgba () -> glib::PropertyProxy<gdk::RGBA>;

    auto
    property_paragraph_background_rgba () const
        -> glib::PropertyProxy_ReadOnly<gdk::RGBA>;

    auto
    property_font_features () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_font_features () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_allow_breaks () -> glib::PropertyProxy<bool>;

    auto
    property_allow_breaks () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_spaces () -> glib::PropertyProxy<pango::ShowFlags>;

    auto
    property_show_spaces () const
        -> glib::PropertyProxy_ReadOnly<pango::ShowFlags>;

    auto
    property_insert_hyphens () -> glib::PropertyProxy<bool>;

    auto
    property_insert_hyphens () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_text_transform () -> glib::PropertyProxy<pango::TextTransform>;

    auto
    property_text_transform () const
        -> glib::PropertyProxy_ReadOnly<pango::TextTransform>;

    auto
    property_word () -> glib::PropertyProxy<bool>;

    auto
    property_word () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_sentence () -> glib::PropertyProxy<bool>;

    auto
    property_sentence () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_accumulative_margin () -> glib::PropertyProxy<bool>;

    auto
    property_accumulative_margin () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_background_set () -> glib::PropertyProxy<bool>;

    auto
    property_background_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_foreground_set () -> glib::PropertyProxy<bool>;

    auto
    property_foreground_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_family_set () -> glib::PropertyProxy<bool>;

    auto
    property_family_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_style_set () -> glib::PropertyProxy<bool>;

    auto
    property_style_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_variant_set () -> glib::PropertyProxy<bool>;

    auto
    property_variant_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_weight_set () -> glib::PropertyProxy<bool>;

    auto
    property_weight_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_stretch_set () -> glib::PropertyProxy<bool>;

    auto
    property_stretch_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_size_set () -> glib::PropertyProxy<bool>;

    auto
    property_size_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_scale_set () -> glib::PropertyProxy<bool>;

    auto
    property_scale_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_pixels_above_lines_set () -> glib::PropertyProxy<bool>;

    auto
    property_pixels_above_lines_set () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_pixels_below_lines_set () -> glib::PropertyProxy<bool>;

    auto
    property_pixels_below_lines_set () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_pixels_inside_wrap_set () -> glib::PropertyProxy<bool>;

    auto
    property_pixels_inside_wrap_set () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_editable_set () -> glib::PropertyProxy<bool>;

    auto
    property_editable_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_wrap_mode_set () -> glib::PropertyProxy<bool>;

    auto
    property_wrap_mode_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_justification_set () -> glib::PropertyProxy<bool>;

    auto
    property_justification_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_left_margin_set () -> glib::PropertyProxy<bool>;

    auto
    property_left_margin_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_indent_set () -> glib::PropertyProxy<bool>;

    auto
    property_indent_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_line_height_set () -> glib::PropertyProxy<bool>;

    auto
    property_line_height_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_strikethrough_set () -> glib::PropertyProxy<bool>;

    auto
    property_strikethrough_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_strikethrough_rgba_set () -> glib::PropertyProxy<bool>;

    auto
    property_strikethrough_rgba_set () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_right_margin_set () -> glib::PropertyProxy<bool>;

    auto
    property_right_margin_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_underline_set () -> glib::PropertyProxy<bool>;

    auto
    property_underline_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_underline_rgba_set () -> glib::PropertyProxy<bool>;

    auto
    property_underline_rgba_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_overline_set () -> glib::PropertyProxy<bool>;

    auto
    property_overline_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_overline_rgba_set () -> glib::PropertyProxy<bool>;

    auto
    property_overline_rgba_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_rise_set () -> glib::PropertyProxy<bool>;

    auto
    property_rise_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_background_full_height_set () -> glib::PropertyProxy<bool>;

    auto
    property_background_full_height_set () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_language_set () -> glib::PropertyProxy<bool>;

    auto
    property_language_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_tabs_set () -> glib::PropertyProxy<bool>;

    auto
    property_tabs_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_invisible_set () -> glib::PropertyProxy<bool>;

    auto
    property_invisible_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_paragraph_background_set () -> glib::PropertyProxy<bool>;

    auto
    property_paragraph_background_set () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_fallback () -> glib::PropertyProxy<bool>;

    auto
    property_fallback () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_fallback_set () -> glib::PropertyProxy<bool>;

    auto
    property_fallback_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_letter_spacing () -> glib::PropertyProxy<int>;

    auto
    property_letter_spacing () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_letter_spacing_set () -> glib::PropertyProxy<bool>;

    auto
    property_letter_spacing_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_font_features_set () -> glib::PropertyProxy<bool>;

    auto
    property_font_features_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_allow_breaks_set () -> glib::PropertyProxy<bool>;

    auto
    property_allow_breaks_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_spaces_set () -> glib::PropertyProxy<bool>;

    auto
    property_show_spaces_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_insert_hyphens_set () -> glib::PropertyProxy<bool>;

    auto
    property_insert_hyphens_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_text_transform_set () -> glib::PropertyProxy<bool>;

    auto
    property_text_transform_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_word_set () -> glib::PropertyProxy<bool>;

    auto
    property_word_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_sentence_set () -> glib::PropertyProxy<bool>;

    auto
    property_sentence_set () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkTextTag* object, bool take_copy = false) -> glib::RefPtr<gtk::TextTag>;
} // namespace glib

#endif
