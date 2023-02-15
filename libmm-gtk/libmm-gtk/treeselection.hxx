// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREESELECTION_H
#define _GTKMM_TREESELECTION_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <vector>

  #include <libmm-gtk/enums.hxx>
  #include <libmm-gtk/treeiter.hxx>
  #include <libmm-gtk/treemodel.hxx>
  #include <libmm-gtk/treepath.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTreeSelection = struct _GtkTreeSelection;
using GtkTreeSelectionClass = struct _GtkTreeSelectionClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT TreeSelection_Class;
}
  #endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT TreeView;

  class LIBMM_GTK_SYMEXPORT TreeSelection : public Glib::Object
  {
  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = TreeSelection;
    using CppClassType = TreeSelection_Class;
    using BaseObjectType = GtkTreeSelection;
    using BaseClassType = GtkTreeSelectionClass;

    TreeSelection (const TreeSelection&) = delete;
    auto
    operator= (const TreeSelection&) -> TreeSelection& = delete;

  private:
    friend class TreeSelection_Class;
    static CppClassType treeselection_class_;

  protected:
    explicit TreeSelection (const Glib::ConstructParams& construct_params);
    explicit TreeSelection (GtkTreeSelection* castitem);

  #endif

  public:
    TreeSelection (TreeSelection&& src) noexcept;
    auto
    operator= (TreeSelection&& src) noexcept -> TreeSelection&;

    ~TreeSelection () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkTreeSelection*
    {
      return reinterpret_cast<GtkTreeSelection*> (gobject_);
    }

    auto
    gobj () const -> const GtkTreeSelection*
    {
      return reinterpret_cast<GtkTreeSelection*> (gobject_);
    }

    auto
    gobj_copy () -> GtkTreeSelection*;

  private:
  public:
    auto
    set_mode (SelectionMode type) -> void;

    auto
    get_mode () const -> SelectionMode;

    using SlotSelect = sigc::slot<
        bool (const Glib::RefPtr<TreeModel>&, const TreeModel::Path&, bool)>;

    auto
    set_select_function (const SlotSelect& slot) -> void;

    auto
    get_tree_view () -> TreeView*;

    auto
    get_tree_view () const -> const TreeView*;

    auto
    get_model () -> Glib::RefPtr<TreeModel>;
    auto
    get_model () const -> Glib::RefPtr<const TreeModel>;

    auto
    get_selected () -> TreeModel::iterator;

    auto
    get_selected () const -> TreeModel::const_iterator;

    auto
    get_selected (Glib::RefPtr<TreeModel>& model) -> TreeModel::iterator;

    auto
    get_selected (Glib::RefPtr<const TreeModel>& model) const
        -> TreeModel::const_iterator;

    auto
    get_selected_rows () const -> std::vector<TreeModel::Path>;

    auto
    get_selected_rows (Glib::RefPtr<TreeModel>& model)
        -> std::vector<TreeModel::Path>;

    auto
    count_selected_rows () const -> int;

    using SlotForeachIter = sigc::slot<void (const TreeModel::const_iterator&)>;

    auto
    selected_foreach_iter (const SlotForeachIter& slot) const -> void;

    using SlotForeachPath = sigc::slot<void (const TreeModel::Path&)>;

    auto
    selected_foreach_path (const SlotForeachPath& slot) const -> void;

    using SlotForeachPathAndIter =
        sigc::slot<void (const TreeModel::Path&,
                         const TreeModel::const_iterator&)>;

    auto
    selected_foreach (const SlotForeachPathAndIter& slot) const -> void;

    auto
    select (const TreeModel::Path& path) -> void;

    auto
    select (const TreeModel::Path& start_path, const TreeModel::Path& end_path)
        -> void;

    auto
    select (const TreeModel::const_iterator& iter) -> void;

    auto
    unselect (const TreeModel::Path& path) -> void;

    auto
    unselect (const TreeModel::Path& start_path,
              const TreeModel::Path& end_path) -> void;

    auto
    unselect (const TreeModel::const_iterator& iter) -> void;

    auto
    is_selected (const TreeModel::Path& path) const -> bool;

    auto
    is_selected (const TreeModel::const_iterator& iter) const -> bool;

    auto
    select_all () -> void;

    auto
    unselect_all () -> void;

    auto
    property_mode () -> Glib::PropertyProxy<SelectionMode>;

    auto
    property_mode () const -> Glib::PropertyProxy_ReadOnly<SelectionMode>;

    auto
    signal_changed () -> Glib::SignalProxy<void ()>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkTreeSelection* object, bool take_copy = false) -> Glib::RefPtr<Gtk::TreeSelection>;
} // namespace Glib

#endif

#endif
