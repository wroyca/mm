// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_VOLUMEBUTTON_H
#define _GTKMM_VOLUMEBUTTON_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/scalebutton.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkVolumeButton = struct _GtkVolumeButton;
using GtkVolumeButtonClass = struct _GtkVolumeButtonClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT VolumeButton_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT VolumeButton : public ScaleButton
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef VolumeButton CppObjectType;
    typedef VolumeButton_Class CppClassType;
    typedef GtkVolumeButton BaseObjectType;
    typedef GtkVolumeButtonClass BaseClassType;
#endif

    VolumeButton (VolumeButton&& src) noexcept;
    auto
    operator= (VolumeButton&& src) noexcept -> VolumeButton&;

    VolumeButton (const VolumeButton&) = delete;
    auto
    operator= (const VolumeButton&) -> VolumeButton& = delete;

    ~VolumeButton () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class VolumeButton_Class;
    static CppClassType volumebutton_class_;

  protected:
    explicit VolumeButton (const Glib::ConstructParams& construct_params);
    explicit VolumeButton (GtkVolumeButton* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkVolumeButton*
    {
      return reinterpret_cast<GtkVolumeButton*> (gobject_);
    }

    auto
    gobj () const -> const GtkVolumeButton*
    {
      return reinterpret_cast<GtkVolumeButton*> (gobject_);
    }

  private:
  public:
    VolumeButton ();

    auto
    property_use_symbolic () -> Glib::PropertyProxy<bool>;

    auto
    property_use_symbolic () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkVolumeButton* object, bool take_copy = false) -> Gtk::VolumeButton*;
} // namespace Glib

#endif
