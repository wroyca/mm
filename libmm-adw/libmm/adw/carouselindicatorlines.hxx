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
  class LIBMM_ADW_SYMEXPORT carousel_indicator_lines_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT carousel_indicator_lines : public gtk::Widget,
                                 public gtk::Orientable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = carousel_indicator_lines;
    using CppClassType = carousel_indicator_lines_class;
    using BaseObjectType = AdwCarouselIndicatorLines;
    using BaseClassType = AdwCarouselIndicatorLinesClass;
#endif

    carousel_indicator_lines (carousel_indicator_lines&& src) noexcept;
    auto
    operator= (carousel_indicator_lines&& src) noexcept
        -> carousel_indicator_lines&;

    carousel_indicator_lines (const carousel_indicator_lines&) = delete;
    auto
    operator= (const carousel_indicator_lines&)
        -> carousel_indicator_lines& = delete;

    ~carousel_indicator_lines () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class carousel_indicator_lines_class;
    static CppClassType carouselindicatorlines_class_;

  protected:
    explicit carousel_indicator_lines (
        const glib::ConstructParams& construct_params);
    explicit carousel_indicator_lines (AdwCarouselIndicatorLines* castitem);

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
    carousel_indicator_lines ();

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
  wrap (AdwCarouselIndicatorLines* object, bool take_copy = false) -> adw::carousel_indicator_lines*;
}

#endif
