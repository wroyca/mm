// SPDX-License-Identifier: LGPL-2.1-or-later

typedef struct _GtkBuilder GtkBuilder;
typedef struct _GtkBuildableParser GtkBuildableParser;

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/buildable.hxx>
#include <libmm/gtk/buildable_p.hxx>

#include <cstring>
#include <gtk/gtk.h>
#include <libmm/gtk/builder.hxx>

namespace gtk
{

  auto
  Buildable_Class::custom_tag_start_vfunc_callback (GtkBuildable* buildable,
                                                    GtkBuilder* builder,
                                                    GObject* child,
                                                    const char* tagname,
                                                    GtkBuildableParser* parser,
                                                    gpointer* data) -> gboolean
  {
    if (GTK_IS_TREE_MODEL (buildable) && std::strcmp (tagname, "columns") == 0)
    {
      const auto cpp_builder = dynamic_cast<Builder*> (
          glib::ObjectBase::_get_current_wrapper ((GObject*) builder));
      if (cpp_builder)
        cpp_builder->set_no_gtkmm_derived_types (true);
    }

    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (buildable),
                                   CppObjectType::get_type ())));

    if (base && base->custom_tag_start)
      return (*base->custom_tag_start) (buildable,
                                        builder,
                                        child,
                                        tagname,
                                        parser,
                                        data);
    return false;
  }

  auto
  Buildable_Class::custom_tag_end_vfunc_callback (GtkBuildable* buildable,
                                                  GtkBuilder* builder,
                                                  GObject* child,
                                                  const char* tagname,
                                                  gpointer data) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (buildable),
                                   CppObjectType::get_type ())));

    if (base && base->custom_tag_end)
      (*base->custom_tag_end) (buildable, builder, child, tagname, data);

    if (GTK_IS_TREE_MODEL (buildable) && std::strcmp (tagname, "columns") == 0)
    {
      const auto cpp_builder = dynamic_cast<Builder*> (
          glib::ObjectBase::_get_current_wrapper ((GObject*) builder));
      if (cpp_builder)
        cpp_builder->set_no_gtkmm_derived_types (false);
    }
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkBuildable* object, bool take_copy) -> glib::RefPtr<gtk::Buildable>
  {
    return glib::make_refptr_for_instance<gtk::Buildable> (
        dynamic_cast<gtk::Buildable*> (
            glib::wrap_auto_interface<gtk::Buildable> ((GObject*) (object),
                                                       take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  Buildable_Class::init () -> const glib::Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Buildable_Class::iface_init_function;

      gtype_ = gtk_buildable_get_type ();
    }

    return *this;
  }

  auto
  Buildable_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->custom_tag_start = &custom_tag_start_vfunc_callback;
    klass->custom_tag_end = &custom_tag_end_vfunc_callback;
  }

  auto
  Buildable_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Buildable ((GtkBuildable*) (object));
  }

  Buildable::Buildable ()
    : glib::Interface (buildable_class_.init ())
  {
  }

  Buildable::Buildable (GtkBuildable* castitem)
    : glib::Interface ((GObject*) (castitem))
  {
  }

  Buildable::Buildable (const glib::Interface_Class& interface_class)
    : glib::Interface (interface_class)
  {
  }

  Buildable::Buildable (Buildable&& src) noexcept
    : glib::Interface (std::move (src))
  {
  }

  auto
  Buildable::operator= (Buildable&& src) noexcept -> Buildable&
  {
    glib::Interface::operator= (std::move (src));
    return *this;
  }

  Buildable::~Buildable () noexcept {}

  auto
  Buildable::add_interface (GType gtype_implementer) -> void
  {
    buildable_class_.init ().add_interface (gtype_implementer);
  }

  Buildable::CppClassType Buildable::buildable_class_;

  auto
  Buildable::get_type () -> GType
  {
    return buildable_class_.init ().get_type ();
  }

  auto
  Buildable::get_base_type () -> GType
  {
    return gtk_buildable_get_type ();
  }

  auto
  Buildable::get_buildable_id () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_buildable_get_buildable_id (const_cast<GtkBuildable*> (gobj ())));
  }

} // namespace gtk
