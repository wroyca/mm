// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  #ifndef _GLIBMM_VALUE_H_INCLUDE_VALUE_BASICTYPES_H
    #error "glibmm/value_basictypes.h cannot be included directly"
  #endif
#endif

#if (__GNUC__ >= 3 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 96))
  #pragma GCC system_header
#endif

namespace glib
{

  template <>
  class LIBMM_GLIB_SYMEXPORT Value<bool> : public ValueBase
  {
  public:
    using CppType = bool;

    static auto
    value_type () -> GType G_GNUC_CONST;

    auto
    set (bool data) -> void;
    auto
    get () const -> bool;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    auto
    create_param_spec (const glib::ustring& name,
                       const glib::ustring& nick,
                       const glib::ustring& blurb,
                       glib::ParamFlags flags) const -> GParamSpec*;
#endif
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Value<signed char> : public ValueBase
  {
  public:
    using CppType = signed char;

    static auto
    value_type () -> GType G_GNUC_CONST;

    auto
    set (signed char data) -> void;
    auto
    get () const -> signed char;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    auto
    create_param_spec (const glib::ustring& name,
                       const glib::ustring& nick,
                       const glib::ustring& blurb,
                       glib::ParamFlags flags) const -> GParamSpec*;
#endif
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Value<unsigned char> : public ValueBase
  {
  public:
    using CppType = unsigned char;

    static auto
    value_type () -> GType G_GNUC_CONST;

    auto
    set (unsigned char data) -> void;
    auto
    get () const -> unsigned char;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    auto
    create_param_spec (const glib::ustring& name,
                       const glib::ustring& nick,
                       const glib::ustring& blurb,
                       glib::ParamFlags flags) const -> GParamSpec*;
#endif
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Value<int> : public ValueBase
  {
  public:
    using CppType = int;

    static auto
    value_type () -> GType G_GNUC_CONST;

    auto
    set (int data) -> void;
    auto
    get () const -> int;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    auto
    create_param_spec (const glib::ustring& name,
                       const glib::ustring& nick,
                       const glib::ustring& blurb,
                       glib::ParamFlags flags) const -> GParamSpec*;
#endif
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Value<unsigned int> : public ValueBase
  {
  public:
    using CppType = unsigned int;

    static auto
    value_type () -> GType G_GNUC_CONST;

    auto
    set (unsigned int data) -> void;
    auto
    get () const -> unsigned int;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    auto
    create_param_spec (const glib::ustring& name,
                       const glib::ustring& nick,
                       const glib::ustring& blurb,
                       glib::ParamFlags flags) const -> GParamSpec*;
#endif
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Value<long> : public ValueBase
  {
  public:
    using CppType = long;

    static auto
    value_type () -> GType G_GNUC_CONST;

    auto
    set (long data) -> void;
    auto
    get () const -> long;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    auto
    create_param_spec (const glib::ustring& name,
                       const glib::ustring& nick,
                       const glib::ustring& blurb,
                       glib::ParamFlags flags) const -> GParamSpec*;
#endif
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Value<unsigned long> : public ValueBase
  {
  public:
    using CppType = unsigned long;

    static auto
    value_type () -> GType G_GNUC_CONST;

    auto
    set (unsigned long data) -> void;
    auto
    get () const -> unsigned long;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    auto
    create_param_spec (const glib::ustring& name,
                       const glib::ustring& nick,
                       const glib::ustring& blurb,
                       glib::ParamFlags flags) const -> GParamSpec*;
#endif
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Value<long long> : public ValueBase
  {
  public:
    using CppType = long long;

    static auto
    value_type () -> GType G_GNUC_CONST;

    auto
    set (long long data) -> void;
    auto
    get () const -> long long;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    auto
    create_param_spec (const glib::ustring& name,
                       const glib::ustring& nick,
                       const glib::ustring& blurb,
                       glib::ParamFlags flags) const -> GParamSpec*;
#endif
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Value<unsigned long long> : public ValueBase
  {
  public:
    using CppType = unsigned long long;

    static auto
    value_type () -> GType G_GNUC_CONST;

    auto
    set (unsigned long long data) -> void;
    auto
    get () const -> unsigned long long;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    auto
    create_param_spec (const glib::ustring& name,
                       const glib::ustring& nick,
                       const glib::ustring& blurb,
                       glib::ParamFlags flags) const -> GParamSpec*;
#endif
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Value<float> : public ValueBase
  {
  public:
    using CppType = float;

    static auto
    value_type () -> GType G_GNUC_CONST;

    auto
    set (float data) -> void;
    auto
    get () const -> float;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    auto
    create_param_spec (const glib::ustring& name,
                       const glib::ustring& nick,
                       const glib::ustring& blurb,
                       glib::ParamFlags flags) const -> GParamSpec*;
#endif
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Value<double> : public ValueBase
  {
  public:
    using CppType = double;

    static auto
    value_type () -> GType G_GNUC_CONST;

    auto
    set (double data) -> void;
    auto
    get () const -> double;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    auto
    create_param_spec (const glib::ustring& name,
                       const glib::ustring& nick,
                       const glib::ustring& blurb,
                       glib::ParamFlags flags) const -> GParamSpec*;
#endif
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Value<void*> : public ValueBase
  {
  public:
    using CppType = void*;

    static auto
    value_type () -> GType G_GNUC_CONST;

    auto
    set (void* data) -> void;
    auto
    get () const -> void*;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    auto
    create_param_spec (const glib::ustring& name,
                       const glib::ustring& nick,
                       const glib::ustring& blurb,
                       glib::ParamFlags flags) const -> GParamSpec*;
#endif
  };

} // namespace glib
