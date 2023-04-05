// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/buildercscope.hxx>
#include <libmm/gtk/buildercscope_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkBuilderCScope* object, bool take_copy) -> glib::RefPtr<gtk::BuilderCScope>
  {
    return glib::make_refptr_for_instance<gtk::BuilderCScope> (
        dynamic_cast<gtk::BuilderCScope*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  BuilderCScope_Class::init () -> const glib::Class&
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
  BuilderCScope_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new BuilderCScope ((GtkBuilderCScope*) object);
  }

  auto
  BuilderCScope::gobj_copy () -> GtkBuilderCScope*
  {
    reference ();
    return gobj ();
  }

  BuilderCScope::BuilderCScope (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  BuilderCScope::BuilderCScope (GtkBuilderCScope* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  BuilderCScope::BuilderCScope (BuilderCScope&& src) noexcept
    : glib::Object (std::move (src)),
      BuilderScope (std::move (src))
  {
  }

  auto
  BuilderCScope::operator= (BuilderCScope&& src) noexcept -> BuilderCScope&
  {
    glib::Object::operator= (std::move (src));
    BuilderScope::operator= (std::move (src));
    return *this;
  }

  BuilderCScope::~BuilderCScope () noexcept {}

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
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (buildercscope_class_.init ()))
  {
  }

  auto
  BuilderCScope::create () -> glib::RefPtr<BuilderCScope>
  {
    return glib::make_refptr_for_instance<BuilderCScope> (new BuilderCScope ());
  }

} // namespace gtk
