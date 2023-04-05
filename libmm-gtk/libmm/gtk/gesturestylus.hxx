// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_GESTURESTYLUS_H
#define _GTKMM_GESTURESTYLUS_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/enums.hxx>
#include <libmm/gdk/timecoord.hxx>
#include <libmm/gtk/gesturesingle.hxx>
#include <optional>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkGestureStylus = struct _GtkGestureStylus;
using GtkGestureStylusClass = struct _GtkGestureStylusClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT GestureStylus_Class;
}
#endif

namespace gdk
{
  class LIBMM_GTK_SYMEXPORT DeviceTool;
}

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT GestureStylus : public GestureSingle
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = GestureStylus;
    using CppClassType = GestureStylus_Class;
    using BaseObjectType = GtkGestureStylus;
    using BaseClassType = GtkGestureStylusClass;

    GestureStylus (const GestureStylus&) = delete;
    auto
    operator= (const GestureStylus&) -> GestureStylus& = delete;

  private:
    friend class GestureStylus_Class;
    static CppClassType gesturestylus_class_;

  protected:
    explicit GestureStylus (const glib::ConstructParams& construct_params);
    explicit GestureStylus (GtkGestureStylus* castitem);

#endif

  public:
    GestureStylus (GestureStylus&& src) noexcept;
    auto
    operator= (GestureStylus&& src) noexcept -> GestureStylus&;

    ~GestureStylus () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkGestureStylus*
    {
      return reinterpret_cast<GtkGestureStylus*> (gobject_);
    }

    auto
    gobj () const -> const GtkGestureStylus*
    {
      return reinterpret_cast<GtkGestureStylus*> (gobject_);
    }

    auto
    gobj_copy () -> GtkGestureStylus*;

  private:
  protected:
    GestureStylus ();

  public:
    static auto
    create () -> glib::RefPtr<GestureStylus>;

    auto
    get_stylus_only () const -> bool;

    auto
    set_stylus_only (bool stylus_only = true) -> void;

    auto
    get_axis (gdk::AxisUse axis) const -> std::optional<double>;

    auto
    get_axes (const std::vector<gdk::AxisUse>& axes) const
        -> std::vector<double>;

    auto
    get_backlog () const -> std::vector<gdk::TimeCoord>;

    auto
    get_device_tool () -> glib::RefPtr<gdk::DeviceTool>;

    auto
    get_device_tool () const -> glib::RefPtr<const gdk::DeviceTool>;

    auto
    signal_proximity () -> glib::SignalProxy<void (double, double)>;

    auto
    signal_down () -> glib::SignalProxy<void (double, double)>;

    auto
    signal_motion () -> glib::SignalProxy<void (double, double)>;

    auto
    signal_up () -> glib::SignalProxy<void (double, double)>;

    auto
    property_stylus_only () -> glib::PropertyProxy<bool>;

    auto
    property_stylus_only () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkGestureStylus* object, bool take_copy = false) -> glib::RefPtr<gtk::GestureStylus>;
} // namespace glib

#endif
