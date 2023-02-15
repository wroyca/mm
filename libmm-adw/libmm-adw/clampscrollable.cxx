// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-adw/clampscrollable.hxx>
#include <libmm-adw/clampscrollable_p.hxx>

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
  wrap (AdwClampScrollable* object, bool take_copy) -> Adw::ClampScrollable*
  {
    return dynamic_cast<Adw::ClampScrollable*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  ClampScrollable_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_clamp_scrollable_get_type ();
    }

    return *this;
  }

  auto
  ClampScrollable_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new ClampScrollable ((AdwClampScrollable*) (o)));
  }

  ClampScrollable::ClampScrollable (
      const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  ClampScrollable::ClampScrollable (AdwClampScrollable* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  ClampScrollable::ClampScrollable (ClampScrollable&& src) noexcept
    : Gtk::Widget (std::move (src)),
      Gtk::Orientable (std::move (src)),
      Gtk::Scrollable (std::move (src))
  {
  }

  auto
  ClampScrollable::operator= (ClampScrollable&& src) noexcept -> ClampScrollable&
  {
    Gtk::Widget::operator= (std::move (src));
    Gtk::Orientable::operator= (std::move (src));
    Gtk::Scrollable::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (clampscrollable_class_.init ()))
  {
  }

  auto
  ClampScrollable::get_child () const -> Gtk::Widget*
  {
    return Glib::wrap (adw_clamp_scrollable_get_child (
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
  ClampScrollable::set_child (Gtk::Widget* child) -> void
  {
    adw_clamp_scrollable_set_child (gobj (), (GtkWidget*) Glib::unwrap (child));
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
  ClampScrollable::property_child () -> Glib::PropertyProxy<Gtk::Widget*>
  {
    return Glib::PropertyProxy<Gtk::Widget*> (this, "child");
  }

  auto
  ClampScrollable::property_child () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::Widget*> (this, "child");
  }

  auto
  ClampScrollable::property_maximum_size () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "maximum-size");
  }

  auto
  ClampScrollable::property_maximum_size () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "maximum-size");
  }

  auto
  ClampScrollable::property_tightening_threshold () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "tightening-threshold");
  }

  auto
  ClampScrollable::property_tightening_threshold () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "tightening-threshold");
  }

} // namespace Adw
