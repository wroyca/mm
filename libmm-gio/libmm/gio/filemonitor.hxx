// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_FILEMONITOR_H
#define _GIOMM_FILEMONITOR_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GFileMonitor = struct _GFileMonitor;
using GFileMonitorClass = struct _GFileMonitorClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT FileMonitor_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT File;

  class LIBMM_GIO_SYMEXPORT FileMonitor : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = FileMonitor;
    using CppClassType = FileMonitor_Class;
    using BaseObjectType = GFileMonitor;
    using BaseClassType = GFileMonitorClass;

    FileMonitor (const FileMonitor&) = delete;
    auto
    operator= (const FileMonitor&) -> FileMonitor& = delete;

  private:
    friend class FileMonitor_Class;
    static CppClassType filemonitor_class_;

  protected:
    explicit FileMonitor (const glib::ConstructParams& construct_params);
    explicit FileMonitor (GFileMonitor* castitem);

#endif

  public:
    FileMonitor (FileMonitor&& src) noexcept;
    auto
    operator= (FileMonitor&& src) noexcept -> FileMonitor&;

    ~FileMonitor () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GFileMonitor*
    {
      return reinterpret_cast<GFileMonitor*> (gobject_);
    }

    auto
    gobj () const -> const GFileMonitor*
    {
      return reinterpret_cast<GFileMonitor*> (gobject_);
    }

    auto
    gobj_copy () -> GFileMonitor*;

  private:
  protected:
  public:
    enum class Event
    {
      CHANGED,
      CHANGES_DONE_HINT,
      DELETED,
      CREATED,
      ATTRIBUTE_CHANGED,
      PRE_UNMOUNT,
      UNMOUNTED,
      MOVED,
      RENAMED,
      MOVED_IN,
      MOVED_OUT
    };

    auto
    cancel () -> bool;

    auto
    is_cancelled () const -> bool;

    auto
    set_rate_limit (int limit_msecs) -> void;

    auto
    signal_changed () -> glib::SignalProxy<
        void (const glib::RefPtr<File>&, const glib::RefPtr<File>&, Event)>;

    auto
    property_rate_limit () -> glib::PropertyProxy<int>;

    auto
    property_rate_limit () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_cancelled () const -> glib::PropertyProxy_ReadOnly<bool>;

  protected:
  public:
  public:
  protected:
    virtual auto
    on_changed (const glib::RefPtr<File>& file,
                const glib::RefPtr<File>& other_file,
                Event event_type) -> void;
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GFileMonitor* object, bool take_copy = false) -> glib::RefPtr<gio::FileMonitor>;
} // namespace glib

#endif
