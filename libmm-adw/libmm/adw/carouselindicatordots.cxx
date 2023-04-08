// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/carouselindicatordots.hxx>
#include <libmm/adw/carouselindicatordots_p.hxx>

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
  wrap (AdwCarouselIndicatorDots* object, bool take_copy) -> adw::carousel_indicator_dots*
  {
    return dynamic_cast<adw::carousel_indicator_dots*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  carousel_indicator_dots_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_carousel_indicator_dots_get_type ();
    }

    return *this;
  }

  auto
  carousel_indicator_dots_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new carousel_indicator_dots ((AdwCarouselIndicatorDots*) (o)));
  }

  carousel_indicator_dots::carousel_indicator_dots (
      const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  carousel_indicator_dots::carousel_indicator_dots (
      AdwCarouselIndicatorDots* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  carousel_indicator_dots::carousel_indicator_dots (
      carousel_indicator_dots&& src) noexcept
    : gtk::Widget (std::move (src)),
      gtk::Orientable (std::move (src))
  {
  }

  auto
  carousel_indicator_dots::operator= (carousel_indicator_dots&& src) noexcept -> carousel_indicator_dots&
  {
    gtk::Widget::operator= (std::move (src));
    gtk::Orientable::operator= (std::move (src));
    return *this;
  }

  carousel_indicator_dots::~carousel_indicator_dots () noexcept
  {
    destroy_ ();
  }

  carousel_indicator_dots::CppClassType
      carousel_indicator_dots::carouselindicatordots_class_;

  auto
  carousel_indicator_dots::get_type () -> GType
  {
    return carouselindicatordots_class_.init ().get_type ();
  }

  auto
  carousel_indicator_dots::get_base_type () -> GType
  {
    return adw_carousel_indicator_dots_get_type ();
  }

  carousel_indicator_dots::carousel_indicator_dots ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (carouselindicatordots_class_.init ()))
  {
  }

  auto
  carousel_indicator_dots::get_carousel () const -> adw::carousel*
  {
    return glib::wrap (adw_carousel_indicator_dots_get_carousel (
        const_cast<AdwCarouselIndicatorDots*> (gobj ())));
  }

  auto
  carousel_indicator_dots::set_carousel (adw::carousel* carousel) -> void
  {
    adw_carousel_indicator_dots_set_carousel (
        gobj (),
        (AdwCarousel*) glib::unwrap (carousel));
  }

  auto
  carousel_indicator_dots::property_carousel () -> glib::PropertyProxy<adw::carousel*>
  {
    return {this, "carousel"};
  }

  auto
  carousel_indicator_dots::property_carousel () const -> glib::PropertyProxy_ReadOnly<adw::carousel*>
  {
    return {this, "carousel"};
  }

} // namespace adw
