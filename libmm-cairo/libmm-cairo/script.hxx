// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef __CAIROMM_SCRIPT_H
#define __CAIROMM_SCRIPT_H

#include <libmm-cairo/device.hxx>
#include <libmm-cairo/enums.hxx>
#include <libmm-cairo/surface.hxx>
#include <string>

#ifdef CAIRO_HAS_SCRIPT_SURFACE
  #include <cairo-script.h>
#endif

namespace Cairo
{

#ifdef CAIRO_HAS_SCRIPT_SURFACE

  class ScriptSurface;

  enum ScriptMode
  {
    SCRIPT_MODE_ASCII = CAIRO_SCRIPT_MODE_ASCII,

    SCRIPT_MODE_BINARY = CAIRO_SCRIPT_MODE_BINARY
  };

  class CAIROMM_API Script : public Device
  {
  public:
    explicit Script (cairo_device_t* cobject, bool has_reference = false);
    ~Script () override;

    void
    add_from_recording_surface (const RefPtr<ScriptSurface>& recording_surface);

    auto
    get_mode () const -> ScriptMode;

    void
    set_mode (ScriptMode new_mode);

    void
    write_comment (const std::string& comment);

    static auto
    create (const std::string& filename) -> RefPtr<Script>;

    static auto
    create_for_stream (const Surface::SlotWriteFunc& write_func)
        -> RefPtr<Script>;
  };

#endif

} // namespace Cairo

#endif
