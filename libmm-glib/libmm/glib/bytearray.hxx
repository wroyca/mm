// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_BYTEARRAY_H
#define _GLIBMM_BYTEARRAY_H

#include <cstddef>
#include <glib.h>
#include <libmm/glib/refptr.hxx>
#include <libmm/glib/value.hxx>
#include <libmm/glib/wrap.hxx>
#include <sigc++/slot.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GByteArray GByteArray;
#endif

namespace glib
{

  class LIBMM_GLIB_SYMEXPORT ByteArray final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ByteArray;
    using BaseObjectType = GByteArray;
#endif

    static auto
    get_type () -> GType G_GNUC_CONST;

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> GByteArray*;

    auto
    gobj () const -> const GByteArray*;

    auto
    gobj_copy () const -> GByteArray*;

    ByteArray () = delete;

    ByteArray (const ByteArray&) = delete;
    auto
    operator= (const ByteArray&) -> ByteArray& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  public:
    using SlotCompare = sigc::slot<int (const guint8*, const guint8*)>;

    static auto
    create () -> glib::RefPtr<ByteArray>;

    auto
    append (const guint8* data, guint len) -> glib::RefPtr<ByteArray>;

    auto
    prepend (const guint8* data, guint len) -> glib::RefPtr<ByteArray>;

    auto
    size () const -> guint;

    auto
    get_data () -> guint8*;

    auto
    get_data () const -> const guint8*;

    auto
    remove_index (guint index) -> glib::RefPtr<ByteArray>;

    auto
    remove_index_fast (guint index) -> glib::RefPtr<ByteArray>;

    auto
    remove_range (guint index, guint length) -> glib::RefPtr<ByteArray>;

    auto
    sort (const SlotCompare& slot) -> void;

    auto
    set_size (guint length) -> glib::RefPtr<ByteArray>;
  };

} // namespace glib

namespace glib
{

  LIBMM_GLIB_SYMEXPORT
  auto
  wrap (GByteArray* object, bool take_copy = false) -> glib::RefPtr<glib::ByteArray>;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class LIBMM_GLIB_SYMEXPORT Value<glib::RefPtr<glib::ByteArray>>
    : public glib::Value_RefPtrBoxed<glib::ByteArray>
  {
  public:
    auto
    get () const -> CppType
    {
      return glib::wrap (static_cast<GByteArray*> (get_boxed ()), true);
    }
  };
#endif

} // namespace glib

#endif
