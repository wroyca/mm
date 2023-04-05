// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/listitem.hxx>
#include <libmm/gtk/listitem_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  auto
  ListItem::unset_child () -> void
  {
    gtk_list_item_set_child (gobj (), nullptr);
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkListItem* object, bool take_copy) -> glib::RefPtr<gtk::ListItem>
  {
    return glib::make_refptr_for_instance<gtk::ListItem> (
        dynamic_cast<gtk::ListItem*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  ListItem_Class::init () -> const glib::Class&
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
  ListItem_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new ListItem ((GtkListItem*) object);
  }

  auto
  ListItem::gobj_copy () -> GtkListItem*
  {
    reference ();
    return gobj ();
  }

  ListItem::ListItem (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  ListItem::ListItem (GtkListItem* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  ListItem::ListItem (ListItem&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  ListItem::operator= (ListItem&& src) noexcept -> ListItem&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  ListItem::~ListItem () noexcept {}

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
  ListItem::get_item () -> glib::RefPtr<glib::ObjectBase>
  {
    auto retvalue = glib::make_refptr_for_instance<glib::ObjectBase> (
        glib::wrap_auto (G_OBJECT (gtk_list_item_get_item (gobj ()))));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ListItem::get_item () const -> glib::RefPtr<const glib::ObjectBase>
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
  ListItem::set_selectable (bool selectable) -> void
  {
    gtk_list_item_set_selectable (gobj (), static_cast<int> (selectable));
  }

  auto
  ListItem::get_activatable () const -> bool
  {
    return gtk_list_item_get_activatable (const_cast<GtkListItem*> (gobj ()));
  }

  auto
  ListItem::set_activatable (bool activatable) -> void
  {
    gtk_list_item_set_activatable (gobj (), static_cast<int> (activatable));
  }

  auto
  ListItem::set_child (Widget& child) -> void
  {
    gtk_list_item_set_child (gobj (), (child).gobj ());
  }

  auto
  ListItem::get_child () -> Widget*
  {
    return glib::wrap (gtk_list_item_get_child (gobj ()));
  }

  auto
  ListItem::get_child () const -> const Widget*
  {
    return const_cast<ListItem*> (this)->get_child ();
  }

  auto
  ListItem::property_activatable () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "activatable");
  }

  auto
  ListItem::property_activatable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "activatable");
  }

  auto
  ListItem::property_child () -> glib::PropertyProxy<Widget*>
  {
    return glib::PropertyProxy<Widget*> (this, "child");
  }

  auto
  ListItem::property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "child");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<glib::ObjectBase>>::value,
      "Type glib::RefPtr<glib::ObjectBase> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ListItem::property_item () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::ObjectBase>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::ObjectBase>> (
        this,
        "item");
  }

  auto
  ListItem::property_position () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "position");
  }

  auto
  ListItem::property_selectable () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "selectable");
  }

  auto
  ListItem::property_selectable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "selectable");
  }

  auto
  ListItem::property_selected () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "selected");
  }

} // namespace gtk
