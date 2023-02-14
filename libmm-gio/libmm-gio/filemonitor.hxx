
#ifndef _GIOMM_FILEMONITOR_H
#define _GIOMM_FILEMONITOR_H

#include <libmm-gio/gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GFileMonitor = struct _GFileMonitor;
using GFileMonitorClass = struct _GFileMonitorClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API FileMonitor_Class;
}
#endif

namespace Gio
{

  class GIOMM_API File;

  class GIOMM_API FileMonitor : public Glib::Object
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
    explicit FileMonitor (const Glib::ConstructParams& construct_params);
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

    void
    set_rate_limit (int limit_msecs);

    auto
    signal_changed () -> Glib::SignalProxy<
        void (const Glib::RefPtr<File>&, const Glib::RefPtr<File>&, Event)>;

    auto
    property_rate_limit () -> Glib::PropertyProxy<int>;

    auto
    property_rate_limit () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_cancelled () const -> Glib::PropertyProxy_ReadOnly<bool>;

  protected:
  public:
  public:
  protected:
    virtual void
    on_changed (const Glib::RefPtr<File>& file,
                const Glib::RefPtr<File>& other_file,
                Event event_type);
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GFileMonitor* object, bool take_copy = false) -> Glib::RefPtr<Gio::FileMonitor>;
} // namespace Glib

#endif
