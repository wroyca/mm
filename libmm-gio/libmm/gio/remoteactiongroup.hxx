// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_REMOTEACTIONGROUP_H
#define _GIOMM_REMOTEACTIONGROUP_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/interface.hxx>

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
  class LIBMM_GIO_SYMEXPORT RemoteActionGroup_Class;
}
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT RemoteActionGroup : public Glib::Interface
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

    static auto
    add_interface (GType gtype_implementer) -> void;

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
    auto
    activate_action (const Glib::ustring& action_name,
                     const Glib::VariantBase& parameter,
                     const Glib::VariantBase& platform_data) -> void;

    auto
    change_action_state (const Glib::ustring& action_name,
                         const Glib::VariantBase& value,
                         const Glib::VariantBase& platform_data) -> void;

  protected:
    virtual auto
    activate_action_full_vfunc (const Glib::ustring& action_name,
                                const Glib::VariantBase& parameter,
                                const Glib::VariantBase& platform_data) -> void;

    virtual auto
    change_action_state_full_vfunc (const Glib::ustring& action_name,
                                    const Glib::VariantBase& value,
                                    const Glib::VariantBase& platform_data)
        -> void;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GRemoteActionGroup* object, bool take_copy = false) -> Glib::RefPtr<Gio::RemoteActionGroup>;

} // namespace Glib

#endif
