// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.h>

#include <mm/gtk/listview.h>
#include <mm/gtk/private/listview_p.h>


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


void ListView_signal_activate_callback(GtkListView* self, guint p0,void* data)
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(guint)>;

  auto obj = dynamic_cast<ListView*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo ListView_signal_activate_info =
{
  "activate",
  (GCallback) &ListView_signal_activate_callback,
  (GCallback) &ListView_signal_activate_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkListView* object, bool take_copy) -> Gtk::ListView*
{
  return dynamic_cast<Gtk::ListView *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto ListView_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ListView_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_list_view_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void ListView_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ListView_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new ListView((GtkListView*)(o)));

}


/* The implementation: */

ListView::ListView(const Glib::ConstructParams& construct_params)
:
  ListBase(construct_params)
{
  }

ListView::ListView(GtkListView* castitem)
:
  ListBase((GtkListBase*)(castitem))
{
  }


ListView::ListView(ListView&& src) noexcept
: ListBase(std::move(src))
{}

auto ListView::operator=(ListView&& src) noexcept -> ListView&
{
  ListBase::operator=(std::move(src));
  return *this;
}

ListView::~ListView() noexcept
{
  destroy_();
}

ListView::CppClassType ListView::listview_class_; // initialize static member

auto ListView::get_type() -> GType
{
  return listview_class_.init().get_type();
}


auto ListView::get_base_type() -> GType
{
  return gtk_list_view_get_type();
}


ListView::ListView(const Glib::RefPtr<SelectionModel>& model, const Glib::RefPtr<ListItemFactory>& factory)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  ListBase(Glib::ConstructParams(listview_class_.init(), "model", Glib::unwrap(model), "factory", Glib::unwrap(factory), nullptr))
{


}

auto ListView::get_model() -> Glib::RefPtr<SelectionModel>
{
  auto retvalue = Glib::wrap(gtk_list_view_get_model(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto ListView::get_model() const -> Glib::RefPtr<const SelectionModel>
{
  return const_cast<ListView*>(this)->get_model();
}

void ListView::set_model(const Glib::RefPtr<SelectionModel>& model)
{
  gtk_list_view_set_model(gobj(), Glib::unwrap(model));
}

void ListView::set_factory(const Glib::RefPtr<ListItemFactory>& factory)
{
  gtk_list_view_set_factory(gobj(), Glib::unwrap(factory));
}

auto ListView::get_factory() -> Glib::RefPtr<ListItemFactory>
{
  auto retvalue = Glib::wrap(gtk_list_view_get_factory(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto ListView::get_factory() const -> Glib::RefPtr<const ListItemFactory>
{
  return const_cast<ListView*>(this)->get_factory();
}

void ListView::set_show_separators(bool show_separators)
{
  gtk_list_view_set_show_separators(gobj(), static_cast<int>(show_separators));
}

auto ListView::get_show_separators() const -> bool
{
  return gtk_list_view_get_show_separators(const_cast<GtkListView*>(gobj()));
}

void ListView::set_single_click_activate(bool single_click_activate)
{
  gtk_list_view_set_single_click_activate(gobj(), static_cast<int>(single_click_activate));
}

auto ListView::get_single_click_activate() const -> bool
{
  return gtk_list_view_get_single_click_activate(const_cast<GtkListView*>(gobj()));
}

void ListView::set_enable_rubberband(bool enable_rubberband)
{
  gtk_list_view_set_enable_rubberband(gobj(), static_cast<int>(enable_rubberband));
}

auto ListView::get_enable_rubberband() const -> bool
{
  return gtk_list_view_get_enable_rubberband(const_cast<GtkListView*>(gobj()));
}


auto ListView::signal_activate() -> Glib::SignalProxy<void(guint)>
{
  return Glib::SignalProxy<void(guint) >(this, &ListView_signal_activate_info);
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<ListItemFactory>>::value,
  "Type Glib::RefPtr<ListItemFactory> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto ListView::property_factory() -> Glib::PropertyProxy< Glib::RefPtr<ListItemFactory> >
{
  return Glib::PropertyProxy< Glib::RefPtr<ListItemFactory> >(this, "factory");
}

auto ListView::property_factory() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ListItemFactory> >
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ListItemFactory> >(this, "factory");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<SelectionModel>>::value,
  "Type Glib::RefPtr<SelectionModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto ListView::property_model() -> Glib::PropertyProxy< Glib::RefPtr<SelectionModel> >
{
  return Glib::PropertyProxy< Glib::RefPtr<SelectionModel> >(this, "model");
}

auto ListView::property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<SelectionModel> >
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<SelectionModel> >(this, "model");
}

auto ListView::property_show_separators() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "show-separators");
}

auto ListView::property_show_separators() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "show-separators");
}

auto ListView::property_single_click_activate() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "single-click-activate");
}

auto ListView::property_single_click_activate() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "single-click-activate");
}

auto ListView::property_enable_rubberband() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "enable-rubberband");
}

auto ListView::property_enable_rubberband() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "enable-rubberband");
}


} // namespace Gtk

