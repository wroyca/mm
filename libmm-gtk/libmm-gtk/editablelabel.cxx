


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/editablelabel.hxx>
#include <libmm-gtk/editablelabel_p.hxx>


/* Copyright (C) 2020 The gtkmm Development Team
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

auto wrap(GtkEditableLabel* object, const bool take_copy) -> Gtk::EditableLabel*
{
  return dynamic_cast<Gtk::EditableLabel *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto EditableLabel_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &EditableLabel_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_editable_label_get_type();

  }

  return *this;
}


auto EditableLabel_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto EditableLabel_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new EditableLabel((GtkEditableLabel*)o));

}


/* The implementation: */

EditableLabel::EditableLabel(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

EditableLabel::EditableLabel(GtkEditableLabel* castitem)
: Widget((GtkWidget*)castitem)
{
  }


EditableLabel::EditableLabel(EditableLabel&& src) noexcept
: Widget(std::move(src))
  , Editable(std::move(src))
{}

auto EditableLabel::operator=(EditableLabel&& src) noexcept -> EditableLabel&
{
  Widget::operator=(std::move(src));
  Editable::operator=(std::move(src));
  return *this;
}

EditableLabel::~EditableLabel() noexcept
{
  destroy_();
}

EditableLabel::CppClassType EditableLabel::editablelabel_class_; // initialize static member

auto EditableLabel::get_type() -> GType
{
  return editablelabel_class_.init().get_type();
}


auto EditableLabel::get_base_type() -> GType
{
  return gtk_editable_label_get_type();
}


EditableLabel::EditableLabel()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(editablelabel_class_.init()))
{


}

EditableLabel::EditableLabel(const Glib::ustring& text)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(editablelabel_class_.init(), "text", text.c_str(), nullptr))
{


}

auto EditableLabel::get_editing() const -> bool
{
  return gtk_editable_label_get_editing(const_cast<GtkEditableLabel*>(gobj()));
}

auto EditableLabel::start_editing () -> void
{
  gtk_editable_label_start_editing(gobj());
}

auto EditableLabel::stop_editing (
  const bool commit) -> void
{
  gtk_editable_label_stop_editing(gobj(), commit);
}


auto EditableLabel::property_editing() -> Glib::PropertyProxy< bool >
{
  return {this, "editing"};
}

auto EditableLabel::property_editing() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "editing"};
}


} // namespace Gtk

