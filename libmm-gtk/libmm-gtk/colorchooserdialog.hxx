
#ifndef _GTKMM_COLORCHOOSERDIALOG_H
#define _GTKMM_COLORCHOOSERDIALOG_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/colorchooser.hxx>
#include <libmm-gtk/dialog.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkColorChooserDialog = struct _GtkColorChooserDialog;
using GtkColorChooserDialogClass = struct _GtkColorChooserDialogClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API ColorChooserDialog_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API ColorChooserDialog : public Dialog,
                                       public ColorChooser
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ColorChooserDialog CppObjectType;
    typedef ColorChooserDialog_Class CppClassType;
    typedef GtkColorChooserDialog BaseObjectType;
    typedef GtkColorChooserDialogClass BaseClassType;
#endif

    ColorChooserDialog (ColorChooserDialog&& src) noexcept;
    auto
    operator= (ColorChooserDialog&& src) noexcept -> ColorChooserDialog&;

    ColorChooserDialog (const ColorChooserDialog&) = delete;
    auto
    operator= (const ColorChooserDialog&) -> ColorChooserDialog& = delete;

    ~ColorChooserDialog () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class ColorChooserDialog_Class;
    static CppClassType colorchooserdialog_class_;

  protected:
    explicit ColorChooserDialog (const Glib::ConstructParams& construct_params);
    explicit ColorChooserDialog (GtkColorChooserDialog* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkColorChooserDialog*
    {
      return reinterpret_cast<GtkColorChooserDialog*> (gobject_);
    }

    auto
    gobj () const -> const GtkColorChooserDialog*
    {
      return reinterpret_cast<GtkColorChooserDialog*> (gobject_);
    }

  private:
  public:
    ColorChooserDialog ();

    explicit ColorChooserDialog (const Glib::ustring& title);

    explicit ColorChooserDialog (const Glib::ustring& title,
                                 Window& transient_for);

    auto
    property_show_editor () -> Glib::PropertyProxy<bool>;

    auto
    property_show_editor () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkColorChooserDialog* object, bool take_copy = false) -> Gtk::ColorChooserDialog*;
} // namespace Glib

#endif
