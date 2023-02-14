
#ifndef _GIOMM_ASYNCINITABLE_H
#define _GIOMM_ASYNCINITABLE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/asyncresult.hxx>
#include <libmm-glib/interface.hxx>
#include <libmm-glib/priorities.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GAsyncInitableIface GAsyncInitableIface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GAsyncInitable = struct _GAsyncInitable;
using GAsyncInitableClass = struct _GAsyncInitableClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API AsyncInitable_Class;
}
#endif

namespace Gio
{

  class GIOMM_API Cancellable;

  class GIOMM_API AsyncInitable : public Glib::Interface
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

    explicit AsyncInitable (const Glib::Interface_Class& interface_class);

  public:
    explicit AsyncInitable (GAsyncInitable* castitem);

  protected:
#endif

  public:
    AsyncInitable (AsyncInitable&& src) noexcept;
    auto
    operator= (AsyncInitable&& src) noexcept -> AsyncInitable&;

    ~AsyncInitable () noexcept override;

    static void
    add_interface (GType gtype_implementer);

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
    void
    init_async (const SlotAsyncReady& slot,
                const Glib::RefPtr<Cancellable>& cancellable,
                int io_priority = Glib::PRIORITY_DEFAULT);

    void
    init_async (const SlotAsyncReady& slot,
                int io_priority = Glib::PRIORITY_DEFAULT);

    auto
    init_finish (const Glib::RefPtr<AsyncResult>& res) -> bool;

    auto
    create_finish (const Glib::RefPtr<AsyncResult>& res)
        -> Glib::RefPtr<Glib::Object>;

    virtual void
    init_async_vfunc (const SlotAsyncReady& slot,
                      const Glib::RefPtr<Cancellable>& cancellable,
                      int io_priority = Glib::PRIORITY_DEFAULT);

    virtual auto
    init_finish_vfunc (const Glib::RefPtr<AsyncResult>& res) -> bool;

  protected:
  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GAsyncInitable* object, bool take_copy = false) -> Glib::RefPtr<Gio::AsyncInitable>;

} // namespace Glib

#endif
