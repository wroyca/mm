// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_SQUEEZER_H
#define _LIBADWAITAMM_SQUEEZER_H

#include <libmm-adw/mm-adwconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/mm-gtk.hxx>

#include <adwaita.h>
#include <libmm-adw/foldthresholdpolicy.hxx>
#include <libmm-adw/squeezerpage.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class LIBMM_ADW_SYMEXPORT Squeezer_Class;
}
#endif

namespace Adw
{

  enum class LIBMM_ADW_SYMEXPORT SqueezerTransitionType
  {
    NONE,
    CROSSFADE
  };

} // namespace Adw

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_ADW_SYMEXPORT Value<Adw::SqueezerTransitionType>
    : public Glib::Value_Enum<Adw::SqueezerTransitionType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT Squeezer : public Gtk::Widget,
                   public Gtk::Orientable
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
    explicit Squeezer (const Glib::ConstructParams& construct_params);
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
    add (Gtk::Widget* p1) -> Glib::RefPtr<SqueezerPage>;

    auto
    get_allow_none () const -> bool;

    auto
    get_homogeneous () const -> bool;

    auto
    get_interpolate_size () const -> bool;

    auto
    get (Gtk::Widget* p1) const -> Glib::RefPtr<SqueezerPage>;

    auto
    get_pages () const -> Glib::RefPtr<Gtk::SelectionModel>;

    auto
    get_switch_threshold_policy () const -> FoldThresholdPolicy;

    auto
    get_transition_duration () const -> guint;

    auto
    get_transition_running () const -> bool;

    auto
    get_transition_type () const -> SqueezerTransitionType;

    auto
    get_visible_child () const -> Gtk::Widget*;

    auto
    get_xalign () const -> float;

    auto
    get_yalign () const -> float;

    auto
    remove (Gtk::Widget* p1) -> void;

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
    property_allow_none () -> Glib::PropertyProxy<bool>;

    auto
    property_allow_none () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_homogeneous () -> Glib::PropertyProxy<bool>;

    auto
    property_homogeneous () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_interpolate_size () -> Glib::PropertyProxy<bool>;

    auto
    property_interpolate_size () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_pages () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gtk::SelectionModel>>;

    auto
    property_switch_threshold_policy ()
        -> Glib::PropertyProxy<FoldThresholdPolicy>;

    auto
    property_switch_threshold_policy () const
        -> Glib::PropertyProxy_ReadOnly<FoldThresholdPolicy>;

    auto
    property_transition_duration () -> Glib::PropertyProxy<guint>;

    auto
    property_transition_duration () const
        -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_transition_running () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_transition_type () -> Glib::PropertyProxy<SqueezerTransitionType>;

    auto
    property_transition_type () const
        -> Glib::PropertyProxy_ReadOnly<SqueezerTransitionType>;

    auto
    property_visible_child () const
        -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>;

    auto
    property_xalign () -> Glib::PropertyProxy<float>;

    auto
    property_xalign () const -> Glib::PropertyProxy_ReadOnly<float>;

    auto
    property_yalign () -> Glib::PropertyProxy<float>;

    auto
    property_yalign () const -> Glib::PropertyProxy_ReadOnly<float>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwSqueezer* object, bool take_copy = false) -> Adw::Squeezer*;
}

#endif
