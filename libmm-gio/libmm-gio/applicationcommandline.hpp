
#ifndef _GIOMM_APPLICATIONCOMMANDLINE_H
#define _GIOMM_APPLICATIONCOMMANDLINE_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2010 Jonathon Jongsma <jonathon@quotidian.org>
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

#include <libmm-gio/file.hpp>
#include <libmm-gio/inputstream.hpp>
#include <libmm-glib/object.hpp>
#include <libmm-glib/variant.hpp>
#include <libmm-glib/variantdict.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GApplicationCommandLine = struct _GApplicationCommandLine;
using GApplicationCommandLineClass = struct _GApplicationCommandLineClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API ApplicationCommandLine_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** ApplicationCommandLine - A command-line invocation of an application.
 * ApplicationCommandLine represents a command-line invocation of an
 * application. It is created by Application and emitted in the "command-line"
 * signal and virtual function.
 *
 * The class contains the list of arguments that the program was invoked with.
 * It is also possible to query if the commandline invocation was local (ie:
 * the current process is running in direct response to the invocation) or
 * remote (ie: some other process forwarded the commandline to this process).
 *
 * The ApplicationCommandLine object can provide the argc and argv parameters
 * for use with the Glib::OptionContext command-line parsing API, with the
 * get_arguments() method.
 *
 * The exit status of the originally-invoked process may be set and messages
 * can be printed to stdout or stderr of that process. The lifecycle of the
 * originally-invoked process is tied to the lifecycle of this object (ie: the
 * process exits when the last reference is dropped).
 *
 * The main use for ApplicationCommandline (and the "command-line" signal) is
 * 'Emacs server' like use cases: You can set the EDITOR environment variable
 * to have e.g. git use your favourite editor to edit commit messages, and if
 * you already have an instance of the editor running, the editing will happen
 * in the running instance, instead of opening a new one. An important aspect
 * of this use case is that the process that gets started by git does not
 * return until the editing is done.
 * @newin{2,32}
 */

class GIOMM_API ApplicationCommandLine : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = ApplicationCommandLine;
  using CppClassType = ApplicationCommandLine_Class;
  using BaseObjectType = GApplicationCommandLine;
  using BaseClassType = GApplicationCommandLineClass;

  // noncopyable
  ApplicationCommandLine(const ApplicationCommandLine&) = delete;
  auto operator=(const ApplicationCommandLine&) -> ApplicationCommandLine& = delete;

private:  friend class ApplicationCommandLine_Class;
  static CppClassType applicationcommandline_class_;

