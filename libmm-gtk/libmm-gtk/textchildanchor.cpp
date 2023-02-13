


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/textchildanchor.hpp>
#include <mm/gtk/private/textchildanchor_p.hpp>


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

#include <mm/glib/vectorutils.hpp>

#include <gtk/gtk.h>

namespace Gtk
{

auto TextChildAnchor::get_widgets() -> std::vector<Widget*>
{
  guint len = 0;
  GtkWidget** widgets = gtk_text_child_anchor_get_widgets(gobj(), &len);
  return Glib::ArrayHandler<Widget*>::array_to_vector(
    widgets, len, Glib::OWNERSHIP_SHALLOW);
}

auto TextChildAnchor::get_widgets() const -> std::vector<const Widget*>
{
  guint len = 0;
  GtkWidget** widgets = gtk_text_child_anchor_get_widgets(
    const_cast<GtkTextChildAnchor*>(gobj()), &len);
  return Glib::ArrayHandler<const Widget*>::array_to_vector(
    widgets, len, Glib::OWNERSHIP_SHALLOW);
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkTextChildAnchor* object, const bool take_copy) -> RefPtr<Gtk::TextChildAnchor>
{
  return Glib::make_refptr_for_instance<Gtk::TextChildAnchor>( dynamic_cast<Gtk::TextChildAnchor*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto TextChildAnchor_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &TextChildAnchor_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_text_child_anchor_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto TextChildAnchor_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto TextChildAnchor_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new TextChildAnchor((GtkTextChildAnchor*)object);
}


/* The implementation: */

auto TextChildAnchor::gobj_copy() -> GtkTextChildAnchor*
{
  reference();
  return gobj();
}

TextChildAnchor::TextChildAnchor(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

TextChildAnchor::TextChildAnchor(GtkTextChildAnchor* castitem)
: Object((GObject*)castitem)
{}


TextChildAnchor::TextChildAnchor(TextChildAnchor&& src) noexcept
: Object(std::move(src))
{}

auto TextChildAnchor::operator=(TextChildAnchor&& src) noexcept -> TextChildAnchor&
{
  Object::operator=(std::move(src));
  return *this;
}


TextChildAnchor::~TextChildAnchor() noexcept = default;

TextChildAnchor::CppClassType TextChildAnchor::textchildanchor_class_; // initialize static member

auto TextChildAnchor::get_type() -> GType
{
  return textchildanchor_class_.init().get_type();
}


auto TextChildAnchor::get_base_type() -> GType
{
  return gtk_text_child_anchor_get_type();
}


TextChildAnchor::TextChildAnchor()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(textchildanchor_class_.init()))
{


}

auto TextChildAnchor::create() -> Glib::RefPtr<TextChildAnchor>
{
  return Glib::make_refptr_for_instance<TextChildAnchor>( new TextChildAnchor() );
}

auto TextChildAnchor::create(const Glib::ustring& replacement_character) -> Glib::RefPtr<TextChildAnchor>
{
  return Glib::wrap(gtk_text_child_anchor_new_with_replacement(replacement_character.c_str()));
}

auto TextChildAnchor::get_deleted() const -> bool
{
  return gtk_text_child_anchor_get_deleted(const_cast<GtkTextChildAnchor*>(gobj()));
}


} // namespace Gtk


