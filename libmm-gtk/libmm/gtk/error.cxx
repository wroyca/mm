// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/error.hxx>
#include <libmm/gtk/error_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

Gtk::DialogError::DialogError (Gtk::DialogError::Code error_code,
                               const Glib::ustring& error_message)
  : Glib::Error (GTK_DIALOG_ERROR, error_code, error_message)
{
}

Gtk::DialogError::DialogError (GError* gobject)
  : Glib::Error (gobject)
{
}

auto
Gtk::DialogError::code () const -> Gtk::DialogError::Code
{
  return static_cast<Code> (Glib::Error::code ());
}

auto
Gtk::DialogError::throw_func (GError* gobject) -> void
{
  throw Gtk::DialogError (gobject);
}

auto
Glib::Value<Gtk::DialogError::Code>::value_type () -> GType
{
  return gtk_dialog_error_get_type ();
}
