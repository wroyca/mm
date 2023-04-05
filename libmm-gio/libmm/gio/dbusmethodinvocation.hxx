// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSMETHODINVOCATION_H
#define _GIOMM_DBUSMETHODINVOCATION_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/dbusintrospection.hxx>
#include <libmm/gio/dbusmessage.hxx>
#include <libmm/glib/object.hxx>
#include <libmm/glib/variant.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusMethodInvocation = struct _GDBusMethodInvocation;
using GDBusMethodInvocationClass = struct _GDBusMethodInvocationClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio::DBus
{
  class LIBMM_GIO_SYMEXPORT MethodInvocation_Class;
}
#endif

namespace glib
{

  class LIBMM_GIO_SYMEXPORT Error;

}

namespace gio::DBus
{

  class Connection;

  class LIBMM_GIO_SYMEXPORT MethodInvocation : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = MethodInvocation;
    using CppClassType = MethodInvocation_Class;
    using BaseObjectType = GDBusMethodInvocation;
    using BaseClassType = GDBusMethodInvocationClass;

    MethodInvocation (const MethodInvocation&) = delete;
    auto
    operator= (const MethodInvocation&) -> MethodInvocation& = delete;

  private:
    friend class MethodInvocation_Class;
    static CppClassType methodinvocation_class_;

  protected:
    explicit MethodInvocation (const glib::ConstructParams& construct_params);
    explicit MethodInvocation (GDBusMethodInvocation* castitem);

#endif

  public:
    MethodInvocation (MethodInvocation&& src) noexcept;
    auto
    operator= (MethodInvocation&& src) noexcept -> MethodInvocation&;

    ~MethodInvocation () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GDBusMethodInvocation*
    {
      return reinterpret_cast<GDBusMethodInvocation*> (gobject_);
    }

    auto
    gobj () const -> const GDBusMethodInvocation*
    {
      return reinterpret_cast<GDBusMethodInvocation*> (gobject_);
    }

    auto
    gobj_copy () -> GDBusMethodInvocation*;

  private:
  public:
    auto
    get_sender () const -> glib::ustring;

    auto
    get_object_path () const -> glib::ustring;

    auto
    get_interface_name () const -> glib::ustring;

    auto
    get_method_name () const -> glib::ustring;

    auto
    get_method_info () const -> glib::RefPtr<const MethodInfo>;

    auto
    get_connection () -> glib::RefPtr<Connection>;

    auto
    get_connection () const -> glib::RefPtr<const Connection>;

    auto
    get_message () -> glib::RefPtr<Message>;

    auto
    get_message () const -> glib::RefPtr<const Message>;

    auto
    get_parameters () const -> glib::VariantContainerBase;

    auto
    return_value (const glib::VariantContainerBase& parameters) -> void;

#ifdef G_OS_UNIX

    void
    return_value (const glib::VariantContainerBase& parameters,
                  const glib::RefPtr<UnixFDList>& fd_list);
#endif

    auto
    return_error (const glib::ustring& domain,
                  int code,
                  const glib::ustring& message) -> void;

    auto
    return_error (const glib::Error& error) -> void;

    auto
    return_dbus_error (const glib::ustring& error_name,
                       const glib::ustring& error_message) -> void;

  public:
  public:
  protected:
  };

} // namespace gio::DBus

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDBusMethodInvocation* object, bool take_copy = false) -> glib::RefPtr<gio::DBus::MethodInvocation>;
} // namespace glib

#endif
