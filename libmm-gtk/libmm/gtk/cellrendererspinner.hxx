// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CELLRENDERERSPINNER_H
#define _GTKMM_CELLRENDERERSPINNER_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gtk/cellrenderer.hxx>
  #include <libmm/gtk/enums.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellRendererSpinner = struct _GtkCellRendererSpinner;
using GtkCellRendererSpinnerClass = struct _GtkCellRendererSpinnerClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT CellRendererSpinner_Class;
}
  #endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT CellRendererSpinner : public CellRenderer
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef CellRendererSpinner CppObjectType;
    typedef CellRendererSpinner_Class CppClassType;
    typedef GtkCellRendererSpinner BaseObjectType;
    typedef GtkCellRendererSpinnerClass BaseClassType;
  #endif

    CellRendererSpinner (CellRendererSpinner&& src) noexcept;
    auto
    operator= (CellRendererSpinner&& src) noexcept -> CellRendererSpinner&;

    CellRendererSpinner (const CellRendererSpinner&) = delete;
    auto
    operator= (const CellRendererSpinner&) -> CellRendererSpinner& = delete;

    ~CellRendererSpinner () noexcept override;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class CellRendererSpinner_Class;
    static CppClassType cellrendererspinner_class_;

  protected:
    explicit CellRendererSpinner (
        const Glib::ConstructParams& construct_params);
    explicit CellRendererSpinner (GtkCellRendererSpinner* castitem);

  #endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkCellRendererSpinner*
    {
      return reinterpret_cast<GtkCellRendererSpinner*> (gobject_);
    }

    auto
    gobj () const -> const GtkCellRendererSpinner*
    {
      return reinterpret_cast<GtkCellRendererSpinner*> (gobject_);
    }

  private:
  public:
    CellRendererSpinner ();

    auto
    property_active () -> Glib::PropertyProxy<bool>;

    auto
    property_active () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_pulse () -> Glib::PropertyProxy<guint>;

    auto
    property_pulse () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_size () -> Glib::PropertyProxy<Gtk::IconSize>;

    auto
    property_size () const -> Glib::PropertyProxy_ReadOnly<Gtk::IconSize>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkCellRendererSpinner* object, bool take_copy = false) -> Gtk::CellRendererSpinner*;
} // namespace Glib

#endif

#endif
