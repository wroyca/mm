// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/leaflet.hxx>
#include <libmm/adw/leaflet_p.hxx>

#include <libmm/adw/selectionlistmodelimpl.hxx>
#include <libmm/gtk/mm-gtk.hxx>

namespace Adw
{

  auto
  Leaflet::get_pages () const -> Glib::RefPtr<Gtk::SelectionModel>
  {
    GtkSelectionModel* pages =
        adw_leaflet_get_pages (const_cast<AdwLeaflet*> (gobj ()));
    g_assert (G_IS_LIST_MODEL (pages));

    Glib::ObjectBase* pCppObject =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) pages);
    if (!pCppObject)
      pCppObject = new Adw::SelectionListModelImpl ((GObject*) pages);
    return Glib::make_refptr_for_instance<Gtk::SelectionModel> (
        dynamic_cast<Gtk::SelectionModel*> (pCppObject));
  }

} // namespace Adw

namespace
{
}

auto
Glib::Value<Adw::LeafletTransitionType>::value_type () -> GType
{
  return adw_leaflet_transition_type_get_type ();
}

namespace Glib
{

  auto
  wrap (AdwLeaflet* object, bool take_copy) -> Adw::Leaflet*
  {
    return dynamic_cast<Adw::Leaflet*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  Leaflet_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_leaflet_get_type ();
    }

