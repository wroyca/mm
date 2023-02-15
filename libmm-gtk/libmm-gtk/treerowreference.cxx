// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/mm-glib.hxx>

  #include <libmm-gtk/treerowreference.hxx>
  #include <libmm-gtk/treerowreference_p.hxx>

  #include <gtk/gtk.h>

namespace Gtk
{

  TreeRowReference::TreeRowReference (const Glib::RefPtr<TreeModel>& model,
                                      const TreeModel::Path& path)
    : gobject_ (
          gtk_tree_row_reference_new (model->gobj (),
                                      const_cast<GtkTreePath*> (path.gobj ())))
  {
  }

  TreeRowReference::operator bool () const
  {
    return is_valid ();
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkTreeRowReference* object, bool take_copy) -> Gtk::TreeRowReference
  {
    return Gtk::TreeRowReference (object, take_copy);
  }

} // namespace Glib

namespace Gtk
{

  auto
  TreeRowReference::get_type () -> GType
  {
    return gtk_tree_row_reference_get_type ();
  }

  TreeRowReference::TreeRowReference ()
    : gobject_ (nullptr)
  {
  }

  TreeRowReference::TreeRowReference (const TreeRowReference& other)
    : gobject_ ((other.gobject_) ?
                    gtk_tree_row_reference_copy (other.gobject_) :
                    nullptr)
  {
  }

  TreeRowReference::TreeRowReference (TreeRowReference&& other) noexcept
    : gobject_ (other.gobject_)
  {
    other.gobject_ = nullptr;
  }

  auto
  TreeRowReference::operator= (TreeRowReference&& other) noexcept -> TreeRowReference&
  {
    TreeRowReference temp (std::move (other));
    swap (temp);
    return *this;
  }

  TreeRowReference::TreeRowReference (GtkTreeRowReference* gobject,
                                      bool make_a_copy)
    : gobject_ ((make_a_copy && gobject) ?
                    gtk_tree_row_reference_copy (gobject) :
                    gobject)
  {
  }

  auto
  TreeRowReference::operator= (const TreeRowReference& other) -> TreeRowReference&
  {
    TreeRowReference temp (other);
    swap (temp);
    return *this;
  }

  TreeRowReference::~TreeRowReference () noexcept
  {
    if (gobject_)
      gtk_tree_row_reference_free (gobject_);
  }

  auto
  TreeRowReference::swap (TreeRowReference& other) noexcept -> void
  {
    std::swap (gobject_, other.gobject_);
  }

  auto
  TreeRowReference::gobj_copy () const -> GtkTreeRowReference*
  {
    return gtk_tree_row_reference_copy (gobject_);
  }

  auto
  TreeRowReference::get_path () const -> TreeModel::Path
  {
    return Gtk::TreePath (gtk_tree_row_reference_get_path (
                              const_cast<GtkTreeRowReference*> (gobj ())),
                          false);
  }

  auto
  TreeRowReference::get_model () -> Glib::RefPtr<TreeModel>
  {
    auto retvalue = Glib::wrap (gtk_tree_row_reference_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TreeRowReference::get_model () const -> Glib::RefPtr<const TreeModel>
  {
    return const_cast<TreeRowReference*> (this)->get_model ();
  }

  auto
  TreeRowReference::is_valid () const -> bool
  {
    return gtk_tree_row_reference_valid (
        const_cast<GtkTreeRowReference*> (gobj ()));
  }

} // namespace Gtk

#endif
