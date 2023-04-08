// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_ENUMLISTITEM_H
#define _LIBADWAITAMM_ENUMLISTITEM_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/mm-glib.hxx>
#include <libmm/gtk/mm-gtk.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT enum_list_item_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT enum_list_item : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = enum_list_item;
    using CppClassType = enum_list_item_class;
    using BaseObjectType = AdwEnumListItem;
    using BaseClassType = AdwEnumListItemClass;

    enum_list_item (const enum_list_item&) = delete;
    auto
    operator= (const enum_list_item&) -> enum_list_item& = delete;

  private:
    friend class enum_list_item_class;
    static CppClassType enumlistitem_class_;

  protected:
    explicit enum_list_item (const glib::ConstructParams& construct_params);
    explicit enum_list_item (AdwEnumListItem* castitem);

#endif

  public:
    enum_list_item (enum_list_item&& src) noexcept;
    auto
    operator= (enum_list_item&& src) noexcept -> enum_list_item&;

    ~enum_list_item () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwEnumListItem*
    {
      return reinterpret_cast<AdwEnumListItem*> (gobject_);
    }

    auto
    gobj () const -> const AdwEnumListItem*
    {
      return reinterpret_cast<AdwEnumListItem*> (gobject_);
    }

    auto
    gobj_copy () -> AdwEnumListItem*;

  private:
  protected:
    enum_list_item ();

  public:
    static auto
    create () -> glib::RefPtr<enum_list_item>;

    auto
    get_name () const -> glib::ustring;

    auto
    get_nick () const -> glib::ustring;

    auto
    get_value () const -> int;

    auto
    property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_nick () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_value () const -> glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwEnumListItem* object, bool take_copy = false) -> glib::RefPtr<adw::enum_list_item>;
}

#endif
