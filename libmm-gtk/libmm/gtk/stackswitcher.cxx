// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/stackswitcher.hxx>
#include <libmm/gtk/stackswitcher_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  auto
  StackSwitcher::unset_stack () -> void
  {
    gtk_stack_switcher_set_stack (gobj (), nullptr);
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkStackSwitcher* object, bool take_copy) -> gtk::StackSwitcher*
  {
    return dynamic_cast<gtk::StackSwitcher*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  StackSwitcher_Class::init () -> const glib::Class&
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
  StackSwitcher_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new StackSwitcher ((GtkStackSwitcher*) (o)));
  }

  StackSwitcher::StackSwitcher (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  StackSwitcher::StackSwitcher (GtkStackSwitcher* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  StackSwitcher::StackSwitcher (StackSwitcher&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  StackSwitcher::operator= (StackSwitcher&& src) noexcept -> StackSwitcher&
  {
    gtk::Widget::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (stackswitcher_class_.init ()))
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
    return glib::wrap (gtk_stack_switcher_get_stack (gobj ()));
  }

  auto
  StackSwitcher::get_stack () const -> const Stack*
  {
    return const_cast<StackSwitcher*> (this)->get_stack ();
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Stack*>::value,
      "Type Stack* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  StackSwitcher::property_stack () -> glib::PropertyProxy<Stack*>
  {
    return glib::PropertyProxy<Stack*> (this, "stack");
  }

  auto
  StackSwitcher::property_stack () const -> glib::PropertyProxy_ReadOnly<Stack*>
  {
    return glib::PropertyProxy_ReadOnly<Stack*> (this, "stack");
  }

} // namespace gtk
