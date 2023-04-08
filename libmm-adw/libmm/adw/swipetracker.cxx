// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/swipetracker.hxx>
#include <libmm/adw/swipetracker_p.hxx>

#include <adwaita.h>
#include <libmm/glib/mm-glib.hxx>
#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

}

namespace
{

  static const glib::SignalProxyInfo SwipeTracker_signal_begin_swipe_info = {
      "begin-swipe",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static auto
  SwipeTracker_signal_end_swipe_callback (AdwSwipeTracker* self,
                                          gdouble p0,
                                          gdouble p1,
                                          void* data) -> void
  {
    using namespace adw;
    using SlotType = sigc::slot<void (double, double)>;

    auto obj = dynamic_cast<swipe_tracker*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0, p1);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo SwipeTracker_signal_end_swipe_info = {
      "end-swipe",
      (GCallback) &SwipeTracker_signal_end_swipe_callback,
      (GCallback) &SwipeTracker_signal_end_swipe_callback};

  static auto
  SwipeTracker_signal_prepare_callback (AdwSwipeTracker* self,
                                        AdwNavigationDirection p0,
                                        void* data) -> void
  {
    using namespace adw;
    using SlotType = sigc::slot<void (NavigationDirection)>;

    auto obj = dynamic_cast<swipe_tracker*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              static_cast<NavigationDirection> (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo SwipeTracker_signal_prepare_info = {
      "prepare",
      (GCallback) &SwipeTracker_signal_prepare_callback,
      (GCallback) &SwipeTracker_signal_prepare_callback};

  static auto
  SwipeTracker_signal_update_swipe_callback (AdwSwipeTracker* self,
                                             gdouble p0,
                                             void* data) -> void
  {
    using namespace adw;
    using SlotType = sigc::slot<void (double)>;

    auto obj = dynamic_cast<swipe_tracker*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo SwipeTracker_signal_update_swipe_info = {
      "update-swipe",
      (GCallback) &SwipeTracker_signal_update_swipe_callback,
      (GCallback) &SwipeTracker_signal_update_swipe_callback};

} // namespace

namespace glib
{

  auto
  wrap (AdwSwipeTracker* object, bool take_copy) -> glib::RefPtr<adw::swipe_tracker>
  {
    return glib::make_refptr_for_instance<adw::swipe_tracker> (
        dynamic_cast<adw::swipe_tracker*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  swipe_tracker_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_swipe_tracker_get_type ();
    }

    return *this;
  }

  auto
  swipe_tracker_class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new swipe_tracker ((AdwSwipeTracker*) object);
  }

  auto
  swipe_tracker::gobj_copy () -> AdwSwipeTracker*
  {
    reference ();
    return gobj ();
  }

  swipe_tracker::swipe_tracker (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  swipe_tracker::swipe_tracker (AdwSwipeTracker* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  swipe_tracker::swipe_tracker (swipe_tracker&& src) noexcept
    : glib::Object (std::move (src)),
      gtk::Orientable (std::move (src))
  {
  }

  auto
  swipe_tracker::operator= (swipe_tracker&& src) noexcept -> swipe_tracker&
  {
    glib::Object::operator= (std::move (src));
    gtk::Orientable::operator= (std::move (src));
    return *this;
  }

  swipe_tracker::~swipe_tracker () noexcept {}

  swipe_tracker::CppClassType swipe_tracker::swipetracker_class_;

  auto
  swipe_tracker::get_type () -> GType
  {
    return swipetracker_class_.init ().get_type ();
  }

  auto
  swipe_tracker::get_base_type () -> GType
  {
    return adw_swipe_tracker_get_type ();
  }

  swipe_tracker::swipe_tracker ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (swipetracker_class_.init ()))
  {
  }

  swipe_tracker::swipe_tracker (const glib::RefPtr<swipeable>& swipeable)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (swipetracker_class_.init (),
                                           "swipeable",
                                           glib::unwrap (swipeable),
                                           nullptr))
  {
  }

  auto
  swipe_tracker::create (const glib::RefPtr<swipeable>& swipeable) -> glib::RefPtr<swipe_tracker>
  {
    return glib::make_refptr_for_instance<swipe_tracker> (
        new swipe_tracker (swipeable));
  }

  auto
  swipe_tracker::get_allow_long_swipes () const -> bool
  {
    return adw_swipe_tracker_get_allow_long_swipes (
        const_cast<AdwSwipeTracker*> (gobj ()));
  }

  auto
  swipe_tracker::get_allow_mouse_drag () const -> bool
  {
    return adw_swipe_tracker_get_allow_mouse_drag (
        const_cast<AdwSwipeTracker*> (gobj ()));
  }

  auto
  swipe_tracker::get_enabled () const -> bool
  {
    return adw_swipe_tracker_get_enabled (
        const_cast<AdwSwipeTracker*> (gobj ()));
  }

  auto
  swipe_tracker::get_reversed () const -> bool
  {
    return adw_swipe_tracker_get_reversed (
        const_cast<AdwSwipeTracker*> (gobj ()));
  }

  auto
  swipe_tracker::get_swipeable () const -> glib::RefPtr<swipeable>
  {
    auto retvalue = glib::wrap (adw_swipe_tracker_get_swipeable (
        const_cast<AdwSwipeTracker*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  swipe_tracker::set_allow_long_swipes (bool allow_long_swipes) -> void
  {
    adw_swipe_tracker_set_allow_long_swipes (
        gobj (),
        static_cast<int> (allow_long_swipes));
  }

  auto
  swipe_tracker::set_allow_mouse_drag (bool allow_mouse_drag) -> void
  {
    adw_swipe_tracker_set_allow_mouse_drag (
        gobj (),
        static_cast<int> (allow_mouse_drag));
  }

  auto
  swipe_tracker::set_enabled (bool enabled) -> void
  {
    adw_swipe_tracker_set_enabled (gobj (), static_cast<int> (enabled));
  }

  auto
  swipe_tracker::set_reversed (bool enabled) -> void
  {
    adw_swipe_tracker_set_reversed (gobj (), static_cast<int> (enabled));
  }

  auto
  swipe_tracker::shift_position (double delta) -> void
  {
    adw_swipe_tracker_shift_position (gobj (), delta);
  }

  auto
  swipe_tracker::signal_begin_swipe () -> glib::SignalProxy<void ()>
  {
    return {this, &SwipeTracker_signal_begin_swipe_info};
  }

  auto
  swipe_tracker::signal_end_swipe () -> glib::SignalProxy<void (double, double)>
  {
    return {this, &SwipeTracker_signal_end_swipe_info};
  }

  auto
  swipe_tracker::signal_prepare () -> glib::SignalProxy<void (NavigationDirection)>
  {
    return {this, &SwipeTracker_signal_prepare_info};
  }

  auto
  swipe_tracker::signal_update_swipe () -> glib::SignalProxy<void (double)>
  {
    return {this, &SwipeTracker_signal_update_swipe_info};
  }

  auto
  swipe_tracker::property_allow_long_swipes () -> glib::PropertyProxy<bool>
  {
    return {this, "allow-long-swipes"};
  }

  auto
  swipe_tracker::property_allow_long_swipes () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "allow-long-swipes"};
  }

  auto
  swipe_tracker::property_allow_mouse_drag () -> glib::PropertyProxy<bool>
  {
    return {this, "allow-mouse-drag"};
  }

  auto
  swipe_tracker::property_allow_mouse_drag () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "allow-mouse-drag"};
  }

  auto
  swipe_tracker::property_enabled () -> glib::PropertyProxy<bool>
  {
    return {this, "enabled"};
  }

  auto
  swipe_tracker::property_enabled () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "enabled"};
  }

  auto
  swipe_tracker::property_reversed () -> glib::PropertyProxy<bool>
  {
    return {this, "reversed"};
  }

  auto
  swipe_tracker::property_reversed () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "reversed"};
  }

  auto
  swipe_tracker::property_swipeable () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<swipeable>>
  {
    return {this, "swipeable"};
  }

} // namespace adw
