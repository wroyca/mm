// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#include <libmm/gtk/mm-gtkconfig.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/treepath.hxx>
  #include <libmm/gtk/treepath_p.hxx>

  #include <gtk/gtk.h>
  #include <libmm/glib/utility.hxx>
  #include <libmm/gtk/treemodel.hxx>

namespace gtk
{

  TreePath::TreePath (GtkTreePath* gobject, bool make_a_copy)
    : gobject_ (gobject ?
                    (make_a_copy ? gtk_tree_path_copy (gobject) : gobject) :
                    gtk_tree_path_new ())
  {
  }

  TreePath::TreePath (TreePath::size_type n, TreePath::value_type value)
    : gobject_ (gtk_tree_path_new ())
  {
    for (; n > 0; --n)
      gtk_tree_path_append_index (gobject_, value);
  }

  TreePath::TreePath (const glib::ustring& path)
    : gobject_ (gtk_tree_path_new_from_string (path.c_str ()))
  {
    if (!gobject_)
      gobject_ = gtk_tree_path_new ();
  }

  TreePath::TreePath (const TreeModel::iterator& iter)
    : gobject_ (gtk_tree_model_get_path (
          const_cast<GtkTreeModel*> (iter.get_model_gobject ()),
          const_cast<GtkTreeIter*> (iter.gobj ())))
  {
    if (!gobject_)
      gobject_ = gtk_tree_path_new ();
  }

  auto
  TreePath::operator= (const TreeModel::iterator& iter) -> TreePath&
  {
    TreePath temp (iter);
    swap (temp);
    return *this;
  }

  auto
  TreePath::clear () -> void
  {
    TreePath empty_path;
    swap (empty_path);
  }

  auto
  TreePath::size () const -> TreePath::size_type
  {
    return gtk_tree_path_get_depth (gobject_);
  }

  TreePath::operator bool () const
  {
    return !empty ();
  }

  auto
  TreePath::empty () const -> bool
  {
    return (gtk_tree_path_get_depth (gobject_) == 0);
  }

  auto
  TreePath::operator[] (TreePath::size_type i) -> TreePath::reference
  {
    int* const indices = gtk_tree_path_get_indices (gobject_);
    return indices[i];
  }

  auto
  TreePath::operator[] (TreePath::size_type i) const -> TreePath::const_reference
  {
    const int* const indices = gtk_tree_path_get_indices (gobject_);
    return indices[i];
  }

  auto
  TreePath::begin () -> TreePath::iterator
  {
    return gtk_tree_path_get_indices (gobject_);
  }

  auto
  TreePath::end () -> TreePath::iterator
  {
    return gtk_tree_path_get_indices (gobject_) +
           gtk_tree_path_get_depth (gobject_);
  }

  auto
  TreePath::begin () const -> TreePath::const_iterator
  {
    return gtk_tree_path_get_indices (gobject_);
  }

  auto
  TreePath::end () const -> TreePath::const_iterator
  {
    return gtk_tree_path_get_indices (gobject_) +
           gtk_tree_path_get_depth (gobject_);
  }

  auto
  TreePath::get_row_drag_data (const glib::ValueBase& value,
                               glib::RefPtr<const TreeModel>& model,
                               TreePath& path) -> bool
  {
    GtkTreeModel* src_model = nullptr;
    GtkTreePath* src_path = nullptr;
    gboolean result =
        gtk_tree_get_row_drag_data (value.gobj (), &src_model, &src_path);

    model = glib::wrap (src_model, true);

    path = glib::wrap (src_path, false);

    return result;
  }

  auto
  TreePath::get_row_drag_data (const glib::ValueBase& value, TreePath& path) -> bool
  {
    GtkTreePath* src_path = nullptr;
    gboolean result =
        gtk_tree_get_row_drag_data (value.gobj (), nullptr, &src_path);

    path = glib::wrap (src_path, false);

    return result;
  }

  auto
  TreePath::create_row_drag_content (const glib::RefPtr<const TreeModel>& model)
      const -> glib::RefPtr<gdk::ContentProvider>
  {
    return glib::wrap (gtk_tree_create_row_drag_content (
        const_cast<GtkTreeModel*> (model->gobj ()),
        const_cast<GtkTreePath*> (gobj ())));
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkTreePath* object, bool take_copy) -> gtk::TreePath
  {
    return gtk::TreePath (object, take_copy);
  }

} // namespace glib

