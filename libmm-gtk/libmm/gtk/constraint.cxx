// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/constraint.hxx>
#include <libmm/gtk/constraint_p.hxx>

#include <gtk/gtk.h>

using Attribute = gtk::Constraint::Attribute;
using Relation = gtk::Constraint::Relation;

namespace
{
}

auto
glib::Value<gtk::Constraint::Attribute>::value_type () -> GType
{
  return gtk_constraint_attribute_get_type ();
}

auto
glib::Value<gtk::Constraint::Relation>::value_type () -> GType
{
  return gtk_constraint_relation_get_type ();
}

auto
glib::Value<gtk::Constraint::Strength>::value_type () -> GType
{
  return gtk_constraint_strength_get_type ();
}

namespace glib
{

  auto
  wrap (GtkConstraint* object, bool take_copy) -> glib::RefPtr<gtk::Constraint>
  {
    return glib::make_refptr_for_instance<gtk::Constraint> (
        dynamic_cast<gtk::Constraint*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  Constraint_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Constraint_Class::class_init_function;

      gtype_ = gtk_constraint_get_type ();
    }

    return *this;
  }

  auto
  Constraint_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Constraint_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Constraint ((GtkConstraint*) object);
  }

  auto
  Constraint::gobj_copy () -> GtkConstraint*
  {
    reference ();
    return gobj ();
  }

  Constraint::Constraint (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  Constraint::Constraint (GtkConstraint* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  Constraint::Constraint (Constraint&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  Constraint::operator= (Constraint&& src) noexcept -> Constraint&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  Constraint::~Constraint () noexcept {}

  Constraint::CppClassType Constraint::constraint_class_;

  auto
  Constraint::get_type () -> GType
  {
    return constraint_class_.init ().get_type ();
  }

  auto
  Constraint::get_base_type () -> GType
  {
    return gtk_constraint_get_type ();
  }

  Constraint::Constraint (const glib::RefPtr<ConstraintTarget>& target,
                          Attribute target_attribute,
                          Relation relation,
                          const glib::RefPtr<ConstraintTarget>& source,
                          Attribute source_attribute,
                          double multiplier,
                          double constant,
                          int strength)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (
          constraint_class_.init (),
          "target",
          glib::unwrap (target),
          "target_attribute",
          static_cast<GtkConstraintAttribute> (target_attribute),
          "relation",
          static_cast<GtkConstraintRelation> (relation),
          "source",
          glib::unwrap (source),
          "source_attribute",
          static_cast<GtkConstraintAttribute> (source_attribute),
          "multiplier",
          multiplier,
          "constant",
          constant,
          "strength",
          strength,
          nullptr))
  {
  }

  Constraint::Constraint (const glib::RefPtr<ConstraintTarget>& target,
                          Attribute target_attribute,
                          Relation relation,
                          double constant,
                          int strength)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (
          constraint_class_.init (),
          "target",
          glib::unwrap (target),
          "target_attribute",
          static_cast<GtkConstraintAttribute> (target_attribute),
          "relation",
          static_cast<GtkConstraintRelation> (relation),
          "constant",
          constant,
          "strength",
          strength,
          nullptr))
  {
  }

  auto
  Constraint::create (const glib::RefPtr<ConstraintTarget>& target,
                      Attribute target_attribute,
                      Relation relation,
                      const glib::RefPtr<ConstraintTarget>& source,
                      Attribute source_attribute,
                      double multiplier,
                      double constant,
                      int strength) -> glib::RefPtr<Constraint>
  {
    return glib::make_refptr_for_instance<Constraint> (
        new Constraint (target,
                        target_attribute,
                        relation,
                        source,
                        source_attribute,
                        multiplier,
                        constant,
                        strength));
  }

  auto
  Constraint::create (const glib::RefPtr<ConstraintTarget>& target,
                      Attribute target_attribute,
                      Relation relation,
                      double constant,
                      int strength) -> glib::RefPtr<Constraint>
  {
    return glib::make_refptr_for_instance<Constraint> (
        new Constraint (target,
                        target_attribute,
                        relation,
                        constant,
                        strength));
  }

  auto
  Constraint::get_target () -> glib::RefPtr<ConstraintTarget>
  {
    auto retvalue = glib::wrap (gtk_constraint_get_target (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Constraint::get_target () const -> glib::RefPtr<const ConstraintTarget>
  {
    return const_cast<Constraint*> (this)->get_target ();
  }

  auto
  Constraint::get_target_attribute () const -> Attribute
  {
    return static_cast<Attribute> (gtk_constraint_get_target_attribute (
        const_cast<GtkConstraint*> (gobj ())));
  }

  auto
  Constraint::get_source () -> glib::RefPtr<ConstraintTarget>
  {
    auto retvalue = glib::wrap (gtk_constraint_get_source (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Constraint::get_source () const -> glib::RefPtr<const ConstraintTarget>
  {
    return const_cast<Constraint*> (this)->get_source ();
  }

  auto
  Constraint::get_source_attribute () const -> Attribute
  {
    return static_cast<Attribute> (gtk_constraint_get_source_attribute (
        const_cast<GtkConstraint*> (gobj ())));
  }

  auto
  Constraint::get_relation () const -> Relation
  {
    return static_cast<Relation> (
        gtk_constraint_get_relation (const_cast<GtkConstraint*> (gobj ())));
  }

  auto
  Constraint::get_multiplier () const -> double
  {
    return gtk_constraint_get_multiplier (const_cast<GtkConstraint*> (gobj ()));
  }

  auto
  Constraint::get_constant () const -> double
  {
    return gtk_constraint_get_constant (const_cast<GtkConstraint*> (gobj ()));
  }

  auto
  Constraint::get_strength () const -> int
  {
    return gtk_constraint_get_strength (const_cast<GtkConstraint*> (gobj ()));
  }

  auto
  Constraint::is_required () const -> bool
  {
    return gtk_constraint_is_required (const_cast<GtkConstraint*> (gobj ()));
  }

  auto
  Constraint::is_attached () const -> bool
  {
    return gtk_constraint_is_attached (const_cast<GtkConstraint*> (gobj ()));
  }

  auto
  Constraint::is_constant () const -> bool
  {
    return gtk_constraint_is_constant (const_cast<GtkConstraint*> (gobj ()));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<ConstraintTarget>>::value,
      "Type glib::RefPtr<ConstraintTarget> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Constraint::property_target () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ConstraintTarget>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<ConstraintTarget>> (
        this,
        "target");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Attribute>::value,
      "Type Attribute cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Constraint::property_target_attribute () const -> glib::PropertyProxy_ReadOnly<Attribute>
  {
    return glib::PropertyProxy_ReadOnly<Attribute> (this, "target-attribute");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Relation>::value,
      "Type Relation cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Constraint::property_relation () const -> glib::PropertyProxy_ReadOnly<Relation>
  {
    return glib::PropertyProxy_ReadOnly<Relation> (this, "relation");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<ConstraintTarget>>::value,
      "Type glib::RefPtr<ConstraintTarget> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Constraint::property_source () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ConstraintTarget>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<ConstraintTarget>> (
        this,
        "source");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Attribute>::value,
      "Type Attribute cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Constraint::property_source_attribute () const -> glib::PropertyProxy_ReadOnly<Attribute>
  {
    return glib::PropertyProxy_ReadOnly<Attribute> (this, "source-attribute");
  }

  auto
  Constraint::property_multiplier () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return glib::PropertyProxy_ReadOnly<double> (this, "multiplier");
  }

  auto
  Constraint::property_constant () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return glib::PropertyProxy_ReadOnly<double> (this, "constant");
  }

  auto
  Constraint::property_strength () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "strength");
  }

} // namespace gtk
