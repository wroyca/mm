// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/constraintguide.hxx>
#include <libmm/gtk/constraintguide_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkConstraintGuide* object, bool take_copy) -> glib::RefPtr<gtk::ConstraintGuide>
  {
    return glib::make_refptr_for_instance<gtk::ConstraintGuide> (
        dynamic_cast<gtk::ConstraintGuide*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  ConstraintGuide_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ConstraintGuide_Class::class_init_function;

      gtype_ = gtk_constraint_guide_get_type ();
    }

    return *this;
  }

  auto
  ConstraintGuide_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ConstraintGuide_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new ConstraintGuide ((GtkConstraintGuide*) object);
  }

  auto
  ConstraintGuide::gobj_copy () -> GtkConstraintGuide*
  {
    reference ();
    return gobj ();
  }

  ConstraintGuide::ConstraintGuide (
      const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  ConstraintGuide::ConstraintGuide (GtkConstraintGuide* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  ConstraintGuide::ConstraintGuide (ConstraintGuide&& src) noexcept
    : glib::Object (std::move (src)),
      ConstraintTarget (std::move (src))
  {
  }

  auto
  ConstraintGuide::operator= (ConstraintGuide&& src) noexcept -> ConstraintGuide&
  {
    glib::Object::operator= (std::move (src));
    ConstraintTarget::operator= (std::move (src));
    return *this;
  }

  ConstraintGuide::~ConstraintGuide () noexcept {}

  ConstraintGuide::CppClassType ConstraintGuide::constraintguide_class_;

  auto
  ConstraintGuide::get_type () -> GType
  {
    return constraintguide_class_.init ().get_type ();
  }

  auto
  ConstraintGuide::get_base_type () -> GType
  {
    return gtk_constraint_guide_get_type ();
  }

  ConstraintGuide::ConstraintGuide ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (constraintguide_class_.init ()))
  {
  }

  auto
  ConstraintGuide::create () -> glib::RefPtr<ConstraintGuide>
  {
    return glib::make_refptr_for_instance<ConstraintGuide> (
        new ConstraintGuide ());
  }

  auto
  ConstraintGuide::set_min_size (int width, int height) -> void
  {
    gtk_constraint_guide_set_min_size (gobj (), width, height);
  }

  auto
  ConstraintGuide::get_min_size (int& width, int& height) const -> void
  {
    gtk_constraint_guide_get_min_size (
        const_cast<GtkConstraintGuide*> (gobj ()),
        &(width),
        &(height));
  }

  auto
  ConstraintGuide::set_nat_size (int width, int height) -> void
  {
    gtk_constraint_guide_set_nat_size (gobj (), width, height);
  }

  auto
  ConstraintGuide::get_nat_size (int& width, int& height) const -> void
  {
    gtk_constraint_guide_get_nat_size (
        const_cast<GtkConstraintGuide*> (gobj ()),
        &(width),
        &(height));
  }

  auto
  ConstraintGuide::set_max_size (int width, int height) -> void
  {
    gtk_constraint_guide_set_max_size (gobj (), width, height);
  }

  auto
  ConstraintGuide::get_max_size (int& width, int& height) const -> void
  {
    gtk_constraint_guide_get_max_size (
        const_cast<GtkConstraintGuide*> (gobj ()),
        &(width),
        &(height));
  }

  auto
  ConstraintGuide::set_strength (Constraint::Strength strength) -> void
  {
    gtk_constraint_guide_set_strength (
        gobj (),
        static_cast<GtkConstraintStrength> (strength));
  }

  auto
  ConstraintGuide::get_strength () const -> Constraint::Strength
  {
    return static_cast<Constraint::Strength> (
        gtk_constraint_guide_get_strength (
            const_cast<GtkConstraintGuide*> (gobj ())));
  }

  auto
  ConstraintGuide::set_name (const glib::ustring& name) -> void
  {
    gtk_constraint_guide_set_name (gobj (), name.c_str ());
  }

  auto
  ConstraintGuide::get_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_constraint_guide_get_name (
            const_cast<GtkConstraintGuide*> (gobj ())));
  }

  auto
  ConstraintGuide::property_min_width () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "min-width");
  }

  auto
  ConstraintGuide::property_min_width () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "min-width");
  }

  auto
  ConstraintGuide::property_min_height () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "min-height");
  }

  auto
  ConstraintGuide::property_min_height () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "min-height");
  }

  auto
  ConstraintGuide::property_nat_width () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "nat-width");
  }

  auto
  ConstraintGuide::property_nat_width () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "nat-width");
  }

  auto
  ConstraintGuide::property_nat_height () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "nat-height");
  }

  auto
  ConstraintGuide::property_nat_height () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "nat-height");
  }

  auto
  ConstraintGuide::property_max_width () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "max-width");
  }

  auto
  ConstraintGuide::property_max_width () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "max-width");
  }

  auto
  ConstraintGuide::property_max_height () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "max-height");
  }

  auto
  ConstraintGuide::property_max_height () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "max-height");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          Constraint::Strength>::value,
      "Type Constraint::Strength cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ConstraintGuide::property_strength () -> glib::PropertyProxy<Constraint::Strength>
  {
    return glib::PropertyProxy<Constraint::Strength> (this, "strength");
  }

  auto
  ConstraintGuide::property_strength () const -> glib::PropertyProxy_ReadOnly<Constraint::Strength>
  {
    return glib::PropertyProxy_ReadOnly<Constraint::Strength> (this,
                                                               "strength");
  }

  auto
  ConstraintGuide::property_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "name");
  }

  auto
  ConstraintGuide::property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "name");
  }

} // namespace gtk
