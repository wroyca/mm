// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_COLORCHOOSER_H
#define _GTKMM_COLORCHOOSER_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gdk/rgba.hxx>
  #include <libmm/glib/interface.hxx>
  #include <libmm/gtk/enums.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkColorChooserInterface GtkColorChooserInterface;
}
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkColorChooser = struct _GtkColorChooser;
using GtkColorChooserClass = struct _GtkColorChooserClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT ColorChooser_Class;
}
  #endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT ColorChooser : public glib::Interface
  {
  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ColorChooser;
    using CppClassType = ColorChooser_Class;
    using BaseObjectType = GtkColorChooser;
    using BaseClassType = GtkColorChooserInterface;

    ColorChooser (const ColorChooser&) = delete;
    auto
    operator= (const ColorChooser&) -> ColorChooser& = delete;

  private:
    friend class ColorChooser_Class;
    static CppClassType colorchooser_class_;

  #endif
  protected:
    ColorChooser ();

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit ColorChooser (const glib::Interface_Class& interface_class);

  public:
    explicit ColorChooser (GtkColorChooser* castitem);

  protected:
  #endif

  public:
    ColorChooser (ColorChooser&& src) noexcept;
    auto
    operator= (ColorChooser&& src) noexcept -> ColorChooser&;

    ~ColorChooser () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkColorChooser*
    {
      return reinterpret_cast<GtkColorChooser*> (gobject_);
    }

    auto
    gobj () const -> const GtkColorChooser*
    {
      return reinterpret_cast<GtkColorChooser*> (gobject_);
    }

  private:
  public:
    auto
    get_rgba () const -> gdk::RGBA;

    auto
    set_rgba (const gdk::RGBA& color) -> void;

    auto
    get_use_alpha () const -> bool;

    auto
    set_use_alpha (bool use_alpha = true) -> void;

    auto
    add_palette (Orientation orientation,
                 int colors_per_line,
                 const std::vector<gdk::RGBA>& colors) -> void;

    auto
    signal_color_activated () -> glib::SignalProxy<void (const gdk::RGBA&)>;

    auto
    property_rgba () -> glib::PropertyProxy<gdk::RGBA>;

    auto
    property_rgba () const -> glib::PropertyProxy_ReadOnly<gdk::RGBA>;

    auto
    property_use_alpha () -> glib::PropertyProxy<bool>;

    auto
    property_use_alpha () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
    virtual auto
    on_color_activated (const gdk::RGBA& color) -> void;
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkColorChooser* object, bool take_copy = false) -> glib::RefPtr<gtk::ColorChooser>;

} // namespace glib

#endif

#endif
