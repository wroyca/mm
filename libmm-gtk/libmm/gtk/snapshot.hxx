// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SNAPSHOT_H
#define _GTKMM_SNAPSHOT_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/rectangle.hxx>
#include <libmm/gdk/snapshot.hxx>
#include <libmm/gtk/stylecontext.hxx>

typedef struct _graphene_rect_t graphene_rect_t;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Snapshot_Class;
}
#endif

namespace gdk
{
  class LIBMM_GTK_SYMEXPORT RGBA;
  class LIBMM_GTK_SYMEXPORT Texture;
} // namespace gdk

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Snapshot : public gdk::Snapshot
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Snapshot;
    using CppClassType = Snapshot_Class;
    using BaseObjectType = GtkSnapshot;
    using BaseClassType = GtkSnapshotClass;

    Snapshot (const Snapshot&) = delete;
    auto
    operator= (const Snapshot&) -> Snapshot& = delete;

  private:
    friend class Snapshot_Class;
    static CppClassType snapshot_class_;

  protected:
    explicit Snapshot (const glib::ConstructParams& construct_params);
    explicit Snapshot (GtkSnapshot* castitem);

#endif

  public:
    Snapshot (Snapshot&& src) noexcept;
    auto
    operator= (Snapshot&& src) noexcept -> Snapshot&;

    ~Snapshot () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkSnapshot*
    {
      return reinterpret_cast<GtkSnapshot*> (gobject_);
    }

    auto
    gobj () const -> const GtkSnapshot*
    {
      return reinterpret_cast<GtkSnapshot*> (gobject_);
    }

    auto
    gobj_copy () -> GtkSnapshot*;

  private:
  public:
    static auto
    create () -> glib::RefPtr<Snapshot>;

    auto
    push_debug (const glib::ustring& name) -> void;

    auto
    push_opacity (double opacity) -> void;

    auto
    push_blur (double radius) -> void;

    auto
    push_repeat (const graphene_rect_t* bounds,
                 const graphene_rect_t* child_bounds) -> void;

    auto
    push_repeat (const gdk::Rectangle& bounds,
                 const gdk::Rectangle& child_bounds) -> void;

    auto
    push_repeat (const gdk::Rectangle& bounds) -> void;

    auto
    push_clip (const graphene_rect_t* bounds) -> void;

    auto
    push_clip (const gdk::Rectangle& bounds) -> void;

    auto
    push_cross_fade (double progress) -> void;

    auto
    gl_shader_pop_texture () -> void;

    auto
    pop () -> void;

    auto
    save () -> void;

    auto
    restore () -> void;

    auto
    rotate (float angle) -> void;

    auto
    scale (float factor_x, float factor_y) -> void;

    auto
    scale (float factor_x, float factor_y, float factor_z) -> void;

    auto
    perspective (float depth) -> void;

    auto
    append_cairo (const graphene_rect_t* bounds)
        -> cairo::RefPtr<cairo::Context>;

    auto
    append_cairo (const gdk::Rectangle& bounds)
        -> cairo::RefPtr<cairo::Context>;

    auto
    append_texture (const glib::RefPtr<gdk::Texture>& texture,
                    const graphene_rect_t* bounds) -> void;

    auto
    append_texture (const glib::RefPtr<gdk::Texture>& texture,
                    const gdk::Rectangle& bounds) -> void;

    auto
    append_color (const gdk::RGBA& color, const graphene_rect_t* bounds)
        -> void;

    auto
    append_color (const gdk::RGBA& color, const gdk::Rectangle& bounds) -> void;

    auto
    append_layout (const glib::RefPtr<pango::Layout>& layout,
                   const gdk::RGBA& color) -> void;

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    render_backgrount (const glib::RefPtr<StyleContext>& context,
                       double x,
                       double y,
                       double width,
                       double height) -> void;
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    render_frame (const glib::RefPtr<StyleContext>& context,
                  double x,
                  double y,
                  double width,
                  double height) -> void;
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    render_focus (const glib::RefPtr<StyleContext>& context,
                  double x,
                  double y,
                  double width,
                  double height) -> void;
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    render_layout (const glib::RefPtr<StyleContext>& context,
                   double x,
                   double y,
                   const glib::RefPtr<pango::Layout>& layout) -> void;
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    render_insertion_cursor (const glib::RefPtr<StyleContext>& context,
                             double x,
                             double y,
                             const glib::RefPtr<pango::Layout>& layout,
                             int index,
                             pango::Direction direction) -> void;
#endif

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap_gtk_snapshot (GtkSnapshot* object, bool take_copy = false) -> glib::RefPtr<gtk::Snapshot>;
} // namespace glib

#endif
