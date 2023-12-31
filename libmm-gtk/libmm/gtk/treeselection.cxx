// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/treeselection.hxx>
  #include <libmm/gtk/treeselection_p.hxx>

  #include <libmm/glib/vectorutils.hxx>

  #include <gtk/gtk.h>
  #include <libmm/gtk/treeview.hxx>

namespace
{

  static auto
  proxy_foreach_selection_iter_callback (GtkTreeModel* model,
                                         GtkTreePath*,
                                         GtkTreeIter* iter,
                                         void* data) -> void
  {
    typedef gtk::TreeSelection::SlotForeachIter SlotType;
    auto& slot = *static_cast<SlotType*> (data);

    try
    {
      slot (gtk::TreeModel::const_iterator (model, iter));
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
    }
  }

  static auto
  proxy_foreach_selection_path_callback (GtkTreeModel*,
                                         GtkTreePath* path,
                                         GtkTreeIter*,
                                         void* data) -> void
  {
    typedef gtk::TreeSelection::SlotForeachPath SlotType;
    auto& slot = *static_cast<SlotType*> (data);

    try
    {
      slot (gtk::TreeModel::Path (path, true));
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
    }
  }

  static auto
  proxy_foreach_selection_path_and_iter_callback (GtkTreeModel* model,
                                                  GtkTreePath* path,
                                                  GtkTreeIter* iter,
                                                  void* data) -> void
  {
    typedef gtk::TreeSelection::SlotForeachPathAndIter SlotType;
    auto& slot = *static_cast<SlotType*> (data);

    try
    {
      slot (gtk::TreeModel::Path (path, true),
            gtk::TreeModel::const_iterator (model, iter));
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
    }
  }

  static auto
  SignalProxy_Select_gtk_callback (GtkTreeSelection*,
                                   GtkTreeModel* model,
                                   GtkTreePath* path,
                                   gboolean path_currently_selected,
                                   void* data) -> gboolean
  {
    const auto the_slot = static_cast<gtk::TreeSelection::SlotSelect*> (data);

    try
    {
      return (*the_slot) (glib::wrap (model, true),
                          gtk::TreePath (path, true),
                          path_currently_selected);
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
    }

    return 0;
  }

} // namespace

static auto
SignalProxy_Select_gtk_callback_destroy (void* data) -> void
{
  delete static_cast<gtk::TreeSelection::SlotSelect*> (data);
}

namespace gtk
{

  auto
  TreeSelection::set_select_function (const SlotSelect& slot) -> void
  {
    auto slot_copy = new SlotSelect (slot);

    gtk_tree_selection_set_select_function (
        gobj (),
        &SignalProxy_Select_gtk_callback,
        slot_copy,
        &SignalProxy_Select_gtk_callback_destroy);
  }

  auto
  TreeSelection::get_model () -> glib::RefPtr<TreeModel>
  {
    const auto tree_view = gtk_tree_selection_get_tree_view (gobj ());
    return glib::wrap (gtk_tree_view_get_model (tree_view), true);
  }

  auto
  TreeSelection::get_model () const -> glib::RefPtr<const TreeModel>
  {
    const auto tree_view = gtk_tree_selection_get_tree_view (
        const_cast<GtkTreeSelection*> (gobj ()));
    return glib::wrap (gtk_tree_view_get_model (tree_view), true);
  }

  auto
  TreeSelection::get_selected () -> TreeModel::iterator
  {
    TreeModel::iterator iter;
    GtkTreeModel* model_gobject = nullptr;

    gtk_tree_selection_get_selected (gobj (), &model_gobject, iter.gobj ());

    iter.set_model_gobject (model_gobject);
    return iter;
  }

  auto
  TreeSelection::get_selected () const -> TreeModel::const_iterator
  {
    return const_cast<TreeSelection*> (this)->get_selected ();
  }

  auto
  TreeSelection::get_selected (glib::RefPtr<TreeModel>& model) -> TreeModel::iterator
  {
    TreeModel::iterator iter;
    GtkTreeModel* model_gobject = nullptr;

    gtk_tree_selection_get_selected (gobj (), &model_gobject, iter.gobj ());

    model = glib::wrap (model_gobject, true);

    iter.set_model_refptr (model);
    return iter;
  }

