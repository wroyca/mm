
#ifndef _GTKMM_PADACTIONENTRY_H
#define _GTKMM_PADACTIONENTRY_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/ustring.hxx>
#include <libmm-glib/value.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkPadActionEntry GtkPadActionEntry;
}
#endif

namespace Gtk
{

  enum class PadActionType
  {
    BUTTON,
    RING,
    STRIP
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::PadActionType>
    : public Glib::Value_Enum<Gtk::PadActionType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

  class GTKMM_API PadActionEntry
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
                    const Glib::ustring& label,
                    const Glib::ustring& action_name);

    PadActionEntry (const PadActionEntry& src);
    auto
    operator= (const PadActionEntry& src) -> PadActionEntry&;

    PadActionEntry (PadActionEntry&& other) noexcept;
    auto
    operator= (PadActionEntry&& other) noexcept -> PadActionEntry&;

    virtual ~PadActionEntry ();

    auto
    get_type () const -> PadActionType;
    void
    set_type (const PadActionType& value);

    auto
    get_index () const -> int;
    void
    set_index (const int& value);

    auto
    get_mode () const -> int;
    void
    set_mode (const int& value);

    auto
    get_label () const -> Glib::ustring;
    void
    set_label (const Glib::ustring& value);

    auto
    get_action_name () const -> Glib::ustring;
    void
    set_action_name (const Glib::ustring& value);

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
    void
    release_gobject () noexcept;
  };

} // namespace Gtk

#endif
