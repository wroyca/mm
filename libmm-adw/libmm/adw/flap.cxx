// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/flap.hxx>
#include <libmm/adw/flap_p.hxx>

#include <libmm/gtk/mm-gtk.hxx>

namespace Adw
{

}

namespace
{
}

auto
Glib::Value<Adw::FlapFoldPolicy>::value_type () -> GType
{
  return adw_flap_fold_policy_get_type ();
}

auto
Glib::Value<Adw::FlapTransitionType>::value_type () -> GType
{
  return adw_flap_transition_type_get_type ();
}

namespace Glib
{

  auto
  wrap (AdwFlap* object, bool take_copy) -> Adw::Flap*
  {
    return dynamic_cast<Adw::Flap*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  Flap_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_flap_get_type ();
    }

    return *this;
  }

  auto
  Flap_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new Flap ((AdwFlap*) (o)));
  }

  Flap::Flap (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  Flap::Flap (AdwFlap* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Flap::Flap (Flap&& src) noexcept
    : Gtk::Widget (std::move (src)),
      Gtk::Orientable (std::move (src)),
      Adw::Swipeable (std::move (src))
  {
  }

  auto
  Flap::operator= (Flap&& src) noexcept -> Flap&
  {
    Gtk::Widget::operator= (std::move (src));
    Gtk::Orientable::operator= (std::move (src));
    Adw::Swipeable::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (flap_class_.init ()))
  {
  }

  auto
  Flap::get_content () const -> Gtk::Widget*
  {
    return Glib::wrap (adw_flap_get_content (const_cast<AdwFlap*> (gobj ())));
  }

  auto
  Flap::get_flap () const -> Gtk::Widget*
  {
    return Glib::wrap (adw_flap_get_flap (const_cast<AdwFlap*> (gobj ())));
  }

  auto
  Flap::get_flap_position () const -> Gtk::PackType
  {
    return static_cast<Gtk::PackType> (
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
  Flap::get_reveal_params () const -> Glib::RefPtr<SpringParams>
  {
    return Glib::wrap (
        adw_flap_get_reveal_params (const_cast<AdwFlap*> (gobj ())));
  }

  auto
  Flap::get_reveal_progress () const -> double
  {
    return adw_flap_get_reveal_progress (const_cast<AdwFlap*> (gobj ()));
  }

  auto
  Flap::get_separator () const -> Gtk::Widget*
  {
    return Glib::wrap (adw_flap_get_separator (const_cast<AdwFlap*> (gobj ())));
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
  Flap::set_content (Gtk::Widget* widget) -> void
  {
    adw_flap_set_content (gobj (), (GtkWidget*) Glib::unwrap (widget));
  }

  auto
  Flap::set_flap (Gtk::Widget* widget) -> void
  {
    adw_flap_set_flap (gobj (), (GtkWidget*) Glib::unwrap (widget));
  }

  auto
  Flap::set_flap_position (Gtk::PackType position) -> void
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
  Flap::set_reveal_params (const Glib::RefPtr<SpringParams>& params) -> void
  {
    adw_flap_set_reveal_params (gobj (), Glib::unwrap (params));
  }

  auto
  Flap::set_separator (Gtk::Widget* separator) -> void
  {
    adw_flap_set_separator (gobj (), (GtkWidget*) Glib::unwrap (separator));
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
  Flap::property_content () -> Glib::PropertyProxy<Gtk::Widget*>
  {
    return Glib::PropertyProxy<Gtk::Widget*> (this, "content");
  }

  auto
  Flap::property_content () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::Widget*> (this, "content");
  }

  auto
  Flap::property_flap () -> Glib::PropertyProxy<Gtk::Widget*>
  {
    return Glib::PropertyProxy<Gtk::Widget*> (this, "flap");
  }

  auto
  Flap::property_flap () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::Widget*> (this, "flap");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Gtk::PackType>::value,
      "Type Gtk::PackType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Flap::property_flap_position () -> Glib::PropertyProxy<Gtk::PackType>
  {
    return Glib::PropertyProxy<Gtk::PackType> (this, "flap-position");
  }

  auto
  Flap::property_flap_position () const -> Glib::PropertyProxy_ReadOnly<Gtk::PackType>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::PackType> (this, "flap-position");
  }

  auto
  Flap::property_fold_duration () -> Glib::PropertyProxy<guint>
  {
    return Glib::PropertyProxy<guint> (this, "fold-duration");
  }

  auto
  Flap::property_fold_duration () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "fold-duration");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<FlapFoldPolicy>::value,
      "Type FlapFoldPolicy cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Flap::property_fold_policy () -> Glib::PropertyProxy<FlapFoldPolicy>
  {
    return Glib::PropertyProxy<FlapFoldPolicy> (this, "fold-policy");
  }

  auto
  Flap::property_fold_policy () const -> Glib::PropertyProxy_ReadOnly<FlapFoldPolicy>
  {
    return Glib::PropertyProxy_ReadOnly<FlapFoldPolicy> (this, "fold-policy");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<FoldThresholdPolicy>::value,
      "Type FoldThresholdPolicy cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Flap::property_fold_threshold_policy () -> Glib::PropertyProxy<FoldThresholdPolicy>
  {
    return Glib::PropertyProxy<FoldThresholdPolicy> (this,
                                                     "fold-threshold-policy");
  }

  auto
  Flap::property_fold_threshold_policy () const -> Glib::PropertyProxy_ReadOnly<FoldThresholdPolicy>
  {
    return Glib::PropertyProxy_ReadOnly<FoldThresholdPolicy> (
        this,
        "fold-threshold-policy");
  }

  auto
  Flap::property_folded () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "folded");
  }

  auto
  Flap::property_locked () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "locked");
  }

  auto
  Flap::property_locked () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "locked");
  }

  auto
  Flap::property_modal () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "modal");
  }

  auto
  Flap::property_modal () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "modal");
  }

  auto
  Flap::property_reveal_flap () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "reveal-flap");
  }

  auto
  Flap::property_reveal_flap () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "reveal-flap");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<SpringParams>>::value,
      "Type Glib::RefPtr<SpringParams> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Flap::property_reveal_params () -> Glib::PropertyProxy<Glib::RefPtr<SpringParams>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<SpringParams>> (this,
                                                            "reveal-params");
  }

  auto
  Flap::property_reveal_params () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<SpringParams>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<SpringParams>> (
        this,
        "reveal-params");
  }

  auto
  Flap::property_reveal_progress () const -> Glib::PropertyProxy_ReadOnly<double>
  {
    return Glib::PropertyProxy_ReadOnly<double> (this, "reveal-progress");
  }

  auto
  Flap::property_separator () -> Glib::PropertyProxy<Gtk::Widget*>
  {
    return Glib::PropertyProxy<Gtk::Widget*> (this, "separator");
  }

  auto
  Flap::property_separator () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::Widget*> (this, "separator");
  }

  auto
  Flap::property_swipe_to_close () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "swipe-to-close");
  }

  auto
  Flap::property_swipe_to_close () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "swipe-to-close");
  }

  auto
  Flap::property_swipe_to_open () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "swipe-to-open");
  }

  auto
  Flap::property_swipe_to_open () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "swipe-to-open");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<FlapTransitionType>::value,
      "Type FlapTransitionType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Flap::property_transition_type () -> Glib::PropertyProxy<FlapTransitionType>
  {
    return Glib::PropertyProxy<FlapTransitionType> (this, "transition-type");
  }

  auto
  Flap::property_transition_type () const -> Glib::PropertyProxy_ReadOnly<FlapTransitionType>
  {
    return Glib::PropertyProxy_ReadOnly<FlapTransitionType> (this,
                                                             "transition-type");
  }

} // namespace Adw
