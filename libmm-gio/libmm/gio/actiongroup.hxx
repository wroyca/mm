// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_ACTIONGROUP_H
#define _GIOMM_ACTIONGROUP_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gio/gio.h>
#include <libmm/glib/interface.hxx>
#include <libmm/glib/varianttype.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GActionGroupInterface GActionGroupInterface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GActionGroup = struct _GActionGroup;
using GActionGroupClass = struct _GActionGroupClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT ActionGroup_Class;
}
#endif

namespace glib
{

  class LIBMM_GIO_SYMEXPORT VariantBase;
  class LIBMM_GIO_SYMEXPORT VariantContainerBase;
  class LIBMM_GIO_SYMEXPORT VariantType;

} // namespace glib

namespace gio
{

  class LIBMM_GIO_SYMEXPORT ActionGroup : public glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ActionGroup;
    using CppClassType = ActionGroup_Class;
    using BaseObjectType = GActionGroup;
    using BaseClassType = GActionGroupInterface;

    ActionGroup (const ActionGroup&) = delete;
    auto
    operator= (const ActionGroup&) -> ActionGroup& = delete;

  private:
    friend class ActionGroup_Class;
    static CppClassType actiongroup_class_;

#endif
  protected:
    ActionGroup ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit ActionGroup (const glib::Interface_Class& interface_class);

  public:
    explicit ActionGroup (GActionGroup* castitem);

  protected:
#endif

  public:
    ActionGroup (ActionGroup&& src) noexcept;
    auto
    operator= (ActionGroup&& src) noexcept -> ActionGroup&;

    ~ActionGroup () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GActionGroup*
    {
      return reinterpret_cast<GActionGroup*> (gobject_);
    }

    auto
    gobj () const -> const GActionGroup*
    {
      return reinterpret_cast<GActionGroup*> (gobject_);
    }

  private:
  public:
    auto
    has_action (const glib::ustring& action_name) const -> bool;

    auto
    list_actions () const -> std::vector<glib::ustring>;

    auto
    query_action (const glib::ustring& action_name,
                  bool& enabled,
                  glib::VariantType& parameter_type,
                  glib::VariantBase& state_hint,
                  glib::VariantType& state_type,
                  glib::VariantBase& state) -> bool;

    auto
    query_action (const glib::ustring& action_name,
                  bool& enabled,
                  glib::VariantType& parameter_type,
                  glib::VariantBase& state_hint,
                  glib::VariantType& state_type) -> bool;

    auto
    query_action (const glib::ustring& action_name,
                  bool& enabled,
                  glib::VariantType& parameter_type,
                  glib::VariantBase& state_hint,
                  glib::VariantBase& state) -> bool;

    auto
    query_action (const glib::ustring& action_name,
                  bool& enabled,
                  glib::VariantType& parameter_type,
                  glib::VariantBase& state_hint) -> bool;

    auto
    query_action (const glib::ustring& action_name,
                  bool& enabled,
                  glib::VariantBase& state_hint,
                  glib::VariantType& state_type,
                  glib::VariantBase& state) -> bool;

    auto
    query_action (const glib::ustring& action_name,
                  bool& enabled,
                  glib::VariantBase& state_hint,
                  glib::VariantType& state_type) -> bool;

    auto
    query_action (const glib::ustring& action_name,
                  bool& enabled,
                  glib::VariantBase& state_hint,
                  glib::VariantBase& state) -> bool;

    auto
    query_action (const glib::ustring& action_name,
                  bool& enabled,
                  glib::VariantBase& state_hint) -> bool;

    auto
    get_action_enabled (const glib::ustring& action_name) const -> bool;

    auto
    get_action_parameter_type (const glib::ustring& action_name) const
        -> glib::VariantType;

    auto
    get_action_state_type (const glib::ustring& action_name) const
        -> glib::VariantType;

    template <typename T_Value>
    auto
    get_action_state_hint (const glib::ustring& action_name,
                           T_Value& value) const -> void;

    auto
    get_action_state_hint_variant (const glib::ustring& action_name) const
        -> glib::VariantContainerBase;

    template <typename T_Value>
    auto
    get_action_state (const glib::ustring& action_name, T_Value& value) const
        -> void;

