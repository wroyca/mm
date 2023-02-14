// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/filefilter.hxx>
#include <libmm-gtk/filefilter_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkFileFilter* object, const bool take_copy) -> RefPtr<Gtk::FileFilter>
  {
    return Glib::make_refptr_for_instance<Gtk::FileFilter> (
        dynamic_cast<Gtk::FileFilter*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  FileFilter_Class::init () -> const Class&
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
  FileFilter_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new FileFilter ((GtkFileFilter*) object);
  }

  auto
  FileFilter::gobj_copy () -> GtkFileFilter*
  {
    reference ();
    return gobj ();
  }

  FileFilter::FileFilter (const Glib::ConstructParams& construct_params)
    : Filter (construct_params)
  {
  }

  FileFilter::FileFilter (GtkFileFilter* castitem)
    : Filter ((GtkFilter*) castitem)
  {
  }

  FileFilter::FileFilter (FileFilter&& src) noexcept
    : Filter (std::move (src)),
      Buildable (std::move (src))
  {
  }

  auto
  FileFilter::operator= (FileFilter&& src) noexcept -> FileFilter&
  {
    Filter::operator= (std::move (src));
    Buildable::operator= (std::move (src));
    return *this;
  }

  FileFilter::~FileFilter () noexcept = default;

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
    : ObjectBase (nullptr),
      Filter (Glib::ConstructParams (filefilter_class_.init ()))
  {
  }

  auto
  FileFilter::create () -> Glib::RefPtr<FileFilter>
  {
    return Glib::make_refptr_for_instance<FileFilter> (new FileFilter ());
  }

  auto
  FileFilter::set_name (const Glib::ustring& name) -> void
  {
    gtk_file_filter_set_name (gobj (), name.c_str ());
  }

  auto
  FileFilter::get_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_file_filter_get_name (const_cast<GtkFileFilter*> (gobj ())));
  }

  auto
  FileFilter::add_mime_type (const Glib::ustring& mime_type) -> void
  {
    gtk_file_filter_add_mime_type (gobj (), mime_type.c_str ());
  }

  auto
  FileFilter::add_pattern (const Glib::ustring& pattern) -> void
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
  FileFilter::property_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return {this, "name"};
  }

  auto
  FileFilter::property_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "name"};
  }

} // namespace Gtk
