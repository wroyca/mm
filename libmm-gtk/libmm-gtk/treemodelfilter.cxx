// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/mm-glib.hxx>

  #include <libmm-gtk/treemodelfilter.hxx>
  #include <libmm-gtk/treemodelfilter_p.hxx>

  #include <gtk/gtk.h>

static auto
SignalProxy_Visible_gtk_callback (GtkTreeModel* model,
                                  GtkTreeIter* iter,
                                  gpointer data) -> gboolean
{
  auto the_slot = static_cast<Gtk::TreeModelFilter::SlotVisible*> (data);

  try
  {
    return (*the_slot) (Gtk::TreeModel::const_iterator (model, iter));
  }
  catch (...)
  {
    Glib::exception_handlers_invoke ();
  }

  return FALSE;
}

static auto
SignalProxy_Visible_gtk_callback_destroy (void* data) -> void
{
  delete static_cast<Gtk::TreeModelFilter::SlotVisible*> (data);
}

static auto
SignalProxy_Modify_gtk_callback (GtkTreeModel* model,
                                 GtkTreeIter* iter,
                                 GValue* value,
                                 int column,
                                 gpointer data) -> void
{
  auto the_slot = static_cast<Gtk::TreeModelFilter::SlotModify*> (data);

  try
  {
    Glib::ValueBase cppValue;
    auto column_type = gtk_tree_model_get_column_type (model, column);
    cppValue.init (column_type);

    (*the_slot) (Gtk::TreeModel::iterator (model, iter), cppValue, column);

    g_value_copy (cppValue.gobj (), value);
  }
  catch (...)
  {
    Glib::exception_handlers_invoke ();
  }
}

static auto
SignalProxy_Modify_gtk_callback_destroy (void* data) -> void
{
  delete static_cast<Gtk::TreeModelFilter::SlotModify*> (data);
}

using Path = Gtk::TreeModel::Path;

namespace Gtk
{

