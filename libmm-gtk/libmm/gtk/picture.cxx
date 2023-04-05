// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/picture.hxx>
#include <libmm/gtk/picture_p.hxx>

#include <gtk/gtk.h>

#include <gtk/gtk.h>

namespace gtk
{

  Picture::Picture (const glib::RefPtr<gdk::Pixbuf>& pixbuf)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (picture_class_.init ()))
  {
    gtk_picture_set_pixbuf (gobj (), glib::unwrap (pixbuf));
  }

  Picture::Picture (const std::string& filename)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (picture_class_.init ()))
  {
    gtk_picture_set_filename (gobj (), glib::c_str_or_nullptr (filename));
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkPicture* object, bool take_copy) -> gtk::Picture*
  {
    return dynamic_cast<gtk::Picture*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  Picture_Class::init () -> const glib::Class&
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
  Picture_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Picture ((GtkPicture*) (o)));
  }

  Picture::Picture (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Picture::Picture (GtkPicture* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Picture::Picture (Picture&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  Picture::operator= (Picture&& src) noexcept -> Picture&
  {
    gtk::Widget::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (picture_class_.init ()))
  {
  }

  Picture::Picture (const glib::RefPtr<gdk::Paintable>& paintable)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (picture_class_.init (),
                                          "paintable",
                                          glib::unwrap (paintable),
                                          nullptr))
  {
  }

  Picture::Picture (const glib::RefPtr<gio::File>& file)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (
          picture_class_.init (),
          "file",
          const_cast<GFile*> (glib::unwrap<gio::File> (file)),
          nullptr))
  {
  }

  auto
  Picture::set_paintable (const glib::RefPtr<gdk::Paintable>& paintable) -> void
  {
    gtk_picture_set_paintable (gobj (), glib::unwrap (paintable));
  }

  auto
  Picture::get_paintable () -> glib::RefPtr<gdk::Paintable>
  {
    auto retvalue = glib::wrap (gtk_picture_get_paintable (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Picture::get_paintable () const -> glib::RefPtr<const gdk::Paintable>
  {
    return const_cast<Picture*> (this)->get_paintable ();
  }

  auto
  Picture::set_file (const glib::RefPtr<const gio::File>& file) -> void
  {
    gtk_picture_set_file (gobj (),
                          const_cast<GFile*> (glib::unwrap<gio::File> (file)));
  }

  auto
  Picture::get_file () -> glib::RefPtr<gio::File>
  {
    auto retvalue = glib::wrap (gtk_picture_get_file (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Picture::get_file () const -> glib::RefPtr<const gio::File>
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
  Picture::set_pixbuf (const glib::RefPtr<gdk::Pixbuf>& pixbuf) -> void
  {
    gtk_picture_set_pixbuf (gobj (), glib::unwrap (pixbuf));
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
  Picture::set_alternative_text (const glib::ustring& alternative_text) -> void
  {
    gtk_picture_set_alternative_text (
        gobj (),
        alternative_text.empty () ? nullptr : alternative_text.c_str ());
  }

  auto
  Picture::get_alternative_text () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_picture_get_alternative_text (const_cast<GtkPicture*> (gobj ())));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gdk::Paintable>>::value,
      "Type glib::RefPtr<gdk::Paintable> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Picture::property_paintable () -> glib::PropertyProxy<glib::RefPtr<gdk::Paintable>>
  {
    return glib::PropertyProxy<glib::RefPtr<gdk::Paintable>> (this,
                                                              "paintable");
  }

  auto
  Picture::property_paintable () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Paintable>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Paintable>> (
        this,
        "paintable");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::File>>::value,
      "Type glib::RefPtr<gio::File> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Picture::property_file () -> glib::PropertyProxy<glib::RefPtr<gio::File>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::File>> (this, "file");
  }

  auto
  Picture::property_file () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::File>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::File>> (this, "file");
  }

  auto
  Picture::property_alternative_text () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "alternative-text");
  }

  auto
  Picture::property_alternative_text () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this,
                                                        "alternative-text");
  }

#ifndef GTKMM_DISABLE_DEPRECATED

  auto
  Picture::property_keep_aspect_ratio () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "keep-aspect-ratio");
  }
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

  auto
  Picture::property_keep_aspect_ratio () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "keep-aspect-ratio");
  }
#endif

  auto
  Picture::property_can_shrink () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "can-shrink");
  }

  auto
  Picture::property_can_shrink () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "can-shrink");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<ContentFit>::value,
      "Type ContentFit cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Picture::property_content_fit () -> glib::PropertyProxy<ContentFit>
  {
    return glib::PropertyProxy<ContentFit> (this, "content-fit");
  }

  auto
  Picture::property_content_fit () const -> glib::PropertyProxy_ReadOnly<ContentFit>
  {
    return glib::PropertyProxy_ReadOnly<ContentFit> (this, "content-fit");
  }

} // namespace gtk
