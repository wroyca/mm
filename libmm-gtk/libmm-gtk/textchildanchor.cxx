// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/textchildanchor.hxx>
#include <libmm-gtk/textchildanchor_p.hxx>

#include <libmm-glib/vectorutils.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  auto
  TextChildAnchor::get_widgets () -> std::vector<Widget*>
  {
    guint len = 0;
    GtkWidget** widgets = gtk_text_child_anchor_get_widgets (gobj (), &len);
    return Glib::ArrayHandler<Widget*>::array_to_vector (
        widgets,
        len,
        Glib::OWNERSHIP_SHALLOW);
  }

  auto
  TextChildAnchor::get_widgets () const -> std::vector<const Widget*>
  {
    guint len = 0;
    GtkWidget** widgets = gtk_text_child_anchor_get_widgets (
        const_cast<GtkTextChildAnchor*> (gobj ()),
        &len);
    return Glib::ArrayHandler<const Widget*>::array_to_vector (
        widgets,
        len,
        Glib::OWNERSHIP_SHALLOW);
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkTextChildAnchor* object, bool take_copy) -> Glib::RefPtr<Gtk::TextChildAnchor>
  {
    return Glib::make_refptr_for_instance<Gtk::TextChildAnchor> (
        dynamic_cast<Gtk::TextChildAnchor*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  TextChildAnchor_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &TextChildAnchor_Class::class_init_function;

      register_derived_type (gtk_text_child_anchor_get_type ());
    }

    return *this;
  }

  auto
  TextChildAnchor_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  TextChildAnchor_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new TextChildAnchor ((GtkTextChildAnchor*) object);
  }

  auto
  TextChildAnchor::gobj_copy () -> GtkTextChildAnchor*
  {
    reference ();
    return gobj ();
  }

  TextChildAnchor::TextChildAnchor (
      const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  TextChildAnchor::TextChildAnchor (GtkTextChildAnchor* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  TextChildAnchor::TextChildAnchor (TextChildAnchor&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  TextChildAnchor::operator= (TextChildAnchor&& src) noexcept -> TextChildAnchor&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  TextChildAnchor::~TextChildAnchor () noexcept {}

  TextChildAnchor::CppClassType TextChildAnchor::textchildanchor_class_;

  auto
  TextChildAnchor::get_type () -> GType
  {
    return textchildanchor_class_.init ().get_type ();
  }

  auto
  TextChildAnchor::get_base_type () -> GType
  {
    return gtk_text_child_anchor_get_type ();
  }

  TextChildAnchor::TextChildAnchor ()
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (textchildanchor_class_.init ()))
  {
  }

  auto
  TextChildAnchor::create () -> Glib::RefPtr<TextChildAnchor>
  {
    return Glib::make_refptr_for_instance<TextChildAnchor> (
        new TextChildAnchor ());
  }

  auto
  TextChildAnchor::create (const Glib::ustring& replacement_character) -> Glib::RefPtr<TextChildAnchor>
  {
    return Glib::wrap (gtk_text_child_anchor_new_with_replacement (
        replacement_character.c_str ()));
  }

  auto
  TextChildAnchor::get_deleted () const -> bool
  {
    return gtk_text_child_anchor_get_deleted (
        const_cast<GtkTextChildAnchor*> (gobj ()));
  }

} // namespace Gtk
