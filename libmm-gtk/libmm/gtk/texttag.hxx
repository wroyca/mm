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
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT TextTag_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT TextTag : public Glib::Object
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
    explicit TextTag (const Glib::ConstructParams& construct_params);
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
    explicit TextTag (const Glib::ustring& name);

  public:
    static auto
    create () -> Glib::RefPtr<TextTag>;

    static auto
    create (const Glib::ustring& name) -> Glib::RefPtr<TextTag>;

    auto
    get_priority () const -> int;

    auto
    set_priority (int priority) -> void;

    auto
    tag_changed (bool size_changed) -> void;

    auto
    property_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_background () -> Glib::PropertyProxy_WriteOnly<Glib::ustring>;

    auto
    property_foreground () -> Glib::PropertyProxy_WriteOnly<Glib::ustring>;

    auto
    property_background_rgba () -> Glib::PropertyProxy<Gdk::RGBA>;

    auto
    property_background_rgba () const
        -> Glib::PropertyProxy_ReadOnly<Gdk::RGBA>;

    auto
    property_foreground_rgba () -> Glib::PropertyProxy<Gdk::RGBA>;

    auto
    property_foreground_rgba () const
        -> Glib::PropertyProxy_ReadOnly<Gdk::RGBA>;

    auto
    property_font () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_font () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_font_desc () -> Glib::PropertyProxy<Pango::FontDescription>;

    auto
    property_font_desc () const
        -> Glib::PropertyProxy_ReadOnly<Pango::FontDescription>;

    auto
    property_family () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_family () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_style () -> Glib::PropertyProxy<Pango::Style>;

    auto
    property_style () const -> Glib::PropertyProxy_ReadOnly<Pango::Style>;

    auto
    property_variant () -> Glib::PropertyProxy<Pango::Variant>;

    auto
    property_variant () const -> Glib::PropertyProxy_ReadOnly<Pango::Variant>;

    auto
    property_weight () -> Glib::PropertyProxy<int>;

    auto
    property_weight () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_stretch () -> Glib::PropertyProxy<Pango::Stretch>;

    auto
    property_stretch () const -> Glib::PropertyProxy_ReadOnly<Pango::Stretch>;

    auto
    property_size () -> Glib::PropertyProxy<int>;

    auto
    property_size () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_size_points () -> Glib::PropertyProxy<double>;

    auto
    property_size_points () const -> Glib::PropertyProxy_ReadOnly<double>;

    auto
    property_scale () -> Glib::PropertyProxy<double>;

    auto
    property_scale () const -> Glib::PropertyProxy_ReadOnly<double>;

    auto
    property_pixels_above_lines () -> Glib::PropertyProxy<int>;

    auto
    property_pixels_above_lines () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_pixels_below_lines () -> Glib::PropertyProxy<int>;

    auto
    property_pixels_below_lines () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_pixels_inside_wrap () -> Glib::PropertyProxy<int>;

    auto
    property_pixels_inside_wrap () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_editable () -> Glib::PropertyProxy<bool>;

    auto
    property_editable () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_wrap_mode () -> Glib::PropertyProxy<WrapMode>;

    auto
    property_wrap_mode () const -> Glib::PropertyProxy_ReadOnly<WrapMode>;

    auto
    property_justification () -> Glib::PropertyProxy<Justification>;

    auto
    property_justification () const
        -> Glib::PropertyProxy_ReadOnly<Justification>;

    auto
    property_direction () -> Glib::PropertyProxy<TextDirection>;

    auto
    property_direction () const -> Glib::PropertyProxy_ReadOnly<TextDirection>;

    auto
    property_left_margin () -> Glib::PropertyProxy<int>;

    auto
    property_left_margin () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_indent () -> Glib::PropertyProxy<int>;

    auto
    property_indent () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_line_height () -> Glib::PropertyProxy<float>;

    auto
    property_line_height () const -> Glib::PropertyProxy_ReadOnly<float>;

    auto
    property_strikethrough () -> Glib::PropertyProxy<bool>;

    auto
    property_strikethrough () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_strikethrough_rgba () -> Glib::PropertyProxy<Gdk::RGBA>;

    auto
    property_strikethrough_rgba () const
        -> Glib::PropertyProxy_ReadOnly<Gdk::RGBA>;

    auto
    property_right_margin () -> Glib::PropertyProxy<int>;

    auto
    property_right_margin () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_underline () -> Glib::PropertyProxy<Pango::Underline>;

    auto
    property_underline () const
        -> Glib::PropertyProxy_ReadOnly<Pango::Underline>;

    auto
    property_underline_rgba () -> Glib::PropertyProxy<Gdk::RGBA>;

    auto
    property_underline_rgba () const -> Glib::PropertyProxy_ReadOnly<Gdk::RGBA>;

    auto
    property_overline () -> Glib::PropertyProxy<Pango::Overline>;

    auto
    property_overline () const -> Glib::PropertyProxy_ReadOnly<Pango::Overline>;

    auto
    property_overline_rgba () -> Glib::PropertyProxy<Gdk::RGBA>;

    auto
    property_overline_rgba () const -> Glib::PropertyProxy_ReadOnly<Gdk::RGBA>;

    auto
    property_rise () -> Glib::PropertyProxy<int>;

    auto
    property_rise () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_background_full_height () -> Glib::PropertyProxy<bool>;

    auto
    property_background_full_height () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_language () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_language () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_tabs () -> Glib::PropertyProxy<Pango::TabArray>;

    auto
    property_tabs () const -> Glib::PropertyProxy_ReadOnly<Pango::TabArray>;

    auto
    property_invisible () -> Glib::PropertyProxy<bool>;

    auto
    property_invisible () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_paragraph_background ()
        -> Glib::PropertyProxy_WriteOnly<Glib::ustring>;

    auto
    property_paragraph_background_rgba () -> Glib::PropertyProxy<Gdk::RGBA>;

    auto
    property_paragraph_background_rgba () const
        -> Glib::PropertyProxy_ReadOnly<Gdk::RGBA>;

    auto
    property_font_features () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_font_features () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_allow_breaks () -> Glib::PropertyProxy<bool>;

    auto
    property_allow_breaks () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_spaces () -> Glib::PropertyProxy<Pango::ShowFlags>;

    auto
    property_show_spaces () const
        -> Glib::PropertyProxy_ReadOnly<Pango::ShowFlags>;

    auto
    property_insert_hyphens () -> Glib::PropertyProxy<bool>;

    auto
    property_insert_hyphens () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_text_transform () -> Glib::PropertyProxy<Pango::TextTransform>;

    auto
    property_text_transform () const
        -> Glib::PropertyProxy_ReadOnly<Pango::TextTransform>;

    auto
    property_word () -> Glib::PropertyProxy<bool>;

    auto
    property_word () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_sentence () -> Glib::PropertyProxy<bool>;

    auto
    property_sentence () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_accumulative_margin () -> Glib::PropertyProxy<bool>;

    auto
    property_accumulative_margin () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_background_set () -> Glib::PropertyProxy<bool>;

    auto
    property_background_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_foreground_set () -> Glib::PropertyProxy<bool>;

    auto
    property_foreground_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_family_set () -> Glib::PropertyProxy<bool>;

    auto
    property_family_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_style_set () -> Glib::PropertyProxy<bool>;

    auto
    property_style_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_variant_set () -> Glib::PropertyProxy<bool>;

    auto
    property_variant_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_weight_set () -> Glib::PropertyProxy<bool>;

    auto
    property_weight_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_stretch_set () -> Glib::PropertyProxy<bool>;

    auto
    property_stretch_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_size_set () -> Glib::PropertyProxy<bool>;

    auto
    property_size_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_scale_set () -> Glib::PropertyProxy<bool>;

    auto
    property_scale_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_pixels_above_lines_set () -> Glib::PropertyProxy<bool>;

    auto
    property_pixels_above_lines_set () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_pixels_below_lines_set () -> Glib::PropertyProxy<bool>;

    auto
    property_pixels_below_lines_set () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_pixels_inside_wrap_set () -> Glib::PropertyProxy<bool>;

    auto
    property_pixels_inside_wrap_set () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_editable_set () -> Glib::PropertyProxy<bool>;

    auto
    property_editable_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_wrap_mode_set () -> Glib::PropertyProxy<bool>;

    auto
    property_wrap_mode_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_justification_set () -> Glib::PropertyProxy<bool>;

    auto
    property_justification_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_left_margin_set () -> Glib::PropertyProxy<bool>;

    auto
    property_left_margin_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_indent_set () -> Glib::PropertyProxy<bool>;

    auto
    property_indent_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_line_height_set () -> Glib::PropertyProxy<bool>;

    auto
    property_line_height_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_strikethrough_set () -> Glib::PropertyProxy<bool>;

    auto
    property_strikethrough_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_strikethrough_rgba_set () -> Glib::PropertyProxy<bool>;

    auto
    property_strikethrough_rgba_set () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_right_margin_set () -> Glib::PropertyProxy<bool>;

    auto
    property_right_margin_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_underline_set () -> Glib::PropertyProxy<bool>;

    auto
    property_underline_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_underline_rgba_set () -> Glib::PropertyProxy<bool>;

    auto
    property_underline_rgba_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_overline_set () -> Glib::PropertyProxy<bool>;

    auto
    property_overline_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_overline_rgba_set () -> Glib::PropertyProxy<bool>;

    auto
    property_overline_rgba_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_rise_set () -> Glib::PropertyProxy<bool>;

    auto
    property_rise_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_background_full_height_set () -> Glib::PropertyProxy<bool>;

    auto
    property_background_full_height_set () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_language_set () -> Glib::PropertyProxy<bool>;

    auto
    property_language_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_tabs_set () -> Glib::PropertyProxy<bool>;

    auto
    property_tabs_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_invisible_set () -> Glib::PropertyProxy<bool>;

    auto
    property_invisible_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_paragraph_background_set () -> Glib::PropertyProxy<bool>;

    auto
    property_paragraph_background_set () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_fallback () -> Glib::PropertyProxy<bool>;

    auto
    property_fallback () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_fallback_set () -> Glib::PropertyProxy<bool>;

    auto
    property_fallback_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_letter_spacing () -> Glib::PropertyProxy<int>;

    auto
    property_letter_spacing () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_letter_spacing_set () -> Glib::PropertyProxy<bool>;

    auto
    property_letter_spacing_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_font_features_set () -> Glib::PropertyProxy<bool>;

    auto
    property_font_features_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_allow_breaks_set () -> Glib::PropertyProxy<bool>;

    auto
    property_allow_breaks_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_spaces_set () -> Glib::PropertyProxy<bool>;

    auto
    property_show_spaces_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_insert_hyphens_set () -> Glib::PropertyProxy<bool>;

    auto
    property_insert_hyphens_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_text_transform_set () -> Glib::PropertyProxy<bool>;

    auto
    property_text_transform_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_word_set () -> Glib::PropertyProxy<bool>;

    auto
    property_word_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_sentence_set () -> Glib::PropertyProxy<bool>;

    auto
    property_sentence_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkTextTag* object, bool take_copy = false) -> Glib::RefPtr<Gtk::TextTag>;
} // namespace Glib

#endif
