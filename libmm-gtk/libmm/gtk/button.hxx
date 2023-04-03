// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_BUTTON_H
#define _GTKMM_BUTTON_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/actionable.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkButton = struct _GtkButton;
using GtkButtonClass = struct _GtkButtonClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT Button_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT Button : public Widget,
                           public Actionable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Button CppObjectType;
    typedef Button_Class CppClassType;
    typedef GtkButton BaseObjectType;
    typedef GtkButtonClass BaseClassType;
#endif

    Button (Button&& src) noexcept;
    auto
    operator= (Button&& src) noexcept -> Button&;

    Button (const Button&) = delete;
    auto
    operator= (const Button&) -> Button& = delete;

    ~Button () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class Button_Class;
    static CppClassType button_class_;

  protected:
    explicit Button (const Glib::ConstructParams& construct_params);
    explicit Button (GtkButton* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkButton*
    {
      return reinterpret_cast<GtkButton*> (gobject_);
    }

    auto
    gobj () const -> const GtkButton*
    {
      return reinterpret_cast<GtkButton*> (gobject_);
    }

  private:
  public:
    Button ();

    explicit Button (const Glib::ustring& label, bool mnemonic = false);

    auto
    set_has_frame (bool has_frame = true) -> void;

    auto
    get_has_frame () const -> bool;

    auto
    set_label (const Glib::ustring& label) -> void;

    auto
    get_label () const -> Glib::ustring;

    auto
    set_use_underline (bool use_underline = true) -> void;

    auto
    get_use_underline () const -> bool;

    auto
    set_icon_name (const Glib::ustring& icon_name) -> void;

    auto
    get_icon_name () const -> Glib::ustring;

    auto
    set_image_from_icon_name (const Glib::ustring& icon_name,
                              IconSize size = IconSize::INHERIT,
                              bool use_fallback = false) -> void;

    auto
    set_child (Widget& child) -> void;
    auto
    unset_child () -> void;

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    auto
    signal_clicked () -> Glib::SignalProxy<void ()>;

    auto
    property_label () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_label () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_has_frame () -> Glib::PropertyProxy<bool>;

    auto
    property_has_frame () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_use_underline () -> Glib::PropertyProxy<bool>;

    auto
    property_use_underline () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_icon_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_child () -> Glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

  public:
  public:
  protected:
    virtual auto
    on_clicked () -> void;
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkButton* object, bool take_copy = false) -> Gtk::Button*;
} // namespace Glib

#endif
