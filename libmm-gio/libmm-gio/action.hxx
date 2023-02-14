
#ifndef _GIOMM_ACTION_H
#define _GIOMM_ACTION_H

#include <libmm-gio/gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gio/gio.h>
#include <libmm-glib/interface.hxx>
#include <libmm-glib/variant.hxx>
#include <libmm-glib/varianttype.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GActionInterface GActionInterface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GAction = struct _GAction;
using GActionClass = struct _GActionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API Action_Class;
}
#endif

namespace Gio
{

  class GIOMM_API Action : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Action;
    using CppClassType = Action_Class;
    using BaseObjectType = GAction;
    using BaseClassType = GActionInterface;

    Action (const Action&) = delete;
    auto
    operator= (const Action&) -> Action& = delete;

  private:
    friend class Action_Class;
    static CppClassType action_class_;

#endif
  protected:
    Action ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit Action (const Glib::Interface_Class& interface_class);

  public:
    explicit Action (GAction* castitem);

  protected:
#endif

  public:
    Action (Action&& src) noexcept;
    auto
    operator= (Action&& src) noexcept -> Action&;

    ~Action () noexcept override;

    static void
    add_interface (GType gtype_implementer);

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GAction*
    {
      return reinterpret_cast<GAction*> (gobject_);
    }

    auto
    gobj () const -> const GAction*
    {
      return reinterpret_cast<GAction*> (gobject_);
    }

  private:
  public:
    auto
    get_name () const -> Glib::ustring;

    auto
    get_parameter_type () const -> Glib::VariantType;

    auto
    get_state_type () const -> Glib::VariantType;

    template <typename T_Value>
    void
    get_state_hint (T_Value& value) const;

    auto
    get_state_hint_variant () const -> Glib::VariantContainerBase;

    auto
    get_enabled () const -> bool;

    template <typename T_Value>
    void
    change_state (const T_Value& value);

    template <typename T_Value>
    void
    change_state (const Glib::Variant<T_Value>& value);

    void
    change_state_variant (const Glib::VariantBase& value);

    template <typename T_Value>
    void
    get_state (T_Value& value) const;

    auto
    get_state_variant () const -> Glib::VariantBase;

    void
    activate ();

    template <typename T_Value>
    void
    activate (const T_Value& parameter);

    template <typename T_Value>
    void
    activate (const Glib::Variant<T_Value>& parameter);

    void
    activate_variant (const Glib::VariantBase& parameter);

    static auto
    name_is_valid (const Glib::ustring& action_name) -> bool;

    template <typename T_Value>
    static void
    parse_detailed_name (const Glib::ustring& detailed_name,
                         Glib::ustring& action_name,
                         T_Value& target_value);

    static void
    parse_detailed_name_variant (const Glib::ustring& detailed_name,
                                 Glib::ustring& action_name,
                                 Glib::VariantBase& target_value);

    template <typename T_Value>
    auto
    print_detailed_name (const T_Value& target_value) -> Glib::ustring;

    static auto
    print_detailed_name_variant (const Glib::ustring& action_name,
                                 const Glib::VariantBase& target_value)
        -> Glib::ustring;

    auto
    property_enabled () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_parameter_type () const
        -> Glib::PropertyProxy_ReadOnly<Glib::VariantType>;

    auto
    property_state () const -> Glib::PropertyProxy_ReadOnly<Glib::VariantBase>;

    auto
    property_state_type () const
        -> Glib::PropertyProxy_ReadOnly<Glib::VariantType>;

  protected:
    virtual auto
    get_name_vfunc () const -> Glib::ustring;

    virtual auto
    get_parameter_type_vfunc () const -> Glib::VariantType;

    virtual auto
    get_state_type_vfunc () const -> Glib::VariantType;

    virtual auto
    get_state_hint_vfunc () const -> Glib::VariantBase;

    virtual auto
    get_enabled_vfunc () const -> bool;

    virtual auto
    get_state_vfunc () const -> Glib::VariantBase;

    virtual void
    change_state_vfunc (const Glib::VariantBase& value);

    virtual void
    activate_vfunc (const Glib::VariantBase& parameter);

