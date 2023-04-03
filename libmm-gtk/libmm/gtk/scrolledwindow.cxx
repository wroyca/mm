// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/scrolledwindow.hxx>
#include <libmm/gtk/scrolledwindow_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gtk/adjustment.hxx>
#include <libmm/gtk/scrollbar.hxx>

namespace Gtk
{

  auto
  ScrolledWindow::unset_child () -> void
  {
    gtk_scrolled_window_set_child (gobj (), nullptr);
  }

} // namespace Gtk

namespace
{

  static auto
  ScrolledWindow_signal_edge_overshot_callback (GtkScrolledWindow* self,
                                                GtkPositionType p0,
                                                void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (Gtk::PositionType)>;

    auto obj = dynamic_cast<ScrolledWindow*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              static_cast<Gtk::PositionType> (p0));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo ScrolledWindow_signal_edge_overshot_info =
      {"edge-overshot",
       (GCallback) &ScrolledWindow_signal_edge_overshot_callback,
       (GCallback) &ScrolledWindow_signal_edge_overshot_callback};

  static auto
  ScrolledWindow_signal_edge_reached_callback (GtkScrolledWindow* self,
                                               GtkPositionType p0,
                                               void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (Gtk::PositionType)>;

    auto obj = dynamic_cast<ScrolledWindow*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              static_cast<Gtk::PositionType> (p0));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo ScrolledWindow_signal_edge_reached_info = {
      "edge-reached",
      (GCallback) &ScrolledWindow_signal_edge_reached_callback,
      (GCallback) &ScrolledWindow_signal_edge_reached_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkScrolledWindow* object, bool take_copy) -> Gtk::ScrolledWindow*
  {
    return dynamic_cast<Gtk::ScrolledWindow*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ScrolledWindow_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ScrolledWindow_Class::class_init_function;

      register_derived_type (gtk_scrolled_window_get_type ());
    }

