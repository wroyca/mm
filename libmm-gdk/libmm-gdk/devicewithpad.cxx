// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-gdk/devicewithpad.hxx>

namespace Gdk
{

  DeviceWithPad::DeviceWithPad (GdkDevice* castitem)
    : Device (castitem)
  {
  }

  DeviceWithPad::DeviceWithPad (DeviceWithPad&& src) noexcept
    : Device (std::move (src)),
      DevicePad (std::move (src))
  {
  }

  auto
  DeviceWithPad::operator= (DeviceWithPad&& src) noexcept -> DeviceWithPad&
  {
    Device::operator= (std::move (src));
    DevicePad::operator= (std::move (src));
    return *this;
  }

  DeviceWithPad::~DeviceWithPad () noexcept = default;
} // namespace Gdk
