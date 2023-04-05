// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/squeezer.hxx>
#include <libmm/adw/squeezer_p.hxx>

#include <libmm/adw/selectionlistmodelimpl.hxx>
#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

  auto
  Squeezer::get_pages () const -> glib::RefPtr<gtk::SelectionModel>
  {
    GtkSelectionModel* pages =
        adw_squeezer_get_pages (const_cast<AdwSqueezer*> (gobj ()));
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
glib::Value<adw::SqueezerTransitionType>::value_type () -> GType
{
  return adw_squeezer_transition_type_get_type ();
}

namespace glib
{

  auto
  wrap (AdwSqueezer* object, bool take_copy) -> adw::Squeezer*
  {
    return dynamic_cast<adw::Squeezer*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  Squeezer_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_squeezer_get_type ();
    }

    return *this;
  }

  auto
  Squeezer_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Squeezer ((AdwSqueezer*) (o)));
  }

  Squeezer::Squeezer (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Squeezer::Squeezer (AdwSqueezer* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Squeezer::Squeezer (Squeezer&& src) noexcept
    : gtk::Widget (std::move (src)),
      gtk::Orientable (std::move (src))
  {
  }

  auto
  Squeezer::operator= (Squeezer&& src) noexcept -> Squeezer&
  {
    gtk::Widget::operator= (std::move (src));
    gtk::Orientable::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (squeezer_class_.init ()))
  {
  }

  auto
  Squeezer::add (gtk::Widget* p1) -> glib::RefPtr<SqueezerPage>
  {
    auto retvalue =
        glib::wrap (adw_squeezer_add (gobj (), (GtkWidget*) glib::unwrap (p1)));
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
  Squeezer::get (gtk::Widget* p1) const -> glib::RefPtr<SqueezerPage>
  {
    auto retvalue =
        glib::wrap (adw_squeezer_get_page (const_cast<AdwSqueezer*> (gobj ()),
                                           (GtkWidget*) glib::unwrap (p1)));
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
  Squeezer::get_visible_child () const -> gtk::Widget*
  {
    return glib::wrap (
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
  Squeezer::remove (gtk::Widget* p1) -> void
  {
    adw_squeezer_remove (gobj (), (GtkWidget*) glib::unwrap (p1));
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
  Squeezer::property_allow_none () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "allow-none");
  }

  auto
  Squeezer::property_allow_none () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "allow-none");
  }

  auto
  Squeezer::property_homogeneous () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "homogeneous");
  }

  auto
  Squeezer::property_homogeneous () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "homogeneous");
  }

  auto
  Squeezer::property_interpolate_size () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "interpolate-size");
  }

  auto
  Squeezer::property_interpolate_size () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "interpolate-size");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gtk::SelectionModel>>::value,
      "Type glib::RefPtr<gtk::SelectionModel> cannot be used in "
      "_WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Squeezer::property_pages () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gtk::SelectionModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gtk::SelectionModel>> (
        this,
        "pages");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<FoldThresholdPolicy>::value,
      "Type FoldThresholdPolicy cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Squeezer::property_switch_threshold_policy () -> glib::PropertyProxy<FoldThresholdPolicy>
  {
    return glib::PropertyProxy<FoldThresholdPolicy> (this,
                                                     "switch-threshold-policy");
  }

  auto
  Squeezer::property_switch_threshold_policy () const -> glib::PropertyProxy_ReadOnly<FoldThresholdPolicy>
  {
    return glib::PropertyProxy_ReadOnly<FoldThresholdPolicy> (
        this,
        "switch-threshold-policy");
  }

  auto
  Squeezer::property_transition_duration () -> glib::PropertyProxy<guint>
  {
    return glib::PropertyProxy<guint> (this, "transition-duration");
  }

  auto
  Squeezer::property_transition_duration () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "transition-duration");
  }

  auto
  Squeezer::property_transition_running () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "transition-running");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          SqueezerTransitionType>::value,
      "Type SqueezerTransitionType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Squeezer::property_transition_type () -> glib::PropertyProxy<SqueezerTransitionType>
  {
    return glib::PropertyProxy<SqueezerTransitionType> (this,
                                                        "transition-type");
  }

  auto
  Squeezer::property_transition_type () const -> glib::PropertyProxy_ReadOnly<SqueezerTransitionType>
  {
    return glib::PropertyProxy_ReadOnly<SqueezerTransitionType> (
        this,
        "transition-type");
  }

  auto
  Squeezer::property_visible_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return glib::PropertyProxy_ReadOnly<gtk::Widget*> (this, "visible-child");
  }

  auto
  Squeezer::property_xalign () -> glib::PropertyProxy<float>
  {
    return glib::PropertyProxy<float> (this, "xalign");
  }

  auto
  Squeezer::property_xalign () const -> glib::PropertyProxy_ReadOnly<float>
  {
    return glib::PropertyProxy_ReadOnly<float> (this, "xalign");
  }

  auto
  Squeezer::property_yalign () -> glib::PropertyProxy<float>
  {
    return glib::PropertyProxy<float> (this, "yalign");
  }

  auto
  Squeezer::property_yalign () const -> glib::PropertyProxy_ReadOnly<float>
  {
    return glib::PropertyProxy_ReadOnly<float> (this, "yalign");
  }

} // namespace adw
