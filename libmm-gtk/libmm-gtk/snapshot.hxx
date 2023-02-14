
#ifndef _GTKMM_SNAPSHOT_H
#define _GTKMM_SNAPSHOT_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/rectangle.hxx>
#include <libmm-gdk/snapshot.hxx>
#include <libmm-gtk/stylecontext.hxx>

typedef struct _graphene_rect_t graphene_rect_t;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Snapshot_Class;
}
#endif

namespace Gdk
{
  class GTKMM_API RGBA;
  class GTKMM_API Texture;
} // namespace Gdk

namespace Gtk
{

  class GTKMM_API Snapshot : public Gdk::Snapshot
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
    explicit Snapshot (const Glib::ConstructParams& construct_params);
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
    create () -> Glib::RefPtr<Snapshot>;

    void
    push_debug (const Glib::ustring& name);

    void
    push_opacity (double opacity);

    void
    push_blur (double radius);

    void
    push_repeat (const graphene_rect_t* bounds,
                 const graphene_rect_t* child_bounds);

    void
    push_repeat (const Gdk::Rectangle& bounds,
                 const Gdk::Rectangle& child_bounds);

    void
    push_repeat (const Gdk::Rectangle& bounds);

    void
    push_clip (const graphene_rect_t* bounds);

    void
    push_clip (const Gdk::Rectangle& bounds);

    void
    push_cross_fade (double progress);

    void
    gl_shader_pop_texture ();

    void
    pop ();

    void
    save ();

    void
    restore ();

    void
    rotate (float angle);

    void
    scale (float factor_x, float factor_y);

    void
    scale (float factor_x, float factor_y, float factor_z);

    void
    perspective (float depth);

    auto
    append_cairo (const graphene_rect_t* bounds)
        -> Cairo::RefPtr<Cairo::Context>;

    auto
    append_cairo (const Gdk::Rectangle& bounds)
        -> Cairo::RefPtr<Cairo::Context>;

    void
    append_texture (const Glib::RefPtr<Gdk::Texture>& texture,
                    const graphene_rect_t* bounds);

    void
    append_texture (const Glib::RefPtr<Gdk::Texture>& texture,
                    const Gdk::Rectangle& bounds);

    void
    append_color (const Gdk::RGBA& color, const graphene_rect_t* bounds);

    void
    append_color (const Gdk::RGBA& color, const Gdk::Rectangle& bounds);

    void
    append_layout (const Glib::RefPtr<Pango::Layout>& layout,
                   const Gdk::RGBA& color);

    void
    render_backgrount (const Glib::RefPtr<StyleContext>& context,
                       double x,
                       double y,
                       double width,
                       double height);

    void
    render_frame (const Glib::RefPtr<StyleContext>& context,
                  double x,
                  double y,
                  double width,
                  double height);

    void
    render_focus (const Glib::RefPtr<StyleContext>& context,
                  double x,
                  double y,
                  double width,
                  double height);

    void
    render_layout (const Glib::RefPtr<StyleContext>& context,
                   double x,
                   double y,
                   const Glib::RefPtr<Pango::Layout>& layout);

    void
    render_insertion_cursor (const Glib::RefPtr<StyleContext>& context,
                             double x,
                             double y,
                             const Glib::RefPtr<Pango::Layout>& layout,
                             int index,
                             Pango::Direction direction);

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap_gtk_snapshot (GtkSnapshot* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Snapshot>;
} // namespace Glib

#endif
