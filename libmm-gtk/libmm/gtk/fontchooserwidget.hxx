// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FONTCHOOSERWIDGET_H
#define _GTKMM_FONTCHOOSERWIDGET_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gtk/fontchooser.hxx>
  #include <libmm/gtk/widget.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkFontChooserWidget = struct _GtkFontChooserWidget;
using GtkFontChooserWidgetClass = struct _GtkFontChooserWidgetClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT FontChooserWidget_Class;
}
  #endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT FontChooserWidget : public Widget,
                                      public FontChooser
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef FontChooserWidget CppObjectType;
    typedef FontChooserWidget_Class CppClassType;
    typedef GtkFontChooserWidget BaseObjectType;
    typedef GtkFontChooserWidgetClass BaseClassType;
  #endif

    FontChooserWidget (FontChooserWidget&& src) noexcept;
    auto
    operator= (FontChooserWidget&& src) noexcept -> FontChooserWidget&;

    FontChooserWidget (const FontChooserWidget&) = delete;
    auto
    operator= (const FontChooserWidget&) -> FontChooserWidget& = delete;

    ~FontChooserWidget () noexcept override;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class FontChooserWidget_Class;
    static CppClassType fontchooserwidget_class_;

  protected:
    explicit FontChooserWidget (const glib::ConstructParams& construct_params);
    explicit FontChooserWidget (GtkFontChooserWidget* castitem);

  #endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkFontChooserWidget*
    {
      return reinterpret_cast<GtkFontChooserWidget*> (gobject_);
    }

    auto
    gobj () const -> const GtkFontChooserWidget*
    {
      return reinterpret_cast<GtkFontChooserWidget*> (gobject_);
    }

  private:
  public:
    FontChooserWidget ();

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkFontChooserWidget* object, bool take_copy = false) -> gtk::FontChooserWidget*;
} // namespace glib

#endif

#endif
