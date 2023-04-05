// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CELLRENDERER_H
#define _GTKMM_CELLRENDERER_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gtk/celleditable.hxx>
  #include <libmm/gtk/widget.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellRenderer = struct _GtkCellRenderer;
using GtkCellRendererClass = struct _GtkCellRendererClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT CellRenderer_Class;
}
  #endif

namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Snapshot;

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

} // namespace gtk

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::CellRendererState>
    : public glib::Value_Flags<gtk::CellRendererState>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
  #endif

namespace gtk
{

  enum class CellRendererMode
  {
    INERT,
    ACTIVATABLE,
    EDITABLE
  };

} // namespace gtk

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::CellRendererMode>
    : public glib::Value_Enum<gtk::CellRendererMode>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
  #endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT CellRenderer : public Object
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
    friend LIBMM_GTK_SYMEXPORT class CellRenderer_Class;
    static CppClassType cellrenderer_class_;

  protected:
    explicit CellRenderer (const glib::ConstructParams& construct_params);
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

    auto
    get_preferred_width (Widget& widget,
                         int& minimum_width,
                         int& natural_width) const -> void;

    auto
    get_preferred_height_for_width (Widget& widget,
                                    int width,
                                    int& minimum_height,
                                    int& natural_height) const -> void;

    auto
    get_preferred_height (Widget& widget,
                          int& minimum_height,
                          int& natural_height) const -> void;

    auto
    get_preferred_width_for_height (Widget& widget,
                                    int height,
                                    int& minimum_width,
                                    int& natural_width) const -> void;

    auto
    get_preferred_size (Widget& widget,
                        Requisition& minimum_size,
                        Requisition& natural_size) const -> void;

    auto
    get_aligned_area (Widget& widget,
                      CellRendererState flags,
                      const gdk::Rectangle& cell_area) const -> gdk::Rectangle;

    auto
    snapshot (const glib::RefPtr<gtk::Snapshot>& snapshot,
              Widget& widget,
              const gdk::Rectangle& background_area,
              const gdk::Rectangle& cell_area,
              CellRendererState flags) -> void;

    auto
    activate (const glib::RefPtr<const gdk::Event>& event,
              Widget& widget,
              const glib::ustring& path,
              const gdk::Rectangle& background_area,
              const gdk::Rectangle& cell_area,
              CellRendererState flags) -> bool;

    auto
    start_editing (const glib::RefPtr<const gdk::Event>& event,
                   Widget& widget,
                   const glib::ustring& path,
                   const gdk::Rectangle& background_area,
                   const gdk::Rectangle& cell_area,
                   CellRendererState flags = CellRendererState (0))
        -> CellEditable*;

    auto
    set_fixed_size (int width, int height) -> void;

    auto
    get_fixed_size (int& width, int& height) const -> void;

    auto
    set_alignment (float xalign, float yalign) -> void;

    auto
    get_alignment (float& xalign, float& yalign) const -> void;

    auto
    set_padding (int xpad, int ypad) -> void;

    auto
    get_padding (int& xpad, int& ypad) const -> void;

    auto
    set_visible (bool visible = true) -> void;

    auto
    get_visible () const -> bool;

    auto
    set_sensitive (bool sensitive = true) -> void;

    auto
    get_sensitive () const -> bool;

    auto
    is_activatable () const -> bool;

    auto
    set_is_expander (bool is_expander = true) -> void;

    auto
    get_is_expander () const -> bool;

    auto
    set_is_expanded (bool is_expanded = true) -> void;

    auto
    get_is_expanded () const -> bool;

    auto
    stop_editing (bool canceled = false) -> void;

    auto
    get_state (Widget& widget, CellRendererState cell_state) const
        -> StateFlags;

    auto
    get_state (CellRendererState cell_state) const -> StateFlags;

    virtual auto
    _property_renderable () -> glib::PropertyProxy_Base;

    auto
    signal_editing_canceled () -> glib::SignalProxy<void ()>;

    auto
    signal_editing_started ()
        -> glib::SignalProxy<void (CellEditable*, const glib::ustring&)>;

    auto
    property_mode () -> glib::PropertyProxy<CellRendererMode>;

    auto
    property_mode () const -> glib::PropertyProxy_ReadOnly<CellRendererMode>;

    auto
    property_visible () -> glib::PropertyProxy<bool>;

    auto
    property_visible () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_sensitive () -> glib::PropertyProxy<bool>;

    auto
    property_sensitive () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_xalign () -> glib::PropertyProxy<float>;

    auto
    property_xalign () const -> glib::PropertyProxy_ReadOnly<float>;

    auto
    property_yalign () -> glib::PropertyProxy<float>;

    auto
    property_yalign () const -> glib::PropertyProxy_ReadOnly<float>;

    auto
    property_xpad () -> glib::PropertyProxy<unsigned int>;

    auto
    property_xpad () const -> glib::PropertyProxy_ReadOnly<unsigned int>;

    auto
    property_ypad () -> glib::PropertyProxy<unsigned int>;

    auto
    property_ypad () const -> glib::PropertyProxy_ReadOnly<unsigned int>;

    auto
    property_width () -> glib::PropertyProxy<int>;

    auto
    property_width () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_height () -> glib::PropertyProxy<int>;

    auto
    property_height () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_is_expander () -> glib::PropertyProxy<bool>;

    auto
    property_is_expander () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_is_expanded () -> glib::PropertyProxy<bool>;

    auto
    property_is_expanded () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_cell_background () -> glib::PropertyProxy_WriteOnly<glib::ustring>;

    auto
    property_cell_background_rgba () -> glib::PropertyProxy<gdk::RGBA>;

    auto
    property_cell_background_rgba () const
        -> glib::PropertyProxy_ReadOnly<gdk::RGBA>;

    auto
    property_cell_background_set () -> glib::PropertyProxy<bool>;

    auto
    property_cell_background_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_editing () const -> glib::PropertyProxy_ReadOnly<bool>;

  protected:
    CellRenderer ();

    virtual auto
    get_request_mode_vfunc () const -> SizeRequestMode;

    virtual auto
    get_preferred_width_vfunc (Widget& widget,
                               int& minimum_width,
                               int& natural_width) const -> void;

    virtual auto
    get_preferred_height_for_width_vfunc (Widget& widget,
                                          int width,
                                          int& minimum_height,
                                          int& natural_height) const -> void;

    virtual auto
    get_preferred_height_vfunc (Widget& widget,
                                int& minimum_height,
                                int& natural_height) const -> void;

    virtual auto
    get_preferred_width_for_height_vfunc (Widget& widget,
                                          int height,
                                          int& minimum_width,
                                          int& natural_width) const -> void;

    virtual auto
    snapshot_vfunc (const glib::RefPtr<gtk::Snapshot>& snapshot,
                    Widget& widget,
                    const gdk::Rectangle& background_area,
                    const gdk::Rectangle& cell_area,
                    CellRendererState flags) -> void;

    virtual auto
    activate_vfunc (const glib::RefPtr<const gdk::Event>& event,
                    Widget& widget,
                    const glib::ustring& path,
                    const gdk::Rectangle& background_area,
                    const gdk::Rectangle& cell_area,
                    CellRendererState flags) -> bool;

    virtual auto
    start_editing_vfunc (const glib::RefPtr<const gdk::Event>& event,
                         Widget& widget,
                         const glib::ustring& path,
                         const gdk::Rectangle& background_area,
                         const gdk::Rectangle& cell_area,
                         CellRendererState flags) -> CellEditable*;

  public:
  public:
  protected:
    virtual auto
    on_editing_canceled () -> void;

    virtual auto
    on_editing_started (CellEditable* editable, const glib::ustring& path)
        -> void;
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkCellRenderer* object, bool take_copy = false) -> gtk::CellRenderer*;
} // namespace glib

#endif

#endif
