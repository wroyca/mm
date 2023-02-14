// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_BINDING_H
#define _GLIBMM_BINDING_H

#include <libmm-glib/object.hxx>
#include <libmm-glib/refptr.hxx>
#include <libmm-glib/ustring.hxx>
#include <libmm-glib/value.hxx>

#include <optional>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GBinding = struct _GBinding;
using GBindingClass = struct _GBindingClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{
  class GLIBMM_API Binding_Class;
}
#endif

namespace Glib
{

  class GLIBMM_API Binding : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Binding;
    using CppClassType = Binding_Class;
    using BaseObjectType = GBinding;
    using BaseClassType = GBindingClass;

    Binding (const Binding&) = delete;
    auto
    operator= (const Binding&) -> Binding& = delete;

  private:
    friend class Binding_Class;
    static CppClassType binding_class_;

  protected:
    explicit Binding (const Glib::ConstructParams& construct_params);
    explicit Binding (GBinding* castitem);

#endif

  public:
    Binding (Binding&& src) noexcept;
    auto
    operator= (Binding&& src) noexcept -> Binding&;

    ~Binding () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GBinding*
    {
      return reinterpret_cast<GBinding*> (gobject_);
    }

    auto
    gobj () const -> const GBinding*
    {
      return reinterpret_cast<GBinding*> (gobject_);
    }

    auto
    gobj_copy () -> GBinding*;

  private:
  public:
    enum class Flags
    {
      DEFAULT = 0x0,
      BIDIRECTIONAL = 1 << 0,
      SYNC_CREATE = 1 << 1,
      INVERT_BOOLEAN = 1 << 2
    };

    using SlotTransform = sigc::slot<bool (const GValue*, GValue*)>;

    template <typename T_from, typename T_to>
    using SlotTypedTransform = sigc::slot<std::optional<T_to> (const T_from&)>;

    static auto
    bind_property_value (const PropertyProxy_Base& source_property,
                         const PropertyProxy_Base& target_property,
                         Flags flags = Flags::DEFAULT,
                         const SlotTransform& transform_to = {},
                         const SlotTransform& transform_from = {})
        -> Glib::RefPtr<Binding>;

    static auto
    bind_property (const PropertyProxy_Base& source_property,
                   const PropertyProxy_Base& target_property,
                   Flags flags = Flags::DEFAULT) -> Glib::RefPtr<Binding>
    {
      return bind_property_value (source_property, target_property, flags);
    }

    template <typename T_source, typename T_target, typename T_functor_to>
    static auto
    bind_property (const PropertyProxy<T_source>& source_property,
                   const PropertyProxy<T_target>& target_property,
                   Flags flags,
                   const T_functor_to& transform_to) -> Glib::RefPtr<Binding>
    {
      SlotTypedTransform<T_source, T_target> slot_transform_to = transform_to;

      return bind_property_value (
          source_property,
          target_property,
          flags,
          slot_transform_to.empty () ?
              SlotTransform () :
              TransformProp<T_source, T_target> (slot_transform_to));
    }

    template <typename T_source, typename T_target, typename T_functor_to>
    static auto
    bind_property (const PropertyProxy<T_source>& source_property,
                   const PropertyProxy_WriteOnly<T_target>& target_property,
                   Flags flags,
                   const T_functor_to& transform_to) -> Glib::RefPtr<Binding>
    {
      SlotTypedTransform<T_source, T_target> slot_transform_to = transform_to;

      return bind_property_value (
          source_property,
          target_property,
          flags,
          slot_transform_to.empty () ?
              SlotTransform () :
              TransformProp<T_source, T_target> (slot_transform_to));
    }

    template <typename T_source, typename T_target, typename T_functor_to>
    static auto
    bind_property (const PropertyProxy_ReadOnly<T_source>& source_property,
                   const PropertyProxy<T_target>& target_property,
                   Flags flags,
                   const T_functor_to& transform_to) -> Glib::RefPtr<Binding>
    {
      SlotTypedTransform<T_source, T_target> slot_transform_to = transform_to;

      return bind_property_value (
          source_property,
          target_property,
          flags,
          slot_transform_to.empty () ?
              SlotTransform () :
              TransformProp<T_source, T_target> (slot_transform_to));
    }

    template <typename T_source, typename T_target, typename T_functor_to>
    static auto
    bind_property (const PropertyProxy_ReadOnly<T_source>& source_property,
                   const PropertyProxy_WriteOnly<T_target>& target_property,
                   Flags flags,
                   const T_functor_to& transform_to) -> Glib::RefPtr<Binding>
    {
      SlotTypedTransform<T_source, T_target> slot_transform_to = transform_to;

      return bind_property_value (
          source_property,
          target_property,
          flags,
          slot_transform_to.empty () ?
              SlotTransform () :
              TransformProp<T_source, T_target> (slot_transform_to));
    }

