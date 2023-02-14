
#ifndef _GTKMM_GESTURESTYLUS_H
#define _GTKMM_GESTURESTYLUS_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/enums.hxx>
#include <libmm-gdk/timecoord.hxx>
#include <libmm-gtk/gesturesingle.hxx>
#include <optional>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkGestureStylus = struct _GtkGestureStylus;
using GtkGestureStylusClass = struct _GtkGestureStylusClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API GestureStylus_Class;
}
#endif

namespace Gdk
{
  class GTKMM_API DeviceTool;
}

namespace Gtk
{

  class GTKMM_API GestureStylus : public GestureSingle
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
    explicit GestureStylus (const Glib::ConstructParams& construct_params);
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
    create () -> Glib::RefPtr<GestureStylus>;

    auto
    get_axis (Gdk::AxisUse axis) const -> std::optional<double>;

    auto
    get_axes (const std::vector<Gdk::AxisUse>& axes) const
        -> std::vector<double>;

    auto
    get_backlog () const -> std::vector<Gdk::TimeCoord>;

    auto
    get_device_tool () -> Glib::RefPtr<Gdk::DeviceTool>;

    auto
    get_device_tool () const -> Glib::RefPtr<const Gdk::DeviceTool>;

    auto
    signal_proximity () -> Glib::SignalProxy<void (double, double)>;

    auto
    signal_down () -> Glib::SignalProxy<void (double, double)>;

    auto
    signal_motion () -> Glib::SignalProxy<void (double, double)>;

    auto
    signal_up () -> Glib::SignalProxy<void (double, double)>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkGestureStylus* object, bool take_copy = false) -> Glib::RefPtr<Gtk::GestureStylus>;
} // namespace Glib

#endif
