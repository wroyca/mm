// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-adw/callbackanimationtarget.hxx>
#include <libmm-adw/callbackanimationtarget_p.hxx>

#include <adwaita.h>
#include <libmm-glib/mm-glib.hxx>

namespace Adw
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
      Glib::exception_handlers_invoke ();
    }
  }

  CallbackAnimationTarget::CallbackAnimationTarget (
      const SlotTarget& slot_target)
  {
    auto slot_copy = new SlotTarget (slot_target);

    gobject_ = G_OBJECT (adw_callback_animation_target_new (
        callback_function,
        slot_copy,
        Glib::destroy_notify_delete<SlotTarget>));
  }

} // namespace Adw

namespace
{
}

namespace Glib
{

  auto
  wrap (AdwCallbackAnimationTarget* object, bool take_copy) -> Glib::RefPtr<Adw::CallbackAnimationTarget>
  {
    return Glib::make_refptr_for_instance<Adw::CallbackAnimationTarget> (
        dynamic_cast<Adw::CallbackAnimationTarget*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Adw
{

  auto
  CallbackAnimationTarget_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_callback_animation_target_get_type ();
    }

    return *this;
  }

  auto
  CallbackAnimationTarget_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
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
      const Glib::ConstructParams& construct_params)
    : Adw::AnimationTarget (construct_params)
  {
  }

  CallbackAnimationTarget::CallbackAnimationTarget (
      AdwCallbackAnimationTarget* castitem)
    : Adw::AnimationTarget ((AdwAnimationTarget*) (castitem))
  {
  }

  CallbackAnimationTarget::CallbackAnimationTarget (
      CallbackAnimationTarget&& src) noexcept
    : Adw::AnimationTarget (std::move (src))
  {
  }

  auto
  CallbackAnimationTarget::operator= (CallbackAnimationTarget&& src) noexcept -> CallbackAnimationTarget&
  {
    Adw::AnimationTarget::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Adw::AnimationTarget (
          Glib::ConstructParams (callbackanimationtarget_class_.init ()))
  {
  }

  auto
  CallbackAnimationTarget::create (const SlotTarget& slot_target) -> Glib::RefPtr<CallbackAnimationTarget>
  {
    return Glib::make_refptr_for_instance<CallbackAnimationTarget> (
        new CallbackAnimationTarget (slot_target));
  }

} // namespace Adw
