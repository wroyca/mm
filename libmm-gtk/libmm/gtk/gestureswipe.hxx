// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_GESTURESWIPE_H
#define _GTKMM_GESTURESWIPE_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/gesturesingle.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkGestureSwipe = struct _GtkGestureSwipe;
using GtkGestureSwipeClass = struct _GtkGestureSwipeClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT GestureSwipe_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT GestureSwipe : public GestureSingle
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = GestureSwipe;
    using CppClassType = GestureSwipe_Class;
    using BaseObjectType = GtkGestureSwipe;
    using BaseClassType = GtkGestureSwipeClass;

    GestureSwipe (const GestureSwipe&) = delete;
    auto
    operator= (const GestureSwipe&) -> GestureSwipe& = delete;

  private:
    friend class GestureSwipe_Class;
    static CppClassType gestureswipe_class_;

  protected:
    explicit GestureSwipe (const glib::ConstructParams& construct_params);
    explicit GestureSwipe (GtkGestureSwipe* castitem);

#endif

  public:
    GestureSwipe (GestureSwipe&& src) noexcept;
    auto
    operator= (GestureSwipe&& src) noexcept -> GestureSwipe&;

    ~GestureSwipe () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkGestureSwipe*
    {
      return reinterpret_cast<GtkGestureSwipe*> (gobject_);
    }

    auto
    gobj () const -> const GtkGestureSwipe*
    {
      return reinterpret_cast<GtkGestureSwipe*> (gobject_);
    }

    auto
    gobj_copy () -> GtkGestureSwipe*;

  private:
  protected:
    GestureSwipe ();

  public:
    static auto
    create () -> glib::RefPtr<GestureSwipe>;

    auto
    get_velocity (double& velocity_x, double& velocity_y) const -> bool;

    auto
    signal_swipe () -> glib::SignalProxy<void (double, double)>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkGestureSwipe* object, bool take_copy = false) -> glib::RefPtr<gtk::GestureSwipe>;
} // namespace glib

#endif
