// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_LEAFLET_H
#define _LIBADWAITAMM_LEAFLET_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/mm-gtk.hxx>

#include <adwaita.h>
#include <libmm/adw/foldthresholdpolicy.hxx>
#include <libmm/adw/leafletpage.hxx>
#include <libmm/adw/navigationdirection.hxx>
#include <libmm/adw/springparams.hxx>
#include <libmm/adw/swipeable.hxx>
#include <libmm/gtk/selectionmodel.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT Leaflet_Class;
}
#endif

namespace adw
{

  enum class LIBMM_ADW_SYMEXPORT LeafletTransitionType
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
  class LIBMM_ADW_SYMEXPORT Value<adw::LeafletTransitionType>
    : public glib::Value_Enum<adw::LeafletTransitionType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT Leaflet : public gtk::Widget,
                  public gtk::Orientable,
                  public adw::Swipeable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Leaflet CppObjectType;
    typedef Leaflet_Class CppClassType;
    typedef AdwLeaflet BaseObjectType;
    typedef AdwLeafletClass BaseClassType;
#endif

    Leaflet (Leaflet&& src) noexcept;
    auto
    operator= (Leaflet&& src) noexcept -> Leaflet&;

    Leaflet (const Leaflet&) = delete;
    auto
    operator= (const Leaflet&) -> Leaflet& = delete;

    ~Leaflet () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class Leaflet_Class;
    static CppClassType leaflet_class_;

  protected:
    explicit Leaflet (const glib::ConstructParams& construct_params);
    explicit Leaflet (AdwLeaflet* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwLeaflet*
    {
      return reinterpret_cast<AdwLeaflet*> (gobject_);
    }

    auto
    gobj () const -> const AdwLeaflet*
    {
      return reinterpret_cast<AdwLeaflet*> (gobject_);
    }

  private:
  public:
    Leaflet ();

    auto
    append (gtk::Widget* child) -> glib::RefPtr<LeafletPage>;

    auto
    get_adjacent_child (NavigationDirection direction) const -> gtk::Widget*;

    auto
    get_can_navigate_back () const -> bool;

    auto
    get_can_navigate_forward () const -> bool;

    auto
    get_can_unfold () const -> bool;

    auto
    get_child_by_name (const glib::ustring& name) const -> gtk::Widget*;

    auto
    get_child_transition_params () const -> glib::RefPtr<SpringParams>;

    auto
    get_child_transition_running () const -> bool;

    auto
    get_fold_threshold_policy () const -> FoldThresholdPolicy;

    auto
    get_folded () const -> bool;

    auto
    get_homogeneous () const -> bool;

    auto
    get_mode_transition_duration () const -> guint;

    auto
    get_page (gtk::Widget* child) const -> glib::RefPtr<LeafletPage>;

    auto
    get_pages () const -> glib::RefPtr<gtk::SelectionModel>;

    auto
    get_transition_type () const -> LeafletTransitionType;

    auto
    get_visible_child () const -> gtk::Widget*;

    auto
    get_visible_child_name () const -> glib::ustring;

    auto
    insert_child_after (gtk::Widget* child, gtk::Widget* sibling)
        -> glib::RefPtr<LeafletPage>;

    auto
    navigate (NavigationDirection direction) -> bool;

    auto
    prepend (gtk::Widget* child) -> glib::RefPtr<LeafletPage>;

    auto
    remove (gtk::Widget* child) -> void;

    auto
    reorder_child_after (gtk::Widget* child, gtk::Widget* sibling) -> void;

    auto
    set_can_navigate_back (bool can_navigate_back) -> void;

    auto
    set_can_navigate_forward (bool can_navigate_forward) -> void;

    auto
    set_can_unfold (bool can_unfold) -> void;

    auto
    set_child_transition_params (const glib::RefPtr<SpringParams>& params)
        -> void;

    auto
    set_fold_threshold_policy (FoldThresholdPolicy policy) -> void;

    auto
    set_homogeneous (bool homogeneous) -> void;

    auto
    set_mode_transition_duration (guint duration) -> void;

    auto
    set_transition_type (LeafletTransitionType transition) -> void;

    auto
    set_visible_child (gtk::Widget* child) -> void;

    auto
    set_visible_child_name (const glib::ustring& name) -> void;

    auto
    property_can_navigate_back () -> glib::PropertyProxy<bool>;

    auto
    property_can_navigate_back () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_can_navigate_forward () -> glib::PropertyProxy<bool>;

    auto
    property_can_navigate_forward () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_can_unfold () -> glib::PropertyProxy<bool>;

    auto
    property_can_unfold () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_child_transition_params ()
        -> glib::PropertyProxy<glib::RefPtr<SpringParams>>;

    auto
    property_child_transition_params () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<SpringParams>>;

    auto
    property_child_transition_running () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_fold_threshold_policy ()
        -> glib::PropertyProxy<FoldThresholdPolicy>;

    auto
    property_fold_threshold_policy () const
        -> glib::PropertyProxy_ReadOnly<FoldThresholdPolicy>;

    auto
    property_folded () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_homogeneous () -> glib::PropertyProxy<bool>;

    auto
    property_homogeneous () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_mode_transition_duration () -> glib::PropertyProxy<guint>;

    auto
    property_mode_transition_duration () const
        -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_pages () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gtk::SelectionModel>>;

    auto
    property_transition_type () -> glib::PropertyProxy<LeafletTransitionType>;

    auto
    property_transition_type () const
        -> glib::PropertyProxy_ReadOnly<LeafletTransitionType>;

    auto
    property_visible_child () -> glib::PropertyProxy<gtk::Widget*>;

    auto
    property_visible_child () const
        -> glib::PropertyProxy_ReadOnly<gtk::Widget*>;

    auto
    property_visible_child_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_visible_child_name () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwLeaflet* object, bool take_copy = false) -> adw::Leaflet*;
}

#endif
