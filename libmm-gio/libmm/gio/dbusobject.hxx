// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSOBJECT_H
#define _GIOMM_DBUSOBJECT_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GDBusObjectIface GDBusObjectIface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusObject = struct _GDBusObject;
using GDBusObjectClass = struct _GDBusObjectClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio::DBus
{
  class LIBMM_GIO_SYMEXPORT Object_Class;
}
#endif

namespace gio::DBus
{

  class LIBMM_GIO_SYMEXPORT Interface;

  class LIBMM_GIO_SYMEXPORT Object : public glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Object;
    using CppClassType = Object_Class;
    using BaseObjectType = GDBusObject;
    using BaseClassType = GDBusObjectIface;

    Object (const Object&) = delete;
    auto
    operator= (const Object&) -> Object& = delete;

  private:
    friend class Object_Class;
    static CppClassType object_class_;

#endif
  protected:
    Object ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit Object (const glib::Interface_Class& interface_class);

  public:
    explicit Object (GDBusObject* castitem);

  protected:
#endif

  public:
    Object (Object&& src) noexcept;
    auto
    operator= (Object&& src) noexcept -> Object&;

    ~Object () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GDBusObject*
    {
      return reinterpret_cast<GDBusObject*> (gobject_);
    }

    auto
    gobj () const -> const GDBusObject*
    {
      return reinterpret_cast<GDBusObject*> (gobject_);
    }

  private:
  public:
    auto
    get_object_path () const -> glib::ustring;

    auto
    get_interfaces () -> std::vector<glib::RefPtr<gio::DBus::Interface>>;

    auto
    get_interfaces () const
        -> std::vector<glib::RefPtr<const gio::DBus::Interface>>;

    auto
    get_interface (const glib::ustring& interface_name)
        -> glib::RefPtr<gio::DBus::Interface>;

    auto
    get_interface (const glib::ustring& interface_name) const
        -> glib::RefPtr<const gio::DBus::Interface>;

    auto
    signal_interface_added ()
        -> glib::SignalProxy<void (const glib::RefPtr<gio::DBus::Interface>&)>;

    auto
    signal_interface_removed ()
        -> glib::SignalProxy<void (const glib::RefPtr<gio::DBus::Interface>&)>;

  protected:
    virtual auto
    get_object_path_vfunc () const -> glib::ustring;

    virtual auto
    get_interfaces_vfunc () const
        -> std::vector<glib::RefPtr<gio::DBus::Interface>>;

    virtual auto
    get_interface_vfunc (const glib::ustring& interface_name) const
        -> glib::RefPtr<gio::DBus::Interface>;

  public:
  public:
  protected:
    virtual auto
    on_interface_added (const glib::RefPtr<gio::DBus::Interface>& iface)
        -> void;

    virtual auto
    on_interface_removed (const glib::RefPtr<gio::DBus::Interface>& iface)
        -> void;
  };

} // namespace gio::DBus

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDBusObject* object, bool take_copy = false) -> glib::RefPtr<gio::DBus::Object>;

} // namespace glib

#endif
