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
namespace Adw
{
  class LIBMM_ADW_SYMEXPORT ToastOverlay_Class;
}
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT ToastOverlay : public Gtk::Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ToastOverlay CppObjectType;
    typedef ToastOverlay_Class CppClassType;
    typedef AdwToastOverlay BaseObjectType;
    typedef AdwToastOverlayClass BaseClassType;
#endif

    ToastOverlay (ToastOverlay&& src) noexcept;
    auto
    operator= (ToastOverlay&& src) noexcept -> ToastOverlay&;

    ToastOverlay (const ToastOverlay&) = delete;
    auto
    operator= (const ToastOverlay&) -> ToastOverlay& = delete;

    ~ToastOverlay () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class ToastOverlay_Class;
    static CppClassType toastoverlay_class_;

  protected:
    explicit ToastOverlay (const Glib::ConstructParams& construct_params);
    explicit ToastOverlay (AdwToastOverlay* castitem);

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
    ToastOverlay ();

    auto
    add_toast (Toast* toast) -> void;

    auto
    get_child () const -> Gtk::Widget*;

    auto
    set_child (Gtk::Widget* child) -> void;

    auto
    property_child () -> Glib::PropertyProxy<Gtk::Widget*>;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwToastOverlay* object, bool take_copy = false) -> Adw::ToastOverlay*;
}

#endif
