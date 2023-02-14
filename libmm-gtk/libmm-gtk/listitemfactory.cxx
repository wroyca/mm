

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/listitemfactory.hxx>
#include <libmm-gtk/listitemfactory_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkListItemFactory* object, const bool take_copy) -> RefPtr<Gtk::ListItemFactory>
  {
    return Glib::make_refptr_for_instance<Gtk::ListItemFactory> (
        dynamic_cast<Gtk::ListItemFactory*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ListItemFactory_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ListItemFactory_Class::class_init_function;

      register_derived_type (gtk_list_item_factory_get_type ());
    }

    return *this;
  }

  auto
  ListItemFactory_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ListItemFactory_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new ListItemFactory ((GtkListItemFactory*) object);
  }

  auto
  ListItemFactory::gobj_copy () -> GtkListItemFactory*
  {
    reference ();
    return gobj ();
  }

  ListItemFactory::ListItemFactory (
      const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  ListItemFactory::ListItemFactory (GtkListItemFactory* castitem)
    : Object ((GObject*) castitem)
  {
  }

  ListItemFactory::ListItemFactory (ListItemFactory&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  ListItemFactory::operator= (ListItemFactory&& src) noexcept -> ListItemFactory&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  ListItemFactory::~ListItemFactory () noexcept = default;

  ListItemFactory::CppClassType ListItemFactory::listitemfactory_class_;

  auto
  ListItemFactory::get_type () -> GType
  {
    return listitemfactory_class_.init ().get_type ();
  }

  auto
  ListItemFactory::get_base_type () -> GType
  {
    return gtk_list_item_factory_get_type ();
  }

} // namespace Gtk
