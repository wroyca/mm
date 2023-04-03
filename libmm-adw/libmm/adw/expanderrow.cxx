// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/expanderrow.hxx>
#include <libmm/adw/expanderrow_p.hxx>

namespace Adw
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (AdwExpanderRow* object, bool take_copy) -> Adw::ExpanderRow*
  {
    return dynamic_cast<Adw::ExpanderRow*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  ExpanderRow_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ExpanderRow_Class::class_init_function;

      register_derived_type (adw_expander_row_get_type ());
    }

    return *this;
  }

  auto
  ExpanderRow_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ExpanderRow_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new ExpanderRow ((AdwExpanderRow*) (o)));
  }

  ExpanderRow::ExpanderRow (const Glib::ConstructParams& construct_params)
    : Adw::PreferencesRow (construct_params)
  {
  }

  ExpanderRow::ExpanderRow (AdwExpanderRow* castitem)
    : Adw::PreferencesRow ((AdwPreferencesRow*) (castitem))
  {
  }

  ExpanderRow::ExpanderRow (ExpanderRow&& src) noexcept
    : Adw::PreferencesRow (std::move (src))
  {
  }

  auto
  ExpanderRow::operator= (ExpanderRow&& src) noexcept -> ExpanderRow&
  {
    Adw::PreferencesRow::operator= (std::move (src));
    return *this;
  }

  ExpanderRow::~ExpanderRow () noexcept
  {
    destroy_ ();
  }

  ExpanderRow::CppClassType ExpanderRow::expanderrow_class_;

  auto
  ExpanderRow::get_type () -> GType
  {
    return expanderrow_class_.init ().get_type ();
  }

  auto
  ExpanderRow::get_base_type () -> GType
  {
    return adw_expander_row_get_type ();
  }

  ExpanderRow::ExpanderRow ()
    : Glib::ObjectBase (nullptr),
      Adw::PreferencesRow (Glib::ConstructParams (expanderrow_class_.init ()))
  {
  }

  auto
  ExpanderRow::add_action (Gtk::Widget* widget) -> void
  {
    adw_expander_row_add_action (gobj (), (GtkWidget*) Glib::unwrap (widget));
  }

  auto
  ExpanderRow::add_prefix (Gtk::Widget* widget) -> void
  {
    adw_expander_row_add_prefix (gobj (), (GtkWidget*) Glib::unwrap (widget));
  }

  auto
  ExpanderRow::add_row (Gtk::Widget* child) -> void
  {
    adw_expander_row_add_row (gobj (), (GtkWidget*) Glib::unwrap (child));
  }

  auto
  ExpanderRow::get_enable_expansion () const -> bool
  {
    return adw_expander_row_get_enable_expansion (
        const_cast<AdwExpanderRow*> (gobj ()));
  }

  auto
  ExpanderRow::get_expanded () const -> bool
  {
    return adw_expander_row_get_expanded (
        const_cast<AdwExpanderRow*> (gobj ()));
  }

  auto
  ExpanderRow::get_icon_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_expander_row_get_icon_name (const_cast<AdwExpanderRow*> (gobj ())));
  }

  auto
  ExpanderRow::get_show_enable_switch () const -> bool
  {
    return adw_expander_row_get_show_enable_switch (
        const_cast<AdwExpanderRow*> (gobj ()));
  }

  auto
  ExpanderRow::get_subtitle () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_expander_row_get_subtitle (const_cast<AdwExpanderRow*> (gobj ())));
  }

  auto
  ExpanderRow::remove (Gtk::Widget* child) -> void
  {
    adw_expander_row_remove (gobj (), (GtkWidget*) Glib::unwrap (child));
  }

  auto
  ExpanderRow::set_enable_expansion (bool enable_expansion) -> void
  {
    adw_expander_row_set_enable_expansion (gobj (),
                                           static_cast<int> (enable_expansion));
  }

  auto
  ExpanderRow::set_expanded (bool expanded) -> void
  {
    adw_expander_row_set_expanded (gobj (), static_cast<int> (expanded));
  }

  auto
  ExpanderRow::set_icon_name (const Glib::ustring& icon_name) -> void
  {
    adw_expander_row_set_icon_name (gobj (), icon_name.c_str ());
  }

  auto
  ExpanderRow::set_show_enable_switch (bool show_enable_switch) -> void
  {
    adw_expander_row_set_show_enable_switch (
        gobj (),
        static_cast<int> (show_enable_switch));
  }

  auto
  ExpanderRow::set_subtitle (const Glib::ustring& subtitle) -> void
  {
    adw_expander_row_set_subtitle (gobj (), subtitle.c_str ());
  }

  auto
  ExpanderRow::property_enable_expansion () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "enable-expansion");
  }

  auto
  ExpanderRow::property_enable_expansion () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "enable-expansion");
  }

  auto
  ExpanderRow::property_expanded () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "expanded");
  }

  auto
  ExpanderRow::property_expanded () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "expanded");
  }

  auto
  ExpanderRow::property_icon_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "icon-name");
  }

  auto
  ExpanderRow::property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "icon-name");
  }

  auto
  ExpanderRow::property_show_enable_switch () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "show-enable-switch");
  }

  auto
  ExpanderRow::property_show_enable_switch () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "show-enable-switch");
  }

  auto
  ExpanderRow::property_subtitle () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "subtitle");
  }

  auto
  ExpanderRow::property_subtitle () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "subtitle");
  }

} // namespace Adw
