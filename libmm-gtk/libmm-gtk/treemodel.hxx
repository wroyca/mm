
#ifndef _GTKMM_TREEMODEL_H
#define _GTKMM_TREEMODEL_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <vector>

#include <gtk/gtk.h>
#include <libmm-glib/interface.hxx>
#include <libmm-gtk/treeiter.hxx>
#include <libmm-gtk/treemodelcolumn.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTreeModel = struct _GtkTreeModel;
using GtkTreeModelClass = struct _GtkTreeModelClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API TreeModel_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API TreeModelFilter;
  class GTKMM_API TreeModelSort;
  class GTKMM_API TreePath;
  class GTKMM_API TreeRowReference;

  class GTKMM_API TreeModel : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = TreeModel;
    using CppClassType = TreeModel_Class;
    using BaseObjectType = GtkTreeModel;
    using BaseClassType = GtkTreeModelIface;

    TreeModel (const TreeModel&) = delete;
    auto
    operator= (const TreeModel&) -> TreeModel& = delete;

  private:
    friend class TreeModel_Class;
    static CppClassType treemodel_class_;

#endif
  protected:
    TreeModel ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit TreeModel (const Glib::Interface_Class& interface_class);

  public:
    explicit TreeModel (GtkTreeModel* castitem);

  protected:
#endif

  public:
    TreeModel (TreeModel&& src) noexcept;
    auto
    operator= (TreeModel&& src) noexcept -> TreeModel&;

    ~TreeModel () noexcept override;

    static void
    add_interface (GType gtype_implementer);

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkTreeModel*
    {
      return reinterpret_cast<GtkTreeModel*> (gobject_);
    }

    auto
    gobj () const -> const GtkTreeModel*
    {
      return reinterpret_cast<GtkTreeModel*> (gobject_);
    }

  private:
  public:
    typedef TreeModelColumnRecord ColumnRecord;

    typedef TreeNodeChildren Children;
    typedef TreeNodeConstChildren ConstChildren;
    typedef Children::iterator iterator;
    typedef ConstChildren::const_iterator const_iterator;

    typedef TreeConstRow ConstRow;
    typedef TreeRow Row;
    typedef TreePath Path;
    typedef TreeRowReference RowReference;

    enum class Flags
    {
      ITERS_PERSIST = 1 << 0,
      LIST_ONLY = 1 << 1
    };

    auto
    get_iter (const Path& path) -> iterator;

    auto
    get_iter (const Path& path) const -> const_iterator;

    auto
    get_iter (const Glib::ustring& path_string) -> iterator;

    auto
    get_iter (const Glib::ustring& path_string) const -> const_iterator;

    auto
    children () -> Children;

    auto
    children () const -> const ConstChildren;

    typedef sigc::slot<bool (const TreeModel::iterator&)> SlotForeachIter;

    void
    foreach_iter (const SlotForeachIter& slot);

    typedef sigc::slot<bool (const TreeModel::Path&)> SlotForeachPath;

    void
    foreach_path (const SlotForeachPath& slot);

    typedef sigc::slot<bool (const TreeModel::Path&,
                             const TreeModel::iterator&)>
        SlotForeachPathAndIter;

    void foreach (const SlotForeachPathAndIter& slot);

    auto
    get_flags () const -> Flags;

    auto
    get_n_columns () const -> int;

    auto
    get_column_type (int index) const -> GType;

    auto
    get_path (const const_iterator& iter) const -> TreeModel::Path;

    void
    row_changed (const Path& path, const const_iterator& iter);

    void
    row_inserted (const Path& path, const const_iterator& iter);

    void
    row_has_child_toggled (const Path& path, const const_iterator& iter);

    void
    row_deleted (const Path& path);

    void
    rows_reordered (const Path& path,
                    const const_iterator& iter,
                    const std::vector<int>& new_order);

    void
    rows_reordered (const Path& path, const std::vector<int>& new_order);

    void
    rows_reordered (const Path& path,
                    const const_iterator& iter,
                    int* new_order);

    auto
    get_string (const const_iterator& iter) const -> Glib::ustring;

    auto
    signal_row_changed ()
        -> Glib::SignalProxy<void (const TreeModel::Path&,
                                   const TreeModel::iterator&)>;

    auto
    signal_row_inserted ()
        -> Glib::SignalProxy<void (const TreeModel::Path&,
                                   const TreeModel::iterator&)>;

    auto
    signal_row_has_child_toggled ()
        -> Glib::SignalProxy<void (const TreeModel::Path&,
                                   const TreeModel::iterator&)>;

    auto
    signal_row_deleted () -> Glib::SignalProxy<void (const TreeModel::Path&)>;

    auto
    signal_rows_reordered () -> Glib::SignalProxy<
        void (const TreeModel::Path&, const TreeModel::iterator&, int*)>;

  protected:
    virtual auto
    get_flags_vfunc () const -> Flags;

    virtual auto
    get_n_columns_vfunc () const -> int;

    virtual auto
    get_column_type_vfunc (int index) const -> GType;

    virtual auto
    iter_next_vfunc (const iterator& iter, iterator& iter_next) const -> bool;

    virtual auto
    get_iter_vfunc (const Path& path, iterator& iter) const -> bool;

    virtual auto
    iter_children_vfunc (const iterator& parent, iterator& iter) const -> bool;

    virtual auto
    iter_parent_vfunc (const iterator& child, iterator& iter) const -> bool;

    virtual auto
    iter_nth_child_vfunc (const iterator& parent, int n, iterator& iter) const
        -> bool;

    virtual auto
    iter_nth_root_child_vfunc (int n, iterator& iter) const -> bool;

    virtual auto
    iter_has_child_vfunc (const const_iterator& iter) const -> bool;

    virtual auto
    iter_n_children_vfunc (const const_iterator& iter) const -> int;

    virtual auto
    iter_n_root_children_vfunc () const -> int;

    virtual void
    ref_node_vfunc (const iterator& iter) const;

    virtual void
    unref_node_vfunc (const iterator& iter) const;

    virtual auto
    get_path_vfunc (const const_iterator& iter) const -> TreeModel::Path;

    virtual void
    get_value_vfunc (const const_iterator& iter,
                     int column,
                     Glib::ValueBase& value) const;

    virtual void
    set_value_impl (const iterator& iter,
                    int column,
                    const Glib::ValueBase& value);

    virtual void
    get_value_impl (const const_iterator& iter,
                    int column,
                    Glib::ValueBase& value) const;

    friend GTKMM_API class Gtk::TreeModelFilter;
    friend GTKMM_API class Gtk::TreeModelSort;
    friend GTKMM_API class Gtk::TreeConstRow;
    friend GTKMM_API class Gtk::TreeRow;

  public:
  public:
  protected:
    virtual void
    on_row_changed (const TreeModel::Path& path,
                    const TreeModel::iterator& iter);

    virtual void
    on_row_inserted (const TreeModel::Path& path,
                     const TreeModel::iterator& iter);

    virtual void
    on_row_has_child_toggled (const TreeModel::Path& path,
                              const TreeModel::iterator& iter);

    virtual void
    on_row_deleted (const TreeModel::Path& path);

    virtual void
    on_rows_reordered (const TreeModel::Path& path,
                       const TreeModel::iterator& iter,
                       int* new_order);
  };

} // namespace Gtk

