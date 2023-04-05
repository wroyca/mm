// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_SWIPETRACKER_H
#define _LIBADWAITAMM_SWIPETRACKER_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/mm-glib.hxx>
#include <libmm/gtk/mm-gtk.hxx>

#include <adwaita.h>
#include <libmm/adw/swipeable.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT SwipeTracker_Class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT SwipeTracker : public glib::Object,
                       public gtk::Orientable
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
    explicit SwipeTracker (const glib::ConstructParams& construct_params);
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
    explicit SwipeTracker (const glib::RefPtr<Swipeable>& swipeable);

  public:
    static auto
    create (const glib::RefPtr<Swipeable>& swipeable)
        -> glib::RefPtr<SwipeTracker>;

    auto
    get_allow_long_swipes () const -> bool;

    auto
    get_allow_mouse_drag () const -> bool;

    auto
    get_enabled () const -> bool;

    auto
    get_reversed () const -> bool;

    auto
    get_swipeable () const -> glib::RefPtr<Swipeable>;

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
    property_allow_long_swipes () -> glib::PropertyProxy<bool>;

    auto
    property_allow_long_swipes () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_allow_mouse_drag () -> glib::PropertyProxy<bool>;

    auto
    property_allow_mouse_drag () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_enabled () -> glib::PropertyProxy<bool>;

    auto
    property_enabled () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_reversed () -> glib::PropertyProxy<bool>;

    auto
    property_reversed () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_swipeable () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Swipeable>>;

    auto
    signal_begin_swipe () -> glib::SignalProxy<void ()>;

    auto
    signal_end_swipe () -> glib::SignalProxy<void (double, double)>;

    auto
    signal_prepare () -> glib::SignalProxy<void (NavigationDirection)>;

    auto
    signal_update_swipe () -> glib::SignalProxy<void (double)>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwSwipeTracker* object, bool take_copy = false) -> glib::RefPtr<adw::SwipeTracker>;
}

#endif
