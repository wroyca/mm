// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/swipetracker.hxx>
#include <libmm/adw/swipetracker_p.hxx>

#include <adwaita.h>
#include <libmm/glib/mm-glib.hxx>
#include <libmm/gtk/mm-gtk.hxx>

namespace Adw
{

}

namespace
{

  static const Glib::SignalProxyInfo SwipeTracker_signal_begin_swipe_info = {
      "begin-swipe",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  static auto
  SwipeTracker_signal_end_swipe_callback (AdwSwipeTracker* self,
                                          gdouble p0,
                                          gdouble p1,
                                          void* data) -> void
  {
    using namespace Adw;
    using SlotType = sigc::slot<void (double, double)>;

    auto obj = dynamic_cast<SwipeTracker*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0, p1);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo SwipeTracker_signal_end_swipe_info = {
      "end-swipe",
      (GCallback) &SwipeTracker_signal_end_swipe_callback,
      (GCallback) &SwipeTracker_signal_end_swipe_callback};

  static auto
  SwipeTracker_signal_prepare_callback (AdwSwipeTracker* self,
                                        AdwNavigationDirection p0,
                                        void* data) -> void
  {
    using namespace Adw;
    using SlotType = sigc::slot<void (NavigationDirection)>;

    auto obj = dynamic_cast<SwipeTracker*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              static_cast<NavigationDirection> (p0));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo SwipeTracker_signal_prepare_info = {
      "prepare",
      (GCallback) &SwipeTracker_signal_prepare_callback,
      (GCallback) &SwipeTracker_signal_prepare_callback};

  static auto
  SwipeTracker_signal_update_swipe_callback (AdwSwipeTracker* self,
                                             gdouble p0,
                                             void* data) -> void
  {
    using namespace Adw;
    using SlotType = sigc::slot<void (double)>;

    auto obj = dynamic_cast<SwipeTracker*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo SwipeTracker_signal_update_swipe_info = {
      "update-swipe",
      (GCallback) &SwipeTracker_signal_update_swipe_callback,
      (GCallback) &SwipeTracker_signal_update_swipe_callback};

} // namespace

namespace Glib
{

  auto
  wrap (AdwSwipeTracker* object, bool take_copy) -> Glib::RefPtr<Adw::SwipeTracker>
  {
    return Glib::make_refptr_for_instance<Adw::SwipeTracker> (
        dynamic_cast<Adw::SwipeTracker*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Adw
{

  auto
  SwipeTracker_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_swipe_tracker_get_type ();
    }

    return *this;
  }

  auto
  SwipeTracker_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new SwipeTracker ((AdwSwipeTracker*) object);
  }

  auto
  SwipeTracker::gobj_copy () -> AdwSwipeTracker*
  {
    reference ();
    return gobj ();
  }

  SwipeTracker::SwipeTracker (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  SwipeTracker::SwipeTracker (AdwSwipeTracker* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  SwipeTracker::SwipeTracker (SwipeTracker&& src) noexcept
    : Glib::Object (std::move (src)),
      Gtk::Orientable (std::move (src))
  {
  }

  auto
  SwipeTracker::operator= (SwipeTracker&& src) noexcept -> SwipeTracker&
  {
    Glib::Object::operator= (std::move (src));
    Gtk::Orientable::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (swipetracker_class_.init ()))
  {
  }

  SwipeTracker::SwipeTracker (const Glib::RefPtr<Swipeable>& swipeable)
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (swipetracker_class_.init (),
                                           "swipeable",
                                           Glib::unwrap (swipeable),
                                           nullptr))
  {
  }

  auto
  SwipeTracker::create (const Glib::RefPtr<Swipeable>& swipeable) -> Glib::RefPtr<SwipeTracker>
  {
    return Glib::make_refptr_for_instance<SwipeTracker> (
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
  SwipeTracker::get_swipeable () const -> Glib::RefPtr<Swipeable>
  {
    auto retvalue = Glib::wrap (adw_swipe_tracker_get_swipeable (
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
  SwipeTracker::signal_begin_swipe () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this,
                                       &SwipeTracker_signal_begin_swipe_info);
  }

  auto
  SwipeTracker::signal_end_swipe () -> Glib::SignalProxy<void (double, double)>
  {
    return Glib::SignalProxy<void (double, double)> (
        this,
        &SwipeTracker_signal_end_swipe_info);
  }

  auto
  SwipeTracker::signal_prepare () -> Glib::SignalProxy<void (NavigationDirection)>
  {
    return Glib::SignalProxy<void (NavigationDirection)> (
        this,
        &SwipeTracker_signal_prepare_info);
  }

  auto
  SwipeTracker::signal_update_swipe () -> Glib::SignalProxy<void (double)>
  {
    return Glib::SignalProxy<void (double)> (
        this,
        &SwipeTracker_signal_update_swipe_info);
  }

  auto
  SwipeTracker::property_allow_long_swipes () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "allow-long-swipes");
  }

  auto
  SwipeTracker::property_allow_long_swipes () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "allow-long-swipes");
  }

  auto
  SwipeTracker::property_allow_mouse_drag () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "allow-mouse-drag");
  }

  auto
  SwipeTracker::property_allow_mouse_drag () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "allow-mouse-drag");
  }

  auto
  SwipeTracker::property_enabled () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "enabled");
  }

  auto
  SwipeTracker::property_enabled () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "enabled");
  }

  auto
  SwipeTracker::property_reversed () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "reversed");
  }

  auto
  SwipeTracker::property_reversed () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "reversed");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Swipeable>>::value,
      "Type Glib::RefPtr<Swipeable> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  SwipeTracker::property_swipeable () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Swipeable>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Swipeable>> (this,
                                                                  "swipeable");
  }

} // namespace Adw
