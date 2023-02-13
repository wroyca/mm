


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/filter.hpp>
#include <mm/gtk/private/filter_p.hpp>


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

using Change = Gtk::Filter::Change;
using Match = Gtk::Filter::Match;

namespace
{


auto Filter_signal_changed_callback (GtkFilter *self, GtkFilterChange p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(Change)>;

  const auto obj = dynamic_cast<Filter*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(static_cast<Change>(p0)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo Filter_signal_changed_info =
{
  "changed",
  (GCallback) &Filter_signal_changed_callback,
  (GCallback) &Filter_signal_changed_callback
};


} // anonymous namespace

// static
auto Glib::Value<Gtk::Filter::Match>::value_type() -> GType
{
  return gtk_filter_match_get_type();
}

// static
auto Glib::Value<Gtk::Filter::Change>::value_type() -> GType
{
  return gtk_filter_change_get_type();
}


namespace Glib
{

auto wrap(GtkFilter* object, const bool take_copy) -> RefPtr<Gtk::Filter>
{
  return Glib::make_refptr_for_instance<Gtk::Filter>( dynamic_cast<Gtk::Filter*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto Filter_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Filter_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_filter_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto Filter_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

  klass->match = &match_vfunc_callback;
  klass->get_strictness = &get_strictness_vfunc_callback;

}

auto Filter_Class::match_vfunc_callback(GtkFilter* self, const gpointer item) -> gboolean
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

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
        return obj->match_vfunc(Glib::wrap(G_OBJECT(item), true)
        );
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->match)
    return (*base->match)(self, item);

  using RType = gboolean;
  return RType();
}
auto Filter_Class::get_strictness_vfunc_callback(GtkFilter* self) -> GtkFilterMatch
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

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
        return static_cast<GtkFilterMatch>(obj->get_strictness_vfunc());
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->get_strictness)
    return (*base->get_strictness)(self);

  using RType = GtkFilterMatch;
  return RType();
}


auto Filter_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Filter((GtkFilter*)object);
}


/* The implementation: */

auto Filter::gobj_copy() -> GtkFilter*
{
  reference();
  return gobj();
}

Filter::Filter(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

Filter::Filter(GtkFilter* castitem)
: Object((GObject*)castitem)
{}


Filter::Filter(Filter&& src) noexcept
: Object(std::move(src))
{}

auto Filter::operator=(Filter&& src) noexcept -> Filter&
{
  Object::operator=(std::move(src));
  return *this;
}


Filter::~Filter() noexcept = default;

Filter::CppClassType Filter::filter_class_; // initialize static member

auto Filter::get_type() -> GType
{
  return filter_class_.init().get_type();
}


auto Filter::get_base_type() -> GType
{
  return gtk_filter_get_type();
}


Filter::Filter()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(filter_class_.init()))
{


}

auto Filter::match(const Glib::RefPtr<ObjectBase>& item) -> bool
{
  return gtk_filter_match(gobj(), item->gobj());
}

auto Filter::get_strictness() -> Match
{
  return static_cast<Match>(gtk_filter_get_strictness(gobj()));
}

auto Filter::changed (Change change) -> void
{
  gtk_filter_changed(gobj(), static_cast<GtkFilterChange>(change));
}


auto Filter::signal_changed() -> Glib::SignalProxy<void(Change)>
{
  return {this, &Filter_signal_changed_info};
}


auto Filter::match_vfunc(const Glib::RefPtr<ObjectBase>& item) -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->match)
  {
    const bool retval((*base->match)(gobj(),item->gobj()));
    return retval;
  }

  using RType = bool;
  return RType();
}
auto Filter::get_strictness_vfunc() -> Match
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->get_strictness)
  {
    const Match retval(static_cast<Match>((*base->get_strictness)(gobj())));
    return retval;
  }

  using RType = Match;
  return RType();
}


} // namespace Gtk


