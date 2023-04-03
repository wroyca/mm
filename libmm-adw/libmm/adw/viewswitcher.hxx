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
namespace Adw
{
  class LIBMM_ADW_SYMEXPORT ViewSwitcher_Class;
}
#endif

namespace Adw
{

  enum class LIBMM_ADW_SYMEXPORT ViewSwitcherPolicy
  {
    NARROW,
    WIDE
  };

} // namespace Adw

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_ADW_SYMEXPORT Value<Adw::ViewSwitcherPolicy>
    : public Glib::Value_Enum<Adw::ViewSwitcherPolicy>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT ViewSwitcher : public Gtk::Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ViewSwitcher CppObjectType;
    typedef ViewSwitcher_Class CppClassType;
    typedef AdwViewSwitcher BaseObjectType;
    typedef AdwViewSwitcherClass BaseClassType;
#endif

    ViewSwitcher (ViewSwitcher&& src) noexcept;
    auto
    operator= (ViewSwitcher&& src) noexcept -> ViewSwitcher&;

    ViewSwitcher (const ViewSwitcher&) = delete;
    auto
    operator= (const ViewSwitcher&) -> ViewSwitcher& = delete;

    ~ViewSwitcher () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class ViewSwitcher_Class;
    static CppClassType viewswitcher_class_;

  protected:
    explicit ViewSwitcher (const Glib::ConstructParams& construct_params);
    explicit ViewSwitcher (AdwViewSwitcher* castitem);

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
    ViewSwitcher ();

    auto
    get_policy () const -> ViewSwitcherPolicy;

    auto
    get_stack () const -> ViewStack*;

    auto
    set_policy (ViewSwitcherPolicy policy) -> void;

    auto
    set_stack (ViewStack* stack) -> void;

    auto
    property_policy () -> Glib::PropertyProxy<ViewSwitcherPolicy>;

    auto
    property_policy () const
        -> Glib::PropertyProxy_ReadOnly<ViewSwitcherPolicy>;

    auto
    property_stack () -> Glib::PropertyProxy<ViewStack*>;

    auto
    property_stack () const -> Glib::PropertyProxy_ReadOnly<ViewStack*>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwViewSwitcher* object, bool take_copy = false) -> Adw::ViewSwitcher*;
}

#endif
