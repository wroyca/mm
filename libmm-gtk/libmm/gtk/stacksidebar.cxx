// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/stacksidebar.hxx>
#include <libmm/gtk/stacksidebar_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  auto
  StackSidebar::unset_stack () -> void
  {
    gtk_stack_sidebar_set_stack (gobj (), nullptr);
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkStackSidebar* object, bool take_copy) -> gtk::StackSidebar*
  {
    return dynamic_cast<gtk::StackSidebar*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  StackSidebar_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &StackSidebar_Class::class_init_function;

      register_derived_type (gtk_stack_sidebar_get_type ());
    }

    return *this;
  }

  auto
  StackSidebar_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  StackSidebar_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new StackSidebar ((GtkStackSidebar*) (o)));
  }

  StackSidebar::StackSidebar (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  StackSidebar::StackSidebar (GtkStackSidebar* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  StackSidebar::StackSidebar (StackSidebar&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  StackSidebar::operator= (StackSidebar&& src) noexcept -> StackSidebar&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  StackSidebar::~StackSidebar () noexcept
  {
    destroy_ ();
  }

  StackSidebar::CppClassType StackSidebar::stacksidebar_class_;

  auto
  StackSidebar::get_type () -> GType
  {
    return stacksidebar_class_.init ().get_type ();
  }

  auto
  StackSidebar::get_base_type () -> GType
  {
    return gtk_stack_sidebar_get_type ();
  }

  StackSidebar::StackSidebar ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (stacksidebar_class_.init ()))
  {
  }

  auto
  StackSidebar::set_stack (Stack& stack) -> void
  {
    gtk_stack_sidebar_set_stack (gobj (), (stack).gobj ());
  }

  auto
  StackSidebar::get_stack () -> Stack*
  {
    return glib::wrap (gtk_stack_sidebar_get_stack (gobj ()));
  }

  auto
  StackSidebar::get_stack () const -> const Stack*
  {
    return const_cast<StackSidebar*> (this)->get_stack ();
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Stack*>::value,
      "Type Stack* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  StackSidebar::property_stack () -> glib::PropertyProxy<Stack*>
  {
    return glib::PropertyProxy<Stack*> (this, "stack");
  }

  auto
  StackSidebar::property_stack () const -> glib::PropertyProxy_ReadOnly<Stack*>
  {
    return glib::PropertyProxy_ReadOnly<Stack*> (this, "stack");
  }

} // namespace gtk
