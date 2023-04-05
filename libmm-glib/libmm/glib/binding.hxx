// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_BINDING_H
#define _GLIBMM_BINDING_H

#include <libmm/glib/object.hxx>
#include <libmm/glib/refptr.hxx>
#include <libmm/glib/ustring.hxx>
#include <libmm/glib/value.hxx>

#include <optional>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GBinding = struct _GBinding;
using GBindingClass = struct _GBindingClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{
  class LIBMM_GLIB_SYMEXPORT Binding_Class;
}
#endif

namespace glib
{

  class LIBMM_GLIB_SYMEXPORT Binding : public glib::Object
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
    explicit Binding (const glib::ConstructParams& construct_params);
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
        -> glib::RefPtr<Binding>;

    static auto
    bind_property (const PropertyProxy_Base& source_property,
                   const PropertyProxy_Base& target_property,
                   Flags flags = Flags::DEFAULT) -> glib::RefPtr<Binding>
    {
      return bind_property_value (source_property, target_property, flags);
    }

    template <typename T_source, typename T_target, typename T_functor_to>
    static auto
    bind_property (const PropertyProxy<T_source>& source_property,
                   const PropertyProxy<T_target>& target_property,
                   Flags flags,
                   const T_functor_to& transform_to) -> glib::RefPtr<Binding>
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
                   const T_functor_to& transform_to) -> glib::RefPtr<Binding>
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
                   const T_functor_to& transform_to) -> glib::RefPtr<Binding>
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
                   const T_functor_to& transform_to) -> glib::RefPtr<Binding>
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
        -> glib::RefPtr<Binding>
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
    get_source () -> glib::ObjectBase*;
#endif

#ifndef GLIBMM_DISABLE_DEPRECATED

    auto
    get_source () const -> const glib::ObjectBase*;
#endif

    auto
    dup_source () -> glib::RefPtr<glib::ObjectBase>;

    auto
    dup_source () const -> glib::RefPtr<const glib::ObjectBase>;

    auto
    get_source_property () const -> glib::ustring;

#ifndef GLIBMM_DISABLE_DEPRECATED

    auto
    get_target () -> glib::ObjectBase*;
#endif

#ifndef GLIBMM_DISABLE_DEPRECATED

    auto
    get_target () const -> const glib::ObjectBase*;
#endif

    auto
    dup_target () -> glib::RefPtr<glib::ObjectBase>;

    auto
    dup_target () const -> glib::RefPtr<const glib::ObjectBase>;

    auto
    get_target_property () const -> glib::ustring;

    auto
    get_flags () const -> Flags;

    auto
    unbind () -> void;

    auto
    property_flags () const -> glib::PropertyProxy_ReadOnly<Flags>;

    auto
    property_source () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::ObjectBase>>;

    auto
    property_source_property () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_target () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::ObjectBase>>;

    auto
    property_target_property () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

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
        glib::Value<T_from> from_glib_value;
        from_glib_value.init (from_value);
        const auto to = typed_transform (from_glib_value.get ());

        if (!to.has_value ())
          return false;

        glib::Value<T_to> to_glib_value;
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

} // namespace glib

namespace glib
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
} // namespace glib

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GLIB_SYMEXPORT Value<glib::Binding::Flags>
    : public glib::Value_Flags<glib::Binding::Flags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace glib
{

  LIBMM_GLIB_SYMEXPORT
  auto
  wrap (GBinding* object, bool take_copy = false) -> glib::RefPtr<glib::Binding>;
} // namespace glib

#endif
