// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/widget.hxx>
#include <libmm/gtk/widget_p.hxx>

#include <gtk/gtk.h>

#include <libmm/gio/listmodel.hxx>
#include <libmm/glib/vectorutils.hxx>

#include <gtk/gtk.h>
#include <libmm/gdk/frameclock.hxx>
#include <libmm/gdk/paintable.hxx>
#include <libmm/gtk/adjustment.hxx>
#include <libmm/gtk/eventcontroller.hxx>
#include <libmm/gtk/layoutmanager.hxx>
#include <libmm/gtk/native.hxx>
#include <libmm/gtk/root.hxx>
#include <libmm/gtk/settings.hxx>
#include <libmm/gtk/snapshot.hxx>
#include <libmm/gtk/tooltip.hxx>
#include <libmm/gtk/window.hxx>

namespace
{

  auto
  Widget_signal_hide_callback (GObject* self, void* data) -> void
  {
    const auto obj = glib::ObjectBase::_get_current_wrapper (self);

    if (obj && !obj->_cpp_destruction_is_in_progress ())
    {
      try
      {
        if (sigc::slot_base* const slot =
                glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<sigc::slot<void ()>*> (slot)) ();
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  auto
  SlotTick_gtk_callback (GtkWidget* self,
                         GdkFrameClock* frame_clock,
                         void* data) -> gboolean
  {
    if (glib::ObjectBase::_get_current_wrapper ((GObject*) self))
    {
      auto the_slot = static_cast<gtk::Widget::SlotTick*> (data);
      try
      {
        return (*the_slot) (glib::wrap (frame_clock, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
    return false;
  }

} // namespace

namespace gtk
{

  auto
  Widget_Class::hide_callback (GtkWidget* self) -> void
  {
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ () &&
        !obj_base->_cpp_destruction_is_in_progress ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_hide ();
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

    if (base && base->hide)
      (*base->hide) (self);
  }

  auto
  Widget_Class::measure_vfunc_callback (GtkWidget* self,
                                        GtkOrientation orientation,
                                        int for_size,
                                        int* minimum,
                                        int* natural,
                                        int* minimum_baseline,
                                        int* natural_baseline) -> void
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
          int no_minimum = 0;
          int no_natural = 0;
          int no_minimum_baseline = 0;
          int no_natural_baseline = 0;
          obj->measure_vfunc (
              (Orientation) orientation,
              for_size,
              (minimum ? *minimum : no_minimum),
              (natural ? *natural : no_natural),
              (minimum_baseline ? *minimum_baseline : no_minimum_baseline),
              (natural_baseline ? *natural_baseline : no_natural_baseline));
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

    if (base && base->measure)
      (*base->measure) (self,
                        orientation,
                        for_size,
                        minimum,
                        natural,
                        minimum_baseline,
                        natural_baseline);
  }

  auto
  Widget_Class::compute_expand_vfunc_callback (GtkWidget* self,
                                               gboolean* hexpand_p,
                                               gboolean* vexpand_p) -> void
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
          bool hexpand_pcxx = hexpand_p ? *hexpand_p : false;
          bool vexpand_pcxx = vexpand_p ? *vexpand_p : false;
          obj->compute_expand_vfunc (hexpand_pcxx, vexpand_pcxx);
          if (hexpand_p)
            *hexpand_p = hexpand_pcxx;
          if (vexpand_p)
            *vexpand_p = vexpand_pcxx;
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

    if (base && base->compute_expand)
      (*base->compute_expand) (self, hexpand_p, vexpand_p);
  }

  auto
  gtk::Widget::compute_expand_vfunc (bool& hexpand_p, bool& vexpand_p) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->compute_expand)
    {
      gboolean hexpand_pc = hexpand_p;
      gboolean vexpand_pc = vexpand_p;
      (*base->compute_expand) (gobj (), &hexpand_pc, &vexpand_pc);
      hexpand_p = hexpand_pc;
      vexpand_p = vexpand_pc;
    }
  }

  Widget::~Widget () noexcept {}

  auto
  Widget::make_refptr_constrainttarget () -> glib::RefPtr<ConstraintTarget>
  {
    auto refcnt_constrainttarget =
        glib::make_refptr_for_instance (static_cast<ConstraintTarget*> (this));
    refcnt_constrainttarget->reference ();
    return refcnt_constrainttarget;
  }

  auto
  Widget::make_refptr_constrainttarget () const -> glib::RefPtr<const ConstraintTarget>
  {
    return const_cast<Widget*> (this)->make_refptr_constrainttarget ();
  }

  auto
  Widget::set_layout_manager (const glib::RefPtr<LayoutManager>& layout_manager) -> void
  {
    if (layout_manager)
      layout_manager->reference ();
    gtk_widget_set_layout_manager (gobj (), glib::unwrap (layout_manager));
  }

  auto
  Widget::unset_layout_manager () -> void
  {
    gtk_widget_set_layout_manager (gobj (), nullptr);
  }

  auto
  Widget::unset_name () -> void
  {
    gtk_widget_set_name (gobj (), nullptr);
  }

  auto
  Widget::realize_if_needed () -> void
  {
    if (!get_realized ())
      realize ();
  }

  auto
  Widget::unset_focus_child () -> void
  {
    gtk_widget_set_focus_child (gobj (), nullptr);
  }

  auto
  Widget::get_allocation () const -> Allocation
  {
    Allocation allocation;
    gtk_widget_get_allocation (const_cast<GtkWidget*> (gobj ()),
                               allocation.gobj ());
    return allocation;
  }

  auto
  Widget_Class::dispose_vfunc_callback (GObject* self) -> void
  {
#ifdef GLIBMM_DEBUG_REFCOUNTING
    g_warning ("Widget_Class::dispose_vfunc_callback(): gobject_: %p\n",
               (void*) self);

#endif

    const auto obj =
        dynamic_cast<Widget*> (glib::ObjectBase::_get_current_wrapper (self));

    if (obj && !obj->_cpp_destruction_is_in_progress ())
    {
      const auto pWidget = obj->gobj ();
      g_return_if_fail (pWidget == GTK_WIDGET (self));

      if (obj->referenced_)
      {
        GtkWidget* parent = gtk_widget_get_parent (pWidget);
        if (parent)
        {
#ifdef GLIBMM_DEBUG_REFCOUNTING
          g_warning ("Widget_Class::dispose_vfunc_callback(): removing "
                     "gobject_: %p from parent: %p",
                     (void*) self,
                     (void*) parent);
#endif

          gtk_widget_unparent (pWidget);

#ifdef GLIBMM_DEBUG_REFCOUNTING
          g_warning ("Widget_Class::dispose_vfunc_callback(): after removing "
                     "from parent.");
#endif
        }

#ifdef GLIBMM_DEBUG_REFCOUNTING
        g_warning ("Widget_Class::dispose_vfunc_callback(): before "
                   "gtk_widget_set_visible(pWidget, false).");
#endif

        gtk_widget_set_visible (pWidget, false);

#ifdef GLIBMM_DEBUG_REFCOUNTING
        g_warning ("Widget_Class::dispose_vfunc_callback(): after "
                   "gtk_widget_set_visible(pWidget, false).");
#endif

        return;
      }

#ifdef GLIBMM_DEBUG_REFCOUNTING
      g_warning ("Widget_Class::dispose_vfunc_callback(): unreferenced: before "
                 "gtk_widget_set_visible(pWidget, false).");
#endif

      gtk_widget_set_visible (pWidget, false);

#ifdef GLIBMM_DEBUG_REFCOUNTING
      g_warning ("Widget_Class::dispose_vfunc_callback(): unreferenced:  after "
                 "gtk_widget_set_visible(pWidget, false).");
#endif
    }

    const auto base = static_cast<GObjectClass*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

#ifdef GLIBMM_DEBUG_REFCOUNTING
    g_warning ("Widget_Class::dispose_vfunc_callback(): before calling "
               "base->dispose.");
#endif

    if (base->dispose)
      (*base->dispose) (self);

#ifdef GLIBMM_DEBUG_REFCOUNTING
    g_warning (
        "Widget_Class::dispose_vfunc_callback(): after calling base->dispose.");
#endif
  }

  auto
  Widget::unset_font_options () -> void
  {
    gtk_widget_set_font_options (gobj (), nullptr);
  }

  auto
  Widget::remove_action_group (const glib::ustring& name) -> void
  {
    gtk_widget_insert_action_group (gobj (), name.c_str (), nullptr);
  }

  auto
  Widget::set_margin (int margin) -> void
  {
    set_margin_start (margin);
    set_margin_end (margin);
    set_margin_top (margin);
    set_margin_bottom (margin);
  }

  auto
  Widget::set_expand (bool expand) -> void
  {
    set_hexpand (expand);
    set_vexpand (expand);
  }

  auto
  Widget::add_controller (const glib::RefPtr<EventController>& controller) -> void
  {
    if (controller)
      controller->reference ();
    gtk_widget_add_controller (gobj (), glib::unwrap (controller));
  }

  auto
  Widget::add_tick_callback (const SlotTick& slot) -> guint
  {
    auto slot_copy = new SlotTick (slot);

    return gtk_widget_add_tick_callback (
        gobj (),
        &SlotTick_gtk_callback,
        slot_copy,
        &glib::destroy_notify_delete<SlotTick>);
  }

  auto
  Widget::insert_at_start (Widget& parent) -> void
  {
    gtk_widget_insert_after (gobj (), parent.gobj (), nullptr);
  }

  auto
  Widget::insert_at_end (Widget& parent) -> void
  {
    gtk_widget_insert_before (gobj (), parent.gobj (), nullptr);
  }

  auto
  Widget::get_color () const -> gdk::RGBA
  {
    GdkRGBA crgba;
    gtk_widget_get_color (const_cast<GtkWidget*> (gobj ()), &crgba);
    return gdk::RGBA (&crgba, true);
  }

} // namespace gtk

namespace
{

  static const glib::SignalProxyInfo Widget_signal_show_info = {
      "show",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static const glib::SignalProxyInfo Widget_signal_hide_info = {
      "hide",
      (GCallback) &Widget_signal_hide_callback,
      (GCallback) &Widget_signal_hide_callback};

  static const glib::SignalProxyInfo Widget_signal_map_info = {
      "map",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static const glib::SignalProxyInfo Widget_signal_unmap_info = {
      "unmap",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static const glib::SignalProxyInfo Widget_signal_realize_info = {
      "realize",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static const glib::SignalProxyInfo Widget_signal_unrealize_info = {
      "unrealize",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static auto
  Widget_signal_state_flags_changed_callback (GtkWidget* self,
                                              GtkStateFlags p0,
                                              void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (gtk::StateFlags)>;

    auto obj = dynamic_cast<Widget*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (static_cast<gtk::StateFlags> (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo Widget_signal_state_flags_changed_info = {
      "state-flags-changed",
      (GCallback) &Widget_signal_state_flags_changed_callback,
      (GCallback) &Widget_signal_state_flags_changed_callback};

  static auto
  Widget_signal_direction_changed_callback (GtkWidget* self,
                                            GtkTextDirection p0,
                                            void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (TextDirection)>;

    auto obj = dynamic_cast<Widget*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (static_cast<TextDirection> (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo Widget_signal_direction_changed_info = {
      "direction_changed",
      (GCallback) &Widget_signal_direction_changed_callback,
      (GCallback) &Widget_signal_direction_changed_callback};

  static auto
  Widget_signal_mnemonic_activate_callback (GtkWidget* self,
                                            gboolean p0,
                                            void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<bool (bool)>;

    auto obj = dynamic_cast<Widget*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> ((*static_cast<SlotType*> (slot)) (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static auto
  Widget_signal_mnemonic_activate_notify_callback (GtkWidget* self,
                                                   gboolean p0,
                                                   void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (bool)>;

    auto obj = dynamic_cast<Widget*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const glib::SignalProxyInfo Widget_signal_mnemonic_activate_info = {
      "mnemonic_activate",
      (GCallback) &Widget_signal_mnemonic_activate_callback,
      (GCallback) &Widget_signal_mnemonic_activate_notify_callback};

  static const glib::SignalProxyInfo Widget_signal_destroy_info = {
      "destroy",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static auto
  Widget_signal_query_tooltip_callback (GtkWidget* self,
                                        gint p0,
                                        gint p1,
                                        gboolean p2,
                                        GtkTooltip* p3,
                                        void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType =
        sigc::slot<bool (int, int, bool, const glib::RefPtr<Tooltip>&)>;

    auto obj = dynamic_cast<Widget*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> ((*static_cast<SlotType*> (
              slot)) (p0, p1, p2, glib::wrap (p3, true)));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static auto
  Widget_signal_query_tooltip_notify_callback (GtkWidget* self,
                                               gint p0,
                                               gint p1,
                                               gboolean p2,
                                               GtkTooltip* p3,
                                               void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType =
        sigc::slot<void (int, int, bool, const glib::RefPtr<Tooltip>&)>;

    auto obj = dynamic_cast<Widget*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0, p1, p2, glib::wrap (p3, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const glib::SignalProxyInfo Widget_signal_query_tooltip_info = {
      "query_tooltip",
      (GCallback) &Widget_signal_query_tooltip_callback,
      (GCallback) &Widget_signal_query_tooltip_notify_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkWidget* object, bool take_copy) -> gtk::Widget*
  {
    return dynamic_cast<gtk::Widget*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  Widget_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Widget_Class::class_init_function;

      register_derived_type (gtk_widget_get_type ());

      Accessible::add_interface (get_type ());
      Buildable::add_interface (get_type ());
      ConstraintTarget::add_interface (get_type ());
    }

    return *this;
  }

  auto
  Widget_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    reinterpret_cast<GObjectClass*> (klass)->dispose = &dispose_vfunc_callback;
    klass->root = &root_vfunc_callback;
    klass->unroot = &unroot_vfunc_callback;
    klass->size_allocate = &size_allocate_vfunc_callback;
    klass->get_request_mode = &get_request_mode_vfunc_callback;
    klass->measure = &measure_vfunc_callback;
    klass->grab_focus = &grab_focus_vfunc_callback;
    klass->set_focus_child = &set_focus_child_vfunc_callback;
    klass->compute_expand = &compute_expand_vfunc_callback;
    klass->contains = &contains_vfunc_callback;
    klass->snapshot = &snapshot_vfunc_callback;

    klass->show = &show_callback;
    klass->hide = &hide_callback;
    klass->map = &map_callback;
    klass->unmap = &unmap_callback;
    klass->realize = &realize_callback;
    klass->unrealize = &unrealize_callback;
    klass->state_flags_changed = &state_flags_changed_callback;
    klass->direction_changed = &direction_changed_callback;
    klass->mnemonic_activate = &mnemonic_activate_callback;
    klass->query_tooltip = &query_tooltip_callback;
  }

  auto
  Widget_Class::root_vfunc_callback (GtkWidget* self) -> void
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
          obj->root_vfunc ();
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

    if (base && base->root)
      (*base->root) (self);
  }

  auto
  Widget_Class::unroot_vfunc_callback (GtkWidget* self) -> void
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
          obj->unroot_vfunc ();
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

    if (base && base->unroot)
      (*base->unroot) (self);
  }

  auto
  Widget_Class::size_allocate_vfunc_callback (GtkWidget* self,
                                              int width,
                                              int height,
                                              int baseline) -> void
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
          obj->size_allocate_vfunc (width, height, baseline);
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

    if (base && base->size_allocate)
      (*base->size_allocate) (self, width, height, baseline);
  }

  auto
  Widget_Class::get_request_mode_vfunc_callback (GtkWidget* self) -> GtkSizeRequestMode
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
  Widget_Class::grab_focus_vfunc_callback (GtkWidget* self) -> gboolean
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
          return static_cast<int> (obj->grab_focus_vfunc ());
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->grab_focus)
      return (*base->grab_focus) (self);

    using RType = gboolean;
    return RType ();
  }

  auto
  Widget_Class::set_focus_child_vfunc_callback (GtkWidget* self,
                                                GtkWidget* child) -> void
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
          obj->set_focus_child_vfunc (glib::wrap (child));
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

    if (base && base->set_focus_child)
      (*base->set_focus_child) (self, child);
  }

  auto
  Widget_Class::contains_vfunc_callback (GtkWidget* self, gdouble x, gdouble y) -> gboolean
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
          return static_cast<int> (obj->contains_vfunc (x, y));
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->contains)
      return (*base->contains) (self, x, y);

    using RType = gboolean;
    return RType ();
  }

  auto
  Widget_Class::snapshot_vfunc_callback (GtkWidget* self, GtkSnapshot* snapshot) -> void
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
          obj->snapshot_vfunc (glib::wrap_gtk_snapshot (snapshot, true));
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
      (*base->snapshot) (self, snapshot);
  }

  auto
  Widget_Class::show_callback (GtkWidget* self) -> void
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
          obj->on_show ();
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

    if (base && base->show)
      (*base->show) (self);
  }

  auto
  Widget_Class::map_callback (GtkWidget* self) -> void
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
          obj->on_map ();
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

    if (base && base->map)
      (*base->map) (self);
  }

  auto
  Widget_Class::unmap_callback (GtkWidget* self) -> void
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
          obj->on_unmap ();
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

    if (base && base->unmap)
      (*base->unmap) (self);
  }

  auto
  Widget_Class::realize_callback (GtkWidget* self) -> void
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
          obj->on_realize ();
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

    if (base && base->realize)
      (*base->realize) (self);
  }

  auto
  Widget_Class::unrealize_callback (GtkWidget* self) -> void
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
          obj->on_unrealize ();
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

    if (base && base->unrealize)
      (*base->unrealize) (self);
  }

  auto
  Widget_Class::state_flags_changed_callback (GtkWidget* self, GtkStateFlags p0) -> void
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
          obj->on_state_flags_changed (static_cast<gtk::StateFlags> (p0));
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

    if (base && base->state_flags_changed)
      (*base->state_flags_changed) (self, p0);
  }

  auto
  Widget_Class::direction_changed_callback (GtkWidget* self,
                                            GtkTextDirection p0) -> void
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
          obj->on_direction_changed (static_cast<TextDirection> (p0));
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

    if (base && base->direction_changed)
      (*base->direction_changed) (self, p0);
  }

  auto
  Widget_Class::mnemonic_activate_callback (GtkWidget* self, gboolean p0) -> gboolean
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
          return static_cast<int> (obj->on_mnemonic_activate (p0));
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->mnemonic_activate)
      return (*base->mnemonic_activate) (self, p0);

    using RType = gboolean;
    return RType ();
  }

  auto
  Widget_Class::query_tooltip_callback (GtkWidget* self,
                                        gint p0,
                                        gint p1,
                                        gboolean p2,
                                        GtkTooltip* p3) -> gboolean
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
          return static_cast<int> (
              obj->on_query_tooltip (p0, p1, p2, glib::wrap (p3, true)));
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->query_tooltip)
      return (*base->query_tooltip) (self, p0, p1, p2, p3);

    using RType = gboolean;
    return RType ();
  }

