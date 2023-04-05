// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/stringfilter.hxx>
#include <libmm/gtk/stringfilter_p.hxx>

#include <gtk/gtk.h>

using MatchMode = gtk::StringFilter::MatchMode;

namespace
{
}

auto
glib::Value<gtk::StringFilter::MatchMode>::value_type () -> GType
{
  return gtk_string_filter_match_mode_get_type ();
}

namespace glib
{

  auto
  wrap (GtkStringFilter* object, bool take_copy) -> glib::RefPtr<gtk::StringFilter>
  {
    return glib::make_refptr_for_instance<gtk::StringFilter> (
        dynamic_cast<gtk::StringFilter*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  StringFilter_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &StringFilter_Class::class_init_function;

      gtype_ = gtk_string_filter_get_type ();
    }

    return *this;
  }

  auto
  StringFilter_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  StringFilter_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new StringFilter ((GtkStringFilter*) object);
  }

  auto
  StringFilter::gobj_copy () -> GtkStringFilter*
  {
    reference ();
    return gobj ();
  }

  StringFilter::StringFilter (const glib::ConstructParams& construct_params)
    : gtk::Filter (construct_params)
  {
  }

  StringFilter::StringFilter (GtkStringFilter* castitem)
    : gtk::Filter ((GtkFilter*) (castitem))
  {
  }

  StringFilter::StringFilter (StringFilter&& src) noexcept
    : gtk::Filter (std::move (src))
  {
  }

  auto
  StringFilter::operator= (StringFilter&& src) noexcept -> StringFilter&
  {
    gtk::Filter::operator= (std::move (src));
    return *this;
  }

  StringFilter::~StringFilter () noexcept {}

  StringFilter::CppClassType StringFilter::stringfilter_class_;

  auto
  StringFilter::get_type () -> GType
  {
    return stringfilter_class_.init ().get_type ();
  }

  auto
  StringFilter::get_base_type () -> GType
  {
    return gtk_string_filter_get_type ();
  }

  StringFilter::StringFilter (
      const glib::RefPtr<Expression<glib::ustring>>& expression)
    : glib::ObjectBase (nullptr),
      gtk::Filter (glib::ConstructParams (
          stringfilter_class_.init (),
          "expression",
          ((expression) ? (expression)->gobj () : nullptr),
          nullptr))
  {
  }

  auto
  StringFilter::create (
      const glib::RefPtr<Expression<glib::ustring>>& expression) -> glib::RefPtr<StringFilter>
  {
    return glib::make_refptr_for_instance<StringFilter> (
        new StringFilter (expression));
  }

  auto
  StringFilter::get_search () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_string_filter_get_search (const_cast<GtkStringFilter*> (gobj ())));
  }

  auto
  StringFilter::set_search (const glib::ustring& search) -> void
  {
    gtk_string_filter_set_search (gobj (), search.c_str ());
  }

  auto
  StringFilter::get_expression () -> glib::RefPtr<Expression<glib::ustring>>
  {
    auto retvalue =
        glib::wrap<glib::ustring> (gtk_string_filter_get_expression (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  StringFilter::get_expression () const -> glib::RefPtr<const Expression<glib::ustring>>
  {
    auto retvalue =
        glib::wrap<glib::ustring> (gtk_string_filter_get_expression (
            const_cast<GtkStringFilter*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  StringFilter::set_expression (
      const glib::RefPtr<Expression<glib::ustring>>& expression) -> void
  {
    gtk_string_filter_set_expression (
        gobj (),
        ((expression) ? (expression)->gobj () : nullptr));
  }

  auto
  StringFilter::get_ignore_case () const -> bool
  {
    return gtk_string_filter_get_ignore_case (
        const_cast<GtkStringFilter*> (gobj ()));
  }

  auto
  StringFilter::set_ignore_case (bool ignore_case) -> void
  {
    gtk_string_filter_set_ignore_case (gobj (), static_cast<int> (ignore_case));
  }

  auto
  StringFilter::get_match_mode () const -> MatchMode
  {
    return static_cast<MatchMode> (gtk_string_filter_get_match_mode (
        const_cast<GtkStringFilter*> (gobj ())));
  }

  auto
  StringFilter::set_match_mode (MatchMode mode) -> void
  {
    gtk_string_filter_set_match_mode (
        gobj (),
        static_cast<GtkStringFilterMatchMode> (mode));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Expression<glib::ustring>>>::value,
      "Type glib::RefPtr<Expression<glib::ustring>> cannot be used in "
      "_WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  StringFilter::property_expression () -> glib::PropertyProxy<glib::RefPtr<Expression<glib::ustring>>>
  {
    return glib::PropertyProxy<glib::RefPtr<Expression<glib::ustring>>> (
        this,
        "expression");
  }

  auto
  StringFilter::property_expression () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Expression<glib::ustring>>>
  {
    return glib::PropertyProxy_ReadOnly<
        glib::RefPtr<Expression<glib::ustring>>> (this, "expression");
  }

  auto
  StringFilter::property_ignore_case () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "ignore-case");
  }

  auto
  StringFilter::property_ignore_case () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "ignore-case");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<MatchMode>::value,
      "Type MatchMode cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  StringFilter::property_match_mode () -> glib::PropertyProxy<MatchMode>
  {
    return glib::PropertyProxy<MatchMode> (this, "match-mode");
  }

  auto
  StringFilter::property_match_mode () const -> glib::PropertyProxy_ReadOnly<MatchMode>
  {
    return glib::PropertyProxy_ReadOnly<MatchMode> (this, "match-mode");
  }

  auto
  StringFilter::property_search () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "search");
  }

  auto
  StringFilter::property_search () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "search");
  }

} // namespace gtk
