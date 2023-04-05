// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREELISTMODEL_H
#define _GTKMM_TREELISTMODEL_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/listmodel.hxx>
#include <libmm/glib/object.hxx>
#include <libmm/gtk/treelistrow.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT TreeListModel_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT TreeListModel : public glib::Object,
                                  public gio::ListModel
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
    explicit TreeListModel (const glib::ConstructParams& construct_params);
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
    using SlotCreateModel = sigc::slot<glib::RefPtr<gio::ListModel> (
        const glib::RefPtr<glib::ObjectBase>&)>;

  protected:
    TreeListModel (const glib::RefPtr<gio::ListModel>& root,
                   const SlotCreateModel& slot_create,
                   bool passthrough = false,
                   bool autoexpand = false);

  public:
    static auto
    create (const glib::RefPtr<gio::ListModel>& root,
            const SlotCreateModel& slot_create,
            bool passthrough = false,
            bool autoexpand = false) -> glib::RefPtr<TreeListModel>;

    auto
    get_model () -> glib::RefPtr<gio::ListModel>;

    auto
    get_model () const -> glib::RefPtr<const gio::ListModel>;

    auto
    get_passthrough () const -> bool;

    auto
    set_autoexpand (bool autoexpand = true) -> void;

    auto
    get_autoexpand () const -> bool;

    auto
    get_child_row (guint position) -> glib::RefPtr<TreeListRow>;

    auto
    get_child_row (guint position) const -> glib::RefPtr<const TreeListRow>;

    auto
    get_row (guint position) -> glib::RefPtr<TreeListRow>;

    auto
    get_row (guint position) const -> glib::RefPtr<const TreeListRow>;

    auto
    property_autoexpand () -> glib::PropertyProxy<bool>;

    auto
    property_autoexpand () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_item_type () const -> glib::PropertyProxy_ReadOnly<GType>;

    auto
    property_model () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>>;

    auto
    property_n_items () const -> glib::PropertyProxy_ReadOnly<unsigned int>;

    auto
    property_passthrough () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkTreeListModel* object, bool take_copy = false) -> glib::RefPtr<gtk::TreeListModel>;
} // namespace glib

#endif
