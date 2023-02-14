

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/stringsorter.hxx>
#include <libmm-gtk/stringsorter_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkStringSorter* object, const bool take_copy) -> RefPtr<Gtk::StringSorter>
  {
    return Glib::make_refptr_for_instance<Gtk::StringSorter> (
        dynamic_cast<Gtk::StringSorter*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  StringSorter_Class::init () -> const Class&
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
    : Sorter (construct_params)
  {
  }

  StringSorter::StringSorter (GtkStringSorter* castitem)
    : Sorter ((GtkSorter*) castitem)
  {
  }

  StringSorter::StringSorter (StringSorter&& src) noexcept
    : Sorter (std::move (src))
  {
  }

  auto
  StringSorter::operator= (StringSorter&& src) noexcept -> StringSorter&
  {
    Sorter::operator= (std::move (src));
    return *this;
  }

  StringSorter::~StringSorter () noexcept = default;

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
    : ObjectBase (nullptr),
      Sorter (Glib::ConstructParams (stringsorter_class_.init (),
                                     "expression",
                                     expression ? expression->gobj () : nullptr,
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
        expression ? expression->gobj () : nullptr);
  }

  auto
  StringSorter::get_ignore_case () const -> bool
  {
    return gtk_string_sorter_get_ignore_case (
        const_cast<GtkStringSorter*> (gobj ()));
  }

  auto
  StringSorter::set_ignore_case (const bool ignore_case) -> void
  {
    gtk_string_sorter_set_ignore_case (gobj (), ignore_case);
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
    return {this, "expression"};
  }

  auto
  StringSorter::property_expression () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Expression<Glib::ustring>>>
  {
    return {this, "expression"};
  }

  auto
  StringSorter::property_ignore_case () -> Glib::PropertyProxy<bool>
  {
    return {this, "ignore-case"};
  }

  auto
  StringSorter::property_ignore_case () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "ignore-case"};
  }

} // namespace Gtk
