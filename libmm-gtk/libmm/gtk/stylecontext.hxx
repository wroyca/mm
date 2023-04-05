// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_STYLECONTEXT_H
#define _GTKMM_STYLECONTEXT_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gdk/display.hxx>
  #include <libmm/gdk/rgba.hxx>
  #include <libmm/gtk/border.hxx>
  #include <libmm/gtk/enums.hxx>
  #include <libmm/gtk/styleprovider.hxx>

  #include <libmm/gtk/enums.hxx>
  #include <libmm/gtk/mm-gtkconfig.hxx>
  #include <libmm/pango/context.hxx>
  #include <libmm/pango/fontdescription.hxx>
  #include <libmm/pango/layout.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkStyleContext = struct _GtkStyleContext;
using GtkStyleContextClass = struct _GtkStyleContextClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT StyleContext_Class;
}
  #endif

namespace gdk
{
  class LIBMM_GTK_SYMEXPORT Texture;
}

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT StyleContext : public glib::Object
  {
  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = StyleContext;
    using CppClassType = StyleContext_Class;
    using BaseObjectType = GtkStyleContext;
    using BaseClassType = GtkStyleContextClass;

    StyleContext (const StyleContext&) = delete;
    auto
    operator= (const StyleContext&) -> StyleContext& = delete;

  private:
    friend class StyleContext_Class;
    static CppClassType stylecontext_class_;

  protected:
    explicit StyleContext (const glib::ConstructParams& construct_params);
    explicit StyleContext (GtkStyleContext* castitem);

  #endif

  public:
    StyleContext (StyleContext&& src) noexcept;
    auto
    operator= (StyleContext&& src) noexcept -> StyleContext&;

    ~StyleContext () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkStyleContext*
    {
      return reinterpret_cast<GtkStyleContext*> (gobject_);
    }

    auto
    gobj () const -> const GtkStyleContext*
    {
      return reinterpret_cast<GtkStyleContext*> (gobject_);
    }

    auto
    gobj_copy () -> GtkStyleContext*;

  private:
  protected:
    StyleContext ();

  public:
    enum class PrintFlags
    {
      NONE = 0x0,
      RECURSE = 1 << 0,
      SHOW_STYLE = 1 << 1,
      SHOW_CHANGE = 1 << 2
    };

  #ifndef GTKMM_DISABLE_DEPRECATED

    static auto
    add_provider_for_display (const glib::RefPtr<gdk::Display>& display,
                              const glib::RefPtr<StyleProvider>& provider,
                              guint priority) -> void;
  #endif

  #ifndef GTKMM_DISABLE_DEPRECATED

    static auto
    remove_provider_for_display (const glib::RefPtr<gdk::Display>& display,
                                 const glib::RefPtr<StyleProvider>& provider)
        -> void;
  #endif

    auto
    add_provider (const glib::RefPtr<StyleProvider>& provider, guint priority)
        -> void;

    auto
    remove_provider (const glib::RefPtr<StyleProvider>& provider) -> void;

    auto
    context_save () -> void;

    auto
    context_restore () -> void;

  #ifndef GTKMM_DISABLE_DEPRECATED

    auto
    set_state (StateFlags flags) -> void;
  #endif

  #ifndef GTKMM_DISABLE_DEPRECATED

    auto
    get_state () const -> StateFlags;
  #endif

  #ifndef GTKMM_DISABLE_DEPRECATED

    auto
    set_scale (int scale) -> void;
  #endif

  #ifndef GTKMM_DISABLE_DEPRECATED

    auto
    get_scale () const -> int;
  #endif

  #ifndef GTKMM_DISABLE_DEPRECATED

    auto
    add_class (const glib::ustring& class_name) -> void;
  #endif

  #ifndef GTKMM_DISABLE_DEPRECATED

    auto
    remove_class (const glib::ustring& class_name) -> void;
  #endif

  #ifndef GTKMM_DISABLE_DEPRECATED

    auto
    has_class (const glib::ustring& class_name) -> bool;
  #endif

  #ifndef GTKMM_DISABLE_DEPRECATED

    auto
    set_display (const glib::RefPtr<gdk::Display>& display) -> void;
  #endif

  #ifndef GTKMM_DISABLE_DEPRECATED

    auto
    get_display () -> glib::RefPtr<gdk::Display>;
  #endif

  #ifndef GTKMM_DISABLE_DEPRECATED

    auto
    get_display () const -> glib::RefPtr<const gdk::Display>;
  #endif

    auto
    lookup_color (const glib::ustring& color_name, gdk::RGBA& color) -> bool;

    auto
    get_color () const -> gdk::RGBA;

    auto
    get_border () const -> Border;

    auto
    get_padding () const -> Border;

    auto
    get_margin () const -> Border;

    auto
    render_check (const cairo::RefPtr<cairo::Context>& cr,
                  double x,
                  double y,
                  double width,
                  double height) -> void;

    auto
    render_option (const cairo::RefPtr<cairo::Context>& cr,
                   double x,
                   double y,
                   double width,
                   double height) -> void;

    auto
    render_arrow (const cairo::RefPtr<cairo::Context>& cr,
                  double angle,
                  double x,
                  double y,
                  double size) -> void;

    auto
    render_background (const cairo::RefPtr<cairo::Context>& cr,
                       double x,
                       double y,
                       double width,
                       double height) -> void;

    auto
    render_frame (const cairo::RefPtr<cairo::Context>& cr,
                  double x,
                  double y,
                  double width,
                  double height) -> void;

    auto
    render_expander (const cairo::RefPtr<cairo::Context>& cr,
                     double x,
                     double y,
                     double width,
                     double height) -> void;

    auto
    render_focus (const cairo::RefPtr<cairo::Context>& cr,
                  double x,
                  double y,
                  double width,
                  double height) -> void;

    auto
    render_layout (const cairo::RefPtr<cairo::Context>& cr,
                   double x,
                   double y,
                   const glib::RefPtr<pango::Layout>& layout) -> void;

    auto
    render_line (const cairo::RefPtr<cairo::Context>& cr,
                 double x0,
                 double y0,
                 double x1,
                 double y1) -> void;

    auto
    render_handle (const cairo::RefPtr<cairo::Context>& cr,
                   double x,
                   double y,
                   double width,
                   double height) -> void;

    auto
    render_activity (const cairo::RefPtr<cairo::Context>& cr,
                     double x,
                     double y,
                     double width,
                     double height) -> void;

    auto
    render_icon (const cairo::RefPtr<cairo::Context>& cr,
                 const glib::RefPtr<gdk::Texture>& texture,
                 double x,
                 double y) -> void;

    auto
    to_string (PrintFlags flags) const -> glib::ustring;

    auto
    property_display () -> glib::PropertyProxy<glib::RefPtr<gdk::Display>>;

    auto
    property_display () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Display>>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace gtk
{

  inline auto
  operator| (StyleContext::PrintFlags lhs, StyleContext::PrintFlags rhs) -> StyleContext::PrintFlags
  {
    return static_cast<StyleContext::PrintFlags> (static_cast<unsigned> (lhs) |
                                                  static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (StyleContext::PrintFlags lhs, StyleContext::PrintFlags rhs) -> StyleContext::PrintFlags
  {
    return static_cast<StyleContext::PrintFlags> (static_cast<unsigned> (lhs) &
                                                  static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (StyleContext::PrintFlags lhs, StyleContext::PrintFlags rhs) -> StyleContext::PrintFlags
  {
    return static_cast<StyleContext::PrintFlags> (static_cast<unsigned> (lhs) ^
                                                  static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(StyleContext::PrintFlags flags) -> StyleContext::PrintFlags
  {
    return static_cast<StyleContext::PrintFlags> (
        ~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (StyleContext::PrintFlags& lhs, StyleContext::PrintFlags rhs) -> StyleContext::PrintFlags&
  {
    return (lhs = static_cast<StyleContext::PrintFlags> (
                static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (StyleContext::PrintFlags& lhs, StyleContext::PrintFlags rhs) -> StyleContext::PrintFlags&
  {
    return (lhs = static_cast<StyleContext::PrintFlags> (
                static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (StyleContext::PrintFlags& lhs, StyleContext::PrintFlags rhs) -> StyleContext::PrintFlags&
  {
    return (lhs = static_cast<StyleContext::PrintFlags> (
                static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs)));
  }
} // namespace gtk

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::StyleContext::PrintFlags>
    : public glib::Value_Flags<gtk::StyleContext::PrintFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
  #endif

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkStyleContext* object, bool take_copy = false) -> glib::RefPtr<gtk::StyleContext>;
} // namespace glib

#endif

#endif
