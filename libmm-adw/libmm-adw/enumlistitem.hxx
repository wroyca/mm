// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_ENUMLISTITEM_H
#define _LIBADWAITAMM_ENUMLISTITEM_H

#include <libmm-adw/mm-adwconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/mm-glib.hxx>
#include <libmm-gtk/mm-gtk.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class EnumListItem_Class;
}
#endif

namespace Adw
{

  class EnumListItem : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = EnumListItem;
    using CppClassType = EnumListItem_Class;
    using BaseObjectType = AdwEnumListItem;
    using BaseClassType = AdwEnumListItemClass;

    EnumListItem (const EnumListItem&) = delete;
    auto
    operator= (const EnumListItem&) -> EnumListItem& = delete;

  private:
    friend class EnumListItem_Class;
    static CppClassType enumlistitem_class_;

  protected:
    explicit EnumListItem (const Glib::ConstructParams& construct_params);
    explicit EnumListItem (AdwEnumListItem* castitem);

#endif

  public:
    EnumListItem (EnumListItem&& src) noexcept;
    auto
    operator= (EnumListItem&& src) noexcept -> EnumListItem&;

    ~EnumListItem () noexcept override;

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
    EnumListItem ();

  public:
    static auto
    create () -> Glib::RefPtr<EnumListItem>;

    auto
    get_name () const -> Glib::ustring;

    auto
    get_nick () const -> Glib::ustring;

    auto
    get_value () const -> int;

    auto
    property_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_nick () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_value () const -> Glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwEnumListItem* object, bool take_copy = false) -> Glib::RefPtr<Adw::EnumListItem>;
}

#endif
