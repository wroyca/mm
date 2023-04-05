// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/filefilter.hxx>
#include <libmm/gtk/filefilter_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkFileFilter* object, bool take_copy) -> glib::RefPtr<gtk::FileFilter>
  {
    return glib::make_refptr_for_instance<gtk::FileFilter> (
        dynamic_cast<gtk::FileFilter*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  FileFilter_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FileFilter_Class::class_init_function;

      register_derived_type (gtk_file_filter_get_type ());

      Buildable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  FileFilter_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  FileFilter_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new FileFilter ((GtkFileFilter*) object);
  }

  auto
  FileFilter::gobj_copy () -> GtkFileFilter*
  {
    reference ();
    return gobj ();
  }

  FileFilter::FileFilter (const glib::ConstructParams& construct_params)
    : gtk::Filter (construct_params)
  {
  }

  FileFilter::FileFilter (GtkFileFilter* castitem)
    : gtk::Filter ((GtkFilter*) (castitem))
  {
  }

  FileFilter::FileFilter (FileFilter&& src) noexcept
    : gtk::Filter (std::move (src)),
      Buildable (std::move (src))
  {
  }

  auto
  FileFilter::operator= (FileFilter&& src) noexcept -> FileFilter&
  {
    gtk::Filter::operator= (std::move (src));
    Buildable::operator= (std::move (src));
    return *this;
  }

  FileFilter::~FileFilter () noexcept {}

  FileFilter::CppClassType FileFilter::filefilter_class_;

  auto
  FileFilter::get_type () -> GType
  {
    return filefilter_class_.init ().get_type ();
  }

  auto
  FileFilter::get_base_type () -> GType
  {
    return gtk_file_filter_get_type ();
  }

  FileFilter::FileFilter ()
    : glib::ObjectBase (nullptr),
      gtk::Filter (glib::ConstructParams (filefilter_class_.init ()))
  {
  }

  auto
  FileFilter::create () -> glib::RefPtr<FileFilter>
  {
    return glib::make_refptr_for_instance<FileFilter> (new FileFilter ());
  }

  auto
  FileFilter::set_name (const glib::ustring& name) -> void
  {
    gtk_file_filter_set_name (gobj (), name.c_str ());
  }

  auto
  FileFilter::get_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_file_filter_get_name (const_cast<GtkFileFilter*> (gobj ())));
  }

  auto
  FileFilter::add_mime_type (const glib::ustring& mime_type) -> void
  {
    gtk_file_filter_add_mime_type (gobj (), mime_type.c_str ());
  }

  auto
  FileFilter::add_pattern (const glib::ustring& pattern) -> void
  {
    gtk_file_filter_add_pattern (gobj (), pattern.c_str ());
  }

  auto
  FileFilter::add_suffix (const std::string& suffix) -> void
  {
    gtk_file_filter_add_suffix (gobj (), suffix.c_str ());
  }

  auto
  FileFilter::add_pixbuf_formats () -> void
  {
    gtk_file_filter_add_pixbuf_formats (gobj ());
  }

  auto
  FileFilter::property_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "name");
  }

  auto
  FileFilter::property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "name");
  }

} // namespace gtk
