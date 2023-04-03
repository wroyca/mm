// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/printoperationpreview.hxx>
#include <libmm/gtk/printoperationpreview_p.hxx>

#include <gtk/gtk.h>

namespace
{

  static auto
  PrintOperationPreview_signal_ready_callback (GtkPrintOperationPreview* self,
                                               GtkPrintContext* p0,
                                               void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (const Glib::RefPtr<PrintContext>&)>;

    auto obj = dynamic_cast<PrintOperationPreview*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo PrintOperationPreview_signal_ready_info = {
      "ready",
      (GCallback) &PrintOperationPreview_signal_ready_callback,
      (GCallback) &PrintOperationPreview_signal_ready_callback};

  static auto
  PrintOperationPreview_signal_got_page_size_callback (
      GtkPrintOperationPreview* self,
      GtkPrintContext* p0,
      GtkPageSetup* p1,
      void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (const Glib::RefPtr<PrintContext>&,
                                      const Glib::RefPtr<PageSetup>&)>;

    auto obj = dynamic_cast<PrintOperationPreview*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true),
                                            Glib::wrap (p1, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo
      PrintOperationPreview_signal_got_page_size_info = {
          "got_page_size",
          (GCallback) &PrintOperationPreview_signal_got_page_size_callback,
          (GCallback) &PrintOperationPreview_signal_got_page_size_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkPrintOperationPreview* object, bool take_copy) -> Glib::RefPtr<Gtk::PrintOperationPreview>
  {
    return Glib::make_refptr_for_instance<Gtk::PrintOperationPreview> (
        dynamic_cast<Gtk::PrintOperationPreview*> (
            Glib::wrap_auto_interface<Gtk::PrintOperationPreview> (
                (GObject*) (object),
                take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  PrintOperationPreview_Class::init () -> const Glib::Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &PrintOperationPreview_Class::iface_init_function;

      gtype_ = gtk_print_operation_preview_get_type ();
    }

    return *this;
  }

  auto
  PrintOperationPreview_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->render_page = &render_page_vfunc_callback;
    klass->end_preview = &end_preview_vfunc_callback;
    klass->is_selected = &is_selected_vfunc_callback;

    klass->ready = &ready_callback;
    klass->got_page_size = &got_page_size_callback;
  }

  auto
  PrintOperationPreview_Class::render_page_vfunc_callback (
      GtkPrintOperationPreview* self,
      gint page_nr) -> void
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
          obj->render_page_vfunc (page_nr);
          return;
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

    if (base && base->render_page)
      (*base->render_page) (self, page_nr);
  }

  auto
  PrintOperationPreview_Class::end_preview_vfunc_callback (
      GtkPrintOperationPreview* self) -> void
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
          obj->end_preview_vfunc ();
          return;
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

    if (base && base->end_preview)
      (*base->end_preview) (self);
  }

  auto
  PrintOperationPreview_Class::is_selected_vfunc_callback (
      GtkPrintOperationPreview* self,
      gint page_nr) -> gboolean
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
          return static_cast<int> (obj->is_selected_vfunc (page_nr));
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

    if (base && base->is_selected)
      return (*base->is_selected) (self, page_nr);

    using RType = gboolean;
    return RType ();
  }

