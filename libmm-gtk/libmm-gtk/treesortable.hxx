// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREESORTABLE_H
#define _GTKMM_TREESORTABLE_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm-glib/interface.hxx>
  #include <libmm-gtk/enums.hxx>
  #include <libmm-gtk/treeiter.hxx>
  #include <libmm-gtk/treemodel.hxx>
  #include <libmm-gtk/treemodelcolumn.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkTreeSortableIface GtkTreeSortableIface;
}
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTreeSortable = struct _GtkTreeSortable;
using GtkTreeSortableClass = struct _GtkTreeSortableClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT TreeSortable_Class;
}
  #endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT TreeSortable : public Glib::Interface
  {
  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = TreeSortable;
    using CppClassType = TreeSortable_Class;
    using BaseObjectType = GtkTreeSortable;
    using BaseClassType = GtkTreeSortableIface;

    TreeSortable (const TreeSortable&) = delete;
    auto
    operator= (const TreeSortable&) -> TreeSortable& = delete;

  private:
    friend class TreeSortable_Class;
    static CppClassType treesortable_class_;

  #endif
  protected:
    TreeSortable ();

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit TreeSortable (const Glib::Interface_Class& interface_class);

  public:
    explicit TreeSortable (GtkTreeSortable* castitem);

  protected:
  #endif

  public:
    TreeSortable (TreeSortable&& src) noexcept;
    auto
    operator= (TreeSortable&& src) noexcept -> TreeSortable&;

    ~TreeSortable () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkTreeSortable*
    {
      return reinterpret_cast<GtkTreeSortable*> (gobject_);
    }

    auto
    gobj () const -> const GtkTreeSortable*
    {
      return reinterpret_cast<GtkTreeSortable*> (gobject_);
    }

  private:
  public:
    enum
    {
      DEFAULT_SORT_COLUMN_ID = -1,
      DEFAULT_UNSORTED_COLUMN_ID = -2
    };

    auto
    get_sort_column_id (int& sort_column_id, SortType& order) const -> bool;

    auto
    set_sort_column (const TreeModelColumnBase& sort_column_id, SortType order)
        -> void;

    auto
    set_sort_column (int sort_column_id, SortType order) -> void;

    typedef sigc::slot<int (const Gtk::TreeModel::const_iterator&,
                            const Gtk::TreeModel::const_iterator&)>
        SlotCompare;

    auto
    set_sort_func (const TreeModelColumnBase& sort_column,
                   const SlotCompare& slot) -> void;

    auto
    set_sort_func (int sort_column_id, const SlotCompare& slot) -> void;

    auto
    set_default_sort_func (const SlotCompare& slot) -> void;

    auto
    unset_default_sort_func () -> void;

    auto
    has_default_sort_func () const -> bool;

    auto
    sort_column_changed () -> void;

    auto
    signal_sort_column_changed () -> Glib::SignalProxy<void ()>;

  protected:
    virtual auto
    get_sort_column_id_vfunc (int* sort_column_id, SortType* order) const
        -> bool;

    virtual auto
    set_sort_column_id_vfunc (int sort_column_id, SortType order) -> void;

    virtual auto
    set_sort_func_vfunc (int sort_column_id,
                         GtkTreeIterCompareFunc func,
                         void* data,
                         GDestroyNotify destroy) -> void;

    virtual auto
    set_default_sort_func_vfunc (GtkTreeIterCompareFunc func,
                                 void* data,
                                 GDestroyNotify destroy) -> void;

    virtual auto
    has_default_sort_func_vfunc () const -> bool;

    virtual auto
    sort_column_changed_vfunc () const -> void;

  public:
  public:
  protected:
    virtual auto
    on_sort_column_changed () -> void;
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkTreeSortable* object, bool take_copy = false) -> Glib::RefPtr<Gtk::TreeSortable>;

} // namespace Glib

#endif

#endif
