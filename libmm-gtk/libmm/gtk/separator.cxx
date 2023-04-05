// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/separator.hxx>
#include <libmm/gtk/separator_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkSeparator* object, bool take_copy) -> gtk::Separator*
  {
    return dynamic_cast<gtk::Separator*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  Separator_Class::init () -> const glib::Class&
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
  Separator_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Separator ((GtkSeparator*) (o)));
  }

  Separator::Separator (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Separator::Separator (GtkSeparator* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Separator::Separator (Separator&& src) noexcept
    : gtk::Widget (std::move (src)),
      Orientable (std::move (src))
  {
  }

  auto
  Separator::operator= (Separator&& src) noexcept -> Separator&
  {
    gtk::Widget::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::Widget (
          glib::ConstructParams (separator_class_.init (),
                                 "orientation",
                                 static_cast<GtkOrientation> (orientation),
                                 nullptr))
  {
  }

} // namespace gtk
