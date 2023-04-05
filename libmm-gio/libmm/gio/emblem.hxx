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
namespace gio
{
  class LIBMM_GIO_SYMEXPORT Emblem_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT Emblem : public glib::Object,
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
    explicit Emblem (const glib::ConstructParams& construct_params);
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
    explicit Emblem (const glib::RefPtr<Icon>& icon);

    explicit Emblem (const glib::RefPtr<Icon>& icon, Origin origin);

  public:
    static auto
    create (const glib::RefPtr<Icon>& icon) -> glib::RefPtr<Emblem>;

    static auto
    create (const glib::RefPtr<Icon>& icon, Origin origin)
        -> glib::RefPtr<Emblem>;

    auto
    get_icon () -> glib::RefPtr<Icon>;

    auto
    get_icon () const -> glib::RefPtr<const Icon>;

    auto
    get_origin () const -> Origin;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GEmblem* object, bool take_copy = false) -> glib::RefPtr<gio::Emblem>;
} // namespace glib

#endif
