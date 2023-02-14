

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
  wrap (GdkPopup* object, const bool take_copy) -> RefPtr<Gdk::Popup>
  {
    return Glib::make_refptr_for_instance<Gdk::Popup> (
        Glib::wrap_auto_interface<Gdk::Popup> ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gdk
{

  auto
  Popup_Class::init () -> const Interface_Class&
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
    return new Popup ((GdkPopup*) object);
  }

  Popup::Popup ()
    : Interface (popup_class_.init ())
  {
  }

  Popup::Popup (GdkPopup* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  Popup::Popup (const Glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  Popup::Popup (Popup&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  Popup::operator= (Popup&& src) noexcept -> Popup&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  Popup::~Popup () noexcept = default;

  auto
  Popup::add_interface (const GType gtype_implementer) -> void
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
  Popup::present (const int width,
                  const int height,
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
    return {this, "parent"};
  }

  auto
  Popup::property_autohide () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "autohide"};
  }

} // namespace Gdk
