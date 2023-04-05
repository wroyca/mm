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
  wrap (AdwCarouselIndicatorDots* object, bool take_copy) -> adw::CarouselIndicatorDots*
  {
    return dynamic_cast<adw::CarouselIndicatorDots*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  CarouselIndicatorDots_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_carousel_indicator_dots_get_type ();
    }

    return *this;
  }

  auto
  CarouselIndicatorDots_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new CarouselIndicatorDots ((AdwCarouselIndicatorDots*) (o)));
  }

  CarouselIndicatorDots::CarouselIndicatorDots (
      const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  CarouselIndicatorDots::CarouselIndicatorDots (
      AdwCarouselIndicatorDots* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  CarouselIndicatorDots::CarouselIndicatorDots (
      CarouselIndicatorDots&& src) noexcept
    : gtk::Widget (std::move (src)),
      gtk::Orientable (std::move (src))
  {
  }

  auto
  CarouselIndicatorDots::operator= (CarouselIndicatorDots&& src) noexcept -> CarouselIndicatorDots&
  {
    gtk::Widget::operator= (std::move (src));
    gtk::Orientable::operator= (std::move (src));
    return *this;
  }

  CarouselIndicatorDots::~CarouselIndicatorDots () noexcept
  {
    destroy_ ();
  }

  CarouselIndicatorDots::CppClassType
      CarouselIndicatorDots::carouselindicatordots_class_;

  auto
  CarouselIndicatorDots::get_type () -> GType
  {
    return carouselindicatordots_class_.init ().get_type ();
  }

  auto
  CarouselIndicatorDots::get_base_type () -> GType
  {
    return adw_carousel_indicator_dots_get_type ();
  }

  CarouselIndicatorDots::CarouselIndicatorDots ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (carouselindicatordots_class_.init ()))
  {
  }

  auto
  CarouselIndicatorDots::get_carousel () const -> adw::Carousel*
  {
    return glib::wrap (adw_carousel_indicator_dots_get_carousel (
        const_cast<AdwCarouselIndicatorDots*> (gobj ())));
  }

  auto
  CarouselIndicatorDots::set_carousel (adw::Carousel* carousel) -> void
  {
    adw_carousel_indicator_dots_set_carousel (
        gobj (),
        (AdwCarousel*) glib::unwrap (carousel));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<adw::Carousel*>::value,
      "Type adw::Carousel* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CarouselIndicatorDots::property_carousel () -> glib::PropertyProxy<adw::Carousel*>
  {
    return glib::PropertyProxy<adw::Carousel*> (this, "carousel");
  }

  auto
  CarouselIndicatorDots::property_carousel () const -> glib::PropertyProxy_ReadOnly<adw::Carousel*>
  {
    return glib::PropertyProxy_ReadOnly<adw::Carousel*> (this, "carousel");
  }

} // namespace adw
