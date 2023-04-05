// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/snapshot.hxx>
#include <libmm/gtk/snapshot_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gdk/cairoutils.hxx>
#include <libmm/gdk/rgba.hxx>
#include <libmm/gdk/texture.hxx>
#include <memory>

namespace
{
  auto
  gdk_rect_to_graphene_rect (const gdk::Rectangle& gdk_rect) -> std::unique_ptr<graphene_rect_t>
  {
    graphene_rect_t* graphene_rect = new graphene_rect_t;
    graphene_rect_init (graphene_rect,
                        gdk_rect.get_x (),
                        gdk_rect.get_y (),
                        gdk_rect.get_width (),
                        gdk_rect.get_height ());
    return std::unique_ptr<graphene_rect_t> (graphene_rect);
  }
} // namespace

namespace gtk
{

  auto
  Snapshot::push_debug (const glib::ustring& name) -> void
  {
    if (name.empty ())
      gtk_snapshot_push_debug (gobj (), nullptr);
    else
      gtk_snapshot_push_debug (gobj (), "%s", name.c_str ());
  }

} // namespace gtk

namespace glib
{

  auto
  wrap_gtk_snapshot (GtkSnapshot* object, bool take_copy) -> glib::RefPtr<gtk::Snapshot>
  {
    return glib::make_refptr_for_instance<gtk::Snapshot> (
        dynamic_cast<gtk::Snapshot*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace
{
}

namespace gtk
{

  auto
  Snapshot_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Snapshot_Class::class_init_function;

      register_derived_type (gtk_snapshot_get_type ());
    }

    return *this;
  }

  auto
  Snapshot_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Snapshot_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Snapshot ((GtkSnapshot*) object);
  }

  auto
  Snapshot::gobj_copy () -> GtkSnapshot*
  {
    reference ();
    return gobj ();
  }

  Snapshot::Snapshot (const glib::ConstructParams& construct_params)
    : gdk::Snapshot (construct_params)
  {
  }

  Snapshot::Snapshot (GtkSnapshot* castitem)
    : gdk::Snapshot ((GdkSnapshot*) (castitem))
  {
  }

  Snapshot::Snapshot (Snapshot&& src) noexcept
    : gdk::Snapshot (std::move (src))
  {
  }

  auto
  Snapshot::operator= (Snapshot&& src) noexcept -> Snapshot&
  {
    gdk::Snapshot::operator= (std::move (src));
    return *this;
  }

  Snapshot::~Snapshot () noexcept {}

  Snapshot::CppClassType Snapshot::snapshot_class_;

  auto
  Snapshot::get_type () -> GType
  {
    return snapshot_class_.init ().get_type ();
  }

  auto
  Snapshot::get_base_type () -> GType
  {
    return gtk_snapshot_get_type ();
  }

  auto
  Snapshot::create () -> glib::RefPtr<Snapshot>
  {
    return glib::wrap_gtk_snapshot (gtk_snapshot_new ());
  }

  auto
  Snapshot::push_opacity (double opacity) -> void
  {
    gtk_snapshot_push_opacity (gobj (), opacity);
  }

  auto
  Snapshot::push_blur (double radius) -> void
  {
    gtk_snapshot_push_blur (gobj (), radius);
  }

  auto
  Snapshot::push_repeat (const graphene_rect_t* bounds,
                         const graphene_rect_t* child_bounds) -> void
  {
    gtk_snapshot_push_repeat (gobj (), bounds, child_bounds);
  }

  auto
  Snapshot::push_repeat (const gdk::Rectangle& bounds,
                         const gdk::Rectangle& child_bounds) -> void
  {
    gtk_snapshot_push_repeat (gobj (),
                              gdk_rect_to_graphene_rect (bounds).get (),
                              gdk_rect_to_graphene_rect (child_bounds).get ());
  }

  auto
  Snapshot::push_repeat (const gdk::Rectangle& bounds) -> void
  {
    gtk_snapshot_push_repeat (gobj (),
                              gdk_rect_to_graphene_rect (bounds).get (),
                              nullptr);
  }

  auto
  Snapshot::push_clip (const graphene_rect_t* bounds) -> void
  {
    gtk_snapshot_push_clip (gobj (), bounds);
  }

  auto
  Snapshot::push_clip (const gdk::Rectangle& bounds) -> void
  {
    gtk_snapshot_push_clip (gobj (), gdk_rect_to_graphene_rect (bounds).get ());
  }

  auto
  Snapshot::push_cross_fade (double progress) -> void
  {
    gtk_snapshot_push_cross_fade (gobj (), progress);
  }

  auto
  Snapshot::gl_shader_pop_texture () -> void
  {
    gtk_snapshot_gl_shader_pop_texture (gobj ());
  }

