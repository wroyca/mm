// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/squeezer.hxx>
#include <libmm/adw/squeezer_p.hxx>

#include <libmm/adw/selectionlistmodelimpl.hxx>
#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

  auto
  squeezer::get_pages () const -> glib::RefPtr<gtk::SelectionModel>
  {
    GtkSelectionModel* pages =
        adw_squeezer_get_pages (const_cast<AdwSqueezer*> (gobj ()));
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
glib::Value<adw::SqueezerTransitionType>::value_type () -> GType
{
  return adw_squeezer_transition_type_get_type ();
}

namespace glib
{

  auto
  wrap (AdwSqueezer* object, bool take_copy) -> adw::squeezer*
  {
    return dynamic_cast<adw::squeezer*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  squeezer_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_squeezer_get_type ();
    }

    return *this;
  }

  auto
  squeezer_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new squeezer ((AdwSqueezer*) (o)));
  }

  squeezer::squeezer (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  squeezer::squeezer (AdwSqueezer* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  squeezer::squeezer (squeezer&& src) noexcept
    : gtk::Widget (std::move (src)),
      gtk::Orientable (std::move (src))
  {
  }

  auto
  squeezer::operator= (squeezer&& src) noexcept -> squeezer&
  {
    gtk::Widget::operator= (std::move (src));
    gtk::Orientable::operator= (std::move (src));
    return *this;
  }

  squeezer::~squeezer () noexcept
  {
    destroy_ ();
  }

  squeezer::CppClassType squeezer::squeezer_class_;

  auto
  squeezer::get_type () -> GType
  {
    return squeezer_class_.init ().get_type ();
  }

  auto
  squeezer::get_base_type () -> GType
  {
    return adw_squeezer_get_type ();
  }

  squeezer::squeezer ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (squeezer_class_.init ()))
  {
  }

  auto
  squeezer::add (gtk::Widget* p1) -> glib::RefPtr<squeezer_page>
  {
    auto retvalue =
        glib::wrap (adw_squeezer_add (gobj (), (GtkWidget*) glib::unwrap (p1)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  squeezer::get_allow_none () const -> bool
  {
    return adw_squeezer_get_allow_none (const_cast<AdwSqueezer*> (gobj ()));
  }

  auto
  squeezer::get_homogeneous () const -> bool
  {
    return adw_squeezer_get_homogeneous (const_cast<AdwSqueezer*> (gobj ()));
  }

  auto
  squeezer::get_interpolate_size () const -> bool
  {
    return adw_squeezer_get_interpolate_size (
        const_cast<AdwSqueezer*> (gobj ()));
  }

  auto
  squeezer::get (gtk::Widget* p1) const -> glib::RefPtr<squeezer_page>
  {
    auto retvalue =
        glib::wrap (adw_squeezer_get_page (const_cast<AdwSqueezer*> (gobj ()),
                                           (GtkWidget*) glib::unwrap (p1)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  squeezer::get_switch_threshold_policy () const -> FoldThresholdPolicy
  {
    return static_cast<FoldThresholdPolicy> (
        adw_squeezer_get_switch_threshold_policy (
            const_cast<AdwSqueezer*> (gobj ())));
  }

  auto
  squeezer::get_transition_duration () const -> guint
  {
    return adw_squeezer_get_transition_duration (
        const_cast<AdwSqueezer*> (gobj ()));
  }

  auto
  squeezer::get_transition_running () const -> bool
  {
    return adw_squeezer_get_transition_running (
        const_cast<AdwSqueezer*> (gobj ()));
  }

  auto
  squeezer::get_transition_type () const -> SqueezerTransitionType
  {
    return static_cast<SqueezerTransitionType> (
        adw_squeezer_get_transition_type (const_cast<AdwSqueezer*> (gobj ())));
  }

  auto
  squeezer::get_visible_child () const -> gtk::Widget*
  {
    return glib::wrap (
        adw_squeezer_get_visible_child (const_cast<AdwSqueezer*> (gobj ())));
  }

  auto
  squeezer::get_xalign () const -> float
  {
    return adw_squeezer_get_xalign (const_cast<AdwSqueezer*> (gobj ()));
  }

  auto
  squeezer::get_yalign () const -> float
  {
    return adw_squeezer_get_yalign (const_cast<AdwSqueezer*> (gobj ()));
  }

  auto
  squeezer::remove (gtk::Widget* p1) -> void
  {
    adw_squeezer_remove (gobj (), (GtkWidget*) glib::unwrap (p1));
  }

  auto
  squeezer::set_allow_none (bool allow_none) -> void
  {
    adw_squeezer_set_allow_none (gobj (), static_cast<int> (allow_none));
  }

  auto
  squeezer::set_homogeneous (bool homogeneous) -> void
  {
    adw_squeezer_set_homogeneous (gobj (), static_cast<int> (homogeneous));
  }

  auto
  squeezer::set_interpolate_size (bool homogeneous) -> void
  {
    adw_squeezer_set_interpolate_size (gobj (), static_cast<int> (homogeneous));
  }

  auto
  squeezer::set_switch_threshold_policy (FoldThresholdPolicy policy) -> void
  {
    adw_squeezer_set_switch_threshold_policy (
        gobj (),
        static_cast<AdwFoldThresholdPolicy> (policy));
  }

  auto
  squeezer::set_transition_duration (guint duration) -> void
  {
    adw_squeezer_set_transition_duration (gobj (), duration);
  }

  auto
  squeezer::set_transition_type (SqueezerTransitionType transition) -> void
  {
    adw_squeezer_set_transition_type (
        gobj (),
        static_cast<AdwSqueezerTransitionType> (transition));
  }

  auto
  squeezer::set_xalign (float xalign) -> void
  {
    adw_squeezer_set_xalign (gobj (), xalign);
  }

  auto
  squeezer::set_yalign (float xalign) -> void
  {
    adw_squeezer_set_yalign (gobj (), xalign);
  }

  auto
  squeezer::property_allow_none () -> glib::PropertyProxy<bool>
  {
    return {this, "allow-none"};
  }

  auto
  squeezer::property_allow_none () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "allow-none"};
  }

  auto
  squeezer::property_homogeneous () -> glib::PropertyProxy<bool>
  {
    return {this, "homogeneous"};
  }

  auto
  squeezer::property_homogeneous () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "homogeneous"};
  }

  auto
  squeezer::property_interpolate_size () -> glib::PropertyProxy<bool>
  {
    return {this, "interpolate-size"};
  }

  auto
  squeezer::property_interpolate_size () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "interpolate-size"};
  }

  auto
  squeezer::property_pages () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gtk::SelectionModel>>
  {
    return {this, "pages"};
  }

  auto
  squeezer::property_switch_threshold_policy () -> glib::PropertyProxy<FoldThresholdPolicy>
  {
    return {this, "switch-threshold-policy"};
  }

  auto
  squeezer::property_switch_threshold_policy () const -> glib::PropertyProxy_ReadOnly<FoldThresholdPolicy>
  {
    return {this, "switch-threshold-policy"};
  }

  auto
  squeezer::property_transition_duration () -> glib::PropertyProxy<guint>
  {
    return {this, "transition-duration"};
  }

  auto
  squeezer::property_transition_duration () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return {this, "transition-duration"};
  }

  auto
  squeezer::property_transition_running () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "transition-running"};
  }

  auto
  squeezer::property_transition_type () -> glib::PropertyProxy<SqueezerTransitionType>
  {
    return {this, "transition-type"};
  }

  auto
  squeezer::property_transition_type () const -> glib::PropertyProxy_ReadOnly<SqueezerTransitionType>
  {
    return {this, "transition-type"};
  }

  auto
  squeezer::property_visible_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "visible-child"};
  }

  auto
  squeezer::property_xalign () -> glib::PropertyProxy<float>
  {
    return {this, "xalign"};
  }

  auto
  squeezer::property_xalign () const -> glib::PropertyProxy_ReadOnly<float>
  {
    return {this, "xalign"};
  }

  auto
  squeezer::property_yalign () -> glib::PropertyProxy<float>
  {
    return {this, "yalign"};
  }

  auto
  squeezer::property_yalign () const -> glib::PropertyProxy_ReadOnly<float>
  {
    return {this, "yalign"};
  }

} // namespace adw
