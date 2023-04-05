// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/actionbar.hxx>
#include <libmm/gtk/actionbar_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  auto
  ActionBar::unset_center_widget () -> void
  {
    gtk_action_bar_set_center_widget (gobj (), nullptr);
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkActionBar* object, bool take_copy) -> gtk::ActionBar*
  {
    return dynamic_cast<gtk::ActionBar*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  ActionBar_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ActionBar_Class::class_init_function;

      register_derived_type (gtk_action_bar_get_type ());
    }

    return *this;
  }

  auto
  ActionBar_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ActionBar_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new ActionBar ((GtkActionBar*) (o)));
  }

  ActionBar::ActionBar (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  ActionBar::ActionBar (GtkActionBar* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  ActionBar::ActionBar (ActionBar&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  ActionBar::operator= (ActionBar&& src) noexcept -> ActionBar&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  ActionBar::~ActionBar () noexcept
  {
    destroy_ ();
  }

  ActionBar::CppClassType ActionBar::actionbar_class_;

  auto
  ActionBar::get_type () -> GType
  {
    return actionbar_class_.init ().get_type ();
  }

  auto
  ActionBar::get_base_type () -> GType
  {
    return gtk_action_bar_get_type ();
  }

  ActionBar::ActionBar ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (actionbar_class_.init ()))
  {
  }

  auto
  ActionBar::pack_start (gtk::Widget& child) -> void
  {
    gtk_action_bar_pack_start (gobj (), (child).gobj ());
  }

  auto
  ActionBar::pack_end (gtk::Widget& child) -> void
  {
    gtk_action_bar_pack_end (gobj (), (child).gobj ());
  }

  auto
  ActionBar::remove (gtk::Widget& child) -> void
  {
    gtk_action_bar_remove (gobj (), (child).gobj ());
  }

  auto
  ActionBar::get_center_widget () -> Widget*
  {
    return glib::wrap (gtk_action_bar_get_center_widget (gobj ()));
  }

  auto
  ActionBar::get_center_widget () const -> const Widget*
  {
    return const_cast<ActionBar*> (this)->get_center_widget ();
  }

  auto
  ActionBar::set_center_widget (Widget& center_widget) -> void
  {
    gtk_action_bar_set_center_widget (gobj (), (center_widget).gobj ());
  }

  auto
  ActionBar::set_revealed (bool revealed) -> void
  {
    gtk_action_bar_set_revealed (gobj (), static_cast<int> (revealed));
  }

  auto
  ActionBar::get_revealed () const -> bool
  {
    return gtk_action_bar_get_revealed (const_cast<GtkActionBar*> (gobj ()));
  }

  auto
  ActionBar::property_revealed () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "revealed");
  }

  auto
  ActionBar::property_revealed () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "revealed");
  }

} // namespace gtk
