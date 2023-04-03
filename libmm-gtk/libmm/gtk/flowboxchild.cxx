// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/flowboxchild.hxx>
#include <libmm/gtk/flowboxchild_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  auto
  FlowBoxChild::unset_child () -> void
  {
    gtk_flow_box_child_set_child (gobj (), nullptr);
  }

} // namespace Gtk

namespace
{

  static const Glib::SignalProxyInfo FlowBoxChild_signal_activate_info = {
      "activate",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

}

namespace Glib
{

  auto
  wrap (GtkFlowBoxChild* object, bool take_copy) -> Gtk::FlowBoxChild*
  {
    return dynamic_cast<Gtk::FlowBoxChild*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  FlowBoxChild_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FlowBoxChild_Class::class_init_function;

      register_derived_type (gtk_flow_box_child_get_type ());
    }

    return *this;
  }

  auto
  FlowBoxChild_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->activate = &activate_callback;
  }

  auto
  FlowBoxChild_Class::activate_callback (GtkFlowBoxChild* self) -> void
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
          obj->on_activate ();
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->activate)
      (*base->activate) (self);
  }

  auto
  FlowBoxChild_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new FlowBoxChild ((GtkFlowBoxChild*) (o)));
  }

  FlowBoxChild::FlowBoxChild (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  FlowBoxChild::FlowBoxChild (GtkFlowBoxChild* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  FlowBoxChild::FlowBoxChild (FlowBoxChild&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  FlowBoxChild::operator= (FlowBoxChild&& src) noexcept -> FlowBoxChild&
  {
    Gtk::Widget::operator= (std::move (src));
    return *this;
  }

  FlowBoxChild::~FlowBoxChild () noexcept
  {
    destroy_ ();
  }

  FlowBoxChild::CppClassType FlowBoxChild::flowboxchild_class_;

  auto
  FlowBoxChild::get_type () -> GType
  {
    return flowboxchild_class_.init ().get_type ();
  }

  auto
  FlowBoxChild::get_base_type () -> GType
  {
    return gtk_flow_box_child_get_type ();
  }

  FlowBoxChild::FlowBoxChild ()
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (flowboxchild_class_.init ()))
  {
  }

  auto
  FlowBoxChild::set_child (Widget& child) -> void
  {
    gtk_flow_box_child_set_child (gobj (), (child).gobj ());
  }

  auto
  FlowBoxChild::get_child () -> Widget*
  {
    return Glib::wrap (gtk_flow_box_child_get_child (gobj ()));
  }

  auto
  FlowBoxChild::get_child () const -> const Widget*
  {
    return const_cast<FlowBoxChild*> (this)->get_child ();
  }

  auto
  FlowBoxChild::get_index () const -> int
  {
    return gtk_flow_box_child_get_index (
        const_cast<GtkFlowBoxChild*> (gobj ()));
  }

  auto
  FlowBoxChild::is_selected () const -> bool
  {
    return gtk_flow_box_child_is_selected (
        const_cast<GtkFlowBoxChild*> (gobj ()));
  }

  auto
  FlowBoxChild::changed () -> void
  {
    gtk_flow_box_child_changed (gobj ());
  }

  auto
  FlowBoxChild::signal_activate () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this,
                                       &FlowBoxChild_signal_activate_info);
  }

  auto
  FlowBoxChild::property_child () -> Glib::PropertyProxy<Widget*>
  {
    return Glib::PropertyProxy<Widget*> (this, "child");
  }

  auto
  FlowBoxChild::property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Widget*> (this, "child");
  }

  auto
  Gtk::FlowBoxChild::on_activate () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->activate)
      (*base->activate) (gobj ());
  }

} // namespace Gtk
