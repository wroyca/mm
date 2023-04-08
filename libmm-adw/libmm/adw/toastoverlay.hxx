// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_TOASTOVERLAY_H
#define _LIBADWAITAMM_TOASTOVERLAY_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/mm-gtk.hxx>

#include <adwaita.h>
#include <libmm/adw/toast.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT toast_overlay_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT toast_overlay : public gtk::Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = toast_overlay;
    using CppClassType = toast_overlay_class;
    using BaseObjectType = AdwToastOverlay;
    using BaseClassType = AdwToastOverlayClass;
#endif

    toast_overlay (toast_overlay&& src) noexcept;
    auto
    operator= (toast_overlay&& src) noexcept -> toast_overlay&;

    toast_overlay (const toast_overlay&) = delete;
    auto
    operator= (const toast_overlay&) -> toast_overlay& = delete;

    ~toast_overlay () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class toast_overlay_class;
    static CppClassType toastoverlay_class_;

  protected:
    explicit toast_overlay (const glib::ConstructParams& construct_params);
    explicit toast_overlay (AdwToastOverlay* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwToastOverlay*
    {
      return reinterpret_cast<AdwToastOverlay*> (gobject_);
    }

    auto
    gobj () const -> const AdwToastOverlay*
    {
      return reinterpret_cast<AdwToastOverlay*> (gobject_);
    }

  private:
  public:
    toast_overlay ();

    auto
    add_toast (toast* toast) -> void;

    auto
    get_child () const -> gtk::Widget*;

    auto
    set_child (gtk::Widget* child) -> void;

    auto
    property_child () -> glib::PropertyProxy<gtk::Widget*>;

    auto
    property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwToastOverlay* object, bool take_copy = false) -> adw::toast_overlay*;
}

#endif
