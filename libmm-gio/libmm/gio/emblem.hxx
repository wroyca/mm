// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_EMBLEM_H
#define _GIOMM_EMBLEM_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/icon.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GEmblem = struct _GEmblem;
using GEmblemClass = struct _GEmblemClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT Emblem_Class;
}
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT Emblem : public Glib::Object,
                           public Icon
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Emblem;
    using CppClassType = Emblem_Class;
    using BaseObjectType = GEmblem;
    using BaseClassType = GEmblemClass;

    Emblem (const Emblem&) = delete;
    auto
    operator= (const Emblem&) -> Emblem& = delete;

  private:
    friend class Emblem_Class;
    static CppClassType emblem_class_;

  protected:
    explicit Emblem (const Glib::ConstructParams& construct_params);
    explicit Emblem (GEmblem* castitem);

#endif

  public:
    Emblem (Emblem&& src) noexcept;
    auto
    operator= (Emblem&& src) noexcept -> Emblem&;

    ~Emblem () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GEmblem*
    {
      return reinterpret_cast<GEmblem*> (gobject_);
    }

    auto
    gobj () const -> const GEmblem*
    {
      return reinterpret_cast<GEmblem*> (gobject_);
    }

    auto
    gobj_copy () -> GEmblem*;

  private:
  public:
    enum class Origin
    {
      UNKNOWN,
      DEVICE,
      LIVEMETADATA,
      TAG
    };

  protected:
    explicit Emblem (const Glib::RefPtr<Icon>& icon);

    explicit Emblem (const Glib::RefPtr<Icon>& icon, Origin origin);

  public:
    static auto
    create (const Glib::RefPtr<Icon>& icon) -> Glib::RefPtr<Emblem>;

    static auto
    create (const Glib::RefPtr<Icon>& icon, Origin origin)
        -> Glib::RefPtr<Emblem>;

    auto
    get_icon () -> Glib::RefPtr<Icon>;

    auto
    get_icon () const -> Glib::RefPtr<const Icon>;

    auto
    get_origin () const -> Origin;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GEmblem* object, bool take_copy = false) -> Glib::RefPtr<Gio::Emblem>;
} // namespace Glib

#endif
