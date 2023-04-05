// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/levelbar.hxx>
#include <libmm/gtk/levelbar_p.hxx>

#include <gtk/gtk.h>

using Mode = gtk::LevelBar::Mode;

namespace
{

  static auto
  LevelBar_signal_offset_changed_callback (GtkLevelBar* self,
                                           const gchar* p0,
                                           void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const glib::ustring&)>;

    auto obj = dynamic_cast<LevelBar*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::convert_const_gchar_ptr_to_ustring (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo LevelBar_signal_offset_changed_info = {
      "offset_changed",
      (GCallback) &LevelBar_signal_offset_changed_callback,
      (GCallback) &LevelBar_signal_offset_changed_callback};

} // namespace

auto
glib::Value<gtk::LevelBar::Mode>::value_type () -> GType
{
  return gtk_level_bar_mode_get_type ();
}

namespace glib
{

  auto
  wrap (GtkLevelBar* object, bool take_copy) -> gtk::LevelBar*
  {
    return dynamic_cast<gtk::LevelBar*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  LevelBar_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &LevelBar_Class::class_init_function;

      register_derived_type (gtk_level_bar_get_type ());

      Orientable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  LevelBar_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  LevelBar_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new LevelBar ((GtkLevelBar*) (o)));
  }

  LevelBar::LevelBar (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  LevelBar::LevelBar (GtkLevelBar* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  LevelBar::LevelBar (LevelBar&& src) noexcept
    : gtk::Widget (std::move (src)),
      Orientable (std::move (src))
  {
  }

  auto
  LevelBar::operator= (LevelBar&& src) noexcept -> LevelBar&
  {
    gtk::Widget::operator= (std::move (src));
    Orientable::operator= (std::move (src));
    return *this;
  }

  LevelBar::~LevelBar () noexcept
  {
    destroy_ ();
  }

  LevelBar::CppClassType LevelBar::levelbar_class_;

  auto
  LevelBar::get_type () -> GType
  {
    return levelbar_class_.init ().get_type ();
  }

  auto
  LevelBar::get_base_type () -> GType
  {
    return gtk_level_bar_get_type ();
  }

  LevelBar::LevelBar ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (levelbar_class_.init ()))
  {
  }

  auto
  LevelBar::set_mode (Mode mode) -> void
  {
    gtk_level_bar_set_mode (gobj (), static_cast<GtkLevelBarMode> (mode));
  }

  auto
  LevelBar::get_mode () const -> Mode
  {
    return static_cast<Mode> (
        gtk_level_bar_get_mode (const_cast<GtkLevelBar*> (gobj ())));
  }

  auto
  LevelBar::set_value (double value) -> void
  {
    gtk_level_bar_set_value (gobj (), value);
  }

  auto
  LevelBar::get_value () const -> double
  {
    return gtk_level_bar_get_value (const_cast<GtkLevelBar*> (gobj ()));
  }

  auto
  LevelBar::set_min_value (double value) -> void
  {
    gtk_level_bar_set_min_value (gobj (), value);
  }

  auto
  LevelBar::get_min_value () const -> double
  {
    return gtk_level_bar_get_min_value (const_cast<GtkLevelBar*> (gobj ()));
  }

  auto
  LevelBar::set_max_value (double value) -> void
  {
    gtk_level_bar_set_max_value (gobj (), value);
  }

  auto
  LevelBar::get_max_value () const -> double
  {
    return gtk_level_bar_get_max_value (const_cast<GtkLevelBar*> (gobj ()));
  }

  auto
  LevelBar::set_inverted (bool inverted) -> void
  {
    gtk_level_bar_set_inverted (gobj (), static_cast<int> (inverted));
  }

  auto
  LevelBar::get_inverted () const -> bool
  {
    return gtk_level_bar_get_inverted (const_cast<GtkLevelBar*> (gobj ()));
  }

  auto
  LevelBar::add_offset_value (const glib::ustring& name, double value) -> void
  {
    gtk_level_bar_add_offset_value (gobj (), name.c_str (), value);
  }

  auto
  LevelBar::remove_offset_value (const glib::ustring& name) -> void
  {
    gtk_level_bar_remove_offset_value (gobj (), name.c_str ());
  }

  auto
  LevelBar::get_offset_value (const glib::ustring& name, double& value) const -> bool
  {
    return gtk_level_bar_get_offset_value (const_cast<GtkLevelBar*> (gobj ()),
                                           name.c_str (),
                                           &(value));
  }

  auto
  LevelBar::signal_offset_changed (const glib::ustring& offset_name) -> glib::SignalProxyDetailed<void (const glib::ustring&)>
  {
    return glib::SignalProxyDetailed<void (const glib::ustring&)> (
        this,
        &LevelBar_signal_offset_changed_info,
        offset_name);
  }

  auto
  LevelBar::property_value () -> glib::PropertyProxy<double>
  {
    return glib::PropertyProxy<double> (this, "value");
  }

  auto
  LevelBar::property_value () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return glib::PropertyProxy_ReadOnly<double> (this, "value");
  }

  auto
  LevelBar::property_min_value () -> glib::PropertyProxy<double>
  {
    return glib::PropertyProxy<double> (this, "min-value");
  }

  auto
  LevelBar::property_min_value () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return glib::PropertyProxy_ReadOnly<double> (this, "min-value");
  }

  auto
  LevelBar::property_max_value () -> glib::PropertyProxy<double>
  {
    return glib::PropertyProxy<double> (this, "max-value");
  }

  auto
  LevelBar::property_max_value () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return glib::PropertyProxy_ReadOnly<double> (this, "max-value");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Mode>::value,
      "Type Mode cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  LevelBar::property_mode () -> glib::PropertyProxy<Mode>
  {
    return glib::PropertyProxy<Mode> (this, "mode");
  }

  auto
  LevelBar::property_mode () const -> glib::PropertyProxy_ReadOnly<Mode>
  {
    return glib::PropertyProxy_ReadOnly<Mode> (this, "mode");
  }

  auto
  LevelBar::property_inverted () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "inverted");
  }

  auto
  LevelBar::property_inverted () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "inverted");
  }

} // namespace gtk
