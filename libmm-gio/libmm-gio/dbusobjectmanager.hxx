// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSOBJECTMANAGER_H
#define _GIOMM_DBUSOBJECTMANAGER_H

#include <libmm-gio/gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/interface.hxx>
#include <libmm-glib/ustring.hxx>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GDBusObjectManagerIface GDBusObjectManagerIface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusObjectManager = struct _GDBusObjectManager;
using GDBusObjectManagerClass = struct _GDBusObjectManagerClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio::DBus
{
  class GIOMM_API ObjectManager_Class;
}
#endif

namespace Gio::DBus
{
  class GIOMM_API Interface;
  class GIOMM_API Object;

  class GIOMM_API ObjectManager : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ObjectManager;
    using CppClassType = ObjectManager_Class;
    using BaseObjectType = GDBusObjectManager;
    using BaseClassType = GDBusObjectManagerIface;

    ObjectManager (const ObjectManager&) = delete;
    auto
    operator= (const ObjectManager&) -> ObjectManager& = delete;

  private:
    friend class ObjectManager_Class;
    static CppClassType objectmanager_class_;

#endif
  protected:
    ObjectManager ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit ObjectManager (const Glib::Interface_Class& interface_class);

  public:
    explicit ObjectManager (GDBusObjectManager* castitem);

  protected:
#endif

  public:
    ObjectManager (ObjectManager&& src) noexcept;
    auto
    operator= (ObjectManager&& src) noexcept -> ObjectManager&;

    ~ObjectManager () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GDBusObjectManager*
    {
      return reinterpret_cast<GDBusObjectManager*> (gobject_);
    }

    auto
    gobj () const -> const GDBusObjectManager*
    {
      return reinterpret_cast<GDBusObjectManager*> (gobject_);
    }

  private:
  public:
    auto
    get_object_path () const -> Glib::ustring;

    auto
    get_objects () -> std::vector<Glib::RefPtr<Gio::DBus::Object>>;

    auto
    get_objects () const -> std::vector<Glib::RefPtr<const Gio::DBus::Object>>;

    auto
    get_object (const Glib::ustring& object_path)
        -> Glib::RefPtr<Gio::DBus::Object>;

    auto
    get_object (const Glib::ustring& object_path) const
        -> Glib::RefPtr<const Gio::DBus::Object>;

    auto
    get_interface (const Glib::ustring& object_path,
                   const Glib::ustring& interface_name)
        -> Glib::RefPtr<Gio::DBus::Interface>;

    auto
    get_interface (const Glib::ustring& object_path,
                   const Glib::ustring& interface_name) const
        -> Glib::RefPtr<const Gio::DBus::Interface>;

    auto
    signal_object_added ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Gio::DBus::Object>&)>;

    auto
    signal_object_removed ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Gio::DBus::Object>&)>;

    auto
    signal_interface_added ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Gio::DBus::Object>&,
                                   const Glib::RefPtr<Gio::DBus::Interface>&)>;

    auto
    signal_interface_removed ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Gio::DBus::Object>&,
                                   const Glib::RefPtr<Gio::DBus::Interface>&)>;

  protected:
    virtual auto
    get_object_path_vfunc () const -> Glib::ustring;

    virtual auto
    get_objects_vfunc () const -> std::vector<Glib::RefPtr<Gio::DBus::Object>>;

    virtual auto
    get_object_vfunc (const Glib::ustring& object_path) const
        -> Glib::RefPtr<Gio::DBus::Object>;

    virtual auto
    get_interface_vfunc (const Glib::ustring& object_path,
                         const Glib::ustring& interface_name) const
        -> Glib::RefPtr<Gio::DBus::Interface>;

  public:
  public:
  protected:
    virtual auto
    on_object_added (const Glib::RefPtr<Gio::DBus::Object>& object) -> void;

    virtual auto
    on_object_removed (const Glib::RefPtr<Gio::DBus::Object>& object) -> void;

    virtual auto
    on_interface_added (const Glib::RefPtr<Gio::DBus::Object>& object,
                        const Glib::RefPtr<Gio::DBus::Interface>& iface)
        -> void;

    virtual auto
    on_interface_removed (const Glib::RefPtr<Gio::DBus::Object>& object,
                          const Glib::RefPtr<Gio::DBus::Interface>& iface)
        -> void;
  };

} // namespace Gio::DBus

namespace Glib
{

  GIOMM_API
  auto
  wrap (GDBusObjectManager* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::ObjectManager>;

} // namespace Glib

#endif
