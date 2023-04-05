// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/stringobject.hxx>
#include <libmm/gtk/stringobject_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkStringObject* object, bool take_copy) -> glib::RefPtr<gtk::StringObject>
  {
    return glib::make_refptr_for_instance<gtk::StringObject> (
        dynamic_cast<gtk::StringObject*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  StringObject_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &StringObject_Class::class_init_function;

      gtype_ = gtk_string_object_get_type ();
    }

    return *this;
  }

  auto
  StringObject_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  StringObject_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new StringObject ((GtkStringObject*) object);
  }

  auto
  StringObject::gobj_copy () -> GtkStringObject*
  {
    reference ();
    return gobj ();
  }

  StringObject::StringObject (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  StringObject::StringObject (GtkStringObject* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  StringObject::StringObject (StringObject&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  StringObject::operator= (StringObject&& src) noexcept -> StringObject&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  StringObject::~StringObject () noexcept {}

  StringObject::CppClassType StringObject::stringobject_class_;

  auto
  StringObject::get_type () -> GType
  {
    return stringobject_class_.init ().get_type ();
  }

  auto
  StringObject::get_base_type () -> GType
  {
    return gtk_string_object_get_type ();
  }

  auto
  StringObject::create (const glib::ustring& string) -> glib::RefPtr<StringObject>
  {
    return glib::wrap (gtk_string_object_new (string.c_str ()));
  }

  auto
  StringObject::get_string () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_string_object_get_string (const_cast<GtkStringObject*> (gobj ())));
  }

  auto
  StringObject::property_string () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "string");
  }

} // namespace gtk
