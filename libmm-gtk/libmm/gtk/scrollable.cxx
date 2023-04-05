// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/scrollable.hxx>
#include <libmm/gtk/scrollable_p.hxx>

#include <gtk/gtk.h>

using Policy = gtk::Scrollable::Policy;

namespace gtk
{

  auto
  Scrollable_Class::get_border_vfunc_callback (GtkScrollable* self,
                                               GtkBorder* border) -> gboolean
  {
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

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
          glib::exception_handlers_invoke ();
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

} // namespace gtk

namespace
{
}

auto
glib::Value<gtk::Scrollable::Policy>::value_type () -> GType
{
  return gtk_scrollable_policy_get_type ();
}

namespace glib
{

  auto
  wrap (GtkScrollable* object, bool take_copy) -> glib::RefPtr<gtk::Scrollable>
  {
    return glib::make_refptr_for_instance<gtk::Scrollable> (
        dynamic_cast<gtk::Scrollable*> (
            glib::wrap_auto_interface<gtk::Scrollable> ((GObject*) (object),
                                                        take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  Scrollable_Class::init () -> const glib::Interface_Class&
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
  Scrollable_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Scrollable ((GtkScrollable*) (object));
  }

  Scrollable::Scrollable ()
    : glib::Interface (scrollable_class_.init ())
  {
  }

  Scrollable::Scrollable (GtkScrollable* castitem)
    : glib::Interface ((GObject*) (castitem))
  {
  }

  Scrollable::Scrollable (const glib::Interface_Class& interface_class)
    : glib::Interface (interface_class)
  {
  }

  Scrollable::Scrollable (Scrollable&& src) noexcept
    : glib::Interface (std::move (src))
  {
  }

  auto
  Scrollable::operator= (Scrollable&& src) noexcept -> Scrollable&
  {
    glib::Interface::operator= (std::move (src));
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
  Scrollable::get_hadjustment () -> glib::RefPtr<Adjustment>
  {
    auto retvalue = glib::wrap (gtk_scrollable_get_hadjustment (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Scrollable::get_hadjustment () const -> glib::RefPtr<const Adjustment>
  {
    return const_cast<Scrollable*> (this)->get_hadjustment ();
  }

  auto
  Scrollable::set_hadjustment (const glib::RefPtr<Adjustment>& hadjustment) -> void
  {
    gtk_scrollable_set_hadjustment (gobj (), glib::unwrap (hadjustment));
  }

  auto
  Scrollable::get_vadjustment () -> glib::RefPtr<Adjustment>
  {
    auto retvalue = glib::wrap (gtk_scrollable_get_vadjustment (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Scrollable::get_vadjustment () const -> glib::RefPtr<const Adjustment>
  {
    auto retvalue = glib::wrap (
        gtk_scrollable_get_vadjustment (const_cast<GtkScrollable*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Scrollable::set_vadjustment (const glib::RefPtr<Adjustment>& vadjustment) -> void
  {
    gtk_scrollable_set_vadjustment (gobj (), glib::unwrap (vadjustment));
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
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Adjustment>>::value,
      "Type glib::RefPtr<Adjustment> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Scrollable::property_hadjustment () -> glib::PropertyProxy<glib::RefPtr<Adjustment>>
  {
    return glib::PropertyProxy<glib::RefPtr<Adjustment>> (this, "hadjustment");
  }

  auto
  Scrollable::property_hadjustment () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Adjustment>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Adjustment>> (
        this,
        "hadjustment");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Adjustment>>::value,
      "Type glib::RefPtr<Adjustment> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Scrollable::property_vadjustment () -> glib::PropertyProxy<glib::RefPtr<Adjustment>>
  {
    return glib::PropertyProxy<glib::RefPtr<Adjustment>> (this, "vadjustment");
  }

  auto
  Scrollable::property_vadjustment () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Adjustment>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Adjustment>> (
        this,
        "vadjustment");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Policy>::value,
      "Type Policy cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Scrollable::property_hscroll_policy () -> glib::PropertyProxy<Policy>
  {
    return glib::PropertyProxy<Policy> (this, "hscroll-policy");
  }

  auto
  Scrollable::property_hscroll_policy () const -> glib::PropertyProxy_ReadOnly<Policy>
  {
    return glib::PropertyProxy_ReadOnly<Policy> (this, "hscroll-policy");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Policy>::value,
      "Type Policy cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Scrollable::property_vscroll_policy () -> glib::PropertyProxy<Policy>
  {
    return glib::PropertyProxy<Policy> (this, "vscroll-policy");
  }

  auto
  Scrollable::property_vscroll_policy () const -> glib::PropertyProxy_ReadOnly<Policy>
  {
    return glib::PropertyProxy_ReadOnly<Policy> (this, "vscroll-policy");
  }

  auto
  gtk::Scrollable::get_border_vfunc (Border& border) const -> bool
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

} // namespace gtk