  auto
  Widget_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Widget ((GtkWidget*) (o)));
  }

  Widget::Widget (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  Widget::Widget (GtkWidget* castitem)
    : Object ((GObject*) (castitem))
  {
  }

  Widget::Widget (Widget&& src) noexcept
    : Object (std::move (src)),
      Accessible (std::move (src)),
      Buildable (std::move (src)),
      ConstraintTarget (std::move (src))
  {
  }

  auto
  Widget::operator= (Widget&& src) noexcept -> Widget&
  {
    Object::operator= (std::move (src));
    Accessible::operator= (std::move (src));
    Buildable::operator= (std::move (src));
    ConstraintTarget::operator= (std::move (src));
    return *this;
  }

  Widget::CppClassType Widget::widget_class_;

  auto
  Widget::get_type () -> GType
  {
    return widget_class_.init ().get_type ();
  }

  auto
  Widget::get_base_type () -> GType
  {
    return gtk_widget_get_type ();
  }

#ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  Widget::show () -> void
  {
    gtk_widget_show (gobj ());
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

#ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  Widget::hide () -> void
  {
    gtk_widget_hide (gobj ());
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

  auto
  Widget::queue_draw () -> void
  {
    gtk_widget_queue_draw (gobj ());
  }

  auto
  Widget::queue_resize () -> void
  {
    gtk_widget_queue_resize (gobj ());
  }

  auto
  Widget::queue_allocate () -> void
  {
    gtk_widget_queue_allocate (gobj ());
  }

  auto
  Widget::size_allocate (const Allocation& allocation, int baseline) -> void
  {
    gtk_widget_size_allocate (gobj (), (allocation.gobj ()), baseline);
  }

  auto
  Widget::get_request_mode () const -> SizeRequestMode
  {
    return static_cast<SizeRequestMode> (
        gtk_widget_get_request_mode (const_cast<GtkWidget*> (gobj ())));
  }

  auto
  Widget::measure (Orientation orientation,
                   int for_size,
                   int& minimum,
                   int& natural,
                   int& minimum_baseline,
                   int& natural_baseline) const -> void
  {
    gtk_widget_measure (const_cast<GtkWidget*> (gobj ()),
                        static_cast<GtkOrientation> (orientation),
                        for_size,
                        &(minimum),
                        &(natural),
                        &(minimum_baseline),
                        &(natural_baseline));
  }

  auto
  Widget::get_preferred_size (Requisition& minimum_size,
                              Requisition& natural_size) const -> void
  {
    gtk_widget_get_preferred_size (const_cast<GtkWidget*> (gobj ()),
                                   (minimum_size).gobj (),
                                   (natural_size).gobj ());
  }

  auto
  Widget::get_layout_manager () -> glib::RefPtr<LayoutManager>
  {
    auto retvalue = glib::wrap (gtk_widget_get_layout_manager (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Widget::get_layout_manager () const -> glib::RefPtr<const LayoutManager>
  {
    return const_cast<Widget*> (this)->get_layout_manager ();
  }

  auto
  Widget::mnemonic_activate (bool group_cycling) -> bool
  {
    return gtk_widget_mnemonic_activate (gobj (),
                                         static_cast<int> (group_cycling));
  }

  auto
  Widget::activate () -> bool
  {
    return gtk_widget_activate (gobj ());
  }

  auto
  Widget::set_can_focus (bool can_focus) -> void
  {
    gtk_widget_set_can_focus (gobj (), static_cast<int> (can_focus));
  }

  auto
  Widget::get_can_focus () const -> bool
  {
    return gtk_widget_get_can_focus (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::set_focusable (bool focusable) -> void
  {
    gtk_widget_set_focusable (gobj (), static_cast<int> (focusable));
  }

  auto
  Widget::get_focusable () const -> bool
  {
    return gtk_widget_get_focusable (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::has_focus () const -> bool
  {
    return gtk_widget_has_focus (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::is_focus () const -> bool
  {
    return gtk_widget_is_focus (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::has_visible_focus () const -> bool
  {
    return gtk_widget_has_visible_focus (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::grab_focus () -> bool
  {
    return gtk_widget_grab_focus (gobj ());
  }

  auto
  Widget::set_focus_on_click (bool focus_on_click) -> void
  {
    gtk_widget_set_focus_on_click (gobj (), static_cast<int> (focus_on_click));
  }

  auto
  Widget::get_focus_on_click () const -> bool
  {
    return gtk_widget_get_focus_on_click (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::set_can_target (bool can_target) -> void
  {
    gtk_widget_set_can_target (gobj (), static_cast<int> (can_target));
  }

  auto
  Widget::get_can_target () const -> bool
  {
    return gtk_widget_get_can_target (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::has_default () const -> bool
  {
    return gtk_widget_has_default (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::set_receives_default (bool receives_default) -> void
  {
    gtk_widget_set_receives_default (gobj (),
                                     static_cast<int> (receives_default));
  }

  auto
  Widget::get_receives_default () const -> bool
  {
    return gtk_widget_get_receives_default (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::set_name (const glib::ustring& name) -> void
  {
    gtk_widget_set_name (gobj (), name.c_str ());
  }

  auto
  Widget::get_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_widget_get_name (const_cast<GtkWidget*> (gobj ())));
  }

  auto
  Widget::set_state_flags (StateFlags flags, bool clear) -> void
  {
    gtk_widget_set_state_flags (gobj (),
                                static_cast<GtkStateFlags> (flags),
                                static_cast<int> (clear));
  }

  auto
  Widget::unset_state_flags (StateFlags flags) -> void
  {
    gtk_widget_unset_state_flags (gobj (), static_cast<GtkStateFlags> (flags));
  }

  auto
  Widget::get_state_flags () const -> StateFlags
  {
    return static_cast<StateFlags> (
        gtk_widget_get_state_flags (const_cast<GtkWidget*> (gobj ())));
  }

  auto
  Widget::set_sensitive (bool sensitive) -> void
  {
    gtk_widget_set_sensitive (gobj (), static_cast<int> (sensitive));
  }

  auto
  Widget::get_sensitive () const -> bool
  {
    return gtk_widget_get_sensitive (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::is_sensitive () const -> bool
  {
    return gtk_widget_is_sensitive (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::set_visible (bool visible) -> void
  {
    gtk_widget_set_visible (gobj (), static_cast<int> (visible));
  }

  auto
  Widget::get_visible () const -> bool
  {
    return gtk_widget_get_visible (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::is_visible () const -> bool
  {
    return gtk_widget_is_visible (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::is_drawable () const -> bool
  {
    return gtk_widget_is_drawable (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::get_realized () const -> bool
  {
    return gtk_widget_get_realized (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::get_mapped () const -> bool
  {
    return gtk_widget_get_mapped (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::set_child_visible (bool visible) -> void
  {
    gtk_widget_set_child_visible (gobj (), static_cast<int> (visible));
  }

  auto
  Widget::get_child_visible () const -> bool
  {
    return gtk_widget_get_child_visible (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::get_allocated_width () const -> int
  {
    return gtk_widget_get_allocated_width (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::get_allocated_height () const -> int
  {
    return gtk_widget_get_allocated_height (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::get_allocated_baseline () const -> int
  {
    return gtk_widget_get_allocated_baseline (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::get_width () const -> int
  {
    return gtk_widget_get_width (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::get_height () const -> int
  {
    return gtk_widget_get_height (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::get_size (Orientation orientation) const -> int
  {
    return gtk_widget_get_size (const_cast<GtkWidget*> (gobj ()),
                                static_cast<GtkOrientation> (orientation));
  }

  auto
  Widget::get_parent () -> Widget*
  {
    return glib::wrap (gtk_widget_get_parent (gobj ()));
  }

  auto
  Widget::get_parent () const -> const Widget*
  {
    return const_cast<Widget*> (this)->get_parent ();
  }

  auto
  Widget::get_root () -> Root*
  {
    return dynamic_cast<Root*> (
        glib::wrap_auto ((GObject*) (gtk_widget_get_root (gobj ())), false));
  }

  auto
  Widget::get_root () const -> const Root*
  {
    return const_cast<Widget*> (this)->get_root ();
  }

  auto
  Widget::get_native () -> Native*
  {
    return dynamic_cast<Native*> (
        glib::wrap_auto ((GObject*) (gtk_widget_get_native (gobj ())), false));
  }

  auto
  Widget::get_native () const -> const Native*
  {
    return const_cast<Widget*> (this)->get_native ();
  }

  auto
  Widget::child_focus (DirectionType direction) -> bool
  {
    return gtk_widget_child_focus (gobj (),
                                   static_cast<GtkDirectionType> (direction));
  }

  auto
  Widget::keynav_failed (DirectionType direction) -> bool
  {
    return gtk_widget_keynav_failed (gobj (),
                                     static_cast<GtkDirectionType> (direction));
  }

  auto
  Widget::error_bell () -> void
  {
    gtk_widget_error_bell (gobj ());
  }

  auto
  Widget::set_size_request (int width, int height) -> void
  {
    gtk_widget_set_size_request (gobj (), width, height);
  }

  auto
  Widget::get_size_request (int& width, int& height) const -> void
  {
    gtk_widget_get_size_request (const_cast<GtkWidget*> (gobj ()),
                                 &(width),
                                 &(height));
  }

  auto
  Widget::set_opacity (double opacity) -> void
  {
    gtk_widget_set_opacity (gobj (), opacity);
  }

  auto
  Widget::get_opacity () const -> double
  {
    return gtk_widget_get_opacity (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::set_overflow (Overflow overflow) -> void
  {
    gtk_widget_set_overflow (gobj (), static_cast<GtkOverflow> (overflow));
  }

  auto
  Widget::get_overflow () const -> Overflow
  {
    return static_cast<Overflow> (
        gtk_widget_get_overflow (const_cast<GtkWidget*> (gobj ())));
  }

  auto
  Widget::get_ancestor (GType widget_type) -> Widget*
  {
    return glib::wrap (gtk_widget_get_ancestor (gobj (), widget_type));
  }

  auto
  Widget::get_ancestor (GType widget_type) const -> const Widget*
  {
    return const_cast<Widget*> (this)->get_ancestor (widget_type);
  }

  auto
  Widget::get_scale_factor () const -> int
  {
    return gtk_widget_get_scale_factor (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::get_display () -> glib::RefPtr<gdk::Display>
  {
    auto retvalue = glib::wrap (gtk_widget_get_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Widget::get_display () const -> glib::RefPtr<const gdk::Display>
  {
    return const_cast<Widget*> (this)->get_display ();
  }

  auto
  Widget::get_settings () -> glib::RefPtr<Settings>
  {
    auto retvalue = glib::wrap (gtk_widget_get_settings (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Widget::get_clipboard () -> glib::RefPtr<gdk::Clipboard>
  {
    auto retvalue = glib::wrap (gtk_widget_get_clipboard (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Widget::get_clipboard () const -> glib::RefPtr<const gdk::Clipboard>
  {
    return const_cast<Widget*> (this)->get_clipboard ();
  }

  auto
  Widget::get_primary_clipboard () -> glib::RefPtr<gdk::Clipboard>
  {
    auto retvalue = glib::wrap (gtk_widget_get_primary_clipboard (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Widget::get_primary_clipboard () const -> glib::RefPtr<const gdk::Clipboard>
  {
    return const_cast<Widget*> (this)->get_primary_clipboard ();
  }

  auto
  Widget::get_hexpand () const -> bool
  {
    return gtk_widget_get_hexpand (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::set_hexpand (bool expand) -> void
  {
    gtk_widget_set_hexpand (gobj (), static_cast<int> (expand));
  }

  auto
  Widget::get_hexpand_set () const -> bool
  {
    return gtk_widget_get_hexpand_set (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::set_hexpand_set (bool set) -> void
  {
    gtk_widget_set_hexpand_set (gobj (), static_cast<int> (set));
  }

  auto
  Widget::get_vexpand () const -> bool
  {
    return gtk_widget_get_vexpand (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::set_vexpand (bool expand) -> void
  {
    gtk_widget_set_vexpand (gobj (), static_cast<int> (expand));
  }

  auto
  Widget::get_vexpand_set () const -> bool
  {
    return gtk_widget_get_vexpand_set (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::set_vexpand_set (bool set) -> void
  {
    gtk_widget_set_vexpand_set (gobj (), static_cast<int> (set));
  }

  auto
  Widget::compute_expand (Orientation orientation) -> bool
  {
    return gtk_widget_compute_expand (
        gobj (),
        static_cast<GtkOrientation> (orientation));
  }

  auto
  Widget::get_halign () const -> Align
  {
    return static_cast<Align> (
        gtk_widget_get_halign (const_cast<GtkWidget*> (gobj ())));
  }

  auto
  Widget::set_halign (Align align) -> void
  {
    gtk_widget_set_halign (gobj (), static_cast<GtkAlign> (align));
  }

  auto
  Widget::get_valign () const -> Align
  {
    return static_cast<Align> (
        gtk_widget_get_valign (const_cast<GtkWidget*> (gobj ())));
  }

  auto
  Widget::set_valign (Align align) -> void
  {
    gtk_widget_set_valign (gobj (), static_cast<GtkAlign> (align));
  }

  auto
  Widget::get_margin_start () const -> int
  {
    return gtk_widget_get_margin_start (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::set_margin_start (int margin) -> void
  {
    gtk_widget_set_margin_start (gobj (), margin);
  }

  auto
  Widget::get_margin_end () const -> int
  {
    return gtk_widget_get_margin_end (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::set_margin_end (int margin) -> void
  {
    gtk_widget_set_margin_end (gobj (), margin);
  }

  auto
  Widget::get_margin_top () const -> int
  {
    return gtk_widget_get_margin_top (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::set_margin_top (int margin) -> void
  {
    gtk_widget_set_margin_top (gobj (), margin);
  }

  auto
  Widget::get_margin_bottom () const -> int
  {
    return gtk_widget_get_margin_bottom (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::set_margin_bottom (int margin) -> void
  {
    gtk_widget_set_margin_bottom (gobj (), margin);
  }

  auto
  Widget::is_ancestor (Widget& ancestor) const -> bool
  {
    return gtk_widget_is_ancestor (const_cast<GtkWidget*> (gobj ()),
                                   (ancestor).gobj ());
  }

  auto
  Widget::translate_coordinates (Widget& dest_widget,
                                 double src_x,
                                 double src_y,
                                 double& dest_x,
                                 double& dest_y) -> bool
  {
    return gtk_widget_translate_coordinates (gobj (),
                                             (dest_widget).gobj (),
                                             src_x,
                                             src_y,
                                             &(dest_x),
                                             &(dest_y));
  }

  auto
  Widget::contains (double x, double y) const -> bool
  {
    return gtk_widget_contains (const_cast<GtkWidget*> (gobj ()), x, y);
  }

  auto
  Widget::pick (double x, double y, PickFlags flags) -> Widget*
  {
    return glib::wrap (
        gtk_widget_pick (gobj (), x, y, static_cast<GtkPickFlags> (flags)));
  }

  auto
  Widget::pick (double x, double y, PickFlags flags) const -> const Widget*
  {
    return const_cast<Widget*> (this)->pick (x, y, flags);
  }

  auto
  Widget::remove_controller (const glib::RefPtr<EventController>& controller) -> void
  {
    gtk_widget_remove_controller (gobj (), glib::unwrap (controller));
  }

  auto
  Widget::create_pango_context () -> glib::RefPtr<pango::Context>
  {
    return glib::wrap (gtk_widget_create_pango_context (gobj ()));
  }

  auto
  Widget::get_pango_context () -> glib::RefPtr<pango::Context>
  {
    auto retvalue = glib::wrap (gtk_widget_get_pango_context (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Widget::set_font_options (const cairo::FontOptions& options) -> void
  {
    gtk_widget_set_font_options (gobj (), (options).cobj ());
  }

  auto
  Widget::get_font_options () const -> cairo::FontOptions
  {
    return cairo::FontOptions (
        const_cast<cairo_font_options_t*> (
            gtk_widget_get_font_options (const_cast<GtkWidget*> (gobj ()))),
        false);
  }

  auto
  Widget::create_pango_layout (const glib::ustring& text) -> glib::RefPtr<pango::Layout>
  {
    return glib::wrap (gtk_widget_create_pango_layout (gobj (), text.c_str ()));
  }

  auto
  Widget::set_direction (TextDirection dir) -> void
  {
    gtk_widget_set_direction (gobj (), static_cast<GtkTextDirection> (dir));
  }

  auto
  Widget::get_direction () const -> TextDirection
  {
    return static_cast<TextDirection> (
        gtk_widget_get_direction (const_cast<GtkWidget*> (gobj ())));
  }

  auto
  Widget::set_default_direction (TextDirection dir) -> void
  {
    gtk_widget_set_default_direction (static_cast<GtkTextDirection> (dir));
  }

  auto
  Widget::get_default_direction () -> TextDirection
  {
    return static_cast<TextDirection> (gtk_widget_get_default_direction ());
  }

  auto
  Widget::set_cursor (const glib::RefPtr<gdk::Cursor>& cursor) -> void
  {
    gtk_widget_set_cursor (gobj (), glib::unwrap (cursor));
  }

  auto
  Widget::set_cursor (const glib::ustring& name) -> void
  {
    gtk_widget_set_cursor_from_name (gobj (),
                                     name.empty () ? nullptr : name.c_str ());
  }

  auto
  Widget::get_cursor () -> glib::RefPtr<gdk::Cursor>
  {
    auto retvalue = glib::wrap (gtk_widget_get_cursor (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Widget::get_cursor () const -> glib::RefPtr<const gdk::Cursor>
  {
    return const_cast<Widget*> (this)->get_cursor ();
  }

  auto
  Widget::list_mnemonic_labels () -> std::vector<Widget*>
  {
    return glib::ListHandler<Widget*>::list_to_vector (
        gtk_widget_list_mnemonic_labels (gobj ()),
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  Widget::list_mnemonic_labels () const -> std::vector<const Widget*>
  {
    return glib::ListHandler<const Widget*>::list_to_vector (
        gtk_widget_list_mnemonic_labels (const_cast<GtkWidget*> (gobj ())),
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  Widget::add_mnemonic_label (Widget& label) -> void
  {
    gtk_widget_add_mnemonic_label (gobj (), (label).gobj ());
  }

  auto
  Widget::remove_mnemonic_label (Widget& label) -> void
  {
    gtk_widget_remove_mnemonic_label (gobj (), (label).gobj ());
  }

  auto
  Widget::drag_check_threshold (int start_x,
                                int start_y,
                                int current_x,
                                int current_y) -> bool
  {
    return gtk_drag_check_threshold (gobj (),
                                     start_x,
                                     start_y,
                                     current_x,
                                     current_y);
  }

  auto
  Widget::get_frame_clock () -> glib::RefPtr<gdk::FrameClock>
  {
    auto retvalue = glib::wrap (gtk_widget_get_frame_clock (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Widget::get_frame_clock () const -> glib::RefPtr<const gdk::FrameClock>
  {
    return const_cast<Widget*> (this)->get_frame_clock ();
  }

  auto
  Widget::set_parent (Widget& parent) -> void
  {
    gtk_widget_set_parent (gobj (), (parent).gobj ());
  }

  auto
  Widget::unparent () -> void
  {
    gtk_widget_unparent (gobj ());
  }

  auto
  Widget::map () -> void
  {
    gtk_widget_map (gobj ());
  }

  auto
  Widget::unmap () -> void
  {
    gtk_widget_unmap (gobj ());
  }

  auto
  Widget::trigger_tooltip_query () -> void
  {
    gtk_widget_trigger_tooltip_query (gobj ());
  }

  auto
  Widget::set_tooltip_text (const glib::ustring& text) -> void
  {
    gtk_widget_set_tooltip_text (gobj (), text.c_str ());
  }

  auto
  Widget::get_tooltip_text () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_widget_get_tooltip_text (const_cast<GtkWidget*> (gobj ())));
  }

  auto
  Widget::set_tooltip_markup (const glib::ustring& markup) -> void
  {
    gtk_widget_set_tooltip_markup (gobj (), markup.c_str ());
  }

  auto
  Widget::get_tooltip_markup () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_widget_get_tooltip_markup (const_cast<GtkWidget*> (gobj ())));
  }

  auto
  Widget::set_has_tooltip (bool has_tooltip) -> void
  {
    gtk_widget_set_has_tooltip (gobj (), static_cast<int> (has_tooltip));
  }

  auto
  Widget::get_has_tooltip () const -> bool
  {
    return gtk_widget_get_has_tooltip (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::in_destruction () const -> bool
  {
    return gtk_widget_in_destruction (const_cast<GtkWidget*> (gobj ()));
  }

#ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  Widget::get_style_context () -> glib::RefPtr<StyleContext>
  {
    auto retvalue = glib::wrap (gtk_widget_get_style_context (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

#ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  Widget::get_style_context () const -> glib::RefPtr<const StyleContext>
  {
    return const_cast<Widget*> (this)->get_style_context ();
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

  auto
  Widget::remove_tick_callback (guint id) -> void
  {
    gtk_widget_remove_tick_callback (gobj (), id);
  }

  auto
  Widget::insert_action_group (const glib::ustring& name,
                               const glib::RefPtr<gio::ActionGroup>& group) -> void
  {
    gtk_widget_insert_action_group (
        gobj (),
        name.c_str (),
        const_cast<GActionGroup*> (glib::unwrap<gio::ActionGroup> (group)));
  }

  auto
  Widget::activate_action (const glib::ustring& name,
                           const glib::VariantBase& args) -> bool
  {
    return gtk_widget_activate_action_variant (
        gobj (),
        name.c_str (),
        const_cast<GVariant*> ((args).gobj ()));
  }

  auto
  Widget::activate_default () -> void
  {
    gtk_widget_activate_default (gobj ());
  }

  auto
  Widget::set_font_map (const glib::RefPtr<pango::FontMap>& font_map) -> void
  {
    gtk_widget_set_font_map (gobj (), glib::unwrap (font_map));
  }

  auto
  Widget::get_font_map () -> glib::RefPtr<pango::FontMap>
  {
    auto retvalue = glib::wrap (gtk_widget_get_font_map (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Widget::get_font_map () const -> glib::RefPtr<const pango::FontMap>
  {
    return const_cast<Widget*> (this)->get_font_map ();
  }

  auto
  Widget::get_first_child () -> Widget*
  {
    return glib::wrap (gtk_widget_get_first_child (gobj ()));
  }

  auto
  Widget::get_first_child () const -> const Widget*
  {
    return const_cast<Widget*> (this)->get_first_child ();
  }

  auto
  Widget::get_last_child () -> Widget*
  {
    return glib::wrap (gtk_widget_get_last_child (gobj ()));
  }

  auto
  Widget::get_last_child () const -> const Widget*
  {
    return const_cast<Widget*> (this)->get_last_child ();
  }

  auto
  Widget::get_next_sibling () -> Widget*
  {
    return glib::wrap (gtk_widget_get_next_sibling (gobj ()));
  }

  auto
  Widget::get_next_sibling () const -> const Widget*
  {
    return const_cast<Widget*> (this)->get_next_sibling ();
  }

  auto
  Widget::get_prev_sibling () -> Widget*
  {
    return glib::wrap (gtk_widget_get_prev_sibling (gobj ()));
  }

  auto
  Widget::get_prev_sibling () const -> const Widget*
  {
    return const_cast<Widget*> (this)->get_prev_sibling ();
  }

  auto
  Widget::observe_children () -> glib::RefPtr<gio::ListModel>
  {
    return glib::wrap (gtk_widget_observe_children (gobj ()));
  }

  auto
  Widget::observe_children () const -> glib::RefPtr<const gio::ListModel>
  {
    return const_cast<Widget*> (this)->observe_children ();
  }

  auto
  Widget::observe_controllers () -> glib::RefPtr<gio::ListModel>
  {
    return glib::wrap (gtk_widget_observe_controllers (gobj ()));
  }

  auto
  Widget::observe_controllers () const -> glib::RefPtr<const gio::ListModel>
  {
    return const_cast<Widget*> (this)->observe_controllers ();
  }

  auto
  Widget::insert_after (Widget& parent, const Widget& previous_sibling) -> void
  {
    gtk_widget_insert_after (
        gobj (),
        (parent).gobj (),
        const_cast<GtkWidget*> ((previous_sibling).gobj ()));
  }

  auto
  Widget::insert_before (Widget& parent, const Widget& next_sibling) -> void
  {
    gtk_widget_insert_before (gobj (),
                              (parent).gobj (),
                              const_cast<GtkWidget*> ((next_sibling).gobj ()));
  }

  auto
  Widget::snapshot_child (Widget& child,
                          const glib::RefPtr<gtk::Snapshot>& snapshot) -> void
  {
    gtk_widget_snapshot_child (gobj (),
                               (child).gobj (),
                               glib::unwrap (snapshot));
  }

  auto
  Widget::should_layout () const -> bool
  {
    return gtk_widget_should_layout (const_cast<GtkWidget*> (gobj ()));
  }

  auto
  Widget::get_css_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_widget_get_css_name (const_cast<GtkWidget*> (gobj ())));
  }

  auto
  Widget::add_css_class (const glib::ustring& css_class) -> void
  {
    gtk_widget_add_css_class (gobj (), css_class.c_str ());
  }

  auto
  Widget::remove_css_class (const glib::ustring& css_class) -> void
  {
    gtk_widget_remove_css_class (gobj (), css_class.c_str ());
  }

  auto
  Widget::has_css_class (const glib::ustring& css_class) const -> bool
  {
    return gtk_widget_has_css_class (const_cast<GtkWidget*> (gobj ()),
                                     css_class.c_str ());
  }

  auto
  Widget::get_css_classes () const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
        gtk_widget_get_css_classes (const_cast<GtkWidget*> (gobj ())),
        glib::OWNERSHIP_DEEP);
  }

  auto
  Widget::set_css_classes (const std::vector<glib::ustring>& classes) -> void
  {
    gtk_widget_set_css_classes (
        gobj (),
        glib::ArrayHandler<glib::ustring>::vector_to_array (classes).data ());
  }

  Widget::Widget ()
    : glib::ObjectBase (nullptr),
      Object (glib::ConstructParams (widget_class_.init ()))
  {
  }

  auto
  Widget::realize () -> void
  {
    gtk_widget_realize (gobj ());
  }

  auto
  Widget::unrealize () -> void
  {
    gtk_widget_unrealize (gobj ());
  }

  auto
  Widget::set_focus_child (Widget& child) -> void
  {
    gtk_widget_set_focus_child (gobj (), (child).gobj ());
  }

  auto
  Widget::get_focus_child () -> Widget*
  {
    return glib::wrap (gtk_widget_get_focus_child (gobj ()));
  }

  auto
  Widget::get_focus_child () const -> const Widget*
  {
    return const_cast<Widget*> (this)->get_focus_child ();
  }

  auto
  Widget::signal_show () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &Widget_signal_show_info);
  }

  auto
  Widget::signal_hide () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &Widget_signal_hide_info);
  }

  auto
  Widget::signal_map () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &Widget_signal_map_info);
  }

  auto
  Widget::signal_unmap () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &Widget_signal_unmap_info);
  }

  auto
  Widget::signal_realize () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &Widget_signal_realize_info);
  }

  auto
  Widget::signal_unrealize () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &Widget_signal_unrealize_info);
  }

  auto
  Widget::signal_state_flags_changed () -> glib::SignalProxy<void (gtk::StateFlags)>
  {
    return glib::SignalProxy<void (gtk::StateFlags)> (
        this,
        &Widget_signal_state_flags_changed_info);
  }

  auto
  Widget::signal_direction_changed () -> glib::SignalProxy<void (TextDirection)>
  {
    return glib::SignalProxy<void (TextDirection)> (
        this,
        &Widget_signal_direction_changed_info);
  }

  auto
  Widget::signal_mnemonic_activate () -> glib::SignalProxy<bool (bool)>
  {
    return glib::SignalProxy<bool (bool)> (
        this,
        &Widget_signal_mnemonic_activate_info);
  }

  auto
  Widget::signal_destroy () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &Widget_signal_destroy_info);
  }

  auto
  Widget::signal_query_tooltip () -> glib::SignalProxy<bool (int, int, bool, const glib::RefPtr<Tooltip>&)>
  {
    return glib::SignalProxy<
        bool (int, int, bool, const glib::RefPtr<Tooltip>&)> (
        this,
        &Widget_signal_query_tooltip_info);
  }

  auto
  Widget::property_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "name");
  }

  auto
  Widget::property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "name");
  }

  auto
  Widget::property_parent () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "parent");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Root*>::value,
      "Type Root* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Widget::property_root () const -> glib::PropertyProxy_ReadOnly<Root*>
  {
    return glib::PropertyProxy_ReadOnly<Root*> (this, "root");
  }

  auto
  Widget::property_width_request () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "width-request");
  }

  auto
  Widget::property_width_request () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "width-request");
  }

  auto
  Widget::property_height_request () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "height-request");
  }

  auto
  Widget::property_height_request () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "height-request");
  }

  auto
  Widget::property_visible () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "visible");
  }

  auto
  Widget::property_visible () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "visible");
  }

  auto
  Widget::property_sensitive () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "sensitive");
  }

  auto
  Widget::property_sensitive () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "sensitive");
  }

  auto
  Widget::property_can_focus () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "can-focus");
  }

  auto
  Widget::property_can_focus () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "can-focus");
  }

  auto
  Widget::property_has_focus () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "has-focus");
  }

  auto
  Widget::property_can_target () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "can-target");
  }

  auto
  Widget::property_can_target () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "can-target");
  }

  auto
  Widget::property_focus_on_click () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "focus-on-click");
  }

  auto
  Widget::property_focus_on_click () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "focus-on-click");
  }

  auto
  Widget::property_focusable () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "focusable");
  }

  auto
  Widget::property_focusable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "focusable");
  }

  auto
  Widget::property_has_default () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "has-default");
  }

  auto
  Widget::property_receives_default () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "receives-default");
  }

  auto
  Widget::property_receives_default () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "receives-default");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gdk::Cursor>>::value,
      "Type glib::RefPtr<gdk::Cursor> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Widget::property_cursor () -> glib::PropertyProxy<glib::RefPtr<gdk::Cursor>>
  {
    return glib::PropertyProxy<glib::RefPtr<gdk::Cursor>> (this, "cursor");
  }

  auto
  Widget::property_cursor () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Cursor>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Cursor>> (this,
                                                                    "cursor");
  }

  auto
  Widget::property_has_tooltip () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "has-tooltip");
  }

  auto
  Widget::property_has_tooltip () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "has-tooltip");
  }

  auto
  Widget::property_tooltip_markup () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "tooltip-markup");
  }

  auto
  Widget::property_tooltip_markup () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "tooltip-markup");
  }

  auto
  Widget::property_tooltip_text () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "tooltip-text");
  }

  auto
  Widget::property_tooltip_text () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "tooltip-text");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Align>::value,
      "Type Align cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Widget::property_halign () -> glib::PropertyProxy<Align>
  {
    return glib::PropertyProxy<Align> (this, "halign");
  }

  auto
  Widget::property_halign () const -> glib::PropertyProxy_ReadOnly<Align>
  {
    return glib::PropertyProxy_ReadOnly<Align> (this, "halign");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Align>::value,
      "Type Align cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Widget::property_valign () -> glib::PropertyProxy<Align>
  {
    return glib::PropertyProxy<Align> (this, "valign");
  }

  auto
  Widget::property_valign () const -> glib::PropertyProxy_ReadOnly<Align>
  {
    return glib::PropertyProxy_ReadOnly<Align> (this, "valign");
  }

  auto
  Widget::property_margin_start () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "margin-start");
  }

  auto
  Widget::property_margin_start () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "margin-start");
  }

  auto
  Widget::property_margin_end () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "margin-end");
  }

  auto
  Widget::property_margin_end () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "margin-end");
  }

  auto
  Widget::property_margin_top () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "margin-top");
  }

  auto
  Widget::property_margin_top () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "margin-top");
  }

  auto
  Widget::property_margin_bottom () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "margin-bottom");
  }

  auto
  Widget::property_margin_bottom () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "margin-bottom");
  }

  auto
  Widget::property_hexpand () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "hexpand");
  }

  auto
  Widget::property_hexpand () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "hexpand");
  }

  auto
  Widget::property_hexpand_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "hexpand-set");
  }

  auto
  Widget::property_hexpand_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "hexpand-set");
  }

  auto
  Widget::property_vexpand () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "vexpand");
  }

  auto
  Widget::property_vexpand () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "vexpand");
  }

  auto
  Widget::property_vexpand_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "vexpand-set");
  }

  auto
  Widget::property_vexpand_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "vexpand-set");
  }

  auto
  Widget::property_opacity () -> glib::PropertyProxy<double>
  {
    return glib::PropertyProxy<double> (this, "opacity");
  }

  auto
  Widget::property_opacity () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return glib::PropertyProxy_ReadOnly<double> (this, "opacity");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Overflow>::value,
      "Type Overflow cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Widget::property_overflow () -> glib::PropertyProxy<Overflow>
  {
    return glib::PropertyProxy<Overflow> (this, "overflow");
  }

  auto
  Widget::property_overflow () const -> glib::PropertyProxy_ReadOnly<Overflow>
  {
    return glib::PropertyProxy_ReadOnly<Overflow> (this, "overflow");
  }

  auto
  Widget::property_scale_factor () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "scale-factor");
  }

  auto
  Widget::property_css_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "css-name");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          std::vector<glib::ustring>>::value,
      "Type std::vector<glib::ustring> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Widget::property_css_classes () -> glib::PropertyProxy<std::vector<glib::ustring>>
  {
    return glib::PropertyProxy<std::vector<glib::ustring>> (this,
                                                            "css-classes");
  }

  auto
  Widget::property_css_classes () const -> glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>>
  {
    return glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>> (
        this,
        "css-classes");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<LayoutManager>>::value,
      "Type glib::RefPtr<LayoutManager> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Widget::property_layout_manager () -> glib::PropertyProxy<glib::RefPtr<LayoutManager>>
  {
    return glib::PropertyProxy<glib::RefPtr<LayoutManager>> (this,
                                                             "layout-manager");
  }

  auto
  Widget::property_layout_manager () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<LayoutManager>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<LayoutManager>> (
        this,
        "layout-manager");
  }

  auto
  gtk::Widget::on_show () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->show)
      (*base->show) (gobj ());
  }

  auto
  gtk::Widget::on_hide () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->hide)
      (*base->hide) (gobj ());
  }

  auto
  gtk::Widget::on_map () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->map)
      (*base->map) (gobj ());
  }

  auto
  gtk::Widget::on_unmap () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->unmap)
      (*base->unmap) (gobj ());
  }

  auto
  gtk::Widget::on_realize () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->realize)
      (*base->realize) (gobj ());
  }

  auto
  gtk::Widget::on_unrealize () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->unrealize)
      (*base->unrealize) (gobj ());
  }

  auto
  gtk::Widget::on_state_flags_changed (gtk::StateFlags previous_state_flags) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->state_flags_changed)
      (*base->state_flags_changed) (
          gobj (),
          static_cast<GtkStateFlags> (previous_state_flags));
  }

  auto
  gtk::Widget::on_direction_changed (TextDirection direction) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->direction_changed)
      (*base->direction_changed) (gobj (),
                                  static_cast<GtkTextDirection> (direction));
  }

  auto
  gtk::Widget::on_mnemonic_activate (bool group_cycling) -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->mnemonic_activate)
      return (*base->mnemonic_activate) (gobj (),
                                         static_cast<int> (group_cycling));

    using RType = bool;
    return RType ();
  }

  auto
  gtk::Widget::on_query_tooltip (int x,
                                 int y,
                                 bool keyboard_tooltip,
                                 const glib::RefPtr<Tooltip>& tooltip) -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->query_tooltip)
      return (*base->query_tooltip) (gobj (),
                                     x,
                                     y,
                                     static_cast<int> (keyboard_tooltip),
                                     glib::unwrap (tooltip));

    using RType = bool;
    return RType ();
  }

  auto
  gtk::Widget::root_vfunc () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->root)
    {
      (*base->root) (gobj ());
    }
  }

  auto
  gtk::Widget::unroot_vfunc () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->unroot)
    {
      (*base->unroot) (gobj ());
    }
  }

  auto
  gtk::Widget::size_allocate_vfunc (int width, int height, int baseline) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->size_allocate)
    {
      (*base->size_allocate) (gobj (), width, height, baseline);
    }
  }

  auto
  gtk::Widget::get_request_mode_vfunc () const -> SizeRequestMode
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->get_request_mode)
    {
      SizeRequestMode retval (static_cast<SizeRequestMode> (
          (*base->get_request_mode) (const_cast<GtkWidget*> (gobj ()))));
      return retval;
    }

    using RType = SizeRequestMode;
    return RType ();
  }

  auto
  gtk::Widget::measure_vfunc (Orientation orientation,
                              int for_size,
                              int& minimum,
                              int& natural,
                              int& minimum_baseline,
                              int& natural_baseline) const -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->measure)
    {
      (*base->measure) (const_cast<GtkWidget*> (gobj ()),
                        static_cast<GtkOrientation> (orientation),
                        for_size,
                        &(minimum),
                        &(natural),
                        &(minimum_baseline),
                        &(natural_baseline));
    }
  }

  auto
  gtk::Widget::grab_focus_vfunc () -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->grab_focus)
    {
      bool retval ((*base->grab_focus) (gobj ()));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  gtk::Widget::set_focus_child_vfunc (Widget* child) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->set_focus_child)
    {
      (*base->set_focus_child) (gobj (), (GtkWidget*) glib::unwrap (child));
    }
  }

  auto
  gtk::Widget::contains_vfunc (double x, double y) const -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->contains)
    {
      bool retval ((*base->contains) (const_cast<GtkWidget*> (gobj ()), x, y));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  gtk::Widget::snapshot_vfunc (const glib::RefPtr<gtk::Snapshot>& snapshot) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->snapshot)
    {
      (*base->snapshot) (gobj (), glib::unwrap (snapshot));
    }
  }

} // namespace gtk
