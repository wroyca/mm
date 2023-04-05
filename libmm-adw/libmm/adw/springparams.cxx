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
  Value<RefPtr<adw::SpringParams>>::value_type () -> GType
  {
    return adw_spring_params_get_type ();
  }

  auto
  Value<RefPtr<adw::SpringParams>>::set (const CppType& data) -> void
  {
    set_boxed (glib::unwrap (data));
  }

  auto
  Value<RefPtr<adw::SpringParams>>::get () const -> Value<RefPtr<adw::SpringParams>>::CppType
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
  wrap (AdwSpringParams* object, bool take_copy) -> glib::RefPtr<adw::SpringParams>
  {
    if (take_copy && object)
      adw_spring_params_ref (object);

    return glib::make_refptr_for_instance<adw::SpringParams> (
        reinterpret_cast<adw::SpringParams*> (object));
  }

} // namespace glib

namespace adw
{

  auto
  SpringParams::reference () const -> void
  {
    adw_spring_params_ref (
        reinterpret_cast<AdwSpringParams*> (const_cast<SpringParams*> (this)));
  }

  auto
  SpringParams::unreference () const -> void
  {
    adw_spring_params_unref (
        reinterpret_cast<AdwSpringParams*> (const_cast<SpringParams*> (this)));
  }

  auto
  SpringParams::gobj () -> AdwSpringParams*
  {
    return reinterpret_cast<AdwSpringParams*> (this);
  }

  auto
  SpringParams::gobj () const -> const AdwSpringParams*
  {
    return reinterpret_cast<const AdwSpringParams*> (this);
  }

  auto
  SpringParams::gobj_copy () const -> AdwSpringParams*
  {
    const auto gobject =
        reinterpret_cast<AdwSpringParams*> (const_cast<SpringParams*> (this));
    adw_spring_params_ref (gobject);
    return gobject;
  }

  auto
  SpringParams::create (DampingRatio damping_ratio,
                        double mass,
                        double stiffness) -> glib::RefPtr<SpringParams>
  {
    return glib::wrap (
        adw_spring_params_new (damping_ratio.damping_ratio, mass, stiffness));
  }

  auto
  SpringParams::create (Damping damping, double mass, double stiffness) -> glib::RefPtr<SpringParams>
  {
    return glib::wrap (
        adw_spring_params_new_full (damping.damping, mass, stiffness));
  }

  auto
  SpringParams::get_damping () const -> double
  {
    return adw_spring_params_get_damping (
        const_cast<AdwSpringParams*> (gobj ()));
  }

  auto
  SpringParams::get_damping_ratio () const -> double
  {
    return adw_spring_params_get_damping_ratio (
        const_cast<AdwSpringParams*> (gobj ()));
  }

  auto
  SpringParams::get_mass () const -> double
  {
    return adw_spring_params_get_mass (const_cast<AdwSpringParams*> (gobj ()));
  }

  auto
  SpringParams::get_stiffness () const -> double
  {
    return adw_spring_params_get_stiffness (
        const_cast<AdwSpringParams*> (gobj ()));
  }

} // namespace adw
