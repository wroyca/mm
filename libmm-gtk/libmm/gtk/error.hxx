// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ERROR_H
#define _GTKMM_ERROR_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/error.hxx>

namespace gtk
{
  class DialogError : public glib::Error
  {
  public:
    enum Code
    {
      FAILED,
      CANCELLED,
      DISMISSED
    };

    LIBMM_GTK_SYMEXPORT
    DialogError (Code error_code, const glib::ustring& error_message);
    LIBMM_GTK_SYMEXPORT explicit DialogError (GError* gobject);
    LIBMM_GTK_SYMEXPORT auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    LIBMM_GTK_SYMEXPORT static auto
    throw_func (GError* gobject) -> void;

    friend LIBMM_GTK_SYMEXPORT auto
    wrap_init () -> void;

#endif
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::DialogError::Code>
    : public glib::Value_Enum<gtk::DialogError::Code>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

}

#endif
