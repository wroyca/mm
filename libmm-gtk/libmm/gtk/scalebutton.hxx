// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SCALEBUTTON_H
#define _GTKMM_SCALEBUTTON_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <vector>

#include <libmm/gtk/adjustment.hxx>
#include <libmm/gtk/button.hxx>
#include <libmm/gtk/enums.hxx>
#include <libmm/gtk/orientable.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkScaleButton = struct _GtkScaleButton;
using GtkScaleButtonClass = struct _GtkScaleButtonClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT ScaleButton_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT ScaleButton : public Widget,
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
    friend LIBMM_GTK_SYMEXPORT class ScaleButton_Class;
    static CppClassType scalebutton_class_;

  protected:
    explicit ScaleButton (const glib::ConstructParams& construct_params);
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
                          const std::vector<glib::ustring>& icons);

    explicit ScaleButton (double min, double max, double step);

    auto
    set_icons (const std::vector<glib::ustring>& icons) -> void;

    auto
    get_value () const -> double;

    auto
    set_value (double value) -> void;

    auto
    get_adjustment () -> glib::RefPtr<Adjustment>;

    auto
    get_adjustment () const -> glib::RefPtr<const Adjustment>;

    auto
    set_adjustment (const glib::RefPtr<Adjustment>& adjustment) -> void;

    auto
    get_plus_button () -> Button*;

    auto
    get_plus_button () const -> const Button*;

    auto
    get_minus_button () -> Button*;

    auto
    get_minus_button () const -> const Button*;

    auto
    get_popup () -> gtk::Widget*;

    auto
    get_popup () const -> const gtk::Widget*;

    auto
    signal_value_changed () -> glib::SignalProxy<void (double)>;

    auto
    property_value () -> glib::PropertyProxy<double>;

    auto
    property_value () const -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_adjustment () -> glib::PropertyProxy<glib::RefPtr<Adjustment>>;

    auto
    property_adjustment () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Adjustment>>;

    auto
    property_icons () -> glib::PropertyProxy<std::vector<glib::ustring>>;

    auto
    property_icons () const
        -> glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>>;

  public:
  public:
  protected:
    virtual auto
    on_value_changed (double value) -> void;
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkScaleButton* object, bool take_copy = false) -> gtk::ScaleButton*;
} // namespace glib

#endif
