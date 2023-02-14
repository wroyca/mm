// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CELLAREACONTEXT_H
#define _GTKMM_CELLAREACONTEXT_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellAreaContext = struct _GtkCellAreaContext;
using GtkCellAreaContextClass = struct _GtkCellAreaContextClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API CellAreaContext_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API CellArea;

  class GTKMM_API CellAreaContext : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = CellAreaContext;
    using CppClassType = CellAreaContext_Class;
    using BaseObjectType = GtkCellAreaContext;
    using BaseClassType = GtkCellAreaContextClass;

    CellAreaContext (const CellAreaContext&) = delete;
    auto
    operator= (const CellAreaContext&) -> CellAreaContext& = delete;

  private:
    friend class CellAreaContext_Class;
    static CppClassType cellareacontext_class_;

  protected:
    explicit CellAreaContext (const Glib::ConstructParams& construct_params);
    explicit CellAreaContext (GtkCellAreaContext* castitem);

#endif

  public:
    CellAreaContext (CellAreaContext&& src) noexcept;
    auto
    operator= (CellAreaContext&& src) noexcept -> CellAreaContext&;

    ~CellAreaContext () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkCellAreaContext*
    {
      return reinterpret_cast<GtkCellAreaContext*> (gobject_);
    }

    auto
    gobj () const -> const GtkCellAreaContext*
    {
      return reinterpret_cast<GtkCellAreaContext*> (gobject_);
    }

    auto
    gobj_copy () -> GtkCellAreaContext*;

  private:
  public:
  protected:
  public:
    auto
    get_area () -> Glib::RefPtr<CellArea>;

    auto
    get_area () const -> Glib::RefPtr<const CellArea>;

    void
    allocate (int width, int height);

    void
    reset ();

    void
    get_preferred_width (int& minimum_width, int& natural_width) const;

    void
    get_preferred_height (int& minimum_height, int& natural_height) const;

    void
    get_preferred_height_for_width (int width,
                                    int& minimum_height,
                                    int& natural_height) const;

    void
    get_preferred_width_for_height (int height,
                                    int& minimum_width,
                                    int& natural_width) const;

    void
    get_allocation (int& width, int& height) const;

    void
    push_preferred_width (int minimum_width, int natural_width);

    void
    push_preferred_height (int minimum_height, int natural_height);

    auto
    property_area () const -> Glib::PropertyProxy_ReadOnly<CellArea*>;

    auto
    property_minimum_width () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_natural_width () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_minimum_height () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_natural_height () const -> Glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkCellAreaContext* object, bool take_copy = false) -> Glib::RefPtr<Gtk::CellAreaContext>;
} // namespace Glib

#endif
