

#undef G_DISABLE_DEPRECATED
#define GLIB_DISABLE_DEPRECATION_WARNINGS 1

#include <libmm-glib/value.hxx>

namespace Glib
{

  G_GNUC_EXTENSION typedef long long long_long;
  G_GNUC_EXTENSION typedef unsigned long long unsigned_long_long;

  auto
  Value<bool>::value_type () -> GType
  {
    return G_TYPE_BOOLEAN;
  }

  auto
  Value<bool>::set (const bool data) -> void
  {
    g_value_set_boolean (&gobject_, data);
  }

  auto
  Value<bool>::get () const -> bool
  {
    return g_value_get_boolean (&gobject_);
  }

  auto
  Value<bool>::create_param_spec (const ustring& name,
                                  const ustring& nick,
                                  const ustring& blurb,
                                  ParamFlags flags) const -> GParamSpec*
  {
    return g_param_spec_boolean (name.c_str (),
                                 nick.empty () ? nullptr : nick.c_str (),
                                 blurb.empty () ? nullptr : blurb.c_str (),
                                 g_value_get_boolean (&gobject_),
                                 static_cast<GParamFlags> (flags));
  }

  auto
  Value<signed char>::value_type () -> GType
  {
    return G_TYPE_CHAR;
  }

  auto
  Value<signed char>::set (const signed char data) -> void
  {
    g_value_set_schar (&gobject_, data);
  }

  auto
  Value<signed char>::get () const -> signed char
  {
    return g_value_get_schar (&gobject_);
  }

  auto
  Value<signed char>::create_param_spec (const ustring& name,
                                         const ustring& nick,
                                         const ustring& blurb,
                                         ParamFlags flags) const -> GParamSpec*
  {
    return g_param_spec_char (name.c_str (),
                              nick.empty () ? nullptr : nick.c_str (),
                              blurb.empty () ? nullptr : blurb.c_str (),
                              -128,
                              127,
                              g_value_get_schar (&gobject_),
                              static_cast<GParamFlags> (flags));
  }

  auto
  Value<unsigned char>::value_type () -> GType
  {
    return G_TYPE_UCHAR;
  }

  auto
  Value<unsigned char>::set (const unsigned char data) -> void
  {
    g_value_set_uchar (&gobject_, data);
  }

  auto
  Value<unsigned char>::get () const -> unsigned char
  {
    return g_value_get_uchar (&gobject_);
  }

  auto
  Value<unsigned char>::create_param_spec (const ustring& name,
                                           const ustring& nick,
                                           const ustring& blurb,
                                           ParamFlags flags) const -> GParamSpec*
  {
    return g_param_spec_uchar (name.c_str (),
                               nick.empty () ? nullptr : nick.c_str (),
                               blurb.empty () ? nullptr : blurb.c_str (),
                               0,
                               255,
                               g_value_get_uchar (&gobject_),
                               static_cast<GParamFlags> (flags));
  }

  auto
  Value<int>::value_type () -> GType
  {
    return G_TYPE_INT;
  }

  auto
  Value<int>::set (const int data) -> void
  {
    g_value_set_int (&gobject_, data);
  }

  auto
  Value<int>::get () const -> int
  {
    return g_value_get_int (&gobject_);
  }

  auto
  Value<int>::create_param_spec (const ustring& name,
                                 const ustring& nick,
                                 const ustring& blurb,
                                 ParamFlags flags) const -> GParamSpec*
  {
    return g_param_spec_int (name.c_str (),
                             nick.empty () ? nullptr : nick.c_str (),
                             blurb.empty () ? nullptr : blurb.c_str (),
                             G_MININT,
                             G_MAXINT,
                             g_value_get_int (&gobject_),
                             static_cast<GParamFlags> (flags));
  }

  auto
  Value<unsigned int>::value_type () -> GType
  {
    return G_TYPE_UINT;
  }

  auto
  Value<unsigned int>::set (const unsigned int data) -> void
  {
    g_value_set_uint (&gobject_, data);
  }

  auto
  Value<unsigned int>::get () const -> unsigned int
  {
    return g_value_get_uint (&gobject_);
  }

  auto
  Value<unsigned int>::create_param_spec (const ustring& name,
                                          const ustring& nick,
                                          const ustring& blurb,
                                          ParamFlags flags) const -> GParamSpec*
  {
    return g_param_spec_uint (name.c_str (),
                              nick.empty () ? nullptr : nick.c_str (),
                              blurb.empty () ? nullptr : blurb.c_str (),
                              0,
                              G_MAXUINT,
                              g_value_get_uint (&gobject_),
                              static_cast<GParamFlags> (flags));
  }

  auto
  Value<long>::value_type () -> GType
  {
    return G_TYPE_LONG;
  }

  auto
  Value<long>::set (const long data) -> void
  {
    g_value_set_long (&gobject_, data);
  }

  auto
  Value<long>::get () const -> long
  {
    return g_value_get_long (&gobject_);
  }

  auto
  Value<long>::create_param_spec (const ustring& name,
                                  const ustring& nick,
                                  const ustring& blurb,
                                  ParamFlags flags) const -> GParamSpec*
  {
    return g_param_spec_long (name.c_str (),
                              nick.empty () ? nullptr : nick.c_str (),
                              blurb.empty () ? nullptr : blurb.c_str (),
                              G_MINLONG,
                              G_MAXLONG,
                              g_value_get_long (&gobject_),
                              static_cast<GParamFlags> (flags));
  }

