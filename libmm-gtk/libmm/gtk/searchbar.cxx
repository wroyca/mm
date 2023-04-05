// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/searchbar.hxx>
#include <libmm/gtk/searchbar_p.hxx>

#include <gtk/gtk.h>

namespace gtk
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

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkSearchBar* object, bool take_copy) -> gtk::SearchBar*
  {
    return dynamic_cast<gtk::SearchBar*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  SearchBar_Class::init () -> const glib::Class&
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
  SearchBar_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new SearchBar ((GtkSearchBar*) (o)));
  }

  SearchBar::SearchBar (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  SearchBar::SearchBar (GtkSearchBar* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  SearchBar::SearchBar (SearchBar&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  SearchBar::operator= (SearchBar&& src) noexcept -> SearchBar&
  {
    gtk::Widget::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (searchbar_class_.init ()))
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
    return glib::wrap (gtk_search_bar_get_key_capture_widget (gobj ()));
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
    return glib::wrap (gtk_search_bar_get_child (gobj ()));
  }

  auto
  SearchBar::get_child () const -> const Widget*
  {
    return const_cast<SearchBar*> (this)->get_child ();
  }

  auto
  SearchBar::property_search_mode_enabled () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "search-mode-enabled");
  }

  auto
  SearchBar::property_search_mode_enabled () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "search-mode-enabled");
  }

  auto
  SearchBar::property_show_close_button () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "show-close-button");
  }

  auto
  SearchBar::property_show_close_button () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "show-close-button");
  }

  auto
  SearchBar::property_child () -> glib::PropertyProxy<Widget*>
  {
    return glib::PropertyProxy<Widget*> (this, "child");
  }

  auto
  SearchBar::property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "child");
  }

  auto
  SearchBar::property_key_capture_widget () -> glib::PropertyProxy<Widget*>
  {
    return glib::PropertyProxy<Widget*> (this, "key-capture-widget");
  }

  auto
  SearchBar::property_key_capture_widget () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "key-capture-widget");
  }

} // namespace gtk
