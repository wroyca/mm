// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/boxlayout.hxx>
#include <libmm/gtk/boxlayout_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkBoxLayout* object, bool take_copy) -> glib::RefPtr<gtk::BoxLayout>
  {
    return glib::make_refptr_for_instance<gtk::BoxLayout> (
        dynamic_cast<gtk::BoxLayout*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  BoxLayout_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &BoxLayout_Class::class_init_function;

      gtype_ = gtk_box_layout_get_type ();
    }

    return *this;
  }

  auto
  BoxLayout_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  BoxLayout_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new BoxLayout ((GtkBoxLayout*) object);
  }

  auto
  BoxLayout::gobj_copy () -> GtkBoxLayout*
  {
    reference ();
    return gobj ();
  }

  BoxLayout::BoxLayout (const glib::ConstructParams& construct_params)
    : LayoutManager (construct_params)
  {
  }

  BoxLayout::BoxLayout (GtkBoxLayout* castitem)
    : LayoutManager ((GtkLayoutManager*) (castitem))
  {
  }

  BoxLayout::BoxLayout (BoxLayout&& src) noexcept
    : LayoutManager (std::move (src)),
      Orientable (std::move (src))
  {
  }

  auto
  BoxLayout::operator= (BoxLayout&& src) noexcept -> BoxLayout&
  {
    LayoutManager::operator= (std::move (src));
    Orientable::operator= (std::move (src));
    return *this;
  }

  BoxLayout::~BoxLayout () noexcept {}

  BoxLayout::CppClassType BoxLayout::boxlayout_class_;

  auto
  BoxLayout::get_type () -> GType
  {
    return boxlayout_class_.init ().get_type ();
  }

  auto
  BoxLayout::get_base_type () -> GType
  {
    return gtk_box_layout_get_type ();
  }

  BoxLayout::BoxLayout (Orientation orientation)
    : glib::ObjectBase (nullptr),
      LayoutManager (
          glib::ConstructParams (boxlayout_class_.init (),
                                 "orientation",
                                 static_cast<GtkOrientation> (orientation),
                                 nullptr))
  {
  }

  auto
  BoxLayout::create (Orientation orientation) -> glib::RefPtr<BoxLayout>
  {
    return glib::make_refptr_for_instance<BoxLayout> (
        new BoxLayout (orientation));
  }

  auto
  BoxLayout::set_homogeneous (bool homogeneous) -> void
  {
    gtk_box_layout_set_homogeneous (gobj (), static_cast<int> (homogeneous));
  }

  auto
  BoxLayout::get_homogeneous () const -> bool
  {
    return gtk_box_layout_get_homogeneous (const_cast<GtkBoxLayout*> (gobj ()));
  }

  auto
  BoxLayout::set_spacing (guint spacing) -> void
  {
    gtk_box_layout_set_spacing (gobj (), spacing);
  }

  auto
  BoxLayout::get_spacing () const -> guint
  {
    return gtk_box_layout_get_spacing (const_cast<GtkBoxLayout*> (gobj ()));
  }

  auto
  BoxLayout::set_baseline_position (BaselinePosition position) -> void
  {
    gtk_box_layout_set_baseline_position (
        gobj (),
        static_cast<GtkBaselinePosition> (position));
  }

  auto
  BoxLayout::get_baseline_position () const -> BaselinePosition
  {
    return static_cast<BaselinePosition> (gtk_box_layout_get_baseline_position (
        const_cast<GtkBoxLayout*> (gobj ())));
  }

  auto
  BoxLayout::property_homogeneous () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "homogeneous");
  }

  auto
  BoxLayout::property_homogeneous () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "homogeneous");
  }

  auto
  BoxLayout::property_spacing () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "spacing");
  }

  auto
  BoxLayout::property_spacing () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "spacing");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<BaselinePosition>::value,
      "Type BaselinePosition cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  BoxLayout::property_baseline_position () -> glib::PropertyProxy<BaselinePosition>
  {
    return glib::PropertyProxy<BaselinePosition> (this, "baseline-position");
  }

  auto
  BoxLayout::property_baseline_position () const -> glib::PropertyProxy_ReadOnly<BaselinePosition>
  {
    return glib::PropertyProxy_ReadOnly<BaselinePosition> (this,
                                                           "baseline-position");
  }

} // namespace gtk
