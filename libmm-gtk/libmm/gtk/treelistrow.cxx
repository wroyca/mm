// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/treelistrow.hxx>
#include <libmm/gtk/treelistrow_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkTreeListRow* object, bool take_copy) -> glib::RefPtr<gtk::TreeListRow>
  {
    return glib::make_refptr_for_instance<gtk::TreeListRow> (
        dynamic_cast<gtk::TreeListRow*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  TreeListRow_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &TreeListRow_Class::class_init_function;

      gtype_ = gtk_tree_list_row_get_type ();
    }

    return *this;
  }

  auto
  TreeListRow_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  TreeListRow_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new TreeListRow ((GtkTreeListRow*) object);
  }

  auto
  TreeListRow::gobj_copy () -> GtkTreeListRow*
  {
    reference ();
    return gobj ();
  }

  TreeListRow::TreeListRow (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  TreeListRow::TreeListRow (GtkTreeListRow* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  TreeListRow::TreeListRow (TreeListRow&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  TreeListRow::operator= (TreeListRow&& src) noexcept -> TreeListRow&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  TreeListRow::~TreeListRow () noexcept {}

  TreeListRow::CppClassType TreeListRow::treelistrow_class_;

  auto
  TreeListRow::get_type () -> GType
  {
    return treelistrow_class_.init ().get_type ();
  }

  auto
  TreeListRow::get_base_type () -> GType
  {
    return gtk_tree_list_row_get_type ();
  }

  auto
  TreeListRow::get_item () -> glib::RefPtr<glib::ObjectBase>
  {
    return glib::make_refptr_for_instance<glib::ObjectBase> (
        glib::wrap_auto (G_OBJECT (gtk_tree_list_row_get_item (gobj ()))));
  }

  auto
  TreeListRow::get_item () const -> glib::RefPtr<const glib::ObjectBase>
  {
    return const_cast<TreeListRow*> (this)->get_item ();
  }

  auto
  TreeListRow::set_expanded (bool expanded) -> void
  {
    gtk_tree_list_row_set_expanded (gobj (), static_cast<int> (expanded));
  }

  auto
  TreeListRow::get_expanded () const -> bool
  {
    return gtk_tree_list_row_get_expanded (
        const_cast<GtkTreeListRow*> (gobj ()));
  }

  auto
  TreeListRow::is_expandable () const -> bool
  {
    return gtk_tree_list_row_is_expandable (
        const_cast<GtkTreeListRow*> (gobj ()));
  }

  auto
  TreeListRow::get_position () const -> guint
  {
    return gtk_tree_list_row_get_position (
        const_cast<GtkTreeListRow*> (gobj ()));
  }

  auto
  TreeListRow::get_depth () const -> guint
  {
    return gtk_tree_list_row_get_depth (const_cast<GtkTreeListRow*> (gobj ()));
  }

  auto
  TreeListRow::get_children () -> glib::RefPtr<gio::ListModel>
  {
    auto retvalue = glib::wrap (gtk_tree_list_row_get_children (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TreeListRow::get_children () const -> glib::RefPtr<const gio::ListModel>
  {
    return const_cast<TreeListRow*> (this)->get_children ();
  }

  auto
  TreeListRow::get_parent () -> glib::RefPtr<TreeListRow>
  {
    return glib::wrap (gtk_tree_list_row_get_parent (gobj ()));
  }

  auto
  TreeListRow::get_parent () const -> glib::RefPtr<const TreeListRow>
  {
    return const_cast<TreeListRow*> (this)->get_parent ();
  }

  auto
  TreeListRow::get_child_row (guint position) -> glib::RefPtr<TreeListRow>
  {
    return glib::wrap (gtk_tree_list_row_get_child_row (gobj (), position));
  }

  auto
  TreeListRow::get_child_row (guint position) const -> glib::RefPtr<const TreeListRow>
  {
    return const_cast<TreeListRow*> (this)->get_child_row (position);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::ListModel>>::value,
      "Type glib::RefPtr<gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TreeListRow::property_children () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>> (
        this,
        "children");
  }

  auto
  TreeListRow::property_depth () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "depth");
  }

  auto
  TreeListRow::property_expandable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "expandable");
  }

  auto
  TreeListRow::property_expanded () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "expanded");
  }

  auto
  TreeListRow::property_expanded () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "expanded");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<glib::ObjectBase>>::value,
      "Type glib::RefPtr<glib::ObjectBase> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TreeListRow::property_item () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::ObjectBase>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::ObjectBase>> (
        this,
        "item");
  }

} // namespace gtk
