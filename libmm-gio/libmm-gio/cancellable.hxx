
#ifndef _GIOMM_CANCELLABLE_H
#define _GIOMM_CANCELLABLE_H

#include <libmm-gio/gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GCancellable = struct _GCancellable;
using GCancellableClass = struct _GCancellableClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API Cancellable_Class;
}
#endif

namespace Gio
{

  class GIOMM_API Cancellable : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Cancellable;
    using CppClassType = Cancellable_Class;
    using BaseObjectType = GCancellable;
    using BaseClassType = GCancellableClass;

    Cancellable (const Cancellable&) = delete;
    auto
    operator= (const Cancellable&) -> Cancellable& = delete;

  private:
    friend class Cancellable_Class;
    static CppClassType cancellable_class_;

  protected:
    explicit Cancellable (const Glib::ConstructParams& construct_params);
    explicit Cancellable (GCancellable* castitem);

#endif

  public:
    Cancellable (Cancellable&& src) noexcept;
    auto
    operator= (Cancellable&& src) noexcept -> Cancellable&;

    ~Cancellable () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GCancellable*
    {
      return reinterpret_cast<GCancellable*> (gobject_);
    }

    auto
    gobj () const -> const GCancellable*
    {
      return reinterpret_cast<GCancellable*> (gobject_);
    }

    auto
    gobj_copy () -> GCancellable*;

  private:
  protected:
    Cancellable ();

  public:
    using SlotCancelledCallback = sigc::slot<void ()>;

    static auto
    create () -> Glib::RefPtr<Cancellable>;

    auto
    is_cancelled () const -> bool;

    auto
    get_fd () const -> int;

    auto
    make_pollfd (GPollFD* pollfd) -> bool;

    void
    release_fd ();

    void
    cancel ();

    static auto
    get_current () -> Glib::RefPtr<Cancellable>;

    void
    push_current ();

    void
    pop_current ();

    void
    reset ();

    auto
    connect (const SlotCancelledCallback& slot) -> gulong;

    void
    disconnect (gulong handler_id);

    auto
    signal_cancelled () -> Glib::SignalProxy<void ()>;

  public:
  public:
  protected:
    virtual void
    on_cancelled ();
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GCancellable* object, bool take_copy = false) -> Glib::RefPtr<Gio::Cancellable>;
} // namespace Glib

#endif
