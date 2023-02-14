

#define GLIBMM_INCLUDED_FROM_WRAP_INIT_CC
#include <libmm-glib/error.hxx>
#include <libmm-glib/mm-glib.hxx>
#include <libmm-glib/object.hxx>
#include <libmm-glib/wrap_init.hxx>

#include <libmm-glib/binding.hxx>
#include <libmm-glib/bytearray.hxx>
#include <libmm-glib/bytes.hxx>
#include <libmm-glib/checksum.hxx>
#include <libmm-glib/convert.hxx>
#include <libmm-glib/date.hxx>
#include <libmm-glib/datetime.hxx>
#include <libmm-glib/enums.hxx>
#include <libmm-glib/fileutils.hxx>
#include <libmm-glib/iochannel.hxx>
#include <libmm-glib/keyfile.hxx>
#include <libmm-glib/markup.hxx>
#include <libmm-glib/miscutils.hxx>
#include <libmm-glib/module.hxx>
#include <libmm-glib/nodetree.hxx>
#include <libmm-glib/optioncontext.hxx>
#include <libmm-glib/optionentry.hxx>
#include <libmm-glib/optiongroup.hxx>
#include <libmm-glib/regex.hxx>
#include <libmm-glib/shell.hxx>
#include <libmm-glib/spawn.hxx>
#include <libmm-glib/timezone.hxx>
#include <libmm-glib/unicode.hxx>
#include <libmm-glib/uriutils.hxx>
#include <libmm-glib/variant.hxx>
#include <libmm-glib/variantdict.hxx>
#include <libmm-glib/variantiter.hxx>
#include <libmm-glib/varianttype.hxx>

namespace Glib
{

  class Binding_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> ObjectBase*;
  };

  auto
  wrap_init () -> void
  {
    Error::register_domain (g_convert_error_quark (),
                            &ConvertError::throw_func);
    Error::register_domain (g_file_error_quark (), &FileError::throw_func);
    Error::register_domain (g_io_channel_error_quark (),
                            &IOChannelError::throw_func);
    Error::register_domain (g_key_file_error_quark (),
                            &KeyFileError::throw_func);
    Error::register_domain (g_markup_error_quark (), &MarkupError::throw_func);
    Error::register_domain (g_option_error_quark (), &OptionError::throw_func);
    Error::register_domain (g_regex_error_quark (), &RegexError::throw_func);
    Error::register_domain (g_shell_error_quark (), &ShellError::throw_func);
    Error::register_domain (g_spawn_error_quark (), &SpawnError::throw_func);
    Error::register_domain (g_variant_parse_error_quark (),
                            &VariantParseError::throw_func);

    wrap_register (g_binding_get_type (), &Binding_Class::wrap_new);

    g_type_ensure (Binding::get_type ());
  }

} // namespace Glib
