// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/mm-glib.hxx>

  #include <libmm-gtk/stylecontext.hxx>
  #include <libmm-gtk/stylecontext_p.hxx>

  #include <gtk/gtk.h>
  #include <libmm-gdk/texture.hxx>
  #include <libmm-gtk/widget.hxx>

namespace Gtk
{

  auto
  StyleContext::get_color () const -> Gdk::RGBA
  {
    GdkRGBA crgba;
    gtk_style_context_get_color (const_cast<GtkStyleContext*> (gobj ()),
                                 &crgba);
    return Gdk::RGBA (&crgba, true);
  }

  auto
  StyleContext::get_border () const -> Border
  {
    GtkBorder cborder;
    gtk_style_context_get_border (const_cast<GtkStyleContext*> (gobj ()),
                                  &cborder);
    return Border (&cborder, true);
  }

  auto
  StyleContext::get_padding () const -> Border
  {
    GtkBorder cborder;
    gtk_style_context_get_padding (const_cast<GtkStyleContext*> (gobj ()),
                                   &cborder);
    return Border (&cborder, true);
  }

  auto
  StyleContext::get_margin () const -> Border
  {
    GtkBorder cborder;
    gtk_style_context_get_margin (const_cast<GtkStyleContext*> (gobj ()),
                                  &cborder);
    return Border (&cborder, true);
  }

} // namespace Gtk

namespace
{
}

auto
Glib::Value<Gtk::StyleContext::PrintFlags>::value_type () -> GType
{
  return gtk_style_context_print_flags_get_type ();
}

namespace Glib
{

  auto
  wrap (GtkStyleContext* object, bool take_copy) -> Glib::RefPtr<Gtk::StyleContext>
  {
    return Glib::make_refptr_for_instance<Gtk::StyleContext> (
        dynamic_cast<Gtk::StyleContext*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  StyleContext_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &StyleContext_Class::class_init_function;

      register_derived_type (gtk_style_context_get_type ());
    }

    return *this;
  }

