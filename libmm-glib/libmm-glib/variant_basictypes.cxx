// This is a generated file, do not edit.  Generated from ../glib/glibmm/../src/variant_basictypes.cc.m4

#include <libmm-glib/variant.hxx>

namespace Glib
{


/**** Glib::Variant<bool> ****************************************************/

// static
auto Variant<bool>::variant_type() -> const VariantType&
{
  static VariantType type(G_VARIANT_TYPE_BOOLEAN);
  return type;
}

auto Variant<bool>::create(
  const bool data) -> Variant<bool>
{
  auto result = Variant<bool>(g_variant_new_boolean(data));
  return result;
}

auto Variant<bool>::get() const -> bool
{
  return g_variant_get_boolean(gobject_);
}


/**** Glib::Variant<unsigned char> *******************************************/

// static
auto Variant<unsigned char>::variant_type() -> const VariantType&
{
  static VariantType type(G_VARIANT_TYPE_BYTE);
  return type;
}

auto Variant<unsigned char>::create(
  const unsigned char data) -> Variant<unsigned char>
{
  auto result = Variant<unsigned char>(g_variant_new_byte(data));
  return result;
}

auto Variant<unsigned char>::get() const -> unsigned char
{
  return g_variant_get_byte(gobject_);
}


/**** Glib::Variant<gint16> **************************************************/

// static
auto Variant<gint16>::variant_type() -> const VariantType&
{
  static VariantType type(G_VARIANT_TYPE_INT16);
  return type;
}

auto Variant<gint16>::create(
  const gint16 data) -> Variant<gint16>
{
  auto result = Variant<gint16>(g_variant_new_int16(data));
  return result;
}

auto Variant<gint16>::get() const -> gint16
{
  return g_variant_get_int16(gobject_);
}


/**** Glib::Variant<guint16> *************************************************/

// static
auto Variant<guint16>::variant_type() -> const VariantType&
{
  static VariantType type(G_VARIANT_TYPE_UINT16);
  return type;
}

auto Variant<guint16>::create(
  const guint16 data) -> Variant<guint16>
{
  auto result = Variant<guint16>(g_variant_new_uint16(data));
  return result;
}

auto Variant<guint16>::get() const -> guint16
{
  return g_variant_get_uint16(gobject_);
}


/**** Glib::Variant<gint32> **************************************************/

// static
auto Variant<gint32>::variant_type() -> const VariantType&
{
  static VariantType type(G_VARIANT_TYPE_INT32);
  return type;
}

auto Variant<gint32>::create(
  const gint32 data) -> Variant<gint32>
{
  auto result = Variant<gint32>(g_variant_new_int32(data));
  return result;
}

auto Variant<gint32>::create_handle(
  const gint32 data) -> Variant<gint32>
{
  auto result = Variant<gint32>(g_variant_new_handle(data));
  return result;
}

auto Variant<gint32>::get() const -> gint32
{
  if (get_type().equal(VARIANT_TYPE_INT32))
    return g_variant_get_int32(gobject_);
  else
    return g_variant_get_handle(gobject_);
}


/**** Glib::Variant<guint32> *************************************************/

// static
auto Variant<guint32>::variant_type() -> const VariantType&
{
  static VariantType type(G_VARIANT_TYPE_UINT32);
  return type;
}

auto Variant<guint32>::create(
  const guint32 data) -> Variant<guint32>
{
  auto result = Variant<guint32>(g_variant_new_uint32(data));
  return result;
}

auto Variant<guint32>::get() const -> guint32
{
  return g_variant_get_uint32(gobject_);
}


/**** Glib::Variant<gint64> **************************************************/

// static
auto Variant<gint64>::variant_type() -> const VariantType&
{
  static VariantType type(G_VARIANT_TYPE_INT64);
  return type;
}

auto Variant<gint64>::create(
  const gint64 data) -> Variant<gint64>
{
  auto result = Variant<gint64>(g_variant_new_int64(data));
  return result;
}

auto Variant<gint64>::get() const -> gint64
{
  return g_variant_get_int64(gobject_);
}


/**** Glib::Variant<guint64> *************************************************/

// static
auto Variant<guint64>::variant_type() -> const VariantType&
{
  static VariantType type(G_VARIANT_TYPE_UINT64);
  return type;
}

auto Variant<guint64>::create(
  const guint64 data) -> Variant<guint64>
{
  auto result = Variant<guint64>(g_variant_new_uint64(data));
  return result;
}

auto Variant<guint64>::get() const -> guint64
{
  return g_variant_get_uint64(gobject_);
}


/**** Glib::Variant<double> **************************************************/

// static
auto Variant<double>::variant_type() -> const VariantType&
{
  static VariantType type(G_VARIANT_TYPE_DOUBLE);
  return type;
}

auto Variant<double>::create(
  const double data) -> Variant<double>
{
  auto result = Variant<double>(g_variant_new_double(data));
  return result;
}

auto Variant<double>::get() const -> double
{
  return g_variant_get_double(gobject_);
}


} // namespace Glib
