// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/box.hxx>
#include <libmm/gtk/box_p.hxx>

#include <gtk/gtk.h>
#include <libmm/glib/wrap.hxx>

namespace gtk
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

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkBox* object, bool take_copy) -> gtk::Box*
  {
    return dynamic_cast<gtk::Box*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  Box_Class::init () -> const glib::Class&
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
  Box_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Box ((GtkBox*) (o)));
  }

  Box::Box (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Box::Box (GtkBox* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Box::Box (Box&& src) noexcept
    : gtk::Widget (std::move (src)),
      Orientable (std::move (src))
  {
  }

  auto
  Box::operator= (Box&& src) noexcept -> Box&
  {
    gtk::Widget::operator= (std::move (src));
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

  Box::Box (Orientation orientation, int spacing)
    : glib::ObjectBase (nullptr),
      gtk::Widget (
          glib::ConstructParams (box_class_.init (),
                                 "orientation",
                                 static_cast<GtkOrientation> (orientation),
                                 "spacing",
                                 spacing,
                                 nullptr))
  {
  }

  auto
  Box::set_homogeneous (bool homogeneous) -> void
  {
    gtk_box_set_homogeneous (gobj (), static_cast<int> (homogeneous));
  }

  auto
  Box::get_homogeneous () const -> bool
  {
    return gtk_box_get_homogeneous (const_cast<GtkBox*> (gobj ()));
  }

  auto
  Box::set_spacing (int spacing) -> void
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
  Box::append (gtk::Widget& child) -> void
  {
    gtk_box_append (gobj (), (child).gobj ());
  }

  auto
  Box::prepend (gtk::Widget& child) -> void
  {
    gtk_box_prepend (gobj (), (child).gobj ());
  }

  auto
  Box::remove (gtk::Widget& child) -> void
  {
    gtk_box_remove (gobj (), (child).gobj ());
  }

  auto
  Box::insert_child_after (Widget& child, const Widget& sibling) -> void
  {
    gtk_box_insert_child_after (gobj (),
                                (child).gobj (),
                                const_cast<GtkWidget*> ((sibling).gobj ()));
  }

  auto
  Box::reorder_child_after (Widget& child, const Widget& sibling) -> void
  {
    gtk_box_reorder_child_after (gobj (),
                                 (child).gobj (),
                                 const_cast<GtkWidget*> ((sibling).gobj ()));
  }

  auto
  Box::property_spacing () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "spacing");
  }

  auto
  Box::property_spacing () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "spacing");
  }

  auto
  Box::property_homogeneous () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "homogeneous");
  }

  auto
  Box::property_homogeneous () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "homogeneous");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<BaselinePosition>::value,
      "Type BaselinePosition cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Box::property_baseline_position () -> glib::PropertyProxy<BaselinePosition>
  {
    return glib::PropertyProxy<BaselinePosition> (this, "baseline-position");
  }

  auto
  Box::property_baseline_position () const -> glib::PropertyProxy_ReadOnly<BaselinePosition>
  {
    return glib::PropertyProxy_ReadOnly<BaselinePosition> (this,
                                                           "baseline-position");
  }

} // namespace gtk
