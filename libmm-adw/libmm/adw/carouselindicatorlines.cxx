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
  wrap (AdwCarouselIndicatorLines* object, bool take_copy) -> adw::carousel_indicator_lines*
  {
    return dynamic_cast<adw::carousel_indicator_lines*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  carousel_indicator_lines_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_carousel_indicator_lines_get_type ();
    }

    return *this;
  }

  auto
  carousel_indicator_lines_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (
        new carousel_indicator_lines ((AdwCarouselIndicatorLines*) (o)));
  }

  carousel_indicator_lines::carousel_indicator_lines (
      const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  carousel_indicator_lines::carousel_indicator_lines (
      AdwCarouselIndicatorLines* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  carousel_indicator_lines::carousel_indicator_lines (
      carousel_indicator_lines&& src) noexcept
    : gtk::Widget (std::move (src)),
      gtk::Orientable (std::move (src))
  {
  }

  auto
  carousel_indicator_lines::operator= (carousel_indicator_lines&& src) noexcept -> carousel_indicator_lines&
  {
    gtk::Widget::operator= (std::move (src));
    gtk::Orientable::operator= (std::move (src));
    return *this;
  }

  carousel_indicator_lines::~carousel_indicator_lines () noexcept
  {
    destroy_ ();
  }

  carousel_indicator_lines::CppClassType
      carousel_indicator_lines::carouselindicatorlines_class_;

  auto
  carousel_indicator_lines::get_type () -> GType
  {
    return carouselindicatorlines_class_.init ().get_type ();
  }

  auto
  carousel_indicator_lines::get_base_type () -> GType
  {
    return adw_carousel_indicator_lines_get_type ();
  }

  carousel_indicator_lines::carousel_indicator_lines ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (
          glib::ConstructParams (carouselindicatorlines_class_.init ()))
  {
  }

  auto
  carousel_indicator_lines::get_carousel () const -> adw::carousel*
  {
    return glib::wrap (adw_carousel_indicator_lines_get_carousel (
        const_cast<AdwCarouselIndicatorLines*> (gobj ())));
  }

  auto
  carousel_indicator_lines::set_carousel (adw::carousel* carousel) -> void
  {
    adw_carousel_indicator_lines_set_carousel (
        gobj (),
        (AdwCarousel*) glib::unwrap (carousel));
  }

  auto
  carousel_indicator_lines::property_carousel () -> glib::PropertyProxy<adw::carousel*>
  {
    return {this, "carousel"};
  }

  auto
  carousel_indicator_lines::property_carousel () const -> glib::PropertyProxy_ReadOnly<adw::carousel*>
  {
    return {this, "carousel"};
  }

} // namespace adw
