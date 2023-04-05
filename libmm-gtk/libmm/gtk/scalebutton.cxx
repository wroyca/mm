// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/scalebutton.hxx>
#include <libmm/gtk/scalebutton_p.hxx>

#include <libmm/glib/vectorutils.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  ScaleButton::ScaleButton (double min,
                            double max,
                            double step,
                            const std::vector<glib::ustring>& icons)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (
          scalebutton_class_.init (),
          "icons",
          glib::ArrayHandler<glib::ustring>::vector_to_array (icons).data (),
          nullptr,
          nullptr))
  {
    auto adjustment = Adjustment::create (min, min, max, step, 10 * step, 0);
    set_adjustment (adjustment);
  }

  ScaleButton::ScaleButton (double min, double max, double step)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (scalebutton_class_.init ()))
  {
    auto adjustment = Adjustment::create (min, min, max, step, 10 * step, 0);
    set_adjustment (adjustment);
  }

} // namespace gtk

namespace
{

  static auto
  ScaleButton_signal_value_changed_callback (GtkScaleButton* self,
                                             gdouble p0,
                                             void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (double)>;

    auto obj = dynamic_cast<ScaleButton*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo ScaleButton_signal_value_changed_info = {
      "value_changed",
      (GCallback) &ScaleButton_signal_value_changed_callback,
      (GCallback) &ScaleButton_signal_value_changed_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkScaleButton* object, bool take_copy) -> gtk::ScaleButton*
  {
    return dynamic_cast<gtk::ScaleButton*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  ScaleButton_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ScaleButton_Class::class_init_function;

      register_derived_type (gtk_scale_button_get_type ());

      Orientable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  ScaleButton_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->value_changed = &value_changed_callback;
  }

  auto
  ScaleButton_Class::value_changed_callback (GtkScaleButton* self, gdouble p0) -> void
  {
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_value_changed (p0);
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->value_changed)
      (*base->value_changed) (self, p0);
  }

  auto
  ScaleButton_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new ScaleButton ((GtkScaleButton*) (o)));
  }

  ScaleButton::ScaleButton (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  ScaleButton::ScaleButton (GtkScaleButton* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  ScaleButton::ScaleButton (ScaleButton&& src) noexcept
    : gtk::Widget (std::move (src)),
      Orientable (std::move (src))
  {
  }

  auto
  ScaleButton::operator= (ScaleButton&& src) noexcept -> ScaleButton&
  {
    gtk::Widget::operator= (std::move (src));
    Orientable::operator= (std::move (src));
    return *this;
  }

  ScaleButton::~ScaleButton () noexcept
  {
    destroy_ ();
  }

  ScaleButton::CppClassType ScaleButton::scalebutton_class_;

  auto
  ScaleButton::get_type () -> GType
  {
    return scalebutton_class_.init ().get_type ();
  }

  auto
  ScaleButton::get_base_type () -> GType
  {
    return gtk_scale_button_get_type ();
  }

  auto
  ScaleButton::set_icons (const std::vector<glib::ustring>& icons) -> void
  {
    gtk_scale_button_set_icons (
        gobj (),
        glib::ArrayHandler<glib::ustring>::vector_to_array (icons).data ());
  }

  auto
  ScaleButton::get_value () const -> double
  {
    return gtk_scale_button_get_value (const_cast<GtkScaleButton*> (gobj ()));
  }

  auto
  ScaleButton::set_value (double value) -> void
  {
    gtk_scale_button_set_value (gobj (), value);
  }

  auto
  ScaleButton::get_adjustment () -> glib::RefPtr<Adjustment>
  {
    auto retvalue = glib::wrap (gtk_scale_button_get_adjustment (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ScaleButton::get_adjustment () const -> glib::RefPtr<const Adjustment>
  {
    return const_cast<ScaleButton*> (this)->get_adjustment ();
  }

  auto
  ScaleButton::set_adjustment (const glib::RefPtr<Adjustment>& adjustment) -> void
  {
    gtk_scale_button_set_adjustment (gobj (), glib::unwrap (adjustment));
  }

  auto
  ScaleButton::get_plus_button () -> Button*
  {
    return glib::wrap (
        (GtkButton*) (gtk_scale_button_get_plus_button (gobj ())));
  }

  auto
  ScaleButton::get_plus_button () const -> const Button*
  {
    return const_cast<ScaleButton*> (this)->get_plus_button ();
  }

  auto
  ScaleButton::get_minus_button () -> Button*
  {
    return glib::wrap (
        (GtkButton*) (gtk_scale_button_get_minus_button (gobj ())));
  }

  auto
  ScaleButton::get_minus_button () const -> const Button*
  {
    return const_cast<ScaleButton*> (this)->get_minus_button ();
  }

  auto
  ScaleButton::get_popup () -> gtk::Widget*
  {
    return glib::wrap (gtk_scale_button_get_popup (gobj ()));
  }

  auto
  ScaleButton::get_popup () const -> const gtk::Widget*
  {
    return glib::wrap (
        gtk_scale_button_get_popup (const_cast<GtkScaleButton*> (gobj ())));
  }

  auto
  ScaleButton::signal_value_changed () -> glib::SignalProxy<void (double)>
  {
    return glib::SignalProxy<void (double)> (
        this,
        &ScaleButton_signal_value_changed_info);
  }

  auto
  ScaleButton::property_value () -> glib::PropertyProxy<double>
  {
    return glib::PropertyProxy<double> (this, "value");
  }

  auto
  ScaleButton::property_value () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return glib::PropertyProxy_ReadOnly<double> (this, "value");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Adjustment>>::value,
      "Type glib::RefPtr<Adjustment> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ScaleButton::property_adjustment () -> glib::PropertyProxy<glib::RefPtr<Adjustment>>
  {
    return glib::PropertyProxy<glib::RefPtr<Adjustment>> (this, "adjustment");
  }

  auto
  ScaleButton::property_adjustment () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Adjustment>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Adjustment>> (
        this,
        "adjustment");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          std::vector<glib::ustring>>::value,
      "Type std::vector<glib::ustring> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ScaleButton::property_icons () -> glib::PropertyProxy<std::vector<glib::ustring>>
  {
    return glib::PropertyProxy<std::vector<glib::ustring>> (this, "icons");
  }

  auto
  ScaleButton::property_icons () const -> glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>>
  {
    return glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>> (this,
                                                                     "icons");
  }

  auto
  gtk::ScaleButton::on_value_changed (double value) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->value_changed)
      (*base->value_changed) (gobj (), value);
  }

} // namespace gtk
