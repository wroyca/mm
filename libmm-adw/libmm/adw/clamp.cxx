// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/clamp.hxx>
#include <libmm/adw/clamp_p.hxx>

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
  wrap (AdwClamp* object, bool take_copy) -> adw::clamp*
  {
    return dynamic_cast<adw::clamp*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  clamp_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_clamp_get_type ();
    }

    return *this;
  }

  auto
  clamp_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new clamp ((AdwClamp*) (o)));
  }

  clamp::clamp (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  clamp::clamp (AdwClamp* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  clamp::clamp (clamp&& src) noexcept
    : gtk::Widget (std::move (src)),
      gtk::Orientable (std::move (src))
  {
  }

  auto
  clamp::operator= (clamp&& src) noexcept -> clamp&
  {
    gtk::Widget::operator= (std::move (src));
    gtk::Orientable::operator= (std::move (src));
    return *this;
  }

  clamp::~clamp () noexcept
  {
    destroy_ ();
  }

  clamp::CppClassType clamp::clamp_class_;

  auto
  clamp::get_type () -> GType
  {
    return clamp_class_.init ().get_type ();
  }

  auto
  clamp::get_base_type () -> GType
  {
    return adw_clamp_get_type ();
  }

  clamp::clamp ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (clamp_class_.init ()))
  {
  }

  auto
  clamp::get_child () const -> gtk::Widget*
  {
    return glib::wrap (adw_clamp_get_child (const_cast<AdwClamp*> (gobj ())));
  }

  auto
  clamp::get_maximum_size () const -> int
  {
    return adw_clamp_get_maximum_size (const_cast<AdwClamp*> (gobj ()));
  }

  auto
  clamp::get_tightening_threshold () const -> int
  {
    return adw_clamp_get_tightening_threshold (const_cast<AdwClamp*> (gobj ()));
  }

  auto
  clamp::set_child (gtk::Widget* child) -> void
  {
    adw_clamp_set_child (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  clamp::get_maximum_size (int maximum_size) -> void
  {
    adw_clamp_set_maximum_size (gobj (), maximum_size);
  }

  auto
  clamp::get_tightening_threshold (int tightening_threshold) -> void
  {
    adw_clamp_set_tightening_threshold (gobj (), tightening_threshold);
  }

  auto
  clamp::property_child () -> glib::PropertyProxy<gtk::Widget*>
  {
    return {this, "child"};
  }

  auto
  clamp::property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "child"};
  }

  auto
  clamp::property_maximum_size () -> glib::PropertyProxy<int>
  {
    return {this, "maximum-size"};
  }

  auto
  clamp::property_maximum_size () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "maximum-size"};
  }

  auto
  clamp::property_tightening_threshold () -> glib::PropertyProxy<int>
  {
    return {this, "tightening-threshold"};
  }

  auto
  clamp::property_tightening_threshold () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "tightening-threshold"};
  }

} // namespace adw
