// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_ENUMLISTMODEL_H
#define _LIBADWAITAMM_ENUMLISTMODEL_H

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
  class LIBMM_ADW_SYMEXPORT enum_list_model_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT enum_list_model : public glib::Object,
                        public gio::ListModel
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = enum_list_model;
    using CppClassType = enum_list_model_class;
    using BaseObjectType = AdwEnumListModel;
    using BaseClassType = AdwEnumListModelClass;

    enum_list_model (const enum_list_model&) = delete;
    auto
    operator= (const enum_list_model&) -> enum_list_model& = delete;

  private:
    friend class enum_list_model_class;
    static CppClassType enumlistmodel_class_;

  protected:
    explicit enum_list_model (const glib::ConstructParams& construct_params);
    explicit enum_list_model (AdwEnumListModel* castitem);

#endif

  public:
    enum_list_model (enum_list_model&& src) noexcept;
    auto
    operator= (enum_list_model&& src) noexcept -> enum_list_model&;

    ~enum_list_model () noexcept override;

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
    enum_list_model ();
    explicit enum_list_model (GType enum_type);

  public:
    static auto
    create (GType enum_type) -> glib::RefPtr<enum_list_model>;

    auto
    find_position (int value) const -> guint;

    auto
    get_enum_type () const -> GType;

    auto
    property_enum_type () const -> glib::PropertyProxy_ReadOnly<GType>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwEnumListModel* object, bool take_copy = false) -> glib::RefPtr<adw::enum_list_model>;
}

#endif
