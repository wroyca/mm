// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_MENUMODEL_H
#define _GIOMM_MENUMODEL_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GMenuModel = struct _GMenuModel;
using GMenuModelClass = struct _GMenuModelClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT MenuModel_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT MenuAttributeIter;
  class LIBMM_GIO_SYMEXPORT MenuLinkIter;

  class LIBMM_GIO_SYMEXPORT MenuModel : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = MenuModel;
    using CppClassType = MenuModel_Class;
    using BaseObjectType = GMenuModel;
    using BaseClassType = GMenuModelClass;

    MenuModel (const MenuModel&) = delete;
    auto
    operator= (const MenuModel&) -> MenuModel& = delete;

  private:
    friend class MenuModel_Class;
    static CppClassType menumodel_class_;

  protected:
    explicit MenuModel (const glib::ConstructParams& construct_params);
    explicit MenuModel (GMenuModel* castitem);

#endif

  public:
    MenuModel (MenuModel&& src) noexcept;
    auto
    operator= (MenuModel&& src) noexcept -> MenuModel&;

    ~MenuModel () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GMenuModel*
    {
      return reinterpret_cast<GMenuModel*> (gobject_);
    }

    auto
    gobj () const -> const GMenuModel*
    {
      return reinterpret_cast<GMenuModel*> (gobject_);
    }

    auto
    gobj_copy () -> GMenuModel*;

  private:
  protected:
    MenuModel ();

  public:
    enum class Attribute
    {
      ACTION,

      LABEL,

      TARGET,

      ACTION_NAMESPACE,

      ICON,
    };

    enum class Link
    {
      SECTION,

      SUBMENU
    };

    auto
    get_item_attribute (int item_index,
                        Attribute attribute,
                        const glib::VariantType& expected_type) const
        -> glib::VariantBase;

    auto
    get_item_link (int item_index, Link link) -> glib::RefPtr<MenuModel>;

    auto
    get_item_link (int item_index, Link link) const
        -> glib::RefPtr<const MenuModel>;

    auto
    is_mutable () const -> bool;

    auto
    get_n_items () const -> int;

    auto
    iterate_item_attributes (int item_index) -> glib::RefPtr<MenuAttributeIter>;

    auto
    iterate_item_attributes (int item_index) const
        -> glib::RefPtr<const MenuAttributeIter>;

    auto
    iterate_item_links (int item_index) -> glib::RefPtr<MenuLinkIter>;

    auto
    iterate_item_links (int item_index) const
        -> glib::RefPtr<const MenuLinkIter>;

    auto
    items_changed (int position, int removed, int added) -> void;

    auto
    signal_items_changed () -> glib::SignalProxy<void (int, int, int)>;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GMenuModel* object, bool take_copy = false) -> glib::RefPtr<gio::MenuModel>;
} // namespace glib

#endif
