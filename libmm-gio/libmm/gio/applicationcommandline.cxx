// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/applicationcommandline.hxx>
#include <libmm/gio/applicationcommandline_p.hxx>

#include <gio/gio.h>
#include <libmm/glib/vectorutils.hxx>

namespace gio
{

  auto
  ApplicationCommandLine::print (const glib::ustring& message) -> void
  {
    g_application_command_line_print (gobj (), "%s", message.c_str ());
  }

  auto
  ApplicationCommandLine::printerr (const glib::ustring& message) -> void
  {
    g_application_command_line_printerr (gobj (), "%s", message.c_str ());
  }

} // namespace gio

namespace
{
}

namespace glib
{

  auto
  wrap (GApplicationCommandLine* object, const bool take_copy) -> RefPtr<gio::ApplicationCommandLine>
  {
    return glib::make_refptr_for_instance<gio::ApplicationCommandLine> (
        dynamic_cast<gio::ApplicationCommandLine*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  ApplicationCommandLine_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ApplicationCommandLine_Class::class_init_function;

      register_derived_type (g_application_command_line_get_type ());
    }

    return *this;
  }

  auto
  ApplicationCommandLine_Class::class_init_function (void* g_class,
                                                     void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ApplicationCommandLine_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new ApplicationCommandLine ((GApplicationCommandLine*) object);
  }

  auto
  ApplicationCommandLine::gobj_copy () -> GApplicationCommandLine*
  {
    reference ();
    return gobj ();
  }

  ApplicationCommandLine::ApplicationCommandLine (
      const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  ApplicationCommandLine::ApplicationCommandLine (
      GApplicationCommandLine* castitem)
    : Object ((GObject*) castitem)
  {
  }

  ApplicationCommandLine::ApplicationCommandLine (
      ApplicationCommandLine&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  ApplicationCommandLine::operator= (ApplicationCommandLine&& src) noexcept -> ApplicationCommandLine&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  ApplicationCommandLine::~ApplicationCommandLine () noexcept = default;

  ApplicationCommandLine::CppClassType
      ApplicationCommandLine::applicationcommandline_class_;

  auto
  ApplicationCommandLine::get_type () -> GType
  {
    return applicationcommandline_class_.init ().get_type ();
  }

  auto
  ApplicationCommandLine::get_base_type () -> GType
  {
    return g_application_command_line_get_type ();
  }

  ApplicationCommandLine::ApplicationCommandLine ()
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (applicationcommandline_class_.init ()))
  {
  }

  auto
  ApplicationCommandLine::get_arguments (int& argc) const -> char**
  {
    return g_application_command_line_get_arguments (
        const_cast<GApplicationCommandLine*> (gobj ()),
        &argc);
  }

  auto
  ApplicationCommandLine::get_options_dict () -> glib::RefPtr<glib::VariantDict>
  {
    auto retvalue =
        glib::wrap (g_application_command_line_get_options_dict (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ApplicationCommandLine::get_options_dict () const -> glib::RefPtr<const glib::VariantDict>
  {
    return const_cast<ApplicationCommandLine*> (this)->get_options_dict ();
  }

  auto
  ApplicationCommandLine::get_stdin () -> glib::RefPtr<InputStream>
  {
    auto retvalue = glib::wrap (g_application_command_line_get_stdin (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ApplicationCommandLine::get_stdin () const -> glib::RefPtr<const InputStream>
  {
    return const_cast<ApplicationCommandLine*> (this)->get_stdin ();
  }

  auto
  ApplicationCommandLine::get_cwd () const -> std::string
  {
    return glib::convert_const_gchar_ptr_to_stdstring (
        g_application_command_line_get_cwd (
            const_cast<GApplicationCommandLine*> (gobj ())));
  }

  auto
  ApplicationCommandLine::get_environ () const -> std::vector<std::string>
  {
    return glib::ArrayHandler<std::string>::array_to_vector (
        g_application_command_line_get_environ (
            const_cast<GApplicationCommandLine*> (gobj ())),
        glib::OWNERSHIP_NONE);
  }

  auto
  ApplicationCommandLine::getenv (const glib::ustring& name) const -> std::string
  {
    return glib::convert_const_gchar_ptr_to_stdstring (
        g_application_command_line_getenv (
            const_cast<GApplicationCommandLine*> (gobj ()),
            name.c_str ()));
  }

  auto
  ApplicationCommandLine::is_remote () const -> bool
  {
    return g_application_command_line_get_is_remote (
        const_cast<GApplicationCommandLine*> (gobj ()));
  }

  auto
  ApplicationCommandLine::get_platform_data () const -> glib::Variant<std::map<glib::ustring, glib::VariantBase>>
  {
    return glib::Variant<std::map<glib::ustring, glib::VariantBase>> (
        g_application_command_line_get_platform_data (
            const_cast<GApplicationCommandLine*> (gobj ())));
  }

  auto
  ApplicationCommandLine::set_exit_status (const int exit_status) -> void
  {
    g_application_command_line_set_exit_status (gobj (), exit_status);
  }

  auto
  ApplicationCommandLine::get_exit_status () const -> int
  {
    return g_application_command_line_get_exit_status (
        const_cast<GApplicationCommandLine*> (gobj ()));
  }

  auto
  ApplicationCommandLine::create_file_for_arg (const glib::ustring& arg) const -> glib::RefPtr<File>
  {
    return glib::wrap (g_application_command_line_create_file_for_arg (
        const_cast<GApplicationCommandLine*> (gobj ()),
        arg.c_str ()));
  }

} // namespace gio
