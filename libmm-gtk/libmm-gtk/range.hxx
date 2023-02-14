// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_RANGE_H
#define _GTKMM_RANGE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/border.hxx>
#include <libmm-gtk/enums.hxx>
#include <libmm-gtk/orientable.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkRange = struct _GtkRange;
using GtkRangeClass = struct _GtkRangeClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Range_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Adjustment;

  class GTKMM_API Range : public Widget,
                          public Orientable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Range CppObjectType;
    typedef Range_Class CppClassType;
    typedef GtkRange BaseObjectType;
    typedef GtkRangeClass BaseClassType;
#endif

    Range (Range&& src) noexcept;
    auto
    operator= (Range&& src) noexcept -> Range&;

    Range (const Range&) = delete;
    auto
    operator= (const Range&) -> Range& = delete;

    ~Range () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class Range_Class;
    static CppClassType range_class_;

  protected:
    explicit Range (const Glib::ConstructParams& construct_params);
    explicit Range (GtkRange* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkRange*
    {
      return reinterpret_cast<GtkRange*> (gobject_);
    }

    auto
    gobj () const -> const GtkRange*
    {
      return reinterpret_cast<GtkRange*> (gobject_);
    }

  private:
  protected:
    Range ();

  public:
    void
    set_adjustment (const Glib::RefPtr<Adjustment>& adjustment);
    void
    unset_adjustment ();

    auto
    get_adjustment () -> Glib::RefPtr<Adjustment>;

    auto
    get_adjustment () const -> Glib::RefPtr<const Adjustment>;

    void
    set_inverted (bool setting = true);

    auto
    get_inverted () const -> bool;

    void
    set_flippable (bool flippable = true);

    auto
    get_flippable () const -> bool;

    void
    set_slider_size_fixed (bool size_fixed = true);

    auto
    get_slider_size_fixed () const -> bool;

    auto
    get_range_rect () const -> Gdk::Rectangle;

    void
    get_slider_range (int& slider_start, int& slider_end) const;

    void
    set_increments (double step, double page);

    void
    set_range (double min, double max);

    void
    set_value (double value);

    auto
    get_value () const -> double;

    void
    set_show_fill_level (bool show_fill_level = true);

    auto
    get_show_fill_level () const -> bool;

    void
    set_restrict_to_fill_level (bool restrict_to_fill_level = true);

    auto
    get_restrict_to_fill_level () const -> bool;

    void
    set_fill_level (double fill_level);

    auto
    get_fill_level () const -> double;

    void
    set_round_digits (int round_digits);

    auto
    get_round_digits () const -> int;

    auto
    signal_value_changed () -> Glib::SignalProxy<void ()>;

    auto
    signal_adjust_bounds () -> Glib::SignalProxy<void (double)>;

    auto
    signal_move_slider () -> Glib::SignalProxy<void (ScrollType)>;

    auto
    signal_change_value () -> Glib::SignalProxy<bool (ScrollType, double)>;

    auto
    property_adjustment () -> Glib::PropertyProxy<Glib::RefPtr<Adjustment>>;

    auto
    property_adjustment () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Adjustment>>;

    auto
    property_inverted () -> Glib::PropertyProxy<bool>;

    auto
    property_inverted () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_fill_level () -> Glib::PropertyProxy<bool>;

    auto
    property_show_fill_level () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_restrict_to_fill_level () -> Glib::PropertyProxy<bool>;

    auto
    property_restrict_to_fill_level () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_fill_level () -> Glib::PropertyProxy<double>;

    auto
    property_fill_level () const -> Glib::PropertyProxy_ReadOnly<double>;

    auto
    property_round_digits () -> Glib::PropertyProxy<int>;

    auto
    property_round_digits () const -> Glib::PropertyProxy_ReadOnly<int>;

  protected:
    virtual void
    get_range_border_vfunc (Gtk::Border& border) const;

  public:
  public:
  protected:
    virtual void
    on_value_changed ();

    virtual void
    on_adjust_bounds (double new_value);

    virtual void
    on_move_slider (ScrollType scroll);

    virtual auto
    on_change_value (ScrollType scroll, double new_value) -> bool;
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkRange* object, bool take_copy = false) -> Gtk::Range*;
} // namespace Glib

#endif
