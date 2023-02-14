

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/viewport.hxx>
#include <libmm-gtk/viewport_p.hxx>

#include <gtk/gtk.h>
#include <libmm-gtk/adjustment.hxx>
#include <libmm-gtk/viewport.hxx>

namespace Gtk
{

  auto
  Viewport::unset_child () -> void
  {
    gtk_viewport_set_child (gobj (), nullptr);
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkViewport* object, const bool take_copy) -> Gtk::Viewport*
  {
    return dynamic_cast<Gtk::Viewport*> (
        wrap_auto ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Viewport_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Viewport_Class::class_init_function;

      register_derived_type (gtk_viewport_get_type ());

      Scrollable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  Viewport_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Viewport_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new Viewport ((GtkViewport*) o));
  }

  Viewport::Viewport (const Glib::ConstructParams& construct_params)
    : Widget (construct_params)
  {
  }

  Viewport::Viewport (GtkViewport* castitem)
    : Widget ((GtkWidget*) castitem)
  {
  }

  Viewport::Viewport (Viewport&& src) noexcept
    : Widget (std::move (src)),
      Scrollable (std::move (src))
  {
  }

  auto
  Viewport::operator= (Viewport&& src) noexcept -> Viewport&
  {
    Widget::operator= (std::move (src));
    Scrollable::operator= (std::move (src));
    return *this;
  }

  Viewport::~Viewport () noexcept
  {
    destroy_ ();
  }

  Viewport::CppClassType Viewport::viewport_class_;

  auto
  Viewport::get_type () -> GType
  {
    return viewport_class_.init ().get_type ();
  }

  auto
  Viewport::get_base_type () -> GType
  {
    return gtk_viewport_get_type ();
  }

  Viewport::Viewport (const Glib::RefPtr<Adjustment>& hadjustment,
                      const Glib::RefPtr<Adjustment>& vadjustment)
    : ObjectBase (nullptr),
      Widget (Glib::ConstructParams (viewport_class_.init (),
                                     "hadjustment",
                                     Glib::unwrap (hadjustment),
                                     "vadjustment",
                                     Glib::unwrap (vadjustment),
                                     nullptr))
  {
  }

  auto
  Viewport::set_scroll_to_focus (const bool scroll_to_focus) -> void
  {
    gtk_viewport_set_scroll_to_focus (gobj (), scroll_to_focus);
  }

  auto
  Viewport::get_scroll_to_focus () const -> bool
  {
    return gtk_viewport_get_scroll_to_focus (
        const_cast<GtkViewport*> (gobj ()));
  }

  auto
  Viewport::set_child (Widget& child) -> void
  {
    gtk_viewport_set_child (gobj (), child.gobj ());
  }

  auto
  Viewport::get_child () -> Widget*
  {
    return Glib::wrap (gtk_viewport_get_child (gobj ()));
  }

  auto
  Viewport::get_child () const -> const Widget*
  {
    return const_cast<Viewport*> (this)->get_child ();
  }

  auto
  Viewport::property_scroll_to_focus () -> Glib::PropertyProxy<bool>
  {
    return {this, "scroll-to-focus"};
  }

  auto
  Viewport::property_scroll_to_focus () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "scroll-to-focus"};
  }

  auto
  Viewport::property_child () -> Glib::PropertyProxy<Widget*>
  {
    return {this, "child"};
  }

  auto
  Viewport::property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>
  {
    return {this, "child"};
  }

} // namespace Gtk
