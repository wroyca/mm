// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/recentmanager.hxx>
#include <libmm/gtk/recentmanager_p.hxx>

#include <libmm/glib/vectorutils.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  auto
  RecentManager::add_item (const glib::ustring& uri, const Data& data) -> bool
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

} // namespace gtk

namespace
{

  static const glib::SignalProxyInfo RecentManager_signal_changed_info = {
      "changed",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

}

gtk::RecentManagerError::RecentManagerError (
    gtk::RecentManagerError::Code error_code,
    const glib::ustring& error_message)
  : glib::Error (GTK_RECENT_MANAGER_ERROR, error_code, error_message)
{
}

gtk::RecentManagerError::RecentManagerError (GError* gobject)
  : glib::Error (gobject)
{
}

auto
gtk::RecentManagerError::code () const -> gtk::RecentManagerError::Code
{
  return static_cast<Code> (glib::Error::code ());
}

auto
gtk::RecentManagerError::throw_func (GError* gobject) -> void
{
  throw gtk::RecentManagerError (gobject);
}

auto
glib::Value<gtk::RecentManagerError::Code>::value_type () -> GType
{
  return gtk_recent_manager_error_get_type ();
}

namespace glib
{

  auto
  wrap (GtkRecentManager* object, bool take_copy) -> glib::RefPtr<gtk::RecentManager>
  {
    return glib::make_refptr_for_instance<gtk::RecentManager> (
        dynamic_cast<gtk::RecentManager*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  RecentManager_Class::init () -> const glib::Class&
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
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

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
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->changed)
      (*base->changed) (self);
  }

  auto
  RecentManager_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new RecentManager ((GtkRecentManager*) object);
  }

  auto
  RecentManager::gobj_copy () -> GtkRecentManager*
  {
    reference ();
    return gobj ();
  }

  RecentManager::RecentManager (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  RecentManager::RecentManager (GtkRecentManager* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  RecentManager::RecentManager (RecentManager&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  RecentManager::operator= (RecentManager&& src) noexcept -> RecentManager&
  {
    glib::Object::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (recentmanager_class_.init ()))
  {
  }

  auto
  RecentManager::create () -> glib::RefPtr<RecentManager>
  {
    return glib::make_refptr_for_instance<RecentManager> (new RecentManager ());
  }

  auto
  RecentManager::get_default () -> glib::RefPtr<RecentManager>
  {
    auto retvalue = glib::wrap (gtk_recent_manager_get_default ());
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  RecentManager::add_item (const glib::ustring& uri) -> bool
  {
    GError* gerror = nullptr;
    auto retvalue = gtk_recent_manager_add_item (gobj (), uri.c_str ());
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  RecentManager::remove_item (const glib::ustring& uri) -> bool
  {
    GError* gerror = nullptr;
    auto retvalue =
        gtk_recent_manager_remove_item (gobj (), uri.c_str (), &(gerror));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  RecentManager::lookup_item (const glib::ustring& uri) -> glib::RefPtr<RecentInfo>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (
        gtk_recent_manager_lookup_item (gobj (), uri.c_str (), &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  RecentManager::lookup_item (const glib::ustring& uri) const -> glib::RefPtr<const RecentInfo>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (
        gtk_recent_manager_lookup_item (const_cast<GtkRecentManager*> (gobj ()),
                                        uri.c_str (),
                                        &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  RecentManager::has_item (const glib::ustring& uri) const -> bool
  {
    return gtk_recent_manager_has_item (const_cast<GtkRecentManager*> (gobj ()),
                                        uri.c_str ());
  }

  auto
  RecentManager::move_item (const glib::ustring& uri,
                            const glib::ustring& new_uri) -> bool
  {
    GError* gerror = nullptr;
    auto retvalue = gtk_recent_manager_move_item (gobj (),
                                                  uri.c_str (),
                                                  new_uri.c_str (),
                                                  &(gerror));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  RecentManager::get_items () const -> std::vector<glib::RefPtr<RecentInfo>>
  {
    return glib::ListHandler<glib::RefPtr<RecentInfo>, RecentInfoTraits>::
        list_to_vector (gtk_recent_manager_get_items (
                            const_cast<GtkRecentManager*> (gobj ())),
                        glib::OWNERSHIP_DEEP);
  }

  auto
  RecentManager::purge_items () -> int
  {
    GError* gerror = nullptr;
    auto retvalue = gtk_recent_manager_purge_items (gobj (), &(gerror));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  RecentManager::signal_changed () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this,
                                       &RecentManager_signal_changed_info);
  }

  auto
  RecentManager::property_filename () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "filename");
  }

  auto
  RecentManager::property_size () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "size");
  }

  auto
  gtk::RecentManager::on_changed () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->changed)
      (*base->changed) (gobj ());
  }

} // namespace gtk