  auto
  Value<unsigned long>::value_type () -> GType
  {
    return G_TYPE_ULONG;
  }

  auto
  Value<unsigned long>::set (const unsigned long data) -> void
  {
    g_value_set_ulong (&gobject_, data);
  }

  auto
  Value<unsigned long>::get () const -> unsigned long
  {
    return g_value_get_ulong (&gobject_);
  }

  auto
  Value<unsigned long>::create_param_spec (const ustring& name,
                                           const ustring& nick,
                                           const ustring& blurb,
                                           ParamFlags flags) const -> GParamSpec*
  {
    return g_param_spec_ulong (name.c_str (),
                               nick.empty () ? nullptr : nick.c_str (),
                               blurb.empty () ? nullptr : blurb.c_str (),
                               0,
                               G_MAXULONG,
                               g_value_get_ulong (&gobject_),
                               static_cast<GParamFlags> (flags));
  }

  auto
  Value<long_long>::value_type () -> GType
  {
    return G_TYPE_INT64;
  }

  auto
  Value<long_long>::set (const long_long data) -> void
  {
    g_value_set_int64 (&gobject_, data);
  }

  auto
  Value<long_long>::get () const -> long_long
  {
    return g_value_get_int64 (&gobject_);
  }

  auto
  Value<long_long>::create_param_spec (const ustring& name,
                                       const ustring& nick,
                                       const ustring& blurb,
                                       ParamFlags flags) const -> GParamSpec*
  {
    return g_param_spec_int64 (name.c_str (),
                               nick.empty () ? nullptr : nick.c_str (),
                               blurb.empty () ? nullptr : blurb.c_str (),
                               G_GINT64_CONSTANT (0x8000000000000000),
                               G_GINT64_CONSTANT (0x7fffffffffffffff),
                               g_value_get_int64 (&gobject_),
                               static_cast<GParamFlags> (flags));
  }

  auto
  Value<unsigned_long_long>::value_type () -> GType
  {
    return G_TYPE_UINT64;
  }

  auto
  Value<unsigned_long_long>::set (const unsigned_long_long data) -> void
  {
    g_value_set_uint64 (&gobject_, data);
  }

  auto
  Value<unsigned_long_long>::get () const -> unsigned_long_long
  {
    return g_value_get_uint64 (&gobject_);
  }

  auto
  Value<unsigned_long_long>::create_param_spec (const ustring& name,
                                                const ustring& nick,
                                                const ustring& blurb,
                                                ParamFlags flags) const -> GParamSpec*
  {
    return g_param_spec_uint64 (name.c_str (),
                                nick.empty () ? nullptr : nick.c_str (),
                                blurb.empty () ? nullptr : blurb.c_str (),
                                G_GINT64_CONSTANT (0U),
                                G_GINT64_CONSTANT (0xffffffffffffffffU),
                                g_value_get_uint64 (&gobject_),
                                static_cast<GParamFlags> (flags));
  }

  auto
  Value<float>::value_type () -> GType
  {
    return G_TYPE_FLOAT;
  }

  auto
  Value<float>::set (const float data) -> void
  {
    g_value_set_float (&gobject_, data);
  }

  auto
  Value<float>::get () const -> float
  {
    return g_value_get_float (&gobject_);
  }

  auto
  Value<float>::create_param_spec (const ustring& name,
                                   const ustring& nick,
                                   const ustring& blurb,
                                   ParamFlags flags) const -> GParamSpec*
  {
    return g_param_spec_float (name.c_str (),
                               nick.empty () ? nullptr : nick.c_str (),
                               blurb.empty () ? nullptr : blurb.c_str (),
                               -G_MAXFLOAT,
                               G_MAXFLOAT,
                               g_value_get_float (&gobject_),
                               static_cast<GParamFlags> (flags));
  }

  auto
  Value<double>::value_type () -> GType
  {
    return G_TYPE_DOUBLE;
  }

  auto
  Value<double>::set (const double data) -> void
  {
    g_value_set_double (&gobject_, data);
  }

  auto
  Value<double>::get () const -> double
  {
    return g_value_get_double (&gobject_);
  }

  auto
  Value<double>::create_param_spec (const ustring& name,
                                    const ustring& nick,
                                    const ustring& blurb,
                                    ParamFlags flags) const -> GParamSpec*
  {
    return g_param_spec_double (name.c_str (),
                                nick.empty () ? nullptr : nick.c_str (),
                                blurb.empty () ? nullptr : blurb.c_str (),
                                -G_MAXDOUBLE,
                                G_MAXDOUBLE,
                                g_value_get_double (&gobject_),
                                static_cast<GParamFlags> (flags));
  }

  auto
  Value<void*>::value_type () -> GType
  {
    return G_TYPE_POINTER;
  }

  auto
  Value<void*>::set (void* data) -> void
  {
    g_value_set_pointer (&gobject_, data);
  }

  auto
  Value<void*>::get () const -> void*
  {
    return g_value_get_pointer (&gobject_);
  }

  auto
  Value<void*>::create_param_spec (const ustring& name,
                                   const ustring& nick,
                                   const ustring& blurb,
                                   ParamFlags flags) const -> GParamSpec*
  {
    return g_param_spec_pointer (name.c_str (),
                                 nick.empty () ? nullptr : nick.c_str (),
                                 blurb.empty () ? nullptr : blurb.c_str (),
                                 static_cast<GParamFlags> (flags));
  }

} // namespace Glib
