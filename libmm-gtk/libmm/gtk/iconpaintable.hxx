// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ICONPAINTABLE_H
#define _GTKMM_ICONPAINTABLE_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/paintable.hxx>
#include <libmm/gio/file.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkIconPaintable = struct _GtkIconPaintable;
using GtkIconPaintableClass = struct _GtkIconPaintableClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT IconPaintable_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT IconPaintable : public glib::Object,
                                  public gdk::Paintable
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
    explicit IconPaintable (const glib::ConstructParams& construct_params);
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
    create (const glib::RefPtr<gio::File>& file, int size, int scale = 1)
        -> glib::RefPtr<IconPaintable>;

    auto
    get_file () const -> glib::RefPtr<gio::File>;

    auto
    get_icon_name () const -> glib::ustring;

    auto
    is_symbolic () const -> bool;

    auto
    property_file () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::File>>;

    auto
    property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_is_symbolic () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkIconPaintable* object, bool take_copy = false) -> glib::RefPtr<gtk::IconPaintable>;
} // namespace glib

#endif
