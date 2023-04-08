// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/leaflet.hxx>
#include <libmm/adw/leaflet_p.hxx>

#include <libmm/adw/selectionlistmodelimpl.hxx>
#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

  auto
  Leaflet::get_pages () const -> glib::RefPtr<gtk::SelectionModel>
  {
    GtkSelectionModel* pages =
        adw_leaflet_get_pages (const_cast<AdwLeaflet*> (gobj ()));
    g_assert (G_IS_LIST_MODEL (pages));

    glib::ObjectBase* pCppObject =
        glib::ObjectBase::_get_current_wrapper ((GObject*) pages);
    if (!pCppObject)
      pCppObject = new adw::SelectionListModelImpl ((GObject*) pages);
    return glib::make_refptr_for_instance<gtk::SelectionModel> (
        dynamic_cast<gtk::SelectionModel*> (pCppObject));
  }

} // namespace adw

namespace
{
}

auto
glib::Value<adw::LeafletTransitionType>::value_type () -> GType
{
  return adw_leaflet_transition_type_get_type ();
}

namespace glib
{

  auto
  wrap (AdwLeaflet* object, bool take_copy) -> adw::Leaflet*
  {
    return dynamic_cast<adw::Leaflet*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  Leaflet_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_leaflet_get_type ();
    }

