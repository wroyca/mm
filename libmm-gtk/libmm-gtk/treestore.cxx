

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/treestore.hxx>
#include <libmm-gtk/treestore_p.hxx>

#include <libmm-glib/vectorutils.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  TreeStore::TreeStore (const TreeModelColumnRecord& columns)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (treestore_class_.init ()))
  {
    gtk_tree_store_set_column_types (gobj (),
                                     columns.size (),
                                     const_cast<GType*> (columns.types ()));
  }

  auto
  TreeStore::set_column_types (const TreeModelColumnRecord& columns) -> void
  {
    gtk_tree_store_set_column_types (gobj (),
                                     columns.size (),
                                     const_cast<GType*> (columns.types ()));
  }

  auto
  TreeStore::erase (const iterator& iter) -> iterator
  {
    g_assert (iter.get_gobject_if_not_end () != nullptr);

    iterator next (iter);
    ++next;

    auto tmp = *iter.gobj ();
    gtk_tree_store_remove (gobj (), &tmp);

    return next;
  }

  auto
  TreeStore::insert (const iterator& iter) -> iterator
  {
    iterator new_pos (this);

    gtk_tree_store_insert_before (
        gobj (),
        new_pos.gobj (),
        const_cast<GtkTreeIter*> (iter.get_parent_gobject_if_end ()),
        const_cast<GtkTreeIter*> (iter.get_gobject_if_not_end ()));

    if (new_pos.gobj ()->stamp == 0)
      new_pos.setup_end_iterator (iter);

    return new_pos;
  }

  auto
  TreeStore::insert_after (const iterator& iter) -> iterator
  {
    iterator new_pos (this);

    gtk_tree_store_insert_after (
        gobj (),
        new_pos.gobj (),
        const_cast<GtkTreeIter*> (iter.get_parent_gobject_if_end ()),
        const_cast<GtkTreeIter*> (iter.get_gobject_if_not_end ()));

    if (new_pos.gobj ()->stamp == 0)
      new_pos.setup_end_iterator (iter);

    return new_pos;
  }

  auto
  TreeStore::prepend () -> iterator
  {
    iterator new_pos (this);
    gtk_tree_store_prepend (gobj (), new_pos.gobj (), nullptr);
    return new_pos;
  }

  auto
  TreeStore::prepend (const TreeNodeChildren& node) -> iterator
  {
    iterator new_pos (this);

    gtk_tree_store_prepend (
        gobj (),
        new_pos.gobj (),
        const_cast<GtkTreeIter*> (node.get_parent_gobject ()));

    return new_pos;
  }

  auto
  TreeStore::append () -> iterator
  {
    iterator new_pos (this);
    gtk_tree_store_append (gobj (), new_pos.gobj (), nullptr);
    return new_pos;
  }

  auto
  TreeStore::append (const TreeNodeChildren& node) -> iterator
  {
    iterator new_pos (this);

    gtk_tree_store_append (
        gobj (),
        new_pos.gobj (),
        const_cast<GtkTreeIter*> (node.get_parent_gobject ()));

    return new_pos;
  }

  auto
  TreeStore::move (const iterator& source, const iterator& destination) -> void
  {
    gtk_tree_store_move_before (
        gobj (),
        const_cast<GtkTreeIter*> (source.get_gobject_if_not_end ()),
        const_cast<GtkTreeIter*> (destination.get_gobject_if_not_end ()));
  }

  auto
  TreeStore::reorder (const TreeNodeChildren& node,
                      const std::vector<int>& new_order) -> void
  {
    gtk_tree_store_reorder (
        gobj (),
        const_cast<GtkTreeIter*> (node.get_parent_gobject ()),
        Glib::ArrayHandler<int>::vector_to_array (new_order).data ());
  }

  auto
  TreeStore::set_value_impl (const iterator& row,
                             const int column,
                             const Glib::ValueBase& value) -> void
  {
    gtk_tree_store_set_value (gobj (),
                              const_cast<GtkTreeIter*> (row.gobj ()),
                              column,
                              const_cast<GValue*> (value.gobj ()));
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkTreeStore* object, const bool take_copy) -> RefPtr<Gtk::TreeStore>
  {
    return Glib::make_refptr_for_instance<Gtk::TreeStore> (
        dynamic_cast<Gtk::TreeStore*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  TreeStore_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &TreeStore_Class::class_init_function;

      register_derived_type (gtk_tree_store_get_type ());

      TreeModel::add_interface (get_type ());
      TreeSortable::add_interface (get_type ());
      TreeDragSource::add_interface (get_type ());
      TreeDragDest::add_interface (get_type ());
      Buildable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  TreeStore_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  TreeStore_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new TreeStore ((GtkTreeStore*) object);
  }

  auto
  TreeStore::gobj_copy () -> GtkTreeStore*
  {
    reference ();
    return gobj ();
  }

  TreeStore::TreeStore (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  TreeStore::TreeStore (GtkTreeStore* castitem)
    : Object ((GObject*) castitem)
  {
  }

  TreeStore::TreeStore (TreeStore&& src) noexcept
    : Object (std::move (src)),
      TreeModel (std::move (src)),
      TreeSortable (std::move (src)),
      TreeDragSource (std::move (src)),
      TreeDragDest (std::move (src)),
      Buildable (std::move (src))
  {
  }

  auto
  TreeStore::operator= (TreeStore&& src) noexcept -> TreeStore&
  {
    Object::operator= (std::move (src));
    TreeModel::operator= (std::move (src));
    TreeSortable::operator= (std::move (src));
    TreeDragSource::operator= (std::move (src));
    TreeDragDest::operator= (std::move (src));
    Buildable::operator= (std::move (src));
    return *this;
  }

  TreeStore::~TreeStore () noexcept = default;

  TreeStore::CppClassType TreeStore::treestore_class_;

  auto
  TreeStore::get_type () -> GType
  {
    return treestore_class_.init ().get_type ();
  }

  auto
  TreeStore::get_base_type () -> GType
  {
    return gtk_tree_store_get_type ();
  }

  TreeStore::TreeStore ()
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (treestore_class_.init ()))
  {
  }

  auto
  TreeStore::create (const TreeModelColumnRecord& columns) -> Glib::RefPtr<TreeStore>
  {
    return Glib::make_refptr_for_instance<TreeStore> (new TreeStore (columns));
  }

  auto
  TreeStore::iter_swap (const iterator& a, const iterator& b) -> void
  {
    gtk_tree_store_swap (gobj (),
                         const_cast<GtkTreeIter*> (a.gobj ()),
                         const_cast<GtkTreeIter*> (b.gobj ()));
  }

  auto
  TreeStore::clear () -> void
  {
    gtk_tree_store_clear (gobj ());
  }

  auto
  TreeStore::is_ancestor (const const_iterator& iter,
                          const const_iterator& descendant) const -> bool
  {
    return gtk_tree_store_is_ancestor (
        const_cast<GtkTreeStore*> (gobj ()),
        const_cast<GtkTreeIter*> (iter.gobj ()),
        const_cast<GtkTreeIter*> (descendant.gobj ()));
  }

  auto
  TreeStore::iter_depth (const const_iterator& iter) const -> int
  {
    return gtk_tree_store_iter_depth (const_cast<GtkTreeStore*> (gobj ()),
                                      const_cast<GtkTreeIter*> (iter.gobj ()));
  }

  auto
  TreeStore::iter_is_valid (const const_iterator& iter) const -> bool
  {
    return gtk_tree_store_iter_is_valid (
        const_cast<GtkTreeStore*> (gobj ()),
        const_cast<GtkTreeIter*> (iter.gobj ()));
  }

} // namespace Gtk
