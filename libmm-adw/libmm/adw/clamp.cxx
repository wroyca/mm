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
  wrap (AdwClamp* object, bool take_copy) -> adw::Clamp*
  {
    return dynamic_cast<adw::Clamp*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  Clamp_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_clamp_get_type ();
    }

    return *this;
  }

  auto
  Clamp_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Clamp ((AdwClamp*) (o)));
  }

  Clamp::Clamp (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Clamp::Clamp (AdwClamp* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Clamp::Clamp (Clamp&& src) noexcept
    : gtk::Widget (std::move (src)),
      gtk::Orientable (std::move (src))
  {
  }

  auto
  Clamp::operator= (Clamp&& src) noexcept -> Clamp&
  {
    gtk::Widget::operator= (std::move (src));
    gtk::Orientable::operator= (std::move (src));
    return *this;
  }

  Clamp::~Clamp () noexcept
  {
    destroy_ ();
  }

  Clamp::CppClassType Clamp::clamp_class_;

  auto
  Clamp::get_type () -> GType
  {
    return clamp_class_.init ().get_type ();
  }

  auto
  Clamp::get_base_type () -> GType
  {
    return adw_clamp_get_type ();
  }

  Clamp::Clamp ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (clamp_class_.init ()))
  {
  }

  auto
  Clamp::get_child () const -> gtk::Widget*
  {
    return glib::wrap (adw_clamp_get_child (const_cast<AdwClamp*> (gobj ())));
  }

  auto
  Clamp::get_maximum_size () const -> int
  {
    return adw_clamp_get_maximum_size (const_cast<AdwClamp*> (gobj ()));
  }

  auto
  Clamp::get_tightening_threshold () const -> int
  {
    return adw_clamp_get_tightening_threshold (const_cast<AdwClamp*> (gobj ()));
  }

  auto
  Clamp::set_child (gtk::Widget* child) -> void
  {
    adw_clamp_set_child (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  Clamp::get_maximum_size (int maximum_size) -> void
  {
    adw_clamp_set_maximum_size (gobj (), maximum_size);
  }

  auto
  Clamp::get_tightening_threshold (int tightening_threshold) -> void
  {
    adw_clamp_set_tightening_threshold (gobj (), tightening_threshold);
  }

  auto
  Clamp::property_child () -> glib::PropertyProxy<gtk::Widget*>
  {
    return glib::PropertyProxy<gtk::Widget*> (this, "child");
  }

  auto
  Clamp::property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return glib::PropertyProxy_ReadOnly<gtk::Widget*> (this, "child");
  }

  auto
  Clamp::property_maximum_size () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "maximum-size");
  }

  auto
  Clamp::property_maximum_size () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "maximum-size");
  }

  auto
  Clamp::property_tightening_threshold () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "tightening-threshold");
  }

  auto
  Clamp::property_tightening_threshold () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "tightening-threshold");
  }

} // namespace adw
