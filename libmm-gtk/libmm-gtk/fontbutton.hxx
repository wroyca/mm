// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FONTBUTTON_H
#define _GTKMM_FONTBUTTON_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/fontchooser.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkFontButton = struct _GtkFontButton;
using GtkFontButtonClass = struct _GtkFontButtonClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API FontButton_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API FontButton : public Widget,
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
    friend GTKMM_API class FontButton_Class;
    static CppClassType fontbutton_class_;

  protected:
    explicit FontButton (const Glib::ConstructParams& construct_params);
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
    explicit FontButton (const Glib::ustring& font);

    auto
    get_title () const -> Glib::ustring;

    void
    set_title (const Glib::ustring& title);

    auto
    get_modal () const -> bool;

    void
    set_modal (bool modal = true);

    auto
    get_use_font () const -> bool;

    void
    set_use_font (bool use_font = true);

    auto
    get_use_size () const -> bool;

    void
    set_use_size (bool use_size = true);

    auto
    property_title () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_modal () -> Glib::PropertyProxy<bool>;

    auto
    property_modal () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_use_font () -> Glib::PropertyProxy<bool>;

    auto
    property_use_font () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_use_size () -> Glib::PropertyProxy<bool>;

    auto
    property_use_size () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    signal_font_set () -> Glib::SignalProxy<void ()>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkFontButton* object, bool take_copy = false) -> Gtk::FontButton*;
} // namespace Glib

#endif