  auto
  TreeSelection::get_selected (glib::RefPtr<const TreeModel>& model) const -> TreeModel::const_iterator
  {
    TreeModel::iterator iter;
    GtkTreeModel* model_gobject = nullptr;

    gtk_tree_selection_get_selected (const_cast<GtkTreeSelection*> (gobj ()),
                                     &model_gobject,
                                     iter.gobj ());

    model = glib::wrap (model_gobject, true);

    iter.set_model_refptr (std::const_pointer_cast<TreeModel> (model));
    return iter;
  }

  auto
  TreeSelection::selected_foreach_iter (const SlotForeachIter& slot) const -> void
  {
    SlotForeachIter slot_copy (slot);
    gtk_tree_selection_selected_foreach (
        const_cast<GtkTreeSelection*> (gobj ()),
        &proxy_foreach_selection_iter_callback,
        &slot_copy);
  }

  auto
  TreeSelection::selected_foreach_path (const SlotForeachPath& slot) const -> void
  {
    SlotForeachPath slot_copy (slot);
    gtk_tree_selection_selected_foreach (
        const_cast<GtkTreeSelection*> (gobj ()),
        &proxy_foreach_selection_path_callback,
        &slot_copy);
  }

  auto
  TreeSelection::selected_foreach (const SlotForeachPathAndIter& slot) const -> void
  {
    SlotForeachPathAndIter slot_copy (slot);
    gtk_tree_selection_selected_foreach (
        const_cast<GtkTreeSelection*> (gobj ()),
        &proxy_foreach_selection_path_and_iter_callback,
        &slot_copy);
  }

  auto
  TreeSelection::get_selected_rows () const -> std::vector<TreeModel::Path>
  {
    return glib::ListHandler<TreeModel::Path, TreePathTraits>::list_to_vector (
        gtk_tree_selection_get_selected_rows (
            const_cast<GtkTreeSelection*> (gobj ()),
            nullptr),
        glib::OWNERSHIP_DEEP);
  }

  auto
  TreeSelection::get_selected_rows (glib::RefPtr<TreeModel>& model) -> std::vector<TreeModel::Path>
  {
    GtkTreeModel* model_gobject = nullptr;

    const std::vector<TreeModel::Path> result (
        glib::ListHandler<TreeModel::Path, TreePathTraits>::list_to_vector (
            gtk_tree_selection_get_selected_rows (
                const_cast<GtkTreeSelection*> (gobj ()),
                &model_gobject),
            glib::OWNERSHIP_DEEP));

    model = glib::wrap (model_gobject, true);
    return result;
  }

} // namespace gtk

namespace
{

  static const glib::SignalProxyInfo TreeSelection_signal_changed_info = {
      "changed",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

}

namespace glib
{

  auto
  wrap (GtkTreeSelection* object, bool take_copy) -> glib::RefPtr<gtk::TreeSelection>
  {
    return glib::make_refptr_for_instance<gtk::TreeSelection> (
        dynamic_cast<gtk::TreeSelection*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  TreeSelection_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &TreeSelection_Class::class_init_function;

      register_derived_type (gtk_tree_selection_get_type ());
    }

    return *this;
  }

  auto
  TreeSelection_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  TreeSelection_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new TreeSelection ((GtkTreeSelection*) object);
  }

  auto
  TreeSelection::gobj_copy () -> GtkTreeSelection*
  {
    reference ();
    return gobj ();
  }

