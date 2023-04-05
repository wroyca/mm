// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_DEVICEWITHPAD_H
#define _GDKMM_DEVICEWITHPAD_H

#include <libmm/gdk/device.hxx>
#include <libmm/gdk/devicepad.hxx>

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT DeviceWithPad : public Device,
                                  public DevicePad
  {
  private:
    DeviceWithPad (const DeviceWithPad&) = delete;
    auto
    operator= (const DeviceWithPad&) -> DeviceWithPad& = delete;

    friend class Device_Class;

  protected:
    explicit DeviceWithPad (GdkDevice* castitem);

  public:
    DeviceWithPad (DeviceWithPad&& src) noexcept;
    auto
    operator= (DeviceWithPad&& src) noexcept -> DeviceWithPad&;

    ~DeviceWithPad () noexcept override;
  };

} // namespace gdk

#endif
