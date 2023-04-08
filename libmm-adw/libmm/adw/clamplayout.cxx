// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/clamplayout.hxx>
#include <libmm/adw/clamplayout_p.hxx>

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
  wrap (AdwClampLayout* object, bool take_copy) -> glib::RefPtr<adw::clamp_layout>
  {
    return glib::make_refptr_for_instance<adw::clamp_layout> (
        dynamic_cast<adw::clamp_layout*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  clamp_layout_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_clamp_layout_get_type ();
    }

    return *this;
  }

  auto
  clamp_layout_class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new clamp_layout ((AdwClampLayout*) object);
  }

  auto
  clamp_layout::gobj_copy () -> AdwClampLayout*
  {
    reference ();
    return gobj ();
  }

  clamp_layout::clamp_layout (const glib::ConstructParams& construct_params)
    : gtk::LayoutManager (construct_params)
  {
  }

  clamp_layout::clamp_layout (AdwClampLayout* castitem)
    : gtk::LayoutManager ((GtkLayoutManager*) (castitem))
  {
  }

  clamp_layout::clamp_layout (clamp_layout&& src) noexcept
    : gtk::LayoutManager (std::move (src)),
      gtk::Orientable (std::move (src))
  {
  }

  auto
  clamp_layout::operator= (clamp_layout&& src) noexcept -> clamp_layout&
  {
    gtk::LayoutManager::operator= (std::move (src));
    gtk::Orientable::operator= (std::move (src));
    return *this;
  }

  clamp_layout::~clamp_layout () noexcept {}

  clamp_layout::CppClassType clamp_layout::clamplayout_class_;

  auto
  clamp_layout::get_type () -> GType
  {
    return clamplayout_class_.init ().get_type ();
  }

  auto
  clamp_layout::get_base_type () -> GType
  {
    return adw_clamp_layout_get_type ();
  }

  clamp_layout::clamp_layout ()
    : glib::ObjectBase (nullptr),
      gtk::LayoutManager (glib::ConstructParams (clamplayout_class_.init ()))
  {
  }

  auto
  clamp_layout::create () -> glib::RefPtr<clamp_layout>
  {
    return glib::make_refptr_for_instance<clamp_layout> (new clamp_layout ());
  }

  auto
  clamp_layout::get_maximum_size () const -> int
  {
    return adw_clamp_layout_get_maximum_size (
        const_cast<AdwClampLayout*> (gobj ()));
  }

  auto
  clamp_layout::get_tightening_threshold () const -> int
  {
    return adw_clamp_layout_get_tightening_threshold (
        const_cast<AdwClampLayout*> (gobj ()));
  }

  auto
  clamp_layout::get_maximum_size (int maximum_size) -> void
  {
    adw_clamp_layout_set_maximum_size (gobj (), maximum_size);
  }

  auto
  clamp_layout::get_tightening_threshold (int tightening_threshold) -> void
  {
    adw_clamp_layout_set_tightening_threshold (gobj (), tightening_threshold);
  }

  auto
  clamp_layout::property_maximum_size () -> glib::PropertyProxy<int>
  {
    return {this, "maximum-size"};
  }

  auto
  clamp_layout::property_maximum_size () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "maximum-size"};
  }

  auto
  clamp_layout::property_tightening_threshold () -> glib::PropertyProxy<int>
  {
    return {this, "tightening-threshold"};
  }

  auto
  clamp_layout::property_tightening_threshold () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "tightening-threshold"};
  }

} // namespace adw
