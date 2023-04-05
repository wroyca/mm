// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/cellarea.hxx>
  #include <libmm/gtk/cellarea_p.hxx>

  #include <gtk/gtk.h>
  #include <libmm/gtk/snapshot.hxx>

namespace
{

  static auto
  proxy_foreach_callback (GtkCellRenderer* cell, void* data) -> gboolean
  {
    typedef gtk::CellArea::SlotForeach SlotType;
    auto& slot = *static_cast<SlotType*> (data);

    try
    {
      return slot (glib::wrap (cell));
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
    }

    return FALSE;
  }

  static auto
  proxy_foreach_alloc_callback (GtkCellRenderer* cell,
                                const GdkRectangle* cell_area,
                                const GdkRectangle* cell_background,
                                void* data) -> gboolean
  {
    typedef gtk::CellArea::SlotForeachAlloc SlotType;
    auto& slot = *static_cast<SlotType*> (data);

    try
    {
      return slot (glib::wrap (cell),
                   glib::wrap (cell_area),
                   glib::wrap (cell_background));
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
    }

    return FALSE;
  }

} // namespace

namespace gtk
{

  auto
  CellArea::foreach (const SlotForeach& slot) -> void
  {
    SlotForeach slot_copy (slot);
    gtk_cell_area_foreach (const_cast<GtkCellArea*> (gobj ()),
                           &proxy_foreach_callback,
                           &slot_copy);
  }

  auto
  CellArea::foreach (const glib::RefPtr<CellAreaContext>& context,
                     Widget * widget,
                     const gdk::Rectangle& cell_area,
                     const gdk::Rectangle& background_area,
                     const SlotForeachAlloc& slot) -> void
  {
    SlotForeachAlloc slot_copy (slot);
    gtk_cell_area_foreach_alloc (const_cast<GtkCellArea*> (gobj ()),
                                 glib::unwrap (context),
                                 glib::unwrap (widget),
                                 cell_area.gobj (),
                                 background_area.gobj (),
                                 &proxy_foreach_alloc_callback,
                                 &slot_copy);
  }

  auto
  CellArea_Class::get_preferred_width_vfunc_callback (
      GtkCellArea* self,
      GtkCellAreaContext* context,
      GtkWidget* widget,
      int* minimum_width,
      int* natural_width) -> void
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
          int min_width = 0;
          int nat_width = 0;
          obj->get_preferred_width_vfunc (
              glib::wrap (context, true),
              *glib::wrap (widget),
              (minimum_width ? *minimum_width : min_width),
              (natural_width ? *natural_width : nat_width));
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

    if (base && base->get_preferred_width)
      (*base->get_preferred_width) (self,
                                    context,
                                    widget,
                                    minimum_width,
                                    natural_width);
  }

  auto
  CellArea_Class::get_preferred_height_for_width_vfunc_callback (
      GtkCellArea* self,
      GtkCellAreaContext* context,
      GtkWidget* widget,
      int width,
      int* minimum_height,
      int* natural_height) -> void
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
          int min_height = 0;
          int nat_height = 0;
          obj->get_preferred_height_for_width_vfunc (
              glib::wrap (context, true),
              *glib::wrap (widget),
              width,
              (minimum_height ? *minimum_height : min_height),
              (natural_height ? *natural_height : nat_height));
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

    if (base && base->get_preferred_height_for_width)
      (*base->get_preferred_height_for_width) (self,
                                               context,
                                               widget,
                                               width,
                                               minimum_height,
                                               natural_height);
  }

  auto
  CellArea_Class::get_preferred_height_vfunc_callback (
      GtkCellArea* self,
      GtkCellAreaContext* context,
      GtkWidget* widget,
      int* minimum_height,
      int* natural_height) -> void
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
          int min_height = 0;
          int nat_height = 0;
          obj->get_preferred_height_vfunc (
              glib::wrap (context, true),
              *glib::wrap (widget),
              (minimum_height ? *minimum_height : min_height),
              (natural_height ? *natural_height : nat_height));
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

    if (base && base->get_preferred_height)
      (*base->get_preferred_height) (self,
                                     context,
                                     widget,
                                     minimum_height,
                                     natural_height);
  }

  auto
  CellArea_Class::get_preferred_width_for_height_vfunc_callback (
      GtkCellArea* self,
      GtkCellAreaContext* context,
      GtkWidget* widget,
      int height,
      int* minimum_width,
      int* natural_width) -> void
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
          int min_width = 0;
          int nat_width = 0;
          obj->get_preferred_width_for_height_vfunc (
              glib::wrap (context, true),
              *glib::wrap (widget),
              height,
              (minimum_width ? *minimum_width : min_width),
              (natural_width ? *natural_width : nat_width));
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

    if (base && base->get_preferred_width_for_height)
      (*base->get_preferred_width_for_height) (self,
                                               context,
                                               widget,
                                               height,
                                               minimum_width,
                                               natural_width);
  }

} // namespace gtk

