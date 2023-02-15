// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/treelistrow.hxx>
#include <libmm-gtk/treelistrow_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkTreeListRow* object, bool take_copy) -> Glib::RefPtr<Gtk::TreeListRow>
  {
    return Glib::make_refptr_for_instance<Gtk::TreeListRow> (
        dynamic_cast<Gtk::TreeListRow*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  TreeListRow_Class::init () -> const Glib::Class&
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
  TreeListRow_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new TreeListRow ((GtkTreeListRow*) object);
  }

  auto
  TreeListRow::gobj_copy () -> GtkTreeListRow*
  {
    reference ();
    return gobj ();
  }

  TreeListRow::TreeListRow (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  TreeListRow::TreeListRow (GtkTreeListRow* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  TreeListRow::TreeListRow (TreeListRow&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  TreeListRow::operator= (TreeListRow&& src) noexcept -> TreeListRow&
  {
    Glib::Object::operator= (std::move (src));
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
  TreeListRow::get_item () -> Glib::RefPtr<Glib::ObjectBase>
  {
    return Glib::make_refptr_for_instance<Glib::ObjectBase> (
        Glib::wrap_auto (G_OBJECT (gtk_tree_list_row_get_item (gobj ()))));
  }

  auto
  TreeListRow::get_item () const -> Glib::RefPtr<const Glib::ObjectBase>
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
  TreeListRow::get_children () -> Glib::RefPtr<Gio::ListModel>
  {
    auto retvalue = Glib::wrap (gtk_tree_list_row_get_children (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TreeListRow::get_children () const -> Glib::RefPtr<const Gio::ListModel>
  {
    return const_cast<TreeListRow*> (this)->get_children ();
  }

  auto
  TreeListRow::get_parent () -> Glib::RefPtr<TreeListRow>
  {
    return Glib::wrap (gtk_tree_list_row_get_parent (gobj ()));
  }

  auto
  TreeListRow::get_parent () const -> Glib::RefPtr<const TreeListRow>
  {
    return const_cast<TreeListRow*> (this)->get_parent ();
  }

  auto
  TreeListRow::get_child_row (guint position) -> Glib::RefPtr<TreeListRow>
  {
    return Glib::wrap (gtk_tree_list_row_get_child_row (gobj (), position));
  }

  auto
  TreeListRow::get_child_row (guint position) const -> Glib::RefPtr<const TreeListRow>
  {
    return const_cast<TreeListRow*> (this)->get_child_row (position);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::ListModel>>::value,
      "Type Glib::RefPtr<Gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TreeListRow::property_children () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>> (
        this,
        "children");
  }

  auto
  TreeListRow::property_depth () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "depth");
  }

  auto
  TreeListRow::property_expandable () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "expandable");
  }

  auto
  TreeListRow::property_expanded () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "expanded");
  }

  auto
  TreeListRow::property_expanded () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "expanded");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Glib::ObjectBase>>::value,
      "Type Glib::RefPtr<Glib::ObjectBase> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TreeListRow::property_item () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Glib::ObjectBase>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Glib::ObjectBase>> (
        this,
        "item");
  }

} // namespace Gtk