  TreeSelection::TreeSelection (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  TreeSelection::TreeSelection (GtkTreeSelection* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  TreeSelection::TreeSelection (TreeSelection&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  TreeSelection::operator= (TreeSelection&& src) noexcept -> TreeSelection&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  TreeSelection::~TreeSelection () noexcept {}

  TreeSelection::CppClassType TreeSelection::treeselection_class_;

  auto
  TreeSelection::get_type () -> GType
  {
    return treeselection_class_.init ().get_type ();
  }

  auto
  TreeSelection::get_base_type () -> GType
  {
    return gtk_tree_selection_get_type ();
  }

  auto
  TreeSelection::set_mode (SelectionMode type) -> void
  {
    gtk_tree_selection_set_mode (gobj (), static_cast<GtkSelectionMode> (type));
  }

  auto
  TreeSelection::get_mode () const -> SelectionMode
  {
    return static_cast<SelectionMode> (
        gtk_tree_selection_get_mode (const_cast<GtkTreeSelection*> (gobj ())));
  }

  auto
  TreeSelection::get_tree_view () -> TreeView*
  {
    return glib::wrap (gtk_tree_selection_get_tree_view (gobj ()));
  }

  auto
  TreeSelection::get_tree_view () const -> const TreeView*
  {
    return const_cast<TreeSelection*> (this)->get_tree_view ();
  }

  auto
  TreeSelection::count_selected_rows () const -> int
  {
    return gtk_tree_selection_count_selected_rows (
        const_cast<GtkTreeSelection*> (gobj ()));
  }

  auto
  TreeSelection::select (const TreeModel::Path& path) -> void
  {
    gtk_tree_selection_select_path (gobj (),
                                    const_cast<GtkTreePath*> ((path).gobj ()));
  }

  auto
  TreeSelection::select (const TreeModel::Path& start_path,
                         const TreeModel::Path& end_path) -> void
  {
    gtk_tree_selection_select_range (
        gobj (),
        const_cast<GtkTreePath*> ((start_path).gobj ()),
        const_cast<GtkTreePath*> ((end_path).gobj ()));
  }

  auto
  TreeSelection::select (const TreeModel::const_iterator& iter) -> void
  {
    gtk_tree_selection_select_iter (gobj (),
                                    const_cast<GtkTreeIter*> ((iter).gobj ()));
  }

  auto
  TreeSelection::unselect (const TreeModel::Path& path) -> void
  {
    gtk_tree_selection_unselect_path (
        gobj (),
        const_cast<GtkTreePath*> ((path).gobj ()));
  }

  auto
  TreeSelection::unselect (const TreeModel::Path& start_path,
                           const TreeModel::Path& end_path) -> void
  {
    gtk_tree_selection_unselect_range (
        gobj (),
        const_cast<GtkTreePath*> ((start_path).gobj ()),
        const_cast<GtkTreePath*> ((end_path).gobj ()));
  }

  auto
  TreeSelection::unselect (const TreeModel::const_iterator& iter) -> void
  {
    gtk_tree_selection_unselect_iter (
        gobj (),
        const_cast<GtkTreeIter*> ((iter).gobj ()));
  }

  auto
  TreeSelection::is_selected (const TreeModel::Path& path) const -> bool
  {
    return gtk_tree_selection_path_is_selected (
        const_cast<GtkTreeSelection*> (gobj ()),
        const_cast<GtkTreePath*> ((path).gobj ()));
  }

  auto
  TreeSelection::is_selected (const TreeModel::const_iterator& iter) const -> bool
  {
    return gtk_tree_selection_iter_is_selected (
        const_cast<GtkTreeSelection*> (gobj ()),
        const_cast<GtkTreeIter*> ((iter).gobj ()));
  }

  auto
  TreeSelection::select_all () -> void
  {
    gtk_tree_selection_select_all (gobj ());
  }

  auto
  TreeSelection::unselect_all () -> void
  {
    gtk_tree_selection_unselect_all (gobj ());
  }

  auto
  TreeSelection::signal_changed () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this,
                                       &TreeSelection_signal_changed_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<SelectionMode>::value,
      "Type SelectionMode cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TreeSelection::property_mode () -> glib::PropertyProxy<SelectionMode>
  {
    return glib::PropertyProxy<SelectionMode> (this, "mode");
  }

  auto
  TreeSelection::property_mode () const -> glib::PropertyProxy_ReadOnly<SelectionMode>
  {
    return glib::PropertyProxy_ReadOnly<SelectionMode> (this, "mode");
  }

} // namespace gtk

#endif
