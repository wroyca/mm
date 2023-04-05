// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SPINBUTTON_H
#define _GTKMM_SPINBUTTON_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/celleditable.hxx>
#include <libmm/gtk/editable.hxx>
#include <libmm/gtk/orientable.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkSpinButton = struct _GtkSpinButton;
using GtkSpinButtonClass = struct _GtkSpinButtonClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT SpinButton_Class;
}
#endif

namespace gtk
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

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::SpinType> : public glib::Value_Enum<gtk::SpinType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
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
    explicit SpinButton (const glib::ConstructParams& construct_params);
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

    explicit SpinButton (const glib::RefPtr<Adjustment>& adjustment,
                         double climb_rate = 0.0,
                         guint digits = 0);

    auto
    configure (const glib::RefPtr<Adjustment>& adjustment,
               double climb_rate,
               guint digits) -> void;

    auto
    set_adjustment (const glib::RefPtr<Adjustment>& adjustment) -> void;
    auto
    unset_adjustment () -> void;

    auto
    get_adjustment () -> glib::RefPtr<Adjustment>;

    auto
    get_adjustment () const -> glib::RefPtr<const Adjustment>;

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
    signal_input () -> glib::SignalProxy<int (double&)>;

    auto
    signal_output () -> glib::SignalProxy<bool ()>;

    auto
    signal_wrapped () -> glib::SignalProxy<void ()>;

    auto
    signal_value_changed () -> glib::SignalProxy<void ()>;

    auto
    property_adjustment () -> glib::PropertyProxy<glib::RefPtr<Adjustment>>;

    auto
    property_adjustment () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Adjustment>>;

    auto
    property_climb_rate () -> glib::PropertyProxy<double>;

    auto
    property_climb_rate () const -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_digits () -> glib::PropertyProxy<guint>;

    auto
    property_digits () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_snap_to_ticks () -> glib::PropertyProxy<bool>;

    auto
    property_snap_to_ticks () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_numeric () -> glib::PropertyProxy<bool>;

    auto
    property_numeric () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_wrap () -> glib::PropertyProxy<bool>;

    auto
    property_wrap () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_update_policy () -> glib::PropertyProxy<UpdatePolicy>;

    auto
    property_update_policy () const
        -> glib::PropertyProxy_ReadOnly<UpdatePolicy>;

    auto
    property_value () -> glib::PropertyProxy<double>;

    auto
    property_value () const -> glib::PropertyProxy_ReadOnly<double>;

  public:
  public:
  protected:
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::SpinButton::UpdatePolicy>
    : public glib::Value_Enum<gtk::SpinButton::UpdatePolicy>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkSpinButton* object, bool take_copy = false) -> gtk::SpinButton*;
} // namespace glib

#endif
