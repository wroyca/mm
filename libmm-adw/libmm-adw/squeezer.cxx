// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-adw/squeezer.hxx>
#include <libmm-adw/squeezer_p.hxx>

#include <libmm-adw/selectionlistmodelimpl.hxx>
#include <libmm-gtk/mm-gtk.hxx>

namespace Adw
{

  auto
  Squeezer::get_pages () const -> Glib::RefPtr<Gtk::SelectionModel>
  {
    GtkSelectionModel* pages =
        adw_squeezer_get_pages (const_cast<AdwSqueezer*> (gobj ()));
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
Glib::Value<Adw::SqueezerTransitionType>::value_type () -> GType
{
  return adw_squeezer_transition_type_get_type ();
}

namespace Glib
{

  auto
  wrap (AdwSqueezer* object, bool take_copy) -> Adw::Squeezer*
  {
    return dynamic_cast<Adw::Squeezer*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  Squeezer_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_squeezer_get_type ();
    }

    return *this;
  }

  auto
  Squeezer_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new Squeezer ((AdwSqueezer*) (o)));
  }

  Squeezer::Squeezer (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  Squeezer::Squeezer (AdwSqueezer* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Squeezer::Squeezer (Squeezer&& src) noexcept
    : Gtk::Widget (std::move (src)),
      Gtk::Orientable (std::move (src))
  {
  }

  auto
  Squeezer::operator= (Squeezer&& src) noexcept -> Squeezer&
  {
    Gtk::Widget::operator= (std::move (src));
    Gtk::Orientable::operator= (std::move (src));
    return *this;
  }

  Squeezer::~Squeezer () noexcept
  {
    destroy_ ();
  }

  Squeezer::CppClassType Squeezer::squeezer_class_;

  auto
  Squeezer::get_type () -> GType
  {
    return squeezer_class_.init ().get_type ();
  }

  auto
  Squeezer::get_base_type () -> GType
  {
    return adw_squeezer_get_type ();
  }

  Squeezer::Squeezer ()
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (squeezer_class_.init ()))
  {
  }

  auto
  Squeezer::add (Gtk::Widget* p1) -> Glib::RefPtr<SqueezerPage>
  {
    auto retvalue =
        Glib::wrap (adw_squeezer_add (gobj (), (GtkWidget*) Glib::unwrap (p1)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Squeezer::get_allow_none () const -> bool
  {
    return adw_squeezer_get_allow_none (const_cast<AdwSqueezer*> (gobj ()));
  }

  auto
  Squeezer::get_homogeneous () const -> bool
  {
    return adw_squeezer_get_homogeneous (const_cast<AdwSqueezer*> (gobj ()));
  }

  auto
  Squeezer::get_interpolate_size () const -> bool
  {
    return adw_squeezer_get_interpolate_size (
        const_cast<AdwSqueezer*> (gobj ()));
  }

  auto
  Squeezer::get (Gtk::Widget* p1) const -> Glib::RefPtr<SqueezerPage>
  {
    auto retvalue =
        Glib::wrap (adw_squeezer_get_page (const_cast<AdwSqueezer*> (gobj ()),
                                           (GtkWidget*) Glib::unwrap (p1)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Squeezer::get_switch_threshold_policy () const -> FoldThresholdPolicy
  {
    return static_cast<FoldThresholdPolicy> (
        adw_squeezer_get_switch_threshold_policy (
            const_cast<AdwSqueezer*> (gobj ())));
  }

  auto
  Squeezer::get_transition_duration () const -> guint
  {
    return adw_squeezer_get_transition_duration (
        const_cast<AdwSqueezer*> (gobj ()));
  }

  auto
  Squeezer::get_transition_running () const -> bool
  {
    return adw_squeezer_get_transition_running (
        const_cast<AdwSqueezer*> (gobj ()));
  }

  auto
  Squeezer::get_transition_type () const -> SqueezerTransitionType
  {
    return static_cast<SqueezerTransitionType> (
        adw_squeezer_get_transition_type (const_cast<AdwSqueezer*> (gobj ())));
  }

  auto
  Squeezer::get_visible_child () const -> Gtk::Widget*
  {
    return Glib::wrap (
        adw_squeezer_get_visible_child (const_cast<AdwSqueezer*> (gobj ())));
  }

  auto
  Squeezer::get_xalign () const -> float
  {
    return adw_squeezer_get_xalign (const_cast<AdwSqueezer*> (gobj ()));
  }

  auto
  Squeezer::get_yalign () const -> float
  {
    return adw_squeezer_get_yalign (const_cast<AdwSqueezer*> (gobj ()));
  }

  auto
  Squeezer::remove (Gtk::Widget* p1) -> void
  {
    adw_squeezer_remove (gobj (), (GtkWidget*) Glib::unwrap (p1));
  }

  auto
  Squeezer::set_allow_none (bool allow_none) -> void
  {
    adw_squeezer_set_allow_none (gobj (), static_cast<int> (allow_none));
  }

  auto
  Squeezer::set_homogeneous (bool homogeneous) -> void
  {
    adw_squeezer_set_homogeneous (gobj (), static_cast<int> (homogeneous));
  }

  auto
  Squeezer::set_interpolate_size (bool homogeneous) -> void
  {
    adw_squeezer_set_interpolate_size (gobj (), static_cast<int> (homogeneous));
  }

  auto
  Squeezer::set_switch_threshold_policy (FoldThresholdPolicy policy) -> void
  {
    adw_squeezer_set_switch_threshold_policy (
        gobj (),
        static_cast<AdwFoldThresholdPolicy> (policy));
  }

  auto
  Squeezer::set_transition_duration (guint duration) -> void
  {
    adw_squeezer_set_transition_duration (gobj (), duration);
  }

  auto
  Squeezer::set_transition_type (SqueezerTransitionType transition) -> void
  {
    adw_squeezer_set_transition_type (
        gobj (),
        static_cast<AdwSqueezerTransitionType> (transition));
  }

  auto
  Squeezer::set_xalign (float xalign) -> void
  {
    adw_squeezer_set_xalign (gobj (), xalign);
  }

  auto
  Squeezer::set_yalign (float xalign) -> void
  {
    adw_squeezer_set_yalign (gobj (), xalign);
  }

  auto
  Squeezer::property_allow_none () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "allow-none");
  }

  auto
  Squeezer::property_allow_none () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "allow-none");
  }

  auto
  Squeezer::property_homogeneous () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "homogeneous");
  }

  auto
  Squeezer::property_homogeneous () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "homogeneous");
  }

  auto
  Squeezer::property_interpolate_size () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "interpolate-size");
  }

  auto
  Squeezer::property_interpolate_size () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "interpolate-size");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gtk::SelectionModel>>::value,
      "Type Glib::RefPtr<Gtk::SelectionModel> cannot be used in "
      "_WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Squeezer::property_pages () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gtk::SelectionModel>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gtk::SelectionModel>> (
        this,
        "pages");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<FoldThresholdPolicy>::value,
      "Type FoldThresholdPolicy cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Squeezer::property_switch_threshold_policy () -> Glib::PropertyProxy<FoldThresholdPolicy>
  {
    return Glib::PropertyProxy<FoldThresholdPolicy> (this,
                                                     "switch-threshold-policy");
  }

  auto
  Squeezer::property_switch_threshold_policy () const -> Glib::PropertyProxy_ReadOnly<FoldThresholdPolicy>
  {
    return Glib::PropertyProxy_ReadOnly<FoldThresholdPolicy> (
        this,
        "switch-threshold-policy");
  }

  auto
  Squeezer::property_transition_duration () -> Glib::PropertyProxy<guint>
  {
    return Glib::PropertyProxy<guint> (this, "transition-duration");
  }

  auto
  Squeezer::property_transition_duration () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "transition-duration");
  }

  auto
  Squeezer::property_transition_running () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "transition-running");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          SqueezerTransitionType>::value,
      "Type SqueezerTransitionType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Squeezer::property_transition_type () -> Glib::PropertyProxy<SqueezerTransitionType>
  {
    return Glib::PropertyProxy<SqueezerTransitionType> (this,
                                                        "transition-type");
  }

  auto
  Squeezer::property_transition_type () const -> Glib::PropertyProxy_ReadOnly<SqueezerTransitionType>
  {
    return Glib::PropertyProxy_ReadOnly<SqueezerTransitionType> (
        this,
        "transition-type");
  }

  auto
  Squeezer::property_visible_child () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::Widget*> (this, "visible-child");
  }

  auto
  Squeezer::property_xalign () -> Glib::PropertyProxy<float>
  {
    return Glib::PropertyProxy<float> (this, "xalign");
  }

  auto
  Squeezer::property_xalign () const -> Glib::PropertyProxy_ReadOnly<float>
  {
    return Glib::PropertyProxy_ReadOnly<float> (this, "xalign");
  }

  auto
  Squeezer::property_yalign () -> Glib::PropertyProxy<float>
  {
    return Glib::PropertyProxy<float> (this, "yalign");
  }

  auto
  Squeezer::property_yalign () const -> Glib::PropertyProxy_ReadOnly<float>
  {
    return Glib::PropertyProxy_ReadOnly<float> (this, "yalign");
  }

} // namespace Adw
