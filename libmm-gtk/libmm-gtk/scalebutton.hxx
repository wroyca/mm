// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SCALEBUTTON_H
#define _GTKMM_SCALEBUTTON_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <vector>

#include <libmm-gtk/adjustment.hxx>
#include <libmm-gtk/button.hxx>
#include <libmm-gtk/enums.hxx>
#include <libmm-gtk/orientable.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkScaleButton = struct _GtkScaleButton;
using GtkScaleButtonClass = struct _GtkScaleButtonClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API ScaleButton_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API ScaleButton : public Widget,
                                public Orientable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ScaleButton CppObjectType;
    typedef ScaleButton_Class CppClassType;
    typedef GtkScaleButton BaseObjectType;
    typedef GtkScaleButtonClass BaseClassType;
#endif

    ScaleButton (ScaleButton&& src) noexcept;
    auto
    operator= (ScaleButton&& src) noexcept -> ScaleButton&;

    ScaleButton (const ScaleButton&) = delete;
    auto
    operator= (const ScaleButton&) -> ScaleButton& = delete;

    ~ScaleButton () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class ScaleButton_Class;
    static CppClassType scalebutton_class_;

  protected:
    explicit ScaleButton (const Glib::ConstructParams& construct_params);
    explicit ScaleButton (GtkScaleButton* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkScaleButton*
    {
      return reinterpret_cast<GtkScaleButton*> (gobject_);
    }

    auto
    gobj () const -> const GtkScaleButton*
    {
      return reinterpret_cast<GtkScaleButton*> (gobject_);
    }

  private:
  public:
    explicit ScaleButton (double min,
                          double max,
                          double step,
                          const std::vector<Glib::ustring>& icons);

    explicit ScaleButton (double min, double max, double step);

    auto
    set_icons (const std::vector<Glib::ustring>& icons) -> void;

    auto
    get_value () const -> double;

    auto
    set_value (double value) -> void;

    auto
    get_adjustment () -> Glib::RefPtr<Adjustment>;

    auto
    get_adjustment () const -> Glib::RefPtr<const Adjustment>;

    auto
    set_adjustment (const Glib::RefPtr<Adjustment>& adjustment) -> void;

    auto
    get_plus_button () -> Button*;

    auto
    get_plus_button () const -> const Button*;

    auto
    get_minus_button () -> Button*;

    auto
    get_minus_button () const -> const Button*;

    auto
    get_popup () -> Gtk::Widget*;

    auto
    get_popup () const -> const Gtk::Widget*;

    auto
    signal_value_changed () -> Glib::SignalProxy<void (double)>;

    auto
    property_value () -> Glib::PropertyProxy<double>;

    auto
    property_value () const -> Glib::PropertyProxy_ReadOnly<double>;

    auto
    property_adjustment () -> Glib::PropertyProxy<Glib::RefPtr<Adjustment>>;

    auto
    property_adjustment () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Adjustment>>;

    auto
    property_icons () -> Glib::PropertyProxy<std::vector<Glib::ustring>>;

    auto
    property_icons () const
        -> Glib::PropertyProxy_ReadOnly<std::vector<Glib::ustring>>;

  public:
  public:
  protected:
    virtual auto
    on_value_changed (double value) -> void;
  };

} // namespace Gtk

namespace Glib
{
  GTKMM_API auto
  wrap (GtkScaleButton* object, bool take_copy = false) -> Gtk::ScaleButton*;
} // namespace Glib

#endif
