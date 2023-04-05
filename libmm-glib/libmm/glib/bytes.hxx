// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_BYTES_H
#define _GLIBMM_BYTES_H

#include <glib.h>
#include <libmm/glib/error.hxx>
#include <libmm/glib/mm-glibconfig.hxx>
#include <libmm/glib/refptr.hxx>
#include <libmm/glib/ustring.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GBytes GBytes;
#endif

namespace glib
{

  class LIBMM_GLIB_SYMEXPORT Bytes final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Bytes;
    using BaseObjectType = GBytes;
#endif

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> GBytes*;

    auto
    gobj () const -> const GBytes*;

    auto
    gobj_copy () const -> GBytes*;

    Bytes () = delete;

    Bytes (const Bytes&) = delete;
    auto
    operator= (const Bytes&) -> Bytes& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  public:
    static auto
    create (gconstpointer data, gsize size) -> glib::RefPtr<glib::Bytes>;

    auto
    get_data (gsize& size) const -> gconstpointer;

    auto
    get_size () const -> gsize;

    static auto
    hash (gconstpointer bytes) -> guint;

    static auto
    equal (gconstpointer bytes1, gconstpointer bytes2) -> bool;

    static auto
    compare (gconstpointer bytes1, gconstpointer bytes2) -> gint;
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Value<glib::RefPtr<glib::Bytes>> : public ValueBase_Boxed
  {
  public:
    using CppType = glib::RefPtr<glib::Bytes>;
    using CType = GBytes*;

    static GType
    value_type ();

    void
    set (const CppType& data);
    CppType
    get () const;
  };

} // namespace glib

namespace glib
{

  LIBMM_GLIB_SYMEXPORT
  auto
  wrap (GBytes* object, bool take_copy = false) -> glib::RefPtr<glib::Bytes>;

} // namespace glib

#endif
