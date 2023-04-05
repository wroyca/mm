// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_CAROUSELINDICATORLINES_H
#define _LIBADWAITAMM_CAROUSELINDICATORLINES_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/adw/carousel.hxx>
#include <libmm/gtk/mm-gtk.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT CarouselIndicatorLines_Class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT CarouselIndicatorLines : public gtk::Widget,
                                 public gtk::Orientable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef CarouselIndicatorLines CppObjectType;
    typedef CarouselIndicatorLines_Class CppClassType;
    typedef AdwCarouselIndicatorLines BaseObjectType;
    typedef AdwCarouselIndicatorLinesClass BaseClassType;
#endif

    CarouselIndicatorLines (CarouselIndicatorLines&& src) noexcept;
    auto
    operator= (CarouselIndicatorLines&& src) noexcept
        -> CarouselIndicatorLines&;

    CarouselIndicatorLines (const CarouselIndicatorLines&) = delete;
    auto
    operator= (const CarouselIndicatorLines&)
        -> CarouselIndicatorLines& = delete;

    ~CarouselIndicatorLines () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class CarouselIndicatorLines_Class;
    static CppClassType carouselindicatorlines_class_;

  protected:
    explicit CarouselIndicatorLines (
        const glib::ConstructParams& construct_params);
    explicit CarouselIndicatorLines (AdwCarouselIndicatorLines* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwCarouselIndicatorLines*
    {
      return reinterpret_cast<AdwCarouselIndicatorLines*> (gobject_);
    }

    auto
    gobj () const -> const AdwCarouselIndicatorLines*
    {
      return reinterpret_cast<AdwCarouselIndicatorLines*> (gobject_);
    }

  private:
  public:
    CarouselIndicatorLines ();

    auto
    get_carousel () const -> adw::Carousel*;

    auto
    set_carousel (adw::Carousel* carousel) -> void;

    auto
    property_carousel () -> glib::PropertyProxy<adw::Carousel*>;

    auto
    property_carousel () const -> glib::PropertyProxy_ReadOnly<adw::Carousel*>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwCarouselIndicatorLines* object, bool take_copy = false) -> adw::CarouselIndicatorLines*;
}

#endif
