// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSOBJECTMANAGER_H
#define _GIOMM_DBUSOBJECTMANAGER_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/interface.hxx>
#include <libmm/glib/ustring.hxx>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GDBusObjectManagerIface GDBusObjectManagerIface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusObjectManager = struct _GDBusObjectManager;
using GDBusObjectManagerClass = struct _GDBusObjectManagerClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio::DBus
{
  class LIBMM_GIO_SYMEXPORT ObjectManager_Class;
}
#endif

namespace gio::DBus
{
  class LIBMM_GIO_SYMEXPORT Interface;
  class LIBMM_GIO_SYMEXPORT Object;

  class LIBMM_GIO_SYMEXPORT ObjectManager : public glib::Interface
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

    explicit ObjectManager (const glib::Interface_Class& interface_class);

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
    get_object_path () const -> glib::ustring;

    auto
    get_objects () -> std::vector<glib::RefPtr<gio::DBus::Object>>;

    auto
    get_objects () const -> std::vector<glib::RefPtr<const gio::DBus::Object>>;

    auto
    get_object (const glib::ustring& object_path)
        -> glib::RefPtr<gio::DBus::Object>;

    auto
    get_object (const glib::ustring& object_path) const
        -> glib::RefPtr<const gio::DBus::Object>;

    auto
    get_interface (const glib::ustring& object_path,
                   const glib::ustring& interface_name)
        -> glib::RefPtr<gio::DBus::Interface>;

    auto
    get_interface (const glib::ustring& object_path,
                   const glib::ustring& interface_name) const
        -> glib::RefPtr<const gio::DBus::Interface>;

    auto
    signal_object_added ()
        -> glib::SignalProxy<void (const glib::RefPtr<gio::DBus::Object>&)>;

    auto
    signal_object_removed ()
        -> glib::SignalProxy<void (const glib::RefPtr<gio::DBus::Object>&)>;

    auto
    signal_interface_added ()
        -> glib::SignalProxy<void (const glib::RefPtr<gio::DBus::Object>&,
                                   const glib::RefPtr<gio::DBus::Interface>&)>;

    auto
    signal_interface_removed ()
        -> glib::SignalProxy<void (const glib::RefPtr<gio::DBus::Object>&,
                                   const glib::RefPtr<gio::DBus::Interface>&)>;

  protected:
    virtual auto
    get_object_path_vfunc () const -> glib::ustring;

    virtual auto
    get_objects_vfunc () const -> std::vector<glib::RefPtr<gio::DBus::Object>>;

    virtual auto
    get_object_vfunc (const glib::ustring& object_path) const
        -> glib::RefPtr<gio::DBus::Object>;

    virtual auto
    get_interface_vfunc (const glib::ustring& object_path,
                         const glib::ustring& interface_name) const
        -> glib::RefPtr<gio::DBus::Interface>;

  public:
  public:
  protected:
    virtual auto
    on_object_added (const glib::RefPtr<gio::DBus::Object>& object) -> void;

    virtual auto
    on_object_removed (const glib::RefPtr<gio::DBus::Object>& object) -> void;

    virtual auto
    on_interface_added (const glib::RefPtr<gio::DBus::Object>& object,
                        const glib::RefPtr<gio::DBus::Interface>& iface)
        -> void;

    virtual auto
    on_interface_removed (const glib::RefPtr<gio::DBus::Object>& object,
                          const glib::RefPtr<gio::DBus::Interface>& iface)
        -> void;
  };

} // namespace gio::DBus

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDBusObjectManager* object, bool take_copy = false) -> glib::RefPtr<gio::DBus::ObjectManager>;

} // namespace glib

#endif
