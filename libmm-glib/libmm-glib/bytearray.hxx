// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_BYTEARRAY_H
#define _GLIBMM_BYTEARRAY_H

#include <cstddef>
#include <glib.h>
#include <libmm-glib/refptr.hxx>
#include <libmm-glib/value.hxx>
#include <libmm-glib/wrap.hxx>
#include <sigc++/slot.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GByteArray GByteArray;
#endif

namespace Glib
{

  class GLIBMM_API ByteArray final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ByteArray;
    using BaseObjectType = GByteArray;
#endif

    static auto
    get_type () -> GType G_GNUC_CONST;

    void
    reference () const;

    void
    unreference () const;

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
    void
    operator delete (void*, std::size_t);

  private:
  public:
    using SlotCompare = sigc::slot<int (const guint8*, const guint8*)>;

    static auto
    create () -> Glib::RefPtr<ByteArray>;

    auto
    append (const guint8* data, guint len) -> Glib::RefPtr<ByteArray>;

    auto
    prepend (const guint8* data, guint len) -> Glib::RefPtr<ByteArray>;

    auto
    size () const -> guint;

    auto
    get_data () -> guint8*;

    auto
    get_data () const -> const guint8*;

    auto
    remove_index (guint index) -> Glib::RefPtr<ByteArray>;

    auto
    remove_index_fast (guint index) -> Glib::RefPtr<ByteArray>;

    auto
    remove_range (guint index, guint length) -> Glib::RefPtr<ByteArray>;

    void
    sort (const SlotCompare& slot);

    auto
    set_size (guint length) -> Glib::RefPtr<ByteArray>;
  };

} // namespace Glib

namespace Glib
{

  GLIBMM_API
  auto
  wrap (GByteArray* object, bool take_copy = false) -> Glib::RefPtr<Glib::ByteArray>;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class GLIBMM_API Value<Glib::RefPtr<Glib::ByteArray>>
    : public Glib::Value_RefPtrBoxed<Glib::ByteArray>
  {
  public:
    auto
    get () const -> CppType
    {
      return Glib::wrap (static_cast<GByteArray*> (get_boxed ()), true);
    }
  };
#endif

} // namespace Glib

#endif
