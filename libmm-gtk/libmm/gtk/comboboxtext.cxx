// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/comboboxtext.hxx>
  #include <libmm/gtk/comboboxtext_p.hxx>

  #include <gtk/gtk.h>

namespace Gtk
{

  ComboBoxText::ComboBoxText (bool has_entry)
    : Glib::ObjectBase (nullptr),
      ComboBox (Glib::ConstructParams (comboboxtext_class_.init (),
                                       "has-entry",
                                       gboolean (has_entry),
                                       nullptr))
  {
  }

  auto
  ComboBoxText::set_active_text (const Glib::ustring& text) -> void
  {
    auto model = get_model ();
    if (model)
    {
      auto enditer = model->children ().end ();
      for (auto iter = model->children ().begin (); iter != enditer; ++iter)
      {
        Glib::ustring this_text;
        iter->get_value (0, this_text);

        if (this_text == text)
        {
          set_active (iter);
          return;
        }
      }
    }

    unset_active ();
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkComboBoxText* object, bool take_copy) -> Gtk::ComboBoxText*
  {
    return dynamic_cast<Gtk::ComboBoxText*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ComboBoxText_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ComboBoxText_Class::class_init_function;

      register_derived_type (gtk_combo_box_text_get_type ());
    }

    return *this;
  }

  auto
  ComboBoxText_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ComboBoxText_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new ComboBoxText ((GtkComboBoxText*) (o)));
  }

  ComboBoxText::ComboBoxText (const Glib::ConstructParams& construct_params)
    : ComboBox (construct_params)
  {
  }

  ComboBoxText::ComboBoxText (GtkComboBoxText* castitem)
    : ComboBox ((GtkComboBox*) (castitem))
  {
  }

  ComboBoxText::ComboBoxText (ComboBoxText&& src) noexcept
    : ComboBox (std::move (src))
  {
  }

  auto
  ComboBoxText::operator= (ComboBoxText&& src) noexcept -> ComboBoxText&
  {
    ComboBox::operator= (std::move (src));
    return *this;
  }

  ComboBoxText::~ComboBoxText () noexcept
  {
    destroy_ ();
  }

  ComboBoxText::CppClassType ComboBoxText::comboboxtext_class_;

  auto
  ComboBoxText::get_type () -> GType
  {
    return comboboxtext_class_.init ().get_type ();
  }

  auto
  ComboBoxText::get_base_type () -> GType
  {
    return gtk_combo_box_text_get_type ();
  }

  auto
  ComboBoxText::append (const Glib::ustring& text) -> void
  {
    gtk_combo_box_text_append_text (gobj (), text.c_str ());
  }

  auto
  ComboBoxText::append (const Glib::ustring& id, const Glib::ustring& text) -> void
  {
    gtk_combo_box_text_append (gobj (), id.c_str (), text.c_str ());
  }

  auto
  ComboBoxText::insert (int position, const Glib::ustring& text) -> void
  {
    gtk_combo_box_text_insert_text (gobj (), position, text.c_str ());
  }

  auto
  ComboBoxText::insert (int position,
                        const Glib::ustring& id,
                        const Glib::ustring& text) -> void
  {
    gtk_combo_box_text_insert (gobj (), position, id.c_str (), text.c_str ());
  }

  auto
  ComboBoxText::prepend (const Glib::ustring& text) -> void
  {
    gtk_combo_box_text_prepend_text (gobj (), text.c_str ());
  }

  auto
  ComboBoxText::prepend (const Glib::ustring& id, const Glib::ustring& text) -> void
  {
    gtk_combo_box_text_prepend (gobj (), id.c_str (), text.c_str ());
  }

  auto
  ComboBoxText::remove_text (int position) -> void
  {
    gtk_combo_box_text_remove (gobj (), position);
  }

  auto
  ComboBoxText::get_active_text () const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        gtk_combo_box_text_get_active_text (
            const_cast<GtkComboBoxText*> (gobj ())));
  }

  auto
  ComboBoxText::remove_all () -> void
  {
    gtk_combo_box_text_remove_all (gobj ());
  }

} // namespace Gtk

#endif
