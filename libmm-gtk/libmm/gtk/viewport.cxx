// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/viewport.hxx>
#include <libmm/gtk/viewport_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gtk/adjustment.hxx>
#include <libmm/gtk/viewport.hxx>

namespace gtk
{

  auto
  Viewport::unset_child () -> void
  {
    gtk_viewport_set_child (gobj (), nullptr);
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkViewport* object, bool take_copy) -> gtk::Viewport*
  {
    return dynamic_cast<gtk::Viewport*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  Viewport_Class::init () -> const glib::Class&
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
  Viewport_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Viewport ((GtkViewport*) (o)));
  }

  Viewport::Viewport (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Viewport::Viewport (GtkViewport* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Viewport::Viewport (Viewport&& src) noexcept
    : gtk::Widget (std::move (src)),
      Scrollable (std::move (src))
  {
  }

  auto
  Viewport::operator= (Viewport&& src) noexcept -> Viewport&
  {
    gtk::Widget::operator= (std::move (src));
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

  Viewport::Viewport (const glib::RefPtr<Adjustment>& hadjustment,
                      const glib::RefPtr<Adjustment>& vadjustment)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (viewport_class_.init (),
                                          "hadjustment",
                                          glib::unwrap (hadjustment),
                                          "vadjustment",
                                          glib::unwrap (vadjustment),
                                          nullptr))
  {
  }

  auto
  Viewport::set_scroll_to_focus (bool scroll_to_focus) -> void
  {
    gtk_viewport_set_scroll_to_focus (gobj (),
                                      static_cast<int> (scroll_to_focus));
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
    gtk_viewport_set_child (gobj (), (child).gobj ());
  }

  auto
  Viewport::get_child () -> Widget*
  {
    return glib::wrap (gtk_viewport_get_child (gobj ()));
  }

  auto
  Viewport::get_child () const -> const Widget*
  {
    return const_cast<Viewport*> (this)->get_child ();
  }

  auto
  Viewport::property_scroll_to_focus () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "scroll-to-focus");
  }

  auto
  Viewport::property_scroll_to_focus () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "scroll-to-focus");
  }

  auto
  Viewport::property_child () -> glib::PropertyProxy<Widget*>
  {
    return glib::PropertyProxy<Widget*> (this, "child");
  }

  auto
  Viewport::property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "child");
  }

} // namespace gtk
