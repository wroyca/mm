// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_VIEWSWITCHER_H
#define _LIBADWAITAMM_VIEWSWITCHER_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/mm-gtk.hxx>

#include <adwaita.h>
#include <libmm/adw/viewstack.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT view_switcher_class;
}
#endif

namespace adw
{

  enum class LIBMM_ADW_SYMEXPORT view_switcher_policy
  {
    NARROW,
    WIDE
  };

} // namespace adw

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_ADW_SYMEXPORT Value<adw::view_switcher_policy>
    : public glib::Value_Enum<adw::view_switcher_policy>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT view_switcher : public gtk::Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = view_switcher;
    using CppClassType = view_switcher_class;
    using BaseObjectType = AdwViewSwitcher;
    using BaseClassType = AdwViewSwitcherClass;
#endif

    view_switcher (view_switcher&& src) noexcept;
    auto
    operator= (view_switcher&& src) noexcept -> view_switcher&;

    view_switcher (const view_switcher&) = delete;
    auto
    operator= (const view_switcher&) -> view_switcher& = delete;

    ~view_switcher () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class view_switcher_class;
    static CppClassType viewswitcher_class_;

  protected:
    explicit view_switcher (const glib::ConstructParams& construct_params);
    explicit view_switcher (AdwViewSwitcher* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwViewSwitcher*
    {
      return reinterpret_cast<AdwViewSwitcher*> (gobject_);
    }

    auto
    gobj () const -> const AdwViewSwitcher*
    {
      return reinterpret_cast<AdwViewSwitcher*> (gobject_);
    }

  private:
  public:
    view_switcher ();

    auto
    get_policy () const -> view_switcher_policy;

    auto
    get_stack () const -> view_stack*;

    auto
    set_policy (view_switcher_policy policy) -> void;

    auto
    set_stack (view_stack* stack) -> void;

    auto
    property_policy () -> glib::PropertyProxy<view_switcher_policy>;

    auto
    property_policy () const
        -> glib::PropertyProxy_ReadOnly<view_switcher_policy>;

    auto
    property_stack () -> glib::PropertyProxy<view_stack*>;

    auto
    property_stack () const -> glib::PropertyProxy_ReadOnly<view_stack*>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwViewSwitcher* object, bool take_copy = false) -> adw::view_switcher*;
}

#endif
