// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/scale.hxx>
#include <libmm/gtk/scale_p.hxx>

#include <libmm/gtk/adjustment.hxx>

#include <cstring>
#include <gtk/gtk.h>
#include <math.h>
#include <memory>

using std::strlen;

namespace
{

  auto
  SignalProxy_Scale_format_value_callback (GtkScale*,
                                           double value,
                                           gpointer user_data) -> char*
  {
    auto the_slot = static_cast<gtk::Scale::SlotFormatValue*> (user_data);

    try
    {
      return g_strdup (((*the_slot) (value)).c_str ());
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
    }
    return g_strdup ("?");
  }

} // namespace

namespace gtk
{

  Scale::Scale (Orientation orientation)
    : glib::ObjectBase (nullptr),
      Range (glib::ConstructParams (scale_class_.init (),
                                    "orientation",
                                    (GtkOrientation) (orientation),
                                    nullptr))
  {
  }

  Scale::Scale (const glib::RefPtr<Adjustment>& adjustment,
                Orientation orientation)
    : glib::ObjectBase (nullptr),
      Range (glib::ConstructParams (scale_class_.init (),
                                    "adjustment",
                                    glib::unwrap (adjustment),
                                    "orientation",
                                    (GtkOrientation) (orientation),
                                    nullptr))
  {
  }

  auto
  Scale::set_format_value_func (const SlotFormatValue& slot) -> void
  {
    auto slot_copy = new SlotFormatValue (slot);

    gtk_scale_set_format_value_func (
        gobj (),
        &SignalProxy_Scale_format_value_callback,
        slot_copy,
        &glib::destroy_notify_delete<SlotFormatValue>);
  }

  auto
  Scale::unset_format_value_func () -> void
  {
    gtk_scale_set_format_value_func (gobj (), nullptr, nullptr, nullptr);
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkScale* object, bool take_copy) -> gtk::Scale*
  {
    return dynamic_cast<gtk::Scale*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  Scale_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Scale_Class::class_init_function;

      register_derived_type (gtk_scale_get_type ());
    }

    return *this;
  }

  auto
  Scale_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Scale_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Scale ((GtkScale*) (o)));
  }

  Scale::Scale (const glib::ConstructParams& construct_params)
    : gtk::Range (construct_params)
  {
  }

  Scale::Scale (GtkScale* castitem)
    : gtk::Range ((GtkRange*) (castitem))
  {
  }

  Scale::Scale (Scale&& src) noexcept
    : gtk::Range (std::move (src))
  {
  }

  auto
  Scale::operator= (Scale&& src) noexcept -> Scale&
  {
    gtk::Range::operator= (std::move (src));
    return *this;
  }

  Scale::~Scale () noexcept
  {
    destroy_ ();
  }

  Scale::CppClassType Scale::scale_class_;

  auto
  Scale::get_type () -> GType
  {
    return scale_class_.init ().get_type ();
  }

  auto
  Scale::get_base_type () -> GType
  {
    return gtk_scale_get_type ();
  }

  Scale::Scale ()
    : glib::ObjectBase (nullptr),
      gtk::Range (glib::ConstructParams (scale_class_.init ()))
  {
  }

  auto
  Scale::set_digits (int digits) -> void
  {
    gtk_scale_set_digits (gobj (), digits);
  }

  auto
  Scale::get_digits () const -> int
  {
    return gtk_scale_get_digits (const_cast<GtkScale*> (gobj ()));
  }

  auto
  Scale::set_draw_value (bool draw_value) -> void
  {
    gtk_scale_set_draw_value (gobj (), static_cast<int> (draw_value));
  }

  auto
  Scale::get_draw_value () const -> bool
  {
    return gtk_scale_get_draw_value (const_cast<GtkScale*> (gobj ()));
  }

  auto
  Scale::set_value_pos (PositionType pos) -> void
  {
    gtk_scale_set_value_pos (gobj (), static_cast<GtkPositionType> (pos));
  }

  auto
  Scale::get_value_pos () const -> PositionType
  {
    return static_cast<PositionType> (
        gtk_scale_get_value_pos (const_cast<GtkScale*> (gobj ())));
  }

  auto
  Scale::set_has_origin (bool has_origin) -> void
  {
    gtk_scale_set_has_origin (gobj (), static_cast<int> (has_origin));
  }

  auto
  Scale::get_has_origin () const -> bool
  {
    return gtk_scale_get_has_origin (const_cast<GtkScale*> (gobj ()));
  }

  auto
  Scale::get_layout () -> glib::RefPtr<pango::Layout>
  {
    auto retvalue = glib::wrap (gtk_scale_get_layout (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Scale::get_layout () const -> glib::RefPtr<const pango::Layout>
  {
    return const_cast<Scale*> (this)->get_layout ();
  }

  auto
  Scale::get_layout_offsets (int& x, int& y) const -> void
  {
    gtk_scale_get_layout_offsets (const_cast<GtkScale*> (gobj ()), &(x), &(y));
  }

  auto
  Scale::add_mark (double value,
                   PositionType position,
                   const glib::ustring& markup) -> void
  {
    gtk_scale_add_mark (gobj (),
                        value,
                        static_cast<GtkPositionType> (position),
                        markup.c_str ());
  }

  auto
  Scale::clear_marks () -> void
  {
    gtk_scale_clear_marks (gobj ());
  }

  auto
  Scale::property_digits () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "digits");
  }

  auto
  Scale::property_digits () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "digits");
  }

  auto
  Scale::property_draw_value () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "draw-value");
  }

  auto
  Scale::property_draw_value () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "draw-value");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<PositionType>::value,
      "Type PositionType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Scale::property_value_pos () -> glib::PropertyProxy<PositionType>
  {
    return glib::PropertyProxy<PositionType> (this, "value-pos");
  }

  auto
  Scale::property_value_pos () const -> glib::PropertyProxy_ReadOnly<PositionType>
  {
    return glib::PropertyProxy_ReadOnly<PositionType> (this, "value-pos");
  }

  auto
  Scale::property_has_origin () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "has-origin");
  }

  auto
  Scale::property_has_origin () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "has-origin");
  }

} // namespace gtk
