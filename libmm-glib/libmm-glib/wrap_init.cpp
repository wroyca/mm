

#define GLIBMM_INCLUDED_FROM_WRAP_INIT_CC
#include <mm/glib/mm-glib.hpp>
#include <mm/glib/wrap_init.hpp>
#include <mm/glib/error.hpp>
#include <mm/glib/object.hpp>

// #include the widget headers so that we can call the get_type() static methods:
#include <mm/glib/binding.hpp>
#include <mm/glib/bytearray.hpp>
#include <mm/glib/bytes.hpp>
#include <mm/glib/checksum.hpp>
#include <mm/glib/convert.hpp>
#include <mm/glib/date.hpp>
#include <mm/glib/datetime.hpp>
#include <mm/glib/enums.hpp>
#include <mm/glib/fileutils.hpp>
#include <mm/glib/iochannel.hpp>
#include <mm/glib/keyfile.hpp>
#include <mm/glib/markup.hpp>
#include <mm/glib/miscutils.hpp>
#include <mm/glib/module.hpp>
#include <mm/glib/nodetree.hpp>
#include <mm/glib/optioncontext.hpp>
#include <mm/glib/optionentry.hpp>
#include <mm/glib/optiongroup.hpp>
#include <mm/glib/regex.hpp>
#include <mm/glib/shell.hpp>
#include <mm/glib/spawn.hpp>
#include <mm/glib/timezone.hpp>
#include <mm/glib/unicode.hpp>
#include <mm/glib/uriutils.hpp>
#include <mm/glib/variant.hpp>
#include <mm/glib/variantdict.hpp>
#include <mm/glib/variantiter.hpp>
#include <mm/glib/varianttype.hpp>

namespace Glib {

//Declarations of the *_Class::wrap_new() methods, instead of including all the private headers:

class Binding_Class { public: static auto wrap_new(GObject*) -> ObjectBase*; };

auto wrap_init () -> void
{
  // Register Error domains in the main namespace:
  Error::register_domain(g_convert_error_quark(), &ConvertError::throw_func);
  Error::register_domain(g_file_error_quark(), &FileError::throw_func);
  Error::register_domain(g_io_channel_error_quark(), &IOChannelError::throw_func);
  Error::register_domain(g_key_file_error_quark(), &KeyFileError::throw_func);
  Error::register_domain(g_markup_error_quark(), &MarkupError::throw_func);
  Error::register_domain(g_option_error_quark(), &OptionError::throw_func);
  Error::register_domain(g_regex_error_quark(), &RegexError::throw_func);
  Error::register_domain(g_shell_error_quark(), &ShellError::throw_func);
  Error::register_domain(g_spawn_error_quark(), &SpawnError::throw_func);
  Error::register_domain(g_variant_parse_error_quark(), &VariantParseError::throw_func);

  // Map gtypes to gtkmm wrapper-creation functions:
  wrap_register(g_binding_get_type(), &Binding_Class::wrap_new);

  // Register the gtkmm gtypes:
  g_type_ensure(Binding::get_type());

} // wrap_init()

} // Glib

