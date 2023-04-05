// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/popover.hxx>
#include <libmm/gtk/popover_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  auto
  Popover::unset_child () -> void
  {
    gtk_popover_set_child (gobj (), nullptr);
  }

} // namespace gtk

namespace
{

  static const glib::SignalProxyInfo Popover_signal_closed_info = {
      "closed",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

}

namespace glib
{

  auto
  wrap (GtkPopover* object, bool take_copy) -> gtk::Popover*
  {
    return dynamic_cast<gtk::Popover*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  Popover_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Popover_Class::class_init_function;

      register_derived_type (gtk_popover_get_type ());

      ShortcutManager::add_interface (get_type ());
      Native::add_interface (get_type ());
    }

    return *this;
  }

  auto
  Popover_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->closed = &closed_callback;
  }

  auto
  Popover_Class::closed_callback (GtkPopover* self) -> void
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
          obj->on_closed ();
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->closed)
      (*base->closed) (self);
  }

  auto
  Popover_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Popover ((GtkPopover*) (o)));
  }

  Popover::Popover (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Popover::Popover (GtkPopover* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Popover::Popover (Popover&& src) noexcept
    : gtk::Widget (std::move (src)),
      ShortcutManager (std::move (src)),
      Native (std::move (src))
  {
  }

  auto
  Popover::operator= (Popover&& src) noexcept -> Popover&
  {
    gtk::Widget::operator= (std::move (src));
    ShortcutManager::operator= (std::move (src));
    Native::operator= (std::move (src));
    return *this;
  }

  Popover::~Popover () noexcept
  {
    destroy_ ();
  }

  Popover::CppClassType Popover::popover_class_;

  auto
  Popover::get_type () -> GType
  {
    return popover_class_.init ().get_type ();
  }

  auto
  Popover::get_base_type () -> GType
  {
    return gtk_popover_get_type ();
  }

  Popover::Popover ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (popover_class_.init ()))
  {
  }

  auto
  Popover::set_child (Widget& child) -> void
  {
    gtk_popover_set_child (gobj (), (child).gobj ());
  }

  auto
  Popover::get_child () -> Widget*
  {
    return glib::wrap (gtk_popover_get_child (gobj ()));
  }

  auto
  Popover::get_child () const -> const Widget*
  {
    return const_cast<Popover*> (this)->get_child ();
  }

  auto
  Popover::set_pointing_to (const gdk::Rectangle& rect) -> void
  {
    gtk_popover_set_pointing_to (gobj (), (rect).gobj ());
  }

  auto
  Popover::get_pointing_to (gdk::Rectangle& rect) const -> bool
  {
    return gtk_popover_get_pointing_to (const_cast<GtkPopover*> (gobj ()),
                                        (rect).gobj ());
  }

  auto
  Popover::set_position (PositionType position) -> void
  {
    gtk_popover_set_position (gobj (), static_cast<GtkPositionType> (position));
  }

  auto
  Popover::get_position () const -> PositionType
  {
    return static_cast<PositionType> (
        gtk_popover_get_position (const_cast<GtkPopover*> (gobj ())));
  }

  auto
  Popover::set_autohide (bool autohide) -> void
  {
    gtk_popover_set_autohide (gobj (), static_cast<int> (autohide));
  }

  auto
  Popover::get_autohide () const -> bool
  {
    return gtk_popover_get_autohide (const_cast<GtkPopover*> (gobj ()));
  }

  auto
  Popover::set_has_arrow (bool has_arrow) -> void
  {
    gtk_popover_set_has_arrow (gobj (), static_cast<int> (has_arrow));
  }

  auto
  Popover::get_has_arrow () const -> bool
  {
    return gtk_popover_get_has_arrow (const_cast<GtkPopover*> (gobj ()));
  }

  auto
  Popover::set_mnemonics_visible (bool mnemonics_visible) -> void
  {
    gtk_popover_set_mnemonics_visible (gobj (),
                                       static_cast<int> (mnemonics_visible));
  }

  auto
  Popover::get_mnemonics_visible () const -> bool
  {
    return gtk_popover_get_mnemonics_visible (
        const_cast<GtkPopover*> (gobj ()));
  }

  auto
  Popover::popup () -> void
  {
    gtk_popover_popup (gobj ());
  }

  auto
  Popover::popdown () -> void
  {
    gtk_popover_popdown (gobj ());
  }

  auto
  Popover::set_offset (int x_offset, int y_offset) -> void
  {
    gtk_popover_set_offset (gobj (), x_offset, y_offset);
  }

  auto
  Popover::get_offset (int& x_offset, int& y_offset) const -> void
  {
    gtk_popover_get_offset (const_cast<GtkPopover*> (gobj ()),
                            &(x_offset),
                            &(y_offset));
  }

  auto
  Popover::set_cascade_popdown (bool cascade_popdown) -> void
  {
    gtk_popover_set_cascade_popdown (gobj (),
                                     static_cast<int> (cascade_popdown));
  }

  auto
  Popover::get_cascade_popdown () const -> bool
  {
    return gtk_popover_get_cascade_popdown (const_cast<GtkPopover*> (gobj ()));
  }

  auto
  Popover::set_default_widget (Widget& widget) -> void
  {
    gtk_popover_set_default_widget (gobj (), (widget).gobj ());
  }

  auto
  Popover::present () -> void
  {
    gtk_popover_present (gobj ());
  }

  auto
  Popover::signal_closed () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &Popover_signal_closed_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<gdk::Rectangle>::value,
      "Type gdk::Rectangle cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Popover::property_pointing_to () -> glib::PropertyProxy<gdk::Rectangle>
  {
    return glib::PropertyProxy<gdk::Rectangle> (this, "pointing-to");
  }

  auto
  Popover::property_pointing_to () const -> glib::PropertyProxy_ReadOnly<gdk::Rectangle>
  {
    return glib::PropertyProxy_ReadOnly<gdk::Rectangle> (this, "pointing-to");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<PositionType>::value,
      "Type PositionType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Popover::property_position () -> glib::PropertyProxy<PositionType>
  {
    return glib::PropertyProxy<PositionType> (this, "position");
  }

  auto
  Popover::property_position () const -> glib::PropertyProxy_ReadOnly<PositionType>
  {
    return glib::PropertyProxy_ReadOnly<PositionType> (this, "position");
  }

  auto
  Popover::property_autohide () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "autohide");
  }

  auto
  Popover::property_autohide () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "autohide");
  }

  auto
  Popover::property_has_arrow () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "has-arrow");
  }

  auto
  Popover::property_has_arrow () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "has-arrow");
  }

  auto
  Popover::property_default_widget () -> glib::PropertyProxy<Widget*>
  {
    return glib::PropertyProxy<Widget*> (this, "default-widget");
  }

  auto
  Popover::property_default_widget () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "default-widget");
  }

  auto
  Popover::property_mnemonics_visible () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "mnemonics-visible");
  }

  auto
  Popover::property_mnemonics_visible () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "mnemonics-visible");
  }

  auto
  Popover::property_child () -> glib::PropertyProxy<Widget*>
  {
    return glib::PropertyProxy<Widget*> (this, "child");
  }

  auto
  Popover::property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "child");
  }

  auto
  Popover::property_cascade_popdown () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "cascade-popdown");
  }

  auto
  Popover::property_cascade_popdown () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "cascade-popdown");
  }

  auto
  gtk::Popover::on_closed () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->closed)
      (*base->closed) (gobj ());
  }

} // namespace gtk
