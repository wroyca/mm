// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSOBJECT_H
#define _GIOMM_DBUSOBJECT_H

#include <libmm-gio/gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GDBusObjectIface GDBusObjectIface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusObject = struct _GDBusObject;
using GDBusObjectClass = struct _GDBusObjectClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio::DBus
{
  class GIOMM_API Object_Class;
}
#endif

namespace Gio::DBus
{

  class GIOMM_API Interface;

  class GIOMM_API Object : public Glib::Interface
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

    explicit Object (const Glib::Interface_Class& interface_class);

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
    get_object_path () const -> Glib::ustring;

    auto
    get_interfaces () -> std::vector<Glib::RefPtr<Gio::DBus::Interface>>;

    auto
    get_interfaces () const
        -> std::vector<Glib::RefPtr<const Gio::DBus::Interface>>;

    auto
    get_interface (const Glib::ustring& interface_name)
        -> Glib::RefPtr<Gio::DBus::Interface>;

    auto
    get_interface (const Glib::ustring& interface_name) const
        -> Glib::RefPtr<const Gio::DBus::Interface>;

    auto
    signal_interface_added ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Gio::DBus::Interface>&)>;

    auto
    signal_interface_removed ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Gio::DBus::Interface>&)>;

  protected:
    virtual auto
    get_object_path_vfunc () const -> Glib::ustring;

    virtual auto
    get_interfaces_vfunc () const
        -> std::vector<Glib::RefPtr<Gio::DBus::Interface>>;

    virtual auto
    get_interface_vfunc (const Glib::ustring& interface_name) const
        -> Glib::RefPtr<Gio::DBus::Interface>;

  public:
  public:
  protected:
    virtual auto
    on_interface_added (const Glib::RefPtr<Gio::DBus::Interface>& iface)
        -> void;

    virtual auto
    on_interface_removed (const Glib::RefPtr<Gio::DBus::Interface>& iface)
        -> void;
  };

} // namespace Gio::DBus

namespace Glib
{

  GIOMM_API
  auto
  wrap (GDBusObject* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::Object>;

} // namespace Glib

#endif
