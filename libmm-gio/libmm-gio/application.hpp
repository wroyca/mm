
#ifndef _GIOMM_APPLICATION_H
#define _GIOMM_APPLICATION_H

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


#include <mm/gio/actiongroup.hpp>
#include <mm/gio/actionmap.hpp>
#include <mm/gio/applicationcommandline.hpp>
#include <mm/gio/file.hpp>
#include <mm/glib/object.hpp>
#include <mm/glib/optionentry.hpp>
#include <mm/glib/optiongroup.hpp>
#include <mm/glib/variant.hpp>
#include <mm/glib/variantdict.hpp>
#include <mm/gio/dbusconnection.hpp>
#include <mm/gio/notification.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GApplication = struct _GApplication;
using GApplicationClass = struct _GApplicationClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API Application_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{


/** Application - Core application class.
 * An Application is the foundation of an application, unique for a given
 * application identifier. The Application class wraps some low-level
 * platform-specific services and is intended to act as the foundation for
 * higher-level application classes such as Gtk::Application or MxApplication.
 * In general, you should not use this class outside of a higher level
 * framework.
 *
 * One of the core features that Application provides is process uniqueness,
 * in the context of a "session". The session concept is platform-dependent,
 * but corresponds roughly to a graphical desktop login. When your application
 * is launched again, its arguments are passed through platform communication
 * to the already running program. The already running instance of the program
 * is called the <i>primary instance</i>.
 *
 * Before using Application, you must choose an "application identifier". The
 * expected form of an application identifier is very close to that of of a
 * <a href="
 * http://dbus.freedesktop.org/doc/dbus-specification.html#message-protocol-names-interface">DBus
 * bus name</a>. Examples include: "com.example.MyApp",
 * "org.example.internal-apps.Calculator". For details on valid application
 * identifiers, see id_is_valid().
 *
 * Application provides convenient life cycle management by maintaining a
 * <i>use count</i> for the primary application instance. The use count can be
 * changed using hold() and release(). If it drops to zero, the application
 * exits.
 *
 * Application also implements the ActionGroup and ActionMap
 * interfaces and lets you easily export actions by adding them with
 * Gio::ActionMap::add_action(). When invoking an action by calling
 * Gio::ActionGroup::activate_action() on the application, it is always
 * invoked in the primary instance.
 *
 * There is a number of different entry points into an Application:
 *
 * - via 'Activate' (i.e. just starting the application)
 * - via 'Open' (i.e. opening some files)
 * - via activating an action
 *
 * The signal_startup() signal lets you handle the application initialization
 * for all of these in a single place.
 *
 * See the C API docs for an example.
 *
 * @newin{2,32}
 */

class GIOMM_API Application : public Glib::Object, public ActionGroup, public ActionMap
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Application;
  using CppClassType = Application_Class;
  using BaseObjectType = GApplication;
  using BaseClassType = GApplicationClass;

  // noncopyable
  Application(const Application&) = delete;
  auto operator=(const Application&) -> Application& = delete;

private:  friend class Application_Class;
  static CppClassType application_class_;

protected:
  explicit Application(const Glib::ConstructParams& construct_params);
  explicit Application(GApplication* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Application(Application&& src) noexcept;
  auto operator=(Application&& src) noexcept -> Application&;

  ~Application() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GApplication*       { return reinterpret_cast<GApplication*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GApplication* { return reinterpret_cast<GApplication*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GApplication*;

private:


public:
  /** @addtogroup giommEnums giomm Enums and Flags */

  /**
   *  @var Flags NONE
   * Default. Deprecated in 2.74, use
   * Gio::Application::Flags::DEFAULT_FLAGS instead.
   *
   *  @var Flags DEFAULT_FLAGS
   * Default flags. @newin{2,74}
   *
   *  @var Flags IS_SERVICE
   * Run as a service. In this mode, registration
   * fails if the service is already running, and the application
   * will initially wait up to 10 seconds for an initial activation
   * message to arrive.
   *
   *  @var Flags IS_LAUNCHER
   * Don't try to become the primary instance.
   *
   *  @var Flags HANDLES_OPEN
   * This application handles opening files (in
   * the primary instance). Note that this flag only affects the default
   * implementation of local_command_line(), and has no effect if
   * Gio::Application::Flags::HANDLES_COMMAND_LINE is given.
   * See g_application_run() for details.
   *
   *  @var Flags HANDLES_COMMAND_LINE
   * This application handles command line
   * arguments (in the primary instance). Note that this flag only affect
   * the default implementation of local_command_line().
   * See g_application_run() for details.
   *
   *  @var Flags SEND_ENVIRONMENT
   * Send the environment of the
   * launching process to the primary instance. Set this flag if your
   * application is expected to behave differently depending on certain
   * environment variables. For instance, an editor might be expected
   * to use the `GIT_COMMITTER_NAME` environment variable
   * when editing a git commit message. The environment is available
   * to the Application::signal_command_line() signal handler, via
   * g_application_command_line_getenv().
   *
   *  @var Flags NON_UNIQUE
   * Make no attempts to do any of the typical
   * single-instance application negotiation, even if the application
   * ID is given.  The application neither attempts to become the
   * owner of the application ID nor does it check if an existing
   * owner already exists.  Everything occurs in the local process.
   * @newin{2,30}
   *
   *  @var Flags CAN_OVERRIDE_APP_ID
   * Allow users to override the
   * application ID from the command line with `--gapplication-app-id`.
   * @newin{2,48}
   *
   *  @var Flags ALLOW_REPLACEMENT
   * Allow another instance to take over
   * the bus name. @newin{2,60}
   *
   *  @var Flags REPLACE
   * Take over from another instance. This flag is
   * usually set by passing `--gapplication-replace` on the commandline.
   * @newin{2,60}
   *
   *  @enum Flags
   *
   * Flags used to define the behaviour of a Application.
   *
   * @newin{2,28}
   *
   * @ingroup giommEnums
   * @par Bitwise operators:
   * <tt>Application::Flags operator|(Application::Flags, Application::Flags)</tt><br>
   * <tt>Application::Flags operator&(Application::Flags, Application::Flags)</tt><br>
   * <tt>Application::Flags operator^(Application::Flags, Application::Flags)</tt><br>
   * <tt>Application::Flags operator~(Application::Flags)</tt><br>
   * <tt>Application::Flags& operator|=(Application::Flags&, Application::Flags)</tt><br>
   * <tt>Application::Flags& operator&=(Application::Flags&, Application::Flags)</tt><br>
   * <tt>Application::Flags& operator^=(Application::Flags&, Application::Flags)</tt><br>
   */
  enum class Flags
  {
    NONE = 0x0,
    DEFAULT_FLAGS = 0x0,
    IS_SERVICE = (1 << 0),
    IS_LAUNCHER = (1 << 1),
    HANDLES_OPEN = (1 << 2),
    HANDLES_COMMAND_LINE = (1 << 3),
    SEND_ENVIRONMENT = (1 << 4),
    NON_UNIQUE = (1 << 5),
    CAN_OVERRIDE_APP_ID = (1 << 6),
    ALLOW_REPLACEMENT = (1 << 7),
    REPLACE = (1 << 8)
  };


protected:
  /** Constructs an application instance.
   * If no application ID is given then some features (most notably application uniqueness) will be disabled.
   *
   * @param application_id The application ID.
   * @param flags The application flags.
   */
  explicit Application(const Glib::ustring& application_id = {}, Flags flags = Flags::NONE);


public:


  // Application::OptionType wraps GOptionArg, but _WRAP_ENUM can't be used here.
  // GOptionArg is defined in glib_enums.defs, not in gio_enums.defs.
  /** The OptionType enum values determine the expected type of a command line option.
   * If an option expects an extra argument, it can be specified in several ways;
   * with a short option: "-x arg", with a long option: "--name arg" or combined
   * in a single argument: "--name=arg". All option types except OptionType::BOOL
   * expect an extra argument. OptionType::STRING_VECTOR and
   * OptionType::FILENAME_VECTOR accept more than one extra argument.
   *
   * The descriptions of the enum values show what type of Glib::Variant<>
   * is stored in a Glib::VariantDict.
   *
   * @newin{2,42}
   *
   * @ingroup glibmmEnums
   */
  enum class OptionType
  {
    BOOL,   ///< bool
    STRING, ///< Glib::ustring
    INT,    ///< gint32
    // CALLBACK,
    FILENAME = INT+2, ///< std::string
    STRING_VECTOR,    ///< std::vector<Glib::ustring>
    FILENAME_VECTOR,  ///< std::vector<std::string>
    DOUBLE,           ///< double
    INT64             ///< gint64
  };

  /** Creates an application instance.
   * If no application ID is given then some features (most notably application uniqueness) will be disabled.
   *
   * @param application_id The application ID.
   * @param flags The application flags.
   */

  static auto create(const Glib::ustring& application_id =  {}, Flags flags =  Flags::NONE) -> Glib::RefPtr<Application>;


  /** Checks if @a application_id is a valid application identifier.
   *
   * A valid ID is required for calls to g_application_new() and
   * g_application_set_application_id().
   *
   * Application identifiers follow the same format as
   * [D-Bus well-known bus names](https://dbus.freedesktop.org/doc/dbus-specification.html#message-protocol-names-bus).
   * For convenience, the restrictions on application identifiers are
   * reproduced here:
   *
   * - Application identifiers are composed of 1 or more elements separated by a
   * period (`.`) character. All elements must contain at least one character.
   *
   * - Each element must only contain the ASCII characters `[A-Z][a-z][0-9]_-`,
   * with `-` discouraged in new application identifiers. Each element must not
   * begin with a digit.
   *
   * - Application identifiers must contain at least one `.` (period) character
   * (and thus at least two elements).
   *
   * - Application identifiers must not begin with a `.` (period) character.
   *
   * - Application identifiers must not exceed 255 characters.
   *
   * Note that the hyphen (`-`) character is allowed in application identifiers,
   * but is problematic or not allowed in various specifications and APIs that
   * refer to D-Bus, such as
   * [Flatpak application IDs](http://docs.flatpak.org/en/latest/introduction.html#identifiers),
   * the
   * [`DBusActivatable` interface in the Desktop Entry Specification](https://specifications.freedesktop.org/desktop-entry-spec/desktop-entry-spec-latest.html#dbus),
   * and the convention that an application's "main" interface and object path
   * resemble its application identifier and bus name. To avoid situations that
   * require special-case handling, it is recommended that new application
   * identifiers consistently replace hyphens with underscores.
   *
   * Like D-Bus interface names, application identifiers should start with the
   * reversed DNS domain name of the author of the interface (in lower-case), and
   * it is conventional for the rest of the application identifier to consist of
   * words run together, with initial capital letters.
   *
   * As with D-Bus interface names, if the author's DNS domain name contains
   * hyphen/minus characters they should be replaced by underscores, and if it
   * contains leading digits they should be escaped by prepending an underscore.
   * For example, if the owner of 7-zip.org used an application identifier for an
   * archiving application, it might be named `org._7_zip.Archiver`.
   *
   * @param application_id A potential application identifier.
   * @return <tt>true</tt> if @a application_id is valid.
   */
  static auto id_is_valid(const Glib::ustring& application_id) -> bool;


  /** Gets the unique identifier for @a application.
   *
   * @newin{2,28}
   *
   * @return The identifier for @a application, owned by @a application.
   */
  auto get_id() const -> Glib::ustring;

  /** Sets the unique identifier for @a application.
   *
   * The application id can only be modified if @a application has not yet
   * been registered.
   *
   * If non-<tt>nullptr</tt>, the application id must be valid.  See
   * g_application_id_is_valid().
   *
   * @newin{2,28}
   *
   * @param application_id The identifier for @a application.
   */
  void set_id(const Glib::ustring& application_id);


  /** Gets the Gio::DBus::Connection being used by the application, or <tt>nullptr</tt>.
   *
   * If Application is using its D-Bus backend then this function will
   * return the Gio::DBus::Connection being used for uniqueness and
   * communication with the desktop environment and other instances of the
   * application.
   *
   * If Application is not using D-Bus then this function will return
   * <tt>nullptr</tt>.  This includes the situation where the D-Bus backend would
   * normally be in use but we were unable to connect to the bus.
   *
   * This function must not be called before the application has been
   * registered.  See g_application_get_is_registered().
   *
   * @newin{2,34}
   *
   * @return A Gio::DBus::Connection, or <tt>nullptr</tt>.
   */
  auto get_dbus_connection() -> Glib::RefPtr<DBus::Connection>;

  /** Gets the Gio::DBus::Connection being used by the application, or <tt>nullptr</tt>.
   *
   * If Application is using its D-Bus backend then this function will
   * return the Gio::DBus::Connection being used for uniqueness and
   * communication with the desktop environment and other instances of the
   * application.
   *
   * If Application is not using D-Bus then this function will return
   * <tt>nullptr</tt>.  This includes the situation where the D-Bus backend would
   * normally be in use but we were unable to connect to the bus.
   *
   * This function must not be called before the application has been
   * registered.  See g_application_get_is_registered().
   *
   * @newin{2,34}
   *
   * @return A Gio::DBus::Connection, or <tt>nullptr</tt>.
   */
  auto get_dbus_connection() const -> Glib::RefPtr<const DBus::Connection>;


  /** Gets the D-Bus object path being used by the application, or <tt>nullptr</tt>.
   *
   * If Application is using its D-Bus backend then this function will
   * return the D-Bus object path that Application is using.  If the
   * application is the primary instance then there is an object published
   * at this path.  If the application is not the primary instance then
   * the result of this function is undefined.
   *
   * If Application is not using D-Bus then this function will return
   * <tt>nullptr</tt>.  This includes the situation where the D-Bus backend would
   * normally be in use but we were unable to connect to the bus.
   *
   * This function must not be called before the application has been
   * registered.  See g_application_get_is_registered().
   *
   * @newin{2,34}
   *
   * @return The object path, or <tt>nullptr</tt>.
   */
  auto get_dbus_object_path() const -> Glib::ustring;


  /** Gets the current inactivity timeout for the application.
   *
   * This is the amount of time (in milliseconds) after the last call to
   * g_application_release() before the application stops running.
   *
   * @newin{2,28}
   *
   * @return The timeout, in milliseconds.
   */
  auto get_inactivity_timeout() const -> guint;

  /** Sets the current inactivity timeout for the application.
   *
   * This is the amount of time (in milliseconds) after the last call to
   * g_application_release() before the application stops running.
   *
   * This call has no side effects of its own.  The value set here is only
   * used for next time g_application_release() drops the use count to
   * zero.  Any timeouts currently in progress are not impacted.
   *
   * @newin{2,28}
   *
   * @param inactivity_timeout The timeout, in milliseconds.
   */
  void set_inactivity_timeout(guint inactivity_timeout);


  /** Gets the flags for @a application.
   *
   * See Gio::Application::Flags.
   *
   * @newin{2,28}
   *
   * @return The flags for @a application.
   */
  auto get_flags() const -> Flags;

  /** Sets the flags for @a application.
   *
   * The flags can only be modified if @a application has not yet been
   * registered.
   *
   * See Gio::Application::Flags.
   *
   * @newin{2,28}
   *
   * @param flags The flags for @a application.
   */
  void set_flags(Flags flags);


  /** Gets the resource base path of @a application.
   *
   * See g_application_set_resource_base_path() for more information.
   *
   * @newin{2,44}
   *
   * @return The base resource path, if one is set.
   */
  auto get_resource_base_path() const -> std::string;

  /** Sets (or unsets) the base resource path of @a application.
   *
   * The path is used to automatically load various [application
   * resources][gresource] such as menu layouts and action descriptions.
   * The various types of resources will be found at fixed names relative
   * to the given base path.
   *
   * By default, the resource base path is determined from the application
   * ID by prefixing '/' and replacing each '.' with '/'.  This is done at
   * the time that the Application object is constructed.  Changes to
   * the application ID after that point will not have an impact on the
   * resource base path.
   *
   * As an example, if the application has an ID of "org.example.app" then
   * the default resource base path will be "/org/example/app".  If this
   * is a Gtk::Application (and you have not manually changed the path)
   * then Gtk will then search for the menus of the application at
   * "/org/example/app/gtk/menus.ui".
   *
   * See Resource for more information about adding resources to your
   * application.
   *
   * You can disable automatic resource loading functionality by setting
   * the path to <tt>nullptr</tt>.
   *
   * Changing the resource base path once the application is running is
   * not recommended.  The point at which the resource path is consulted
   * for forming paths for various purposes is unspecified.  When writing
   * a sub-class of Application you should either set the
   * Application::property_resource_base_path() property at construction time, or call
   * this function during the instance initialization. Alternatively, you
   * can call this function in the ApplicationClass.startup virtual function,
   * before chaining up to the parent implementation.
   *
   * @newin{2,44}
   *
   * @param resource_path The resource path to use.
   */
  void set_resource_base_path(const std::string& resource_path);

  /** Disable automatic resource loading functionality.
   * See set_resource_base_path().
   * @newin{2,44}
   */
  void unset_resource_base_path();


  //Note: We would like to add a group, not just some entries,
  //so we can do pre and post parsing. See https://bugzilla.gnome.org/show_bug.cgi?id=727602
  //but instead we need to use the VariantDict passed to the handle_local_options signal
  //and provided by ApplicationCommandLine::get_options_dict() in on_command_line().

  /** Adds a main option entry to be handled by the Application.
   *
   * This function is comparable to Glib::OptionGroup::add_entry() +
   * Glib::OptionContext::set_main_group().
   *
   * After the commandline arguments are parsed, the
   * signal_handle_local_options() signal will be emitted.  At this
   * point, the application can inspect the parsed values.
   *
   * Unlike OptionGroup + OptionContext, Application packs the arguments
   * into a Glib::VariantDict which is passed to the
   * signal_handle_local_options() handler, where it can be
   * inspected and modified. If Gio::Application::Flags::HANDLES_COMMAND_LINE is
   * set, then the resulting dictionary is sent to the primary instance,
   * where Gio::ApplicationCommandLine::get_options_dict() will return it.
   * This "packing" is done according to the type of the argument --
   * booleans for normal flags, Glib::ustring's for strings, std::string's for
   * filenames, etc.  The packing only occurs if the flag is given (ie: we
   * do not pack a "false" Variant in the case that a flag is missing).
   *
   * In general, it is recommended that all commandline arguments are
   * parsed locally.  The options dictionary should then be used to
   * transmit the result of the parsing to the primary instance, where
   * Glib::VariantDict::lookup_value() can be used.  For local options, it is
   * possible to consult (and potentially remove) the option from the options dictionary.
   *
   * This function is new in GLib 2.40.  Before then, the only real choice
   * was to send all of the commandline arguments (options and all) to the
   * primary instance for handling.  Application ignored them completely
   * on the local side.  Calling this function "opts in" to the new
   * behaviour, and in particular, means that unrecognised options will be
   * treated as errors.  Unrecognised options have never been ignored when
   * Gio::Application::Flags::HANDLES_COMMAND_LINE is unset.
   *
   * If signal_handle_local_options() needs to see the list of
   * filenames, then the use of G_OPTION_REMAINING as @a long_name is recommended.
   * G_OPTION_REMAINING can be used as a key into
   * the options dictionary.  If you do use G_OPTION_REMAINING then you
   * need to handle these arguments for yourself because once they are
   * consumed, they will no longer be visible to the default handling
   * (which treats them as filenames to be opened).
   *
   * @newin{2,42}
   *
   * @param arg_type A Gio::Application::OptionType.
   * @param long_name The long name of an option can be used to specify it
   *     in a commandline as `--long_name`. Every option must have a
   *     long name.
   * @param short_name If an option has a short name, it can be specified
   *     `-short_name` in a commandline. @a short_name must be a printable
   *     ASCII character different from '-', or '\0' if the option has no
   *     short name.
   * @param description The description for the option in `--help` output.
   * @param arg_description The placeholder to use for the extra argument parsed
   *     by the option in `--help` output.
   * @param flags Flags from Glib::OptionEntry::Flags. Do not set OptionEntry::Flags::FILENAME.
   *     Character encoding is chosen with @a arg_type.
   */
  void add_main_option_entry(OptionType arg_type, const Glib::ustring& long_name,
    gchar short_name = '\0', const Glib::ustring& description = {},
    const Glib::ustring& arg_description = {},
    Glib::OptionEntry::Flags flags = Glib::OptionEntry::Flags::NONE);


  /** Adds a main option entry to be handled by the Application.
   *
   * Adds a string option entry, but lets the callback @a slot parse the extra
   * argument instead of having it packed in a Glib::VariantDict.
   *
   * If you create more than one Application instance (unusual),
   * one Application instance can't add an option with the same name as
   * another instance adds. This restriction does not apply to the
   * add_main_option_entry() that takes an OptionType parameter.
   *
   * @newin{2,42}
   *
   * @see add_main_option_entry(OptionType, const Glib::ustring&,
   *   gchar, const Glib::ustring&, const Glib::ustring&, Glib::OptionEntry::Flags)
   */
  void add_main_option_entry(const Glib::OptionGroup::SlotOptionArgString& slot,
    const Glib::ustring& long_name,
    gchar short_name = '\0', const Glib::ustring& description = {},
    const Glib::ustring& arg_description = {},
    Glib::OptionEntry::Flags flags = Glib::OptionEntry::Flags::NONE);

  /** Adds a main option entry to be handled by the Application.
   *
   * Adds a filename option entry, but lets the callback @a slot parse the extra
   * argument instead of having it packed in a Glib::VariantDict.
   *
   * If you create more than one Application instance (unusual),
   * one Application instance can't add an option with the same name as
   * another instance adds. This restriction does not apply to the
   * add_main_option_entry() that takes an OptionType parameter.
   *
   * @newin{2,42}
   *
   * @see add_main_option_entry(OptionType, const Glib::ustring&,
   *   gchar, const Glib::ustring&, const Glib::ustring&, Glib::OptionEntry::Flags)
   */
  void add_main_option_entry_filename(const Glib::OptionGroup::SlotOptionArgFilename& slot,
    const Glib::ustring& long_name,
    gchar short_name = '\0', const Glib::ustring& description = {},
    const Glib::ustring& arg_description = {},
    Glib::OptionEntry::Flags flags = Glib::OptionEntry::Flags::NONE);

  // GApplication takes ownership of the GOptionGroup, unrefing it later.


  /** Adds a Glib::OptionGroup to the commandline handling of the application.
   *
   * This function is comparable to Glib::OptionContext::add_group().
   *
   * Unlike add_main_option_entry(), this function never transmits options to the
   * primary instance.
   *
   * The reason for that is because, by the time the options arrive at the
   * primary instance, it is typically too late to do anything with them.
   * Taking the GTK option group as an example: GTK will already have been
   * initialised by the time the signal_command_line() handler runs.
   * In the case that this is not the first-running instance of the
   * application, the existing instance may already have been running for
   * a very long time.
   *
   * This means that the options from Glib::OptionGroup are only really usable
   * in the case that the instance of the application being run is the
   * first instance. Passing options like `--display=` or `--gdk-debug=`
   * on future runs will have no effect on the existing primary instance.
   *
   * Calling this function will cause the options in the supplied option
   * group to be parsed, but it does not cause you to be "opted in" to the
   * new functionality whereby unrecognised options are rejected even if
   * Gio::Application::Flags::HANDLES_COMMAND_LINE was given.
   *
   * @newin{2,62}
   *
   * @param group A Glib::OptionGroup.
   * @note The group will not be copied, so it should exist for as long as the application exists.
   */
  void add_option_group(Glib::OptionGroup& group);


  /** Sets the parameter string to be used by the commandline handling of @a application.
   *
   * This function registers the argument to be passed to Glib::option_context_new()
   * when the internal OptionContext of @a application is created.
   *
   * See Glib::option_context_new() for more information about @a parameter_string.
   *
   * @newin{2,56}
   *
   * @param parameter_string A string which is displayed
   * in the first line of `--help` output, after the usage summary `programname [OPTION...]`.
   */
  void set_option_context_parameter_string(const Glib::ustring& parameter_string);

  /** Adds a summary to the @a application option context.
   *
   * See Glib::option_context_set_summary() for more information.
   *
   * @newin{2,56}
   *
   * @param summary A string to be shown in `--help` output
   * before the list of options, or <tt>nullptr</tt>.
   */
  void set_option_context_summary(const Glib::ustring& summary);

  /** Adds a description to the @a application option context.
   *
   * See Glib::option_context_set_description() for more information.
   *
   * @newin{2,56}
   *
   * @param description A string to be shown in `--help` output
   * after the list of options, or <tt>nullptr</tt>.
   */
  void set_option_context_description(const Glib::ustring& description);


  /** Checks if @a application is registered.
   *
   * An application is registered if g_application_register() has been
   * successfully called.
   *
   * @newin{2,28}
   *
   * @return <tt>true</tt> if @a application is registered.
   */
  auto is_registered() const -> bool;

  /** Checks if @a application is remote.
   *
   * If @a application is remote then it means that another instance of
   * application already exists (the 'primary' instance).  Calls to
   * perform actions on @a application will result in the actions being
   * performed by the primary instance.
   *
   * The value of this property cannot be accessed before
   * g_application_register() has been called.  See
   * g_application_get_is_registered().
   *
   * @newin{2,28}
   *
   * @return <tt>true</tt> if @a application is remote.
   */
  auto is_remote() const -> bool;

  //Renamed from register() because that is a C++ keyword.

  /** Attempts registration of the application.
   *
   * This is the point at which the application discovers if it is the
   * primary instance or merely acting as a remote for an already-existing
   * primary instance.  This is implemented by attempting to acquire the
   * application identifier as a unique bus name on the session bus using
   * GDBus.
   *
   * If there is no application ID or if Gio::Application::Flags::NON_UNIQUE was
   * given, then this process will always become the primary instance.
   *
   * Due to the internal architecture of GDBus, method calls can be
   * dispatched at any time (even if a main loop is not running).  For
   * this reason, you must ensure that any object paths that you wish to
   * register are registered before calling this function.
   *
   * If the application has already been registered then <tt>true</tt> is
   * returned with no work performed.
   *
   * The Application::signal_startup() signal is emitted if registration succeeds
   * and @a application is the primary instance (including the non-unique
   * case).
   *
   * In the event of an error (such as @a cancellable being cancelled, or a
   * failure to connect to the session bus), <tt>false</tt> is returned and @a error
   * is set appropriately.
   *
   * @note the return value of this function is not an indicator that this
   * instance is or is not the primary instance of the application.  See
   * g_application_get_is_remote() for that.
   *
   * @newin{2,28}
   *
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   * @return <tt>true</tt> if registration succeeded.
   *
   * @throws Glib::Error
   */
  auto register_application(const Glib::RefPtr<Gio::Cancellable>& cancellable) -> bool;

  /// A register_application() convenience overload.
  auto register_application() -> bool;


  /** Increases the use count of @a application.
   *
   * Use this function to indicate that the application has a reason to
   * continue to run.  For example, g_application_hold() is called by GTK+
   * when a toplevel window is on the screen.
   *
   * To cancel the hold, call g_application_release().
   */
  void hold();

  /** Decrease the use count of @a application.
   *
   * When the use count reaches zero, the application will stop running.
   *
   * Never call this function except to cancel the effect of a previous
   * call to g_application_hold().
   */
  void release();

  /** Activates the application.
   *
   * In essence, this results in the Application::signal_activate() signal being
   * emitted in the primary instance.
   *
   * The application must be registered before calling this function.
   *
   * @newin{2,28}
   */
  void activate();

  using type_vec_files = std::vector< Glib::RefPtr<File> >;

  /* Opens the given files.
   *
   * In essence, this results in the open signal being emitted
   * in the primary instance.
   *
   * @a hint is simply passed through to the open signal.  It is
   * intended to be used by applications that have multiple modes for
   * opening files (eg: "view" vs "edit", etc).
   *
   * The application must be registered before calling this method
   * and it must have the Application::Flags::HANDLES_OPEN flag set.
   *
   * @param files The files to open. This must be non-empty.
   * @param hint A hint.
   *
   * @newin{2,32}
   */
  void open(const type_vec_files& files, const Glib::ustring& hint = {});


  /* Opens the given file.
   *
   * In essence, this results in the open signal being emitted
   * in the primary instance.
   *
   * @a hint is simply passed through to the open signal.  It is
   * intended to be used by applications that have multiple modes for
   * opening files (eg: "view" vs "edit", etc).
   *
   * The application must be registered before calling this method
   * and it must have the Application::Flags::HANDLES_OPEN flag set.
   *
   * @param file The file to open. This must be non-empty.
   * @param hint A hint.
   *
   * @newin{2,32}
   */
  void open(const Glib::RefPtr<Gio::File>& file, const Glib::ustring& hint = {});


  /** Runs the application.
   *
   * This function is intended to be run from main() and its return value
   * is intended to be returned by main(). Although you are expected to pass
   * the @a argc, @a argv parameters from main() to this function, it is possible
   * to pass <tt>nullptr</tt> if @a argv is not available or commandline handling is not
   * required.  Note that on Windows, @a argc and @a argv are ignored, and
   * Glib::win32_get_command_line() is called internally (for proper support
   * of Unicode commandline arguments).
   *
   * Application will attempt to parse the commandline arguments.  You
   * can add commandline flags to the list of recognised options by way of
   * g_application_add_main_option_entries().  After this, the
   * Application::signal_handle_local_options() signal is emitted, from which the
   * application can inspect the values of its OptionEntrys.
   *
   * Application::signal_handle_local_options() is a good place to handle options
   * such as `--version`, where an immediate reply from the local process is
   * desired (instead of communicating with an already-running instance).
   * A Application::signal_handle_local_options() handler can stop further processing
   * by returning a non-negative value, which then becomes the exit status of
   * the process.
   *
   * What happens next depends on the flags: if
   * Gio::Application::Flags::HANDLES_COMMAND_LINE was specified then the remaining
   * commandline arguments are sent to the primary instance, where a
   * Application::signal_command_line() signal is emitted.  Otherwise, the
   * remaining commandline arguments are assumed to be a list of files.
   * If there are no files listed, the application is activated via the
   * Application::signal_activate() signal.  If there are one or more files, and
   * Gio::Application::Flags::HANDLES_OPEN was specified then the files are opened
   * via the Application::signal_open() signal.
   *
   * If you are interested in doing more complicated local handling of the
   * commandline then you should implement your own Application subclass
   * and override local_command_line(). In this case, you most likely want
   * to return <tt>true</tt> from your local_command_line() implementation to
   * suppress the default handling. See
   * [gapplication-example-cmdline2.c][https://gitlab.gnome.org/GNOME/glib/-/blob/HEAD/gio/tests/gapplication-example-cmdline2.c]
   * for an example.
   *
   * If, after the above is done, the use count of the application is zero
   * then the exit status is returned immediately.  If the use count is
   * non-zero then the default main context is iterated until the use count
   * falls to zero, at which point 0 is returned.
   *
   * If the Gio::Application::Flags::IS_SERVICE flag is set, then the service will
   * run for as much as 10 seconds with a use count of zero while waiting
   * for the message that caused the activation to arrive.  After that,
   * if the use count falls to zero the application will exit immediately,
   * except in the case that g_application_set_inactivity_timeout() is in
   * use.
   *
   * This function sets the prgname (Glib::set_prgname()), if not already set,
   * to the basename of argv[0].
   *
   * Much like Glib::main_loop_run(), this function will acquire the main context
   * for the duration that the application is running.
   *
   * Since 2.40, applications that are not explicitly flagged as services
   * or launchers (ie: neither Gio::Application::Flags::IS_SERVICE or
   * Gio::Application::Flags::IS_LAUNCHER are given as flags) will check (from the
   * default handler for local_command_line) if "--gapplication-service"
   * was given in the command line.  If this flag is present then normal
   * commandline processing is interrupted and the
   * Gio::Application::Flags::IS_SERVICE flag is set.  This provides a "compromise"
   * solution whereby running an application directly from the commandline
   * will invoke it in the normal way (which can be useful for debugging)
   * while still allowing applications to be D-Bus activated in service
   * mode.  The D-Bus service file should invoke the executable with
   * "--gapplication-service" as the sole commandline argument.  This
   * approach is suitable for use by most graphical applications but
   * should not be used from applications like editors that need precise
   * control over when processes invoked via the commandline will exit and
   * what their exit status will be.
   *
   * @newin{2,28}
   *
   * @param argc The argc from main() (or 0 if @a argv is <tt>nullptr</tt>).
   * @param argv The argv from main(), or <tt>nullptr</tt>.
   * @return The exit status.
   */
  auto run(int argc, char** argv) -> int;


  /** Immediately quits the application.
   *
   * Upon return to the mainloop, g_application_run() will return,
   * calling only the 'shutdown' function before doing so.
   *
   * The hold count is ignored.
   * Take care if your code has called g_application_hold() on the application and
   * is therefore still expecting it to exist.
   * (Note that you may have called g_application_hold() indirectly, for example
   * through gtk_application_add_window().)
   *
   * The result of calling g_application_run() again after it returns is
   * unspecified.
   *
   * @newin{2,32}
   */
  void quit();


  /** Sets or unsets the default application for the process, as returned
   * by g_application_get_default().
   *
   * This function does not take its own reference on @a application.  If
   *  @a application is destroyed then the default application will revert
   * back to <tt>nullptr</tt>.
   *
   * @newin{2,32}
   *
   * @param application The application to set as default, or <tt>nullptr</tt>.
   */
  static void set_default(const Glib::RefPtr<Application>& application);

  /// Unsets any existing default application.
  static void unset_default();


  /** Returns the default Application instance for this process.
   *
   * Normally there is only one Application per process and it becomes
   * the default when it is created.  You can exercise more control over
   * this by using g_application_set_default().
   *
   * If there is no default application then <tt>nullptr</tt> is returned.
   *
   * @newin{2,32}
   *
   * @return The default application for this process, or <tt>nullptr</tt>.
   */
  static auto get_default() -> Glib::RefPtr<Application>;


  /** Increases the busy count of @a application.
   *
   * Use this function to indicate that the application is busy, for instance
   * while a long running operation is pending.
   *
   * The busy state will be exposed to other processes, so a session shell will
   * use that information to indicate the state to the user (e.g. with a
   * spinner).
   *
   * To cancel the busy indication, use g_application_unmark_busy().
   *
   * The application must be registered before calling this function.
   *
   * @newin{2,38}
   */
  void mark_busy();

  /** Decreases the busy count of @a application.
   *
   * When the busy count reaches zero, the new state will be propagated
   * to other processes.
   *
   * This function must only be called to cancel the effect of a previous
   * call to g_application_mark_busy().
   *
   * @newin{2,38}
   */
  void unmark_busy();

  /** Gets the application's current busy state, as set through
   * g_application_mark_busy() or g_application_bind_busy_property().
   *
   * @newin{2,44}
   *
   * @return <tt>true</tt> if @a application is currently marked as busy.
   */
  auto get_is_busy() const -> bool;


  /** Sends a notification on behalf of @a application to the desktop shell.
   * There is no guarantee that the notification is displayed immediately,
   * or even at all.
   *
   * Notifications may persist after the application exits. It will be
   * D-Bus-activated when the notification or one of its actions is
   * activated.
   *
   * Modifying @a notification after this call has no effect. However, the
   * object can be reused for a later call to this function.
   *
   *  @a id may be any string that uniquely identifies the event for the
   * application. It does not need to be in any special format. For
   * example, "new-message" might be appropriate for a notification about
   * new messages.
   *
   * If a previous notification was sent with the same @a id, it will be
   * replaced with @a notification and shown again as if it was a new
   * notification. This works even for notifications sent from a previous
   * execution of the application, as long as @a id is the same string.
   *
   *  @a id may be <tt>nullptr</tt>, but it is impossible to replace or withdraw
   * notifications without an id.
   *
   * If @a notification is no longer relevant, it can be withdrawn with
   * g_application_withdraw_notification().
   *
   * @newin{2,40}
   *
   * @param id Id of the notification, or <tt>nullptr</tt>.
   * @param notification The Notification to send.
   */
  void send_notification(const Glib::ustring& id, const Glib::RefPtr<Notification>& notification);

  /// A send_notification() convenience overload.
  void send_notification(const Glib::RefPtr<Notification>& notification);

  /** Withdraws a notification that was sent with
   * g_application_send_notification().
   *
   * This call does nothing if a notification with @a id doesn't exist or
   * the notification was never sent.
   *
   * This function works even for notifications sent in previous
   * executions of this application, as long @a id is the same as it was for
   * the sent notification.
   *
   * Note that notifications are dismissed when the user clicks on one
   * of the buttons in a notification or triggers its default action, so
   * there is no need to explicitly withdraw the notification in that case.
   *
   * @newin{2,40}
   *
   * @param id Id of a previously sent notification.
   */
  void withdraw_notification(const Glib::ustring& id);

//TODO: Glib::RefPtr<Glib::ObjectBase>, Glib::ObjectBase, or both?
//#m4 __CONVERSION(`const Glib::RefPtr<Glib::ObjectBase>&', `gpointer', `($3)->gobj()')
//  _WRAP_METHOD(void bind_busy_property(const Glib::RefPtr<Glib::ObjectBase>& object, const Glib::ustring& property), g_application_bind_busy_property)
//  _WRAP_METHOD(void unbind_busy_property(const Glib::RefPtr<Glib::ObjectBase>& object, const Glib::ustring& property), g_application_unbind_busy_property)


  /** The unique identifier for the application.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_application_id() -> Glib::PropertyProxy< Glib::ustring > ;

/** The unique identifier for the application.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_application_id() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Flags specifying the behaviour of the application.
   *
   * Default value: Gio::Application::Flags::NONE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_flags() -> Glib::PropertyProxy< Flags > ;

/** Flags specifying the behaviour of the application.
   *
   * Default value: Gio::Application::Flags::NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_flags() const -> Glib::PropertyProxy_ReadOnly< Flags >;

  /** Time (ms) to stay alive after becoming idle.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_inactivity_timeout() -> Glib::PropertyProxy< guint > ;

/** Time (ms) to stay alive after becoming idle.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_inactivity_timeout() const -> Glib::PropertyProxy_ReadOnly< guint >;

  /** If g_application_register() has been called.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_is_registered() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** If this application instance is remote.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_is_remote() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** The base resource path for the application.
   *
   * @newin{2,44}
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_resource_base_path() -> Glib::PropertyProxy< std::string > ;

/** The base resource path for the application.
   *
   * @newin{2,44}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_resource_base_path() const -> Glib::PropertyProxy_ReadOnly< std::string >;

  /** Whether the application is currently marked as busy through
   * g_application_mark_busy() or g_application_bind_busy_property().
   *
   * @newin{2,44}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_is_busy() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%startup()</tt>
   *
   * Flags: Run First
   *
   * The signal_startup() signal is emitted on the primary instance immediately
   * after registration. See g_application_register().
   */

  auto signal_startup() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%shutdown()</tt>
   *
   * Flags: Run Last
   *
   * The signal_shutdown() signal is emitted only on the registered primary instance
   * immediately after the main loop terminates.
   *
   * @newin{2,46}
   */

  auto signal_shutdown() -> Glib::SignalProxy<void()>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%activate()</tt>
   *
   * Flags: Run Last
   *
   * The signal_activate() signal is emitted on the primary instance when an
   * activation occurs. See g_application_activate().
   */

  auto signal_activate() -> Glib::SignalProxy<void()>;


  //We wrap the open signal without _WRAP_SIGNAL(), because we need to change its parameters.
  //See bug https://bugzilla.gnome.org/show_bug.cgi?id=637457
  auto signal_open() -> Glib::SignalProxy<void(const type_vec_files&, const Glib::ustring&)>;


  /**
   * @par Slot Prototype:
   * <tt>int on_my_%command_line(const Glib::RefPtr<ApplicationCommandLine>& command_line)</tt>
   *
   * Flags: Run Last
   *
   * The signal_command_line() signal is emitted on the primary instance when
   * a commandline is not handled locally. See g_application_run() and
   * the ApplicationCommandLine documentation for more information.
   *
   * @param command_line A ApplicationCommandLine representing the
   * passed commandline.
   * @return An integer that is set as the exit status for the calling
   * process. See g_application_command_line_set_exit_status().
   */

  auto signal_command_line() -> Glib::SignalProxy<int(const Glib::RefPtr<ApplicationCommandLine>&)>;


  //TODO: Avoid the use of the Variants in the VariantDict?
  //options must be non-const. The handler is meant to modify it. See the description
  //of add_main_option_entry(OptionType, ...).


  /**
   * @par Slot Prototype:
   * <tt>int on_my_%handle_local_options(const Glib::RefPtr<Glib::VariantDict>& options)</tt>
   *
   * Flags: Run Last
   *
   * The signal_handle_local_options() signal is emitted on the local instance
   * after the parsing of the commandline options has occurred.
   *
   * You can add options to be recognised during commandline option
   * parsing using g_application_add_main_option_entries() and
   * g_application_add_option_group().
   *
   * Signal handlers can inspect @a options (along with values pointed to
   * from the @a arg_data of an installed OptionEntrys) in order to
   * decide to perform certain actions, including direct local handling
   * (which may be useful for options like --version).
   *
   * In the event that the application is marked
   * Gio::Application::Flags::HANDLES_COMMAND_LINE the "normal processing" will
   * send the @a options dictionary to the primary instance where it can be
   * read with g_application_command_line_get_options_dict().  The signal
   * handler can modify the dictionary before returning, and the
   * modified dictionary will be sent.
   *
   * In the event that Gio::Application::Flags::HANDLES_COMMAND_LINE is not set,
   * "normal processing" will treat the remaining uncollected command
   * line arguments as filenames or URIs.  If there are no arguments,
   * the application is activated by g_application_activate().  One or
   * more arguments results in a call to g_application_open().
   *
   * If you want to handle the local commandline arguments for yourself
   * by converting them to calls to g_application_open() or
   * g_action_group_activate_action() then you must be sure to register
   * the application first.  You should probably not call
   * g_application_activate() for yourself, however: just return -1 and
   * allow the default handler to do it for you.  This will ensure that
   * the `--gapplication-service` switch works properly (i.e. no activation
   * in that case).
   *
   * Note that this signal is emitted from the default implementation of
   * local_command_line().  If you override that function and don't
   * chain up then this signal will never be emitted.
   *
   * You can override local_command_line() if you need more powerful
   * capabilities than what is provided here, but this should not
   * normally be required.
   *
   * @newin{2,40}
   *
   * @param options The options dictionary.
   * @return An exit code. If you have handled your options and want
   * to exit the process, return a non-negative option, 0 for success,
   * and a positive value for failure. To continue, return -1 to let
   * the default option processing continue.
   */

  auto signal_handle_local_options() -> Glib::SignalProxy<int(const Glib::RefPtr<Glib::VariantDict>&)>;


  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%name_lost()</tt>
   *
   * Flags: Run Last
   *
   * The signal_name_lost() signal is emitted only on the registered primary instance
   * when a new instance has taken over. This can only happen if the application
   * is using the Gio::Application::Flags::ALLOW_REPLACEMENT flag.
   *
   * The default handler for this signal calls g_application_quit().
   *
   * @newin{2,60}
   *
   * @return <tt>true</tt> if the signal has been handled.
   */

  auto signal_name_lost() -> Glib::SignalProxy<bool()>;


protected:
  virtual void on_open(const type_vec_files& files, const Glib::ustring& hint);


    virtual auto local_command_line_vfunc(char**& arguments, int& exit_status) -> bool;


    virtual void before_emit_vfunc(const Glib::VariantBase& platform_data);

    virtual void after_emit_vfunc(const Glib::VariantBase& platform_data);


  //TODO: File a bug about GVariantBuilder not being registered with the GType system first:
  //_WRAP_VFUNC(void add_platform_data(Glib::VariantBuilder* builder), "add_platform_data")

    virtual void quit_mainloop_vfunc();

    virtual void run_mainloop_vfunc();


  /// @throws Glib::Error.
  virtual auto dbus_register_vfunc(const Glib::RefPtr<DBus::Connection>& connection, const Glib::ustring& object_path) -> bool;

    virtual void dbus_unregister_vfunc(const Glib::RefPtr<DBus::Connection>& connection, const Glib::ustring& object_path);


private:
  /** This is just a way to call Glib::init() before calling a Glib::Object ctor,
   * so that glibmm's GQuarks are created before they are used.
   */
  auto custom_class_init() -> const Glib::Class&;

  // Code, common to the public add_main_option_entry*() methods with a callback slot.
  void add_main_option_entry_private(const gchar* long_name, gchar short_name,
    const gchar* description, const gchar* arg_description,
    Glib::OptionEntry::Flags flags);


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_startup().
  virtual void on_startup();
  /// This is a default handler for the signal signal_shutdown().
  virtual void on_shutdown();
  /// This is a default handler for the signal signal_activate().
  virtual void on_activate();
  /// This is a default handler for the signal signal_command_line().
  virtual auto on_command_line(const Glib::RefPtr<ApplicationCommandLine>& command_line) -> int;
  /// This is a default handler for the signal signal_handle_local_options().
  virtual auto on_handle_local_options(const Glib::RefPtr<Glib::VariantDict>& options) -> int;
  /// This is a default handler for the signal signal_name_lost().
  virtual auto on_name_lost() -> bool;


};

} // namespace Gio

namespace Gio
{

/** @ingroup giommEnums */
inline auto operator|(Application::Flags lhs, Application::Flags rhs) -> Application::Flags
  { return static_cast<Application::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(Application::Flags lhs, Application::Flags rhs) -> Application::Flags
  { return static_cast<Application::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(Application::Flags lhs, Application::Flags rhs) -> Application::Flags
  { return static_cast<Application::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(Application::Flags flags) -> Application::Flags
  { return static_cast<Application::Flags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(Application::Flags& lhs, Application::Flags rhs) -> Application::Flags&
  { return (lhs = static_cast<Application::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(Application::Flags& lhs, Application::Flags rhs) -> Application::Flags&
  { return (lhs = static_cast<Application::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(Application::Flags& lhs, Application::Flags rhs) -> Application::Flags&
  { return (lhs = static_cast<Application::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::Application::Flags> : public Glib::Value_Flags<Gio::Application::Flags>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::Application
   */
  GIOMM_API
  auto wrap(GApplication* object, bool take_copy = false) -> Glib::RefPtr<Gio::Application>;
}


#endif /* _GIOMM_APPLICATION_H */

