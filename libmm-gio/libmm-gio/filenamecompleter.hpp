
#ifndef _GIOMM_FILENAMECOMPLETER_H
#define _GIOMM_FILENAMECOMPLETER_H

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
using GFilenameCompleter = struct _GFilenameCompleter;
using GFilenameCompleterClass = struct _GFilenameCompleterClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API FilenameCompleter_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

class GIOMM_API File;

/** Completes partial file and directory names given a partial string by looking in the file system for clues.
 * Can return a list of possible completion strings for widget implementation.
 *
 * @newin{2,16}
 */

class GIOMM_API FilenameCompleter : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = FilenameCompleter;
  using CppClassType = FilenameCompleter_Class;
  using BaseObjectType = GFilenameCompleter;
  using BaseClassType = GFilenameCompleterClass;

  // noncopyable
  FilenameCompleter(const FilenameCompleter&) = delete;
  auto operator=(const FilenameCompleter&) -> FilenameCompleter& = delete;

private:  friend class FilenameCompleter_Class;
  static CppClassType filenamecompleter_class_;

protected:
  explicit FilenameCompleter(const Glib::ConstructParams& construct_params);
  explicit FilenameCompleter(GFilenameCompleter* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  FilenameCompleter(FilenameCompleter&& src) noexcept;
  auto operator=(FilenameCompleter&& src) noexcept -> FilenameCompleter&;

  ~FilenameCompleter() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GFilenameCompleter*       { return reinterpret_cast<GFilenameCompleter*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GFilenameCompleter* { return reinterpret_cast<GFilenameCompleter*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GFilenameCompleter*;

private:

protected:
  FilenameCompleter();

public:

  static auto create() -> Glib::RefPtr<FilenameCompleter>;


  /** Obtains a completion for @a initial_text from @a completer.
   *
   * @param initial_text Text to be completed.
   * @return A completed string, or <tt>nullptr</tt> if no
   * completion exists.
   */
  auto get_completion_suffix(const std::string& initial_text) const -> std::string;


  /** Gets an array of completion strings for a given initial text.
   *
   * @param initial_text Text to be completed.
   * @return Array of strings with possible completions for @a initial_text.
   */
  auto get_completions(const std::string& initial_text) const -> std::vector<Glib::ustring>;

  /** If @a dirs_only is <tt>true</tt>, @a completer will only
   * complete directory names, and not file names.
   *
   * @param dirs_only A <tt>bool</tt>.
   */
  void set_dirs_only(bool dirs_only =  true);


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%got_completion_data()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the file name completion information comes available.
   */

  auto signal_got_completion_data() -> Glib::SignalProxy<void()>;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_got_completion_data().
  virtual void on_got_completion_data();


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
   * @relates Gio::FilenameCompleter
   */
  GIOMM_API
  auto wrap(GFilenameCompleter* object, bool take_copy = false) -> Glib::RefPtr<Gio::FilenameCompleter>;
}


#endif /* _GIOMM_FILENAMECOMPLETER_H */

