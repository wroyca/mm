// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_CONTENTTYPE_H
#define _GIOMM_CONTENTTYPE_H

#include <libmm/gio/file.hxx>
#include <libmm/gio/icon.hxx>
#include <libmm/glib/ustring.hxx>
#include <string>

namespace Gio
{

  LIBMM_GIO_SYMEXPORT
  auto
  content_type_equals (const Glib::ustring& type1, const Glib::ustring& type2) -> bool;

  LIBMM_GIO_SYMEXPORT
  auto
  content_type_is_a (const Glib::ustring& type, const Glib::ustring& supertype) -> bool;

  LIBMM_GIO_SYMEXPORT
  auto
  content_type_is_unknown (const Glib::ustring& type) -> bool;

  LIBMM_GIO_SYMEXPORT
  auto
  content_type_get_description (const Glib::ustring& type) -> Glib::ustring;

  LIBMM_GIO_SYMEXPORT
  auto
  content_type_get_mime_type (const Glib::ustring& type) -> Glib::ustring;

  LIBMM_GIO_SYMEXPORT
  auto
  content_type_get_icon (const Glib::ustring& type) -> Glib::RefPtr<Icon>;

#ifdef G_OS_UNIX

  LIBMM_GIO_SYMEXPORT
  auto
  content_type_get_symbolic_icon (const Glib::ustring& type) -> Glib::RefPtr<Icon>;
#endif

  LIBMM_GIO_SYMEXPORT
  auto
  content_type_can_be_executable (const Glib::ustring& type) -> bool;

  LIBMM_GIO_SYMEXPORT
  auto
  content_type_from_mime_type (const Glib::ustring& mime_type) -> Glib::ustring;

  LIBMM_GIO_SYMEXPORT
  auto
  content_type_guess (const std::string& filename,
                      const guchar* data,
                      gsize data_size,
                      bool& result_uncertain) -> Glib::ustring;

  LIBMM_GIO_SYMEXPORT
  auto
  content_type_guess (const std::string& filename,
                      const std::string& data,
                      bool& result_uncertain) -> Glib::ustring;

  LIBMM_GIO_SYMEXPORT
  auto
  content_type_guess_for_tree (const Glib::RefPtr<const File>& root) -> std::vector<Glib::ustring>;

  LIBMM_GIO_SYMEXPORT
  auto
  content_types_get_registered () -> std::vector<Glib::ustring>;

} // namespace Gio
#endif
