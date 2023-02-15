// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/boolfilter.hxx>
#include <libmm-gtk/boolfilter_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkBoolFilter* object, bool take_copy) -> Glib::RefPtr<Gtk::BoolFilter>
  {
    return Glib::make_refptr_for_instance<Gtk::BoolFilter> (
        dynamic_cast<Gtk::BoolFilter*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  BoolFilter_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &BoolFilter_Class::class_init_function;

      gtype_ = gtk_bool_filter_get_type ();
    }

    return *this;
  }

  auto
  BoolFilter_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  BoolFilter_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new BoolFilter ((GtkBoolFilter*) object);
  }

  auto
  BoolFilter::gobj_copy () -> GtkBoolFilter*
  {
    reference ();
    return gobj ();
  }

  BoolFilter::BoolFilter (const Glib::ConstructParams& construct_params)
    : Gtk::Filter (construct_params)
  {
  }

  BoolFilter::BoolFilter (GtkBoolFilter* castitem)
    : Gtk::Filter ((GtkFilter*) (castitem))
  {
  }

  BoolFilter::BoolFilter (BoolFilter&& src) noexcept
    : Gtk::Filter (std::move (src))
  {
  }

  auto
  BoolFilter::operator= (BoolFilter&& src) noexcept -> BoolFilter&
  {
    Gtk::Filter::operator= (std::move (src));
    return *this;
  }

  BoolFilter::~BoolFilter () noexcept {}

  BoolFilter::CppClassType BoolFilter::boolfilter_class_;

  auto
  BoolFilter::get_type () -> GType
  {
    return boolfilter_class_.init ().get_type ();
  }

  auto
  BoolFilter::get_base_type () -> GType
  {
    return gtk_bool_filter_get_type ();
  }

  BoolFilter::BoolFilter (const Glib::RefPtr<Expression<bool>>& expression)
    : Glib::ObjectBase (nullptr),
      Gtk::Filter (Glib::ConstructParams (
          boolfilter_class_.init (),
          "expression",
          ((expression) ? (expression)->gobj () : nullptr),
          nullptr))
  {
  }

  auto
  BoolFilter::create (const Glib::RefPtr<Expression<bool>>& expression) -> Glib::RefPtr<BoolFilter>
  {
    return Glib::make_refptr_for_instance<BoolFilter> (
        new BoolFilter (expression));
  }

  auto
  BoolFilter::get_expression () -> Glib::RefPtr<Expression<bool>>
  {
    auto retvalue = Glib::wrap<bool> (gtk_bool_filter_get_expression (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  BoolFilter::get_expression () const -> Glib::RefPtr<const Expression<bool>>
  {
    auto retvalue = Glib::wrap<bool> (
        gtk_bool_filter_get_expression (const_cast<GtkBoolFilter*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  BoolFilter::set_expression (const Glib::RefPtr<Expression<bool>>& expression) -> void
  {
    gtk_bool_filter_set_expression (
        gobj (),
        ((expression) ? (expression)->gobj () : nullptr));
  }

  auto
  BoolFilter::get_invert () const -> bool
  {
    return gtk_bool_filter_get_invert (const_cast<GtkBoolFilter*> (gobj ()));
  }

  auto
  BoolFilter::set_invert (bool invert) -> void
  {
    gtk_bool_filter_set_invert (gobj (), static_cast<int> (invert));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Expression<bool>>>::value,
      "Type Glib::RefPtr<Expression<bool>> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  BoolFilter::property_expression () -> Glib::PropertyProxy<Glib::RefPtr<Expression<bool>>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Expression<bool>>> (this,
                                                                "expression");
  }

  auto
  BoolFilter::property_expression () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Expression<bool>>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Expression<bool>>> (
        this,
        "expression");
  }

  auto
  BoolFilter::property_invert () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "invert");
  }

  auto
  BoolFilter::property_invert () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "invert");
  }

} // namespace Gtk
