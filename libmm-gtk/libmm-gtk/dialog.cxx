


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/dialog.hxx>
#include <libmm-gtk/dialog_p.hxx>

#include <gtk/gtk.h>

/* Copyright 1998-2002 The gtkmm Development Team
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

Dialog::Dialog(const Glib::ustring& title, Window & parent, const bool modal, const bool use_header_bar)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Window(Glib::ConstructParams(dialog_class_.init(), "title",title.c_str(),"use-header-bar",use_header_bar, nullptr))
{
  set_modal(modal);
  set_transient_for(parent);
}

Dialog::Dialog(const Glib::ustring& title, const bool modal, const bool use_header_bar)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Window(Glib::ConstructParams(dialog_class_.init(), "title",title.c_str(),"use-header-bar",use_header_bar, nullptr))
{
  set_modal(modal);
}

} // namespace Gtk

namespace
{


auto Dialog_signal_response_callback (GtkDialog *self, const gint p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(int)>;

  const auto obj = dynamic_cast<Dialog*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo Dialog_signal_response_info =
{
  "response",
  (GCallback) &Dialog_signal_response_callback,
  (GCallback) &Dialog_signal_response_callback
};


} // anonymous namespace

// static
auto Glib::Value<Gtk::ResponseType>::value_type() -> GType
{
  return gtk_response_type_get_type();
}


namespace Glib
{

auto wrap(GtkDialog* object, const bool take_copy) -> Gtk::Dialog*
{
  return dynamic_cast<Gtk::Dialog *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto Dialog_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Dialog_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_dialog_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto Dialog_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


  klass->response = &response_callback;
}


auto Dialog_Class::response_callback (GtkDialog *self, const gint p0) -> void
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
        obj->on_response(p0
);
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
  if(base && base->response)
    (*base->response)(self, p0);
}


auto Dialog_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return new Dialog((GtkDialog*)o); //top-level windows can not be manage()ed.

}


/* The implementation: */

Dialog::Dialog(const Glib::ConstructParams& construct_params)
: Window(construct_params)
{
  }

Dialog::Dialog(GtkDialog* castitem)
: Window((GtkWindow*)castitem)
{
  }


Dialog::Dialog(Dialog&& src) noexcept
: Window(std::move(src))
{}

auto Dialog::operator=(Dialog&& src) noexcept -> Dialog&
{
  Window::operator=(std::move(src));
  return *this;
}

Dialog::~Dialog() noexcept
{
  destroy_();
}

Dialog::CppClassType Dialog::dialog_class_; // initialize static member

auto Dialog::get_type() -> GType
{
  return dialog_class_.init().get_type();
}


auto Dialog::get_base_type() -> GType
{
  return gtk_dialog_get_type();
}


Dialog::Dialog()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Window(Glib::ConstructParams(dialog_class_.init()))
{


}

auto Dialog::add_action_widget (Widget &child, const int response_id) -> void
{
  gtk_dialog_add_action_widget(gobj(), child.gobj(), response_id);
}

auto Dialog::add_button(const Glib::ustring& button_text, const int response_id) -> Button*
{
  return Glib::wrap((GtkButton*)gtk_dialog_add_button(gobj(), button_text.c_str(), response_id));
}

auto Dialog::set_response_sensitive (
  const int response_id, const bool setting) -> void
{
  gtk_dialog_set_response_sensitive(gobj(), response_id, setting);
}

auto Dialog::set_default_response (
  const int response_id) -> void
{
  gtk_dialog_set_default_response(gobj(), response_id);
}

auto Dialog::get_widget_for_response(
  const int response_id) -> Widget*
{
  return Glib::wrap(gtk_dialog_get_widget_for_response(gobj(), response_id));
}

auto Dialog::get_widget_for_response(
  const int response_id) const -> const Widget*
{
  return const_cast<Dialog*>(this)->get_widget_for_response(response_id);
}

auto Dialog::get_response_for_widget(const Widget & widget) const -> int
{
  return gtk_dialog_get_response_for_widget(const_cast<GtkDialog*>(gobj()), const_cast<GtkWidget*>(widget.gobj()));
}

auto Dialog::response (
  const int response_id) -> void
{
  gtk_dialog_response(gobj(), response_id);
}

auto Dialog::get_content_area() -> Box*
{
  return Glib::wrap((GtkBox*)gtk_dialog_get_content_area(gobj()));
}

auto Dialog::get_content_area() const -> const Box*
{
  return const_cast<Dialog*>(this)->get_content_area();
}

auto Dialog::get_header_bar() -> HeaderBar*
{
  return Glib::wrap((GtkHeaderBar*)gtk_dialog_get_header_bar(gobj()));
}

auto Dialog::get_header_bar() const -> const HeaderBar*
{
  return const_cast<Dialog*>(this)->get_header_bar();
}


auto Dialog::signal_response() -> Glib::SignalProxy<void(int)>
{
  return {this, &Dialog_signal_response_info};
}


auto Dialog::property_use_header_bar() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "use-header-bar"};
}


auto Dialog::on_response (
  const int response_id) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->response)
    (*base->response)(gobj(),response_id);
}


} // namespace Gtk


