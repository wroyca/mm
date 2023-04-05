// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/boolfilter.hxx>
#include <libmm/gtk/boolfilter_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkBoolFilter* object, bool take_copy) -> glib::RefPtr<gtk::BoolFilter>
  {
    return glib::make_refptr_for_instance<gtk::BoolFilter> (
        dynamic_cast<gtk::BoolFilter*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  BoolFilter_Class::init () -> const glib::Class&
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
  BoolFilter_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new BoolFilter ((GtkBoolFilter*) object);
  }

  auto
  BoolFilter::gobj_copy () -> GtkBoolFilter*
  {
    reference ();
    return gobj ();
  }

  BoolFilter::BoolFilter (const glib::ConstructParams& construct_params)
    : gtk::Filter (construct_params)
  {
  }

  BoolFilter::BoolFilter (GtkBoolFilter* castitem)
    : gtk::Filter ((GtkFilter*) (castitem))
  {
  }

  BoolFilter::BoolFilter (BoolFilter&& src) noexcept
    : gtk::Filter (std::move (src))
  {
  }

  auto
  BoolFilter::operator= (BoolFilter&& src) noexcept -> BoolFilter&
  {
    gtk::Filter::operator= (std::move (src));
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

  BoolFilter::BoolFilter (const glib::RefPtr<Expression<bool>>& expression)
    : glib::ObjectBase (nullptr),
      gtk::Filter (glib::ConstructParams (
          boolfilter_class_.init (),
          "expression",
          ((expression) ? (expression)->gobj () : nullptr),
          nullptr))
  {
  }

  auto
  BoolFilter::create (const glib::RefPtr<Expression<bool>>& expression) -> glib::RefPtr<BoolFilter>
  {
    return glib::make_refptr_for_instance<BoolFilter> (
        new BoolFilter (expression));
  }

  auto
  BoolFilter::get_expression () -> glib::RefPtr<Expression<bool>>
  {
    auto retvalue = glib::wrap<bool> (gtk_bool_filter_get_expression (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  BoolFilter::get_expression () const -> glib::RefPtr<const Expression<bool>>
  {
    auto retvalue = glib::wrap<bool> (
        gtk_bool_filter_get_expression (const_cast<GtkBoolFilter*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  BoolFilter::set_expression (const glib::RefPtr<Expression<bool>>& expression) -> void
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
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Expression<bool>>>::value,
      "Type glib::RefPtr<Expression<bool>> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  BoolFilter::property_expression () -> glib::PropertyProxy<glib::RefPtr<Expression<bool>>>
  {
    return glib::PropertyProxy<glib::RefPtr<Expression<bool>>> (this,
                                                                "expression");
  }

  auto
  BoolFilter::property_expression () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Expression<bool>>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Expression<bool>>> (
        this,
        "expression");
  }

  auto
  BoolFilter::property_invert () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "invert");
  }

  auto
  BoolFilter::property_invert () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "invert");
  }

} // namespace gtk
