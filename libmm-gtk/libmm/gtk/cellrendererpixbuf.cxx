// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/cellrendererpixbuf.hxx>
  #include <libmm/gtk/cellrendererpixbuf_p.hxx>

  #include <gtk/gtk.h>

namespace gtk
{

  auto
  CellRendererPixbuf::_property_renderable () -> glib::PropertyProxy_Base
  {
    return property_pixbuf ();
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkCellRendererPixbuf* object, bool take_copy) -> gtk::CellRendererPixbuf*
  {
    return dynamic_cast<gtk::CellRendererPixbuf*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  CellRendererPixbuf_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &CellRendererPixbuf_Class::class_init_function;

      register_derived_type (gtk_cell_renderer_pixbuf_get_type ());
    }

    return *this;
  }

  auto
  CellRendererPixbuf_Class::class_init_function (void* g_class,
                                                 void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  CellRendererPixbuf_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new CellRendererPixbuf ((GtkCellRendererPixbuf*) (o)));
  }

  CellRendererPixbuf::CellRendererPixbuf (
      const glib::ConstructParams& construct_params)
    : gtk::CellRenderer (construct_params)
  {
  }

  CellRendererPixbuf::CellRendererPixbuf (GtkCellRendererPixbuf* castitem)
    : gtk::CellRenderer ((GtkCellRenderer*) (castitem))
  {
  }

  CellRendererPixbuf::CellRendererPixbuf (CellRendererPixbuf&& src) noexcept
    : gtk::CellRenderer (std::move (src))
  {
  }

  auto
  CellRendererPixbuf::operator= (CellRendererPixbuf&& src) noexcept -> CellRendererPixbuf&
  {
    gtk::CellRenderer::operator= (std::move (src));
    return *this;
  }

  CellRendererPixbuf::~CellRendererPixbuf () noexcept
  {
    destroy_ ();
  }

  CellRendererPixbuf::CppClassType
      CellRendererPixbuf::cellrendererpixbuf_class_;

  auto
  CellRendererPixbuf::get_type () -> GType
  {
    return cellrendererpixbuf_class_.init ().get_type ();
  }

  auto
  CellRendererPixbuf::get_base_type () -> GType
  {
    return gtk_cell_renderer_pixbuf_get_type ();
  }

  CellRendererPixbuf::CellRendererPixbuf ()
    : glib::ObjectBase (nullptr),
      gtk::CellRenderer (
          glib::ConstructParams (cellrendererpixbuf_class_.init ()))
  {
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gdk::Pixbuf>>::value,
      "Type glib::RefPtr<gdk::Pixbuf> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CellRendererPixbuf::property_pixbuf () -> glib::PropertyProxy_WriteOnly<glib::RefPtr<gdk::Pixbuf>>
  {
    return glib::PropertyProxy_WriteOnly<glib::RefPtr<gdk::Pixbuf>> (this,
                                                                     "pixbuf");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gdk::Pixbuf>>::value,
      "Type glib::RefPtr<gdk::Pixbuf> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CellRendererPixbuf::property_pixbuf_expander_open () -> glib::PropertyProxy<glib::RefPtr<gdk::Pixbuf>>
  {
    return glib::PropertyProxy<glib::RefPtr<gdk::Pixbuf>> (
        this,
        "pixbuf-expander-open");
  }

  auto
  CellRendererPixbuf::property_pixbuf_expander_open () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Pixbuf>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Pixbuf>> (
        this,
        "pixbuf-expander-open");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gdk::Pixbuf>>::value,
      "Type glib::RefPtr<gdk::Pixbuf> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CellRendererPixbuf::property_pixbuf_expander_closed () -> glib::PropertyProxy<glib::RefPtr<gdk::Pixbuf>>
  {
    return glib::PropertyProxy<glib::RefPtr<gdk::Pixbuf>> (
        this,
        "pixbuf-expander-closed");
  }

  auto
  CellRendererPixbuf::property_pixbuf_expander_closed () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Pixbuf>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Pixbuf>> (
        this,
        "pixbuf-expander-closed");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<gtk::IconSize>::value,
      "Type gtk::IconSize cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CellRendererPixbuf::property_icon_size () -> glib::PropertyProxy<gtk::IconSize>
  {
    return glib::PropertyProxy<gtk::IconSize> (this, "icon-size");
  }

  auto
  CellRendererPixbuf::property_icon_size () const -> glib::PropertyProxy_ReadOnly<gtk::IconSize>
  {
    return glib::PropertyProxy_ReadOnly<gtk::IconSize> (this, "icon-size");
  }

  auto
  CellRendererPixbuf::property_icon_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "icon-name");
  }

  auto
  CellRendererPixbuf::property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "icon-name");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::Icon>>::value,
      "Type glib::RefPtr<gio::Icon> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CellRendererPixbuf::property_gicon () -> glib::PropertyProxy<glib::RefPtr<gio::Icon>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::Icon>> (this, "gicon");
  }

  auto
  CellRendererPixbuf::property_gicon () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::Icon>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::Icon>> (this,
                                                                  "gicon");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gdk::Texture>>::value,
      "Type glib::RefPtr<gdk::Texture> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CellRendererPixbuf::property_texture () -> glib::PropertyProxy<glib::RefPtr<gdk::Texture>>
  {
    return glib::PropertyProxy<glib::RefPtr<gdk::Texture>> (this, "texture");
  }

  auto
  CellRendererPixbuf::property_texture () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Texture>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Texture>> (this,
                                                                     "texture");
  }

} // namespace gtk

#endif
