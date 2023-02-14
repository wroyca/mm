

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/stacksidebar.hxx>
#include <libmm-gtk/stacksidebar_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  auto
  StackSidebar::unset_stack () -> void
  {
    gtk_stack_sidebar_set_stack (gobj (), nullptr);
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkStackSidebar* object, const bool take_copy) -> Gtk::StackSidebar*
  {
    return dynamic_cast<Gtk::StackSidebar*> (
        wrap_auto ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  StackSidebar_Class::init () -> const Class&
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
  StackSidebar_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new StackSidebar ((GtkStackSidebar*) o));
  }

  StackSidebar::StackSidebar (const Glib::ConstructParams& construct_params)
    : Widget (construct_params)
  {
  }

  StackSidebar::StackSidebar (GtkStackSidebar* castitem)
    : Widget ((GtkWidget*) castitem)
  {
  }

  StackSidebar::StackSidebar (StackSidebar&& src) noexcept
    : Widget (std::move (src))
  {
  }

  auto
  StackSidebar::operator= (StackSidebar&& src) noexcept -> StackSidebar&
  {
    Widget::operator= (std::move (src));
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
    : ObjectBase (nullptr),
      Widget (Glib::ConstructParams (stacksidebar_class_.init ()))
  {
  }

  auto
  StackSidebar::set_stack (Stack& stack) -> void
  {
    gtk_stack_sidebar_set_stack (gobj (), stack.gobj ());
  }

  auto
  StackSidebar::get_stack () -> Stack*
  {
    return Glib::wrap (gtk_stack_sidebar_get_stack (gobj ()));
  }

  auto
  StackSidebar::get_stack () const -> const Stack*
  {
    return const_cast<StackSidebar*> (this)->get_stack ();
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Stack*>::value,
      "Type Stack* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  StackSidebar::property_stack () -> Glib::PropertyProxy<Stack*>
  {
    return {this, "stack"};
  }

  auto
  StackSidebar::property_stack () const -> Glib::PropertyProxy_ReadOnly<Stack*>
  {
    return {this, "stack"};
  }

} // namespace Gtk
