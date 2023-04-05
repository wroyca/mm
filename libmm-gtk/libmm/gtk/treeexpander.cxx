// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/treeexpander.hxx>
#include <libmm/gtk/treeexpander_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  auto
  TreeExpander::unset_child () -> void
  {
    gtk_tree_expander_set_child (gobj (), nullptr);
  }

  auto
  TreeExpander::unset_list_row () -> void
  {
    gtk_tree_expander_set_list_row (gobj (), nullptr);
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkTreeExpander* object, bool take_copy) -> gtk::TreeExpander*
  {
    return dynamic_cast<gtk::TreeExpander*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  TreeExpander_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &TreeExpander_Class::class_init_function;

      gtype_ = gtk_tree_expander_get_type ();
    }

    return *this;
  }

  auto
  TreeExpander_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  TreeExpander_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new TreeExpander ((GtkTreeExpander*) (o)));
  }

  TreeExpander::TreeExpander (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  TreeExpander::TreeExpander (GtkTreeExpander* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  TreeExpander::TreeExpander (TreeExpander&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  TreeExpander::operator= (TreeExpander&& src) noexcept -> TreeExpander&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  TreeExpander::~TreeExpander () noexcept
  {
    destroy_ ();
  }

  TreeExpander::CppClassType TreeExpander::treeexpander_class_;

  auto
  TreeExpander::get_type () -> GType
  {
    return treeexpander_class_.init ().get_type ();
  }

  auto
  TreeExpander::get_base_type () -> GType
  {
    return gtk_tree_expander_get_type ();
  }

  TreeExpander::TreeExpander ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (treeexpander_class_.init ()))
  {
  }

  auto
  TreeExpander::get_child () -> Widget*
  {
    return glib::wrap (gtk_tree_expander_get_child (gobj ()));
  }

  auto
  TreeExpander::get_child () const -> const Widget*
  {
    return const_cast<TreeExpander*> (this)->get_child ();
  }

  auto
  TreeExpander::set_child (Widget& widget) -> void
  {
    gtk_tree_expander_set_child (gobj (), (widget).gobj ());
  }

  auto
  TreeExpander::get_item () -> glib::RefPtr<glib::ObjectBase>
  {
    return glib::make_refptr_for_instance<glib::ObjectBase> (
        glib::wrap_auto (G_OBJECT (gtk_tree_expander_get_item (gobj ()))));
  }

  auto
  TreeExpander::get_item () const -> glib::RefPtr<const glib::ObjectBase>
  {
    return const_cast<TreeExpander*> (this)->get_item ();
  }

  auto
  TreeExpander::get_list_row () -> glib::RefPtr<TreeListRow>
  {
    auto retvalue = glib::wrap (gtk_tree_expander_get_list_row (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TreeExpander::get_list_row () const -> glib::RefPtr<const TreeListRow>
  {
    return const_cast<TreeExpander*> (this)->get_list_row ();
  }

  auto
  TreeExpander::set_list_row (const glib::RefPtr<TreeListRow>& list_row) -> void
  {
    gtk_tree_expander_set_list_row (gobj (), glib::unwrap (list_row));
  }

  auto
  TreeExpander::get_indent_for_depth () const -> bool
  {
    return gtk_tree_expander_get_indent_for_depth (
        const_cast<GtkTreeExpander*> (gobj ()));
  }

  auto
  TreeExpander::set_indent_for_depth (bool indent_for_depth) -> void
  {
    gtk_tree_expander_set_indent_for_depth (
        gobj (),
        static_cast<int> (indent_for_depth));
  }

  auto
  TreeExpander::get_indent_for_icon () const -> bool
  {
    return gtk_tree_expander_get_indent_for_icon (
        const_cast<GtkTreeExpander*> (gobj ()));
  }

  auto
  TreeExpander::set_indent_for_icon (bool indent_for_icon) -> void
  {
    gtk_tree_expander_set_indent_for_icon (gobj (),
                                           static_cast<int> (indent_for_icon));
  }

  auto
  TreeExpander::get_hide_expander () const -> bool
  {
    return gtk_tree_expander_get_hide_expander (
        const_cast<GtkTreeExpander*> (gobj ()));
  }

  auto
  TreeExpander::set_hide_expander (bool hide_expander) -> void
  {
    gtk_tree_expander_set_hide_expander (gobj (),
                                         static_cast<int> (hide_expander));
  }

  auto
  TreeExpander::property_child () -> glib::PropertyProxy<Widget*>
  {
    return glib::PropertyProxy<Widget*> (this, "child");
  }

  auto
  TreeExpander::property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "child");
  }

  auto
  TreeExpander::property_hide_expander () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "hide-expander");
  }

  auto
  TreeExpander::property_hide_expander () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "hide-expander");
  }

  auto
  TreeExpander::property_indent_for_depth () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "indent-for-depth");
  }

  auto
  TreeExpander::property_indent_for_depth () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "indent-for-depth");
  }

  auto
  TreeExpander::property_indent_for_icon () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "indent-for-icon");
  }

  auto
  TreeExpander::property_indent_for_icon () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "indent-for-icon");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<glib::ObjectBase>>::value,
      "Type glib::RefPtr<glib::ObjectBase> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TreeExpander::property_item () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::ObjectBase>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::ObjectBase>> (
        this,
        "item");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<TreeListRow>>::value,
      "Type glib::RefPtr<TreeListRow> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TreeExpander::property_list_row () -> glib::PropertyProxy<glib::RefPtr<TreeListRow>>
  {
    return glib::PropertyProxy<glib::RefPtr<TreeListRow>> (this, "list-row");
  }

  auto
  TreeExpander::property_list_row () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<TreeListRow>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<TreeListRow>> (this,
                                                                    "list-row");
  }

} // namespace gtk
