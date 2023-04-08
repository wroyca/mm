// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_FLAP_H
#define _LIBADWAITAMM_FLAP_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/mm-gtk.hxx>

#include <adwaita.h>
#include <libmm/adw/foldthresholdpolicy.hxx>
#include <libmm/adw/springparams.hxx>
#include <libmm/adw/swipeable.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT flap_class;
}
#endif

namespace adw
{

  enum class LIBMM_ADW_SYMEXPORT FlapFoldPolicy
  {
    NEVER,
    ALWAYS,
    AUTO
  };

} // namespace adw

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_ADW_SYMEXPORT Value<adw::FlapFoldPolicy>
    : public glib::Value_Enum<adw::FlapFoldPolicy>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace adw
{

  enum class LIBMM_ADW_SYMEXPORT FlapTransitionType
  {
    OVER,
    UNDER,
    SLIDE
  };

} // namespace adw

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_ADW_SYMEXPORT Value<adw::FlapTransitionType>
    : public glib::Value_Enum<adw::FlapTransitionType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT flap : public gtk::Widget,
               gtk::Orientable,
               adw::swipeable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = flap;
    using CppClassType = flap_class;
    using BaseObjectType = AdwFlap;
    using BaseClassType = AdwFlapClass;
#endif

    flap (flap&& src) noexcept;
    auto
    operator= (flap&& src) noexcept -> flap&;

    flap (const flap&) = delete;
    auto
    operator= (const flap&) -> flap& = delete;

    ~flap () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class flap_class;
    static CppClassType flap_class_;

  protected:
    explicit flap (const glib::ConstructParams& construct_params);
    explicit flap (AdwFlap* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwFlap*
    {
      return reinterpret_cast<AdwFlap*> (gobject_);
    }

    auto
    gobj () const -> const AdwFlap*
    {
      return reinterpret_cast<AdwFlap*> (gobject_);
    }

  private:
  public:
    flap ();

    auto
    get_content () const -> gtk::Widget*;

    auto
    get_flap () const -> gtk::Widget*;

    auto
    get_flap_position () const -> gtk::PackType;

    auto
    get_fold_duration () const -> guint;

    auto
    get_fold_policy () const -> FlapFoldPolicy;

    auto
    get_fold_threshold_policy () const -> FoldThresholdPolicy;

    auto
    get_folded () const -> bool;

    auto
    get_locked () const -> bool;

    auto
    get_modal () const -> bool;

    auto
    get_reveal_flap () const -> bool;

    auto
    get_reveal_params () const -> glib::RefPtr<spring_params>;

    auto
    get_reveal_progress () const -> double;

    auto
    get_separator () const -> gtk::Widget*;

    auto
    get_swipe_to_close () const -> bool;

    auto
    get_swipe_to_open () const -> bool;

    auto
    get_transition_type () const -> FlapTransitionType;

    auto
    set_content (gtk::Widget* widget) -> void;

    auto
    set_flap (gtk::Widget* widget) -> void;

    auto
    set_flap_position (gtk::PackType position) -> void;

    auto
    set_fold_duration (guint duration) -> void;

    auto
    set_fold_policy (FlapFoldPolicy policy) -> void;

    auto
    set_fold_threshold_policy (FoldThresholdPolicy p1) -> void;

    auto
    set_locked (bool locked) -> void;

    auto
    set_modal (bool modal) -> void;

    auto
    set_reveal_flap (bool reveal_flap) -> void;

    auto
    set_reveal_params (const glib::RefPtr<spring_params>& params) -> void;

    auto
    set_separator (gtk::Widget* separator) -> void;

    auto
    set_swipe_to_close (bool locked) -> void;

    auto
    set_swipe_to_open (bool locked) -> void;

    auto
    set_transition_type (FlapTransitionType transition_type) -> void;

    auto
    property_content () -> glib::PropertyProxy<gtk::Widget*>;

    auto
    property_content () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>;

    auto
    property_flap () -> glib::PropertyProxy<gtk::Widget*>;

    auto
    property_flap () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>;

    auto
    property_flap_position () -> glib::PropertyProxy<gtk::PackType>;

    auto
    property_flap_position () const
        -> glib::PropertyProxy_ReadOnly<gtk::PackType>;

    auto
    property_fold_duration () -> glib::PropertyProxy<guint>;

    auto
    property_fold_duration () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_fold_policy () -> glib::PropertyProxy<FlapFoldPolicy>;

    auto
    property_fold_policy () const
        -> glib::PropertyProxy_ReadOnly<FlapFoldPolicy>;

    auto
    property_fold_threshold_policy ()
        -> glib::PropertyProxy<FoldThresholdPolicy>;

    auto
    property_fold_threshold_policy () const
        -> glib::PropertyProxy_ReadOnly<FoldThresholdPolicy>;

    auto
    property_folded () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_locked () -> glib::PropertyProxy<bool>;

    auto
    property_locked () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_modal () -> glib::PropertyProxy<bool>;

    auto
    property_modal () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_reveal_flap () -> glib::PropertyProxy<bool>;

    auto
    property_reveal_flap () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_reveal_params ()
        -> glib::PropertyProxy<glib::RefPtr<spring_params>>;

    auto
    property_reveal_params () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<spring_params>>;

    auto
    property_reveal_progress () const -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_separator () -> glib::PropertyProxy<gtk::Widget*>;

    auto
    property_separator () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>;

    auto
    property_swipe_to_close () -> glib::PropertyProxy<bool>;

    auto
    property_swipe_to_close () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_swipe_to_open () -> glib::PropertyProxy<bool>;

    auto
    property_swipe_to_open () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_transition_type () -> glib::PropertyProxy<FlapTransitionType>;

    auto
    property_transition_type () const
        -> glib::PropertyProxy_ReadOnly<FlapTransitionType>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwFlap* object, bool take_copy = false) -> adw::flap*;
}

#endif
