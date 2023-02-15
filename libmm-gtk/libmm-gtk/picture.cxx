// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/picture.hxx>
#include <libmm-gtk/picture_p.hxx>

#include <gtk/gtk.h>

#include <gtk/gtk.h>

namespace Gtk
{

  Picture::Picture (const Glib::RefPtr<Gdk::Pixbuf>& pixbuf)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (picture_class_.init ()))
  {
    gtk_picture_set_pixbuf (gobj (), Glib::unwrap (pixbuf));
  }

  Picture::Picture (const std::string& filename)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (picture_class_.init ()))
  {
    gtk_picture_set_filename (gobj (), Glib::c_str_or_nullptr (filename));
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkPicture* object, bool take_copy) -> Gtk::Picture*
  {
    return dynamic_cast<Gtk::Picture*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Picture_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Picture_Class::class_init_function;

      gtype_ = gtk_picture_get_type ();
    }

    return *this;
  }

  auto
  Picture_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Picture_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new Picture ((GtkPicture*) (o)));
  }

  Picture::Picture (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  Picture::Picture (GtkPicture* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Picture::Picture (Picture&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  Picture::operator= (Picture&& src) noexcept -> Picture&
  {
    Gtk::Widget::operator= (std::move (src));
    return *this;
  }

  Picture::~Picture () noexcept
  {
    destroy_ ();
  }

  Picture::CppClassType Picture::picture_class_;

  auto
  Picture::get_type () -> GType
  {
    return picture_class_.init ().get_type ();
  }

  auto
  Picture::get_base_type () -> GType
  {
    return gtk_picture_get_type ();
  }

  Picture::Picture ()
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (picture_class_.init ()))
  {
  }

  Picture::Picture (const Glib::RefPtr<Gdk::Paintable>& paintable)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (picture_class_.init (),
                                          "paintable",
                                          Glib::unwrap (paintable),
                                          nullptr))
  {
  }

  Picture::Picture (const Glib::RefPtr<Gio::File>& file)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (
          picture_class_.init (),
          "file",
          const_cast<GFile*> (Glib::unwrap<Gio::File> (file)),
          nullptr))
  {
  }

  auto
  Picture::set_paintable (const Glib::RefPtr<Gdk::Paintable>& paintable) -> void
  {
    gtk_picture_set_paintable (gobj (), Glib::unwrap (paintable));
  }

  auto
  Picture::get_paintable () -> Glib::RefPtr<Gdk::Paintable>
  {
    auto retvalue = Glib::wrap (gtk_picture_get_paintable (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Picture::get_paintable () const -> Glib::RefPtr<const Gdk::Paintable>
  {
    return const_cast<Picture*> (this)->get_paintable ();
  }

  auto
  Picture::set_file (const Glib::RefPtr<const Gio::File>& file) -> void
  {
    gtk_picture_set_file (gobj (),
                          const_cast<GFile*> (Glib::unwrap<Gio::File> (file)));
  }

  auto
  Picture::get_file () -> Glib::RefPtr<Gio::File>
  {
    auto retvalue = Glib::wrap (gtk_picture_get_file (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Picture::get_file () const -> Glib::RefPtr<const Gio::File>
  {
    return const_cast<Picture*> (this)->get_file ();
  }

  auto
  Picture::set_filename (const std::string& filename) -> void
  {
    gtk_picture_set_filename (gobj (), filename.c_str ());
  }

  auto
  Picture::set_resource (const std::string& resource_path) -> void
  {
    gtk_picture_set_resource (gobj (), resource_path.c_str ());
  }

  auto
  Picture::set_pixbuf (const Glib::RefPtr<Gdk::Pixbuf>& pixbuf) -> void
  {
    gtk_picture_set_pixbuf (gobj (), Glib::unwrap (pixbuf));
  }

#ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  Picture::set_keep_aspect_ratio (bool keep_aspect_ratio) -> void
  {
    gtk_picture_set_keep_aspect_ratio (gobj (),
                                       static_cast<int> (keep_aspect_ratio));
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

#ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  Picture::get_keep_aspect_ratio () const -> bool
  {
    return gtk_picture_get_keep_aspect_ratio (
        const_cast<GtkPicture*> (gobj ()));
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

  auto
  Picture::set_can_shrink (bool can_shrink) -> void
  {
    gtk_picture_set_can_shrink (gobj (), static_cast<int> (can_shrink));
  }

  auto
  Picture::get_can_shrink () const -> bool
  {
    return gtk_picture_get_can_shrink (const_cast<GtkPicture*> (gobj ()));
  }

  auto
  Picture::set_content_fit (ContentFit content_fit) -> void
  {
    gtk_picture_set_content_fit (gobj (),
                                 static_cast<GtkContentFit> (content_fit));
  }

  auto
  Picture::get_content_fit () const -> ContentFit
  {
    return static_cast<ContentFit> (
        gtk_picture_get_content_fit (const_cast<GtkPicture*> (gobj ())));
  }

  auto
  Picture::set_alternative_text (const Glib::ustring& alternative_text) -> void
  {
    gtk_picture_set_alternative_text (
        gobj (),
        alternative_text.empty () ? nullptr : alternative_text.c_str ());
  }

  auto
  Picture::get_alternative_text () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_picture_get_alternative_text (const_cast<GtkPicture*> (gobj ())));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gdk::Paintable>>::value,
      "Type Glib::RefPtr<Gdk::Paintable> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Picture::property_paintable () -> Glib::PropertyProxy<Glib::RefPtr<Gdk::Paintable>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gdk::Paintable>> (this,
                                                              "paintable");
  }

  auto
  Picture::property_paintable () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Paintable>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Paintable>> (
        this,
        "paintable");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::File>>::value,
      "Type Glib::RefPtr<Gio::File> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Picture::property_file () -> Glib::PropertyProxy<Glib::RefPtr<Gio::File>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::File>> (this, "file");
  }

  auto
  Picture::property_file () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::File>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::File>> (this, "file");
  }

  auto
  Picture::property_alternative_text () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "alternative-text");
  }

  auto
  Picture::property_alternative_text () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this,
                                                        "alternative-text");
  }

#ifndef GTKMM_DISABLE_DEPRECATED

  auto
  Picture::property_keep_aspect_ratio () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "keep-aspect-ratio");
  }
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

  auto
  Picture::property_keep_aspect_ratio () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "keep-aspect-ratio");
  }
#endif

  auto
  Picture::property_can_shrink () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "can-shrink");
  }

  auto
  Picture::property_can_shrink () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "can-shrink");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<ContentFit>::value,
      "Type ContentFit cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Picture::property_content_fit () -> Glib::PropertyProxy<ContentFit>
  {
    return Glib::PropertyProxy<ContentFit> (this, "content-fit");
  }

  auto
  Picture::property_content_fit () const -> Glib::PropertyProxy_ReadOnly<ContentFit>
  {
    return Glib::PropertyProxy_ReadOnly<ContentFit> (this, "content-fit");
  }

} // namespace Gtk
