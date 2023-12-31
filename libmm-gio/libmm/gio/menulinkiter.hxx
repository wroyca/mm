// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_MENULINKITER_H
#define _GIOMM_MENULINKITER_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GMenuLinkIter = struct _GMenuLinkIter;
using GMenuLinkIterClass = struct _GMenuLinkIterClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT MenuLinkIter_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT MenuModel;

  class LIBMM_GIO_SYMEXPORT MenuLinkIter : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = MenuLinkIter;
    using CppClassType = MenuLinkIter_Class;
    using BaseObjectType = GMenuLinkIter;
    using BaseClassType = GMenuLinkIterClass;

    MenuLinkIter (const MenuLinkIter&) = delete;
    auto
    operator= (const MenuLinkIter&) -> MenuLinkIter& = delete;

  private:
    friend class MenuLinkIter_Class;
    static CppClassType menulinkiter_class_;

  protected:
    explicit MenuLinkIter (const glib::ConstructParams& construct_params);
    explicit MenuLinkIter (GMenuLinkIter* castitem);

#endif

  public:
    MenuLinkIter (MenuLinkIter&& src) noexcept;
    auto
    operator= (MenuLinkIter&& src) noexcept -> MenuLinkIter&;

    ~MenuLinkIter () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GMenuLinkIter*
    {
      return reinterpret_cast<GMenuLinkIter*> (gobject_);
    }

    auto
    gobj () const -> const GMenuLinkIter*
    {
      return reinterpret_cast<GMenuLinkIter*> (gobject_);
    }

    auto
    gobj_copy () -> GMenuLinkIter*;

  private:
  protected:
    MenuLinkIter ();

  public:
    auto
    get_name () const -> glib::ustring;

    auto
    get_next (glib::ustring& out_link, glib::RefPtr<MenuModel>& value) -> bool;

    auto
    get_value () -> glib::RefPtr<MenuModel>;

    auto
    get_value () const -> glib::RefPtr<const MenuModel>;

    auto
    next () -> bool;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GMenuLinkIter* object, bool take_copy = false) -> glib::RefPtr<gio::MenuLinkIter>;
} // namespace glib

#endif
