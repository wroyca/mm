
#ifndef _GIOMM_REMOTEACTIONGROUP_H
#define _GIOMM_REMOTEACTIONGROUP_H

#include <libmm-gio/gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GRemoteActionGroupInterface GRemoteActionGroupInterface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GRemoteActionGroup = struct _GRemoteActionGroup;
using GRemoteActionGroupClass = struct _GRemoteActionGroupClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API RemoteActionGroup_Class;
}
#endif

namespace Gio
{

  class GIOMM_API RemoteActionGroup : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = RemoteActionGroup;
    using CppClassType = RemoteActionGroup_Class;
    using BaseObjectType = GRemoteActionGroup;
    using BaseClassType = GRemoteActionGroupInterface;

    RemoteActionGroup (const RemoteActionGroup&) = delete;
    auto
    operator= (const RemoteActionGroup&) -> RemoteActionGroup& = delete;

  private:
    friend class RemoteActionGroup_Class;
    static CppClassType remoteactiongroup_class_;

#endif
  protected:
    RemoteActionGroup ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit RemoteActionGroup (const Glib::Interface_Class& interface_class);

  public:
    explicit RemoteActionGroup (GRemoteActionGroup* castitem);

  protected:
#endif

  public:
    RemoteActionGroup (RemoteActionGroup&& src) noexcept;
    auto
    operator= (RemoteActionGroup&& src) noexcept -> RemoteActionGroup&;

    ~RemoteActionGroup () noexcept override;

    static void
    add_interface (GType gtype_implementer);

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GRemoteActionGroup*
    {
      return reinterpret_cast<GRemoteActionGroup*> (gobject_);
    }

    auto
    gobj () const -> const GRemoteActionGroup*
    {
      return reinterpret_cast<GRemoteActionGroup*> (gobject_);
    }

  private:
  public:
    void
    activate_action (const Glib::ustring& action_name,
                     const Glib::VariantBase& parameter,
                     const Glib::VariantBase& platform_data);

    void
    change_action_state (const Glib::ustring& action_name,
                         const Glib::VariantBase& value,
                         const Glib::VariantBase& platform_data);

  protected:
    virtual void
    activate_action_full_vfunc (const Glib::ustring& action_name,
                                const Glib::VariantBase& parameter,
                                const Glib::VariantBase& platform_data);

    virtual void
    change_action_state_full_vfunc (const Glib::ustring& action_name,
                                    const Glib::VariantBase& value,
                                    const Glib::VariantBase& platform_data);

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GRemoteActionGroup* object, bool take_copy = false) -> Glib::RefPtr<Gio::RemoteActionGroup>;

} // namespace Glib

#endif
