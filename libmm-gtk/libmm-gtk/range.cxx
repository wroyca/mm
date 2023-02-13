


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/range.hxx>
#include <libmm-gtk/range_p.hxx>


/* Copyright 1998-2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <gtk/gtk.h>
#include <libmm-gtk/adjustment.hxx>

namespace Gtk
{

auto Range::unset_adjustment () -> void
{
  gtk_range_set_adjustment(gobj(), nullptr);
}

auto Range_Class::get_range_border_vfunc_callback (GtkRange *self, GtkBorder *border) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        Border cxx_border(border, true);
        obj->get_range_border_vfunc(cxx_border);
        *border = *cxx_border.gobj();
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->get_range_border)
    (*base->get_range_border)(self, border);

}

auto Range::get_range_rect() const -> Gdk::Rectangle
{
  Gdk::Rectangle result;
  gtk_range_get_range_rect(const_cast<GtkRange*>(gobj()), result.gobj());
  return result;
}

} // namespace Gtk

namespace
{


const Glib::SignalProxyInfo Range_signal_value_changed_info =
{
  "value_changed",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


auto Range_signal_adjust_bounds_callback (GtkRange *self, const gdouble p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(double)>;

  const auto obj = dynamic_cast<Range*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo Range_signal_adjust_bounds_info =
{
  "adjust_bounds",
  (GCallback) &Range_signal_adjust_bounds_callback,
  (GCallback) &Range_signal_adjust_bounds_callback
};


auto Range_signal_move_slider_callback (GtkRange *self, GtkScrollType p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(ScrollType)>;

  const auto obj = dynamic_cast<Range*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(static_cast<ScrollType>(p0)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo Range_signal_move_slider_info =
{
  "move_slider",
  (GCallback) &Range_signal_move_slider_callback,
  (GCallback) &Range_signal_move_slider_callback
};


auto Range_signal_change_value_callback(GtkRange* self, GtkScrollType p0, const gdouble p1,void* data) -> gboolean
{
  using namespace Gtk;
  using SlotType = sigc::slot<bool(ScrollType, double)>;

  const auto obj = dynamic_cast<Range*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        return (*static_cast<SlotType*>(slot))(static_cast<ScrollType>(p0)
                                               , p1
        );
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }

  using RType = gboolean;
  return RType();
}

auto Range_signal_change_value_notify_callback(GtkRange* self, GtkScrollType p0, const gdouble p1, void* data) -> gboolean
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(ScrollType, double)>;

  const auto obj = dynamic_cast<Range*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(static_cast<ScrollType>(p0)
, p1
);
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }

  using RType = gboolean;
  return RType();
}

const Glib::SignalProxyInfo Range_signal_change_value_info =
{
  "change_value",
  (GCallback) &Range_signal_change_value_callback,
  (GCallback) &Range_signal_change_value_notify_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkRange* object, const bool take_copy) -> Gtk::Range*
{
  return dynamic_cast<Gtk::Range *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto Range_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Range_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_range_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Orientable::add_interface(get_type());

  }

  return *this;
}


auto Range_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

  klass->get_range_border = &get_range_border_vfunc_callback;

  klass->value_changed = &value_changed_callback;
  klass->adjust_bounds = &adjust_bounds_callback;
  klass->move_slider = &move_slider_callback;
  klass->change_value = &change_value_callback;
}


auto Range_Class::value_changed_callback (GtkRange *self) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_value_changed();
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->value_changed)
    (*base->value_changed)(self);
}
auto Range_Class::adjust_bounds_callback (GtkRange *self, const gdouble p0) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_adjust_bounds(p0
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->adjust_bounds)
    (*base->adjust_bounds)(self, p0);
}
auto Range_Class::move_slider_callback (GtkRange *self, GtkScrollType p0) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_move_slider(static_cast<ScrollType>(p0)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->move_slider)
    (*base->move_slider)(self, p0);
}
auto Range_Class::change_value_callback(GtkRange* self, GtkScrollType p0, const gdouble p1) -> gboolean
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return obj->on_change_value(static_cast<ScrollType>(p0)
                                    , p1
        );
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->change_value)
    return (*base->change_value)(self, p0, p1);

  using RType = gboolean;
  return RType();
}


auto Range_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new Range((GtkRange*)o));

}


/* The implementation: */

Range::Range(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

Range::Range(GtkRange* castitem)
: Widget((GtkWidget*)castitem)
{
  }


Range::Range(Range&& src) noexcept
: Widget(std::move(src))
  , Orientable(std::move(src))
{}

auto Range::operator=(Range&& src) noexcept -> Range&
{
  Widget::operator=(std::move(src));
  Orientable::operator=(std::move(src));
  return *this;
}

Range::~Range() noexcept
{
  destroy_();
}

Range::CppClassType Range::range_class_; // initialize static member

auto Range::get_type() -> GType
{
  return range_class_.init().get_type();
}


auto Range::get_base_type() -> GType
{
  return gtk_range_get_type();
}


Range::Range()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(range_class_.init()))
{


}

auto Range::set_adjustment (const Glib::RefPtr <Adjustment> &adjustment) -> void
{
  gtk_range_set_adjustment(gobj(), Glib::unwrap(adjustment));
}

