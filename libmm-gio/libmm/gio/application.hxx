// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_APPLICATION_H
#define _GIOMM_APPLICATION_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/actiongroup.hxx>
#include <libmm/gio/actionmap.hxx>
#include <libmm/gio/applicationcommandline.hxx>
#include <libmm/gio/dbusconnection.hxx>
#include <libmm/gio/file.hxx>
#include <libmm/gio/notification.hxx>
#include <libmm/glib/object.hxx>
#include <libmm/glib/optionentry.hxx>
#include <libmm/glib/optiongroup.hxx>
#include <libmm/glib/variant.hxx>
#include <libmm/glib/variantdict.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GApplication = struct _GApplication;
using GApplicationClass = struct _GApplicationClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT Application_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT Application : public glib::Object,
                                public ActionGroup,
                                public ActionMap
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Application;
    using CppClassType = Application_Class;
    using BaseObjectType = GApplication;
    using BaseClassType = GApplicationClass;

    Application (const Application&) = delete;
    auto
    operator= (const Application&) -> Application& = delete;

  private:
    friend class Application_Class;
    static CppClassType application_class_;

  protected:
    explicit Application (const glib::ConstructParams& construct_params);
    explicit Application (GApplication* castitem);

#endif

  public:
    Application (Application&& src) noexcept;
    auto
    operator= (Application&& src) noexcept -> Application&;

    ~Application () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GApplication*
    {
      return reinterpret_cast<GApplication*> (gobject_);
    }

    auto
    gobj () const -> const GApplication*
    {
      return reinterpret_cast<GApplication*> (gobject_);
    }

    auto
    gobj_copy () -> GApplication*;

  private:
  public:
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
    explicit Application (const glib::ustring& application_id = {},
                          Flags flags = Flags::NONE);

  public:
    enum class OptionType
    {
      BOOL,
      STRING,
      INT,

      FILENAME = INT + 2,
      STRING_VECTOR,
      FILENAME_VECTOR,
      DOUBLE,
      INT64
    };

    static auto
    create (const glib::ustring& application_id = {}, Flags flags = Flags::NONE)
        -> glib::RefPtr<Application>;

    static auto
    id_is_valid (const glib::ustring& application_id) -> bool;

    auto
    get_id () const -> glib::ustring;

    auto
    set_id (const glib::ustring& application_id) -> void;

    auto
    get_dbus_connection () -> glib::RefPtr<DBus::Connection>;

    auto
    get_dbus_connection () const -> glib::RefPtr<const DBus::Connection>;

    auto
    get_dbus_object_path () const -> glib::ustring;

    auto
    get_inactivity_timeout () const -> guint;

    auto
    set_inactivity_timeout (guint inactivity_timeout) -> void;

    auto
    get_flags () const -> Flags;

    auto
    set_flags (Flags flags) -> void;

    auto
    get_resource_base_path () const -> std::string;

    auto
    set_resource_base_path (const std::string& resource_path) -> void;

    auto
    unset_resource_base_path () -> void;

    auto
    add_main_option_entry (OptionType arg_type,
                           const glib::ustring& long_name,
                           gchar short_name = '\0',
                           const glib::ustring& description = {},
                           const glib::ustring& arg_description = {},
                           glib::OptionEntry::Flags flags =
                               glib::OptionEntry::Flags::NONE) -> void;

    auto
    add_main_option_entry (const glib::OptionGroup::SlotOptionArgString& slot,
                           const glib::ustring& long_name,
                           gchar short_name = '\0',
                           const glib::ustring& description = {},
                           const glib::ustring& arg_description = {},
                           glib::OptionEntry::Flags flags =
                               glib::OptionEntry::Flags::NONE) -> void;

    auto
    add_main_option_entry_filename (
        const glib::OptionGroup::SlotOptionArgFilename& slot,
        const glib::ustring& long_name,
        gchar short_name = '\0',
        const glib::ustring& description = {},
        const glib::ustring& arg_description = {},
        glib::OptionEntry::Flags flags = glib::OptionEntry::Flags::NONE)
        -> void;

    auto
    add_option_group (glib::OptionGroup& group) -> void;

    auto
    set_option_context_parameter_string (const glib::ustring& parameter_string)
        -> void;

    auto
    set_option_context_summary (const glib::ustring& summary) -> void;

    auto
    set_option_context_description (const glib::ustring& description) -> void;

    auto
    is_registered () const -> bool;

    auto
    is_remote () const -> bool;

    auto
    register_application (const glib::RefPtr<gio::Cancellable>& cancellable)
        -> bool;

    auto
    register_application () -> bool;

    auto
    hold () -> void;

    auto
    release () -> void;

    auto
    activate () -> void;

    using type_vec_files = std::vector<glib::RefPtr<File>>;

    auto
    open (const type_vec_files& files, const glib::ustring& hint = {}) -> void;

    auto
    open (const glib::RefPtr<gio::File>& file, const glib::ustring& hint = {})
        -> void;

    auto
    run (int argc, char** argv) -> int;

    auto
    quit () -> void;

    static auto
    set_default (const glib::RefPtr<Application>& application) -> void;

    static auto
    unset_default () -> void;

    static auto
    get_default () -> glib::RefPtr<Application>;

    auto
    mark_busy () -> void;

    auto
    unmark_busy () -> void;

    auto
    get_is_busy () const -> bool;

    auto
    send_notification (const glib::ustring& id,
                       const glib::RefPtr<Notification>& notification) -> void;

    auto
    send_notification (const glib::RefPtr<Notification>& notification) -> void;

    auto
    withdraw_notification (const glib::ustring& id) -> void;

    auto
    property_application_id () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_application_id () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_flags () -> glib::PropertyProxy<Flags>;

    auto
    property_flags () const -> glib::PropertyProxy_ReadOnly<Flags>;

    auto
    property_inactivity_timeout () -> glib::PropertyProxy<guint>;

    auto
    property_inactivity_timeout () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_is_registered () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_is_remote () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_resource_base_path () -> glib::PropertyProxy<std::string>;

    auto
    property_resource_base_path () const
        -> glib::PropertyProxy_ReadOnly<std::string>;

    auto
    property_is_busy () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    signal_startup () -> glib::SignalProxy<void ()>;

    auto
    signal_shutdown () -> glib::SignalProxy<void ()>;

    auto
    signal_activate () -> glib::SignalProxy<void ()>;

    auto
    signal_open () -> glib::SignalProxy<void (const type_vec_files&,
                                              const glib::ustring&)>;

    auto
    signal_command_line ()
        -> glib::SignalProxy<int (const glib::RefPtr<ApplicationCommandLine>&)>;

    auto
    signal_handle_local_options ()
        -> glib::SignalProxy<int (const glib::RefPtr<glib::VariantDict>&)>;

    auto
    signal_name_lost () -> glib::SignalProxy<bool ()>;

  protected:
    virtual auto
    on_open (const type_vec_files& files, const glib::ustring& hint) -> void;

    virtual auto
    local_command_line_vfunc (char**& arguments, int& exit_status) -> bool;

    virtual auto
    before_emit_vfunc (const glib::VariantBase& platform_data) -> void;

    virtual auto
    after_emit_vfunc (const glib::VariantBase& platform_data) -> void;

    virtual auto
    quit_mainloop_vfunc () -> void;

    virtual auto
    run_mainloop_vfunc () -> void;

    virtual auto
    dbus_register_vfunc (const glib::RefPtr<DBus::Connection>& connection,
                         const glib::ustring& object_path) -> bool;

    virtual auto
    dbus_unregister_vfunc (const glib::RefPtr<DBus::Connection>& connection,
                           const glib::ustring& object_path) -> void;

  private:
    auto
    custom_class_init () -> const glib::Class&;

    auto
    add_main_option_entry_private (const gchar* long_name,
                                   gchar short_name,
                                   const gchar* description,
                                   const gchar* arg_description,
                                   glib::OptionEntry::Flags flags) -> void;

  public:
  public:
  protected:
    virtual auto
    on_startup () -> void;

    virtual auto
    on_shutdown () -> void;

    virtual auto
    on_activate () -> void;

    virtual auto
    on_command_line (const glib::RefPtr<ApplicationCommandLine>& command_line)
        -> int;

    virtual auto
    on_handle_local_options (const glib::RefPtr<glib::VariantDict>& options)
        -> int;

    virtual auto
    on_name_lost () -> bool;
  };

} // namespace gio

