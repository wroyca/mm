// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/scrollable.hxx>
#include <libmm/gtk/scrollable_p.hxx>

#include <gtk/gtk.h>

using Policy = Gtk::Scrollable::Policy;

namespace Gtk
{

  auto
  Scrollable_Class::get_border_vfunc_callback (GtkScrollable* self,
                                               GtkBorder* border) -> gboolean
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          Border border_copy (border, true);
          auto result = obj->get_border_vfunc (border_copy);
          if (border)
            *border = *border_copy.gobj ();
          return result;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->get_border)
      return (*base->get_border) (self, border);

    using RType = gboolean;
    return RType ();
  }

  auto
  Scrollable::unset_hadjustment () -> void
  {
    gtk_scrollable_set_hadjustment (gobj (), nullptr);
  }

  auto
  Scrollable::unset_vadjustment () -> void
  {
    gtk_scrollable_set_vadjustment (gobj (), nullptr);
  }

} // namespace Gtk

namespace
{
}

auto
Glib::Value<Gtk::Scrollable::Policy>::value_type () -> GType
{
  return gtk_scrollable_policy_get_type ();
}

namespace Glib
{

  auto
  wrap (GtkScrollable* object, bool take_copy) -> Glib::RefPtr<Gtk::Scrollable>
  {
    return Glib::make_refptr_for_instance<Gtk::Scrollable> (
        dynamic_cast<Gtk::Scrollable*> (
            Glib::wrap_auto_interface<Gtk::Scrollable> ((GObject*) (object),
                                                        take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Scrollable_Class::init () -> const Glib::Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Scrollable_Class::iface_init_function;

      gtype_ = gtk_scrollable_get_type ();
    }

    return *this;
  }

  auto
  Scrollable_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->get_border = &get_border_vfunc_callback;
  }

  auto
  Scrollable_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Scrollable ((GtkScrollable*) (object));
  }

  Scrollable::Scrollable ()
    : Glib::Interface (scrollable_class_.init ())
  {
  }

  Scrollable::Scrollable (GtkScrollable* castitem)
    : Glib::Interface ((GObject*) (castitem))
  {
  }

  Scrollable::Scrollable (const Glib::Interface_Class& interface_class)
    : Glib::Interface (interface_class)
  {
  }

  Scrollable::Scrollable (Scrollable&& src) noexcept
    : Glib::Interface (std::move (src))
  {
  }

  auto
  Scrollable::operator= (Scrollable&& src) noexcept -> Scrollable&
  {
    Glib::Interface::operator= (std::move (src));
    return *this;
  }

  Scrollable::~Scrollable () noexcept {}

  auto
  Scrollable::add_interface (GType gtype_implementer) -> void
  {
    scrollable_class_.init ().add_interface (gtype_implementer);
  }

  Scrollable::CppClassType Scrollable::scrollable_class_;

  auto
  Scrollable::get_type () -> GType
  {
    return scrollable_class_.init ().get_type ();
  }

  auto
  Scrollable::get_base_type () -> GType
  {
    return gtk_scrollable_get_type ();
  }

  auto
  Scrollable::get_hadjustment () -> Glib::RefPtr<Adjustment>
  {
    auto retvalue = Glib::wrap (gtk_scrollable_get_hadjustment (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Scrollable::get_hadjustment () const -> Glib::RefPtr<const Adjustment>
  {
    return const_cast<Scrollable*> (this)->get_hadjustment ();
  }

  auto
  Scrollable::set_hadjustment (const Glib::RefPtr<Adjustment>& hadjustment) -> void
  {
    gtk_scrollable_set_hadjustment (gobj (), Glib::unwrap (hadjustment));
  }

  auto
  Scrollable::get_vadjustment () -> Glib::RefPtr<Adjustment>
  {
    auto retvalue = Glib::wrap (gtk_scrollable_get_vadjustment (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Scrollable::get_vadjustment () const -> Glib::RefPtr<const Adjustment>
  {
    auto retvalue = Glib::wrap (
        gtk_scrollable_get_vadjustment (const_cast<GtkScrollable*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Scrollable::set_vadjustment (const Glib::RefPtr<Adjustment>& vadjustment) -> void
  {
    gtk_scrollable_set_vadjustment (gobj (), Glib::unwrap (vadjustment));
  }

  auto
  Scrollable::get_hscroll_policy () const -> Policy
  {
    return static_cast<Policy> (gtk_scrollable_get_hscroll_policy (
        const_cast<GtkScrollable*> (gobj ())));
  }

  auto
  Scrollable::set_hscroll_policy (Policy policy) -> void
  {
    gtk_scrollable_set_hscroll_policy (
        gobj (),
        static_cast<GtkScrollablePolicy> (policy));
  }

  auto
  Scrollable::get_vscroll_policy () const -> Policy
  {
    return static_cast<Policy> (gtk_scrollable_get_vscroll_policy (
        const_cast<GtkScrollable*> (gobj ())));
  }

  auto
  Scrollable::set_vscroll_policy (Policy policy) -> void
  {
    gtk_scrollable_set_vscroll_policy (
        gobj (),
        static_cast<GtkScrollablePolicy> (policy));
  }

  auto
  Scrollable::get_border (Border& border) const -> bool
  {
    return gtk_scrollable_get_border (const_cast<GtkScrollable*> (gobj ()),
                                      (border).gobj ());
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Adjustment>>::value,
      "Type Glib::RefPtr<Adjustment> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Scrollable::property_hadjustment () -> Glib::PropertyProxy<Glib::RefPtr<Adjustment>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Adjustment>> (this, "hadjustment");
  }

  auto
  Scrollable::property_hadjustment () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Adjustment>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Adjustment>> (
        this,
        "hadjustment");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Adjustment>>::value,
      "Type Glib::RefPtr<Adjustment> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Scrollable::property_vadjustment () -> Glib::PropertyProxy<Glib::RefPtr<Adjustment>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Adjustment>> (this, "vadjustment");
  }

  auto
  Scrollable::property_vadjustment () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Adjustment>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Adjustment>> (
        this,
        "vadjustment");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Policy>::value,
      "Type Policy cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Scrollable::property_hscroll_policy () -> Glib::PropertyProxy<Policy>
  {
    return Glib::PropertyProxy<Policy> (this, "hscroll-policy");
  }

  auto
  Scrollable::property_hscroll_policy () const -> Glib::PropertyProxy_ReadOnly<Policy>
  {
    return Glib::PropertyProxy_ReadOnly<Policy> (this, "hscroll-policy");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Policy>::value,
      "Type Policy cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Scrollable::property_vscroll_policy () -> Glib::PropertyProxy<Policy>
  {
    return Glib::PropertyProxy<Policy> (this, "vscroll-policy");
  }

  auto
  Scrollable::property_vscroll_policy () const -> Glib::PropertyProxy_ReadOnly<Policy>
  {
    return Glib::PropertyProxy_ReadOnly<Policy> (this, "vscroll-policy");
  }

  auto
  Gtk::Scrollable::get_border_vfunc (Border& border) const -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->get_border)
    {
      bool retval ((*base->get_border) (const_cast<GtkScrollable*> (gobj ()),
                                        (border).gobj ()));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

} // namespace Gtk
