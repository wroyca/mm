// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#include <libmm/gtk/mm-gtkconfig.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/cellrenderer.hxx>
  #include <libmm/gtk/cellrenderer_p.hxx>

  #include <gtk/gtk.h>
  #include <libmm/gtk/snapshot.hxx>

namespace Gtk
{

  auto
  CellRenderer::get_aligned_area (Widget& widget,
                                  CellRendererState flags,
                                  const Gdk::Rectangle& cell_area) const -> Gdk::Rectangle
  {
    GdkRectangle gdk_aligned_area;
    gtk_cell_renderer_get_aligned_area (
        const_cast<GtkCellRenderer*> (gobj ()),
        widget.gobj (),
        static_cast<GtkCellRendererState> (flags),
        cell_area.gobj (),
        &gdk_aligned_area);

    return Glib::wrap (&gdk_aligned_area);
  }

  auto
  CellRenderer::_property_renderable () -> Glib::PropertyProxy_Base
  {
    g_assert_not_reached ();
    return Glib::PropertyProxy<int> (nullptr, nullptr);
  }

  auto
  CellRenderer_Class::get_preferred_width_vfunc_callback (GtkCellRenderer* self,
                                                          GtkWidget* widget,
                                                          int* minimum_width,
                                                          int* natural_width) -> void
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
          int min_width = 0;
          int nat_width = 0;
          obj->get_preferred_width_vfunc (
              *Glib::wrap (widget),
              (minimum_width ? *minimum_width : min_width),
              (natural_width ? *natural_width : nat_width));
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

    if (base && base->get_preferred_width)
      (*base->get_preferred_width) (self, widget, minimum_width, natural_width);
  }

  auto
  CellRenderer_Class::get_preferred_height_for_width_vfunc_callback (
      GtkCellRenderer* self,
      GtkWidget* widget,
      int width,
      int* minimum_height,
      int* natural_height) -> void
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
          int min_height = 0;
          int nat_height = 0;
          obj->get_preferred_height_for_width_vfunc (
              *Glib::wrap (widget),
              width,
              (minimum_height ? *minimum_height : min_height),
              (natural_height ? *natural_height : nat_height));
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

    if (base && base->get_preferred_height_for_width)
      (*base->get_preferred_height_for_width) (self,
                                               widget,
                                               width,
                                               minimum_height,
                                               natural_height);
  }

  auto
  CellRenderer_Class::get_preferred_height_vfunc_callback (
      GtkCellRenderer* self,
      GtkWidget* widget,
      int* minimum_height,
      int* natural_height) -> void
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
          int min_height = 0;
          int nat_height = 0;
          obj->get_preferred_height_vfunc (
              *Glib::wrap (widget),
              (minimum_height ? *minimum_height : min_height),
              (natural_height ? *natural_height : nat_height));
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

    if (base && base->get_preferred_height)
      (*base->get_preferred_height) (self,
                                     widget,
                                     minimum_height,
                                     natural_height);
  }

  auto
  CellRenderer_Class::get_preferred_width_for_height_vfunc_callback (
      GtkCellRenderer* self,
      GtkWidget* widget,
      int height,
      int* minimum_width,
      int* natural_width) -> void
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
          int min_width = 0;
          int nat_width = 0;
          obj->get_preferred_width_for_height_vfunc (
              *Glib::wrap (widget),
              height,
              (minimum_width ? *minimum_width : min_width),
              (natural_width ? *natural_width : nat_width));
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

    if (base && base->get_preferred_width_for_height)
      (*base->get_preferred_width_for_height) (self,
                                               widget,
                                               height,
                                               minimum_width,
                                               natural_width);
  }

} // namespace Gtk

namespace
{

