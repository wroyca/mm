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
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT FontDialog_Class;
}
#endif

namespace gtk
{
  class Window;

  class LIBMM_GTK_SYMEXPORT FontDialog : public glib::Object
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
    explicit FontDialog (const glib::ConstructParams& construct_params);
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
    create () -> glib::RefPtr<FontDialog>;

    auto
    get_title () const -> glib::ustring;

    auto
    set_title (const glib::ustring& title) -> void;

    auto
    get_modal () const -> bool;

    auto
    set_modal (bool modal = true) -> void;

    auto
    get_language () const -> pango::Language;

    auto
    set_language (const pango::Language& language) -> void;

    auto
    get_font_map () -> glib::RefPtr<pango::FontMap>;

    auto
    get_font_map () const -> glib::RefPtr<const pango::FontMap>;

    auto
    set_font_map (const glib::RefPtr<pango::FontMap>& fontmap) -> void;

    auto
    get_filter () -> glib::RefPtr<Filter>;

    auto
    get_filter () const -> glib::RefPtr<const Filter>;

    auto
    set_filter (const glib::RefPtr<Filter>& filter) -> void;

    auto
    choose_family (Window& parent,
                   const gio::SlotAsyncReady& slot,
                   const glib::RefPtr<pango::FontFamily>& initial_value = {},
                   const glib::RefPtr<gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    choose_family (const gio::SlotAsyncReady& slot,
                   const glib::RefPtr<pango::FontFamily>& initial_value = {},
                   const glib::RefPtr<gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    choose_family_finish (const glib::RefPtr<gio::AsyncResult>& result) const
        -> glib::RefPtr<pango::FontFamily>;

    auto
    choose_face (Window& parent,
                 const gio::SlotAsyncReady& slot,
                 const glib::RefPtr<pango::FontFace>& initial_value = {},
                 const glib::RefPtr<gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    choose_face (const gio::SlotAsyncReady& slot,
                 const glib::RefPtr<pango::FontFace>& initial_value = {},
                 const glib::RefPtr<gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    choose_face_finish (const glib::RefPtr<gio::AsyncResult>& result) const
        -> glib::RefPtr<pango::FontFace>;

    auto
    choose_font (Window& parent,
                 const gio::SlotAsyncReady& slot,
                 const pango::FontDescription& initial_value,
                 const glib::RefPtr<gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    choose_font (Window& parent,
                 const gio::SlotAsyncReady& slot,
                 const glib::RefPtr<gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    choose_font (const gio::SlotAsyncReady& slot,
                 const pango::FontDescription& initial_value,
                 const glib::RefPtr<gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    choose_font (const gio::SlotAsyncReady& slot,
                 const glib::RefPtr<gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    choose_font_finish (const glib::RefPtr<gio::AsyncResult>& result) const
        -> pango::FontDescription;

    auto
    choose_font_and_features (
        Window& parent,
        const gio::SlotAsyncReady& slot,
        const pango::FontDescription& initial_value,
        const glib::RefPtr<gio::Cancellable>& cancellable = {}) const -> void;

    auto
    choose_font_and_features (
        Window& parent,
        const gio::SlotAsyncReady& slot,
        const glib::RefPtr<gio::Cancellable>& cancellable = {}) const -> void;

    auto
    choose_font_and_features (
        const gio::SlotAsyncReady& slot,
        const pango::FontDescription& initial_value,
        const glib::RefPtr<gio::Cancellable>& cancellable = {}) const -> void;

    auto
    choose_font_and_features (
        const gio::SlotAsyncReady& slot,
        const glib::RefPtr<gio::Cancellable>& cancellable = {}) const -> void;

    auto
    choose_font_and_features_finish (
        const glib::RefPtr<gio::AsyncResult>& result) const
        -> std::tuple<pango::FontDescription, glib::ustring, pango::Language>;

    auto
    property_title () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_modal () -> glib::PropertyProxy<bool>;

    auto
    property_modal () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_language () -> glib::PropertyProxy<pango::Language>;

    auto
    property_language () const -> glib::PropertyProxy_ReadOnly<pango::Language>;

    auto
    property_font_map () -> glib::PropertyProxy<glib::RefPtr<pango::FontMap>>;

    auto
    property_font_map () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<pango::FontMap>>;

    auto
    property_filter () -> glib::PropertyProxy<glib::RefPtr<Filter>>;

    auto
    property_filter () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Filter>>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkFontDialog* object, bool take_copy = false) -> glib::RefPtr<gtk::FontDialog>;
} // namespace glib

#endif
