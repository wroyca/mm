


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/assistant.hxx>
#include <libmm-gtk/assistant_p.hxx>


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

static auto SignalProxy_SlotForwardPage_gtk_callback(
  const int current_page, const gpointer data) -> int
{
  const auto the_slot = static_cast<Gtk::Assistant::SlotForwardPage*>(data);

  try
  {
    return (*the_slot)(current_page);
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
    return int();
  }
}

static auto SignalProxy_SlotForwardPage_gtk_callback_destroy (void *data) -> void
{
  delete static_cast<Gtk::Assistant::SlotForwardPage*>(data);
}


namespace Gtk
{

// use-header-bar is construct-only. It must be set in the constructor,
// if you don't want the default value.
Assistant::Assistant(const bool use_header_bar)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Window(Glib::ConstructParams(assistant_class_.init(), "use-header-bar",use_header_bar, nullptr))
{
}

auto Assistant::set_forward_page_func (const SlotForwardPage &slot) -> void
{
  // Create a copy of the slot object. A pointer to this will be passed
  // through the callback's data parameter.  It will be deleted
  // when SignalProxy_SlotForwardPage_gtk_callback_destroy() is called.
  const auto slot_copy = new SlotForwardPage(slot);

  gtk_assistant_set_forward_page_func(gobj(),
      &SignalProxy_SlotForwardPage_gtk_callback, slot_copy,
      &SignalProxy_SlotForwardPage_gtk_callback_destroy);
}


} // namespace Gtk


