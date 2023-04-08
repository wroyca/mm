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
namespace adw
{
  class LIBMM_ADW_SYMEXPORT carousel_indicator_dots_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT carousel_indicator_dots : public gtk::Widget,
                                public gtk::Orientable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = carousel_indicator_dots;
    using CppClassType = carousel_indicator_dots_class;
    using BaseObjectType = AdwCarouselIndicatorDots;
    using BaseClassType = AdwCarouselIndicatorDotsClass;
#endif

    carousel_indicator_dots (carousel_indicator_dots&& src) noexcept;
    auto
    operator= (carousel_indicator_dots&& src) noexcept -> carousel_indicator_dots&;

    carousel_indicator_dots (const carousel_indicator_dots&) = delete;
    auto
    operator= (const carousel_indicator_dots&) -> carousel_indicator_dots& = delete;

    ~carousel_indicator_dots () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class carousel_indicator_dots_class;
    static CppClassType carouselindicatordots_class_;

  protected:
    explicit carousel_indicator_dots (
        const glib::ConstructParams& construct_params);
    explicit carousel_indicator_dots (AdwCarouselIndicatorDots* castitem);

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
    carousel_indicator_dots ();

    auto
    get_carousel () const -> adw::carousel*;

    auto
    set_carousel (adw::carousel* carousel) -> void;

    auto
    property_carousel () -> glib::PropertyProxy<adw::carousel*>;

    auto
    property_carousel () const -> glib::PropertyProxy_ReadOnly<adw::carousel*>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwCarouselIndicatorDots* object, bool take_copy = false) -> adw::carousel_indicator_dots*;
}

#endif
