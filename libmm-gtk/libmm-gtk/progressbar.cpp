


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/progressbar.hpp>
#include <libmm-gtk/progressbar_p.hpp>

#include <gtk/gtk.h>

/*
 * Copyright 1998-2002 The gtkmm Development Team
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

#include <libmm-gtk/adjustment.hpp>
#include <gtk/gtk.h>

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkProgressBar* object, const bool take_copy) -> Gtk::ProgressBar*
{
  return dynamic_cast<Gtk::ProgressBar *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto ProgressBar_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ProgressBar_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_progress_bar_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Orientable::add_interface(get_type());

  }

  return *this;
}


auto ProgressBar_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ProgressBar_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new ProgressBar((GtkProgressBar*)o));

}


/* The implementation: */

ProgressBar::ProgressBar(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

ProgressBar::ProgressBar(GtkProgressBar* castitem)
: Widget((GtkWidget*)castitem)
{
  }


ProgressBar::ProgressBar(ProgressBar&& src) noexcept
: Widget(std::move(src))
  , Orientable(std::move(src))
{}

auto ProgressBar::operator=(ProgressBar&& src) noexcept -> ProgressBar&
{
  Widget::operator=(std::move(src));
  Orientable::operator=(std::move(src));
  return *this;
}

ProgressBar::~ProgressBar() noexcept
{
  destroy_();
}

ProgressBar::CppClassType ProgressBar::progressbar_class_; // initialize static member

auto ProgressBar::get_type() -> GType
{
  return progressbar_class_.init().get_type();
}


auto ProgressBar::get_base_type() -> GType
{
  return gtk_progress_bar_get_type();
}


ProgressBar::ProgressBar()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(progressbar_class_.init()))
{


}

auto ProgressBar::pulse () -> void
{
  gtk_progress_bar_pulse(gobj());
}

auto ProgressBar::get_text() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_progress_bar_get_text(const_cast<GtkProgressBar*>(gobj())));
}

auto ProgressBar::set_text (const Glib::ustring &text) -> void
{
  gtk_progress_bar_set_text(gobj(), text.c_str());
}

auto ProgressBar::get_fraction() const -> double
{
  return gtk_progress_bar_get_fraction(const_cast<GtkProgressBar*>(gobj()));
}

auto ProgressBar::set_fraction (
  const double fraction) -> void
{
  gtk_progress_bar_set_fraction(gobj(), fraction);
}

auto ProgressBar::get_pulse_step() const -> double
{
  return gtk_progress_bar_get_pulse_step(const_cast<GtkProgressBar*>(gobj()));
}

auto ProgressBar::set_pulse_step (
  const double fraction) -> void
{
  gtk_progress_bar_set_pulse_step(gobj(), fraction);
}

auto ProgressBar::set_inverted (
  const bool inverted) -> void
{
  gtk_progress_bar_set_inverted(gobj(), inverted);
}

auto ProgressBar::get_inverted() const -> bool
{
  return gtk_progress_bar_get_inverted(const_cast<GtkProgressBar*>(gobj()));
}

auto ProgressBar::set_ellipsize (Pango::EllipsizeMode mode) -> void
{
  gtk_progress_bar_set_ellipsize(gobj(), static_cast<PangoEllipsizeMode>(mode));
}

auto ProgressBar::get_ellipsize() const -> Pango::EllipsizeMode
{
  return static_cast<Pango::EllipsizeMode>(gtk_progress_bar_get_ellipsize(const_cast<GtkProgressBar*>(gobj())));
}

auto ProgressBar::set_show_text (
  const bool show_text) -> void
{
  gtk_progress_bar_set_show_text(gobj(), show_text);
}

auto ProgressBar::get_show_text() const -> bool
{
  return gtk_progress_bar_get_show_text(const_cast<GtkProgressBar*>(gobj()));
}


auto ProgressBar::property_fraction() -> Glib::PropertyProxy< double >
{
  return {this, "fraction"};
}

auto ProgressBar::property_fraction() const -> Glib::PropertyProxy_ReadOnly< double >
{
  return {this, "fraction"};
}

auto ProgressBar::property_pulse_step() -> Glib::PropertyProxy< double >
{
  return {this, "pulse-step"};
}

auto ProgressBar::property_pulse_step() const -> Glib::PropertyProxy_ReadOnly< double >
{
  return {this, "pulse-step"};
}

auto ProgressBar::property_text() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "text"};
}

auto ProgressBar::property_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "text"};
}

auto ProgressBar::property_ellipsize() -> Glib::PropertyProxy< bool >
{
  return {this, "ellipsize"};
}

auto ProgressBar::property_ellipsize() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "ellipsize"};
}

auto ProgressBar::property_show_text() -> Glib::PropertyProxy< bool >
{
  return {this, "show-text"};
}

auto ProgressBar::property_show_text() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "show-text"};
}

auto ProgressBar::property_inverted() -> Glib::PropertyProxy< bool >
{
  return {this, "inverted"};
}

auto ProgressBar::property_inverted() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "inverted"};
}


} // namespace Gtk


