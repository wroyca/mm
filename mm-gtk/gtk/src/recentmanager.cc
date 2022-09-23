// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gtkmm/recentmanager.h>
#include <gtkmm/private/recentmanager_p.h>


/* Copyright (C) 2006 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <glibmm/vectorutils.h>

#include <gtk/gtk.h>

namespace Gtk
{

bool RecentManager::add_item(const Glib::ustring& uri, const Data& data)
{
  GtkRecentData c_data;
  gboolean result;

  // I wonder whether these should be const in the GTK+ API. armin.
  c_data.display_name = data.display_name.empty() ? nullptr : const_cast<char*>(data.display_name.c_str());
  c_data.description = const_cast<char*>(data.description.c_str());
  c_data.mime_type = const_cast<char*>(data.mime_type.c_str());
  c_data.app_name = const_cast<char*>(data.app_name.c_str());
  c_data.app_exec = const_cast<char*>(data.app_exec.c_str());

  c_data.groups = static_cast<char**>(g_malloc((data.groups.size() + 1) * sizeof(char*)));
  for(unsigned int i = 0; i < data.groups.size(); ++ i)
    c_data.groups[i] = const_cast<char*>(data.groups[i].c_str());
  c_data.groups[data.groups.size()] = nullptr;

  c_data.is_private = data.is_private;

  result = gtk_recent_manager_add_full(gobj(), uri.c_str(), &c_data);
  g_free(c_data.groups);
  return result == TRUE;
}

} //namespace Gtk

namespace
{


static const Glib::SignalProxyInfo RecentManager_signal_changed_info =
{
  "changed",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


Gtk::RecentManagerError::RecentManagerError(Gtk::RecentManagerError::Code error_code, const Glib::ustring& error_message)
:
  Glib::Error (GTK_RECENT_MANAGER_ERROR, error_code, error_message)
{}

Gtk::RecentManagerError::RecentManagerError(GError* gobject)
:
  Glib::Error (gobject)
{}

Gtk::RecentManagerError::Code Gtk::RecentManagerError::code() const
{
  return static_cast<Code>(Glib::Error::code());
}

void Gtk::RecentManagerError::throw_func(GError* gobject)
{
  throw Gtk::RecentManagerError(gobject);
}

// static
GType Glib::Value<Gtk::RecentManagerError::Code>::value_type()
{
  return gtk_recent_manager_error_get_type();
}


namespace Glib
{

Glib::RefPtr<Gtk::RecentManager> wrap(GtkRecentManager* object, bool take_copy)
{
  return Glib::make_refptr_for_instance<Gtk::RecentManager>( dynamic_cast<Gtk::RecentManager*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& RecentManager_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &RecentManager_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_recent_manager_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void RecentManager_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


  klass->changed = &changed_callback;
}


void RecentManager_Class::changed_callback(GtkRecentManager* self)
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_changed();
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->changed)
    (*base->changed)(self);
}


Glib::ObjectBase* RecentManager_Class::wrap_new(GObject* object)
{
  return new RecentManager((GtkRecentManager*)object);
}


/* The implementation: */

GtkRecentManager* RecentManager::gobj_copy()
{
  reference();
  return gobj();
}

RecentManager::RecentManager(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

RecentManager::RecentManager(GtkRecentManager* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


RecentManager::RecentManager(RecentManager&& src) noexcept
: Glib::Object(std::move(src))
{}

RecentManager& RecentManager::operator=(RecentManager&& src) noexcept
{
  Glib::Object::operator=(std::move(src));
  return *this;
}


RecentManager::~RecentManager() noexcept
{}


RecentManager::CppClassType RecentManager::recentmanager_class_; // initialize static member

GType RecentManager::get_type()
{
  return recentmanager_class_.init().get_type();
}


GType RecentManager::get_base_type()
{
  return gtk_recent_manager_get_type();
}


RecentManager::RecentManager()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Glib::Object(Glib::ConstructParams(recentmanager_class_.init()))
{
  

}

Glib::RefPtr<RecentManager> RecentManager::create()
{
  return Glib::make_refptr_for_instance<RecentManager>( new RecentManager() );
}

Glib::RefPtr<RecentManager> RecentManager::get_default()
{

  auto retvalue = Glib::wrap(gtk_recent_manager_get_default());
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us
  return retvalue;
}

bool RecentManager::add_item(const Glib::ustring& uri)
{
  GError* gerror = nullptr;
  auto retvalue = gtk_recent_manager_add_item(gobj(), uri.c_str());
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool RecentManager::remove_item(const Glib::ustring& uri)
{
  GError* gerror = nullptr;
  auto retvalue = gtk_recent_manager_remove_item(gobj(), uri.c_str(), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

Glib::RefPtr<RecentInfo> RecentManager::lookup_item(const Glib::ustring& uri)
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(gtk_recent_manager_lookup_item(gobj(), uri.c_str(), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

Glib::RefPtr<const RecentInfo> RecentManager::lookup_item(const Glib::ustring& uri) const
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(gtk_recent_manager_lookup_item(const_cast<GtkRecentManager*>(gobj()), uri.c_str(), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool RecentManager::has_item(const Glib::ustring& uri) const
{
  return gtk_recent_manager_has_item(const_cast<GtkRecentManager*>(gobj()), uri.c_str());
}

bool RecentManager::move_item(const Glib::ustring& uri, const Glib::ustring& new_uri)
{
  GError* gerror = nullptr;
  auto retvalue = gtk_recent_manager_move_item(gobj(), uri.c_str(), new_uri.c_str(), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

std::vector<Glib::RefPtr<RecentInfo> > RecentManager::get_items() const
{
  return Glib::ListHandler<Glib::RefPtr<RecentInfo>, RecentInfoTraits>::list_to_vector(gtk_recent_manager_get_items(const_cast<GtkRecentManager*>(gobj())), Glib::OWNERSHIP_DEEP);
}

int RecentManager::purge_items()
{
  GError* gerror = nullptr;
  auto retvalue = gtk_recent_manager_purge_items(gobj(), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}


Glib::SignalProxy<void()> RecentManager::signal_changed()
{
  return Glib::SignalProxy<void() >(this, &RecentManager_signal_changed_info);
}


Glib::PropertyProxy_ReadOnly< Glib::ustring > RecentManager::property_filename() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "filename");
}

Glib::PropertyProxy_ReadOnly< int > RecentManager::property_size() const
{
  return Glib::PropertyProxy_ReadOnly< int >(this, "size");
}


void Gtk::RecentManager::on_changed()
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->changed)
    (*base->changed)(gobj());
}


} // namespace Gtk


