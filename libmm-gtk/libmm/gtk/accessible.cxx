// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/accessible.hxx>
#include <libmm/gtk/accessible_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gtk/atcontext.hxx>

using Role = gtk::Accessible::Role;

namespace gtk
{

  auto
  Accessible::update_state (State state, const glib::ValueBase& value) -> void
  {
    auto c_state = static_cast<GtkAccessibleState> (state);
    gtk_accessible_update_state_value (gobj (), 1, &c_state, value.gobj ());
  }

  auto
  Accessible::update_property (Property property, const glib::ValueBase& value) -> void
  {
    auto c_prop = static_cast<GtkAccessibleProperty> (property);
    gtk_accessible_update_property_value (gobj (), 1, &c_prop, value.gobj ());
  }

  auto
  Accessible::update_relation (Relation relation, const glib::ValueBase& value) -> void
  {
    auto c_rel = static_cast<GtkAccessibleRelation> (relation);
    gtk_accessible_update_relation_value (gobj (), 1, &c_rel, value.gobj ());
  }

} // namespace gtk

namespace
{
}

auto
glib::Value<gtk::Accessible::Role>::value_type () -> GType
{
  return gtk_accessible_role_get_type ();
}

auto
glib::Value<gtk::Accessible::State>::value_type () -> GType
{
  return gtk_accessible_state_get_type ();
}

auto
glib::Value<gtk::Accessible::Property>::value_type () -> GType
{
  return gtk_accessible_property_get_type ();
}

auto
glib::Value<gtk::Accessible::Relation>::value_type () -> GType
{
  return gtk_accessible_relation_get_type ();
}

auto
glib::Value<gtk::Accessible::PlatformState>::value_type () -> GType
{
  return gtk_accessible_platform_state_get_type ();
}

namespace glib
{

  auto
  wrap (GtkAccessible* object, bool take_copy) -> glib::RefPtr<gtk::Accessible>
  {
    return glib::make_refptr_for_instance<gtk::Accessible> (
        dynamic_cast<gtk::Accessible*> (
            glib::wrap_auto_interface<gtk::Accessible> ((GObject*) (object),
                                                        take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  Accessible_Class::init () -> const glib::Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Accessible_Class::iface_init_function;

      gtype_ = gtk_accessible_get_type ();
    }

    return *this;
  }

  auto
  Accessible_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);
  }

  auto
  Accessible_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Accessible ((GtkAccessible*) (object));
  }

  Accessible::Accessible ()
    : glib::Interface (accessible_class_.init ())
  {
  }

  Accessible::Accessible (GtkAccessible* castitem)
    : glib::Interface ((GObject*) (castitem))
  {
  }

  Accessible::Accessible (const glib::Interface_Class& interface_class)
    : glib::Interface (interface_class)
  {
  }

  Accessible::Accessible (Accessible&& src) noexcept
    : glib::Interface (std::move (src))
  {
  }

  auto
  Accessible::operator= (Accessible&& src) noexcept -> Accessible&
  {
    glib::Interface::operator= (std::move (src));
    return *this;
  }

  Accessible::~Accessible () noexcept {}

  auto
  Accessible::add_interface (GType gtype_implementer) -> void
  {
    accessible_class_.init ().add_interface (gtype_implementer);
  }

  Accessible::CppClassType Accessible::accessible_class_;

  auto
  Accessible::get_type () -> GType
  {
    return accessible_class_.init ().get_type ();
  }

  auto
  Accessible::get_base_type () -> GType
  {
    return gtk_accessible_get_type ();
  }

  auto
  Accessible::get_at_context () -> glib::RefPtr<ATContext>
  {
    auto retvalue = glib::wrap (gtk_accessible_get_at_context (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Accessible::get_at_context () const -> glib::RefPtr<const ATContext>
  {
    return const_cast<Accessible*> (this)->get_at_context ();
  }

  auto
  Accessible::get_platform_state (PlatformState state) const -> bool
  {
    return gtk_accessible_get_platform_state (
        const_cast<GtkAccessible*> (gobj ()),
        static_cast<GtkAccessiblePlatformState> (state));
  }

  auto
  Accessible::get_accessible_parent () -> glib::RefPtr<Accessible>
  {
    auto retvalue = glib::wrap (gtk_accessible_get_accessible_parent (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Accessible::get_accessible_parent () const -> glib::RefPtr<const Accessible>
  {
    return const_cast<Accessible*> (this)->get_accessible_parent ();
  }

  auto
  Accessible::get_first_accessible_child () -> glib::RefPtr<Accessible>
  {
    auto retvalue =
        glib::wrap (gtk_accessible_get_first_accessible_child (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Accessible::get_first_accessible_child () const -> glib::RefPtr<const Accessible>
  {
    return const_cast<Accessible*> (this)->get_first_accessible_child ();
  }

  auto
  Accessible::get_next_accessible_sibling () -> glib::RefPtr<Accessible>
  {
    auto retvalue =
        glib::wrap (gtk_accessible_get_next_accessible_sibling (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Accessible::get_next_accessible_sibling () const -> glib::RefPtr<const Accessible>
  {
    return const_cast<Accessible*> (this)->get_next_accessible_sibling ();
  }

  auto
  Accessible::get_bounds (int& x, int& y, int& width, int& height) const -> bool
  {
    return gtk_accessible_get_bounds (const_cast<GtkAccessible*> (gobj ()),
                                      &(x),
                                      &(y),
                                      &(width),
                                      &(height));
  }

  auto
  Accessible::get_accessible_role () const -> Role
  {
    return static_cast<Role> (gtk_accessible_get_accessible_role (
        const_cast<GtkAccessible*> (gobj ())));
  }

  auto
  Accessible::reset_state (State state) -> void
  {
    gtk_accessible_reset_state (gobj (),
                                static_cast<GtkAccessibleState> (state));
  }

  auto
  Accessible::reset_property (Property property) -> void
  {
    gtk_accessible_reset_property (
        gobj (),
        static_cast<GtkAccessibleProperty> (property));
  }

  auto
  Accessible::reset_relation (Relation relation) -> void
  {
    gtk_accessible_reset_relation (
        gobj (),
        static_cast<GtkAccessibleRelation> (relation));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Role>::value,
      "Type Role cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Accessible::property_accessible_role () -> glib::PropertyProxy<Role>
  {
    return glib::PropertyProxy<Role> (this, "accessible-role");
  }

  auto
  Accessible::property_accessible_role () const -> glib::PropertyProxy_ReadOnly<Role>
  {
    return glib::PropertyProxy_ReadOnly<Role> (this, "accessible-role");
  }

} // namespace gtk
