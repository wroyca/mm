// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/headerbar.hxx>
#include <libmm/gtk/headerbar_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  auto
  HeaderBar::unset_decoration_layout () -> void
  {
    gtk_header_bar_set_decoration_layout (gobj (), nullptr);
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkHeaderBar* object, bool take_copy) -> Gtk::HeaderBar*
  {
    return dynamic_cast<Gtk::HeaderBar*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  HeaderBar_Class::init () -> const Glib::Class&
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
  HeaderBar_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new HeaderBar ((GtkHeaderBar*) (o)));
  }

  HeaderBar::HeaderBar (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  HeaderBar::HeaderBar (GtkHeaderBar* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  HeaderBar::HeaderBar (HeaderBar&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  HeaderBar::operator= (HeaderBar&& src) noexcept -> HeaderBar&
  {
    Gtk::Widget::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (headerbar_class_.init ()))
  {
  }

  auto
  HeaderBar::set_title_widget (Gtk::Widget& title_widget) -> void
  {
    gtk_header_bar_set_title_widget (gobj (), (title_widget).gobj ());
  }

  auto
  HeaderBar::get_title_widget () -> Widget*
  {
    return Glib::wrap (gtk_header_bar_get_title_widget (gobj ()));
  }

  auto
  HeaderBar::get_title_widget () const -> const Widget*
  {
    return const_cast<HeaderBar*> (this)->get_title_widget ();
  }

  auto
  HeaderBar::pack_start (Gtk::Widget& child) -> void
  {
    gtk_header_bar_pack_start (gobj (), (child).gobj ());
  }

  auto
  HeaderBar::pack_end (Gtk::Widget& child) -> void
  {
    gtk_header_bar_pack_end (gobj (), (child).gobj ());
  }

  auto
  HeaderBar::remove (Gtk::Widget& child) -> void
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
  HeaderBar::set_decoration_layout (const Glib::ustring& layout) -> void
  {
    gtk_header_bar_set_decoration_layout (gobj (), layout.c_str ());
  }

  auto
  HeaderBar::get_decoration_layout () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_header_bar_get_decoration_layout (
            const_cast<GtkHeaderBar*> (gobj ())));
  }

  auto
  HeaderBar::property_title_widget () -> Glib::PropertyProxy<Gtk::Widget*>
  {
    return Glib::PropertyProxy<Gtk::Widget*> (this, "title-widget");
  }

  auto
  HeaderBar::property_title_widget () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::Widget*> (this, "title-widget");
  }

  auto
  HeaderBar::property_show_title_buttons () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "show-title-buttons");
  }

  auto
  HeaderBar::property_show_title_buttons () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "show-title-buttons");
  }

  auto
  HeaderBar::property_decoration_layout () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "decoration-layout");
  }

  auto
  HeaderBar::property_decoration_layout () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this,
                                                        "decoration-layout");
  }

} // namespace Gtk