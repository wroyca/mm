// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/liststore.hxx>
  #include <libmm/gtk/liststore_p.hxx>

  #include <libmm/glib/vectorutils.hxx>

  #include <gtk/gtk.h>

namespace gtk
{

  ListStore::ListStore (const TreeModelColumnRecord& columns)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (liststore_class_.init ()))
  {
    gtk_list_store_set_column_types (gobj (),
                                     columns.size (),
                                     const_cast<GType*> (columns.types ()));
  }

  auto
  ListStore::set_column_types (const TreeModelColumnRecord& columns) -> void
  {
    gtk_list_store_set_column_types (gobj (),
                                     columns.size (),
                                     const_cast<GType*> (columns.types ()));
  }

  auto
  ListStore::erase (const iterator& iter) -> TreeModel::iterator
  {
    g_assert (iter.get_gobject_if_not_end () != nullptr);

    iterator next (iter);
    ++next;

    auto tmp = *iter.gobj ();
    gtk_list_store_remove (gobj (), &tmp);

    return next;
  }

  auto
  ListStore::insert (const iterator& iter) -> TreeModel::iterator
  {
    iterator new_pos (this);

    gtk_list_store_insert_before (
        gobj (),
        new_pos.gobj (),
        const_cast<GtkTreeIter*> (iter.get_gobject_if_not_end ()));

    if (new_pos.gobj ()->stamp == 0)
      new_pos.setup_end_iterator (iter);

    return new_pos;
  }

  auto
  ListStore::insert_after (const iterator& iter) -> TreeModel::iterator
  {
    iterator new_pos (this);

    gtk_list_store_insert_after (
        gobj (),
        new_pos.gobj (),
        const_cast<GtkTreeIter*> (iter.get_gobject_if_not_end ()));

    if (new_pos.gobj ()->stamp == 0)
      new_pos.setup_end_iterator (iter);

    return new_pos;
  }

  auto
  ListStore::prepend () -> TreeModel::iterator
  {
    iterator new_pos (this);
    gtk_list_store_prepend (gobj (), new_pos.gobj ());
    return new_pos;
  }

  auto
  ListStore::append () -> TreeModel::iterator
  {
    iterator new_pos (this);
    gtk_list_store_append (gobj (), new_pos.gobj ());
    return new_pos;
  }

  auto
  ListStore::move (const iterator& source, const iterator& destination) -> void
  {
    gtk_list_store_move_before (
        gobj (),
        const_cast<GtkTreeIter*> (source.get_gobject_if_not_end ()),
        const_cast<GtkTreeIter*> (destination.get_gobject_if_not_end ()));
  }

  auto
  ListStore::reorder (const std::vector<int>& new_order) -> void
  {
    gtk_list_store_reorder (
        gobj (),
        const_cast<int*> (
            glib::ArrayHandler<int>::vector_to_array (new_order).data ()));
  }

  auto
  ListStore::set_value_impl (const iterator& row,
                             int column,
                             const glib::ValueBase& value) -> void
  {
    gtk_list_store_set_value (gobj (),
                              const_cast<GtkTreeIter*> (row.gobj ()),
                              column,
                              const_cast<GValue*> (value.gobj ()));
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkListStore* object, bool take_copy) -> glib::RefPtr<gtk::ListStore>
  {
    return glib::make_refptr_for_instance<gtk::ListStore> (
        dynamic_cast<gtk::ListStore*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  ListStore_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ListStore_Class::class_init_function;

      register_derived_type (gtk_list_store_get_type ());

      TreeModel::add_interface (get_type ());
      TreeSortable::add_interface (get_type ());
      TreeDragSource::add_interface (get_type ());
      TreeDragDest::add_interface (get_type ());
      Buildable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  ListStore_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ListStore_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new ListStore ((GtkListStore*) object);
  }

  auto
  ListStore::gobj_copy () -> GtkListStore*
  {
    reference ();
    return gobj ();
  }

  ListStore::ListStore (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  ListStore::ListStore (GtkListStore* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  ListStore::ListStore (ListStore&& src) noexcept
    : glib::Object (std::move (src)),
      TreeModel (std::move (src)),
      TreeSortable (std::move (src)),
      TreeDragSource (std::move (src)),
      TreeDragDest (std::move (src)),
      Buildable (std::move (src))
  {
  }

  auto
  ListStore::operator= (ListStore&& src) noexcept -> ListStore&
  {
    glib::Object::operator= (std::move (src));
    TreeModel::operator= (std::move (src));
    TreeSortable::operator= (std::move (src));
    TreeDragSource::operator= (std::move (src));
    TreeDragDest::operator= (std::move (src));
    Buildable::operator= (std::move (src));
    return *this;
  }

  ListStore::~ListStore () noexcept {}

  ListStore::CppClassType ListStore::liststore_class_;

  auto
  ListStore::get_type () -> GType
  {
    return liststore_class_.init ().get_type ();
  }

  auto
  ListStore::get_base_type () -> GType
  {
    return gtk_list_store_get_type ();
  }

  ListStore::ListStore ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (liststore_class_.init ()))
  {
  }

  auto
  ListStore::create (const TreeModelColumnRecord& columns) -> glib::RefPtr<ListStore>
  {
    return glib::make_refptr_for_instance<ListStore> (new ListStore (columns));
  }

  auto
  ListStore::iter_swap (const iterator& a, const iterator& b) -> void
  {
    gtk_list_store_swap (gobj (),
                         const_cast<GtkTreeIter*> ((a).gobj ()),
                         const_cast<GtkTreeIter*> ((b).gobj ()));
  }

  auto
  ListStore::clear () -> void
  {
    gtk_list_store_clear (gobj ());
  }

  auto
  ListStore::iter_is_valid (const const_iterator& iter) const -> bool
  {
    return gtk_list_store_iter_is_valid (
        const_cast<GtkListStore*> (gobj ()),
        const_cast<GtkTreeIter*> ((iter).gobj ()));
  }

} // namespace gtk

#endif
