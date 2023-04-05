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
  wrap (AdwClampLayout* object, bool take_copy) -> glib::RefPtr<adw::ClampLayout>
  {
    return glib::make_refptr_for_instance<adw::ClampLayout> (
        dynamic_cast<adw::ClampLayout*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  ClampLayout_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_clamp_layout_get_type ();
    }

    return *this;
  }

  auto
  ClampLayout_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new ClampLayout ((AdwClampLayout*) object);
  }

  auto
  ClampLayout::gobj_copy () -> AdwClampLayout*
  {
    reference ();
    return gobj ();
  }

  ClampLayout::ClampLayout (const glib::ConstructParams& construct_params)
    : gtk::LayoutManager (construct_params)
  {
  }

  ClampLayout::ClampLayout (AdwClampLayout* castitem)
    : gtk::LayoutManager ((GtkLayoutManager*) (castitem))
  {
  }

  ClampLayout::ClampLayout (ClampLayout&& src) noexcept
    : gtk::LayoutManager (std::move (src)),
      gtk::Orientable (std::move (src))
  {
  }

  auto
  ClampLayout::operator= (ClampLayout&& src) noexcept -> ClampLayout&
  {
    gtk::LayoutManager::operator= (std::move (src));
    gtk::Orientable::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::LayoutManager (glib::ConstructParams (clamplayout_class_.init ()))
  {
  }

  auto
  ClampLayout::create () -> glib::RefPtr<ClampLayout>
  {
    return glib::make_refptr_for_instance<ClampLayout> (new ClampLayout ());
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
  ClampLayout::property_maximum_size () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "maximum-size");
  }

  auto
  ClampLayout::property_maximum_size () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "maximum-size");
  }

  auto
  ClampLayout::property_tightening_threshold () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "tightening-threshold");
  }

  auto
  ClampLayout::property_tightening_threshold () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "tightening-threshold");
  }

} // namespace adw
