// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/glib/bytes.hxx>
#include <libmm/glib/bytes_p.hxx>

namespace glib
{

  auto
  Bytes::create (const gconstpointer data, const gsize size) -> RefPtr<Bytes>
  {
    GBytes* bytes = g_bytes_new (data, size);
    return wrap (bytes);
  }

  GType
  Value<RefPtr<glib::Bytes>>::value_type()
  {
    return g_bytes_get_type();
  }

  void
  Value<RefPtr<glib::Bytes>>::set(const CppType& data)
  {
    set_boxed(glib::unwrap(data));
  }

  Value<RefPtr<glib::Bytes>>::CppType
  Value<RefPtr<glib::Bytes>>::get() const
  {
    return glib::wrap(static_cast<CType>(get_boxed()), true);
  }

} // namespace glib

namespace
{
}

namespace glib
{

  auto
  wrap (GBytes* object, const bool take_copy) -> RefPtr<Bytes>
  {
    if (take_copy && object)
      g_bytes_ref (object);

    return glib::make_refptr_for_instance<Bytes> (
        reinterpret_cast<Bytes*> (object));
  }

} // namespace glib

namespace glib
{

  auto
  Bytes::reference () const -> void
  {
    g_bytes_ref (reinterpret_cast<GBytes*> (const_cast<Bytes*> (this)));
  }

  auto
  Bytes::unreference () const -> void
  {
    g_bytes_unref (reinterpret_cast<GBytes*> (const_cast<Bytes*> (this)));
  }

  auto
  Bytes::gobj () -> GBytes*
  {
    return reinterpret_cast<GBytes*> (this);
  }

  auto
  Bytes::gobj () const -> const GBytes*
  {
    return reinterpret_cast<const GBytes*> (this);
  }

  auto
  Bytes::gobj_copy () const -> GBytes*
  {
    const auto gobject = reinterpret_cast<GBytes*> (const_cast<Bytes*> (this));
    g_bytes_ref (gobject);
    return gobject;
  }

  auto
  Bytes::get_data (gsize& size) const -> gconstpointer
  {
    return g_bytes_get_data (const_cast<GBytes*> (gobj ()), &size);
  }

  auto
  Bytes::get_size () const -> gsize
  {
    return g_bytes_get_size (const_cast<GBytes*> (gobj ()));
  }

  auto
  Bytes::hash (const gconstpointer bytes) -> guint
  {
    return g_bytes_hash (bytes);
  }

  auto
  Bytes::equal (const gconstpointer bytes1, const gconstpointer bytes2) -> bool
  {
    return g_bytes_equal (bytes1, bytes2);
  }

  auto
  Bytes::compare (const gconstpointer bytes1, const gconstpointer bytes2) -> gint
  {
    return g_bytes_compare (bytes1, bytes2);
  }

} // namespace glib
