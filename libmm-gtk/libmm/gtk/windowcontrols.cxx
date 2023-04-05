// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/windowcontrols.hxx>
#include <libmm/gtk/windowcontrols_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  auto
  WindowControls::unset_decoration_layout () -> void
  {
    gtk_window_controls_set_decoration_layout (gobj (), nullptr);
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkWindowControls* object, bool take_copy) -> gtk::WindowControls*
  {
    return dynamic_cast<gtk::WindowControls*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  WindowControls_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &WindowControls_Class::class_init_function;

      gtype_ = gtk_window_controls_get_type ();
    }

    return *this;
  }

  auto
  WindowControls_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  WindowControls_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new WindowControls ((GtkWindowControls*) (o)));
  }

  WindowControls::WindowControls (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  WindowControls::WindowControls (GtkWindowControls* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  WindowControls::WindowControls (WindowControls&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  WindowControls::operator= (WindowControls&& src) noexcept -> WindowControls&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  WindowControls::~WindowControls () noexcept
  {
    destroy_ ();
  }

  WindowControls::CppClassType WindowControls::windowcontrols_class_;

  auto
  WindowControls::get_type () -> GType
  {
    return windowcontrols_class_.init ().get_type ();
  }

  auto
  WindowControls::get_base_type () -> GType
  {
    return gtk_window_controls_get_type ();
  }

  WindowControls::WindowControls (PackType side)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (windowcontrols_class_.init (),
                                          "side",
                                          static_cast<GtkPackType> (side),
                                          nullptr))
  {
  }

  auto
  WindowControls::set_side (PackType side) -> void
  {
    gtk_window_controls_set_side (gobj (), static_cast<GtkPackType> (side));
  }

  auto
  WindowControls::get_side () const -> PackType
  {
    return static_cast<PackType> (gtk_window_controls_get_side (
        const_cast<GtkWindowControls*> (gobj ())));
  }

  auto
  WindowControls::set_decoration_layout (const glib::ustring& layout) -> void
  {
    gtk_window_controls_set_decoration_layout (gobj (), layout.c_str ());
  }

  auto
  WindowControls::get_decoration_layout () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_window_controls_get_decoration_layout (
            const_cast<GtkWindowControls*> (gobj ())));
  }

  auto
  WindowControls::get_empty () const -> bool
  {
    return gtk_window_controls_get_empty (
        const_cast<GtkWindowControls*> (gobj ()));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<PackType>::value,
      "Type PackType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  WindowControls::property_side () -> glib::PropertyProxy<PackType>
  {
    return glib::PropertyProxy<PackType> (this, "side");
  }

  auto
  WindowControls::property_side () const -> glib::PropertyProxy_ReadOnly<PackType>
  {
    return glib::PropertyProxy_ReadOnly<PackType> (this, "side");
  }

  auto
  WindowControls::property_decoration_layout () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "decoration-layout");
  }

  auto
  WindowControls::property_decoration_layout () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this,
                                                        "decoration-layout");
  }

  auto
  WindowControls::property_empty () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "empty");
  }

} // namespace gtk
