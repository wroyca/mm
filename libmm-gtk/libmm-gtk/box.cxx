// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/box.hxx>
#include <libmm-gtk/box_p.hxx>

#include <gtk/gtk.h>
#include <libmm-glib/wrap.hxx>

namespace Gtk
{
  auto
  Box::insert_child_at_start (Widget& child) -> void
  {
    gtk_box_insert_child_after (gobj (), child.gobj (), nullptr);
  }

  auto
  Box::reorder_child_at_start (Widget& child) -> void
  {
    gtk_box_reorder_child_after (gobj (), child.gobj (), nullptr);
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkBox* object, const bool take_copy) -> Gtk::Box*
  {
    return dynamic_cast<Gtk::Box*> (wrap_auto ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Box_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Box_Class::class_init_function;

      register_derived_type (gtk_box_get_type ());

      Orientable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  Box_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Box_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new Box ((GtkBox*) o));
  }

  Box::Box (const Glib::ConstructParams& construct_params)
    : Widget (construct_params)
  {
  }

  Box::Box (GtkBox* castitem)
    : Widget ((GtkWidget*) castitem)
  {
  }

  Box::Box (Box&& src) noexcept
    : Widget (std::move (src)),
      Orientable (std::move (src))
  {
  }

  auto
  Box::operator= (Box&& src) noexcept -> Box&
  {
    Widget::operator= (std::move (src));
    Orientable::operator= (std::move (src));
    return *this;
  }

  Box::~Box () noexcept
  {
    destroy_ ();
  }

  Box::CppClassType Box::box_class_;

  auto
  Box::get_type () -> GType
  {
    return box_class_.init ().get_type ();
  }

  auto
  Box::get_base_type () -> GType
  {
    return gtk_box_get_type ();
  }

  Box::Box (const Orientation orientation, const int spacing)
    : ObjectBase (nullptr),
      Widget (Glib::ConstructParams (box_class_.init (),
                                     "orientation",
                                     orientation,
                                     "spacing",
                                     spacing,
                                     nullptr))
  {
  }

  auto
  Box::set_homogeneous (const bool homogeneous) -> void
  {
    gtk_box_set_homogeneous (gobj (), homogeneous);
  }

  auto
  Box::get_homogeneous () const -> bool
  {
    return gtk_box_get_homogeneous (const_cast<GtkBox*> (gobj ()));
  }

  auto
  Box::set_spacing (const int spacing) -> void
  {
    gtk_box_set_spacing (gobj (), spacing);
  }

  auto
  Box::get_spacing () const -> int
  {
    return gtk_box_get_spacing (const_cast<GtkBox*> (gobj ()));
  }

  auto
  Box::set_baseline_position (BaselinePosition position) -> void
  {
    gtk_box_set_baseline_position (gobj (),
                                   static_cast<GtkBaselinePosition> (position));
  }

  auto
  Box::get_baseline_position () const -> BaselinePosition
  {
    return static_cast<BaselinePosition> (
        gtk_box_get_baseline_position (const_cast<GtkBox*> (gobj ())));
  }

  auto
  Box::append (Widget& child) -> void
  {
    gtk_box_append (gobj (), child.gobj ());
  }

  auto
  Box::prepend (Widget& child) -> void
  {
    gtk_box_prepend (gobj (), child.gobj ());
  }

  auto
  Box::remove (Widget& child) -> void
  {
    gtk_box_remove (gobj (), child.gobj ());
  }

  auto
  Box::insert_child_after (Widget& child, const Widget& sibling) -> void
  {
    gtk_box_insert_child_after (gobj (),
                                child.gobj (),
                                const_cast<GtkWidget*> (sibling.gobj ()));
  }

  auto
  Box::reorder_child_after (Widget& child, const Widget& sibling) -> void
  {
    gtk_box_reorder_child_after (gobj (),
                                 child.gobj (),
                                 const_cast<GtkWidget*> (sibling.gobj ()));
  }

  auto
  Box::property_spacing () -> Glib::PropertyProxy<int>
  {
    return {this, "spacing"};
  }

  auto
  Box::property_spacing () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "spacing"};
  }

  auto
  Box::property_homogeneous () -> Glib::PropertyProxy<bool>
  {
    return {this, "homogeneous"};
  }

  auto
  Box::property_homogeneous () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "homogeneous"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<BaselinePosition>::value,
      "Type BaselinePosition cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Box::property_baseline_position () -> Glib::PropertyProxy<BaselinePosition>
  {
    return {this, "baseline-position"};
  }

  auto
  Box::property_baseline_position () const -> Glib::PropertyProxy_ReadOnly<BaselinePosition>
  {
    return {this, "baseline-position"};
  }

} // namespace Gtk
