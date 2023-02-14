
#ifndef _GTKMM_CELLRENDERERSPIN_H
#define _GTKMM_CELLRENDERERSPIN_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/cellrenderertext.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellRendererSpin = struct _GtkCellRendererSpin;
using GtkCellRendererSpinClass = struct _GtkCellRendererSpinClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API CellRendererSpin_Class;
}
#endif

namespace Gtk
{
  class GTKMM_API Adjustment;

  class GTKMM_API CellRendererSpin : public CellRendererText
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef CellRendererSpin CppObjectType;
    typedef CellRendererSpin_Class CppClassType;
    typedef GtkCellRendererSpin BaseObjectType;
    typedef GtkCellRendererSpinClass BaseClassType;
#endif

    CellRendererSpin (CellRendererSpin&& src) noexcept;
    auto
    operator= (CellRendererSpin&& src) noexcept -> CellRendererSpin&;

    CellRendererSpin (const CellRendererSpin&) = delete;
    auto
    operator= (const CellRendererSpin&) -> CellRendererSpin& = delete;

    ~CellRendererSpin () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class CellRendererSpin_Class;
    static CppClassType cellrendererspin_class_;

  protected:
    explicit CellRendererSpin (const Glib::ConstructParams& construct_params);
    explicit CellRendererSpin (GtkCellRendererSpin* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkCellRendererSpin*
    {
      return reinterpret_cast<GtkCellRendererSpin*> (gobject_);
    }

    auto
    gobj () const -> const GtkCellRendererSpin*
    {
      return reinterpret_cast<GtkCellRendererSpin*> (gobject_);
    }

  private:
  public:
    CellRendererSpin ();

    auto
    property_adjustment () -> Glib::PropertyProxy<Glib::RefPtr<Adjustment>>;

    auto
    property_adjustment () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Adjustment>>;

    auto
    property_climb_rate () -> Glib::PropertyProxy<double>;

    auto
    property_climb_rate () const -> Glib::PropertyProxy_ReadOnly<double>;

    auto
    property_digits () -> Glib::PropertyProxy<guint>;

    auto
    property_digits () const -> Glib::PropertyProxy_ReadOnly<guint>;

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
  wrap (GtkCellRendererSpin* object, bool take_copy = false) -> Gtk::CellRendererSpin*;
} // namespace Glib

#endif
