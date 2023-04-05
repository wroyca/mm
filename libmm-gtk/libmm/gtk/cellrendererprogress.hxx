// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CELLRENDERERPROGRESS_H
#define _GTKMM_CELLRENDERERPROGRESS_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gtk/cellrenderer.hxx>
  #include <libmm/gtk/orientable.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellRendererProgress = struct _GtkCellRendererProgress;
using GtkCellRendererProgressClass = struct _GtkCellRendererProgressClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT CellRendererProgress_Class;
}
  #endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT CellRendererProgress : public CellRenderer,
                                         public Orientable
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef CellRendererProgress CppObjectType;
    typedef CellRendererProgress_Class CppClassType;
    typedef GtkCellRendererProgress BaseObjectType;
    typedef GtkCellRendererProgressClass BaseClassType;
  #endif

    CellRendererProgress (CellRendererProgress&& src) noexcept;
    auto
    operator= (CellRendererProgress&& src) noexcept -> CellRendererProgress&;

    CellRendererProgress (const CellRendererProgress&) = delete;
    auto
    operator= (const CellRendererProgress&) -> CellRendererProgress& = delete;

    ~CellRendererProgress () noexcept override;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class CellRendererProgress_Class;
    static CppClassType cellrendererprogress_class_;

  protected:
    explicit CellRendererProgress (
        const glib::ConstructParams& construct_params);
    explicit CellRendererProgress (GtkCellRendererProgress* castitem);

  #endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkCellRendererProgress*
    {
      return reinterpret_cast<GtkCellRendererProgress*> (gobject_);
    }

    auto
    gobj () const -> const GtkCellRendererProgress*
    {
      return reinterpret_cast<GtkCellRendererProgress*> (gobject_);
    }

  private:
  public:
    CellRendererProgress ();

    auto
    property_value () -> glib::PropertyProxy<int>;

    auto
    property_value () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_text () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_text () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_pulse () -> glib::PropertyProxy<int>;

    auto
    property_pulse () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_text_xalign () -> glib::PropertyProxy<float>;

    auto
    property_text_xalign () const -> glib::PropertyProxy_ReadOnly<float>;

    auto
    property_text_yalign () -> glib::PropertyProxy<float>;

    auto
    property_text_yalign () const -> glib::PropertyProxy_ReadOnly<float>;

    auto
    property_inverted () -> glib::PropertyProxy<bool>;

    auto
    property_inverted () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    _property_renderable () -> glib::PropertyProxy_Base override;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkCellRendererProgress* object, bool take_copy = false) -> gtk::CellRendererProgress*;
} // namespace glib

#endif

#endif
