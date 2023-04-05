// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FLATTENLISTMODEL_H
#define _GTKMM_FLATTENLISTMODEL_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm/gio/listmodel.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT FlattenListModel_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT FlattenListModel : public glib::Object,
                                     public gio::ListModel
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = FlattenListModel;
    using CppClassType = FlattenListModel_Class;
    using BaseObjectType = GtkFlattenListModel;
    using BaseClassType = GtkFlattenListModelClass;

    FlattenListModel (const FlattenListModel&) = delete;
    auto
    operator= (const FlattenListModel&) -> FlattenListModel& = delete;

  private:
    friend class FlattenListModel_Class;
    static CppClassType flattenlistmodel_class_;

  protected:
    explicit FlattenListModel (const glib::ConstructParams& construct_params);
    explicit FlattenListModel (GtkFlattenListModel* castitem);

#endif

  public:
    FlattenListModel (FlattenListModel&& src) noexcept;
    auto
    operator= (FlattenListModel&& src) noexcept -> FlattenListModel&;

    ~FlattenListModel () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkFlattenListModel*
    {
      return reinterpret_cast<GtkFlattenListModel*> (gobject_);
    }

    auto
    gobj () const -> const GtkFlattenListModel*
    {
      return reinterpret_cast<GtkFlattenListModel*> (gobject_);
    }

    auto
    gobj_copy () -> GtkFlattenListModel*;

  private:
  protected:
    explicit FlattenListModel (const glib::RefPtr<gio::ListModel>& model);

  public:
    static auto
    create (const glib::RefPtr<gio::ListModel>& model)
        -> glib::RefPtr<FlattenListModel>;

    auto
    set_model (const glib::RefPtr<gio::ListModel>& model) -> void;

    auto
    get_model () -> glib::RefPtr<gio::ListModel>;

    auto
    get_model () const -> glib::RefPtr<const gio::ListModel>;

    auto
    get_model_for_item (guint position) -> glib::RefPtr<gio::ListModel>;

    auto
    property_item_type () const -> glib::PropertyProxy_ReadOnly<GType>;

    auto
    property_model () -> glib::PropertyProxy<glib::RefPtr<gio::ListModel>>;

    auto
    property_model () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>>;

    auto
    property_n_items () const -> glib::PropertyProxy_ReadOnly<unsigned int>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkFlattenListModel* object, bool take_copy = false) -> glib::RefPtr<gtk::FlattenListModel>;
} // namespace glib

#endif
