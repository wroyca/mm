// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/snapshot.hxx>
#include <libmm-gtk/snapshot_p.hxx>

#include <gtk/gtk.h>
#include <libmm-gdk/cairoutils.hxx>
#include <libmm-gdk/rgba.hxx>
#include <libmm-gdk/texture.hxx>
#include <memory>

namespace
{
  auto
  gdk_rect_to_graphene_rect (const Gdk::Rectangle& gdk_rect) -> std::unique_ptr<graphene_rect_t>
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

namespace Gtk
{

  auto
  Snapshot::push_debug (const Glib::ustring& name) -> void
  {
    if (name.empty ())
      gtk_snapshot_push_debug (gobj (), nullptr);
    else
      gtk_snapshot_push_debug (gobj (), "%s", name.c_str ());
  }

} // namespace Gtk

namespace Glib
{

  auto
  wrap_gtk_snapshot (GtkSnapshot* object, const bool take_copy) -> RefPtr<Gtk::Snapshot>
  {
    return Glib::make_refptr_for_instance<Gtk::Snapshot> (
        dynamic_cast<Gtk::Snapshot*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace
{
}

namespace Gtk
{

  auto
  Snapshot_Class::init () -> const Class&
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
  Snapshot_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Snapshot ((GtkSnapshot*) object);
  }

  auto
  Snapshot::gobj_copy () -> GtkSnapshot*
  {
    reference ();
    return gobj ();
  }

  Snapshot::Snapshot (const Glib::ConstructParams& construct_params)
    : Gdk::Snapshot (construct_params)
  {
  }

  Snapshot::Snapshot (GtkSnapshot* castitem)
    : Gdk::Snapshot (castitem)
  {
  }

  Snapshot::Snapshot (Snapshot&& src) noexcept
    : Gdk::Snapshot (std::move (src))
  {
  }

  auto
  Snapshot::operator= (Snapshot&& src) noexcept -> Snapshot&
  {
    Gdk::Snapshot::operator= (std::move (src));
    return *this;
  }

  Snapshot::~Snapshot () noexcept = default;

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
  Snapshot::create () -> Glib::RefPtr<Snapshot>
  {
    return Glib::wrap_gtk_snapshot (gtk_snapshot_new ());
  }

  auto
  Snapshot::push_opacity (const double opacity) -> void
  {
    gtk_snapshot_push_opacity (gobj (), opacity);
  }

  auto
  Snapshot::push_blur (const double radius) -> void
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
  Snapshot::push_repeat (const Gdk::Rectangle& bounds,
                         const Gdk::Rectangle& child_bounds) -> void
  {
    gtk_snapshot_push_repeat (gobj (),
                              gdk_rect_to_graphene_rect (bounds).get (),
                              gdk_rect_to_graphene_rect (child_bounds).get ());
  }

  auto
  Snapshot::push_repeat (const Gdk::Rectangle& bounds) -> void
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
  Snapshot::push_clip (const Gdk::Rectangle& bounds) -> void
  {
    gtk_snapshot_push_clip (gobj (), gdk_rect_to_graphene_rect (bounds).get ());
  }

  auto
  Snapshot::push_cross_fade (const double progress) -> void
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
  Snapshot::rotate (const float angle) -> void
  {
    gtk_snapshot_rotate (gobj (), angle);
  }

  auto
  Snapshot::scale (const float factor_x, const float factor_y) -> void
  {
    gtk_snapshot_scale (gobj (), factor_x, factor_y);
  }

  auto
  Snapshot::scale (const float factor_x,
                   const float factor_y,
                   const float factor_z) -> void
  {
    gtk_snapshot_scale_3d (gobj (), factor_x, factor_y, factor_z);
  }

  auto
  Snapshot::perspective (const float depth) -> void
  {
    gtk_snapshot_perspective (gobj (), depth);
  }

  auto
  Snapshot::append_cairo (const graphene_rect_t* bounds) -> Cairo::RefPtr<Cairo::Context>
  {
    return Gdk::Cairo::wrap (gtk_snapshot_append_cairo (gobj (), bounds));
  }

  auto
  Snapshot::append_cairo (const Gdk::Rectangle& bounds) -> Cairo::RefPtr<Cairo::Context>
  {
    return Gdk::Cairo::wrap (
        gtk_snapshot_append_cairo (gobj (),
                                   gdk_rect_to_graphene_rect (bounds).get ()));
  }

  auto
  Snapshot::append_texture (const Glib::RefPtr<Gdk::Texture>& texture,
                            const graphene_rect_t* bounds) -> void
  {
    gtk_snapshot_append_texture (gobj (), Glib::unwrap (texture), bounds);
  }

  auto
  Snapshot::append_texture (const Glib::RefPtr<Gdk::Texture>& texture,
                            const Gdk::Rectangle& bounds) -> void
  {
    gtk_snapshot_append_texture (gobj (),
                                 Glib::unwrap (texture),
                                 gdk_rect_to_graphene_rect (bounds).get ());
  }

  auto
  Snapshot::append_color (const Gdk::RGBA& color, const graphene_rect_t* bounds) -> void
  {
    gtk_snapshot_append_color (gobj (), color.gobj (), bounds);
  }

  auto
  Snapshot::append_color (const Gdk::RGBA& color, const Gdk::Rectangle& bounds) -> void
  {
    gtk_snapshot_append_color (gobj (),
                               color.gobj (),
                               gdk_rect_to_graphene_rect (bounds).get ());
  }

  auto
  Snapshot::append_layout (const Glib::RefPtr<Pango::Layout>& layout,
                           const Gdk::RGBA& color) -> void
  {
    gtk_snapshot_append_layout (gobj (), Glib::unwrap (layout), color.gobj ());
  }

  auto
  Snapshot::render_backgrount (const Glib::RefPtr<StyleContext>& context,
                               const double x,
                               const double y,
                               const double width,
                               const double height) -> void
  {
    gtk_snapshot_render_background (gobj (),
                                    Glib::unwrap (context),
                                    x,
                                    y,
                                    width,
                                    height);
  }

  auto
  Snapshot::render_frame (const Glib::RefPtr<StyleContext>& context,
                          const double x,
                          const double y,
                          const double width,
                          const double height) -> void
  {
    gtk_snapshot_render_frame (gobj (),
                               Glib::unwrap (context),
                               x,
                               y,
                               width,
                               height);
  }

  auto
  Snapshot::render_focus (const Glib::RefPtr<StyleContext>& context,
                          const double x,
                          const double y,
                          const double width,
                          const double height) -> void
  {
    gtk_snapshot_render_focus (gobj (),
                               Glib::unwrap (context),
                               x,
                               y,
                               width,
                               height);
  }

  auto
  Snapshot::render_layout (const Glib::RefPtr<StyleContext>& context,
                           const double x,
                           const double y,
                           const Glib::RefPtr<Pango::Layout>& layout) -> void
  {
    gtk_snapshot_render_layout (gobj (),
                                Glib::unwrap (context),
                                x,
                                y,
                                Glib::unwrap (layout));
  }

  auto
  Snapshot::render_insertion_cursor (const Glib::RefPtr<StyleContext>& context,
                                     const double x,
                                     const double y,
                                     const Glib::RefPtr<Pango::Layout>& layout,
                                     const int index,
                                     Pango::Direction direction) -> void
  {
    gtk_snapshot_render_insertion_cursor (
        gobj (),
        Glib::unwrap (context),
        x,
        y,
        Glib::unwrap (layout),
        index,
        static_cast<PangoDirection> (direction));
  }

} // namespace Gtk
