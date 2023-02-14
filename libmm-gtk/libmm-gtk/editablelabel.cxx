// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/editablelabel.hxx>
#include <libmm-gtk/editablelabel_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkEditableLabel* object, const bool take_copy) -> Gtk::EditableLabel*
  {
    return dynamic_cast<Gtk::EditableLabel*> (
        wrap_auto ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  EditableLabel_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &EditableLabel_Class::class_init_function;

      gtype_ = gtk_editable_label_get_type ();
    }

    return *this;
  }

  auto
  EditableLabel_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  EditableLabel_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new EditableLabel ((GtkEditableLabel*) o));
  }

  EditableLabel::EditableLabel (const Glib::ConstructParams& construct_params)
    : Widget (construct_params)
  {
  }

  EditableLabel::EditableLabel (GtkEditableLabel* castitem)
    : Widget ((GtkWidget*) castitem)
  {
  }

  EditableLabel::EditableLabel (EditableLabel&& src) noexcept
    : Widget (std::move (src)),
      Editable (std::move (src))
  {
  }

  auto
  EditableLabel::operator= (EditableLabel&& src) noexcept -> EditableLabel&
  {
    Widget::operator= (std::move (src));
    Editable::operator= (std::move (src));
    return *this;
  }

  EditableLabel::~EditableLabel () noexcept
  {
    destroy_ ();
  }

  EditableLabel::CppClassType EditableLabel::editablelabel_class_;

  auto
  EditableLabel::get_type () -> GType
  {
    return editablelabel_class_.init ().get_type ();
  }

  auto
  EditableLabel::get_base_type () -> GType
  {
    return gtk_editable_label_get_type ();
  }

  EditableLabel::EditableLabel ()
    : ObjectBase (nullptr),
      Widget (Glib::ConstructParams (editablelabel_class_.init ()))
  {
  }

  EditableLabel::EditableLabel (const Glib::ustring& text)
    : ObjectBase (nullptr),
      Widget (Glib::ConstructParams (editablelabel_class_.init (),
                                     "text",
                                     text.c_str (),
                                     nullptr))
  {
  }

  auto
  EditableLabel::get_editing () const -> bool
  {
    return gtk_editable_label_get_editing (
        const_cast<GtkEditableLabel*> (gobj ()));
  }

  auto
  EditableLabel::start_editing () -> void
  {
    gtk_editable_label_start_editing (gobj ());
  }

  auto
  EditableLabel::stop_editing (const bool commit) -> void
  {
    gtk_editable_label_stop_editing (gobj (), commit);
  }

  auto
  EditableLabel::property_editing () -> Glib::PropertyProxy<bool>
  {
    return {this, "editing"};
  }

  auto
  EditableLabel::property_editing () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "editing"};
  }

} // namespace Gtk
