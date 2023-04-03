// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREEMODELSORT_H
#define _GTKMM_TREEMODELSORT_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gtk/treedragsource.hxx>
  #include <libmm/gtk/treeiter.hxx>
  #include <libmm/gtk/treemodel.hxx>
  #include <libmm/gtk/treesortable.hxx>

  #include <libmm/gtk/treepath.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTreeModelSort = struct _GtkTreeModelSort;
using GtkTreeModelSortClass = struct _GtkTreeModelSortClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT TreeModelSort_Class;
}
  #endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT TreeModelSort : public Glib::Object,
                                  public TreeModel,
                                  public TreeSortable,
                                  public TreeDragSource
  {
  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = TreeModelSort;
    using CppClassType = TreeModelSort_Class;
    using BaseObjectType = GtkTreeModelSort;
    using BaseClassType = GtkTreeModelSortClass;

    TreeModelSort (const TreeModelSort&) = delete;
    auto
    operator= (const TreeModelSort&) -> TreeModelSort& = delete;

  private:
    friend class TreeModelSort_Class;
    static CppClassType treemodelsort_class_;

  protected:
    explicit TreeModelSort (const Glib::ConstructParams& construct_params);
    explicit TreeModelSort (GtkTreeModelSort* castitem);

  #endif

  public:
    TreeModelSort (TreeModelSort&& src) noexcept;
    auto
    operator= (TreeModelSort&& src) noexcept -> TreeModelSort&;

    ~TreeModelSort () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkTreeModelSort*
    {
      return reinterpret_cast<GtkTreeModelSort*> (gobject_);
    }

    auto
    gobj () const -> const GtkTreeModelSort*
    {
      return reinterpret_cast<GtkTreeModelSort*> (gobject_);
    }

    auto
    gobj_copy () -> GtkTreeModelSort*;

  private:
  protected:
    explicit TreeModelSort (const Glib::RefPtr<TreeModel>& model);

  public:
    static auto
    create (const Glib::RefPtr<TreeModel>& model)
        -> Glib::RefPtr<TreeModelSort>;

    auto
    get_model () -> Glib::RefPtr<TreeModel>;

    auto
    get_model () const -> Glib::RefPtr<const TreeModel>;

    auto
    convert_child_path_to_path (const Path& child_path) const -> Path;

    auto
    convert_child_iter_to_iter (const iterator& child_iter) -> iterator;

    auto
    convert_child_iter_to_iter (const const_iterator& child_iter) const
        -> const_iterator;

    auto
    convert_path_to_child_path (const Path& sorted_path) const -> Path;

    auto
    convert_iter_to_child_iter (const iterator& sorted_iter) -> iterator;

    auto
    convert_iter_to_child_iter (const const_iterator& sorted_iter) const
        -> const_iterator;

    auto
    reset_default_sort_func () -> void;

    auto
    clear_cache () -> void;

    auto
    iter_is_valid (const const_iterator& iter) const -> bool;

    auto
    property_model () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<TreeModel>>;

  protected:
    auto
    set_value_impl (const iterator& row,
                    int column,
                    const Glib::ValueBase& value) -> void override;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkTreeModelSort* object, bool take_copy = false) -> Glib::RefPtr<Gtk::TreeModelSort>;
} // namespace Glib

#endif

#endif