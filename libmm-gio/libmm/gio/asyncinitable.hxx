// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_ASYNCINITABLE_H
#define _GIOMM_ASYNCINITABLE_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/asyncresult.hxx>
#include <libmm/glib/interface.hxx>
#include <libmm/glib/priorities.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GAsyncInitableIface GAsyncInitableIface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GAsyncInitable = struct _GAsyncInitable;
using GAsyncInitableClass = struct _GAsyncInitableClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT AsyncInitable_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT Cancellable;

  class LIBMM_GIO_SYMEXPORT AsyncInitable : public glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = AsyncInitable;
    using CppClassType = AsyncInitable_Class;
    using BaseObjectType = GAsyncInitable;
    using BaseClassType = GAsyncInitableIface;

    AsyncInitable (const AsyncInitable&) = delete;
    auto
    operator= (const AsyncInitable&) -> AsyncInitable& = delete;

  private:
    friend class AsyncInitable_Class;
    static CppClassType asyncinitable_class_;

#endif
  protected:
    AsyncInitable ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit AsyncInitable (const glib::Interface_Class& interface_class);

  public:
    explicit AsyncInitable (GAsyncInitable* castitem);

  protected:
#endif

  public:
    AsyncInitable (AsyncInitable&& src) noexcept;
    auto
    operator= (AsyncInitable&& src) noexcept -> AsyncInitable&;

    ~AsyncInitable () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GAsyncInitable*
    {
      return reinterpret_cast<GAsyncInitable*> (gobject_);
    }

    auto
    gobj () const -> const GAsyncInitable*
    {
      return reinterpret_cast<GAsyncInitable*> (gobject_);
    }

  private:
  protected:
    auto
    init_async (const SlotAsyncReady& slot,
                const glib::RefPtr<Cancellable>& cancellable,
                int io_priority = glib::PRIORITY_DEFAULT) -> void;

    auto
    init_async (const SlotAsyncReady& slot,
                int io_priority = glib::PRIORITY_DEFAULT) -> void;

    auto
    init_finish (const glib::RefPtr<AsyncResult>& res) -> bool;

    auto
    create_finish (const glib::RefPtr<AsyncResult>& res)
        -> glib::RefPtr<glib::Object>;

    virtual auto
    init_async_vfunc (const SlotAsyncReady& slot,
                      const glib::RefPtr<Cancellable>& cancellable,
                      int io_priority = glib::PRIORITY_DEFAULT) -> void;

    virtual auto
    init_finish_vfunc (const glib::RefPtr<AsyncResult>& res) -> bool;

  protected:
  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GAsyncInitable* object, bool take_copy = false) -> glib::RefPtr<gio::AsyncInitable>;

} // namespace glib

#endif
