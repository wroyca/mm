// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/spinner.hxx>
#include <libmm-gtk/spinner_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkSpinner* object, bool take_copy) -> Gtk::Spinner*
  {
    return dynamic_cast<Gtk::Spinner*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Spinner_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Spinner_Class::class_init_function;

      register_derived_type (gtk_spinner_get_type ());
    }

    return *this;
  }

  auto
  Spinner_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Spinner_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new Spinner ((GtkSpinner*) (o)));
  }

  Spinner::Spinner (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  Spinner::Spinner (GtkSpinner* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Spinner::Spinner (Spinner&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  Spinner::operator= (Spinner&& src) noexcept -> Spinner&
  {
    Gtk::Widget::operator= (std::move (src));
    return *this;
  }

  Spinner::~Spinner () noexcept
  {
    destroy_ ();
  }

  Spinner::CppClassType Spinner::spinner_class_;

  auto
  Spinner::get_type () -> GType
  {
    return spinner_class_.init ().get_type ();
  }

  auto
  Spinner::get_base_type () -> GType
  {
    return gtk_spinner_get_type ();
  }

  Spinner::Spinner ()
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (spinner_class_.init ()))
  {
  }

  auto
  Spinner::start () -> void
  {
    gtk_spinner_start (gobj ());
  }

  auto
  Spinner::stop () -> void
  {
    gtk_spinner_stop (gobj ());
  }

  auto
  Spinner::set_spinning (bool spinning) -> void
  {
    gtk_spinner_set_spinning (gobj (), static_cast<int> (spinning));
  }

  auto
  Spinner::get_spinning () const -> bool
  {
    return gtk_spinner_get_spinning (const_cast<GtkSpinner*> (gobj ()));
  }

  auto
  Spinner::property_spinning () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "spinning");
  }

  auto
  Spinner::property_spinning () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "spinning");
  }

} // namespace Gtk
