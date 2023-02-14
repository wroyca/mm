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
  class GTKMM_API Popover_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Popover : public Widget,
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
    friend GTKMM_API class Popover_Class;
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

    void
    set_child (Widget& child);
    void
    unset_child ();

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    void
    set_pointing_to (const Gdk::Rectangle& rect);

    auto
    get_pointing_to (Gdk::Rectangle& rect) const -> bool;

    void
    set_position (PositionType position = PositionType::TOP);

    auto
    get_position () const -> PositionType;

    void
    set_autohide (bool autohide = true);

    auto
    get_autohide () const -> bool;

    void
    set_has_arrow (bool has_arrow = true);

    auto
    get_has_arrow () const -> bool;

    void
    set_mnemonics_visible (bool mnemonics_visible = true);

    auto
    get_mnemonics_visible () const -> bool;

    void
    popup ();

    void
    popdown ();

    void
    set_offset (int x_offset, int y_offset);

    void
    get_offset (int& x_offset, int& y_offset) const;

    void
    set_cascade_popdown (bool cascade_popdown = true);

    auto
    get_cascade_popdown () const -> bool;

    void
    set_default_widget (Widget& widget);

    void
    present ();

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
    virtual void
    on_closed ();
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkPopover* object, bool take_copy = false) -> Gtk::Popover*;
} // namespace Glib

#endif
