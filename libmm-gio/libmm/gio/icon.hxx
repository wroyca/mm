// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_ICON_H
#define _GIOMM_ICON_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/interface.hxx>
#include <libmm/glib/variant.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GIconIface GIconIface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GIcon = struct _GIcon;
using GIconClass = struct _GIconClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT Icon_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT Icon : public glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Icon;
    using CppClassType = Icon_Class;
    using BaseObjectType = GIcon;
    using BaseClassType = GIconIface;

    Icon (const Icon&) = delete;
    auto
    operator= (const Icon&) -> Icon& = delete;

  private:
    friend class Icon_Class;
    static CppClassType icon_class_;

#endif
  protected:
    Icon ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit Icon (const glib::Interface_Class& interface_class);

  public:
    explicit Icon (GIcon* castitem);

  protected:
#endif

  public:
    Icon (Icon&& src) noexcept;
    auto
    operator= (Icon&& src) noexcept -> Icon&;

    ~Icon () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GIcon*
    {
      return reinterpret_cast<GIcon*> (gobject_);
    }

    auto
    gobj () const -> const GIcon*
    {
      return reinterpret_cast<GIcon*> (gobject_);
    }

  private:
  public:
    static auto
    create (const std::string& str) -> glib::RefPtr<Icon>;

    auto
    hash () const -> guint;

    auto
    to_string () const -> std::string;

    auto
    equal (const glib::RefPtr<Icon>& other) const -> bool;

    auto
    serialize () const -> glib::VariantBase;

    static auto
    deserialize (const glib::VariantBase& value) -> glib::RefPtr<Icon>;

  protected:
  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GIcon* object, bool take_copy = false) -> glib::RefPtr<gio::Icon>;

} // namespace glib

#endif
