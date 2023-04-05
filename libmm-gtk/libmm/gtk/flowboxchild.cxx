// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/flowboxchild.hxx>
#include <libmm/gtk/flowboxchild_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  auto
  FlowBoxChild::unset_child () -> void
  {
    gtk_flow_box_child_set_child (gobj (), nullptr);
  }

} // namespace gtk

namespace
{

  static const glib::SignalProxyInfo FlowBoxChild_signal_activate_info = {
      "activate",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

}

namespace glib
{

  auto
  wrap (GtkFlowBoxChild* object, bool take_copy) -> gtk::FlowBoxChild*
  {
    return dynamic_cast<gtk::FlowBoxChild*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  FlowBoxChild_Class::init () -> const glib::Class&
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
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

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
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->activate)
      (*base->activate) (self);
  }

  auto
  FlowBoxChild_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new FlowBoxChild ((GtkFlowBoxChild*) (o)));
  }

  FlowBoxChild::FlowBoxChild (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  FlowBoxChild::FlowBoxChild (GtkFlowBoxChild* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  FlowBoxChild::FlowBoxChild (FlowBoxChild&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  FlowBoxChild::operator= (FlowBoxChild&& src) noexcept -> FlowBoxChild&
  {
    gtk::Widget::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (flowboxchild_class_.init ()))
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
    return glib::wrap (gtk_flow_box_child_get_child (gobj ()));
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
  FlowBoxChild::signal_activate () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this,
                                       &FlowBoxChild_signal_activate_info);
  }

  auto
  FlowBoxChild::property_child () -> glib::PropertyProxy<Widget*>
  {
    return glib::PropertyProxy<Widget*> (this, "child");
  }

  auto
  FlowBoxChild::property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "child");
  }

  auto
  gtk::FlowBoxChild::on_activate () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->activate)
      (*base->activate) (gobj ());
  }

} // namespace gtk
