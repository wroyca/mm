// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_CAROUSEL_H
#define _LIBADWAITAMM_CAROUSEL_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/adw/springparams.hxx>
#include <libmm/adw/swipeable.hxx>
#include <libmm/gtk/mm-gtk.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT carousel_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT carousel : public gtk::Widget,
                   public gtk::Orientable,
                   public adw::swipeable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = carousel;
    using CppClassType = carousel_class;
    using BaseObjectType = AdwCarousel;
    using BaseClassType = AdwCarouselClass;
#endif

    carousel (carousel&& src) noexcept;
    auto
    operator= (carousel&& src) noexcept -> carousel&;

    carousel (const carousel&) = delete;
    auto
    operator= (const carousel&) -> carousel& = delete;

    ~carousel () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class carousel_class;
    static CppClassType carousel_class_;

  protected:
    explicit carousel (const glib::ConstructParams& construct_params);
    explicit carousel (AdwCarousel* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwCarousel*
    {
      return reinterpret_cast<AdwCarousel*> (gobject_);
    }

    auto
    gobj () const -> const AdwCarousel*
    {
      return reinterpret_cast<AdwCarousel*> (gobject_);
    }

  private:
  public:
    carousel ();

    auto
    append (gtk::Widget* child) -> void;

    auto
    get_allow_long_swipes () const -> bool;

    auto
    get_allow_mouse_drag () const -> bool;

    auto
    get_allow_scroll_wheel () const -> bool;

    auto
    get_interactive () const -> bool;

    auto
    get_n_pages () const -> guint;

    auto
    get_nth_page (guint n) const -> gtk::Widget*;

    auto
    get_position () const -> double;

    auto
    get_reveal_duration () const -> guint;

    auto
    get_scroll_params () const -> glib::RefPtr<spring_params>;

    auto
    get_spacing () const -> guint;

    auto
    insert (gtk::Widget* child, int position) -> void;

    auto
    prepend (gtk::Widget* child) -> void;

    auto
    remove (gtk::Widget* child) -> void;

    auto
    reorder (gtk::Widget* child, int position) -> void;

    auto
    scroll_to (gtk::Widget* child, bool animate) -> void;

    auto
    set_allow_long_swipes (bool allow_long_swipes) -> void;

    auto
    set_allow_mouse_drag (bool allow_mouse_drag) -> void;

    auto
    set_allow_scroll_wheel (bool allow_scroll_wheel) -> void;

    auto
    set_interactive (bool interactive) -> void;

    auto
    set_reveal_duration (guint reveal_duration) -> void;

    auto
    set_scroll_params (const glib::RefPtr<spring_params>& scroll_params) -> void;

    auto
    set_spacing (guint spacing) -> void;

    auto
    property_interactive () -> glib::PropertyProxy<bool>;

    auto
    property_interactive () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_scroll_params () -> glib::PropertyProxy<bool>;

    auto
    property_scroll_params () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_allow_mouse_drag () -> glib::PropertyProxy<bool>;

    auto
    property_allow_mouse_drag () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_allow_scroll_wheel () -> glib::PropertyProxy<bool>;

    auto
    property_allow_scroll_wheel () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_allow_long_swipes () -> glib::PropertyProxy<bool>;

    auto
    property_allow_long_swipes () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_reveal_duration () -> glib::PropertyProxy<guint>;

    auto
    property_reveal_duration () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_position () const -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_n_pages () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_spacing () -> glib::PropertyProxy<guint>;

    auto
    property_spacing () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    signal_page_changed () -> glib::SignalProxy<void (guint)>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwCarousel* object, bool take_copy = false) -> adw::carousel*;
}

#endif
