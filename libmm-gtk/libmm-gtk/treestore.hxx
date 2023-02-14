// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREESTORE_H
#define _GTKMM_TREESTORE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <vector>

#include <libmm-gtk/buildable.hxx>
#include <libmm-gtk/treedragdest.hxx>
#include <libmm-gtk/treedragsource.hxx>
#include <libmm-gtk/treeiter.hxx>
#include <libmm-gtk/treemodel.hxx>
#include <libmm-gtk/treesortable.hxx>

#include <libmm-gtk/treepath.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTreeStore = struct _GtkTreeStore;
using GtkTreeStoreClass = struct _GtkTreeStoreClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API TreeStore_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API TreeStore : public Glib::Object,
                              public Gtk::TreeModel,
                              public TreeSortable,
                              public TreeDragSource,
                              public TreeDragDest,
                              public Buildable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = TreeStore;
    using CppClassType = TreeStore_Class;
    using BaseObjectType = GtkTreeStore;
    using BaseClassType = GtkTreeStoreClass;

    TreeStore (const TreeStore&) = delete;
    auto
    operator= (const TreeStore&) -> TreeStore& = delete;

  private:
    friend class TreeStore_Class;
    static CppClassType treestore_class_;

  protected:
    explicit TreeStore (const Glib::ConstructParams& construct_params);
    explicit TreeStore (GtkTreeStore* castitem);

#endif

  public:
    TreeStore (TreeStore&& src) noexcept;
    auto
    operator= (TreeStore&& src) noexcept -> TreeStore&;

    ~TreeStore () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkTreeStore*
    {
      return reinterpret_cast<GtkTreeStore*> (gobject_);
    }

    auto
    gobj () const -> const GtkTreeStore*
    {
      return reinterpret_cast<GtkTreeStore*> (gobject_);
    }

    auto
    gobj_copy () -> GtkTreeStore*;

  private:
  protected:
    TreeStore ();

    explicit TreeStore (const TreeModelColumnRecord& columns);

  public:
    static auto
    create (const TreeModelColumnRecord& columns) -> Glib::RefPtr<TreeStore>;

    void
    set_column_types (const TreeModelColumnRecord& columns);

    auto
    erase (const iterator& iter) -> iterator;

    auto
    insert (const iterator& iter) -> iterator;

    auto
    insert_after (const iterator& iter) -> iterator;

    auto
    prepend () -> iterator;

    auto
    prepend (const TreeNodeChildren& node) -> iterator;

    auto
    append () -> iterator;

    auto
    append (const TreeNodeChildren& node) -> iterator;

    void
    iter_swap (const iterator& a, const iterator& b);

    void
    move (const iterator& source, const iterator& destination);

    void
    reorder (const TreeNodeChildren& node, const std::vector<int>& new_order);

    void
    clear ();

    auto
    is_ancestor (const const_iterator& iter,
                 const const_iterator& descendant) const -> bool;

    auto
    iter_depth (const const_iterator& iter) const -> int;

    auto
    iter_is_valid (const const_iterator& iter) const -> bool;

  protected:
    void
    set_value_impl (const iterator& row,
                    int column,
                    const Glib::ValueBase& value) override;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkTreeStore* object, bool take_copy = false) -> Glib::RefPtr<Gtk::TreeStore>;
} // namespace Glib

#endif
