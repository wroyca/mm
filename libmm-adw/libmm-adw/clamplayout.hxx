// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_CLAMPLAYOUT_H
#define _LIBADWAITAMM_CLAMPLAYOUT_H

#include <libmm-adw/mm-adwconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/mm-gtk.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class ClampLayout_Class;
}
#endif

namespace Adw
{

  class ClampLayout : public Gtk::LayoutManager,
                      public Gtk::Orientable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ClampLayout;
    using CppClassType = ClampLayout_Class;
    using BaseObjectType = AdwClampLayout;
    using BaseClassType = AdwClampLayoutClass;

    ClampLayout (const ClampLayout&) = delete;
    auto
    operator= (const ClampLayout&) -> ClampLayout& = delete;

  private:
    friend class ClampLayout_Class;
    static CppClassType clamplayout_class_;

  protected:
    explicit ClampLayout (const Glib::ConstructParams& construct_params);
    explicit ClampLayout (AdwClampLayout* castitem);

#endif

  public:
    ClampLayout (ClampLayout&& src) noexcept;
    auto
    operator= (ClampLayout&& src) noexcept -> ClampLayout&;

    ~ClampLayout () noexcept override;

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
    ClampLayout ();

  public:
    static auto
    create () -> Glib::RefPtr<ClampLayout>;

    auto
    get_maximum_size () const -> int;

    auto
    get_tightening_threshold () const -> int;

    auto
    get_maximum_size (int maximum_size) -> void;

    auto
    get_tightening_threshold (int tightening_threshold) -> void;

    auto
    property_maximum_size () -> Glib::PropertyProxy<int>;

    auto
    property_maximum_size () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_tightening_threshold () -> Glib::PropertyProxy<int>;

    auto
    property_tightening_threshold () const -> Glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwClampLayout* object, bool take_copy = false) -> Glib::RefPtr<Adw::ClampLayout>;
}

#endif
