// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/stringsorter.hxx>
#include <libmm/gtk/stringsorter_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

auto
glib::Value<gtk::Collation>::value_type () -> GType
{
  return gtk_collation_get_type ();
}

namespace glib
{

  auto
  wrap (GtkStringSorter* object, bool take_copy) -> glib::RefPtr<gtk::StringSorter>
  {
    return glib::make_refptr_for_instance<gtk::StringSorter> (
        dynamic_cast<gtk::StringSorter*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  StringSorter_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &StringSorter_Class::class_init_function;

      gtype_ = gtk_string_sorter_get_type ();
    }

    return *this;
  }

  auto
  StringSorter_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  StringSorter_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new StringSorter ((GtkStringSorter*) object);
  }

  auto
  StringSorter::gobj_copy () -> GtkStringSorter*
  {
    reference ();
    return gobj ();
  }

  StringSorter::StringSorter (const glib::ConstructParams& construct_params)
    : gtk::Sorter (construct_params)
  {
  }

  StringSorter::StringSorter (GtkStringSorter* castitem)
    : gtk::Sorter ((GtkSorter*) (castitem))
  {
  }

  StringSorter::StringSorter (StringSorter&& src) noexcept
    : gtk::Sorter (std::move (src))
  {
  }

  auto
  StringSorter::operator= (StringSorter&& src) noexcept -> StringSorter&
  {
    gtk::Sorter::operator= (std::move (src));
    return *this;
  }

  StringSorter::~StringSorter () noexcept {}

  StringSorter::CppClassType StringSorter::stringsorter_class_;

  auto
  StringSorter::get_type () -> GType
  {
    return stringsorter_class_.init ().get_type ();
  }

  auto
  StringSorter::get_base_type () -> GType
  {
    return gtk_string_sorter_get_type ();
  }

  StringSorter::StringSorter (
      const glib::RefPtr<Expression<glib::ustring>>& expression)
    : glib::ObjectBase (nullptr),
      gtk::Sorter (glib::ConstructParams (
          stringsorter_class_.init (),
          "expression",
          ((expression) ? (expression)->gobj () : nullptr),
          nullptr))
  {
  }

  auto
  StringSorter::create (
      const glib::RefPtr<Expression<glib::ustring>>& expression) -> glib::RefPtr<StringSorter>
  {
    return glib::make_refptr_for_instance<StringSorter> (
        new StringSorter (expression));
  }

  auto
  StringSorter::get_expression () -> glib::RefPtr<Expression<glib::ustring>>
  {
    auto retvalue =
        glib::wrap<glib::ustring> (gtk_string_sorter_get_expression (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  StringSorter::get_expression () const -> glib::RefPtr<const Expression<glib::ustring>>
  {
    auto retvalue =
        glib::wrap<glib::ustring> (gtk_string_sorter_get_expression (
            const_cast<GtkStringSorter*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  StringSorter::set_expression (
      const glib::RefPtr<Expression<glib::ustring>>& expression) -> void
  {
    gtk_string_sorter_set_expression (
        gobj (),
        ((expression) ? (expression)->gobj () : nullptr));
  }

  auto
  StringSorter::get_ignore_case () const -> bool
  {
    return gtk_string_sorter_get_ignore_case (
        const_cast<GtkStringSorter*> (gobj ()));
  }

  auto
  StringSorter::set_ignore_case (bool ignore_case) -> void
  {
    gtk_string_sorter_set_ignore_case (gobj (), static_cast<int> (ignore_case));
  }

  auto
  StringSorter::set_collation (Collation collation) -> void
  {
    gtk_string_sorter_set_collation (gobj (),
                                     static_cast<GtkCollation> (collation));
  }

  auto
  StringSorter::get_collation () const -> Collation
  {
    return static_cast<Collation> (gtk_string_sorter_get_collation (
        const_cast<GtkStringSorter*> (gobj ())));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Expression<glib::ustring>>>::value,
      "Type glib::RefPtr<Expression<glib::ustring>> cannot be used in "
      "_WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  StringSorter::property_expression () -> glib::PropertyProxy<glib::RefPtr<Expression<glib::ustring>>>
  {
    return glib::PropertyProxy<glib::RefPtr<Expression<glib::ustring>>> (
        this,
        "expression");
  }

  auto
  StringSorter::property_expression () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Expression<glib::ustring>>>
  {
    return glib::PropertyProxy_ReadOnly<
        glib::RefPtr<Expression<glib::ustring>>> (this, "expression");
  }

  auto
  StringSorter::property_ignore_case () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "ignore-case");
  }

  auto
  StringSorter::property_ignore_case () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "ignore-case");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Collation>::value,
      "Type Collation cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  StringSorter::property_collation () -> glib::PropertyProxy<Collation>
  {
    return glib::PropertyProxy<Collation> (this, "collation");
  }

  auto
  StringSorter::property_collation () const -> glib::PropertyProxy_ReadOnly<Collation>
  {
    return glib::PropertyProxy_ReadOnly<Collation> (this, "collation");
  }

} // namespace gtk
