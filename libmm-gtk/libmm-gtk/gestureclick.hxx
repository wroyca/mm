// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_GESTURECLICK_H
#define _GTKMM_GESTURECLICK_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/rectangle.hxx>
#include <libmm-gtk/gesturesingle.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkGestureClick = struct _GtkGestureClick;
using GtkGestureClickClass = struct _GtkGestureClickClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API GestureClick_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API GestureClick : public GestureSingle
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = GestureClick;
    using CppClassType = GestureClick_Class;
    using BaseObjectType = GtkGestureClick;
    using BaseClassType = GtkGestureClickClass;

    GestureClick (const GestureClick&) = delete;
    auto
    operator= (const GestureClick&) -> GestureClick& = delete;

  private:
    friend class GestureClick_Class;
    static CppClassType gestureclick_class_;

  protected:
    explicit GestureClick (const Glib::ConstructParams& construct_params);
    explicit GestureClick (GtkGestureClick* castitem);

#endif

  public:
    GestureClick (GestureClick&& src) noexcept;
    auto
    operator= (GestureClick&& src) noexcept -> GestureClick&;

    ~GestureClick () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkGestureClick*
    {
      return reinterpret_cast<GtkGestureClick*> (gobject_);
    }

    auto
    gobj () const -> const GtkGestureClick*
    {
      return reinterpret_cast<GtkGestureClick*> (gobject_);
    }

    auto
    gobj_copy () -> GtkGestureClick*;

  private:
  protected:
    GestureClick ();

  public:
    static auto
    create () -> Glib::RefPtr<GestureClick>;

    auto
    signal_pressed () -> Glib::SignalProxy<void (int, double, double)>;

    auto
    signal_released () -> Glib::SignalProxy<void (int, double, double)>;

    auto
    signal_stopped () -> Glib::SignalProxy<void ()>;

    auto
    signal_unpaired_release ()
        -> Glib::SignalProxy<void (double, double, guint, Gdk::EventSequence*)>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  GTKMM_API auto
  wrap (GtkGestureClick* object, bool take_copy = false) -> Glib::RefPtr<Gtk::GestureClick>;
} // namespace Glib

#endif
