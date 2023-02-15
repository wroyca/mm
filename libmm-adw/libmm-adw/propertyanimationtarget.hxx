// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_PROPERTYANIMATIONTARGET_H
#define _LIBADWAITAMM_PROPERTYANIMATIONTARGET_H

#include <libmm-adw/mm-adwconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-adw/animationtarget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using AdwPropertyAnimationTarget = struct _AdwPropertyAnimationTarget;
using AdwPropertyAnimationTargetClass = struct _AdwPropertyAnimationTargetClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class PropertyAnimationTarget_Class;
}
#endif

namespace Adw
{

  class PropertyAnimationTarget : public AnimationTarget
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = PropertyAnimationTarget;
    using CppClassType = PropertyAnimationTarget_Class;
    using BaseObjectType = AdwPropertyAnimationTarget;
    using BaseClassType = AdwPropertyAnimationTargetClass;

    PropertyAnimationTarget (const PropertyAnimationTarget&) = delete;
    auto
    operator= (const PropertyAnimationTarget&)
        -> PropertyAnimationTarget& = delete;

  private:
    friend class PropertyAnimationTarget_Class;
    static CppClassType propertyanimationtarget_class_;

  protected:
    explicit PropertyAnimationTarget (
        const Glib::ConstructParams& construct_params);
    explicit PropertyAnimationTarget (AdwPropertyAnimationTarget* castitem);

#endif

  public:
    PropertyAnimationTarget (PropertyAnimationTarget&& src) noexcept;
    auto
    operator= (PropertyAnimationTarget&& src) noexcept
        -> PropertyAnimationTarget&;

    ~PropertyAnimationTarget () noexcept override;

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
    PropertyAnimationTarget (const Glib::RefPtr<Glib::Object>& object,
                             const Glib::ustring& property_name);
    explicit PropertyAnimationTarget (const Glib::RefPtr<Glib::Object>& object,
                                      GParamSpec* pspec);

  public:
    PropertyAnimationTarget ();

    static auto
    create (const Glib::RefPtr<Glib::Object>& object,
            const Glib::ustring& property_name)
        -> Glib::RefPtr<PropertyAnimationTarget>;

    static auto
    create (const Glib::RefPtr<Glib::Object>& object, GParamSpec* pspec)
        -> Glib::RefPtr<PropertyAnimationTarget>;

    auto
    get_object () const -> Glib::RefPtr<Glib::Object>;

    auto
    get_pspec () const -> GParamSpec*;

    auto
    property_object () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Glib::Object>>;

    auto
    property_pspec () const -> Glib::PropertyProxy_ReadOnly<GParamSpec*>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwPropertyAnimationTarget* object, bool take_copy = false) -> Glib::RefPtr<Adw::PropertyAnimationTarget>;
}

#endif
