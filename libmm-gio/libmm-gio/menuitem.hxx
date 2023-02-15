// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_MENUITEM_H
#define _GIOMM_MENUITEM_H

#include <libmm-gio/mm-gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/icon.hxx>
#include <libmm-gio/menumodel.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GMenuItem = struct _GMenuItem;
using GMenuItemClass = struct _GMenuItemClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT MenuItem_Class;
}
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT MenuItem : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = MenuItem;
    using CppClassType = MenuItem_Class;
    using BaseObjectType = GMenuItem;
    using BaseClassType = GMenuItemClass;

    MenuItem (const MenuItem&) = delete;
    auto
    operator= (const MenuItem&) -> MenuItem& = delete;

  private:
    friend class MenuItem_Class;
    static CppClassType menuitem_class_;

  protected:
    explicit MenuItem (const Glib::ConstructParams& construct_params);
    explicit MenuItem (GMenuItem* castitem);

#endif

  public:
    MenuItem (MenuItem&& src) noexcept;
    auto
    operator= (MenuItem&& src) noexcept -> MenuItem&;

    ~MenuItem () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GMenuItem*
    {
      return reinterpret_cast<GMenuItem*> (gobject_);
    }

    auto
    gobj () const -> const GMenuItem*
    {
      return reinterpret_cast<GMenuItem*> (gobject_);
    }

    auto
    gobj_copy () -> GMenuItem*;

  private:
  protected:
    explicit MenuItem (const Glib::ustring& label = {},
                       const Glib::ustring& detailed_action = {});

    explicit MenuItem (const Glib::ustring& label,
                       const Glib::RefPtr<MenuModel>& submenu);

    explicit MenuItem (const Glib::RefPtr<MenuModel>& submenu);

  public:
    static auto
    create (const Glib::ustring& label, const Glib::ustring& detailed_action)
        -> Glib::RefPtr<MenuItem>;

    static auto
    create (const Glib::ustring& label, const Glib::RefPtr<MenuModel>& submenu)
        -> Glib::RefPtr<MenuItem>;

    static auto
    create (const Glib::RefPtr<MenuModel>& submenu) -> Glib::RefPtr<MenuItem>;

    auto
    set_attribute_value (const Glib::ustring& attribute,
                         const Glib::VariantBase& value) -> void;

    auto
    get_link (const Glib::ustring& link) -> Glib::RefPtr<MenuModel>;

    auto
    get_link (const Glib::ustring& link) const -> Glib::RefPtr<const MenuModel>;

    auto
    set_link (const Glib::ustring& link, const Glib::RefPtr<MenuModel>& model)
        -> void;

    auto
    set_label (const Glib::ustring& label) -> void;

    auto
    set_submenu (const Glib::RefPtr<MenuModel>& submenu) -> void;

    auto
    set_section (const Glib::RefPtr<MenuModel>& section) -> void;

    auto
    get_attribute_value (const Glib::ustring& attribute,
                         const Glib::VariantType& expected_type) const
        -> Glib::VariantBase;

    auto
    get_attribute_value (const Glib::ustring& attribute) const
        -> Glib::VariantBase;

    auto
    set_action (const Glib::ustring& action) -> void;

    auto
    unset_target () -> void;

    auto
    unset_action_and_target () -> void;

    auto
    set_action_and_target (const Glib::ustring& action,
                           const Glib::VariantBase& target_value) -> void;

    auto
    set_detailed_action (const Glib::ustring& detailed_action) -> void;

    auto
    set_icon (const Glib::RefPtr<Icon>& icon) -> void;

    auto
    unset_icon () -> void;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GMenuItem* object, bool take_copy = false) -> Glib::RefPtr<Gio::MenuItem>;
} // namespace Glib

#endif
