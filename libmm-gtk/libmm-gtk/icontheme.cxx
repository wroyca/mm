

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/icontheme.hxx>
#include <libmm-gtk/icontheme_p.hxx>

#include <gtk/gtk.h>
#include <libmm-glib/vectorutils.hxx>

namespace
{

  const Glib::SignalProxyInfo IconTheme_signal_changed_info = {
      "changed",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

}

Gtk::IconThemeError::IconThemeError (const Code error_code,
                                     const Glib::ustring& error_message)
  : Error (GTK_ICON_THEME_ERROR, error_code, error_message)
{
}

Gtk::IconThemeError::IconThemeError (GError* gobject)
  : Error (gobject)
{
}

auto
Gtk::IconThemeError::code () const -> Code
{
  return static_cast<Code> (Error::code ());
}

auto
Gtk::IconThemeError::throw_func (GError* gobject) -> void
{
  throw IconThemeError (gobject);
}

auto
Glib::Value<Gtk::IconThemeError::Code>::value_type () -> GType
{
  return gtk_icon_theme_error_get_type ();
}

namespace Glib
{

  auto
  wrap (GtkIconTheme* object, const bool take_copy) -> RefPtr<Gtk::IconTheme>
  {
    return Glib::make_refptr_for_instance<Gtk::IconTheme> (
        dynamic_cast<Gtk::IconTheme*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  IconTheme_Class::init () -> const Class&
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
  IconTheme_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new IconTheme ((GtkIconTheme*) object);
  }

  auto
  IconTheme::gobj_copy () -> GtkIconTheme*
  {
    reference ();
    return gobj ();
  }

  IconTheme::IconTheme (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  IconTheme::IconTheme (GtkIconTheme* castitem)
    : Object ((GObject*) castitem)
  {
  }

  IconTheme::IconTheme (IconTheme&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  IconTheme::operator= (IconTheme&& src) noexcept -> IconTheme&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  IconTheme::~IconTheme () noexcept = default;

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
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (icontheme_class_.init ()))
  {
  }

  auto
  IconTheme::create () -> Glib::RefPtr<IconTheme>
  {
    return Glib::make_refptr_for_instance<IconTheme> (new IconTheme ());
  }

  auto
  IconTheme::get_for_display (const Glib::RefPtr<Gdk::Display>& display) -> Glib::RefPtr<IconTheme>
  {
    auto retvalue =
        Glib::wrap (gtk_icon_theme_get_for_display (Glib::unwrap (display)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  IconTheme::get_display () -> Glib::RefPtr<Gdk::Display>
  {
    auto retvalue = Glib::wrap (gtk_icon_theme_get_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  IconTheme::get_display () const -> Glib::RefPtr<const Gdk::Display>
  {
    return const_cast<IconTheme*> (this)->get_display ();
  }

  auto
  IconTheme::set_search_path (const std::vector<std::string>& path) -> void
  {
    gtk_icon_theme_set_search_path (
        gobj (),
        Glib::ArrayHandler<std::string>::vector_to_array (path).data ());
  }

  auto
  IconTheme::get_search_path () const -> std::vector<std::string>
  {
    return Glib::ArrayHandler<std::string>::array_to_vector (
        gtk_icon_theme_get_search_path (const_cast<GtkIconTheme*> (gobj ())),
        Glib::OWNERSHIP_DEEP);
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
        Glib::ArrayHandler<std::string>::vector_to_array (path).data ());
  }

  auto
  IconTheme::get_resource_path () const -> std::vector<std::string>
  {
    return Glib::ArrayHandler<std::string>::array_to_vector (
        gtk_icon_theme_get_resource_path (const_cast<GtkIconTheme*> (gobj ())),
        Glib::OWNERSHIP_DEEP);
  }

  auto
  IconTheme::add_resource_path (const std::string& path) -> void
  {
    gtk_icon_theme_add_resource_path (gobj (), path.c_str ());
  }

  auto
  IconTheme::set_theme_name (const Glib::ustring& theme_name) -> void
  {
    gtk_icon_theme_set_theme_name (gobj (), theme_name.c_str ());
  }

  auto
  IconTheme::get_theme_name () const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        gtk_icon_theme_get_theme_name (const_cast<GtkIconTheme*> (gobj ())));
  }

  auto
  IconTheme::has_icon (const Glib::ustring& icon_name) const -> bool
  {
    return gtk_icon_theme_has_icon (const_cast<GtkIconTheme*> (gobj ()),
                                    icon_name.c_str ());
  }

  auto
  IconTheme::has_gicon (const Glib::RefPtr<const Gio::Icon>& gicon) const -> bool
  {
    return gtk_icon_theme_has_gicon (
        const_cast<GtkIconTheme*> (gobj ()),
        const_cast<GIcon*> (Glib::unwrap<Gio::Icon> (gicon)));
  }

  auto
  IconTheme::get_icon_sizes (const Glib::ustring& icon_name) const -> std::vector<int>
  {
    return Glib::ArrayHandler<int>::array_to_vector (
        gtk_icon_theme_get_icon_sizes (const_cast<GtkIconTheme*> (gobj ()),
                                       icon_name.c_str ()),
        Glib::OWNERSHIP_SHALLOW);
  }

  auto
  IconTheme::lookup_icon (const Glib::ustring& icon_name,
                          const std::vector<Glib::ustring>& fallbacks,
                          const int size,
                          const int scale,
                          TextDirection direction,
                          IconLookupFlags flags) -> Glib::RefPtr<IconPaintable>
  {
    return Glib::wrap (gtk_icon_theme_lookup_icon (
        gobj (),
        icon_name.c_str (),
        Glib::ArrayHandler<Glib::ustring>::vector_to_array (fallbacks).data (),
        size,
        scale,
        static_cast<GtkTextDirection> (direction),
        static_cast<GtkIconLookupFlags> (flags)));
  }

  auto
  IconTheme::lookup_icon (const Glib::ustring& icon_name,
                          const int size,
                          const int scale,
                          TextDirection direction,
                          IconLookupFlags flags) -> Glib::RefPtr<IconPaintable>
  {
    return Glib::wrap (
        gtk_icon_theme_lookup_icon (gobj (),
                                    icon_name.c_str (),
                                    nullptr,
                                    size,
                                    scale,
                                    static_cast<GtkTextDirection> (direction),
                                    static_cast<GtkIconLookupFlags> (flags)));
  }

  auto
  IconTheme::lookup_icon (const Glib::ustring& icon_name,
                          const std::vector<Glib::ustring>& fallbacks,
                          const int size,
                          const int scale,
                          const TextDirection direction,
                          const IconLookupFlags flags) const -> Glib::RefPtr<const IconPaintable>
  {
    return const_cast<IconTheme*> (this)
        ->lookup_icon (icon_name, fallbacks, size, scale, direction, flags);
  }

  auto
  IconTheme::lookup_icon (const Glib::ustring& icon_name,
                          const int size,
                          const int scale,
                          const TextDirection direction,
                          const IconLookupFlags flags) const -> Glib::RefPtr<const IconPaintable>
  {
    return const_cast<IconTheme*> (this)->lookup_icon (icon_name,
                                                       size,
                                                       scale,
                                                       direction,
                                                       flags);
  }

  auto
  IconTheme::lookup_icon (const Glib::RefPtr<const Gio::Icon>& icon,
                          const int size,
                          const int scale,
                          TextDirection direction,
                          IconLookupFlags flags) -> Glib::RefPtr<IconPaintable>
  {
    return Glib::wrap (gtk_icon_theme_lookup_by_gicon (
        gobj (),
        const_cast<GIcon*> (Glib::unwrap<Gio::Icon> (icon)),
        size,
        scale,
        static_cast<GtkTextDirection> (direction),
        static_cast<GtkIconLookupFlags> (flags)));
  }

  auto
  IconTheme::lookup_icon (const Glib::RefPtr<const Gio::Icon>& icon,
                          const int size,
                          const int scale,
                          const TextDirection direction,
                          const IconLookupFlags flags) const -> Glib::RefPtr<const IconPaintable>
  {
    return const_cast<IconTheme*> (this)->lookup_icon (icon,
                                                       size,
                                                       scale,
                                                       direction,
                                                       flags);
  }

  auto
  IconTheme::get_icon_names () const -> std::vector<Glib::ustring>
  {
    return Glib::ArrayHandler<Glib::ustring>::array_to_vector (
        gtk_icon_theme_get_icon_names (const_cast<GtkIconTheme*> (gobj ())),
        Glib::OWNERSHIP_DEEP);
  }

  auto
  IconTheme::signal_changed () -> Glib::SignalProxy<void ()>
  {
    return {this, &IconTheme_signal_changed_info};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gdk::Display>>::value,
      "Type Glib::RefPtr<Gdk::Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  IconTheme::property_display () -> Glib::PropertyProxy<Glib::RefPtr<Gdk::Display>>
  {
    return {this, "display"};
  }

  auto
  IconTheme::property_display () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Display>>
  {
    return {this, "display"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          std::vector<Glib::ustring>>::value,
      "Type std::vector<Glib::ustring> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  IconTheme::property_icon_names () const -> Glib::PropertyProxy_ReadOnly<std::vector<Glib::ustring>>
  {
    return {this, "icon-names"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          std::vector<std::string>>::value,
      "Type std::vector<std::string> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  IconTheme::property_search_path () -> Glib::PropertyProxy<std::vector<std::string>>
  {
    return {this, "search-path"};
  }

  auto
  IconTheme::property_search_path () const -> Glib::PropertyProxy_ReadOnly<std::vector<std::string>>
  {
    return {this, "search-path"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          std::vector<std::string>>::value,
      "Type std::vector<std::string> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  IconTheme::property_resource_path () -> Glib::PropertyProxy<std::vector<std::string>>
  {
    return {this, "resource-path"};
  }

  auto
  IconTheme::property_resource_path () const -> Glib::PropertyProxy_ReadOnly<std::vector<std::string>>
  {
    return {this, "resource-path"};
  }

  auto
  IconTheme::property_theme_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return {this, "theme-name"};
  }

  auto
  IconTheme::property_theme_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "theme-name"};
  }

} // namespace Gtk
