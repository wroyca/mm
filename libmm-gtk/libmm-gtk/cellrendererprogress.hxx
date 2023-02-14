
#ifndef _GTKMM_CELLRENDERERPROGRESS_H
#define _GTKMM_CELLRENDERERPROGRESS_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/cellrenderer.hxx>
#include <libmm-gtk/orientable.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellRendererProgress = struct _GtkCellRendererProgress;
using GtkCellRendererProgressClass = struct _GtkCellRendererProgressClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API CellRendererProgress_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API CellRendererProgress : public CellRenderer,
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
    friend GTKMM_API class CellRendererProgress_Class;
    static CppClassType cellrendererprogress_class_;

  protected:
    explicit CellRendererProgress (
        const Glib::ConstructParams& construct_params);
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
    property_value () -> Glib::PropertyProxy<int>;

    auto
    property_value () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_text () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_text () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_pulse () -> Glib::PropertyProxy<int>;

    auto
    property_pulse () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_text_xalign () -> Glib::PropertyProxy<float>;

    auto
    property_text_xalign () const -> Glib::PropertyProxy_ReadOnly<float>;

    auto
    property_text_yalign () -> Glib::PropertyProxy<float>;

    auto
    property_text_yalign () const -> Glib::PropertyProxy_ReadOnly<float>;

    auto
    property_inverted () -> Glib::PropertyProxy<bool>;

    auto
    property_inverted () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    _property_renderable () -> Glib::PropertyProxy_Base override;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkCellRendererProgress* object, bool take_copy = false) -> Gtk::CellRendererProgress*;
} // namespace Glib

#endif
