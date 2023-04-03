// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TOOLTIP_H
#define _GTKMM_TOOLTIP_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/paintable.hxx>
#include <libmm/gio/icon.hxx>
#include <libmm/glib/object.hxx>
#include <libmm/gtk/enums.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTooltip = struct _GtkTooltip;
using GtkTooltipClass = struct _GtkTooltipClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT Tooltip_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT Tooltip : public Glib::Object
  {
  protected:
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Tooltip;
    using CppClassType = Tooltip_Class;
    using BaseObjectType = GtkTooltip;
    using BaseClassType = GtkTooltipClass;

    Tooltip (const Tooltip&) = delete;
    auto
    operator= (const Tooltip&) -> Tooltip& = delete;

  private:
    friend class Tooltip_Class;
    static CppClassType tooltip_class_;

  protected:
    explicit Tooltip (const Glib::ConstructParams& construct_params);
    explicit Tooltip (GtkTooltip* castitem);

#endif

  public:
    Tooltip (Tooltip&& src) noexcept;
    auto
    operator= (Tooltip&& src) noexcept -> Tooltip&;

    ~Tooltip () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkTooltip*
    {
      return reinterpret_cast<GtkTooltip*> (gobject_);
    }

    auto
    gobj () const -> const GtkTooltip*
    {
      return reinterpret_cast<GtkTooltip*> (gobject_);
    }

    auto
    gobj_copy () -> GtkTooltip*;

  private:
  public:
    auto
    set_markup (const Glib::ustring& markup) -> void;

    auto
    unset_markup () -> void;

    auto
    set_text (const Glib::ustring& text) -> void;

    auto
    unset_text () -> void;

    auto
    set_icon (const Glib::RefPtr<Gdk::Paintable>& paintable) -> void;

    auto
    set_icon (const Glib::RefPtr<Gio::Icon>& gicon) -> void;

    auto
    set_icon (const Glib::ustring& icon_name) -> void;

    auto
    unset_icon () -> void;

    auto
    set_custom (Widget& custom_widget) -> void;

    auto
    unset_custom () -> void;

    auto
    set_tip_area (const Gdk::Rectangle& rect) -> void;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkTooltip* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Tooltip>;
} // namespace Glib

#endif