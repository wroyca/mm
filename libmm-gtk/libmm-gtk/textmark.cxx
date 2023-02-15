// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/textmark.hxx>
#include <libmm-gtk/textmark_p.hxx>

#include <gtk/gtk.h>
#include <libmm-gtk/textbuffer.hxx>
#include <libmm-gtk/textmark.hxx>

namespace Gtk
{

  TextMark::TextMark (bool left_gravity)
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (textmark_class_.init (),
                                           "left_gravity",
                                           gboolean (left_gravity),
                                           nullptr))
  {
  }

  auto
  TextMark::get_iter () -> TextIter
  {
    return get_buffer ()->get_iter_at_mark (gobj ());
  }

  auto
  TextMark::get_iter () const -> TextConstIter
  {
    return const_cast<TextMark*> (this)->get_iter ();
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkTextMark* object, bool take_copy) -> Glib::RefPtr<Gtk::TextMark>
  {
    return Glib::make_refptr_for_instance<Gtk::TextMark> (
        dynamic_cast<Gtk::TextMark*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  TextMark_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &TextMark_Class::class_init_function;

      register_derived_type (gtk_text_mark_get_type ());
    }

    return *this;
  }

  auto
  TextMark_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  TextMark_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new TextMark ((GtkTextMark*) object);
  }

  auto
  TextMark::gobj_copy () -> GtkTextMark*
  {
    reference ();
    return gobj ();
  }

  TextMark::TextMark (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  TextMark::TextMark (GtkTextMark* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  TextMark::TextMark (TextMark&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  TextMark::operator= (TextMark&& src) noexcept -> TextMark&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  TextMark::~TextMark () noexcept {}

  TextMark::CppClassType TextMark::textmark_class_;

  auto
  TextMark::get_type () -> GType
  {
    return textmark_class_.init ().get_type ();
  }

  auto
  TextMark::get_base_type () -> GType
  {
    return gtk_text_mark_get_type ();
  }

  TextMark::TextMark (const Glib::ustring& name, bool left_gravity)
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (textmark_class_.init (),
                                           "name",
                                           name.c_str (),
                                           "left_gravity",
                                           static_cast<int> (left_gravity),
                                           nullptr))
  {
  }

  auto
  TextMark::create (bool left_gravity) -> Glib::RefPtr<TextMark>
  {
    return Glib::make_refptr_for_instance<TextMark> (
        new TextMark (left_gravity));
  }

  auto
  TextMark::create (const Glib::ustring& name, bool left_gravity) -> Glib::RefPtr<TextMark>
  {
    return Glib::make_refptr_for_instance<TextMark> (
        new TextMark (name, left_gravity));
  }

  auto
  TextMark::set_visible (bool setting) -> void
  {
    gtk_text_mark_set_visible (gobj (), static_cast<int> (setting));
  }

  auto
  TextMark::get_visible () const -> bool
  {
    return gtk_text_mark_get_visible (const_cast<GtkTextMark*> (gobj ()));
  }

  auto
  TextMark::get_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_text_mark_get_name (const_cast<GtkTextMark*> (gobj ())));
  }

  auto
  TextMark::get_deleted () const -> bool
  {
    return gtk_text_mark_get_deleted (const_cast<GtkTextMark*> (gobj ()));
  }

  auto
  TextMark::get_buffer () -> Glib::RefPtr<TextBuffer>
  {
    auto retvalue = Glib::wrap (gtk_text_mark_get_buffer (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TextMark::get_buffer () const -> Glib::RefPtr<const TextBuffer>
  {
    return const_cast<TextMark*> (this)->get_buffer ();
  }

  auto
  TextMark::get_left_gravity () const -> bool
  {
    return gtk_text_mark_get_left_gravity (const_cast<GtkTextMark*> (gobj ()));
  }

  auto
  TextMark::property_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "name");
  }

  auto
  TextMark::property_left_gravity () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "left-gravity");
  }

} // namespace Gtk
