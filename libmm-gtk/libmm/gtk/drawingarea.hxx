// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_DRAWINGAREA_H
#define _GTKMM_DRAWINGAREA_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkDrawingArea = struct _GtkDrawingArea;
using GtkDrawingAreaClass = struct _GtkDrawingAreaClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT DrawingArea_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT DrawingArea : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef DrawingArea CppObjectType;
    typedef DrawingArea_Class CppClassType;
    typedef GtkDrawingArea BaseObjectType;
    typedef GtkDrawingAreaClass BaseClassType;
#endif

    DrawingArea (DrawingArea&& src) noexcept;
    auto
    operator= (DrawingArea&& src) noexcept -> DrawingArea&;

    DrawingArea (const DrawingArea&) = delete;
    auto
    operator= (const DrawingArea&) -> DrawingArea& = delete;

    ~DrawingArea () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class DrawingArea_Class;
    static CppClassType drawingarea_class_;

  protected:
    explicit DrawingArea (const glib::ConstructParams& construct_params);
    explicit DrawingArea (GtkDrawingArea* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkDrawingArea*
    {
      return reinterpret_cast<GtkDrawingArea*> (gobject_);
    }

    auto
    gobj () const -> const GtkDrawingArea*
    {
      return reinterpret_cast<GtkDrawingArea*> (gobject_);
    }

  private:
  public:
    DrawingArea ();

    using SlotDraw =
        sigc::slot<void (const cairo::RefPtr<cairo::Context>&, int, int)>;

    auto
    set_content_width (int width) -> void;

    auto
    get_content_width () const -> int;

    auto
    set_content_height (int width) -> void;

    auto
    get_content_height () const -> int;

    auto
    set_draw_func (const SlotDraw& slot) -> void;

    auto
    signal_resize () -> glib::SignalProxy<void (int, int)>;

    auto
    property_content_width () -> glib::PropertyProxy<int>;

    auto
    property_content_width () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_content_height () -> glib::PropertyProxy<int>;

    auto
    property_content_height () const -> glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
    virtual auto
    on_resize (int width, int height) -> void;
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkDrawingArea* object, bool take_copy = false) -> gtk::DrawingArea*;
} // namespace glib

#endif