  TreeModelFilter::TreeModelFilter (const Glib::RefPtr<TreeModel>& child_model)
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (treemodelfilter_class_.init (),
                                           "child_model",
                                           child_model->gobj (),
                                           nullptr))
  {
  }

  TreeModelFilter::TreeModelFilter (const Glib::RefPtr<TreeModel>& child_model,
                                    const TreeModel::Path& virtual_root)
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (
          treemodelfilter_class_.init (),
          "child_model",
          child_model->gobj (),
          "virtual_root",
          (virtual_root.empty () ?
               nullptr :
               const_cast<GtkTreePath*> ((virtual_root).gobj ())),
          nullptr))
  {
  }

  auto
  TreeModelFilter::set_visible_func (const SlotVisible& slot) -> void
  {
    auto slot_copy = new SlotVisible (slot);

    gtk_tree_model_filter_set_visible_func (
        gobj (),
        &SignalProxy_Visible_gtk_callback,
        slot_copy,
        &SignalProxy_Visible_gtk_callback_destroy);
  }

  auto
  TreeModelFilter::convert_child_iter_to_iter (const iterator& child_iter) -> TreeModel::iterator
  {
    iterator filter_iter (this);

    gtk_tree_model_filter_convert_child_iter_to_iter (
        gobj (),
        filter_iter.gobj (),
        const_cast<GtkTreeIter*> (child_iter.gobj ()));

    return filter_iter;
  }

  auto
  TreeModelFilter::convert_child_iter_to_iter (
      const const_iterator& child_iter) const -> TreeModel::const_iterator
  {
    const_iterator filter_iter (const_cast<TreeModelFilter*> (this));

    gtk_tree_model_filter_convert_child_iter_to_iter (
        const_cast<GtkTreeModelFilter*> (gobj ()),
        filter_iter.gobj (),
        const_cast<GtkTreeIter*> (child_iter.gobj ()));

    return filter_iter;
  }

  auto
  TreeModelFilter::convert_iter_to_child_iter (const iterator& filter_iter) -> TreeModel::iterator
  {
    const auto child_model = gtk_tree_model_filter_get_model (gobj ());

    iterator child_iter (dynamic_cast<TreeModel*> (
        Glib::wrap_auto ((GObject*) child_model, false)));

    gtk_tree_model_filter_convert_iter_to_child_iter (
        gobj (),
        child_iter.gobj (),
        const_cast<GtkTreeIter*> (filter_iter.gobj ()));

    return child_iter;
  }

  auto
  TreeModelFilter::convert_iter_to_child_iter (
      const const_iterator& filter_iter) const -> TreeModel::const_iterator
  {
    const auto child_model = gtk_tree_model_filter_get_model (
        const_cast<GtkTreeModelFilter*> (gobj ()));

    const_iterator child_iter (dynamic_cast<TreeModel*> (
        Glib::wrap_auto ((GObject*) child_model, false)));

    gtk_tree_model_filter_convert_iter_to_child_iter (
        const_cast<GtkTreeModelFilter*> (gobj ()),
        child_iter.gobj (),
        const_cast<GtkTreeIter*> (filter_iter.gobj ()));

    return child_iter;
  }

  auto
  TreeModelFilter::set_modify_func (const TreeModelColumnRecord& columns,
                                    const SlotModify& slot) -> void
  {
    auto slot_copy = new SlotModify (slot);

    gtk_tree_model_filter_set_modify_func (
        gobj (),
        columns.size (),
        const_cast<GType*> (columns.types ()),
        &SignalProxy_Modify_gtk_callback,
        slot_copy,
        &SignalProxy_Modify_gtk_callback_destroy);
  }

  auto
  TreeModelFilter::set_value_impl (const iterator& row,
                                   int column,
                                   const Glib::ValueBase& value) -> void
  {
    const auto child_model = dynamic_cast<TreeModel*> (
        Glib::wrap_auto ((GObject*) gtk_tree_model_filter_get_model (gobj ()),
                         false));

    iterator child_iter (child_model);

    gtk_tree_model_filter_convert_iter_to_child_iter (
        gobj (),
        child_iter.gobj (),
        const_cast<GtkTreeIter*> (row.gobj ()));

    child_model->set_value_impl (child_iter, column, value);
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkTreeModelFilter* object, bool take_copy) -> Glib::RefPtr<Gtk::TreeModelFilter>
  {
    return Glib::make_refptr_for_instance<Gtk::TreeModelFilter> (
        dynamic_cast<Gtk::TreeModelFilter*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  TreeModelFilter_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &TreeModelFilter_Class::class_init_function;

      register_derived_type (gtk_tree_model_filter_get_type ());

      TreeModel::add_interface (get_type ());
      TreeDragSource::add_interface (get_type ());
    }

    return *this;
  }

  auto
  TreeModelFilter_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  TreeModelFilter_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new TreeModelFilter ((GtkTreeModelFilter*) object);
  }

  auto
  TreeModelFilter::gobj_copy () -> GtkTreeModelFilter*
  {
    reference ();
    return gobj ();
  }

  TreeModelFilter::TreeModelFilter (
      const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  TreeModelFilter::TreeModelFilter (GtkTreeModelFilter* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  TreeModelFilter::TreeModelFilter (TreeModelFilter&& src) noexcept
    : Glib::Object (std::move (src)),
      TreeModel (std::move (src)),
      TreeDragSource (std::move (src))
  {
  }

  auto
  TreeModelFilter::operator= (TreeModelFilter&& src) noexcept -> TreeModelFilter&
  {
    Glib::Object::operator= (std::move (src));
    TreeModel::operator= (std::move (src));
    TreeDragSource::operator= (std::move (src));
    return *this;
  }

  TreeModelFilter::~TreeModelFilter () noexcept {}

  TreeModelFilter::CppClassType TreeModelFilter::treemodelfilter_class_;

  auto
  TreeModelFilter::get_type () -> GType
  {
    return treemodelfilter_class_.init ().get_type ();
  }

  auto
  TreeModelFilter::get_base_type () -> GType
  {
    return gtk_tree_model_filter_get_type ();
  }

  auto
  TreeModelFilter::create (const Glib::RefPtr<TreeModel>& child_model) -> Glib::RefPtr<TreeModelFilter>
  {
    return Glib::make_refptr_for_instance<TreeModelFilter> (
        new TreeModelFilter (child_model));
  }

  auto
  TreeModelFilter::create (const Glib::RefPtr<TreeModel>& child_model,
                           const TreeModel::Path& virtual_root) -> Glib::RefPtr<TreeModelFilter>
  {
    return Glib::make_refptr_for_instance<TreeModelFilter> (
        new TreeModelFilter (child_model, virtual_root));
  }

  auto
  TreeModelFilter::set_visible_column (const TreeModelColumnBase& column) -> void
  {
    gtk_tree_model_filter_set_visible_column (gobj (), (column).index ());
  }

  auto
  TreeModelFilter::set_visible_column (int column) -> void
  {
    gtk_tree_model_filter_set_visible_column (gobj (), column);
  }

  auto
  TreeModelFilter::get_model () -> Glib::RefPtr<TreeModel>
  {
    auto retvalue = Glib::wrap (gtk_tree_model_filter_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TreeModelFilter::get_model () const -> Glib::RefPtr<const TreeModel>
  {
    return const_cast<TreeModelFilter*> (this)->get_model ();
  }

  auto
  TreeModelFilter::convert_child_path_to_path (const Path& child_path) const -> Path
  {
    return Gtk::TreePath (gtk_tree_model_filter_convert_child_path_to_path (
                              const_cast<GtkTreeModelFilter*> (gobj ()),
                              const_cast<GtkTreePath*> ((child_path).gobj ())),
                          false);
  }

  auto
  TreeModelFilter::convert_path_to_child_path (const Path& filter_path) const -> Path
  {
    return Gtk::TreePath (gtk_tree_model_filter_convert_path_to_child_path (
                              const_cast<GtkTreeModelFilter*> (gobj ()),
                              const_cast<GtkTreePath*> ((filter_path).gobj ())),
                          false);
  }

  auto
  TreeModelFilter::refilter () -> void
  {
    gtk_tree_model_filter_refilter (gobj ());
  }

  auto
  TreeModelFilter::clear_cache () -> void
  {
    gtk_tree_model_filter_clear_cache (gobj ());
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<TreeModel>>::value,
      "Type Glib::RefPtr<TreeModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TreeModelFilter::property_child_model () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<TreeModel>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<TreeModel>> (
        this,
        "child-model");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<TreeModel::Path>::value,
      "Type TreeModel::Path cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TreeModelFilter::property_virtual_root () const -> Glib::PropertyProxy_ReadOnly<TreeModel::Path>
  {
    return Glib::PropertyProxy_ReadOnly<TreeModel::Path> (this, "virtual-root");
  }

} // namespace Gtk

#endif
