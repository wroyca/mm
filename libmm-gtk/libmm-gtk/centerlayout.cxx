

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/centerlayout.hxx>
#include <libmm-gtk/centerlayout_p.hxx>

#include <gtk/gtk.h>
#include <libmm-gtk/widget.hxx>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkCenterLayout* object, const bool take_copy) -> RefPtr<Gtk::CenterLayout>
  {
    return Glib::make_refptr_for_instance<Gtk::CenterLayout> (
        dynamic_cast<Gtk::CenterLayout*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  CenterLayout_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &CenterLayout_Class::class_init_function;

      gtype_ = gtk_center_layout_get_type ();
    }

    return *this;
  }

  auto
  CenterLayout_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  CenterLayout_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new CenterLayout ((GtkCenterLayout*) object);
  }

  auto
  CenterLayout::gobj_copy () -> GtkCenterLayout*
  {
    reference ();
    return gobj ();
  }

  CenterLayout::CenterLayout (const Glib::ConstructParams& construct_params)
    : LayoutManager (construct_params)
  {
  }

  CenterLayout::CenterLayout (GtkCenterLayout* castitem)
    : LayoutManager ((GtkLayoutManager*) castitem)
  {
  }

  CenterLayout::CenterLayout (CenterLayout&& src) noexcept
    : LayoutManager (std::move (src))
  {
  }

  auto
  CenterLayout::operator= (CenterLayout&& src) noexcept -> CenterLayout&
  {
    LayoutManager::operator= (std::move (src));
    return *this;
  }

  CenterLayout::~CenterLayout () noexcept = default;

  CenterLayout::CppClassType CenterLayout::centerlayout_class_;

  auto
  CenterLayout::get_type () -> GType
  {
    return centerlayout_class_.init ().get_type ();
  }

  auto
  CenterLayout::get_base_type () -> GType
  {
    return gtk_center_layout_get_type ();
  }

  CenterLayout::CenterLayout ()
    : ObjectBase (nullptr),
      LayoutManager (Glib::ConstructParams (centerlayout_class_.init ()))
  {
  }

  auto
  CenterLayout::create () -> Glib::RefPtr<CenterLayout>
  {
    return Glib::make_refptr_for_instance<CenterLayout> (new CenterLayout ());
  }

  auto
  CenterLayout::set_orientation (Orientation orientation) -> void
  {
    gtk_center_layout_set_orientation (
        gobj (),
        static_cast<GtkOrientation> (orientation));
  }

  auto
  CenterLayout::get_orientation () const -> Orientation
  {
    return static_cast<Orientation> (gtk_center_layout_get_orientation (
        const_cast<GtkCenterLayout*> (gobj ())));
  }

  auto
  CenterLayout::set_baseline_position (BaselinePosition baseline_position) -> void
  {
    gtk_center_layout_set_baseline_position (
        gobj (),
        static_cast<GtkBaselinePosition> (baseline_position));
  }

  auto
  CenterLayout::get_baseline_position () const -> BaselinePosition
  {
    return static_cast<BaselinePosition> (
        gtk_center_layout_get_baseline_position (
            const_cast<GtkCenterLayout*> (gobj ())));
  }

  auto
  CenterLayout::set_start_widget (Widget* widget) -> void
  {
    gtk_center_layout_set_start_widget (gobj (), Glib::unwrap (widget));
  }

  auto
  CenterLayout::get_start_widget () -> Widget*
  {
    return Glib::wrap (gtk_center_layout_get_start_widget (gobj ()));
  }

  auto
  CenterLayout::get_start_widget () const -> const Widget*
  {
    return const_cast<CenterLayout*> (this)->get_start_widget ();
  }

  auto
  CenterLayout::set_center_widget (Widget* widget) -> void
  {
    gtk_center_layout_set_center_widget (gobj (), Glib::unwrap (widget));
  }

  auto
  CenterLayout::get_center_widget () -> Widget*
  {
    return Glib::wrap (gtk_center_layout_get_center_widget (gobj ()));
  }

  auto
  CenterLayout::get_center_widget () const -> const Widget*
  {
    return const_cast<CenterLayout*> (this)->get_center_widget ();
  }

  auto
  CenterLayout::set_end_widget (Widget* widget) -> void
  {
    gtk_center_layout_set_end_widget (gobj (), Glib::unwrap (widget));
  }

  auto
  CenterLayout::get_end_widget () -> Widget*
  {
    return Glib::wrap (gtk_center_layout_get_end_widget (gobj ()));
  }

  auto
  CenterLayout::get_end_widget () const -> const Widget*
  {
    return const_cast<CenterLayout*> (this)->get_end_widget ();
  }

} // namespace Gtk
