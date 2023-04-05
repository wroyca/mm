// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CELLRENDERERCOMBO_H
#define _GTKMM_CELLRENDERERCOMBO_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gtk/cellrenderertext.hxx>
  #include <libmm/gtk/treemodel.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellRendererCombo = struct _GtkCellRendererCombo;
using GtkCellRendererComboClass = struct _GtkCellRendererComboClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT CellRendererCombo_Class;
}
  #endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT CellRendererCombo : public CellRendererText
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef CellRendererCombo CppObjectType;
    typedef CellRendererCombo_Class CppClassType;
    typedef GtkCellRendererCombo BaseObjectType;
    typedef GtkCellRendererComboClass BaseClassType;
  #endif

    CellRendererCombo (CellRendererCombo&& src) noexcept;
    auto
    operator= (CellRendererCombo&& src) noexcept -> CellRendererCombo&;

    CellRendererCombo (const CellRendererCombo&) = delete;
    auto
    operator= (const CellRendererCombo&) -> CellRendererCombo& = delete;

    ~CellRendererCombo () noexcept override;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class CellRendererCombo_Class;
    static CppClassType cellrenderercombo_class_;

  protected:
    explicit CellRendererCombo (const glib::ConstructParams& construct_params);
    explicit CellRendererCombo (GtkCellRendererCombo* castitem);

  #endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkCellRendererCombo*
    {
      return reinterpret_cast<GtkCellRendererCombo*> (gobject_);
    }

    auto
    gobj () const -> const GtkCellRendererCombo*
    {
      return reinterpret_cast<GtkCellRendererCombo*> (gobject_);
    }

  private:
  public:
    CellRendererCombo ();

    auto
    signal_changed () -> glib::SignalProxy<void (const glib::ustring&,
                                                 const TreeModel::iterator&)>;

    auto
    property_model () -> glib::PropertyProxy<glib::RefPtr<gtk::TreeModel>>;

    auto
    property_model () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gtk::TreeModel>>;

    auto
    property_text_column () -> glib::PropertyProxy<int>;

    auto
    property_text_column () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_has_entry () -> glib::PropertyProxy<bool>;

    auto
    property_has_entry () const -> glib::PropertyProxy_ReadOnly<bool>;

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
  wrap (GtkCellRendererCombo* object, bool take_copy = false) -> gtk::CellRendererCombo*;
} // namespace glib

#endif

#endif
