
#ifndef _GIOMM_ACTIONGROUP_H
#define _GIOMM_ACTIONGROUP_H

#include <libmm-gio/gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gio/gio.h>
#include <libmm-glib/interface.hxx>
#include <libmm-glib/varianttype.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GActionGroupInterface GActionGroupInterface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GActionGroup = struct _GActionGroup;
using GActionGroupClass = struct _GActionGroupClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API ActionGroup_Class;
}
#endif

namespace Glib
{

  class GIOMM_API VariantBase;
  class GIOMM_API VariantContainerBase;
  class GIOMM_API VariantType;

} // namespace Glib

namespace Gio
{

  class GIOMM_API ActionGroup : public Glib::Interface
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

    explicit ActionGroup (const Glib::Interface_Class& interface_class);

  public:
    explicit ActionGroup (GActionGroup* castitem);

  protected:
#endif

  public:
    ActionGroup (ActionGroup&& src) noexcept;
    auto
    operator= (ActionGroup&& src) noexcept -> ActionGroup&;

    ~ActionGroup () noexcept override;

    static void
    add_interface (GType gtype_implementer);

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
    has_action (const Glib::ustring& action_name) const -> bool;

    auto
    list_actions () const -> std::vector<Glib::ustring>;

    auto
    query_action (const Glib::ustring& action_name,
                  bool& enabled,
                  Glib::VariantType& parameter_type,
                  Glib::VariantBase& state_hint,
                  Glib::VariantType& state_type,
                  Glib::VariantBase& state) -> bool;

    auto
    query_action (const Glib::ustring& action_name,
                  bool& enabled,
                  Glib::VariantType& parameter_type,
                  Glib::VariantBase& state_hint,
                  Glib::VariantType& state_type) -> bool;

    auto
    query_action (const Glib::ustring& action_name,
                  bool& enabled,
                  Glib::VariantType& parameter_type,
                  Glib::VariantBase& state_hint,
                  Glib::VariantBase& state) -> bool;

    auto
    query_action (const Glib::ustring& action_name,
                  bool& enabled,
                  Glib::VariantType& parameter_type,
                  Glib::VariantBase& state_hint) -> bool;

    auto
    query_action (const Glib::ustring& action_name,
                  bool& enabled,
                  Glib::VariantBase& state_hint,
                  Glib::VariantType& state_type,
                  Glib::VariantBase& state) -> bool;

    auto
    query_action (const Glib::ustring& action_name,
                  bool& enabled,
                  Glib::VariantBase& state_hint,
                  Glib::VariantType& state_type) -> bool;

    auto
    query_action (const Glib::ustring& action_name,
                  bool& enabled,
                  Glib::VariantBase& state_hint,
                  Glib::VariantBase& state) -> bool;

    auto
    query_action (const Glib::ustring& action_name,
                  bool& enabled,
                  Glib::VariantBase& state_hint) -> bool;

    auto
    get_action_enabled (const Glib::ustring& action_name) const -> bool;

    auto
    get_action_parameter_type (const Glib::ustring& action_name) const
        -> Glib::VariantType;

    auto
    get_action_state_type (const Glib::ustring& action_name) const
        -> Glib::VariantType;

    template <typename T_Value>
    void
    get_action_state_hint (const Glib::ustring& action_name,
                           T_Value& value) const;

    auto
    get_action_state_hint_variant (const Glib::ustring& action_name) const
        -> Glib::VariantContainerBase;

    template <typename T_Value>
    void
    get_action_state (const Glib::ustring& action_name, T_Value& value) const;

    auto
    get_action_state_variant (const Glib::ustring& action_name) const
        -> Glib::VariantBase;

    void
    change_action_state (const Glib::ustring& action_name,
                         const Glib::VariantBase& value);

    void
    activate_action (const Glib::ustring& action_name,
                     const Glib::VariantBase& parameter);

    void
    activate_action (const Glib::ustring& action_name);

    void
    action_added (const Glib::ustring& action_name);

    void
    action_removed (const Glib::ustring& action_name);

    void
    action_enabled_changed (const Glib::ustring& action_name, bool enabled);

    void
    action_state_changed (const Glib::ustring& action_name,
                          const Glib::VariantBase& state);

    auto
    signal_action_added (const Glib::ustring& action_name = {})
        -> Glib::SignalProxyDetailed<void (const Glib::ustring&)>;

    auto
    signal_action_enabled_changed (const Glib::ustring& action_name = {})
        -> Glib::SignalProxyDetailed<void (const Glib::ustring&, bool)>;

    auto
    signal_action_removed (const Glib::ustring& action_name = {})
        -> Glib::SignalProxyDetailed<void (const Glib::ustring&)>;

    auto
    signal_action_state_changed (const Glib::ustring& action_name = {})
        -> Glib::SignalProxyDetailed<void (const Glib::ustring&,
                                           const Glib::VariantBase&)>;

  protected:
    virtual auto
    has_action_vfunc (const Glib::ustring& name) const -> bool;

    virtual auto
    list_actions_vfunc () const -> std::vector<Glib::ustring>;

    virtual auto
    get_action_enabled_vfunc (const Glib::ustring& name) const -> bool;

    virtual auto
    get_action_parameter_type_vfunc (const Glib::ustring& name) const
        -> Glib::VariantType;

    virtual auto
    get_action_state_type_vfunc (const Glib::ustring& name) const
        -> Glib::VariantType;

    virtual auto
    get_action_state_hint_vfunc (const Glib::ustring& name) const
        -> Glib::VariantBase;

    virtual auto
    get_action_state_vfunc (const Glib::ustring& name) const
        -> Glib::VariantBase;

    virtual void
    change_action_state_vfunc (const Glib::ustring& name,
                               const Glib::VariantBase& value);

    virtual void
    activate_action_vfunc (const Glib::ustring& name,
                           const Glib::VariantBase& parameter);

  public:
  public:
  protected:
    virtual void
    on_action_added (const Glib::ustring& action_name);

    virtual void
    on_action_enabled_changed (const Glib::ustring& action_name, bool enabled);

    virtual void
    on_action_removed (const Glib::ustring& action_name);

    virtual void
    on_action_state_changed (const Glib::ustring& action_name,
                             const Glib::VariantBase& value);
  };

  template <typename T_Value>
  void
  ActionGroup::get_action_state (const Glib::ustring& action_name,
                                 T_Value& value) const
  {
    value = T_Value ();

    using type_glib_variant = Glib::Variant<T_Value>;

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
  void
  ActionGroup::get_action_state_hint (const Glib::ustring& action_name,
                                      T_Value& value) const
  {
    value = T_Value ();

    using type_glib_variant = Glib::Variant<T_Value>;

    const auto variantBase = get_action_state_hint_variant (action_name);

    g_return_if_fail (
        variantBase.is_of_type (type_glib_variant::variant_type ()));

    const auto variantDerived =
        variantBase.cast_dynamic<type_glib_variant> (variantBase);
    value = variantDerived.get ();
  }

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GActionGroup* object, bool take_copy = false) -> Glib::RefPtr<Gio::ActionGroup>;

} // namespace Glib

#endif
