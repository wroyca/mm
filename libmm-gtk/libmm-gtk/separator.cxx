// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/separator.hxx>
#include <libmm-gtk/separator_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkSeparator* object, bool take_copy) -> Gtk::Separator*
  {
    return dynamic_cast<Gtk::Separator*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Separator_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Separator_Class::class_init_function;

      register_derived_type (gtk_separator_get_type ());

      Orientable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  Separator_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Separator_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new Separator ((GtkSeparator*) (o)));
  }

  Separator::Separator (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  Separator::Separator (GtkSeparator* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Separator::Separator (Separator&& src) noexcept
    : Gtk::Widget (std::move (src)),
      Orientable (std::move (src))
  {
  }

  auto
  Separator::operator= (Separator&& src) noexcept -> Separator&
  {
    Gtk::Widget::operator= (std::move (src));
    Orientable::operator= (std::move (src));
    return *this;
  }

  Separator::~Separator () noexcept
  {
    destroy_ ();
  }

  Separator::CppClassType Separator::separator_class_;

  auto
  Separator::get_type () -> GType
  {
    return separator_class_.init ().get_type ();
  }

  auto
  Separator::get_base_type () -> GType
  {
    return gtk_separator_get_type ();
  }

  Separator::Separator (Orientation orientation)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (
          Glib::ConstructParams (separator_class_.init (),
                                 "orientation",
                                 static_cast<GtkOrientation> (orientation),
                                 nullptr))
  {
  }

} // namespace Gtk
