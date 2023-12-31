// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_PADACTIONENTRY_H
#define _GTKMM_PADACTIONENTRY_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/ustring.hxx>
#include <libmm/glib/value.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkPadActionEntry GtkPadActionEntry;
}
#endif

namespace gtk
{

  enum class PadActionType
  {
    BUTTON,
    RING,
    STRIP
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::PadActionType>
    : public glib::Value_Enum<gtk::PadActionType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT PadActionEntry
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = PadActionEntry;
    using BaseObjectType = GtkPadActionEntry;
#endif

  private:
  public:
    PadActionEntry ();

    PadActionEntry (PadActionType type,
                    int index,
                    int mode,
                    const glib::ustring& label,
                    const glib::ustring& action_name);

    PadActionEntry (const PadActionEntry& src);
    auto
    operator= (const PadActionEntry& src) -> PadActionEntry&;

    PadActionEntry (PadActionEntry&& other) noexcept;
    auto
    operator= (PadActionEntry&& other) noexcept -> PadActionEntry&;

    virtual ~PadActionEntry ();

    auto
    get_type () const -> PadActionType;
    auto
    set_type (const PadActionType& value) -> void;

    auto
    get_index () const -> int;
    auto
    set_index (const int& value) -> void;

    auto
    get_mode () const -> int;
    auto
    set_mode (const int& value) -> void;

    auto
    get_label () const -> glib::ustring;
    auto
    set_label (const glib::ustring& value) -> void;

    auto
    get_action_name () const -> glib::ustring;
    auto
    set_action_name (const glib::ustring& value) -> void;

    auto
    gobj () -> GtkPadActionEntry*
    {
      return gobject_;
    }

    auto
    gobj () const -> const GtkPadActionEntry*
    {
      return gobject_;
    }

  protected:
    GtkPadActionEntry* gobject_;

  private:
    auto
    release_gobject () noexcept -> void;
  };

} // namespace gtk

#endif
