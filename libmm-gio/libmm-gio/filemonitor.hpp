
#ifndef _GIOMM_FILEMONITOR_H
#define _GIOMM_FILEMONITOR_H

#include <mm/gio/gioconfig.hpp>


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2007 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */


//#include <mm/gio/file.hpp>
#include <mm/glib/object.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GFileMonitor = struct _GFileMonitor;
using GFileMonitorClass = struct _GFileMonitorClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API FileMonitor_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{


class GIOMM_API File;

/** Monitors a file or directory for changes.
 * To obtain a FileMonitor for a file or directory, use File::monitor_file() or
 * File::monitor_directory().
 *
 * To get informed about changes to the file or directory you are monitoring,
 * connect to signal_changed().
 *
 * @newin{2,16}
 */

class GIOMM_API FileMonitor : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = FileMonitor;
  using CppClassType = FileMonitor_Class;
  using BaseObjectType = GFileMonitor;
  using BaseClassType = GFileMonitorClass;

  // noncopyable
  FileMonitor(const FileMonitor&) = delete;
  auto operator=(const FileMonitor&) -> FileMonitor& = delete;

private:  friend class FileMonitor_Class;
  static CppClassType filemonitor_class_;

protected:
  explicit FileMonitor(const Glib::ConstructParams& construct_params);
  explicit FileMonitor(GFileMonitor* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  FileMonitor(FileMonitor&& src) noexcept;
  auto operator=(FileMonitor&& src) noexcept -> FileMonitor&;

  ~FileMonitor() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GFileMonitor*       { return reinterpret_cast<GFileMonitor*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GFileMonitor* { return reinterpret_cast<GFileMonitor*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GFileMonitor*;

private:

protected:

public:

  /** @addtogroup giommEnums giomm Enums and Flags */

  /**
   *  @var Event CHANGED
   * A file changed.
   *
   *  @var Event CHANGES_DONE_HINT
   * A hint that this was probably the last change in a set of changes.
   *
   *  @var Event DELETED
   * A file was deleted.
   *
   *  @var Event CREATED
   * A file was created.
   *
   *  @var Event ATTRIBUTE_CHANGED
   * A file attribute was changed.
   *
   *  @var Event PRE_UNMOUNT
   * The file location will soon be unmounted.
   *
   *  @var Event UNMOUNTED
   * The file location was unmounted.
   *
   *  @var Event MOVED
   * The file was moved -- only sent if the
   * (deprecated) Gio::FileMonitorFlags::SEND_MOVED flag is set.
   *
   *  @var Event RENAMED
   * The file was renamed within the
   * current directory -- only sent if the Gio::FileMonitorFlags::WATCH_MOVES
   * flag is set.  @newin{2,46}
   *
   *  @var Event MOVED_IN
   * The file was moved into the
   * monitored directory from another location -- only sent if the
   * Gio::FileMonitorFlags::WATCH_MOVES flag is set.  @newin{2,46}
   *
   *  @var Event MOVED_OUT
   * The file was moved out of the
   * monitored directory to another location -- only sent if the
   * Gio::FileMonitorFlags::WATCH_MOVES flag is set.  @newin{2,46}
   *
   *  @enum Event
   *
   * Specifies what type of event a monitor event is.
   *
   * @ingroup giommEnums
   */
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


  /** Cancels a file monitor.
   *
   * @return Always <tt>true</tt>.
   */
  auto cancel() -> bool;

  /** Returns whether the monitor is canceled.
   *
   * @return <tt>true</tt> if monitor is canceled. <tt>false</tt> otherwise.
   */
  auto is_cancelled() const -> bool;

  /** Sets the rate limit to which the @a monitor will report
   * consecutive change events to the same file.
   *
   * @param limit_msecs A non-negative integer with the limit in milliseconds
   * to poll for changes.
   */
  void set_rate_limit(int limit_msecs);

  //g_file_monitor_emit_event is for implementations.


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%changed(const Glib::RefPtr<File>& file, const Glib::RefPtr<File>& other_file, Event event_type)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when @a file has been changed.
   *
   * If using Gio::FileMonitorFlags::WATCH_MOVES on a directory monitor, and
   * the information is available (and if supported by the backend),
   *  @a event_type may be Gio::FileMonitor::Event::RENAMED,
   * Gio::FileMonitor::Event::MOVED_IN or Gio::FileMonitor::Event::MOVED_OUT.
   *
   * In all cases @a file will be a child of the monitored directory.  For
   * renames, @a file will be the old name and @a other_file is the new
   * name.  For "moved in" events, @a file is the name of the file that
   * appeared and @a other_file is the old name that it was moved from (in
   * another directory).  For "moved out" events, @a file is the name of
   * the file that used to be in this directory and @a other_file is the
   * name of the file at its new location.
   *
   * It makes sense to treat Gio::FileMonitor::Event::MOVED_IN as
   * equivalent to Gio::FileMonitor::Event::CREATED and
   * Gio::FileMonitor::Event::MOVED_OUT as equivalent to
   * Gio::FileMonitor::Event::DELETED, with extra information.
   * Gio::FileMonitor::Event::RENAMED is equivalent to a delete/create
   * pair.  This is exactly how the events will be reported in the case
   * that the Gio::FileMonitorFlags::WATCH_MOVES flag is not in use.
   *
   * If using the deprecated flag Gio::FileMonitorFlags::SEND_MOVED flag and @a event_type is
   * Gio::FileMonitor::Event::MOVED, @a file will be set to a File containing the
   * old path, and @a other_file will be set to a File containing the new path.
   *
   * In all the other cases, @a other_file will be set to #<tt>nullptr</tt>.
   *
   * @param file A File.
   * @param other_file A File or #<tt>nullptr</tt>.
   * @param event_type A Gio::FileMonitor::Event.
   */

  auto signal_changed() -> Glib::SignalProxy<void(const Glib::RefPtr<File>&, const Glib::RefPtr<File>&, Event)>;


  /** The limit of the monitor to watch for changes, in milliseconds.
   *
   * Default value: 800
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_rate_limit() -> Glib::PropertyProxy< int > ;

/** The limit of the monitor to watch for changes, in milliseconds.
   *
   * Default value: 800
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_rate_limit() const -> Glib::PropertyProxy_ReadOnly< int >;

  /** Whether the monitor has been cancelled.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_cancelled() const -> Glib::PropertyProxy_ReadOnly< bool >;


protected:
  //_WRAP_VFUNC(bool cancel(), cancel);


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_changed().
  virtual void on_changed(const Glib::RefPtr<File>& file, const Glib::RefPtr<File>& other_file, Event event_type);


};

} // namespace Gio


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::FileMonitor
   */
  GIOMM_API
  auto wrap(GFileMonitor* object, bool take_copy = false) -> Glib::RefPtr<Gio::FileMonitor>;
}


#endif /* _GIOMM_FILEMONITOR_H */

