// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/flap.hxx>
#include <libmm/adw/flap_p.hxx>

#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

}

namespace
{
}

auto
glib::Value<adw::FlapFoldPolicy>::value_type () -> GType
{
  return adw_flap_fold_policy_get_type ();
}

auto
glib::Value<adw::FlapTransitionType>::value_type () -> GType
{
  return adw_flap_transition_type_get_type ();
}

namespace glib
{

  auto
  wrap (AdwFlap* object, bool take_copy) -> adw::flap*
  {
    return dynamic_cast<adw::flap*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  flap_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_flap_get_type ();
    }

    return *this;
  }

  auto
  flap_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new flap ((AdwFlap*) (o)));
  }

  flap::flap (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  flap::flap (AdwFlap* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  flap::flap (flap&& src) noexcept
    : gtk::Widget (std::move (src)),
      gtk::Orientable (std::move (src)),
      adw::swipeable (std::move (src))
  {
  }

  auto
  flap::operator= (flap&& src) noexcept -> flap&
  {
    gtk::Widget::operator= (std::move (src));
    gtk::Orientable::operator= (std::move (src));
    adw::swipeable::operator= (std::move (src));
    return *this;
  }

  flap::~flap () noexcept
  {
    destroy_ ();
  }

  flap::CppClassType flap::flap_class_;

  auto
  flap::get_type () -> GType
  {
    return flap_class_.init ().get_type ();
  }

  auto
  flap::get_base_type () -> GType
  {
    return adw_flap_get_type ();
  }

  flap::flap ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (flap_class_.init ()))
  {
  }

  auto
  flap::get_content () const -> gtk::Widget*
  {
    return glib::wrap (adw_flap_get_content (const_cast<AdwFlap*> (gobj ())));
  }

  auto
  flap::get_flap () const -> gtk::Widget*
  {
    return glib::wrap (adw_flap_get_flap (const_cast<AdwFlap*> (gobj ())));
  }

  auto
  flap::get_flap_position () const -> gtk::PackType
  {
    return static_cast<gtk::PackType> (
        adw_flap_get_flap_position (const_cast<AdwFlap*> (gobj ())));
  }

  auto
  flap::get_fold_duration () const -> guint
  {
    return adw_flap_get_fold_duration (const_cast<AdwFlap*> (gobj ()));
  }

  auto
  flap::get_fold_policy () const -> FlapFoldPolicy
  {
    return static_cast<FlapFoldPolicy> (
        adw_flap_get_fold_policy (const_cast<AdwFlap*> (gobj ())));
  }

  auto
  flap::get_fold_threshold_policy () const -> FoldThresholdPolicy
  {
    return static_cast<FoldThresholdPolicy> (
        adw_flap_get_fold_threshold_policy (const_cast<AdwFlap*> (gobj ())));
  }

  auto
  flap::get_folded () const -> bool
  {
    return adw_flap_get_folded (const_cast<AdwFlap*> (gobj ()));
  }

  auto
  flap::get_locked () const -> bool
  {
    return adw_flap_get_locked (const_cast<AdwFlap*> (gobj ()));
  }

  auto
  flap::get_modal () const -> bool
  {
    return adw_flap_get_modal (const_cast<AdwFlap*> (gobj ()));
  }

  auto
  flap::get_reveal_flap () const -> bool
  {
    return adw_flap_get_reveal_flap (const_cast<AdwFlap*> (gobj ()));
  }

  auto
  flap::get_reveal_params () const -> glib::RefPtr<spring_params>
  {
    return glib::wrap (
        adw_flap_get_reveal_params (const_cast<AdwFlap*> (gobj ())));
  }

  auto
  flap::get_reveal_progress () const -> double
  {
    return adw_flap_get_reveal_progress (const_cast<AdwFlap*> (gobj ()));
  }

  auto
  flap::get_separator () const -> gtk::Widget*
  {
    return glib::wrap (adw_flap_get_separator (const_cast<AdwFlap*> (gobj ())));
  }

  auto
  flap::get_swipe_to_close () const -> bool
  {
    return adw_flap_get_swipe_to_close (const_cast<AdwFlap*> (gobj ()));
  }

  auto
  flap::get_swipe_to_open () const -> bool
  {
    return adw_flap_get_swipe_to_open (const_cast<AdwFlap*> (gobj ()));
  }

  auto
  flap::get_transition_type () const -> FlapTransitionType
  {
    return static_cast<FlapTransitionType> (
        adw_flap_get_transition_type (const_cast<AdwFlap*> (gobj ())));
  }

  auto
  flap::set_content (gtk::Widget* widget) -> void
  {
    adw_flap_set_content (gobj (), (GtkWidget*) glib::unwrap (widget));
  }

  auto
  flap::set_flap (gtk::Widget* widget) -> void
  {
    adw_flap_set_flap (gobj (), (GtkWidget*) glib::unwrap (widget));
  }

  auto
  flap::set_flap_position (gtk::PackType position) -> void
  {
    adw_flap_set_flap_position (gobj (), static_cast<GtkPackType> (position));
  }

  auto
  flap::set_fold_duration (guint duration) -> void
  {
    adw_flap_set_fold_duration (gobj (), duration);
  }

  auto
  flap::set_fold_policy (FlapFoldPolicy policy) -> void
  {
    adw_flap_set_fold_policy (gobj (), static_cast<AdwFlapFoldPolicy> (policy));
  }

  auto
  flap::set_fold_threshold_policy (FoldThresholdPolicy p1) -> void
  {
    adw_flap_set_fold_threshold_policy (
        gobj (),
        static_cast<AdwFoldThresholdPolicy> (p1));
  }

  auto
  flap::set_locked (bool locked) -> void
  {
    adw_flap_set_locked (gobj (), static_cast<int> (locked));
  }

  auto
  flap::set_modal (bool modal) -> void
  {
    adw_flap_set_modal (gobj (), static_cast<int> (modal));
  }

  auto
  flap::set_reveal_flap (bool reveal_flap) -> void
  {
    adw_flap_set_reveal_flap (gobj (), static_cast<int> (reveal_flap));
  }

  auto
  flap::set_reveal_params (const glib::RefPtr<spring_params>& params) -> void
  {
    adw_flap_set_reveal_params (gobj (), glib::unwrap (params));
  }

  auto
  flap::set_separator (gtk::Widget* separator) -> void
  {
    adw_flap_set_separator (gobj (), (GtkWidget*) glib::unwrap (separator));
  }

  auto
  flap::set_swipe_to_close (bool locked) -> void
  {
    adw_flap_set_swipe_to_close (gobj (), static_cast<int> (locked));
  }

  auto
  flap::set_swipe_to_open (bool locked) -> void
  {
    adw_flap_set_swipe_to_open (gobj (), static_cast<int> (locked));
  }

  auto
  flap::set_transition_type (FlapTransitionType transition_type) -> void
  {
    adw_flap_set_transition_type (
        gobj (),
        static_cast<AdwFlapTransitionType> (transition_type));
  }

  auto
  flap::property_content () -> glib::PropertyProxy<gtk::Widget*>
  {
    return {this, "content"};
  }

  auto
  flap::property_content () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "content"};
  }

  auto
  flap::property_flap () -> glib::PropertyProxy<gtk::Widget*>
  {
    return {this, "flap"};
  }

  auto
  flap::property_flap () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "flap"};
  }

  auto
  flap::property_flap_position () -> glib::PropertyProxy<gtk::PackType>
  {
    return {this, "flap-position"};
  }

  auto
  flap::property_flap_position () const -> glib::PropertyProxy_ReadOnly<gtk::PackType>
  {
    return {this, "flap-position"};
  }

  auto
  flap::property_fold_duration () -> glib::PropertyProxy<guint>
  {
    return {this, "fold-duration"};
  }

  auto
  flap::property_fold_duration () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return {this, "fold-duration"};
  }

  auto
  flap::property_fold_policy () -> glib::PropertyProxy<FlapFoldPolicy>
  {
    return {this, "fold-policy"};
  }

  auto
  flap::property_fold_policy () const -> glib::PropertyProxy_ReadOnly<FlapFoldPolicy>
  {
    return {this, "fold-policy"};
  }

  auto
  flap::property_fold_threshold_policy () -> glib::PropertyProxy<FoldThresholdPolicy>
  {
    return {this, "fold-threshold-policy"};
  }

  auto
  flap::property_fold_threshold_policy () const -> glib::PropertyProxy_ReadOnly<FoldThresholdPolicy>
  {
    return {this, "fold-threshold-policy"};
  }

  auto
  flap::property_folded () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "folded"};
  }

  auto
  flap::property_locked () -> glib::PropertyProxy<bool>
  {
    return {this, "locked"};
  }

  auto
  flap::property_locked () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "locked"};
  }

  auto
  flap::property_modal () -> glib::PropertyProxy<bool>
  {
    return {this, "modal"};
  }

  auto
  flap::property_modal () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "modal"};
  }

  auto
  flap::property_reveal_flap () -> glib::PropertyProxy<bool>
  {
    return {this, "reveal-flap"};
  }

  auto
  flap::property_reveal_flap () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "reveal-flap"};
  }

  auto
  flap::property_reveal_params () -> glib::PropertyProxy<glib::RefPtr<spring_params>>
  {
    return {this, "reveal-params"};
  }

  auto
  flap::property_reveal_params () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<spring_params>>
  {
    return {this, "reveal-params"};
  }

  auto
  flap::property_reveal_progress () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return {this, "reveal-progress"};
  }

  auto
  flap::property_separator () -> glib::PropertyProxy<gtk::Widget*>
  {
    return {this, "separator"};
  }

  auto
  flap::property_separator () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "separator"};
  }

  auto
  flap::property_swipe_to_close () -> glib::PropertyProxy<bool>
  {
    return {this, "swipe-to-close"};
  }

  auto
  flap::property_swipe_to_close () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "swipe-to-close"};
  }

  auto
  flap::property_swipe_to_open () -> glib::PropertyProxy<bool>
  {
    return {this, "swipe-to-open"};
  }

  auto
  flap::property_swipe_to_open () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "swipe-to-open"};
  }

  auto
  flap::property_transition_type () -> glib::PropertyProxy<FlapTransitionType>
  {
    return {this, "transition-type"};
  }

  auto
  flap::property_transition_type () const -> glib::PropertyProxy_ReadOnly<FlapTransitionType>
  {
    return {this, "transition-type"};
  }

} // namespace adw
