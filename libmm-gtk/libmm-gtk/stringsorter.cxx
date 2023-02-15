// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/stringsorter.hxx>
#include <libmm-gtk/stringsorter_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

auto
Glib::Value<Gtk::Collation>::value_type () -> GType
{
  return gtk_collation_get_type ();
}

namespace Glib
{

  auto
  wrap (GtkStringSorter* object, bool take_copy) -> Glib::RefPtr<Gtk::StringSorter>
  {
    return Glib::make_refptr_for_instance<Gtk::StringSorter> (
        dynamic_cast<Gtk::StringSorter*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  StringSorter_Class::init () -> const Glib::Class&
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
  StringSorter_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new StringSorter ((GtkStringSorter*) object);
  }

  auto
  StringSorter::gobj_copy () -> GtkStringSorter*
  {
    reference ();
    return gobj ();
  }

  StringSorter::StringSorter (const Glib::ConstructParams& construct_params)
    : Gtk::Sorter (construct_params)
  {
  }

  StringSorter::StringSorter (GtkStringSorter* castitem)
    : Gtk::Sorter ((GtkSorter*) (castitem))
  {
  }

  StringSorter::StringSorter (StringSorter&& src) noexcept
    : Gtk::Sorter (std::move (src))
  {
  }

  auto
  StringSorter::operator= (StringSorter&& src) noexcept -> StringSorter&
  {
    Gtk::Sorter::operator= (std::move (src));
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
      const Glib::RefPtr<Expression<Glib::ustring>>& expression)
    : Glib::ObjectBase (nullptr),
      Gtk::Sorter (Glib::ConstructParams (
          stringsorter_class_.init (),
          "expression",
          ((expression) ? (expression)->gobj () : nullptr),
          nullptr))
  {
  }

  auto
  StringSorter::create (
      const Glib::RefPtr<Expression<Glib::ustring>>& expression) -> Glib::RefPtr<StringSorter>
  {
    return Glib::make_refptr_for_instance<StringSorter> (
        new StringSorter (expression));
  }

  auto
  StringSorter::get_expression () -> Glib::RefPtr<Expression<Glib::ustring>>
  {
    auto retvalue =
        Glib::wrap<Glib::ustring> (gtk_string_sorter_get_expression (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  StringSorter::get_expression () const -> Glib::RefPtr<const Expression<Glib::ustring>>
  {
    auto retvalue =
        Glib::wrap<Glib::ustring> (gtk_string_sorter_get_expression (
            const_cast<GtkStringSorter*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  StringSorter::set_expression (
      const Glib::RefPtr<Expression<Glib::ustring>>& expression) -> void
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
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Expression<Glib::ustring>>>::value,
      "Type Glib::RefPtr<Expression<Glib::ustring>> cannot be used in "
      "_WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  StringSorter::property_expression () -> Glib::PropertyProxy<Glib::RefPtr<Expression<Glib::ustring>>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Expression<Glib::ustring>>> (
        this,
        "expression");
  }

  auto
  StringSorter::property_expression () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Expression<Glib::ustring>>>
  {
    return Glib::PropertyProxy_ReadOnly<
        Glib::RefPtr<Expression<Glib::ustring>>> (this, "expression");
  }

  auto
  StringSorter::property_ignore_case () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "ignore-case");
  }

  auto
  StringSorter::property_ignore_case () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "ignore-case");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Collation>::value,
      "Type Collation cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  StringSorter::property_collation () -> Glib::PropertyProxy<Collation>
  {
    return Glib::PropertyProxy<Collation> (this, "collation");
  }

  auto
  StringSorter::property_collation () const -> Glib::PropertyProxy_ReadOnly<Collation>
  {
    return Glib::PropertyProxy_ReadOnly<Collation> (this, "collation");
  }

} // namespace Gtk