namespace
{

  static auto
  CellArea_signal_apply_attributes_callback (GtkCellArea* self,
                                             GtkTreeModel* p0,
                                             GtkTreeIter* p1,
                                             gboolean p2,
                                             gboolean p3,
                                             void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const glib::RefPtr<TreeModel>&,
                                      const TreeModel::iterator&,
                                      bool,
                                      bool)>;

    auto obj = dynamic_cast<CellArea*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true),
                                            gtk::TreeModel::iterator (p0, p1),
                                            p2,
                                            p3);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo CellArea_signal_apply_attributes_info = {
      "apply-attributes",
      (GCallback) &CellArea_signal_apply_attributes_callback,
      (GCallback) &CellArea_signal_apply_attributes_callback};

  static auto
  CellArea_signal_add_editable_callback (GtkCellArea* self,
                                         GtkCellRenderer* p0,
                                         GtkCellEditable* p1,
                                         GdkRectangle* p2,
                                         const gchar* p3,
                                         void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (CellRenderer*,
                                      CellEditable*,
                                      const gdk::Rectangle&,
                                      const glib::ustring&)>;

    auto obj = dynamic_cast<CellArea*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::wrap (p0),
              dynamic_cast<CellEditable*> (
                  glib::wrap_auto ((GObject*) (p1), false)),
              glib::wrap (p2),
              glib::convert_const_gchar_ptr_to_ustring (p3));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo CellArea_signal_add_editable_info = {
      "add-editable",
      (GCallback) &CellArea_signal_add_editable_callback,
      (GCallback) &CellArea_signal_add_editable_callback};

  static auto
  CellArea_signal_remove_editable_callback (GtkCellArea* self,
                                            GtkCellRenderer* p0,
                                            GtkCellEditable* p1,
                                            void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (CellRenderer*, CellEditable*)>;

    auto obj = dynamic_cast<CellArea*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::wrap (p0),
              dynamic_cast<CellEditable*> (
                  glib::wrap_auto ((GObject*) (p1), false)));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo CellArea_signal_remove_editable_info = {
      "remove-editable",
      (GCallback) &CellArea_signal_remove_editable_callback,
      (GCallback) &CellArea_signal_remove_editable_callback};

  static auto
  CellArea_signal_focus_changed_callback (GtkCellArea* self,
                                          GtkCellRenderer* p0,
                                          const gchar* p1,
                                          void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (CellRenderer*, const glib::ustring&)>;

    auto obj = dynamic_cast<CellArea*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::wrap (p0),
              glib::convert_const_gchar_ptr_to_ustring (p1));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo CellArea_signal_focus_changed_info = {
      "focus-changed",
      (GCallback) &CellArea_signal_focus_changed_callback,
      (GCallback) &CellArea_signal_focus_changed_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkCellArea* object, bool take_copy) -> glib::RefPtr<gtk::CellArea>
  {
    return glib::make_refptr_for_instance<gtk::CellArea> (
        dynamic_cast<gtk::CellArea*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  CellArea_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &CellArea_Class::class_init_function;

      register_derived_type (gtk_cell_area_get_type ());

      Buildable::add_interface (get_type ());
      CellLayout::add_interface (get_type ());
    }

    return *this;
  }

  auto
  CellArea_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->snapshot = &snapshot_vfunc_callback;
    klass->get_request_mode = &get_request_mode_vfunc_callback;
    klass->get_preferred_width = &get_preferred_width_vfunc_callback;
    klass->get_preferred_height_for_width =
        &get_preferred_height_for_width_vfunc_callback;
    klass->get_preferred_height = &get_preferred_height_vfunc_callback;
    klass->get_preferred_width_for_height =
        &get_preferred_width_for_height_vfunc_callback;

    klass->apply_attributes = &apply_attributes_callback;
  }

  auto
  CellArea_Class::snapshot_vfunc_callback (GtkCellArea* self,
                                           GtkCellAreaContext* context,
                                           GtkWidget* widget,
                                           GtkSnapshot* snapshot,
                                           const GdkRectangle* background_area,
                                           const GdkRectangle* cell_area,
                                           GtkCellRendererState flags,
                                           gboolean paint_focus) -> void
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
          obj->snapshot_vfunc (glib::wrap (context, true),
                               *glib::wrap (widget),
                               glib::wrap_gtk_snapshot (snapshot, true),
                               glib::wrap (background_area),
                               glib::wrap (cell_area),
                               static_cast<CellRendererState> (flags),
                               paint_focus);
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->snapshot)
      (*base->snapshot) (self,
                         context,
                         widget,
                         snapshot,
                         background_area,
                         cell_area,
                         flags,
                         paint_focus);
  }

  auto
  CellArea_Class::get_request_mode_vfunc_callback (GtkCellArea* self) -> GtkSizeRequestMode
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
          return static_cast<GtkSizeRequestMode> (
              obj->get_request_mode_vfunc ());
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
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
  CellArea_Class::apply_attributes_callback (GtkCellArea* self,
                                             GtkTreeModel* p0,
                                             GtkTreeIter* p1,
                                             gboolean p2,
                                             gboolean p3) -> void
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
          obj->on_apply_attributes (glib::wrap (p0, true),
                                    gtk::TreeModel::iterator (p0, p1),
                                    p2,
                                    p3);
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

    if (base && base->apply_attributes)
      (*base->apply_attributes) (self, p0, p1, p2, p3);
  }

  auto
  CellArea_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new CellArea ((GtkCellArea*) object);
  }

  auto
  CellArea::gobj_copy () -> GtkCellArea*
  {
    reference ();
    return gobj ();
  }

  CellArea::CellArea (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
    if (gobject_ && g_object_is_floating (gobject_))
      g_object_ref_sink (gobject_);
  }

  CellArea::CellArea (GtkCellArea* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  CellArea::CellArea (CellArea&& src) noexcept
    : glib::Object (std::move (src)),
      Buildable (std::move (src)),
      CellLayout (std::move (src))
  {
  }

  auto
  CellArea::operator= (CellArea&& src) noexcept -> CellArea&
  {
    glib::Object::operator= (std::move (src));
    Buildable::operator= (std::move (src));
    CellLayout::operator= (std::move (src));
    return *this;
  }

  CellArea::~CellArea () noexcept {}

  CellArea::CppClassType CellArea::cellarea_class_;

  auto
  CellArea::get_type () -> GType
  {
    return cellarea_class_.init ().get_type ();
  }

  auto
  CellArea::get_base_type () -> GType
  {
    return gtk_cell_area_get_type ();
  }

  CellArea::CellArea ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (cellarea_class_.init ()))
  {
    if (gobject_ && g_object_is_floating (gobject_))
      g_object_ref_sink (gobject_);
  }

  auto
  CellArea::add (CellRenderer& renderer) -> void
  {
    gtk_cell_area_add (gobj (), (renderer).gobj ());
  }

  auto
  CellArea::remove (CellRenderer& renderer) -> void
  {
    gtk_cell_area_remove (gobj (), (renderer).gobj ());
  }

  auto
  CellArea::has_renderer (CellRenderer& renderer) -> bool
  {
    return gtk_cell_area_has_renderer (gobj (), (renderer).gobj ());
  }

  auto
  CellArea::event (const glib::RefPtr<CellAreaContext>& context,
                   Widget& widget,
                   const glib::RefPtr<const gdk::Event>& gdk_event,
                   const gdk::Rectangle& cell_area,
                   GtkCellRendererState flags) -> int
  {
    return gtk_cell_area_event (
        gobj (),
        glib::unwrap (context),
        (widget).gobj (),
        const_cast<GdkEvent*> (glib::unwrap (gdk_event)),
        (cell_area).gobj (),
        flags);
  }

  auto
  CellArea::snapshot (const glib::RefPtr<CellAreaContext>& context,
                      Widget& widget,
                      const glib::RefPtr<gtk::Snapshot>& snapshot,
                      const gdk::Rectangle& background_area,
                      const gdk::Rectangle& cell_area,
                      CellRendererState flags,
                      bool paint_focus) -> void
  {
    gtk_cell_area_snapshot (gobj (),
                            glib::unwrap (context),
                            (widget).gobj (),
                            glib::unwrap (snapshot),
                            (background_area).gobj (),
                            (cell_area).gobj (),
                            static_cast<GtkCellRendererState> (flags),
                            static_cast<int> (paint_focus));
  }

  auto
  CellArea::get_cell_allocation (const glib::RefPtr<CellAreaContext>& context,
                                 Widget& widget,
                                 CellRenderer& renderer,
                                 const gdk::Rectangle& cell_area,
                                 gdk::Rectangle& allocation) -> void
  {
    gtk_cell_area_get_cell_allocation (gobj (),
                                       glib::unwrap (context),
                                       (widget).gobj (),
                                       (renderer).gobj (),
                                       (cell_area).gobj (),
                                       (allocation).gobj ());
  }

  auto
  CellArea::get_cell_at_position (const glib::RefPtr<CellAreaContext>& context,
                                  Widget& widget,
                                  const gdk::Rectangle& cell_area,
                                  int x,
                                  int y,
                                  gdk::Rectangle& alloc_area) -> CellRenderer*
  {
    return glib::wrap (
        gtk_cell_area_get_cell_at_position (gobj (),
                                            glib::unwrap (context),
                                            (widget).gobj (),
                                            (cell_area).gobj (),
                                            x,
                                            y,
                                            (alloc_area).gobj ()));
  }

  auto
  CellArea::get_cell_at_position (const glib::RefPtr<CellAreaContext>& context,
                                  Widget& widget,
                                  const gdk::Rectangle& cell_area,
                                  int x,
                                  int y,
                                  gdk::Rectangle& alloc_area) const -> const CellRenderer*
  {
    return const_cast<CellArea*> (this)
        ->get_cell_at_position (context, widget, cell_area, x, y, alloc_area);
  }

  auto
  CellArea::create_context () const -> glib::RefPtr<CellAreaContext>
  {
    return glib::wrap (
        gtk_cell_area_create_context (const_cast<GtkCellArea*> (gobj ())));
  }

  auto
  CellArea::copy_context (const glib::RefPtr<const CellAreaContext>& context) -> glib::RefPtr<CellAreaContext>
  {
    return glib::wrap (gtk_cell_area_copy_context (
        gobj (),
        const_cast<GtkCellAreaContext*> (glib::unwrap (context))));
  }

  auto
  CellArea::get_request_mode () const -> SizeRequestMode
  {
    return static_cast<SizeRequestMode> (
        gtk_cell_area_get_request_mode (const_cast<GtkCellArea*> (gobj ())));
  }

  auto
  CellArea::get_preferred_width (const glib::RefPtr<CellAreaContext>& context,
                                 Widget& widget,
                                 int& minimum_width,
                                 int& natural_width) -> void
  {
    gtk_cell_area_get_preferred_width (gobj (),
                                       glib::unwrap (context),
                                       (widget).gobj (),
                                       &(minimum_width),
                                       &(natural_width));
  }

  auto
  CellArea::get_preferred_height_for_width (
      const glib::RefPtr<CellAreaContext>& context,
      Widget& widget,
      int width,
      int& minimum_height,
      int& natural_height) -> void
  {
    gtk_cell_area_get_preferred_height_for_width (gobj (),
                                                  glib::unwrap (context),
                                                  (widget).gobj (),
                                                  width,
                                                  &(minimum_height),
                                                  &(natural_height));
  }

  auto
  CellArea::get_preferred_height (const glib::RefPtr<CellAreaContext>& context,
                                  Widget& widget,
                                  int& minimum_height,
                                  int& natural_height) -> void
  {
    gtk_cell_area_get_preferred_height (gobj (),
                                        glib::unwrap (context),
                                        (widget).gobj (),
                                        &(minimum_height),
                                        &(natural_height));
  }

  auto
  CellArea::get_preferred_width_for_height (
      const glib::RefPtr<CellAreaContext>& context,
      Widget& widget,
      int height,
      int& minimum_width,
      int& natural_width) -> void
  {
    gtk_cell_area_get_preferred_width_for_height (gobj (),
                                                  glib::unwrap (context),
                                                  (widget).gobj (),
                                                  height,
                                                  &(minimum_width),
                                                  &(natural_width));
  }

  auto
  CellArea::get_current_path_string () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_cell_area_get_current_path_string (
            const_cast<GtkCellArea*> (gobj ())));
  }

  auto
  CellArea::apply_attributes (const glib::RefPtr<TreeModel>& tree_model,
                              const TreeModel::iterator& iter,
                              bool is_expander,
                              bool is_expanded) -> void
  {
    gtk_cell_area_apply_attributes (gobj (),
                                    glib::unwrap (tree_model),
                                    const_cast<GtkTreeIter*> ((iter).gobj ()),
                                    static_cast<int> (is_expander),
                                    static_cast<int> (is_expanded));
  }

  auto
  CellArea::attribute_connect (CellRenderer& renderer,
                               const glib::ustring& attribute,
                               int column) -> void
  {
    gtk_cell_area_attribute_connect (gobj (),
                                     (renderer).gobj (),
                                     attribute.c_str (),
                                     column);
  }

  auto
  CellArea::attribute_disconnect (CellRenderer& renderer,
                                  const glib::ustring& attribute) -> void
  {
    gtk_cell_area_attribute_disconnect (gobj (),
                                        (renderer).gobj (),
                                        attribute.c_str ());
  }

  auto
  CellArea::attribute_get_column (CellRenderer& renderer,
                                  const glib::ustring& attribute) const -> int
  {
    return gtk_cell_area_attribute_get_column (
        const_cast<GtkCellArea*> (gobj ()),
        (renderer).gobj (),
        attribute.c_str ());
  }

  auto
  CellArea::cell_set_property (CellRenderer& renderer,
                               const glib::ustring& property_name,
                               const glib::ValueBase& value) -> void
  {
    gtk_cell_area_cell_set_property (gobj (),
                                     (renderer).gobj (),
                                     property_name.c_str (),
                                     (value).gobj ());
  }

  auto
  CellArea::cell_get_property (CellRenderer& renderer,
                               const glib::ustring& property_name,
                               glib::ValueBase& value) -> void
  {
    gtk_cell_area_cell_get_property (gobj (),
                                     (renderer).gobj (),
                                     property_name.c_str (),
                                     (value).gobj ());
  }

  auto
  CellArea::is_activatable () const -> bool
  {
    return gtk_cell_area_is_activatable (const_cast<GtkCellArea*> (gobj ()));
  }

  auto
  CellArea::activate (const glib::RefPtr<CellAreaContext>& context,
                      Widget& widget,
                      const gdk::Rectangle& cell_area,
                      CellRendererState flags,
                      bool edit_only) -> bool
  {
    return gtk_cell_area_activate (gobj (),
                                   glib::unwrap (context),
                                   (widget).gobj (),
                                   (cell_area).gobj (),
                                   static_cast<GtkCellRendererState> (flags),
                                   static_cast<int> (edit_only));
  }

  auto
  CellArea::focus (DirectionType direction) -> bool
  {
    return gtk_cell_area_focus (gobj (),
                                static_cast<GtkDirectionType> (direction));
  }

  auto
  CellArea::set_focus_cell (CellRenderer& renderer) -> void
  {
    gtk_cell_area_set_focus_cell (gobj (), (renderer).gobj ());
  }

  auto
  CellArea::get_focus_cell () -> CellRenderer*
  {
    return glib::wrap (gtk_cell_area_get_focus_cell (gobj ()));
  }

  auto
  CellArea::get_focus_cell () const -> const CellRenderer*
  {
    return const_cast<CellArea*> (this)->get_focus_cell ();
  }

  auto
  CellArea::add_focus_sibling (CellRenderer& renderer, CellRenderer& sibling) -> void
  {
    gtk_cell_area_add_focus_sibling (gobj (),
                                     (renderer).gobj (),
                                     (sibling).gobj ());
  }

  auto
  CellArea::remove_focus_sibling (CellRenderer& renderer, CellRenderer& sibling) -> void
  {
    gtk_cell_area_remove_focus_sibling (gobj (),
                                        (renderer).gobj (),
                                        (sibling).gobj ());
  }

  auto
  CellArea::is_focus_sibling (CellRenderer& renderer, CellRenderer& sibling) -> bool
  {
    return gtk_cell_area_is_focus_sibling (gobj (),
                                           (renderer).gobj (),
                                           (sibling).gobj ());
  }

  auto
  CellArea::get_focus_siblings (CellRenderer& renderer) -> std::vector<CellRenderer*>
  {
    return glib::ListHandler<CellRenderer*>::list_to_vector (
        const_cast<GList*> (
            gtk_cell_area_get_focus_siblings (gobj (), (renderer).gobj ())),
        glib::OWNERSHIP_NONE);
  }

  auto
  CellArea::get_focus_siblings (const CellRenderer& renderer) const -> std::vector<const CellRenderer*>
  {
    return glib::ListHandler<const CellRenderer*>::list_to_vector (
        const_cast<GList*> (gtk_cell_area_get_focus_siblings (
            const_cast<GtkCellArea*> (gobj ()),
            const_cast<GtkCellRenderer*> ((renderer).gobj ()))),
        glib::OWNERSHIP_NONE);
  }

  auto
  CellArea::get_focus_from_sibling (CellRenderer& renderer) -> CellRenderer*
  {
    return glib::wrap (
        gtk_cell_area_get_focus_from_sibling (gobj (), (renderer).gobj ()));
  }

  auto
  CellArea::get_focus_from_sibling (CellRenderer& renderer) const -> const CellRenderer*
  {
    return const_cast<CellArea*> (this)->get_focus_from_sibling (renderer);
  }

  auto
  CellArea::get_edited_cell () -> CellRenderer*
  {
    return glib::wrap (gtk_cell_area_get_edited_cell (gobj ()));
  }

  auto
  CellArea::get_edited_cell () const -> const CellRenderer*
  {
    return const_cast<CellArea*> (this)->get_edited_cell ();
  }

  auto
  CellArea::get_edit_widget () -> CellEditable*
  {
    return dynamic_cast<CellEditable*> (
        glib::wrap_auto ((GObject*) (gtk_cell_area_get_edit_widget (gobj ())),
                         false));
  }

  auto
  CellArea::get_edit_widget () const -> const CellEditable*
  {
    return const_cast<CellArea*> (this)->get_edit_widget ();
  }

  auto
  CellArea::activate_cell (Widget& widget,
                           CellRenderer& renderer,
                           const glib::RefPtr<const gdk::Event>& gdk_event,
                           const gdk::Rectangle& cell_area,
                           CellRendererState flags) -> bool
  {
    return gtk_cell_area_activate_cell (
        gobj (),
        (widget).gobj (),
        (renderer).gobj (),
        const_cast<GdkEvent*> (glib::unwrap (gdk_event)),
        (cell_area).gobj (),
        static_cast<GtkCellRendererState> (flags));
  }

  auto
  CellArea::stop_editing (bool canceled) -> void
  {
    gtk_cell_area_stop_editing (gobj (), static_cast<int> (canceled));
  }

  auto
  CellArea::inner_cell_area (Widget& widget,
                             const gdk::Rectangle& cell_area,
                             gdk::Rectangle& inner_area) -> void
  {
    gtk_cell_area_inner_cell_area (gobj (),
                                   (widget).gobj (),
                                   (cell_area).gobj (),
                                   (inner_area).gobj ());
  }

  auto
  CellArea::request_renderer (CellRenderer& renderer,
                              Orientation orientation,
                              Widget& widget,
                              int for_size,
                              int& minimum_size,
                              int& natural_size) -> void
  {
    gtk_cell_area_request_renderer (gobj (),
                                    (renderer).gobj (),
                                    static_cast<GtkOrientation> (orientation),
                                    (widget).gobj (),
                                    for_size,
                                    &(minimum_size),
                                    &(natural_size));
  }

  auto
  CellArea::signal_apply_attributes () -> glib::SignalProxy<void (const glib::RefPtr<TreeModel>&,
                                 const TreeModel::iterator&,
                                 bool,
                                 bool)>
  {
    return glib::SignalProxy<void (const glib::RefPtr<TreeModel>&,
                                   const TreeModel::iterator&,
                                   bool,
                                   bool)> (
        this,
        &CellArea_signal_apply_attributes_info);
  }

  auto
  CellArea::signal_add_editable () -> glib::SignalProxy<void (CellRenderer*,
                                 CellEditable*,
                                 const gdk::Rectangle&,
                                 const glib::ustring&)>
  {
    return glib::SignalProxy<void (CellRenderer*,
                                   CellEditable*,
                                   const gdk::Rectangle&,
                                   const glib::ustring&)> (
        this,
        &CellArea_signal_add_editable_info);
  }

  auto
  CellArea::signal_remove_editable () -> glib::SignalProxy<void (CellRenderer*, CellEditable*)>
  {
    return glib::SignalProxy<void (CellRenderer*, CellEditable*)> (
        this,
        &CellArea_signal_remove_editable_info);
  }

  auto
  CellArea::signal_focus_changed () -> glib::SignalProxy<void (CellRenderer*, const glib::ustring&)>
  {
    return glib::SignalProxy<void (CellRenderer*, const glib::ustring&)> (
        this,
        &CellArea_signal_focus_changed_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<CellRenderer*>::value,
      "Type CellRenderer* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CellArea::property_focus_cell () -> glib::PropertyProxy<CellRenderer*>
  {
    return glib::PropertyProxy<CellRenderer*> (this, "focus-cell");
  }

  auto
  CellArea::property_focus_cell () const -> glib::PropertyProxy_ReadOnly<CellRenderer*>
  {
    return glib::PropertyProxy_ReadOnly<CellRenderer*> (this, "focus-cell");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<CellRenderer*>::value,
      "Type CellRenderer* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CellArea::property_edited_cell () const -> glib::PropertyProxy_ReadOnly<CellRenderer*>
  {
    return glib::PropertyProxy_ReadOnly<CellRenderer*> (this, "edited-cell");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<CellEditable*>::value,
      "Type CellEditable* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CellArea::property_edit_widget () const -> glib::PropertyProxy_ReadOnly<CellEditable*>
  {
    return glib::PropertyProxy_ReadOnly<CellEditable*> (this, "edit-widget");
  }

  auto
  gtk::CellArea::on_apply_attributes (const glib::RefPtr<TreeModel>& tree_model,
                                      const TreeModel::iterator& iter,
                                      bool is_expander,
                                      bool is_expanded) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->apply_attributes)
      (*base->apply_attributes) (gobj (),
                                 glib::unwrap (tree_model),
                                 const_cast<GtkTreeIter*> ((iter).gobj ()),
                                 static_cast<int> (is_expander),
                                 static_cast<int> (is_expanded));
  }

  auto
  gtk::CellArea::snapshot_vfunc (const glib::RefPtr<CellAreaContext>& context,
                                 Widget& widget,
                                 const glib::RefPtr<gtk::Snapshot>& snapshot,
                                 const gdk::Rectangle& background_area,
                                 const gdk::Rectangle& cell_area,
                                 CellRendererState flags,
                                 bool paint_focus) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->snapshot)
    {
      (*base->snapshot) (gobj (),
                         glib::unwrap (context),
                         (widget).gobj (),
                         glib::unwrap (snapshot),
                         (background_area).gobj (),
                         (cell_area).gobj (),
                         static_cast<GtkCellRendererState> (flags),
                         static_cast<int> (paint_focus));
    }
  }

  auto
  gtk::CellArea::get_request_mode_vfunc () const -> SizeRequestMode
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->get_request_mode)
    {
      SizeRequestMode retval (static_cast<SizeRequestMode> (
          (*base->get_request_mode) (const_cast<GtkCellArea*> (gobj ()))));
      return retval;
    }

    using RType = SizeRequestMode;
    return RType ();
  }

  auto
  gtk::CellArea::get_preferred_width_vfunc (
      const glib::RefPtr<CellAreaContext>& context,
      Widget& widget,
      int& minimum_width,
      int& natural_width) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->get_preferred_width)
    {
      (*base->get_preferred_width) (gobj (),
                                    glib::unwrap (context),
                                    (widget).gobj (),
                                    &(minimum_width),
                                    &(natural_width));
    }
  }

  auto
  gtk::CellArea::get_preferred_height_for_width_vfunc (
      const glib::RefPtr<CellAreaContext>& context,
      Widget& widget,
      int width,
      int& minimum_height,
      int& natural_height) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->get_preferred_height_for_width)
    {
      (*base->get_preferred_height_for_width) (gobj (),
                                               glib::unwrap (context),
                                               (widget).gobj (),
                                               width,
                                               &(minimum_height),
                                               &(natural_height));
    }
  }

  auto
  gtk::CellArea::get_preferred_height_vfunc (
      const glib::RefPtr<CellAreaContext>& context,
      Widget& widget,
      int& minimum_height,
      int& natural_height) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->get_preferred_height)
    {
      (*base->get_preferred_height) (gobj (),
                                     glib::unwrap (context),
                                     (widget).gobj (),
                                     &(minimum_height),
                                     &(natural_height));
    }
  }

  auto
  gtk::CellArea::get_preferred_width_for_height_vfunc (
      const glib::RefPtr<CellAreaContext>& context,
      Widget& widget,
      int height,
      int& minimum_width,
      int& natural_width) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->get_preferred_width_for_height)
    {
      (*base->get_preferred_width_for_height) (gobj (),
                                               glib::unwrap (context),
                                               (widget).gobj (),
                                               height,
                                               &(minimum_width),
                                               &(natural_width));
    }
  }

} // namespace gtk

#endif
