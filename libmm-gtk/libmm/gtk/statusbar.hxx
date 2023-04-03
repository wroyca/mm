// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_STATUSBAR_H
#define _GTKMM_STATUSBAR_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gtk/widget.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkStatusbar = struct _GtkStatusbar;
using GtkStatusbarClass = struct _GtkStatusbarClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT Statusbar_Class;
}
  #endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT Statusbar : public Widget
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
    friend LIBMM_GTK_SYMEXPORT class Statusbar_Class;
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

    auto
    pop (guint context_id = 0) -> void;

    auto
    remove_message (guint message_id, guint context_id = 0) -> void;

    auto
    remove_all_messages (guint context_id = 0) -> void;

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
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkStatusbar* object, bool take_copy = false) -> Gtk::Statusbar*;
} // namespace Glib

#endif

#endif