namespace gtk
{

  auto
  TreePath::get_type () -> GType
  {
    return gtk_tree_path_get_type ();
  }

  TreePath::TreePath ()
    : gobject_ (gtk_tree_path_new ())
  {
  }

  TreePath::TreePath (const TreePath& other)
    : gobject_ ((other.gobject_) ? gtk_tree_path_copy (other.gobject_) :
                                   nullptr)
  {
  }

  TreePath::TreePath (TreePath&& other) noexcept
    : gobject_ (other.gobject_)
  {
    other.gobject_ = nullptr;
  }

  auto
  TreePath::operator= (TreePath&& other) noexcept -> TreePath&
  {
    TreePath temp (std::move (other));
    swap (temp);
    return *this;
  }

  auto
  TreePath::operator= (const TreePath& other) -> TreePath&
  {
    TreePath temp (other);
    swap (temp);
    return *this;
  }

  TreePath::~TreePath () noexcept
  {
    if (gobject_)
      gtk_tree_path_free (gobject_);
  }

  auto
  TreePath::swap (TreePath& other) noexcept -> void
  {
    std::swap (gobject_, other.gobject_);
  }

  auto
  TreePath::gobj_copy () const -> GtkTreePath*
  {
    return gtk_tree_path_copy (gobject_);
  }

  auto
  TreePath::push_back (int index) -> void
  {
    gtk_tree_path_append_index (gobj (), index);
  }

  auto
  TreePath::push_front (int index) -> void
  {
    gtk_tree_path_prepend_index (gobj (), index);
  }

  auto
  TreePath::next () -> void
  {
    gtk_tree_path_next (gobj ());
  }

  auto
  TreePath::prev () -> bool
  {
    return gtk_tree_path_prev (gobj ());
  }

  auto
  TreePath::up () -> bool
  {
    return gtk_tree_path_up (gobj ());
  }

  auto
  TreePath::down () -> void
  {
    gtk_tree_path_down (gobj ());
  }

  auto
  TreePath::is_ancestor (const TreePath& descendant) const -> bool
  {
    return gtk_tree_path_is_ancestor (
        const_cast<GtkTreePath*> (gobj ()),
        const_cast<GtkTreePath*> ((descendant).gobj ()));
  }

  auto
  TreePath::is_descendant (const TreePath& ancestor) const -> bool
  {
    return gtk_tree_path_is_descendant (
        const_cast<GtkTreePath*> (gobj ()),
        const_cast<GtkTreePath*> ((ancestor).gobj ()));
  }

  auto
  TreePath::to_string () const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        gtk_tree_path_to_string (const_cast<GtkTreePath*> (gobj ())));
  }

  auto
  operator== (const TreePath& lhs, const TreePath& rhs) -> bool
  {
    return (gtk_tree_path_compare (lhs.gobj (), rhs.gobj ()) == 0);
  }

  auto
  operator!= (const TreePath& lhs, const TreePath& rhs) -> bool
  {
    return (gtk_tree_path_compare (lhs.gobj (), rhs.gobj ()) != 0);
  }

  auto
  operator<(const TreePath& lhs, const TreePath& rhs) -> bool
  {
    return (gtk_tree_path_compare (lhs.gobj (), rhs.gobj ()) < 0);
  }

  auto
  operator> (const TreePath& lhs, const TreePath& rhs) -> bool
  {
    return (gtk_tree_path_compare (lhs.gobj (), rhs.gobj ()) > 0);
  }

  auto
  operator<= (const TreePath& lhs, const TreePath& rhs) -> bool
  {
    return (gtk_tree_path_compare (lhs.gobj (), rhs.gobj ()) <= 0);
  }

  auto
  operator>= (const TreePath& lhs, const TreePath& rhs) -> bool
  {
    return (gtk_tree_path_compare (lhs.gobj (), rhs.gobj ()) >= 0);
  }

} // namespace gtk

#endif
