// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SWITCH_H
#define _GTKMM_SWITCH_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/actionable.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkSwitch = struct _GtkSwitch;
using GtkSwitchClass = struct _GtkSwitchClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Switch_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Switch : public Widget,
                           public Actionable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Switch CppObjectType;
    typedef Switch_Class CppClassType;
    typedef GtkSwitch BaseObjectType;
    typedef GtkSwitchClass BaseClassType;
#endif

    Switch (Switch&& src) noexcept;
    auto
    operator= (Switch&& src) noexcept -> Switch&;

    Switch (const Switch&) = delete;
    auto
    operator= (const Switch&) -> Switch& = delete;

    ~Switch () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class Switch_Class;
    static CppClassType switch_class_;

  protected:
    explicit Switch (const Glib::ConstructParams& construct_params);
    explicit Switch (GtkSwitch* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkSwitch*
    {
      return reinterpret_cast<GtkSwitch*> (gobject_);
    }

    auto
    gobj () const -> const GtkSwitch*
    {
      return reinterpret_cast<GtkSwitch*> (gobject_);
    }

  private:
  public:
    Switch ();

    void
    set_active (bool is_active = true);

    auto
    get_active () const -> bool;

    void
    set_state (bool state = true);

    auto
    get_state () const -> bool;

    auto
    property_active () -> Glib::PropertyProxy<bool>;

    auto
    property_active () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_state () -> Glib::PropertyProxy<bool>;

    auto
    property_state () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    signal_state_set () -> Glib::SignalProxy<bool (bool)>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkSwitch* object, bool take_copy = false) -> Gtk::Switch*;
} // namespace Glib

#endif
