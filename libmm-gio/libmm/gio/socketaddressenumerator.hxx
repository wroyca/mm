// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SOCKETADDRESSENUMERATOR_H
#define _GIOMM_SOCKETADDRESSENUMERATOR_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/cancellable.hxx>
#include <libmm/glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSocketAddressEnumerator = struct _GSocketAddressEnumerator;
using GSocketAddressEnumeratorClass = struct _GSocketAddressEnumeratorClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT SocketAddressEnumerator_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT SocketAddress;

  class LIBMM_GIO_SYMEXPORT SocketAddressEnumerator : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = SocketAddressEnumerator;
    using CppClassType = SocketAddressEnumerator_Class;
    using BaseObjectType = GSocketAddressEnumerator;
    using BaseClassType = GSocketAddressEnumeratorClass;

    SocketAddressEnumerator (const SocketAddressEnumerator&) = delete;
    auto
    operator= (const SocketAddressEnumerator&)
        -> SocketAddressEnumerator& = delete;

  private:
    friend class SocketAddressEnumerator_Class;
    static CppClassType socketaddressenumerator_class_;

  protected:
    explicit SocketAddressEnumerator (
        const glib::ConstructParams& construct_params);
    explicit SocketAddressEnumerator (GSocketAddressEnumerator* castitem);

#endif

  public:
    SocketAddressEnumerator (SocketAddressEnumerator&& src) noexcept;
    auto
    operator= (SocketAddressEnumerator&& src) noexcept
        -> SocketAddressEnumerator&;

    ~SocketAddressEnumerator () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GSocketAddressEnumerator*
    {
      return reinterpret_cast<GSocketAddressEnumerator*> (gobject_);
    }

    auto
    gobj () const -> const GSocketAddressEnumerator*
    {
      return reinterpret_cast<GSocketAddressEnumerator*> (gobject_);
    }

    auto
    gobj_copy () -> GSocketAddressEnumerator*;

  private:
  public:
    auto
    next (const glib::RefPtr<Cancellable>& cancellable)
        -> glib::RefPtr<SocketAddress>;

    auto
    next () -> glib::RefPtr<SocketAddress>;

    auto
    next_async (const glib::RefPtr<Cancellable>& cancellable,
                const SlotAsyncReady& slot) -> void;

    auto
    next_async (const SlotAsyncReady& slot) -> void;

    auto
    next_finish (const glib::RefPtr<AsyncResult>& result)
        -> glib::RefPtr<SocketAddress>;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GSocketAddressEnumerator* object, bool take_copy = false) -> glib::RefPtr<gio::SocketAddressEnumerator>;
} // namespace glib

#endif
