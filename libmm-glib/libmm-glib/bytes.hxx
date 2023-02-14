// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_BYTES_H
#define _GLIBMM_BYTES_H

#include <glib.h>
#include <libmm-glib/error.hxx>
#include <libmm-glib/mm-glibconfig.hxx>
#include <libmm-glib/refptr.hxx>
#include <libmm-glib/ustring.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GBytes GBytes;
#endif

namespace Glib
{

  class GLIBMM_API Bytes final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Bytes;
    using BaseObjectType = GBytes;
#endif

    void
    reference () const;

    void
    unreference () const;

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
    void
    operator delete (void*, std::size_t);

  private:
  public:
    static auto
    create (gconstpointer data, gsize size) -> Glib::RefPtr<Glib::Bytes>;

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

} // namespace Glib

namespace Glib
{

  GLIBMM_API
  auto
  wrap (GBytes* object, bool take_copy = false) -> Glib::RefPtr<Glib::Bytes>;

} // namespace Glib

#endif
