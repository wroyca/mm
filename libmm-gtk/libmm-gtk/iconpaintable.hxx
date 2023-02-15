// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ICONPAINTABLE_H
#define _GTKMM_ICONPAINTABLE_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/paintable.hxx>
#include <libmm-gio/file.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkIconPaintable = struct _GtkIconPaintable;
using GtkIconPaintableClass = struct _GtkIconPaintableClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT IconPaintable_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT IconPaintable : public Glib::Object,
                                  public Gdk::Paintable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = IconPaintable;
    using CppClassType = IconPaintable_Class;
    using BaseObjectType = GtkIconPaintable;
    using BaseClassType = GtkIconPaintableClass;

    IconPaintable (const IconPaintable&) = delete;
    auto
    operator= (const IconPaintable&) -> IconPaintable& = delete;

  private:
    friend class IconPaintable_Class;
    static CppClassType iconpaintable_class_;

  protected:
    explicit IconPaintable (const Glib::ConstructParams& construct_params);
    explicit IconPaintable (GtkIconPaintable* castitem);

#endif

  public:
    IconPaintable (IconPaintable&& src) noexcept;
    auto
    operator= (IconPaintable&& src) noexcept -> IconPaintable&;

    ~IconPaintable () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkIconPaintable*
    {
      return reinterpret_cast<GtkIconPaintable*> (gobject_);
    }

    auto
    gobj () const -> const GtkIconPaintable*
    {
      return reinterpret_cast<GtkIconPaintable*> (gobject_);
    }

    auto
    gobj_copy () -> GtkIconPaintable*;

  private:
  public:
    static auto
    create (const Glib::RefPtr<Gio::File>& file, int size, int scale = 1)
        -> Glib::RefPtr<IconPaintable>;

    auto
    get_file () const -> Glib::RefPtr<Gio::File>;

    auto
    get_icon_name () const -> Glib::ustring;

    auto
    is_symbolic () const -> bool;

    auto
    property_file () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::File>>;

    auto
    property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_is_symbolic () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkIconPaintable* object, bool take_copy = false) -> Glib::RefPtr<Gtk::IconPaintable>;
} // namespace Glib

#endif
