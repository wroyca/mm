

#define GLIBMM_INCLUDED_FROM_WRAP_INIT_CC
#include <libmm-glib/mm-glib.hpp>
#include <libmm-glib/wrap_init.hpp>
#include <libmm-glib/error.hpp>
#include <libmm-glib/object.hpp>

// #include the widget headers so that we can call the get_type() static methods:
#include <libmm-glib/binding.hpp>
#include <libmm-glib/bytearray.hpp>
#include <libmm-glib/bytes.hpp>
#include <libmm-glib/checksum.hpp>
#include <libmm-glib/convert.hpp>
#include <libmm-glib/date.hpp>
#include <libmm-glib/datetime.hpp>
#include <libmm-glib/enums.hpp>
#include <libmm-glib/fileutils.hpp>
#include <libmm-glib/iochannel.hpp>
#include <libmm-glib/keyfile.hpp>
#include <libmm-glib/markup.hpp>
#include <libmm-glib/miscutils.hpp>
#include <libmm-glib/module.hpp>
#include <libmm-glib/nodetree.hpp>
#include <libmm-glib/optioncontext.hpp>
#include <libmm-glib/optionentry.hpp>
#include <libmm-glib/optiongroup.hpp>
#include <libmm-glib/regex.hpp>
#include <libmm-glib/shell.hpp>
#include <libmm-glib/spawn.hpp>
#include <libmm-glib/timezone.hpp>
#include <libmm-glib/unicode.hpp>
#include <libmm-glib/uriutils.hpp>
#include <libmm-glib/variant.hpp>
#include <libmm-glib/variantdict.hpp>
#include <libmm-glib/variantiter.hpp>
#include <libmm-glib/varianttype.hpp>

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

