// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_MENUATTRIBUTEITER_H
#define _GIOMM_MENUATTRIBUTEITER_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GMenuAttributeIter = struct _GMenuAttributeIter;
using GMenuAttributeIterClass = struct _GMenuAttributeIterClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT MenuAttributeIter_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT MenuAttributeIter : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = MenuAttributeIter;
    using CppClassType = MenuAttributeIter_Class;
    using BaseObjectType = GMenuAttributeIter;
    using BaseClassType = GMenuAttributeIterClass;

    MenuAttributeIter (const MenuAttributeIter&) = delete;
    auto
    operator= (const MenuAttributeIter&) -> MenuAttributeIter& = delete;

  private:
    friend class MenuAttributeIter_Class;
    static CppClassType menuattributeiter_class_;

  protected:
    explicit MenuAttributeIter (const glib::ConstructParams& construct_params);
    explicit MenuAttributeIter (GMenuAttributeIter* castitem);

#endif

  public:
    MenuAttributeIter (MenuAttributeIter&& src) noexcept;
    auto
    operator= (MenuAttributeIter&& src) noexcept -> MenuAttributeIter&;

    ~MenuAttributeIter () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GMenuAttributeIter*
    {
      return reinterpret_cast<GMenuAttributeIter*> (gobject_);
    }

    auto
    gobj () const -> const GMenuAttributeIter*
    {
      return reinterpret_cast<GMenuAttributeIter*> (gobject_);
    }

    auto
    gobj_copy () -> GMenuAttributeIter*;

  private:
  protected:
    MenuAttributeIter ();

  public:
    auto
    get_next (glib::ustring& out_name, glib::VariantBase& value) -> bool;

    auto
    get_name () const -> glib::ustring;

    auto
    get_value () const -> glib::VariantBase;

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
  wrap (GMenuAttributeIter* object, bool take_copy = false) -> glib::RefPtr<gio::MenuAttributeIter>;
} // namespace glib

#endif
