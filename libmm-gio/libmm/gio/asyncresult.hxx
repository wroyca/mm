// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_ASYNCRESULT_H
#define _GIOMM_ASYNCRESULT_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/interface.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GAsyncResultIface GAsyncResultIface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GAsyncResult = struct _GAsyncResult;
using GAsyncResultClass = struct _GAsyncResultClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT AsyncResult_Class;
}
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT AsyncResult;

  using SlotAsyncReady = sigc::slot<void (Glib::RefPtr<AsyncResult>&)>;

  class LIBMM_GIO_SYMEXPORT AsyncResult : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = AsyncResult;
    using CppClassType = AsyncResult_Class;
    using BaseObjectType = GAsyncResult;
    using BaseClassType = GAsyncResultIface;

    AsyncResult (const AsyncResult&) = delete;
    auto
    operator= (const AsyncResult&) -> AsyncResult& = delete;

  private:
    friend class AsyncResult_Class;
    static CppClassType asyncresult_class_;

#endif
  protected:
    AsyncResult ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit AsyncResult (const Glib::Interface_Class& interface_class);

  public:
    explicit AsyncResult (GAsyncResult* castitem);

  protected:
#endif

  public:
    AsyncResult (AsyncResult&& src) noexcept;
    auto
    operator= (AsyncResult&& src) noexcept -> AsyncResult&;

    ~AsyncResult () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GAsyncResult*
    {
      return reinterpret_cast<GAsyncResult*> (gobject_);
    }

    auto
    gobj () const -> const GAsyncResult*
    {
      return reinterpret_cast<GAsyncResult*> (gobject_);
    }

  private:
  public:
    auto
    get_source_object_base () -> Glib::RefPtr<Glib::ObjectBase>;
    auto
    get_source_object_base () const -> Glib::RefPtr<const Glib::ObjectBase>;

    auto
    is_tagged (gpointer source_tag) const -> bool;

  protected:
    virtual auto
    get_source_object_vfunc () -> Glib::RefPtr<Glib::ObjectBase>;

    virtual auto
    is_tagged_vfunc (gpointer source_tag) -> bool;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GAsyncResult* object, bool take_copy = false) -> Glib::RefPtr<Gio::AsyncResult>;

} // namespace Glib

#endif
