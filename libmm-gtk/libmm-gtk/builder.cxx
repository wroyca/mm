// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/builder.hxx>
#include <libmm-gtk/builder_p.hxx>

#include <libmm-glib/vectorutils.hxx>
#include <libmm-gtk/application.hxx>
#include <libmm-gtk/buildercscope.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  auto
  Builder::set_no_gtkmm_derived_types (const bool status) -> void
  {
    no_gtkmm_derived_types = status;
  }

  auto
  Builder::get_no_gtkmm_derived_types () const -> bool
  {
    return no_gtkmm_derived_types;
  }

  Builder::Builder ()
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (builder_class_.init (),
                                     "scope",
                                     BuilderCScope::create ()->gobj (),
                                     nullptr))
  {
  }

  auto
  Builder::create_from_file (const std::string& filename) -> Glib::RefPtr<Builder>
  {
    auto builder = create ();
    if (builder->add_from_file (filename))
      return builder;
    else
      return {};
  }

  auto
  Builder::create_from_file (const std::string& filename, const char* object_id) -> Glib::RefPtr<Builder>
  {
    auto builder = create ();
    if (builder->add_from_file (filename, object_id))
      return builder;
    else
      return {};
  }

  auto
  Builder::create_from_file (const std::string& filename,
                             const Glib::ustring& object_id) -> Glib::RefPtr<Builder>
  {
    auto builder = create ();
    if (builder->add_from_file (filename, object_id))
      return builder;
    else
      return {};
  }

  auto
  Builder::create_from_file (const std::string& filename,
                             const std::vector<Glib::ustring>& object_ids) -> Glib::RefPtr<Builder>
  {
    auto builder = create ();
    if (builder->add_from_file (filename, object_ids))
      return builder;
    else
      return {};
  }

  auto
  Builder::create_from_resource (const std::string& resource_path) -> Glib::RefPtr<Builder>
  {
    auto builder = create ();
    if (builder->add_from_resource (resource_path))
      return builder;
    else
      return {};
  }

  auto
  Builder::create_from_resource (const std::string& resource_path,
                                 const char* object_id) -> Glib::RefPtr<Builder>
  {
    auto builder = create ();
    if (builder->add_from_resource (resource_path, object_id))
      return builder;
    else
      return {};
  }

  auto
  Builder::create_from_resource (const std::string& resource_path,
                                 const Glib::ustring& object_id) -> Glib::RefPtr<Builder>
  {
    auto builder = create ();
    if (builder->add_from_resource (resource_path, object_id))
      return builder;
    else
      return {};
  }

  auto
  Builder::create_from_resource (const std::string& resource_path,
                                 const std::vector<Glib::ustring>& object_ids) -> Glib::RefPtr<Builder>
  {
    auto builder = create ();
    if (builder->add_from_resource (resource_path, object_ids))
      return builder;
    else
      return {};
  }

  auto
  Builder::create_from_string (const Glib::ustring& buffer) -> Glib::RefPtr<Builder>
  {
    auto builder = create ();
    if (builder->add_from_string (buffer))
      return builder;
    else
      return {};
  }

  auto
  Builder::create_from_string (const Glib::ustring& buffer,
                               const char* object_id) -> Glib::RefPtr<Builder>
  {
    auto builder = create ();
    if (builder->add_from_string (buffer, object_id))
      return builder;
    else
      return {};
  }

  auto
  Builder::create_from_string (const Glib::ustring& buffer,
                               const Glib::ustring& object_id) -> Glib::RefPtr<Builder>
  {
    auto builder = create ();
    if (builder->add_from_string (buffer, object_id))
      return builder;
    else
      return {};
  }

  auto
  Builder::create_from_string (const Glib::ustring& buffer,
                               const std::vector<Glib::ustring>& object_ids) -> Glib::RefPtr<Builder>
  {
    auto builder = create ();
    if (builder->add_from_string (buffer, object_ids))
      return builder;
    else
      return {};
  }

  auto
  Builder::add_from_file (const std::string& filename, const char* object_id) -> bool
  {
    const std::vector<Glib::ustring> object_ids (1, object_id);

    return add_from_file (filename, object_ids);
  }

  auto
  Builder::add_from_file (const std::string& filename,
                          const Glib::ustring& object_id) -> bool
  {
    const std::vector<Glib::ustring> object_ids (1, object_id);

    return add_from_file (filename, object_ids);
  }

  auto
  Builder::add_from_resource (const std::string& resource_path,
                              const char* object_id) -> bool
  {
    const std::vector<Glib::ustring> object_ids (1, object_id);

    return add_from_resource (resource_path, object_ids);
  }

  auto
  Builder::add_from_resource (const std::string& resource_path,
                              const Glib::ustring& object_id) -> bool
  {
    const std::vector<Glib::ustring> object_ids (1, object_id);

    return add_from_resource (resource_path, object_ids);
  }

  auto
  Builder::add_from_string (const Glib::ustring& buffer) -> bool
  {
    GError* gerror = nullptr;
    const bool retvalue =
        gtk_builder_add_from_string (gobj (), buffer.c_str (), -1, &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  Builder::add_from_string (const Glib::ustring& buffer, const char* object_id) -> bool
  {
    const std::vector<Glib::ustring> object_ids (1, object_id);

    return add_from_string (buffer, object_ids);
  }

  auto
  Builder::add_from_string (const Glib::ustring& buffer,
                            const Glib::ustring& object_id) -> bool
  {
    const std::vector<Glib::ustring> object_ids (1, object_id);

    return add_from_string (buffer, object_ids);
  }

  auto
  Builder::add_from_string (const Glib::ustring& buffer,
                            const std::vector<Glib::ustring>& object_ids) -> bool
  {
    GError* gerror = nullptr;
    const bool retvalue = gtk_builder_add_objects_from_string (
        gobj (),
        buffer.c_str (),
        -1,
        Glib::ArrayHandler<Glib::ustring>::vector_to_array (object_ids).data (),
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  Builder::get_cwidget (const Glib::ustring& name) -> GtkWidget*
  {
    auto* cobject = gtk_builder_get_object (gobj (), name.c_str ());
    if (!cobject)
    {
      g_critical ("gtkmm: object `%s' not found in GtkBuilder file.",
                  name.c_str ());
      return nullptr;
    }

    if (!GTK_IS_WIDGET (cobject))
    {
      g_critical ("gtkmm: object `%s' (type=`%s') (in GtkBuilder file) is not "
                  "a widget type.",
                  name.c_str (),
                  G_OBJECT_TYPE_NAME (cobject));

      return nullptr;
    }

    return GTK_WIDGET (cobject);
  }

  auto
  Builder::get_widget_checked (const Glib::ustring& name, const GType type) -> Widget*
  {
    auto* cobject = get_cwidget (name);
    if (!cobject)
    {
      g_critical ("gtkmm: Gtk::Builder: widget `%s' was not found in the "
                  "GtkBuilder file, or the specified part of it.",
                  name.c_str ());
      return nullptr;
    }

    if (!g_type_is_a (G_OBJECT_TYPE (cobject), type))
    {
      g_critical ("gtkmm: widget `%s' (in GtkBuilder file) is of type `%s' but "
                  "`%s' was expected",
                  name.c_str (),
                  G_OBJECT_TYPE_NAME (cobject),
                  g_type_name (type));
      return nullptr;
    }

    return Glib::wrap (GTK_WIDGET (cobject), false);
  }

} // namespace Gtk

namespace
{
}

Gtk::BuilderError::BuilderError (const Code error_code,
                                 const Glib::ustring& error_message)
  : Error (GTK_BUILDER_ERROR, error_code, error_message)
{
}

Gtk::BuilderError::BuilderError (GError* gobject)
  : Error (gobject)
{
}

auto
Gtk::BuilderError::code () const -> Code
{
  return static_cast<Code> (Error::code ());
}

auto
Gtk::BuilderError::throw_func (GError* gobject) -> void
{
  throw BuilderError (gobject);
}

auto
Glib::Value<Gtk::BuilderError::Code>::value_type () -> GType
{
  return gtk_builder_error_get_type ();
}

namespace Glib
{

  auto
  wrap (GtkBuilder* object, const bool take_copy) -> RefPtr<Gtk::Builder>
  {
    return Glib::make_refptr_for_instance<Gtk::Builder> (
        dynamic_cast<Gtk::Builder*> (wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Builder_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Builder_Class::class_init_function;

      register_derived_type (gtk_builder_get_type ());
    }

    return *this;
  }

  auto
  Builder_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Builder_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Builder ((GtkBuilder*) object);
  }

  auto
  Builder::gobj_copy () -> GtkBuilder*
  {
    reference ();
    return gobj ();
  }

  Builder::Builder (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  Builder::Builder (GtkBuilder* castitem)
    : Object ((GObject*) castitem)
  {
  }

  Builder::Builder (Builder&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  Builder::operator= (Builder&& src) noexcept -> Builder&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  Builder::~Builder () noexcept = default;

  Builder::CppClassType Builder::builder_class_;

  auto
  Builder::get_type () -> GType
  {
    return builder_class_.init ().get_type ();
  }

  auto
  Builder::get_base_type () -> GType
  {
    return gtk_builder_get_type ();
  }

  auto
  Builder::create () -> Glib::RefPtr<Builder>
  {
    return Glib::make_refptr_for_instance<Builder> (new Builder ());
  }

  auto
  Builder::add_from_file (const std::string& filename) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue =
        gtk_builder_add_from_file (gobj (), filename.c_str (), &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Builder::add_from_file (const std::string& filename,
                          const std::vector<Glib::ustring>& object_ids) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = gtk_builder_add_objects_from_file (
        gobj (),
        filename.c_str (),
        Glib::ArrayHandler<Glib::ustring>::vector_to_array (object_ids).data (),
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Builder::add_from_resource (const std::string& resource_path) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = gtk_builder_add_from_resource (gobj (),
                                                         resource_path.c_str (),
                                                         &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Builder::add_from_resource (const std::string& resource_path,
                              const std::vector<Glib::ustring>& object_ids) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = gtk_builder_add_objects_from_resource (
        gobj (),
        resource_path.c_str (),
        Glib::ArrayHandler<Glib::ustring>::vector_to_array (object_ids).data (),
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Builder::add_from_string (const char* buffer, const gssize length) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue =
        gtk_builder_add_from_string (gobj (), buffer, length, &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Builder::expose_object (const Glib::ustring& name,
                          const Glib::RefPtr<Object>& object) -> void
  {
    gtk_builder_expose_object (gobj (), name.c_str (), Glib::unwrap (object));
  }

  auto
  Builder::expose_widget (const Glib::ustring& name, Widget& widget) -> void
  {
    gtk_builder_expose_object (gobj (),
                               name.c_str (),
                               G_OBJECT (widget.gobj ()));
  }

  auto
  Builder::get_object (const Glib::ustring& name) -> Glib::RefPtr<Object>
  {
    auto retvalue =
        Glib::wrap (gtk_builder_get_object (gobj (), name.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Builder::get_object (const Glib::ustring& name) const -> Glib::RefPtr<const Object>
  {
    return const_cast<Builder*> (this)->get_object (name);
  }

  auto
  Builder::get_objects () -> std::vector<Glib::RefPtr<Object>>
  {
    return Glib::SListHandler<Glib::RefPtr<Object>>::slist_to_vector (
        gtk_builder_get_objects (gobj ()),
        Glib::OWNERSHIP_SHALLOW);
  }

  auto
  Builder::get_objects () const -> std::vector<Glib::RefPtr<const Object>>
  {
    return Glib::SListHandler<Glib::RefPtr<const Object>>::slist_to_vector (
        gtk_builder_get_objects (const_cast<GtkBuilder*> (gobj ())),
        Glib::OWNERSHIP_SHALLOW);
  }

  auto
  Builder::set_translation_domain (const Glib::ustring& domain) -> void
  {
    gtk_builder_set_translation_domain (gobj (), domain.c_str ());
  }

  auto
  Builder::get_translation_domain () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_builder_get_translation_domain (const_cast<GtkBuilder*> (gobj ())));
  }

  auto
  Builder::property_translation_domain () -> Glib::PropertyProxy<Glib::ustring>
  {
    return {this, "translation-domain"};
  }

  auto
  Builder::property_translation_domain () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "translation-domain"};
  }

} // namespace Gtk