namespace Gtk
{

  inline auto
  operator| (TreeModel::Flags lhs, TreeModel::Flags rhs) -> TreeModel::Flags
  {
    return static_cast<TreeModel::Flags> (static_cast<unsigned> (lhs) |
                                          static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (TreeModel::Flags lhs, TreeModel::Flags rhs) -> TreeModel::Flags
  {
    return static_cast<TreeModel::Flags> (static_cast<unsigned> (lhs) &
                                          static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (TreeModel::Flags lhs, TreeModel::Flags rhs) -> TreeModel::Flags
  {
    return static_cast<TreeModel::Flags> (static_cast<unsigned> (lhs) ^
                                          static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(TreeModel::Flags flags) -> TreeModel::Flags
  {
    return static_cast<TreeModel::Flags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (TreeModel::Flags& lhs, TreeModel::Flags rhs) -> TreeModel::Flags&
  {
    return (lhs = static_cast<TreeModel::Flags> (static_cast<unsigned> (lhs) |
                                                 static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (TreeModel::Flags& lhs, TreeModel::Flags rhs) -> TreeModel::Flags&
  {
    return (lhs = static_cast<TreeModel::Flags> (static_cast<unsigned> (lhs) &
                                                 static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (TreeModel::Flags& lhs, TreeModel::Flags rhs) -> TreeModel::Flags&
  {
    return (lhs = static_cast<TreeModel::Flags> (static_cast<unsigned> (lhs) ^
                                                 static_cast<unsigned> (rhs)));
  }
} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::TreeModel::Flags>
    : public Glib::Value_Flags<Gtk::TreeModel::Flags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkTreeModel* object, bool take_copy = false) -> Glib::RefPtr<Gtk::TreeModel>;

} // namespace Glib

#endif
