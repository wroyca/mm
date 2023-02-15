// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_CAROUSEL_H
#define _LIBADWAITAMM_CAROUSEL_H

#include <libmm-adw/mm-adwconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-adw/springparams.hxx>
#include <libmm-adw/swipeable.hxx>
#include <libmm-gtk/mm-gtk.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class Carousel_Class;
}
#endif

namespace Adw
{

  class Carousel : public Gtk::Widget,
                   public Gtk::Orientable,
                   public Adw::Swipeable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Carousel CppObjectType;
    typedef Carousel_Class CppClassType;
    typedef AdwCarousel BaseObjectType;
    typedef AdwCarouselClass BaseClassType;
#endif

    Carousel (Carousel&& src) noexcept;
    auto
    operator= (Carousel&& src) noexcept -> Carousel&;

    Carousel (const Carousel&) = delete;
    auto
    operator= (const Carousel&) -> Carousel& = delete;

    ~Carousel () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class Carousel_Class;
    static CppClassType carousel_class_;

  protected:
    explicit Carousel (const Glib::ConstructParams& construct_params);
    explicit Carousel (AdwCarousel* castitem);

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
    Carousel ();

    auto
    append (Gtk::Widget* child) -> void;

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
    get_nth_page (guint n) const -> Gtk::Widget*;

    auto
    get_position () const -> double;

    auto
    get_reveal_duration () const -> guint;

    auto
    get_scroll_params () const -> Glib::RefPtr<SpringParams>;

    auto
    get_spacing () const -> guint;

    auto
    insert (Gtk::Widget* child, int position) -> void;

    auto
    prepend (Gtk::Widget* child) -> void;

    auto
    remove (Gtk::Widget* child) -> void;

    auto
    reorder (Gtk::Widget* child, int position) -> void;

    auto
    scroll_to (Gtk::Widget* child, bool animate) -> void;

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
    set_scroll_params (const Glib::RefPtr<SpringParams>& scroll_params) -> void;

    auto
    set_spacing (guint spacing) -> void;

    auto
    property_interactive () -> Glib::PropertyProxy<bool>;

    auto
    property_interactive () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_scroll_params () -> Glib::PropertyProxy<bool>;

    auto
    property_scroll_params () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_allow_mouse_drag () -> Glib::PropertyProxy<bool>;

    auto
    property_allow_mouse_drag () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_allow_scroll_wheel () -> Glib::PropertyProxy<bool>;

    auto
    property_allow_scroll_wheel () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_allow_long_swipes () -> Glib::PropertyProxy<bool>;

    auto
    property_allow_long_swipes () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_reveal_duration () -> Glib::PropertyProxy<guint>;

    auto
    property_reveal_duration () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_position () const -> Glib::PropertyProxy_ReadOnly<double>;

    auto
    property_n_pages () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_spacing () -> Glib::PropertyProxy<guint>;

    auto
    property_spacing () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    signal_page_changed () -> Glib::SignalProxy<void (guint)>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwCarousel* object, bool take_copy = false) -> Adw::Carousel*;
}

#endif
