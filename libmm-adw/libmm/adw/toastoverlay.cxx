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
  wrap (AdwToastOverlay* object, bool take_copy) -> adw::toast_overlay*
  {
    return dynamic_cast<adw::toast_overlay*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  toast_overlay_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_toast_overlay_get_type ();
    }

    return *this;
  }

  auto
  toast_overlay_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new toast_overlay ((AdwToastOverlay*) (o)));
  }

  toast_overlay::toast_overlay (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  toast_overlay::toast_overlay (AdwToastOverlay* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  toast_overlay::toast_overlay (toast_overlay&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  toast_overlay::operator= (toast_overlay&& src) noexcept -> toast_overlay&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  toast_overlay::~toast_overlay () noexcept
  {
    destroy_ ();
  }

  toast_overlay::CppClassType toast_overlay::toastoverlay_class_;

  auto
  toast_overlay::get_type () -> GType
  {
    return toastoverlay_class_.init ().get_type ();
  }

  auto
  toast_overlay::get_base_type () -> GType
  {
    return adw_toast_overlay_get_type ();
  }

  toast_overlay::toast_overlay ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (toastoverlay_class_.init ()))
  {
  }

  auto
  toast_overlay::add_toast (toast* toast) -> void
  {
    adw_toast_overlay_add_toast (gobj (), (AdwToast*) glib::unwrap (toast));
  }

  auto
  toast_overlay::get_child () const -> gtk::Widget*
  {
    return glib::wrap (
        adw_toast_overlay_get_child (const_cast<AdwToastOverlay*> (gobj ())));
  }

  auto
  toast_overlay::set_child (gtk::Widget* child) -> void
  {
    adw_toast_overlay_set_child (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  toast_overlay::property_child () -> glib::PropertyProxy<gtk::Widget*>
  {
    return {this, "child"};
  }

  auto
  toast_overlay::property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "child"};
  }

} // namespace adw
