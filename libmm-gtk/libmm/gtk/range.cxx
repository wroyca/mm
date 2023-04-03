// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/range.hxx>
#include <libmm/gtk/range_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gtk/adjustment.hxx>

namespace Gtk
{

  auto
  Range::unset_adjustment () -> void
  {
    gtk_range_set_adjustment (gobj (), nullptr);
  }

  auto
  Range_Class::get_range_border_vfunc_callback (GtkRange* self,
                                                GtkBorder* border) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          Gtk::Border cxx_border (border, true);
          obj->get_range_border_vfunc (cxx_border);
          *border = *(cxx_border.gobj ());
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->get_range_border)
      (*base->get_range_border) (self, border);
  }

  auto
  Range::get_range_rect () const -> Gdk::Rectangle
  {
    Gdk::Rectangle result;
    gtk_range_get_range_rect (const_cast<GtkRange*> (gobj ()), result.gobj ());
    return result;
  }

} // namespace Gtk

namespace
{

  static const Glib::SignalProxyInfo Range_signal_value_changed_info = {
      "value_changed",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  static auto
  Range_signal_adjust_bounds_callback (GtkRange* self, gdouble p0, void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (double)>;

    auto obj = dynamic_cast<Range*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo Range_signal_adjust_bounds_info = {
      "adjust_bounds",
      (GCallback) &Range_signal_adjust_bounds_callback,
      (GCallback) &Range_signal_adjust_bounds_callback};

  static auto
  Range_signal_move_slider_callback (GtkRange* self,
                                     GtkScrollType p0,
                                     void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (ScrollType)>;

    auto obj = dynamic_cast<Range*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (static_cast<ScrollType> (p0));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo Range_signal_move_slider_info = {
      "move_slider",
      (GCallback) &Range_signal_move_slider_callback,
      (GCallback) &Range_signal_move_slider_callback};

  static auto
  Range_signal_change_value_callback (GtkRange* self,
                                      GtkScrollType p0,
                                      gdouble p1,
                                      void* data) -> gboolean
  {
    using namespace Gtk;
    using SlotType = sigc::slot<bool (ScrollType, double)>;

    auto obj = dynamic_cast<Range*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> ((*static_cast<SlotType*> (
              slot)) (static_cast<ScrollType> (p0), p1));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static auto
  Range_signal_change_value_notify_callback (GtkRange* self,
                                             GtkScrollType p0,
                                             gdouble p1,
                                             void* data) -> gboolean
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (ScrollType, double)>;

    auto obj = dynamic_cast<Range*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (static_cast<ScrollType> (p0), p1);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const Glib::SignalProxyInfo Range_signal_change_value_info = {
      "change_value",
      (GCallback) &Range_signal_change_value_callback,
      (GCallback) &Range_signal_change_value_notify_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkRange* object, bool take_copy) -> Gtk::Range*
  {
    return dynamic_cast<Gtk::Range*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Range_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Range_Class::class_init_function;

      register_derived_type (gtk_range_get_type ());

      Orientable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  Range_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->get_range_border = &get_range_border_vfunc_callback;

    klass->value_changed = &value_changed_callback;
    klass->adjust_bounds = &adjust_bounds_callback;
    klass->move_slider = &move_slider_callback;
    klass->change_value = &change_value_callback;
  }

  auto
  Range_Class::value_changed_callback (GtkRange* self) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_value_changed ();
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->value_changed)
      (*base->value_changed) (self);
  }

  auto
  Range_Class::adjust_bounds_callback (GtkRange* self, gdouble p0) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_adjust_bounds (p0);
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->adjust_bounds)
      (*base->adjust_bounds) (self, p0);
  }

