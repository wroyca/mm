// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SPINBUTTON_H
#define _GTKMM_SPINBUTTON_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/celleditable.hxx>
#include <libmm-gtk/editable.hxx>
#include <libmm-gtk/orientable.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkSpinButton = struct _GtkSpinButton;
using GtkSpinButtonClass = struct _GtkSpinButtonClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT SpinButton_Class;
}
#endif

namespace Gtk
{

  enum class SpinType
  {
    STEP_FORWARD,
    STEP_BACKWARD,
    PAGE_FORWARD,
    PAGE_BACKWARD,
    HOME,
    END,
    USER_DEFINED
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<Gtk::SpinType> : public Glib::Value_Enum<Gtk::SpinType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT Adjustment;

  class LIBMM_GTK_SYMEXPORT SpinButton : public Widget,
                               public Orientable,
                               public Editable,
                               public CellEditable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef SpinButton CppObjectType;
    typedef SpinButton_Class CppClassType;
    typedef GtkSpinButton BaseObjectType;
    typedef GtkSpinButtonClass BaseClassType;
#endif

    SpinButton (SpinButton&& src) noexcept;
    auto
    operator= (SpinButton&& src) noexcept -> SpinButton&;

    SpinButton (const SpinButton&) = delete;
    auto
    operator= (const SpinButton&) -> SpinButton& = delete;

    ~SpinButton () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class SpinButton_Class;
    static CppClassType spinbutton_class_;

  protected:
    explicit SpinButton (const Glib::ConstructParams& construct_params);
    explicit SpinButton (GtkSpinButton* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkSpinButton*
    {
      return reinterpret_cast<GtkSpinButton*> (gobject_);
    }

    auto
    gobj () const -> const GtkSpinButton*
    {
      return reinterpret_cast<GtkSpinButton*> (gobject_);
    }

  private:
  public:
    enum class UpdatePolicy
    {
      ALWAYS,
      IF_VALID
    };

    explicit SpinButton (double climb_rate = 0.0, guint digits = 0);

    explicit SpinButton (const Glib::RefPtr<Adjustment>& adjustment,
                         double climb_rate = 0.0,
                         guint digits = 0);

    auto
    configure (const Glib::RefPtr<Adjustment>& adjustment,
               double climb_rate,
               guint digits) -> void;

    auto
    set_adjustment (const Glib::RefPtr<Adjustment>& adjustment) -> void;
    auto
    unset_adjustment () -> void;

    auto
    get_adjustment () -> Glib::RefPtr<Adjustment>;

    auto
    get_adjustment () const -> Glib::RefPtr<const Adjustment>;

    auto
    set_digits (guint digits) -> void;

    auto
    get_digits () const -> guint;

    auto
    set_increments (double step, double page) -> void;

    auto
    get_increments (double& step, double& page) const -> void;

    auto
    set_range (double min, double max) -> void;

    auto
    get_range (double& min, double& max) const -> void;

    auto
    get_value () const -> double;

    auto
    get_value_as_int () const -> int;

    auto
    set_value (double value) -> void;

    auto
    set_update_policy (UpdatePolicy policy) -> void;

    auto
    get_update_policy () const -> UpdatePolicy;

    auto
    set_numeric (bool numeric = true) -> void;

    auto
    get_numeric () const -> bool;

    auto
    spin (SpinType direction, double increment) -> void;

    auto
    set_wrap (bool wrap = true) -> void;

    auto
    get_wrap () const -> bool;

    auto
    set_snap_to_ticks (bool snap_to_ticks = true) -> void;

    auto
    get_snap_to_ticks () const -> bool;

    auto
    set_climb_rate (double climb_rate) -> void;

    auto
    get_climb_rate () const -> double;

    auto
    update () -> void;

    enum
    {
      INPUT_ERROR = -1
    };

    auto
    signal_input () -> Glib::SignalProxy<int (double&)>;

    auto
    signal_output () -> Glib::SignalProxy<bool ()>;

    auto
    signal_wrapped () -> Glib::SignalProxy<void ()>;

    auto
    signal_value_changed () -> Glib::SignalProxy<void ()>;

    auto
    property_adjustment () -> Glib::PropertyProxy<Glib::RefPtr<Adjustment>>;

    auto
    property_adjustment () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Adjustment>>;

    auto
    property_climb_rate () -> Glib::PropertyProxy<double>;

    auto
    property_climb_rate () const -> Glib::PropertyProxy_ReadOnly<double>;

    auto
    property_digits () -> Glib::PropertyProxy<guint>;

    auto
    property_digits () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_snap_to_ticks () -> Glib::PropertyProxy<bool>;

    auto
    property_snap_to_ticks () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_numeric () -> Glib::PropertyProxy<bool>;

    auto
    property_numeric () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_wrap () -> Glib::PropertyProxy<bool>;

    auto
    property_wrap () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_update_policy () -> Glib::PropertyProxy<UpdatePolicy>;

    auto
    property_update_policy () const
        -> Glib::PropertyProxy_ReadOnly<UpdatePolicy>;

    auto
    property_value () -> Glib::PropertyProxy<double>;

    auto
    property_value () const -> Glib::PropertyProxy_ReadOnly<double>;

  public:
  public:
  protected:
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<Gtk::SpinButton::UpdatePolicy>
    : public Glib::Value_Enum<Gtk::SpinButton::UpdatePolicy>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkSpinButton* object, bool take_copy = false) -> Gtk::SpinButton*;
} // namespace Glib

#endif
