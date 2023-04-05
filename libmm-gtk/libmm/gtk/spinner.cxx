// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/spinner.hxx>
#include <libmm/gtk/spinner_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkSpinner* object, bool take_copy) -> gtk::Spinner*
  {
    return dynamic_cast<gtk::Spinner*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  Spinner_Class::init () -> const glib::Class&
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
  Spinner_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Spinner ((GtkSpinner*) (o)));
  }

  Spinner::Spinner (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Spinner::Spinner (GtkSpinner* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Spinner::Spinner (Spinner&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  Spinner::operator= (Spinner&& src) noexcept -> Spinner&
  {
    gtk::Widget::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (spinner_class_.init ()))
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
  Spinner::property_spinning () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "spinning");
  }

  auto
  Spinner::property_spinning () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "spinning");
  }

} // namespace gtk