  auto
  Range_Class::move_slider_callback (GtkRange* self, GtkScrollType p0) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_move_slider (static_cast<ScrollType> (p0));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->move_slider)
      (*base->move_slider) (self, p0);
  }

  auto
  Range_Class::change_value_callback (GtkRange* self,
                                      GtkScrollType p0,
                                      gdouble p1) -> gboolean
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return static_cast<int> (
              obj->on_change_value (static_cast<ScrollType> (p0), p1));
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->change_value)
      return (*base->change_value) (self, p0, p1);

    using RType = gboolean;
    return RType ();
  }

  auto
  Range_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new Range ((GtkRange*) (o)));
  }

  Range::Range (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  Range::Range (GtkRange* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Range::Range (Range&& src) noexcept
    : Gtk::Widget (std::move (src)),
      Orientable (std::move (src))
  {
  }

  auto
  Range::operator= (Range&& src) noexcept -> Range&
  {
    Gtk::Widget::operator= (std::move (src));
    Orientable::operator= (std::move (src));
    return *this;
  }

  Range::~Range () noexcept
  {
    destroy_ ();
  }

  Range::CppClassType Range::range_class_;

  auto
  Range::get_type () -> GType
  {
    return range_class_.init ().get_type ();
  }

  auto
  Range::get_base_type () -> GType
  {
    return gtk_range_get_type ();
  }

  Range::Range ()
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (range_class_.init ()))
  {
  }

  auto
  Range::set_adjustment (const Glib::RefPtr<Adjustment>& adjustment) -> void
  {
    gtk_range_set_adjustment (gobj (), Glib::unwrap (adjustment));
  }

  auto
  Range::get_adjustment () -> Glib::RefPtr<Adjustment>
  {
    auto retvalue = Glib::wrap (gtk_range_get_adjustment (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Range::get_adjustment () const -> Glib::RefPtr<const Adjustment>
  {
    return const_cast<Range*> (this)->get_adjustment ();
  }

  auto
  Range::set_inverted (bool setting) -> void
  {
    gtk_range_set_inverted (gobj (), static_cast<int> (setting));
  }

  auto
  Range::get_inverted () const -> bool
  {
    return gtk_range_get_inverted (const_cast<GtkRange*> (gobj ()));
  }

  auto
  Range::set_flippable (bool flippable) -> void
  {
    gtk_range_set_flippable (gobj (), static_cast<int> (flippable));
  }

  auto
  Range::get_flippable () const -> bool
  {
    return gtk_range_get_flippable (const_cast<GtkRange*> (gobj ()));
  }

  auto
  Range::set_slider_size_fixed (bool size_fixed) -> void
  {
    gtk_range_set_slider_size_fixed (gobj (), static_cast<int> (size_fixed));
  }

  auto
  Range::get_slider_size_fixed () const -> bool
  {
    return gtk_range_get_slider_size_fixed (const_cast<GtkRange*> (gobj ()));
  }

  auto
  Range::get_slider_range (int& slider_start, int& slider_end) const -> void
  {
    gtk_range_get_slider_range (const_cast<GtkRange*> (gobj ()),
                                &(slider_start),
                                &(slider_end));
  }

  auto
  Range::set_increments (double step, double page) -> void
  {
    gtk_range_set_increments (gobj (), step, page);
  }

  auto
  Range::set_range (double min, double max) -> void
  {
    gtk_range_set_range (gobj (), min, max);
  }

  auto
  Range::set_value (double value) -> void
  {
    gtk_range_set_value (gobj (), value);
  }

  auto
  Range::get_value () const -> double
  {
    return gtk_range_get_value (const_cast<GtkRange*> (gobj ()));
  }

  auto
  Range::set_show_fill_level (bool show_fill_level) -> void
  {
    gtk_range_set_show_fill_level (gobj (), static_cast<int> (show_fill_level));
  }

  auto
  Range::get_show_fill_level () const -> bool
  {
    return gtk_range_get_show_fill_level (const_cast<GtkRange*> (gobj ()));
  }

  auto
  Range::set_restrict_to_fill_level (bool restrict_to_fill_level) -> void
  {
    gtk_range_set_restrict_to_fill_level (
        gobj (),
        static_cast<int> (restrict_to_fill_level));
  }

  auto
  Range::get_restrict_to_fill_level () const -> bool
  {
    return gtk_range_get_restrict_to_fill_level (
        const_cast<GtkRange*> (gobj ()));
  }

  auto
  Range::set_fill_level (double fill_level) -> void
  {
    gtk_range_set_fill_level (gobj (), fill_level);
  }

  auto
  Range::get_fill_level () const -> double
  {
    return gtk_range_get_fill_level (const_cast<GtkRange*> (gobj ()));
  }

  auto
  Range::set_round_digits (int round_digits) -> void
  {
    gtk_range_set_round_digits (gobj (), round_digits);
  }

  auto
  Range::get_round_digits () const -> int
  {
    return gtk_range_get_round_digits (const_cast<GtkRange*> (gobj ()));
  }

  auto
  Range::signal_value_changed () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this, &Range_signal_value_changed_info);
  }

  auto
  Range::signal_adjust_bounds () -> Glib::SignalProxy<void (double)>
  {
    return Glib::SignalProxy<void (double)> (this,
                                             &Range_signal_adjust_bounds_info);
  }

  auto
  Range::signal_move_slider () -> Glib::SignalProxy<void (ScrollType)>
  {
    return Glib::SignalProxy<void (ScrollType)> (
        this,
        &Range_signal_move_slider_info);
  }

  auto
  Range::signal_change_value () -> Glib::SignalProxy<bool (ScrollType, double)>
  {
    return Glib::SignalProxy<bool (ScrollType, double)> (
        this,
        &Range_signal_change_value_info);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Adjustment>>::value,
      "Type Glib::RefPtr<Adjustment> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Range::property_adjustment () -> Glib::PropertyProxy<Glib::RefPtr<Adjustment>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Adjustment>> (this, "adjustment");
  }

  auto
  Range::property_adjustment () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Adjustment>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Adjustment>> (
        this,
        "adjustment");
  }

  auto
  Range::property_inverted () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "inverted");
  }

  auto
  Range::property_inverted () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "inverted");
  }

  auto
  Range::property_show_fill_level () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "show-fill-level");
  }

  auto
  Range::property_show_fill_level () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "show-fill-level");
  }

  auto
  Range::property_restrict_to_fill_level () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "restrict-to-fill-level");
  }

  auto
  Range::property_restrict_to_fill_level () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "restrict-to-fill-level");
  }

  auto
  Range::property_fill_level () -> Glib::PropertyProxy<double>
  {
    return Glib::PropertyProxy<double> (this, "fill-level");
  }

  auto
  Range::property_fill_level () const -> Glib::PropertyProxy_ReadOnly<double>
  {
    return Glib::PropertyProxy_ReadOnly<double> (this, "fill-level");
  }

  auto
  Range::property_round_digits () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "round-digits");
  }

  auto
  Range::property_round_digits () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "round-digits");
  }

  auto
  Gtk::Range::on_value_changed () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->value_changed)
      (*base->value_changed) (gobj ());
  }

  auto
  Gtk::Range::on_adjust_bounds (double new_value) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->adjust_bounds)
      (*base->adjust_bounds) (gobj (), new_value);
  }

  auto
  Gtk::Range::on_move_slider (ScrollType scroll) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->move_slider)
      (*base->move_slider) (gobj (), static_cast<GtkScrollType> (scroll));
  }

  auto
  Gtk::Range::on_change_value (ScrollType scroll, double new_value) -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->change_value)
      return (*base->change_value) (gobj (),
                                    static_cast<GtkScrollType> (scroll),
                                    new_value);

    using RType = bool;
    return RType ();
  }

  auto
  Gtk::Range::get_range_border_vfunc (Gtk::Border& border) const -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->get_range_border)
    {
      (*base->get_range_border) (const_cast<GtkRange*> (gobj ()),
                                 border.gobj ());
    }
  }

} // namespace Gtk