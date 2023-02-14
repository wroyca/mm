// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREELISTMODEL_H
#define _GTKMM_TREELISTMODEL_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/listmodel.hxx>
#include <libmm-glib/object.hxx>
#include <libmm-gtk/treelistrow.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API TreeListModel_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API TreeListModel : public Glib::Object,
                                  public Gio::ListModel
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = TreeListModel;
    using CppClassType = TreeListModel_Class;
    using BaseObjectType = GtkTreeListModel;
    using BaseClassType = GtkTreeListModelClass;

    TreeListModel (const TreeListModel&) = delete;
    auto
    operator= (const TreeListModel&) -> TreeListModel& = delete;

  private:
    friend class TreeListModel_Class;
    static CppClassType treelistmodel_class_;

  protected:
    explicit TreeListModel (const Glib::ConstructParams& construct_params);
    explicit TreeListModel (GtkTreeListModel* castitem);

#endif

  public:
    TreeListModel (TreeListModel&& src) noexcept;
    auto
    operator= (TreeListModel&& src) noexcept -> TreeListModel&;

    ~TreeListModel () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkTreeListModel*
    {
      return reinterpret_cast<GtkTreeListModel*> (gobject_);
    }

    auto
    gobj () const -> const GtkTreeListModel*
    {
      return reinterpret_cast<GtkTreeListModel*> (gobject_);
    }

    auto
    gobj_copy () -> GtkTreeListModel*;

  private:
  public:
    using SlotCreateModel = sigc::slot<Glib::RefPtr<Gio::ListModel> (
        const Glib::RefPtr<Glib::ObjectBase>&)>;

  protected:
    TreeListModel (const Glib::RefPtr<Gio::ListModel>& root,
                   const SlotCreateModel& slot_create,
                   bool passthrough = false,
                   bool autoexpand = false);

  public:
    static auto
    create (const Glib::RefPtr<Gio::ListModel>& root,
            const SlotCreateModel& slot_create,
            bool passthrough = false,
            bool autoexpand = false) -> Glib::RefPtr<TreeListModel>;

    auto
    get_model () -> Glib::RefPtr<Gio::ListModel>;

    auto
    get_model () const -> Glib::RefPtr<const Gio::ListModel>;

    auto
    get_passthrough () const -> bool;

    void
    set_autoexpand (bool autoexpand = true);

    auto
    get_autoexpand () const -> bool;

    auto
    get_child_row (guint position) -> Glib::RefPtr<TreeListRow>;

    auto
    get_child_row (guint position) const -> Glib::RefPtr<const TreeListRow>;

    auto
    get_row (guint position) -> Glib::RefPtr<TreeListRow>;

    auto
    get_row (guint position) const -> Glib::RefPtr<const TreeListRow>;

    auto
    property_autoexpand () -> Glib::PropertyProxy<bool>;

    auto
    property_autoexpand () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_item_type () const -> Glib::PropertyProxy_ReadOnly<GType>;

    auto
    property_model () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>>;

    auto
    property_n_items () const -> Glib::PropertyProxy_ReadOnly<unsigned int>;

    auto
    property_passthrough () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkTreeListModel* object, bool take_copy = false) -> Glib::RefPtr<Gtk::TreeListModel>;
} // namespace Glib

#endif
