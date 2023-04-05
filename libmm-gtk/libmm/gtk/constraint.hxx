// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CONSTRAINT_H
#define _GTKMM_CONSTRAINT_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm/glib/object.hxx>
#include <libmm/gtk/constrainttarget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Constraint_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Constraint : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Constraint;
    using CppClassType = Constraint_Class;
    using BaseObjectType = GtkConstraint;
    using BaseClassType = GtkConstraintClass;

    Constraint (const Constraint&) = delete;
    auto
    operator= (const Constraint&) -> Constraint& = delete;

  private:
    friend class Constraint_Class;
    static CppClassType constraint_class_;

  protected:
    explicit Constraint (const glib::ConstructParams& construct_params);
    explicit Constraint (GtkConstraint* castitem);

#endif

  public:
    Constraint (Constraint&& src) noexcept;
    auto
    operator= (Constraint&& src) noexcept -> Constraint&;

    ~Constraint () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkConstraint*
    {
      return reinterpret_cast<GtkConstraint*> (gobject_);
    }

    auto
    gobj () const -> const GtkConstraint*
    {
      return reinterpret_cast<GtkConstraint*> (gobject_);
    }

    auto
    gobj_copy () -> GtkConstraint*;

  private:
  public:
    enum class Attribute
    {
      NONE,
      LEFT,
      RIGHT,
      TOP,
      BOTTOM,
      START,
      END,
      WIDTH,
      HEIGHT,
      CENTER_X,
      CENTER_Y,
      BASELINE
    };

    enum class Relation
    {
      LE = -1,
      EQ,
      GE
    };

    class Strength_Wrapper final
    {
    public:
      enum Strength
      {
        REQUIRED = 1001001000,
        STRONG = 1000000000,
        MEDIUM = 1000,
        WEAK = 1
      };
#ifndef DOXYGEN_SHOULD_SKIP_THIS
      Strength_Wrapper () = delete;
#endif
    };

    using Strength = Strength_Wrapper::Strength;

  protected:
    explicit Constraint (const glib::RefPtr<ConstraintTarget>& target,
                         Attribute target_attribute,
                         Relation relation,
                         const glib::RefPtr<ConstraintTarget>& source,
                         Attribute source_attribute,
                         double multiplier,
                         double constant,
                         int strength);

    explicit Constraint (const glib::RefPtr<ConstraintTarget>& target,
                         Attribute target_attribute,
                         Relation relation,
                         double constant,
                         int strength);

  public:
    static auto
    create (const glib::RefPtr<ConstraintTarget>& target,
            Attribute target_attribute,
            Relation relation,
            const glib::RefPtr<ConstraintTarget>& source,
            Attribute source_attribute,
            double multiplier,
            double constant,
            int strength) -> glib::RefPtr<Constraint>;

    static auto
    create (const glib::RefPtr<ConstraintTarget>& target,
            Attribute target_attribute,
            Relation relation,
            double constant,
            int strength) -> glib::RefPtr<Constraint>;

    auto
    get_target () -> glib::RefPtr<ConstraintTarget>;

    auto
    get_target () const -> glib::RefPtr<const ConstraintTarget>;

    auto
    get_target_attribute () const -> Attribute;

    auto
    get_source () -> glib::RefPtr<ConstraintTarget>;

    auto
    get_source () const -> glib::RefPtr<const ConstraintTarget>;

    auto
    get_source_attribute () const -> Attribute;

    auto
    get_relation () const -> Relation;

    auto
    get_multiplier () const -> double;

    auto
    get_constant () const -> double;

    auto
    get_strength () const -> int;

    auto
    is_required () const -> bool;

    auto
    is_attached () const -> bool;

    auto
    is_constant () const -> bool;

    auto
    property_target () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ConstraintTarget>>;

    auto
    property_target_attribute () const
        -> glib::PropertyProxy_ReadOnly<Attribute>;

    auto
    property_relation () const -> glib::PropertyProxy_ReadOnly<Relation>;

    auto
    property_source () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ConstraintTarget>>;

    auto
    property_source_attribute () const
        -> glib::PropertyProxy_ReadOnly<Attribute>;

    auto
    property_multiplier () const -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_constant () const -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_strength () const -> glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::Constraint::Attribute>
    : public glib::Value_Enum<gtk::Constraint::Attribute>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::Constraint::Relation>
    : public glib::Value_Enum<gtk::Constraint::Relation>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::Constraint::Strength>
    : public glib::Value_Enum<gtk::Constraint::Strength>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkConstraint* object, bool take_copy = false) -> glib::RefPtr<gtk::Constraint>;
} // namespace glib

#endif
