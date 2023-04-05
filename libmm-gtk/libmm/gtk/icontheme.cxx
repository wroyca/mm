// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/icontheme.hxx>
#include <libmm/gtk/icontheme_p.hxx>

#include <gtk/gtk.h>
#include <libmm/glib/vectorutils.hxx>

namespace
{

  static const glib::SignalProxyInfo IconTheme_signal_changed_info = {
      "changed",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

}

gtk::IconThemeError::IconThemeError (gtk::IconThemeError::Code error_code,
                                     const glib::ustring& error_message)
  : glib::Error (GTK_ICON_THEME_ERROR, error_code, error_message)
{
}

gtk::IconThemeError::IconThemeError (GError* gobject)
  : glib::Error (gobject)
{
}

auto
gtk::IconThemeError::code () const -> gtk::IconThemeError::Code
{
  return static_cast<Code> (glib::Error::code ());
}

auto
gtk::IconThemeError::throw_func (GError* gobject) -> void
{
  throw gtk::IconThemeError (gobject);
}

auto
glib::Value<gtk::IconThemeError::Code>::value_type () -> GType
{
  return gtk_icon_theme_error_get_type ();
}

namespace glib
{

  auto
  wrap (GtkIconTheme* object, bool take_copy) -> glib::RefPtr<gtk::IconTheme>
  {
    return glib::make_refptr_for_instance<gtk::IconTheme> (
        dynamic_cast<gtk::IconTheme*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  IconTheme_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &IconTheme_Class::class_init_function;

      register_derived_type (gtk_icon_theme_get_type ());
    }

    return *this;
  }

  auto
  IconTheme_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  IconTheme_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new IconTheme ((GtkIconTheme*) object);
  }

  auto
  IconTheme::gobj_copy () -> GtkIconTheme*
  {
    reference ();
    return gobj ();
  }

