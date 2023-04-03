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
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT CellRendererText_Class;
}
  #endif

namespace Gtk
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
    explicit CellRendererText (const Glib::ConstructParams& construct_params);
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
        -> Glib::SignalProxy<void (const Glib::ustring&, const Glib::ustring&)>;

    auto
    property_text () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_text () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_markup () -> Glib::PropertyProxy_WriteOnly<Glib::ustring>;

    auto
    property_attributes () -> Glib::PropertyProxy<Pango::AttrList>;

    auto
    property_attributes () const
        -> Glib::PropertyProxy_ReadOnly<Pango::AttrList>;

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
    property_editable () -> Glib::PropertyProxy<bool>;

    auto
    property_editable () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_strikethrough () -> Glib::PropertyProxy<bool>;

    auto
    property_strikethrough () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_underline () -> Glib::PropertyProxy<Pango::Underline>;

    auto
    property_underline () const
        -> Glib::PropertyProxy_ReadOnly<Pango::Underline>;

    auto
    property_rise () -> Glib::PropertyProxy<int>;

    auto
    property_rise () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_language () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_language () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_ellipsize () -> Glib::PropertyProxy<Pango::EllipsizeMode>;

    auto
    property_ellipsize () const
        -> Glib::PropertyProxy_ReadOnly<Pango::EllipsizeMode>;

    auto
    property_width_chars () -> Glib::PropertyProxy<int>;

    auto
    property_width_chars () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_max_width_chars () -> Glib::PropertyProxy<int>;

    auto
    property_max_width_chars () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_wrap_mode () -> Glib::PropertyProxy<Pango::WrapMode>;

    auto
    property_wrap_mode () const
        -> Glib::PropertyProxy_ReadOnly<Pango::WrapMode>;

    auto
    property_wrap_width () -> Glib::PropertyProxy<int>;

    auto
    property_wrap_width () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_alignment () -> Glib::PropertyProxy<Pango::Alignment>;

    auto
    property_alignment () const
        -> Glib::PropertyProxy_ReadOnly<Pango::Alignment>;

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
    property_editable_set () -> Glib::PropertyProxy<bool>;

    auto
    property_editable_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_strikethrough_set () -> Glib::PropertyProxy<bool>;

    auto
    property_strikethrough_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_underline_set () -> Glib::PropertyProxy<bool>;

    auto
    property_underline_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_rise_set () -> Glib::PropertyProxy<bool>;

    auto
    property_rise_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_language_set () -> Glib::PropertyProxy<bool>;

    auto
    property_language_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_ellipsize_set () -> Glib::PropertyProxy<bool>;

    auto
    property_ellipsize_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_single_paragraph_mode () -> Glib::PropertyProxy<bool>;

    auto
    property_single_paragraph_mode () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_align_set () -> Glib::PropertyProxy<bool>;

    auto
    property_align_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_placeholder_text () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_placeholder_text () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    _property_renderable () -> Glib::PropertyProxy_Base override;

  protected:
    auto
    edited (const Glib::ustring& path, const Glib::ustring& new_text) -> void;

  public:
  public:
  protected:
    virtual auto
    on_edited (const Glib::ustring& path, const Glib::ustring& new_text)
        -> void;
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkCellRendererText* object, bool take_copy = false) -> Gtk::CellRendererText*;
} // namespace Glib

#endif

#endif