  static const Glib::SignalProxyInfo CellRenderer_signal_editing_canceled_info =
      {"editing_canceled",
       (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
       (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  static auto
  CellRenderer_signal_editing_started_callback (GtkCellRenderer* self,
                                                GtkCellEditable* p0,
                                                const gchar* p1,
                                                void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (CellEditable*, const Glib::ustring&)>;

    auto obj = dynamic_cast<CellRenderer*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              dynamic_cast<CellEditable*> (
                  Glib::wrap_auto ((GObject*) (p0), false)),
              Glib::convert_const_gchar_ptr_to_ustring (p1));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo CellRenderer_signal_editing_started_info =
      {"editing_started",
       (GCallback) &CellRenderer_signal_editing_started_callback,
       (GCallback) &CellRenderer_signal_editing_started_callback};

} // namespace

auto
Glib::Value<Gtk::CellRendererState>::value_type () -> GType
{
  return gtk_cell_renderer_state_get_type ();
}

auto
Glib::Value<Gtk::CellRendererMode>::value_type () -> GType
{
  return gtk_cell_renderer_mode_get_type ();
}

namespace Glib
{

  auto
  wrap (GtkCellRenderer* object, bool take_copy) -> Gtk::CellRenderer*
  {
    return dynamic_cast<Gtk::CellRenderer*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  CellRenderer_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &CellRenderer_Class::class_init_function;

      register_derived_type (gtk_cell_renderer_get_type ());
    }

    return *this;
  }

  auto
  CellRenderer_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->get_request_mode = &get_request_mode_vfunc_callback;
    klass->get_preferred_width = &get_preferred_width_vfunc_callback;
    klass->get_preferred_height_for_width =
        &get_preferred_height_for_width_vfunc_callback;
    klass->get_preferred_height = &get_preferred_height_vfunc_callback;
    klass->get_preferred_width_for_height =
        &get_preferred_width_for_height_vfunc_callback;
    klass->snapshot = &snapshot_vfunc_callback;
    klass->activate = &activate_vfunc_callback;
    klass->start_editing = &start_editing_vfunc_callback;

    klass->editing_canceled = &editing_canceled_callback;
    klass->editing_started = &editing_started_callback;
  }

  auto
  CellRenderer_Class::get_request_mode_vfunc_callback (GtkCellRenderer* self) -> GtkSizeRequestMode
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
          return static_cast<GtkSizeRequestMode> (
              obj->get_request_mode_vfunc ());
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->get_request_mode)
      return (*base->get_request_mode) (self);

