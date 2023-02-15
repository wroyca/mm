// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_EMBLEMEDICON_H
#define _GIOMM_EMBLEMEDICON_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/emblem.hxx>
#include <libmm-gio/icon.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GEmblemedIcon = struct _GEmblemedIcon;
using GEmblemedIconClass = struct _GEmblemedIconClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API EmblemedIcon_Class;
}
#endif

namespace Gio
{

  class GIOMM_API EmblemedIcon : public Glib::Object,
                                 public Icon
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = EmblemedIcon;
    using CppClassType = EmblemedIcon_Class;
    using BaseObjectType = GEmblemedIcon;
    using BaseClassType = GEmblemedIconClass;

    EmblemedIcon (const EmblemedIcon&) = delete;
    auto
    operator= (const EmblemedIcon&) -> EmblemedIcon& = delete;

  private:
    friend class EmblemedIcon_Class;
    static CppClassType emblemedicon_class_;

  protected:
    explicit EmblemedIcon (const Glib::ConstructParams& construct_params);
    explicit EmblemedIcon (GEmblemedIcon* castitem);

#endif

  public:
    EmblemedIcon (EmblemedIcon&& src) noexcept;
    auto
    operator= (EmblemedIcon&& src) noexcept -> EmblemedIcon&;

    ~EmblemedIcon () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GEmblemedIcon*
    {
      return reinterpret_cast<GEmblemedIcon*> (gobject_);
    }

    auto
    gobj () const -> const GEmblemedIcon*
    {
      return reinterpret_cast<GEmblemedIcon*> (gobject_);
    }

    auto
    gobj_copy () -> GEmblemedIcon*;

  private:
  protected:
    explicit EmblemedIcon (const Glib::RefPtr<Icon>& icon);

    explicit EmblemedIcon (const Glib::RefPtr<Icon>& icon,
                           const Glib::RefPtr<Emblem>& emblem);

  public:
    static auto
    create (const Glib::RefPtr<Icon>& icon, const Glib::RefPtr<Emblem>& emblem)
        -> Glib::RefPtr<EmblemedIcon>;

    static auto
    create (const Glib::RefPtr<Icon>& icon) -> Glib::RefPtr<EmblemedIcon>;

    auto
    get_icon () -> Glib::RefPtr<Icon>;

    auto
    get_icon () const -> Glib::RefPtr<const Icon>;

    auto
    get_emblems () -> std::vector<Glib::RefPtr<Emblem>>;

    auto
    get_emblems () const -> std::vector<Glib::RefPtr<const Emblem>>;

    auto
    add_emblem (const Glib::RefPtr<Emblem>& emblem) -> void;

    auto
    clear_emblems () -> void;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GEmblemedIcon* object, bool take_copy = false) -> Glib::RefPtr<Gio::EmblemedIcon>;
} // namespace Glib

#endif
