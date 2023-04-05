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
  wrap (AdwClampScrollable* object, bool take_copy) -> adw::ClampScrollable*
  {
    return dynamic_cast<adw::ClampScrollable*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  ClampScrollable_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_clamp_scrollable_get_type ();
    }

    return *this;
  }

  auto
  ClampScrollable_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new ClampScrollable ((AdwClampScrollable*) (o)));
  }

  ClampScrollable::ClampScrollable (
      const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  ClampScrollable::ClampScrollable (AdwClampScrollable* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  ClampScrollable::ClampScrollable (ClampScrollable&& src) noexcept
    : gtk::Widget (std::move (src)),
      gtk::Orientable (std::move (src)),
      gtk::Scrollable (std::move (src))
  {
  }

  auto
  ClampScrollable::operator= (ClampScrollable&& src) noexcept -> ClampScrollable&
  {
    gtk::Widget::operator= (std::move (src));
    gtk::Orientable::operator= (std::move (src));
    gtk::Scrollable::operator= (std::move (src));
    return *this;
  }

  ClampScrollable::~ClampScrollable () noexcept
  {
    destroy_ ();
  }

  ClampScrollable::CppClassType ClampScrollable::clampscrollable_class_;

  auto
  ClampScrollable::get_type () -> GType
  {
    return clampscrollable_class_.init ().get_type ();
  }

  auto
  ClampScrollable::get_base_type () -> GType
  {
    return adw_clamp_scrollable_get_type ();
  }

  ClampScrollable::ClampScrollable ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (clampscrollable_class_.init ()))
  {
  }

  auto
  ClampScrollable::get_child () const -> gtk::Widget*
  {
    return glib::wrap (adw_clamp_scrollable_get_child (
        const_cast<AdwClampScrollable*> (gobj ())));
  }

  auto
  ClampScrollable::get_maximum_size () const -> int
  {
    return adw_clamp_scrollable_get_maximum_size (
        const_cast<AdwClampScrollable*> (gobj ()));
  }

  auto
  ClampScrollable::get_tightening_threshold () const -> int
  {
    return adw_clamp_scrollable_get_tightening_threshold (
        const_cast<AdwClampScrollable*> (gobj ()));
  }

  auto
  ClampScrollable::set_child (gtk::Widget* child) -> void
  {
    adw_clamp_scrollable_set_child (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  ClampScrollable::get_maximum_size (int maximum_size) -> void
  {
    adw_clamp_scrollable_set_maximum_size (gobj (), maximum_size);
  }

  auto
  ClampScrollable::get_tightening_threshold (int tightening_threshold) -> void
  {
    adw_clamp_scrollable_set_tightening_threshold (gobj (),
                                                   tightening_threshold);
  }

  auto
  ClampScrollable::property_child () -> glib::PropertyProxy<gtk::Widget*>
  {
    return glib::PropertyProxy<gtk::Widget*> (this, "child");
  }

  auto
  ClampScrollable::property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return glib::PropertyProxy_ReadOnly<gtk::Widget*> (this, "child");
  }

  auto
  ClampScrollable::property_maximum_size () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "maximum-size");
  }

  auto
  ClampScrollable::property_maximum_size () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "maximum-size");
  }

  auto
  ClampScrollable::property_tightening_threshold () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "tightening-threshold");
  }

  auto
  ClampScrollable::property_tightening_threshold () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "tightening-threshold");
  }

} // namespace adw
