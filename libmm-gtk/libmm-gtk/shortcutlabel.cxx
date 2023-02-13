


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/shortcutlabel.hpp>
#include <libmm-gtk/shortcutlabel_p.hpp>


/* Copyright (C) 2016 The gtkmm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>


namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkShortcutLabel* object, const bool take_copy) -> Gtk::ShortcutLabel*
{
  return dynamic_cast<Gtk::ShortcutLabel *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto ShortcutLabel_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ShortcutLabel_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_shortcut_label_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto ShortcutLabel_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ShortcutLabel_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new ShortcutLabel((GtkShortcutLabel*)o));

}


/* The implementation: */

ShortcutLabel::ShortcutLabel(const Glib::ConstructParams& construct_params)
:
  Widget(construct_params)
{
  }

ShortcutLabel::ShortcutLabel(GtkShortcutLabel* castitem)
:
  Widget((GtkWidget*)castitem)
{
  }


ShortcutLabel::ShortcutLabel(ShortcutLabel&& src) noexcept
: Widget(std::move(src))
{}

auto ShortcutLabel::operator=(ShortcutLabel&& src) noexcept -> ShortcutLabel&
{
  Widget::operator=(std::move(src));
  return *this;
}

ShortcutLabel::~ShortcutLabel() noexcept
{
  destroy_();
}

ShortcutLabel::CppClassType ShortcutLabel::shortcutlabel_class_; // initialize static member

auto ShortcutLabel::get_type() -> GType
{
  return shortcutlabel_class_.init().get_type();
}


auto ShortcutLabel::get_base_type() -> GType
{
  return gtk_shortcut_label_get_type();
}


ShortcutLabel::ShortcutLabel()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  Widget(Glib::ConstructParams(shortcutlabel_class_.init()))
{


}

ShortcutLabel::ShortcutLabel(const Glib::ustring& accelerator)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  Widget(Glib::ConstructParams(shortcutlabel_class_.init(), "accelerator", accelerator.c_str(), nullptr))
{


}

auto ShortcutLabel::get_accelerator() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_shortcut_label_get_accelerator(const_cast<GtkShortcutLabel*>(gobj())));
}

auto ShortcutLabel::set_accelerator (const Glib::ustring &accelerator) -> void
{
  gtk_shortcut_label_set_accelerator(gobj(), accelerator.c_str());
}

auto ShortcutLabel::get_disabled_text() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_shortcut_label_get_disabled_text(const_cast<GtkShortcutLabel*>(gobj())));
}

auto ShortcutLabel::set_disabled_text (const Glib::ustring &disabled_text) -> void
{
  gtk_shortcut_label_set_disabled_text(gobj(), disabled_text.c_str());
}


auto ShortcutLabel::property_accelerator() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "accelerator"};
}

auto ShortcutLabel::property_accelerator() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "accelerator"};
}

auto ShortcutLabel::property_disabled_text() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "disabled-text"};
}

auto ShortcutLabel::property_disabled_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "disabled-text"};
}


} // namespace Gtk


