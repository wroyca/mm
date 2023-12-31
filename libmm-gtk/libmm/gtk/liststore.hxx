// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_LISTSTORE_H
#define _GTKMM_LISTSTORE_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <vector>

  #include <libmm/gtk/buildable.hxx>
  #include <libmm/gtk/treedragdest.hxx>
  #include <libmm/gtk/treedragsource.hxx>
  #include <libmm/gtk/treeiter.hxx>
  #include <libmm/gtk/treemodel.hxx>
  #include <libmm/gtk/treesortable.hxx>

  #include <libmm/gtk/treepath.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkListStore = struct _GtkListStore;
using GtkListStoreClass = struct _GtkListStoreClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT ListStore_Class;
}
  #endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT ListStore : public glib::Object,
                              public TreeModel,
                              public TreeSortable,
                              public TreeDragSource,
                              public TreeDragDest,
                              public Buildable
  {
  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ListStore;
    using CppClassType = ListStore_Class;
    using BaseObjectType = GtkListStore;
    using BaseClassType = GtkListStoreClass;

    ListStore (const ListStore&) = delete;
    auto
    operator= (const ListStore&) -> ListStore& = delete;

  private:
    friend class ListStore_Class;
    static CppClassType liststore_class_;

  protected:
    explicit ListStore (const glib::ConstructParams& construct_params);
    explicit ListStore (GtkListStore* castitem);

  #endif

  public:
    ListStore (ListStore&& src) noexcept;
    auto
    operator= (ListStore&& src) noexcept -> ListStore&;

    ~ListStore () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkListStore*
    {
      return reinterpret_cast<GtkListStore*> (gobject_);
    }

    auto
    gobj () const -> const GtkListStore*
    {
      return reinterpret_cast<GtkListStore*> (gobject_);
    }

    auto
    gobj_copy () -> GtkListStore*;

  private:
  protected:
    ListStore ();

    explicit ListStore (const TreeModelColumnRecord& columns);

  public:
    static auto
    create (const TreeModelColumnRecord& columns) -> glib::RefPtr<ListStore>;

    auto
    set_column_types (const TreeModelColumnRecord& columns) -> void;

    auto
    erase (const iterator& iter) -> iterator;

    auto
    insert (const iterator& iter) -> iterator;

    auto
    insert_after (const iterator& iter) -> iterator;

    auto
    prepend () -> iterator;

    auto
    append () -> iterator;

    auto
    iter_swap (const iterator& a, const iterator& b) -> void;

    auto
    move (const iterator& source, const iterator& destination) -> void;

    auto
    reorder (const std::vector<int>& new_order) -> void;

    auto
    clear () -> void;

    auto
    iter_is_valid (const const_iterator& iter) const -> bool;

  protected:
    auto
    set_value_impl (const iterator& row,
                    int column,
                    const glib::ValueBase& value) -> void override;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkListStore* object, bool take_copy = false) -> glib::RefPtr<gtk::ListStore>;
} // namespace glib

#endif

#endif
