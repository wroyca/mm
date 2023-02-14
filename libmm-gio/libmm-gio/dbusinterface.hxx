
#ifndef _GIOMM_DBUSINTERFACE_H
#define _GIOMM_DBUSINTERFACE_H

#include <libmm-gio/gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GDBusInterfaceIface GDBusInterfaceIface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusInterface = struct _GDBusInterface;
using GDBusInterfaceClass = struct _GDBusInterfaceClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio::DBus
{
  class GIOMM_API Interface_Class;
}
#endif

namespace Gio::DBus
{

  class GIOMM_API InterfaceInfo;
  class GIOMM_API Object;

  class GIOMM_API Interface : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Interface;
    using CppClassType = Interface_Class;
    using BaseObjectType = GDBusInterface;
    using BaseClassType = GDBusInterfaceIface;

    Interface (const Interface&) = delete;
    auto
    operator= (const Interface&) -> Interface& = delete;

  private:
    friend class Interface_Class;
    static CppClassType interface_class_;

#endif
  protected:
    Interface ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit Interface (const Glib::Interface_Class& interface_class);

  public:
    explicit Interface (GDBusInterface* castitem);

  protected:
#endif

  public:
    Interface (Interface&& src) noexcept;
    auto
    operator= (Interface&& src) noexcept -> Interface&;

    ~Interface () noexcept override;

    static void
    add_interface (GType gtype_implementer);

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GDBusInterface*
    {
      return reinterpret_cast<GDBusInterface*> (gobject_);
    }

    auto
    gobj () const -> const GDBusInterface*
    {
      return reinterpret_cast<GDBusInterface*> (gobject_);
    }

  private:
  public:
    auto
    get_info () -> Glib::RefPtr<InterfaceInfo>;

    auto
    get_info () const -> Glib::RefPtr<const InterfaceInfo>;

    auto
    get_object () -> Glib::RefPtr<Gio::DBus::Object>;

    auto
    get_object () const -> Glib::RefPtr<const Gio::DBus::Object>;

    auto
    dup_object () -> Glib::RefPtr<Gio::DBus::Object>;

    auto
    dup_object () const -> Glib::RefPtr<const Gio::DBus::Object>;

    void
    set_object (const Glib::RefPtr<Gio::DBus::Object>& object);

  protected:
    virtual auto
    get_info_vfunc () const -> Glib::RefPtr<InterfaceInfo>;

    virtual auto
    get_object_vfunc () const -> Glib::RefPtr<Gio::DBus::Object>;

    virtual void
    set_object_vfunc (const Glib::RefPtr<Gio::DBus::Object>& object);

    virtual auto
    dup_object_vfunc () const -> Glib::RefPtr<Gio::DBus::Object>;

  public:
  public:
  protected:
  };

} // namespace Gio::DBus

namespace Glib
{

  GIOMM_API
  auto
  wrap (GDBusInterface* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::Interface>;

} // namespace Glib

#endif
