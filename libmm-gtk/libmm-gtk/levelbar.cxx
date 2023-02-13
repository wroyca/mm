


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/levelbar.hxx>
#include <libmm-gtk/levelbar_p.hxx>


/* Copyright (C) 2012 The gtkmm Development Team
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

using Mode = Gtk::LevelBar::Mode;

namespace
{


auto LevelBar_signal_offset_changed_callback (
  GtkLevelBar *self, const gchar *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::ustring&)>;

  const auto obj = dynamic_cast<LevelBar*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::convert_const_gchar_ptr_to_ustring(p0)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo LevelBar_signal_offset_changed_info =
{
  "offset_changed",
  (GCallback) &LevelBar_signal_offset_changed_callback,
  (GCallback) &LevelBar_signal_offset_changed_callback
};


} // anonymous namespace

// static
auto Glib::Value<Gtk::LevelBar::Mode>::value_type() -> GType
{
  return gtk_level_bar_mode_get_type();
}


namespace Glib
{

auto wrap(GtkLevelBar* object, const bool take_copy) -> Gtk::LevelBar*
{
  return dynamic_cast<Gtk::LevelBar *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto LevelBar_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &LevelBar_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_level_bar_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Orientable::add_interface(get_type());

  }

  return *this;
}


auto LevelBar_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto LevelBar_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new LevelBar((GtkLevelBar*)o));

}


/* The implementation: */

LevelBar::LevelBar(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

LevelBar::LevelBar(GtkLevelBar* castitem)
: Widget((GtkWidget*)castitem)
{
  }


LevelBar::LevelBar(LevelBar&& src) noexcept
: Widget(std::move(src))
  , Orientable(std::move(src))
{}

auto LevelBar::operator=(LevelBar&& src) noexcept -> LevelBar&
{
  Widget::operator=(std::move(src));
  Orientable::operator=(std::move(src));
  return *this;
}

LevelBar::~LevelBar() noexcept
{
  destroy_();
}

LevelBar::CppClassType LevelBar::levelbar_class_; // initialize static member

auto LevelBar::get_type() -> GType
{
  return levelbar_class_.init().get_type();
}


auto LevelBar::get_base_type() -> GType
{
  return gtk_level_bar_get_type();
}


LevelBar::LevelBar()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(levelbar_class_.init()))
{


}

auto LevelBar::set_mode (Mode mode) -> void
{
  gtk_level_bar_set_mode(gobj(), static_cast<GtkLevelBarMode>(mode));
}

auto LevelBar::get_mode() const -> Mode
{
  return static_cast<Mode>(gtk_level_bar_get_mode(const_cast<GtkLevelBar*>(gobj())));
}

auto LevelBar::set_value (
  const double value) -> void
{
  gtk_level_bar_set_value(gobj(), value);
}

auto LevelBar::get_value() const -> double
{
  return gtk_level_bar_get_value(const_cast<GtkLevelBar*>(gobj()));
}

auto LevelBar::set_min_value (
  const double value) -> void
{
  gtk_level_bar_set_min_value(gobj(), value);
}

auto LevelBar::get_min_value() const -> double
{
  return gtk_level_bar_get_min_value(const_cast<GtkLevelBar*>(gobj()));
}

auto LevelBar::set_max_value (
  const double value) -> void
{
  gtk_level_bar_set_max_value(gobj(), value);
}

auto LevelBar::get_max_value() const -> double
{
  return gtk_level_bar_get_max_value(const_cast<GtkLevelBar*>(gobj()));
}

auto LevelBar::set_inverted (
  const bool inverted) -> void
{
  gtk_level_bar_set_inverted(gobj(), inverted);
}

auto LevelBar::get_inverted() const -> bool
{
  return gtk_level_bar_get_inverted(const_cast<GtkLevelBar*>(gobj()));
}

auto LevelBar::add_offset_value (const Glib::ustring &name, const double value) -> void
{
  gtk_level_bar_add_offset_value(gobj(), name.c_str(), value);
}

auto LevelBar::remove_offset_value (const Glib::ustring &name) -> void
{
  gtk_level_bar_remove_offset_value(gobj(), name.c_str());
}

auto LevelBar::get_offset_value(const Glib::ustring& name, double& value) const -> bool
{
  return gtk_level_bar_get_offset_value(const_cast<GtkLevelBar*>(gobj()), name.c_str(), &value);
}


auto LevelBar::signal_offset_changed(const Glib::ustring& offset_name) -> Glib::SignalProxyDetailed<void(const Glib::ustring&)>
{
  return Glib::SignalProxyDetailed<void(const Glib::ustring&)>(this, &LevelBar_signal_offset_changed_info, offset_name);
}


auto LevelBar::property_value() -> Glib::PropertyProxy< double >
{
  return {this, "value"};
}

auto LevelBar::property_value() const -> Glib::PropertyProxy_ReadOnly< double >
{
  return {this, "value"};
}

auto LevelBar::property_min_value() -> Glib::PropertyProxy< double >
{
  return {this, "min-value"};
}

auto LevelBar::property_min_value() const -> Glib::PropertyProxy_ReadOnly< double >
{
  return {this, "min-value"};
}

auto LevelBar::property_max_value() -> Glib::PropertyProxy< double >
{
  return {this, "max-value"};
}

auto LevelBar::property_max_value() const -> Glib::PropertyProxy_ReadOnly< double >
{
  return {this, "max-value"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Mode>::value,
  "Type Mode cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto LevelBar::property_mode() -> Glib::PropertyProxy< Mode >
{
  return {this, "mode"};
}

auto LevelBar::property_mode() const -> Glib::PropertyProxy_ReadOnly< Mode >
{
  return {this, "mode"};
}

auto LevelBar::property_inverted() -> Glib::PropertyProxy< bool >
{
  return {this, "inverted"};
}

auto LevelBar::property_inverted() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "inverted"};
}


} // namespace Gtk

