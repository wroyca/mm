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
  class LIBMM_ADW_SYMEXPORT EnumListItem_Class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT EnumListItem : public glib::Object
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
    explicit EnumListItem (const glib::ConstructParams& construct_params);
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
    create () -> glib::RefPtr<EnumListItem>;

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
  wrap (AdwEnumListItem* object, bool take_copy = false) -> glib::RefPtr<adw::EnumListItem>;
}

#endif
