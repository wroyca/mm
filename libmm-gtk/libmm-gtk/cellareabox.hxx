// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CELLAREABOX_H
#define _GTKMM_CELLAREABOX_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm-gtk/cellarea.hxx>
  #include <libmm-gtk/orientable.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellAreaBox = struct _GtkCellAreaBox;
using GtkCellAreaBoxClass = struct _GtkCellAreaBoxClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT CellAreaBox_Class;
}
  #endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT CellAreaBox : public Gtk::CellArea,
                                public Orientable
  {
  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = CellAreaBox;
    using CppClassType = CellAreaBox_Class;
    using BaseObjectType = GtkCellAreaBox;
    using BaseClassType = GtkCellAreaBoxClass;

    CellAreaBox (const CellAreaBox&) = delete;
    auto
    operator= (const CellAreaBox&) -> CellAreaBox& = delete;

  private:
    friend class CellAreaBox_Class;
    static CppClassType cellareabox_class_;

  protected:
    explicit CellAreaBox (const Glib::ConstructParams& construct_params);
    explicit CellAreaBox (GtkCellAreaBox* castitem);

  #endif

  public:
    CellAreaBox (CellAreaBox&& src) noexcept;
    auto
    operator= (CellAreaBox&& src) noexcept -> CellAreaBox&;

    ~CellAreaBox () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkCellAreaBox*
    {
      return reinterpret_cast<GtkCellAreaBox*> (gobject_);
    }

    auto
    gobj () const -> const GtkCellAreaBox*
    {
      return reinterpret_cast<GtkCellAreaBox*> (gobject_);
    }

    auto
    gobj_copy () -> GtkCellAreaBox*;

  private:
  protected:
    CellAreaBox ();

  public:
    static auto
    create () -> Glib::RefPtr<CellAreaBox>;

    auto
    pack_start (CellRenderer& renderer,
                bool expand = false,
                bool align = false,
                bool fixed = true) -> void;

    auto
    pack_end (CellRenderer& renderer,
              bool expand = false,
              bool align = false,
              bool fixed = true) -> void;

    auto
    get_spacing () const -> int;

    auto
    set_spacing (int spacing) -> void;

    auto
    property_spacing () -> Glib::PropertyProxy<int>;

    auto
    property_spacing () const -> Glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkCellAreaBox* object, bool take_copy = false) -> Glib::RefPtr<Gtk::CellAreaBox>;
} // namespace Glib

#endif

#endif
