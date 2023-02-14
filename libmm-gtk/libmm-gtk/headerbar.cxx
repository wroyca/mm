

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/headerbar.hxx>
#include <libmm-gtk/headerbar_p.hxx>

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
  wrap (GtkHeaderBar* object, const bool take_copy) -> Gtk::HeaderBar*
  {
    return dynamic_cast<Gtk::HeaderBar*> (
        wrap_auto ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  HeaderBar_Class::init () -> const Class&
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
    return manage (new HeaderBar ((GtkHeaderBar*) o));
  }

  HeaderBar::HeaderBar (const Glib::ConstructParams& construct_params)
    : Widget (construct_params)
  {
  }

  HeaderBar::HeaderBar (GtkHeaderBar* castitem)
    : Widget ((GtkWidget*) castitem)
  {
  }

  HeaderBar::HeaderBar (HeaderBar&& src) noexcept
    : Widget (std::move (src))
  {
  }

  auto
  HeaderBar::operator= (HeaderBar&& src) noexcept -> HeaderBar&
  {
    Widget::operator= (std::move (src));
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
    : ObjectBase (nullptr),
      Widget (Glib::ConstructParams (headerbar_class_.init ()))
  {
  }

  auto
  HeaderBar::set_title_widget (Widget& title_widget) -> void
  {
    gtk_header_bar_set_title_widget (gobj (), title_widget.gobj ());
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
  HeaderBar::pack_start (Widget& child) -> void
  {
    gtk_header_bar_pack_start (gobj (), child.gobj ());
  }

  auto
  HeaderBar::pack_end (Widget& child) -> void
  {
    gtk_header_bar_pack_end (gobj (), child.gobj ());
  }

  auto
  HeaderBar::remove (Widget& child) -> void
  {
    gtk_header_bar_remove (gobj (), child.gobj ());
  }

  auto
  HeaderBar::set_show_title_buttons (const bool setting) -> void
  {
    gtk_header_bar_set_show_title_buttons (gobj (), setting);
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
  HeaderBar::property_title_widget () -> Glib::PropertyProxy<Widget*>
  {
    return {this, "title-widget"};
  }

  auto
  HeaderBar::property_title_widget () const -> Glib::PropertyProxy_ReadOnly<Widget*>
  {
    return {this, "title-widget"};
  }

  auto
  HeaderBar::property_show_title_buttons () -> Glib::PropertyProxy<bool>
  {
    return {this, "show-title-buttons"};
  }

  auto
  HeaderBar::property_show_title_buttons () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "show-title-buttons"};
  }

  auto
  HeaderBar::property_decoration_layout () -> Glib::PropertyProxy<Glib::ustring>
  {
    return {this, "decoration-layout"};
  }

  auto
  HeaderBar::property_decoration_layout () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "decoration-layout"};
  }

} // namespace Gtk
