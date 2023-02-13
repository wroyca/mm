


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/signallistitemfactory.hxx>
#include <libmm-gtk/signallistitemfactory_p.hxx>


/* Copyright (C) 2020 The gtkmm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>

namespace
{


auto SignalListItemFactory_signal_setup_callback (
  GtkSignalListItemFactory *self, GtkListItem *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<ListItem>&)>;

  const auto obj = dynamic_cast<SignalListItemFactory*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo SignalListItemFactory_signal_setup_info =
{
  "setup",
  (GCallback) &SignalListItemFactory_signal_setup_callback,
  (GCallback) &SignalListItemFactory_signal_setup_callback
};


auto SignalListItemFactory_signal_bind_callback (
  GtkSignalListItemFactory *self, GtkListItem *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<ListItem>&)>;

  const auto obj = dynamic_cast<SignalListItemFactory*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo SignalListItemFactory_signal_bind_info =
{
  "bind",
  (GCallback) &SignalListItemFactory_signal_bind_callback,
  (GCallback) &SignalListItemFactory_signal_bind_callback
};


auto SignalListItemFactory_signal_unbind_callback (
  GtkSignalListItemFactory *self, GtkListItem *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<ListItem>&)>;

  const auto obj = dynamic_cast<SignalListItemFactory*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo SignalListItemFactory_signal_unbind_info =
{
  "unbind",
  (GCallback) &SignalListItemFactory_signal_unbind_callback,
  (GCallback) &SignalListItemFactory_signal_unbind_callback
};


auto SignalListItemFactory_signal_teardown_callback (
  GtkSignalListItemFactory *self, GtkListItem *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<ListItem>&)>;

  const auto obj = dynamic_cast<SignalListItemFactory*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo SignalListItemFactory_signal_teardown_info =
{
  "teardown",
  (GCallback) &SignalListItemFactory_signal_teardown_callback,
  (GCallback) &SignalListItemFactory_signal_teardown_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkSignalListItemFactory* object, const bool take_copy) -> RefPtr<Gtk::SignalListItemFactory>
{
  return Glib::make_refptr_for_instance<Gtk::SignalListItemFactory>( dynamic_cast<Gtk::SignalListItemFactory*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto SignalListItemFactory_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &SignalListItemFactory_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_signal_list_item_factory_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto SignalListItemFactory_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto SignalListItemFactory_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new SignalListItemFactory((GtkSignalListItemFactory*)object);
}


/* The implementation: */

auto SignalListItemFactory::gobj_copy() -> GtkSignalListItemFactory*
{
  reference();
  return gobj();
}

SignalListItemFactory::SignalListItemFactory(const Glib::ConstructParams& construct_params)
: ListItemFactory(construct_params)
{

}

SignalListItemFactory::SignalListItemFactory(GtkSignalListItemFactory* castitem)
: ListItemFactory((GtkListItemFactory*)castitem)
{}


SignalListItemFactory::SignalListItemFactory(SignalListItemFactory&& src) noexcept
: ListItemFactory(std::move(src))
{}

auto SignalListItemFactory::operator=(SignalListItemFactory&& src) noexcept -> SignalListItemFactory&
{
  ListItemFactory::operator=(std::move(src));
  return *this;
}


SignalListItemFactory::~SignalListItemFactory() noexcept = default;

SignalListItemFactory::CppClassType SignalListItemFactory::signallistitemfactory_class_; // initialize static member

auto SignalListItemFactory::get_type() -> GType
{
  return signallistitemfactory_class_.init().get_type();
}


auto SignalListItemFactory::get_base_type() -> GType
{
  return gtk_signal_list_item_factory_get_type();
}


SignalListItemFactory::SignalListItemFactory()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
ListItemFactory(Glib::ConstructParams(signallistitemfactory_class_.init()))
{


}

auto SignalListItemFactory::create() -> Glib::RefPtr<SignalListItemFactory>
{
  return Glib::make_refptr_for_instance<SignalListItemFactory>( new SignalListItemFactory() );
}


auto SignalListItemFactory::signal_setup() -> Glib::SignalProxy<void(const Glib::RefPtr<ListItem>&)>
{
  return {this, &SignalListItemFactory_signal_setup_info};
}


auto SignalListItemFactory::signal_bind() -> Glib::SignalProxy<void(const Glib::RefPtr<ListItem>&)>
{
  return {this, &SignalListItemFactory_signal_bind_info};
}


auto SignalListItemFactory::signal_unbind() -> Glib::SignalProxy<void(const Glib::RefPtr<ListItem>&)>
{
  return {this, &SignalListItemFactory_signal_unbind_info};
}


auto SignalListItemFactory::signal_teardown() -> Glib::SignalProxy<void(const Glib::RefPtr<ListItem>&)>
{
  return {this, &SignalListItemFactory_signal_teardown_info};
}


} // namespace Gtk


