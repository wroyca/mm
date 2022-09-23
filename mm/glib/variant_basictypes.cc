// This is a generated file, do not edit.  Generated from ../glib/glibmm/../src/variant_basictypes.cc.m4

#include <mm/glib/variant.h>

namespace Glib
{


/**** Glib::Variant<bool> ****************************************************/

// static
const VariantType& Variant<bool>::variant_type()
{
  static VariantType type(G_VARIANT_TYPE_BOOLEAN);
  return type;
}

Variant<bool> Variant<bool>::create(bool data)
{
  auto result = Variant<bool>(g_variant_new_boolean(data));
  return result;
}

bool Variant<bool>::get() const
{
  return g_variant_get_boolean(gobject_);
}


/**** Glib::Variant<unsigned char> *******************************************/

// static
const VariantType& Variant<unsigned char>::variant_type()
{
  static VariantType type(G_VARIANT_TYPE_BYTE);
  return type;
}

Variant<unsigned char> Variant<unsigned char>::create(unsigned char data)
{
  auto result = Variant<unsigned char>(g_variant_new_byte(data));
  return result;
}

unsigned char Variant<unsigned char>::get() const
{
  return g_variant_get_byte(gobject_);
}


/**** Glib::Variant<gint16> **************************************************/

// static
const VariantType& Variant<gint16>::variant_type()
{
  static VariantType type(G_VARIANT_TYPE_INT16);
  return type;
}

Variant<gint16> Variant<gint16>::create(gint16 data)
{
  auto result = Variant<gint16>(g_variant_new_int16(data));
  return result;
}

gint16 Variant<gint16>::get() const
{
  return g_variant_get_int16(gobject_);
}


/**** Glib::Variant<guint16> *************************************************/

// static
const VariantType& Variant<guint16>::variant_type()
{
  static VariantType type(G_VARIANT_TYPE_UINT16);
  return type;
}

Variant<guint16> Variant<guint16>::create(guint16 data)
{
  auto result = Variant<guint16>(g_variant_new_uint16(data));
  return result;
}

guint16 Variant<guint16>::get() const
{
  return g_variant_get_uint16(gobject_);
}


/**** Glib::Variant<gint32> **************************************************/

// static
const VariantType& Variant<gint32>::variant_type()
{
  static VariantType type(G_VARIANT_TYPE_INT32);
  return type;
}

Variant<gint32> Variant<gint32>::create(gint32 data)
{
  auto result = Variant<gint32>(g_variant_new_int32(data));
  return result;
}

Variant<gint32> Variant<gint32>::create_handle(gint32 data)
{
  auto result = Variant<gint32>(g_variant_new_handle(data));
  return result;
}

gint32 Variant<gint32>::get() const
{
  if (get_type().equal(VARIANT_TYPE_INT32))
    return g_variant_get_int32(gobject_);
  else
    return g_variant_get_handle(gobject_);
}


/**** Glib::Variant<guint32> *************************************************/

// static
const VariantType& Variant<guint32>::variant_type()
{
  static VariantType type(G_VARIANT_TYPE_UINT32);
  return type;
}

Variant<guint32> Variant<guint32>::create(guint32 data)
{
  auto result = Variant<guint32>(g_variant_new_uint32(data));
  return result;
}

guint32 Variant<guint32>::get() const
{
  return g_variant_get_uint32(gobject_);
}


/**** Glib::Variant<gint64> **************************************************/

// static
const VariantType& Variant<gint64>::variant_type()
{
  static VariantType type(G_VARIANT_TYPE_INT64);
  return type;
}

Variant<gint64> Variant<gint64>::create(gint64 data)
{
  auto result = Variant<gint64>(g_variant_new_int64(data));
  return result;
}

gint64 Variant<gint64>::get() const
{
  return g_variant_get_int64(gobject_);
}


/**** Glib::Variant<guint64> *************************************************/

// static
const VariantType& Variant<guint64>::variant_type()
{
  static VariantType type(G_VARIANT_TYPE_UINT64);
  return type;
}

Variant<guint64> Variant<guint64>::create(guint64 data)
{
  auto result = Variant<guint64>(g_variant_new_uint64(data));
  return result;
}

guint64 Variant<guint64>::get() const
{
  return g_variant_get_uint64(gobject_);
}


/**** Glib::Variant<double> **************************************************/

// static
const VariantType& Variant<double>::variant_type()
{
  static VariantType type(G_VARIANT_TYPE_DOUBLE);
  return type;
}

Variant<double> Variant<double>::create(double data)
{
  auto result = Variant<double>(g_variant_new_double(data));
  return result;
}

double Variant<double>::get() const
{
  return g_variant_get_double(gobject_);
}


} // namespace Glib
