// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/popup.hxx>
#include <libmm/gdk/popup_p.hxx>

#include <gdk/gdk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GdkPopup* object, bool take_copy) -> glib::RefPtr<gdk::Popup>
  {
    return glib::make_refptr_for_instance<gdk::Popup> (
        dynamic_cast<gdk::Popup*> (
            glib::wrap_auto_interface<gdk::Popup> ((GObject*) (object),
                                                   take_copy)));
  }

} // namespace glib

namespace gdk
{

  auto
  Popup_Class::init () -> const glib::Interface_Class&
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
  Popup_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Popup ((GdkPopup*) (object));
  }

  Popup::Popup ()
    : glib::Interface (popup_class_.init ())
  {
  }

  Popup::Popup (GdkPopup* castitem)
    : glib::Interface ((GObject*) (castitem))
  {
  }

  Popup::Popup (const glib::Interface_Class& interface_class)
    : glib::Interface (interface_class)
  {
  }

  Popup::Popup (Popup&& src) noexcept
    : glib::Interface (std::move (src))
  {
  }

  auto
  Popup::operator= (Popup&& src) noexcept -> Popup&
  {
    glib::Interface::operator= (std::move (src));
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
                  const glib::RefPtr<PopupLayout>& layout) -> bool
  {
    return gdk_popup_present (gobj (), width, height, glib::unwrap (layout));
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
  Popup::get_parent () -> glib::RefPtr<Surface>
  {
    auto retvalue = glib::wrap (gdk_popup_get_parent (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Popup::get_parent () const -> glib::RefPtr<const Surface>
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
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Surface>>::value,
      "Type glib::RefPtr<Surface> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Popup::property_parent () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Surface>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Surface>> (this, "parent");
  }

  auto
  Popup::property_autohide () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "autohide");
  }

} // namespace gdk
