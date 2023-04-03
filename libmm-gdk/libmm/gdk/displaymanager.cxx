// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/displaymanager.hxx>
#include <libmm/gdk/displaymanager_p.hxx>

#include <gdk/gdk.h>

namespace Gdk
{

}

namespace
{

  static auto
  DisplayManager_signal_display_opened_callback (GdkDisplayManager* self,
                                                 GdkDisplay* p0,
                                                 void* data) -> void
  {
    using namespace Gdk;
    using SlotType = sigc::slot<void (const Glib::RefPtr<Display>&)>;

    auto obj = dynamic_cast<DisplayManager*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo DisplayManager_signal_display_opened_info =
      {"display-opened",
       (GCallback) &DisplayManager_signal_display_opened_callback,
       (GCallback) &DisplayManager_signal_display_opened_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GdkDisplayManager* object, bool take_copy) -> Glib::RefPtr<Gdk::DisplayManager>
  {
    return Glib::make_refptr_for_instance<Gdk::DisplayManager> (
        dynamic_cast<Gdk::DisplayManager*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gdk
{

  auto
  DisplayManager_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &DisplayManager_Class::class_init_function;

      register_derived_type (gdk_display_manager_get_type ());
    }

    return *this;
  }

  auto
  DisplayManager_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  DisplayManager_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new DisplayManager ((GdkDisplayManager*) object);
  }

  auto
  DisplayManager::gobj_copy () -> GdkDisplayManager*
  {
    reference ();
    return gobj ();
  }

  DisplayManager::DisplayManager (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  DisplayManager::DisplayManager (GdkDisplayManager* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  DisplayManager::DisplayManager (DisplayManager&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  DisplayManager::operator= (DisplayManager&& src) noexcept -> DisplayManager&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  DisplayManager::~DisplayManager () noexcept {}

  DisplayManager::CppClassType DisplayManager::displaymanager_class_;

  auto
  DisplayManager::get_type () -> GType
  {
    return displaymanager_class_.init ().get_type ();
  }

  auto
  DisplayManager::get_base_type () -> GType
  {
    return gdk_display_manager_get_type ();
  }

  auto
  DisplayManager::get () -> Glib::RefPtr<DisplayManager>
  {
    auto retvalue = Glib::wrap (gdk_display_manager_get ());
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DisplayManager::get_default_display () -> Glib::RefPtr<Display>
  {
    auto retvalue =
        Glib::wrap (gdk_display_manager_get_default_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DisplayManager::get_default_display () const -> Glib::RefPtr<const Display>
  {
    return const_cast<DisplayManager*> (this)->get_default_display ();
  }

  auto
  DisplayManager::set_default_display (const Glib::RefPtr<Display>& display) -> void
  {
    gdk_display_manager_set_default_display (gobj (), Glib::unwrap (display));
  }

  auto
  DisplayManager::list_displays () -> std::vector<Glib::RefPtr<Display>>
  {
    return Glib::SListHandler<Glib::RefPtr<Display>>::slist_to_vector (
        gdk_display_manager_list_displays (gobj ()),
        Glib::OWNERSHIP_SHALLOW);
  }

  auto
  DisplayManager::open_display (const Glib::ustring& name) -> Glib::RefPtr<Display>
  {
    auto retvalue =
        Glib::wrap (gdk_display_manager_open_display (gobj (), name.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DisplayManager::signal_display_opened () -> Glib::SignalProxy<void (const Glib::RefPtr<Display>&)>
  {
    return Glib::SignalProxy<void (const Glib::RefPtr<Display>&)> (
        this,
        &DisplayManager_signal_display_opened_info);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Display>>::value,
      "Type Glib::RefPtr<Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  DisplayManager::property_default_display () -> Glib::PropertyProxy<Glib::RefPtr<Display>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Display>> (this, "default-display");
  }

  auto
  DisplayManager::property_default_display () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Display>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Display>> (
        this,
        "default-display");
  }

} // namespace Gdk
