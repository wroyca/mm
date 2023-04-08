// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/springparams.hxx>
#include <libmm/adw/springparams_p.hxx>

#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

}

namespace glib
{

  auto
  Value<RefPtr<adw::spring_params>>::value_type () -> GType
  {
    return adw_spring_params_get_type ();
  }

  auto
  Value<RefPtr<adw::spring_params>>::set (const CppType& data) -> void
  {
    set_boxed (glib::unwrap (data));
  }

  auto
  Value<RefPtr<adw::spring_params>>::get () const -> Value<RefPtr<adw::spring_params>>::CppType
  {
    return glib::wrap (static_cast<CType> (get_boxed ()), true);
  }

} // namespace glib

namespace
{
}

namespace glib
{

  auto
  wrap (AdwSpringParams* object, bool take_copy) -> glib::RefPtr<adw::spring_params>
  {
    if (take_copy && object)
      adw_spring_params_ref (object);

    return glib::make_refptr_for_instance<adw::spring_params> (
        reinterpret_cast<adw::spring_params*> (object));
  }

} // namespace glib

namespace adw
{

  auto
  spring_params::reference () const -> void
  {
    adw_spring_params_ref (
        reinterpret_cast<AdwSpringParams*> (const_cast<spring_params*> (this)));
  }

  auto
  spring_params::unreference () const -> void
  {
    adw_spring_params_unref (
        reinterpret_cast<AdwSpringParams*> (const_cast<spring_params*> (this)));
  }

  auto
  spring_params::gobj () -> AdwSpringParams*
  {
    return reinterpret_cast<AdwSpringParams*> (this);
  }

  auto
  spring_params::gobj () const -> const AdwSpringParams*
  {
    return reinterpret_cast<const AdwSpringParams*> (this);
  }

  auto
  spring_params::gobj_copy () const -> AdwSpringParams*
  {
    const auto gobject =
        reinterpret_cast<AdwSpringParams*> (const_cast<spring_params*> (this));
    adw_spring_params_ref (gobject);
    return gobject;
  }

  auto
  spring_params::create (DampingRatio damping_ratio,
                        double mass,
                        double stiffness) -> glib::RefPtr<spring_params>
  {
    return glib::wrap (
        adw_spring_params_new (damping_ratio.damping_ratio, mass, stiffness));
  }

  auto
  spring_params::create (Damping damping, double mass, double stiffness) -> glib::RefPtr<spring_params>
  {
    return glib::wrap (
        adw_spring_params_new_full (damping.damping, mass, stiffness));
  }

  auto
  spring_params::get_damping () const -> double
  {
    return adw_spring_params_get_damping (
        const_cast<AdwSpringParams*> (gobj ()));
  }

  auto
  spring_params::get_damping_ratio () const -> double
  {
    return adw_spring_params_get_damping_ratio (
        const_cast<AdwSpringParams*> (gobj ()));
  }

  auto
  spring_params::get_mass () const -> double
  {
    return adw_spring_params_get_mass (const_cast<AdwSpringParams*> (gobj ()));
  }

  auto
  spring_params::get_stiffness () const -> double
  {
    return adw_spring_params_get_stiffness (
        const_cast<AdwSpringParams*> (gobj ()));
  }

} // namespace adw
