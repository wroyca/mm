

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/listbase.hxx>
#include <libmm-gtk/listbase_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkListBase* object, const bool take_copy) -> Gtk::ListBase*
  {
    return dynamic_cast<Gtk::ListBase*> (
        wrap_auto ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ListBase_Class::init () -> const Class&
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
  ListBase_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new ListBase ((GtkListBase*) o));
  }

  ListBase::ListBase (const Glib::ConstructParams& construct_params)
    : Widget (construct_params)
  {
  }

  ListBase::ListBase (GtkListBase* castitem)
    : Widget ((GtkWidget*) castitem)
  {
  }

  ListBase::ListBase (ListBase&& src) noexcept
    : Widget (std::move (src)),
      Orientable (std::move (src)),
      Scrollable (std::move (src))
  {
  }

  auto
  ListBase::operator= (ListBase&& src) noexcept -> ListBase&
  {
    Widget::operator= (std::move (src));
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

} // namespace Gtk
