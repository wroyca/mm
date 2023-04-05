// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_SPRINGPARAMS_H
#define _LIBADWAITAMM_SPRINGPARAMS_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/mm-gtk.hxx>

#include <adwaita.h>

namespace adw
{

  struct DampingRatio
  {
    double damping_ratio;
  };

  struct Damping
  {
    double damping;
  };

  class LIBMM_ADW_SYMEXPORT SpringParams
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = SpringParams;
    using BaseObjectType = AdwSpringParams;
#endif

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> AdwSpringParams*;

    auto
    gobj () const -> const AdwSpringParams*;

    auto
    gobj_copy () const -> AdwSpringParams*;

    SpringParams () = delete;

    SpringParams (const SpringParams&) = delete;
    auto
    operator= (const SpringParams&) -> SpringParams& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  public:
    static auto
    create (DampingRatio damping_ratio, double mass, double stiffness)
        -> glib::RefPtr<SpringParams>;

    static auto
    create (Damping damping, double mass, double stiffness)
        -> glib::RefPtr<SpringParams>;

    auto
    get_damping () const -> double;

    auto
    get_damping_ratio () const -> double;

    auto
    get_mass () const -> double;

    auto
    get_stiffness () const -> double;
  };

} // namespace adw

namespace glib
{

  template <>
  class LIBMM_ADW_SYMEXPORT Value<glib::RefPtr<adw::SpringParams>> : public ValueBase_Boxed
  {
  public:
    typedef glib::RefPtr<adw::SpringParams> CppType;
    typedef AdwSpringParams* CType;

    static auto
    value_type () -> GType;

    auto
    set (const CppType& data) -> void;
    auto
    get () const -> CppType;
  };

} // namespace glib

namespace glib
{

  auto
  wrap (AdwSpringParams* object, bool take_copy = false) -> glib::RefPtr<adw::SpringParams>;

}

#endif
