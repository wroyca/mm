// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSMETHODINVOCATION_H
#define _GIOMM_DBUSMETHODINVOCATION_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/dbusintrospection.hxx>
#include <libmm-gio/dbusmessage.hxx>
#include <libmm-glib/object.hxx>
#include <libmm-glib/variant.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusMethodInvocation = struct _GDBusMethodInvocation;
using GDBusMethodInvocationClass = struct _GDBusMethodInvocationClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio::DBus
{
  class LIBMM_GIO_SYMEXPORT MethodInvocation_Class;
}
#endif

namespace Glib
{

  class LIBMM_GIO_SYMEXPORT Error;

}

namespace Gio::DBus
{

  class Connection;

  class LIBMM_GIO_SYMEXPORT MethodInvocation : public Glib::Object
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
    explicit MethodInvocation (const Glib::ConstructParams& construct_params);
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
    get_sender () const -> Glib::ustring;

    auto
    get_object_path () const -> Glib::ustring;

    auto
    get_interface_name () const -> Glib::ustring;

    auto
    get_method_name () const -> Glib::ustring;

    auto
    get_method_info () const -> Glib::RefPtr<const MethodInfo>;

    auto
    get_connection () -> Glib::RefPtr<Connection>;

    auto
    get_connection () const -> Glib::RefPtr<const Connection>;

    auto
    get_message () -> Glib::RefPtr<Message>;

    auto
    get_message () const -> Glib::RefPtr<const Message>;

    auto
    get_parameters () const -> Glib::VariantContainerBase;

    auto
    return_value (const Glib::VariantContainerBase& parameters) -> void;

#ifdef G_OS_UNIX

    void
    return_value (const Glib::VariantContainerBase& parameters,
                  const Glib::RefPtr<UnixFDList>& fd_list);
#endif

    auto
    return_error (const Glib::ustring& domain,
                  int code,
                  const Glib::ustring& message) -> void;

    auto
    return_error (const Glib::Error& error) -> void;

    auto
    return_dbus_error (const Glib::ustring& error_name,
                       const Glib::ustring& error_message) -> void;

  public:
  public:
  protected:
  };

} // namespace Gio::DBus

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDBusMethodInvocation* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::MethodInvocation>;
} // namespace Glib

#endif