auto Range::get_adjustment() -> Glib::RefPtr<Adjustment>
{
  auto retvalue = Glib::wrap(gtk_range_get_adjustment(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Range::get_adjustment() const -> Glib::RefPtr<const Adjustment>
{
  return const_cast<Range*>(this)->get_adjustment();
}

auto Range::set_inverted (
  const bool setting) -> void
{
  gtk_range_set_inverted(gobj(), setting);
}

auto Range::get_inverted() const -> bool
{
  return gtk_range_get_inverted(const_cast<GtkRange*>(gobj()));
}

auto Range::set_flippable (
  const bool flippable) -> void
{
  gtk_range_set_flippable(gobj(), flippable);
}

auto Range::get_flippable() const -> bool
{
  return gtk_range_get_flippable(const_cast<GtkRange*>(gobj()));
}

auto Range::set_slider_size_fixed (
  const bool size_fixed) -> void
{
  gtk_range_set_slider_size_fixed(gobj(), size_fixed);
}

auto Range::get_slider_size_fixed() const -> bool
{
  return gtk_range_get_slider_size_fixed(const_cast<GtkRange*>(gobj()));
}

auto Range::get_slider_range (int &slider_start, int &slider_end) const -> void
{
  gtk_range_get_slider_range(const_cast<GtkRange*>(gobj()), &slider_start, &slider_end);
}

auto Range::set_increments (
  const double step, const double page) -> void
{
  gtk_range_set_increments(gobj(), step, page);
}

auto Range::set_range (
  const double min, const double max) -> void
{
  gtk_range_set_range(gobj(), min, max);
}

auto Range::set_value (
  const double value) -> void
{
  gtk_range_set_value(gobj(), value);
}

auto Range::get_value() const -> double
{
  return gtk_range_get_value(const_cast<GtkRange*>(gobj()));
}

auto Range::set_show_fill_level (
  const bool show_fill_level) -> void
{
  gtk_range_set_show_fill_level(gobj(), show_fill_level);
}

auto Range::get_show_fill_level() const -> bool
{
  return gtk_range_get_show_fill_level(const_cast<GtkRange*>(gobj()));
}

auto Range::set_restrict_to_fill_level (
  const bool restrict_to_fill_level) -> void
{
  gtk_range_set_restrict_to_fill_level(gobj(), restrict_to_fill_level);
}

auto Range::get_restrict_to_fill_level() const -> bool
{
  return gtk_range_get_restrict_to_fill_level(const_cast<GtkRange*>(gobj()));
}

auto Range::set_fill_level (
  const double fill_level) -> void
{
  gtk_range_set_fill_level(gobj(), fill_level);
}

auto Range::get_fill_level() const -> double
{
  return gtk_range_get_fill_level(const_cast<GtkRange*>(gobj()));
}

auto Range::set_round_digits (
  const int round_digits) -> void
{
  gtk_range_set_round_digits(gobj(), round_digits);
}

auto Range::get_round_digits() const -> int
{
  return gtk_range_get_round_digits(const_cast<GtkRange*>(gobj()));
}


auto Range::signal_value_changed() -> Glib::SignalProxy<void()>
{
  return {this, &Range_signal_value_changed_info};
}


auto Range::signal_adjust_bounds() -> Glib::SignalProxy<void(double)>
{
  return {this, &Range_signal_adjust_bounds_info};
}


auto Range::signal_move_slider() -> Glib::SignalProxy<void(ScrollType)>
{
  return {this, &Range_signal_move_slider_info};
}


auto Range::signal_change_value() -> Glib::SignalProxy<bool(ScrollType, double)>
{
  return {this, &Range_signal_change_value_info};
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Adjustment>>::value,
  "Type Glib::RefPtr<Adjustment> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Range::property_adjustment() -> Glib::PropertyProxy< Glib::RefPtr<Adjustment> >
{
  return {this, "adjustment"};
}

auto Range::property_adjustment() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Adjustment> >
{
  return {this, "adjustment"};
}

auto Range::property_inverted() -> Glib::PropertyProxy< bool >
{
  return {this, "inverted"};
}

auto Range::property_inverted() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "inverted"};
}

auto Range::property_show_fill_level() -> Glib::PropertyProxy< bool >
{
  return {this, "show-fill-level"};
}

auto Range::property_show_fill_level() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "show-fill-level"};
}

auto Range::property_restrict_to_fill_level() -> Glib::PropertyProxy< bool >
{
  return {this, "restrict-to-fill-level"};
}

auto Range::property_restrict_to_fill_level() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "restrict-to-fill-level"};
}

auto Range::property_fill_level() -> Glib::PropertyProxy< double >
{
  return {this, "fill-level"};
}

auto Range::property_fill_level() const -> Glib::PropertyProxy_ReadOnly< double >
{
  return {this, "fill-level"};
}

auto Range::property_round_digits() -> Glib::PropertyProxy< int >
{
  return {this, "round-digits"};
}

auto Range::property_round_digits() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "round-digits"};
}


auto Range::on_value_changed () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->value_changed)
    (*base->value_changed)(gobj());
}
auto Range::on_adjust_bounds (
  const double new_value) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->adjust_bounds)
    (*base->adjust_bounds)(gobj(),new_value);
}
auto Range::on_move_slider (ScrollType scroll) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->move_slider)
    (*base->move_slider)(gobj(),static_cast<GtkScrollType>(scroll));
}
auto Range::on_change_value(ScrollType scroll, const double new_value) -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->change_value)
    return (*base->change_value)(gobj(),static_cast<GtkScrollType>(scroll),new_value);

  using RType = bool;
  return RType();
}

auto Range::get_range_border_vfunc (
  Border &border) const -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->get_range_border)
  {
    (*base->get_range_border)(const_cast<GtkRange*>(gobj()),border.gobj());
  }
}


} // namespace Gtk


