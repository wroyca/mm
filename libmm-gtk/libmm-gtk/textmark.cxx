

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/textmark.hxx>
#include <libmm-gtk/textmark_p.hxx>

#include <gtk/gtk.h>
#include <libmm-gtk/textbuffer.hxx>
#include <libmm-gtk/textmark.hxx>

namespace Gtk
{

  TextMark::TextMark (const bool left_gravity)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (textmark_class_.init (),
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
  wrap (GtkTextMark* object, const bool take_copy) -> RefPtr<Gtk::TextMark>
  {
    return Glib::make_refptr_for_instance<Gtk::TextMark> (
        dynamic_cast<Gtk::TextMark*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  TextMark_Class::init () -> const Class&
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
    : Object (construct_params)
  {
  }

  TextMark::TextMark (GtkTextMark* castitem)
    : Object ((GObject*) castitem)
  {
  }

  TextMark::TextMark (TextMark&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  TextMark::operator= (TextMark&& src) noexcept -> TextMark&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  TextMark::~TextMark () noexcept = default;

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

  TextMark::TextMark (const Glib::ustring& name, const bool left_gravity)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (textmark_class_.init (),
                                     "name",
                                     name.c_str (),
                                     "left_gravity",
                                     left_gravity,
                                     nullptr))
  {
  }

  auto
  TextMark::create (const bool left_gravity) -> Glib::RefPtr<TextMark>
  {
    return Glib::make_refptr_for_instance<TextMark> (
        new TextMark (left_gravity));
  }

  auto
  TextMark::create (const Glib::ustring& name, const bool left_gravity) -> Glib::RefPtr<TextMark>
  {
    return Glib::make_refptr_for_instance<TextMark> (
        new TextMark (name, left_gravity));
  }

  auto
  TextMark::set_visible (const bool setting) -> void
  {
    gtk_text_mark_set_visible (gobj (), setting);
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
    return {this, "name"};
  }

  auto
  TextMark::property_left_gravity () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "left-gravity"};
  }

} // namespace Gtk