    return *this;
  }

  auto
  Leaflet_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new Leaflet ((AdwLeaflet*) (o)));
  }

  Leaflet::Leaflet (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  Leaflet::Leaflet (AdwLeaflet* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Leaflet::Leaflet (Leaflet&& src) noexcept
    : Gtk::Widget (std::move (src)),
      Gtk::Orientable (std::move (src)),
      Adw::Swipeable (std::move (src))
  {
  }

  auto
  Leaflet::operator= (Leaflet&& src) noexcept -> Leaflet&
  {
    Gtk::Widget::operator= (std::move (src));
    Gtk::Orientable::operator= (std::move (src));
    Adw::Swipeable::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (leaflet_class_.init ()))
  {
  }

  auto
  Leaflet::append (Gtk::Widget* child) -> Glib::RefPtr<LeafletPage>
  {
    auto retvalue = Glib::wrap (
        adw_leaflet_append (gobj (), (GtkWidget*) Glib::unwrap (child)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Leaflet::get_adjacent_child (NavigationDirection direction) const -> Gtk::Widget*
  {
    return Glib::wrap (adw_leaflet_get_adjacent_child (
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
  Leaflet::get_child_by_name (const Glib::ustring& name) const -> Gtk::Widget*
  {
    return Glib::wrap (
        adw_leaflet_get_child_by_name (const_cast<AdwLeaflet*> (gobj ()),
                                       name.c_str ()));
  }

  auto
  Leaflet::get_child_transition_params () const -> Glib::RefPtr<SpringParams>
  {
    return Glib::wrap (adw_leaflet_get_child_transition_params (
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
  Leaflet::get_page (Gtk::Widget* child) const -> Glib::RefPtr<LeafletPage>
  {
    auto retvalue =
        Glib::wrap (adw_leaflet_get_page (const_cast<AdwLeaflet*> (gobj ()),
                                          (GtkWidget*) Glib::unwrap (child)));
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
  Leaflet::get_visible_child () const -> Gtk::Widget*
  {
    return Glib::wrap (
        adw_leaflet_get_visible_child (const_cast<AdwLeaflet*> (gobj ())));
  }

  auto
  Leaflet::get_visible_child_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_leaflet_get_visible_child_name (const_cast<AdwLeaflet*> (gobj ())));
  }

  auto
  Leaflet::insert_child_after (Gtk::Widget* child, Gtk::Widget* sibling) -> Glib::RefPtr<LeafletPage>
  {
    auto retvalue = Glib::wrap (
        adw_leaflet_insert_child_after (gobj (),
                                        (GtkWidget*) Glib::unwrap (child),
                                        (GtkWidget*) Glib::unwrap (sibling)));
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
  Leaflet::prepend (Gtk::Widget* child) -> Glib::RefPtr<LeafletPage>
  {
    auto retvalue = Glib::wrap (
        adw_leaflet_prepend (gobj (), (GtkWidget*) Glib::unwrap (child)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Leaflet::remove (Gtk::Widget* child) -> void
  {
    adw_leaflet_remove (gobj (), (GtkWidget*) Glib::unwrap (child));
  }

  auto
  Leaflet::reorder_child_after (Gtk::Widget* child, Gtk::Widget* sibling) -> void
  {
    adw_leaflet_reorder_child_after (gobj (),
                                     (GtkWidget*) Glib::unwrap (child),
                                     (GtkWidget*) Glib::unwrap (sibling));
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
      const Glib::RefPtr<SpringParams>& params) -> void
  {
    adw_leaflet_set_child_transition_params (gobj (), Glib::unwrap (params));
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
  Leaflet::set_visible_child (Gtk::Widget* child) -> void
  {
    adw_leaflet_set_visible_child (gobj (), (GtkWidget*) Glib::unwrap (child));
  }

  auto
  Leaflet::set_visible_child_name (const Glib::ustring& name) -> void
  {
    adw_leaflet_set_visible_child_name (gobj (), name.c_str ());
  }

  auto
  Leaflet::property_can_navigate_back () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "can-navigate-back");
  }

  auto
  Leaflet::property_can_navigate_back () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "can-navigate-back");
  }

  auto
  Leaflet::property_can_navigate_forward () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "can-navigate-forward");
  }

  auto
  Leaflet::property_can_navigate_forward () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "can-navigate-forward");
  }

  auto
  Leaflet::property_can_unfold () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "can-unfold");
  }

  auto
  Leaflet::property_can_unfold () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "can-unfold");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<SpringParams>>::value,
      "Type Glib::RefPtr<SpringParams> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Leaflet::property_child_transition_params () -> Glib::PropertyProxy<Glib::RefPtr<SpringParams>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<SpringParams>> (
        this,
        "child-transition-params");
  }

  auto
  Leaflet::property_child_transition_params () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<SpringParams>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<SpringParams>> (
        this,
        "child-transition-params");
  }

  auto
  Leaflet::property_child_transition_running () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this,
                                               "child-transition-running");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<FoldThresholdPolicy>::value,
      "Type FoldThresholdPolicy cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Leaflet::property_fold_threshold_policy () -> Glib::PropertyProxy<FoldThresholdPolicy>
  {
    return Glib::PropertyProxy<FoldThresholdPolicy> (this,
                                                     "fold-threshold-policy");
  }

  auto
  Leaflet::property_fold_threshold_policy () const -> Glib::PropertyProxy_ReadOnly<FoldThresholdPolicy>
  {
    return Glib::PropertyProxy_ReadOnly<FoldThresholdPolicy> (
        this,
        "fold-threshold-policy");
  }

  auto
  Leaflet::property_folded () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "folded");
  }

  auto
  Leaflet::property_homogeneous () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "homogeneous");
  }

  auto
  Leaflet::property_homogeneous () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "homogeneous");
  }

  auto
  Leaflet::property_mode_transition_duration () -> Glib::PropertyProxy<guint>
  {
    return Glib::PropertyProxy<guint> (this, "mode-transition-duration");
  }

  auto
  Leaflet::property_mode_transition_duration () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this,
                                                "mode-transition-duration");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gtk::SelectionModel>>::value,
      "Type Glib::RefPtr<Gtk::SelectionModel> cannot be used in "
      "_WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Leaflet::property_pages () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gtk::SelectionModel>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gtk::SelectionModel>> (
        this,
        "pages");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          LeafletTransitionType>::value,
      "Type LeafletTransitionType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Leaflet::property_transition_type () -> Glib::PropertyProxy<LeafletTransitionType>
  {
    return Glib::PropertyProxy<LeafletTransitionType> (this, "transition-type");
  }

  auto
  Leaflet::property_transition_type () const -> Glib::PropertyProxy_ReadOnly<LeafletTransitionType>
  {
    return Glib::PropertyProxy_ReadOnly<LeafletTransitionType> (
        this,
        "transition-type");
  }

  auto
  Leaflet::property_visible_child () -> Glib::PropertyProxy<Gtk::Widget*>
  {
    return Glib::PropertyProxy<Gtk::Widget*> (this, "visible-child");
  }

  auto
  Leaflet::property_visible_child () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::Widget*> (this, "visible-child");
  }

  auto
  Leaflet::property_visible_child_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "visible-child-name");
  }

  auto
  Leaflet::property_visible_child_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this,
                                                        "visible-child-name");
  }

} // namespace Adw
