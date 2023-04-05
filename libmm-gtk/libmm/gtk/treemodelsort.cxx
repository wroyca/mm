// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/treemodelsort.hxx>
  #include <libmm/gtk/treemodelsort_p.hxx>

  #include <gtk/gtk.h>

using Path = gtk::TreeModel::Path;

namespace gtk
{

  auto
  TreeModelSort::convert_child_iter_to_iter (const iterator& child_iter) -> TreeModel::iterator
  {
    iterator sorted_iter (this);

    gtk_tree_model_sort_convert_child_iter_to_iter (
        gobj (),
        sorted_iter.gobj (),
        const_cast<GtkTreeIter*> (child_iter.gobj ()));

    return sorted_iter;
  }

  auto
  TreeModelSort::convert_child_iter_to_iter (
      const const_iterator& child_iter) const -> TreeModel::const_iterator
  {
    const_iterator sorted_iter (const_cast<TreeModelSort*> (this));

    gtk_tree_model_sort_convert_child_iter_to_iter (
        const_cast<GtkTreeModelSort*> (gobj ()),
        sorted_iter.gobj (),
        const_cast<GtkTreeIter*> (child_iter.gobj ()));

    return sorted_iter;
  }

  auto
  TreeModelSort::convert_iter_to_child_iter (const iterator& sorted_iter) -> TreeModel::iterator
  {
    const auto child_model = gtk_tree_model_sort_get_model (gobj ());

    iterator child_iter (dynamic_cast<TreeModel*> (
        glib::wrap_auto ((GObject*) child_model, false)));

    gtk_tree_model_sort_convert_iter_to_child_iter (
        gobj (),
        child_iter.gobj (),
        const_cast<GtkTreeIter*> (sorted_iter.gobj ()));

    return child_iter;
  }

  auto
  TreeModelSort::convert_iter_to_child_iter (
      const const_iterator& sorted_iter) const -> TreeModel::const_iterator
  {
    const auto child_model =
        gtk_tree_model_sort_get_model (const_cast<GtkTreeModelSort*> (gobj ()));

    const_iterator child_iter (dynamic_cast<TreeModel*> (
        glib::wrap_auto ((GObject*) child_model, false)));

    gtk_tree_model_sort_convert_iter_to_child_iter (
        const_cast<GtkTreeModelSort*> (gobj ()),
        child_iter.gobj (),
        const_cast<GtkTreeIter*> (sorted_iter.gobj ()));

    return child_iter;
  }

  auto
  TreeModelSort::set_value_impl (const iterator& row,
                                 int column,
                                 const glib::ValueBase& value) -> void
  {
    const auto child_model = dynamic_cast<TreeModel*> (
        glib::wrap_auto ((GObject*) gtk_tree_model_sort_get_model (gobj ()),
                         false));

    iterator child_iter (child_model);

    gtk_tree_model_sort_convert_iter_to_child_iter (
        gobj (),
        child_iter.gobj (),
        const_cast<GtkTreeIter*> (row.gobj ()));

    child_model->set_value_impl (child_iter, column, value);
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkTreeModelSort* object, bool take_copy) -> glib::RefPtr<gtk::TreeModelSort>
  {
    return glib::make_refptr_for_instance<gtk::TreeModelSort> (
        dynamic_cast<gtk::TreeModelSort*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  TreeModelSort_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &TreeModelSort_Class::class_init_function;

      register_derived_type (gtk_tree_model_sort_get_type ());

      TreeModel::add_interface (get_type ());
      TreeSortable::add_interface (get_type ());
      TreeDragSource::add_interface (get_type ());
    }

    return *this;
  }

  auto
  TreeModelSort_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  TreeModelSort_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new TreeModelSort ((GtkTreeModelSort*) object);
  }

  auto
  TreeModelSort::gobj_copy () -> GtkTreeModelSort*
  {
    reference ();
    return gobj ();
  }

  TreeModelSort::TreeModelSort (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  TreeModelSort::TreeModelSort (GtkTreeModelSort* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  TreeModelSort::TreeModelSort (TreeModelSort&& src) noexcept
    : glib::Object (std::move (src)),
      TreeModel (std::move (src)),
      TreeSortable (std::move (src)),
      TreeDragSource (std::move (src))
  {
  }

  auto
  TreeModelSort::operator= (TreeModelSort&& src) noexcept -> TreeModelSort&
  {
    glib::Object::operator= (std::move (src));
    TreeModel::operator= (std::move (src));
    TreeSortable::operator= (std::move (src));
    TreeDragSource::operator= (std::move (src));
    return *this;
  }

  TreeModelSort::~TreeModelSort () noexcept {}

  TreeModelSort::CppClassType TreeModelSort::treemodelsort_class_;

  auto
  TreeModelSort::get_type () -> GType
  {
    return treemodelsort_class_.init ().get_type ();
  }

  auto
  TreeModelSort::get_base_type () -> GType
  {
    return gtk_tree_model_sort_get_type ();
  }

  TreeModelSort::TreeModelSort (const glib::RefPtr<TreeModel>& model)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (treemodelsort_class_.init (),
                                           "model",
                                           glib::unwrap (model),
                                           nullptr))
  {
  }

  auto
  TreeModelSort::create (const glib::RefPtr<TreeModel>& model) -> glib::RefPtr<TreeModelSort>
  {
    return glib::make_refptr_for_instance<TreeModelSort> (
        new TreeModelSort (model));
  }

  auto
  TreeModelSort::get_model () -> glib::RefPtr<TreeModel>
  {
    auto retvalue = glib::wrap (gtk_tree_model_sort_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TreeModelSort::get_model () const -> glib::RefPtr<const TreeModel>
  {
    return const_cast<TreeModelSort*> (this)->get_model ();
  }

  auto
  TreeModelSort::convert_child_path_to_path (const Path& child_path) const -> Path
  {
    return gtk::TreePath (gtk_tree_model_sort_convert_child_path_to_path (
                              const_cast<GtkTreeModelSort*> (gobj ()),
                              const_cast<GtkTreePath*> ((child_path).gobj ())),
                          false);
  }

  auto
  TreeModelSort::convert_path_to_child_path (const Path& sorted_path) const -> Path
  {
    return gtk::TreePath (gtk_tree_model_sort_convert_path_to_child_path (
                              const_cast<GtkTreeModelSort*> (gobj ()),
                              const_cast<GtkTreePath*> ((sorted_path).gobj ())),
                          false);
  }

  auto
  TreeModelSort::reset_default_sort_func () -> void
  {
    gtk_tree_model_sort_reset_default_sort_func (gobj ());
  }

  auto
  TreeModelSort::clear_cache () -> void
  {
    gtk_tree_model_sort_clear_cache (gobj ());
  }

  auto
  TreeModelSort::iter_is_valid (const const_iterator& iter) const -> bool
  {
    return gtk_tree_model_sort_iter_is_valid (
        const_cast<GtkTreeModelSort*> (gobj ()),
        const_cast<GtkTreeIter*> ((iter).gobj ()));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<TreeModel>>::value,
      "Type glib::RefPtr<TreeModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TreeModelSort::property_model () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<TreeModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<TreeModel>> (this,
                                                                  "model");
  }

} // namespace gtk

#endif
