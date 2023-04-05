// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/error.hxx>
#include <libmm/gtk/error_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

gtk::DialogError::DialogError (gtk::DialogError::Code error_code,
                               const glib::ustring& error_message)
  : glib::Error (GTK_DIALOG_ERROR, error_code, error_message)
{
}

gtk::DialogError::DialogError (GError* gobject)
  : glib::Error (gobject)
{
}

auto
gtk::DialogError::code () const -> gtk::DialogError::Code
{
  return static_cast<Code> (glib::Error::code ());
}

auto
gtk::DialogError::throw_func (GError* gobject) -> void
{
  throw gtk::DialogError (gobject);
}

auto
glib::Value<gtk::DialogError::Code>::value_type () -> GType
{
  return gtk_dialog_error_get_type ();
}
