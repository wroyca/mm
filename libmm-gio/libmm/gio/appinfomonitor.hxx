// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_APPINFOMONITOR_H
#define _GIOMM_APPINFOMONITOR_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GAppInfoMonitor = struct _GAppInfoMonitor;
using GAppInfoMonitorClass = struct _GAppInfoMonitorClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT AppInfoMonitor_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT AppInfoMonitor : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = AppInfoMonitor;
    using CppClassType = AppInfoMonitor_Class;
    using BaseObjectType = GAppInfoMonitor;
    using BaseClassType = GAppInfoMonitorClass;

    AppInfoMonitor (const AppInfoMonitor&) = delete;
    auto
    operator= (const AppInfoMonitor&) -> AppInfoMonitor& = delete;

  private:
    friend class AppInfoMonitor_Class;
    static CppClassType appinfomonitor_class_;

  protected:
    explicit AppInfoMonitor (const glib::ConstructParams& construct_params);
    explicit AppInfoMonitor (GAppInfoMonitor* castitem);

#endif

  public:
    AppInfoMonitor (AppInfoMonitor&& src) noexcept;
    auto
    operator= (AppInfoMonitor&& src) noexcept -> AppInfoMonitor&;

    ~AppInfoMonitor () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GAppInfoMonitor*
    {
      return reinterpret_cast<GAppInfoMonitor*> (gobject_);
    }

    auto
    gobj () const -> const GAppInfoMonitor*
    {
      return reinterpret_cast<GAppInfoMonitor*> (gobject_);
    }

    auto
    gobj_copy () -> GAppInfoMonitor*;

  private:
  public:
    static auto
    get () -> glib::RefPtr<AppInfoMonitor>;

    auto
    signal_changed () -> glib::SignalProxy<void ()>;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GAppInfoMonitor* object, bool take_copy = false) -> glib::RefPtr<gio::AppInfoMonitor>;
} // namespace glib

#endif
