
#ifndef _GTKMM_INFOBAR_H
#define _GTKMM_INFOBAR_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/button.hxx>
#include <libmm-gtk/enums.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkInfoBar = struct _GtkInfoBar;
using GtkInfoBarClass = struct _GtkInfoBarClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API InfoBar_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API InfoBar : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef InfoBar CppObjectType;
    typedef InfoBar_Class CppClassType;
    typedef GtkInfoBar BaseObjectType;
    typedef GtkInfoBarClass BaseClassType;
#endif

    InfoBar (InfoBar&& src) noexcept;
    auto
    operator= (InfoBar&& src) noexcept -> InfoBar&;

    InfoBar (const InfoBar&) = delete;
    auto
    operator= (const InfoBar&) -> InfoBar& = delete;

    ~InfoBar () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class InfoBar_Class;
    static CppClassType infobar_class_;

  protected:
    explicit InfoBar (const Glib::ConstructParams& construct_params);
    explicit InfoBar (GtkInfoBar* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkInfoBar*
    {
      return reinterpret_cast<GtkInfoBar*> (gobject_);
    }

    auto
    gobj () const -> const GtkInfoBar*
    {
      return reinterpret_cast<GtkInfoBar*> (gobject_);
    }

  private:
  public:
    InfoBar ();

    void
    add_action_widget (Widget& child, int response_id);

    void
    remove_action_widget (Widget& widget);

    auto
    add_button (const Glib::ustring& button_text, int response_id) -> Button*;

    void
    add_child (Widget& widget);

    void
    remove_child (Widget& widget);

    void
    set_response_sensitive (int response_id, bool setting = true);

    void
    set_default_response (int response_id);

    void
    response (int response_id);

    void
    set_message_type (MessageType message_type);

    auto
    get_message_type () const -> MessageType;

    void
    set_show_close_button (bool setting = true);

    auto
    get_show_close_button () const -> bool;

    void
    set_revealed (bool revealed = true);

    auto
    get_revealed () const -> bool;

    auto
    signal_response () -> Glib::SignalProxy<void (int)>;

    auto
    property_message_type () -> Glib::PropertyProxy<MessageType>;

    auto
    property_message_type () const -> Glib::PropertyProxy_ReadOnly<MessageType>;

    auto
    property_show_close_button () -> Glib::PropertyProxy<bool>;

    auto
    property_show_close_button () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_revealed () -> Glib::PropertyProxy<bool>;

    auto
    property_revealed () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkInfoBar* object, bool take_copy = false) -> Gtk::InfoBar*;
} // namespace Glib

#endif
