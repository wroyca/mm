// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-adw/clamp.hxx>
#include <libmm-adw/clamp_p.hxx>

#include <libmm-gtk/mm-gtk.hxx>

namespace Adw
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (AdwClamp* object, bool take_copy) -> Adw::Clamp*
  {
    return dynamic_cast<Adw::Clamp*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  Clamp_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_clamp_get_type ();
    }

    return *this;
  }

  auto
  Clamp_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new Clamp ((AdwClamp*) (o)));
  }

  Clamp::Clamp (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  Clamp::Clamp (AdwClamp* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Clamp::Clamp (Clamp&& src) noexcept
    : Gtk::Widget (std::move (src)),
      Gtk::Orientable (std::move (src))
  {
  }

  auto
  Clamp::operator= (Clamp&& src) noexcept -> Clamp&
  {
    Gtk::Widget::operator= (std::move (src));
    Gtk::Orientable::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (clamp_class_.init ()))
  {
  }

  auto
  Clamp::get_child () const -> Gtk::Widget*
  {
    return Glib::wrap (adw_clamp_get_child (const_cast<AdwClamp*> (gobj ())));
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
  Clamp::set_child (Gtk::Widget* child) -> void
  {
    adw_clamp_set_child (gobj (), (GtkWidget*) Glib::unwrap (child));
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
  Clamp::property_child () -> Glib::PropertyProxy<Gtk::Widget*>
  {
    return Glib::PropertyProxy<Gtk::Widget*> (this, "child");
  }

  auto
  Clamp::property_child () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::Widget*> (this, "child");
  }

  auto
  Clamp::property_maximum_size () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "maximum-size");
  }

  auto
  Clamp::property_maximum_size () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "maximum-size");
  }

  auto
  Clamp::property_tightening_threshold () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "tightening-threshold");
  }

  auto
  Clamp::property_tightening_threshold () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "tightening-threshold");
  }

} // namespace Adw
