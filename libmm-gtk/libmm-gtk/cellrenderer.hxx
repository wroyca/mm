// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CELLRENDERER_H
#define _GTKMM_CELLRENDERER_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/celleditable.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellRenderer = struct _GtkCellRenderer;
using GtkCellRendererClass = struct _GtkCellRendererClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API CellRenderer_Class;
}
#endif

namespace Gtk
{
  class GTKMM_API Snapshot;

  enum class CellRendererState
  {
    SELECTED = 1 << 0,
    PRELIT = 1 << 1,
    INSENSITIVE = 1 << 2,
    SORTED = 1 << 3,
    FOCUSED = 1 << 4,
    EXPANDABLE = 1 << 5,
    EXPANDED = 1 << 6
  };

  inline auto
  operator| (CellRendererState lhs, CellRendererState rhs) -> CellRendererState
  {
    return static_cast<CellRendererState> (static_cast<unsigned> (lhs) |
                                           static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (CellRendererState lhs, CellRendererState rhs) -> CellRendererState
  {
    return static_cast<CellRendererState> (static_cast<unsigned> (lhs) &
                                           static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (CellRendererState lhs, CellRendererState rhs) -> CellRendererState
  {
    return static_cast<CellRendererState> (static_cast<unsigned> (lhs) ^
                                           static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(CellRendererState flags) -> CellRendererState
  {
    return static_cast<CellRendererState> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (CellRendererState& lhs, CellRendererState rhs) -> CellRendererState&
  {
    return (lhs = static_cast<CellRendererState> (static_cast<unsigned> (lhs) |
                                                  static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (CellRendererState& lhs, CellRendererState rhs) -> CellRendererState&
  {
    return (lhs = static_cast<CellRendererState> (static_cast<unsigned> (lhs) &
                                                  static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (CellRendererState& lhs, CellRendererState rhs) -> CellRendererState&
  {
    return (lhs = static_cast<CellRendererState> (static_cast<unsigned> (lhs) ^
                                                  static_cast<unsigned> (rhs)));
  }

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::CellRendererState>
    : public Glib::Value_Flags<Gtk::CellRendererState>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

  enum class CellRendererMode
  {
    INERT,
    ACTIVATABLE,
    EDITABLE
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::CellRendererMode>
    : public Glib::Value_Enum<Gtk::CellRendererMode>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

  class GTKMM_API CellRenderer : public Object
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef CellRenderer CppObjectType;
    typedef CellRenderer_Class CppClassType;
    typedef GtkCellRenderer BaseObjectType;
    typedef GtkCellRendererClass BaseClassType;
#endif

    CellRenderer (CellRenderer&& src) noexcept;
    auto
    operator= (CellRenderer&& src) noexcept -> CellRenderer&;

    CellRenderer (const CellRenderer&) = delete;
    auto
    operator= (const CellRenderer&) -> CellRenderer& = delete;

    ~CellRenderer () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class CellRenderer_Class;
    static CppClassType cellrenderer_class_;

  protected:
    explicit CellRenderer (const Glib::ConstructParams& construct_params);
    explicit CellRenderer (GtkCellRenderer* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkCellRenderer*
    {
      return reinterpret_cast<GtkCellRenderer*> (gobject_);
    }

    auto
    gobj () const -> const GtkCellRenderer*
    {
      return reinterpret_cast<GtkCellRenderer*> (gobject_);
    }

  private:
  public:
    auto
    get_request_mode () const -> SizeRequestMode;

    void
    get_preferred_width (Widget& widget,
                         int& minimum_width,
                         int& natural_width) const;

    void
    get_preferred_height_for_width (Widget& widget,
                                    int width,
                                    int& minimum_height,
                                    int& natural_height) const;

    void
    get_preferred_height (Widget& widget,
                          int& minimum_height,
                          int& natural_height) const;

    void
    get_preferred_width_for_height (Widget& widget,
                                    int height,
                                    int& minimum_width,
                                    int& natural_width) const;

    void
    get_preferred_size (Widget& widget,
                        Requisition& minimum_size,
                        Requisition& natural_size) const;

    auto
    get_aligned_area (Widget& widget,
                      CellRendererState flags,
                      const Gdk::Rectangle& cell_area) const -> Gdk::Rectangle;

    void
    snapshot (const Glib::RefPtr<Gtk::Snapshot>& snapshot,
              Widget& widget,
              const Gdk::Rectangle& background_area,
              const Gdk::Rectangle& cell_area,
              CellRendererState flags);

    auto
    activate (const Glib::RefPtr<const Gdk::Event>& event,
              Widget& widget,
              const Glib::ustring& path,
              const Gdk::Rectangle& background_area,
              const Gdk::Rectangle& cell_area,
              CellRendererState flags) -> bool;

    auto
    start_editing (const Glib::RefPtr<const Gdk::Event>& event,
                   Widget& widget,
                   const Glib::ustring& path,
                   const Gdk::Rectangle& background_area,
                   const Gdk::Rectangle& cell_area,
                   CellRendererState flags = CellRendererState (0))
        -> CellEditable*;

    void
    set_fixed_size (int width, int height);

    void
    get_fixed_size (int& width, int& height) const;

    void
    set_alignment (float xalign, float yalign);

    void
    get_alignment (float& xalign, float& yalign) const;

    void
    set_padding (int xpad, int ypad);

    void
    get_padding (int& xpad, int& ypad) const;

    void
    set_visible (bool visible = true);

    auto
    get_visible () const -> bool;

    void
    set_sensitive (bool sensitive = true);

    auto
    get_sensitive () const -> bool;

    auto
    is_activatable () const -> bool;

    void
    set_is_expander (bool is_expander = true);

    auto
    get_is_expander () const -> bool;

    void
    set_is_expanded (bool is_expanded = true);

    auto
    get_is_expanded () const -> bool;

    void
    stop_editing (bool canceled = false);

    auto
    get_state (Widget& widget, CellRendererState cell_state) const
        -> StateFlags;

    auto
    get_state (CellRendererState cell_state) const -> StateFlags;

    virtual auto
    _property_renderable () -> Glib::PropertyProxy_Base;

    auto
    signal_editing_canceled () -> Glib::SignalProxy<void ()>;

    auto
    signal_editing_started ()
        -> Glib::SignalProxy<void (CellEditable*, const Glib::ustring&)>;

    auto
    property_mode () -> Glib::PropertyProxy<CellRendererMode>;

    auto
    property_mode () const -> Glib::PropertyProxy_ReadOnly<CellRendererMode>;

    auto
    property_visible () -> Glib::PropertyProxy<bool>;

    auto
    property_visible () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_sensitive () -> Glib::PropertyProxy<bool>;

    auto
    property_sensitive () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_xalign () -> Glib::PropertyProxy<float>;

    auto
    property_xalign () const -> Glib::PropertyProxy_ReadOnly<float>;

    auto
    property_yalign () -> Glib::PropertyProxy<float>;

    auto
    property_yalign () const -> Glib::PropertyProxy_ReadOnly<float>;

    auto
    property_xpad () -> Glib::PropertyProxy<unsigned int>;

    auto
    property_xpad () const -> Glib::PropertyProxy_ReadOnly<unsigned int>;

    auto
    property_ypad () -> Glib::PropertyProxy<unsigned int>;

    auto
    property_ypad () const -> Glib::PropertyProxy_ReadOnly<unsigned int>;

    auto
    property_width () -> Glib::PropertyProxy<int>;

    auto
    property_width () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_height () -> Glib::PropertyProxy<int>;

    auto
    property_height () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_is_expander () -> Glib::PropertyProxy<bool>;

    auto
    property_is_expander () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_is_expanded () -> Glib::PropertyProxy<bool>;

    auto
    property_is_expanded () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_cell_background () -> Glib::PropertyProxy_WriteOnly<Glib::ustring>;

    auto
    property_cell_background_rgba () -> Glib::PropertyProxy<Gdk::RGBA>;

    auto
    property_cell_background_rgba () const
        -> Glib::PropertyProxy_ReadOnly<Gdk::RGBA>;

    auto
    property_cell_background_set () -> Glib::PropertyProxy<bool>;

    auto
    property_cell_background_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_editing () const -> Glib::PropertyProxy_ReadOnly<bool>;

  protected:
    CellRenderer ();

    virtual auto
    get_request_mode_vfunc () const -> SizeRequestMode;

    virtual void
    get_preferred_width_vfunc (Widget& widget,
                               int& minimum_width,
                               int& natural_width) const;

    virtual void
    get_preferred_height_for_width_vfunc (Widget& widget,
                                          int width,
                                          int& minimum_height,
                                          int& natural_height) const;

    virtual void
    get_preferred_height_vfunc (Widget& widget,
                                int& minimum_height,
                                int& natural_height) const;

    virtual void
    get_preferred_width_for_height_vfunc (Widget& widget,
                                          int height,
                                          int& minimum_width,
                                          int& natural_width) const;

    virtual void
    snapshot_vfunc (const Glib::RefPtr<Gtk::Snapshot>& snapshot,
                    Widget& widget,
                    const Gdk::Rectangle& background_area,
                    const Gdk::Rectangle& cell_area,
                    CellRendererState flags);

    virtual auto
    activate_vfunc (const Glib::RefPtr<const Gdk::Event>& event,
                    Widget& widget,
                    const Glib::ustring& path,
                    const Gdk::Rectangle& background_area,
                    const Gdk::Rectangle& cell_area,
                    CellRendererState flags) -> bool;

    virtual auto
    start_editing_vfunc (const Glib::RefPtr<const Gdk::Event>& event,
                         Widget& widget,
                         const Glib::ustring& path,
                         const Gdk::Rectangle& background_area,
                         const Gdk::Rectangle& cell_area,
                         CellRendererState flags) -> CellEditable*;

  public:
  public:
  protected:
    virtual void
    on_editing_canceled ();

    virtual void
    on_editing_started (CellEditable* editable, const Glib::ustring& path);
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkCellRenderer* object, bool take_copy = false) -> Gtk::CellRenderer*;
} // namespace Glib

#endif
