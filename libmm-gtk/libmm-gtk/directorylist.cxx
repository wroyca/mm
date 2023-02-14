// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/directorylist.hxx>
#include <libmm-gtk/directorylist_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkDirectoryList* object, const bool take_copy) -> RefPtr<Gtk::DirectoryList>
  {
    return Glib::make_refptr_for_instance<Gtk::DirectoryList> (
        dynamic_cast<Gtk::DirectoryList*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  DirectoryList_Class::init () -> const Class&
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
  DirectoryList_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new DirectoryList ((GtkDirectoryList*) object);
  }

  auto
  DirectoryList::gobj_copy () -> GtkDirectoryList*
  {
    reference ();
    return gobj ();
  }

  DirectoryList::DirectoryList (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  DirectoryList::DirectoryList (GtkDirectoryList* castitem)
    : Object ((GObject*) castitem)
  {
  }

  DirectoryList::DirectoryList (DirectoryList&& src) noexcept
    : Object (std::move (src)),
      ListModel (std::move (src))
  {
  }

  auto
  DirectoryList::operator= (DirectoryList&& src) noexcept -> DirectoryList&
  {
    Object::operator= (std::move (src));
    ListModel::operator= (std::move (src));
    return *this;
  }

  DirectoryList::~DirectoryList () noexcept = default;

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
                                const Glib::RefPtr<Gio::File>& file)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (directorylist_class_.init (),
                                     "attributes",
                                     attributes.c_str (),
                                     "file",
                                     Glib::unwrap<Gio::File> (file),
                                     nullptr))
  {
  }

  auto
  DirectoryList::create (const std::string& attributes,
                         const Glib::RefPtr<Gio::File>& file) -> Glib::RefPtr<DirectoryList>
  {
    return Glib::make_refptr_for_instance<DirectoryList> (
        new DirectoryList (attributes, file));
  }

  auto
  DirectoryList::set_file (const Glib::RefPtr<Gio::File>& file) -> void
  {
    gtk_directory_list_set_file (gobj (), Glib::unwrap<Gio::File> (file));
  }

  auto
  DirectoryList::get_file () -> Glib::RefPtr<Gio::File>
  {
    auto retvalue = Glib::wrap (gtk_directory_list_get_file (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DirectoryList::get_file () const -> Glib::RefPtr<const Gio::File>
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
    return Glib::convert_const_gchar_ptr_to_stdstring (
        gtk_directory_list_get_attributes (
            const_cast<GtkDirectoryList*> (gobj ())));
  }

  auto
  DirectoryList::set_io_priority (const int io_priority) -> void
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
  DirectoryList::get_error () const -> Glib::Error
  {
    return Glib::Error (const_cast<GError*> (gtk_directory_list_get_error (
                            const_cast<GtkDirectoryList*> (gobj ()))),
                        true);
  }

  auto
  DirectoryList::set_monitored (const bool monitored) -> void
  {
    gtk_directory_list_set_monitored (gobj (), monitored);
  }

  auto
  DirectoryList::get_monitored () const -> bool
  {
    return gtk_directory_list_get_monitored (
        const_cast<GtkDirectoryList*> (gobj ()));
  }

  auto
  DirectoryList::property_attributes () -> Glib::PropertyProxy<std::string>
  {
    return {this, "attributes"};
  }

  auto
  DirectoryList::property_attributes () const -> Glib::PropertyProxy_ReadOnly<std::string>
  {
    return {this, "attributes"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Glib::Error>::value,
      "Type Glib::Error cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  DirectoryList::property_error () const -> Glib::PropertyProxy_ReadOnly<Glib::Error>
  {
    return {this, "error"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::File>>::value,
      "Type Glib::RefPtr<Gio::File> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  DirectoryList::property_file () -> Glib::PropertyProxy<Glib::RefPtr<Gio::File>>
  {
    return {this, "file"};
  }

  auto
  DirectoryList::property_file () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::File>>
  {
    return {this, "file"};
  }

  auto
  DirectoryList::property_io_priority () -> Glib::PropertyProxy<int>
  {
    return {this, "io-priority"};
  }

  auto
  DirectoryList::property_io_priority () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "io-priority"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
      "Type GType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  DirectoryList::property_item_type () const -> Glib::PropertyProxy_ReadOnly<GType>
  {
    return {this, "item-type"};
  }

  auto
  DirectoryList::property_loading () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "loading"};
  }

  auto
  DirectoryList::property_monitored () -> Glib::PropertyProxy<bool>
  {
    return {this, "monitored"};
  }

  auto
  DirectoryList::property_monitored () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "monitored"};
  }

  auto
  DirectoryList::property_n_items () const -> Glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return {this, "n-items"};
  }

} // namespace Gtk
