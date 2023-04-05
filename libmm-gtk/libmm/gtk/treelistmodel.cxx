// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/treelistmodel.hxx>
#include <libmm/gtk/treelistmodel_p.hxx>

#include <gtk/gtk.h>

namespace
{

  auto
  TreeListModel_CreateModelFunc (gpointer item, gpointer user_data) -> GListModel*
  {
    auto slot = static_cast<gtk::TreeListModel::SlotCreateModel*> (user_data);
    auto result = (*slot) (glib::wrap (G_OBJECT (item), true));
    if (result)
      return G_LIST_MODEL (result->gobj_copy ());
    else
      return nullptr;
  }

} // namespace

namespace gtk
{

  TreeListModel::TreeListModel (const glib::RefPtr<gio::ListModel>& root,
                                const SlotCreateModel& slot_create,
                                bool passthrough,
                                bool autoexpand)
    : glib::ObjectBase (nullptr),
      glib::Object (G_OBJECT (gtk_tree_list_model_new (
          G_LIST_MODEL (root->gobj_copy ()),
          passthrough,
          autoexpand,
          &TreeListModel_CreateModelFunc,
          new SlotCreateModel (slot_create),
          &glib::destroy_notify_delete<SlotCreateModel>)))
  {
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkTreeListModel* object, bool take_copy) -> glib::RefPtr<gtk::TreeListModel>
  {
    return glib::make_refptr_for_instance<gtk::TreeListModel> (
        dynamic_cast<gtk::TreeListModel*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  TreeListModel_Class::init () -> const glib::Class&
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
  TreeListModel_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new TreeListModel ((GtkTreeListModel*) object);
  }

  auto
  TreeListModel::gobj_copy () -> GtkTreeListModel*
  {
    reference ();
    return gobj ();
  }

  TreeListModel::TreeListModel (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  TreeListModel::TreeListModel (GtkTreeListModel* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  TreeListModel::TreeListModel (TreeListModel&& src) noexcept
    : glib::Object (std::move (src)),
      gio::ListModel (std::move (src))
  {
  }

  auto
  TreeListModel::operator= (TreeListModel&& src) noexcept -> TreeListModel&
  {
    glib::Object::operator= (std::move (src));
    gio::ListModel::operator= (std::move (src));
    return *this;
  }

  TreeListModel::~TreeListModel () noexcept {}

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
  TreeListModel::create (const glib::RefPtr<gio::ListModel>& root,
                         const SlotCreateModel& slot_create,
                         bool passthrough,
                         bool autoexpand) -> glib::RefPtr<TreeListModel>
  {
    return glib::make_refptr_for_instance<TreeListModel> (
        new TreeListModel (root, slot_create, passthrough, autoexpand));
  }

  auto
  TreeListModel::get_model () -> glib::RefPtr<gio::ListModel>
  {
    auto retvalue = glib::wrap (gtk_tree_list_model_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TreeListModel::get_model () const -> glib::RefPtr<const gio::ListModel>
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
  TreeListModel::set_autoexpand (bool autoexpand) -> void
  {
    gtk_tree_list_model_set_autoexpand (gobj (), static_cast<int> (autoexpand));
  }

  auto
  TreeListModel::get_autoexpand () const -> bool
  {
    return gtk_tree_list_model_get_autoexpand (
        const_cast<GtkTreeListModel*> (gobj ()));
  }

  auto
  TreeListModel::get_child_row (guint position) -> glib::RefPtr<TreeListRow>
  {
    return glib::wrap (gtk_tree_list_model_get_child_row (gobj (), position));
  }

  auto
  TreeListModel::get_child_row (guint position) const -> glib::RefPtr<const TreeListRow>
  {
    return const_cast<TreeListModel*> (this)->get_child_row (position);
  }

  auto
  TreeListModel::get_row (guint position) -> glib::RefPtr<TreeListRow>
  {
    return glib::wrap (gtk_tree_list_model_get_row (gobj (), position));
  }

  auto
  TreeListModel::get_row (guint position) const -> glib::RefPtr<const TreeListRow>
  {
    return const_cast<TreeListModel*> (this)->get_row (position);
  }

  auto
  TreeListModel::property_autoexpand () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "autoexpand");
  }

  auto
  TreeListModel::property_autoexpand () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "autoexpand");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
      "Type GType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TreeListModel::property_item_type () const -> glib::PropertyProxy_ReadOnly<GType>
  {
    return glib::PropertyProxy_ReadOnly<GType> (this, "item-type");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::ListModel>>::value,
      "Type glib::RefPtr<gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TreeListModel::property_model () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>> (this,
                                                                       "model");
  }

  auto
  TreeListModel::property_n_items () const -> glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return glib::PropertyProxy_ReadOnly<unsigned int> (this, "n-items");
  }

  auto
  TreeListModel::property_passthrough () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "passthrough");
  }

} // namespace gtk
