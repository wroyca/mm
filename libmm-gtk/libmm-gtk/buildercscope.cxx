

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/buildercscope.hxx>
#include <libmm-gtk/buildercscope_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkBuilderCScope* object, const bool take_copy) -> RefPtr<Gtk::BuilderCScope>
  {
    return Glib::make_refptr_for_instance<Gtk::BuilderCScope> (
        dynamic_cast<Gtk::BuilderCScope*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  BuilderCScope_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &BuilderCScope_Class::class_init_function;

      register_derived_type (gtk_builder_cscope_get_type ());

      BuilderScope::add_interface (get_type ());
    }

    return *this;
  }

  auto
  BuilderCScope_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  BuilderCScope_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new BuilderCScope ((GtkBuilderCScope*) object);
  }

  auto
  BuilderCScope::gobj_copy () -> GtkBuilderCScope*
  {
    reference ();
    return gobj ();
  }

  BuilderCScope::BuilderCScope (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  BuilderCScope::BuilderCScope (GtkBuilderCScope* castitem)
    : Object ((GObject*) castitem)
  {
  }

  BuilderCScope::BuilderCScope (BuilderCScope&& src) noexcept
    : Object (std::move (src)),
      BuilderScope (std::move (src))
  {
  }

  auto
  BuilderCScope::operator= (BuilderCScope&& src) noexcept -> BuilderCScope&
  {
    Object::operator= (std::move (src));
    BuilderScope::operator= (std::move (src));
    return *this;
  }

  BuilderCScope::~BuilderCScope () noexcept = default;

  BuilderCScope::CppClassType BuilderCScope::buildercscope_class_;

  auto
  BuilderCScope::get_type () -> GType
  {
    return buildercscope_class_.init ().get_type ();
  }

  auto
  BuilderCScope::get_base_type () -> GType
  {
    return gtk_builder_cscope_get_type ();
  }

  BuilderCScope::BuilderCScope ()
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (buildercscope_class_.init ()))
  {
  }

  auto
  BuilderCScope::create () -> Glib::RefPtr<BuilderCScope>
  {
    return Glib::make_refptr_for_instance<BuilderCScope> (new BuilderCScope ());
  }

} // namespace Gtk
