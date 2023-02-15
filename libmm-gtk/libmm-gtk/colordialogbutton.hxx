// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_COLORDIALOGBUTTON_H
#define _GTKMM_COLORDIALOGBUTTON_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/rgba.hxx>
#include <libmm-gtk/colordialog.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT ColorDialogButton_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT ColorDialogButton : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ColorDialogButton CppObjectType;
    typedef ColorDialogButton_Class CppClassType;
    typedef GtkColorDialogButton BaseObjectType;
    typedef GtkColorDialogButtonClass BaseClassType;
#endif

    ColorDialogButton (ColorDialogButton&& src) noexcept;
    auto
    operator= (ColorDialogButton&& src) noexcept -> ColorDialogButton&;

    ColorDialogButton (const ColorDialogButton&) = delete;
    auto
    operator= (const ColorDialogButton&) -> ColorDialogButton& = delete;

    ~ColorDialogButton () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class ColorDialogButton_Class;
    static CppClassType colordialogbutton_class_;

  protected:
    explicit ColorDialogButton (const Glib::ConstructParams& construct_params);
    explicit ColorDialogButton (GtkColorDialogButton* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkColorDialogButton*
    {
      return reinterpret_cast<GtkColorDialogButton*> (gobject_);
    }

    auto
    gobj () const -> const GtkColorDialogButton*
    {
      return reinterpret_cast<GtkColorDialogButton*> (gobject_);
    }

  private:
  public:
    explicit ColorDialogButton (const Glib::RefPtr<ColorDialog>& dialog = {});

    auto
    get_dialog () -> Glib::RefPtr<ColorDialog>;

    auto
    get_dialog () const -> Glib::RefPtr<const ColorDialog>;

    auto
    set_dialog (const Glib::RefPtr<ColorDialog>& dialog) -> void;

    auto
    get_rgba () const -> Gdk::RGBA;

    auto
    set_rgba (const Gdk::RGBA& color) -> void;

    auto
    property_dialog () -> Glib::PropertyProxy<Glib::RefPtr<ColorDialog>>;

    auto
    property_dialog () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ColorDialog>>;

    auto
    property_rgba () -> Glib::PropertyProxy<Gdk::RGBA>;

    auto
    property_rgba () const -> Glib::PropertyProxy_ReadOnly<Gdk::RGBA>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkColorDialogButton* object, bool take_copy = false) -> Gtk::ColorDialogButton*;
} // namespace Glib

#endif
