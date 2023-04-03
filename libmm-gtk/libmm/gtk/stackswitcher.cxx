// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/stackswitcher.hxx>
#include <libmm/gtk/stackswitcher_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  auto
  StackSwitcher::unset_stack () -> void
  {
    gtk_stack_switcher_set_stack (gobj (), nullptr);
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkStackSwitcher* object, bool take_copy) -> Gtk::StackSwitcher*
  {
    return dynamic_cast<Gtk::StackSwitcher*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  StackSwitcher_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &StackSwitcher_Class::class_init_function;

      register_derived_type (gtk_stack_switcher_get_type ());
    }

    return *this;
  }

  auto
  StackSwitcher_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  StackSwitcher_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new StackSwitcher ((GtkStackSwitcher*) (o)));
  }

  StackSwitcher::StackSwitcher (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  StackSwitcher::StackSwitcher (GtkStackSwitcher* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  StackSwitcher::StackSwitcher (StackSwitcher&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  StackSwitcher::operator= (StackSwitcher&& src) noexcept -> StackSwitcher&
  {
    Gtk::Widget::operator= (std::move (src));
    return *this;
  }

  StackSwitcher::~StackSwitcher () noexcept
  {
    destroy_ ();
  }

  StackSwitcher::CppClassType StackSwitcher::stackswitcher_class_;

  auto
  StackSwitcher::get_type () -> GType
  {
    return stackswitcher_class_.init ().get_type ();
  }

  auto
  StackSwitcher::get_base_type () -> GType
  {
    return gtk_stack_switcher_get_type ();
  }

  StackSwitcher::StackSwitcher ()
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (stackswitcher_class_.init ()))
  {
  }

  auto
  StackSwitcher::set_stack (Stack& stack) -> void
  {
    gtk_stack_switcher_set_stack (gobj (), (stack).gobj ());
  }

  auto
  StackSwitcher::get_stack () -> Stack*
  {
    return Glib::wrap (gtk_stack_switcher_get_stack (gobj ()));
  }

  auto
  StackSwitcher::get_stack () const -> const Stack*
  {
    return const_cast<StackSwitcher*> (this)->get_stack ();
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Stack*>::value,
      "Type Stack* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  StackSwitcher::property_stack () -> Glib::PropertyProxy<Stack*>
  {
    return Glib::PropertyProxy<Stack*> (this, "stack");
  }

  auto
  StackSwitcher::property_stack () const -> Glib::PropertyProxy_ReadOnly<Stack*>
  {
    return Glib::PropertyProxy_ReadOnly<Stack*> (this, "stack");
  }

} // namespace Gtk
