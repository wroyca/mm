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

    auto obj = dynamic_cast<SwipeTracker*> (
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

    auto obj = dynamic_cast<SwipeTracker*> (
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

    auto obj = dynamic_cast<SwipeTracker*> (
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
  wrap (AdwSwipeTracker* object, bool take_copy) -> glib::RefPtr<adw::SwipeTracker>
  {
    return glib::make_refptr_for_instance<adw::SwipeTracker> (
        dynamic_cast<adw::SwipeTracker*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  SwipeTracker_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_swipe_tracker_get_type ();
    }

    return *this;
  }

  auto
  SwipeTracker_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new SwipeTracker ((AdwSwipeTracker*) object);
  }

  auto
  SwipeTracker::gobj_copy () -> AdwSwipeTracker*
  {
    reference ();
    return gobj ();
  }

  SwipeTracker::SwipeTracker (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  SwipeTracker::SwipeTracker (AdwSwipeTracker* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  SwipeTracker::SwipeTracker (SwipeTracker&& src) noexcept
    : glib::Object (std::move (src)),
      gtk::Orientable (std::move (src))
  {
  }

  auto
  SwipeTracker::operator= (SwipeTracker&& src) noexcept -> SwipeTracker&
  {
    glib::Object::operator= (std::move (src));
    gtk::Orientable::operator= (std::move (src));
    return *this;
  }

  SwipeTracker::~SwipeTracker () noexcept {}

  SwipeTracker::CppClassType SwipeTracker::swipetracker_class_;

  auto
  SwipeTracker::get_type () -> GType
  {
    return swipetracker_class_.init ().get_type ();
  }

  auto
  SwipeTracker::get_base_type () -> GType
  {
    return adw_swipe_tracker_get_type ();
  }

  SwipeTracker::SwipeTracker ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (swipetracker_class_.init ()))
  {
  }

  SwipeTracker::SwipeTracker (const glib::RefPtr<Swipeable>& swipeable)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (swipetracker_class_.init (),
                                           "swipeable",
                                           glib::unwrap (swipeable),
                                           nullptr))
  {
  }

  auto
  SwipeTracker::create (const glib::RefPtr<Swipeable>& swipeable) -> glib::RefPtr<SwipeTracker>
  {
    return glib::make_refptr_for_instance<SwipeTracker> (
        new SwipeTracker (swipeable));
  }

  auto
  SwipeTracker::get_allow_long_swipes () const -> bool
  {
    return adw_swipe_tracker_get_allow_long_swipes (
        const_cast<AdwSwipeTracker*> (gobj ()));
  }

  auto
  SwipeTracker::get_allow_mouse_drag () const -> bool
  {
    return adw_swipe_tracker_get_allow_mouse_drag (
        const_cast<AdwSwipeTracker*> (gobj ()));
  }

  auto
  SwipeTracker::get_enabled () const -> bool
  {
    return adw_swipe_tracker_get_enabled (
        const_cast<AdwSwipeTracker*> (gobj ()));
  }

  auto
  SwipeTracker::get_reversed () const -> bool
  {
    return adw_swipe_tracker_get_reversed (
        const_cast<AdwSwipeTracker*> (gobj ()));
  }

  auto
  SwipeTracker::get_swipeable () const -> glib::RefPtr<Swipeable>
  {
    auto retvalue = glib::wrap (adw_swipe_tracker_get_swipeable (
        const_cast<AdwSwipeTracker*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  SwipeTracker::set_allow_long_swipes (bool allow_long_swipes) -> void
  {
    adw_swipe_tracker_set_allow_long_swipes (
        gobj (),
        static_cast<int> (allow_long_swipes));
  }

  auto
  SwipeTracker::set_allow_mouse_drag (bool allow_mouse_drag) -> void
  {
    adw_swipe_tracker_set_allow_mouse_drag (
        gobj (),
        static_cast<int> (allow_mouse_drag));
  }

  auto
  SwipeTracker::set_enabled (bool enabled) -> void
  {
    adw_swipe_tracker_set_enabled (gobj (), static_cast<int> (enabled));
  }

  auto
  SwipeTracker::set_reversed (bool enabled) -> void
  {
    adw_swipe_tracker_set_reversed (gobj (), static_cast<int> (enabled));
  }

  auto
  SwipeTracker::shift_position (double delta) -> void
  {
    adw_swipe_tracker_shift_position (gobj (), delta);
  }

  auto
  SwipeTracker::signal_begin_swipe () -> glib::SignalProxy<void ()>
  {
    return {this, &SwipeTracker_signal_begin_swipe_info};
  }

  auto
  SwipeTracker::signal_end_swipe () -> glib::SignalProxy<void (double, double)>
  {
    return {this, &SwipeTracker_signal_end_swipe_info};
  }

  auto
  SwipeTracker::signal_prepare () -> glib::SignalProxy<void (NavigationDirection)>
  {
    return {this, &SwipeTracker_signal_prepare_info};
  }

  auto
  SwipeTracker::signal_update_swipe () -> glib::SignalProxy<void (double)>
  {
    return {this, &SwipeTracker_signal_update_swipe_info};
  }

  auto
  SwipeTracker::property_allow_long_swipes () -> glib::PropertyProxy<bool>
  {
    return {this, "allow-long-swipes"};
  }

  auto
  SwipeTracker::property_allow_long_swipes () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "allow-long-swipes"};
  }

  auto
  SwipeTracker::property_allow_mouse_drag () -> glib::PropertyProxy<bool>
  {
    return {this, "allow-mouse-drag"};
  }

  auto
  SwipeTracker::property_allow_mouse_drag () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "allow-mouse-drag"};
  }

  auto
  SwipeTracker::property_enabled () -> glib::PropertyProxy<bool>
  {
    return {this, "enabled"};
  }

  auto
  SwipeTracker::property_enabled () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "enabled"};
  }

  auto
  SwipeTracker::property_reversed () -> glib::PropertyProxy<bool>
  {
    return {this, "reversed"};
  }

  auto
  SwipeTracker::property_reversed () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "reversed"};
  }

  auto
  SwipeTracker::property_swipeable () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Swipeable>>
  {
    return {this, "swipeable"};
  }

} // namespace adw