    using RType = GtkSizeRequestMode;
    return RType ();
  }

  auto
  CellRenderer_Class::snapshot_vfunc_callback (
      GtkCellRenderer* self,
      GtkSnapshot* snapshot,
      GtkWidget* widget,
      const GdkRectangle* background_area,
      const GdkRectangle* cell_area,
      GtkCellRendererState flags) -> void
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
          obj->snapshot_vfunc (Glib::wrap_gtk_snapshot (snapshot, true),
                               *Glib::wrap (widget),
                               Glib::wrap (background_area),
                               Glib::wrap (cell_area),
                               static_cast<CellRendererState> (flags));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->snapshot)
      (*base->snapshot) (self,
                         snapshot,
                         widget,
                         background_area,
                         cell_area,
                         flags);
  }

  auto
  CellRenderer_Class::activate_vfunc_callback (
      GtkCellRenderer* self,
      GdkEvent* event,
      GtkWidget* widget,
      const gchar* path,
      const GdkRectangle* background_area,
      const GdkRectangle* cell_area,
      GtkCellRendererState flags) -> gboolean
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
          return static_cast<int> (obj->activate_vfunc (
              Glib::wrap (event, true),
              *Glib::wrap (widget),
              Glib::convert_const_gchar_ptr_to_ustring (path),
              Glib::wrap (background_area),
              Glib::wrap (cell_area),
              static_cast<CellRendererState> (flags)));
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->activate)
      return (*base->activate) (self,
                                event,
                                widget,
                                path,
                                background_area,
                                cell_area,
                                flags);

    using RType = gboolean;
    return RType ();
  }

  auto
  CellRenderer_Class::start_editing_vfunc_callback (
      GtkCellRenderer* self,
      GdkEvent* event,
      GtkWidget* widget,
      const gchar* path,
      const GdkRectangle* background_area,
      const GdkRectangle* cell_area,
      GtkCellRendererState flags) -> GtkCellEditable*
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
          return Glib::unwrap (obj->start_editing_vfunc (
              Glib::wrap (event, true),
              *Glib::wrap (widget),
              Glib::convert_const_gchar_ptr_to_ustring (path),
              Glib::wrap (background_area),
              Glib::wrap (cell_area),
              static_cast<CellRendererState> (flags)));
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->start_editing)
      return (*base->start_editing) (self,
                                     event,
                                     widget,
                                     path,
                                     background_area,
                                     cell_area,
                                     flags);

    using RType = GtkCellEditable*;
    return RType ();
  }

  auto
  CellRenderer_Class::editing_canceled_callback (GtkCellRenderer* self) -> void
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
          obj->on_editing_canceled ();
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

    if (base && base->editing_canceled)
      (*base->editing_canceled) (self);
  }

  auto
  CellRenderer_Class::editing_started_callback (GtkCellRenderer* self,
                                                GtkCellEditable* p0,
                                                const gchar* p1) -> void
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
          obj->on_editing_started (
              dynamic_cast<CellEditable*> (
                  Glib::wrap_auto ((GObject*) (p0), false)),
              Glib::convert_const_gchar_ptr_to_ustring (p1));
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

    if (base && base->editing_started)
      (*base->editing_started) (self, p0, p1);
  }

  auto
  CellRenderer_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new CellRenderer ((GtkCellRenderer*) (o)));
  }

  CellRenderer::CellRenderer (const Glib::ConstructParams& construct_params)
    : Gtk::Object (construct_params)
  {
  }

  CellRenderer::CellRenderer (GtkCellRenderer* castitem)
    : Gtk::Object ((GObject*) (castitem))
  {
  }

  CellRenderer::CellRenderer (CellRenderer&& src) noexcept
    : Gtk::Object (std::move (src))
  {
  }

  auto
  CellRenderer::operator= (CellRenderer&& src) noexcept -> CellRenderer&
  {
    Gtk::Object::operator= (std::move (src));
    return *this;
  }

  CellRenderer::~CellRenderer () noexcept
  {
    destroy_ ();
  }

  CellRenderer::CppClassType CellRenderer::cellrenderer_class_;

  auto
  CellRenderer::get_type () -> GType
  {
    return cellrenderer_class_.init ().get_type ();
  }

  auto
  CellRenderer::get_base_type () -> GType
  {
    return gtk_cell_renderer_get_type ();
  }

  auto
  CellRenderer::get_request_mode () const -> SizeRequestMode
  {
    return static_cast<SizeRequestMode> (gtk_cell_renderer_get_request_mode (
        const_cast<GtkCellRenderer*> (gobj ())));
  }

  auto
  CellRenderer::get_preferred_width (Widget& widget,
                                     int& minimum_width,
                                     int& natural_width) const -> void
  {
    gtk_cell_renderer_get_preferred_width (
        const_cast<GtkCellRenderer*> (gobj ()),
        (widget).gobj (),
        &(minimum_width),
        &(natural_width));
  }

  auto
  CellRenderer::get_preferred_height_for_width (Widget& widget,
                                                int width,
                                                int& minimum_height,
                                                int& natural_height) const -> void
  {
    gtk_cell_renderer_get_preferred_height_for_width (
        const_cast<GtkCellRenderer*> (gobj ()),
        (widget).gobj (),
        width,
        &(minimum_height),
        &(natural_height));
  }

  auto
  CellRenderer::get_preferred_height (Widget& widget,
                                      int& minimum_height,
                                      int& natural_height) const -> void
  {
    gtk_cell_renderer_get_preferred_height (
        const_cast<GtkCellRenderer*> (gobj ()),
        (widget).gobj (),
        &(minimum_height),
        &(natural_height));
  }

  auto
  CellRenderer::get_preferred_width_for_height (Widget& widget,
                                                int height,
                                                int& minimum_width,
                                                int& natural_width) const -> void
  {
    gtk_cell_renderer_get_preferred_width_for_height (
        const_cast<GtkCellRenderer*> (gobj ()),
        (widget).gobj (),
        height,
        &(minimum_width),
        &(natural_width));
  }

  auto
  CellRenderer::get_preferred_size (Widget& widget,
                                    Requisition& minimum_size,
                                    Requisition& natural_size) const -> void
  {
    gtk_cell_renderer_get_preferred_size (
        const_cast<GtkCellRenderer*> (gobj ()),
        (widget).gobj (),
        (minimum_size).gobj (),
        (natural_size).gobj ());
  }

  auto
  CellRenderer::snapshot (const Glib::RefPtr<Gtk::Snapshot>& snapshot,
                          Widget& widget,
                          const Gdk::Rectangle& background_area,
                          const Gdk::Rectangle& cell_area,
                          CellRendererState flags) -> void
  {
    gtk_cell_renderer_snapshot (gobj (),
                                Glib::unwrap (snapshot),
                                (widget).gobj (),
                                (background_area).gobj (),
                                (cell_area).gobj (),
                                static_cast<GtkCellRendererState> (flags));
  }

  auto
  CellRenderer::activate (const Glib::RefPtr<const Gdk::Event>& event,
                          Widget& widget,
                          const Glib::ustring& path,
                          const Gdk::Rectangle& background_area,
                          const Gdk::Rectangle& cell_area,
                          CellRendererState flags) -> bool
  {
    return gtk_cell_renderer_activate (
        gobj (),
        const_cast<GdkEvent*> (Glib::unwrap (event)),
        (widget).gobj (),
        path.c_str (),
        (background_area).gobj (),
        (cell_area).gobj (),
        static_cast<GtkCellRendererState> (flags));
  }

  auto
  CellRenderer::start_editing (const Glib::RefPtr<const Gdk::Event>& event,
                               Widget& widget,
                               const Glib::ustring& path,
                               const Gdk::Rectangle& background_area,
                               const Gdk::Rectangle& cell_area,
                               CellRendererState flags) -> CellEditable*
  {
    return dynamic_cast<CellEditable*> (
        Glib::wrap_auto ((GObject*) (gtk_cell_renderer_start_editing (
                             gobj (),
                             const_cast<GdkEvent*> (Glib::unwrap (event)),
                             (widget).gobj (),
                             path.c_str (),
                             (background_area).gobj (),
                             (cell_area).gobj (),
                             static_cast<GtkCellRendererState> (flags))),
                         false));
  }

  auto
  CellRenderer::set_fixed_size (int width, int height) -> void
  {
    gtk_cell_renderer_set_fixed_size (gobj (), width, height);
  }

  auto
  CellRenderer::get_fixed_size (int& width, int& height) const -> void
  {
    gtk_cell_renderer_get_fixed_size (const_cast<GtkCellRenderer*> (gobj ()),
                                      &(width),
                                      &(height));
  }

  auto
  CellRenderer::set_alignment (float xalign, float yalign) -> void
  {
    gtk_cell_renderer_set_alignment (gobj (), xalign, yalign);
  }

  auto
  CellRenderer::get_alignment (float& xalign, float& yalign) const -> void
  {
    gtk_cell_renderer_get_alignment (const_cast<GtkCellRenderer*> (gobj ()),
                                     &(xalign),
                                     &(yalign));
  }

  auto
  CellRenderer::set_padding (int xpad, int ypad) -> void
  {
    gtk_cell_renderer_set_padding (gobj (), xpad, ypad);
  }

  auto
  CellRenderer::get_padding (int& xpad, int& ypad) const -> void
  {
    gtk_cell_renderer_get_padding (const_cast<GtkCellRenderer*> (gobj ()),
                                   &(xpad),
                                   &(ypad));
  }

  auto
  CellRenderer::set_visible (bool visible) -> void
  {
    gtk_cell_renderer_set_visible (gobj (), static_cast<int> (visible));
  }

  auto
  CellRenderer::get_visible () const -> bool
  {
    return gtk_cell_renderer_get_visible (
        const_cast<GtkCellRenderer*> (gobj ()));
  }

  auto
  CellRenderer::set_sensitive (bool sensitive) -> void
  {
    gtk_cell_renderer_set_sensitive (gobj (), static_cast<int> (sensitive));
  }

  auto
  CellRenderer::get_sensitive () const -> bool
  {
    return gtk_cell_renderer_get_sensitive (
        const_cast<GtkCellRenderer*> (gobj ()));
  }

  auto
  CellRenderer::is_activatable () const -> bool
  {
    return gtk_cell_renderer_is_activatable (
        const_cast<GtkCellRenderer*> (gobj ()));
  }

  auto
  CellRenderer::set_is_expander (bool is_expander) -> void
  {
    gtk_cell_renderer_set_is_expander (gobj (), static_cast<int> (is_expander));
  }

  auto
  CellRenderer::get_is_expander () const -> bool
  {
    return gtk_cell_renderer_get_is_expander (
        const_cast<GtkCellRenderer*> (gobj ()));
  }

  auto
  CellRenderer::set_is_expanded (bool is_expanded) -> void
  {
    gtk_cell_renderer_set_is_expanded (gobj (), static_cast<int> (is_expanded));
  }

  auto
  CellRenderer::get_is_expanded () const -> bool
  {
    return gtk_cell_renderer_get_is_expanded (
        const_cast<GtkCellRenderer*> (gobj ()));
  }

  auto
  CellRenderer::stop_editing (bool canceled) -> void
  {
    gtk_cell_renderer_stop_editing (gobj (), static_cast<int> (canceled));
  }

  auto
  CellRenderer::get_state (Widget& widget, CellRendererState cell_state) const -> StateFlags
  {
    return static_cast<StateFlags> (gtk_cell_renderer_get_state (
        const_cast<GtkCellRenderer*> (gobj ()),
        (widget).gobj (),
        static_cast<GtkCellRendererState> (cell_state)));
  }

  auto
  CellRenderer::get_state (CellRendererState cell_state) const -> StateFlags
  {
    return static_cast<StateFlags> (gtk_cell_renderer_get_state (
        const_cast<GtkCellRenderer*> (gobj ()),
        nullptr,
        static_cast<GtkCellRendererState> (cell_state)));
  }

  CellRenderer::CellRenderer ()
    : Glib::ObjectBase (nullptr),
      Gtk::Object (Glib::ConstructParams (cellrenderer_class_.init ()))
  {
  }

  auto
  CellRenderer::signal_editing_canceled () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (
        this,
        &CellRenderer_signal_editing_canceled_info);
  }

  auto
  CellRenderer::signal_editing_started () -> Glib::SignalProxy<void (CellEditable*, const Glib::ustring&)>
  {
    return Glib::SignalProxy<void (CellEditable*, const Glib::ustring&)> (
        this,
        &CellRenderer_signal_editing_started_info);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<CellRendererMode>::value,
      "Type CellRendererMode cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  CellRenderer::property_mode () -> Glib::PropertyProxy<CellRendererMode>
  {
    return Glib::PropertyProxy<CellRendererMode> (this, "mode");
  }

  auto
  CellRenderer::property_mode () const -> Glib::PropertyProxy_ReadOnly<CellRendererMode>
  {
    return Glib::PropertyProxy_ReadOnly<CellRendererMode> (this, "mode");
  }

  auto
  CellRenderer::property_visible () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "visible");
  }

  auto
  CellRenderer::property_visible () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "visible");
  }

  auto
  CellRenderer::property_sensitive () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "sensitive");
  }

  auto
  CellRenderer::property_sensitive () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "sensitive");
  }

  auto
  CellRenderer::property_xalign () -> Glib::PropertyProxy<float>
  {
    return Glib::PropertyProxy<float> (this, "xalign");
  }

  auto
  CellRenderer::property_xalign () const -> Glib::PropertyProxy_ReadOnly<float>
  {
    return Glib::PropertyProxy_ReadOnly<float> (this, "xalign");
  }

  auto
  CellRenderer::property_yalign () -> Glib::PropertyProxy<float>
  {
    return Glib::PropertyProxy<float> (this, "yalign");
  }

  auto
  CellRenderer::property_yalign () const -> Glib::PropertyProxy_ReadOnly<float>
  {
    return Glib::PropertyProxy_ReadOnly<float> (this, "yalign");
  }

  auto
  CellRenderer::property_xpad () -> Glib::PropertyProxy<unsigned int>
  {
    return Glib::PropertyProxy<unsigned int> (this, "xpad");
  }

  auto
  CellRenderer::property_xpad () const -> Glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return Glib::PropertyProxy_ReadOnly<unsigned int> (this, "xpad");
  }

  auto
  CellRenderer::property_ypad () -> Glib::PropertyProxy<unsigned int>
  {
    return Glib::PropertyProxy<unsigned int> (this, "ypad");
  }

  auto
  CellRenderer::property_ypad () const -> Glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return Glib::PropertyProxy_ReadOnly<unsigned int> (this, "ypad");
  }

  auto
  CellRenderer::property_width () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "width");
  }

  auto
  CellRenderer::property_width () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "width");
  }

  auto
  CellRenderer::property_height () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "height");
  }

  auto
  CellRenderer::property_height () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "height");
  }

  auto
  CellRenderer::property_is_expander () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "is-expander");
  }

  auto
  CellRenderer::property_is_expander () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "is-expander");
  }

  auto
  CellRenderer::property_is_expanded () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "is-expanded");
  }

  auto
  CellRenderer::property_is_expanded () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "is-expanded");
  }

  auto
  CellRenderer::property_cell_background () -> Glib::PropertyProxy_WriteOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_WriteOnly<Glib::ustring> (this,
                                                         "cell-background");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Gdk::RGBA>::value,
      "Type Gdk::RGBA cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  CellRenderer::property_cell_background_rgba () -> Glib::PropertyProxy<Gdk::RGBA>
  {
    return Glib::PropertyProxy<Gdk::RGBA> (this, "cell-background-rgba");
  }

  auto
  CellRenderer::property_cell_background_rgba () const -> Glib::PropertyProxy_ReadOnly<Gdk::RGBA>
  {
    return Glib::PropertyProxy_ReadOnly<Gdk::RGBA> (this,
                                                    "cell-background-rgba");
  }

  auto
  CellRenderer::property_cell_background_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "cell-background-set");
  }

  auto
  CellRenderer::property_cell_background_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "cell-background-set");
  }

  auto
  CellRenderer::property_editing () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "editing");
  }

  auto
  Gtk::CellRenderer::on_editing_canceled () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->editing_canceled)
      (*base->editing_canceled) (gobj ());
  }

  auto
  Gtk::CellRenderer::on_editing_started (CellEditable* editable,
                                         const Glib::ustring& path) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->editing_started)
      (*base->editing_started) (gobj (),
                                Glib::unwrap (editable),
                                path.c_str ());
  }

  auto
  Gtk::CellRenderer::get_request_mode_vfunc () const -> SizeRequestMode
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->get_request_mode)
    {
      SizeRequestMode retval (static_cast<SizeRequestMode> (
          (*base->get_request_mode) (const_cast<GtkCellRenderer*> (gobj ()))));
      return retval;
    }

    using RType = SizeRequestMode;
    return RType ();
  }

  auto
  Gtk::CellRenderer::get_preferred_width_vfunc (Widget& widget,
                                                int& minimum_width,
                                                int& natural_width) const -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->get_preferred_width)
    {
      (*base->get_preferred_width) (const_cast<GtkCellRenderer*> (gobj ()),
                                    (widget).gobj (),
                                    &(minimum_width),
                                    &(natural_width));
    }
  }

  auto
  Gtk::CellRenderer::get_preferred_height_for_width_vfunc (
      Widget& widget,
      int width,
      int& minimum_height,
      int& natural_height) const -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->get_preferred_height_for_width)
    {
      (*base->get_preferred_height_for_width) (
          const_cast<GtkCellRenderer*> (gobj ()),
          (widget).gobj (),
          width,
          &(minimum_height),
          &(natural_height));
    }
  }

  auto
  Gtk::CellRenderer::get_preferred_height_vfunc (Widget& widget,
                                                 int& minimum_height,
                                                 int& natural_height) const -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->get_preferred_height)
    {
      (*base->get_preferred_height) (const_cast<GtkCellRenderer*> (gobj ()),
                                     (widget).gobj (),
                                     &(minimum_height),
                                     &(natural_height));
    }
  }

  auto
  Gtk::CellRenderer::get_preferred_width_for_height_vfunc (
      Widget& widget,
      int height,
      int& minimum_width,
      int& natural_width) const -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->get_preferred_width_for_height)
    {
      (*base->get_preferred_width_for_height) (
          const_cast<GtkCellRenderer*> (gobj ()),
          (widget).gobj (),
          height,
          &(minimum_width),
          &(natural_width));
    }
  }

  auto
  Gtk::CellRenderer::snapshot_vfunc (
      const Glib::RefPtr<Gtk::Snapshot>& snapshot,
      Widget& widget,
      const Gdk::Rectangle& background_area,
      const Gdk::Rectangle& cell_area,
      CellRendererState flags) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->snapshot)
    {
      (*base->snapshot) (gobj (),
                         Glib::unwrap (snapshot),
                         (widget).gobj (),
                         (background_area).gobj (),
                         (cell_area).gobj (),
                         static_cast<GtkCellRendererState> (flags));
    }
  }

  auto
  Gtk::CellRenderer::activate_vfunc (
      const Glib::RefPtr<const Gdk::Event>& event,
      Widget& widget,
      const Glib::ustring& path,
      const Gdk::Rectangle& background_area,
      const Gdk::Rectangle& cell_area,
      CellRendererState flags) -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->activate)
    {
      bool retval (
          (*base->activate) (gobj (),
                             const_cast<GdkEvent*> (Glib::unwrap (event)),
                             (widget).gobj (),
                             path.c_str (),
                             (background_area).gobj (),
                             (cell_area).gobj (),
                             static_cast<GtkCellRendererState> (flags)));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  Gtk::CellRenderer::start_editing_vfunc (
      const Glib::RefPtr<const Gdk::Event>& event,
      Widget& widget,
      const Glib::ustring& path,
      const Gdk::Rectangle& background_area,
      const Gdk::Rectangle& cell_area,
      CellRendererState flags) -> CellEditable*
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->start_editing)
    {
      CellEditable* retval (dynamic_cast<CellEditable*> (
          Glib::wrap_auto ((GObject*) ((*base->start_editing) (
                               gobj (),
                               const_cast<GdkEvent*> (Glib::unwrap (event)),
                               (widget).gobj (),
                               path.c_str (),
                               (background_area).gobj (),
                               (cell_area).gobj (),
                               static_cast<GtkCellRendererState> (flags))),
                           false)));
      return retval;
    }

    using RType = CellEditable*;
    return RType ();
  }

} // namespace Gtk

#endif
