// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FONTDIALOG_H
#define _GTKMM_FONTDIALOG_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/cancellable.hxx>
#include <libmm/glib/object.hxx>
#include <libmm/gtk/filter.hxx>
#include <libmm/pango/fontdescription.hxx>
#include <libmm/pango/fontface.hxx>
#include <libmm/pango/fontfamily.hxx>
#include <libmm/pango/fontmap.hxx>
#include <libmm/pango/language.hxx>
#include <tuple>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT FontDialog_Class;
}
#endif

namespace Gtk
{
  class Window;

  class LIBMM_GTK_SYMEXPORT FontDialog : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = FontDialog;
    using CppClassType = FontDialog_Class;
    using BaseObjectType = GtkFontDialog;
    using BaseClassType = GtkFontDialogClass;

    FontDialog (const FontDialog&) = delete;
    auto
    operator= (const FontDialog&) -> FontDialog& = delete;

  private:
    friend class FontDialog_Class;
    static CppClassType fontdialog_class_;

  protected:
    explicit FontDialog (const Glib::ConstructParams& construct_params);
    explicit FontDialog (GtkFontDialog* castitem);

#endif

  public:
    FontDialog (FontDialog&& src) noexcept;
    auto
    operator= (FontDialog&& src) noexcept -> FontDialog&;

    ~FontDialog () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkFontDialog*
    {
      return reinterpret_cast<GtkFontDialog*> (gobject_);
    }

    auto
    gobj () const -> const GtkFontDialog*
    {
      return reinterpret_cast<GtkFontDialog*> (gobject_);
    }

    auto
    gobj_copy () -> GtkFontDialog*;

  private:
  protected:
    FontDialog ();

  public:
    static auto
    create () -> Glib::RefPtr<FontDialog>;

    auto
    get_title () const -> Glib::ustring;

    auto
    set_title (const Glib::ustring& title) -> void;

    auto
    get_modal () const -> bool;

    auto
    set_modal (bool modal = true) -> void;

    auto
    get_language () const -> Pango::Language;

    auto
    set_language (const Pango::Language& language) -> void;

    auto
    get_font_map () -> Glib::RefPtr<Pango::FontMap>;

    auto
    get_font_map () const -> Glib::RefPtr<const Pango::FontMap>;

    auto
    set_font_map (const Glib::RefPtr<Pango::FontMap>& fontmap) -> void;

    auto
    get_filter () -> Glib::RefPtr<Filter>;

    auto
    get_filter () const -> Glib::RefPtr<const Filter>;

    auto
    set_filter (const Glib::RefPtr<Filter>& filter) -> void;

    auto
    choose_family (Window& parent,
                   const Gio::SlotAsyncReady& slot,
                   const Glib::RefPtr<Pango::FontFamily>& initial_value = {},
                   const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    choose_family (const Gio::SlotAsyncReady& slot,
                   const Glib::RefPtr<Pango::FontFamily>& initial_value = {},
                   const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    choose_family_finish (const Glib::RefPtr<Gio::AsyncResult>& result) const
        -> Glib::RefPtr<Pango::FontFamily>;

    auto
    choose_face (Window& parent,
                 const Gio::SlotAsyncReady& slot,
                 const Glib::RefPtr<Pango::FontFace>& initial_value = {},
                 const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    choose_face (const Gio::SlotAsyncReady& slot,
                 const Glib::RefPtr<Pango::FontFace>& initial_value = {},
                 const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    choose_face_finish (const Glib::RefPtr<Gio::AsyncResult>& result) const
        -> Glib::RefPtr<Pango::FontFace>;

    auto
    choose_font (Window& parent,
                 const Gio::SlotAsyncReady& slot,
                 const Pango::FontDescription& initial_value,
                 const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    choose_font (Window& parent,
                 const Gio::SlotAsyncReady& slot,
                 const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    choose_font (const Gio::SlotAsyncReady& slot,
                 const Pango::FontDescription& initial_value,
                 const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    choose_font (const Gio::SlotAsyncReady& slot,
                 const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    choose_font_finish (const Glib::RefPtr<Gio::AsyncResult>& result) const
        -> Pango::FontDescription;

    auto
    choose_font_and_features (
        Window& parent,
        const Gio::SlotAsyncReady& slot,
        const Pango::FontDescription& initial_value,
        const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const -> void;

    auto
    choose_font_and_features (
        Window& parent,
        const Gio::SlotAsyncReady& slot,
        const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const -> void;

    auto
    choose_font_and_features (
        const Gio::SlotAsyncReady& slot,
        const Pango::FontDescription& initial_value,
        const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const -> void;

    auto
    choose_font_and_features (
        const Gio::SlotAsyncReady& slot,
        const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const -> void;

    auto
    choose_font_and_features_finish (
        const Glib::RefPtr<Gio::AsyncResult>& result) const
        -> std::tuple<Pango::FontDescription, Glib::ustring, Pango::Language>;

    auto
    property_title () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_modal () -> Glib::PropertyProxy<bool>;

    auto
    property_modal () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_language () -> Glib::PropertyProxy<Pango::Language>;

    auto
    property_language () const -> Glib::PropertyProxy_ReadOnly<Pango::Language>;

    auto
    property_font_map () -> Glib::PropertyProxy<Glib::RefPtr<Pango::FontMap>>;

    auto
    property_font_map () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Pango::FontMap>>;

    auto
    property_filter () -> Glib::PropertyProxy<Glib::RefPtr<Filter>>;

    auto
    property_filter () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Filter>>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkFontDialog* object, bool take_copy = false) -> Glib::RefPtr<Gtk::FontDialog>;
} // namespace Glib

#endif
