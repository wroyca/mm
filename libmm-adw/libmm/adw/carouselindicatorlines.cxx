// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/carouselindicatorlines.hxx>
#include <libmm/adw/carouselindicatorlines_p.hxx>

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
  wrap (AdwCarouselIndicatorLines* object, bool take_copy) -> adw::CarouselIndicatorLines*
  {
    return dynamic_cast<adw::CarouselIndicatorLines*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  CarouselIndicatorLines_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_carousel_indicator_lines_get_type ();
    }

    return *this;
  }

  auto
  CarouselIndicatorLines_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (
        new CarouselIndicatorLines ((AdwCarouselIndicatorLines*) (o)));
  }

  CarouselIndicatorLines::CarouselIndicatorLines (
      const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  CarouselIndicatorLines::CarouselIndicatorLines (
      AdwCarouselIndicatorLines* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  CarouselIndicatorLines::CarouselIndicatorLines (
      CarouselIndicatorLines&& src) noexcept
    : gtk::Widget (std::move (src)),
      gtk::Orientable (std::move (src))
  {
  }

  auto
  CarouselIndicatorLines::operator= (CarouselIndicatorLines&& src) noexcept -> CarouselIndicatorLines&
  {
    gtk::Widget::operator= (std::move (src));
    gtk::Orientable::operator= (std::move (src));
    return *this;
  }

  CarouselIndicatorLines::~CarouselIndicatorLines () noexcept
  {
    destroy_ ();
  }

  CarouselIndicatorLines::CppClassType
      CarouselIndicatorLines::carouselindicatorlines_class_;

  auto
  CarouselIndicatorLines::get_type () -> GType
  {
    return carouselindicatorlines_class_.init ().get_type ();
  }

  auto
  CarouselIndicatorLines::get_base_type () -> GType
  {
    return adw_carousel_indicator_lines_get_type ();
  }

  CarouselIndicatorLines::CarouselIndicatorLines ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (
          glib::ConstructParams (carouselindicatorlines_class_.init ()))
  {
  }

  auto
  CarouselIndicatorLines::get_carousel () const -> adw::Carousel*
  {
    return glib::wrap (adw_carousel_indicator_lines_get_carousel (
        const_cast<AdwCarouselIndicatorLines*> (gobj ())));
  }

  auto
  CarouselIndicatorLines::set_carousel (adw::Carousel* carousel) -> void
  {
    adw_carousel_indicator_lines_set_carousel (
        gobj (),
        (AdwCarousel*) glib::unwrap (carousel));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<adw::Carousel*>::value,
      "Type adw::Carousel* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CarouselIndicatorLines::property_carousel () -> glib::PropertyProxy<adw::Carousel*>
  {
    return glib::PropertyProxy<adw::Carousel*> (this, "carousel");
  }

  auto
  CarouselIndicatorLines::property_carousel () const -> glib::PropertyProxy_ReadOnly<adw::Carousel*>
  {
    return glib::PropertyProxy_ReadOnly<adw::Carousel*> (this, "carousel");
  }

} // namespace adw
