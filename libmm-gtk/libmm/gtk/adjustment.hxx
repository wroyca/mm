// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ADJUSTMENT_H
#define _GTKMM_ADJUSTMENT_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkAdjustment = struct _GtkAdjustment;
using GtkAdjustmentClass = struct _GtkAdjustmentClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Adjustment_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Adjustment : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Adjustment;
    using CppClassType = Adjustment_Class;
    using BaseObjectType = GtkAdjustment;
    using BaseClassType = GtkAdjustmentClass;

    Adjustment (const Adjustment&) = delete;
    auto
    operator= (const Adjustment&) -> Adjustment& = delete;

  private:
    friend class Adjustment_Class;
    static CppClassType adjustment_class_;

  protected:
    explicit Adjustment (const glib::ConstructParams& construct_params);
    explicit Adjustment (GtkAdjustment* castitem);

#endif

  public:
    Adjustment (Adjustment&& src) noexcept;
    auto
    operator= (Adjustment&& src) noexcept -> Adjustment&;

    ~Adjustment () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkAdjustment*
    {
      return reinterpret_cast<GtkAdjustment*> (gobject_);
    }

    auto
    gobj () const -> const GtkAdjustment*
    {
      return reinterpret_cast<GtkAdjustment*> (gobject_);
    }

    auto
    gobj_copy () -> GtkAdjustment*;

  private:
  public:
    friend LIBMM_GTK_SYMEXPORT class Range;
    friend LIBMM_GTK_SYMEXPORT class HScrollbar;
    friend LIBMM_GTK_SYMEXPORT class VScrollbar;

  protected:
    Adjustment (double value,
                double lower,
                double upper,
                double step_increment = 1,
                double page_increment = 10,
                double page_size = 0);

  public:
    static auto
    create (double value,
            double lower,
            double upper,
            double step_increment = 1,
            double page_increment = 10,
            double page_size = 0) -> glib::RefPtr<Adjustment>;

    auto
    clamp_page (double lower, double upper) -> void;

    auto
    set_value (double value) -> void;

    auto
    get_value () const -> double;

    auto
    set_lower (double lower) -> void;

    auto
    get_lower () const -> double;

    auto
    set_upper (double upper) -> void;

    auto
    get_upper () const -> double;

    auto
    set_step_increment (double step_increment) -> void;

    auto
    get_step_increment () const -> double;

    auto
    set_page_increment (double page_increment) -> void;

    auto
    get_page_increment () const -> double;

    auto
    set_page_size (double page_size) -> void;

    auto
    get_page_size () const -> double;

    auto
    configure (double value,
               double lower,
               double upper,
               double step_increment,
               double page_increment,
               double page_size) -> void;

    auto
    get_minimum_increment () const -> double;

    auto
    signal_changed () -> glib::SignalProxy<void ()>;

    auto
    signal_value_changed () -> glib::SignalProxy<void ()>;

    auto
    property_value () -> glib::PropertyProxy<double>;

    auto
    property_value () const -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_lower () -> glib::PropertyProxy<double>;

    auto
    property_lower () const -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_upper () -> glib::PropertyProxy<double>;

    auto
    property_upper () const -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_step_increment () -> glib::PropertyProxy<double>;

    auto
    property_step_increment () const -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_page_increment () -> glib::PropertyProxy<double>;

    auto
    property_page_increment () const -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_page_size () -> glib::PropertyProxy<double>;

    auto
    property_page_size () const -> glib::PropertyProxy_ReadOnly<double>;

  public:
  public:
  protected:
    virtual auto
    on_changed () -> void;

    virtual auto
    on_value_changed () -> void;
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkAdjustment* object, bool take_copy = false) -> glib::RefPtr<gtk::Adjustment>;
} // namespace glib

#endif
