// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_COLORDIALOG_H
#define _GTKMM_COLORDIALOG_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm/gdk/rgba.hxx>
#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/cancellable.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT ColorDialog_Class;
}
#endif

namespace gtk
{
  class Window;

  class LIBMM_GTK_SYMEXPORT ColorDialog : public glib::Object
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
    explicit ColorDialog (const glib::ConstructParams& construct_params);
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
    create () -> glib::RefPtr<ColorDialog>;

    auto
    get_title () const -> glib::ustring;

    auto
    set_title (const glib::ustring& title) -> void;

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
                 const gdk::RGBA& initial_color,
                 const gio::SlotAsyncReady& slot,
                 const glib::RefPtr<gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    choose_rgba (Window& parent,
                 const gio::SlotAsyncReady& slot,
                 const glib::RefPtr<gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    choose_rgba (const gdk::RGBA& initial_color,
                 const gio::SlotAsyncReady& slot,
                 const glib::RefPtr<gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    choose_rgba (const gio::SlotAsyncReady& slot,
                 const glib::RefPtr<gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    choose_rgba_finish (const glib::RefPtr<gio::AsyncResult>& result) const
        -> gdk::RGBA;

    auto
    property_title () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_modal () -> glib::PropertyProxy<bool>;

    auto
    property_modal () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_with_alpha () -> glib::PropertyProxy<bool>;

    auto
    property_with_alpha () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkColorDialog* object, bool take_copy = false) -> glib::RefPtr<gtk::ColorDialog>;
} // namespace glib

#endif
