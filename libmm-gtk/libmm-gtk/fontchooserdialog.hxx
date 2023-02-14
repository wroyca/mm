// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FONTCHOOSERDIALOG_H
#define _GTKMM_FONTCHOOSERDIALOG_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/dialog.hxx>
#include <libmm-gtk/fontchooser.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkFontChooserDialog = struct _GtkFontChooserDialog;
using GtkFontChooserDialogClass = struct _GtkFontChooserDialogClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API FontChooserDialog_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API FontChooserDialog : public Dialog,
                                      public FontChooser
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef FontChooserDialog CppObjectType;
    typedef FontChooserDialog_Class CppClassType;
    typedef GtkFontChooserDialog BaseObjectType;
    typedef GtkFontChooserDialogClass BaseClassType;
#endif

    FontChooserDialog (FontChooserDialog&& src) noexcept;
    auto
    operator= (FontChooserDialog&& src) noexcept -> FontChooserDialog&;

    FontChooserDialog (const FontChooserDialog&) = delete;
    auto
    operator= (const FontChooserDialog&) -> FontChooserDialog& = delete;

    ~FontChooserDialog () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class FontChooserDialog_Class;
    static CppClassType fontchooserdialog_class_;

  protected:
    explicit FontChooserDialog (const Glib::ConstructParams& construct_params);
    explicit FontChooserDialog (GtkFontChooserDialog* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkFontChooserDialog*
    {
      return reinterpret_cast<GtkFontChooserDialog*> (gobject_);
    }

    auto
    gobj () const -> const GtkFontChooserDialog*
    {
      return reinterpret_cast<GtkFontChooserDialog*> (gobject_);
    }

  private:
  public:
    FontChooserDialog ();
    explicit FontChooserDialog (const Glib::ustring& title);

    explicit FontChooserDialog (const Glib::ustring& title,
                                Window& transient_for);

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkFontChooserDialog* object, bool take_copy = false) -> Gtk::FontChooserDialog*;
} // namespace Glib

#endif