  public:
  public:
  protected:
  };

  template <typename T_Value>
  void
  Action::get_state (T_Value& value) const
  {
    value = T_Value ();

    using type_glib_variant = Glib::Variant<T_Value>;

    g_return_if_fail (g_variant_type_equal (
        g_action_get_state_type (const_cast<GAction*> (gobj ())),
        type_glib_variant::variant_type ().gobj ()));

    const auto variantBase = get_state_variant ();
    const auto variantDerived =
        variantBase.cast_dynamic<type_glib_variant> (variantBase);
    value = variantDerived.get ();
  }

  template <typename T_Value>
  void
  Action::get_state_hint (T_Value& value) const
  {
    value = T_Value ();

    using type_glib_variant = Glib::Variant<T_Value>;

    const auto variantBase = get_state_hint_variant ();

    g_return_if_fail (
        variantBase.is_of_type (type_glib_variant::variant_type ()));

    const auto variantDerived =
        variantBase.cast_dynamic<type_glib_variant> (variantBase);
    value = variantDerived.get ();
  }

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  template <typename T_Value>

  void
  Action::parse_detailed_name (const Glib::ustring& detailed_name,
                               Glib::ustring& action_name,
                               T_Value& target_value)
  {
    action_name.clear ();
    target_value = T_Value ();

    using type_glib_variant = Glib::Variant<T_Value>;

    Glib::VariantBase target_value_variantBase;
    parse_detailed_name_variant (detailed_name,
                                 action_name,
                                 target_value_variantBase);

    if (!target_value_variantBase)
      throw Glib::VariantParseError (
          Glib::VariantParseError::TYPE_ERROR,
          "Detailed action name '" + detailed_name +
              "' has no target. Expected a target of type " +
              type_glib_variant::variant_type ().get_string ());

    if (!target_value_variantBase.is_of_type (
            type_glib_variant::variant_type ()))
      throw Glib::VariantParseError (
          Glib::VariantParseError::TYPE_ERROR,
          "Detailed action name '" + detailed_name + "' has a target of type " +
              target_value_variantBase.get_type_string () + ". Expected " +
              type_glib_variant::variant_type ().get_string ());

    const type_glib_variant target_value_variantDerived =
        target_value_variantBase.cast_dynamic<type_glib_variant> (
            target_value_variantBase);
    target_value = target_value_variantDerived.get ();
  }
#endif

  template <typename T_Value>
  auto
  Action::print_detailed_name (const T_Value& target_value) -> Glib::ustring
  {
    using type_glib_variant = Glib::Variant<T_Value>;

    g_return_val_if_fail (
        g_variant_type_equal (
            g_action_get_parameter_type (const_cast<GAction*> (gobj ())),
            type_glib_variant::variant_type ().gobj ()),
        Glib::ustring ());
    return print_detailed_name_variant (
        get_name (),
        type_glib_variant::create (target_value));
  }

  template <typename T_Value>
  void
  Action::change_state (const T_Value& value)
  {
    using type_glib_variant = Glib::Variant<T_Value>;

    g_return_if_fail (g_variant_type_equal (
        g_action_get_state_type (const_cast<GAction*> (gobj ())),
        type_glib_variant::variant_type ().gobj ()));

    change_state_variant (type_glib_variant::create (value));
  }

  template <typename T_Value>
  void
  Action::change_state (const Glib::Variant<T_Value>& value)
  {
    change_state_variant (value);
  }

  template <typename T_Value>
  void
  Action::activate (const T_Value& parameter)
  {
    using type_glib_variant = Glib::Variant<T_Value>;

    g_return_if_fail (g_variant_type_equal (
        g_action_get_parameter_type (const_cast<GAction*> (gobj ())),
        type_glib_variant::variant_type ().gobj ()));

    activate_variant (type_glib_variant::create (parameter));
  }

  template <typename T_Value>
  void
  Action::activate (const Glib::Variant<T_Value>& value)
  {
    activate_variant (value);
  }

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GAction* object, bool take_copy = false) -> Glib::RefPtr<Gio::Action>;

} // namespace Glib

#endif
