// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gtkmm/padcontroller.h>
#include <gtkmm/private/padcontroller_p.h>


/* Copyright (C) 2019 The gtkmm Development Team
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
#include <memory>

namespace Gtk
{

PadController::PadController(const Glib::RefPtr<Gio::ActionGroup>& action_group, const Glib::RefPtr<Gdk::Device>& pad)
:
  // gtk_pad_controller_new() sets the propagation-phase property.
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  EventController(Glib::ConstructParams(padcontroller_class_.init(), "propagation-phase",GTK_PHASE_CAPTURE,"action-group",Glib::unwrap(action_group),"pad",Glib::unwrap(pad), nullptr))
{
}

void PadController::set_action_entries(const std::vector<PadActionEntry>& entries)
{
  if (entries.empty())
    return;

  auto c_entries = std::make_unique<GtkPadActionEntry[]>(entries.size());

  // Copy the GtkPadActionEntry instances to an array without duplicating the
  // strings. Those strings are owned by entries. They are not deleted
  // when the array in c_entries is deleted.
  for (std::size_t i = 0; i < entries.size(); ++i)
    c_entries[i] = *entries[i].gobj();

  gtk_pad_controller_set_action_entries(gobj(), c_entries.get(), entries.size());
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Gtk::PadController> wrap(GtkPadController* object, bool take_copy)
{
  return Glib::make_refptr_for_instance<Gtk::PadController>( dynamic_cast<Gtk::PadController*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& PadController_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &PadController_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_pad_controller_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void PadController_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* PadController_Class::wrap_new(GObject* object)
{
  return new PadController((GtkPadController*)object);
}


/* The implementation: */

GtkPadController* PadController::gobj_copy()
{
  reference();
  return gobj();
}

PadController::PadController(const Glib::ConstructParams& construct_params)
:
  EventController(construct_params)
{

}

PadController::PadController(GtkPadController* castitem)
:
  EventController((GtkEventController*)(castitem))
{}


PadController::PadController(PadController&& src) noexcept
: EventController(std::move(src))
{}

PadController& PadController::operator=(PadController&& src) noexcept
{
  EventController::operator=(std::move(src));
  return *this;
}


PadController::~PadController() noexcept
{}


PadController::CppClassType PadController::padcontroller_class_; // initialize static member

GType PadController::get_type()
{
  return padcontroller_class_.init().get_type();
}


GType PadController::get_base_type()
{
  return gtk_pad_controller_get_type();
}


Glib::RefPtr<PadController> PadController::create(const Glib::RefPtr<Gio::ActionGroup>& action_group, const Glib::RefPtr<Gdk::Device>& pad)
{
  return Glib::make_refptr_for_instance<PadController>( new PadController(action_group, pad) );
}

void PadController::set_action(PadActionType type, int index, int mode, const Glib::ustring& label, const Glib::ustring& action_name)
{
  gtk_pad_controller_set_action(gobj(), static_cast<GtkPadActionType>(type), index, mode, label.c_str(), action_name.c_str());
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::ActionGroup>>::value,
  "Type Glib::RefPtr<Gio::ActionGroup> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::ActionGroup> > PadController::property_action_group() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::ActionGroup> >(this, "action-group");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gdk::Device>>::value,
  "Type Glib::RefPtr<Gdk::Device> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Device> > PadController::property_pad() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Device> >(this, "pad");
}


} // namespace Gtk