    return *this;
  }

  auto
  ScrolledWindow_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ScrolledWindow_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new ScrolledWindow ((GtkScrolledWindow*) (o)));
  }

  ScrolledWindow::ScrolledWindow (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  ScrolledWindow::ScrolledWindow (GtkScrolledWindow* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  ScrolledWindow::ScrolledWindow (ScrolledWindow&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  ScrolledWindow::operator= (ScrolledWindow&& src) noexcept -> ScrolledWindow&
  {
    Gtk::Widget::operator= (std::move (src));
    return *this;
  }

  ScrolledWindow::~ScrolledWindow () noexcept
  {
    destroy_ ();
  }

  ScrolledWindow::CppClassType ScrolledWindow::scrolledwindow_class_;

  auto
  ScrolledWindow::get_type () -> GType
  {
    return scrolledwindow_class_.init ().get_type ();
  }

  auto
  ScrolledWindow::get_base_type () -> GType
  {
    return gtk_scrolled_window_get_type ();
  }

  ScrolledWindow::ScrolledWindow ()
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (scrolledwindow_class_.init ()))
  {
  }

  auto
  ScrolledWindow::set_hadjustment (const Glib::RefPtr<Adjustment>& hadjustment) -> void
  {
    gtk_scrolled_window_set_hadjustment (gobj (), Glib::unwrap (hadjustment));
  }

  auto
  ScrolledWindow::set_vadjustment (const Glib::RefPtr<Adjustment>& vadjustment) -> void
  {
    gtk_scrolled_window_set_vadjustment (gobj (), Glib::unwrap (vadjustment));
  }

  auto
  ScrolledWindow::get_hadjustment () -> Glib::RefPtr<Adjustment>
  {
    auto retvalue = Glib::wrap (gtk_scrolled_window_get_hadjustment (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ScrolledWindow::get_hadjustment () const -> Glib::RefPtr<const Adjustment>
  {
    return const_cast<ScrolledWindow*> (this)->get_hadjustment ();
  }

  auto
  ScrolledWindow::get_vadjustment () -> Glib::RefPtr<Adjustment>
  {
    auto retvalue = Glib::wrap (gtk_scrolled_window_get_vadjustment (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ScrolledWindow::get_vadjustment () const -> Glib::RefPtr<const Adjustment>
  {
    return const_cast<ScrolledWindow*> (this)->get_vadjustment ();
  }

  auto
  ScrolledWindow::set_policy (PolicyType hscrollbar_policy,
                              PolicyType vscrollbar_policy) -> void
  {
    gtk_scrolled_window_set_policy (
        gobj (),
        static_cast<GtkPolicyType> (hscrollbar_policy),
        static_cast<GtkPolicyType> (vscrollbar_policy));
  }

  auto
  ScrolledWindow::get_policy (PolicyType& hscrollbar_policy,
                              PolicyType& vscrollbar_policy) const -> void
  {
    gtk_scrolled_window_get_policy (const_cast<GtkScrolledWindow*> (gobj ()),
                                    ((GtkPolicyType*) &(hscrollbar_policy)),
                                    ((GtkPolicyType*) &(vscrollbar_policy)));
  }

  auto
  ScrolledWindow::set_placement (CornerType window_placement) -> void
  {
    gtk_scrolled_window_set_placement (
        gobj (),
        static_cast<GtkCornerType> (window_placement));
  }

  auto
  ScrolledWindow::unset_placement () -> void
  {
    gtk_scrolled_window_unset_placement (gobj ());
  }

  auto
  ScrolledWindow::get_placement () const -> CornerType
  {
    return static_cast<CornerType> (gtk_scrolled_window_get_placement (
        const_cast<GtkScrolledWindow*> (gobj ())));
  }

  auto
  ScrolledWindow::set_has_frame (bool has_frame) -> void
  {
    gtk_scrolled_window_set_has_frame (gobj (), static_cast<int> (has_frame));
  }

  auto
  ScrolledWindow::get_has_frame () const -> bool
  {
    return gtk_scrolled_window_get_has_frame (
        const_cast<GtkScrolledWindow*> (gobj ()));
  }

  auto
  ScrolledWindow::get_vscrollbar () -> Scrollbar*
  {
    return Glib::wrap (
        (GtkScrollbar*) gtk_scrolled_window_get_vscrollbar (gobj ()));
  }

  auto
  ScrolledWindow::get_vscrollbar () const -> const Scrollbar*
  {
    return Glib::wrap ((GtkScrollbar*) gtk_scrolled_window_get_vscrollbar (
        const_cast<GtkScrolledWindow*> (gobj ())));
  }

  auto
  ScrolledWindow::get_hscrollbar () -> Scrollbar*
  {
    return Glib::wrap (
        (GtkScrollbar*) gtk_scrolled_window_get_hscrollbar (gobj ()));
  }

  auto
  ScrolledWindow::get_hscrollbar () const -> const Scrollbar*
  {
    return Glib::wrap ((GtkScrollbar*) gtk_scrolled_window_get_hscrollbar (
        const_cast<GtkScrolledWindow*> (gobj ())));
  }

  auto
  ScrolledWindow::get_min_content_width () const -> int
  {
    return gtk_scrolled_window_get_min_content_width (
        const_cast<GtkScrolledWindow*> (gobj ()));
  }

  auto
  ScrolledWindow::set_min_content_width (int width) -> void
  {
    gtk_scrolled_window_set_min_content_width (gobj (), width);
  }

  auto
  ScrolledWindow::get_min_content_height () const -> int
  {
    return gtk_scrolled_window_get_min_content_height (
        const_cast<GtkScrolledWindow*> (gobj ()));
  }

  auto
  ScrolledWindow::set_min_content_height (int height) -> void
  {
    gtk_scrolled_window_set_min_content_height (gobj (), height);
  }

  auto
  ScrolledWindow::set_kinetic_scrolling (bool kinetic_scrolling) -> void
  {
    gtk_scrolled_window_set_kinetic_scrolling (
        gobj (),
        static_cast<int> (kinetic_scrolling));
  }

  auto
  ScrolledWindow::get_kinetic_scrolling () const -> bool
  {
    return gtk_scrolled_window_get_kinetic_scrolling (
        const_cast<GtkScrolledWindow*> (gobj ()));
  }

  auto
  ScrolledWindow::set_overlay_scrolling (bool overlay_scrolling) -> void
  {
    gtk_scrolled_window_set_overlay_scrolling (
        gobj (),
        static_cast<int> (overlay_scrolling));
  }

  auto
  ScrolledWindow::get_overlay_scrolling () const -> bool
  {
    return gtk_scrolled_window_get_overlay_scrolling (
        const_cast<GtkScrolledWindow*> (gobj ()));
  }

  auto
  ScrolledWindow::set_max_content_width (int width) -> void
  {
    gtk_scrolled_window_set_max_content_width (gobj (), width);
  }

  auto
  ScrolledWindow::get_max_content_width () const -> int
  {
    return gtk_scrolled_window_get_max_content_width (
        const_cast<GtkScrolledWindow*> (gobj ()));
  }

  auto
  ScrolledWindow::set_max_content_height (int height) -> void
  {
    gtk_scrolled_window_set_max_content_height (gobj (), height);
  }

  auto
  ScrolledWindow::get_max_content_height () const -> int
  {
    return gtk_scrolled_window_get_max_content_height (
        const_cast<GtkScrolledWindow*> (gobj ()));
  }

  auto
  ScrolledWindow::set_propagate_natural_width (bool propagate) -> void
  {
    gtk_scrolled_window_set_propagate_natural_width (
        gobj (),
        static_cast<int> (propagate));
  }

  auto
  ScrolledWindow::get_propagate_natural_width () const -> bool
  {
    return gtk_scrolled_window_get_propagate_natural_width (
        const_cast<GtkScrolledWindow*> (gobj ()));
  }

  auto
  ScrolledWindow::set_propagate_natural_height (bool propagate) -> void
  {
    gtk_scrolled_window_set_propagate_natural_height (
        gobj (),
        static_cast<int> (propagate));
  }

  auto
  ScrolledWindow::get_propagate_natural_height () const -> bool
  {
    return gtk_scrolled_window_get_propagate_natural_height (
        const_cast<GtkScrolledWindow*> (gobj ()));
  }

  auto
  ScrolledWindow::set_child (Widget& child) -> void
  {
    gtk_scrolled_window_set_child (gobj (), (child).gobj ());
  }

  auto
  ScrolledWindow::get_child () -> Widget*
  {
    return Glib::wrap (gtk_scrolled_window_get_child (gobj ()));
  }

  auto
  ScrolledWindow::get_child () const -> const Widget*
  {
    return const_cast<ScrolledWindow*> (this)->get_child ();
  }

  auto
  ScrolledWindow::signal_edge_overshot () -> Glib::SignalProxy<void (Gtk::PositionType)>
  {
    return Glib::SignalProxy<void (Gtk::PositionType)> (
        this,
        &ScrolledWindow_signal_edge_overshot_info);
  }

  auto
  ScrolledWindow::signal_edge_reached () -> Glib::SignalProxy<void (Gtk::PositionType)>
  {
    return Glib::SignalProxy<void (Gtk::PositionType)> (
        this,
        &ScrolledWindow_signal_edge_reached_info);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Adjustment>>::value,
      "Type Glib::RefPtr<Adjustment> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ScrolledWindow::property_hadjustment () -> Glib::PropertyProxy<Glib::RefPtr<Adjustment>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Adjustment>> (this, "hadjustment");
  }

  auto
  ScrolledWindow::property_hadjustment () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Adjustment>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Adjustment>> (
        this,
        "hadjustment");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Adjustment>>::value,
      "Type Glib::RefPtr<Adjustment> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ScrolledWindow::property_vadjustment () -> Glib::PropertyProxy<Glib::RefPtr<Adjustment>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Adjustment>> (this, "vadjustment");
  }

  auto
  ScrolledWindow::property_vadjustment () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Adjustment>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Adjustment>> (
        this,
        "vadjustment");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<PolicyType>::value,
      "Type PolicyType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ScrolledWindow::property_hscrollbar_policy () -> Glib::PropertyProxy<PolicyType>
  {
    return Glib::PropertyProxy<PolicyType> (this, "hscrollbar-policy");
  }

  auto
  ScrolledWindow::property_hscrollbar_policy () const -> Glib::PropertyProxy_ReadOnly<PolicyType>
  {
    return Glib::PropertyProxy_ReadOnly<PolicyType> (this, "hscrollbar-policy");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<PolicyType>::value,
      "Type PolicyType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ScrolledWindow::property_vscrollbar_policy () -> Glib::PropertyProxy<PolicyType>
  {
    return Glib::PropertyProxy<PolicyType> (this, "vscrollbar-policy");
  }

  auto
  ScrolledWindow::property_vscrollbar_policy () const -> Glib::PropertyProxy_ReadOnly<PolicyType>
  {
    return Glib::PropertyProxy_ReadOnly<PolicyType> (this, "vscrollbar-policy");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<CornerType>::value,
      "Type CornerType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ScrolledWindow::property_window_placement () -> Glib::PropertyProxy<CornerType>
  {
    return Glib::PropertyProxy<CornerType> (this, "window-placement");
  }

  auto
  ScrolledWindow::property_window_placement () const -> Glib::PropertyProxy_ReadOnly<CornerType>
  {
    return Glib::PropertyProxy_ReadOnly<CornerType> (this, "window-placement");
  }

  auto
  ScrolledWindow::property_has_frame () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "has-frame");
  }

  auto
  ScrolledWindow::property_has_frame () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "has-frame");
  }

  auto
  ScrolledWindow::property_min_content_width () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "min-content-width");
  }

  auto
  ScrolledWindow::property_min_content_width () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "min-content-width");
  }

  auto
  ScrolledWindow::property_min_content_height () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "min-content-height");
  }

  auto
  ScrolledWindow::property_min_content_height () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "min-content-height");
  }

  auto
  ScrolledWindow::property_kinetic_scrolling () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "kinetic-scrolling");
  }

  auto
  ScrolledWindow::property_kinetic_scrolling () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "kinetic-scrolling");
  }

  auto
  ScrolledWindow::property_overlay_scrolling () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "overlay-scrolling");
  }

  auto
  ScrolledWindow::property_overlay_scrolling () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "overlay-scrolling");
  }

  auto
  ScrolledWindow::property_max_content_width () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "max-content-width");
  }

  auto
  ScrolledWindow::property_max_content_width () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "max-content-width");
  }

  auto
  ScrolledWindow::property_max_content_height () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "max-content-height");
  }

  auto
  ScrolledWindow::property_max_content_height () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "max-content-height");
  }

  auto
  ScrolledWindow::property_propagate_natural_width () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "propagate-natural-width");
  }

  auto
  ScrolledWindow::property_propagate_natural_width () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "propagate-natural-width");
  }

  auto
  ScrolledWindow::property_propagate_natural_height () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "propagate-natural-height");
  }

  auto
  ScrolledWindow::property_propagate_natural_height () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this,
                                               "propagate-natural-height");
  }

  auto
  ScrolledWindow::property_child () -> Glib::PropertyProxy<Widget*>
  {
    return Glib::PropertyProxy<Widget*> (this, "child");
  }

  auto
  ScrolledWindow::property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Widget*> (this, "child");
  }

} // namespace Gtk