// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/tooltip.hxx>
#include <libmm/gtk/tooltip_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  auto
  Tooltip::unset_markup () -> void
  {
    gtk_tooltip_set_markup (gobj (), nullptr);
  }

  auto
  Tooltip::unset_text () -> void
  {
    gtk_tooltip_set_text (gobj (), nullptr);
  }

  auto
  Tooltip::unset_icon () -> void
  {
    gtk_tooltip_set_icon (gobj (), nullptr);
  }

  auto
  Tooltip::unset_custom () -> void
  {
    gtk_tooltip_set_custom (gobj (), nullptr);
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkTooltip* object, bool take_copy) -> glib::RefPtr<gtk::Tooltip>
  {
    return glib::make_refptr_for_instance<gtk::Tooltip> (
        dynamic_cast<gtk::Tooltip*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  Tooltip_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Tooltip_Class::class_init_function;

      register_derived_type (gtk_tooltip_get_type ());
    }

    return *this;
  }

  auto
  Tooltip_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Tooltip_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Tooltip ((GtkTooltip*) object);
  }

  auto
  Tooltip::gobj_copy () -> GtkTooltip*
  {
    reference ();
    return gobj ();
  }

  Tooltip::Tooltip (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  Tooltip::Tooltip (GtkTooltip* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  Tooltip::Tooltip (Tooltip&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  Tooltip::operator= (Tooltip&& src) noexcept -> Tooltip&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  Tooltip::~Tooltip () noexcept {}

  Tooltip::CppClassType Tooltip::tooltip_class_;

  auto
  Tooltip::get_type () -> GType
  {
    return tooltip_class_.init ().get_type ();
  }

  auto
  Tooltip::get_base_type () -> GType
  {
    return gtk_tooltip_get_type ();
  }

  auto
  Tooltip::set_markup (const glib::ustring& markup) -> void
  {
    gtk_tooltip_set_markup (gobj (), markup.c_str ());
  }

  auto
  Tooltip::set_text (const glib::ustring& text) -> void
  {
    gtk_tooltip_set_text (gobj (), text.c_str ());
  }

  auto
  Tooltip::set_icon (const glib::RefPtr<gdk::Paintable>& paintable) -> void
  {
    gtk_tooltip_set_icon (gobj (), glib::unwrap (paintable));
  }

  auto
  Tooltip::set_icon (const glib::RefPtr<gio::Icon>& gicon) -> void
  {
    gtk_tooltip_set_icon_from_gicon (
        gobj (),
        const_cast<GIcon*> (glib::unwrap<gio::Icon> (gicon)));
  }

  auto
  Tooltip::set_icon (const glib::ustring& icon_name) -> void
  {
    gtk_tooltip_set_icon_from_icon_name (
        gobj (),
        icon_name.empty () ? nullptr : icon_name.c_str ());
  }

  auto
  Tooltip::set_custom (Widget& custom_widget) -> void
  {
    gtk_tooltip_set_custom (gobj (), (custom_widget).gobj ());
  }

  auto
  Tooltip::set_tip_area (const gdk::Rectangle& rect) -> void
  {
    gtk_tooltip_set_tip_area (gobj (), (rect).gobj ());
  }

} // namespace gtk
