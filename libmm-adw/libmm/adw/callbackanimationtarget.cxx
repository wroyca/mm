// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/callbackanimationtarget.hxx>
#include <libmm/adw/callbackanimationtarget_p.hxx>

#include <adwaita.h>
#include <libmm/glib/mm-glib.hxx>

namespace adw
{
  auto
  callback_animation_target::callback_function (double value, gpointer user_data) -> void
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

  callback_animation_target::callback_animation_target (
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
  wrap (AdwCallbackAnimationTarget* object, bool take_copy) -> glib::RefPtr<adw::callback_animation_target>
  {
    return glib::make_refptr_for_instance<adw::callback_animation_target> (
        dynamic_cast<adw::callback_animation_target*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  callback_animation_target_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_callback_animation_target_get_type ();
    }

    return *this;
  }

  auto
  callback_animation_target_class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new callback_animation_target ((AdwCallbackAnimationTarget*) object);
  }

  auto
  callback_animation_target::gobj_copy () -> AdwCallbackAnimationTarget*
  {
    reference ();
    return gobj ();
  }

  callback_animation_target::callback_animation_target (
      const glib::ConstructParams& construct_params)
    : adw::AnimationTarget (construct_params)
  {
  }

  callback_animation_target::callback_animation_target (
      AdwCallbackAnimationTarget* castitem)
    : adw::AnimationTarget ((AdwAnimationTarget*) (castitem))
  {
  }

  callback_animation_target::callback_animation_target (
      callback_animation_target&& src) noexcept
    : adw::AnimationTarget (std::move (src))
  {
  }

  auto
  callback_animation_target::operator= (callback_animation_target&& src) noexcept -> callback_animation_target&
  {
    adw::AnimationTarget::operator= (std::move (src));
    return *this;
  }

  callback_animation_target::~callback_animation_target () noexcept {}

  callback_animation_target::CppClassType
      callback_animation_target::callbackanimationtarget_class_;

  auto
  callback_animation_target::get_type () -> GType
  {
    return callbackanimationtarget_class_.init ().get_type ();
  }

  auto
  callback_animation_target::get_base_type () -> GType
  {
    return adw_callback_animation_target_get_type ();
  }

  callback_animation_target::callback_animation_target ()
    : glib::ObjectBase (nullptr),
      adw::AnimationTarget (
          glib::ConstructParams (callbackanimationtarget_class_.init ()))
  {
  }

  auto
  callback_animation_target::create (const SlotTarget& slot_target) -> glib::RefPtr<callback_animation_target>
  {
    return glib::make_refptr_for_instance<callback_animation_target> (
        new callback_animation_target (slot_target));
  }

} // namespace adw
