// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_STATUSBAR_H
#define _GTKMM_STATUSBAR_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkStatusbar = struct _GtkStatusbar;
using GtkStatusbarClass = struct _GtkStatusbarClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Statusbar_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Statusbar : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Statusbar CppObjectType;
    typedef Statusbar_Class CppClassType;
    typedef GtkStatusbar BaseObjectType;
    typedef GtkStatusbarClass BaseClassType;
#endif

    Statusbar (Statusbar&& src) noexcept;
    auto
    operator= (Statusbar&& src) noexcept -> Statusbar&;

    Statusbar (const Statusbar&) = delete;
    auto
    operator= (const Statusbar&) -> Statusbar& = delete;

    ~Statusbar () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class Statusbar_Class;
    static CppClassType statusbar_class_;

  protected:
    explicit Statusbar (const Glib::ConstructParams& construct_params);
    explicit Statusbar (GtkStatusbar* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkStatusbar*
    {
      return reinterpret_cast<GtkStatusbar*> (gobject_);
    }

    auto
    gobj () const -> const GtkStatusbar*
    {
      return reinterpret_cast<GtkStatusbar*> (gobject_);
    }

  private:
  public:
    Statusbar ();

    auto
    get_context_id (const Glib::ustring& context_description) -> guint;

    auto
    push (const Glib::ustring& text, guint context_id = 0) -> guint;

    void
    pop (guint context_id = 0);

    void
    remove_message (guint message_id, guint context_id = 0);

    void
    remove_all_messages (guint context_id = 0);

    auto
    signal_text_pushed ()
        -> Glib::SignalProxy<void (guint, const Glib::ustring&)>;

    auto
    signal_text_popped ()
        -> Glib::SignalProxy<void (guint, const Glib::ustring&)>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkStatusbar* object, bool take_copy = false) -> Gtk::Statusbar*;
} // namespace Glib

#endif
