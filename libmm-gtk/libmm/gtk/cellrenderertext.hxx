// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CELLRENDERERTEXT_H
#define _GTKMM_CELLRENDERERTEXT_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gtk/cellrenderer.hxx>
  #include <libmm/pango/attrlist.hxx>
  #include <libmm/pango/fontdescription.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellRendererText = struct _GtkCellRendererText;
using GtkCellRendererTextClass = struct _GtkCellRendererTextClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT CellRendererText_Class;
}
  #endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT CellRendererText : public CellRenderer
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef CellRendererText CppObjectType;
    typedef CellRendererText_Class CppClassType;
    typedef GtkCellRendererText BaseObjectType;
    typedef GtkCellRendererTextClass BaseClassType;
  #endif

    CellRendererText (CellRendererText&& src) noexcept;
    auto
    operator= (CellRendererText&& src) noexcept -> CellRendererText&;

    CellRendererText (const CellRendererText&) = delete;
    auto
    operator= (const CellRendererText&) -> CellRendererText& = delete;

    ~CellRendererText () noexcept override;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class CellRendererText_Class;
    static CppClassType cellrenderertext_class_;

  protected:
    explicit CellRendererText (const glib::ConstructParams& construct_params);
    explicit CellRendererText (GtkCellRendererText* castitem);

  #endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkCellRendererText*
    {
      return reinterpret_cast<GtkCellRendererText*> (gobject_);
    }

    auto
    gobj () const -> const GtkCellRendererText*
    {
      return reinterpret_cast<GtkCellRendererText*> (gobject_);
    }

  private:
  public:
    CellRendererText ();

    auto
    set_fixed_height_from_font (int number_of_rows) -> void;

    auto
    signal_edited ()
        -> glib::SignalProxy<void (const glib::ustring&, const glib::ustring&)>;

    auto
    property_text () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_text () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_markup () -> glib::PropertyProxy_WriteOnly<glib::ustring>;

    auto
    property_attributes () -> glib::PropertyProxy<pango::AttrList>;

    auto
    property_attributes () const
        -> glib::PropertyProxy_ReadOnly<pango::AttrList>;

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
    property_editable () -> glib::PropertyProxy<bool>;

    auto
    property_editable () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_strikethrough () -> glib::PropertyProxy<bool>;

    auto
    property_strikethrough () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_underline () -> glib::PropertyProxy<pango::Underline>;

    auto
    property_underline () const
        -> glib::PropertyProxy_ReadOnly<pango::Underline>;

    auto
    property_rise () -> glib::PropertyProxy<int>;

    auto
    property_rise () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_language () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_language () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_ellipsize () -> glib::PropertyProxy<pango::EllipsizeMode>;

    auto
    property_ellipsize () const
        -> glib::PropertyProxy_ReadOnly<pango::EllipsizeMode>;

    auto
    property_width_chars () -> glib::PropertyProxy<int>;

    auto
    property_width_chars () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_max_width_chars () -> glib::PropertyProxy<int>;

    auto
    property_max_width_chars () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_wrap_mode () -> glib::PropertyProxy<pango::WrapMode>;

    auto
    property_wrap_mode () const
        -> glib::PropertyProxy_ReadOnly<pango::WrapMode>;

    auto
    property_wrap_width () -> glib::PropertyProxy<int>;

    auto
    property_wrap_width () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_alignment () -> glib::PropertyProxy<pango::Alignment>;

    auto
    property_alignment () const
        -> glib::PropertyProxy_ReadOnly<pango::Alignment>;

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
    property_editable_set () -> glib::PropertyProxy<bool>;

    auto
    property_editable_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_strikethrough_set () -> glib::PropertyProxy<bool>;

    auto
    property_strikethrough_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_underline_set () -> glib::PropertyProxy<bool>;

    auto
    property_underline_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_rise_set () -> glib::PropertyProxy<bool>;

    auto
    property_rise_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_language_set () -> glib::PropertyProxy<bool>;

    auto
    property_language_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_ellipsize_set () -> glib::PropertyProxy<bool>;

    auto
    property_ellipsize_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_single_paragraph_mode () -> glib::PropertyProxy<bool>;

    auto
    property_single_paragraph_mode () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_align_set () -> glib::PropertyProxy<bool>;

    auto
    property_align_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_placeholder_text () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_placeholder_text () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    _property_renderable () -> glib::PropertyProxy_Base override;

  protected:
    auto
    edited (const glib::ustring& path, const glib::ustring& new_text) -> void;

  public:
  public:
  protected:
    virtual auto
    on_edited (const glib::ustring& path, const glib::ustring& new_text)
        -> void;
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkCellRendererText* object, bool take_copy = false) -> gtk::CellRendererText*;
} // namespace glib

#endif

#endif