  IconTheme::IconTheme (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  IconTheme::IconTheme (GtkIconTheme* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  IconTheme::IconTheme (IconTheme&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  IconTheme::operator= (IconTheme&& src) noexcept -> IconTheme&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  IconTheme::~IconTheme () noexcept {}

  IconTheme::CppClassType IconTheme::icontheme_class_;

  auto
  IconTheme::get_type () -> GType
  {
    return icontheme_class_.init ().get_type ();
  }

  auto
  IconTheme::get_base_type () -> GType
  {
    return gtk_icon_theme_get_type ();
  }

  IconTheme::IconTheme ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (icontheme_class_.init ()))
  {
  }

  auto
  IconTheme::create () -> glib::RefPtr<IconTheme>
  {
    return glib::make_refptr_for_instance<IconTheme> (new IconTheme ());
  }

  auto
  IconTheme::get_for_display (const glib::RefPtr<gdk::Display>& display) -> glib::RefPtr<IconTheme>
  {
    auto retvalue =
        glib::wrap (gtk_icon_theme_get_for_display (glib::unwrap (display)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  IconTheme::get_display () -> glib::RefPtr<gdk::Display>
  {
    auto retvalue = glib::wrap (gtk_icon_theme_get_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  IconTheme::get_display () const -> glib::RefPtr<const gdk::Display>
  {
    return const_cast<IconTheme*> (this)->get_display ();
  }

  auto
  IconTheme::set_search_path (const std::vector<std::string>& path) -> void
  {
    gtk_icon_theme_set_search_path (
        gobj (),
        glib::ArrayHandler<std::string>::vector_to_array (path).data ());
  }

  auto
  IconTheme::get_search_path () const -> std::vector<std::string>
  {
    return glib::ArrayHandler<std::string>::array_to_vector (
        gtk_icon_theme_get_search_path (const_cast<GtkIconTheme*> (gobj ())),
        glib::OWNERSHIP_DEEP);
  }

  auto
  IconTheme::add_search_path (const std::string& path) -> void
  {
    gtk_icon_theme_add_search_path (gobj (), path.c_str ());
  }

  auto
  IconTheme::set_resource_path (const std::vector<std::string>& path) -> void
  {
    gtk_icon_theme_set_resource_path (
        gobj (),
        glib::ArrayHandler<std::string>::vector_to_array (path).data ());
  }

  auto
  IconTheme::get_resource_path () const -> std::vector<std::string>
  {
    return glib::ArrayHandler<std::string>::array_to_vector (
        gtk_icon_theme_get_resource_path (const_cast<GtkIconTheme*> (gobj ())),
        glib::OWNERSHIP_DEEP);
  }

  auto
  IconTheme::add_resource_path (const std::string& path) -> void
  {
    gtk_icon_theme_add_resource_path (gobj (), path.c_str ());
  }

  auto
  IconTheme::set_theme_name (const glib::ustring& theme_name) -> void
  {
    gtk_icon_theme_set_theme_name (gobj (), theme_name.c_str ());
  }

  auto
  IconTheme::get_theme_name () const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        gtk_icon_theme_get_theme_name (const_cast<GtkIconTheme*> (gobj ())));
  }

  auto
  IconTheme::has_icon (const glib::ustring& icon_name) const -> bool
  {
    return gtk_icon_theme_has_icon (const_cast<GtkIconTheme*> (gobj ()),
                                    icon_name.c_str ());
  }

  auto
  IconTheme::has_gicon (const glib::RefPtr<const gio::Icon>& gicon) const -> bool
  {
    return gtk_icon_theme_has_gicon (
        const_cast<GtkIconTheme*> (gobj ()),
        const_cast<GIcon*> (glib::unwrap<gio::Icon> (gicon)));
  }

  auto
  IconTheme::get_icon_sizes (const glib::ustring& icon_name) const -> std::vector<int>
  {
    return glib::ArrayHandler<int>::array_to_vector (
        gtk_icon_theme_get_icon_sizes (const_cast<GtkIconTheme*> (gobj ()),
                                       icon_name.c_str ()),
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  IconTheme::lookup_icon (const glib::ustring& icon_name,
                          const std::vector<glib::ustring>& fallbacks,
                          int size,
                          int scale,
                          TextDirection direction,
                          IconLookupFlags flags) -> glib::RefPtr<IconPaintable>
  {
    return glib::wrap (gtk_icon_theme_lookup_icon (
        gobj (),
        icon_name.c_str (),
        const_cast<const char**> (
            glib::ArrayHandler<glib::ustring>::vector_to_array (fallbacks)
                .data ()),
        size,
        scale,
        static_cast<GtkTextDirection> (direction),
        static_cast<GtkIconLookupFlags> (flags)));
  }

  auto
  IconTheme::lookup_icon (const glib::ustring& icon_name,
                          int size,
                          int scale,
                          TextDirection direction,
                          IconLookupFlags flags) -> glib::RefPtr<IconPaintable>
  {
    return glib::wrap (
        gtk_icon_theme_lookup_icon (gobj (),
                                    icon_name.c_str (),
                                    nullptr,
                                    size,
                                    scale,
                                    static_cast<GtkTextDirection> (direction),
                                    static_cast<GtkIconLookupFlags> (flags)));
  }

  auto
  IconTheme::lookup_icon (const glib::ustring& icon_name,
                          const std::vector<glib::ustring>& fallbacks,
                          int size,
                          int scale,
                          TextDirection direction,
                          IconLookupFlags flags) const -> glib::RefPtr<const IconPaintable>
  {
    return const_cast<IconTheme*> (this)
        ->lookup_icon (icon_name, fallbacks, size, scale, direction, flags);
  }

  auto
  IconTheme::lookup_icon (const glib::ustring& icon_name,
                          int size,
                          int scale,
                          TextDirection direction,
                          IconLookupFlags flags) const -> glib::RefPtr<const IconPaintable>
  {
    return const_cast<IconTheme*> (this)->lookup_icon (icon_name,
                                                       size,
                                                       scale,
                                                       direction,
                                                       flags);
  }

  auto
  IconTheme::lookup_icon (const glib::RefPtr<const gio::Icon>& icon,
                          int size,
                          int scale,
                          TextDirection direction,
                          IconLookupFlags flags) -> glib::RefPtr<IconPaintable>
  {
    return glib::wrap (gtk_icon_theme_lookup_by_gicon (
        gobj (),
        const_cast<GIcon*> (glib::unwrap<gio::Icon> (icon)),
        size,
        scale,
        static_cast<GtkTextDirection> (direction),
        static_cast<GtkIconLookupFlags> (flags)));
  }

  auto
  IconTheme::lookup_icon (const glib::RefPtr<const gio::Icon>& icon,
                          int size,
                          int scale,
                          TextDirection direction,
                          IconLookupFlags flags) const -> glib::RefPtr<const IconPaintable>
  {
    return const_cast<IconTheme*> (this)->lookup_icon (icon,
                                                       size,
                                                       scale,
                                                       direction,
                                                       flags);
  }

  auto
  IconTheme::get_icon_names () const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
        gtk_icon_theme_get_icon_names (const_cast<GtkIconTheme*> (gobj ())),
        glib::OWNERSHIP_DEEP);
  }

  auto
  IconTheme::signal_changed () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &IconTheme_signal_changed_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gdk::Display>>::value,
      "Type glib::RefPtr<gdk::Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  IconTheme::property_display () -> glib::PropertyProxy<glib::RefPtr<gdk::Display>>
  {
    return glib::PropertyProxy<glib::RefPtr<gdk::Display>> (this, "display");
  }

  auto
  IconTheme::property_display () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Display>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Display>> (this,
                                                                     "display");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          std::vector<glib::ustring>>::value,
      "Type std::vector<glib::ustring> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  IconTheme::property_icon_names () const -> glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>>
  {
    return glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>> (
        this,
        "icon-names");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          std::vector<std::string>>::value,
      "Type std::vector<std::string> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  IconTheme::property_search_path () -> glib::PropertyProxy<std::vector<std::string>>
  {
    return glib::PropertyProxy<std::vector<std::string>> (this, "search-path");
  }

  auto
  IconTheme::property_search_path () const -> glib::PropertyProxy_ReadOnly<std::vector<std::string>>
  {
    return glib::PropertyProxy_ReadOnly<std::vector<std::string>> (
        this,
        "search-path");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          std::vector<std::string>>::value,
      "Type std::vector<std::string> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  IconTheme::property_resource_path () -> glib::PropertyProxy<std::vector<std::string>>
  {
    return glib::PropertyProxy<std::vector<std::string>> (this,
                                                          "resource-path");
  }

  auto
  IconTheme::property_resource_path () const -> glib::PropertyProxy_ReadOnly<std::vector<std::string>>
  {
    return glib::PropertyProxy_ReadOnly<std::vector<std::string>> (
        this,
        "resource-path");
  }

  auto
  IconTheme::property_theme_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "theme-name");
  }

  auto
  IconTheme::property_theme_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "theme-name");
  }

} // namespace gtk
