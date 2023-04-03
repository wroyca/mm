// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SIMPLEPERMISSION_H
#define _GIOMM_SIMPLEPERMISSION_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/permission.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSimplePermission = struct _GSimplePermission;
using GSimplePermissionClass = struct _GSimplePermissionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT SimplePermission_Class;
}
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT SimplePermission : public Permission
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = SimplePermission;
    using CppClassType = SimplePermission_Class;
    using BaseObjectType = GSimplePermission;
    using BaseClassType = GSimplePermissionClass;

    SimplePermission (const SimplePermission&) = delete;
    auto
    operator= (const SimplePermission&) -> SimplePermission& = delete;

  private:
    friend class SimplePermission_Class;
    static CppClassType simplepermission_class_;

  protected:
    explicit SimplePermission (const Glib::ConstructParams& construct_params);
    explicit SimplePermission (GSimplePermission* castitem);

#endif

  public:
    SimplePermission (SimplePermission&& src) noexcept;
    auto
    operator= (SimplePermission&& src) noexcept -> SimplePermission&;

    ~SimplePermission () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GSimplePermission*
    {
      return reinterpret_cast<GSimplePermission*> (gobject_);
    }

    auto
    gobj () const -> const GSimplePermission*
    {
      return reinterpret_cast<GSimplePermission*> (gobject_);
    }

    auto
    gobj_copy () -> GSimplePermission*;

  private:
  protected:
    explicit SimplePermission (bool allowed);

  public:
    static auto
    create (bool allowed) -> Glib::RefPtr<SimplePermission>;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GSimplePermission* object, bool take_copy = false) -> Glib::RefPtr<Gio::SimplePermission>;
} // namespace Glib

#endif
