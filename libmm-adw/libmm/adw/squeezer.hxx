// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_SQUEEZER_H
#define _LIBADWAITAMM_SQUEEZER_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/mm-gtk.hxx>

#include <adwaita.h>
#include <libmm/adw/foldthresholdpolicy.hxx>
#include <libmm/adw/squeezerpage.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT Squeezer_Class;
}
#endif

namespace adw
{

  enum class LIBMM_ADW_SYMEXPORT SqueezerTransitionType
  {
    NONE,
    CROSSFADE
  };

} // namespace adw

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_ADW_SYMEXPORT Value<adw::SqueezerTransitionType>
    : public glib::Value_Enum<adw::SqueezerTransitionType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT Squeezer : public gtk::Widget,
                   public gtk::Orientable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Squeezer CppObjectType;
    typedef Squeezer_Class CppClassType;
    typedef AdwSqueezer BaseObjectType;
    typedef AdwSqueezerClass BaseClassType;
#endif

    Squeezer (Squeezer&& src) noexcept;
    auto
    operator= (Squeezer&& src) noexcept -> Squeezer&;

    Squeezer (const Squeezer&) = delete;
    auto
    operator= (const Squeezer&) -> Squeezer& = delete;

    ~Squeezer () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class Squeezer_Class;
    static CppClassType squeezer_class_;

  protected:
    explicit Squeezer (const glib::ConstructParams& construct_params);
    explicit Squeezer (AdwSqueezer* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwSqueezer*
    {
      return reinterpret_cast<AdwSqueezer*> (gobject_);
    }

    auto
    gobj () const -> const AdwSqueezer*
    {
      return reinterpret_cast<AdwSqueezer*> (gobject_);
    }

  private:
  public:
    Squeezer ();

    auto
    add (gtk::Widget* p1) -> glib::RefPtr<SqueezerPage>;

    auto
    get_allow_none () const -> bool;

    auto
    get_homogeneous () const -> bool;

    auto
    get_interpolate_size () const -> bool;

    auto
    get (gtk::Widget* p1) const -> glib::RefPtr<SqueezerPage>;

    auto
    get_pages () const -> glib::RefPtr<gtk::SelectionModel>;

    auto
    get_switch_threshold_policy () const -> FoldThresholdPolicy;

    auto
    get_transition_duration () const -> guint;

    auto
    get_transition_running () const -> bool;

    auto
    get_transition_type () const -> SqueezerTransitionType;

    auto
    get_visible_child () const -> gtk::Widget*;

    auto
    get_xalign () const -> float;

    auto
    get_yalign () const -> float;

    auto
    remove (gtk::Widget* p1) -> void;

    auto
    set_allow_none (bool allow_none) -> void;

    auto
    set_homogeneous (bool homogeneous) -> void;

    auto
    set_interpolate_size (bool homogeneous) -> void;

    auto
    set_switch_threshold_policy (FoldThresholdPolicy policy) -> void;

    auto
    set_transition_duration (guint duration) -> void;

    auto
    set_transition_type (SqueezerTransitionType transition) -> void;

    auto
    set_xalign (float xalign) -> void;

    auto
    set_yalign (float xalign) -> void;

    auto
    property_allow_none () -> glib::PropertyProxy<bool>;

    auto
    property_allow_none () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_homogeneous () -> glib::PropertyProxy<bool>;

    auto
    property_homogeneous () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_interpolate_size () -> glib::PropertyProxy<bool>;

    auto
    property_interpolate_size () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_pages () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gtk::SelectionModel>>;

    auto
    property_switch_threshold_policy ()
        -> glib::PropertyProxy<FoldThresholdPolicy>;

    auto
    property_switch_threshold_policy () const
        -> glib::PropertyProxy_ReadOnly<FoldThresholdPolicy>;

    auto
    property_transition_duration () -> glib::PropertyProxy<guint>;

    auto
    property_transition_duration () const
        -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_transition_running () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_transition_type () -> glib::PropertyProxy<SqueezerTransitionType>;

    auto
    property_transition_type () const
        -> glib::PropertyProxy_ReadOnly<SqueezerTransitionType>;

    auto
    property_visible_child () const
        -> glib::PropertyProxy_ReadOnly<gtk::Widget*>;

    auto
    property_xalign () -> glib::PropertyProxy<float>;

    auto
    property_xalign () const -> glib::PropertyProxy_ReadOnly<float>;

    auto
    property_yalign () -> glib::PropertyProxy<float>;

    auto
    property_yalign () const -> glib::PropertyProxy_ReadOnly<float>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwSqueezer* object, bool take_copy = false) -> adw::Squeezer*;
}

#endif