    auto
    get_action_state_variant (const glib::ustring& action_name) const
        -> glib::VariantBase;

    auto
    change_action_state (const glib::ustring& action_name,
                         const glib::VariantBase& value) -> void;

    auto
    activate_action (const glib::ustring& action_name,
                     const glib::VariantBase& parameter) -> void;

    auto
    activate_action (const glib::ustring& action_name) -> void;

    auto
    action_added (const glib::ustring& action_name) -> void;

    auto
    action_removed (const glib::ustring& action_name) -> void;

    auto
    action_enabled_changed (const glib::ustring& action_name, bool enabled)
        -> void;

    auto
    action_state_changed (const glib::ustring& action_name,
                          const glib::VariantBase& state) -> void;

    auto
    signal_action_added (const glib::ustring& action_name = {})
        -> glib::SignalProxyDetailed<void (const glib::ustring&)>;

    auto
    signal_action_enabled_changed (const glib::ustring& action_name = {})
        -> glib::SignalProxyDetailed<void (const glib::ustring&, bool)>;

    auto
    signal_action_removed (const glib::ustring& action_name = {})
        -> glib::SignalProxyDetailed<void (const glib::ustring&)>;

    auto
    signal_action_state_changed (const glib::ustring& action_name = {})
        -> glib::SignalProxyDetailed<void (const glib::ustring&,
                                           const glib::VariantBase&)>;

  protected:
    virtual auto
    has_action_vfunc (const glib::ustring& name) const -> bool;

    virtual auto
    list_actions_vfunc () const -> std::vector<glib::ustring>;

    virtual auto
    get_action_enabled_vfunc (const glib::ustring& name) const -> bool;

    virtual auto
    get_action_parameter_type_vfunc (const glib::ustring& name) const
        -> glib::VariantType;

    virtual auto
    get_action_state_type_vfunc (const glib::ustring& name) const
        -> glib::VariantType;

    virtual auto
    get_action_state_hint_vfunc (const glib::ustring& name) const
        -> glib::VariantBase;

    virtual auto
    get_action_state_vfunc (const glib::ustring& name) const
        -> glib::VariantBase;

    virtual auto
    change_action_state_vfunc (const glib::ustring& name,
                               const glib::VariantBase& value) -> void;

    virtual auto
    activate_action_vfunc (const glib::ustring& name,
                           const glib::VariantBase& parameter) -> void;

  public:
  public:
  protected:
    virtual auto
    on_action_added (const glib::ustring& action_name) -> void;

    virtual auto
    on_action_enabled_changed (const glib::ustring& action_name, bool enabled)
        -> void;

    virtual auto
    on_action_removed (const glib::ustring& action_name) -> void;

    virtual auto
    on_action_state_changed (const glib::ustring& action_name,
                             const glib::VariantBase& value) -> void;
  };

  template <typename T_Value>
  auto
  ActionGroup::get_action_state (const glib::ustring& action_name,
                                 T_Value& value) const -> void
  {
    value = T_Value ();

    using type_glib_variant = glib::Variant<T_Value>;

    g_return_if_fail (
        g_variant_type_equal (g_action_group_get_action_state_type (
                                  const_cast<GActionGroup*> (gobj ()),
                                  action_name.c_str ()),
                              type_glib_variant::variant_type ().gobj ()));

    const auto variantBase = get_action_state_variant (action_name);

    const auto variantDerived =
        variantBase.cast_dynamic<type_glib_variant> (variantBase);
    value = variantDerived.get ();
  }

  template <typename T_Value>
  auto
  ActionGroup::get_action_state_hint (const glib::ustring& action_name,
                                      T_Value& value) const -> void
  {
    value = T_Value ();

    using type_glib_variant = glib::Variant<T_Value>;

    const auto variantBase = get_action_state_hint_variant (action_name);

    g_return_if_fail (
        variantBase.is_of_type (type_glib_variant::variant_type ()));

    const auto variantDerived =
        variantBase.cast_dynamic<type_glib_variant> (variantBase);
    value = variantDerived.get ();
  }

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GActionGroup* object, bool take_copy = false) -> glib::RefPtr<gio::ActionGroup>;

} // namespace glib

#endif
