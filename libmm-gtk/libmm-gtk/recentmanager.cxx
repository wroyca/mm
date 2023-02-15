// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/recentmanager.hxx>
#include <libmm-gtk/recentmanager_p.hxx>

#include <libmm-glib/vectorutils.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  auto
  RecentManager::add_item (const Glib::ustring& uri, const Data& data) -> bool
  {
    GtkRecentData c_data;
    gboolean result;

    c_data.display_name = data.display_name.empty () ?
                              nullptr :
                              const_cast<char*> (data.display_name.c_str ());
    c_data.description = const_cast<char*> (data.description.c_str ());
    c_data.mime_type = const_cast<char*> (data.mime_type.c_str ());
    c_data.app_name = const_cast<char*> (data.app_name.c_str ());
    c_data.app_exec = const_cast<char*> (data.app_exec.c_str ());

    c_data.groups = static_cast<char**> (
        g_malloc ((data.groups.size () + 1) * sizeof (char*)));
    for (unsigned int i = 0; i < data.groups.size (); ++i)
      c_data.groups[i] = const_cast<char*> (data.groups[i].c_str ());
    c_data.groups[data.groups.size ()] = nullptr;

    c_data.is_private = data.is_private;

    result = gtk_recent_manager_add_full (gobj (), uri.c_str (), &c_data);
    g_free (c_data.groups);
    return result == TRUE;
  }

} // namespace Gtk

namespace
{

  static const Glib::SignalProxyInfo RecentManager_signal_changed_info = {
      "changed",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

}

Gtk::RecentManagerError::RecentManagerError (
    Gtk::RecentManagerError::Code error_code,
    const Glib::ustring& error_message)
  : Glib::Error (GTK_RECENT_MANAGER_ERROR, error_code, error_message)
{
}

Gtk::RecentManagerError::RecentManagerError (GError* gobject)
  : Glib::Error (gobject)
{
}

auto
Gtk::RecentManagerError::code () const -> Gtk::RecentManagerError::Code
{
  return static_cast<Code> (Glib::Error::code ());
}

auto
Gtk::RecentManagerError::throw_func (GError* gobject) -> void
{
  throw Gtk::RecentManagerError (gobject);
}

auto
Glib::Value<Gtk::RecentManagerError::Code>::value_type () -> GType
{
  return gtk_recent_manager_error_get_type ();
}

namespace Glib
{

  auto
  wrap (GtkRecentManager* object, bool take_copy) -> Glib::RefPtr<Gtk::RecentManager>
  {
    return Glib::make_refptr_for_instance<Gtk::RecentManager> (
        dynamic_cast<Gtk::RecentManager*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  RecentManager_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &RecentManager_Class::class_init_function;

      register_derived_type (gtk_recent_manager_get_type ());
    }

    return *this;
  }

  auto
  RecentManager_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->changed = &changed_callback;
  }

  auto
  RecentManager_Class::changed_callback (GtkRecentManager* self) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_changed ();
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->changed)
      (*base->changed) (self);
  }

  auto
  RecentManager_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new RecentManager ((GtkRecentManager*) object);
  }

  auto
  RecentManager::gobj_copy () -> GtkRecentManager*
  {
    reference ();
    return gobj ();
  }

  RecentManager::RecentManager (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  RecentManager::RecentManager (GtkRecentManager* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  RecentManager::RecentManager (RecentManager&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  RecentManager::operator= (RecentManager&& src) noexcept -> RecentManager&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  RecentManager::~RecentManager () noexcept {}

  RecentManager::CppClassType RecentManager::recentmanager_class_;

  auto
  RecentManager::get_type () -> GType
  {
    return recentmanager_class_.init ().get_type ();
  }

  auto
  RecentManager::get_base_type () -> GType
  {
    return gtk_recent_manager_get_type ();
  }

  RecentManager::RecentManager ()
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (recentmanager_class_.init ()))
  {
  }

  auto
  RecentManager::create () -> Glib::RefPtr<RecentManager>
  {
    return Glib::make_refptr_for_instance<RecentManager> (new RecentManager ());
  }

  auto
  RecentManager::get_default () -> Glib::RefPtr<RecentManager>
  {
    auto retvalue = Glib::wrap (gtk_recent_manager_get_default ());
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  RecentManager::add_item (const Glib::ustring& uri) -> bool
  {
    GError* gerror = nullptr;
    auto retvalue = gtk_recent_manager_add_item (gobj (), uri.c_str ());
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  RecentManager::remove_item (const Glib::ustring& uri) -> bool
  {
    GError* gerror = nullptr;
    auto retvalue =
        gtk_recent_manager_remove_item (gobj (), uri.c_str (), &(gerror));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  RecentManager::lookup_item (const Glib::ustring& uri) -> Glib::RefPtr<RecentInfo>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        gtk_recent_manager_lookup_item (gobj (), uri.c_str (), &(gerror)));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  RecentManager::lookup_item (const Glib::ustring& uri) const -> Glib::RefPtr<const RecentInfo>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        gtk_recent_manager_lookup_item (const_cast<GtkRecentManager*> (gobj ()),
                                        uri.c_str (),
                                        &(gerror)));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  RecentManager::has_item (const Glib::ustring& uri) const -> bool
  {
    return gtk_recent_manager_has_item (const_cast<GtkRecentManager*> (gobj ()),
                                        uri.c_str ());
  }

  auto
  RecentManager::move_item (const Glib::ustring& uri,
                            const Glib::ustring& new_uri) -> bool
  {
    GError* gerror = nullptr;
    auto retvalue = gtk_recent_manager_move_item (gobj (),
                                                  uri.c_str (),
                                                  new_uri.c_str (),
                                                  &(gerror));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  RecentManager::get_items () const -> std::vector<Glib::RefPtr<RecentInfo>>
  {
    return Glib::ListHandler<Glib::RefPtr<RecentInfo>, RecentInfoTraits>::
        list_to_vector (gtk_recent_manager_get_items (
                            const_cast<GtkRecentManager*> (gobj ())),
                        Glib::OWNERSHIP_DEEP);
  }

  auto
  RecentManager::purge_items () -> int
  {
    GError* gerror = nullptr;
    auto retvalue = gtk_recent_manager_purge_items (gobj (), &(gerror));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  RecentManager::signal_changed () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this,
                                       &RecentManager_signal_changed_info);
  }

  auto
  RecentManager::property_filename () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "filename");
  }

  auto
  RecentManager::property_size () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "size");
  }

  auto
  Gtk::RecentManager::on_changed () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->changed)
      (*base->changed) (gobj ());
  }

} // namespace Gtk
