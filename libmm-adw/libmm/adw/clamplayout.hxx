// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_CLAMPLAYOUT_H
#define _LIBADWAITAMM_CLAMPLAYOUT_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/mm-gtk.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT clamp_layout_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT clamp_layout : public gtk::LayoutManager,
                      public gtk::Orientable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = clamp_layout;
    using CppClassType = clamp_layout_class;
    using BaseObjectType = AdwClampLayout;
    using BaseClassType = AdwClampLayoutClass;

    clamp_layout (const clamp_layout&) = delete;
    auto
    operator= (const clamp_layout&) -> clamp_layout& = delete;

  private:
    friend class clamp_layout_class;
    static CppClassType clamplayout_class_;

  protected:
    explicit clamp_layout (const glib::ConstructParams& construct_params);
    explicit clamp_layout (AdwClampLayout* castitem);

#endif

  public:
    clamp_layout (clamp_layout&& src) noexcept;
    auto
    operator= (clamp_layout&& src) noexcept -> clamp_layout&;

    ~clamp_layout () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwClampLayout*
    {
      return reinterpret_cast<AdwClampLayout*> (gobject_);
    }

    auto
    gobj () const -> const AdwClampLayout*
    {
      return reinterpret_cast<AdwClampLayout*> (gobject_);
    }

    auto
    gobj_copy () -> AdwClampLayout*;

  private:
  protected:
    clamp_layout ();

  public:
    static auto
    create () -> glib::RefPtr<clamp_layout>;

    auto
    get_maximum_size () const -> int;

    auto
    get_tightening_threshold () const -> int;

    auto
    get_maximum_size (int maximum_size) -> void;

    auto
    get_tightening_threshold (int tightening_threshold) -> void;

    auto
    property_maximum_size () -> glib::PropertyProxy<int>;

    auto
    property_maximum_size () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_tightening_threshold () -> glib::PropertyProxy<int>;

    auto
    property_tightening_threshold () const -> glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwClampLayout* object, bool take_copy = false) -> glib::RefPtr<adw::clamp_layout>;
}

#endif