    template <typename T_source,
              typename T_target,
              typename T_functor_to,
              typename T_functor_from>
    static auto
    bind_property (const PropertyProxy<T_source>& source_property,
                   const PropertyProxy<T_target>& target_property,
                   Flags flags,
                   const T_functor_to& transform_to,
                   const T_functor_from& transform_from)
        -> Glib::RefPtr<Binding>
    {
      SlotTypedTransform<T_source, T_target> slot_transform_from =
          transform_from;
      SlotTypedTransform<T_target, T_source> slot_transform_to = transform_to;

      return bind_property_value (
          source_property,
          target_property,
          flags,
          slot_transform_to.empty () ?
              SlotTransform () :
              TransformProp<T_source, T_target> (slot_transform_to),
          slot_transform_from.empty () ?
              SlotTransform () :
              TransformProp<T_target, T_source> (slot_transform_from));
    }

#ifndef GLIBMM_DISABLE_DEPRECATED

    auto
    get_source () -> Glib::ObjectBase*;
#endif

#ifndef GLIBMM_DISABLE_DEPRECATED

    auto
    get_source () const -> const Glib::ObjectBase*;
#endif

    auto
    dup_source () -> Glib::RefPtr<Glib::ObjectBase>;

    auto
    dup_source () const -> Glib::RefPtr<const Glib::ObjectBase>;

    auto
    get_source_property () const -> Glib::ustring;

#ifndef GLIBMM_DISABLE_DEPRECATED

    auto
    get_target () -> Glib::ObjectBase*;
#endif

#ifndef GLIBMM_DISABLE_DEPRECATED

    auto
    get_target () const -> const Glib::ObjectBase*;
#endif

    auto
    dup_target () -> Glib::RefPtr<Glib::ObjectBase>;

    auto
    dup_target () const -> Glib::RefPtr<const Glib::ObjectBase>;

    auto
    get_target_property () const -> Glib::ustring;

    auto
    get_flags () const -> Flags;

    void
    unbind ();

    auto
    property_flags () const -> Glib::PropertyProxy_ReadOnly<Flags>;

    auto
    property_source () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Glib::ObjectBase>>;

    auto
    property_source_property () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_target () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Glib::ObjectBase>>;

    auto
    property_target_property () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  private:
    template <typename T_from, typename T_to>
    class TransformProp
    {
    public:
      explicit TransformProp (const SlotTypedTransform<T_from, T_to>& slot)
        : typed_transform (slot)
      {
      }

#if __GNUC__ >= 10
      __attribute__ ((optimize (0)))
#endif
      auto
      operator() (const GValue* from_value, GValue* to_value) -> bool
      {
        Glib::Value<T_from> from_glib_value;
        from_glib_value.init (from_value);
        const auto to = typed_transform (from_glib_value.get ());

        if (!to.has_value ())
          return false;

        Glib::Value<T_to> to_glib_value;
        to_glib_value.init (to_value);
        to_glib_value.set (*to);
        g_value_copy (to_glib_value.gobj (), to_value);
        return true;
      }

    private:
      SlotTypedTransform<T_from, T_to> typed_transform;
    };

  public:
  public:
  protected:
  };

} // namespace Glib

namespace Glib
{

  inline auto
  operator| (Binding::Flags lhs, Binding::Flags rhs) -> Binding::Flags
  {
    return static_cast<Binding::Flags> (static_cast<unsigned> (lhs) |
                                        static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (Binding::Flags lhs, Binding::Flags rhs) -> Binding::Flags
  {
    return static_cast<Binding::Flags> (static_cast<unsigned> (lhs) &
                                        static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (Binding::Flags lhs, Binding::Flags rhs) -> Binding::Flags
  {
    return static_cast<Binding::Flags> (static_cast<unsigned> (lhs) ^
                                        static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(Binding::Flags flags) -> Binding::Flags
  {
    return static_cast<Binding::Flags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (Binding::Flags& lhs, Binding::Flags rhs) -> Binding::Flags&
  {
    return (lhs = static_cast<Binding::Flags> (static_cast<unsigned> (lhs) |
                                               static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (Binding::Flags& lhs, Binding::Flags rhs) -> Binding::Flags&
  {
    return (lhs = static_cast<Binding::Flags> (static_cast<unsigned> (lhs) &
                                               static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (Binding::Flags& lhs, Binding::Flags rhs) -> Binding::Flags&
  {
    return (lhs = static_cast<Binding::Flags> (static_cast<unsigned> (lhs) ^
                                               static_cast<unsigned> (rhs)));
  }
} // namespace Glib

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GLIBMM_API Value<Glib::Binding::Flags>
    : public Glib::Value_Flags<Glib::Binding::Flags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{

  GLIBMM_API
  auto
  wrap (GBinding* object, bool take_copy = false) -> Glib::RefPtr<Glib::Binding>;
} // namespace Glib

#endif
