// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/popup.hxx>
#include <libmm-gdk/popup_p.hxx>

#include <gdk/gdk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GdkPopup* object, bool take_copy) -> Glib::RefPtr<Gdk::Popup>
  {
    return Glib::make_refptr_for_instance<Gdk::Popup> (
        dynamic_cast<Gdk::Popup*> (
            Glib::wrap_auto_interface<Gdk::Popup> ((GObject*) (object),
                                                   take_copy)));
  }

} // namespace Glib

namespace Gdk
{

  auto
  Popup_Class::init () -> const Glib::Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Popup_Class::iface_init_function;

      gtype_ = gdk_popup_get_type ();
    }

    return *this;
  }

  auto
  Popup_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);
  }

  auto
  Popup_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Popup ((GdkPopup*) (object));
  }

  Popup::Popup ()
    : Glib::Interface (popup_class_.init ())
  {
  }

  Popup::Popup (GdkPopup* castitem)
    : Glib::Interface ((GObject*) (castitem))
  {
  }

  Popup::Popup (const Glib::Interface_Class& interface_class)
    : Glib::Interface (interface_class)
  {
  }

  Popup::Popup (Popup&& src) noexcept
    : Glib::Interface (std::move (src))
  {
  }

  auto
  Popup::operator= (Popup&& src) noexcept -> Popup&
  {
    Glib::Interface::operator= (std::move (src));
    return *this;
  }

  Popup::~Popup () noexcept {}

  auto
  Popup::add_interface (GType gtype_implementer) -> void
  {
    popup_class_.init ().add_interface (gtype_implementer);
  }

  Popup::CppClassType Popup::popup_class_;

  auto
  Popup::get_type () -> GType
  {
    return popup_class_.init ().get_type ();
  }

  auto
  Popup::get_base_type () -> GType
  {
    return gdk_popup_get_type ();
  }

  auto
  Popup::present (int width,
                  int height,
                  const Glib::RefPtr<PopupLayout>& layout) -> bool
  {
    return gdk_popup_present (gobj (), width, height, Glib::unwrap (layout));
  }

  auto
  Popup::get_surface_anchor () const -> Gravity
  {
    return static_cast<Gravity> (
        gdk_popup_get_surface_anchor (const_cast<GdkPopup*> (gobj ())));
  }

  auto
  Popup::get_rect_anchor () const -> Gravity
  {
    return static_cast<Gravity> (
        gdk_popup_get_rect_anchor (const_cast<GdkPopup*> (gobj ())));
  }

  auto
  Popup::get_parent () -> Glib::RefPtr<Surface>
  {
    auto retvalue = Glib::wrap (gdk_popup_get_parent (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Popup::get_parent () const -> Glib::RefPtr<const Surface>
  {
    return const_cast<Popup*> (this)->get_parent ();
  }

  auto
  Popup::get_position_x () const -> int
  {
    return gdk_popup_get_position_x (const_cast<GdkPopup*> (gobj ()));
  }

  auto
  Popup::get_position_y () const -> int
  {
    return gdk_popup_get_position_y (const_cast<GdkPopup*> (gobj ()));
  }

  auto
  Popup::get_autohide () const -> bool
  {
    return gdk_popup_get_autohide (const_cast<GdkPopup*> (gobj ()));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Surface>>::value,
      "Type Glib::RefPtr<Surface> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Popup::property_parent () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Surface>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Surface>> (this, "parent");
  }

  auto
  Popup::property_autohide () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "autohide");
  }

} // namespace Gdk
