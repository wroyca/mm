// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_KEYFILE_H
#define _GLIBMM_KEYFILE_H

#include <glib.h>
#include <libmm-glib/error.hxx>
#include <libmm-glib/mm-glibconfig.hxx>
#include <libmm-glib/refptr.hxx>
#include <libmm-glib/ustring.hxx>
#include <libmm-glib/utility.hxx>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GKeyFile GKeyFile;
}
#endif

namespace Glib
{

  class KeyFileError : public Glib::Error
  {
  public:
    enum Code
    {
      UNKNOWN_ENCODING,
      PARSE,
      NOT_FOUND,
      KEY_NOT_FOUND,
      GROUP_NOT_FOUND,
      INVALID_VALUE
    };

    GLIBMM_API
    KeyFileError (Code error_code, const Glib::ustring& error_message);
    GLIBMM_API explicit KeyFileError (GError* gobject);
    GLIBMM_API auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    GLIBMM_API static auto
    throw_func (GError* gobject) -> void;

    friend GLIBMM_API auto
    wrap_init () -> void;

#endif
  };

  class GLIBMM_API KeyFile final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = KeyFile;
    using BaseObjectType = GKeyFile;
#endif

    static auto
    create () -> Glib::RefPtr<KeyFile>;

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> GKeyFile*;

    auto
    gobj () const -> const GKeyFile*;

    auto
    gobj_copy () const -> GKeyFile*;

    KeyFile () = delete;

    KeyFile (const KeyFile&) = delete;
    auto
    operator= (const KeyFile&) -> KeyFile& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  public:
    enum class Flags
    {
      NONE = 0x0,
      KEEP_COMMENTS = 1 << 0,
      KEEP_TRANSLATIONS = 1 << 1
    };

    auto
    load_from_file (const std::string& file, Flags flags = Flags::NONE) -> bool;

    auto
    load_from_data (const Glib::ustring& data, Flags flags = Flags::NONE)
        -> bool;

    auto
    load_from_dirs (const std::string& file,
                    const std::vector<std::string>& search_dirs,
                    std::string& full_path,
                    Flags flags = Flags::NONE) -> bool;

    auto
    load_from_data_dirs (const std::string& file,
                         std::string& full_path,
                         Flags flags = Flags::NONE) -> bool;

    auto
    to_data () -> Glib::ustring;

    auto
    save_to_file (const std::string& filename) -> bool;

    auto
    get_start_group () const -> Glib::ustring;

    auto
    get_groups () const -> std::vector<Glib::ustring>;

    auto
    get_keys (const Glib::ustring& group_name) const
        -> std::vector<Glib::ustring>;

    auto
    has_group (const Glib::ustring& group_name) const -> bool;

    auto
    has_key (const Glib::ustring& group_name, const Glib::ustring& key) const
        -> bool;

    auto
    get_value (const Glib::ustring& group_name, const Glib::ustring& key) const
        -> Glib::ustring;

    auto
    get_string (const Glib::ustring& group_name, const Glib::ustring& key) const
        -> Glib::ustring;

    auto
    get_locale_for_key (const Glib::ustring& group_name,
                        const Glib::ustring& key,
                        const Glib::ustring& locale = {}) const
        -> Glib::ustring;

    auto
    get_locale_string (const Glib::ustring& group_name,
                       const Glib::ustring& key) const -> Glib::ustring;

    auto
    get_locale_string (const Glib::ustring& group_name,
                       const Glib::ustring& key,
                       const Glib::ustring& locale) const -> Glib::ustring;

    auto
    get_boolean (const Glib::ustring& key) const -> bool;

    auto
    get_boolean (const Glib::ustring& group_name,
                 const Glib::ustring& key) const -> bool;

    auto
    get_integer (const Glib::ustring& key) const -> int;

    auto
    get_integer (const Glib::ustring& group_name,
                 const Glib::ustring& key) const -> int;

    auto
    get_int64 (const Glib::ustring& key) const -> gint64;

    auto
    get_int64 (const Glib::ustring& group_name, const Glib::ustring& key) const
        -> gint64;

    auto
    get_uint64 (const Glib::ustring& key) const -> guint64;

    auto
    get_uint64 (const Glib::ustring& group_name, const Glib::ustring& key) const
        -> guint64;

    auto
    get_double (const Glib::ustring& key) const -> double;

    auto
    get_double (const Glib::ustring& group_name, const Glib::ustring& key) const
        -> double;

    auto
    set_double (const Glib::ustring& group_name,
                const Glib::ustring& key,
                double value) -> void;

    auto
    set_double (const Glib::ustring& key, double value) -> void;

    auto
    get_string_list (const Glib::ustring& group_name,
                     const Glib::ustring& key) const
        -> std::vector<Glib::ustring>;

    auto
    get_locale_string_list (const Glib::ustring& group_name,
                            const Glib::ustring& key) const
        -> std::vector<Glib::ustring>;

