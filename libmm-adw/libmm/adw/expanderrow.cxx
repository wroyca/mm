// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/expanderrow.hxx>
#include <libmm/adw/expanderrow_p.hxx>

namespace adw
{

}

namespace
{
}

namespace glib
{

  auto
  wrap (AdwExpanderRow* object, bool take_copy) -> adw::expander_row*
  {
    return dynamic_cast<adw::expander_row*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  expander_row_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &expander_row_class::class_init_function;

      register_derived_type (adw_expander_row_get_type ());
    }

    return *this;
  }

  auto
  expander_row_class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  expander_row_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new expander_row ((AdwExpanderRow*) (o)));
  }

  expander_row::expander_row (const glib::ConstructParams& construct_params)
    : adw::preferences_row (construct_params)
  {
  }

  expander_row::expander_row (AdwExpanderRow* castitem)
    : adw::preferences_row ((AdwPreferencesRow*) (castitem))
  {
  }

  expander_row::expander_row (expander_row&& src) noexcept
    : adw::preferences_row (std::move (src))
  {
  }

  auto
  expander_row::operator= (expander_row&& src) noexcept -> expander_row&
  {
    adw::preferences_row::operator= (std::move (src));
    return *this;
  }

  expander_row::~expander_row () noexcept
  {
    destroy_ ();
  }

  expander_row::CppClassType expander_row::expanderrow_class_;

  auto
  expander_row::get_type () -> GType
  {
    return expanderrow_class_.init ().get_type ();
  }

  auto
  expander_row::get_base_type () -> GType
  {
    return adw_expander_row_get_type ();
  }

  expander_row::expander_row ()
    : glib::ObjectBase (nullptr),
      adw::preferences_row (glib::ConstructParams (expanderrow_class_.init ()))
  {
  }

  auto
  expander_row::add_action (gtk::Widget* widget) -> void
  {
    adw_expander_row_add_action (gobj (), (GtkWidget*) glib::unwrap (widget));
  }

  auto
  expander_row::add_prefix (gtk::Widget* widget) -> void
  {
    adw_expander_row_add_prefix (gobj (), (GtkWidget*) glib::unwrap (widget));
  }

  auto
  expander_row::add_row (gtk::Widget* child) -> void
  {
    adw_expander_row_add_row (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  expander_row::get_enable_expansion () const -> bool
  {
    return adw_expander_row_get_enable_expansion (
        const_cast<AdwExpanderRow*> (gobj ()));
  }

  auto
  expander_row::get_expanded () const -> bool
  {
    return adw_expander_row_get_expanded (
        const_cast<AdwExpanderRow*> (gobj ()));
  }

  auto
  expander_row::get_icon_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_expander_row_get_icon_name (const_cast<AdwExpanderRow*> (gobj ())));
  }

  auto
  expander_row::get_show_enable_switch () const -> bool
  {
    return adw_expander_row_get_show_enable_switch (
        const_cast<AdwExpanderRow*> (gobj ()));
  }

  auto
  expander_row::get_subtitle () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_expander_row_get_subtitle (const_cast<AdwExpanderRow*> (gobj ())));
  }

  auto
  expander_row::remove (gtk::Widget* child) -> void
  {
    adw_expander_row_remove (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  expander_row::set_enable_expansion (bool enable_expansion) -> void
  {
    adw_expander_row_set_enable_expansion (gobj (),
                                           static_cast<int> (enable_expansion));
  }

  auto
  expander_row::set_expanded (bool expanded) -> void
  {
    adw_expander_row_set_expanded (gobj (), static_cast<int> (expanded));
  }

  auto
  expander_row::set_icon_name (const glib::ustring& icon_name) -> void
  {
    adw_expander_row_set_icon_name (gobj (), icon_name.c_str ());
  }

  auto
  expander_row::set_show_enable_switch (bool show_enable_switch) -> void
  {
    adw_expander_row_set_show_enable_switch (
        gobj (),
        static_cast<int> (show_enable_switch));
  }

  auto
  expander_row::set_subtitle (const glib::ustring& subtitle) -> void
  {
    adw_expander_row_set_subtitle (gobj (), subtitle.c_str ());
  }

  auto
  expander_row::property_enable_expansion () -> glib::PropertyProxy<bool>
  {
    return {this, "enable-expansion"};
  }

  auto
  expander_row::property_enable_expansion () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "enable-expansion"};
  }

  auto
  expander_row::property_expanded () -> glib::PropertyProxy<bool>
  {
    return {this, "expanded"};
  }

  auto
  expander_row::property_expanded () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "expanded"};
  }

  auto
  expander_row::property_icon_name () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "icon-name"};
  }

  auto
  expander_row::property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "icon-name"};
  }

  auto
  expander_row::property_show_enable_switch () -> glib::PropertyProxy<bool>
  {
    return {this, "show-enable-switch"};
  }

  auto
  expander_row::property_show_enable_switch () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "show-enable-switch"};
  }

  auto
  expander_row::property_subtitle () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "subtitle"};
  }

  auto
  expander_row::property_subtitle () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "subtitle"};
  }

} // namespace adw
