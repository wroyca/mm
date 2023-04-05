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

    auto obj = dynamic_cast<Carousel*> (
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
  wrap (AdwCarousel* object, bool take_copy) -> adw::Carousel*
  {
    return dynamic_cast<adw::Carousel*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  Carousel_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_carousel_get_type ();
    }

    return *this;
  }

  auto
  Carousel_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Carousel ((AdwCarousel*) (o)));
  }

  Carousel::Carousel (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Carousel::Carousel (AdwCarousel* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Carousel::Carousel (Carousel&& src) noexcept
    : gtk::Widget (std::move (src)),
      gtk::Orientable (std::move (src)),
      adw::Swipeable (std::move (src))
  {
  }

  auto
  Carousel::operator= (Carousel&& src) noexcept -> Carousel&
  {
    gtk::Widget::operator= (std::move (src));
    gtk::Orientable::operator= (std::move (src));
    adw::Swipeable::operator= (std::move (src));
    return *this;
  }

  Carousel::~Carousel () noexcept
  {
    destroy_ ();
  }

  Carousel::CppClassType Carousel::carousel_class_;

  auto
  Carousel::get_type () -> GType
  {
    return carousel_class_.init ().get_type ();
  }

  auto
  Carousel::get_base_type () -> GType
  {
    return adw_carousel_get_type ();
  }

  Carousel::Carousel ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (carousel_class_.init ()))
  {
  }

  auto
  Carousel::append (gtk::Widget* child) -> void
  {
    adw_carousel_append (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  Carousel::get_allow_long_swipes () const -> bool
  {
    return adw_carousel_get_allow_long_swipes (
        const_cast<AdwCarousel*> (gobj ()));
  }

  auto
  Carousel::get_allow_mouse_drag () const -> bool
  {
    return adw_carousel_get_allow_mouse_drag (
        const_cast<AdwCarousel*> (gobj ()));
  }

  auto
  Carousel::get_allow_scroll_wheel () const -> bool
  {
    return adw_carousel_get_allow_scroll_wheel (
        const_cast<AdwCarousel*> (gobj ()));
  }

  auto
  Carousel::get_interactive () const -> bool
  {
    return adw_carousel_get_interactive (const_cast<AdwCarousel*> (gobj ()));
  }

  auto
  Carousel::get_n_pages () const -> guint
  {
    return adw_carousel_get_n_pages (const_cast<AdwCarousel*> (gobj ()));
  }

  auto
  Carousel::get_nth_page (guint n) const -> gtk::Widget*
  {
    return glib::wrap (
        adw_carousel_get_nth_page (const_cast<AdwCarousel*> (gobj ()), n));
  }

  auto
  Carousel::get_position () const -> double
  {
    return adw_carousel_get_position (const_cast<AdwCarousel*> (gobj ()));
  }

  auto
  Carousel::get_reveal_duration () const -> guint
  {
    return adw_carousel_get_reveal_duration (
        const_cast<AdwCarousel*> (gobj ()));
  }

  auto
  Carousel::get_scroll_params () const -> glib::RefPtr<SpringParams>
  {
    auto retvalue = glib::wrap (
        adw_carousel_get_scroll_params (const_cast<AdwCarousel*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Carousel::get_spacing () const -> guint
  {
    return adw_carousel_get_spacing (const_cast<AdwCarousel*> (gobj ()));
  }

  auto
  Carousel::insert (gtk::Widget* child, int position) -> void
  {
    adw_carousel_insert (gobj (), (GtkWidget*) glib::unwrap (child), position);
  }

  auto
  Carousel::prepend (gtk::Widget* child) -> void
  {
    adw_carousel_prepend (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  Carousel::remove (gtk::Widget* child) -> void
  {
    adw_carousel_remove (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  Carousel::reorder (gtk::Widget* child, int position) -> void
  {
    adw_carousel_reorder (gobj (), (GtkWidget*) glib::unwrap (child), position);
  }

  auto
  Carousel::scroll_to (gtk::Widget* child, bool animate) -> void
  {
    adw_carousel_scroll_to (gobj (),
                            (GtkWidget*) glib::unwrap (child),
                            static_cast<int> (animate));
  }

  auto
  Carousel::set_allow_long_swipes (bool allow_long_swipes) -> void
  {
    adw_carousel_set_allow_long_swipes (gobj (),
                                        static_cast<int> (allow_long_swipes));
  }

  auto
  Carousel::set_allow_mouse_drag (bool allow_mouse_drag) -> void
  {
    adw_carousel_set_allow_mouse_drag (gobj (),
                                       static_cast<int> (allow_mouse_drag));
  }

  auto
  Carousel::set_allow_scroll_wheel (bool allow_scroll_wheel) -> void
  {
    adw_carousel_set_allow_scroll_wheel (gobj (),
                                         static_cast<int> (allow_scroll_wheel));
  }

  auto
  Carousel::set_interactive (bool interactive) -> void
  {
    adw_carousel_set_interactive (gobj (), static_cast<int> (interactive));
  }

  auto
  Carousel::set_reveal_duration (guint reveal_duration) -> void
  {
    adw_carousel_set_reveal_duration (gobj (), reveal_duration);
  }

  auto
  Carousel::set_scroll_params (const glib::RefPtr<SpringParams>& scroll_params) -> void
  {
    adw_carousel_set_scroll_params (gobj (), glib::unwrap (scroll_params));
  }

  auto
  Carousel::set_spacing (guint spacing) -> void
  {
    adw_carousel_set_spacing (gobj (), spacing);
  }

  auto
  Carousel::signal_page_changed () -> glib::SignalProxy<void (guint)>
  {
    return glib::SignalProxy<void (guint)> (this,
                                            &Carousel_signal_page_changed_info);
  }

  auto
  Carousel::property_interactive () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "interactive");
  }

  auto
  Carousel::property_interactive () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "interactive");
  }

  auto
  Carousel::property_scroll_params () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "scroll-params");
  }

  auto
  Carousel::property_scroll_params () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "scroll-params");
  }

  auto
  Carousel::property_allow_mouse_drag () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "allow-mouse-drag");
  }

  auto
  Carousel::property_allow_mouse_drag () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "allow-mouse-drag");
  }

  auto
  Carousel::property_allow_scroll_wheel () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "allow-scroll-wheel");
  }

  auto
  Carousel::property_allow_scroll_wheel () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "allow-scroll-wheel");
  }

  auto
  Carousel::property_allow_long_swipes () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "allow-long-swipes");
  }

  auto
  Carousel::property_allow_long_swipes () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "allow-long-swipes");
  }

  auto
  Carousel::property_reveal_duration () -> glib::PropertyProxy<guint>
  {
    return glib::PropertyProxy<guint> (this, "reveal-duration");
  }

  auto
  Carousel::property_reveal_duration () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "reveal-duration");
  }

  auto
  Carousel::property_position () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return glib::PropertyProxy_ReadOnly<double> (this, "position");
  }

  auto
  Carousel::property_n_pages () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "n-pages");
  }

  auto
  Carousel::property_spacing () -> glib::PropertyProxy<guint>
  {
    return glib::PropertyProxy<guint> (this, "spacing");
  }

  auto
  Carousel::property_spacing () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "spacing");
  }

} // namespace adw
