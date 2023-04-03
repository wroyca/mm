// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/centerbox.hxx>
#include <libmm/gtk/centerbox_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{
  auto
  CenterBox::unset_start_widget () -> void
  {
    gtk_center_box_set_start_widget (gobj (), nullptr);
  }

  auto
  CenterBox::unset_center_widget () -> void
  {
    gtk_center_box_set_center_widget (gobj (), nullptr);
  }

  auto
  CenterBox::unset_end_widget () -> void
  {
    gtk_center_box_set_end_widget (gobj (), nullptr);
  }
} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkCenterBox* object, bool take_copy) -> Gtk::CenterBox*
  {
    return dynamic_cast<Gtk::CenterBox*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  CenterBox_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &CenterBox_Class::class_init_function;

      register_derived_type (gtk_center_box_get_type ());

      Orientable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  CenterBox_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  CenterBox_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new CenterBox ((GtkCenterBox*) (o)));
  }

  CenterBox::CenterBox (const Glib::ConstructParams& construct_params)
    : Widget (construct_params)
  {
  }

  CenterBox::CenterBox (GtkCenterBox* castitem)
    : Widget ((GtkWidget*) (castitem))
  {
  }

  CenterBox::CenterBox (CenterBox&& src) noexcept
    : Widget (std::move (src)),
      Orientable (std::move (src))
  {
  }

  auto
  CenterBox::operator= (CenterBox&& src) noexcept -> CenterBox&
  {
    Widget::operator= (std::move (src));
    Orientable::operator= (std::move (src));
    return *this;
  }

  CenterBox::~CenterBox () noexcept
  {
    destroy_ ();
  }

  CenterBox::CppClassType CenterBox::centerbox_class_;

  auto
  CenterBox::get_type () -> GType
  {
    return centerbox_class_.init ().get_type ();
  }

  auto
  CenterBox::get_base_type () -> GType
  {
    return gtk_center_box_get_type ();
  }

  CenterBox::CenterBox ()
    : Glib::ObjectBase (nullptr),
      Widget (Glib::ConstructParams (centerbox_class_.init ()))
  {
  }

  auto
  CenterBox::set_start_widget (Widget& child) -> void
  {
    gtk_center_box_set_start_widget (gobj (), (child).gobj ());
  }

  auto
  CenterBox::get_start_widget () -> Widget*
  {
    return Glib::wrap (gtk_center_box_get_start_widget (gobj ()));
  }

  auto
  CenterBox::get_start_widget () const -> const Widget*
  {
    return const_cast<CenterBox*> (this)->get_start_widget ();
  }

  auto
  CenterBox::set_center_widget (Widget& child) -> void
  {
    gtk_center_box_set_center_widget (gobj (), (child).gobj ());
  }

  auto
  CenterBox::get_center_widget () -> Widget*
  {
    return Glib::wrap (gtk_center_box_get_center_widget (gobj ()));
  }

  auto
  CenterBox::get_center_widget () const -> const Widget*
  {
    return const_cast<CenterBox*> (this)->get_center_widget ();
  }

  auto
  CenterBox::set_end_widget (Widget& child) -> void
  {
    gtk_center_box_set_end_widget (gobj (), (child).gobj ());
  }

  auto
  CenterBox::get_end_widget () -> Widget*
  {
    return Glib::wrap (gtk_center_box_get_end_widget (gobj ()));
  }

  auto
  CenterBox::get_end_widget () const -> const Widget*
  {
    return const_cast<CenterBox*> (this)->get_end_widget ();
  }

  auto
  CenterBox::set_baseline_position (BaselinePosition position) -> void
  {
    gtk_center_box_set_baseline_position (
        gobj (),
        static_cast<GtkBaselinePosition> (position));
  }

  auto
  CenterBox::get_baseline_position () -> BaselinePosition
  {
    return static_cast<BaselinePosition> (
        gtk_center_box_get_baseline_position (gobj ()));
  }

  auto
  CenterBox::property_start_widget () -> Glib::PropertyProxy<Widget*>
  {
    return Glib::PropertyProxy<Widget*> (this, "start-widget");
  }

  auto
  CenterBox::property_start_widget () const -> Glib::PropertyProxy_ReadOnly<Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Widget*> (this, "start-widget");
  }

  auto
  CenterBox::property_center_widget () -> Glib::PropertyProxy<Widget*>
  {
    return Glib::PropertyProxy<Widget*> (this, "center-widget");
  }

  auto
  CenterBox::property_center_widget () const -> Glib::PropertyProxy_ReadOnly<Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Widget*> (this, "center-widget");
  }

  auto
  CenterBox::property_end_widget () -> Glib::PropertyProxy<Widget*>
  {
    return Glib::PropertyProxy<Widget*> (this, "end-widget");
  }

  auto
  CenterBox::property_end_widget () const -> Glib::PropertyProxy_ReadOnly<Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Widget*> (this, "end-widget");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<BaselinePosition>::value,
      "Type BaselinePosition cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  CenterBox::property_baseline_position () -> Glib::PropertyProxy<BaselinePosition>
  {
    return Glib::PropertyProxy<BaselinePosition> (this, "baseline-position");
  }

  auto
  CenterBox::property_baseline_position () const -> Glib::PropertyProxy_ReadOnly<BaselinePosition>
  {
    return Glib::PropertyProxy_ReadOnly<BaselinePosition> (this,
                                                           "baseline-position");
  }

} // namespace Gtk
