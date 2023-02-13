


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/comboboxtext.hpp>
#include <libmm-gtk/comboboxtext_p.hpp>


/*
 * Copyright 2010 The gtkmm Development Team
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

namespace Gtk
{

ComboBoxText::ComboBoxText(const bool has_entry)
:
  //The entry-text-column and id-column values are copied from gtk_combo_box_text_new():
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  ComboBox(Glib::ConstructParams(comboboxtext_class_.init(), "has-entry",gboolean(has_entry), nullptr))
{}

auto ComboBoxText::set_active_text (const Glib::ustring &text) -> void
{
  //Look for the row with this text, and activate it:
  const auto model = get_model();
  if(model)
  {
    const auto enditer = model->children().end();
    for(auto iter = model->children().begin(); iter != enditer; ++iter)
    {
      Glib::ustring this_text;
      iter->get_value(0, this_text);

      if(this_text == text)
      {
        set_active(iter);
        return; //success
      }
    }
  }

  //Not found, so mark it as blank:
  unset_active();
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkComboBoxText* object, const bool take_copy) -> Gtk::ComboBoxText*
{
  return dynamic_cast<Gtk::ComboBoxText *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto ComboBoxText_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ComboBoxText_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_combo_box_text_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto ComboBoxText_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ComboBoxText_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new ComboBoxText((GtkComboBoxText*)o));

}


/* The implementation: */

ComboBoxText::ComboBoxText(const Glib::ConstructParams& construct_params)
:
  ComboBox(construct_params)
{
  }

ComboBoxText::ComboBoxText(GtkComboBoxText* castitem)
:
  ComboBox((GtkComboBox*)castitem)
{
  }


ComboBoxText::ComboBoxText(ComboBoxText&& src) noexcept
: ComboBox(std::move(src))
{}

auto ComboBoxText::operator=(ComboBoxText&& src) noexcept -> ComboBoxText&
{
  ComboBox::operator=(std::move(src));
  return *this;
}

ComboBoxText::~ComboBoxText() noexcept
{
  destroy_();
}

ComboBoxText::CppClassType ComboBoxText::comboboxtext_class_; // initialize static member

auto ComboBoxText::get_type() -> GType
{
  return comboboxtext_class_.init().get_type();
}


auto ComboBoxText::get_base_type() -> GType
{
  return gtk_combo_box_text_get_type();
}


auto ComboBoxText::append (const Glib::ustring &text) -> void
{
  gtk_combo_box_text_append_text(gobj(), text.c_str());
}

auto ComboBoxText::append (const Glib::ustring &id, const Glib::ustring &text) -> void
{
  gtk_combo_box_text_append(gobj(), id.c_str(), text.c_str());
}

auto ComboBoxText::insert (
  const int position, const Glib::ustring &text) -> void
{
  gtk_combo_box_text_insert_text(gobj(), position, text.c_str());
}

auto ComboBoxText::insert (
  const int position, const Glib::ustring &id, const Glib::ustring &text) -> void
{
  gtk_combo_box_text_insert(gobj(), position, id.c_str(), text.c_str());
}

auto ComboBoxText::prepend (const Glib::ustring &text) -> void
{
  gtk_combo_box_text_prepend_text(gobj(), text.c_str());
}

auto ComboBoxText::prepend (const Glib::ustring &id, const Glib::ustring &text) -> void
{
  gtk_combo_box_text_prepend(gobj(), id.c_str(), text.c_str());
}

auto ComboBoxText::remove_text (
  const int position) -> void
{
  gtk_combo_box_text_remove(gobj(), position);
}

auto ComboBoxText::get_active_text() const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(gtk_combo_box_text_get_active_text(const_cast<GtkComboBoxText*>(gobj())));
}

auto ComboBoxText::remove_all () -> void
{
  gtk_combo_box_text_remove_all(gobj());
}


} // namespace Gtk


