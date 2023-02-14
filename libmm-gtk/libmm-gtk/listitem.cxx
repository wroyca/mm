

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/listitem.hxx>
#include <libmm-gtk/listitem_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  auto
  ListItem::unset_child () -> void
  {
    gtk_list_item_set_child (gobj (), nullptr);
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkListItem* object, const bool take_copy) -> RefPtr<Gtk::ListItem>
  {
    return Glib::make_refptr_for_instance<Gtk::ListItem> (
        dynamic_cast<Gtk::ListItem*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ListItem_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ListItem_Class::class_init_function;

      register_derived_type (gtk_list_item_get_type ());
    }

    return *this;
  }

  auto
  ListItem_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ListItem_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new ListItem ((GtkListItem*) object);
  }

  auto
  ListItem::gobj_copy () -> GtkListItem*
  {
    reference ();
    return gobj ();
  }

  ListItem::ListItem (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  ListItem::ListItem (GtkListItem* castitem)
    : Object ((GObject*) castitem)
  {
  }

  ListItem::ListItem (ListItem&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  ListItem::operator= (ListItem&& src) noexcept -> ListItem&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  ListItem::~ListItem () noexcept = default;

  ListItem::CppClassType ListItem::listitem_class_;

  auto
  ListItem::get_type () -> GType
  {
    return listitem_class_.init ().get_type ();
  }

  auto
  ListItem::get_base_type () -> GType
  {
    return gtk_list_item_get_type ();
  }

  auto
  ListItem::get_item () -> Glib::RefPtr<ObjectBase>
  {
    auto retvalue = Glib::make_refptr_for_instance<ObjectBase> (
        Glib::wrap_auto (G_OBJECT (gtk_list_item_get_item (gobj ()))));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ListItem::get_item () const -> Glib::RefPtr<const ObjectBase>
  {
    return const_cast<ListItem*> (this)->get_item ();
  }

  auto
  ListItem::get_position () const -> guint
  {
    return gtk_list_item_get_position (const_cast<GtkListItem*> (gobj ()));
  }

  auto
  ListItem::get_selected () const -> bool
  {
    return gtk_list_item_get_selected (const_cast<GtkListItem*> (gobj ()));
  }

  auto
  ListItem::get_selectable () const -> bool
  {
    return gtk_list_item_get_selectable (const_cast<GtkListItem*> (gobj ()));
  }

  auto
  ListItem::set_selectable (const bool selectable) -> void
  {
    gtk_list_item_set_selectable (gobj (), selectable);
  }

  auto
  ListItem::get_activatable () const -> bool
  {
    return gtk_list_item_get_activatable (const_cast<GtkListItem*> (gobj ()));
  }

  auto
  ListItem::set_activatable (const bool activatable) -> void
  {
    gtk_list_item_set_activatable (gobj (), activatable);
  }

  auto
  ListItem::set_child (Widget& child) -> void
  {
    gtk_list_item_set_child (gobj (), child.gobj ());
  }

  auto
  ListItem::get_child () -> Widget*
  {
    return Glib::wrap (gtk_list_item_get_child (gobj ()));
  }

  auto
  ListItem::get_child () const -> const Widget*
  {
    return const_cast<ListItem*> (this)->get_child ();
  }

  auto
  ListItem::property_activatable () -> Glib::PropertyProxy<bool>
  {
    return {this, "activatable"};
  }

  auto
  ListItem::property_activatable () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "activatable"};
  }

  auto
  ListItem::property_child () -> Glib::PropertyProxy<Widget*>
  {
    return {this, "child"};
  }

  auto
  ListItem::property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>
  {
    return {this, "child"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Glib::ObjectBase>>::value,
      "Type Glib::RefPtr<Glib::ObjectBase> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ListItem::property_item () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ObjectBase>>
  {
    return {this, "item"};
  }

  auto
  ListItem::property_position () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return {this, "position"};
  }

  auto
  ListItem::property_selectable () -> Glib::PropertyProxy<bool>
  {
    return {this, "selectable"};
  }

  auto
  ListItem::property_selectable () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "selectable"};
  }

  auto
  ListItem::property_selected () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "selected"};
  }

} // namespace Gtk