    auto
    get_locale_string_list (const Glib::ustring& group_name,
                            const Glib::ustring& key,
                            const Glib::ustring& locale) const
        -> std::vector<Glib::ustring>;

    auto
    get_boolean_list (const Glib::ustring& group_name,
                      const Glib::ustring& key) const -> std::vector<bool>;

    auto
    get_integer_list (const Glib::ustring& group_name,
                      const Glib::ustring& key) const -> std::vector<int>;

    auto
    get_double_list (const Glib::ustring& group_name,
                     const Glib::ustring& key) const -> std::vector<double>;

    auto
    get_comment () const -> Glib::ustring;

    auto
    get_comment (const Glib::ustring& group_name) const -> Glib::ustring;

    auto
    get_comment (const Glib::ustring& group_name,
                 const Glib::ustring& key) const -> Glib::ustring;

    auto
    set_list_separator (gchar separator) -> void;

    auto
    set_value (const Glib::ustring& group_name,
               const Glib::ustring& key,
               const Glib::ustring& value) -> void;

    auto
    set_string (const Glib::ustring& group_name,
                const Glib::ustring& key,
                const Glib::ustring& string) -> void;

    auto
    set_locale_string (const Glib::ustring& group_name,
                       const Glib::ustring& key,
                       const Glib::ustring& locale,
                       const Glib::ustring& string) -> void;

    auto
    set_boolean (const Glib::ustring& group_name,
                 const Glib::ustring& key,
                 bool value) -> void;

    auto
    set_integer (const Glib::ustring& group_name,
                 const Glib::ustring& key,
                 int value) -> void;

    auto
    set_int64 (const Glib::ustring& group_name,
               const Glib::ustring& key,
               gint64 value) -> void;

    auto
    set_uint64 (const Glib::ustring& group_name,
                const Glib::ustring& key,
                guint64 value) -> void;

    auto
    set_string_list (const Glib::ustring& group_name,
                     const Glib::ustring& key,
                     const std::vector<Glib::ustring>& list) -> void;

    auto
    set_locale_string_list (const Glib::ustring& group_name,
                            const Glib::ustring& key,
                            const Glib::ustring& locale,
                            const std::vector<Glib::ustring>& list) -> void;

    auto
    set_boolean_list (const Glib::ustring& group_name,
                      const Glib::ustring& key,
                      const std::vector<bool>& list) -> void;

    auto
    set_integer_list (const Glib::ustring& group_name,
                      const Glib::ustring& key,
                      const std::vector<int>& list) -> void;

    auto
    set_double_list (const Glib::ustring& group_name,
                     const Glib::ustring& key,
                     const std::vector<double>& list) -> void;

    auto
    set_comment (const Glib::ustring& comment) -> void;

    auto
    set_comment (const Glib::ustring& group_name, const Glib::ustring& comment)
        -> void;

    auto
    set_comment (const Glib::ustring& group_name,
                 const Glib::ustring& key,
                 const Glib::ustring& comment) -> void;

    auto
    remove_comment (const Glib::ustring& group_name, const Glib::ustring& key)
        -> void;

    auto
    remove_key (const Glib::ustring& group_name, const Glib::ustring& key)
        -> void;

    auto
    remove_group (const Glib::ustring& group_name) -> void;
  };

} // namespace Glib

namespace Glib
{

  inline auto
  operator| (KeyFile::Flags lhs, KeyFile::Flags rhs) -> KeyFile::Flags
  {
    return static_cast<KeyFile::Flags> (static_cast<unsigned> (lhs) |
                                        static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (KeyFile::Flags lhs, KeyFile::Flags rhs) -> KeyFile::Flags
  {
    return static_cast<KeyFile::Flags> (static_cast<unsigned> (lhs) &
                                        static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (KeyFile::Flags lhs, KeyFile::Flags rhs) -> KeyFile::Flags
  {
    return static_cast<KeyFile::Flags> (static_cast<unsigned> (lhs) ^
                                        static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(KeyFile::Flags flags) -> KeyFile::Flags
  {
    return static_cast<KeyFile::Flags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (KeyFile::Flags& lhs, KeyFile::Flags rhs) -> KeyFile::Flags&
  {
    return (lhs = static_cast<KeyFile::Flags> (static_cast<unsigned> (lhs) |
                                               static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (KeyFile::Flags& lhs, KeyFile::Flags rhs) -> KeyFile::Flags&
  {
    return (lhs = static_cast<KeyFile::Flags> (static_cast<unsigned> (lhs) &
                                               static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (KeyFile::Flags& lhs, KeyFile::Flags rhs) -> KeyFile::Flags&
  {
    return (lhs = static_cast<KeyFile::Flags> (static_cast<unsigned> (lhs) ^
                                               static_cast<unsigned> (rhs)));
  }
} // namespace Glib

namespace Glib
{

  GLIBMM_API
  auto
  wrap (GKeyFile* object, bool take_copy = false) -> Glib::RefPtr<Glib::KeyFile>;

} // namespace Glib

#endif
