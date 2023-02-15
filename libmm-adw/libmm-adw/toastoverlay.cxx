// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-adw/toastoverlay.hxx>
#include <libmm-adw/toastoverlay_p.hxx>

#include <libmm-gtk/mm-gtk.hxx>

namespace Adw
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (AdwToastOverlay* object, bool take_copy) -> Adw::ToastOverlay*
  {
    return dynamic_cast<Adw::ToastOverlay*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  ToastOverlay_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_toast_overlay_get_type ();
    }

    return *this;
  }

  auto
  ToastOverlay_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new ToastOverlay ((AdwToastOverlay*) (o)));
  }

  ToastOverlay::ToastOverlay (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  ToastOverlay::ToastOverlay (AdwToastOverlay* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  ToastOverlay::ToastOverlay (ToastOverlay&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  ToastOverlay::operator= (ToastOverlay&& src) noexcept -> ToastOverlay&
  {
    Gtk::Widget::operator= (std::move (src));
    return *this;
  }

  ToastOverlay::~ToastOverlay () noexcept
  {
    destroy_ ();
  }

  ToastOverlay::CppClassType ToastOverlay::toastoverlay_class_;

  auto
  ToastOverlay::get_type () -> GType
  {
    return toastoverlay_class_.init ().get_type ();
  }

  auto
  ToastOverlay::get_base_type () -> GType
  {
    return adw_toast_overlay_get_type ();
  }

  ToastOverlay::ToastOverlay ()
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (toastoverlay_class_.init ()))
  {
  }

  auto
  ToastOverlay::add_toast (Toast* toast) -> void
  {
    adw_toast_overlay_add_toast (gobj (), (AdwToast*) Glib::unwrap (toast));
  }

  auto
  ToastOverlay::get_child () const -> Gtk::Widget*
  {
    return Glib::wrap (
        adw_toast_overlay_get_child (const_cast<AdwToastOverlay*> (gobj ())));
  }

  auto
  ToastOverlay::set_child (Gtk::Widget* child) -> void
  {
    adw_toast_overlay_set_child (gobj (), (GtkWidget*) Glib::unwrap (child));
  }

  auto
  ToastOverlay::property_child () -> Glib::PropertyProxy<Gtk::Widget*>
  {
    return Glib::PropertyProxy<Gtk::Widget*> (this, "child");
  }

  auto
  ToastOverlay::property_child () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::Widget*> (this, "child");
  }

} // namespace Adw
