// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_POPUP_H
#define _GDKMM_POPUP_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/enums.hxx>
#include <libmm/gdk/popuplayout.hxx>
#include <libmm/gdk/surface.hxx>
#include <libmm/glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GdkPopupInterface GdkPopupInterface;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkPopup = struct _GdkPopup;
using GdkPopupClass = struct _GdkPopupClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gdk
{
  class LIBMM_GDK_SYMEXPORT Popup_Class;
}
#endif

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT Popup : public glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Popup;
    using CppClassType = Popup_Class;
    using BaseObjectType = GdkPopup;
    using BaseClassType = GdkPopupInterface;

    Popup (const Popup&) = delete;
    auto
    operator= (const Popup&) -> Popup& = delete;

  private:
    friend class Popup_Class;
    static CppClassType popup_class_;

#endif
  protected:
    Popup ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit Popup (const glib::Interface_Class& interface_class);

  public:
    explicit Popup (GdkPopup* castitem);

  protected:
#endif

  public:
    Popup (Popup&& src) noexcept;
    auto
    operator= (Popup&& src) noexcept -> Popup&;

    ~Popup () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkPopup*
    {
      return reinterpret_cast<GdkPopup*> (gobject_);
    }

    auto
    gobj () const -> const GdkPopup*
    {
      return reinterpret_cast<GdkPopup*> (gobject_);
    }

  private:
  public:
    auto
    present (int width, int height, const glib::RefPtr<PopupLayout>& layout)
        -> bool;

    auto
    get_surface_anchor () const -> Gravity;

    auto
    get_rect_anchor () const -> Gravity;

    auto
    get_parent () -> glib::RefPtr<Surface>;

    auto
    get_parent () const -> glib::RefPtr<const Surface>;

    auto
    get_position_x () const -> int;

    auto
    get_position_y () const -> int;

    auto
    get_autohide () const -> bool;

    auto
    property_parent () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Surface>>;

    auto
    property_autohide () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gdk

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkPopup* object, bool take_copy = false) -> glib::RefPtr<gdk::Popup>;

} // namespace glib

#endif
