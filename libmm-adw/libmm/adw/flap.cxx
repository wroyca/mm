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
  wrap (AdwFlap* object, bool take_copy) -> adw::Flap*
  {
    return dynamic_cast<adw::Flap*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  Flap_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_flap_get_type ();
    }

    return *this;
  }

  auto
  Flap_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Flap ((AdwFlap*) (o)));
  }

  Flap::Flap (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Flap::Flap (AdwFlap* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Flap::Flap (Flap&& src) noexcept
    : gtk::Widget (std::move (src)),
      gtk::Orientable (std::move (src)),
      adw::Swipeable (std::move (src))
  {
  }

  auto
  Flap::operator= (Flap&& src) noexcept -> Flap&
  {
    gtk::Widget::operator= (std::move (src));
    gtk::Orientable::operator= (std::move (src));
    adw::Swipeable::operator= (std::move (src));
    return *this;
  }

  Flap::~Flap () noexcept
  {
    destroy_ ();
  }

  Flap::CppClassType Flap::flap_class_;

  auto
  Flap::get_type () -> GType
  {
    return flap_class_.init ().get_type ();
  }

  auto
  Flap::get_base_type () -> GType
  {
    return adw_flap_get_type ();
  }

  Flap::Flap ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (flap_class_.init ()))
  {
  }

  auto
  Flap::get_content () const -> gtk::Widget*
  {
    return glib::wrap (adw_flap_get_content (const_cast<AdwFlap*> (gobj ())));
  }

  auto
  Flap::get_flap () const -> gtk::Widget*
  {
    return glib::wrap (adw_flap_get_flap (const_cast<AdwFlap*> (gobj ())));
  }

  auto
  Flap::get_flap_position () const -> gtk::PackType
  {
    return static_cast<gtk::PackType> (
        adw_flap_get_flap_position (const_cast<AdwFlap*> (gobj ())));
  }

  auto
  Flap::get_fold_duration () const -> guint
  {
    return adw_flap_get_fold_duration (const_cast<AdwFlap*> (gobj ()));
  }

  auto
  Flap::get_fold_policy () const -> FlapFoldPolicy
  {
    return static_cast<FlapFoldPolicy> (
        adw_flap_get_fold_policy (const_cast<AdwFlap*> (gobj ())));
  }

  auto
  Flap::get_fold_threshold_policy () const -> FoldThresholdPolicy
  {
    return static_cast<FoldThresholdPolicy> (
        adw_flap_get_fold_threshold_policy (const_cast<AdwFlap*> (gobj ())));
  }

  auto
  Flap::get_folded () const -> bool
  {
    return adw_flap_get_folded (const_cast<AdwFlap*> (gobj ()));
  }

  auto
  Flap::get_locked () const -> bool
  {
    return adw_flap_get_locked (const_cast<AdwFlap*> (gobj ()));
  }

  auto
  Flap::get_modal () const -> bool
  {
    return adw_flap_get_modal (const_cast<AdwFlap*> (gobj ()));
  }

  auto
  Flap::get_reveal_flap () const -> bool
  {
    return adw_flap_get_reveal_flap (const_cast<AdwFlap*> (gobj ()));
  }

  auto
  Flap::get_reveal_params () const -> glib::RefPtr<SpringParams>
  {
    return glib::wrap (
        adw_flap_get_reveal_params (const_cast<AdwFlap*> (gobj ())));
  }

  auto
  Flap::get_reveal_progress () const -> double
  {
    return adw_flap_get_reveal_progress (const_cast<AdwFlap*> (gobj ()));
  }

  auto
  Flap::get_separator () const -> gtk::Widget*
  {
    return glib::wrap (adw_flap_get_separator (const_cast<AdwFlap*> (gobj ())));
  }

  auto
  Flap::get_swipe_to_close () const -> bool
  {
    return adw_flap_get_swipe_to_close (const_cast<AdwFlap*> (gobj ()));
  }

  auto
  Flap::get_swipe_to_open () const -> bool
  {
    return adw_flap_get_swipe_to_open (const_cast<AdwFlap*> (gobj ()));
  }

  auto
  Flap::get_transition_type () const -> FlapTransitionType
  {
    return static_cast<FlapTransitionType> (
        adw_flap_get_transition_type (const_cast<AdwFlap*> (gobj ())));
  }

  auto
  Flap::set_content (gtk::Widget* widget) -> void
  {
    adw_flap_set_content (gobj (), (GtkWidget*) glib::unwrap (widget));
  }

  auto
  Flap::set_flap (gtk::Widget* widget) -> void
  {
    adw_flap_set_flap (gobj (), (GtkWidget*) glib::unwrap (widget));
  }

  auto
  Flap::set_flap_position (gtk::PackType position) -> void
  {
    adw_flap_set_flap_position (gobj (), static_cast<GtkPackType> (position));
  }

  auto
  Flap::set_fold_duration (guint duration) -> void
  {
    adw_flap_set_fold_duration (gobj (), duration);
  }

  auto
  Flap::set_fold_policy (FlapFoldPolicy policy) -> void
  {
    adw_flap_set_fold_policy (gobj (), static_cast<AdwFlapFoldPolicy> (policy));
  }

  auto
  Flap::set_fold_threshold_policy (FoldThresholdPolicy p1) -> void
  {
    adw_flap_set_fold_threshold_policy (
        gobj (),
        static_cast<AdwFoldThresholdPolicy> (p1));
  }

  auto
  Flap::set_locked (bool locked) -> void
  {
    adw_flap_set_locked (gobj (), static_cast<int> (locked));
  }

  auto
  Flap::set_modal (bool modal) -> void
  {
    adw_flap_set_modal (gobj (), static_cast<int> (modal));
  }

  auto
  Flap::set_reveal_flap (bool reveal_flap) -> void
  {
    adw_flap_set_reveal_flap (gobj (), static_cast<int> (reveal_flap));
  }

  auto
  Flap::set_reveal_params (const glib::RefPtr<SpringParams>& params) -> void
  {
    adw_flap_set_reveal_params (gobj (), glib::unwrap (params));
  }

  auto
  Flap::set_separator (gtk::Widget* separator) -> void
  {
    adw_flap_set_separator (gobj (), (GtkWidget*) glib::unwrap (separator));
  }

  auto
  Flap::set_swipe_to_close (bool locked) -> void
  {
    adw_flap_set_swipe_to_close (gobj (), static_cast<int> (locked));
  }

  auto
  Flap::set_swipe_to_open (bool locked) -> void
  {
    adw_flap_set_swipe_to_open (gobj (), static_cast<int> (locked));
  }

  auto
  Flap::set_transition_type (FlapTransitionType transition_type) -> void
  {
    adw_flap_set_transition_type (
        gobj (),
        static_cast<AdwFlapTransitionType> (transition_type));
  }

  auto
  Flap::property_content () -> glib::PropertyProxy<gtk::Widget*>
  {
    return glib::PropertyProxy<gtk::Widget*> (this, "content");
  }

  auto
  Flap::property_content () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return glib::PropertyProxy_ReadOnly<gtk::Widget*> (this, "content");
  }

  auto
  Flap::property_flap () -> glib::PropertyProxy<gtk::Widget*>
  {
    return glib::PropertyProxy<gtk::Widget*> (this, "flap");
  }

  auto
  Flap::property_flap () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return glib::PropertyProxy_ReadOnly<gtk::Widget*> (this, "flap");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<gtk::PackType>::value,
      "Type gtk::PackType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Flap::property_flap_position () -> glib::PropertyProxy<gtk::PackType>
  {
    return glib::PropertyProxy<gtk::PackType> (this, "flap-position");
  }

  auto
  Flap::property_flap_position () const -> glib::PropertyProxy_ReadOnly<gtk::PackType>
  {
    return glib::PropertyProxy_ReadOnly<gtk::PackType> (this, "flap-position");
  }

  auto
  Flap::property_fold_duration () -> glib::PropertyProxy<guint>
  {
    return glib::PropertyProxy<guint> (this, "fold-duration");
  }

  auto
  Flap::property_fold_duration () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "fold-duration");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<FlapFoldPolicy>::value,
      "Type FlapFoldPolicy cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Flap::property_fold_policy () -> glib::PropertyProxy<FlapFoldPolicy>
  {
    return glib::PropertyProxy<FlapFoldPolicy> (this, "fold-policy");
  }

  auto
  Flap::property_fold_policy () const -> glib::PropertyProxy_ReadOnly<FlapFoldPolicy>
  {
    return glib::PropertyProxy_ReadOnly<FlapFoldPolicy> (this, "fold-policy");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<FoldThresholdPolicy>::value,
      "Type FoldThresholdPolicy cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Flap::property_fold_threshold_policy () -> glib::PropertyProxy<FoldThresholdPolicy>
  {
    return glib::PropertyProxy<FoldThresholdPolicy> (this,
                                                     "fold-threshold-policy");
  }

  auto
  Flap::property_fold_threshold_policy () const -> glib::PropertyProxy_ReadOnly<FoldThresholdPolicy>
  {
    return glib::PropertyProxy_ReadOnly<FoldThresholdPolicy> (
        this,
        "fold-threshold-policy");
  }

  auto
  Flap::property_folded () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "folded");
  }

  auto
  Flap::property_locked () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "locked");
  }

  auto
  Flap::property_locked () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "locked");
  }

  auto
  Flap::property_modal () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "modal");
  }

  auto
  Flap::property_modal () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "modal");
  }

  auto
  Flap::property_reveal_flap () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "reveal-flap");
  }

  auto
  Flap::property_reveal_flap () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "reveal-flap");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<SpringParams>>::value,
      "Type glib::RefPtr<SpringParams> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Flap::property_reveal_params () -> glib::PropertyProxy<glib::RefPtr<SpringParams>>
  {
    return glib::PropertyProxy<glib::RefPtr<SpringParams>> (this,
                                                            "reveal-params");
  }

  auto
  Flap::property_reveal_params () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<SpringParams>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<SpringParams>> (
        this,
        "reveal-params");
  }

  auto
  Flap::property_reveal_progress () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return glib::PropertyProxy_ReadOnly<double> (this, "reveal-progress");
  }

  auto
  Flap::property_separator () -> glib::PropertyProxy<gtk::Widget*>
  {
    return glib::PropertyProxy<gtk::Widget*> (this, "separator");
  }

  auto
  Flap::property_separator () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return glib::PropertyProxy_ReadOnly<gtk::Widget*> (this, "separator");
  }

  auto
  Flap::property_swipe_to_close () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "swipe-to-close");
  }

  auto
  Flap::property_swipe_to_close () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "swipe-to-close");
  }

  auto
  Flap::property_swipe_to_open () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "swipe-to-open");
  }

  auto
  Flap::property_swipe_to_open () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "swipe-to-open");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<FlapTransitionType>::value,
      "Type FlapTransitionType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Flap::property_transition_type () -> glib::PropertyProxy<FlapTransitionType>
  {
    return glib::PropertyProxy<FlapTransitionType> (this, "transition-type");
  }

  auto
  Flap::property_transition_type () const -> glib::PropertyProxy_ReadOnly<FlapTransitionType>
  {
    return glib::PropertyProxy_ReadOnly<FlapTransitionType> (this,
                                                             "transition-type");
  }

} // namespace adw
