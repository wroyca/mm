// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/stylecontext.hxx>
  #include <libmm/gtk/stylecontext_p.hxx>

  #include <gtk/gtk.h>
  #include <libmm/gdk/texture.hxx>
  #include <libmm/gtk/widget.hxx>

namespace gtk
{

  auto
  StyleContext::get_color () const -> gdk::RGBA
  {
    GdkRGBA crgba;
    gtk_style_context_get_color (const_cast<GtkStyleContext*> (gobj ()),
                                 &crgba);
    return gdk::RGBA (&crgba, true);
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

} // namespace gtk

namespace
{
}

auto
glib::Value<gtk::StyleContext::PrintFlags>::value_type () -> GType
{
  return gtk_style_context_print_flags_get_type ();
}

namespace glib
{

  auto
  wrap (GtkStyleContext* object, bool take_copy) -> glib::RefPtr<gtk::StyleContext>
  {
    return glib::make_refptr_for_instance<gtk::StyleContext> (
        dynamic_cast<gtk::StyleContext*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  StyleContext_Class::init () -> const glib::Class&
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
  StyleContext_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new StyleContext ((GtkStyleContext*) object);
  }

  auto
  StyleContext::gobj_copy () -> GtkStyleContext*
  {
    reference ();
    return gobj ();
  }

  StyleContext::StyleContext (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  StyleContext::StyleContext (GtkStyleContext* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  StyleContext::StyleContext (StyleContext&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  StyleContext::operator= (StyleContext&& src) noexcept -> StyleContext&
  {
    glib::Object::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (stylecontext_class_.init ()))
  {
  }

  #ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  StyleContext::add_provider_for_display (
      const glib::RefPtr<gdk::Display>& display,
      const glib::RefPtr<StyleProvider>& provider,
      guint priority) -> void
  {
    gtk_style_context_add_provider_for_display (glib::unwrap (display),
                                                glib::unwrap (provider),
                                                priority);
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
  #endif

  #ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  StyleContext::remove_provider_for_display (
      const glib::RefPtr<gdk::Display>& display,
      const glib::RefPtr<StyleProvider>& provider) -> void
  {
    gtk_style_context_remove_provider_for_display (glib::unwrap (display),
                                                   glib::unwrap (provider));
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
  #endif

  auto
  StyleContext::add_provider (const glib::RefPtr<StyleProvider>& provider,
                              guint priority) -> void
  {
    gtk_style_context_add_provider (gobj (), glib::unwrap (provider), priority);
  }

  auto
  StyleContext::remove_provider (const glib::RefPtr<StyleProvider>& provider) -> void
  {
    gtk_style_context_remove_provider (gobj (), glib::unwrap (provider));
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
  StyleContext::add_class (const glib::ustring& class_name) -> void
  {
    gtk_style_context_add_class (gobj (), class_name.c_str ());
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
  #endif

  #ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  StyleContext::remove_class (const glib::ustring& class_name) -> void
  {
    gtk_style_context_remove_class (gobj (), class_name.c_str ());
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
  #endif

  #ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  StyleContext::has_class (const glib::ustring& class_name) -> bool
  {
    return gtk_style_context_has_class (gobj (), class_name.c_str ());
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
  #endif

  #ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  StyleContext::set_display (const glib::RefPtr<gdk::Display>& display) -> void
  {
    gtk_style_context_set_display (gobj (), glib::unwrap (display));
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
  #endif

  #ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  StyleContext::get_display () -> glib::RefPtr<gdk::Display>
  {
    auto retvalue = glib::wrap (gtk_style_context_get_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
  #endif

  #ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  StyleContext::get_display () const -> glib::RefPtr<const gdk::Display>
  {
    return const_cast<StyleContext*> (this)->get_display ();
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
  #endif

  auto
  StyleContext::lookup_color (const glib::ustring& color_name, gdk::RGBA& color) -> bool
  {
    return gtk_style_context_lookup_color (gobj (),
                                           color_name.c_str (),
                                           (color).gobj ());
  }

  auto
  StyleContext::render_check (const cairo::RefPtr<cairo::Context>& cr,
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
  StyleContext::render_option (const cairo::RefPtr<cairo::Context>& cr,
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
  StyleContext::render_arrow (const cairo::RefPtr<cairo::Context>& cr,
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
  StyleContext::render_background (const cairo::RefPtr<cairo::Context>& cr,
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
  StyleContext::render_frame (const cairo::RefPtr<cairo::Context>& cr,
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
  StyleContext::render_expander (const cairo::RefPtr<cairo::Context>& cr,
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
  StyleContext::render_focus (const cairo::RefPtr<cairo::Context>& cr,
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
  StyleContext::render_layout (const cairo::RefPtr<cairo::Context>& cr,
                               double x,
                               double y,
                               const glib::RefPtr<pango::Layout>& layout) -> void
  {
    gtk_render_layout (gobj (),
                       ((cr) ? (cr)->cobj () : nullptr),
                       x,
                       y,
                       glib::unwrap (layout));
  }

  auto
  StyleContext::render_line (const cairo::RefPtr<cairo::Context>& cr,
                             double x0,
                             double y0,
                             double x1,
                             double y1) -> void
  {
    gtk_render_line (gobj (), ((cr) ? (cr)->cobj () : nullptr), x0, y0, x1, y1);
  }

  auto
  StyleContext::render_handle (const cairo::RefPtr<cairo::Context>& cr,
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
  StyleContext::render_activity (const cairo::RefPtr<cairo::Context>& cr,
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
  StyleContext::render_icon (const cairo::RefPtr<cairo::Context>& cr,
                             const glib::RefPtr<gdk::Texture>& texture,
                             double x,
                             double y) -> void
  {
    gtk_render_icon (gobj (),
                     ((cr) ? (cr)->cobj () : nullptr),
                     glib::unwrap (texture),
                     x,
                     y);
  }

  auto
  StyleContext::to_string (PrintFlags flags) const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        gtk_style_context_to_string (
            const_cast<GtkStyleContext*> (gobj ()),
            static_cast<GtkStyleContextPrintFlags> (flags)));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gdk::Display>>::value,
      "Type glib::RefPtr<gdk::Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  StyleContext::property_display () -> glib::PropertyProxy<glib::RefPtr<gdk::Display>>
  {
    return glib::PropertyProxy<glib::RefPtr<gdk::Display>> (this, "display");
  }

  auto
  StyleContext::property_display () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Display>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Display>> (this,
                                                                     "display");
  }

} // namespace gtk

#endif
