// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/gesturepan.hxx>
#include <libmm/gtk/gesturepan_p.hxx>

#include <gtk/gtk.h>

namespace
{

  static auto
  GesturePan_signal_pan_callback (GtkGesturePan* self,
                                  GtkPanDirection p0,
                                  gdouble p1,
                                  void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (PanDirection, double)>;

    auto obj = dynamic_cast<GesturePan*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (static_cast<PanDirection> (p0), p1);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo GesturePan_signal_pan_info = {
      "pan",
      (GCallback) &GesturePan_signal_pan_callback,
      (GCallback) &GesturePan_signal_pan_callback};

} // namespace

auto
Glib::Value<Gtk::PanDirection>::value_type () -> GType
{
  return gtk_pan_direction_get_type ();
}

namespace Glib
{

  auto
  wrap (GtkGesturePan* object, bool take_copy) -> Glib::RefPtr<Gtk::GesturePan>
  {
    return Glib::make_refptr_for_instance<Gtk::GesturePan> (
        dynamic_cast<Gtk::GesturePan*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  GesturePan_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &GesturePan_Class::class_init_function;

      register_derived_type (gtk_gesture_pan_get_type ());
    }

    return *this;
  }

  auto
  GesturePan_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  GesturePan_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new GesturePan ((GtkGesturePan*) object);
  }

  auto
  GesturePan::gobj_copy () -> GtkGesturePan*
  {
    reference ();
    return gobj ();
  }

  GesturePan::GesturePan (const Glib::ConstructParams& construct_params)
    : GestureDrag (construct_params)
  {
  }

  GesturePan::GesturePan (GtkGesturePan* castitem)
    : GestureDrag ((GtkGestureDrag*) (castitem))
  {
  }

  GesturePan::GesturePan (GesturePan&& src) noexcept
    : GestureDrag (std::move (src))
  {
  }

  auto
  GesturePan::operator= (GesturePan&& src) noexcept -> GesturePan&
  {
    GestureDrag::operator= (std::move (src));
    return *this;
  }

  GesturePan::~GesturePan () noexcept {}

  GesturePan::CppClassType GesturePan::gesturepan_class_;

  auto
  GesturePan::get_type () -> GType
  {
    return gesturepan_class_.init ().get_type ();
  }

  auto
  GesturePan::get_base_type () -> GType
  {
    return gtk_gesture_pan_get_type ();
  }

  GesturePan::GesturePan ()
    : Glib::ObjectBase (nullptr),
      GestureDrag (Glib::ConstructParams (gesturepan_class_.init ()))
  {
  }

  GesturePan::GesturePan (Orientation orientation)
    : Glib::ObjectBase (nullptr),
      GestureDrag (
          Glib::ConstructParams (gesturepan_class_.init (),
                                 "orientation",
                                 static_cast<GtkOrientation> (orientation),
                                 nullptr))
  {
  }

  auto
  GesturePan::create (Orientation orientation) -> Glib::RefPtr<GesturePan>
  {
    return Glib::make_refptr_for_instance<GesturePan> (
        new GesturePan (orientation));
  }

  auto
  GesturePan::get_orientation () const -> Orientation
  {
    return static_cast<Orientation> (
        gtk_gesture_pan_get_orientation (const_cast<GtkGesturePan*> (gobj ())));
  }

  auto
  GesturePan::set_orientation (Orientation orientation) -> void
  {
    gtk_gesture_pan_set_orientation (gobj (),
                                     static_cast<GtkOrientation> (orientation));
  }

  auto
  GesturePan::signal_pan () -> Glib::SignalProxy<void (PanDirection, double)>
  {
    return Glib::SignalProxy<void (PanDirection, double)> (
        this,
        &GesturePan_signal_pan_info);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Orientation>::value,
      "Type Orientation cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  GesturePan::property_orientation () -> Glib::PropertyProxy<Orientation>
  {
    return Glib::PropertyProxy<Orientation> (this, "orientation");
  }

  auto
  GesturePan::property_orientation () const -> Glib::PropertyProxy_ReadOnly<Orientation>
  {
    return Glib::PropertyProxy_ReadOnly<Orientation> (this, "orientation");
  }

} // namespace Gtk
