// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef __CAIROMM_DEVICE_H
#define __CAIROMM_DEVICE_H

#include <cairo.h>
#include <libmm-cairo/enums.hxx>
#include <libmm-cairo/refptr.hxx>
#include <libmm-cairo/types.hxx>

namespace Cairo
{

  class CAIROMM_API Device
  {
  public:
    class Lock
    {
    public:
      Lock (const RefPtr<Device>& device);
      Lock (const Lock& other);
      ~Lock ();

    private:
      RefPtr<Device> m_device;
    };

    enum class DeviceType
    {
      DRM = CAIRO_DEVICE_TYPE_DRM,

      GL = CAIRO_DEVICE_TYPE_GL,

      SCRIPT = CAIRO_DEVICE_TYPE_SCRIPT,

      XCB = CAIRO_DEVICE_TYPE_XCB,

      XLIB = CAIRO_DEVICE_TYPE_XLIB,

      XML = CAIRO_DEVICE_TYPE_XML
    };

    explicit Device (cairo_device_t* cobject, bool has_reference = false);

    virtual ~Device ();

    auto
    get_type () const -> DeviceType;

    auto
    flush () -> void;

    auto
    finish () -> void;

    auto
    acquire () -> void;

    auto
    release () -> void;

    typedef cairo_device_t cobject;

    inline auto
    cobj () -> cobject*
    {
      return m_cobject;
    }

    inline auto
    cobj () const -> const cobject*
    {
      return m_cobject;
    }

#ifndef DOXYGEN_IGNORE_THIS

    inline auto
    get_status () const -> ErrorStatus
    {
      return cairo_device_status (const_cast<cairo_device_t*> (cobj ()));
    }
#endif

    auto
    reference () const -> void;
    auto
    unreference () const -> void;

  protected:
    cobject* m_cobject;
  };

} // namespace Cairo

#endif
