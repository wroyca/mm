// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/revealer.hxx>
#include <libmm-gtk/revealer_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  auto
  Revealer::unset_child () -> void
  {
    gtk_revealer_set_child (gobj (), nullptr);
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkRevealer* object, const bool take_copy) -> Gtk::Revealer*
  {
    return dynamic_cast<Gtk::Revealer*> (
        wrap_auto ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Revealer_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Revealer_Class::class_init_function;

      register_derived_type (gtk_revealer_get_type ());
    }

    return *this;
  }

  auto
  Revealer_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Revealer_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new Revealer ((GtkRevealer*) o));
  }

  Revealer::Revealer (const Glib::ConstructParams& construct_params)
    : Widget (construct_params)
  {
  }

  Revealer::Revealer (GtkRevealer* castitem)
    : Widget ((GtkWidget*) castitem)
  {
  }

  Revealer::Revealer (Revealer&& src) noexcept
    : Widget (std::move (src))
  {
  }

  auto
  Revealer::operator= (Revealer&& src) noexcept -> Revealer&
  {
    Widget::operator= (std::move (src));
    return *this;
  }

  Revealer::~Revealer () noexcept
  {
    destroy_ ();
  }

  Revealer::CppClassType Revealer::revealer_class_;

  auto
  Revealer::get_type () -> GType
  {
    return revealer_class_.init ().get_type ();
  }

  auto
  Revealer::get_base_type () -> GType
  {
    return gtk_revealer_get_type ();
  }

  Revealer::Revealer ()
    : ObjectBase (nullptr),
      Widget (Glib::ConstructParams (revealer_class_.init ()))
  {
  }

  auto
  Revealer::get_reveal_child () const -> bool
  {
    return gtk_revealer_get_reveal_child (const_cast<GtkRevealer*> (gobj ()));
  }

  auto
  Revealer::set_reveal_child (const bool reveal_child) -> void
  {
    gtk_revealer_set_reveal_child (gobj (), reveal_child);
  }

  auto
  Revealer::get_child_revealed () const -> bool
  {
    return gtk_revealer_get_child_revealed (const_cast<GtkRevealer*> (gobj ()));
  }

  auto
  Revealer::get_transition_duration () const -> guint
  {
    return gtk_revealer_get_transition_duration (
        const_cast<GtkRevealer*> (gobj ()));
  }

  auto
  Revealer::set_transition_duration (const guint duration) -> void
  {
    gtk_revealer_set_transition_duration (gobj (), duration);
  }

  auto
  Revealer::get_transition_type () const -> RevealerTransitionType
  {
    return static_cast<RevealerTransitionType> (
        gtk_revealer_get_transition_type (const_cast<GtkRevealer*> (gobj ())));
  }

  auto
  Revealer::set_transition_type (RevealerTransitionType transition) -> void
  {
    gtk_revealer_set_transition_type (
        gobj (),
        static_cast<GtkRevealerTransitionType> (transition));
  }

  auto
  Revealer::set_child (Widget& child) -> void
  {
    gtk_revealer_set_child (gobj (), child.gobj ());
  }

  auto
  Revealer::get_child () -> Widget*
  {
    return Glib::wrap (gtk_revealer_get_child (gobj ()));
  }

  auto
  Revealer::get_child () const -> const Widget*
  {
    return const_cast<Revealer*> (this)->get_child ();
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          RevealerTransitionType>::value,
      "Type RevealerTransitionType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Revealer::property_transition_type () -> Glib::PropertyProxy<RevealerTransitionType>
  {
    return {this, "transition-type"};
  }

  auto
  Revealer::property_transition_type () const -> Glib::PropertyProxy_ReadOnly<RevealerTransitionType>
  {
    return {this, "transition-type"};
  }

  auto
  Revealer::property_transition_duration () -> Glib::PropertyProxy<guint>
  {
    return {this, "transition-duration"};
  }

  auto
  Revealer::property_transition_duration () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return {this, "transition-duration"};
  }

  auto
  Revealer::property_reveal_child () -> Glib::PropertyProxy<bool>
  {
    return {this, "reveal-child"};
  }

  auto
  Revealer::property_reveal_child () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "reveal-child"};
  }

  auto
  Revealer::property_child_revealed () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "child-revealed"};
  }

  auto
  Revealer::property_child () -> Glib::PropertyProxy<Widget*>
  {
    return {this, "child"};
  }

  auto
  Revealer::property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>
  {
    return {this, "child"};
  }

} // namespace Gtk
