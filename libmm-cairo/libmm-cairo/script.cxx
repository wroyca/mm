/* Copyright (C) 2014 The cairomm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#include <libmm-cairo/script_surface.hpp>
#include <libmm-cairo/private.hpp>

namespace Cairo {

#ifdef CAIRO_HAS_SCRIPT_SURFACE

Script::Script(cairo_device_t* cobject, const bool has_reference) :
  Device(cobject, has_reference)
{}

Script::~Script()
{
  // script device is destroyed in base class
}

auto Script::add_from_recording_surface (const RefPtr <ScriptSurface> &recording_surface) -> void
{
  const auto status = cairo_script_from_recording_surface(m_cobject,
                                                          recording_surface->cobj());
  check_status_and_throw_exception(status);
}

auto Script::get_mode() const -> ScriptMode
{
  return static_cast<ScriptMode>(cairo_script_get_mode(m_cobject));
}

auto Script::set_mode (ScriptMode new_mode) -> void
{
  cairo_script_set_mode(m_cobject, static_cast<cairo_script_mode_t>(new_mode));
}

auto Script::write_comment (const std::string &comment) -> void
{
  cairo_script_write_comment(m_cobject, comment.data(), comment.length());
}

auto Script::create(const std::string& filename) -> RefPtr<Script>
{
  const auto cobject = cairo_script_create(filename.c_str());
  check_status_and_throw_exception(cairo_device_status(cobject));
  return make_refptr_for_instance<Script>(new Script(cobject, true /* has reference */));
}

static cairo_user_data_key_t USER_DATA_KEY_DEVICE_WRITE_FUNC = {0};

static auto device_free_slot (void *data) -> void
{
  // FIXME: duplicates free_slot in surface.cc
  const auto slot = static_cast<Surface::SlotWriteFunc*>(data);
  delete slot;
}

auto device_write_func_wrapper(void* closure, const unsigned char* data, const unsigned int length) -> cairo_status_t
{
  // FIXME: duplicates free_slot in surface.cc
  if (!closure)
    return CAIRO_STATUS_WRITE_ERROR;
  const auto write_func = static_cast<Surface::SlotWriteFunc*>(closure);
  return (*write_func)(data, length);
}

static auto set_write_slot (
  cairo_device_t *surface,
  Surface::SlotWriteFunc *slot) -> void
{
  // the slot will automatically be freed by device_free_slot() when the
  // underlying C instance is destroyed
  cairo_device_set_user_data(surface, &USER_DATA_KEY_DEVICE_WRITE_FUNC, slot,
                             &device_free_slot);
}

auto Script::create_for_stream(const Surface::SlotWriteFunc& write_func) -> RefPtr<Script>
{
  const auto slot_copy = new Surface::SlotWriteFunc(write_func);
  const auto cobject = cairo_script_create_for_stream(device_write_func_wrapper,
                                                      slot_copy);
  check_status_and_throw_exception(cairo_device_status(cobject));
  set_write_slot(cobject, slot_copy);
  return make_refptr_for_instance<Script>(new Script(cobject, true /* has reference */));
}

#endif // CAIRO_HAS_SCRIPT_SURFACE

} //namespace Cairo
