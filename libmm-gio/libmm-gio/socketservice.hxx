
#ifndef _GIOMM_SOCKETSERVICE_H
#define _GIOMM_SOCKETSERVICE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/socketlistener.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSocketService = struct _GSocketService;
using GSocketServiceClass = struct _GSocketServiceClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API SocketService_Class;
}
#endif

namespace Gio
{

  class GIOMM_API SocketService : public Gio::SocketListener
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = SocketService;
    using CppClassType = SocketService_Class;
    using BaseObjectType = GSocketService;
    using BaseClassType = GSocketServiceClass;

    SocketService (const SocketService&) = delete;
    auto
    operator= (const SocketService&) -> SocketService& = delete;

  private:
    friend class SocketService_Class;
    static CppClassType socketservice_class_;

  protected:
    explicit SocketService (const Glib::ConstructParams& construct_params);
    explicit SocketService (GSocketService* castitem);

#endif

  public:
    SocketService (SocketService&& src) noexcept;
    auto
    operator= (SocketService&& src) noexcept -> SocketService&;

    ~SocketService () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GSocketService*
    {
      return reinterpret_cast<GSocketService*> (gobject_);
    }

    auto
    gobj () const -> const GSocketService*
    {
      return reinterpret_cast<GSocketService*> (gobject_);
    }

    auto
    gobj_copy () -> GSocketService*;

  private:
  protected:
    SocketService ();

  public:
    static auto
    create () -> Glib::RefPtr<SocketService>;

    void
    start ();

    void
    stop ();

    auto
    is_active () -> bool;

    auto
    signal_incoming ()
        -> Glib::SignalProxy<bool (const Glib::RefPtr<SocketConnection>&,
                                   const Glib::RefPtr<Glib::Object>&)>;

    auto
    property_active () -> Glib::PropertyProxy<bool>;

    auto
    property_active () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
    virtual auto
    on_incoming (const Glib::RefPtr<SocketConnection>& connection,
                 const Glib::RefPtr<Glib::Object>& source_object) -> bool;
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GSocketService* object, bool take_copy = false) -> Glib::RefPtr<Gio::SocketService>;
} // namespace Glib

#endif
