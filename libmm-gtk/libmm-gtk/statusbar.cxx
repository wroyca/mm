


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/statusbar.hpp>
#include <libmm-gtk/statusbar_p.hpp>


/*
 * Copyright 1998-2002 The gtkmm Development Team
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

namespace Gtk
{

auto Statusbar::push(const Glib::ustring& text, const guint context_id /* = 0 */) -> guint
{
  return gtk_statusbar_push(gobj(), context_id, text.c_str());
}

auto Statusbar::remove_message (
  const guint message_id, const guint context_id /* = 0 */) -> void
{
  return gtk_statusbar_remove(gobj(), context_id, message_id);
}

} //namespace Gtk


namespace
{


auto Statusbar_signal_text_pushed_callback (
  GtkStatusbar *self, const guint p0, const gchar *p1, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(guint, const Glib::ustring&)>;

  const auto obj = dynamic_cast<Statusbar*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0, Glib::convert_const_gchar_ptr_to_ustring(p1)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo Statusbar_signal_text_pushed_info =
{
  "text_pushed",
  (GCallback) &Statusbar_signal_text_pushed_callback,
  (GCallback) &Statusbar_signal_text_pushed_callback
};


auto Statusbar_signal_text_popped_callback (
  GtkStatusbar *self, const guint p0, const gchar *p1, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(guint, const Glib::ustring&)>;

  const auto obj = dynamic_cast<Statusbar*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0, Glib::convert_const_gchar_ptr_to_ustring(p1)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo Statusbar_signal_text_popped_info =
{
  "text_popped",
  (GCallback) &Statusbar_signal_text_popped_callback,
  (GCallback) &Statusbar_signal_text_popped_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkStatusbar* object, const bool take_copy) -> Gtk::Statusbar*
{
  return dynamic_cast<Gtk::Statusbar *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto Statusbar_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Statusbar_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_statusbar_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto Statusbar_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Statusbar_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new Statusbar((GtkStatusbar*)o));

}


/* The implementation: */

Statusbar::Statusbar(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

Statusbar::Statusbar(GtkStatusbar* castitem)
: Widget((GtkWidget*)castitem)
{
  }


Statusbar::Statusbar(Statusbar&& src) noexcept
: Widget(std::move(src))
{}

auto Statusbar::operator=(Statusbar&& src) noexcept -> Statusbar&
{
  Widget::operator=(std::move(src));
  return *this;
}

Statusbar::~Statusbar() noexcept
{
  destroy_();
}

Statusbar::CppClassType Statusbar::statusbar_class_; // initialize static member

auto Statusbar::get_type() -> GType
{
  return statusbar_class_.init().get_type();
}


auto Statusbar::get_base_type() -> GType
{
  return gtk_statusbar_get_type();
}


Statusbar::Statusbar()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(statusbar_class_.init()))
{


}

auto Statusbar::get_context_id(const Glib::ustring& context_description) -> guint
{
  return gtk_statusbar_get_context_id(gobj(), context_description.c_str());
}

auto Statusbar::pop (
  const guint context_id) -> void
{
  gtk_statusbar_pop(gobj(), context_id);
}

auto Statusbar::remove_all_messages (
  const guint context_id) -> void
{
  gtk_statusbar_remove_all(gobj(), context_id);
}


auto Statusbar::signal_text_pushed() -> Glib::SignalProxy<void(guint, const Glib::ustring&)>
{
  return {this, &Statusbar_signal_text_pushed_info};
}


auto Statusbar::signal_text_popped() -> Glib::SignalProxy<void(guint, const Glib::ustring&)>
{
  return {this, &Statusbar_signal_text_popped_info};
}


} // namespace Gtk


