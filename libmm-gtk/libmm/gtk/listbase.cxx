// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/listbase.hxx>
#include <libmm/gtk/listbase_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkListBase* object, bool take_copy) -> gtk::ListBase*
  {
    return dynamic_cast<gtk::ListBase*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  ListBase_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ListBase_Class::class_init_function;

      register_derived_type (gtk_list_base_get_type ());

      Orientable::add_interface (get_type ());
      Scrollable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  ListBase_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ListBase_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new ListBase ((GtkListBase*) (o)));
  }

  ListBase::ListBase (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  ListBase::ListBase (GtkListBase* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  ListBase::ListBase (ListBase&& src) noexcept
    : gtk::Widget (std::move (src)),
      Orientable (std::move (src)),
      Scrollable (std::move (src))
  {
  }

  auto
  ListBase::operator= (ListBase&& src) noexcept -> ListBase&
  {
    gtk::Widget::operator= (std::move (src));
    Orientable::operator= (std::move (src));
    Scrollable::operator= (std::move (src));
    return *this;
  }

  ListBase::~ListBase () noexcept
  {
    destroy_ ();
  }

  ListBase::CppClassType ListBase::listbase_class_;

  auto
  ListBase::get_type () -> GType
  {
    return listbase_class_.init ().get_type ();
  }

  auto
  ListBase::get_base_type () -> GType
  {
    return gtk_list_base_get_type ();
  }

} // namespace gtk
