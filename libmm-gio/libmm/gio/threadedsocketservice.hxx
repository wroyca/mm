// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_THREADEDSOCKETSERVICE_H
#define _GIOMM_THREADEDSOCKETSERVICE_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/socketservice.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GThreadedSocketService = struct _GThreadedSocketService;
using GThreadedSocketServiceClass = struct _GThreadedSocketServiceClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT ThreadedSocketService_Class;
}
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT ThreadedSocketService : public Gio::SocketService
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ThreadedSocketService;
    using CppClassType = ThreadedSocketService_Class;
    using BaseObjectType = GThreadedSocketService;
    using BaseClassType = GThreadedSocketServiceClass;

    ThreadedSocketService (const ThreadedSocketService&) = delete;
    auto
    operator= (const ThreadedSocketService&) -> ThreadedSocketService& = delete;

  private:
    friend class ThreadedSocketService_Class;
    static CppClassType threadedsocketservice_class_;

  protected:
    explicit ThreadedSocketService (
        const Glib::ConstructParams& construct_params);
    explicit ThreadedSocketService (GThreadedSocketService* castitem);

#endif

  public:
    ThreadedSocketService (ThreadedSocketService&& src) noexcept;
    auto
    operator= (ThreadedSocketService&& src) noexcept -> ThreadedSocketService&;

    ~ThreadedSocketService () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GThreadedSocketService*
    {
      return reinterpret_cast<GThreadedSocketService*> (gobject_);
    }

    auto
    gobj () const -> const GThreadedSocketService*
    {
      return reinterpret_cast<GThreadedSocketService*> (gobject_);
    }

    auto
    gobj_copy () -> GThreadedSocketService*;

  private:
  protected:
    explicit ThreadedSocketService (int max_threads);

  public:
    static auto
    create (int max_threads) -> Glib::RefPtr<ThreadedSocketService>;

    auto
    signal_run ()
        -> Glib::SignalProxy<bool (const Glib::RefPtr<SocketConnection>&,
                                   const Glib::RefPtr<Glib::Object>&)>;

    auto
    property_max_threads () const -> Glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
    virtual auto
    on_run (const Glib::RefPtr<SocketConnection>& connection,
            const Glib::RefPtr<Glib::Object>& source_object) -> bool;
  };

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GThreadedSocketService* object, bool take_copy = false) -> Glib::RefPtr<Gio::ThreadedSocketService>;
} // namespace Glib

#endif
