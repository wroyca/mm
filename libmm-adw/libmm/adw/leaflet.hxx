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
  class LIBMM_ADW_SYMEXPORT leaflet_class;
}
#endif

namespace adw
{

  enum class LIBMM_ADW_SYMEXPORT leaflet_transition_type
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
  class LIBMM_ADW_SYMEXPORT Value<adw::leaflet_transition_type>
    : public glib::Value_Enum<adw::leaflet_transition_type>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT leaflet : public gtk::Widget,
                  public gtk::Orientable,
                  public adw::swipeable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = leaflet;
    using CppClassType = leaflet_class;
    using BaseObjectType = AdwLeaflet;
    using BaseClassType = AdwLeafletClass;
#endif

    leaflet (leaflet&& src) noexcept;
    auto
    operator= (leaflet&& src) noexcept -> leaflet&;

    leaflet (const leaflet&) = delete;
    auto
    operator= (const leaflet&) -> leaflet& = delete;

    ~leaflet () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class leaflet_class;
    static CppClassType leaflet_class_;

  protected:
    explicit leaflet (const glib::ConstructParams& construct_params);
    explicit leaflet (AdwLeaflet* castitem);

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
    leaflet ();

    auto
    append (gtk::Widget* child) -> glib::RefPtr<leaflet_page>;

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
    get_child_transition_params () const -> glib::RefPtr<spring_params>;

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
    get_page (gtk::Widget* child) const -> glib::RefPtr<leaflet_page>;

    auto
    get_pages () const -> glib::RefPtr<gtk::SelectionModel>;

    auto
    get_transition_type () const -> leaflet_transition_type;

    auto
    get_visible_child () const -> gtk::Widget*;

    auto
    get_visible_child_name () const -> glib::ustring;

    auto
    insert_child_after (gtk::Widget* child, gtk::Widget* sibling)
        -> glib::RefPtr<leaflet_page>;

    auto
    navigate (NavigationDirection direction) -> bool;

    auto
    prepend (gtk::Widget* child) -> glib::RefPtr<leaflet_page>;

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
    set_child_transition_params (const glib::RefPtr<spring_params>& params)
        -> void;

    auto
    set_fold_threshold_policy (FoldThresholdPolicy policy) -> void;

    auto
    set_homogeneous (bool homogeneous) -> void;

    auto
    set_mode_transition_duration (guint duration) -> void;

    auto
    set_transition_type (leaflet_transition_type transition) -> void;

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
        -> glib::PropertyProxy<glib::RefPtr<spring_params>>;

    auto
    property_child_transition_params () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<spring_params>>;

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
    property_transition_type () -> glib::PropertyProxy<leaflet_transition_type>;

    auto
    property_transition_type () const
        -> glib::PropertyProxy_ReadOnly<leaflet_transition_type>;

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
  wrap (AdwLeaflet* object, bool take_copy = false) -> adw::leaflet*;
}

#endif
