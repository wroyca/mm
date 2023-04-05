// SPDX-License-Identifier: LGPL-2.1-or-later

#include <gio/gio.h>
#include <libmm/gio/contenttype.hxx>
#include <libmm/glib/vectorutils.hxx>

namespace gio
{

  auto
  content_type_equals (const glib::ustring& type1, const glib::ustring& type2) -> bool
  {
    return g_content_type_equals (type1.c_str (), type2.c_str ());
  }

  auto
  content_type_is_a (const glib::ustring& type, const glib::ustring& supertype) -> bool
  {
    return g_content_type_is_a (type.c_str (), supertype.c_str ());
  }

  auto
  content_type_is_unknown (const glib::ustring& type) -> bool
  {
    return g_content_type_is_unknown (type.c_str ());
  }

  auto
  content_type_get_description (const glib::ustring& type) -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        g_content_type_get_description (type.c_str ()));
  }

  auto
  content_type_get_mime_type (const glib::ustring& type) -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        g_content_type_get_mime_type (type.c_str ()));
  }

  auto
  content_type_get_icon (const glib::ustring& type) -> glib::RefPtr<Icon>
  {
    auto retvalue = glib::wrap (g_content_type_get_icon (type.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

#ifdef G_OS_UNIX
  auto
  content_type_get_symbolic_icon (const glib::ustring& type) -> glib::RefPtr<gio::Icon>
  {
    auto retvalue =
        glib::wrap (g_content_type_get_symbolic_icon (type.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }
#endif

  auto
  content_type_can_be_executable (const glib::ustring& type) -> bool
  {
    return g_content_type_can_be_executable (type.c_str ());
  }

  auto
  content_type_from_mime_type (const glib::ustring& mime_type) -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        g_content_type_from_mime_type (mime_type.c_str ()));
  }

  auto
  content_type_guess (const std::string& filename,
                      const std::basic_string<guchar>& data,
                      bool& result_uncertain) -> glib::ustring
  {
    gboolean c_result_uncertain = FALSE;
    const gchar* c_filename = filename.empty () ? nullptr : filename.c_str ();
    gchar* cresult = g_content_type_guess (c_filename,
                                           data.c_str (),
                                           data.size (),
                                           &c_result_uncertain);
    result_uncertain = c_result_uncertain;
    return glib::convert_return_gchar_ptr_to_ustring (cresult);
  }

  auto
  content_type_guess (const std::string& filename,
                      const guchar* data,
                      const gsize data_size,
                      bool& result_uncertain) -> glib::ustring
  {
    gboolean c_result_uncertain = FALSE;
    const gchar* c_filename = filename.empty () ? nullptr : filename.c_str ();
    gchar* cresult =
        g_content_type_guess (c_filename, data, data_size, &c_result_uncertain);
    result_uncertain = c_result_uncertain;
    return glib::convert_return_gchar_ptr_to_ustring (cresult);
  }

  auto
  content_type_guess (const std::string& filename,
                      const std::string& data,
                      bool& result_uncertain) -> glib::ustring
  {
    gboolean c_result_uncertain = FALSE;
    const gchar* c_filename = filename.empty () ? nullptr : filename.c_str ();
    gchar* cresult = g_content_type_guess (c_filename,
                                           (const guchar*) data.c_str (),
                                           data.size (),
                                           &c_result_uncertain);
    result_uncertain = c_result_uncertain;
    return glib::convert_return_gchar_ptr_to_ustring (cresult);
  }

  auto
  content_type_guess_for_tree (const glib::RefPtr<const File>& root) -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
        g_content_type_guess_for_tree (const_cast<GFile*> (root->gobj ())),
        glib::OWNERSHIP_DEEP);
  }

  auto
  content_types_get_registered () -> std::vector<glib::ustring>
  {
    return glib::ListHandler<glib::ustring>::list_to_vector (
        g_content_types_get_registered (),
        glib::OWNERSHIP_DEEP);
  }

} // namespace gio
