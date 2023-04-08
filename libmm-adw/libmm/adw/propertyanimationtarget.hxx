// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_PROPERTYANIMATIONTARGET_H
#define _LIBADWAITAMM_PROPERTYANIMATIONTARGET_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/adw/animationtarget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using AdwPropertyAnimationTarget = struct _AdwPropertyAnimationTarget;
using AdwPropertyAnimationTargetClass = struct _AdwPropertyAnimationTargetClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT property_animation_target_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT property_animation_target : public AnimationTarget
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = property_animation_target;
    using CppClassType = property_animation_target_class;
    using BaseObjectType = AdwPropertyAnimationTarget;
    using BaseClassType = AdwPropertyAnimationTargetClass;

    property_animation_target (const property_animation_target&) = delete;
    auto
    operator= (const property_animation_target&)
        -> property_animation_target& = delete;

  private:
    friend class property_animation_target_class;
    static CppClassType propertyanimationtarget_class_;

  protected:
    explicit property_animation_target (
        const glib::ConstructParams& construct_params);
    explicit property_animation_target (AdwPropertyAnimationTarget* castitem);

#endif

  public:
    property_animation_target (property_animation_target&& src) noexcept;
    auto
    operator= (property_animation_target&& src) noexcept
        -> property_animation_target&;

    ~property_animation_target () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwPropertyAnimationTarget*
    {
      return reinterpret_cast<AdwPropertyAnimationTarget*> (gobject_);
    }

    auto
    gobj () const -> const AdwPropertyAnimationTarget*
    {
      return reinterpret_cast<AdwPropertyAnimationTarget*> (gobject_);
    }

    auto
    gobj_copy () -> AdwPropertyAnimationTarget*;

  private:
    property_animation_target (const glib::RefPtr<glib::Object>& object,
                             const glib::ustring& property_name);
    explicit property_animation_target (const glib::RefPtr<glib::Object>& object,
                                      GParamSpec* pspec);

  public:
    property_animation_target ();

    static auto
    create (const glib::RefPtr<glib::Object>& object,
            const glib::ustring& property_name)
        -> glib::RefPtr<property_animation_target>;

    static auto
    create (const glib::RefPtr<glib::Object>& object, GParamSpec* pspec)
        -> glib::RefPtr<property_animation_target>;

    auto
    get_object () const -> glib::RefPtr<glib::Object>;

    auto
    get_pspec () const -> GParamSpec*;

    auto
    property_object () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::Object>>;

    auto
    property_pspec () const -> glib::PropertyProxy_ReadOnly<GParamSpec*>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwPropertyAnimationTarget* object, bool take_copy = false) -> glib::RefPtr<adw::property_animation_target>;
}

#endif
