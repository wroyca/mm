// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/builderscope.hxx>
#include <libmm/gtk/builderscope_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gtk/builder.hxx>

namespace gtk
{

  auto
  BuilderScope_Class::get_type_from_name_vfunc_callback (GtkBuilderScope* self,
                                                         GtkBuilder* builder,
                                                         const char* type_name) -> GType
  {
    if (!type_name)
      return G_TYPE_INVALID;

    GType gtype = G_TYPE_INVALID;

    const auto obj = dynamic_cast<Builder*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) builder));
    if (!(obj && obj->no_gtkmm_derived_types))
    {
      glib::ustring classname_prefixed ("gtkmm__");
      classname_prefixed += type_name;

      gtype = g_type_from_name (classname_prefixed.c_str ());
    }

    if (gtype == G_TYPE_INVALID)
    {
      const auto base = static_cast<BaseClassType*> (

          g_type_interface_peek_parent (

              g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                     CppObjectType::get_type ())));

      if (base && base->get_type_from_name)
        gtype = (*base->get_type_from_name) (self, builder, type_name);
      else
        gtype = g_type_from_name (type_name);
    }

    return gtype;
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkBuilderScope* object, bool take_copy) -> glib::RefPtr<gtk::BuilderScope>
  {
    return glib::make_refptr_for_instance<gtk::BuilderScope> (
        dynamic_cast<gtk::BuilderScope*> (
            glib::wrap_auto_interface<gtk::BuilderScope> ((GObject*) (object),
                                                          take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  BuilderScope_Class::init () -> const glib::Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &BuilderScope_Class::iface_init_function;

      gtype_ = gtk_builder_scope_get_type ();
    }

    return *this;
  }

  auto
  BuilderScope_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->get_type_from_name = &get_type_from_name_vfunc_callback;
  }

  auto
  BuilderScope_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new BuilderScope ((GtkBuilderScope*) (object));
  }

  BuilderScope::BuilderScope ()
    : glib::Interface (builderscope_class_.init ())
  {
  }

  BuilderScope::BuilderScope (GtkBuilderScope* castitem)
    : glib::Interface ((GObject*) (castitem))
  {
  }

  BuilderScope::BuilderScope (const glib::Interface_Class& interface_class)
    : glib::Interface (interface_class)
  {
  }

  BuilderScope::BuilderScope (BuilderScope&& src) noexcept
    : glib::Interface (std::move (src))
  {
  }

  auto
  BuilderScope::operator= (BuilderScope&& src) noexcept -> BuilderScope&
  {
    glib::Interface::operator= (std::move (src));
    return *this;
  }

  BuilderScope::~BuilderScope () noexcept {}

  auto
  BuilderScope::add_interface (GType gtype_implementer) -> void
  {
    builderscope_class_.init ().add_interface (gtype_implementer);
  }

  BuilderScope::CppClassType BuilderScope::builderscope_class_;

  auto
  BuilderScope::get_type () -> GType
  {
    return builderscope_class_.init ().get_type ();
  }

  auto
  BuilderScope::get_base_type () -> GType
  {
    return gtk_builder_scope_get_type ();
  }

} // namespace gtk
