// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_CONTENTTYPE_H
#define _GIOMM_CONTENTTYPE_H

#include <libmm/gio/file.hxx>
#include <libmm/gio/icon.hxx>
#include <libmm/glib/ustring.hxx>
#include <string>

namespace gio
{

  LIBMM_GIO_SYMEXPORT
  auto
  content_type_equals (const glib::ustring& type1, const glib::ustring& type2) -> bool;

  LIBMM_GIO_SYMEXPORT
  auto
  content_type_is_a (const glib::ustring& type, const glib::ustring& supertype) -> bool;

  LIBMM_GIO_SYMEXPORT
  auto
  content_type_is_unknown (const glib::ustring& type) -> bool;

  LIBMM_GIO_SYMEXPORT
  auto
  content_type_get_description (const glib::ustring& type) -> glib::ustring;

  LIBMM_GIO_SYMEXPORT
  auto
  content_type_get_mime_type (const glib::ustring& type) -> glib::ustring;

  LIBMM_GIO_SYMEXPORT
  auto
  content_type_get_icon (const glib::ustring& type) -> glib::RefPtr<Icon>;

#ifdef G_OS_UNIX

  LIBMM_GIO_SYMEXPORT
  auto
  content_type_get_symbolic_icon (const glib::ustring& type) -> glib::RefPtr<Icon>;
#endif

  LIBMM_GIO_SYMEXPORT
  auto
  content_type_can_be_executable (const glib::ustring& type) -> bool;

  LIBMM_GIO_SYMEXPORT
  auto
  content_type_from_mime_type (const glib::ustring& mime_type) -> glib::ustring;

  LIBMM_GIO_SYMEXPORT
  auto
  content_type_guess (const std::string& filename,
                      const guchar* data,
                      gsize data_size,
                      bool& result_uncertain) -> glib::ustring;

  LIBMM_GIO_SYMEXPORT
  auto
  content_type_guess (const std::string& filename,
                      const std::string& data,
                      bool& result_uncertain) -> glib::ustring;

  LIBMM_GIO_SYMEXPORT
  auto
  content_type_guess_for_tree (const glib::RefPtr<const File>& root) -> std::vector<glib::ustring>;

  LIBMM_GIO_SYMEXPORT
  auto
  content_types_get_registered () -> std::vector<glib::ustring>;

} // namespace gio
#endif
