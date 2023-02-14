// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/gesturesingle.hxx>
#include <libmm-gtk/gesturesingle_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkGestureSingle* object, const bool take_copy) -> RefPtr<Gtk::GestureSingle>
  {
    return Glib::make_refptr_for_instance<Gtk::GestureSingle> (
        dynamic_cast<Gtk::GestureSingle*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  GestureSingle_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &GestureSingle_Class::class_init_function;

      register_derived_type (gtk_gesture_single_get_type ());
    }

    return *this;
  }

  auto
  GestureSingle_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  GestureSingle_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new GestureSingle ((GtkGestureSingle*) object);
  }

  auto
  GestureSingle::gobj_copy () -> GtkGestureSingle*
  {
    reference ();
    return gobj ();
  }

  GestureSingle::GestureSingle (const Glib::ConstructParams& construct_params)
    : Gesture (construct_params)
  {
  }

  GestureSingle::GestureSingle (GtkGestureSingle* castitem)
    : Gesture ((GtkGesture*) castitem)
  {
  }

  GestureSingle::GestureSingle (GestureSingle&& src) noexcept
    : Gesture (std::move (src))
  {
  }

  auto
  GestureSingle::operator= (GestureSingle&& src) noexcept -> GestureSingle&
  {
    Gesture::operator= (std::move (src));
    return *this;
  }

  GestureSingle::~GestureSingle () noexcept = default;

  GestureSingle::CppClassType GestureSingle::gesturesingle_class_;

  auto
  GestureSingle::get_type () -> GType
  {
    return gesturesingle_class_.init ().get_type ();
  }

  auto
  GestureSingle::get_base_type () -> GType
  {
    return gtk_gesture_single_get_type ();
  }

  GestureSingle::GestureSingle ()
    : ObjectBase (nullptr),
      Gesture (Glib::ConstructParams (gesturesingle_class_.init ()))
  {
  }

  auto
  GestureSingle::get_touch_only () const -> bool
  {
    return gtk_gesture_single_get_touch_only (
        const_cast<GtkGestureSingle*> (gobj ()));
  }

  auto
  GestureSingle::set_touch_only (const bool touch_only) -> void
  {
    gtk_gesture_single_set_touch_only (gobj (), touch_only);
  }

  auto
  GestureSingle::get_exclusive () const -> bool
  {
    return gtk_gesture_single_get_exclusive (
        const_cast<GtkGestureSingle*> (gobj ()));
  }

  auto
  GestureSingle::set_exclusive (const bool exclusive) const -> void
  {
    gtk_gesture_single_set_exclusive (const_cast<GtkGestureSingle*> (gobj ()),
                                      exclusive);
  }

  auto
  GestureSingle::get_button () const -> unsigned int
  {
    return gtk_gesture_single_get_button (
        const_cast<GtkGestureSingle*> (gobj ()));
  }

  auto
  GestureSingle::set_button (const unsigned int button) -> void
  {
    gtk_gesture_single_set_button (gobj (), button);
  }

  auto
  GestureSingle::get_current_button () const -> unsigned int
  {
    return gtk_gesture_single_get_current_button (
        const_cast<GtkGestureSingle*> (gobj ()));
  }

  auto
  GestureSingle::get_current_sequence () -> Gdk::EventSequence*
  {
    return reinterpret_cast<Gdk::EventSequence*> (
        gtk_gesture_single_get_current_sequence (gobj ()));
  }

  auto
  GestureSingle::get_current_sequence () const -> const Gdk::EventSequence*
  {
    return const_cast<GestureSingle*> (this)->get_current_sequence ();
  }

  auto
  GestureSingle::property_touch_only () -> Glib::PropertyProxy<bool>
  {
    return {this, "touch-only"};
  }

  auto
  GestureSingle::property_touch_only () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "touch-only"};
  }

  auto
  GestureSingle::property_exclusive () -> Glib::PropertyProxy<bool>
  {
    return {this, "exclusive"};
  }

  auto
  GestureSingle::property_exclusive () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "exclusive"};
  }

  auto
  GestureSingle::property_button () -> Glib::PropertyProxy<unsigned int>
  {
    return {this, "button"};
  }

  auto
  GestureSingle::property_button () const -> Glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return {this, "button"};
  }

} // namespace Gtk
