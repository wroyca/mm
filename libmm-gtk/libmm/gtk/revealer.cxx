// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/revealer.hxx>
#include <libmm/gtk/revealer_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  auto
  Revealer::unset_child () -> void
  {
    gtk_revealer_set_child (gobj (), nullptr);
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkRevealer* object, bool take_copy) -> gtk::Revealer*
  {
    return dynamic_cast<gtk::Revealer*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  Revealer_Class::init () -> const glib::Class&
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
  Revealer_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Revealer ((GtkRevealer*) (o)));
  }

  Revealer::Revealer (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Revealer::Revealer (GtkRevealer* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Revealer::Revealer (Revealer&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  Revealer::operator= (Revealer&& src) noexcept -> Revealer&
  {
    gtk::Widget::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (revealer_class_.init ()))
  {
  }

  auto
  Revealer::get_reveal_child () const -> bool
  {
    return gtk_revealer_get_reveal_child (const_cast<GtkRevealer*> (gobj ()));
  }

  auto
  Revealer::set_reveal_child (bool reveal_child) -> void
  {
    gtk_revealer_set_reveal_child (gobj (), static_cast<int> (reveal_child));
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
  Revealer::set_transition_duration (guint duration) -> void
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
    gtk_revealer_set_child (gobj (), (child).gobj ());
  }

  auto
  Revealer::get_child () -> Widget*
  {
    return glib::wrap (gtk_revealer_get_child (gobj ()));
  }

  auto
  Revealer::get_child () const -> const Widget*
  {
    return const_cast<Revealer*> (this)->get_child ();
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          RevealerTransitionType>::value,
      "Type RevealerTransitionType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Revealer::property_transition_type () -> glib::PropertyProxy<RevealerTransitionType>
  {
    return glib::PropertyProxy<RevealerTransitionType> (this,
                                                        "transition-type");
  }

  auto
  Revealer::property_transition_type () const -> glib::PropertyProxy_ReadOnly<RevealerTransitionType>
  {
    return glib::PropertyProxy_ReadOnly<RevealerTransitionType> (
        this,
        "transition-type");
  }

  auto
  Revealer::property_transition_duration () -> glib::PropertyProxy<guint>
  {
    return glib::PropertyProxy<guint> (this, "transition-duration");
  }

  auto
  Revealer::property_transition_duration () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "transition-duration");
  }

  auto
  Revealer::property_reveal_child () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "reveal-child");
  }

  auto
  Revealer::property_reveal_child () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "reveal-child");
  }

  auto
  Revealer::property_child_revealed () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "child-revealed");
  }

  auto
  Revealer::property_child () -> glib::PropertyProxy<Widget*>
  {
    return glib::PropertyProxy<Widget*> (this, "child");
  }

  auto
  Revealer::property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "child");
  }

} // namespace gtk
