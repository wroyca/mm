// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/headerbar.hxx>
#include <libmm/gtk/headerbar_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  auto
  HeaderBar::unset_decoration_layout () -> void
  {
    gtk_header_bar_set_decoration_layout (gobj (), nullptr);
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkHeaderBar* object, bool take_copy) -> gtk::HeaderBar*
  {
    return dynamic_cast<gtk::HeaderBar*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  HeaderBar_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &HeaderBar_Class::class_init_function;

      register_derived_type (gtk_header_bar_get_type ());
    }

    return *this;
  }

  auto
  HeaderBar_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  HeaderBar_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new HeaderBar ((GtkHeaderBar*) (o)));
  }

  HeaderBar::HeaderBar (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  HeaderBar::HeaderBar (GtkHeaderBar* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  HeaderBar::HeaderBar (HeaderBar&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  HeaderBar::operator= (HeaderBar&& src) noexcept -> HeaderBar&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  HeaderBar::~HeaderBar () noexcept
  {
    destroy_ ();
  }

  HeaderBar::CppClassType HeaderBar::headerbar_class_;

  auto
  HeaderBar::get_type () -> GType
  {
    return headerbar_class_.init ().get_type ();
  }

  auto
  HeaderBar::get_base_type () -> GType
  {
    return gtk_header_bar_get_type ();
  }

  HeaderBar::HeaderBar ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (headerbar_class_.init ()))
  {
  }

  auto
  HeaderBar::set_title_widget (gtk::Widget& title_widget) -> void
  {
    gtk_header_bar_set_title_widget (gobj (), (title_widget).gobj ());
  }

  auto
  HeaderBar::get_title_widget () -> Widget*
  {
    return glib::wrap (gtk_header_bar_get_title_widget (gobj ()));
  }

  auto
  HeaderBar::get_title_widget () const -> const Widget*
  {
    return const_cast<HeaderBar*> (this)->get_title_widget ();
  }

  auto
  HeaderBar::pack_start (gtk::Widget& child) -> void
  {
    gtk_header_bar_pack_start (gobj (), (child).gobj ());
  }

  auto
  HeaderBar::pack_end (gtk::Widget& child) -> void
  {
    gtk_header_bar_pack_end (gobj (), (child).gobj ());
  }

  auto
  HeaderBar::remove (gtk::Widget& child) -> void
  {
    gtk_header_bar_remove (gobj (), (child).gobj ());
  }

  auto
  HeaderBar::set_show_title_buttons (bool setting) -> void
  {
    gtk_header_bar_set_show_title_buttons (gobj (), static_cast<int> (setting));
  }

  auto
  HeaderBar::get_show_title_buttons () const -> bool
  {
    return gtk_header_bar_get_show_title_buttons (
        const_cast<GtkHeaderBar*> (gobj ()));
  }

  auto
  HeaderBar::set_decoration_layout (const glib::ustring& layout) -> void
  {
    gtk_header_bar_set_decoration_layout (gobj (), layout.c_str ());
  }

  auto
  HeaderBar::get_decoration_layout () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_header_bar_get_decoration_layout (
            const_cast<GtkHeaderBar*> (gobj ())));
  }

  auto
  HeaderBar::property_title_widget () -> glib::PropertyProxy<gtk::Widget*>
  {
    return glib::PropertyProxy<gtk::Widget*> (this, "title-widget");
  }

  auto
  HeaderBar::property_title_widget () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return glib::PropertyProxy_ReadOnly<gtk::Widget*> (this, "title-widget");
  }

  auto
  HeaderBar::property_show_title_buttons () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "show-title-buttons");
  }

  auto
  HeaderBar::property_show_title_buttons () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "show-title-buttons");
  }

  auto
  HeaderBar::property_decoration_layout () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "decoration-layout");
  }

  auto
  HeaderBar::property_decoration_layout () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this,
                                                        "decoration-layout");
  }

} // namespace gtk
