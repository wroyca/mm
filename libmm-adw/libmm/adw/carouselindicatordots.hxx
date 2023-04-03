// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_CAROUSELINDICATORDOTS_H
#define _LIBADWAITAMM_CAROUSELINDICATORDOTS_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/adw/carousel.hxx>
#include <libmm/gtk/mm-gtk.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class LIBMM_ADW_SYMEXPORT CarouselIndicatorDots_Class;
}
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT CarouselIndicatorDots : public Gtk::Widget,
                                public Gtk::Orientable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef CarouselIndicatorDots CppObjectType;
    typedef CarouselIndicatorDots_Class CppClassType;
    typedef AdwCarouselIndicatorDots BaseObjectType;
    typedef AdwCarouselIndicatorDotsClass BaseClassType;
#endif

    CarouselIndicatorDots (CarouselIndicatorDots&& src) noexcept;
    auto
    operator= (CarouselIndicatorDots&& src) noexcept -> CarouselIndicatorDots&;

    CarouselIndicatorDots (const CarouselIndicatorDots&) = delete;
    auto
    operator= (const CarouselIndicatorDots&) -> CarouselIndicatorDots& = delete;

    ~CarouselIndicatorDots () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class CarouselIndicatorDots_Class;
    static CppClassType carouselindicatordots_class_;

  protected:
    explicit CarouselIndicatorDots (
        const Glib::ConstructParams& construct_params);
    explicit CarouselIndicatorDots (AdwCarouselIndicatorDots* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwCarouselIndicatorDots*
    {
      return reinterpret_cast<AdwCarouselIndicatorDots*> (gobject_);
    }

    auto
    gobj () const -> const AdwCarouselIndicatorDots*
    {
      return reinterpret_cast<AdwCarouselIndicatorDots*> (gobject_);
    }

  private:
  public:
    CarouselIndicatorDots ();

    auto
    get_carousel () const -> Adw::Carousel*;

    auto
    set_carousel (Adw::Carousel* carousel) -> void;

    auto
    property_carousel () -> Glib::PropertyProxy<Adw::Carousel*>;

    auto
    property_carousel () const -> Glib::PropertyProxy_ReadOnly<Adw::Carousel*>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwCarouselIndicatorDots* object, bool take_copy = false) -> Adw::CarouselIndicatorDots*;
}

#endif