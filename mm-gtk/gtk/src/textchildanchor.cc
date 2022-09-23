// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gtkmm/textchildanchor.h>
#include <gtkmm/private/textchildanchor_p.h>


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

#include <glibmm/vectorutils.h>

#include <gtk/gtk.h>

namespace Gtk
{

std::vector<Widget*> TextChildAnchor::get_widgets()
{
  guint len = 0;
  GtkWidget** widgets = gtk_text_child_anchor_get_widgets(gobj(), &len);
  return Glib::ArrayHandler<Widget*>::array_to_vector(
    widgets, len, Glib::OWNERSHIP_SHALLOW);
}

std::vector<const Widget*> TextChildAnchor::get_widgets() const
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

Glib::RefPtr<Gtk::TextChildAnchor> wrap(GtkTextChildAnchor* object, bool take_copy)
{
  return Glib::make_refptr_for_instance<Gtk::TextChildAnchor>( dynamic_cast<Gtk::TextChildAnchor*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& TextChildAnchor_Class::init()
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


void TextChildAnchor_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* TextChildAnchor_Class::wrap_new(GObject* object)
{
  return new TextChildAnchor((GtkTextChildAnchor*)object);
}


/* The implementation: */

GtkTextChildAnchor* TextChildAnchor::gobj_copy()
{
  reference();
  return gobj();
}

TextChildAnchor::TextChildAnchor(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

TextChildAnchor::TextChildAnchor(GtkTextChildAnchor* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


TextChildAnchor::TextChildAnchor(TextChildAnchor&& src) noexcept
: Glib::Object(std::move(src))
{}

TextChildAnchor& TextChildAnchor::operator=(TextChildAnchor&& src) noexcept
{
  Glib::Object::operator=(std::move(src));
  return *this;
}


TextChildAnchor::~TextChildAnchor() noexcept
{}


TextChildAnchor::CppClassType TextChildAnchor::textchildanchor_class_; // initialize static member

GType TextChildAnchor::get_type()
{
  return textchildanchor_class_.init().get_type();
}


GType TextChildAnchor::get_base_type()
{
  return gtk_text_child_anchor_get_type();
}


TextChildAnchor::TextChildAnchor()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Glib::Object(Glib::ConstructParams(textchildanchor_class_.init()))
{
  

}

Glib::RefPtr<TextChildAnchor> TextChildAnchor::create()
{
  return Glib::make_refptr_for_instance<TextChildAnchor>( new TextChildAnchor() );
}

Glib::RefPtr<TextChildAnchor> TextChildAnchor::create(const Glib::ustring& replacement_character)
{
  return Glib::wrap(gtk_text_child_anchor_new_with_replacement(replacement_character.c_str()));
}

bool TextChildAnchor::get_deleted() const
{
  return gtk_text_child_anchor_get_deleted(const_cast<GtkTextChildAnchor*>(gobj()));
}


} // namespace Gtk


