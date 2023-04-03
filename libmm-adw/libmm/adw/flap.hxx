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
namespace Adw
{
  class LIBMM_ADW_SYMEXPORT Flap_Class;
}
#endif

namespace Adw
{

  enum class LIBMM_ADW_SYMEXPORT FlapFoldPolicy
  {
    NEVER,
    ALWAYS,
    AUTO
  };

} // namespace Adw

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_ADW_SYMEXPORT Value<Adw::FlapFoldPolicy>
    : public Glib::Value_Enum<Adw::FlapFoldPolicy>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Adw
{

  enum class LIBMM_ADW_SYMEXPORT FlapTransitionType
  {
    OVER,
    UNDER,
    SLIDE
  };

} // namespace Adw

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_ADW_SYMEXPORT Value<Adw::FlapTransitionType>
    : public Glib::Value_Enum<Adw::FlapTransitionType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT Flap : public Gtk::Widget,
               Gtk::Orientable,
               Adw::Swipeable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Flap CppObjectType;
    typedef Flap_Class CppClassType;
    typedef AdwFlap BaseObjectType;
    typedef AdwFlapClass BaseClassType;
#endif

    Flap (Flap&& src) noexcept;
    auto
    operator= (Flap&& src) noexcept -> Flap&;

    Flap (const Flap&) = delete;
    auto
    operator= (const Flap&) -> Flap& = delete;

    ~Flap () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class Flap_Class;
    static CppClassType flap_class_;

  protected:
    explicit Flap (const Glib::ConstructParams& construct_params);
    explicit Flap (AdwFlap* castitem);

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
    Flap ();

    auto
    get_content () const -> Gtk::Widget*;

    auto
    get_flap () const -> Gtk::Widget*;

    auto
    get_flap_position () const -> Gtk::PackType;

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
    get_reveal_params () const -> Glib::RefPtr<SpringParams>;

    auto
    get_reveal_progress () const -> double;

    auto
    get_separator () const -> Gtk::Widget*;

    auto
    get_swipe_to_close () const -> bool;

    auto
    get_swipe_to_open () const -> bool;

    auto
    get_transition_type () const -> FlapTransitionType;

    auto
    set_content (Gtk::Widget* widget) -> void;

    auto
    set_flap (Gtk::Widget* widget) -> void;

    auto
    set_flap_position (Gtk::PackType position) -> void;

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
    set_reveal_params (const Glib::RefPtr<SpringParams>& params) -> void;

    auto
    set_separator (Gtk::Widget* separator) -> void;

    auto
    set_swipe_to_close (bool locked) -> void;

    auto
    set_swipe_to_open (bool locked) -> void;

    auto
    set_transition_type (FlapTransitionType transition_type) -> void;

    auto
    property_content () -> Glib::PropertyProxy<Gtk::Widget*>;

    auto
    property_content () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>;

    auto
    property_flap () -> Glib::PropertyProxy<Gtk::Widget*>;

    auto
    property_flap () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>;

    auto
    property_flap_position () -> Glib::PropertyProxy<Gtk::PackType>;

    auto
    property_flap_position () const
        -> Glib::PropertyProxy_ReadOnly<Gtk::PackType>;

    auto
    property_fold_duration () -> Glib::PropertyProxy<guint>;

    auto
    property_fold_duration () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_fold_policy () -> Glib::PropertyProxy<FlapFoldPolicy>;

    auto
    property_fold_policy () const
        -> Glib::PropertyProxy_ReadOnly<FlapFoldPolicy>;

    auto
    property_fold_threshold_policy ()
        -> Glib::PropertyProxy<FoldThresholdPolicy>;

    auto
    property_fold_threshold_policy () const
        -> Glib::PropertyProxy_ReadOnly<FoldThresholdPolicy>;

    auto
    property_folded () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_locked () -> Glib::PropertyProxy<bool>;

    auto
    property_locked () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_modal () -> Glib::PropertyProxy<bool>;

    auto
    property_modal () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_reveal_flap () -> Glib::PropertyProxy<bool>;

    auto
    property_reveal_flap () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_reveal_params ()
        -> Glib::PropertyProxy<Glib::RefPtr<SpringParams>>;

    auto
    property_reveal_params () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<SpringParams>>;

    auto
    property_reveal_progress () const -> Glib::PropertyProxy_ReadOnly<double>;

    auto
    property_separator () -> Glib::PropertyProxy<Gtk::Widget*>;

    auto
    property_separator () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>;

    auto
    property_swipe_to_close () -> Glib::PropertyProxy<bool>;

    auto
    property_swipe_to_close () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_swipe_to_open () -> Glib::PropertyProxy<bool>;

    auto
    property_swipe_to_open () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_transition_type () -> Glib::PropertyProxy<FlapTransitionType>;

    auto
    property_transition_type () const
        -> Glib::PropertyProxy_ReadOnly<FlapTransitionType>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwFlap* object, bool take_copy = false) -> Adw::Flap*;
}

#endif
