// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/overlay.hxx>
#include <libmm/gtk/overlay_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  auto
  Overlay::unset_child () -> void
  {
    gtk_overlay_set_child (gobj (), nullptr);
  }

} // namespace gtk

namespace
{

  static auto
  Overlay_signal_get_child_position_callback (GtkOverlay* self,
                                              GtkWidget* p0,
                                              GdkRectangle* p1,
                                              void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<bool (gtk::Widget*, gdk::Rectangle&)>;

    auto obj = dynamic_cast<Overlay*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> ((*static_cast<SlotType*> (
              slot)) (glib::wrap (p0), glib::wrap (p1)));
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
  Overlay_signal_get_child_position_notify_callback (GtkOverlay* self,
                                                     GtkWidget* p0,
                                                     GdkRectangle* p1,
                                                     void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (gtk::Widget*, gdk::Rectangle&)>;

    auto obj = dynamic_cast<Overlay*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0), glib::wrap (p1));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const glib::SignalProxyInfo Overlay_signal_get_child_position_info = {
      "get-child-position",
      (GCallback) &Overlay_signal_get_child_position_callback,
      (GCallback) &Overlay_signal_get_child_position_notify_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkOverlay* object, bool take_copy) -> gtk::Overlay*
  {
    return dynamic_cast<gtk::Overlay*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  Overlay_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Overlay_Class::class_init_function;

      register_derived_type (gtk_overlay_get_type ());
    }

    return *this;
  }

  auto
  Overlay_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Overlay_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Overlay ((GtkOverlay*) (o)));
  }

  Overlay::Overlay (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Overlay::Overlay (GtkOverlay* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Overlay::Overlay (Overlay&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  Overlay::operator= (Overlay&& src) noexcept -> Overlay&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  Overlay::~Overlay () noexcept
  {
    destroy_ ();
  }

  Overlay::CppClassType Overlay::overlay_class_;

  auto
  Overlay::get_type () -> GType
  {
    return overlay_class_.init ().get_type ();
  }

  auto
  Overlay::get_base_type () -> GType
  {
    return gtk_overlay_get_type ();
  }

  Overlay::Overlay ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (overlay_class_.init ()))
  {
  }

  auto
  Overlay::add_overlay (gtk::Widget& widget) -> void
  {
    gtk_overlay_add_overlay (gobj (), (widget).gobj ());
  }

  auto
  Overlay::remove_overlay (gtk::Widget& widget) -> void
  {
    gtk_overlay_remove_overlay (gobj (), (widget).gobj ());
  }

  auto
  Overlay::set_child (Widget& child) -> void
  {
    gtk_overlay_set_child (gobj (), (child).gobj ());
  }

  auto
  Overlay::get_child () -> Widget*
  {
    return glib::wrap (gtk_overlay_get_child (gobj ()));
  }

  auto
  Overlay::get_child () const -> const Widget*
  {
    return const_cast<Overlay*> (this)->get_child ();
  }

  auto
  Overlay::get_measure_overlay (Widget& widget) const -> bool
  {
    return gtk_overlay_get_measure_overlay (const_cast<GtkOverlay*> (gobj ()),
                                            (widget).gobj ());
  }

  auto
  Overlay::set_measure_overlay (Widget& widget, bool measure) -> void
  {
    gtk_overlay_set_measure_overlay (gobj (),
                                     (widget).gobj (),
                                     static_cast<int> (measure));
  }

  auto
  Overlay::get_clip_overlay (const Widget& widget) const -> bool
  {
    return gtk_overlay_get_clip_overlay (
        const_cast<GtkOverlay*> (gobj ()),
        const_cast<GtkWidget*> ((widget).gobj ()));
  }

  auto
  Overlay::set_clip_overlay (const Widget& widget, bool clip_overlay) -> void
  {
    gtk_overlay_set_clip_overlay (gobj (),
                                  const_cast<GtkWidget*> ((widget).gobj ()),
                                  static_cast<int> (clip_overlay));
  }

  auto
  Overlay::signal_get_child_position () -> glib::SignalProxy<bool (gtk::Widget*, gdk::Rectangle&)>
  {
    return glib::SignalProxy<bool (gtk::Widget*, gdk::Rectangle&)> (
        this,
        &Overlay_signal_get_child_position_info);
  }

  auto
  Overlay::property_child () -> glib::PropertyProxy<Widget*>
  {
    return glib::PropertyProxy<Widget*> (this, "child");
  }

  auto
  Overlay::property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "child");
  }

} // namespace gtk