  auto
  StyleContext_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  StyleContext_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new StyleContext ((GtkStyleContext*) object);
  }

  auto
  StyleContext::gobj_copy () -> GtkStyleContext*
  {
    reference ();
    return gobj ();
  }

  StyleContext::StyleContext (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  StyleContext::StyleContext (GtkStyleContext* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  StyleContext::StyleContext (StyleContext&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  StyleContext::operator= (StyleContext&& src) noexcept -> StyleContext&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  StyleContext::~StyleContext () noexcept {}

  StyleContext::CppClassType StyleContext::stylecontext_class_;

  auto
  StyleContext::get_type () -> GType
  {
    return stylecontext_class_.init ().get_type ();
  }

  auto
  StyleContext::get_base_type () -> GType
  {
    return gtk_style_context_get_type ();
  }

  StyleContext::StyleContext ()
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (stylecontext_class_.init ()))
  {
  }

  #ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  StyleContext::add_provider_for_display (
      const Glib::RefPtr<Gdk::Display>& display,
      const Glib::RefPtr<StyleProvider>& provider,
      guint priority) -> void
  {
    gtk_style_context_add_provider_for_display (Glib::unwrap (display),
                                                Glib::unwrap (provider),
                                                priority);
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
  #endif

  #ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  StyleContext::remove_provider_for_display (
      const Glib::RefPtr<Gdk::Display>& display,
      const Glib::RefPtr<StyleProvider>& provider) -> void
  {
    gtk_style_context_remove_provider_for_display (Glib::unwrap (display),
                                                   Glib::unwrap (provider));
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
  #endif

  auto
  StyleContext::add_provider (const Glib::RefPtr<StyleProvider>& provider,
                              guint priority) -> void
  {
    gtk_style_context_add_provider (gobj (), Glib::unwrap (provider), priority);
  }

  auto
  StyleContext::remove_provider (const Glib::RefPtr<StyleProvider>& provider) -> void
  {
    gtk_style_context_remove_provider (gobj (), Glib::unwrap (provider));
  }

  auto
  StyleContext::context_save () -> void
  {
    gtk_style_context_save (gobj ());
  }

  auto
  StyleContext::context_restore () -> void
  {
    gtk_style_context_restore (gobj ());
  }

  #ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  StyleContext::set_state (StateFlags flags) -> void
  {
    gtk_style_context_set_state (gobj (), static_cast<GtkStateFlags> (flags));
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
  #endif

  #ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  StyleContext::get_state () const -> StateFlags
  {
    return static_cast<StateFlags> (
        gtk_style_context_get_state (const_cast<GtkStyleContext*> (gobj ())));
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
  #endif

  #ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  StyleContext::set_scale (int scale) -> void
  {
    gtk_style_context_set_scale (gobj (), scale);
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
  #endif

  #ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  StyleContext::get_scale () const -> int
  {
    return gtk_style_context_get_scale (const_cast<GtkStyleContext*> (gobj ()));
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
  #endif

  #ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  StyleContext::add_class (const Glib::ustring& class_name) -> void
  {
    gtk_style_context_add_class (gobj (), class_name.c_str ());
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
  #endif

  #ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  StyleContext::remove_class (const Glib::ustring& class_name) -> void
  {
    gtk_style_context_remove_class (gobj (), class_name.c_str ());
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
  #endif

  #ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  StyleContext::has_class (const Glib::ustring& class_name) -> bool
  {
    return gtk_style_context_has_class (gobj (), class_name.c_str ());
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
  #endif

  #ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  StyleContext::set_display (const Glib::RefPtr<Gdk::Display>& display) -> void
  {
    gtk_style_context_set_display (gobj (), Glib::unwrap (display));
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
  #endif

  #ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  StyleContext::get_display () -> Glib::RefPtr<Gdk::Display>
  {
    auto retvalue = Glib::wrap (gtk_style_context_get_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
  #endif

  #ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  StyleContext::get_display () const -> Glib::RefPtr<const Gdk::Display>
  {
    return const_cast<StyleContext*> (this)->get_display ();
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
  #endif

  auto
  StyleContext::lookup_color (const Glib::ustring& color_name, Gdk::RGBA& color) -> bool
  {
    return gtk_style_context_lookup_color (gobj (),
                                           color_name.c_str (),
                                           (color).gobj ());
  }

  auto
  StyleContext::render_check (const Cairo::RefPtr<Cairo::Context>& cr,
                              double x,
                              double y,
                              double width,
                              double height) -> void
  {
    gtk_render_check (gobj (),
                      ((cr) ? (cr)->cobj () : nullptr),
                      x,
                      y,
                      width,
                      height);
  }

  auto
  StyleContext::render_option (const Cairo::RefPtr<Cairo::Context>& cr,
                               double x,
                               double y,
                               double width,
                               double height) -> void
  {
    gtk_render_option (gobj (),
                       ((cr) ? (cr)->cobj () : nullptr),
                       x,
                       y,
                       width,
                       height);
  }

  auto
  StyleContext::render_arrow (const Cairo::RefPtr<Cairo::Context>& cr,
                              double angle,
                              double x,
                              double y,
                              double size) -> void
  {
    gtk_render_arrow (gobj (),
                      ((cr) ? (cr)->cobj () : nullptr),
                      angle,
                      x,
                      y,
                      size);
  }

  auto
  StyleContext::render_background (const Cairo::RefPtr<Cairo::Context>& cr,
                                   double x,
                                   double y,
                                   double width,
                                   double height) -> void
  {
    gtk_render_background (gobj (),
                           ((cr) ? (cr)->cobj () : nullptr),
                           x,
                           y,
                           width,
                           height);
  }

  auto
  StyleContext::render_frame (const Cairo::RefPtr<Cairo::Context>& cr,
                              double x,
                              double y,
                              double width,
                              double height) -> void
  {
    gtk_render_frame (gobj (),
                      ((cr) ? (cr)->cobj () : nullptr),
                      x,
                      y,
                      width,
                      height);
  }

  auto
  StyleContext::render_expander (const Cairo::RefPtr<Cairo::Context>& cr,
                                 double x,
                                 double y,
                                 double width,
                                 double height) -> void
  {
    gtk_render_expander (gobj (),
                         ((cr) ? (cr)->cobj () : nullptr),
                         x,
                         y,
                         width,
                         height);
  }

  auto
  StyleContext::render_focus (const Cairo::RefPtr<Cairo::Context>& cr,
                              double x,
                              double y,
                              double width,
                              double height) -> void
  {
    gtk_render_focus (gobj (),
                      ((cr) ? (cr)->cobj () : nullptr),
                      x,
                      y,
                      width,
                      height);
  }

  auto
  StyleContext::render_layout (const Cairo::RefPtr<Cairo::Context>& cr,
                               double x,
                               double y,
                               const Glib::RefPtr<Pango::Layout>& layout) -> void
  {
    gtk_render_layout (gobj (),
                       ((cr) ? (cr)->cobj () : nullptr),
                       x,
                       y,
                       Glib::unwrap (layout));
  }

  auto
  StyleContext::render_line (const Cairo::RefPtr<Cairo::Context>& cr,
                             double x0,
                             double y0,
                             double x1,
                             double y1) -> void
  {
    gtk_render_line (gobj (), ((cr) ? (cr)->cobj () : nullptr), x0, y0, x1, y1);
  }

  auto
  StyleContext::render_handle (const Cairo::RefPtr<Cairo::Context>& cr,
                               double x,
                               double y,
                               double width,
                               double height) -> void
  {
    gtk_render_handle (gobj (),
                       ((cr) ? (cr)->cobj () : nullptr),
                       x,
                       y,
                       width,
                       height);
  }

  auto
  StyleContext::render_activity (const Cairo::RefPtr<Cairo::Context>& cr,
                                 double x,
                                 double y,
                                 double width,
                                 double height) -> void
  {
    gtk_render_activity (gobj (),
                         ((cr) ? (cr)->cobj () : nullptr),
                         x,
                         y,
                         width,
                         height);
  }

  auto
  StyleContext::render_icon (const Cairo::RefPtr<Cairo::Context>& cr,
                             const Glib::RefPtr<Gdk::Texture>& texture,
                             double x,
                             double y) -> void
  {
    gtk_render_icon (gobj (),
                     ((cr) ? (cr)->cobj () : nullptr),
                     Glib::unwrap (texture),
                     x,
                     y);
  }

  auto
  StyleContext::to_string (PrintFlags flags) const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        gtk_style_context_to_string (
            const_cast<GtkStyleContext*> (gobj ()),
            static_cast<GtkStyleContextPrintFlags> (flags)));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gdk::Display>>::value,
      "Type Glib::RefPtr<Gdk::Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  StyleContext::property_display () -> Glib::PropertyProxy<Glib::RefPtr<Gdk::Display>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gdk::Display>> (this, "display");
  }

  auto
  StyleContext::property_display () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Display>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Display>> (this,
                                                                     "display");
  }

} // namespace Gtk

#endif
