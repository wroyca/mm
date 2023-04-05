// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/stringlist.hxx>
#include <libmm/gtk/stringlist_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  StringList::StringList (const std::vector<glib::ustring>& strings)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (stringlist_class_.init ()))
  {
    gtk_string_list_splice (
        gobj (),
        0,
        0,
        glib::ArrayHandler<glib::ustring>::vector_to_array (strings).data ());
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkStringList* object, bool take_copy) -> glib::RefPtr<gtk::StringList>
  {
    return glib::make_refptr_for_instance<gtk::StringList> (
        dynamic_cast<gtk::StringList*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  StringList_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &StringList_Class::class_init_function;

      gtype_ = gtk_string_list_get_type ();
    }

    return *this;
  }

  auto
  StringList_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  StringList_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new StringList ((GtkStringList*) object);
  }

  auto
  StringList::gobj_copy () -> GtkStringList*
  {
    reference ();
    return gobj ();
  }

  StringList::StringList (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  StringList::StringList (GtkStringList* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  StringList::StringList (StringList&& src) noexcept
    : glib::Object (std::move (src)),
      gio::ListModel (std::move (src)),
      Buildable (std::move (src))
  {
  }

  auto
  StringList::operator= (StringList&& src) noexcept -> StringList&
  {
    glib::Object::operator= (std::move (src));
    gio::ListModel::operator= (std::move (src));
    Buildable::operator= (std::move (src));
    return *this;
  }

  StringList::~StringList () noexcept {}

  StringList::CppClassType StringList::stringlist_class_;

  auto
  StringList::get_type () -> GType
  {
    return stringlist_class_.init ().get_type ();
  }

  auto
  StringList::get_base_type () -> GType
  {
    return gtk_string_list_get_type ();
  }

  auto
  StringList::create (const std::vector<glib::ustring>& strings) -> glib::RefPtr<StringList>
  {
    return glib::make_refptr_for_instance<StringList> (
        new StringList (strings));
  }

  auto
  StringList::append (const glib::ustring& string) -> void
  {
    gtk_string_list_append (gobj (), string.c_str ());
  }

  auto
  StringList::remove (guint position) -> void
  {
    gtk_string_list_remove (gobj (), position);
  }

  auto
  StringList::splice (guint position,
                      guint n_removals,
                      const std::vector<glib::ustring>& additions) -> void
  {
    gtk_string_list_splice (
        gobj (),
        position,
        n_removals,
        glib::ArrayHandler<glib::ustring>::vector_to_array (additions).data ());
  }

  auto
  StringList::get_string (guint position) const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_string_list_get_string (const_cast<GtkStringList*> (gobj ()),
                                    position));
  }

} // namespace gtk
