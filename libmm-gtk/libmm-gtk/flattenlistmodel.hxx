// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FLATTENLISTMODEL_H
#define _GTKMM_FLATTENLISTMODEL_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm-gio/listmodel.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API FlattenListModel_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API FlattenListModel : public Glib::Object,
                                     public Gio::ListModel
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
    explicit FlattenListModel (const Glib::ConstructParams& construct_params);
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
    explicit FlattenListModel (const Glib::RefPtr<Gio::ListModel>& model);

  public:
    static auto
    create (const Glib::RefPtr<Gio::ListModel>& model)
        -> Glib::RefPtr<FlattenListModel>;

    void
    set_model (const Glib::RefPtr<Gio::ListModel>& model);

    auto
    get_model () -> Glib::RefPtr<Gio::ListModel>;

    auto
    get_model () const -> Glib::RefPtr<const Gio::ListModel>;

    auto
    get_model_for_item (guint position) -> Glib::RefPtr<Gio::ListModel>;

    auto
    property_item_type () const -> Glib::PropertyProxy_ReadOnly<GType>;

    auto
    property_model () -> Glib::PropertyProxy<Glib::RefPtr<Gio::ListModel>>;

    auto
    property_model () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>>;

    auto
    property_n_items () const -> Glib::PropertyProxy_ReadOnly<unsigned int>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkFlattenListModel* object, bool take_copy = false) -> Glib::RefPtr<Gtk::FlattenListModel>;
} // namespace Glib

#endif
