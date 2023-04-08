// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/clampscrollable.hxx>
#include <libmm/adw/clampscrollable_p.hxx>

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
  wrap (AdwClampScrollable* object, bool take_copy) -> adw::clamp_scrollable*
  {
    return dynamic_cast<adw::clamp_scrollable*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  clamp_scrollable_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_clamp_scrollable_get_type ();
    }

    return *this;
  }

  auto
  clamp_scrollable_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new clamp_scrollable ((AdwClampScrollable*) (o)));
  }

  clamp_scrollable::clamp_scrollable (
      const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  clamp_scrollable::clamp_scrollable (AdwClampScrollable* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  clamp_scrollable::clamp_scrollable (clamp_scrollable&& src) noexcept
    : gtk::Widget (std::move (src)),
      gtk::Orientable (std::move (src)),
      gtk::Scrollable (std::move (src))
  {
  }

  auto
  clamp_scrollable::operator= (clamp_scrollable&& src) noexcept -> clamp_scrollable&
  {
    gtk::Widget::operator= (std::move (src));
    gtk::Orientable::operator= (std::move (src));
    gtk::Scrollable::operator= (std::move (src));
    return *this;
  }

  clamp_scrollable::~clamp_scrollable () noexcept
  {
    destroy_ ();
  }

  clamp_scrollable::CppClassType clamp_scrollable::clampscrollable_class_;

  auto
  clamp_scrollable::get_type () -> GType
  {
    return clampscrollable_class_.init ().get_type ();
  }

  auto
  clamp_scrollable::get_base_type () -> GType
  {
    return adw_clamp_scrollable_get_type ();
  }

  clamp_scrollable::clamp_scrollable ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (clampscrollable_class_.init ()))
  {
  }

  auto
  clamp_scrollable::get_child () const -> gtk::Widget*
  {
    return glib::wrap (adw_clamp_scrollable_get_child (
        const_cast<AdwClampScrollable*> (gobj ())));
  }

  auto
  clamp_scrollable::get_maximum_size () const -> int
  {
    return adw_clamp_scrollable_get_maximum_size (
        const_cast<AdwClampScrollable*> (gobj ()));
  }

  auto
  clamp_scrollable::get_tightening_threshold () const -> int
  {
    return adw_clamp_scrollable_get_tightening_threshold (
        const_cast<AdwClampScrollable*> (gobj ()));
  }

  auto
  clamp_scrollable::set_child (gtk::Widget* child) -> void
  {
    adw_clamp_scrollable_set_child (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  clamp_scrollable::get_maximum_size (int maximum_size) -> void
  {
    adw_clamp_scrollable_set_maximum_size (gobj (), maximum_size);
  }

  auto
  clamp_scrollable::get_tightening_threshold (int tightening_threshold) -> void
  {
    adw_clamp_scrollable_set_tightening_threshold (gobj (),
                                                   tightening_threshold);
  }

  auto
  clamp_scrollable::property_child () -> glib::PropertyProxy<gtk::Widget*>
  {
    return {this, "child"};
  }

  auto
  clamp_scrollable::property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "child"};
  }

  auto
  clamp_scrollable::property_maximum_size () -> glib::PropertyProxy<int>
  {
    return {this, "maximum-size"};
  }

  auto
  clamp_scrollable::property_maximum_size () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "maximum-size"};
  }

  auto
  clamp_scrollable::property_tightening_threshold () -> glib::PropertyProxy<int>
  {
    return {this, "tightening-threshold"};
  }

  auto
  clamp_scrollable::property_tightening_threshold () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "tightening-threshold"};
  }

} // namespace adw
