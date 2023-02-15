// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-adw/clamplayout.hxx>
#include <libmm-adw/clamplayout_p.hxx>

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
  wrap (AdwClampLayout* object, bool take_copy) -> Glib::RefPtr<Adw::ClampLayout>
  {
    return Glib::make_refptr_for_instance<Adw::ClampLayout> (
        dynamic_cast<Adw::ClampLayout*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Adw
{

  auto
  ClampLayout_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_clamp_layout_get_type ();
    }

    return *this;
  }

  auto
  ClampLayout_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new ClampLayout ((AdwClampLayout*) object);
  }

  auto
  ClampLayout::gobj_copy () -> AdwClampLayout*
  {
    reference ();
    return gobj ();
  }

  ClampLayout::ClampLayout (const Glib::ConstructParams& construct_params)
    : Gtk::LayoutManager (construct_params)
  {
  }

  ClampLayout::ClampLayout (AdwClampLayout* castitem)
    : Gtk::LayoutManager ((GtkLayoutManager*) (castitem))
  {
  }

  ClampLayout::ClampLayout (ClampLayout&& src) noexcept
    : Gtk::LayoutManager (std::move (src)),
      Gtk::Orientable (std::move (src))
  {
  }

  auto
  ClampLayout::operator= (ClampLayout&& src) noexcept -> ClampLayout&
  {
    Gtk::LayoutManager::operator= (std::move (src));
    Gtk::Orientable::operator= (std::move (src));
    return *this;
  }

  ClampLayout::~ClampLayout () noexcept {}

  ClampLayout::CppClassType ClampLayout::clamplayout_class_;

  auto
  ClampLayout::get_type () -> GType
  {
    return clamplayout_class_.init ().get_type ();
  }

  auto
  ClampLayout::get_base_type () -> GType
  {
    return adw_clamp_layout_get_type ();
  }

  ClampLayout::ClampLayout ()
    : Glib::ObjectBase (nullptr),
      Gtk::LayoutManager (Glib::ConstructParams (clamplayout_class_.init ()))
  {
  }

  auto
  ClampLayout::create () -> Glib::RefPtr<ClampLayout>
  {
    return Glib::make_refptr_for_instance<ClampLayout> (new ClampLayout ());
  }

  auto
  ClampLayout::get_maximum_size () const -> int
  {
    return adw_clamp_layout_get_maximum_size (
        const_cast<AdwClampLayout*> (gobj ()));
  }

  auto
  ClampLayout::get_tightening_threshold () const -> int
  {
    return adw_clamp_layout_get_tightening_threshold (
        const_cast<AdwClampLayout*> (gobj ()));
  }

  auto
  ClampLayout::get_maximum_size (int maximum_size) -> void
  {
    adw_clamp_layout_set_maximum_size (gobj (), maximum_size);
  }

  auto
  ClampLayout::get_tightening_threshold (int tightening_threshold) -> void
  {
    adw_clamp_layout_set_tightening_threshold (gobj (), tightening_threshold);
  }

  auto
  ClampLayout::property_maximum_size () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "maximum-size");
  }

  auto
  ClampLayout::property_maximum_size () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "maximum-size");
  }

  auto
  ClampLayout::property_tightening_threshold () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "tightening-threshold");
  }

  auto
  ClampLayout::property_tightening_threshold () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "tightening-threshold");
  }

} // namespace Adw
