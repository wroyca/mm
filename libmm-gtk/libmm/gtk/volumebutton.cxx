// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/volumebutton.hxx>
#include <libmm/gtk/volumebutton_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

}

namespace
{
}

namespace glib
{

  auto
  wrap (GtkVolumeButton* object, bool take_copy) -> gtk::VolumeButton*
  {
    return dynamic_cast<gtk::VolumeButton*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  VolumeButton_Class::init () -> const glib::Class&
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
  VolumeButton_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new VolumeButton ((GtkVolumeButton*) (o)));
  }

  VolumeButton::VolumeButton (const glib::ConstructParams& construct_params)
    : gtk::ScaleButton (construct_params)
  {
  }

  VolumeButton::VolumeButton (GtkVolumeButton* castitem)
    : gtk::ScaleButton ((GtkScaleButton*) (castitem))
  {
  }

  VolumeButton::VolumeButton (VolumeButton&& src) noexcept
    : gtk::ScaleButton (std::move (src))
  {
  }

  auto
  VolumeButton::operator= (VolumeButton&& src) noexcept -> VolumeButton&
  {
    gtk::ScaleButton::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::ScaleButton (glib::ConstructParams (volumebutton_class_.init ()))
  {
  }

  auto
  VolumeButton::property_use_symbolic () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "use-symbolic");
  }

  auto
  VolumeButton::property_use_symbolic () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "use-symbolic");
  }

} // namespace gtk
