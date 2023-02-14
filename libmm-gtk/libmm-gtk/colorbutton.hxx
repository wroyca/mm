// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_COLORBUTTON_H
#define _GTKMM_COLORBUTTON_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/rgba.hxx>
#include <libmm-gtk/colorchooser.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkColorButton = struct _GtkColorButton;
using GtkColorButtonClass = struct _GtkColorButtonClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API ColorButton_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API ColorButton : public Widget,
                                public ColorChooser
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ColorButton CppObjectType;
    typedef ColorButton_Class CppClassType;
    typedef GtkColorButton BaseObjectType;
    typedef GtkColorButtonClass BaseClassType;
#endif

    ColorButton (ColorButton&& src) noexcept;
    auto
    operator= (ColorButton&& src) noexcept -> ColorButton&;

    ColorButton (const ColorButton&) = delete;
    auto
    operator= (const ColorButton&) -> ColorButton& = delete;

    ~ColorButton () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class ColorButton_Class;
    static CppClassType colorbutton_class_;

  protected:
    explicit ColorButton (const Glib::ConstructParams& construct_params);
    explicit ColorButton (GtkColorButton* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkColorButton*
    {
      return reinterpret_cast<GtkColorButton*> (gobject_);
    }

    auto
    gobj () const -> const GtkColorButton*
    {
      return reinterpret_cast<GtkColorButton*> (gobject_);
    }

  private:
  public:
    ColorButton ();

    explicit ColorButton (const Gdk::RGBA& rgba);

    void
    set_title (const Glib::ustring& title);

    auto
    get_title () const -> Glib::ustring;

    void
    set_modal (bool modal = true);

    auto
    get_modal () const -> bool;

    auto
    property_title () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_show_editor () -> Glib::PropertyProxy<bool>;

    auto
    property_show_editor () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_modal () -> Glib::PropertyProxy<bool>;

    auto
    property_modal () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    signal_color_set () -> Glib::SignalProxy<void ()>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkColorButton* object, bool take_copy = false) -> Gtk::ColorButton*;
} // namespace Glib

#endif
