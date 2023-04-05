// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FONTBUTTON_H
#define _GTKMM_FONTBUTTON_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gtk/fontchooser.hxx>
  #include <libmm/gtk/widget.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkFontButton = struct _GtkFontButton;
using GtkFontButtonClass = struct _GtkFontButtonClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT FontButton_Class;
}
  #endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT FontButton : public Widget,
                               public FontChooser
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef FontButton CppObjectType;
    typedef FontButton_Class CppClassType;
    typedef GtkFontButton BaseObjectType;
    typedef GtkFontButtonClass BaseClassType;
  #endif

    FontButton (FontButton&& src) noexcept;
    auto
    operator= (FontButton&& src) noexcept -> FontButton&;

    FontButton (const FontButton&) = delete;
    auto
    operator= (const FontButton&) -> FontButton& = delete;

    ~FontButton () noexcept override;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class FontButton_Class;
    static CppClassType fontbutton_class_;

  protected:
    explicit FontButton (const glib::ConstructParams& construct_params);
    explicit FontButton (GtkFontButton* castitem);

  #endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkFontButton*
    {
      return reinterpret_cast<GtkFontButton*> (gobject_);
    }

    auto
    gobj () const -> const GtkFontButton*
    {
      return reinterpret_cast<GtkFontButton*> (gobject_);
    }

  private:
  public:
    FontButton ();
    explicit FontButton (const glib::ustring& font);

    auto
    get_title () const -> glib::ustring;

    auto
    set_title (const glib::ustring& title) -> void;

    auto
    get_modal () const -> bool;

    auto
    set_modal (bool modal = true) -> void;

    auto
    get_use_font () const -> bool;

    auto
    set_use_font (bool use_font = true) -> void;

    auto
    get_use_size () const -> bool;

    auto
    set_use_size (bool use_size = true) -> void;

    auto
    property_title () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_modal () -> glib::PropertyProxy<bool>;

    auto
    property_modal () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_use_font () -> glib::PropertyProxy<bool>;

    auto
    property_use_font () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_use_size () -> glib::PropertyProxy<bool>;

    auto
    property_use_size () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    signal_font_set () -> glib::SignalProxy<void ()>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkFontButton* object, bool take_copy = false) -> gtk::FontButton*;
} // namespace glib

#endif

#endif
