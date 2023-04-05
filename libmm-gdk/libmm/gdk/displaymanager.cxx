// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/displaymanager.hxx>
#include <libmm/gdk/displaymanager_p.hxx>

#include <gdk/gdk.h>

namespace gdk
{

}

namespace
{

  static auto
  DisplayManager_signal_display_opened_callback (GdkDisplayManager* self,
                                                 GdkDisplay* p0,
                                                 void* data) -> void
  {
    using namespace gdk;
    using SlotType = sigc::slot<void (const glib::RefPtr<Display>&)>;

    auto obj = dynamic_cast<DisplayManager*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo DisplayManager_signal_display_opened_info =
      {"display-opened",
       (GCallback) &DisplayManager_signal_display_opened_callback,
       (GCallback) &DisplayManager_signal_display_opened_callback};

} // namespace

namespace glib
{

  auto
  wrap (GdkDisplayManager* object, bool take_copy) -> glib::RefPtr<gdk::DisplayManager>
  {
    return glib::make_refptr_for_instance<gdk::DisplayManager> (
        dynamic_cast<gdk::DisplayManager*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gdk
{

  auto
  DisplayManager_Class::init () -> const glib::Class&
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
  DisplayManager_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new DisplayManager ((GdkDisplayManager*) object);
  }

  auto
  DisplayManager::gobj_copy () -> GdkDisplayManager*
  {
    reference ();
    return gobj ();
  }

  DisplayManager::DisplayManager (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  DisplayManager::DisplayManager (GdkDisplayManager* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  DisplayManager::DisplayManager (DisplayManager&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  DisplayManager::operator= (DisplayManager&& src) noexcept -> DisplayManager&
  {
    glib::Object::operator= (std::move (src));
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
  DisplayManager::get () -> glib::RefPtr<DisplayManager>
  {
    auto retvalue = glib::wrap (gdk_display_manager_get ());
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DisplayManager::get_default_display () -> glib::RefPtr<Display>
  {
    auto retvalue =
        glib::wrap (gdk_display_manager_get_default_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DisplayManager::get_default_display () const -> glib::RefPtr<const Display>
  {
    return const_cast<DisplayManager*> (this)->get_default_display ();
  }

  auto
  DisplayManager::set_default_display (const glib::RefPtr<Display>& display) -> void
  {
    gdk_display_manager_set_default_display (gobj (), glib::unwrap (display));
  }

  auto
  DisplayManager::list_displays () -> std::vector<glib::RefPtr<Display>>
  {
    return glib::SListHandler<glib::RefPtr<Display>>::slist_to_vector (
        gdk_display_manager_list_displays (gobj ()),
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  DisplayManager::open_display (const glib::ustring& name) -> glib::RefPtr<Display>
  {
    auto retvalue =
        glib::wrap (gdk_display_manager_open_display (gobj (), name.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DisplayManager::signal_display_opened () -> glib::SignalProxy<void (const glib::RefPtr<Display>&)>
  {
    return glib::SignalProxy<void (const glib::RefPtr<Display>&)> (
        this,
        &DisplayManager_signal_display_opened_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Display>>::value,
      "Type glib::RefPtr<Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  DisplayManager::property_default_display () -> glib::PropertyProxy<glib::RefPtr<Display>>
  {
    return glib::PropertyProxy<glib::RefPtr<Display>> (this, "default-display");
  }

  auto
  DisplayManager::property_default_display () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>> (
        this,
        "default-display");
  }

} // namespace gdk
