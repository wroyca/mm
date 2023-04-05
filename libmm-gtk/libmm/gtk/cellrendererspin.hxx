// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CELLRENDERERSPIN_H
#define _GTKMM_CELLRENDERERSPIN_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gtk/cellrenderertext.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellRendererSpin = struct _GtkCellRendererSpin;
using GtkCellRendererSpinClass = struct _GtkCellRendererSpinClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT CellRendererSpin_Class;
}
  #endif

namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Adjustment;

  class LIBMM_GTK_SYMEXPORT CellRendererSpin : public CellRendererText
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
    friend LIBMM_GTK_SYMEXPORT class CellRendererSpin_Class;
    static CppClassType cellrendererspin_class_;

  protected:
    explicit CellRendererSpin (const glib::ConstructParams& construct_params);
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
    property_adjustment () -> glib::PropertyProxy<glib::RefPtr<Adjustment>>;

    auto
    property_adjustment () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Adjustment>>;

    auto
    property_climb_rate () -> glib::PropertyProxy<double>;

    auto
    property_climb_rate () const -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_digits () -> glib::PropertyProxy<guint>;

    auto
    property_digits () const -> glib::PropertyProxy_ReadOnly<guint>;

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
  wrap (GtkCellRendererSpin* object, bool take_copy = false) -> gtk::CellRendererSpin*;
} // namespace glib

#endif

#endif
