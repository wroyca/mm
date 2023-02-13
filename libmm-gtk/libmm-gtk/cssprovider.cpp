


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/cssprovider.hpp>
#include <libmm-gtk/cssprovider_p.hpp>


/* Copyright (C) 2010 The gtkmm Development Team
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
auto CssProvider_signal_parsing_error_callback (
  GtkCssProvider *self, GtkCssSection *p0, const GError *p1, void *data) -> void
{
  using namespace Gtk;
  typedef sigc::slot<void(const Glib::RefPtr<const CssSection>&,const Glib::Error&)> SlotType;

  const auto obj = dynamic_cast<CssProvider*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      Glib::Error::throw_exception(g_error_copy(p1));
    }
    catch (const Glib::Error& ex)
    {
      // ex can be (and usually is) an instance of a subclass of Glib::Error.
      try
      {
        if(sigc::slot_base *const slot = Glib::SignalProxyNormal::data_to_slot(data))
          (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true), ex);
      }
      catch (...)
      {
         Glib::exception_handlers_invoke();
      }
    }
  }
}

} // anonymous namespace

namespace Gtk
{

auto CssProvider::load_from_data (const std::string &data) -> void
{
  gtk_css_provider_load_from_data(gobj(), data.c_str(), -1);
}

} //namespace Gtk

namespace
{


const Glib::SignalProxyInfo CssProvider_signal_parsing_error_info =
{
  "parsing-error",
  (GCallback) &CssProvider_signal_parsing_error_callback,
  (GCallback) &CssProvider_signal_parsing_error_callback
};


} // anonymous namespace


Gtk::CssParserError::CssParserError(const Code error_code, const Glib::ustring& error_message)
: Error(GTK_CSS_PARSER_ERROR, error_code, error_message)
{}

Gtk::CssParserError::CssParserError(GError* gobject)
: Error(gobject)
{}

auto Gtk::CssParserError::code() const -> Code
{
  return static_cast<Code>(Error::code());
}

auto Gtk::CssParserError::throw_func (GError *gobject) -> void
{
  throw CssParserError(gobject);
}

// static
auto Glib::Value<Gtk::CssParserError::Code>::value_type() -> GType
{
  return gtk_css_parser_error_get_type();
}


Gtk::CssParserWarning::CssParserWarning(const Code error_code, const Glib::ustring& error_message)
: Error(GTK_CSS_PARSER_WARNING, error_code, error_message)
{}

Gtk::CssParserWarning::CssParserWarning(GError* gobject)
: Error(gobject)
{}

auto Gtk::CssParserWarning::code() const -> Code
{
  return static_cast<Code>(Error::code());
}

auto Gtk::CssParserWarning::throw_func (GError *gobject) -> void
{
  throw CssParserWarning(gobject);
}

// static
auto Glib::Value<Gtk::CssParserWarning::Code>::value_type() -> GType
{
  return gtk_css_parser_warning_get_type();
}


namespace Glib
{

auto wrap(GtkCssProvider* object, const bool take_copy) -> RefPtr<Gtk::CssProvider>
{
  return Glib::make_refptr_for_instance<Gtk::CssProvider>( dynamic_cast<Gtk::CssProvider*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto CssProvider_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &CssProvider_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_css_provider_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  StyleProvider::add_interface(get_type());

  }

  return *this;
}


auto CssProvider_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto CssProvider_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new CssProvider((GtkCssProvider*)object);
}


/* The implementation: */

auto CssProvider::gobj_copy() -> GtkCssProvider*
{
  reference();
  return gobj();
}

CssProvider::CssProvider(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

CssProvider::CssProvider(GtkCssProvider* castitem)
: Object((GObject*)castitem)
{}


CssProvider::CssProvider(CssProvider&& src) noexcept
: Object(std::move(src))
  , StyleProvider(std::move(src))
{}

auto CssProvider::operator=(CssProvider&& src) noexcept -> CssProvider&
{
  Object::operator=(std::move(src));
  StyleProvider::operator=(std::move(src));
  return *this;
}


CssProvider::~CssProvider() noexcept = default;

CssProvider::CppClassType CssProvider::cssprovider_class_; // initialize static member

auto CssProvider::get_type() -> GType
{
  return cssprovider_class_.init().get_type();
}


auto CssProvider::get_base_type() -> GType
{
  return gtk_css_provider_get_type();
}


CssProvider::CssProvider()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(cssprovider_class_.init()))
{


}

auto CssProvider::create() -> Glib::RefPtr<CssProvider>
{
  return Glib::make_refptr_for_instance<CssProvider>( new CssProvider() );
}

auto CssProvider::to_string() const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(gtk_css_provider_to_string(const_cast<GtkCssProvider*>(gobj())));
}

auto CssProvider::load_from_file (const Glib::RefPtr <const Gio::File> &file) -> void
{
  gtk_css_provider_load_from_file(gobj(), const_cast<GFile*>(Glib::unwrap<Gio::File>(file)));
}

auto CssProvider::load_from_path (const std::string &path) -> void
{
  gtk_css_provider_load_from_path(gobj(), path.c_str());
}

auto CssProvider::load_from_resource (const std::string &resource_path) -> void
{
  gtk_css_provider_load_from_resource(gobj(), resource_path.c_str());
}

auto CssProvider::load_named (const Glib::ustring &name, const Glib::ustring &variant) -> void
{
  gtk_css_provider_load_named(gobj(), name.c_str(), variant.empty() ? nullptr : variant.c_str());
}


auto CssProvider::signal_parsing_error() -> Glib::SignalProxy<void(const Glib::RefPtr<const CssSection>&, const Glib::Error&)>
{
  return {this, &CssProvider_signal_parsing_error_info};
}


} // namespace Gtk


