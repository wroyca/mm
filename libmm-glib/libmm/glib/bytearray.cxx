// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/glib/bytearray.hxx>
#include <libmm/glib/bytearray_p.hxx>

namespace
{

  extern "C"
  {
    auto
    ByteArray_Compare_Data_Func (const gconstpointer a,
                                 const gconstpointer b,
                                 const gpointer user_data) -> int
    {
      const Glib::ByteArray::SlotCompare* slot =
          static_cast<Glib::ByteArray::SlotCompare*> (user_data);

      return (*slot) (static_cast<const guint8*> (a),
                      static_cast<const guint8*> (b));
    }
  }
} // namespace

namespace Glib
{

  auto
  ByteArray::size () const -> guint
  {
    return gobj ()->len;
  }

  auto
  ByteArray::get_data () -> guint8*
  {
    return gobj ()->data;
  }

  auto
  ByteArray::get_data () const -> const guint8*
  {
    return gobj ()->data;
  }

} // namespace Glib

namespace
{
}

namespace Glib
{

  auto
  wrap (GByteArray* object, const bool take_copy) -> RefPtr<ByteArray>
  {
    if (take_copy && object)
      g_byte_array_ref (object);

    return Glib::make_refptr_for_instance<ByteArray> (
        reinterpret_cast<ByteArray*> (object));
  }

} // namespace Glib

namespace Glib
{

  auto
  ByteArray::get_type () -> GType
  {
    return g_byte_array_get_type ();
  }

  auto
  ByteArray::reference () const -> void
  {
    g_byte_array_ref (
        reinterpret_cast<GByteArray*> (const_cast<ByteArray*> (this)));
  }

  auto
  ByteArray::unreference () const -> void
  {
    g_byte_array_unref (
        reinterpret_cast<GByteArray*> (const_cast<ByteArray*> (this)));
  }

  auto
  ByteArray::gobj () -> GByteArray*
  {
    return reinterpret_cast<GByteArray*> (this);
  }

  auto
  ByteArray::gobj () const -> const GByteArray*
  {
    return reinterpret_cast<const GByteArray*> (this);
  }

  auto
  ByteArray::gobj_copy () const -> GByteArray*
  {
    const auto gobject =
        reinterpret_cast<GByteArray*> (const_cast<ByteArray*> (this));
    g_byte_array_ref (gobject);
    return gobject;
  }

  auto
  ByteArray::create () -> RefPtr<ByteArray>
  {
    return wrap (g_byte_array_new ());
  }

  auto
  ByteArray::append (const guint8* data, const guint len) -> RefPtr<ByteArray>
  {
    auto retvalue = wrap (g_byte_array_append (gobj (), data, len));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ByteArray::prepend (const guint8* data, const guint len) -> RefPtr<ByteArray>
  {
    auto retvalue = wrap (g_byte_array_prepend (gobj (), data, len));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ByteArray::remove_index (const guint index) -> RefPtr<ByteArray>
  {
    auto retvalue = wrap (g_byte_array_remove_index (gobj (), index));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ByteArray::remove_index_fast (const guint index) -> RefPtr<ByteArray>
  {
    auto retvalue = wrap (g_byte_array_remove_index_fast (gobj (), index));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ByteArray::remove_range (const guint index, const guint length) -> RefPtr<ByteArray>
  {
    auto retvalue = wrap (g_byte_array_remove_range (gobj (), index, length));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ByteArray::sort (const SlotCompare& slot) -> void
  {
    const auto slot_copy = const_cast<SlotCompare*> (&slot);

    g_byte_array_sort_with_data (gobj (),
                                 &ByteArray_Compare_Data_Func,
                                 slot_copy);
  }

  auto
  ByteArray::set_size (const guint length) -> RefPtr<ByteArray>
  {
    auto retvalue = wrap (g_byte_array_set_size (gobj (), length));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

} // namespace Glib
