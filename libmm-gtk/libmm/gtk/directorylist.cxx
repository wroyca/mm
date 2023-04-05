// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/directorylist.hxx>
#include <libmm/gtk/directorylist_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkDirectoryList* object, bool take_copy) -> glib::RefPtr<gtk::DirectoryList>
  {
    return glib::make_refptr_for_instance<gtk::DirectoryList> (
        dynamic_cast<gtk::DirectoryList*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  DirectoryList_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &DirectoryList_Class::class_init_function;

      gtype_ = gtk_directory_list_get_type ();
    }

    return *this;
  }

  auto
  DirectoryList_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  DirectoryList_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new DirectoryList ((GtkDirectoryList*) object);
  }

  auto
  DirectoryList::gobj_copy () -> GtkDirectoryList*
  {
    reference ();
    return gobj ();
  }

  DirectoryList::DirectoryList (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  DirectoryList::DirectoryList (GtkDirectoryList* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  DirectoryList::DirectoryList (DirectoryList&& src) noexcept
    : glib::Object (std::move (src)),
      gio::ListModel (std::move (src))
  {
  }

  auto
  DirectoryList::operator= (DirectoryList&& src) noexcept -> DirectoryList&
  {
    glib::Object::operator= (std::move (src));
    gio::ListModel::operator= (std::move (src));
    return *this;
  }

  DirectoryList::~DirectoryList () noexcept {}

  DirectoryList::CppClassType DirectoryList::directorylist_class_;

  auto
  DirectoryList::get_type () -> GType
  {
    return directorylist_class_.init ().get_type ();
  }

  auto
  DirectoryList::get_base_type () -> GType
  {
    return gtk_directory_list_get_type ();
  }

  DirectoryList::DirectoryList (const std::string& attributes,
                                const glib::RefPtr<gio::File>& file)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (
          directorylist_class_.init (),
          "attributes",
          attributes.c_str (),
          "file",
          const_cast<GFile*> (glib::unwrap<gio::File> (file)),
          nullptr))
  {
  }

  auto
  DirectoryList::create (const std::string& attributes,
                         const glib::RefPtr<gio::File>& file) -> glib::RefPtr<DirectoryList>
  {
    return glib::make_refptr_for_instance<DirectoryList> (
        new DirectoryList (attributes, file));
  }

  auto
  DirectoryList::set_file (const glib::RefPtr<gio::File>& file) -> void
  {
    gtk_directory_list_set_file (
        gobj (),
        const_cast<GFile*> (glib::unwrap<gio::File> (file)));
  }

  auto
  DirectoryList::get_file () -> glib::RefPtr<gio::File>
  {
    auto retvalue = glib::wrap (gtk_directory_list_get_file (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DirectoryList::get_file () const -> glib::RefPtr<const gio::File>
  {
    return const_cast<DirectoryList*> (this)->get_file ();
  }

  auto
  DirectoryList::set_attributes (const std::string& attributes) -> void
  {
    gtk_directory_list_set_attributes (gobj (), attributes.c_str ());
  }

  auto
  DirectoryList::get_attributes () const -> std::string
  {
    return glib::convert_const_gchar_ptr_to_stdstring (
        gtk_directory_list_get_attributes (
            const_cast<GtkDirectoryList*> (gobj ())));
  }

  auto
  DirectoryList::set_io_priority (int io_priority) -> void
  {
    gtk_directory_list_set_io_priority (gobj (), io_priority);
  }

  auto
  DirectoryList::get_io_priority () const -> int
  {
    return gtk_directory_list_get_io_priority (
        const_cast<GtkDirectoryList*> (gobj ()));
  }

  auto
  DirectoryList::is_loading () const -> bool
  {
    return gtk_directory_list_is_loading (
        const_cast<GtkDirectoryList*> (gobj ()));
  }

  auto
  DirectoryList::get_error () const -> glib::Error
  {
    return glib::Error (const_cast<GError*> (gtk_directory_list_get_error (
                            const_cast<GtkDirectoryList*> (gobj ()))),
                        true);
  }

  auto
  DirectoryList::set_monitored (bool monitored) -> void
  {
    gtk_directory_list_set_monitored (gobj (), static_cast<int> (monitored));
  }

  auto
  DirectoryList::get_monitored () const -> bool
  {
    return gtk_directory_list_get_monitored (
        const_cast<GtkDirectoryList*> (gobj ()));
  }

  auto
  DirectoryList::property_attributes () -> glib::PropertyProxy<std::string>
  {
    return glib::PropertyProxy<std::string> (this, "attributes");
  }

  auto
  DirectoryList::property_attributes () const -> glib::PropertyProxy_ReadOnly<std::string>
  {
    return glib::PropertyProxy_ReadOnly<std::string> (this, "attributes");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<glib::Error>::value,
      "Type glib::Error cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  DirectoryList::property_error () const -> glib::PropertyProxy_ReadOnly<glib::Error>
  {
    return glib::PropertyProxy_ReadOnly<glib::Error> (this, "error");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::File>>::value,
      "Type glib::RefPtr<gio::File> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  DirectoryList::property_file () -> glib::PropertyProxy<glib::RefPtr<gio::File>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::File>> (this, "file");
  }

  auto
  DirectoryList::property_file () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::File>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::File>> (this, "file");
  }

  auto
  DirectoryList::property_io_priority () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "io-priority");
  }

  auto
  DirectoryList::property_io_priority () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "io-priority");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
      "Type GType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  DirectoryList::property_item_type () const -> glib::PropertyProxy_ReadOnly<GType>
  {
    return glib::PropertyProxy_ReadOnly<GType> (this, "item-type");
  }

  auto
  DirectoryList::property_loading () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "loading");
  }

  auto
  DirectoryList::property_monitored () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "monitored");
  }

  auto
  DirectoryList::property_monitored () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "monitored");
  }

  auto
  DirectoryList::property_n_items () const -> glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return glib::PropertyProxy_ReadOnly<unsigned int> (this, "n-items");
  }

} // namespace gtk
