// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/toastoverlay.hxx>
#include <libmm/adw/toastoverlay_p.hxx>

#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

}

namespace
{
}

namespace glib
{

  auto
  wrap (AdwToastOverlay* object, bool take_copy) -> adw::ToastOverlay*
  {
    return dynamic_cast<adw::ToastOverlay*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  ToastOverlay_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_toast_overlay_get_type ();
    }

    return *this;
  }

  auto
  ToastOverlay_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new ToastOverlay ((AdwToastOverlay*) (o)));
  }

  ToastOverlay::ToastOverlay (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  ToastOverlay::ToastOverlay (AdwToastOverlay* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  ToastOverlay::ToastOverlay (ToastOverlay&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  ToastOverlay::operator= (ToastOverlay&& src) noexcept -> ToastOverlay&
  {
    gtk::Widget::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (toastoverlay_class_.init ()))
  {
  }

  auto
  ToastOverlay::add_toast (Toast* toast) -> void
  {
    adw_toast_overlay_add_toast (gobj (), (AdwToast*) glib::unwrap (toast));
  }

  auto
  ToastOverlay::get_child () const -> gtk::Widget*
  {
    return glib::wrap (
        adw_toast_overlay_get_child (const_cast<AdwToastOverlay*> (gobj ())));
  }

  auto
  ToastOverlay::set_child (gtk::Widget* child) -> void
  {
    adw_toast_overlay_set_child (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  ToastOverlay::property_child () -> glib::PropertyProxy<gtk::Widget*>
  {
    return glib::PropertyProxy<gtk::Widget*> (this, "child");
  }

  auto
  ToastOverlay::property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return glib::PropertyProxy_ReadOnly<gtk::Widget*> (this, "child");
  }

} // namespace adw
