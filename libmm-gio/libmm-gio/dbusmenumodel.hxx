
#ifndef _GIOMM_DBUSMENUMODEL_H
#define _GIOMM_DBUSMENUMODEL_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/menumodel.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusMenuModel = struct _GDBusMenuModel;
using GDBusMenuModelClass = struct _GDBusMenuModelClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio::DBus
{
  class GIOMM_API MenuModel_Class;
}
#endif

namespace Gio::DBus
{

  class GIOMM_API Connection;

  class GIOMM_API MenuModel : public ::Gio::MenuModel
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = MenuModel;
    using CppClassType = MenuModel_Class;
    using BaseObjectType = GDBusMenuModel;
    using BaseClassType = GDBusMenuModelClass;

    MenuModel (const MenuModel&) = delete;
    auto
    operator= (const MenuModel&) -> MenuModel& = delete;

  private:
    friend class MenuModel_Class;
    static CppClassType menumodel_class_;

  protected:
    explicit MenuModel (const Glib::ConstructParams& construct_params);
    explicit MenuModel (GDBusMenuModel* castitem);

#endif

  public:
    MenuModel (MenuModel&& src) noexcept;
    auto
    operator= (MenuModel&& src) noexcept -> MenuModel&;

    ~MenuModel () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GDBusMenuModel*
    {
      return reinterpret_cast<GDBusMenuModel*> (gobject_);
    }

    auto
    gobj () const -> const GDBusMenuModel*
    {
      return reinterpret_cast<GDBusMenuModel*> (gobject_);
    }

    auto
    gobj_copy () -> GDBusMenuModel*;

  private:
  protected:
    MenuModel ();

  public:
    static auto
    get (const Glib::RefPtr<Connection>& connection,
         const Glib::ustring& bus_name,
         const Glib::ustring& object_path) -> Glib::RefPtr<MenuModel>;

  public:
  public:
  protected:
  };

} // namespace Gio::DBus

namespace Glib
{

  GIOMM_API
  auto
  wrap (GDBusMenuModel* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::MenuModel>;
} // namespace Glib

#endif
