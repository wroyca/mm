// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_POPOVER_H
#define _GTKMM_POPOVER_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/native.hxx>
#include <libmm-gtk/shortcutmanager.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPopover = struct _GtkPopover;
using GtkPopoverClass = struct _GtkPopoverClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT Popover_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT Popover : public Widget,
                            public ShortcutManager,
                            public Native
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Popover CppObjectType;
    typedef Popover_Class CppClassType;
    typedef GtkPopover BaseObjectType;
    typedef GtkPopoverClass BaseClassType;
#endif

    Popover (Popover&& src) noexcept;
    auto
    operator= (Popover&& src) noexcept -> Popover&;

    Popover (const Popover&) = delete;
    auto
    operator= (const Popover&) -> Popover& = delete;

    ~Popover () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class Popover_Class;
    static CppClassType popover_class_;

  protected:
    explicit Popover (const Glib::ConstructParams& construct_params);
    explicit Popover (GtkPopover* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkPopover*
    {
      return reinterpret_cast<GtkPopover*> (gobject_);
    }

    auto
    gobj () const -> const GtkPopover*
    {
      return reinterpret_cast<GtkPopover*> (gobject_);
    }

  private:
  public:
    Popover ();

    auto
    set_child (Widget& child) -> void;
    auto
    unset_child () -> void;

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    auto
    set_pointing_to (const Gdk::Rectangle& rect) -> void;

    auto
    get_pointing_to (Gdk::Rectangle& rect) const -> bool;

    auto
    set_position (PositionType position = PositionType::TOP) -> void;

    auto
    get_position () const -> PositionType;

    auto
    set_autohide (bool autohide = true) -> void;

    auto
    get_autohide () const -> bool;

    auto
    set_has_arrow (bool has_arrow = true) -> void;

    auto
    get_has_arrow () const -> bool;

    auto
    set_mnemonics_visible (bool mnemonics_visible = true) -> void;

    auto
    get_mnemonics_visible () const -> bool;

    auto
    popup () -> void;

    auto
    popdown () -> void;

    auto
    set_offset (int x_offset, int y_offset) -> void;

    auto
    get_offset (int& x_offset, int& y_offset) const -> void;

    auto
    set_cascade_popdown (bool cascade_popdown = true) -> void;

    auto
    get_cascade_popdown () const -> bool;

    auto
    set_default_widget (Widget& widget) -> void;

    auto
    present () -> void;

    auto
    property_pointing_to () -> Glib::PropertyProxy<Gdk::Rectangle>;

    auto
    property_pointing_to () const
        -> Glib::PropertyProxy_ReadOnly<Gdk::Rectangle>;

    auto
    property_position () -> Glib::PropertyProxy<PositionType>;

    auto
    property_position () const -> Glib::PropertyProxy_ReadOnly<PositionType>;

    auto
    property_autohide () -> Glib::PropertyProxy<bool>;

    auto
    property_autohide () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_has_arrow () -> Glib::PropertyProxy<bool>;

    auto
    property_has_arrow () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_default_widget () -> Glib::PropertyProxy<Widget*>;

    auto
    property_default_widget () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_mnemonics_visible () -> Glib::PropertyProxy<bool>;

    auto
    property_mnemonics_visible () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_child () -> Glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_cascade_popdown () -> Glib::PropertyProxy<bool>;

    auto
    property_cascade_popdown () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    signal_closed () -> Glib::SignalProxy<void ()>;

  public:
  public:
  protected:
    virtual auto
    on_closed () -> void;
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkPopover* object, bool take_copy = false) -> Gtk::Popover*;
} // namespace Glib

#endif
