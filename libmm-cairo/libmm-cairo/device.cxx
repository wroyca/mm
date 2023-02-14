

#include <libmm-cairo/device.hxx>
#include <libmm-cairo/private.hxx>

namespace Cairo
{

  Device::Device (cairo_device_t* cobject, const bool has_reference)
    : m_cobject (nullptr)
  {
    if (has_reference)
      m_cobject = cobject;
    else
      m_cobject = cairo_device_reference (cobject);
  }

  Device::~Device ()
  {
    if (m_cobject)
      cairo_device_destroy (m_cobject);
  }

  auto
  Device::reference () const -> void
  {
    cairo_device_reference (m_cobject);
  }

  auto
  Device::unreference () const -> void
  {
    cairo_device_destroy (m_cobject);
  }

  auto
  Device::get_type () const -> DeviceType
  {
    auto surface_type = cairo_device_get_type (const_cast<cobject*> (cobj ()));
    check_object_status_and_throw_exception (*this);
    return static_cast<DeviceType> (surface_type);
  }

  auto
  Device::flush () -> void
  {
    cairo_device_flush (m_cobject);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Device::finish () -> void
  {
    cairo_device_flush (m_cobject);
    check_object_status_and_throw_exception (*this);
  }

  auto
  Device::acquire () -> void
  {
    const auto status = cairo_device_acquire (m_cobject);
    check_status_and_throw_exception (status);
  }

  auto
  Device::release () -> void
  {
    cairo_device_release (m_cobject);
    check_object_status_and_throw_exception (*this);
  }

  Device::Lock::Lock (const RefPtr<Device>& device)
    : m_device (device)
  {
    m_device->acquire ();
  }

  Device::Lock::Lock (const Lock& other)
    : m_device (other.m_device)
  {
    m_device->acquire ();
  }

  Device::Lock::~Lock ()
  {
    m_device->release ();
  }

} // namespace Cairo
