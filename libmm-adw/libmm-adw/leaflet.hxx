// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_LEAFLET_H
#define _LIBADWAITAMM_LEAFLET_H

#include <libmm-adw/mm-adwconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/mm-gtk.hxx>

#include <adwaita.h>
#include <libmm-adw/foldthresholdpolicy.hxx>
#include <libmm-adw/leafletpage.hxx>
#include <libmm-adw/navigationdirection.hxx>
#include <libmm-adw/springparams.hxx>
#include <libmm-adw/swipeable.hxx>
#include <libmm-gtk/selectionmodel.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class LIBMM_ADW_SYMEXPORT Leaflet_Class;
}
#endif

namespace Adw
{

  enum class LIBMM_ADW_SYMEXPORT LeafletTransitionType
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
  class LIBMM_ADW_SYMEXPORT Value<Adw::LeafletTransitionType>
    : public Glib::Value_Enum<Adw::LeafletTransitionType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT Leaflet : public Gtk::Widget,
                  public Gtk::Orientable,
                  public Adw::Swipeable
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
    explicit Leaflet (const Glib::ConstructParams& construct_params);
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
    append (Gtk::Widget* child) -> Glib::RefPtr<LeafletPage>;

    auto
    get_adjacent_child (NavigationDirection direction) const -> Gtk::Widget*;

    auto
    get_can_navigate_back () const -> bool;

    auto
    get_can_navigate_forward () const -> bool;

    auto
    get_can_unfold () const -> bool;

    auto
    get_child_by_name (const Glib::ustring& name) const -> Gtk::Widget*;

    auto
    get_child_transition_params () const -> Glib::RefPtr<SpringParams>;

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
    get_page (Gtk::Widget* child) const -> Glib::RefPtr<LeafletPage>;

    auto
    get_pages () const -> Glib::RefPtr<Gtk::SelectionModel>;

    auto
    get_transition_type () const -> LeafletTransitionType;

    auto
    get_visible_child () const -> Gtk::Widget*;

    auto
    get_visible_child_name () const -> Glib::ustring;

    auto
    insert_child_after (Gtk::Widget* child, Gtk::Widget* sibling)
        -> Glib::RefPtr<LeafletPage>;

    auto
    navigate (NavigationDirection direction) -> bool;

    auto
    prepend (Gtk::Widget* child) -> Glib::RefPtr<LeafletPage>;

    auto
    remove (Gtk::Widget* child) -> void;

    auto
    reorder_child_after (Gtk::Widget* child, Gtk::Widget* sibling) -> void;

    auto
    set_can_navigate_back (bool can_navigate_back) -> void;

    auto
    set_can_navigate_forward (bool can_navigate_forward) -> void;

    auto
    set_can_unfold (bool can_unfold) -> void;

    auto
    set_child_transition_params (const Glib::RefPtr<SpringParams>& params)
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
    set_visible_child (Gtk::Widget* child) -> void;

    auto
    set_visible_child_name (const Glib::ustring& name) -> void;

    auto
    property_can_navigate_back () -> Glib::PropertyProxy<bool>;

    auto
    property_can_navigate_back () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_can_navigate_forward () -> Glib::PropertyProxy<bool>;

    auto
    property_can_navigate_forward () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_can_unfold () -> Glib::PropertyProxy<bool>;

    auto
    property_can_unfold () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_child_transition_params ()
        -> Glib::PropertyProxy<Glib::RefPtr<SpringParams>>;

    auto
    property_child_transition_params () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<SpringParams>>;

    auto
    property_child_transition_running () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_fold_threshold_policy ()
        -> Glib::PropertyProxy<FoldThresholdPolicy>;

    auto
    property_fold_threshold_policy () const
        -> Glib::PropertyProxy_ReadOnly<FoldThresholdPolicy>;

    auto
    property_folded () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_homogeneous () -> Glib::PropertyProxy<bool>;

    auto
    property_homogeneous () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_mode_transition_duration () -> Glib::PropertyProxy<guint>;

    auto
    property_mode_transition_duration () const
        -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_pages () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gtk::SelectionModel>>;

    auto
    property_transition_type () -> Glib::PropertyProxy<LeafletTransitionType>;

    auto
    property_transition_type () const
        -> Glib::PropertyProxy_ReadOnly<LeafletTransitionType>;

    auto
    property_visible_child () -> Glib::PropertyProxy<Gtk::Widget*>;

    auto
    property_visible_child () const
        -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>;

    auto
    property_visible_child_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_visible_child_name () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwLeaflet* object, bool take_copy = false) -> Adw::Leaflet*;
}

#endif