namespace gio
{

  inline auto
  operator| (Application::Flags lhs, Application::Flags rhs) -> Application::Flags
  {
    return static_cast<Application::Flags> (static_cast<unsigned> (lhs) |
                                            static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (Application::Flags lhs, Application::Flags rhs) -> Application::Flags
  {
    return static_cast<Application::Flags> (static_cast<unsigned> (lhs) &
                                            static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (Application::Flags lhs, Application::Flags rhs) -> Application::Flags
  {
    return static_cast<Application::Flags> (static_cast<unsigned> (lhs) ^
                                            static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(Application::Flags flags) -> Application::Flags
  {
    return static_cast<Application::Flags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (Application::Flags& lhs, Application::Flags rhs) -> Application::Flags&
  {
    return (lhs = static_cast<Application::Flags> (
                static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (Application::Flags& lhs, Application::Flags rhs) -> Application::Flags&
  {
    return (lhs = static_cast<Application::Flags> (
                static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (Application::Flags& lhs, Application::Flags rhs) -> Application::Flags&
  {
    return (lhs = static_cast<Application::Flags> (
                static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs)));
  }
} // namespace gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::Application::Flags>
    : public glib::Value_Flags<gio::Application::Flags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GApplication* object, bool take_copy = false) -> glib::RefPtr<gio::Application>;
} // namespace glib

#endif
