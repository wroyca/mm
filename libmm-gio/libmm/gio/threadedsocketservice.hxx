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
namespace gio
{
  class LIBMM_GIO_SYMEXPORT ThreadedSocketService_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT ThreadedSocketService : public gio::SocketService
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
        const glib::ConstructParams& construct_params);
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
    create (int max_threads) -> glib::RefPtr<ThreadedSocketService>;

    auto
    signal_run ()
        -> glib::SignalProxy<bool (const glib::RefPtr<SocketConnection>&,
                                   const glib::RefPtr<glib::Object>&)>;

    auto
    property_max_threads () const -> glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
    virtual auto
    on_run (const glib::RefPtr<SocketConnection>& connection,
            const glib::RefPtr<glib::Object>& source_object) -> bool;
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GThreadedSocketService* object, bool take_copy = false) -> glib::RefPtr<gio::ThreadedSocketService>;
} // namespace glib

#endif
