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
  class LIBMM_ADW_SYMEXPORT swipe_tracker_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT swipe_tracker : public glib::Object,
                       public gtk::Orientable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = swipe_tracker;
    using CppClassType = swipe_tracker_class;
    using BaseObjectType = AdwSwipeTracker;
    using BaseClassType = AdwSwipeTrackerClass;

    swipe_tracker (const swipe_tracker&) = delete;
    auto
    operator= (const swipe_tracker&) -> swipe_tracker& = delete;

  private:
    friend class swipe_tracker_class;
    static CppClassType swipetracker_class_;

  protected:
    explicit swipe_tracker (const glib::ConstructParams& construct_params);
    explicit swipe_tracker (AdwSwipeTracker* castitem);

#endif

  public:
    swipe_tracker (swipe_tracker&& src) noexcept;
    auto
    operator= (swipe_tracker&& src) noexcept -> swipe_tracker&;

    ~swipe_tracker () noexcept override;

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
    swipe_tracker ();
    explicit swipe_tracker (const glib::RefPtr<swipeable>& swipeable);

  public:
    static auto
    create (const glib::RefPtr<swipeable>& swipeable)
        -> glib::RefPtr<swipe_tracker>;

    auto
    get_allow_long_swipes () const -> bool;

    auto
    get_allow_mouse_drag () const -> bool;

    auto
    get_enabled () const -> bool;

    auto
    get_reversed () const -> bool;

    auto
    get_swipeable () const -> glib::RefPtr<swipeable>;

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
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<swipeable>>;

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
  wrap (AdwSwipeTracker* object, bool take_copy = false) -> glib::RefPtr<adw::swipe_tracker>;
}

#endif
