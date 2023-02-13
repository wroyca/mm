


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/applicationcommandline.hpp>
#include <mm/gio/private/applicationcommandline_p.hpp>


/* Copyright (C) 2010 Jonathon Jongsma <jonathon@quotidian.org>
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gio/gio.h>
#include <mm/glib/vectorutils.hpp>

namespace Gio
{

auto ApplicationCommandLine::print (const Glib::ustring &message) -> void
{
  g_application_command_line_print(gobj(), "%s", message.c_str());
}

auto ApplicationCommandLine::printerr (const Glib::ustring &message) -> void
{
  g_application_command_line_printerr(gobj(), "%s", message.c_str());
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GApplicationCommandLine* object, const bool take_copy) -> RefPtr<Gio::ApplicationCommandLine>
{
  return Glib::make_refptr_for_instance<Gio::ApplicationCommandLine>( dynamic_cast<Gio::ApplicationCommandLine*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto ApplicationCommandLine_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ApplicationCommandLine_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_application_command_line_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto ApplicationCommandLine_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ApplicationCommandLine_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new ApplicationCommandLine((GApplicationCommandLine*)object);
}


/* The implementation: */

auto ApplicationCommandLine::gobj_copy() -> GApplicationCommandLine*
{
  reference();
  return gobj();
}

ApplicationCommandLine::ApplicationCommandLine(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

ApplicationCommandLine::ApplicationCommandLine(GApplicationCommandLine* castitem)
: Object((GObject*)castitem)
{}


ApplicationCommandLine::ApplicationCommandLine(ApplicationCommandLine&& src) noexcept
: Object(std::move(src))
{}

auto ApplicationCommandLine::operator=(ApplicationCommandLine&& src) noexcept -> ApplicationCommandLine&
{
  Object::operator=(std::move(src));
  return *this;
}


ApplicationCommandLine::~ApplicationCommandLine() noexcept = default;

ApplicationCommandLine::CppClassType ApplicationCommandLine::applicationcommandline_class_; // initialize static member

auto ApplicationCommandLine::get_type() -> GType
{
  return applicationcommandline_class_.init().get_type();
}


auto ApplicationCommandLine::get_base_type() -> GType
{
  return g_application_command_line_get_type();
}


ApplicationCommandLine::ApplicationCommandLine()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(applicationcommandline_class_.init()))
{


}

auto ApplicationCommandLine::get_arguments(int& argc) const -> char**
{
  return g_application_command_line_get_arguments(const_cast<GApplicationCommandLine*>(gobj()), &argc);
}

auto ApplicationCommandLine::get_options_dict() -> Glib::RefPtr<Glib::VariantDict>
{
  auto retvalue = Glib::wrap(g_application_command_line_get_options_dict(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto ApplicationCommandLine::get_options_dict() const -> Glib::RefPtr<const Glib::VariantDict>
{
  return const_cast<ApplicationCommandLine*>(this)->get_options_dict();
}

auto ApplicationCommandLine::get_stdin() -> Glib::RefPtr<InputStream>
{
  auto retvalue = Glib::wrap(g_application_command_line_get_stdin(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto ApplicationCommandLine::get_stdin() const -> Glib::RefPtr<const InputStream>
{
  return const_cast<ApplicationCommandLine*>(this)->get_stdin();
}

auto ApplicationCommandLine::get_cwd() const -> std::string
{
  return Glib::convert_const_gchar_ptr_to_stdstring(g_application_command_line_get_cwd(const_cast<GApplicationCommandLine*>(gobj())));
}

auto ApplicationCommandLine::get_environ() const -> std::vector<std::string>
{
  return Glib::ArrayHandler<std::string>::array_to_vector(g_application_command_line_get_environ(const_cast<GApplicationCommandLine*>(gobj())), Glib::OWNERSHIP_NONE);
}

auto ApplicationCommandLine::getenv(const Glib::ustring& name) const -> std::string
{
  return Glib::convert_const_gchar_ptr_to_stdstring(g_application_command_line_getenv(const_cast<GApplicationCommandLine*>(gobj()), name.c_str()));
}

auto ApplicationCommandLine::is_remote() const -> bool
{
  return g_application_command_line_get_is_remote(const_cast<GApplicationCommandLine*>(gobj()));
}

auto ApplicationCommandLine::get_platform_data() const -> Glib::Variant< std::map<Glib::ustring, Glib::VariantBase> >
{
  return Glib::Variant< std::map<Glib::ustring, Glib::VariantBase> >(g_application_command_line_get_platform_data(const_cast<GApplicationCommandLine*>(gobj())));
}

auto ApplicationCommandLine::set_exit_status (
  const int exit_status) -> void
{
  g_application_command_line_set_exit_status(gobj(), exit_status);
}

auto ApplicationCommandLine::get_exit_status() const -> int
{
  return g_application_command_line_get_exit_status(const_cast<GApplicationCommandLine*>(gobj()));
}

auto ApplicationCommandLine::create_file_for_arg(const Glib::ustring& arg) const -> Glib::RefPtr<File>
{
  return Glib::wrap(g_application_command_line_create_file_for_arg(const_cast<GApplicationCommandLine*>(gobj()), arg.c_str()));
}


} // namespace Gio