protected:
  explicit ApplicationCommandLine(const Glib::ConstructParams& construct_params);
  explicit ApplicationCommandLine(GApplicationCommandLine* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  ApplicationCommandLine(ApplicationCommandLine&& src) noexcept;
  auto operator=(ApplicationCommandLine&& src) noexcept -> ApplicationCommandLine&;

  ~ApplicationCommandLine() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GApplicationCommandLine*       { return reinterpret_cast<GApplicationCommandLine*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GApplicationCommandLine* { return reinterpret_cast<GApplicationCommandLine*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GApplicationCommandLine*;

private:


protected:
  ApplicationCommandLine();

public:


  /** Gets the list of arguments that was passed on the command line.
   *
   * The strings in the array may contain non-UTF-8 data on UNIX (such as
   * filenames or arguments given in the system locale) but are always in
   * UTF-8 on Windows.
   *
   * If you wish to use the return value with Glib::OptionContext, you must
   * use Glib::OptionContext::parse(char**& argv).
   *
   * The return value is nullptr-terminated and should be freed using
   * g_strfreev().
   *
   * @newin{2,28}
   *
   * @param[out] argc The length of the arguments array.
   * @return The string array containing the arguments (the argv).
   */
  auto get_arguments(int& argc) const -> char**;

  //TODO: Wrap the GVariantDict*. See also Application's handle-local-options signal.

  /** Gets the options there were passed to Glib::application_command_line().
   *
   * If you did not override local_command_line() then these are the same
   * options that were parsed according to the OptionEntrys added to the
   * application with g_application_add_main_option_entries() and possibly
   * modified from your GApplication::handle-local-options handler.
   *
   * If no options were sent then an empty dictionary is returned so that
   * you don't need to check for <tt>nullptr</tt>.
   *
   * @newin{2,40}
   *
   * @return A VariantDict with the options.
   */
  auto get_options_dict() -> Glib::RefPtr<Glib::VariantDict>;

  /** Gets the options there were passed to Glib::application_command_line().
   *
   * If you did not override local_command_line() then these are the same
   * options that were parsed according to the OptionEntrys added to the
   * application with g_application_add_main_option_entries() and possibly
   * modified from your GApplication::handle-local-options handler.
   *
   * If no options were sent then an empty dictionary is returned so that
   * you don't need to check for <tt>nullptr</tt>.
   *
   * @newin{2,40}
   *
   * @return A VariantDict with the options.
   */
  auto get_options_dict() const -> Glib::RefPtr<const Glib::VariantDict>;


  /** Gets the stdin of the invoking process.
   *
   * The InputStream can be used to read data passed to the standard
   * input of the invoking process.
   * This doesn't work on all platforms.  Presently, it is only available
   * on UNIX when using a D-Bus daemon capable of passing file descriptors.
   * If stdin is not available then <tt>nullptr</tt> will be returned.  In the
   * future, support may be expanded to other platforms.
   *
   * You must only call this function once per commandline invocation.
   *
   * @newin{2,34}
   *
   * @return A InputStream for stdin.
   */
  auto get_stdin() -> Glib::RefPtr<InputStream>;

  /** Gets the stdin of the invoking process.
   *
   * The InputStream can be used to read data passed to the standard
   * input of the invoking process.
   * This doesn't work on all platforms.  Presently, it is only available
   * on UNIX when using a D-Bus daemon capable of passing file descriptors.
   * If stdin is not available then <tt>nullptr</tt> will be returned.  In the
   * future, support may be expanded to other platforms.
   *
   * You must only call this function once per commandline invocation.
   *
   * @newin{2,34}
   *
   * @return A InputStream for stdin.
   */
  auto get_stdin() const -> Glib::RefPtr<const InputStream>;


  //We use std::string instead of ustring because the C documentation says that it may be non-UTF-8 data:

  /** Gets the working directory of the command line invocation.
   * The string may contain non-utf8 data.
   *
   * It is possible that the remote application did not send a working
   * directory, so this may be <tt>nullptr</tt>.
   *
   * The return value should not be modified or freed and is valid for as
   * long as @a cmdline exists.
   *
   * @newin{2,28}
   *
   * @return The current directory, or <tt>nullptr</tt>.
   */
  auto get_cwd() const -> std::string;

  //We use std::string instead of ustring because the C documentation says that it may be non-UTF-8 data:


  /** Gets the contents of the 'environ' variable of the command line
   * invocation, as would be returned by Glib::get_environ(), ie as a
   * <tt>nullptr</tt>-terminated list of strings in the form 'NAME=VALUE'.
   * The strings may contain non-utf8 data.
   *
   * The remote application usually does not send an environment.  Use
   * Gio::Application::Flags::SEND_ENVIRONMENT to affect that.  Even with this flag
   * set it is possible that the environment is still not available (due
   * to invocation messages from other applications).
   *
   * The return value should not be modified or freed and is valid for as
   * long as @a cmdline exists.
   *
   * See g_application_command_line_getenv() if you are only interested
   * in the value of a single environment variable.
   *
   * @newin{2,28}
   *
   * @return The environment strings, or <tt>nullptr</tt> if they were not sent.
   */
  auto get_environ() const -> std::vector<std::string>;

  //We use std::string instead of ustring because the C documentation says that it may be non-UTF-8 data:

  /** Gets the value of a particular environment variable of the command
   * line invocation, as would be returned by Glib::getenv().  The strings may
   * contain non-utf8 data.
   *
   * The remote application usually does not send an environment.  Use
   * Gio::Application::Flags::SEND_ENVIRONMENT to affect that.  Even with this flag
   * set it is possible that the environment is still not available (due
   * to invocation messages from other applications).
   *
   * The return value should not be modified or freed and is valid for as
   * long as @a cmdline exists.
   *
   * @newin{2,28}
   *
   * @param name The environment variable to get.
   * @return The value of the variable, or <tt>nullptr</tt> if unset or unsent.
   */
  auto getenv(const Glib::ustring& name) const -> std::string;


  /** Determines if @a cmdline represents a remote invocation.
   *
   * @newin{2,28}
   *
   * @return <tt>true</tt> if the invocation was remote.
   */
  auto is_remote() const -> bool;


  /** Gets the platform data associated with the invocation of @a cmdline.
   *
   * This is a Variant dictionary containing information about the
   * context in which the invocation occurred.  It typically contains
   * information like the current working directory and the startup
   * notification ID.
   *
   * For local invocation, it will be <tt>nullptr</tt>.
   *
   * @newin{2,28}
   *
   * @return The platform data, or <tt>nullptr</tt>.
   */
  auto get_platform_data() const -> Glib::Variant< std::map<Glib::ustring, Glib::VariantBase> >;


  /** Sets the exit status that will be used when the invoking process
   * exits.
   *
   * The return value of the Application::signal_command_line() signal is
   * passed to this function when the handler returns.  This is the usual
   * way of setting the exit status.
   *
   * In the event that you want the remote invocation to continue running
   * and want to decide on the exit status in the future, you can use this
   * call.  For the case of a remote invocation, the remote process will
   * typically exit when the last reference is dropped on @a cmdline.  The
   * exit status of the remote process will be equal to the last value
   * that was set with this function.
   *
   * In the case that the commandline invocation is local, the situation
   * is slightly more complicated.  If the commandline invocation results
   * in the mainloop running (ie: because the use-count of the application
   * increased to a non-zero value) then the application is considered to
   * have been 'successful' in a certain sense, and the exit status is
   * always zero.  If the application use count is zero, though, the exit
   * status of the local ApplicationCommandLine is used.
   *
   * @newin{2,28}
   *
   * @param exit_status The exit status.
   */
  void set_exit_status(int exit_status);

  /** Gets the exit status of @a cmdline.  See
   * g_application_command_line_set_exit_status() for more information.
   *
   * @newin{2,28}
   *
   * @return The exit status.
   */
  auto get_exit_status() const -> int;

  /** Formats a message and prints it using the stdout print handler in the invoking process.
   * If this is a local invocation then this is exactly equivalent to g_print().
   *  If this is remote then this is equivalent to calling g_print() in the invoking process.
   *
   * @param message The text to print.
   */
  void print(const Glib::ustring& message);


  /** Formats a message and prints it using the stderr print handler in the invoking process.
   * If this is a local invocation then this is exactly equivalent to g_printerr().
   *  If this is remote then this is equivalent to calling g_printerr() in the invoking process.
   *
   * @param message The text to print.
   */
  void printerr(const Glib::ustring& message);


  /** Creates a File corresponding to a filename that was given as part
   * of the invocation of @a cmdline.
   *
   * This differs from g_file_new_for_commandline_arg() in that it
   * resolves relative pathnames using the current working directory of
   * the invoking process rather than the local process.
   *
   * @newin{2,36}
   *
   * @param arg An argument from @a cmdline.
   * @return A new File.
   */
  auto create_file_for_arg(const Glib::ustring& arg) const -> Glib::RefPtr<File>;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


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
   * @relates Gio::ApplicationCommandLine
   */
  GIOMM_API
  auto wrap(GApplicationCommandLine* object, bool take_copy = false) -> Glib::RefPtr<Gio::ApplicationCommandLine>;
}


#endif /* _GIOMM_APPLICATIONCOMMANDLINE_H */

