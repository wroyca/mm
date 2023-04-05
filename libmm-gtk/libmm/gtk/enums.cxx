// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/enums.hxx>
#include <libmm/gtk/enums_p.hxx>

#include <gtk/gtk.h>

#include <libmm/gtk/enums.hxx>

namespace gtk
{

  auto
  _gtkmm_align_float_from_enum (Align value) -> float
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

} // namespace gtk

namespace
{
}

auto
glib::Value<gtk::Align>::value_type () -> GType
{
  return gtk_align_get_type ();
}

auto
glib::Value<gtk::ArrowType>::value_type () -> GType
{
  return gtk_arrow_type_get_type ();
}

auto
glib::Value<gtk::DeleteType>::value_type () -> GType
{
  return gtk_delete_type_get_type ();
}

auto
glib::Value<gtk::DirectionType>::value_type () -> GType
{
  return gtk_direction_type_get_type ();
}

auto
glib::Value<gtk::IconSize>::value_type () -> GType
{
  return gtk_icon_size_get_type ();
}

auto
glib::Value<gtk::TextDirection>::value_type () -> GType
{
  return gtk_text_direction_get_type ();
}

auto
glib::Value<gtk::Justification>::value_type () -> GType
{
  return gtk_justification_get_type ();
}

auto
glib::Value<gtk::MessageType>::value_type () -> GType
{
  return gtk_message_type_get_type ();
}

auto
glib::Value<gtk::MovementStep>::value_type () -> GType
{
  return gtk_movement_step_get_type ();
}

auto
glib::Value<gtk::Orientation>::value_type () -> GType
{
  return gtk_orientation_get_type ();
}

auto
glib::Value<gtk::Overflow>::value_type () -> GType
{
  return gtk_overflow_get_type ();
}

auto
glib::Value<gtk::CornerType>::value_type () -> GType
{
  return gtk_corner_type_get_type ();
}

auto
glib::Value<gtk::PackType>::value_type () -> GType
{
  return gtk_pack_type_get_type ();
}

auto
glib::Value<gtk::PickFlags>::value_type () -> GType
{
  return gtk_pick_flags_get_type ();
}

auto
glib::Value<gtk::PolicyType>::value_type () -> GType
{
  return gtk_policy_type_get_type ();
}

auto
glib::Value<gtk::PositionType>::value_type () -> GType
{
  return gtk_position_type_get_type ();
}

auto
glib::Value<gtk::RevealerTransitionType>::value_type () -> GType
{
  return gtk_revealer_transition_type_get_type ();
}

auto
glib::Value<gtk::ScrollType>::value_type () -> GType
{
  return gtk_scroll_type_get_type ();
}

auto
glib::Value<gtk::SelectionMode>::value_type () -> GType
{
  return gtk_selection_mode_get_type ();
}

auto
glib::Value<gtk::StackTransitionType>::value_type () -> GType
{
  return gtk_stack_transition_type_get_type ();
}

auto
glib::Value<gtk::WrapMode>::value_type () -> GType
{
  return gtk_wrap_mode_get_type ();
}

auto
glib::Value<gtk::NaturalWrapMode>::value_type () -> GType
{
  return gtk_natural_wrap_mode_get_type ();
}

auto
glib::Value<gtk::SortType>::value_type () -> GType
{
  return gtk_sort_type_get_type ();
}

auto
glib::Value<gtk::Ordering>::value_type () -> GType
{
  return gtk_ordering_get_type ();
}

auto
glib::Value<gtk::PageOrientation>::value_type () -> GType
{
  return gtk_page_orientation_get_type ();
}

auto
glib::Value<gtk::SensitivityType>::value_type () -> GType
{
  return gtk_sensitivity_type_get_type ();
}

auto
glib::Value<gtk::SizeRequestMode>::value_type () -> GType
{
  return gtk_size_request_mode_get_type ();
}

auto
glib::Value<gtk::StateFlags>::value_type () -> GType
{
  return gtk_state_flags_get_type ();
}

auto
glib::Value<gtk::InputPurpose>::value_type () -> GType
{
  return gtk_input_purpose_get_type ();
}

auto
glib::Value<gtk::InputHints>::value_type () -> GType
{
  return gtk_input_hints_get_type ();
}

auto
glib::Value<gtk::BaselinePosition>::value_type () -> GType
{
  return gtk_baseline_position_get_type ();
}

auto
glib::Value<gtk::ShortcutScope>::value_type () -> GType
{
  return gtk_shortcut_scope_get_type ();
}

auto
glib::Value<gtk::ContentFit>::value_type () -> GType
{
  return gtk_content_fit_get_type ();
}
