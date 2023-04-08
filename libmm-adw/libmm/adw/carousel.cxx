// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/carousel.hxx>
#include <libmm/adw/carousel_p.hxx>

#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

}

namespace
{

  static auto
  Carousel_signal_page_changed_callback (AdwCarousel* self,
                                         guint p0,
                                         void* data) -> void
  {
    using namespace adw;
    using SlotType = sigc::slot<void (guint)>;

    auto obj = dynamic_cast<carousel*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo Carousel_signal_page_changed_info = {
      "page_changed",
      (GCallback) &Carousel_signal_page_changed_callback,
      (GCallback) &Carousel_signal_page_changed_callback};

} // namespace

namespace glib
{

  auto
  wrap (AdwCarousel* object, bool take_copy) -> adw::carousel*
  {
    return dynamic_cast<adw::carousel*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  carousel_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_carousel_get_type ();
    }

    return *this;
  }

  auto
  carousel_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new carousel ((AdwCarousel*) (o)));
  }

  carousel::carousel (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  carousel::carousel (AdwCarousel* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  carousel::carousel (carousel&& src) noexcept
    : gtk::Widget (std::move (src)),
      gtk::Orientable (std::move (src)),
      adw::swipeable (std::move (src))
  {
  }

  auto
  carousel::operator= (carousel&& src) noexcept -> carousel&
  {
    gtk::Widget::operator= (std::move (src));
    gtk::Orientable::operator= (std::move (src));
    adw::swipeable::operator= (std::move (src));
    return *this;
  }

  carousel::~carousel () noexcept
  {
    destroy_ ();
  }

  carousel::CppClassType carousel::carousel_class_;

  auto
  carousel::get_type () -> GType
  {
    return carousel_class_.init ().get_type ();
  }

  auto
  carousel::get_base_type () -> GType
  {
    return adw_carousel_get_type ();
  }

  carousel::carousel ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (carousel_class_.init ()))
  {
  }

  auto
  carousel::append (gtk::Widget* child) -> void
  {
    adw_carousel_append (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  carousel::get_allow_long_swipes () const -> bool
  {
    return adw_carousel_get_allow_long_swipes (
        const_cast<AdwCarousel*> (gobj ()));
  }

  auto
  carousel::get_allow_mouse_drag () const -> bool
  {
    return adw_carousel_get_allow_mouse_drag (
        const_cast<AdwCarousel*> (gobj ()));
  }

  auto
  carousel::get_allow_scroll_wheel () const -> bool
  {
    return adw_carousel_get_allow_scroll_wheel (
        const_cast<AdwCarousel*> (gobj ()));
  }

  auto
  carousel::get_interactive () const -> bool
  {
    return adw_carousel_get_interactive (const_cast<AdwCarousel*> (gobj ()));
  }

  auto
  carousel::get_n_pages () const -> guint
  {
    return adw_carousel_get_n_pages (const_cast<AdwCarousel*> (gobj ()));
  }

  auto
  carousel::get_nth_page (guint n) const -> gtk::Widget*
  {
    return glib::wrap (
        adw_carousel_get_nth_page (const_cast<AdwCarousel*> (gobj ()), n));
  }

  auto
  carousel::get_position () const -> double
  {
    return adw_carousel_get_position (const_cast<AdwCarousel*> (gobj ()));
  }

  auto
  carousel::get_reveal_duration () const -> guint
  {
    return adw_carousel_get_reveal_duration (
        const_cast<AdwCarousel*> (gobj ()));
  }

  auto
  carousel::get_scroll_params () const -> glib::RefPtr<spring_params>
  {
    auto retvalue = glib::wrap (
        adw_carousel_get_scroll_params (const_cast<AdwCarousel*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  carousel::get_spacing () const -> guint
  {
    return adw_carousel_get_spacing (const_cast<AdwCarousel*> (gobj ()));
  }

  auto
  carousel::insert (gtk::Widget* child, int position) -> void
  {
    adw_carousel_insert (gobj (), (GtkWidget*) glib::unwrap (child), position);
  }

  auto
  carousel::prepend (gtk::Widget* child) -> void
  {
    adw_carousel_prepend (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  carousel::remove (gtk::Widget* child) -> void
  {
    adw_carousel_remove (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  carousel::reorder (gtk::Widget* child, int position) -> void
  {
    adw_carousel_reorder (gobj (), (GtkWidget*) glib::unwrap (child), position);
  }

  auto
  carousel::scroll_to (gtk::Widget* child, bool animate) -> void
  {
    adw_carousel_scroll_to (gobj (),
                            (GtkWidget*) glib::unwrap (child),
                            static_cast<int> (animate));
  }

  auto
  carousel::set_allow_long_swipes (bool allow_long_swipes) -> void
  {
    adw_carousel_set_allow_long_swipes (gobj (),
                                        static_cast<int> (allow_long_swipes));
  }

  auto
  carousel::set_allow_mouse_drag (bool allow_mouse_drag) -> void
  {
    adw_carousel_set_allow_mouse_drag (gobj (),
                                       static_cast<int> (allow_mouse_drag));
  }

  auto
  carousel::set_allow_scroll_wheel (bool allow_scroll_wheel) -> void
  {
    adw_carousel_set_allow_scroll_wheel (gobj (),
                                         static_cast<int> (allow_scroll_wheel));
  }

  auto
  carousel::set_interactive (bool interactive) -> void
  {
    adw_carousel_set_interactive (gobj (), static_cast<int> (interactive));
  }

  auto
  carousel::set_reveal_duration (guint reveal_duration) -> void
  {
    adw_carousel_set_reveal_duration (gobj (), reveal_duration);
  }

  auto
  carousel::set_scroll_params (const glib::RefPtr<spring_params>& scroll_params) -> void
  {
    adw_carousel_set_scroll_params (gobj (), glib::unwrap (scroll_params));
  }

  auto
  carousel::set_spacing (guint spacing) -> void
  {
    adw_carousel_set_spacing (gobj (), spacing);
  }

  auto
  carousel::signal_page_changed () -> glib::SignalProxy<void (guint)>
  {
    return {this, &Carousel_signal_page_changed_info};
  }

  auto
  carousel::property_interactive () -> glib::PropertyProxy<bool>
  {
    return {this, "interactive"};
  }

  auto
  carousel::property_interactive () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "interactive"};
  }

  auto
  carousel::property_scroll_params () -> glib::PropertyProxy<bool>
  {
    return {this, "scroll-params"};
  }

  auto
  carousel::property_scroll_params () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "scroll-params"};
  }

  auto
  carousel::property_allow_mouse_drag () -> glib::PropertyProxy<bool>
  {
    return {this, "allow-mouse-drag"};
  }

  auto
  carousel::property_allow_mouse_drag () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "allow-mouse-drag"};
  }

  auto
  carousel::property_allow_scroll_wheel () -> glib::PropertyProxy<bool>
  {
    return {this, "allow-scroll-wheel"};
  }

  auto
  carousel::property_allow_scroll_wheel () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "allow-scroll-wheel"};
  }

  auto
  carousel::property_allow_long_swipes () -> glib::PropertyProxy<bool>
  {
    return {this, "allow-long-swipes"};
  }

  auto
  carousel::property_allow_long_swipes () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "allow-long-swipes"};
  }

  auto
  carousel::property_reveal_duration () -> glib::PropertyProxy<guint>
  {
    return {this, "reveal-duration"};
  }

  auto
  carousel::property_reveal_duration () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return {this, "reveal-duration"};
  }

  auto
  carousel::property_position () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return {this, "position"};
  }

  auto
  carousel::property_n_pages () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return {this, "n-pages"};
  }

  auto
  carousel::property_spacing () -> glib::PropertyProxy<guint>
  {
    return {this, "spacing"};
  }

  auto
  carousel::property_spacing () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return {this, "spacing"};
  }

} // namespace adw
