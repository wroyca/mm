// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_DIALOG_H
#define _GTKMM_DIALOG_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <vector>

#include <libmm-gtk/box.hxx>
#include <libmm-gtk/button.hxx>
#include <libmm-gtk/headerbar.hxx>
#include <libmm-gtk/window.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkDialog = struct _GtkDialog;
using GtkDialogClass = struct _GtkDialogClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Dialog_Class;
}
#endif

namespace Gtk
{

  class ResponseType_Wrapper final
  {
  public:
    enum ResponseType
    {
      NONE = -1,
      REJECT = -2,
      ACCEPT = -3,
      DELETE_EVENT = -4,
      OK = -5,
      CANCEL = -6,
      CLOSE = -7,
      YES = -8,
      NO = -9,
      APPLY = -10,
      HELP = -11
    };
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    ResponseType_Wrapper () = delete;
#endif
  };

  using ResponseType = ResponseType_Wrapper::ResponseType;

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::ResponseType>
    : public Glib::Value_Enum<Gtk::ResponseType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

  class GTKMM_API Dialog : public Window
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Dialog CppObjectType;
    typedef Dialog_Class CppClassType;
    typedef GtkDialog BaseObjectType;
    typedef GtkDialogClass BaseClassType;
#endif

    Dialog (Dialog&& src) noexcept;
    auto
    operator= (Dialog&& src) noexcept -> Dialog&;

    Dialog (const Dialog&) = delete;
    auto
    operator= (const Dialog&) -> Dialog& = delete;

    ~Dialog () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class Dialog_Class;
    static CppClassType dialog_class_;

  protected:
    explicit Dialog (const Glib::ConstructParams& construct_params);
    explicit Dialog (GtkDialog* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkDialog*
    {
      return reinterpret_cast<GtkDialog*> (gobject_);
    }

    auto
    gobj () const -> const GtkDialog*
    {
      return reinterpret_cast<GtkDialog*> (gobject_);
    }

  private:
  public:
    Dialog ();
    explicit Dialog (const Glib::ustring& title,
                     bool modal = false,
                     bool use_header_bar = false);
    Dialog (const Glib::ustring& title,
            Gtk::Window& parent,
            bool modal = false,
            bool use_header_bar = false);

    void
    add_action_widget (Widget& child, int response_id);

    auto
    add_button (const Glib::ustring& button_text, int response_id) -> Button*;

    void
    set_response_sensitive (int response_id, bool setting = true);

    void
    set_default_response (int response_id);

    auto
    get_widget_for_response (int response_id) -> Widget*;

    auto
    get_widget_for_response (int response_id) const -> const Widget*;

    auto
    get_response_for_widget (const Gtk::Widget& widget) const -> int;

    void
    response (int response_id);

    auto
    get_content_area () -> Box*;

    auto
    get_content_area () const -> const Box*;

    auto
    get_header_bar () -> HeaderBar*;

    auto
    get_header_bar () const -> const HeaderBar*;

    auto
    signal_response () -> Glib::SignalProxy<void (int)>;

    auto
    property_use_header_bar () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
    virtual void
    on_response (int response_id);
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkDialog* object, bool take_copy = false) -> Gtk::Dialog*;
} // namespace Glib

#endif
