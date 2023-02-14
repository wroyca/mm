// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/enums.hxx>
#include <libmm-gtk/enums_p.hxx>

#include <gtk/gtk.h>

#include <libmm-gtk/enums.hxx>

namespace Gtk
{

  auto
  _gtkmm_align_float_from_enum (const Align value) -> float
  {
    switch (value)
    {
      case Align::START:
        return 0.0;
        break;
      case Align::CENTER:
        return 0.5;
        break;
      case Align::END:
        return 1.0;
        break;
      default:
        return _gtkmm_align_float_from_enum (Align::START);
        break;
    }
  }

} // namespace Gtk

namespace
{
}

auto
Glib::Value<Gtk::Align>::value_type () -> GType
{
  return gtk_align_get_type ();
}

auto
Glib::Value<Gtk::ArrowType>::value_type () -> GType
{
  return gtk_arrow_type_get_type ();
}

auto
Glib::Value<Gtk::DeleteType>::value_type () -> GType
{
  return gtk_delete_type_get_type ();
}

auto
Glib::Value<Gtk::DirectionType>::value_type () -> GType
{
  return gtk_direction_type_get_type ();
}

auto
Glib::Value<Gtk::IconSize>::value_type () -> GType
{
  return gtk_icon_size_get_type ();
}

auto
Glib::Value<Gtk::TextDirection>::value_type () -> GType
{
  return gtk_text_direction_get_type ();
}

auto
Glib::Value<Gtk::Justification>::value_type () -> GType
{
  return gtk_justification_get_type ();
}

auto
Glib::Value<Gtk::MessageType>::value_type () -> GType
{
  return gtk_message_type_get_type ();
}

auto
Glib::Value<Gtk::MovementStep>::value_type () -> GType
{
  return gtk_movement_step_get_type ();
}

auto
Glib::Value<Gtk::Orientation>::value_type () -> GType
{
  return gtk_orientation_get_type ();
}

auto
Glib::Value<Gtk::Overflow>::value_type () -> GType
{
  return gtk_overflow_get_type ();
}

auto
Glib::Value<Gtk::CornerType>::value_type () -> GType
{
  return gtk_corner_type_get_type ();
}

auto
Glib::Value<Gtk::PackType>::value_type () -> GType
{
  return gtk_pack_type_get_type ();
}

auto
Glib::Value<Gtk::PickFlags>::value_type () -> GType
{
  return gtk_pick_flags_get_type ();
}

auto
Glib::Value<Gtk::PolicyType>::value_type () -> GType
{
  return gtk_policy_type_get_type ();
}

auto
Glib::Value<Gtk::PositionType>::value_type () -> GType
{
  return gtk_position_type_get_type ();
}

auto
Glib::Value<Gtk::RevealerTransitionType>::value_type () -> GType
{
  return gtk_revealer_transition_type_get_type ();
}

auto
Glib::Value<Gtk::ScrollType>::value_type () -> GType
{
  return gtk_scroll_type_get_type ();
}

auto
Glib::Value<Gtk::SelectionMode>::value_type () -> GType
{
  return gtk_selection_mode_get_type ();
}

auto
Glib::Value<Gtk::StackTransitionType>::value_type () -> GType
{
  return gtk_stack_transition_type_get_type ();
}

auto
Glib::Value<Gtk::WrapMode>::value_type () -> GType
{
  return gtk_wrap_mode_get_type ();
}

auto
Glib::Value<Gtk::NaturalWrapMode>::value_type () -> GType
{
  return gtk_natural_wrap_mode_get_type ();
}

auto
Glib::Value<Gtk::SortType>::value_type () -> GType
{
  return gtk_sort_type_get_type ();
}

auto
Glib::Value<Gtk::Ordering>::value_type () -> GType
{
  return gtk_ordering_get_type ();
}

auto
Glib::Value<Gtk::PageOrientation>::value_type () -> GType
{
  return gtk_page_orientation_get_type ();
}

auto
Glib::Value<Gtk::SensitivityType>::value_type () -> GType
{
  return gtk_sensitivity_type_get_type ();
}

auto
Glib::Value<Gtk::SizeRequestMode>::value_type () -> GType
{
  return gtk_size_request_mode_get_type ();
}

auto
Glib::Value<Gtk::StateFlags>::value_type () -> GType
{
  return gtk_state_flags_get_type ();
}

auto
Glib::Value<Gtk::InputPurpose>::value_type () -> GType
{
  return gtk_input_purpose_get_type ();
}

auto
Glib::Value<Gtk::InputHints>::value_type () -> GType
{
  return gtk_input_hints_get_type ();
}

auto
Glib::Value<Gtk::BaselinePosition>::value_type () -> GType
{
  return gtk_baseline_position_get_type ();
}

auto
Glib::Value<Gtk::ShortcutScope>::value_type () -> GType
{
  return gtk_shortcut_scope_get_type ();
}

auto
Glib::Value<Gtk::ContentFit>::value_type () -> GType
{
  return gtk_content_fit_get_type ();
}
