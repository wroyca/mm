// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/searchbar.hxx>
#include <libmm/gtk/searchbar_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  auto
  SearchBar::unset_key_capture_widget () -> void
  {
    gtk_search_bar_set_key_capture_widget (gobj (), nullptr);
  }

  auto
  SearchBar::unset_child () -> void
  {
    gtk_search_bar_set_child (gobj (), nullptr);
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkSearchBar* object, bool take_copy) -> Gtk::SearchBar*
  {
    return dynamic_cast<Gtk::SearchBar*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  SearchBar_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &SearchBar_Class::class_init_function;

      register_derived_type (gtk_search_bar_get_type ());
    }

    return *this;
  }

  auto
  SearchBar_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  SearchBar_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new SearchBar ((GtkSearchBar*) (o)));
  }

  SearchBar::SearchBar (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  SearchBar::SearchBar (GtkSearchBar* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  SearchBar::SearchBar (SearchBar&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  SearchBar::operator= (SearchBar&& src) noexcept -> SearchBar&
  {
    Gtk::Widget::operator= (std::move (src));
    return *this;
  }

  SearchBar::~SearchBar () noexcept
  {
    destroy_ ();
  }

  SearchBar::CppClassType SearchBar::searchbar_class_;

  auto
  SearchBar::get_type () -> GType
  {
    return searchbar_class_.init ().get_type ();
  }

  auto
  SearchBar::get_base_type () -> GType
  {
    return gtk_search_bar_get_type ();
  }

  SearchBar::SearchBar ()
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (searchbar_class_.init ()))
  {
  }

  auto
  SearchBar::connect_entry (Editable& entry) -> void
  {
    gtk_search_bar_connect_entry (gobj (), (entry).gobj ());
  }

  auto
  SearchBar::get_search_mode () const -> bool
  {
    return gtk_search_bar_get_search_mode (const_cast<GtkSearchBar*> (gobj ()));
  }

  auto
  SearchBar::set_search_mode (bool search_mode) -> void
  {
    gtk_search_bar_set_search_mode (gobj (), static_cast<int> (search_mode));
  }

  auto
  SearchBar::get_show_close_button () const -> bool
  {
    return gtk_search_bar_get_show_close_button (
        const_cast<GtkSearchBar*> (gobj ()));
  }

  auto
  SearchBar::set_show_close_button (bool visible) -> void
  {
    gtk_search_bar_set_show_close_button (gobj (), static_cast<int> (visible));
  }

  auto
  SearchBar::set_key_capture_widget (Widget& widget) -> void
  {
    gtk_search_bar_set_key_capture_widget (gobj (), (widget).gobj ());
  }

  auto
  SearchBar::get_key_capture_widget () -> Widget*
  {
    return Glib::wrap (gtk_search_bar_get_key_capture_widget (gobj ()));
  }

  auto
  SearchBar::get_key_capture_widget () const -> const Widget*
  {
    return const_cast<SearchBar*> (this)->get_key_capture_widget ();
  }

  auto
  SearchBar::set_child (Widget& child) -> void
  {
    gtk_search_bar_set_child (gobj (), (child).gobj ());
  }

  auto
  SearchBar::get_child () -> Widget*
  {
    return Glib::wrap (gtk_search_bar_get_child (gobj ()));
  }

  auto
  SearchBar::get_child () const -> const Widget*
  {
    return const_cast<SearchBar*> (this)->get_child ();
  }

  auto
  SearchBar::property_search_mode_enabled () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "search-mode-enabled");
  }

  auto
  SearchBar::property_search_mode_enabled () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "search-mode-enabled");
  }

  auto
  SearchBar::property_show_close_button () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "show-close-button");
  }

  auto
  SearchBar::property_show_close_button () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "show-close-button");
  }

  auto
  SearchBar::property_child () -> Glib::PropertyProxy<Widget*>
  {
    return Glib::PropertyProxy<Widget*> (this, "child");
  }

  auto
  SearchBar::property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Widget*> (this, "child");
  }

  auto
  SearchBar::property_key_capture_widget () -> Glib::PropertyProxy<Widget*>
  {
    return Glib::PropertyProxy<Widget*> (this, "key-capture-widget");
  }

  auto
  SearchBar::property_key_capture_widget () const -> Glib::PropertyProxy_ReadOnly<Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Widget*> (this, "key-capture-widget");
  }

} // namespace Gtk