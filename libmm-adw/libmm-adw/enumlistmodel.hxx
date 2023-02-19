// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_ENUMLISTMODEL_H
#define _LIBADWAITAMM_ENUMLISTMODEL_H

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
  class LIBMM_ADW_SYMEXPORT EnumListModel_Class;
}
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT EnumListModel : public Glib::Object,
                        public Gio::ListModel
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = EnumListModel;
    using CppClassType = EnumListModel_Class;
    using BaseObjectType = AdwEnumListModel;
    using BaseClassType = AdwEnumListModelClass;

    EnumListModel (const EnumListModel&) = delete;
    auto
    operator= (const EnumListModel&) -> EnumListModel& = delete;

  private:
    friend class EnumListModel_Class;
    static CppClassType enumlistmodel_class_;

  protected:
    explicit EnumListModel (const Glib::ConstructParams& construct_params);
    explicit EnumListModel (AdwEnumListModel* castitem);

#endif

  public:
    EnumListModel (EnumListModel&& src) noexcept;
    auto
    operator= (EnumListModel&& src) noexcept -> EnumListModel&;

    ~EnumListModel () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwEnumListModel*
    {
      return reinterpret_cast<AdwEnumListModel*> (gobject_);
    }

    auto
    gobj () const -> const AdwEnumListModel*
    {
      return reinterpret_cast<AdwEnumListModel*> (gobject_);
    }

    auto
    gobj_copy () -> AdwEnumListModel*;

  private:
  protected:
    EnumListModel ();
    explicit EnumListModel (GType enum_type);

  public:
    static auto
    create (GType enum_type) -> Glib::RefPtr<EnumListModel>;

    auto
    find_position (int value) const -> guint;

    auto
    get_enum_type () const -> GType;

    auto
    property_enum_type () const -> Glib::PropertyProxy_ReadOnly<GType>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwEnumListModel* object, bool take_copy = false) -> Glib::RefPtr<Adw::EnumListModel>;
}

#endif
