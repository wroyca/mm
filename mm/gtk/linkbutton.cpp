// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/linkbutton.hpp>
#include <mm/gtk/private/linkbutton_p.hpp>


/*
 * Copyright 2006 The gtkmm Development Team
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

#include <gtk/gtk.h>

namespace
{


auto LinkButton_signal_activate_link_callback(GtkLinkButton* self, void* data) -> gboolean
{
  using namespace Gtk;
  using SlotType = sigc::slot<bool()>;

  auto obj = dynamic_cast<LinkButton*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        return static_cast<int>((*static_cast<SlotType*>(slot))());
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }

  using RType = gboolean;
  return RType();
}

auto LinkButton_signal_activate_link_notify_callback(GtkLinkButton* self,  void* data) -> gboolean
{
  using namespace Gtk;
  using SlotType = sigc::slot<void()>;

  auto obj = dynamic_cast<LinkButton*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))();
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }

  using RType = gboolean;
  return RType();
}

const Glib::SignalProxyInfo LinkButton_signal_activate_link_info =
{
  "activate-link",
  (GCallback) &LinkButton_signal_activate_link_callback,
  (GCallback) &LinkButton_signal_activate_link_notify_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkLinkButton* object, bool take_copy) -> Gtk::LinkButton*
{
  return dynamic_cast<Gtk::LinkButton *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto LinkButton_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &LinkButton_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_link_button_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto LinkButton_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto LinkButton_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new LinkButton((GtkLinkButton*)(o)));

}


/* The implementation: */

LinkButton::LinkButton(const Glib::ConstructParams& construct_params)
:
  Gtk::Button(construct_params)
{
  }

LinkButton::LinkButton(GtkLinkButton* castitem)
:
  Gtk::Button((GtkButton*)(castitem))
{
  }


LinkButton::LinkButton(LinkButton&& src) noexcept
: Gtk::Button(std::move(src))
{}

auto LinkButton::operator=(LinkButton&& src) noexcept -> LinkButton&
{
  Gtk::Button::operator=(std::move(src));
  return *this;
}

LinkButton::~LinkButton() noexcept
{
  destroy_();
}

LinkButton::CppClassType LinkButton::linkbutton_class_; // initialize static member

auto LinkButton::get_type() -> GType
{
  return linkbutton_class_.init().get_type();
}


auto LinkButton::get_base_type() -> GType
{
  return gtk_link_button_get_type();
}


LinkButton::LinkButton()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::Button(Glib::ConstructParams(linkbutton_class_.init()))
{


}

LinkButton::LinkButton(const Glib::ustring& uri, const Glib::ustring& label)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::Button(Glib::ConstructParams(linkbutton_class_.init(), "uri", uri.c_str(), "label", label.c_str(), nullptr))
{


}

auto LinkButton::get_uri() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_link_button_get_uri(const_cast<GtkLinkButton*>(gobj())));
}

auto LinkButton::set_uri (const Glib::ustring &uri) -> void
{
  gtk_link_button_set_uri(gobj(), uri.c_str());
}

auto LinkButton::get_visited() const -> bool
{
  return gtk_link_button_get_visited(const_cast<GtkLinkButton*>(gobj()));
}

auto LinkButton::set_visited (bool visited) -> void
{
  gtk_link_button_set_visited(gobj(), static_cast<int>(visited));
}


auto LinkButton::signal_activate_link() -> Glib::SignalProxy<bool()>
{
  return Glib::SignalProxy<bool() >(this, &LinkButton_signal_activate_link_info);
}


auto LinkButton::property_uri() -> Glib::PropertyProxy< Glib::ustring >
{
  return Glib::PropertyProxy< Glib::ustring >(this, "uri");
}

auto LinkButton::property_uri() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "uri");
}

auto LinkButton::property_visited() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "visited");
}

auto LinkButton::property_visited() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "visited");
}


} // namespace Gtk


