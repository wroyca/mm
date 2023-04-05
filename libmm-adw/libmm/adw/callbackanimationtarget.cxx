// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/callbackanimationtarget.hxx>
#include <libmm/adw/callbackanimationtarget_p.hxx>

#include <adwaita.h>
#include <libmm/glib/mm-glib.hxx>

namespace adw
{
  auto
  CallbackAnimationTarget::callback_function (double value, gpointer user_data) -> void
  {
    auto the_slot = static_cast<SlotTarget*> (user_data);
    try
    {
      (*the_slot) (value);
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
    }
  }

  CallbackAnimationTarget::CallbackAnimationTarget (
      const SlotTarget& slot_target)
  {
    auto slot_copy = new SlotTarget (slot_target);

    gobject_ = G_OBJECT (adw_callback_animation_target_new (
        callback_function,
        slot_copy,
        glib::destroy_notify_delete<SlotTarget>));
  }

} // namespace adw

namespace
{
}

namespace glib
{

  auto
  wrap (AdwCallbackAnimationTarget* object, bool take_copy) -> glib::RefPtr<adw::CallbackAnimationTarget>
  {
    return glib::make_refptr_for_instance<adw::CallbackAnimationTarget> (
        dynamic_cast<adw::CallbackAnimationTarget*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  CallbackAnimationTarget_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_callback_animation_target_get_type ();
    }

    return *this;
  }

  auto
  CallbackAnimationTarget_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new CallbackAnimationTarget ((AdwCallbackAnimationTarget*) object);
  }

  auto
  CallbackAnimationTarget::gobj_copy () -> AdwCallbackAnimationTarget*
  {
    reference ();
    return gobj ();
  }

  CallbackAnimationTarget::CallbackAnimationTarget (
      const glib::ConstructParams& construct_params)
    : adw::AnimationTarget (construct_params)
  {
  }

  CallbackAnimationTarget::CallbackAnimationTarget (
      AdwCallbackAnimationTarget* castitem)
    : adw::AnimationTarget ((AdwAnimationTarget*) (castitem))
  {
  }

  CallbackAnimationTarget::CallbackAnimationTarget (
      CallbackAnimationTarget&& src) noexcept
    : adw::AnimationTarget (std::move (src))
  {
  }

  auto
  CallbackAnimationTarget::operator= (CallbackAnimationTarget&& src) noexcept -> CallbackAnimationTarget&
  {
    adw::AnimationTarget::operator= (std::move (src));
    return *this;
  }

  CallbackAnimationTarget::~CallbackAnimationTarget () noexcept {}

  CallbackAnimationTarget::CppClassType
      CallbackAnimationTarget::callbackanimationtarget_class_;

  auto
  CallbackAnimationTarget::get_type () -> GType
  {
    return callbackanimationtarget_class_.init ().get_type ();
  }

  auto
  CallbackAnimationTarget::get_base_type () -> GType
  {
    return adw_callback_animation_target_get_type ();
  }

  CallbackAnimationTarget::CallbackAnimationTarget ()
    : glib::ObjectBase (nullptr),
      adw::AnimationTarget (
          glib::ConstructParams (callbackanimationtarget_class_.init ()))
  {
  }

  auto
  CallbackAnimationTarget::create (const SlotTarget& slot_target) -> glib::RefPtr<CallbackAnimationTarget>
  {
    return glib::make_refptr_for_instance<CallbackAnimationTarget> (
        new CallbackAnimationTarget (slot_target));
  }

} // namespace adw
