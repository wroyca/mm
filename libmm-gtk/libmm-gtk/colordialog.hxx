// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_COLORDIALOG_H
#define _GTKMM_COLORDIALOG_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm-gdk/rgba.hxx>
#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/cancellable.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT ColorDialog_Class;
}
#endif

namespace Gtk
{
  class Window;

  class LIBMM_GTK_SYMEXPORT ColorDialog : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ColorDialog;
    using CppClassType = ColorDialog_Class;
    using BaseObjectType = GtkColorDialog;
    using BaseClassType = GtkColorDialogClass;

    ColorDialog (const ColorDialog&) = delete;
    auto
    operator= (const ColorDialog&) -> ColorDialog& = delete;

  private:
    friend class ColorDialog_Class;
    static CppClassType colordialog_class_;

  protected:
    explicit ColorDialog (const Glib::ConstructParams& construct_params);
    explicit ColorDialog (GtkColorDialog* castitem);

#endif

  public:
    ColorDialog (ColorDialog&& src) noexcept;
    auto
    operator= (ColorDialog&& src) noexcept -> ColorDialog&;

    ~ColorDialog () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkColorDialog*
    {
      return reinterpret_cast<GtkColorDialog*> (gobject_);
    }

    auto
    gobj () const -> const GtkColorDialog*
    {
      return reinterpret_cast<GtkColorDialog*> (gobject_);
    }

    auto
    gobj_copy () -> GtkColorDialog*;

  private:
  protected:
    ColorDialog ();

  public:
    static auto
    create () -> Glib::RefPtr<ColorDialog>;

    auto
    get_title () const -> Glib::ustring;

    auto
    set_title (const Glib::ustring& title) -> void;

    auto
    get_modal () const -> bool;

    auto
    set_modal (bool modal = true) -> void;

    auto
    get_with_alpha () const -> bool;

    auto
    set_with_alpha (bool with_alpha = true) -> void;

    auto
    choose_rgba (Window& parent,
                 const Gdk::RGBA& initial_color,
                 const Gio::SlotAsyncReady& slot,
                 const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    choose_rgba (Window& parent,
                 const Gio::SlotAsyncReady& slot,
                 const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    choose_rgba (const Gdk::RGBA& initial_color,
                 const Gio::SlotAsyncReady& slot,
                 const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    choose_rgba (const Gio::SlotAsyncReady& slot,
                 const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    choose_rgba_finish (const Glib::RefPtr<Gio::AsyncResult>& result) const
        -> Gdk::RGBA;

    auto
    property_title () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_modal () -> Glib::PropertyProxy<bool>;

    auto
    property_modal () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_with_alpha () -> Glib::PropertyProxy<bool>;

    auto
    property_with_alpha () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkColorDialog* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ColorDialog>;
} // namespace Glib

#endif
