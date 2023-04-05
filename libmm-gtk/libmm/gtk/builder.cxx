// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/builder.hxx>
#include <libmm/gtk/builder_p.hxx>

#include <libmm/glib/vectorutils.hxx>
#include <libmm/gtk/application.hxx>
#include <libmm/gtk/buildercscope.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  auto
  Builder::set_no_gtkmm_derived_types (bool status) -> void
  {
    no_gtkmm_derived_types = status;
  }

  auto
  Builder::get_no_gtkmm_derived_types () const -> bool
  {
    return no_gtkmm_derived_types;
  }

  Builder::Builder ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (builder_class_.init (),
                                           "scope",
                                           BuilderCScope::create ()->gobj (),
                                           nullptr))
  {
  }

  auto
  Builder::create_from_file (const std::string& filename) -> glib::RefPtr<Builder>
  {
    auto builder = Builder::create ();
    if (builder->add_from_file (filename))
      return builder;
    else
      return glib::RefPtr<Builder> ();
  }

  auto
  Builder::create_from_file (const std::string& filename, const char* object_id) -> glib::RefPtr<Builder>
  {
    auto builder = Builder::create ();
    if (builder->add_from_file (filename, object_id))
      return builder;
    else
      return glib::RefPtr<Builder> ();
  }

  auto
  Builder::create_from_file (const std::string& filename,
                             const glib::ustring& object_id) -> glib::RefPtr<Builder>
  {
    auto builder = Builder::create ();
    if (builder->add_from_file (filename, object_id))
      return builder;
    else
      return glib::RefPtr<Builder> ();
  }

  auto
  Builder::create_from_file (const std::string& filename,
                             const std::vector<glib::ustring>& object_ids) -> glib::RefPtr<Builder>
  {
    auto builder = Builder::create ();
    if (builder->add_from_file (filename, object_ids))
      return builder;
    else
      return glib::RefPtr<Builder> ();
  }

  auto
  Builder::create_from_resource (const std::string& resource_path) -> glib::RefPtr<Builder>
  {
    auto builder = Builder::create ();
    if (builder->add_from_resource (resource_path))
      return builder;
    else
      return glib::RefPtr<Builder> ();
  }

  auto
  Builder::create_from_resource (const std::string& resource_path,
                                 const char* object_id) -> glib::RefPtr<Builder>
  {
    auto builder = Builder::create ();
    if (builder->add_from_resource (resource_path, object_id))
      return builder;
    else
      return glib::RefPtr<Builder> ();
  }

  auto
  Builder::create_from_resource (const std::string& resource_path,
                                 const glib::ustring& object_id) -> glib::RefPtr<Builder>
  {
    auto builder = Builder::create ();
    if (builder->add_from_resource (resource_path, object_id))
      return builder;
    else
      return glib::RefPtr<Builder> ();
  }

  auto
  Builder::create_from_resource (const std::string& resource_path,
                                 const std::vector<glib::ustring>& object_ids) -> glib::RefPtr<Builder>
  {
    auto builder = Builder::create ();
    if (builder->add_from_resource (resource_path, object_ids))
      return builder;
    else
      return glib::RefPtr<Builder> ();
  }

  auto
  Builder::create_from_string (const glib::ustring& buffer) -> glib::RefPtr<Builder>
  {
    auto builder = Builder::create ();
    if (builder->add_from_string (buffer))
      return builder;
    else
      return glib::RefPtr<Builder> ();
  }

  auto
  Builder::create_from_string (const glib::ustring& buffer,
                               const char* object_id) -> glib::RefPtr<Builder>
  {
    auto builder = Builder::create ();
    if (builder->add_from_string (buffer, object_id))
      return builder;
    else
      return glib::RefPtr<Builder> ();
  }

  auto
  Builder::create_from_string (const glib::ustring& buffer,
                               const glib::ustring& object_id) -> glib::RefPtr<Builder>
  {
    auto builder = Builder::create ();
    if (builder->add_from_string (buffer, object_id))
      return builder;
    else
      return glib::RefPtr<Builder> ();
  }

  auto
  Builder::create_from_string (const glib::ustring& buffer,
                               const std::vector<glib::ustring>& object_ids) -> glib::RefPtr<Builder>
  {
    auto builder = Builder::create ();
    if (builder->add_from_string (buffer, object_ids))
      return builder;
    else
      return glib::RefPtr<Builder> ();
  }

  auto
  Builder::add_from_file (const std::string& filename, const char* object_id) -> bool
  {
    std::vector<glib::ustring> object_ids (1, object_id);

    return add_from_file (filename, object_ids);
  }

  auto
  Builder::add_from_file (const std::string& filename,
                          const glib::ustring& object_id) -> bool
  {
    std::vector<glib::ustring> object_ids (1, object_id);

    return add_from_file (filename, object_ids);
  }

  auto
  Builder::add_from_resource (const std::string& resource_path,
                              const char* object_id) -> bool
  {
    std::vector<glib::ustring> object_ids (1, object_id);

    return add_from_resource (resource_path, object_ids);
  }

  auto
  Builder::add_from_resource (const std::string& resource_path,
                              const glib::ustring& object_id) -> bool
  {
    std::vector<glib::ustring> object_ids (1, object_id);

    return add_from_resource (resource_path, object_ids);
  }

  auto
  Builder::add_from_string (const glib::ustring& buffer) -> bool
  {
    GError* gerror = nullptr;
    bool retvalue =
        gtk_builder_add_from_string (gobj (), buffer.c_str (), -1, &(gerror));
    if (gerror)
      ::glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  Builder::add_from_string (const glib::ustring& buffer, const char* object_id) -> bool
  {
    std::vector<glib::ustring> object_ids (1, object_id);

    return add_from_string (buffer, object_ids);
  }

  auto
  Builder::add_from_string (const glib::ustring& buffer,
                            const glib::ustring& object_id) -> bool
  {
    std::vector<glib::ustring> object_ids (1, object_id);

    return add_from_string (buffer, object_ids);
  }

  auto
  Builder::add_from_string (const glib::ustring& buffer,
                            const std::vector<glib::ustring>& object_ids) -> bool
  {
    GError* gerror = nullptr;
    bool retvalue = gtk_builder_add_objects_from_string (
        gobj (),
        buffer.c_str (),
        -1,
        glib::ArrayHandler<glib::ustring>::vector_to_array (object_ids).data (),
        &(gerror));
    if (gerror)
      ::glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  Builder::get_cwidget (const glib::ustring& name) -> GtkWidget*
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
  Builder::get_widget_checked (const glib::ustring& name, GType type) -> gtk::Widget*
  {
    auto* cobject = get_cwidget (name);
    if (!cobject)
    {
      g_critical ("gtkmm: gtk::Builder: widget `%s' was not found in the "
                  "GtkBuilder file, or the "
                  "specified part of it.",
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

    return glib::wrap (GTK_WIDGET (cobject), false);
  }

} // namespace gtk

namespace
{
}

gtk::BuilderError::BuilderError (gtk::BuilderError::Code error_code,
                                 const glib::ustring& error_message)
  : glib::Error (GTK_BUILDER_ERROR, error_code, error_message)
{
}

gtk::BuilderError::BuilderError (GError* gobject)
  : glib::Error (gobject)
{
}

auto
gtk::BuilderError::code () const -> gtk::BuilderError::Code
{
  return static_cast<Code> (glib::Error::code ());
}

auto
gtk::BuilderError::throw_func (GError* gobject) -> void
{
  throw gtk::BuilderError (gobject);
}

auto
glib::Value<gtk::BuilderError::Code>::value_type () -> GType
{
  return gtk_builder_error_get_type ();
}

namespace glib
{

  auto
  wrap (GtkBuilder* object, bool take_copy) -> glib::RefPtr<gtk::Builder>
  {
    return glib::make_refptr_for_instance<gtk::Builder> (
        dynamic_cast<gtk::Builder*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  Builder_Class::init () -> const glib::Class&
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
  Builder_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Builder ((GtkBuilder*) object);
  }

  auto
  Builder::gobj_copy () -> GtkBuilder*
  {
    reference ();
    return gobj ();
  }

  Builder::Builder (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  Builder::Builder (GtkBuilder* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  Builder::Builder (Builder&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  Builder::operator= (Builder&& src) noexcept -> Builder&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  Builder::~Builder () noexcept {}

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
  Builder::create () -> glib::RefPtr<Builder>
  {
    return glib::make_refptr_for_instance<Builder> (new Builder ());
  }

  auto
  Builder::add_from_file (const std::string& filename) -> bool
  {
    GError* gerror = nullptr;
    auto retvalue =
        gtk_builder_add_from_file (gobj (), filename.c_str (), &(gerror));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Builder::add_from_file (const std::string& filename,
                          const std::vector<glib::ustring>& object_ids) -> bool
  {
    GError* gerror = nullptr;
    auto retvalue = gtk_builder_add_objects_from_file (
        gobj (),
        filename.c_str (),
        glib::ArrayHandler<glib::ustring>::vector_to_array (object_ids).data (),
        &(gerror));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Builder::add_from_resource (const std::string& resource_path) -> bool
  {
    GError* gerror = nullptr;
    auto retvalue = gtk_builder_add_from_resource (gobj (),
                                                   resource_path.c_str (),
                                                   &(gerror));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Builder::add_from_resource (const std::string& resource_path,
                              const std::vector<glib::ustring>& object_ids) -> bool
  {
    GError* gerror = nullptr;
    auto retvalue = gtk_builder_add_objects_from_resource (
        gobj (),
        resource_path.c_str (),
        glib::ArrayHandler<glib::ustring>::vector_to_array (object_ids).data (),
        &(gerror));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Builder::add_from_string (const char* buffer, gssize length) -> bool
  {
    GError* gerror = nullptr;
    auto retvalue =
        gtk_builder_add_from_string (gobj (), buffer, length, &(gerror));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Builder::expose_object (const glib::ustring& name,
                          const glib::RefPtr<glib::Object>& object) -> void
  {
    gtk_builder_expose_object (gobj (), name.c_str (), glib::unwrap (object));
  }

  auto
  Builder::expose_widget (const glib::ustring& name, Widget& widget) -> void
  {
    gtk_builder_expose_object (gobj (),
                               name.c_str (),
                               G_OBJECT ((widget).gobj ()));
  }

  auto
  Builder::get_object (const glib::ustring& name) -> glib::RefPtr<glib::Object>
  {
    auto retvalue =
        glib::wrap (gtk_builder_get_object (gobj (), name.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Builder::get_object (const glib::ustring& name) const -> glib::RefPtr<const glib::Object>
  {
    return const_cast<Builder*> (this)->get_object (name);
  }

  auto
  Builder::get_objects () -> std::vector<glib::RefPtr<glib::Object>>
  {
    return glib::SListHandler<glib::RefPtr<glib::Object>>::slist_to_vector (
        gtk_builder_get_objects (gobj ()),
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  Builder::get_objects () const -> std::vector<glib::RefPtr<const glib::Object>>
  {
    return glib::SListHandler<glib::RefPtr<const glib::Object>>::
        slist_to_vector (
            gtk_builder_get_objects (const_cast<GtkBuilder*> (gobj ())),
            glib::OWNERSHIP_SHALLOW);
  }

  auto
  Builder::set_translation_domain (const glib::ustring& domain) -> void
  {
    gtk_builder_set_translation_domain (gobj (), domain.c_str ());
  }

  auto
  Builder::get_translation_domain () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_builder_get_translation_domain (const_cast<GtkBuilder*> (gobj ())));
  }

  auto
  Builder::property_translation_domain () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "translation-domain");
  }

  auto
  Builder::property_translation_domain () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this,
                                                        "translation-domain");
  }

} // namespace gtk
