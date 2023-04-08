// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/leaflet.hxx>
#include <libmm/adw/leaflet_p.hxx>

#include <libmm/adw/selectionlistmodelimpl.hxx>
#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

  auto
  leaflet::get_pages () const -> glib::RefPtr<gtk::SelectionModel>
  {
    GtkSelectionModel* pages =
        adw_leaflet_get_pages (const_cast<AdwLeaflet*> (gobj ()));
    g_assert (G_IS_LIST_MODEL (pages));

    glib::ObjectBase* pCppObject =
        glib::ObjectBase::_get_current_wrapper ((GObject*) pages);
    if (!pCppObject)
      pCppObject = new adw::selection_list_model_impl ((GObject*) pages);
    return glib::make_refptr_for_instance<gtk::SelectionModel> (
        dynamic_cast<gtk::SelectionModel*> (pCppObject));
  }

} // namespace adw

namespace
{
}

auto
glib::Value<adw::leaflet_transition_type>::value_type () -> GType
{
  return adw_leaflet_transition_type_get_type ();
}

namespace glib
{

  auto
  wrap (AdwLeaflet* object, bool take_copy) -> adw::leaflet*
  {
    return dynamic_cast<adw::leaflet*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  leaflet_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_leaflet_get_type ();
    }

    return *this;
  }

  auto
  leaflet_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new leaflet ((AdwLeaflet*) (o)));
  }

  leaflet::leaflet (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  leaflet::leaflet (AdwLeaflet* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  leaflet::leaflet (leaflet&& src) noexcept
    : gtk::Widget (std::move (src)),
      gtk::Orientable (std::move (src)),
      adw::swipeable (std::move (src))
  {
  }

  auto
  leaflet::operator= (leaflet&& src) noexcept -> leaflet&
  {
    gtk::Widget::operator= (std::move (src));
    gtk::Orientable::operator= (std::move (src));
    adw::swipeable::operator= (std::move (src));
    return *this;
  }

  leaflet::~leaflet () noexcept
  {
    destroy_ ();
  }

  leaflet::CppClassType leaflet::leaflet_class_;

  auto
  leaflet::get_type () -> GType
  {
    return leaflet_class_.init ().get_type ();
  }

  auto
  leaflet::get_base_type () -> GType
  {
    return adw_leaflet_get_type ();
  }

  leaflet::leaflet ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (leaflet_class_.init ()))
  {
  }

  auto
  leaflet::append (gtk::Widget* child) -> glib::RefPtr<leaflet_page>
  {
    auto retvalue = glib::wrap (
        adw_leaflet_append (gobj (), (GtkWidget*) glib::unwrap (child)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  leaflet::get_adjacent_child (NavigationDirection direction) const -> gtk::Widget*
  {
    return glib::wrap (adw_leaflet_get_adjacent_child (
        const_cast<AdwLeaflet*> (gobj ()),
        static_cast<AdwNavigationDirection> (direction)));
  }

  auto
  leaflet::get_can_navigate_back () const -> bool
  {
    return adw_leaflet_get_can_navigate_back (
        const_cast<AdwLeaflet*> (gobj ()));
  }

  auto
  leaflet::get_can_navigate_forward () const -> bool
  {
    return adw_leaflet_get_can_navigate_forward (
        const_cast<AdwLeaflet*> (gobj ()));
  }

  auto
  leaflet::get_can_unfold () const -> bool
  {
    return adw_leaflet_get_can_unfold (const_cast<AdwLeaflet*> (gobj ()));
  }

  auto
  leaflet::get_child_by_name (const glib::ustring& name) const -> gtk::Widget*
  {
    return glib::wrap (
        adw_leaflet_get_child_by_name (const_cast<AdwLeaflet*> (gobj ()),
                                       name.c_str ()));
  }

  auto
  leaflet::get_child_transition_params () const -> glib::RefPtr<spring_params>
  {
    return glib::wrap (adw_leaflet_get_child_transition_params (
        const_cast<AdwLeaflet*> (gobj ())));
  }

  auto
  leaflet::get_child_transition_running () const -> bool
  {
    return adw_leaflet_get_child_transition_running (
        const_cast<AdwLeaflet*> (gobj ()));
  }

  auto
  leaflet::get_fold_threshold_policy () const -> FoldThresholdPolicy
  {
    return static_cast<FoldThresholdPolicy> (
        adw_leaflet_get_fold_threshold_policy (
            const_cast<AdwLeaflet*> (gobj ())));
  }

  auto
  leaflet::get_folded () const -> bool
  {
    return adw_leaflet_get_folded (const_cast<AdwLeaflet*> (gobj ()));
  }

  auto
  leaflet::get_homogeneous () const -> bool
  {
    return adw_leaflet_get_homogeneous (const_cast<AdwLeaflet*> (gobj ()));
  }

  auto
  leaflet::get_mode_transition_duration () const -> guint
  {
    return adw_leaflet_get_mode_transition_duration (
        const_cast<AdwLeaflet*> (gobj ()));
  }

  auto
  leaflet::get_page (gtk::Widget* child) const -> glib::RefPtr<leaflet_page>
  {
    auto retvalue =
        glib::wrap (adw_leaflet_get_page (const_cast<AdwLeaflet*> (gobj ()),
                                          (GtkWidget*) glib::unwrap (child)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  leaflet::get_transition_type () const -> leaflet_transition_type
  {
    return static_cast<leaflet_transition_type> (
        adw_leaflet_get_transition_type (const_cast<AdwLeaflet*> (gobj ())));
  }

  auto
  leaflet::get_visible_child () const -> gtk::Widget*
  {
    return glib::wrap (
        adw_leaflet_get_visible_child (const_cast<AdwLeaflet*> (gobj ())));
  }

  auto
  leaflet::get_visible_child_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_leaflet_get_visible_child_name (const_cast<AdwLeaflet*> (gobj ())));
  }

  auto
  leaflet::insert_child_after (gtk::Widget* child, gtk::Widget* sibling) -> glib::RefPtr<leaflet_page>
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
  leaflet::navigate (NavigationDirection direction) -> bool
  {
    return adw_leaflet_navigate (
        gobj (),
        static_cast<AdwNavigationDirection> (direction));
  }

  auto
  leaflet::prepend (gtk::Widget* child) -> glib::RefPtr<leaflet_page>
  {
    auto retvalue = glib::wrap (
        adw_leaflet_prepend (gobj (), (GtkWidget*) glib::unwrap (child)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  leaflet::remove (gtk::Widget* child) -> void
  {
    adw_leaflet_remove (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  leaflet::reorder_child_after (gtk::Widget* child, gtk::Widget* sibling) -> void
  {
    adw_leaflet_reorder_child_after (gobj (),
                                     (GtkWidget*) glib::unwrap (child),
                                     (GtkWidget*) glib::unwrap (sibling));
  }

  auto
  leaflet::set_can_navigate_back (bool can_navigate_back) -> void
  {
    adw_leaflet_set_can_navigate_back (gobj (),
                                       static_cast<int> (can_navigate_back));
  }

  auto
  leaflet::set_can_navigate_forward (bool can_navigate_forward) -> void
  {
    adw_leaflet_set_can_navigate_forward (
        gobj (),
        static_cast<int> (can_navigate_forward));
  }

  auto
  leaflet::set_can_unfold (bool can_unfold) -> void
  {
    adw_leaflet_set_can_unfold (gobj (), static_cast<int> (can_unfold));
  }

  auto
  leaflet::set_child_transition_params (
      const glib::RefPtr<spring_params>& params) -> void
  {
    adw_leaflet_set_child_transition_params (gobj (), glib::unwrap (params));
  }

  auto
  leaflet::set_fold_threshold_policy (FoldThresholdPolicy policy) -> void
  {
    adw_leaflet_set_fold_threshold_policy (
        gobj (),
        static_cast<AdwFoldThresholdPolicy> (policy));
  }

  auto
  leaflet::set_homogeneous (bool homogeneous) -> void
  {
    adw_leaflet_set_homogeneous (gobj (), static_cast<int> (homogeneous));
  }

  auto
  leaflet::set_mode_transition_duration (guint duration) -> void
  {
    adw_leaflet_set_mode_transition_duration (gobj (), duration);
  }

  auto
  leaflet::set_transition_type (leaflet_transition_type transition) -> void
  {
    adw_leaflet_set_transition_type (
        gobj (),
        static_cast<AdwLeafletTransitionType> (transition));
  }

  auto
  leaflet::set_visible_child (gtk::Widget* child) -> void
  {
    adw_leaflet_set_visible_child (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  leaflet::set_visible_child_name (const glib::ustring& name) -> void
  {
    adw_leaflet_set_visible_child_name (gobj (), name.c_str ());
  }

  auto
  leaflet::property_can_navigate_back () -> glib::PropertyProxy<bool>
  {
    return {this, "can-navigate-back"};
  }

  auto
  leaflet::property_can_navigate_back () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "can-navigate-back"};
  }

  auto
  leaflet::property_can_navigate_forward () -> glib::PropertyProxy<bool>
  {
    return {this, "can-navigate-forward"};
  }

  auto
  leaflet::property_can_navigate_forward () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "can-navigate-forward"};
  }

  auto
  leaflet::property_can_unfold () -> glib::PropertyProxy<bool>
  {
    return {this, "can-unfold"};
  }

  auto
  leaflet::property_can_unfold () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "can-unfold"};
  }

  auto
  leaflet::property_child_transition_params () -> glib::PropertyProxy<glib::RefPtr<spring_params>>
  {
    return {this, "child-transition-params"};
  }

  auto
  leaflet::property_child_transition_params () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<spring_params>>
  {
    return {this, "child-transition-params"};
  }

  auto
  leaflet::property_child_transition_running () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "child-transition-running"};
  }

  auto
  leaflet::property_fold_threshold_policy () -> glib::PropertyProxy<FoldThresholdPolicy>
  {
    return {this, "fold-threshold-policy"};
  }

  auto
  leaflet::property_fold_threshold_policy () const -> glib::PropertyProxy_ReadOnly<FoldThresholdPolicy>
  {
    return {this, "fold-threshold-policy"};
  }

  auto
  leaflet::property_folded () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "folded"};
  }

  auto
  leaflet::property_homogeneous () -> glib::PropertyProxy<bool>
  {
    return {this, "homogeneous"};
  }

  auto
  leaflet::property_homogeneous () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "homogeneous"};
  }

  auto
  leaflet::property_mode_transition_duration () -> glib::PropertyProxy<guint>
  {
    return {this, "mode-transition-duration"};
  }

  auto
  leaflet::property_mode_transition_duration () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return {this, "mode-transition-duration"};
  }

  auto
  leaflet::property_pages () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gtk::SelectionModel>>
  {
    return {this, "pages"};
  }

  auto
  leaflet::property_transition_type () -> glib::PropertyProxy<leaflet_transition_type>
  {
    return {this, "transition-type"};
  }

  auto
  leaflet::property_transition_type () const -> glib::PropertyProxy_ReadOnly<leaflet_transition_type>
  {
    return {this, "transition-type"};
  }

  auto
  leaflet::property_visible_child () -> glib::PropertyProxy<gtk::Widget*>
  {
    return {this, "visible-child"};
  }

  auto
  leaflet::property_visible_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "visible-child"};
  }

  auto
  leaflet::property_visible_child_name () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "visible-child-name"};
  }

  auto
  leaflet::property_visible_child_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "visible-child-name"};
  }
} // namespace adw
