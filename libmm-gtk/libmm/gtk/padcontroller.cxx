// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/padcontroller.hxx>
#include <libmm/gtk/padcontroller_p.hxx>

#include <gtk/gtk.h>
#include <memory>

namespace gtk
{

  PadController::PadController (
      const glib::RefPtr<gio::ActionGroup>& action_group,
      const glib::RefPtr<gdk::Device>& pad)
    : glib::ObjectBase (nullptr),
      EventController (glib::ConstructParams (padcontroller_class_.init (),
                                              "propagation-phase",
                                              GTK_PHASE_CAPTURE,
                                              "action-group",
                                              glib::unwrap (action_group),
                                              "pad",
                                              glib::unwrap (pad),
                                              nullptr))
  {
  }

  auto
  PadController::set_action_entries (const std::vector<PadActionEntry>& entries) -> void
  {
    if (entries.empty ())
      return;

    auto c_entries = std::make_unique<GtkPadActionEntry[]> (entries.size ());

    for (std::size_t i = 0; i < entries.size (); ++i)
      c_entries[i] = *entries[i].gobj ();

    gtk_pad_controller_set_action_entries (gobj (),
                                           c_entries.get (),
                                           entries.size ());
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkPadController* object, bool take_copy) -> glib::RefPtr<gtk::PadController>
  {
    return glib::make_refptr_for_instance<gtk::PadController> (
        dynamic_cast<gtk::PadController*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  PadController_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &PadController_Class::class_init_function;

      register_derived_type (gtk_pad_controller_get_type ());
    }

    return *this;
  }

  auto
  PadController_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  PadController_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new PadController ((GtkPadController*) object);
  }

  auto
  PadController::gobj_copy () -> GtkPadController*
  {
    reference ();
    return gobj ();
  }

  PadController::PadController (const glib::ConstructParams& construct_params)
    : EventController (construct_params)
  {
  }

  PadController::PadController (GtkPadController* castitem)
    : EventController ((GtkEventController*) (castitem))
  {
  }

  PadController::PadController (PadController&& src) noexcept
    : EventController (std::move (src))
  {
  }

  auto
  PadController::operator= (PadController&& src) noexcept -> PadController&
  {
    EventController::operator= (std::move (src));
    return *this;
  }

  PadController::~PadController () noexcept {}

  PadController::CppClassType PadController::padcontroller_class_;

  auto
  PadController::get_type () -> GType
  {
    return padcontroller_class_.init ().get_type ();
  }

  auto
  PadController::get_base_type () -> GType
  {
    return gtk_pad_controller_get_type ();
  }

  auto
  PadController::create (const glib::RefPtr<gio::ActionGroup>& action_group,
                         const glib::RefPtr<gdk::Device>& pad) -> glib::RefPtr<PadController>
  {
    return glib::make_refptr_for_instance<PadController> (
        new PadController (action_group, pad));
  }

  auto
  PadController::set_action (PadActionType type,
                             int index,
                             int mode,
                             const glib::ustring& label,
                             const glib::ustring& action_name) -> void
  {
    gtk_pad_controller_set_action (gobj (),
                                   static_cast<GtkPadActionType> (type),
                                   index,
                                   mode,
                                   label.c_str (),
                                   action_name.c_str ());
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::ActionGroup>>::value,
      "Type glib::RefPtr<gio::ActionGroup> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  PadController::property_action_group () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ActionGroup>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ActionGroup>> (
        this,
        "action-group");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gdk::Device>>::value,
      "Type glib::RefPtr<gdk::Device> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  PadController::property_pad () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Device>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Device>> (this,
                                                                    "pad");
  }

} // namespace gtk
