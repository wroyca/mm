// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ERROR_H
#define _GTKMM_ERROR_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/error.hxx>

namespace Gtk
{
  class DialogError : public Glib::Error
  {
  public:
    enum Code
    {
      FAILED,
      CANCELLED,
      DISMISSED
    };

    GTKMM_API
    DialogError (Code error_code, const Glib::ustring& error_message);
    GTKMM_API explicit DialogError (GError* gobject);
    GTKMM_API auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    GTKMM_API static auto
    throw_func (GError* gobject) -> void;

    friend GTKMM_API auto
    wrap_init () -> void;

#endif
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::DialogError::Code>
    : public Glib::Value_Enum<Gtk::DialogError::Code>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

}

#endif
