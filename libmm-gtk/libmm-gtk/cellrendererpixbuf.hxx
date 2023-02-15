// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CELLRENDERERPIXBUF_H
#define _GTKMM_CELLRENDERERPIXBUF_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm-gdk/pixbuf.hxx>
  #include <libmm-gdk/texture.hxx>
  #include <libmm-gio/icon.hxx>
  #include <libmm-gtk/cellrenderer.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellRendererPixbuf = struct _GtkCellRendererPixbuf;
using GtkCellRendererPixbufClass = struct _GtkCellRendererPixbufClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT CellRendererPixbuf_Class;
}
  #endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT CellRendererPixbuf : public CellRenderer
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef CellRendererPixbuf CppObjectType;
    typedef CellRendererPixbuf_Class CppClassType;
    typedef GtkCellRendererPixbuf BaseObjectType;
    typedef GtkCellRendererPixbufClass BaseClassType;
  #endif

    CellRendererPixbuf (CellRendererPixbuf&& src) noexcept;
    auto
    operator= (CellRendererPixbuf&& src) noexcept -> CellRendererPixbuf&;

    CellRendererPixbuf (const CellRendererPixbuf&) = delete;
    auto
    operator= (const CellRendererPixbuf&) -> CellRendererPixbuf& = delete;

    ~CellRendererPixbuf () noexcept override;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class CellRendererPixbuf_Class;
    static CppClassType cellrendererpixbuf_class_;

  protected:
    explicit CellRendererPixbuf (const Glib::ConstructParams& construct_params);
    explicit CellRendererPixbuf (GtkCellRendererPixbuf* castitem);

  #endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkCellRendererPixbuf*
    {
      return reinterpret_cast<GtkCellRendererPixbuf*> (gobject_);
    }

    auto
    gobj () const -> const GtkCellRendererPixbuf*
    {
      return reinterpret_cast<GtkCellRendererPixbuf*> (gobject_);
    }

  private:
  public:
    CellRendererPixbuf ();

    auto
    property_pixbuf ()
        -> Glib::PropertyProxy_WriteOnly<Glib::RefPtr<Gdk::Pixbuf>>;

    auto
    property_pixbuf_expander_open ()
        -> Glib::PropertyProxy<Glib::RefPtr<Gdk::Pixbuf>>;

    auto
    property_pixbuf_expander_open () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Pixbuf>>;

    auto
    property_pixbuf_expander_closed ()
        -> Glib::PropertyProxy<Glib::RefPtr<Gdk::Pixbuf>>;

    auto
    property_pixbuf_expander_closed () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Pixbuf>>;

    auto
    property_icon_size () -> Glib::PropertyProxy<Gtk::IconSize>;

    auto
    property_icon_size () const -> Glib::PropertyProxy_ReadOnly<Gtk::IconSize>;

    auto
    property_icon_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_gicon () -> Glib::PropertyProxy<Glib::RefPtr<Gio::Icon>>;

    auto
    property_gicon () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::Icon>>;

    auto
    property_texture () -> Glib::PropertyProxy<Glib::RefPtr<Gdk::Texture>>;

    auto
    property_texture () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Texture>>;

    auto
    _property_renderable () -> Glib::PropertyProxy_Base override;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkCellRendererPixbuf* object, bool take_copy = false) -> Gtk::CellRendererPixbuf*;
} // namespace Glib

#endif

#endif
