// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_COLORCHOOSER_H
#define _GTKMM_COLORCHOOSER_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/rgba.hxx>
#include <libmm-glib/interface.hxx>
#include <libmm-gtk/enums.hxx>

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
namespace Gtk
{
  class GTKMM_API ColorChooser_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API ColorChooser : public Glib::Interface
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

    explicit ColorChooser (const Glib::Interface_Class& interface_class);

  public:
    explicit ColorChooser (GtkColorChooser* castitem);

  protected:
#endif

  public:
    ColorChooser (ColorChooser&& src) noexcept;
    auto
    operator= (ColorChooser&& src) noexcept -> ColorChooser&;

    ~ColorChooser () noexcept override;

    static void
    add_interface (GType gtype_implementer);

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
    get_rgba () const -> Gdk::RGBA;

    void
    set_rgba (const Gdk::RGBA& color);

    auto
    get_use_alpha () const -> bool;

    void
    set_use_alpha (bool use_alpha = true);

    void
    add_palette (Orientation orientation,
                 int colors_per_line,
                 const std::vector<Gdk::RGBA>& colors);

    auto
    signal_color_activated () -> Glib::SignalProxy<void (const Gdk::RGBA&)>;

    auto
    property_rgba () -> Glib::PropertyProxy<Gdk::RGBA>;

    auto
    property_rgba () const -> Glib::PropertyProxy_ReadOnly<Gdk::RGBA>;

    auto
    property_use_alpha () -> Glib::PropertyProxy<bool>;

    auto
    property_use_alpha () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
    virtual void
    on_color_activated (const Gdk::RGBA& color);
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkColorChooser* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ColorChooser>;

} // namespace Glib

#endif
