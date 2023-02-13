


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/colorchooser.hxx>
#include <libmm-gtk/colorchooser_p.hxx>


/* Copyright 2012 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <gtk/gtk.h>

namespace Gtk
{

auto ColorChooser::get_rgba() const -> Gdk::RGBA
{
  GdkRGBA crgba;
  gtk_color_chooser_get_rgba(const_cast<GtkColorChooser*>(gobj()), &crgba);
  return Glib::wrap(&crgba, true);
}

auto ColorChooser::add_palette (
  Orientation orientation, const int colors_per_line, const std::vector <Gdk::RGBA> &colors) -> void
{
  gtk_color_chooser_add_palette(gobj(), (GtkOrientation)orientation, colors_per_line, colors.size(),
    Glib::ArrayHandler<Gdk::RGBA, Gdk::RGBATraits>::vector_to_array(colors).data() );
}

} //namespace Gtk

namespace
{


auto ColorChooser_signal_color_activated_callback (
  GtkColorChooser *self, const GdkRGBA *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Gdk::RGBA&)>;

  const auto obj = dynamic_cast<ColorChooser*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(const_cast<GdkRGBA*>(p0), true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo ColorChooser_signal_color_activated_info =
{
  "color-activated",
  (GCallback) &ColorChooser_signal_color_activated_callback,
  (GCallback) &ColorChooser_signal_color_activated_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkColorChooser* object, const bool take_copy) -> RefPtr<Gtk::ColorChooser>
{
  return Glib::make_refptr_for_instance<Gtk::ColorChooser>( Glib::wrap_auto_interface<Gtk::ColorChooser> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gtk
{


/* The *_Class implementation: */

auto ColorChooser_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &ColorChooser_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = gtk_color_chooser_get_type();
  }

  return *this;
}

auto ColorChooser_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);


  klass->color_activated = &color_activated_callback;
}


auto ColorChooser_Class::color_activated_callback (GtkColorChooser *self, const GdkRGBA *p0) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_color_activated(Glib::wrap(const_cast<GdkRGBA*>(p0), true)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)    );

  // Call the original underlying C function:
  if(base && base->color_activated)
    (*base->color_activated)(self, p0);
}


auto ColorChooser_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new ColorChooser((GtkColorChooser*)object);
}


/* The implementation: */

ColorChooser::ColorChooser()
: Interface(colorchooser_class_.init())
{}

ColorChooser::ColorChooser(GtkColorChooser* castitem)
: Interface((GObject*)castitem)
{}

ColorChooser::ColorChooser(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

ColorChooser::ColorChooser(ColorChooser&& src) noexcept
: Interface(std::move(src))
{}

auto ColorChooser::operator=(ColorChooser&& src) noexcept -> ColorChooser&
{
  Interface::operator=(std::move(src));
  return *this;
}

ColorChooser::~ColorChooser() noexcept = default;

// static
auto ColorChooser::add_interface (
  const GType gtype_implementer) -> void
{
  colorchooser_class_.init().add_interface(gtype_implementer);
}

ColorChooser::CppClassType ColorChooser::colorchooser_class_; // initialize static member

auto ColorChooser::get_type() -> GType
{
  return colorchooser_class_.init().get_type();
}


auto ColorChooser::get_base_type() -> GType
{
  return gtk_color_chooser_get_type();
}


auto ColorChooser::set_rgba (const Gdk::RGBA &color) -> void
{
  gtk_color_chooser_set_rgba(gobj(), color.gobj());
}

auto ColorChooser::get_use_alpha() const -> bool
{
  return gtk_color_chooser_get_use_alpha(const_cast<GtkColorChooser*>(gobj()));
}

auto ColorChooser::set_use_alpha (
  const bool use_alpha) -> void
{
  gtk_color_chooser_set_use_alpha(gobj(), use_alpha);
}


auto ColorChooser::signal_color_activated() -> Glib::SignalProxy<void(const Gdk::RGBA&)>
{
  return {this, &ColorChooser_signal_color_activated_info};
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Gdk::RGBA>::value,
  "Type Gdk::RGBA cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto ColorChooser::property_rgba() -> Glib::PropertyProxy< Gdk::RGBA >
{
  return {this, "rgba"};
}

auto ColorChooser::property_rgba() const -> Glib::PropertyProxy_ReadOnly< Gdk::RGBA >
{
  return {this, "rgba"};
}

auto ColorChooser::property_use_alpha() -> Glib::PropertyProxy< bool >
{
  return {this, "use-alpha"};
}

auto ColorChooser::property_use_alpha() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "use-alpha"};
}


auto ColorChooser::on_color_activated (const Gdk::RGBA &color) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->color_activated)
    (*base->color_activated)(gobj(),color.gobj());
}


} // namespace Gtk

