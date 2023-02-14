

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/treelistmodel.hxx>
#include <libmm-gtk/treelistmodel_p.hxx>

#include <gtk/gtk.h>

namespace
{

  auto
  TreeListModel_CreateModelFunc (const gpointer item, const gpointer user_data) -> GListModel*
  {
    const auto slot =
        static_cast<Gtk::TreeListModel::SlotCreateModel*> (user_data);
    const auto result = (*slot) (Glib::wrap (G_OBJECT (item), true));
    if (result)
      return G_LIST_MODEL (result->gobj_copy ());
    else
      return nullptr;
  }

} // namespace

namespace Gtk
{

  TreeListModel::TreeListModel (const Glib::RefPtr<ListModel>& root,
                                const SlotCreateModel& slot_create,
                                const bool passthrough,
                                const bool autoexpand)
    : ObjectBase (nullptr),
      Object (G_OBJECT (gtk_tree_list_model_new (
          G_LIST_MODEL (root->gobj_copy ()),
          passthrough,
          autoexpand,
          &TreeListModel_CreateModelFunc,
          new SlotCreateModel (slot_create),
          &Glib::destroy_notify_delete<SlotCreateModel>)))
  {
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkTreeListModel* object, const bool take_copy) -> RefPtr<Gtk::TreeListModel>
  {
    return Glib::make_refptr_for_instance<Gtk::TreeListModel> (
        dynamic_cast<Gtk::TreeListModel*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  TreeListModel_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &TreeListModel_Class::class_init_function;

      gtype_ = gtk_tree_list_model_get_type ();
    }

    return *this;
  }

  auto
  TreeListModel_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  TreeListModel_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new TreeListModel ((GtkTreeListModel*) object);
  }

  auto
  TreeListModel::gobj_copy () -> GtkTreeListModel*
  {
    reference ();
    return gobj ();
  }

  TreeListModel::TreeListModel (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  TreeListModel::TreeListModel (GtkTreeListModel* castitem)
    : Object ((GObject*) castitem)
  {
  }

  TreeListModel::TreeListModel (TreeListModel&& src) noexcept
    : Object (std::move (src)),
      ListModel (std::move (src))
  {
  }

  auto
  TreeListModel::operator= (TreeListModel&& src) noexcept -> TreeListModel&
  {
    Object::operator= (std::move (src));
    ListModel::operator= (std::move (src));
    return *this;
  }

  TreeListModel::~TreeListModel () noexcept = default;

  TreeListModel::CppClassType TreeListModel::treelistmodel_class_;

  auto
  TreeListModel::get_type () -> GType
  {
    return treelistmodel_class_.init ().get_type ();
  }

  auto
  TreeListModel::get_base_type () -> GType
  {
    return gtk_tree_list_model_get_type ();
  }

  auto
  TreeListModel::create (const Glib::RefPtr<ListModel>& root,
                         const SlotCreateModel& slot_create,
                         const bool passthrough,
                         const bool autoexpand) -> Glib::RefPtr<TreeListModel>
  {
    return Glib::make_refptr_for_instance<TreeListModel> (
        new TreeListModel (root, slot_create, passthrough, autoexpand));
  }

  auto
  TreeListModel::get_model () -> Glib::RefPtr<ListModel>
  {
    auto retvalue = Glib::wrap (gtk_tree_list_model_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TreeListModel::get_model () const -> Glib::RefPtr<const ListModel>
  {
    return const_cast<TreeListModel*> (this)->get_model ();
  }

  auto
  TreeListModel::get_passthrough () const -> bool
  {
    return gtk_tree_list_model_get_passthrough (
        const_cast<GtkTreeListModel*> (gobj ()));
  }

  auto
  TreeListModel::set_autoexpand (const bool autoexpand) -> void
  {
    gtk_tree_list_model_set_autoexpand (gobj (), autoexpand);
  }

  auto
  TreeListModel::get_autoexpand () const -> bool
  {
    return gtk_tree_list_model_get_autoexpand (
        const_cast<GtkTreeListModel*> (gobj ()));
  }

  auto
  TreeListModel::get_child_row (const guint position) -> Glib::RefPtr<TreeListRow>
  {
    return Glib::wrap (gtk_tree_list_model_get_child_row (gobj (), position));
  }

  auto
  TreeListModel::get_child_row (const guint position) const -> Glib::RefPtr<const TreeListRow>
  {
    return const_cast<TreeListModel*> (this)->get_child_row (position);
  }

  auto
  TreeListModel::get_row (const guint position) -> Glib::RefPtr<TreeListRow>
  {
    return Glib::wrap (gtk_tree_list_model_get_row (gobj (), position));
  }

  auto
  TreeListModel::get_row (const guint position) const -> Glib::RefPtr<const TreeListRow>
  {
    return const_cast<TreeListModel*> (this)->get_row (position);
  }

  auto
  TreeListModel::property_autoexpand () -> Glib::PropertyProxy<bool>
  {
    return {this, "autoexpand"};
  }

  auto
  TreeListModel::property_autoexpand () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "autoexpand"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
      "Type GType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TreeListModel::property_item_type () const -> Glib::PropertyProxy_ReadOnly<GType>
  {
    return {this, "item-type"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::ListModel>>::value,
      "Type Glib::RefPtr<Gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TreeListModel::property_model () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ListModel>>
  {
    return {this, "model"};
  }

  auto
  TreeListModel::property_n_items () const -> Glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return {this, "n-items"};
  }

  auto
  TreeListModel::property_passthrough () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "passthrough"};
  }

} // namespace Gtk
