// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/base64.hxx>
#include <libmm/glib/utility.hxx>

namespace glib
{

  auto
  Base64::encode (const std::string& source, const bool break_lines) -> std::string
  {
    gsize length = (source.length () / 3 + 1) * 4 + 1;
    length += length / 72 + 1;
    const auto buf = make_unique_ptr_gfree ((char*) g_malloc (length));
    gint state = 0, save = 0;
    const guchar* src = reinterpret_cast<const unsigned char*> (source.data ());
    gsize out = g_base64_encode_step (src,
                                      source.length (),
                                      break_lines,
                                      buf.get (),
                                      &state,
                                      &save);
    out += g_base64_encode_close (break_lines, buf.get () + out, &state, &save);
    return std::string (buf.get (), buf.get () + out);
  }

  auto
  Base64::decode (const std::string& source) -> std::string
  {
    gsize size;
    const auto buf = make_unique_ptr_gfree (
        (char*) g_base64_decode (source.c_str (), &size));
    return std::string (buf.get (), buf.get () + size);
  }

} // namespace glib
