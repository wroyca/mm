// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/celleditable.hxx>
#include <libmm/gtk/celleditable_p.hxx>

#include <gtk/gtk.h>

namespace
{

#ifndef GTKMM_DISABLE_DEPRECATED

  static const glib::SignalProxyInfo CellEditable_signal_editing_done_info = {
      "editing_done",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

#endif

#ifndef GTKMM_DISABLE_DEPRECATED

  static const glib::SignalProxyInfo CellEditable_signal_remove_widget_info = {
      "remove_widget",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

#endif

} // namespace

namespace glib
{

  auto
  wrap (GtkCellEditable* object, bool take_copy) -> glib::RefPtr<gtk::CellEditable>
  {
    return glib::make_refptr_for_instance<gtk::CellEditable> (
        dynamic_cast<gtk::CellEditable*> (
            glib::wrap_auto_interface<gtk::CellEditable> ((GObject*) (object),
                                                          take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  CellEditable_Class::init () -> const glib::Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &CellEditable_Class::iface_init_function;

      gtype_ = gtk_cell_editable_get_type ();
    }

    return *this;
  }

  auto
  CellEditable_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->start_editing = &start_editing_vfunc_callback;

#ifndef GTKMM_DISABLE_DEPRECATED

    klass->editing_done = &editing_done_callback;
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

    klass->remove_widget = &remove_widget_callback;
#endif
  }

  auto
  CellEditable_Class::start_editing_vfunc_callback (GtkCellEditable* self,
                                                    GdkEvent* event) -> void
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
          obj->start_editing_vfunc (glib::wrap (event, true));
          return;
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

    if (base && base->start_editing)
      (*base->start_editing) (self, event);
  }

#ifndef GTKMM_DISABLE_DEPRECATED

  auto
  CellEditable_Class::editing_done_callback (GtkCellEditable* self) -> void
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
          obj->on_editing_done ();
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->editing_done)
      (*base->editing_done) (self);
  }
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

  auto
  CellEditable_Class::remove_widget_callback (GtkCellEditable* self) -> void
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
          obj->on_remove_widget ();
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->remove_widget)
      (*base->remove_widget) (self);
  }
#endif

  auto
  CellEditable_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new CellEditable ((GtkCellEditable*) (object));
  }

  CellEditable::CellEditable ()
    : glib::Interface (celleditable_class_.init ())
  {
  }

  CellEditable::CellEditable (GtkCellEditable* castitem)
    : glib::Interface ((GObject*) (castitem))
  {
  }

  CellEditable::CellEditable (const glib::Interface_Class& interface_class)
    : glib::Interface (interface_class)
  {
  }

  CellEditable::CellEditable (CellEditable&& src) noexcept
    : glib::Interface (std::move (src))
  {
  }

  auto
  CellEditable::operator= (CellEditable&& src) noexcept -> CellEditable&
  {
    glib::Interface::operator= (std::move (src));
    return *this;
  }

  CellEditable::~CellEditable () noexcept {}

  auto
  CellEditable::add_interface (GType gtype_implementer) -> void
  {
    celleditable_class_.init ().add_interface (gtype_implementer);
  }

  CellEditable::CppClassType CellEditable::celleditable_class_;

  auto
  CellEditable::get_type () -> GType
  {
    return celleditable_class_.init ().get_type ();
  }

  auto
  CellEditable::get_base_type () -> GType
  {
    return gtk_cell_editable_get_type ();
  }

#ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  CellEditable::start_editing (const glib::RefPtr<const gdk::Event>& event) -> void
  {
    gtk_cell_editable_start_editing (
        gobj (),
        const_cast<GdkEvent*> (glib::unwrap (event)));
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

#ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  CellEditable::editing_done () -> void
  {
    gtk_cell_editable_editing_done (gobj ());
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

#ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  CellEditable::remove_widget () -> void
  {
    gtk_cell_editable_remove_widget (gobj ());
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

  auto
  CellEditable::signal_editing_done () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this,
                                       &CellEditable_signal_editing_done_info);
  }
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

  auto
  CellEditable::signal_remove_widget () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this,
                                       &CellEditable_signal_remove_widget_info);
  }
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

  auto
  CellEditable::property_editing_canceled () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "editing-canceled");
  }
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

  auto
  CellEditable::property_editing_canceled () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "editing-canceled");
  }
#endif

  auto
  gtk::CellEditable::on_editing_done () -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->editing_done)
      (*base->editing_done) (gobj ());
  }

  auto
  gtk::CellEditable::on_remove_widget () -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->remove_widget)
      (*base->remove_widget) (gobj ());
  }

  auto
  gtk::CellEditable::start_editing_vfunc (
      const glib::RefPtr<const gdk::Event>& event) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->start_editing)
    {
      (*base->start_editing) (gobj (),
                              const_cast<GdkEvent*> (glib::unwrap (event)));
    }
  }

} // namespace gtk