namespace
{


auto Assistant_signal_prepare_callback (GtkAssistant *self, GtkWidget *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(Widget *)>;

  const auto obj = dynamic_cast<Assistant*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo Assistant_signal_prepare_info =
{
  "prepare",
  (GCallback) &Assistant_signal_prepare_callback,
  (GCallback) &Assistant_signal_prepare_callback
};


const Glib::SignalProxyInfo Assistant_signal_apply_info =
{
  "apply",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


const Glib::SignalProxyInfo Assistant_signal_close_info =
{
  "close",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


const Glib::SignalProxyInfo Assistant_signal_cancel_info =
{
  "cancel",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkAssistant* object, const bool take_copy) -> Gtk::Assistant*
{
  return dynamic_cast<Gtk::Assistant *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto Assistant_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Assistant_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_assistant_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto Assistant_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Assistant_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return new Assistant((GtkAssistant*)o); //top-level windows can not be manage()ed.

}


/* The implementation: */

Assistant::Assistant(const Glib::ConstructParams& construct_params)
: Window(construct_params)
{
  }

Assistant::Assistant(GtkAssistant* castitem)
: Window((GtkWindow*)castitem)
{
  }


Assistant::Assistant(Assistant&& src) noexcept
: Window(std::move(src))
{}

auto Assistant::operator=(Assistant&& src) noexcept -> Assistant&
{
  Window::operator=(std::move(src));
  return *this;
}

Assistant::~Assistant() noexcept
{
  destroy_();
}

Assistant::CppClassType Assistant::assistant_class_; // initialize static member

auto Assistant::get_type() -> GType
{
  return assistant_class_.init().get_type();
}


auto Assistant::get_base_type() -> GType
{
  return gtk_assistant_get_type();
}


Assistant::Assistant()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Window(Glib::ConstructParams(assistant_class_.init()))
{


}

auto Assistant::next_page () -> void
{
  gtk_assistant_next_page(gobj());
}

auto Assistant::previous_page () -> void
{
  gtk_assistant_previous_page(gobj());
}

auto Assistant::get_current_page() const -> int
{
  return gtk_assistant_get_current_page(const_cast<GtkAssistant*>(gobj()));
}

auto Assistant::set_current_page (
  const int page_num) -> void
{
  gtk_assistant_set_current_page(gobj(), page_num);
}

auto Assistant::get_n_pages() const -> int
{
  return gtk_assistant_get_n_pages(const_cast<GtkAssistant*>(gobj()));
}

auto Assistant::get_nth_page(
  const int page_num) -> Widget*
{
  return Glib::wrap(gtk_assistant_get_nth_page(gobj(), page_num));
}

auto Assistant::get_nth_page(
  const int page_num) const -> const Widget*
{
  return const_cast<Assistant*>(this)->get_nth_page(page_num);
}

auto Assistant::prepend_page(Widget& page) -> int
{
  return gtk_assistant_prepend_page(gobj(), page.gobj());
}

auto Assistant::append_page(Widget& page) -> int
{
  return gtk_assistant_append_page(gobj(), page.gobj());
}

auto Assistant::insert_page(Widget& page, const int position) -> int
{
  return gtk_assistant_insert_page(gobj(), page.gobj(), position);
}

auto Assistant::remove_page (
  const int page_num) -> void
{
  gtk_assistant_remove_page(gobj(), page_num);
}

auto Assistant::set_page_type (const Widget &page, AssistantPage::Type type) -> void
{
  gtk_assistant_set_page_type(gobj(), const_cast<GtkWidget*>(page.gobj()), static_cast<GtkAssistantPageType>(type));
}

auto Assistant::get_page_type(const Widget& page) const -> AssistantPage::Type
{
  return static_cast<AssistantPage::Type>(gtk_assistant_get_page_type(const_cast<GtkAssistant*>(gobj()), const_cast<GtkWidget*>(page.gobj())));
}

auto Assistant::set_page_title (const Widget &page, const Glib::ustring &title) -> void
{
  gtk_assistant_set_page_title(gobj(), const_cast<GtkWidget*>(page.gobj()), title.c_str());
}

auto Assistant::get_page_title(const Widget& page) const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_assistant_get_page_title(const_cast<GtkAssistant*>(gobj()), const_cast<GtkWidget*>(page.gobj())));
}

auto Assistant::set_page_complete (const Widget &page, const bool complete) -> void
{
  gtk_assistant_set_page_complete(gobj(), const_cast<GtkWidget*>(page.gobj()), complete);
}

auto Assistant::get_page_complete(const Widget& page) const -> bool
{
  return gtk_assistant_get_page_complete(const_cast<GtkAssistant*>(gobj()), const_cast<GtkWidget*>(page.gobj()));
}

auto Assistant::add_action_widget (Widget &child) -> void
{
  gtk_assistant_add_action_widget(gobj(), child.gobj());
}

auto Assistant::remove_action_widget (Widget &child) -> void
{
  gtk_assistant_remove_action_widget(gobj(), child.gobj());
}

auto Assistant::update_buttons_state () -> void
{
  gtk_assistant_update_buttons_state(gobj());
}

auto Assistant::commit () -> void
{
  gtk_assistant_commit(gobj());
}

auto Assistant::get_page(Widget& child) -> Glib::RefPtr<AssistantPage>
{
  auto retvalue = Glib::wrap(gtk_assistant_get_page(gobj(), child.gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Assistant::get_page(const Widget& child) const -> Glib::RefPtr<const AssistantPage>
{
  auto retvalue = Glib::wrap(gtk_assistant_get_page(const_cast<GtkAssistant*>(gobj()), const_cast<GtkWidget*>(child.gobj())));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Assistant::get_pages() -> Glib::RefPtr<Gio::ListModel>
{
  return Glib::wrap(gtk_assistant_get_pages(gobj()));
}

auto Assistant::get_pages() const -> Glib::RefPtr<const Gio::ListModel>
{
  return const_cast<Assistant*>(this)->get_pages();
}


auto Assistant::signal_prepare() -> Glib::SignalProxy<void(Widget *)>
{
  return {this, &Assistant_signal_prepare_info};
}


auto Assistant::signal_apply() -> Glib::SignalProxy<void()>
{
  return {this, &Assistant_signal_apply_info};
}


auto Assistant::signal_close() -> Glib::SignalProxy<void()>
{
  return {this, &Assistant_signal_close_info};
}


auto Assistant::signal_cancel() -> Glib::SignalProxy<void()>
{
  return {this, &Assistant_signal_cancel_info};
}


auto Assistant::property_use_header_bar() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "use-header-bar"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::ListModel>>::value,
  "Type Glib::RefPtr<Gio::ListModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Assistant::property_pages() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::ListModel> >
{
  return {this, "pages"};
}


} // namespace Gtk

