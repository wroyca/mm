// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_ACTION_H
#define _GIOMM_ACTION_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gio/gio.h>
#include <libmm/glib/interface.hxx>
#include <libmm/glib/variant.hxx>
#include <libmm/glib/varianttype.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GActionInterface GActionInterface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GAction = struct _GAction;
using GActionClass = struct _GActionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT Action_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT Action : public glib::Interface
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

    explicit Action (const glib::Interface_Class& interface_class);

  public:
    explicit Action (GAction* castitem);

  protected:
#endif

  public:
    Action (Action&& src) noexcept;
    auto
    operator= (Action&& src) noexcept -> Action&;

    ~Action () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

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
    get_name () const -> glib::ustring;

    auto
    get_parameter_type () const -> glib::VariantType;

    auto
    get_state_type () const -> glib::VariantType;

    template <typename T_Value>
    auto
    get_state_hint (T_Value& value) const -> void;

    auto
    get_state_hint_variant () const -> glib::VariantContainerBase;

    auto
    get_enabled () const -> bool;

    template <typename T_Value>
    auto
    change_state (const T_Value& value) -> void;

    template <typename T_Value>
    auto
    change_state (const glib::Variant<T_Value>& value) -> void;

    auto
    change_state_variant (const glib::VariantBase& value) -> void;

    template <typename T_Value>
    auto
    get_state (T_Value& value) const -> void;

    auto
    get_state_variant () const -> glib::VariantBase;

    auto
    activate () -> void;

    template <typename T_Value>
    auto
    activate (const T_Value& parameter) -> void;

    template <typename T_Value>
    auto
    activate (const glib::Variant<T_Value>& parameter) -> void;

    auto
    activate_variant (const glib::VariantBase& parameter) -> void;

    static auto
    name_is_valid (const glib::ustring& action_name) -> bool;

    template <typename T_Value>
    static auto
    parse_detailed_name (const glib::ustring& detailed_name,
                         glib::ustring& action_name,
                         T_Value& target_value) -> void;

    static auto
    parse_detailed_name_variant (const glib::ustring& detailed_name,
                                 glib::ustring& action_name,
                                 glib::VariantBase& target_value) -> void;

    template <typename T_Value>
    auto
    print_detailed_name (const T_Value& target_value) -> glib::ustring;

    static auto
    print_detailed_name_variant (const glib::ustring& action_name,
                                 const glib::VariantBase& target_value)
        -> glib::ustring;

    auto
    property_enabled () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_parameter_type () const
        -> glib::PropertyProxy_ReadOnly<glib::VariantType>;

    auto
    property_state () const -> glib::PropertyProxy_ReadOnly<glib::VariantBase>;

    auto
    property_state_type () const
        -> glib::PropertyProxy_ReadOnly<glib::VariantType>;

  protected:
    virtual auto
    get_name_vfunc () const -> glib::ustring;

    virtual auto
    get_parameter_type_vfunc () const -> glib::VariantType;

    virtual auto
    get_state_type_vfunc () const -> glib::VariantType;

    virtual auto
    get_state_hint_vfunc () const -> glib::VariantBase;

    virtual auto
    get_enabled_vfunc () const -> bool;

    virtual auto
    get_state_vfunc () const -> glib::VariantBase;

    virtual auto
    change_state_vfunc (const glib::VariantBase& value) -> void;

    virtual auto
    activate_vfunc (const glib::VariantBase& parameter) -> void;

  public:
  public:
  protected:
  };

  template <typename T_Value>
  auto
  Action::get_state (T_Value& value) const -> void
  {
    value = T_Value ();

    using type_glib_variant = glib::Variant<T_Value>;

    g_return_if_fail (g_variant_type_equal (
        g_action_get_state_type (const_cast<GAction*> (gobj ())),
        type_glib_variant::variant_type ().gobj ()));

    const auto variantBase = get_state_variant ();
    const auto variantDerived =
        variantBase.cast_dynamic<type_glib_variant> (variantBase);
    value = variantDerived.get ();
  }

  template <typename T_Value>
  auto
  Action::get_state_hint (T_Value& value) const -> void
  {
    value = T_Value ();

    using type_glib_variant = glib::Variant<T_Value>;

    const auto variantBase = get_state_hint_variant ();

    g_return_if_fail (
        variantBase.is_of_type (type_glib_variant::variant_type ()));

    const auto variantDerived =
        variantBase.cast_dynamic<type_glib_variant> (variantBase);
    value = variantDerived.get ();
  }

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  template <typename T_Value>

  auto
  Action::parse_detailed_name (const glib::ustring& detailed_name,
                               glib::ustring& action_name,
                               T_Value& target_value) -> void
  {
    action_name.clear ();
    target_value = T_Value ();

    using type_glib_variant = glib::Variant<T_Value>;

    glib::VariantBase target_value_variantBase;
    parse_detailed_name_variant (detailed_name,
                                 action_name,
                                 target_value_variantBase);

    if (!target_value_variantBase)
      throw glib::VariantParseError (
          glib::VariantParseError::TYPE_ERROR,
          "Detailed action name '" + detailed_name +
              "' has no target. Expected a target of type " +
              type_glib_variant::variant_type ().get_string ());

    if (!target_value_variantBase.is_of_type (
            type_glib_variant::variant_type ()))
      throw glib::VariantParseError (
          glib::VariantParseError::TYPE_ERROR,
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
  Action::print_detailed_name (const T_Value& target_value) -> glib::ustring
  {
    using type_glib_variant = glib::Variant<T_Value>;

    g_return_val_if_fail (
        g_variant_type_equal (
            g_action_get_parameter_type (const_cast<GAction*> (gobj ())),
            type_glib_variant::variant_type ().gobj ()),
        glib::ustring ());
    return print_detailed_name_variant (
        get_name (),
        type_glib_variant::create (target_value));
  }

  template <typename T_Value>
  auto
  Action::change_state (const T_Value& value) -> void
  {
    using type_glib_variant = glib::Variant<T_Value>;

    g_return_if_fail (g_variant_type_equal (
        g_action_get_state_type (const_cast<GAction*> (gobj ())),
        type_glib_variant::variant_type ().gobj ()));

    change_state_variant (type_glib_variant::create (value));
  }

  template <typename T_Value>
  auto
  Action::change_state (const glib::Variant<T_Value>& value) -> void
  {
    change_state_variant (value);
  }

  template <typename T_Value>
  auto
  Action::activate (const T_Value& parameter) -> void
  {
    using type_glib_variant = glib::Variant<T_Value>;

    g_return_if_fail (g_variant_type_equal (
        g_action_get_parameter_type (const_cast<GAction*> (gobj ())),
        type_glib_variant::variant_type ().gobj ()));

    activate_variant (type_glib_variant::create (parameter));
  }

  template <typename T_Value>
  auto
  Action::activate (const glib::Variant<T_Value>& value) -> void
  {
    activate_variant (value);
  }

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GAction* object, bool take_copy = false) -> glib::RefPtr<gio::Action>;

} // namespace glib

#endif
