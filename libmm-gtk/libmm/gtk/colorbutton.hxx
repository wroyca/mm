// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_COLORBUTTON_H
#define _GTKMM_COLORBUTTON_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gdk/rgba.hxx>
  #include <libmm/gtk/colorchooser.hxx>
  #include <libmm/gtk/widget.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkColorButton = struct _GtkColorButton;
using GtkColorButtonClass = struct _GtkColorButtonClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT ColorButton_Class;
}
  #endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT ColorButton : public Widget,
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
    friend LIBMM_GTK_SYMEXPORT class ColorButton_Class;
    static CppClassType colorbutton_class_;

  protected:
    explicit ColorButton (const glib::ConstructParams& construct_params);
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

    explicit ColorButton (const gdk::RGBA& rgba);

    auto
    set_title (const glib::ustring& title) -> void;

    auto
    get_title () const -> glib::ustring;

    auto
    set_modal (bool modal = true) -> void;

    auto
    get_modal () const -> bool;

    auto
    property_title () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_show_editor () -> glib::PropertyProxy<bool>;

    auto
    property_show_editor () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_modal () -> glib::PropertyProxy<bool>;

    auto
    property_modal () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    signal_color_set () -> glib::SignalProxy<void ()>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkColorButton* object, bool take_copy = false) -> gtk::ColorButton*;
} // namespace glib

#endif

#endif