  auto
  Snapshot::pop () -> void
  {
    gtk_snapshot_pop (gobj ());
  }

  auto
  Snapshot::save () -> void
  {
    gtk_snapshot_save (gobj ());
  }

  auto
  Snapshot::restore () -> void
  {
    gtk_snapshot_restore (gobj ());
  }

  auto
  Snapshot::rotate (float angle) -> void
  {
    gtk_snapshot_rotate (gobj (), angle);
  }

  auto
  Snapshot::scale (float factor_x, float factor_y) -> void
  {
    gtk_snapshot_scale (gobj (), factor_x, factor_y);
  }

  auto
  Snapshot::scale (float factor_x, float factor_y, float factor_z) -> void
  {
    gtk_snapshot_scale_3d (gobj (), factor_x, factor_y, factor_z);
  }

  auto
  Snapshot::perspective (float depth) -> void
  {
    gtk_snapshot_perspective (gobj (), depth);
  }

  auto
  Snapshot::append_cairo (const graphene_rect_t* bounds) -> cairo::RefPtr<cairo::Context>
  {
    return gdk::cairo::wrap (gtk_snapshot_append_cairo (gobj (), bounds));
  }

  auto
  Snapshot::append_cairo (const gdk::Rectangle& bounds) -> cairo::RefPtr<cairo::Context>
  {
    return gdk::cairo::wrap (
        gtk_snapshot_append_cairo (gobj (),
                                   gdk_rect_to_graphene_rect (bounds).get ()));
  }

  auto
  Snapshot::append_texture (const glib::RefPtr<gdk::Texture>& texture,
                            const graphene_rect_t* bounds) -> void
  {
    gtk_snapshot_append_texture (gobj (), glib::unwrap (texture), bounds);
  }

  auto
  Snapshot::append_texture (const glib::RefPtr<gdk::Texture>& texture,
                            const gdk::Rectangle& bounds) -> void
  {
    gtk_snapshot_append_texture (gobj (),
                                 glib::unwrap (texture),
                                 gdk_rect_to_graphene_rect (bounds).get ());
  }

  auto
  Snapshot::append_color (const gdk::RGBA& color, const graphene_rect_t* bounds) -> void
  {
    gtk_snapshot_append_color (gobj (), (color).gobj (), bounds);
  }

  auto
  Snapshot::append_color (const gdk::RGBA& color, const gdk::Rectangle& bounds) -> void
  {
    gtk_snapshot_append_color (gobj (),
                               (color).gobj (),
                               gdk_rect_to_graphene_rect (bounds).get ());
  }

  auto
  Snapshot::append_layout (const glib::RefPtr<pango::Layout>& layout,
                           const gdk::RGBA& color) -> void
  {
    gtk_snapshot_append_layout (gobj (),
                                glib::unwrap (layout),
                                (color).gobj ());
  }

#ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  Snapshot::render_backgrount (const glib::RefPtr<StyleContext>& context,
                               double x,
                               double y,
                               double width,
                               double height) -> void
  {
    gtk_snapshot_render_background (gobj (),
                                    glib::unwrap (context),
                                    x,
                                    y,
                                    width,
                                    height);
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

#ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  Snapshot::render_frame (const glib::RefPtr<StyleContext>& context,
                          double x,
                          double y,
                          double width,
                          double height) -> void
  {
    gtk_snapshot_render_frame (gobj (),
                               glib::unwrap (context),
                               x,
                               y,
                               width,
                               height);
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

#ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  Snapshot::render_focus (const glib::RefPtr<StyleContext>& context,
                          double x,
                          double y,
                          double width,
                          double height) -> void
  {
    gtk_snapshot_render_focus (gobj (),
                               glib::unwrap (context),
                               x,
                               y,
                               width,
                               height);
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

#ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  Snapshot::render_layout (const glib::RefPtr<StyleContext>& context,
                           double x,
                           double y,
                           const glib::RefPtr<pango::Layout>& layout) -> void
  {
    gtk_snapshot_render_layout (gobj (),
                                glib::unwrap (context),
                                x,
                                y,
                                glib::unwrap (layout));
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

#ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  Snapshot::render_insertion_cursor (const glib::RefPtr<StyleContext>& context,
                                     double x,
                                     double y,
                                     const glib::RefPtr<pango::Layout>& layout,
                                     int index,
                                     pango::Direction direction) -> void
  {
    gtk_snapshot_render_insertion_cursor (
        gobj (),
        glib::unwrap (context),
        x,
        y,
        glib::unwrap (layout),
        index,
        static_cast<PangoDirection> (direction));
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

} // namespace gtk
