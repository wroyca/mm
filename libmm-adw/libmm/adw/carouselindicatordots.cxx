// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/carouselindicatordots.hxx>
#include <libmm/adw/carouselindicatordots_p.hxx>

#include <libmm/gtk/mm-gtk.hxx>

namespace Adw
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (AdwCarouselIndicatorDots* object, bool take_copy) -> Adw::CarouselIndicatorDots*
  {
    return dynamic_cast<Adw::CarouselIndicatorDots*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  CarouselIndicatorDots_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_carousel_indicator_dots_get_type ();
    }

    return *this;
  }

  auto
  CarouselIndicatorDots_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new CarouselIndicatorDots ((AdwCarouselIndicatorDots*) (o)));
  }

  CarouselIndicatorDots::CarouselIndicatorDots (
      const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  CarouselIndicatorDots::CarouselIndicatorDots (
      AdwCarouselIndicatorDots* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  CarouselIndicatorDots::CarouselIndicatorDots (
      CarouselIndicatorDots&& src) noexcept
    : Gtk::Widget (std::move (src)),
      Gtk::Orientable (std::move (src))
  {
  }

  auto
  CarouselIndicatorDots::operator= (CarouselIndicatorDots&& src) noexcept -> CarouselIndicatorDots&
  {
    Gtk::Widget::operator= (std::move (src));
    Gtk::Orientable::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (carouselindicatordots_class_.init ()))
  {
  }

  auto
  CarouselIndicatorDots::get_carousel () const -> Adw::Carousel*
  {
    return Glib::wrap (adw_carousel_indicator_dots_get_carousel (
        const_cast<AdwCarouselIndicatorDots*> (gobj ())));
  }

  auto
  CarouselIndicatorDots::set_carousel (Adw::Carousel* carousel) -> void
  {
    adw_carousel_indicator_dots_set_carousel (
        gobj (),
        (AdwCarousel*) Glib::unwrap (carousel));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Adw::Carousel*>::value,
      "Type Adw::Carousel* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  CarouselIndicatorDots::property_carousel () -> Glib::PropertyProxy<Adw::Carousel*>
  {
    return Glib::PropertyProxy<Adw::Carousel*> (this, "carousel");
  }

  auto
  CarouselIndicatorDots::property_carousel () const -> Glib::PropertyProxy_ReadOnly<Adw::Carousel*>
  {
    return Glib::PropertyProxy_ReadOnly<Adw::Carousel*> (this, "carousel");
  }

} // namespace Adw