  auto
  PrintOperationPreview_Class::ready_callback (GtkPrintOperationPreview* self,
                                               GtkPrintContext* p0) -> void
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
          obj->on_ready (Glib::wrap (p0, true));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->ready)
      (*base->ready) (self, p0);
  }

  auto
  PrintOperationPreview_Class::got_page_size_callback (
      GtkPrintOperationPreview* self,
      GtkPrintContext* p0,
      GtkPageSetup* p1) -> void
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
          obj->on_got_page_size (Glib::wrap (p0, true), Glib::wrap (p1, true));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->got_page_size)
      (*base->got_page_size) (self, p0, p1);
  }

  auto
  PrintOperationPreview_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new PrintOperationPreview ((GtkPrintOperationPreview*) (object));
  }

  PrintOperationPreview::PrintOperationPreview ()
    : Glib::Interface (printoperationpreview_class_.init ())
  {
  }

  PrintOperationPreview::PrintOperationPreview (
      GtkPrintOperationPreview* castitem)
    : Glib::Interface ((GObject*) (castitem))
  {
  }

  PrintOperationPreview::PrintOperationPreview (
      const Glib::Interface_Class& interface_class)
    : Glib::Interface (interface_class)
  {
  }

  PrintOperationPreview::PrintOperationPreview (
      PrintOperationPreview&& src) noexcept
    : Glib::Interface (std::move (src))
  {
  }

  auto
  PrintOperationPreview::operator= (PrintOperationPreview&& src) noexcept -> PrintOperationPreview&
  {
    Glib::Interface::operator= (std::move (src));
    return *this;
  }

  PrintOperationPreview::~PrintOperationPreview () noexcept {}

  auto
  PrintOperationPreview::add_interface (GType gtype_implementer) -> void
  {
    printoperationpreview_class_.init ().add_interface (gtype_implementer);
  }

  PrintOperationPreview::CppClassType
      PrintOperationPreview::printoperationpreview_class_;

  auto
  PrintOperationPreview::get_type () -> GType
  {
    return printoperationpreview_class_.init ().get_type ();
  }

  auto
  PrintOperationPreview::get_base_type () -> GType
  {
    return gtk_print_operation_preview_get_type ();
  }

  auto
  PrintOperationPreview::render_page (int page_nr) -> void
  {
    gtk_print_operation_preview_render_page (gobj (), page_nr);
  }

  auto
  PrintOperationPreview::end_preview () -> void
  {
    gtk_print_operation_preview_end_preview (gobj ());
  }

  auto
  PrintOperationPreview::is_selected (int page_nr) const -> bool
  {
    return gtk_print_operation_preview_is_selected (
        const_cast<GtkPrintOperationPreview*> (gobj ()),
        page_nr);
  }

  auto
  PrintOperationPreview::signal_ready () -> Glib::SignalProxy<void (const Glib::RefPtr<PrintContext>&)>
  {
    return Glib::SignalProxy<void (const Glib::RefPtr<PrintContext>&)> (
        this,
        &PrintOperationPreview_signal_ready_info);
  }

  auto
  PrintOperationPreview::signal_got_page_size () -> Glib::SignalProxy<void (const Glib::RefPtr<PrintContext>&,
                                 const Glib::RefPtr<PageSetup>&)>
  {
    return Glib::SignalProxy<void (const Glib::RefPtr<PrintContext>&,
                                   const Glib::RefPtr<PageSetup>&)> (
        this,
        &PrintOperationPreview_signal_got_page_size_info);
  }

  auto
  Gtk::PrintOperationPreview::on_ready (
      const Glib::RefPtr<PrintContext>& context) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->ready)
      (*base->ready) (gobj (), Glib::unwrap (context));
  }

  auto
  Gtk::PrintOperationPreview::on_got_page_size (
      const Glib::RefPtr<PrintContext>& context,
      const Glib::RefPtr<PageSetup>& page_setup) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->got_page_size)
      (*base->got_page_size) (gobj (),
                              Glib::unwrap (context),
                              Glib::unwrap (page_setup));
  }

  auto
  Gtk::PrintOperationPreview::render_page_vfunc (int page_nr) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->render_page)
    {
      (*base->render_page) (gobj (), page_nr);
    }
  }

  auto
  Gtk::PrintOperationPreview::end_preview_vfunc () -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->end_preview)
    {
      (*base->end_preview) (gobj ());
    }
  }

  auto
  Gtk::PrintOperationPreview::is_selected_vfunc (int page_nr) const -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->is_selected)
    {
      bool retval (
          (*base->is_selected) (const_cast<GtkPrintOperationPreview*> (gobj ()),
                                page_nr));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

} // namespace Gtk
