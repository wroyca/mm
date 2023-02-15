// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/scale.hxx>
#include <libmm-gtk/scale_p.hxx>

#include <libmm-gtk/adjustment.hxx>

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
    auto the_slot = static_cast<Gtk::Scale::SlotFormatValue*> (user_data);

    try
    {
      return g_strdup (((*the_slot) (value)).c_str ());
    }
    catch (...)
    {
      Glib::exception_handlers_invoke ();
    }
    return g_strdup ("?");
  }

} // namespace

namespace Gtk
{

  Scale::Scale (Orientation orientation)
    : Glib::ObjectBase (nullptr),
      Range (Glib::ConstructParams (scale_class_.init (),
                                    "orientation",
                                    (GtkOrientation) (orientation),
                                    nullptr))
  {
  }

  Scale::Scale (const Glib::RefPtr<Adjustment>& adjustment,
                Orientation orientation)
    : Glib::ObjectBase (nullptr),
      Range (Glib::ConstructParams (scale_class_.init (),
                                    "adjustment",
                                    Glib::unwrap (adjustment),
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
        &Glib::destroy_notify_delete<SlotFormatValue>);
  }

  auto
  Scale::unset_format_value_func () -> void
  {
    gtk_scale_set_format_value_func (gobj (), nullptr, nullptr, nullptr);
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkScale* object, bool take_copy) -> Gtk::Scale*
  {
    return dynamic_cast<Gtk::Scale*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Scale_Class::init () -> const Glib::Class&
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
  Scale_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new Scale ((GtkScale*) (o)));
  }

  Scale::Scale (const Glib::ConstructParams& construct_params)
    : Gtk::Range (construct_params)
  {
  }

  Scale::Scale (GtkScale* castitem)
    : Gtk::Range ((GtkRange*) (castitem))
  {
  }

  Scale::Scale (Scale&& src) noexcept
    : Gtk::Range (std::move (src))
  {
  }

  auto
  Scale::operator= (Scale&& src) noexcept -> Scale&
  {
    Gtk::Range::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::Range (Glib::ConstructParams (scale_class_.init ()))
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
  Scale::get_layout () -> Glib::RefPtr<Pango::Layout>
  {
    auto retvalue = Glib::wrap (gtk_scale_get_layout (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Scale::get_layout () const -> Glib::RefPtr<const Pango::Layout>
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
                   const Glib::ustring& markup) -> void
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
  Scale::property_digits () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "digits");
  }

  auto
  Scale::property_digits () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "digits");
  }

  auto
  Scale::property_draw_value () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "draw-value");
  }

  auto
  Scale::property_draw_value () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "draw-value");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<PositionType>::value,
      "Type PositionType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Scale::property_value_pos () -> Glib::PropertyProxy<PositionType>
  {
    return Glib::PropertyProxy<PositionType> (this, "value-pos");
  }

  auto
  Scale::property_value_pos () const -> Glib::PropertyProxy_ReadOnly<PositionType>
  {
    return Glib::PropertyProxy_ReadOnly<PositionType> (this, "value-pos");
  }

  auto
  Scale::property_has_origin () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "has-origin");
  }

  auto
  Scale::property_has_origin () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "has-origin");
  }

} // namespace Gtk
