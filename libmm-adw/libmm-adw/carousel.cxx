// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-adw/carousel.hxx>
#include <libmm-adw/carousel_p.hxx>

#include <libmm-gtk/mm-gtk.hxx>

namespace Adw
{

}

namespace
{

  static auto
  Carousel_signal_page_changed_callback (AdwCarousel* self,
                                         guint p0,
                                         void* data) -> void
  {
    using namespace Adw;
    using SlotType = sigc::slot<void (guint)>;

    auto obj = dynamic_cast<Carousel*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo Carousel_signal_page_changed_info = {
      "page_changed",
      (GCallback) &Carousel_signal_page_changed_callback,
      (GCallback) &Carousel_signal_page_changed_callback};

} // namespace

namespace Glib
{

  auto
  wrap (AdwCarousel* object, bool take_copy) -> Adw::Carousel*
  {
    return dynamic_cast<Adw::Carousel*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  Carousel_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_carousel_get_type ();
    }

    return *this;
  }

  auto
  Carousel_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new Carousel ((AdwCarousel*) (o)));
  }

  Carousel::Carousel (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  Carousel::Carousel (AdwCarousel* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Carousel::Carousel (Carousel&& src) noexcept
    : Gtk::Widget (std::move (src)),
      Gtk::Orientable (std::move (src)),
      Adw::Swipeable (std::move (src))
  {
  }

  auto
  Carousel::operator= (Carousel&& src) noexcept -> Carousel&
  {
    Gtk::Widget::operator= (std::move (src));
    Gtk::Orientable::operator= (std::move (src));
    Adw::Swipeable::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (carousel_class_.init ()))
  {
  }

  auto
  Carousel::append (Gtk::Widget* child) -> void
  {
    adw_carousel_append (gobj (), (GtkWidget*) Glib::unwrap (child));
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
  Carousel::get_nth_page (guint n) const -> Gtk::Widget*
  {
    return Glib::wrap (
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
  Carousel::get_scroll_params () const -> Glib::RefPtr<SpringParams>
  {
    auto retvalue = Glib::wrap (
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
  Carousel::insert (Gtk::Widget* child, int position) -> void
  {
    adw_carousel_insert (gobj (), (GtkWidget*) Glib::unwrap (child), position);
  }

  auto
  Carousel::prepend (Gtk::Widget* child) -> void
  {
    adw_carousel_prepend (gobj (), (GtkWidget*) Glib::unwrap (child));
  }

  auto
  Carousel::remove (Gtk::Widget* child) -> void
  {
    adw_carousel_remove (gobj (), (GtkWidget*) Glib::unwrap (child));
  }

  auto
  Carousel::reorder (Gtk::Widget* child, int position) -> void
  {
    adw_carousel_reorder (gobj (), (GtkWidget*) Glib::unwrap (child), position);
  }

  auto
  Carousel::scroll_to (Gtk::Widget* child, bool animate) -> void
  {
    adw_carousel_scroll_to (gobj (),
                            (GtkWidget*) Glib::unwrap (child),
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
  Carousel::set_scroll_params (const Glib::RefPtr<SpringParams>& scroll_params) -> void
  {
    adw_carousel_set_scroll_params (gobj (), Glib::unwrap (scroll_params));
  }

  auto
  Carousel::set_spacing (guint spacing) -> void
  {
    adw_carousel_set_spacing (gobj (), spacing);
  }

  auto
  Carousel::signal_page_changed () -> Glib::SignalProxy<void (guint)>
  {
    return Glib::SignalProxy<void (guint)> (this,
                                            &Carousel_signal_page_changed_info);
  }

  auto
  Carousel::property_interactive () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "interactive");
  }

  auto
  Carousel::property_interactive () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "interactive");
  }

  auto
  Carousel::property_scroll_params () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "scroll-params");
  }

  auto
  Carousel::property_scroll_params () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "scroll-params");
  }

  auto
  Carousel::property_allow_mouse_drag () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "allow-mouse-drag");
  }

  auto
  Carousel::property_allow_mouse_drag () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "allow-mouse-drag");
  }

  auto
  Carousel::property_allow_scroll_wheel () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "allow-scroll-wheel");
  }

  auto
  Carousel::property_allow_scroll_wheel () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "allow-scroll-wheel");
  }

  auto
  Carousel::property_allow_long_swipes () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "allow-long-swipes");
  }

  auto
  Carousel::property_allow_long_swipes () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "allow-long-swipes");
  }

  auto
  Carousel::property_reveal_duration () -> Glib::PropertyProxy<guint>
  {
    return Glib::PropertyProxy<guint> (this, "reveal-duration");
  }

  auto
  Carousel::property_reveal_duration () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "reveal-duration");
  }

  auto
  Carousel::property_position () const -> Glib::PropertyProxy_ReadOnly<double>
  {
    return Glib::PropertyProxy_ReadOnly<double> (this, "position");
  }

  auto
  Carousel::property_n_pages () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "n-pages");
  }

  auto
  Carousel::property_spacing () -> Glib::PropertyProxy<guint>
  {
    return Glib::PropertyProxy<guint> (this, "spacing");
  }

  auto
  Carousel::property_spacing () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "spacing");
  }

} // namespace Adw