    return *this;
  }

  auto
  Leaflet_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Leaflet ((AdwLeaflet*) (o)));
  }

  Leaflet::Leaflet (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Leaflet::Leaflet (AdwLeaflet* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Leaflet::Leaflet (Leaflet&& src) noexcept
    : gtk::Widget (std::move (src)),
      gtk::Orientable (std::move (src)),
      adw::Swipeable (std::move (src))
  {
  }

  auto
  Leaflet::operator= (Leaflet&& src) noexcept -> Leaflet&
  {
    gtk::Widget::operator= (std::move (src));
    gtk::Orientable::operator= (std::move (src));
    adw::Swipeable::operator= (std::move (src));
    return *this;
  }

  Leaflet::~Leaflet () noexcept
  {
    destroy_ ();
  }

  Leaflet::CppClassType Leaflet::leaflet_class_;

  auto
  Leaflet::get_type () -> GType
  {
    return leaflet_class_.init ().get_type ();
  }

  auto
  Leaflet::get_base_type () -> GType
  {
    return adw_leaflet_get_type ();
  }

  Leaflet::Leaflet ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (leaflet_class_.init ()))
  {
  }

  auto
  Leaflet::append (gtk::Widget* child) -> glib::RefPtr<LeafletPage>
  {
    auto retvalue = glib::wrap (
        adw_leaflet_append (gobj (), (GtkWidget*) glib::unwrap (child)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Leaflet::get_adjacent_child (NavigationDirection direction) const -> gtk::Widget*
  {
    return glib::wrap (adw_leaflet_get_adjacent_child (
        const_cast<AdwLeaflet*> (gobj ()),
        static_cast<AdwNavigationDirection> (direction)));
  }

  auto
  Leaflet::get_can_navigate_back () const -> bool
  {
    return adw_leaflet_get_can_navigate_back (
        const_cast<AdwLeaflet*> (gobj ()));
  }

  auto
  Leaflet::get_can_navigate_forward () const -> bool
  {
    return adw_leaflet_get_can_navigate_forward (
        const_cast<AdwLeaflet*> (gobj ()));
  }

  auto
  Leaflet::get_can_unfold () const -> bool
  {
    return adw_leaflet_get_can_unfold (const_cast<AdwLeaflet*> (gobj ()));
  }

  auto
  Leaflet::get_child_by_name (const glib::ustring& name) const -> gtk::Widget*
  {
    return glib::wrap (
        adw_leaflet_get_child_by_name (const_cast<AdwLeaflet*> (gobj ()),
                                       name.c_str ()));
  }

  auto
  Leaflet::get_child_transition_params () const -> glib::RefPtr<SpringParams>
  {
    return glib::wrap (adw_leaflet_get_child_transition_params (
        const_cast<AdwLeaflet*> (gobj ())));
  }

  auto
  Leaflet::get_child_transition_running () const -> bool
  {
    return adw_leaflet_get_child_transition_running (
        const_cast<AdwLeaflet*> (gobj ()));
  }

  auto
  Leaflet::get_fold_threshold_policy () const -> FoldThresholdPolicy
  {
    return static_cast<FoldThresholdPolicy> (
        adw_leaflet_get_fold_threshold_policy (
            const_cast<AdwLeaflet*> (gobj ())));
  }

  auto
  Leaflet::get_folded () const -> bool
  {
    return adw_leaflet_get_folded (const_cast<AdwLeaflet*> (gobj ()));
  }

  auto
  Leaflet::get_homogeneous () const -> bool
  {
    return adw_leaflet_get_homogeneous (const_cast<AdwLeaflet*> (gobj ()));
  }

  auto
  Leaflet::get_mode_transition_duration () const -> guint
  {
    return adw_leaflet_get_mode_transition_duration (
        const_cast<AdwLeaflet*> (gobj ()));
  }

  auto
  Leaflet::get_page (gtk::Widget* child) const -> glib::RefPtr<LeafletPage>
  {
    auto retvalue =
        glib::wrap (adw_leaflet_get_page (const_cast<AdwLeaflet*> (gobj ()),
                                          (GtkWidget*) glib::unwrap (child)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Leaflet::get_transition_type () const -> LeafletTransitionType
  {
    return static_cast<LeafletTransitionType> (
        adw_leaflet_get_transition_type (const_cast<AdwLeaflet*> (gobj ())));
  }

  auto
  Leaflet::get_visible_child () const -> gtk::Widget*
  {
    return glib::wrap (
        adw_leaflet_get_visible_child (const_cast<AdwLeaflet*> (gobj ())));
  }

  auto
  Leaflet::get_visible_child_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_leaflet_get_visible_child_name (const_cast<AdwLeaflet*> (gobj ())));
  }

  auto
  Leaflet::insert_child_after (gtk::Widget* child, gtk::Widget* sibling) -> glib::RefPtr<LeafletPage>
  {
    auto retvalue = glib::wrap (
        adw_leaflet_insert_child_after (gobj (),
                                        (GtkWidget*) glib::unwrap (child),
                                        (GtkWidget*) glib::unwrap (sibling)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Leaflet::navigate (NavigationDirection direction) -> bool
  {
    return adw_leaflet_navigate (
        gobj (),
        static_cast<AdwNavigationDirection> (direction));
  }

  auto
  Leaflet::prepend (gtk::Widget* child) -> glib::RefPtr<LeafletPage>
  {
    auto retvalue = glib::wrap (
        adw_leaflet_prepend (gobj (), (GtkWidget*) glib::unwrap (child)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Leaflet::remove (gtk::Widget* child) -> void
  {
    adw_leaflet_remove (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  Leaflet::reorder_child_after (gtk::Widget* child, gtk::Widget* sibling) -> void
  {
    adw_leaflet_reorder_child_after (gobj (),
                                     (GtkWidget*) glib::unwrap (child),
                                     (GtkWidget*) glib::unwrap (sibling));
  }

  auto
  Leaflet::set_can_navigate_back (bool can_navigate_back) -> void
  {
    adw_leaflet_set_can_navigate_back (gobj (),
                                       static_cast<int> (can_navigate_back));
  }

  auto
  Leaflet::set_can_navigate_forward (bool can_navigate_forward) -> void
  {
    adw_leaflet_set_can_navigate_forward (
        gobj (),
        static_cast<int> (can_navigate_forward));
  }

  auto
  Leaflet::set_can_unfold (bool can_unfold) -> void
  {
    adw_leaflet_set_can_unfold (gobj (), static_cast<int> (can_unfold));
  }

  auto
  Leaflet::set_child_transition_params (
      const glib::RefPtr<SpringParams>& params) -> void
  {
    adw_leaflet_set_child_transition_params (gobj (), glib::unwrap (params));
  }

  auto
  Leaflet::set_fold_threshold_policy (FoldThresholdPolicy policy) -> void
  {
    adw_leaflet_set_fold_threshold_policy (
        gobj (),
        static_cast<AdwFoldThresholdPolicy> (policy));
  }

  auto
  Leaflet::set_homogeneous (bool homogeneous) -> void
  {
    adw_leaflet_set_homogeneous (gobj (), static_cast<int> (homogeneous));
  }

  auto
  Leaflet::set_mode_transition_duration (guint duration) -> void
  {
    adw_leaflet_set_mode_transition_duration (gobj (), duration);
  }

  auto
  Leaflet::set_transition_type (LeafletTransitionType transition) -> void
  {
    adw_leaflet_set_transition_type (
        gobj (),
        static_cast<AdwLeafletTransitionType> (transition));
  }

  auto
  Leaflet::set_visible_child (gtk::Widget* child) -> void
  {
    adw_leaflet_set_visible_child (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  Leaflet::set_visible_child_name (const glib::ustring& name) -> void
  {
    adw_leaflet_set_visible_child_name (gobj (), name.c_str ());
  }

  auto
  Leaflet::property_can_navigate_back () -> glib::PropertyProxy<bool>
  {
    return {this, "can-navigate-back"};
  }

  auto
  Leaflet::property_can_navigate_back () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "can-navigate-back"};
  }

  auto
  Leaflet::property_can_navigate_forward () -> glib::PropertyProxy<bool>
  {
    return {this, "can-navigate-forward"};
  }

  auto
  Leaflet::property_can_navigate_forward () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "can-navigate-forward"};
  }

  auto
  Leaflet::property_can_unfold () -> glib::PropertyProxy<bool>
  {
    return {this, "can-unfold"};
  }

  auto
  Leaflet::property_can_unfold () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "can-unfold"};
  }

  auto
  Leaflet::property_child_transition_params () -> glib::PropertyProxy<glib::RefPtr<SpringParams>>
  {
    return {this, "child-transition-params"};
  }

  auto
  Leaflet::property_child_transition_params () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<SpringParams>>
  {
    return {this, "child-transition-params"};
  }

  auto
  Leaflet::property_child_transition_running () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "child-transition-running"};
  }

  auto
  Leaflet::property_fold_threshold_policy () -> glib::PropertyProxy<FoldThresholdPolicy>
  {
    return {this, "fold-threshold-policy"};
  }

  auto
  Leaflet::property_fold_threshold_policy () const -> glib::PropertyProxy_ReadOnly<FoldThresholdPolicy>
  {
    return {this, "fold-threshold-policy"};
  }

  auto
  Leaflet::property_folded () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "folded"};
  }

  auto
  Leaflet::property_homogeneous () -> glib::PropertyProxy<bool>
  {
    return {this, "homogeneous"};
  }

  auto
  Leaflet::property_homogeneous () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "homogeneous"};
  }

  auto
  Leaflet::property_mode_transition_duration () -> glib::PropertyProxy<guint>
  {
    return {this, "mode-transition-duration"};
  }

  auto
  Leaflet::property_mode_transition_duration () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return {this, "mode-transition-duration"};
  }

  auto
  Leaflet::property_pages () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gtk::SelectionModel>>
  {
    return {this, "pages"};
  }

  auto
  Leaflet::property_transition_type () -> glib::PropertyProxy<LeafletTransitionType>
  {
    return {this, "transition-type"};
  }

  auto
  Leaflet::property_transition_type () const -> glib::PropertyProxy_ReadOnly<LeafletTransitionType>
  {
    return {this, "transition-type"};
  }

  auto
  Leaflet::property_visible_child () -> glib::PropertyProxy<gtk::Widget*>
  {
    return {this, "visible-child"};
  }

  auto
  Leaflet::property_visible_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "visible-child"};
  }

  auto
  Leaflet::property_visible_child_name () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "visible-child-name"};
  }

  auto
  Leaflet::property_visible_child_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "visible-child-name"};
  }
} // namespace adw
