// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_SWIPETRACKER_H
#define _LIBADWAITAMM_SWIPETRACKER_H

#include <libmm-adw/mm-adwconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/mm-glib.hxx>
#include <libmm-gtk/mm-gtk.hxx>

#include <adwaita.h>
#include <libmm-adw/swipeable.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class SwipeTracker_Class;
}
#endif

namespace Adw
{

  class SwipeTracker : public Glib::Object,
                       public Gtk::Orientable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = SwipeTracker;
    using CppClassType = SwipeTracker_Class;
    using BaseObjectType = AdwSwipeTracker;
    using BaseClassType = AdwSwipeTrackerClass;

    SwipeTracker (const SwipeTracker&) = delete;
    auto
    operator= (const SwipeTracker&) -> SwipeTracker& = delete;

  private:
    friend class SwipeTracker_Class;
    static CppClassType swipetracker_class_;

  protected:
    explicit SwipeTracker (const Glib::ConstructParams& construct_params);
    explicit SwipeTracker (AdwSwipeTracker* castitem);

#endif

  public:
    SwipeTracker (SwipeTracker&& src) noexcept;
    auto
    operator= (SwipeTracker&& src) noexcept -> SwipeTracker&;

    ~SwipeTracker () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwSwipeTracker*
    {
      return reinterpret_cast<AdwSwipeTracker*> (gobject_);
    }

    auto
    gobj () const -> const AdwSwipeTracker*
    {
      return reinterpret_cast<AdwSwipeTracker*> (gobject_);
    }

    auto
    gobj_copy () -> AdwSwipeTracker*;

  private:
  protected:
    SwipeTracker ();
    explicit SwipeTracker (const Glib::RefPtr<Swipeable>& swipeable);

  public:
    static auto
    create (const Glib::RefPtr<Swipeable>& swipeable)
        -> Glib::RefPtr<SwipeTracker>;

    auto
    get_allow_long_swipes () const -> bool;

    auto
    get_allow_mouse_drag () const -> bool;

    auto
    get_enabled () const -> bool;

    auto
    get_reversed () const -> bool;

    auto
    get_swipeable () const -> Glib::RefPtr<Swipeable>;

    auto
    set_allow_long_swipes (bool allow_long_swipes) -> void;

    auto
    set_allow_mouse_drag (bool allow_mouse_drag) -> void;

    auto
    set_enabled (bool enabled) -> void;

    auto
    set_reversed (bool enabled) -> void;

    auto
    shift_position (double delta) -> void;

    auto
    property_allow_long_swipes () -> Glib::PropertyProxy<bool>;

    auto
    property_allow_long_swipes () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_allow_mouse_drag () -> Glib::PropertyProxy<bool>;

    auto
    property_allow_mouse_drag () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_enabled () -> Glib::PropertyProxy<bool>;

    auto
    property_enabled () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_reversed () -> Glib::PropertyProxy<bool>;

    auto
    property_reversed () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_swipeable () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Swipeable>>;

    auto
    signal_begin_swipe () -> Glib::SignalProxy<void ()>;

    auto
    signal_end_swipe () -> Glib::SignalProxy<void (double, double)>;

    auto
    signal_prepare () -> Glib::SignalProxy<void (NavigationDirection)>;

    auto
    signal_update_swipe () -> Glib::SignalProxy<void (double)>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwSwipeTracker* object, bool take_copy = false) -> Glib::RefPtr<Adw::SwipeTracker>;
}

#endif
