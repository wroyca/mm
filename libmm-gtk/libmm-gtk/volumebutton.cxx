// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/volumebutton.hxx>
#include <libmm-gtk/volumebutton_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkVolumeButton* object, bool take_copy) -> Gtk::VolumeButton*
  {
    return dynamic_cast<Gtk::VolumeButton*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  VolumeButton_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &VolumeButton_Class::class_init_function;

      register_derived_type (gtk_volume_button_get_type ());
    }

    return *this;
  }

  auto
  VolumeButton_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  VolumeButton_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new VolumeButton ((GtkVolumeButton*) (o)));
  }

  VolumeButton::VolumeButton (const Glib::ConstructParams& construct_params)
    : Gtk::ScaleButton (construct_params)
  {
  }

  VolumeButton::VolumeButton (GtkVolumeButton* castitem)
    : Gtk::ScaleButton ((GtkScaleButton*) (castitem))
  {
  }

  VolumeButton::VolumeButton (VolumeButton&& src) noexcept
    : Gtk::ScaleButton (std::move (src))
  {
  }

  auto
  VolumeButton::operator= (VolumeButton&& src) noexcept -> VolumeButton&
  {
    Gtk::ScaleButton::operator= (std::move (src));
    return *this;
  }

  VolumeButton::~VolumeButton () noexcept
  {
    destroy_ ();
  }

  VolumeButton::CppClassType VolumeButton::volumebutton_class_;

  auto
  VolumeButton::get_type () -> GType
  {
    return volumebutton_class_.init ().get_type ();
  }

  auto
  VolumeButton::get_base_type () -> GType
  {
    return gtk_volume_button_get_type ();
  }

  VolumeButton::VolumeButton ()
    : Glib::ObjectBase (nullptr),
      Gtk::ScaleButton (Glib::ConstructParams (volumebutton_class_.init ()))
  {
  }

  auto
  VolumeButton::property_use_symbolic () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "use-symbolic");
  }

  auto
  VolumeButton::property_use_symbolic () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "use-symbolic");
  }

} // namespace Gtk
