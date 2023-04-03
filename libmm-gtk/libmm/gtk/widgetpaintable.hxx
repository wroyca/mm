// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_WIDGETPAINTABLE_H
#define _GTKMM_WIDGETPAINTABLE_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/paintable.hxx>
#include <libmm/glib/object.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT WidgetPaintable_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT WidgetPaintable : public Glib::Object,
                                    public Gdk::Paintable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = WidgetPaintable;
    using CppClassType = WidgetPaintable_Class;
    using BaseObjectType = GtkWidgetPaintable;
    using BaseClassType = GtkWidgetPaintableClass;

    WidgetPaintable (const WidgetPaintable&) = delete;
    auto
    operator= (const WidgetPaintable&) -> WidgetPaintable& = delete;

  private:
    friend class WidgetPaintable_Class;
    static CppClassType widgetpaintable_class_;

  protected:
    explicit WidgetPaintable (const Glib::ConstructParams& construct_params);
    explicit WidgetPaintable (GtkWidgetPaintable* castitem);

#endif

  public:
    WidgetPaintable (WidgetPaintable&& src) noexcept;
    auto
    operator= (WidgetPaintable&& src) noexcept -> WidgetPaintable&;

    ~WidgetPaintable () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkWidgetPaintable*
    {
      return reinterpret_cast<GtkWidgetPaintable*> (gobject_);
    }

    auto
    gobj () const -> const GtkWidgetPaintable*
    {
      return reinterpret_cast<GtkWidgetPaintable*> (gobject_);
    }

    auto
    gobj_copy () -> GtkWidgetPaintable*;

  private:
  protected:
    WidgetPaintable ();
    explicit WidgetPaintable (Widget& widget);

  public:
    static auto
    create () -> Glib::RefPtr<WidgetPaintable>;

    static auto
    create (Widget& widget) -> Glib::RefPtr<WidgetPaintable>;

    auto
    get_widget () -> Widget*;

    auto
    get_widget () const -> const Widget*;

    auto
    set_widget (Widget& widget) -> void;
    auto
    unset_widget () -> void;

    auto
    property_widget () -> Glib::PropertyProxy<Widget*>;

    auto
    property_widget () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkWidgetPaintable* object, bool take_copy = false) -> Glib::RefPtr<Gtk::WidgetPaintable>;
} // namespace Glib

#endif
