// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/carouselindicatorlines.hxx>
#include <libmm/adw/carouselindicatorlines_p.hxx>

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
  wrap (AdwCarouselIndicatorLines* object, bool take_copy) -> Adw::CarouselIndicatorLines*
  {
    return dynamic_cast<Adw::CarouselIndicatorLines*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  CarouselIndicatorLines_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_carousel_indicator_lines_get_type ();
    }

    return *this;
  }

  auto
  CarouselIndicatorLines_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (
        new CarouselIndicatorLines ((AdwCarouselIndicatorLines*) (o)));
  }

  CarouselIndicatorLines::CarouselIndicatorLines (
      const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  CarouselIndicatorLines::CarouselIndicatorLines (
      AdwCarouselIndicatorLines* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  CarouselIndicatorLines::CarouselIndicatorLines (
      CarouselIndicatorLines&& src) noexcept
    : Gtk::Widget (std::move (src)),
      Gtk::Orientable (std::move (src))
  {
  }

  auto
  CarouselIndicatorLines::operator= (CarouselIndicatorLines&& src) noexcept -> CarouselIndicatorLines&
  {
    Gtk::Widget::operator= (std::move (src));
    Gtk::Orientable::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (
          Glib::ConstructParams (carouselindicatorlines_class_.init ()))
  {
  }

  auto
  CarouselIndicatorLines::get_carousel () const -> Adw::Carousel*
  {
    return Glib::wrap (adw_carousel_indicator_lines_get_carousel (
        const_cast<AdwCarouselIndicatorLines*> (gobj ())));
  }

  auto
  CarouselIndicatorLines::set_carousel (Adw::Carousel* carousel) -> void
  {
    adw_carousel_indicator_lines_set_carousel (
        gobj (),
        (AdwCarousel*) Glib::unwrap (carousel));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Adw::Carousel*>::value,
      "Type Adw::Carousel* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  CarouselIndicatorLines::property_carousel () -> Glib::PropertyProxy<Adw::Carousel*>
  {
    return Glib::PropertyProxy<Adw::Carousel*> (this, "carousel");
  }

  auto
  CarouselIndicatorLines::property_carousel () const -> Glib::PropertyProxy_ReadOnly<Adw::Carousel*>
  {
    return Glib::PropertyProxy_ReadOnly<Adw::Carousel*> (this, "carousel");
  }

} // namespace Adw
