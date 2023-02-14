

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/orientable.hxx>
#include <libmm-gtk/orientable_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkOrientable* object, const bool take_copy) -> RefPtr<Gtk::Orientable>
  {
    return Glib::make_refptr_for_instance<Gtk::Orientable> (
        Glib::wrap_auto_interface<Gtk::Orientable> ((GObject*) object,
                                                    take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Orientable_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Orientable_Class::iface_init_function;

      gtype_ = gtk_orientable_get_type ();
    }

    return *this;
  }

  auto
  Orientable_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);
  }

  auto
  Orientable_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Orientable ((GtkOrientable*) object);
  }

  Orientable::Orientable ()
    : Interface (orientable_class_.init ())
  {
  }

  Orientable::Orientable (GtkOrientable* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  Orientable::Orientable (const Glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  Orientable::Orientable (Orientable&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  Orientable::operator= (Orientable&& src) noexcept -> Orientable&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  Orientable::~Orientable () noexcept = default;

  auto
  Orientable::add_interface (const GType gtype_implementer) -> void
  {
    orientable_class_.init ().add_interface (gtype_implementer);
  }

  Orientable::CppClassType Orientable::orientable_class_;

  auto
  Orientable::get_type () -> GType
  {
    return orientable_class_.init ().get_type ();
  }

  auto
  Orientable::get_base_type () -> GType
  {
    return gtk_orientable_get_type ();
  }

  auto
  Orientable::set_orientation (Orientation orientation) -> void
  {
    gtk_orientable_set_orientation (gobj (),
                                    static_cast<GtkOrientation> (orientation));
  }

  auto
  Orientable::get_orientation () const -> Orientation
  {
    return static_cast<Orientation> (
        gtk_orientable_get_orientation (const_cast<GtkOrientable*> (gobj ())));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Orientation>::value,
      "Type Orientation cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Orientable::property_orientation () -> Glib::PropertyProxy<Orientation>
  {
    return {this, "orientation"};
  }

  auto
  Orientable::property_orientation () const -> Glib::PropertyProxy_ReadOnly<Orientation>
  {
    return {this, "orientation"};
  }

} // namespace Gtk
