// This is a generated file, do not edit.  Generated from ../glib/glibmm/../src/value_basictypes.cc.m4

/* So we can use deprecated functions in our deprecated methods */
#undef G_DISABLE_DEPRECATED
#define GLIB_DISABLE_DEPRECATION_WARNINGS 1

#include <glibmm/value.h>

namespace Glib
{

G_GNUC_EXTENSION typedef long long long_long;
G_GNUC_EXTENSION typedef unsigned long long unsigned_long_long;


/**** Glib::Value<bool> ****************************************************/

// static
GType Value<bool>::value_type()
{
  return G_TYPE_BOOLEAN;
}

void Value<bool>::set(bool data)
{
  g_value_set_boolean(&gobject_, data);
}

bool Value<bool>::get() const
{
  return g_value_get_boolean(&gobject_);
}

GParamSpec* Value<bool>::create_param_spec(const Glib::ustring& name, const Glib::ustring& nick,
                                         const Glib::ustring& blurb, Glib::ParamFlags flags) const
{
  return g_param_spec_boolean(
      name.c_str(), nick.empty() ? nullptr : nick.c_str(),
      blurb.empty() ? nullptr : blurb.c_str(), 
      g_value_get_boolean(&gobject_),
      static_cast<GParamFlags>(flags));
}


/**** Glib::Value<signed char> *********************************************/

// static
GType Value<signed char>::value_type()
{
  return G_TYPE_CHAR;
}

void Value<signed char>::set(signed char data)
{
  g_value_set_schar(&gobject_, data);
}

signed char Value<signed char>::get() const
{
  return g_value_get_schar(&gobject_);
}

GParamSpec* Value<signed char>::create_param_spec(const Glib::ustring& name, const Glib::ustring& nick,
                                         const Glib::ustring& blurb, Glib::ParamFlags flags) const
{
  return g_param_spec_char(
      name.c_str(), nick.empty() ? nullptr : nick.c_str(),
      blurb.empty() ? nullptr : blurb.c_str(), 
      -128, 127, g_value_get_schar(&gobject_),
      static_cast<GParamFlags>(flags));
}


/**** Glib::Value<unsigned char> *******************************************/

// static
GType Value<unsigned char>::value_type()
{
  return G_TYPE_UCHAR;
}

void Value<unsigned char>::set(unsigned char data)
{
  g_value_set_uchar(&gobject_, data);
}

unsigned char Value<unsigned char>::get() const
{
  return g_value_get_uchar(&gobject_);
}

GParamSpec* Value<unsigned char>::create_param_spec(const Glib::ustring& name, const Glib::ustring& nick,
                                         const Glib::ustring& blurb, Glib::ParamFlags flags) const
{
  return g_param_spec_uchar(
      name.c_str(), nick.empty() ? nullptr : nick.c_str(),
      blurb.empty() ? nullptr : blurb.c_str(), 
      0, 255, g_value_get_uchar(&gobject_),
      static_cast<GParamFlags>(flags));
}


/**** Glib::Value<int> *****************************************************/

// static
GType Value<int>::value_type()
{
  return G_TYPE_INT;
}

void Value<int>::set(int data)
{
  g_value_set_int(&gobject_, data);
}

int Value<int>::get() const
{
  return g_value_get_int(&gobject_);
}

GParamSpec* Value<int>::create_param_spec(const Glib::ustring& name, const Glib::ustring& nick,
                                         const Glib::ustring& blurb, Glib::ParamFlags flags) const
{
  return g_param_spec_int(
      name.c_str(), nick.empty() ? nullptr : nick.c_str(),
      blurb.empty() ? nullptr : blurb.c_str(), 
      G_MININT, G_MAXINT, g_value_get_int(&gobject_),
      static_cast<GParamFlags>(flags));
}


/**** Glib::Value<unsigned int> ********************************************/

// static
GType Value<unsigned int>::value_type()
{
  return G_TYPE_UINT;
}

void Value<unsigned int>::set(unsigned int data)
{
  g_value_set_uint(&gobject_, data);
}

unsigned int Value<unsigned int>::get() const
{
  return g_value_get_uint(&gobject_);
}

GParamSpec* Value<unsigned int>::create_param_spec(const Glib::ustring& name, const Glib::ustring& nick,
                                         const Glib::ustring& blurb, Glib::ParamFlags flags) const
{
  return g_param_spec_uint(
      name.c_str(), nick.empty() ? nullptr : nick.c_str(),
      blurb.empty() ? nullptr : blurb.c_str(), 
      0, G_MAXUINT, g_value_get_uint(&gobject_),
      static_cast<GParamFlags>(flags));
}


/**** Glib::Value<long> ****************************************************/

// static
GType Value<long>::value_type()
{
  return G_TYPE_LONG;
}

void Value<long>::set(long data)
{
  g_value_set_long(&gobject_, data);
}

long Value<long>::get() const
{
  return g_value_get_long(&gobject_);
}

GParamSpec* Value<long>::create_param_spec(const Glib::ustring& name, const Glib::ustring& nick,
                                         const Glib::ustring& blurb, Glib::ParamFlags flags) const
{
  return g_param_spec_long(
      name.c_str(), nick.empty() ? nullptr : nick.c_str(),
      blurb.empty() ? nullptr : blurb.c_str(), 
      G_MINLONG, G_MAXLONG, g_value_get_long(&gobject_),
      static_cast<GParamFlags>(flags));
}


/**** Glib::Value<unsigned long> *******************************************/

// static
GType Value<unsigned long>::value_type()
{
  return G_TYPE_ULONG;
}

void Value<unsigned long>::set(unsigned long data)
{
  g_value_set_ulong(&gobject_, data);
}

unsigned long Value<unsigned long>::get() const
{
  return g_value_get_ulong(&gobject_);
}

GParamSpec* Value<unsigned long>::create_param_spec(const Glib::ustring& name, const Glib::ustring& nick,
                                         const Glib::ustring& blurb, Glib::ParamFlags flags) const
{
  return g_param_spec_ulong(
      name.c_str(), nick.empty() ? nullptr : nick.c_str(),
      blurb.empty() ? nullptr : blurb.c_str(), 
      0, G_MAXULONG, g_value_get_ulong(&gobject_),
      static_cast<GParamFlags>(flags));
}


/**** Glib::Value<long_long> ***********************************************/

// static
GType Value<long_long>::value_type()
{
  return G_TYPE_INT64;
}

void Value<long_long>::set(long_long data)
{
  g_value_set_int64(&gobject_, data);
}

long_long Value<long_long>::get() const
{
  return g_value_get_int64(&gobject_);
}

GParamSpec* Value<long_long>::create_param_spec(const Glib::ustring& name, const Glib::ustring& nick,
                                         const Glib::ustring& blurb, Glib::ParamFlags flags) const
{
  return g_param_spec_int64(
      name.c_str(), nick.empty() ? nullptr : nick.c_str(),
      blurb.empty() ? nullptr : blurb.c_str(), 
      G_GINT64_CONSTANT(0x8000000000000000), G_GINT64_CONSTANT(0x7fffffffffffffff), g_value_get_int64(&gobject_),
      static_cast<GParamFlags>(flags));
}


/**** Glib::Value<unsigned_long_long> **************************************/

// static
GType Value<unsigned_long_long>::value_type()
{
  return G_TYPE_UINT64;
}

void Value<unsigned_long_long>::set(unsigned_long_long data)
{
  g_value_set_uint64(&gobject_, data);
}

unsigned_long_long Value<unsigned_long_long>::get() const
{
  return g_value_get_uint64(&gobject_);
}

GParamSpec* Value<unsigned_long_long>::create_param_spec(const Glib::ustring& name, const Glib::ustring& nick,
                                         const Glib::ustring& blurb, Glib::ParamFlags flags) const
{
  return g_param_spec_uint64(
      name.c_str(), nick.empty() ? nullptr : nick.c_str(),
      blurb.empty() ? nullptr : blurb.c_str(), 
      G_GINT64_CONSTANT(0U), G_GINT64_CONSTANT(0xffffffffffffffffU), g_value_get_uint64(&gobject_),
      static_cast<GParamFlags>(flags));
}


/**** Glib::Value<float> ***************************************************/

// static
GType Value<float>::value_type()
{
  return G_TYPE_FLOAT;
}

void Value<float>::set(float data)
{
  g_value_set_float(&gobject_, data);
}

float Value<float>::get() const
{
  return g_value_get_float(&gobject_);
}

GParamSpec* Value<float>::create_param_spec(const Glib::ustring& name, const Glib::ustring& nick,
                                         const Glib::ustring& blurb, Glib::ParamFlags flags) const
{
  return g_param_spec_float(
      name.c_str(), nick.empty() ? nullptr : nick.c_str(),
      blurb.empty() ? nullptr : blurb.c_str(), 
      -G_MAXFLOAT, G_MAXFLOAT, g_value_get_float(&gobject_),
      static_cast<GParamFlags>(flags));
}


/**** Glib::Value<double> **************************************************/

// static
GType Value<double>::value_type()
{
  return G_TYPE_DOUBLE;
}

void Value<double>::set(double data)
{
  g_value_set_double(&gobject_, data);
}

double Value<double>::get() const
{
  return g_value_get_double(&gobject_);
}

GParamSpec* Value<double>::create_param_spec(const Glib::ustring& name, const Glib::ustring& nick,
                                         const Glib::ustring& blurb, Glib::ParamFlags flags) const
{
  return g_param_spec_double(
      name.c_str(), nick.empty() ? nullptr : nick.c_str(),
      blurb.empty() ? nullptr : blurb.c_str(), 
      -G_MAXDOUBLE, G_MAXDOUBLE, g_value_get_double(&gobject_),
      static_cast<GParamFlags>(flags));
}


/**** Glib::Value<void*> ***************************************************/

// static
GType Value<void*>::value_type()
{
  return G_TYPE_POINTER;
}

void Value<void*>::set(void* data)
{
  g_value_set_pointer(&gobject_, data);
}

void* Value<void*>::get() const
{
  return g_value_get_pointer(&gobject_);
}

GParamSpec* Value<void*>::create_param_spec(const Glib::ustring& name, const Glib::ustring& nick,
                                         const Glib::ustring& blurb, Glib::ParamFlags flags) const
{
  return g_param_spec_pointer(
      name.c_str(), nick.empty() ? nullptr : nick.c_str(),
      blurb.empty() ? nullptr : blurb.c_str(), 
      static_cast<GParamFlags>(flags));
}

} // namespace Glib
