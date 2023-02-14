// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_GESTUREROTATE_H
#define _GTKMM_GESTUREROTATE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/gesture.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkGestureRotate = struct _GtkGestureRotate;
using GtkGestureRotateClass = struct _GtkGestureRotateClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API GestureRotate_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API GestureRotate : public Gesture
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = GestureRotate;
    using CppClassType = GestureRotate_Class;
    using BaseObjectType = GtkGestureRotate;
    using BaseClassType = GtkGestureRotateClass;

    GestureRotate (const GestureRotate&) = delete;
    auto
    operator= (const GestureRotate&) -> GestureRotate& = delete;

  private:
    friend class GestureRotate_Class;
    static CppClassType gesturerotate_class_;

  protected:
    explicit GestureRotate (const Glib::ConstructParams& construct_params);
    explicit GestureRotate (GtkGestureRotate* castitem);

#endif

  public:
    GestureRotate (GestureRotate&& src) noexcept;
    auto
    operator= (GestureRotate&& src) noexcept -> GestureRotate&;

    ~GestureRotate () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkGestureRotate*
    {
      return reinterpret_cast<GtkGestureRotate*> (gobject_);
    }

    auto
    gobj () const -> const GtkGestureRotate*
    {
      return reinterpret_cast<GtkGestureRotate*> (gobject_);
    }

    auto
    gobj_copy () -> GtkGestureRotate*;

  private:
  protected:
    GestureRotate ();

  public:
    static auto
    create () -> Glib::RefPtr<GestureRotate>;

    auto
    get_angle_delta () const -> double;

    auto
    signal_angle_changed () -> Glib::SignalProxy<void (double, double)>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkGestureRotate* object, bool take_copy = false) -> Glib::RefPtr<Gtk::GestureRotate>;
} // namespace Glib

#endif
