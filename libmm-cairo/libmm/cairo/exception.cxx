// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm/cairo/exception.hxx>
#include <string>

namespace cairo
{

  inline static auto
  string_or_empty (const char* text) -> const char*
  {
    return text ? text : "";
  }

  logic_error::logic_error (const ErrorStatus status)
    : std::logic_error (string_or_empty (cairo_status_to_string (status))),
      m_status (status)
  {
  }

  logic_error::~logic_error () noexcept = default;

  auto
  logic_error::get_status_code () const -> ErrorStatus
  {
    return m_status;
  }

} // namespace cairo
